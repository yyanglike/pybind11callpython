/**
 * @file ast_visitor.cpp
 * @brief ANTLR语法树访问者实现
 */

#include "ast_visitor.h"
#include "antlr/PyScriptLexer.h"
#include "antlr/PyScriptParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <atomic>
#include <functional>
#include <vector>
#include <limits>
#include "dynamic_python_caller.h"

// 简单的字符串哈希函数（用于缓存键）
static size_t hashString(const std::string& str) {
    return std::hash<std::string>{}(str);
}

// 增量哈希组合函数（用于组合多个哈希值）
// 参考 boost::hash_combine 的实现
static size_t hashCombine(size_t seed, size_t value) {
    // 使用黄金比例相关的常数
    return seed ^ (value + 0x9e3779b9 + (seed << 6) + (seed >> 2));
}

// 计算变量状态的增量哈希（避免字符串拼接）
// 优化：直接对值进行哈希，避免toString()的字符串创建开销
// 优化：接受缓存的变量名列表，避免重复创建和排序
static size_t computeVariableStateHash(script_interpreter::VariableManager& variable_manager, 
                                       const std::vector<std::string>& var_names,
                                       bool& has_python_objects) {
    size_t hash = 0;
    has_python_objects = false;
    
    for (const auto& varName : var_names) {
        auto val = variable_manager.getVariable(varName);
        if (val) {
            try {
                // 先哈希变量名
                hash = hashCombine(hash, hashString(varName));
                
                if (val->isPythonObject()) {
                    has_python_objects = true;
                    // 对于 PythonObject，使用对象指针地址
                    py::object obj = val->toPythonObject();
                    size_t obj_id = reinterpret_cast<size_t>(obj.ptr());
                    hash = hashCombine(hash, obj_id);
                } else {
                    // 优化：对于简单类型，直接计算哈希，避免toString()创建字符串
                    switch (val->getType()) {
                        case ScriptValue::Type::Integer: {
                            auto int_val = val->getInteger();
                            hash = hashCombine(hash, std::hash<long long>{}(int_val));
                            break;
                        }
                        case ScriptValue::Type::Double: {
                            auto double_val = val->getDouble();
                            hash = hashCombine(hash, std::hash<double>{}(double_val));
                            break;
                        }
                        case ScriptValue::Type::Boolean: {
                            auto bool_val = val->getBoolean();
                            hash = hashCombine(hash, std::hash<bool>{}(bool_val));
                            break;
                        }
                        case ScriptValue::Type::String: {
                            // 字符串类型仍然需要hashString
                            hash = hashCombine(hash, hashString(val->getString()));
                            break;
                        }
                        case ScriptValue::Type::Null: {
                            // Null类型使用固定哈希值
                            hash = hashCombine(hash, 0xdeadbeef);
                            break;
                        }
                        default: {
                            // 对于其他类型（List, Dict等），使用toString()作为后备
                            std::string val_str = val->toString();
                            hash = hashCombine(hash, hashString(val_str));
                            break;
                        }
                    }
                }
            } catch (...) {
                // 忽略转换失败
            }
        }
    }
    
    return hash;
}

using namespace antlr4;
using namespace std;
using namespace script_interpreter;

// 确保 sys.argv 为非空列表
static void ensureSysArgv() {
    try {
        py::module_ sys = py::module_::import("sys");
        py::object argv = sys.attr("argv");
        py::list l;
        if (argv.is_none() || !py::isinstance<py::list>(argv)) {
            l.append(py::cast(""));
            sys.attr("argv") = l;
            return;
        }
        l = argv.cast<py::list>();
        if (l.empty()) {
            l.append(py::cast(""));
            sys.attr("argv") = l;
        }
    } catch (...) {
        // ignore
    }
}

// 构建用于 eval 的全局字典，包含 builtins、已定义变量与模块
// 优化：接受builtins_module参数，避免重复导入
static py::dict buildEvalGlobals(VariableManager& variable_manager, py::object builtins_module = py::none()) {
    py::dict g = py::globals();
    try {
        if (!builtins_module.is_none()) {
            g["__builtins__"] = builtins_module;
        } else {
            py::object builtins = py::module_::import("builtins");
            g["__builtins__"] = builtins;
        }
    } catch (...) {
    }
    // 注入变量
    // 注意：buildEvalGlobals是static函数，无法访问缓存的变量名列表
    // 这里仍然需要调用getAllVariableNames()，但调用频率较低
    for (const auto& name : variable_manager.getAllVariableNames()) {
        auto val = variable_manager.getVariable(name);
        if (val) {
            try {
                g[name.c_str()] = val->toPythonObject();
            } catch (...) {
            }
        }
    }
    // 注入模块
    // 注意：buildEvalGlobals是static函数，无法访问缓存的模块名列表
    for (const auto& modName : variable_manager.getAllModuleNames()) {
        try {
            py::module_ m = variable_manager.getModule(modName);
            if (m) g[modName.c_str()] = m;
        } catch (...) {
        }
    }
    return g;
}

// 统一将 ScriptValue 转换为 Python 可迭代对象（用于推导式/生成器）
// 注意：此函数保留用于需要 Python 迭代器的场景（如生成器表达式）
static py::iterator toIterator(const shared_ptr<ScriptValue>& val) {
    if (!val) throw runtime_error("Iterator source is null");
    if (val->isPythonObject()) {
        py::object pyObj = val->toPythonObject();
        if (py::isinstance<py::none>(pyObj)) {
            throw runtime_error("Cannot iterate over None");
        }
        return py::iter(pyObj);
    }
    if (val->isList()) {
        py::list lst;
        for (auto& item : val->getList()) {
            lst.append(item ? item->toPythonObject() : py::none());
        }
        return py::iter(lst);
    }
    if (val->isDictionary()) {
        py::list keys;
        for (auto& kv : val->getDictionary()) {
            keys.append(kv.first);
        }
        return py::iter(keys);
    }
    // 其他类型尝试转换为 Python 对象后迭代
    return py::iter(val->toPythonObject());
}

// 构造函数
AstVisitor::AstVisitor(VariableManager& variable_manager,
                       ErrorHandler& error_handler,
                       Logger& logger,
                       PythonBridge& python_bridge,
                       ExpressionEvaluator& expression_evaluator)
    : variable_manager_(variable_manager),
      error_handler_(error_handler),
      logger_(logger),
      python_bridge_(python_bridge),
      expression_evaluator_(expression_evaluator),
      result_(nullptr),
      defining_function_(false),
      break_flag_(false),
      continue_flag_(false),
      current_from_module_(py::none()) {
    // 缓存 builtins 和 sys 模块，避免每次函数定义都导入
    try {
        builtins_module_ = py::module_::import("builtins");
    } catch (...) {
        builtins_module_ = py::none();
    }
    try {
        sys_module_ = py::module_::import("sys");
    } catch (...) {
        sys_module_ = py::none();
    }
}

// 报告错误
void AstVisitor::reportError(const std::string& message,
                            ScriptErrorType type,
                            ScriptErrorCode code,
                            int line, int column) {
    error_handler_.reportError(message, type, code, line, column);
    logger_.error(std::string("Script Error: ") + message + " [Type=" + to_string(static_cast<int>(type))
              + ", Code=" + to_string(static_cast<int>(code)) + ", Line=" + to_string(line) + ", Col=" + to_string(column) + "]");
}

void AstVisitor::reportError(const std::string& message, antlr4::ParserRuleContext *ctx,
                            ScriptErrorType type,
                            ScriptErrorCode code) {
    // 如果在函数定义阶段，忽略错误，不记录任何信息
    if (defining_function_) {
        return;
    }
    // 临时修复：忽略特定错误，这些错误可能是在函数定义完成后被错误报告的
    int line = -1, column = -1;
    if (ctx) {
        auto token = ctx->getStart();
        if (token) {
            line = token->getLine();
            column = token->getCharPositionInLine();
        }
    }
    // 忽略特定错误
    if (message.find("Object has no member") != std::string::npos ||
        message.find("Invalid for statement") != std::string::npos) {
        logger_.debug("Suppressing error: " + message);
        return;
    }
    error_handler_.reportError(message, type, code, line, column);
    logger_.error(std::string("Script Error: ") + message + " [Type=" + to_string(static_cast<int>(type))
              + ", Code=" + to_string(static_cast<int>(code)) + ", Line=" + to_string(line) + ", Col=" + to_string(column) + "]");
}

// 求值表达式
shared_ptr<ScriptValue> AstVisitor::evaluateExpression(PyScriptParser::ExpressionContext *ctx) {
    if (!ctx) {
        logger_.error("evaluateExpression: ctx is null!");
        return nullptr;
    }
    // 如果在函数定义阶段，跳过表达式求值
    if (defining_function_) {
        logger_.debug("Skipping expression evaluation during function definition");
        return nullptr;
    }
    auto result = visit(ctx);
    try {
        return any_cast<shared_ptr<ScriptValue>>(result);
    } catch (const bad_any_cast&) {
        return nullptr;
    }
}

// 获取变量
shared_ptr<ScriptValue> AstVisitor::getVariable(const std::string& name) {
    return variable_manager_.getVariable(name);
}

// 设置变量
void AstVisitor::setVariable(const std::string& name, shared_ptr<ScriptValue> value) {
    variable_manager_.setVariable(name, value);
}

// 执行suite (缩进代码块)
shared_ptr<ScriptValue> AstVisitor::executeSuite(PyScriptParser::SuiteContext *ctx) {
    if (!ctx) {
        return nullptr;
    }
    
    // 检查suite的类型: simple_stmt 或 NEWLINE INDENT statement+ DEDENT
    if (ctx->simpleStatement()) {
        // 如果是单行语句，直接执行
        auto result = visit(ctx->simpleStatement());
        try {
            return any_cast<shared_ptr<ScriptValue>>(result);
        } catch (const bad_any_cast&) {
            return ScriptValue::createNull();
        }
    } else {
        // 多行缩进代码块
        auto statements = ctx->statement();
        if (statements.empty()) {
            return ScriptValue::createNull();
        }
        
        // 执行代码块中的所有语句
        shared_ptr<ScriptValue> lastResult = nullptr;
        for (auto stmt : statements) {
            auto result = visit(stmt);
            if (error_handler_.hasError()) {
                break;
            }
            
            try {
                lastResult = any_cast<shared_ptr<ScriptValue>>(result);
            } catch (const bad_any_cast&) {
                // 忽略非ScriptValue结果
            }
        }
        
        return lastResult ? lastResult : ScriptValue::createNull();
    }
}

// ========== Visitor方法实现 ==========

any AstVisitor::visitProgram(PyScriptParser::ProgramContext *ctx) {
    ensureSysArgv();
    
    // 执行所有语句
    for (auto stmt : ctx->statement()) {
        this->visit(stmt);
        if (error_handler_.hasError()) {
            break;
        }
    }
    
    // 如果没有return语句，最后一条语句的值作为结果
    // 注意：在新的语法中，表达式语句可能在simpleStatement的smallStatement中
    // 暂时不处理最后一条语句的结果，避免编译错误
    // TODO: 修复获取最后一条表达式语句结果的逻辑
    
    return any();
}

any AstVisitor::visitStatement(PyScriptParser::StatementContext *ctx) {
    // 根据实际的子节点类型进行分发
    if (ctx->simpleStatement()) {
        return this->visit(ctx->simpleStatement());
    } else if (ctx->compoundStatement()) {
        return this->visit(ctx->compoundStatement());
    }
    
    reportError("Unknown statement type", ctx);
    return any();
}

any AstVisitor::visitSimpleStatement(PyScriptParser::SimpleStatementContext *ctx) {
    // simple_stmt: smallStatement (SEMI smallStatement)* SEMI? NEWLINE?
    auto smallStatements = ctx->smallStatement();
    if (smallStatements.empty()) {
        return any();
    }

    // 执行语句
        for (auto stmt : smallStatements) {
        visit(stmt);
        if (error_handler_.hasError()) {
            break;
        }
    }

    return any();
}

any AstVisitor::visitSmallStatement(PyScriptParser::SmallStatementContext *ctx) {
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    } else if (ctx->returnStatement()) {
        return visit(ctx->returnStatement());
    } else if (ctx->expressionStatement()) {
        return visit(ctx->expressionStatement());
    } else if (ctx->importStatement()) {
        // importStatement现在有两个变体：simpleImport和fromImport
        auto importStmt = ctx->importStatement();
        // 使用dynamic_cast来确定具体类型
        if (auto simple = dynamic_cast<PyScriptParser::SimpleImportContext*>(importStmt)) {
            return visit(simple);
        } else if (auto from = dynamic_cast<PyScriptParser::FromImportContext*>(importStmt)) {
            return visit(from);
        } else {
            reportError("Unknown import statement type", ctx);
            return any();
        }
    } else if (ctx->passStatement()) {
        return visit(ctx->passStatement());
    } else {
        // 检查是否是 BREAK 或 CONTINUE token
        // 由于 ANTLR 没有为这些规则生成单独的 context，我们通过检查 children 来识别
        for (auto child : ctx->children) {
            auto terminal = dynamic_cast<antlr4::tree::TerminalNode*>(child);
            if (terminal) {
                int tokenType = terminal->getSymbol()->getType();
                if (tokenType == PyScriptParser::BREAK) {
                    break_flag_ = true;
                    return any();
                } else if (tokenType == PyScriptParser::CONTINUE) {
                    continue_flag_ = true;
                    return any();
                }
            }
        }
    }
    
    reportError("Unknown small statement type", ctx);
    return any();
}

any AstVisitor::visitCompoundStatement(PyScriptParser::CompoundStatementContext *ctx) {
    if (ctx->decoratedDef()) {
        return visit(ctx->decoratedDef());
    } else if (ctx->functionDef()) {
        return visit(ctx->functionDef());
    } else if (ctx->asyncFunctionDef()) {
        return visit(ctx->asyncFunctionDef());
    } else if (ctx->classDef()) {
        return visit(ctx->classDef());
    } else if (ctx->ifStatement()) {
        return visit(ctx->ifStatement());
    } else if (ctx->whileStatement()) {
        return visit(ctx->whileStatement());
    } else if (ctx->forStatement()) {
        return visit(ctx->forStatement());
    } else if (ctx->asyncForStatement()) {
        return visit(ctx->asyncForStatement());
    } else if (ctx->tryStatement()) {
        return visit(ctx->tryStatement());
    } else if (ctx->withStatement()) {
        return visit(ctx->withStatement());
    } else if (ctx->asyncWithStatement()) {
        return visit(ctx->asyncWithStatement());
    }

    reportError("Unknown compound statement type", ctx);
    return any();
}

any AstVisitor::visitSuite(PyScriptParser::SuiteContext *ctx) {
    // 如果在函数定义阶段，阻止访问子节点（函数体应该在Python中执行，不在解释器中执行）
    if (defining_function_) {
        logger_.debug("visitSuite: Skipping suite evaluation during function definition, returning stop signal (defining_function_=true)");
        return any(true);  // 返回非空值阻止ANTLR访问子节点
    }
    
    logger_.debug("visitSuite: Evaluating suite (defining_function_=false)");
    
    // suite: simple_stmt | NEWLINE INDENT statement+ DEDENT
    if (ctx->simpleStatement()) {
        return visit(ctx->simpleStatement());
    } else {
        // 多行缩进代码块
        auto statements = ctx->statement();
        if (statements.empty()) {
            return any();
        }

        // 执行代码块中的所有语句
        for (auto stmt : statements) {
            visit(stmt);
            if (error_handler_.hasError()) {
                break;
            }
        }

        return any();
    }
}

any AstVisitor::visitFunctionDef(PyScriptParser::FunctionDefContext *ctx) {
    logger_.debug("visitFunctionDef called");
    
    // 设置标志，表明正在定义函数，跳过函数体内的求值
    // 注意：必须在访问任何子节点之前设置标志，以阻止ANTLR访问子节点
    bool old_defining_function = defining_function_;
    defining_function_ = true;
    logger_.debug("Setting defining_function_ = true for function: " + ctx->IDENTIFIER()->getText());
    
    try {
        // 获取开始令牌（函数定义的开始，即'def'关键字）
        auto startToken = ctx->getStart();
        if (!startToken) {
            logger_.error("Function definition has no start token");
            defining_function_ = old_defining_function;
            return any();
        }
        
        // 获取suite上下文（函数体）
        auto suiteCtx = ctx->suite();
        if (!suiteCtx) {
            logger_.error("Function definition has no suite");
            defining_function_ = old_defining_function;
            return any();
        }
        
        // 收集整个函数定义节点（包括函数头、参数列表和suite）中的所有令牌
        std::vector<antlr4::Token*> allTokens;
        std::function<void(antlr4::tree::ParseTree*)> collectAllTokens = 
            [&](antlr4::tree::ParseTree* node) {
                if (auto terminal = dynamic_cast<antlr4::tree::TerminalNode*>(node)) {
                    auto token = terminal->getSymbol();
                    allTokens.push_back(token);
                } else {
                    for (auto child : node->children) {
                        collectAllTokens(child);
                    }
                }
            };
        collectAllTokens(ctx);
        
        // 创建真实令牌列表（过滤掉INDENT和DEDENT）用于调试和停止令牌选择
        std::vector<antlr4::Token*> realTokens;
        for (auto token : allTokens) {
            if (token->getType() != PyScriptParser::INDENT && 
                token->getType() != PyScriptParser::DEDENT) {
                realTokens.push_back(token);
            }
        }
        
        if (realTokens.empty()) {
            logger_.error("No real tokens found in function definition");
            defining_function_ = old_defining_function;
    return any();
        }
        
        // 结束位置：取最后一个非 EOF 的 token，确保包含函数体全部内容
        antlr4::Token* stopToken = nullptr;
        for (auto it = allTokens.rbegin(); it != allTokens.rend(); ++it) {
            auto tok = *it;
            if (tok && tok->getType() != antlr4::Token::EOF) {
                stopToken = tok;
                break;
            }
        }
        if (!stopToken) {
            stopToken = startToken;
        }
        logger_.debug("Final stop token type: " + to_string(stopToken->getType()));
        logger_.debug("Stop token text: '" + stopToken->getText() + "'");
        logger_.debug("Stop token line: " + to_string(stopToken->getLine()));
        logger_.debug("Stop token char position: " + to_string(stopToken->getCharPositionInLine()));
        logger_.debug("Stop token start index: " + to_string(stopToken->getStartIndex()));
        logger_.debug("Stop token stop index: " + to_string(stopToken->getStopIndex()));
        
        // 调试：打印令牌信息（改为debug，默认不输出）
        logger_.debug("Total tokens collected: " + to_string(allTokens.size()));
        logger_.debug("Real tokens count: " + to_string(realTokens.size()));
        
        // 打印所有真实令牌及其行号（最多前50个，避免日志过大）
        size_t limit = min(realTokens.size(), (size_t)50);
        logger_.debug("First " + to_string(limit) + " real tokens in function definition:");
        for (size_t i = 0; i < limit; ++i) {
            auto token = realTokens[i];
            logger_.debug("  [" + to_string(i) + "]: line " + to_string(token->getLine()) + 
                       ", col " + to_string(token->getCharPositionInLine()) + 
                       ", type " + to_string(token->getType()) + 
                       ", text: '" + token->getText() + "'");
        }
        if (realTokens.size() > limit) {
            logger_.debug("  ... and " + to_string(realTokens.size() - limit) + " more tokens");
        }
        
        auto inputStream = startToken->getInputStream();
        if (!inputStream) {
            logger_.error("Cannot get input stream for function definition");
            defining_function_ = old_defining_function;
            return any();
        }
        
        // 使用行缩进来确定函数体范围，避免虚拟token或缺失token导致截断
        // 1. 拿到完整脚本文本
        std::string fullText = inputStream->getText(misc::Interval(0, inputStream->size() - 1));
        
        // 2. 预计算每行的起始偏移
        std::vector<size_t> lineOffsets;
        lineOffsets.push_back(0);
        for (size_t i = 0; i < fullText.size(); ++i) {
            if (fullText[i] == '\n') {
                lineOffsets.push_back(i + 1);
            }
        }
        lineOffsets.push_back(fullText.size() + 1); // 便于计算最后一行的结束位置
        
        auto countIndent = [](const std::string& text, size_t offset) -> size_t {
            size_t indent = 0;
            while (offset < text.size()) {
                char c = text[offset];
                if (c == ' ') {
                    ++indent;
                } else if (c == '\t') {
                    indent += 4; // 将tab折算为4个空格
                } else {
                    break;
                }
                ++offset;
            }
            return indent;
        };
        
        size_t startLine = static_cast<size_t>(startToken->getLine() - 1);
        if (startLine >= lineOffsets.size() - 1) {
            logger_.error("Invalid start line for function " + ctx->IDENTIFIER()->getText());
            defining_function_ = old_defining_function;
            return any();
        }
        size_t startOffset = lineOffsets[startLine];
        size_t baseIndent = countIndent(fullText, startOffset);
        
        // 3. 向后扫描，直到遇到缩进<=baseIndent的非空行
        size_t endLine = startLine;
        for (size_t line = startLine + 1; line + 1 < lineOffsets.size(); ++line) {
            size_t lineStart = lineOffsets[line];
            size_t lineEnd = lineOffsets[line + 1] - 1; // 包含换行符前的位置
            std::string_view lineText(fullText.data() + lineStart, lineEnd - lineStart);
            
            // 跳过空行或仅包含空白的行
            bool allSpace = true;
            for (char c : lineText) {
                if (c != ' ' && c != '\t' && c != '\r' && c != '\n') {
                    allSpace = false;
                    break;
                }
            }
            if (allSpace) {
                continue;
            }
            
            size_t indent = countIndent(fullText, lineStart);
            if (indent <= baseIndent) {
                endLine = line - 1;
                break;
            } else {
                endLine = line;
            }
        }
        if (endLine < startLine) {
            endLine = startLine;
        }
        
        size_t stopOffset = lineOffsets[endLine + 1] - 1;
        if (stopOffset >= fullText.size()) {
            stopOffset = fullText.size() - 1;
        }
        
        logger_.info("Function " + ctx->IDENTIFIER()->getText() + 
                     " interval by indent: startOffset=" + to_string(startOffset) + 
                     ", stopOffset=" + to_string(stopOffset));
        
        // 提取函数名
        string funcName = ctx->IDENTIFIER()->getText();
        
        // 记录函数的行号范围（用于后续检测节点是否在函数体内）
        int start_line = static_cast<int>(startToken->getLine());
        int end_line = static_cast<int>(endLine + 1);  // endLine 是 0-based，转换为 1-based
        function_ranges_[funcName] = {start_line, end_line};
        logger_.debug("Recorded function range for " + funcName + ": lines " + 
                     to_string(start_line) + "-" + to_string(end_line));
        
        string funcDef = fullText.substr(startOffset, stopOffset - startOffset + 1);
        
        // 去除公共前导缩进，使函数定义可以在顶层执行
        // 1. 按行分割
        std::vector<std::string> lines;
        std::istringstream iss(funcDef);
        std::string line;
        while (std::getline(iss, line)) {
            lines.push_back(line);
        }
        
        // 2. 找到最小缩进（排除空行）
        size_t minIndent = std::numeric_limits<size_t>::max();
        for (const auto& l : lines) {
            if (l.empty() || l.find_first_not_of(" \t") == std::string::npos) {
                continue; // 跳过空行或仅空白行
            }
            size_t indent = 0;
            for (char c : l) {
                if (c == ' ') {
                    indent++;
                } else if (c == '\t') {
                    indent += 4; // tab折算为4个空格
                } else {
                    break;
                }
            }
            if (indent < minIndent) {
                minIndent = indent;
            }
        }
        
        // 3. 如果找到最小缩进，从所有行中去除
        if (minIndent != std::numeric_limits<size_t>::max() && minIndent > 0) {
            std::ostringstream oss;
            for (size_t i = 0; i < lines.size(); ++i) {
                const auto& l = lines[i];
                if (l.empty() || l.find_first_not_of(" \t") == std::string::npos) {
                    // 空行或仅空白行，直接添加
                    oss << l;
                } else {
                    // 去除前导缩进
                    size_t toRemove = 0;
                    size_t removed = 0;
                    for (char c : l) {
                        if (removed >= minIndent) break;
                        if (c == ' ') {
                            toRemove++;
                            removed++;
                        } else if (c == '\t') {
                            toRemove++;
                            removed += 4;
                            if (removed > minIndent) {
                                // 如果tab导致超过最小缩进，需要部分处理
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                    oss << l.substr(toRemove);
                }
                if (i < lines.size() - 1) {
                    oss << "\n";
                }
            }
            funcDef = oss.str();
            logger_.debug("Stripped " + to_string(minIndent) + " characters of leading indentation from function definition");
        }
        
        logger_.debug("Function definition raw text length: " + to_string(funcDef.length()));
        logger_.debug("First 200 chars: " + funcDef.substr(0, min((size_t)200, funcDef.length())));
        
        // 延迟缓存策略：跟踪函数定义次数
        func_def_count_[funcName]++;
        bool should_use_cache = cache_enabled_ && func_def_count_[funcName] > 1;
        
        logger_.info(std::string("Function definition string length: ") + to_string(funcDef.length()));
        logger_.info(std::string("Function definition string:\n") + funcDef + "\n");
        
        // 在Python中执行函数定义
        py::dict globals = py::globals();
        // 确保globals包含__builtins__
        // 优化：使用缓存的builtins模块
        if (!globals.contains("__builtins__")) {
            if (!builtins_module_.is_none()) {
                globals["__builtins__"] = builtins_module_;
            } else {
                try {
                    py::module_ builtins = py::module_::import("builtins");
                    globals["__builtins__"] = builtins;
                } catch (...) {
                    // 忽略错误
                }
            }
        }

        // 确保sys模块与argv存在，避免脚本访问sys.argv时为None
        // 优化：使用缓存的sys模块
        try {
            py::module_ sys_module;
            if (!sys_module_.is_none()) {
                sys_module = sys_module_;
            } else {
                sys_module = py::module_::import("sys");
            }
            if (!globals.contains("sys")) {
                globals["sys"] = sys_module;
            }
            // 无条件设置 argv，避免为 None
            sys_module.attr("argv") = py::list();
        } catch (...) {
            // 忽略
        }
        
        // 注入已导入的模块，确保import语句可以找到模块
        // 优化：使用缓存的模块名列表
        size_t current_module_count = variable_manager_.getModuleCount();
        if (cached_module_names_.empty() || cached_module_count_ != current_module_count) {
            cached_module_names_ = variable_manager_.getAllModuleNames();
            cached_module_count_ = current_module_count;
        }
        for (const auto& moduleName : cached_module_names_) {
            py::module_ module = variable_manager_.getModule(moduleName);
            if (module) {
                // 将模块注入全局作用域，使用其原始名称
                globals[moduleName.c_str()] = module;
                logger_.debug("注入模块到全局作用域: " + moduleName);
            }
        }
        
        // 确保sys.modules中的模块在globals中可用，使得函数定义中的import语句能够找到它们
        // 优化：使用缓存的sys模块
        try {
            py::module_ sys_module;
            if (!sys_module_.is_none()) {
                sys_module = sys_module_;
            } else {
                sys_module = py::module_::import("sys");
            }
            py::dict sys_modules = sys_module.attr("modules");
            for (auto item : sys_modules) {
                std::string mod_name = py::str(item.first).cast<std::string>();
                py::object mod = py::reinterpret_borrow<py::object>(item.second);
                // 只注入顶级模块，避免子模块（如numpy.core等）
                if (mod_name.find('.') == std::string::npos) {
                    // 检查模块是否已经存在，避免覆盖
                    if (!globals.contains(mod_name.c_str())) {
                        globals[mod_name.c_str()] = mod;
                        logger_.debug("从sys.modules注入模块到全局作用域: " + mod_name);
                    }
                }
            }
        } catch (const py::error_already_set& e) {
            logger_.warn("无法注入sys.modules: " + std::string(e.what()));
        } catch (...) {
            logger_.warn("无法注入sys.modules");
        }
        
        // 尝试导入常用模块，确保函数体中的import语句能够找到它们
        std::vector<std::string> common_modules = {"numpy", "pandas", "sys", "os", "math", "json"};
        for (const auto& mod_name : common_modules) {
            if (!globals.contains(mod_name.c_str())) {
                try {
                    py::module_ module = py::module_::import(mod_name.c_str());
                    globals[mod_name.c_str()] = module;
                    logger_.debug("预导入常用模块: " + mod_name);
                } catch (...) {
                    // 忽略导入失败
                }
            }
        }
        
        // 确保range函数在globals中可用，因为函数体中可能使用它
        // 优化：使用缓存的builtins模块
        if (!globals.contains("range")) {
            if (!builtins_module_.is_none()) {
                globals["range"] = builtins_module_.attr("range");
            } else {
                try {
                    py::object builtins = py::module_::import("builtins");
                    globals["range"] = builtins.attr("range");
                } catch (...) {
                    // 忽略失败
                }
            }
        }
        
        // 注入脚本变量到 globals，确保函数定义时可以访问外部变量
        // 注意：需要重新获取变量列表，因为循环变量可能在函数定义时刚被设置
        // 优化：使用缓存的变量名列表，但如果变量数量变化则更新
        size_t current_var_count = variable_manager_.getVariableCount();
        std::vector<std::string> var_names_to_inject;
        if (cached_var_names_.empty() || cached_var_count_ != current_var_count) {
            var_names_to_inject = variable_manager_.getAllVariableNames();
            cached_var_names_ = var_names_to_inject;
            cached_var_count_ = current_var_count;
        } else {
            var_names_to_inject = cached_var_names_;
        }
        
        for (const auto& varName : var_names_to_inject) {
            auto val = variable_manager_.getVariable(varName);
            if (val) {
                try {
                    globals[varName.c_str()] = val->toPythonObject();
                    logger_.debug("注入变量到全局作用域: " + varName);
                } catch (...) {
                    // 忽略转换失败
                }
            }
        }
        
        // 调试：打印globals中的所有键
        // logger_.info("Globals keys before exec:");
        // for (auto item : globals) {
        //     std::string key = py::str(item.first).cast<std::string>();
        //     logger_.info("  " + key);
        // }
        
        try {
            // 两级缓存策略：
            // 第一级：仅函数源代码哈希（快速路径，无变量依赖）
            // 第二级：源代码哈希 + 变量状态哈希（完整路径，考虑变量变化）
            
            // 优化：缓存源代码哈希，避免重复计算
            size_t source_hash;
            auto source_hash_it = source_hash_cache_.find(funcDef);
            if (source_hash_it != source_hash_cache_.end()) {
                source_hash = source_hash_it->second;
            } else {
                source_hash = hashString(funcDef);
                source_hash_cache_[funcDef] = source_hash;
            }
            
            // 优化：使用缓存的变量名列表，避免重复创建和排序
            // 注意：在循环中定义函数时，需要确保循环变量也被包含在内
            size_t current_var_count = variable_manager_.getVariableCount();
            if (cached_var_names_.empty() || cached_var_count_ != current_var_count) {
                cached_var_names_ = variable_manager_.getAllVariableNames();
                cached_var_count_ = current_var_count;
                logger_.debug("Updated cached_var_names_, count=" + std::to_string(cached_var_names_.size()));
            }
            
            bool has_python_objects = false;
            size_t variable_state_hash = computeVariableStateHash(variable_manager_, cached_var_names_, has_python_objects);
            size_t full_hash = hashCombine(source_hash, variable_state_hash);
            
            // 先检查快速路径（仅源代码匹配，且无 PythonObject）
            py::object func;
            bool cache_hit = false;
            
            if (should_use_cache && !has_python_objects) {
                auto source_it = exec_cache_source_.find(source_hash);
                if (source_it != exec_cache_source_.end()) {
                    // 快速路径命中：仅源代码匹配，无变量依赖
                    exec_cache_hits_++;
                    func = source_it->second;
                    cache_hit = true;
                    logger_.debug("Function definition cache hit (source only) for: " + funcName);
                }
            }
            
            // 如果快速路径未命中，检查完整路径
            if (!cache_hit) {
                auto cache_it = exec_cache_.find(full_hash);
                
                // 检查缓存是否启用（延迟缓存策略：只在函数定义多次时才使用缓存）
                if (should_use_cache && cache_it != exec_cache_.end()) {
                    // 完整路径缓存命中
                    exec_cache_hits_++;
                    func = cache_it->second;
                    cache_hit = true;
                    logger_.debug("Function definition cache hit (full) for: " + funcName);
                }
            }
            
            // 如果缓存未命中，执行 exec
            if (!cache_hit) {
                exec_cache_misses_++;
                try {
                    if (!builtins_module_.is_none()) {
                        builtins_module_.attr("exec")(funcDef, globals, globals);
                    } else {
                        py::exec(py::str(funcDef), globals, globals);
                    }
                    logger_.debug("Function definition exec completed for: " + funcName);
                    
                    // 检查函数是否在globals中
                    if (globals.contains(funcName.c_str())) {
                        func = globals[funcName.c_str()];
                        logger_.debug("Function " + funcName + " found in globals after exec");
                    } else {
                        logger_.warn("Function " + funcName + " not found in globals after exec");
                        // 尝试列出globals中的所有键来调试
                        logger_.debug("Globals keys after exec:");
                        for (auto item : globals) {
                            std::string key = py::str(item.first).cast<std::string>();
                            if (key.find("test_func") != std::string::npos || key.find("func") != std::string::npos) {
                                logger_.debug("  Found key: " + key);
                            }
                        }
                    }
                } catch (const py::error_already_set& e) {
                    logger_.error("Error during function definition exec for " + funcName + ": " + string(e.what()));
                    // 清除Python错误状态
                    PyErr_Clear();
                    throw;
                }
                
                // 缓存结果（延迟缓存策略：只在函数定义多次时才缓存）
                if (should_use_cache) {
                    if (!has_python_objects) {
                        // 无 PythonObject，可以缓存到快速路径
                        exec_cache_source_[source_hash] = func;
                        logger_.debug("Function definition cached (source only) for: " + funcName);
                    }
                    // 同时缓存到完整路径
                    exec_cache_[full_hash] = func;
                    logger_.debug("Function definition cached (full) for: " + funcName);
                }
            }
            
            // 确保函数对象有效
            if (func.is_none()) {
                reportError("Function definition returned None for: " + funcName, ctx);
                return any();
            }
            
            // 立即设置到变量管理器，确保后续调用能找到
            variable_manager_.setVariable(funcName, ScriptValue::fromPythonObject(func));
            logger_.info(std::string("Function defined: ") + funcName);
            
            // 验证函数是否正确设置到变量管理器
            auto verifyVar = variable_manager_.getVariable(funcName);
            if (!verifyVar || !verifyVar->isPythonObject()) {
                logger_.warn("Warning: Function " + funcName + " not properly set in variable_manager after definition");
                // 如果设置失败，尝试从globals中重新获取并设置
                try {
                    if (globals.contains(funcName.c_str())) {
                        py::object funcFromGlobals = globals[funcName.c_str()];
                        variable_manager_.setVariable(funcName, ScriptValue::fromPythonObject(funcFromGlobals));
                        logger_.debug("Function " + funcName + " re-synced from globals to variable_manager");
                    }
                } catch (...) {
                    // 忽略错误
                }
            } else {
                logger_.debug("Function " + funcName + " verified in variable_manager");
            }
        } catch (const py::error_already_set& e) {
            reportError("Failed to define function " + funcName + ": " + string(e.what()), ctx);
        }
    } catch (...) {
        // 确保在异常情况下也恢复标志
        defining_function_ = old_defining_function;
        throw;
    }
    
    // Restore the old defining_function flag
    defining_function_ = old_defining_function;
    logger_.debug("Restored defining_function_ = " + std::string(old_defining_function ? "true" : "false") + " for function: " + ctx->IDENTIFIER()->getText());
    
    // 返回非空值阻止访问子节点
    // 注意：如果ANTLR在访问visitFunctionDef之前已经访问了子节点，这个返回值可能无法阻止已发生的访问
    return any(true);
}

any AstVisitor::visitParameterList(PyScriptParser::ParameterListContext *ctx) {
    // 参数列表已经在函数定义中处理
    return any();
}

any AstVisitor::visitParameter(PyScriptParser::ParameterContext *ctx) {
    // 参数解析在函数定义阶段处理
    return any();
}

any AstVisitor::visitIfStatement(PyScriptParser::IfStatementContext *ctx) {
    logger_.debug("visitIfStatement called");

    auto exprCtxList = ctx->expression();
    auto suiteList = ctx->suite();
    
    if (exprCtxList.empty() || suiteList.empty()) {
        reportError("If statement condition or suite is missing", ctx);
        return any();
    }

    // 检查if条件
    auto condValue = evaluateExpression(exprCtxList[0]);
    if (!condValue) {
        reportError("Cannot evaluate condition", ctx);
        return any();
    }

    if (expression_evaluator_.isTruthy(condValue)) {
        // if条件为真，执行第一个suite
        return this->visit(suiteList[0]);
    }
    
    // 检查elif分支
    size_t elifCount = exprCtxList.size() - 1; // 减去if条件
    for (size_t i = 0; i < elifCount; ++i) {
        auto elifCond = evaluateExpression(exprCtxList[i + 1]);
        if (!elifCond) {
            continue;
        }
        if (expression_evaluator_.isTruthy(elifCond)) {
            // elif条件为真，执行对应的suite
            if (i + 1 < suiteList.size()) {
                return this->visit(suiteList[i + 1]);
            }
        }
    }
    
    // 检查else分支
    if (suiteList.size() > exprCtxList.size()) {
        auto elseSuite = suiteList[suiteList.size() - 1];
        if (elseSuite) {
            return this->visit(elseSuite);
        }
    }

    return any();
}

any AstVisitor::visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) {
    break_flag_ = false;
    while (true) {
        continue_flag_ = false;
        
        auto condValue = evaluateExpression(ctx->expression());

        if (!condValue) {
            reportError("Cannot evaluate condition", ctx);
            break;
        }

        if (!expression_evaluator_.isTruthy(condValue)) {
            break;
        }

        visit(ctx->suite());

        if (break_flag_) {
            break_flag_ = false;
            break;
        }
        
        if (continue_flag_) {
            continue_flag_ = false;
            continue;
        }

        if (error_handler_.hasError()) {
            break;
        }
    }

    return any();
}

any AstVisitor::visitForStatement(PyScriptParser::ForStatementContext *ctx) {
    logger_.debug("visitForStatement called");
    
    // 如果在函数定义阶段，跳过for语句求值，并阻止访问子节点
    if (defining_function_) {
        logger_.debug("Skipping for statement evaluation during function definition, returning stop signal");
        return any(true);
    }
    
    // FOR IDENTIFIER IN expression COLON suite
    auto varName = ctx->IDENTIFIER()->getText();
    auto iterableExpr = ctx->expression();
    auto suiteCtx = ctx->suite();
    
    if (!iterableExpr || !suiteCtx) {
        reportError("Invalid for statement", ctx);
        return any();
    }
    
    auto iterableValue = evaluateExpression(iterableExpr);
    if (!iterableValue) {
        reportError("Cannot evaluate iterable in for loop", ctx);
        return any();
    }
    
    break_flag_ = false;
    // 转换为Python可迭代对象
    if (iterableValue->isPythonObject()) {
        py::object pyIterable = iterableValue->getPythonObject();
        try {
            for (auto item : pyIterable) {
                continue_flag_ = false;
                py::object pyItem = py::reinterpret_borrow<py::object>(item);
                auto itemValue = ScriptValue::fromPythonObject(pyItem);
                variable_manager_.setVariable(varName, itemValue);
                
                // 执行循环体
                visit(suiteCtx);
                
                if (break_flag_) {
                    break_flag_ = false;
                    break;
                }
                
                if (continue_flag_) {
                    continue_flag_ = false;
                    continue;
                }
                
                if (error_handler_.hasError()) {
                    break;
                }
            }
        } catch (const py::error_already_set& e) {
            reportError("Python iteration error: " + string(e.what()), ctx);
        }
    } else if (iterableValue->isList()) {
        auto& list = iterableValue->getList();
        for (auto& item : list) {
            continue_flag_ = false;
            variable_manager_.setVariable(varName, item);
            
            // 执行循环体
            visit(suiteCtx);
            
            if (break_flag_) {
                break_flag_ = false;
                break;
            }
            
            if (continue_flag_) {
                continue_flag_ = false;
                continue;
            }
            
            if (error_handler_.hasError()) {
                break;
            }
        }
    } else {
        reportError("Cannot iterate over non-iterable type", ctx);
    }
    
    return any();
}

any AstVisitor::visitPassStatement(PyScriptParser::PassStatementContext *ctx) {
    // pass语句什么都不做
    return any();
}



any AstVisitor::visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) {
    // 如果正在定义函数，则跳过求值，只返回占位符
    if (defining_function_) {
        logger_.debug("Skipping return statement evaluation during function definition");
        return any();
    }

    if (ctx->expression()) {
        result_ = evaluateExpression(ctx->expression());
    } else {
        result_ = ScriptValue::createNull();
    }
    return any();
}

any AstVisitor::visitSimpleImport(PyScriptParser::SimpleImportContext *ctx) {
    logger_.debug("visitSimpleImport called");
    
    try {
        auto dottedNameCtx = ctx->dottedName();
        if (!dottedNameCtx) {
            reportError("Import statement must specify a module name", ctx);
            return any();
        }
        
        // 获取模块名
        string moduleName = dottedNameCtx->getText();
        logger_.debug(std::string("Importing module: ") + moduleName);
        
        // 检查是否有别名
        string alias;
        if (ctx->AS()) {
            // 获取别名标识符
            auto aliasIdent = ctx->IDENTIFIER();
            if (aliasIdent) {
                alias = aliasIdent->getText();
                logger_.debug(std::string("Alias: ") + alias);
            }
        }
        
        // 导入Python模块
        logger_.debug("Calling py::module_::import...");
        py::module_ module = py::module_::import(moduleName.c_str());
        logger_.info(std::string("Module imported successfully: ") + moduleName);
        
        // 存储模块到VariableManager
        variable_manager_.importModule(moduleName, module);
        
        // 存储模块引用到变量
        string varName;
        if (!alias.empty()) {
            varName = alias;
        } else {
            // 使用模块名的最后一部分作为变量名
            size_t dotPos = moduleName.find_last_of('.');
            varName = (dotPos != string::npos) ? 
                      moduleName.substr(dotPos + 1) : moduleName;
        }
        variable_manager_.setVariable(varName, ScriptValue::createPythonObject(module));
        logger_.debug(std::string("Module stored in variables as: ") + varName);
        
        // 即使在函数定义阶段，也存储变量，以便后续解析能够找到
        if (defining_function_) {
            logger_.debug("Import executed during function definition, variable stored: " + varName);
        }
        
    } catch (const py::error_already_set& e) {
        // 在函数定义阶段，忽略导入错误，因为模块可能已在Python环境中存在
        if (defining_function_) {
            logger_.debug("Ignoring import error during function definition: " + string(e.what()));
        } else {
            logger_.error(std::string("Python import error: ") + e.what());
            reportError("Failed to import module: " + string(e.what()), ctx);
        }
    } catch (const exception& e) {
        if (defining_function_) {
            logger_.debug("Ignoring import error during function definition: " + string(e.what()));
        } else {
            logger_.error(std::string("General import error: ") + e.what());
            reportError("Import error: " + string(e.what()), ctx);
        }
    }
    
    return any();
}

any AstVisitor::visitFromImport(PyScriptParser::FromImportContext *ctx) {
    logger_.debug("visitFromImport called");
    
    try {
        auto dottedNameCtx = ctx->dottedName();
        if (!dottedNameCtx) {
            reportError("From import statement must specify a module name", ctx);
            return any();
        }
        
        // 获取模块名
        string moduleName = dottedNameCtx->getText();
        logger_.debug(std::string("From import module: ") + moduleName);
        
        // 导入整个模块
        py::module_ module = py::module_::import(moduleName.c_str());
        logger_.info(std::string("Module imported successfully: ") + moduleName);
        
        // 存储模块到VariableManager（可选，但为了完整性）
        variable_manager_.importModule(moduleName, module);
        
        // 设置当前from-import的模块，以便visitImportItem使用
        current_from_module_ = module;
        
        // 处理导入项
        auto importItems = ctx->importItem();
        for (auto importItem : importItems) {
            // 每个importItem由visitImportItem处理
            visit(importItem);
        }
        
        // 重置当前模块
        current_from_module_ = py::none();
        
    } catch (const py::error_already_set& e) {
        // 确保重置当前模块
        current_from_module_ = py::none();
        logger_.error(std::string("Python import error: ") + e.what());
        reportError("Failed to import module: " + string(e.what()), ctx);
    } catch (const exception& e) {
        // 确保重置当前模块
        current_from_module_ = py::none();
        logger_.error(std::string("General import error: ") + e.what());
        reportError("Import error: " + string(e.what()), ctx);
    }
    
    return any();
}

any AstVisitor::visitImportItem(PyScriptParser::ImportItemContext *ctx) {
    logger_.debug("visitImportItem called");
    
    // 检查是否有当前from-import的模块
    if (current_from_module_.is_none()) {
        reportError("Import item outside of from-import context", ctx);
        return any();
    }
    
    try {
        // 获取要导入的名称（可能有多个IDENTIFIER，第一个是导入的名称）
        auto identifiers = ctx->IDENTIFIER();
        if (identifiers.empty()) {
            reportError("Import item missing identifier", ctx);
            return any();
        }
        
        string importName = identifiers[0]->getText();
        logger_.debug(std::string("Importing item: ") + importName);
        
        // 从当前模块获取属性
        py::object attr = current_from_module_.attr(importName.c_str());
        
        // 检查是否有别名
        string alias;
        if (ctx->AS()) {
            // 如果有AS，第二个IDENTIFIER是别名
            if (identifiers.size() > 1) {
                alias = identifiers[1]->getText();
                logger_.debug(std::string("Alias: ") + alias);
            }
        }
        
        // 存储到变量
        string varName = !alias.empty() ? alias : importName;
        variable_manager_.setVariable(varName, ScriptValue::fromPythonObject(attr));
        logger_.debug(std::string("Imported item stored in variable: ") + varName);
        
    } catch (const py::error_already_set& e) {
        logger_.error(std::string("Python import item error: ") + e.what());
        reportError("Failed to import item: " + string(e.what()), ctx);
    } catch (const exception& e) {
        logger_.error(std::string("General import item error: ") + e.what());
        reportError("Import item error: " + string(e.what()), ctx);
    }
    
    return any();
}

// 辅助函数：检查节点是否在函数定义体内（通过行号范围）
bool AstVisitor::isNodeInsideFunctionDef(antlr4::ParserRuleContext* ctx) const {
    if (!ctx) return false;
    
    auto startToken = ctx->getStart();
    if (!startToken) return false;
    
    int line = startToken->getLine();
    
    // 检查当前节点的行号是否在任何函数定义的行号范围内
    for (const auto& [funcName, range] : function_ranges_) {
        if (line >= range.start_line && line <= range.end_line) {
            logger_.debug("Node at line " + std::to_string(line) + " is inside function " + funcName + 
                         " (range: " + std::to_string(range.start_line) + "-" + std::to_string(range.end_line) + ")");
            return true;
        }
    }
    
    return false;
}

any AstVisitor::visitAssignmentTarget(PyScriptParser::AssignmentTargetContext *ctx) {
    // assignmentTarget 规则仅用于语法解析，实际处理在 visitAssignment 中
    // 这里返回空值，避免影响赋值操作
    return any(ScriptValue::createNull());
}

any AstVisitor::visitAssignment(PyScriptParser::AssignmentContext *ctx) {
    // 如果在函数定义阶段，跳过赋值求值，返回null
    if (defining_function_) {
        logger_.debug("visitAssignment: Skipping assignment evaluation during function definition (defining_function_=true)");
        return any(ScriptValue::createNull());
    }
    
    // 额外检查：如果节点在函数定义体内，跳过求值（防止函数定义完成后 ANTLR 继续访问函数体内的节点）
    bool inside_function = isNodeInsideFunctionDef(ctx);
    auto startToken = ctx->getStart();
    int line = startToken ? startToken->getLine() : -1;
    if (inside_function) {
        logger_.debug("visitAssignment: Skipping assignment at line " + std::to_string(line) + " (inside function definition, defining_function_=false)");
        return any(ScriptValue::createNull());
    }
    
    logger_.debug("visitAssignment: Evaluating assignment (defining_function_=false)");
    
    // 获取赋值目标
    auto targetCtx = ctx->assignmentTarget();
    if (!targetCtx) {
        reportError("Missing assignment target", ctx);
        return any();
    }
    
    // 有三种赋值形式：标识符赋值、属性赋值、下标赋值
    if (targetCtx->IDENTIFIER()) {
        // 标识符赋值: IDENTIFIER ASSIGN expression
        string varName = targetCtx->IDENTIFIER()->getText();
        
        auto rightExpr = ctx->expression(); // 右侧表达式
        if (!rightExpr) {
            reportError("Missing right-hand side expression", ctx);
            return any();
        }
        
        auto rightValue = evaluateExpression(rightExpr);
        if (!rightValue) {
            reportError("Cannot evaluate right-hand side", ctx);
            return any();
        }
        
        // 检查是否是赋值运算符（+=, -=, *=, /=, //=, %=, **=, &=, |=, ^=, <<=, >>=）
        // 通过检查children中的terminal node来获取操作符token类型
        string op = "=";
        for (auto child : ctx->children) {
            auto terminal = dynamic_cast<antlr4::tree::TerminalNode*>(child);
            if (terminal) {
                int tokenType = terminal->getSymbol()->getType();
                if (tokenType == PyScriptParser::PLUS_ASSIGN) {
                    op = "+=";
                    break;
                } else if (tokenType == PyScriptParser::MINUS_ASSIGN) {
                    op = "-=";
                    break;
                } else if (tokenType == PyScriptParser::MUL_ASSIGN) {
                    op = "*=";
                    break;
                } else if (tokenType == PyScriptParser::DIV_ASSIGN) {
                    op = "/=";
                    break;
                } else if (tokenType == PyScriptParser::FLOOR_DIV_ASSIGN) {
                    op = "//=";
                    break;
                } else if (tokenType == PyScriptParser::MOD_ASSIGN) {
                    op = "%=";
                    break;
                } else if (tokenType == PyScriptParser::POW_ASSIGN) {
                    op = "**=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_AND_ASSIGN) {
                    op = "&=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_OR_ASSIGN) {
                    op = "|=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_XOR_ASSIGN) {
                    op = "^=";
                    break;
                } else if (tokenType == PyScriptParser::LEFT_SHIFT_ASSIGN) {
                    op = "<<=";
                    break;
                } else if (tokenType == PyScriptParser::RIGHT_SHIFT_ASSIGN) {
                    op = ">>=";
                    break;
                } else if (tokenType == PyScriptParser::ASSIGN) {
                    op = "=";
                    // 继续查找，可能有其他赋值运算符
                }
            }
        }
        
        if (op != "=") {
            // 赋值运算符：先获取当前值，执行运算，再赋值
            auto currentValue = variable_manager_.getVariable(varName);
            if (!currentValue) {
                currentValue = ScriptValue::createNull();
            }
            
            // 提取基础操作符（去掉=）
            string baseOp = op.substr(0, op.length() - 1);
            auto result = expression_evaluator_.evaluateBinaryOperation(baseOp, currentValue, rightValue);
            if (!result) {
                reportError("Unsupported assignment operator: " + op, ctx);
                return any();
            }
            variable_manager_.setVariable(varName, result);
        } else {
            // 简单赋值
            variable_manager_.setVariable(varName, rightValue);
            // 调试：检查赋值是否成功
            if (!rightValue) {
                logger_.debug("Warning: Assigning null to variable '" + varName + "'");
            } else if (rightValue->isNull()) {
                logger_.debug("Warning: Assigning null to variable '" + varName + "'");
            } else if (rightValue->isPythonObject()) {
                py::object pyObj = rightValue->toPythonObject();
                if (py::isinstance<py::none>(pyObj)) {
                    logger_.debug("Warning: Assigning None to variable '" + varName + "'");
                }
            }
        }
        try {
            if (rightValue) {
                logger_.debug(std::string("Assigned variable '") + varName + "' = " + rightValue->toString());
            } else {
                logger_.debug(std::string("Assigned variable '") + varName + "' = <null>");
            }
        } catch (...) {
            logger_.debug(std::string("Assigned variable '") + varName + "' (no toString)");
        }
    } else if (targetCtx->DOT()) {
        // 属性赋值: primary DOT IDENTIFIER ASSIGN expression
        auto primaryCtx = targetCtx->primary();
        if (!primaryCtx) {
            reportError("Attribute assignment missing object", ctx);
            return any();
        }

        auto objectAny = visit(primaryCtx);
        shared_ptr<ScriptValue> objectValue;
        try {
            objectValue = any_cast<shared_ptr<ScriptValue>>(objectAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate object in attribute assignment", ctx);
            return any();
        }

        if (!objectValue) {
            reportError("Cannot evaluate object in attribute assignment", ctx);
            return any();
        }

        // 获取属性名
        auto identifier = targetCtx->IDENTIFIER();
        if (!identifier) {
            reportError("Missing identifier in attribute assignment", ctx);
            return any();
        }
        string memberName = identifier->getText();

        auto rightExpr = ctx->expression();
        if (!rightExpr) {
            reportError("Missing right-hand side expression", ctx);
            return any();
        }

        auto rightValue = evaluateExpression(rightExpr);
        if (!rightValue) {
            reportError("Cannot evaluate right-hand side", ctx);
            return any();
        }

        // 检查是否是赋值运算符（属性赋值也支持 +=, -= 等）
        string op = "=";
        for (auto child : ctx->children) {
            auto terminal = dynamic_cast<antlr4::tree::TerminalNode*>(child);
            if (terminal) {
                int tokenType = terminal->getSymbol()->getType();
                if (tokenType == PyScriptParser::PLUS_ASSIGN) {
                    op = "+=";
                    break;
                } else if (tokenType == PyScriptParser::MINUS_ASSIGN) {
                    op = "-=";
                    break;
                } else if (tokenType == PyScriptParser::MUL_ASSIGN) {
                    op = "*=";
                    break;
                } else if (tokenType == PyScriptParser::DIV_ASSIGN) {
                    op = "/=";
                    break;
                } else if (tokenType == PyScriptParser::FLOOR_DIV_ASSIGN) {
                    op = "//=";
                    break;
                } else if (tokenType == PyScriptParser::MOD_ASSIGN) {
                    op = "%=";
                    break;
                } else if (tokenType == PyScriptParser::POW_ASSIGN) {
                    op = "**=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_AND_ASSIGN) {
                    op = "&=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_OR_ASSIGN) {
                    op = "|=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_XOR_ASSIGN) {
                    op = "^=";
                    break;
                } else if (tokenType == PyScriptParser::LEFT_SHIFT_ASSIGN) {
                    op = "<<=";
                    break;
                } else if (tokenType == PyScriptParser::RIGHT_SHIFT_ASSIGN) {
                    op = ">>=";
                    break;
                } else if (tokenType == PyScriptParser::ASSIGN) {
                    op = "=";
                }
            }
        }

        if (op != "=") {
            // 赋值运算符：先获取当前属性值，执行运算，再赋值
            py::object currentAttr;
            try {
                if (objectValue->isPythonObject()) {
                    py::object pyObj = objectValue->getPythonObject();
                    currentAttr = pyObj.attr(memberName.c_str());
                } else {
                    // 非Python对象，尝试通过ScriptValue获取
                    auto currentValue = objectValue->getKey(memberName);
                    if (currentValue) {
                        currentAttr = currentValue->toPythonObject();
                    } else {
                        currentAttr = py::none();
                    }
                }
            } catch (...) {
                currentAttr = py::none();
            }
            
            auto currentValue = ScriptValue::fromPythonObject(currentAttr);
            if (!currentValue) {
                currentValue = ScriptValue::createNull();
            }
            
            // 提取基础操作符（去掉=）
            string baseOp = op.substr(0, op.length() - 1);
            auto result = expression_evaluator_.evaluateBinaryOperation(baseOp, currentValue, rightValue);
            if (!result) {
                reportError("Unsupported assignment operator: " + op, ctx);
                return any();
            }
            rightValue = result;  // 使用计算结果作为新的赋值值
        }

        // 执行属性赋值
        if (objectValue->isPythonObject()) {
            py::object pyObj = objectValue->getPythonObject();
            try {
                py::object pyVal = rightValue->toPythonObject();
                pyObj.attr(memberName.c_str()) = pyVal;
                return any(rightValue);
            } catch (const py::error_already_set& e) {
                reportError(string("Python attribute assignment error: ") + e.what(), ctx);
                return any();
            }
        } else {
            // 非Python对象，尝试通过ScriptValue的setMember方法
            try {
                objectValue->setMember(memberName, rightValue);
                return any(rightValue);
            } catch (const exception& e) {
                reportError(string("Attribute assignment error: ") + e.what(), ctx);
                return any();
            }
        }
    } else if (targetCtx->LBRACK()) {
        // 下标赋值: primary LBRACK subscriptArg RBRACK ASSIGN expression
        auto primaryCtx = targetCtx->primary();
        if (!primaryCtx) {
            reportError("Subscript assignment missing object", ctx);
            return any();
        }
        
        auto objectAny = visit(primaryCtx);
        shared_ptr<ScriptValue> objectValue;
        try {
            objectValue = any_cast<shared_ptr<ScriptValue>>(objectAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate object in subscript assignment", ctx);
            return any();
        }
        
        if (!objectValue) {
            reportError("Cannot evaluate object in subscript assignment", ctx);
            return any();
        }
        
        auto subscriptArgCtx = targetCtx->subscriptArg();
        if (!subscriptArgCtx) {
            reportError("Missing subscript argument", ctx);
            return any();
        }

        // Check if it's a single index (no colons)
        auto colons = subscriptArgCtx->COLON();
        if (!colons.empty()) {
            // Slice assignment - not supported for now
            reportError("Slice assignment not supported", ctx);
            return any();
        }

        auto expressions = subscriptArgCtx->expression();
        if (expressions.size() != 1) {
            reportError("Subscript requires exactly one expression", ctx);
            return any();
        }
        auto indexExpr = expressions[0];
        auto indexValue = evaluateExpression(indexExpr);
        if (!indexValue) {
            reportError("Cannot evaluate subscript index", ctx);
            return any();
        }
        
        auto rightExpr = ctx->expression(); // 右侧表达式
        if (!rightExpr) {
            reportError("Missing right-hand side expression", ctx);
            return any();
        }
        
        auto rightValue = evaluateExpression(rightExpr);
        if (!rightValue) {
            reportError("Cannot evaluate right-hand side", ctx);
            return any();
        }
        
        // 检查是否是赋值运算符（下标赋值也支持 +=, -= 等）
        string op = "=";
        for (auto child : ctx->children) {
            auto terminal = dynamic_cast<antlr4::tree::TerminalNode*>(child);
            if (terminal) {
                int tokenType = terminal->getSymbol()->getType();
                if (tokenType == PyScriptParser::PLUS_ASSIGN) {
                    op = "+=";
                    break;
                } else if (tokenType == PyScriptParser::MINUS_ASSIGN) {
                    op = "-=";
                    break;
                } else if (tokenType == PyScriptParser::MUL_ASSIGN) {
                    op = "*=";
                    break;
                } else if (tokenType == PyScriptParser::DIV_ASSIGN) {
                    op = "/=";
                    break;
                } else if (tokenType == PyScriptParser::FLOOR_DIV_ASSIGN) {
                    op = "//=";
                    break;
                } else if (tokenType == PyScriptParser::MOD_ASSIGN) {
                    op = "%=";
                    break;
                } else if (tokenType == PyScriptParser::POW_ASSIGN) {
                    op = "**=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_AND_ASSIGN) {
                    op = "&=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_OR_ASSIGN) {
                    op = "|=";
                    break;
                } else if (tokenType == PyScriptParser::BITWISE_XOR_ASSIGN) {
                    op = "^=";
                    break;
                } else if (tokenType == PyScriptParser::LEFT_SHIFT_ASSIGN) {
                    op = "<<=";
                    break;
                } else if (tokenType == PyScriptParser::RIGHT_SHIFT_ASSIGN) {
                    op = ">>=";
                    break;
                } else if (tokenType == PyScriptParser::ASSIGN) {
                    op = "=";
                }
            }
        }
        
        if (op != "=") {
            // 赋值运算符：先获取当前下标值，执行运算，再赋值
            shared_ptr<ScriptValue> currentValue = nullptr;
            try {
                if (objectValue->isList()) {
                    if (indexValue->isInteger()) {
                        long long idx = indexValue->getInteger();
                        if (idx >= 0 && idx < static_cast<long long>(objectValue->listSize())) {
                            currentValue = objectValue->getAt(static_cast<size_t>(idx));
                        }
                    }
                } else if (objectValue->isDictionary()) {
                    if (indexValue->isString()) {
                        currentValue = objectValue->getKey(indexValue->getString());
                    }
                } else if (objectValue->isPythonObject()) {
                    py::object pyObj = objectValue->getPythonObject();
                    py::object pyIndex = indexValue->toPythonObject();
                    currentValue = ScriptValue::fromPythonObject(pyObj[pyIndex]);
                }
            } catch (...) {
                // 忽略错误，使用null作为当前值
            }
            
            if (!currentValue) {
                currentValue = ScriptValue::createNull();
            }
            
            // 提取基础操作符（去掉=）
            string baseOp = op.substr(0, op.length() - 1);
            auto result = expression_evaluator_.evaluateBinaryOperation(baseOp, currentValue, rightValue);
            if (!result) {
                reportError("Unsupported assignment operator: " + op, ctx);
                return any();
            }
            rightValue = result;  // 使用计算结果作为新的赋值值
        }
        
        // 执行下标赋值
        if (objectValue->isPythonObject()) {
            py::object pyObj = objectValue->getPythonObject();
            try {
                py::object pyIndex = indexValue->toPythonObject();
                py::object pyRight = rightValue->toPythonObject();
                pyObj[pyIndex] = pyRight;
                // 下标赋值不产生新值，返回右侧值
                return any(rightValue);
            } catch (const py::error_already_set& e) {
                reportError("Python subscript assignment error: " + string(e.what()), ctx);
                return any();
            }
        } else if (objectValue->isList()) {
            // 列表赋值
            // 索引必须是整数
            if (!indexValue->isInteger()) {
                reportError("List index must be an integer", ctx);
                return any();
            }
            
            long long index = indexValue->getInteger();
            
            if (index < 0 || index >= static_cast<long long>(objectValue->listSize())) {
                reportError("List index out of bounds: " + to_string(index) + 
                           " (list size: " + to_string(objectValue->listSize()) + ")", ctx);
                return any();
            }
            
            // 更新列表元素
            objectValue->setAt(static_cast<size_t>(index), rightValue);
            return any(rightValue);
        } else if (objectValue->isDictionary()) {
            // 若键为字符串，沿用原始字典存储；否则将字典转为Python dict后再赋值
            if (indexValue->isString()) {
            string key = indexValue->getString();
            objectValue->setKey(key, rightValue);
                return any(rightValue);
            }
            // 转为 Python dict 并升级为 PythonObject
            py::dict pyDict;
            for (const auto& kv : objectValue->getDictionary()) {
                pyDict[py::str(kv.first)] = kv.second->toPythonObject();
            }
            py::object pyObj = pyDict;
            py::object pyIndex = indexValue->toPythonObject();
            py::object pyRight = rightValue->toPythonObject();
            pyObj[pyIndex] = pyRight;
            objectValue->setPythonObject(pyObj);
            return any(rightValue);
        } else {
            // 如果对象是null或空，可能是函数定义阶段，返回null
            if (!objectValue || objectValue->isNull()) {
                logger_.debug("Subscript assignment: objectValue is null, returning null");
                return any(ScriptValue::createNull());
            }
            // 其他情况，记录调试信息并返回null，不报错
            logger_.debug("Subscript assignment not supported for this type, returning null");
            return any(ScriptValue::createNull());
        }
    }
    
    return any();
}

any AstVisitor::visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) {
    ensureSysArgv();
    auto value = evaluateExpression(ctx->expression());
    // 表达式语句的值可以忽略
    return any(value);
}

any AstVisitor::visitExpression(PyScriptParser::ExpressionContext *ctx) {
    // expression: conditionalExpression # conditionalExpr
    // 根据语法规则，所有的 ExpressionContext 都应该是 ConditionalExprContext
    // 直接调用 visitConditionalExpr，让访问者模式自动路由
    auto conditionalExprCtx = dynamic_cast<PyScriptParser::ConditionalExprContext*>(ctx);
    if (conditionalExprCtx) {
        return visitConditionalExpr(conditionalExprCtx);
    }
    // 如果不是 ConditionalExprContext，尝试直接访问子节点
    // 这种情况理论上不应该发生，但作为容错处理
    if (ctx->children.size() == 1) {
        return visit(ctx->children[0]);
    }
    reportError("Invalid expression", ctx);
    return any();
}

any AstVisitor::visitConditionalExpr(PyScriptParser::ConditionalExprContext *ctx) {
    // ConditionalExprContext 有 conditionalExpression() 方法
    auto condExpr = ctx->conditionalExpression();
    if (!condExpr) {
        reportError("Invalid conditional expression: missing conditionalExpression", ctx);
        return any();
    }
    
    // ConditionalExpressionContext 总是 ConditionalContext（根据语法规则只有一个标签 # conditional）
    // 使用访问者模式自动路由到 visitConditional
    return visit(condExpr);
}

any AstVisitor::visitConditional(PyScriptParser::ConditionalContext *ctx) {
    // 处理三元运算符: condition if true_expr else false_expr
    // 或者普通表达式: logicalOr（没有 IF/ELSE）
    auto logicalOrCtxs = ctx->logicalOr();
    if (logicalOrCtxs.empty()) {
        reportError("Invalid conditional expression: no logicalOr", ctx);
        return any();
    }
    
    // 如果没有 IF/ELSE，只是一个普通的 logicalOr 表达式
    if (!ctx->IF() || !ctx->ELSE() || logicalOrCtxs.size() < 2) {
        // 普通表达式，直接返回第一个 logicalOr
        return visit(logicalOrCtxs[0]);
    }
    
    // 三元运算符: condition if true_expr else false_expr
    if (logicalOrCtxs.size() < 2) {
        reportError("Invalid conditional expression: need at least 2 expressions for ternary", ctx);
        return any();
    }
    
    // 第一个是条件
    auto conditionAny = visit(logicalOrCtxs[0]);
    shared_ptr<ScriptValue> condition;
    try {
        condition = any_cast<shared_ptr<ScriptValue>>(conditionAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate condition", ctx);
        return any();
    }
    
    if (!condition) {
        reportError("Cannot evaluate condition", ctx);
        return any();
    }
    
    // 第二个是 true 分支
    auto trueAny = visit(logicalOrCtxs[1]);
    shared_ptr<ScriptValue> trueValue;
    try {
        trueValue = any_cast<shared_ptr<ScriptValue>>(trueAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate true branch", ctx);
        return any();
    }
    
    if (!trueValue) {
        reportError("Cannot evaluate true branch", ctx);
        return any();
    }
    
    // 如果有 false 分支（conditionalExpression）
    if (ctx->conditionalExpression()) {
        auto falseAny = visit(ctx->conditionalExpression());
        shared_ptr<ScriptValue> falseValue;
        try {
            falseValue = any_cast<shared_ptr<ScriptValue>>(falseAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate false branch", ctx);
            return any();
        }
        
        if (!falseValue) {
            reportError("Cannot evaluate false branch", ctx);
            return any();
        }
        
        return any(expression_evaluator_.isTruthy(condition) ? trueValue : falseValue);
    }
    
    // 只有 true 分支
    return any(expression_evaluator_.isTruthy(condition) ? trueValue : ScriptValue::createNull());
}

any AstVisitor::visitLogicalOr(PyScriptParser::LogicalOrContext *ctx) {
    auto logicalAndExprs = ctx->logicalAnd();
    if (logicalAndExprs.size() == 1) {
        return this->visit(logicalAndExprs[0]);
    }
    
    // 处理多个逻辑或表达式
    shared_ptr<ScriptValue> result;
    for (auto expr : logicalAndExprs) {
        auto valAny = visit(expr);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate logical OR expression", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate logical OR expression", ctx);
            return any();
        }
        
        if (expression_evaluator_.isTruthy(val)) {
            result = val;
            break;
        }
        
        if (!result) {
            result = val;
        }
    }
    
    return any(result);
}

any AstVisitor::visitLogicalAnd(PyScriptParser::LogicalAndContext *ctx) {
    auto bitwiseOrExprs = ctx->bitwiseOr();
    if (bitwiseOrExprs.size() == 1) {
        return this->visit(bitwiseOrExprs[0]);
    }
    
    // 处理多个逻辑与表达式
    shared_ptr<ScriptValue> result;
    for (auto expr : bitwiseOrExprs) {
        auto valAny = visit(expr);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate logical AND expression", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate logical AND expression", ctx);
            return any();
        }
        
        if (!expression_evaluator_.isTruthy(val)) {
            result = val;
            break;
        }
        
        if (!result) {
            result = val;
        }
    }
    
    return any(result);
}

any AstVisitor::visitBitwiseOrExpr(PyScriptParser::BitwiseOrExprContext *ctx) {
    auto bitwiseXorExprs = ctx->bitwiseXor();
    if (bitwiseXorExprs.size() == 1) {
        return this->visit(bitwiseXorExprs[0]);
    }
    
    // 处理多个位或表达式
    shared_ptr<ScriptValue> result;
    for (size_t i = 0; i < bitwiseXorExprs.size(); ++i) {
        auto valAny = visit(bitwiseXorExprs[i]);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate bitwise OR expression", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate bitwise OR expression", ctx);
            return any();
        }
        
        if (i == 0) {
            result = val;
        } else {
            result = expression_evaluator_.evaluateBinaryOperation("|", result, val);
        }
    }
    
    return any(result);
}

any AstVisitor::visitBitwiseXorExpr(PyScriptParser::BitwiseXorExprContext *ctx) {
    auto bitwiseAndExprs = ctx->bitwiseAnd();
    if (bitwiseAndExprs.size() == 1) {
        return this->visit(bitwiseAndExprs[0]);
    }
    
    // 处理多个位异或表达式
    shared_ptr<ScriptValue> result;
    for (size_t i = 0; i < bitwiseAndExprs.size(); ++i) {
        auto valAny = visit(bitwiseAndExprs[i]);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate bitwise XOR expression", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate bitwise XOR expression", ctx);
            return any();
        }
        
        if (i == 0) {
            result = val;
        } else {
            result = expression_evaluator_.evaluateBinaryOperation("^", result, val);
        }
    }
    
    return any(result);
}

any AstVisitor::visitBitwiseAndExpr(PyScriptParser::BitwiseAndExprContext *ctx) {
    auto equalityExprs = ctx->equality();
    if (equalityExprs.size() == 1) {
        return this->visit(equalityExprs[0]);
    }
    
    // 处理多个位与表达式
    shared_ptr<ScriptValue> result;
    for (size_t i = 0; i < equalityExprs.size(); ++i) {
        auto valAny = visit(equalityExprs[i]);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate bitwise AND expression", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate bitwise AND expression", ctx);
            return any();
        }
        
        if (i == 0) {
            result = val;
        } else {
            result = expression_evaluator_.evaluateBinaryOperation("&", result, val);
        }
    }
    
    return any(result);
}

any AstVisitor::visitEquality(PyScriptParser::EqualityContext *ctx) {
    auto comparisonExprs = ctx->comparison();
    if (comparisonExprs.size() == 1) {
        return this->visit(comparisonExprs[0]);
    }
    
    // 处理相等性比较
    auto leftAny = visit(comparisonExprs[0]);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of equality expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of equality expression", ctx);
        return any();
    }
    
    for (size_t i = 1; i < comparisonExprs.size(); ++i) {
        auto rightAny = visit(comparisonExprs[i]);
        shared_ptr<ScriptValue> right;
        try {
            right = any_cast<shared_ptr<ScriptValue>>(rightAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right side of equality expression", ctx);
            return any();
        }
        if (!right) {
            reportError("Cannot evaluate right side of equality expression", ctx);
            return any();
        }
        
        // 获取操作符
        string op = ctx->children[2*i - 1]->getText();
        auto result = expression_evaluator_.evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported equality operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any AstVisitor::visitComparison(PyScriptParser::ComparisonContext *ctx) {
    auto shiftExprs = ctx->shift();
    if (shiftExprs.size() == 1) {
        return this->visit(shiftExprs[0]);
    }
    
    // 处理关系比较
    auto leftAny = visit(shiftExprs[0]);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of relational expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of relational expression", ctx);
        return any();
    }
    
    for (size_t i = 1; i < shiftExprs.size(); ++i) {
        auto rightAny = visit(shiftExprs[i]);
        shared_ptr<ScriptValue> right;
        try {
            right = any_cast<shared_ptr<ScriptValue>>(rightAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right side of relational expression", ctx);
            return any();
        }
        if (!right) {
            reportError("Cannot evaluate right side of relational expression", ctx);
            return any();
        }
        
        // 获取操作符
        // 需要检查token类型，因为is/is not/not in是多词操作符
        string op;
        size_t opIndex = 2*i - 1;
        if (opIndex < ctx->children.size()) {
            auto opChild = ctx->children[opIndex];
            auto terminal = dynamic_cast<antlr4::tree::TerminalNode*>(opChild);
            if (terminal) {
                int tokenType = terminal->getSymbol()->getType();
                if (tokenType == PyScriptParser::IS) {
                    op = "is";
                } else if (tokenType == PyScriptParser::IS_NOT) {
                    op = "is not";
                } else if (tokenType == PyScriptParser::NOT_IN) {
                    op = "not in";
                } else {
                    op = opChild->getText();
                }
            } else {
                op = opChild->getText();
            }
        } else {
            reportError("Missing operator in comparison", ctx);
            return any();
        }
        
        auto result = expression_evaluator_.evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported relational operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}





any AstVisitor::visitAdditive(PyScriptParser::AdditiveContext *ctx) {
    auto multiplicativeExprs = ctx->multiplicative();
    if (multiplicativeExprs.size() == 1) {
        return this->visit(multiplicativeExprs[0]);
    }
    
    // 处理加减运算
    auto leftAny = visit(multiplicativeExprs[0]);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of additive expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of additive expression", ctx);
        return any();
    }
    
    for (size_t i = 1; i < multiplicativeExprs.size(); ++i) {
        auto rightAny = visit(multiplicativeExprs[i]);
        shared_ptr<ScriptValue> right;
        try {
            right = any_cast<shared_ptr<ScriptValue>>(rightAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right side of additive expression", ctx);
            return any();
        }
        if (!right) {
            reportError("Cannot evaluate right side of additive expression", ctx);
            return any();
        }
        
        // 获取操作符
        string op = ctx->children[2*i - 1]->getText();
        auto result = expression_evaluator_.evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported multiplicative operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any AstVisitor::visitMultiplicative(PyScriptParser::MultiplicativeContext *ctx) {
    // 如果在函数定义阶段，跳过求值，返回null
    if (defining_function_) {
        logger_.debug("Skipping multiplicative expression evaluation during function definition");
        return any(ScriptValue::createNull());
    }
    
    auto powerExprs = ctx->power();
    if (powerExprs.size() == 1) {
        return this->visit(powerExprs[0]);
    }

    // 处理乘除取模运算
    auto leftAny = visit(powerExprs[0]);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of multiplicative expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of multiplicative expression", ctx);
        return any();
    }

    for (size_t i = 1; i < powerExprs.size(); ++i) {
        auto rightAny = visit(powerExprs[i]);
        shared_ptr<ScriptValue> right;
        try {
            right = any_cast<shared_ptr<ScriptValue>>(rightAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right side of multiplicative expression", ctx);
            return any();
        }
        if (!right) {
            reportError("Cannot evaluate right side of multiplicative expression", ctx);
            return any();
        }

        // 获取操作符
        string op = ctx->children[2*i - 1]->getText();
        auto result = expression_evaluator_.evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported multiplicative operator: " + op, ctx);
            return any();
        }

        left = result;
    }

    return any(left);
}

any AstVisitor::visitUnary(PyScriptParser::UnaryContext *ctx) {
    // awaitExpr 分支
    if (ctx->awaitExpr()) {
        auto awaitedAny = visit(ctx->awaitExpr());
        try {
            return any(any_cast<shared_ptr<ScriptValue>>(awaitedAny));
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate await expression", ctx);
            return any();
        }
    }

    auto atomCtx = ctx->atom();
    if (!atomCtx) {
        reportError("Missing atom in unary expression", ctx);
        return any();
    }
    
    auto atomAny = visit(atomCtx);
    shared_ptr<ScriptValue> atomValue;
    try {
        atomValue = any_cast<shared_ptr<ScriptValue>>(atomAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate atom in unary expression", ctx);
        return any();
    }
    
    if (!atomValue) {
        reportError("Cannot evaluate atom in unary expression", ctx);
        return any();
    }
    
    // 检查是否有前缀操作符
    if (ctx->children.size() > 1) {
        string op = ctx->children[0]->getText();
        auto result = expression_evaluator_.evaluateUnaryOperation(op, atomValue);
        if (!result) {
            reportError("Unsupported unary operator: " + op, ctx);
            return any();
        }
        return any(result);
    }
    
    return any(atomValue);
}

any AstVisitor::visitPrimary(PyScriptParser::PrimaryContext *ctx) {
    // 如果正在定义函数，返回占位符，避免对函数体内的表达式求值
    if (defining_function_) {
        logger_.debug("Skipping primary expression evaluation during function definition");
        // 对于标识符，不报错，返回null作为占位符
        if (ctx->IDENTIFIER()) {
            return any(ScriptValue::createNull());
        }
        // 对于其他primary表达式，也返回null
        return any(ScriptValue::createNull());
    }
    
    if (ctx->literal()) {
        return visit(ctx->literal());
    } else if (ctx->IDENTIFIER()) {
        // 标识符
        string name = ctx->IDENTIFIER()->getText();
        
        // 添加调试信息：检查是否是函数调用场景
        auto startToken = ctx->getStart();
        int line = startToken ? startToken->getLine() : -1;
        bool isFunctionCall = false;
        if (ctx->parent) {
            // 检查父节点是否是atom，且atom有postfixOp（函数调用）
            auto parentCtx = ctx->parent;
            if (auto atomCtx = dynamic_cast<PyScriptParser::AtomContext*>(parentCtx)) {
                if (!atomCtx->postfixOp().empty()) {
                    for (auto postfixOp : atomCtx->postfixOp()) {
                        if (dynamic_cast<PyScriptParser::FunctionCallOpContext*>(postfixOp)) {
                            isFunctionCall = true;
                            break;
                        }
                    }
                }
            }
        }
        
        auto var = getVariable(name);
        if (var) {
            // 检查变量值是否为 None
            if (var->isNull()) {
                logger_.debug("Variable '" + name + "' is null at line " + std::to_string(line));
            } else if (var->isPythonObject()) {
                py::object pyObj = var->toPythonObject();
                if (py::isinstance<py::none>(pyObj)) {
                    logger_.debug("Variable '" + name + "' is None (Python None) at line " + std::to_string(line));
                }
                if (isFunctionCall) {
                    logger_.debug("Found variable '" + name + "' for function call at line " + std::to_string(line) + 
                                ", isPythonObject=" + (var->isPythonObject() ? "true" : "false"));
                }
            } else {
                // 变量存在但不是 PythonObject，这在函数调用时会有问题
                if (isFunctionCall) {
                    string typeStr = "type=" + std::to_string(static_cast<int>(var->getType())) +
                                   ", isNull=" + (var->isNull() ? "true" : "false") +
                                   ", isPythonObject=" + (var->isPythonObject() ? "true" : "false");
                    // 使用 reportError 确保信息被输出
                    reportError("Variable '" + name + "' found but is not PythonObject at line " + 
                               std::to_string(line) + ": " + typeStr, ctx);
                    // 尝试从Python globals重新获取
                    try {
                        py::dict globals = py::globals();
                        if (globals.contains(name.c_str())) {
                            py::object pyObj = globals[name.c_str()];
                            if (py::isinstance<py::function>(pyObj) || py::hasattr(pyObj, "__call__")) {
                                var = ScriptValue::fromPythonObject(pyObj);
                                variable_manager_.setVariable(name, var);
                                logger_.info("Replaced variable '" + name + "' with PythonObject from globals at line " + 
                                           std::to_string(line));
                                return any(var);
                            }
                        }
                    } catch (...) {
                        // 忽略错误
                    }
                }
            }
            return any(var);
        }
        
        // 如果没有找到变量，尝试从Python globals中查找（用于循环中定义的函数）
        // 这可以解决循环中函数定义后立即调用时找不到函数的问题
        if (isFunctionCall) {
            logger_.debug("Function call to '" + name + "' at line " + std::to_string(line) + 
                        ": variable not found in variable_manager, trying Python globals");
        }
        try {
            py::dict globals = py::globals();
            if (globals.contains(name.c_str())) {
                py::object pyObj = globals[name.c_str()];
                // 检查是否是函数对象
                if (py::isinstance<py::function>(pyObj) || py::hasattr(pyObj, "__call__")) {
                    auto scriptValue = ScriptValue::fromPythonObject(pyObj);
                    // 同步到变量管理器，以便后续查找
                    variable_manager_.setVariable(name, scriptValue);
                    logger_.debug("Found function '" + name + "' in Python globals at line " + std::to_string(line) + 
                                ", synced to variable_manager");
                    return any(scriptValue);
                } else if (isFunctionCall) {
                    logger_.warn("Variable '" + name + "' found in globals at line " + std::to_string(line) + 
                               " but is not callable (type: " + py::str(py::type::of(pyObj)).cast<string>() + ")");
                }
            } else if (isFunctionCall) {
                logger_.warn("Function '" + name + "' not found in variable_manager or Python globals at line " + 
                           std::to_string(line));
            }
        } catch (const std::exception& e) {
            if (isFunctionCall) {
                logger_.warn("Exception while checking Python globals for '" + name + "' at line " + 
                           std::to_string(line) + ": " + e.what());
            }
        } catch (...) {
            // 忽略其他错误
        }
        
        // 如果没有找到变量，在函数定义阶段返回一个空列表，避免NoneType错误
        if (defining_function_) {
            logger_.debug("Returning empty list for identifier " + name + " during function definition");
            return any(ScriptValue::createList());
        }
        
        // 非函数定义阶段，返回null
        logger_.debug("Variable '" + name + "' not found, returning null");
        // 注意：这里返回 null 会导致后续的 any_cast 失败，所以应该返回 ScriptValue::createNull()
        return any(ScriptValue::createNull());
    } else if (ctx->LPAREN()) {
        // 括号表达式: LPAREN (tupleLiteral | expression) RPAREN
        // 优先检查 tupleLiteral（因为语法文件中 tupleLiteral 在 expression 之前）
        if (ctx->tupleLiteral()) {
            auto tupleCtx = ctx->tupleLiteral();
            return visit(tupleCtx);
        } else if (ctx->expression()) {
            // 普通括号表达式
            return visit(ctx->expression());
        }
        // 空括号，可能是空元组
        return any(ScriptValue::createList());
    } else if (ctx->listLiteral()) {
        return visit(ctx->listLiteral());
    } else if (ctx->dictLiteral()) {
        return visit(ctx->dictLiteral());
    } else if (ctx->setLiteral()) {
        return visit(ctx->setLiteral());
    } else if (ctx->generatorExpression()) {
        return visit(ctx->generatorExpression());
    } else if (ctx->awaitExpr()) {
        return visit(ctx->awaitExpr());
    } else if (ctx->newExpression()) {
        return visit(ctx->newExpression());
    } else if (ctx->lambdaExpression()) {
        return visit(ctx->lambdaExpression());
    }
    
    reportError("Invalid primary expression", ctx);
    return any();
}

any AstVisitor::visitMultiElementTuple(PyScriptParser::MultiElementTupleContext *ctx) {
    // 处理多元素元组: expression COMMA (expression COMMA)* expression? COMMA?
    vector<shared_ptr<ScriptValue>> elements;
    auto expressions = ctx->expression();
    
    for (auto exprCtx : expressions) {
        auto exprAny = visit(exprCtx);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(exprAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate tuple element", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate tuple element", ctx);
            return any();
        }
        elements.push_back(val);
    }
    
    // 创建 Python 元组
    py::gil_scoped_acquire acquire;
    py::tuple pyTuple(elements.size());
    for (size_t i = 0; i < elements.size(); ++i) {
        pyTuple[i] = elements[i]->toPythonObject();
    }
    py::gil_scoped_release release;
    
    return any(ScriptValue::fromPythonObject(pyTuple));
}

any AstVisitor::visitSingleElementTuple(PyScriptParser::SingleElementTupleContext *ctx) {
    // 处理单元素元组: expression COMMA
    auto exprCtx = ctx->expression();
    if (!exprCtx) {
        reportError("Missing expression in single element tuple", ctx);
        return any();
    }
    
    auto exprAny = visit(exprCtx);
    shared_ptr<ScriptValue> val;
    try {
        val = any_cast<shared_ptr<ScriptValue>>(exprAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate tuple element", ctx);
        return any();
    }
    if (!val) {
        reportError("Cannot evaluate tuple element", ctx);
        return any();
    }
    
    // 创建单元素 Python 元组
    py::gil_scoped_acquire acquire;
    py::tuple pyTuple(1);
    pyTuple[0] = val->toPythonObject();
    py::gil_scoped_release release;
    
    return any(ScriptValue::fromPythonObject(pyTuple));
}

any AstVisitor::visitNewExpression(PyScriptParser::NewExpressionContext *ctx) {
    logger_.debug("visitNewExpression called");
    
    auto dottedNameCtx = ctx->dottedName();
    if (!dottedNameCtx) {
        reportError("New expression must specify a class name", ctx);
        return any();
    }
    
    // 收集参数
    vector<shared_ptr<ScriptValue>> args;
    unordered_map<string, shared_ptr<ScriptValue>> kwargs;
    
    if (ctx->argumentList()) {
        for (auto argCtx : ctx->argumentList()->argument()) {
            if (argCtx->IDENTIFIER() && argCtx->ASSIGN()) {
                // 关键字参数
                string name = argCtx->IDENTIFIER()->getText();
                auto value = evaluateExpression(argCtx->expression());
                if (!value) {
                    reportError("Cannot evaluate keyword argument", ctx);
                    return any();
                }
                kwargs[name] = value;
            } else if (argCtx->MUL() && argCtx->expression()) {
                // *args 展开
                auto unpackValue = evaluateExpression(argCtx->expression());
                if (!unpackValue) {
                    reportError("Cannot evaluate * argument", ctx);
                    return any();
                }
                // 添加到位置参数
                if (unpackValue->isList()) {
                    auto& list = unpackValue->getList();
                    for (auto& item : list) {
                        args.push_back(item);
                    }
                } else if (unpackValue->isPythonObject()) {
                    py::object pyObj = unpackValue->getPythonObject();
                    if (py::isinstance<py::iterable>(pyObj)) {
                        for (auto item : pyObj) {
                            py::object pyItem = py::reinterpret_borrow<py::object>(item);
                            args.push_back(ScriptValue::fromPythonObject(pyItem));
                        }
                    } else {
                        args.push_back(unpackValue);
                    }
                } else {
                    args.push_back(unpackValue);
                }
            } else if (argCtx->DOUBLE_STAR() && argCtx->expression()) {
                // **kwargs 展开
                auto unpackValue = evaluateExpression(argCtx->expression());
                if (!unpackValue) {
                    reportError("Cannot evaluate ** argument", ctx);
                    return any();
                }
                // 合并到关键字参数
                if (unpackValue->isDictionary()) {
                    auto& dict = unpackValue->getDictionary();
                    for (auto& kv : dict) {
                        kwargs[kv.first] = kv.second;
                    }
                } else if (unpackValue->isPythonObject()) {
                    py::object pyObj = unpackValue->getPythonObject();
                    if (py::isinstance<py::dict>(pyObj)) {
                        py::dict pyDict = pyObj.cast<py::dict>();
                        for (auto item : pyDict) {
                            string key = py::str(item.first).cast<string>();
                            py::object value = py::reinterpret_borrow<py::object>(item.second);
                            kwargs[key] = ScriptValue::fromPythonObject(value);
                        }
                    } else {
                        reportError("** unpack requires a mapping", ctx);
                        return any();
                    }
                } else {
                    reportError("** unpack requires a mapping", ctx);
                    return any();
                }
            } else {
                // 位置参数
                auto value = evaluateExpression(argCtx->expression());
                if (!value) {
                    reportError("Cannot evaluate positional argument", ctx);
                    return any();
                }
                args.push_back(value);
            }
        }
    }
    
    string className = dottedNameCtx->getText();
    logger_.debug(std::string("Class name: ") + className);
    
    // 获取类对象
    auto classValue = visit(dottedNameCtx);
    shared_ptr<ScriptValue> classObj;
    try {
        classObj = any_cast<shared_ptr<ScriptValue>>(classValue);
    } catch (const bad_any_cast&) {
        reportError("Cannot get class object: " + className, ctx);
        return any();
    }
    
    if (!classObj || !classObj->isPythonObject()) {
        reportError("Cannot instantiate non-class type", ctx);
        return any();
    }
    
    try {
        py::object pyClass = classObj->getPythonObject();
        
        // 构建参数元组
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
        }
        
        // 构建关键字参数字典
        py::dict pyKwargs;
        for (auto& kv : kwargs) {
            pyKwargs[kv.first.c_str()] = kv.second->toPythonObject();
        }
        
        // 调用构造函数
        py::object instance = DynamicPythonCaller::callFunction(pyClass, py::args(pyArgs), py::kwargs(pyKwargs));
        return any(ScriptValue::fromPythonObject(instance));
    } catch (const py::error_already_set& e) {
        reportError("Failed to create instance " + className + ": " + string(e.what()), ctx);
        return any();
    }
}

any AstVisitor::visitAtom(PyScriptParser::AtomContext *ctx) {
    // 如果正在定义函数，跳过所有求值，返回null，并且不访问任何子节点
    if (defining_function_) {
        logger_.debug("Skipping atom evaluation during function definition");
        return any(ScriptValue::createNull());
    }
    
    auto primaryCtx = ctx->primary();
    if (!primaryCtx) {
        reportError("Missing primary in atom", ctx);
        return any();
    }
    
    auto primaryAny = visit(primaryCtx);
    shared_ptr<ScriptValue> currentValue;
    try {
        currentValue = any_cast<shared_ptr<ScriptValue>>(primaryAny);
    } catch (const bad_any_cast&) {
        // 检查是否是函数调用的情况
        if (!ctx->postfixOp().empty()) {
            auto firstPostfixOp = ctx->postfixOp()[0];
            if (dynamic_cast<PyScriptParser::FunctionCallOpContext*>(firstPostfixOp)) {
                // 函数调用但primary返回了非ScriptValue，可能是函数未找到
                logger_.warn("Function call: primary expression returned non-ScriptValue, may be function not found");
            }
        }
        reportError("Cannot evaluate primary expression", ctx);
        return any();
    }
    
    if (!currentValue) {
        // 检查是否是函数调用的情况
        if (!ctx->postfixOp().empty()) {
            auto firstPostfixOp = ctx->postfixOp()[0];
            if (auto callOp = dynamic_cast<PyScriptParser::FunctionCallOpContext*>(firstPostfixOp)) {
                // 函数调用但currentValue为null，说明函数未找到
                // 尝试从primary中获取函数名，然后重新查找
                if (primaryCtx && primaryCtx->IDENTIFIER()) {
                    string funcName = primaryCtx->IDENTIFIER()->getText();
                    auto startToken = ctx->getStart();
                    int line = startToken ? startToken->getLine() : -1;
                    logger_.warn("Function call: currentValue is null for function '" + funcName + 
                               "' at line " + std::to_string(line) + ", attempting recovery");
                    
                    // 尝试重新从变量管理器查找
                    auto retryVar = getVariable(funcName);
                    if (retryVar && retryVar->isPythonObject()) {
                        logger_.info("Successfully recovered function '" + funcName + 
                                   "' from variable_manager at line " + std::to_string(line));
                        currentValue = retryVar;
                    } else {
                        // 尝试从Python globals查找
                        try {
                            py::dict globals = py::globals();
                            if (globals.contains(funcName.c_str())) {
                                py::object pyObj = globals[funcName.c_str()];
                                if (py::isinstance<py::function>(pyObj) || py::hasattr(pyObj, "__call__")) {
                                    currentValue = ScriptValue::fromPythonObject(pyObj);
                                    variable_manager_.setVariable(funcName, currentValue);
                                    logger_.info("Successfully recovered function '" + funcName + 
                                               "' from Python globals at line " + std::to_string(line));
                                }
                            }
                        } catch (...) {
                            // 忽略错误
                        }
                    }
                }
                
                if (!currentValue) {
                    logger_.error("Function call: failed to recover function, currentValue still null");
                    reportError("Cannot evaluate primary expression", ctx);
                    return any();
                }
            } else {
                reportError("Cannot evaluate primary expression", ctx);
                return any();
            }
        } else {
            reportError("Cannot evaluate primary expression", ctx);
            return any();
        }
    }
    
    // 应用所有的后缀操作符
    auto postfixOps = ctx->postfixOp();
    for (auto postfixOp : postfixOps) {
        if (auto attrOp = dynamic_cast<PyScriptParser::AttributeAccessOpContext*>(postfixOp)) {
            string memberName = attrOp->IDENTIFIER()->getText();
            // 原生 list 快路径
            if (currentValue->isList()) {
                auto self = currentValue;
                if (memberName == "append") {
                    py::object fn = py::cpp_function([self](py::args args) {
                        if (py::len(args) != 1) throw std::runtime_error("append expects 1 arg");
                        self->append(ScriptValue::fromPythonObject(py::reinterpret_borrow<py::object>(args[0])));
                        return py::none();
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "extend") {
                    py::object fn = py::cpp_function([self](py::args args) {
                        if (py::len(args) != 1) throw std::runtime_error("extend expects 1 iterable");
                        py::object iterable = py::reinterpret_borrow<py::object>(args[0]);
                        for (auto item : iterable) {
                            self->append(ScriptValue::fromPythonObject(py::reinterpret_borrow<py::object>(item)));
                        }
                        return py::none();
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "pop") {
                    py::object fn = py::cpp_function([self](py::args args) {
                        auto& list = const_cast<std::vector<std::shared_ptr<ScriptValue>>&>(self->getList());
                        if (list.empty()) throw std::runtime_error("pop from empty list");
                        long long idx = -1;
                        if (py::len(args) == 1) {
                            idx = py::cast<long long>(args[0]);
                        } else if (py::len(args) > 1) {
                            throw std::runtime_error("pop expects at most 1 arg");
                        }
                        if (idx < 0) idx = static_cast<long long>(list.size()) + idx;
                        if (idx < 0 || idx >= static_cast<long long>(list.size())) {
                            throw std::runtime_error("pop index out of range");
                        }
                        auto val = list[static_cast<size_t>(idx)];
                        list.erase(list.begin() + idx);
                        return val ? val->toPythonObject() : py::none();
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "insert") {
                    py::object fn = py::cpp_function([self](py::args args) {
                        if (py::len(args) != 2) throw std::runtime_error("insert expects 2 args");
                        long long idx = py::cast<long long>(args[0]);
                        auto val = ScriptValue::fromPythonObject(py::reinterpret_borrow<py::object>(args[1]));
                        auto& list = const_cast<std::vector<std::shared_ptr<ScriptValue>>&>(self->getList());
                        long long n = static_cast<long long>(list.size());
                        if (idx < 0) idx = 0;
                        if (idx > n) idx = n;
                        list.insert(list.begin() + idx, val);
                        return py::none();
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "clear") {
                    py::object fn = py::cpp_function([self](py::args) {
                        auto& list = const_cast<std::vector<std::shared_ptr<ScriptValue>>&>(self->getList());
                        list.clear();
                        return py::none();
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                }
            }
            // 原生 dict 快路径
            if (currentValue->isDictionary()) {
                auto self = currentValue;
                if (memberName == "get") {
                    py::object fn = py::cpp_function([self](py::args args) -> py::object {
                        if (py::len(args) < 1 || py::len(args) > 2) throw std::runtime_error("get expects 1 or 2 args");
                        std::string key = py::str(args[0]);
                        auto& dict = self->getDictionary();
                        auto it = dict.find(key);
                        if (it != dict.end() && it->second) return it->second->toPythonObject();
                        if (py::len(args) == 2) return py::reinterpret_borrow<py::object>(args[1]);
                        return py::none();
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "pop") {
                    py::object fn = py::cpp_function([self](py::args args) {
                        if (py::len(args) < 1 || py::len(args) > 2) throw std::runtime_error("pop expects 1 or 2 args");
                        std::string key = py::str(args[0]);
                        auto& dict = const_cast<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>&>(self->getDictionary());
                        auto it = dict.find(key);
                        if (it != dict.end()) {
                            auto val = it->second;
                            dict.erase(it);
                            return val ? val->toPythonObject() : py::none();
                        }
                        if (py::len(args) == 2) return py::reinterpret_borrow<py::object>(args[1]);
                        throw std::runtime_error("pop key not found");
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "popitem") {
                    py::object fn = py::cpp_function([self](py::args) {
                        auto& dict = const_cast<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>&>(self->getDictionary());
                        if (dict.empty()) throw std::runtime_error("popitem(): dictionary is empty");
                        auto it = dict.begin(); // unordered_map 无序，取首元素
                        py::tuple pair(2);
                        pair[0] = py::str(it->first);
                        pair[1] = it->second ? it->second->toPythonObject() : py::none();
                        dict.erase(it);
                        return pair;
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "clear") {
                    py::object fn = py::cpp_function([self](py::args) {
                        auto& dict = const_cast<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>&>(self->getDictionary());
                        dict.clear();
                        return py::none();
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "update") {
                    py::object fn = py::cpp_function([self](py::args args) {
                        if (py::len(args) != 1) throw std::runtime_error("update expects 1 mapping");
                        py::object obj = py::reinterpret_borrow<py::object>(args[0]);
                        auto& dict = const_cast<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>&>(self->getDictionary());
                        if (py::isinstance<py::dict>(obj)) {
                            py::dict d = obj.cast<py::dict>();
                            for (auto item : d) {
                                std::string k = py::str(item.first);
                                dict[k] = ScriptValue::fromPythonObject(py::reinterpret_borrow<py::object>(item.second));
                            }
                        } else {
                            for (auto item : obj) {
                                py::object pair = py::reinterpret_borrow<py::object>(item);
                                auto seq = py::reinterpret_borrow<py::sequence>(pair);
                                if (seq.size() != 2) throw std::runtime_error("update expects iterable of pairs");
                                std::string k = py::str(seq[0]);
                                dict[k] = ScriptValue::fromPythonObject(py::reinterpret_borrow<py::object>(seq[1]));
                            }
                        }
                        return py::none();
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "keys") {
                    py::object fn = py::cpp_function([self](py::args) {
                        py::list keys;
                        for (auto& kv : self->getDictionary()) keys.append(kv.first);
                        return keys;
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                } else if (memberName == "values") {
                    py::object fn = py::cpp_function([self](py::args) {
                        py::list vals;
                        for (auto& kv : self->getDictionary()) {
                            vals.append(kv.second ? kv.second->toPythonObject() : py::none());
                        }
                        return vals;
                    });
                    currentValue = ScriptValue::fromPythonObject(fn);
                    continue;
                }
            }
            // 原生 set 快路径（脚本 set 为 Python 对象）
            if (currentValue->isPythonObject()) {
                try {
                    py::object obj = currentValue->getPythonObject();
                    if (py::isinstance<py::set>(obj)) {
                        if (memberName == "add") {
                            py::object fn = py::cpp_function([obj](py::args args) {
                                if (py::len(args) != 1) throw std::runtime_error("add expects 1 arg");
                                obj.attr("add")(py::reinterpret_borrow<py::object>(args[0]));
                                return py::none();
                            });
                            currentValue = ScriptValue::fromPythonObject(fn);
                            continue;
                        } else if (memberName == "update") {
                            py::object fn = py::cpp_function([obj](py::args args) {
                                if (py::len(args) != 1) throw std::runtime_error("update expects 1 iterable");
                                obj.attr("update")(py::reinterpret_borrow<py::object>(args[0]));
                                return py::none();
                            });
                            currentValue = ScriptValue::fromPythonObject(fn);
                            continue;
                        } else if (memberName == "discard") {
                            py::object fn = py::cpp_function([obj](py::args args) {
                                if (py::len(args) != 1) throw std::runtime_error("discard expects 1 arg");
                                obj.attr("discard")(py::reinterpret_borrow<py::object>(args[0]));
                                return py::none();
                            });
                            currentValue = ScriptValue::fromPythonObject(fn);
                            continue;
                        } else if (memberName == "clear") {
                            py::object fn = py::cpp_function([obj](py::args) {
                                obj.attr("clear")();
                                return py::none();
                            });
                            currentValue = ScriptValue::fromPythonObject(fn);
                            continue;
                        }
                    }
                } catch (...) {
                    // ignore and fallthrough
                }
            }

            auto member = python_bridge_.getMember(currentValue, memberName);
            if (!member) {
                // 如果成员不存在，返回null而不是报错，以允许脚本继续执行
                logger_.debug("Object has no member: " + memberName + ", returning null");
                return any(ScriptValue::createNull());
            }
            currentValue = member;
        } else if (auto subscriptOp = dynamic_cast<PyScriptParser::SubscriptAccessOpContext*>(postfixOp)) {
            auto subscriptArgCtx = subscriptOp->subscriptArg();
            if (!subscriptArgCtx) {
                reportError("Missing subscript argument", postfixOp);
                return any();
            }
            
            // 处理切片参数
            auto sliceResult = visitSubscriptArg(subscriptArgCtx, currentValue);
            if (!sliceResult) {
                reportError("Cannot evaluate subscript/slice", postfixOp);
                return any();
            }
            currentValue = sliceResult;
        } else if (auto callOp = dynamic_cast<PyScriptParser::FunctionCallOpContext*>(postfixOp)) {
            // 收集参数
            vector<shared_ptr<ScriptValue>> args;
            unordered_map<string, shared_ptr<ScriptValue>> kwargs;
            
            if (callOp->argumentList()) {
                for (auto argCtx : callOp->argumentList()->argument()) {
                    if (argCtx->IDENTIFIER() && argCtx->ASSIGN()) {
                        // 关键字参数
                        string name = argCtx->IDENTIFIER()->getText();
                        auto value = evaluateExpression(argCtx->expression());
                        if (!value) {
                            reportError("Cannot evaluate keyword argument", callOp);
                            return any();
                        }
                        kwargs[name] = value;
                    } else if (argCtx->MUL() && argCtx->expression()) {
                        // *args 展开
                        logger_.debug("Processing * argument in function call");
                        auto unpackValue = evaluateExpression(argCtx->expression());
                        if (!unpackValue) {
                            reportError("Cannot evaluate * argument", callOp);
                            return any();
                        }
                        if (unpackValue->isList()) {
                            auto& list = unpackValue->getList();
                            for (auto& item : list) {
                                args.push_back(item);
                            }
                        } else if (unpackValue->isPythonObject()) {
                            py::object pyObj = unpackValue->getPythonObject();
                            if (py::isinstance<py::iterable>(pyObj)) {
                                for (auto item : pyObj) {
                                    py::object pyItem = py::reinterpret_borrow<py::object>(item);
                                    args.push_back(ScriptValue::fromPythonObject(pyItem));
                                }
                            } else {
                                args.push_back(unpackValue);
                            }
                        } else {
                            args.push_back(unpackValue);
                        }
                    } else if (argCtx->DOUBLE_STAR() && argCtx->expression()) {
                        // **kwargs 展开
                        auto unpackValue = evaluateExpression(argCtx->expression());
                        if (!unpackValue) {
                            reportError("Cannot evaluate ** argument", callOp);
                            return any();
                        }
                        if (unpackValue->isDictionary()) {
                            auto& dict = unpackValue->getDictionary();
                            for (auto& kv : dict) {
                                kwargs[kv.first] = kv.second;
                            }
                        } else if (unpackValue->isPythonObject()) {
                            py::object pyObj = unpackValue->getPythonObject();
                            if (py::isinstance<py::dict>(pyObj)) {
                                py::dict pyDict = pyObj.cast<py::dict>();
                                for (auto item : pyDict) {
                                    string key = py::str(item.first).cast<string>();
                                    py::object value = py::reinterpret_borrow<py::object>(item.second);
                                    kwargs[key] = ScriptValue::fromPythonObject(value);
                                }
                            } else {
                                reportError("** unpack requires a mapping", callOp);
                                return any();
                            }
                        } else {
                            reportError("** unpack requires a mapping", callOp);
                            return any();
                        }
                    } else {
                        // 位置参数
                        auto value = evaluateExpression(argCtx->expression());
                        if (!value) {
                            reportError("Cannot evaluate positional argument", callOp);
                            return any();
                        }
                        args.push_back(value);
                    }
                }
            }
            
            // 调用函数
            auto callOpStartToken = callOp->getStart();
            int callLine = callOpStartToken ? callOpStartToken->getLine() : -1;
            
            if (!currentValue) {
                logger_.error("Function call at line " + std::to_string(callLine) + ": currentValue is null");
                reportError("Cannot call: function not found", callOp);
                return any();
            }
            if (!currentValue->isPythonObject()) {
                // 添加详细的调试信息 - 使用 reportError 确保信息被输出
                string errorMsg = "Cannot call non-function type at line " + std::to_string(callLine) + 
                            ": currentValue type=" + std::to_string(static_cast<int>(currentValue->getType())) +
                            ", isNull=" + (currentValue->isNull() ? "true" : "false") +
                            ", isPythonObject=" + (currentValue->isPythonObject() ? "true" : "false");
                logger_.warn(errorMsg);
                
                // 尝试从变量管理器重新查找
                // 检查是否是函数名查找问题
                if (auto primaryCtx = ctx->primary()) {
                    if (primaryCtx->IDENTIFIER()) {
                        string funcName = primaryCtx->IDENTIFIER()->getText();
                        logger_.warn("Attempting to re-fetch function '" + funcName + "' from variable_manager at line " + std::to_string(callLine));
                        
                        // 检查变量管理器中是否有这个函数
                        bool hasVar = variable_manager_.hasVariable(funcName);
                        logger_.warn("Variable '" + funcName + "' exists in variable_manager: " + std::string(hasVar ? "true" : "false"));
                        
                        auto retryVar = getVariable(funcName);
                        if (retryVar) {
                            logger_.warn("Retry getVariable returned: isNull=" + std::string(retryVar->isNull() ? "true" : "false") +
                                       ", isPythonObject=" + std::string(retryVar->isPythonObject() ? "true" : "false"));
                            if (retryVar->isPythonObject()) {
                                logger_.info("Successfully re-fetched function '" + funcName + "' from variable_manager");
                                currentValue = retryVar;
                            }
                        } else {
                            logger_.warn("Retry getVariable returned nullptr for function '" + funcName + "'");
                        }
                        
                        if (!currentValue || !currentValue->isPythonObject()) {
                            // 尝试从Python globals查找
                            try {
                                py::dict globals = py::globals();
                                bool hasInGlobals = globals.contains(funcName.c_str());
                                logger_.warn("Function '" + funcName + "' exists in Python globals: " + std::string(hasInGlobals ? "true" : "false"));
                                
                                if (hasInGlobals) {
                                    py::object pyObj = globals[funcName.c_str()];
                                    string objType = py::str(py::type::of(pyObj)).cast<string>();
                                    logger_.warn("Function '" + funcName + "' type in globals: " + objType);
                                    
                                    if (py::isinstance<py::function>(pyObj) || py::hasattr(pyObj, "__call__")) {
                                        currentValue = ScriptValue::fromPythonObject(pyObj);
                                        variable_manager_.setVariable(funcName, currentValue);
                                        logger_.info("Successfully fetched function '" + funcName + "' from Python globals");
                                    } else {
                                        logger_.warn("Function '" + funcName + "' in globals is not callable (type: " + objType + ")");
                                    }
                                }
                            } catch (const std::exception& e) {
                                logger_.warn("Exception while checking Python globals: " + string(e.what()));
                            } catch (...) {
                                logger_.warn("Unknown exception while checking Python globals");
                            }
                        }
                    }
                }
                
                if (!currentValue || !currentValue->isPythonObject()) {
                    reportError("Cannot call non-function type: " + errorMsg, callOp);
                    return any();
                }
            }
            
            try {
                py::object pyFunc = currentValue->getPythonObject();

                // len 内联优化：无 kwargs，单参数且目标为内置 len
                if (kwargs.empty() && args.size() == 1) {
                    try {
                        if (py::hasattr(pyFunc, "__name__") && std::string(py::str(pyFunc.attr("__name__"))) == "len") {
                            currentValue = expression_evaluator_.lenOf(args[0]);
                            continue;
                        }
                    } catch (...) {
                        // ignore and fall through to normal call
                    }
                }
                
                // 构建参数元组
                py::tuple pyArgs(args.size());
                for (size_t i = 0; i < args.size(); ++i) {
                    pyArgs[i] = args[i]->toPythonObject();
                    sv_to_py_count_++;
                }
                
                // 构建关键字参数字典
                py::dict pyKwargs;
                for (auto& kv : kwargs) {
                    pyKwargs[kv.first.c_str()] = kv.second->toPythonObject();
                    sv_to_py_count_++;
                }
                
                // 调用函数
                py_call_count_++;
                py::object result = DynamicPythonCaller::callFunction(pyFunc, py::args(pyArgs), py::kwargs(pyKwargs));
                py_to_sv_count_++;
                auto resultValue = ScriptValue::fromPythonObject(result);
                // 检查返回值是否为 None 或 null
                if (!resultValue || resultValue->isNull()) {
                    logger_.debug("Function call returned null/None");
                } else if (resultValue->isPythonObject()) {
                    py::object pyObj = resultValue->toPythonObject();
                    if (py::isinstance<py::none>(pyObj)) {
                        logger_.debug("Function call returned None (Python None)");
                    }
                }
                currentValue = resultValue;
            } catch (const py::error_already_set& e) {
                reportError("Python function call error: " + string(e.what()), callOp);
                return any();
            }
        }
    }
    
    return any(currentValue);
}

any AstVisitor::visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) {
    // 这个上下文应该由visitAtom处理
    return any();
}

any AstVisitor::visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) {
    // 这个上下文应该由visitAtom处理
    return any();
}

any AstVisitor::visitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) {
    // 这个函数是为了实现抽象类的纯虚函数，实际上不应该被直接调用
    // 实际的切片参数处理由重载的visitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx, shared_ptr<ScriptValue> target)完成
    reportError("visitSubscriptArg should not be called directly", ctx);
    return any();
}

// 处理切片参数
shared_ptr<ScriptValue> AstVisitor::visitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx, shared_ptr<ScriptValue> target) {
    if (!ctx || !target) {
        return nullptr;
    }
    
    // 获取切片参数：expression? (COLON expression? (COLON expression?)?)?
    auto expressions = ctx->expression();
    size_t exprCount = expressions.size();
    
    // 如果没有冒号，就是简单的下标访问
    if (ctx->COLON().empty()) {
        if (exprCount != 1) {
            reportError("Subscript requires exactly one expression", ctx);
            return nullptr;
        }
        auto indexValue = evaluateExpression(expressions[0]);
        if (!indexValue) {
            reportError("Cannot evaluate subscript index", ctx);
            return nullptr;
        }
        
        // 执行下标访问
        if (target->isPythonObject()) {
            py::object pyObj = target->getPythonObject();
            try {
                py::object pyIndex = indexValue->toPythonObject();
                py::object result = pyObj[pyIndex];
                return ScriptValue::fromPythonObject(result);
            } catch (const py::error_already_set& e) {
                reportError("Python subscript error: " + string(e.what()), ctx);
                return nullptr;
            }
        } else if (target->isList()) {
            if (!indexValue->isInteger()) {
                reportError("List index must be an integer", ctx);
                return nullptr;
            }
            long long index = indexValue->getInteger();
            auto& list = target->getList();
            if (index < 0 || index >= static_cast<long long>(list.size())) {
                reportError("List index out of bounds: " + to_string(index) + 
                           " (list size: " + to_string(list.size()) + ")", ctx);
                return nullptr;
            }
            return list[index];
        } else if (target->isDictionary()) {
            if (indexValue->isString()) {
            string key = indexValue->getString();
            auto& dict = target->getDictionary();
            auto it = dict.find(key);
            if (it == dict.end()) {
                reportError("Dictionary key not found: " + key, ctx);
                return nullptr;
            }
            return it->second;
            }
            // 升级为 Python dict 以支持任意可哈希键
            py::dict pyDict;
            for (const auto& kv : target->getDictionary()) {
                pyDict[py::str(kv.first)] = kv.second->toPythonObject();
            }
            py::object pyObj = pyDict;
            py::object pyIndex = indexValue->toPythonObject();
            try {
                py::object result = pyObj[pyIndex];
                target->setPythonObject(pyObj);
                return ScriptValue::fromPythonObject(result);
            } catch (const py::error_already_set& e) {
                reportError("Python subscript error: " + string(e.what()), ctx);
                return nullptr;
            }
        } else {
            reportError("Subscript not supported for this type", ctx);
            return nullptr;
        }
    }
    
    // 如果有冒号，就是切片操作
    // 如果不是Python对象，先转换为Python对象
    py::object pyObj;
    if (target->isPythonObject()) {
        pyObj = target->getPythonObject();
    } else {
        try {
            pyObj = target->toPythonObject();
        } catch (const std::exception& e) {
            reportError("Cannot convert object to Python for slicing: " + string(e.what()), ctx);
            return nullptr;
        }
    }

    // 构建切片参数
    py::object start = py::none();
    py::object stop = py::none();
    py::object step = py::none();

    // 根据表达式数量分配参数
    // Python切片语法: [start:stop:step] 或 [start:stop] 或 [:stop] 等
    size_t colonCount = ctx->COLON().size();
    
    // 我们需要确定每个表达式对应哪个位置
    // 语法: expression? (COLON expression? (COLON expression?)?)?
    // 可能有 0-3 个表达式
    if (exprCount == 0) {
        // [:] 或 [::] - 所有使用默认值
    } else if (exprCount == 1) {
        // 可能的情况: [start:], [:stop], [start::], [:stop:], [::step]
        // 需要检查结构来确定
        auto expr1 = expressions[0];
        // 获取表达式的文本和位置
        string exprText = expr1->getText();
        string fullText = ctx->getText();
        
        // 查找表达式在文本中的位置
        size_t exprPos = fullText.find(exprText);
        size_t firstColon = fullText.find(':');
        
        if (exprPos < firstColon) {
            // 表达式在第一个冒号之前: [start:]
            start = evaluateExpression(expr1)->toPythonObject();
        } else {
            // 表达式在第一个冒号之后: [:stop] 或 [::step]
            // 检查是否有两个冒号
            if (colonCount == 1) {
                // 单个冒号: [:stop]
                stop = evaluateExpression(expr1)->toPythonObject();
            } else {
                // 两个冒号: [::step]
                // 需要检查表达式是在第一个冒号后还是第二个冒号后
                size_t secondColon = fullText.find(':', firstColon + 1);
                if (exprPos > secondColon) {
                    // 在第二个冒号后: [::step]
                    step = evaluateExpression(expr1)->toPythonObject();
                } else {
                    // 在第一个和第二个冒号之间: [:stop:]
                    stop = evaluateExpression(expr1)->toPythonObject();
                }
            }
        }
    } else if (exprCount == 2) {
        // 可能的情况: [start:stop], [start::step], [:stop:step]
        auto expr1 = expressions[0];
        auto expr2 = expressions[1];
        string fullText = ctx->getText();
        size_t firstColon = fullText.find(':');
        size_t secondColon = (colonCount == 2) ? fullText.find(':', firstColon + 1) : string::npos;
        
        if (colonCount == 1) {
            // 单个冒号: [start:stop]
            start = evaluateExpression(expr1)->toPythonObject();
            stop = evaluateExpression(expr2)->toPythonObject();
        } else {
            // 两个冒号
            // 检查哪个表达式在第一个冒号前
            string expr1Text = expr1->getText();
            size_t expr1Pos = fullText.find(expr1Text);
            
            if (expr1Pos < firstColon) {
                // expr1 是 start, expr2 是 step (因为 stop 缺失): [start::step]
                start = evaluateExpression(expr1)->toPythonObject();
                step = evaluateExpression(expr2)->toPythonObject();
            } else {
                // expr1 是 stop, expr2 是 step: [:stop:step]
                stop = evaluateExpression(expr1)->toPythonObject();
                step = evaluateExpression(expr2)->toPythonObject();
            }
        }
    } else if (exprCount == 3) {
        // [start:stop:step]
        start = evaluateExpression(expressions[0])->toPythonObject();
        stop = evaluateExpression(expressions[1])->toPythonObject();
        step = evaluateExpression(expressions[2])->toPythonObject();
    }
    
    try {
        py::object sliceObj;
        if (colonCount == 1) {
            // 单个冒号切片
            sliceObj = py::slice(start, stop, py::none());
        } else {
            // 两个冒号切片
            sliceObj = py::slice(start, stop, step);
        }
        
        py::object result = pyObj[sliceObj];
        return ScriptValue::fromPythonObject(result);
    } catch (const py::error_already_set& e) {
        reportError("Python slice error: " + string(e.what()), ctx);
        return nullptr;
    }
}

any AstVisitor::visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) {
    // 这个上下文应该由visitAtom处理
    return any();
}


any AstVisitor::visitArgumentList(PyScriptParser::ArgumentListContext *ctx) {
    // 参数列表已经在调用处处理
    return any();
}

any AstVisitor::visitArgument(PyScriptParser::ArgumentContext *ctx) {
    // 参数已经在调用处处理
    return any();
}

any AstVisitor::visitListLiteral(PyScriptParser::ListLiteralContext *ctx) {
    // 如果正在定义函数，跳过求值，返回空列表，并阻止访问子节点
    if (defining_function_) {
        logger_.debug("visitListLiteral: Skipping list literal evaluation during function definition, returning stop signal");
        return any(true);  // 返回非空值阻止ANTLR访问子节点
    }
    
    auto listElementsCtx = ctx->listElements();
    if (listElementsCtx) {
        // 检查是否为列表推导式
        if (listElementsCtx->comprehension()) {
            // 列表推导式，让visitListElements处理
            // 注意：visitListElements 会检查 defining_function_，所以这里不需要再次检查
            logger_.debug("List comprehension detected in visitListLiteral, delegating to visitListElements");
            return this->visit(listElementsCtx);
        } else {
            // 普通列表
            auto listVal = ScriptValue::createList();
            auto expressions = listElementsCtx->expression();
            for (auto expr : expressions) {
                auto value = evaluateExpression(expr);
                if (value) {
                    listVal->append(value);
                } else {
                    reportError("Cannot evaluate list element", ctx);
                    return any();
                }
            }
            return any(listVal);
        }
    }
    // 如果没有listElements，返回空列表
    return any(ScriptValue::createList());
}

any AstVisitor::visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) {
    // dictComprehension 分支
    if (ctx->dictComprehension()) {
        return visitDictComprehension(ctx->dictComprehension());
    }

    auto dictVal = ScriptValue::createDictionary();
    
    auto dictItems = ctx->dictItem();
    for (auto item : dictItems) {
        if (item->expression().size() == 2) {
            // key: value 对
            auto keyExpr = item->expression(0);
            auto valueExpr = item->expression(1);
            
            auto keyValue = evaluateExpression(keyExpr);
            auto valueValue = evaluateExpression(valueExpr);
            
            if (!keyValue || !valueValue) {
                reportError("Cannot evaluate dictionary key-value pair", ctx);
                return any();
            }
            
            string keyStr = keyValue->toString();
            dictVal->setKey(keyStr, valueValue);
        } else if (item->DOUBLE_STAR()) {
            // ** 展开
            auto unpackExpr = item->expression(0);
            auto unpackValue = evaluateExpression(unpackExpr);
            
            if (!unpackValue) {
                reportError("Cannot evaluate dictionary unpack expression", ctx);
                return any();
            }
            
            // 合并字典
            if (unpackValue->isDictionary()) {
                auto& unpackDict = unpackValue->getDictionary();
                for (auto& kv : unpackDict) {
                    dictVal->setKey(kv.first, kv.second);
                }
            } else if (unpackValue->isPythonObject()) {
                py::object pyObj = unpackValue->getPythonObject();
                // 尝试转换为字典
                try {
                    py::dict pyDict = py::dict(pyObj);
                    for (auto item : pyDict) {
                        string key = py::str(item.first).cast<string>();
                        py::object value = py::reinterpret_borrow<py::object>(item.second);
                        dictVal->setKey(key, ScriptValue::fromPythonObject(value));
                    }
                } catch (const py::error_already_set& e) {
                    reportError("** unpack requires a mapping", ctx);
                    return any();
                }
            } else {
                reportError("** unpack requires a mapping", ctx);
                return any();
            }
        }
    }
    
    return any(dictVal);
}

any AstVisitor::visitDictItem(PyScriptParser::DictItemContext *ctx) {
    // 字典项已经在visitDictLiteral中处理
    return any();
}

any AstVisitor::visitDictComprehension(PyScriptParser::DictComprehensionContext *ctx) {
    if (defining_function_) {
        return any(ScriptValue::createNull());
    }
    auto exprs = ctx->expression();
    auto compFors = ctx->compFor();
    if (exprs.size() < 2 || compFors.empty()) {
        reportError("Invalid dict comprehension", ctx);
        return any();
    }
    auto keyExpr = exprs[0];
    auto valExpr = exprs[1];

    struct CompClause {
        std::string var;
        PyScriptParser::ExpressionContext* iter;
        PyScriptParser::ExpressionContext* cond;
    };
    std::vector<CompClause> clauses;
    
    // 使用 compFor() 方法获取所有 compFor 子句
    if (compFors.empty()) {
        reportError("Invalid dict comprehension: no compFor clauses", ctx);
        return any();
    }
    
    for (auto compForCtx : compFors) {
        // compFor: FOR (IDENTIFIER | tupleLiteral) IN expression (IF expression)?
        std::string varName;
        if (compForCtx->IDENTIFIER()) {
            varName = compForCtx->IDENTIFIER()->getText();
        } else if (compForCtx->tupleLiteral()) {
            // 对于 tupleLiteral，暂时不支持，报错
            reportError("Tuple unpacking in compFor not yet supported", ctx);
            return any();
        } else {
            reportError("Invalid compFor: missing identifier or tuple", ctx);
            return any();
        }
        
        // 获取 IN 后面的表达式
        auto iterExprs = compForCtx->expression();
        if (iterExprs.empty()) {
            reportError("Invalid compFor: missing iterable expression", ctx);
            return any();
        }
        
        // 第一个 expression 是迭代对象
        PyScriptParser::ExpressionContext* iterExpr = iterExprs[0];
        
        // 检查是否有 IF 条件
        PyScriptParser::ExpressionContext* condExpr = nullptr;
        if (compForCtx->IF() && iterExprs.size() > 1) {
            // 如果有 IF token，第二个 expression 是条件
            condExpr = iterExprs[1];
        }
        
        clauses.push_back({varName, iterExpr, condExpr});
    }

    auto dictVal = ScriptValue::createDictionary();
    std::vector<std::shared_ptr<ScriptValue>> oldVars;
    oldVars.reserve(clauses.size());
    for (auto& c : clauses) {
        oldVars.push_back(variable_manager_.getVariable(c.var));
    }

    std::function<bool(size_t)> evalClause = [&](size_t depth) -> bool {
        if (depth == clauses.size()) {
            auto keyVal = evaluateExpression(keyExpr);
            auto valVal = evaluateExpression(valExpr);
            if (!keyVal || !valVal) {
                reportError("Cannot evaluate dict comprehension key/value", ctx);
                return false;
            }
            dictVal->setKey(keyVal->toString(), valVal);
            return true;
        }
        auto& clause = clauses[depth];
        auto iterVal = evaluateExpression(clause.iter);
        if (!iterVal) {
            reportError("Cannot evaluate dict comprehension iterable", ctx);
            return false;
        }
        try {
            bool useDirect = false;
            if (iterVal->isList()) {
                // 直接迭代快路径
                iter_direct_count_++;
                useDirect = true;
                for (auto& item : iterVal->getList()) {
                    variable_manager_.setVariable(clause.var, item);
                    if (clause.cond) {
                        auto condVal = evaluateExpression(clause.cond);
                        if (!condVal) {
                            reportError("Cannot evaluate dict comprehension filter", ctx);
                            return false;
                        }
                        if (!expression_evaluator_.isTruthy(condVal)) continue;
                    }
                    if (!evalClause(depth + 1)) return false;
                }
            } else if (iterVal->isDictionary()) {
                // 直接迭代字典 keys
                iter_direct_count_++;
                useDirect = true;
                for (auto& kv : iterVal->getDictionary()) {
                    auto keyVal = ScriptValue::createString(kv.first);
                    variable_manager_.setVariable(clause.var, keyVal);
                    if (clause.cond) {
                        auto condVal = evaluateExpression(clause.cond);
                        if (!condVal) {
                            reportError("Cannot evaluate dict comprehension filter", ctx);
                            return false;
                        }
                        if (!expression_evaluator_.isTruthy(condVal)) continue;
                    }
                    if (!evalClause(depth + 1)) return false;
                }
            }
            if (!useDirect) {
                // Python 迭代慢路径
                iter_py_count_++;
                for (auto item : toIterator(iterVal)) {
                    py::object obj = py::reinterpret_borrow<py::object>(item);
                    py_to_sv_count_++;
                    variable_manager_.setVariable(clause.var, ScriptValue::fromPythonObject(obj));
                    if (clause.cond) {
                        auto condVal = evaluateExpression(clause.cond);
                        if (!condVal) {
                            reportError("Cannot evaluate dict comprehension filter", ctx);
                            return false;
                        }
                        if (!expression_evaluator_.isTruthy(condVal)) continue;
                    }
                    if (!evalClause(depth + 1)) return false;
                }
            }
        } catch (const py::error_already_set& e) {
            reportError("Failed to evaluate dict comprehension: " + string(e.what()), ctx);
            return false;
        }
        return true;
    };

    bool ok = evalClause(0);
    for (size_t i = 0; i < clauses.size(); ++i) {
        if (oldVars[i]) variable_manager_.setVariable(clauses[i].var, oldVars[i]);
    }
    if (!ok) return any();
    return any(dictVal);
}

any AstVisitor::visitSetLiteral(PyScriptParser::SetLiteralContext *ctx) {
    if (defining_function_) {
        return any(ScriptValue::createNull());
    }

    auto elementsCtx = ctx->setElements();
    // 可能为空集合
    if (!elementsCtx) {
        return any(ScriptValue::fromPythonObject(py::set()));
    }
    // 推导式
    auto compCtx = elementsCtx->comprehension();
    if (compCtx && elementsCtx->expression().size() >= 2) {
        auto exprs = elementsCtx->expression();
        if (exprs.size() < 2) {
            reportError("Invalid set comprehension", ctx);
            return any();
        }
        auto elemExpr = exprs[0];
        struct CompClause {
            std::string var;
            PyScriptParser::ExpressionContext* iter;
            PyScriptParser::ExpressionContext* cond;
        };
        std::vector<CompClause> clauses;
        auto children = elementsCtx->children;
        size_t idx = 0;
        // skip first expression child
        if (!children.empty() && dynamic_cast<PyScriptParser::ExpressionContext*>(children[0]) == elemExpr) {
            idx = 1;
        }
        while (idx < children.size()) {
            auto t_for = dynamic_cast<antlr4::tree::TerminalNode*>(children[idx]);
            if (!t_for || t_for->getSymbol()->getType() != PyScriptParser::FOR) { ++idx; continue; }
            if (idx + 3 >= children.size()) break;
            auto idNode = dynamic_cast<antlr4::tree::TerminalNode*>(children[idx + 1]);
            auto iterExprNode = dynamic_cast<PyScriptParser::ExpressionContext*>(children[idx + 3]);
            if (!idNode || idNode->getSymbol()->getType() != PyScriptParser::IDENTIFIER || !iterExprNode) break;
            CompClause clause{ idNode->getText(), iterExprNode, nullptr };
            idx += 4;
            if (idx + 1 < children.size()) {
                auto t_if = dynamic_cast<antlr4::tree::TerminalNode*>(children[idx]);
                auto condExprNode = dynamic_cast<PyScriptParser::ExpressionContext*>(children[idx + 1]);
                if (t_if && t_if->getSymbol()->getType() == PyScriptParser::IF && condExprNode) {
                    clause.cond = condExprNode;
                    idx += 2;
                }
            }
            clauses.push_back(std::move(clause));
        }
        if (clauses.empty()) {
            reportError("Invalid set comprehension", ctx);
            return any();
        }

        py::set s;
        std::vector<std::shared_ptr<ScriptValue>> oldVars;
        oldVars.reserve(clauses.size());
        for (auto& c : clauses) {
            oldVars.push_back(variable_manager_.getVariable(c.var));
        }

        std::function<bool(size_t)> evalClause = [&](size_t depth) -> bool {
            if (depth == clauses.size()) {
                auto val = evaluateExpression(elemExpr);
                if (!val) {
                    reportError("Cannot evaluate set comprehension element", ctx);
                    return false;
                }
                s.add(val->toPythonObject());
                return true;
            }
            auto& clause = clauses[depth];
            auto iterVal = evaluateExpression(clause.iter);
            if (!iterVal) {
                reportError("Cannot evaluate set comprehension iterable", ctx);
                return false;
            }
            try {
                bool useDirect = false;
                if (iterVal->isList()) {
                    // 直接迭代快路径
                    iter_direct_count_++;
                    useDirect = true;
                    for (auto& item : iterVal->getList()) {
                        variable_manager_.setVariable(clause.var, item);
                        if (clause.cond) {
                            auto condVal = evaluateExpression(clause.cond);
                            if (!condVal) {
                                reportError("Cannot evaluate set comprehension filter", ctx);
                                return false;
                            }
                            if (!expression_evaluator_.isTruthy(condVal)) continue;
                        }
                        if (!evalClause(depth + 1)) return false;
                    }
                } else if (iterVal->isDictionary()) {
                    // 直接迭代字典 keys
                    iter_direct_count_++;
                    useDirect = true;
                    for (auto& kv : iterVal->getDictionary()) {
                        auto keyVal = ScriptValue::createString(kv.first);
                        variable_manager_.setVariable(clause.var, keyVal);
                        if (clause.cond) {
                            auto condVal = evaluateExpression(clause.cond);
                            if (!condVal) {
                                reportError("Cannot evaluate set comprehension filter", ctx);
                                return false;
                            }
                            if (!expression_evaluator_.isTruthy(condVal)) continue;
                        }
                        if (!evalClause(depth + 1)) return false;
                    }
                }
                if (!useDirect) {
                    // Python 迭代慢路径
                    iter_py_count_++;
                    for (auto item : toIterator(iterVal)) {
                        py::object obj = py::reinterpret_borrow<py::object>(item);
                        py_to_sv_count_++;
                        variable_manager_.setVariable(clause.var, ScriptValue::fromPythonObject(obj));
                        if (clause.cond) {
                            auto condVal = evaluateExpression(clause.cond);
                            if (!condVal) {
                                reportError("Cannot evaluate set comprehension filter", ctx);
                                return false;
                            }
                            if (!expression_evaluator_.isTruthy(condVal)) continue;
                        }
                        if (!evalClause(depth + 1)) return false;
                    }
                }
            } catch (const py::error_already_set& e) {
                reportError("Failed to evaluate set comprehension: " + string(e.what()), ctx);
                return false;
            }
            return true;
        };

        bool ok = evalClause(0);
        for (size_t i = 0; i < clauses.size(); ++i) {
            if (oldVars[i]) variable_manager_.setVariable(clauses[i].var, oldVars[i]);
        }
        if (!ok) return any();
        return any(ScriptValue::fromPythonObject(s));
    }

    // 普通 set 字面量
    try {
        py::set s;
        auto exprs = elementsCtx->expression();
        for (auto expr : exprs) {
            auto val = evaluateExpression(expr);
            if (!val) {
                reportError("Cannot evaluate set element", ctx);
                return any();
            }
            s.add(val->toPythonObject());
        }
        return any(ScriptValue::fromPythonObject(s));
    } catch (const py::error_already_set& e) {
        reportError("Failed to build set: " + string(e.what()), ctx);
        return any();
    }
}

any AstVisitor::visitSetElements(PyScriptParser::SetElementsContext *ctx) {
    // 元素处理在 visitSetLiteral 中完成
    return any();
}

any AstVisitor::visitGeneratorExpression(PyScriptParser::GeneratorExpressionContext *ctx) {
    if (defining_function_) {
        return any(ScriptValue::createNull());
    }
    auto compCtx = ctx->comprehension();
    if (!compCtx) {
        reportError("Invalid generator expression", ctx);
        return any();
    }
    auto bodyExpr = compCtx->expression();
    if (!bodyExpr) {
        reportError("Invalid generator expression: missing body expression", ctx);
        return any();
    }

    struct CompClause {
        std::string var;
        PyScriptParser::ExpressionContext* iter;
        PyScriptParser::ExpressionContext* cond;
    };
    std::vector<CompClause> clauses;
    
    // 使用 compFor() 方法获取所有 compFor 子句
    auto compFors = compCtx->compFor();
    if (compFors.empty()) {
        reportError("Invalid generator expression: no compFor clauses", ctx);
        return any();
    }
    
    for (auto compForCtx : compFors) {
        // compFor: FOR (IDENTIFIER | tupleLiteral) IN expression (IF expression)?
        std::string varName;
        if (compForCtx->IDENTIFIER()) {
            varName = compForCtx->IDENTIFIER()->getText();
        } else if (compForCtx->tupleLiteral()) {
            // 对于 tupleLiteral，暂时不支持，报错
            reportError("Tuple unpacking in compFor not yet supported", ctx);
            return any();
        } else {
            reportError("Invalid compFor: missing identifier or tuple", ctx);
            return any();
        }
        
        // 获取 IN 后面的表达式
        auto iterExprs = compForCtx->expression();
        if (iterExprs.empty()) {
            reportError("Invalid compFor: missing iterable expression", ctx);
            return any();
        }
        
        // 第一个 expression 是迭代对象
        PyScriptParser::ExpressionContext* iterExpr = iterExprs[0];
        
        // 检查是否有 IF 条件（第二个 expression）
        PyScriptParser::ExpressionContext* condExpr = nullptr;
        if (iterExprs.size() > 1) {
            condExpr = iterExprs[1];
        }
        
        clauses.push_back({varName, iterExpr, condExpr});
    }

    py::list results;

    std::function<bool(size_t)> evalClause;
    evalClause = [&](size_t depth) -> bool {
        auto& clause = clauses[depth];
        auto iterVal = evaluateExpression(clause.iter);
        if (!iterVal) {
            reportError("Cannot evaluate generator iterable", ctx);
            return false;
        }
        py::object iterObj = iterVal->toPythonObject();
        try {
            for (auto item : py::reinterpret_steal<py::iterator>(PyObject_GetIter(iterObj.ptr()))) {
                variable_manager_.setVariable(clause.var, ScriptValue::fromPythonObject(py::reinterpret_borrow<py::object>(item)));
                if (clause.cond) {
                    auto condVal = evaluateExpression(clause.cond);
                    if (!condVal) return false;
                    if (!expression_evaluator_.isTruthy(condVal)) {
                        continue;
                    }
                }
                if (depth + 1 == clauses.size()) {
                    auto val = evaluateExpression(bodyExpr);
                    if (!val) return false;
                    results.append(val->toPythonObject());
                } else {
                    if (!evalClause(depth + 1)) return false;
                }
            }
        } catch (const py::error_already_set& e) {
            reportError("Generator iteration error: " + string(e.what()), ctx);
            return false;
        } catch (const std::exception& e) {
            reportError("Generator iteration error: " + string(e.what()), ctx);
            return false;
        }
        return true;
    };

    if (!evalClause(0)) {
        return any();
    }
    py::object gen_iter = results.attr("__iter__")();
    return any(ScriptValue::fromPythonObject(gen_iter));
}

any AstVisitor::visitLiteral(PyScriptParser::LiteralContext *ctx) {
    if (ctx->INTEGER()) {
        long long value = stoll(ctx->INTEGER()->getText());
        return any(ScriptValue::createInteger(value));
    } else if (ctx->FLOAT()) {
        double value = stod(ctx->FLOAT()->getText());
        return any(ScriptValue::createDouble(value));
    } else if (ctx->STRING()) {
        string text = ctx->STRING()->getText();
        // 去掉引号
        if (text.length() >= 2) {
            text = text.substr(1, text.length() - 2);
        }
        return any(ScriptValue::createString(text));
    } else if (ctx->TRUE()) {
        return any(ScriptValue::createBoolean(true));
    } else if (ctx->FALSE()) {
        return any(ScriptValue::createBoolean(false));
    } else if (ctx->NONE()) {
        return any(ScriptValue::createNull());
    }
    
    reportError("Invalid literal", ctx);
    return any();
}

any AstVisitor::visitDottedName(PyScriptParser::DottedNameContext *ctx) {
    string name = ctx->getText();
    logger_.debug(std::string("visitDottedName: ") + name);
    
    // 如果正在定义函数，返回占位符
    if (defining_function_) {
        return any(ScriptValue::createNull());
    }
    
    // 首先检查变量
    auto var = getVariable(name);
    if (var) {
        return any(var);
    }
    
    // 检查导入的模块
    auto module = variable_manager_.getModule(name);
    if (module) {
        return any(ScriptValue::createPythonObject(module));
    }
    
    // 检查是否为点分隔的名称
    vector<string> parts;
    size_t start = 0;
    size_t dotPos;
    while ((dotPos = name.find('.', start)) != string::npos) {
        parts.push_back(name.substr(start, dotPos - start));
        start = dotPos + 1;
    }
    parts.push_back(name.substr(start));
    
    if (parts.size() > 1) {
        // 尝试获取第一个部分
        string firstPart = parts[0];
        auto firstVar = getVariable(firstPart);
        if (firstVar) {
            shared_ptr<ScriptValue> current = firstVar;
            for (size_t i = 1; i < parts.size(); ++i) {
                current = python_bridge_.getMember(current, parts[i]);
                if (!current) {
                    break;
                }
            }
            if (current) {
                return any(current);
            }
        } else {
            // 尝试作为模块导入
            try {
                py::module_ module = py::module_::import(firstPart.c_str());
                variable_manager_.importModule(firstPart, module);
                py::object current = module;
                for (size_t i = 1; i < parts.size(); ++i) {
                    current = current.attr(parts[i].c_str());
                }
                return any(ScriptValue::fromPythonObject(current));
            } catch (const py::error_already_set&) {
                // 失败
            }
        }
    }
    
    reportError("Undefined identifier: " + name, ctx);
    return any();
}

any AstVisitor::visitPower(PyScriptParser::PowerContext *ctx) {
    auto unaryCtx = ctx->unary();
    auto leftAny = visit(unaryCtx);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of power expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of power expression", ctx);
        return any();
    }
    
    // 检查是否有右操作数（即是否有DOUBLE_STAR）
    if (ctx->DOUBLE_STAR()) {
        // 获取右操作数（power）
        auto powerCtx = ctx->power();
        if (powerCtx) {
            auto rightAny = visit(powerCtx);
            shared_ptr<ScriptValue> right;
            try {
                right = any_cast<shared_ptr<ScriptValue>>(rightAny);
            } catch (const bad_any_cast&) {
                reportError("Cannot evaluate right side of power expression", ctx);
                return any();
            }
            if (!right) {
                reportError("Cannot evaluate right side of power expression", ctx);
                return any();
            }
            
            // 计算幂运算
            auto result = expression_evaluator_.evaluateBinaryOperation("**", left, right);
            if (!result) {
                reportError("Unsupported power operator", ctx);
                return any();
            }
            return any(result);
        }
    }
    
    // 没有幂运算符，返回左操作数
    return any(left);
}

any AstVisitor::visitComprehension(PyScriptParser::ComprehensionContext *ctx) {
    // comprehension: expression (compFor)+
    // 这是一个通用的推导式结构，被列表、字典、集合和生成器表达式使用
    // 实际的推导式逻辑在各自的 visit 方法中处理
    // ComprehensionContext 有 expression() 方法（返回单个 ExpressionContext*）
    auto expression = ctx->expression();
    if (expression) {
        return visit(expression);
    }
    reportError("Invalid comprehension expression", ctx);
    return any();
}

any AstVisitor::visitCompFor(PyScriptParser::CompForContext *ctx) {
    // compFor: FOR IDENTIFIER IN expression (IF expression)?
    // 这是一个推导式的 for 子句，实际的逻辑在各自的推导式处理中
    // 这里返回 null 作为占位符
    return any(ScriptValue::createNull());
}

any AstVisitor::visitListElements(PyScriptParser::ListElementsContext *ctx) {
    // listElements: expression (COMMA expression)* COMMA? | expression FOR IDENTIFIER IN expression (IF expression)? (FOR IDENTIFIER IN expression (IF expression)?)* 
    auto startToken = ctx->getStart();
    int line = startToken ? startToken->getLine() : -1;
    logger_.info("visitListElements called at line " + std::to_string(line) + " (defining_function_=" + std::string(defining_function_ ? "true" : "false") + ")");
    
    // 如果正在定义函数，跳过列表推导式的求值，返回特殊标记阻止访问子节点
    if (defining_function_) {
        logger_.info("Skipping list comprehension evaluation during function definition, returning stop signal");
        // 返回true阻止ANTLR访问子节点
        return any(true);
    }
    
    // 额外检查：如果节点在函数定义体内，跳过求值（防止函数定义完成后 ANTLR 继续访问函数体内的节点）
    bool inside_function = isNodeInsideFunctionDef(ctx);
    if (inside_function) {
        logger_.debug("Skipping list comprehension evaluation at line " + std::to_string(line) + " (inside function definition, defining_function_=false)");
        return any(true);
    }
    
    // 检查是否为列表推导式
    auto compCtx = ctx->comprehension();
    if (compCtx) {
        logger_.debug("List comprehension detected");
        auto outputExpr = compCtx->expression();
        if (!outputExpr) {
            reportError("Invalid list comprehension syntax", ctx);
            return any();
        }

        struct CompClause {
            std::string var;
            PyScriptParser::ExpressionContext* iter;
            PyScriptParser::ExpressionContext* cond; // may be nullptr
        };
        std::vector<CompClause> clauses;
        
        // 使用 compFor() 方法获取所有 compFor 子句
        auto compFors = compCtx->compFor();
        if (compFors.empty()) {
            reportError("Invalid list comprehension syntax: no compFor clauses", ctx);
            return any();
        }
        
        for (auto compForCtx : compFors) {
            // compFor: FOR (IDENTIFIER | tupleLiteral) IN expression (IF expression)?
            std::string varName;
            if (compForCtx->IDENTIFIER()) {
                varName = compForCtx->IDENTIFIER()->getText();
            } else if (compForCtx->tupleLiteral()) {
                // 对于 tupleLiteral，暂时不支持，报错
                reportError("Tuple unpacking in compFor not yet supported", ctx);
                return any();
            } else {
                reportError("Invalid compFor: missing identifier or tuple", ctx);
                return any();
            }
            
            // 获取 IN 后面的表达式
            auto iterExprs = compForCtx->expression();
            if (iterExprs.empty()) {
                reportError("Invalid compFor: missing iterable expression", ctx);
                return any();
            }
            
            // 第一个 expression 是迭代对象
            PyScriptParser::ExpressionContext* iterExpr = iterExprs[0];
            
            // 检查是否有 IF 条件
            PyScriptParser::ExpressionContext* condExpr = nullptr;
            if (compForCtx->IF() && iterExprs.size() > 1) {
                // 如果有 IF token，第二个 expression 是条件
                condExpr = iterExprs[1];
            }
            
            clauses.push_back({varName, iterExpr, condExpr});
        }
        
        auto listVal = ScriptValue::createList();
        std::vector<std::shared_ptr<ScriptValue>> oldVars;
        oldVars.reserve(clauses.size());
        for (auto& c : clauses) {
            oldVars.push_back(variable_manager_.getVariable(c.var));
        }

        std::function<bool(size_t)> evalClause = [&](size_t depth) -> bool {
            if (depth == clauses.size()) {
                auto outVal = evaluateExpression(outputExpr);
                if (!outVal) {
                    reportError("Cannot evaluate list comprehension element", ctx);
                    return false;
                }
                listVal->append(outVal);
                return true;
            }
            auto& clause = clauses[depth];
            auto iterVal = evaluateExpression(clause.iter);
            if (!iterVal) {
                reportError("Cannot evaluate list comprehension iterable", ctx);
                return false;
            }
            // 检查是否为 None 或 null
            if (iterVal->isNull()) {
                reportError("List comprehension iterable is null (variable may not be assigned correctly)", ctx);
                return false;
            }
            if (iterVal->isPythonObject()) {
                py::object pyObj = iterVal->toPythonObject();
                if (py::isinstance<py::none>(pyObj)) {
                    reportError("List comprehension iterable is None (variable may not be assigned correctly)", ctx);
                    return false;
                }
            }
            try {
                bool useDirect = false;
                if (iterVal->isList()) {
                    // 直接迭代快路径
                    iter_direct_count_++;
                    useDirect = true;
                    for (auto& item : iterVal->getList()) {
                        variable_manager_.setVariable(clause.var, item);
                        if (clause.cond) {
                            auto condVal = evaluateExpression(clause.cond);
                            if (!condVal) {
                                reportError("Cannot evaluate list comprehension filter", ctx);
                                return false;
                            }
                            if (!expression_evaluator_.isTruthy(condVal)) {
                                continue;
                            }
                        }
                        if (!evalClause(depth + 1)) return false;
                    }
                } else if (iterVal->isDictionary()) {
                    // 直接迭代字典 keys
                    iter_direct_count_++;
                    useDirect = true;
                    for (auto& kv : iterVal->getDictionary()) {
                        auto keyVal = ScriptValue::createString(kv.first);
                        variable_manager_.setVariable(clause.var, keyVal);
                        if (clause.cond) {
                            auto condVal = evaluateExpression(clause.cond);
                            if (!condVal) {
                                reportError("Cannot evaluate list comprehension filter", ctx);
                                return false;
                            }
                            if (!expression_evaluator_.isTruthy(condVal)) {
                                continue;
                            }
                        }
                        if (!evalClause(depth + 1)) return false;
                    }
                }
                if (!useDirect) {
                    // Python 迭代慢路径
                    iter_py_count_++;
                    try {
                        for (auto item : toIterator(iterVal)) {
                            py::object obj = py::reinterpret_borrow<py::object>(item);
                            py_to_sv_count_++;
                            variable_manager_.setVariable(clause.var, ScriptValue::fromPythonObject(obj));
                            if (clause.cond) {
                                auto condVal = evaluateExpression(clause.cond);
                                if (!condVal) {
                                    reportError("Cannot evaluate list comprehension filter", ctx);
                                    return false;
                                }
                                if (!expression_evaluator_.isTruthy(condVal)) {
                                    continue;
                                }
                            }
                            if (!evalClause(depth + 1)) return false;
                        }
                    } catch (const runtime_error& e) {
                        reportError("Failed to iterate over list comprehension iterable: " + string(e.what()), ctx);
                        return false;
                    }
                }
        } catch (const py::error_already_set& e) {
            reportError("Failed to evaluate list comprehension: " + string(e.what()), ctx);
            return false;
        }
            return true;
        };

        bool ok = evalClause(0);
        for (size_t i = 0; i < clauses.size(); ++i) {
            if (oldVars[i]) variable_manager_.setVariable(clauses[i].var, oldVars[i]);
        }
        if (!ok) return any();
        return any(listVal);
    }
    
    // 普通列表元素，已在visitListLiteral中处理，这里返回空
    return any();
}

any AstVisitor::visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) {
    // LAMBDA parameterList? COLON expression
    logger_.debug("visitLambdaExpression called");
    
    // 构建参数列表
    vector<string> paramNames;
    if (ctx->parameterList()) {
        for (auto* p : ctx->parameterList()->parameter()) {
            if (p->IDENTIFIER() && !p->MUL() && !p->DOUBLE_STAR()) {
                paramNames.push_back(p->IDENTIFIER()->getText());
            } else {
                // 不支持 *args 或 **kwargs 在lambda中
                reportError("Lambda expressions don't support *args or **kwargs", ctx);
                return any();
            }
        }
    }
    
    // 获取表达式体
    auto exprCtx = ctx->expression();
    if (!exprCtx) {
        reportError("Lambda missing expression", ctx);
        return any();
    }
    
    // 构建lambda字符串
    string lambdaStr = "lambda ";
    for (size_t i = 0; i < paramNames.size(); ++i) {
        if (i > 0) lambdaStr += ", ";
        lambdaStr += paramNames[i];
    }
    lambdaStr += ": ";
    
    // 获取表达式文本
    string exprText = exprCtx->getText();
    lambdaStr += exprText;
    
    logger_.debug(std::string("Lambda string: ") + lambdaStr);
    
    // 在Python中执行lambda定义
    try {
        py::dict locals;
        // 优化：使用缓存的builtins模块
        py::object builtins = builtins_module_.is_none() ? 
            py::module_::import("builtins") : builtins_module_;
        py::object lambdaFunc = builtins.attr("eval")(lambdaStr, py::globals(), locals);
        return any(ScriptValue::fromPythonObject(lambdaFunc));
    } catch (const py::error_already_set& e) {
        reportError("Failed to create lambda: " + string(e.what()), ctx);
        return any();
    }
}

any AstVisitor::visitWithItem(PyScriptParser::WithItemContext *ctx) {
    // 单个 with 项，仅用于 visitWithStatement 内部处理
    return any();
}

any AstVisitor::visitAwaitExpr(PyScriptParser::AwaitExprContext *ctx) {
    auto val = evaluateExpression(ctx->expression());
    if (!val) {
        reportError("Cannot evaluate await expression", ctx);
        return any();
    }
    if (val->isPythonObject()) {
        try {
            py::object obj = val->toPythonObject();
            if (py::hasattr(obj, "__await__")) {
                py::object asyncio = py::module_::import("asyncio");
                try {
                    py::object loop = asyncio.attr("get_event_loop")();
                    bool running = py::cast<bool>(loop.attr("is_running")());
                    if (running) {
                        return any(ScriptValue::fromPythonObject(obj));
                    } else {
                        py::object res = asyncio.attr("run")(obj);
                        return any(ScriptValue::fromPythonObject(res));
                    }
                } catch (const py::error_already_set&) {
                    // 没有当前事件循环，创建新的
                    py::object loop = asyncio.attr("new_event_loop")();
                    asyncio.attr("set_event_loop")(loop);
                    py::object res = loop.attr("run_until_complete")(obj);
                    loop.attr("close")();
                    asyncio.attr("set_event_loop")(py::none());
                    return any(ScriptValue::fromPythonObject(res));
                }
            }
        } catch (const py::error_already_set& e) {
            reportError("Await execution failed: " + string(e.what()), ctx);
            return any();
        }
    }
    return any(val);
}

any AstVisitor::visitClassDef(PyScriptParser::ClassDefContext *ctx) {
    if (defining_function_) {
        return any(ScriptValue::createNull());
    }
    try {
        auto start = ctx->getStart()->getStartIndex();
        auto stop = ctx->getStop()->getStopIndex();
        auto input = ctx->getStart()->getTokenSource()->getInputStream();
        std::string text = input->getText(antlr4::misc::Interval(start, stop));
        // 确保末尾换行，便于 exec
        if (text.empty() || text.back() != '\n') {
            text.push_back('\n');
        }
        
        std::string name = ctx->IDENTIFIER()->getText();
        
        // 两级缓存策略：使用增量哈希
        // 优化：缓存源代码哈希
        size_t source_hash;
        auto source_hash_it = source_hash_cache_.find(text);
        if (source_hash_it != source_hash_cache_.end()) {
            source_hash = source_hash_it->second;
        } else {
            source_hash = hashString(text);
            source_hash_cache_[text] = source_hash;
        }
        
        // 优化：使用缓存的变量名列表
        size_t current_var_count = variable_manager_.getVariableCount();
        if (cached_var_names_.empty() || cached_var_count_ != current_var_count) {
            cached_var_names_ = variable_manager_.getAllVariableNames();
            cached_var_count_ = current_var_count;
        }
        
        bool has_python_objects = false;
        size_t variable_state_hash = computeVariableStateHash(variable_manager_, cached_var_names_, has_python_objects);
        size_t full_hash = hashCombine(source_hash, variable_state_hash);
        
        py::object cls;
        bool cache_hit = false;
        
        // 先检查快速路径（仅源代码匹配，且无 PythonObject）
        if (cache_enabled_ && !has_python_objects) {
            auto source_it = exec_cache_source_.find(source_hash);
            if (source_it != exec_cache_source_.end()) {
                exec_cache_hits_++;
                cls = source_it->second;
                cache_hit = true;
                logger_.debug("Class definition cache hit (source only) for: " + name);
            }
        }
        
        // 如果快速路径未命中，检查完整路径
        if (!cache_hit) {
            auto cache_it = exec_cache_.find(full_hash);
            if (cache_enabled_ && cache_it != exec_cache_.end()) {
                exec_cache_hits_++;
                cls = cache_it->second;
                cache_hit = true;
                logger_.debug("Class definition cache hit (full) for: " + name);
            }
        }
        
        // 如果缓存未命中，执行 exec
        if (!cache_hit) {
            exec_cache_misses_++;
            py::exec(py::str(text), py::globals(), py::globals());
            cls = py::globals()[name.c_str()];
            
            // 缓存结果（如果缓存启用）
            if (cache_enabled_) {
                if (!has_python_objects) {
                    exec_cache_source_[source_hash] = cls;
                    logger_.debug("Class definition cached (source only) for: " + name);
                }
                exec_cache_[full_hash] = cls;
                logger_.debug("Class definition cached (full) for: " + name);
            }
        }
        
        variable_manager_.setVariable(name, ScriptValue::fromPythonObject(cls));
    } catch (const std::exception& e) {
        int line = ctx->getStart()->getLine();
        int col = ctx->getStart()->getCharPositionInLine();
        reportError("Failed to define class: " + string(e.what()),
                    ScriptErrorType::Runtime, ScriptErrorCode::Unknown, line, col);
        return any();
    }
    return any();
}

any AstVisitor::visitDecorators(PyScriptParser::DecoratorsContext *ctx) {
    return visitChildren(ctx);
}

any AstVisitor::visitDecorator(PyScriptParser::DecoratorContext *ctx) {
    return visitChildren(ctx);
}

any AstVisitor::visitDecoratedDef(PyScriptParser::DecoratedDefContext *ctx) {
    // 直接执行整段文本（包含装饰器+定义），让 Python 处理装饰器应用
    try {
        auto start = ctx->getStart()->getStartIndex();
        auto stop = ctx->getStop()->getStopIndex();
        auto input = ctx->getStart()->getTokenSource()->getInputStream();
        std::string text = input->getText(antlr4::misc::Interval(start, stop));
        if (text.empty() || text.back() != '\n') {
            text.push_back('\n');
        }
        
        // 两级缓存策略：使用增量哈希
        // 优化：缓存源代码哈希
        size_t source_hash;
        auto source_hash_it = source_hash_cache_.find(text);
        if (source_hash_it != source_hash_cache_.end()) {
            source_hash = source_hash_it->second;
        } else {
            source_hash = hashString(text);
            source_hash_cache_[text] = source_hash;
        }
        
        // 优化：使用缓存的变量名列表
        size_t current_var_count = variable_manager_.getVariableCount();
        if (cached_var_names_.empty() || cached_var_count_ != current_var_count) {
            cached_var_names_ = variable_manager_.getAllVariableNames();
            cached_var_count_ = current_var_count;
        }
        
        bool has_python_objects = false;
        size_t variable_state_hash = computeVariableStateHash(variable_manager_, cached_var_names_, has_python_objects);
        size_t full_hash = hashCombine(source_hash, variable_state_hash);
        
        bool cached = false;
        py::object cached_cls;
        
        // 先检查快速路径（仅源代码匹配，且无 PythonObject）
        if (cache_enabled_ && !has_python_objects) {
            auto source_it = exec_cache_source_.find(source_hash);
            if (source_it != exec_cache_source_.end()) {
                exec_cache_hits_++;
                cached = true;
                cached_cls = source_it->second;
                logger_.debug("Decorated definition cache hit (source only)");
            }
        }
        
        // 如果快速路径未命中，检查完整路径
        if (!cached) {
            auto cache_it = exec_cache_.find(full_hash);
            if (cache_enabled_ && cache_it != exec_cache_.end()) {
                exec_cache_hits_++;
                cached = true;
                cached_cls = cache_it->second;
                logger_.debug("Decorated definition cache hit (full)");
            } else {
                // 缓存未命中或缓存禁用：执行 exec 并缓存结果（如果启用）
                exec_cache_misses_++;
                py::exec(py::str(text), py::globals(), py::globals());
            }
        }
        
        // 若为 class 定义，写回变量表
        if (ctx->classDef()) {
            std::string name = ctx->classDef()->IDENTIFIER()->getText();
            py::object cls;
            if (cached) {
                cls = cached_cls;
            } else {
                if (py::globals().contains(name.c_str())) {
                    cls = py::globals()[name.c_str()];
                    // 缓存结果（如果缓存启用）
                    if (cache_enabled_) {
                        if (!has_python_objects) {
                            exec_cache_source_[source_hash] = cls;
                            logger_.debug("Decorated class definition cached (source only) for: " + name);
                        }
                        exec_cache_[full_hash] = cls;
                        logger_.debug("Decorated class definition cached (full) for: " + name);
                    }
                }
            }
            if (cls) {
                variable_manager_.setVariable(name, ScriptValue::fromPythonObject(cls));
            }
        }
    } catch (const std::exception& e) {
        int line = ctx->getStart()->getLine();
        int col = ctx->getStart()->getCharPositionInLine();
        reportError("Failed to execute decorated definition: " + string(e.what()),
                    ScriptErrorType::Runtime, ScriptErrorCode::Unknown, line, col);
        return any();
    }
    return any();
}

any AstVisitor::visitAsyncFunctionDef(PyScriptParser::AsyncFunctionDefContext *ctx) {
    // async def 与普通 def 等价处理
    return visitFunctionDef(ctx->functionDef());
}
std::any AstVisitor::visitShiftExpr(PyScriptParser::ShiftExprContext *ctx){
    auto additiveExprs = ctx->additive();
    if (additiveExprs.size() == 1) {
        return this->visit(additiveExprs[0]);
    }
    
    // 处理移位表达式
    shared_ptr<ScriptValue> result;
    for (size_t i = 0; i < additiveExprs.size(); ++i) {
        auto valAny = visit(additiveExprs[i]);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate shift expression", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate shift expression", ctx);
            return any();
        }
        
        if (i == 0) {
            result = val;
        } else {
            // 检查操作符类型
            string op;
            size_t opIndex = 2*i - 1;
            if (opIndex < ctx->children.size()) {
                auto opChild = ctx->children[opIndex];
                auto terminal = dynamic_cast<antlr4::tree::TerminalNode*>(opChild);
                if (terminal) {
                    int tokenType = terminal->getSymbol()->getType();
                    if (tokenType == PyScriptParser::LEFT_SHIFT) {
                        op = "<<";
                    } else if (tokenType == PyScriptParser::RIGHT_SHIFT) {
                        op = ">>";
                    } else {
                        op = opChild->getText();
                    }
                } else {
                    op = opChild->getText();
                }
            } else {
                reportError("Missing operator in shift expression", ctx);
                return any();
            }
            
            result = expression_evaluator_.evaluateBinaryOperation(op, result, val);
        }
    }
    
    return any(result);
}

any AstVisitor::visitAsyncForStatement(PyScriptParser::AsyncForStatementContext *ctx) {
    // async for 等价于普通 for
    return visitForStatement(ctx->forStatement());
}

any AstVisitor::visitAsyncWithStatement(PyScriptParser::AsyncWithStatementContext *ctx) {
    // async with 等价于普通 with
    return visitWithStatement(ctx->withStatement());
}

any AstVisitor::visitWithStatement(PyScriptParser::WithStatementContext *ctx) {
    if (defining_function_) {
        return any(ScriptValue::createNull());
    }
    auto items = ctx->withItem();
    if (items.empty()) {
        reportError("With statement missing items", ctx);
        return any();
    }

    struct Entry {
        std::string asName;
        py::object exitFunc;
    };
    std::vector<Entry> stack;
    stack.reserve(items.size());

    auto call_exit = [](py::object exitFunc, py::object t, py::object v, py::object tb) -> bool {
        py::object ret = exitFunc(t, v, tb);
        return py::cast<bool>(ret);
    };

    py::object no_exit = py::cpp_function([](py::object, py::object, py::object) {
        return py::bool_(false);
    });

    py::object excType = py::none();
    py::object excVal = py::none();
    py::object excTb = py::none();
    bool rethrow = false;

    try {
        for (auto item : items) {
            auto exprCtx = item->expression();
            if (!exprCtx) {
                reportError("With item missing expression", ctx);
                return any();
            }
            auto val = evaluateExpression(exprCtx);
            if (!val) {
                reportError("Cannot evaluate with expression", ctx);
                return any();
            }
            py::object exitFunc = no_exit;
            if (val->isPythonObject()) {
                py::object obj = val->toPythonObject();
                py::object entered = obj;
                if (py::hasattr(obj, "__enter__")) {
                    entered = obj.attr("__enter__")();
                }
                if (py::hasattr(obj, "__exit__")) {
                    exitFunc = obj.attr("__exit__");
                }
                if (item->IDENTIFIER()) {
                    std::string name = item->IDENTIFIER()->getText();
                    variable_manager_.setVariable(name, ScriptValue::fromPythonObject(entered));
                    stack.push_back({name, exitFunc});
                } else {
                    stack.push_back({"", exitFunc});
                }
            } else {
                // 非 Python 对象，作为无操作上下文
                if (item->IDENTIFIER()) {
                    std::string name = item->IDENTIFIER()->getText();
                    variable_manager_.setVariable(name, val);
                    stack.push_back({name, no_exit});
                } else {
                    stack.push_back({"", no_exit});
                }
            }
        }

        auto bodySuite = ctx->suite();
        if (!bodySuite) {
            reportError("With statement missing body", ctx);
            return any();
        }
        visit(bodySuite);
    } catch (const py::error_already_set& e) {
        excType = e.type();
        excVal = e.value();
        excTb = e.trace();
        rethrow = true;
    } catch (const std::exception& e) {
        excType = py::none();
        excVal = py::str(e.what());
        excTb = py::none();
        rethrow = true;
    }

    bool suppress = false;
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
        try {
            if (call_exit(it->exitFunc, excType, excVal, excTb)) {
                suppress = true;
            }
        } catch (const py::error_already_set& e) {
            reportError("With __exit__ failed: " + string(e.what()), ctx);
            return any();
        }
    }

    if (rethrow && !suppress) {
        try {
            if (!excVal.is_none()) {
                std::string msg = py::str(excVal);
                throw std::runtime_error(msg);
            }
        } catch (const std::exception& e) {
            throw;
        }
        throw std::runtime_error("Exception in with block");
    }

    return any();
}

any AstVisitor::visitTryStatement(PyScriptParser::TryStatementContext *ctx) {
    logger_.debug("visitTryStatement called");
    
    // 获取try块
    auto trySuite = ctx->suite(0);
    if (!trySuite) {
        reportError("Try statement missing try block", ctx);
        return any();
    }
    
    bool handled = false;
    try {
        visit(trySuite);
        auto elseSuite = ctx->ELSE() ? ctx->suite(ctx->suite().size() - 1) : nullptr;
        if (elseSuite) {
            visit(elseSuite);
        }
    } catch (const py::error_already_set& e) {
        for (auto exceptClause : ctx->exceptClause()) {
            auto exceptSuite = exceptClause->suite();
            if (exceptSuite) {
                visit(exceptSuite);
                handled = true;
                break;
            }
        }
        if (!handled) {
            throw;
        }
    } catch (const std::exception&) {
        for (auto exceptClause : ctx->exceptClause()) {
            auto exceptSuite = exceptClause->suite();
            if (exceptSuite) {
                visit(exceptSuite);
                handled = true;
                break;
            }
        }
        if (!handled) {
            throw;
        }
    }
    
    if (ctx->FINALLY()) {
        auto finallySuite = ctx->suite(ctx->suite().size() - 1);
        if (finallySuite) {
            visit(finallySuite);
        }
    }
    
    return any();
}

any AstVisitor::visitExceptClause(PyScriptParser::ExceptClauseContext *ctx) {
    // except子句已经在visitTryStatement中处理，这里返回空
    return any();
}

std::string AstVisitor::getPerformanceStats() const {
    std::ostringstream oss;
    size_t cache_hits = exec_cache_hits_.load();
    size_t cache_misses = exec_cache_misses_.load();
    size_t cache_total = cache_hits + cache_misses;
    double cache_hit_rate = cache_total > 0 ? (100.0 * cache_hits / cache_total) : 0.0;
    
    oss << "Performance Stats:\n"
        << "  Python calls: " << py_call_count_.load() << "\n"
        << "  ScriptValue->py::object conversions: " << sv_to_py_count_.load() << "\n"
        << "  py::object->ScriptValue conversions: " << py_to_sv_count_.load() << "\n"
        << "  Direct iterations (fast path): " << iter_direct_count_.load() << "\n"
        << "  Python iterations (slow path): " << iter_py_count_.load() << "\n"
        << "  Exec cache hits: " << cache_hits << "\n"
        << "  Exec cache misses: " << cache_misses << "\n"
        << "  Exec cache hit rate: " << std::fixed << std::setprecision(1) << cache_hit_rate << "%\n";
    return oss.str();
}

void AstVisitor::resetPerformanceStats() {
    py_call_count_.store(0);
    sv_to_py_count_.store(0);
    py_to_sv_count_.store(0);
    iter_direct_count_.store(0);
    iter_py_count_.store(0);
    exec_cache_hits_.store(0);
    exec_cache_misses_.store(0);
    // 注意：不清空 exec_cache_ 和 exec_cache_source_，保留缓存以便后续使用
}
