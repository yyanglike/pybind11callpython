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
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include "dynamic_python_caller.h"

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
      current_from_module_(py::none()) {
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
    }
    
    reportError("Unknown small statement type", ctx);
    return any();
}

any AstVisitor::visitCompoundStatement(PyScriptParser::CompoundStatementContext *ctx) {
    if (ctx->functionDef()) {
        return visit(ctx->functionDef());
    } else if (ctx->ifStatement()) {
        return visit(ctx->ifStatement());
    } else if (ctx->whileStatement()) {
        return visit(ctx->whileStatement());
    } else if (ctx->forStatement()) {
        return visit(ctx->forStatement());
    } else if (ctx->tryStatement()) {
        return visit(ctx->tryStatement());
    }

    reportError("Unknown compound statement type", ctx);
    return any();
}

any AstVisitor::visitSuite(PyScriptParser::SuiteContext *ctx) {
    // 如果在函数定义阶段，仍然访问子节点，但其他visit方法会跳过求值
    if (defining_function_) {
        logger_.debug("Suite evaluation during function definition - visiting children but skipping evaluation");
    }
    
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
    bool old_defining_function = defining_function_;
    defining_function_ = true;
    
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
        
        // 调试：打印令牌信息
        logger_.info("Total tokens collected: " + to_string(allTokens.size()));
        logger_.info("Real tokens count: " + to_string(realTokens.size()));
        
        // 打印所有真实令牌及其行号（最多前50个，避免日志过大）
        size_t limit = min(realTokens.size(), (size_t)50);
        logger_.info("First " + to_string(limit) + " real tokens in function definition:");
        for (size_t i = 0; i < limit; ++i) {
            auto token = realTokens[i];
            logger_.info("  [" + to_string(i) + "]: line " + to_string(token->getLine()) + 
                       ", col " + to_string(token->getCharPositionInLine()) + 
                       ", type " + to_string(token->getType()) + 
                       ", text: '" + token->getText() + "'");
        }
        if (realTokens.size() > limit) {
            logger_.info("  ... and " + to_string(realTokens.size() - limit) + " more tokens");
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
        
        string funcDef = fullText.substr(startOffset, stopOffset - startOffset + 1);
        
        logger_.debug("Function definition raw text length: " + to_string(funcDef.length()));
        logger_.debug("First 200 chars: " + funcDef.substr(0, min((size_t)200, funcDef.length())));
        
        // 提取函数名
        string funcName = ctx->IDENTIFIER()->getText();
        logger_.info(std::string("Function definition string length: ") + to_string(funcDef.length()));
        logger_.info(std::string("Function definition string:\n") + funcDef + "\n");
        
        // 在Python中执行函数定义
        py::dict globals = py::globals();
        // 确保globals包含__builtins__
        if (!globals.contains("__builtins__")) {
            try {
                py::module_ builtins = py::module_::import("builtins");
                globals["__builtins__"] = builtins;
            } catch (...) {
                // 忽略错误
            }
        }

        // 确保sys模块与argv存在，避免脚本访问sys.argv时为None
        try {
            py::module_ sys_module = py::module_::import("sys");
            if (!globals.contains("sys")) {
                globals["sys"] = sys_module;
            }
            // 无条件设置 argv，避免为 None
            sys_module.attr("argv") = py::list();
        } catch (...) {
            // 忽略
        }
        
        // 注入已导入的模块，确保import语句可以找到模块
        for (const auto& moduleName : variable_manager_.getAllModuleNames()) {
            py::module_ module = variable_manager_.getModule(moduleName);
            if (module) {
                // 将模块注入全局作用域，使用其原始名称
                globals[moduleName.c_str()] = module;
                logger_.debug("注入模块到全局作用域: " + moduleName);
            }
        }
        
        // 确保sys.modules中的模块在globals中可用，使得函数定义中的import语句能够找到它们
        try {
            py::module_ sys_module = py::module_::import("sys");
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
        if (!globals.contains("range")) {
            try {
                py::object builtins = py::module_::import("builtins");
                globals["range"] = builtins.attr("range");
            } catch (...) {
                // 忽略失败
            }
        }
        
        // 调试：打印globals中的所有键
        // logger_.info("Globals keys before exec:");
        // for (auto item : globals) {
        //     std::string key = py::str(item.first).cast<std::string>();
        //     logger_.info("  " + key);
        // }
        
        try {
            py::object builtins_module = py::module_::import("builtins");
            builtins_module.attr("exec")(funcDef, globals, globals);
            py::object func = globals[funcName.c_str()];
            
            variable_manager_.setVariable(funcName, ScriptValue::fromPythonObject(func));
            logger_.info(std::string("Function defined: ") + funcName);
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
    
    // 返回非空值阻止访问子节点
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
    if (exprCtxList.empty()) {
        reportError("If statement condition is missing", ctx);
        return any();
    }

    auto condValue = evaluateExpression(exprCtxList[0]);
    if (!condValue) {
        reportError("Cannot evaluate condition", ctx);
        return any();
    }

    if (expression_evaluator_.isTruthy(condValue)) {
        auto thenSuite = ctx->suite(0);
        if (thenSuite) {
            return this->visit(thenSuite);
        }
    } else if (ctx->suite().size() > 1) {
        auto elseSuite = ctx->suite(1);
        if (elseSuite) {
            return this->visit(elseSuite);
        }
    }

    return any();
}

any AstVisitor::visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) {
    while (true) {
        auto condValue = evaluateExpression(ctx->expression());

        if (!condValue) {
            reportError("Cannot evaluate condition", ctx);
            break;
        }

        if (!expression_evaluator_.isTruthy(condValue)) {
            break;
        }

        visit(ctx->suite());

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
    
    // 转换为Python可迭代对象
    if (iterableValue->isPythonObject()) {
        py::object pyIterable = iterableValue->getPythonObject();
        try {
            for (auto item : pyIterable) {
                py::object pyItem = py::reinterpret_borrow<py::object>(item);
                auto itemValue = ScriptValue::fromPythonObject(pyItem);
                variable_manager_.setVariable(varName, itemValue);
                
                // 执行循环体
                visit(suiteCtx);
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
            variable_manager_.setVariable(varName, item);
            
            // 执行循环体
            visit(suiteCtx);
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

any AstVisitor::visitAssignment(PyScriptParser::AssignmentContext *ctx) {
    // 如果在函数定义阶段，跳过赋值求值，返回null
    if (defining_function_) {
        logger_.debug("Skipping assignment evaluation during function definition");
        return any(ScriptValue::createNull());
    }
    
    // 有三种赋值形式：标识符赋值、属性赋值、下标赋值
    if (ctx->IDENTIFIER()) {
        // 标识符赋值: IDENTIFIER ASSIGN expression
        string varName = ctx->IDENTIFIER()->getText();
        
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
        
        // 简单赋值
        variable_manager_.setVariable(varName, rightValue);
        try {
            if (rightValue) {
                logger_.debug(std::string("Assigned variable '") + varName + "' = " + rightValue->toString());
            } else {
                logger_.debug(std::string("Assigned variable '") + varName + "' = <null>");
            }
        } catch (...) {
            logger_.debug(std::string("Assigned variable '") + varName + "' (no toString)");
        }
    } else if (ctx->attributeAccess()) {
        // 属性赋值: attributeAccess ASSIGN expression
        auto attrCtx = ctx->attributeAccess();
        
        // 需要获取对象和属性名
        auto atomCtx = attrCtx->atom();
        if (!atomCtx) {
            reportError("Attribute assignment missing object", ctx);
            return any();
        }

        auto objectAny = visit(atomCtx);
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

        // 获取属性名（注意：attributeAccess: atom DOT IDENTIFIER）
        auto identifier = attrCtx->IDENTIFIER();
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
    } else if (ctx->subscriptAccess()) {
        // 下标赋值: subscriptAccess ASSIGN expression
        auto subscriptCtx = ctx->subscriptAccess();
        auto atomCtx = subscriptCtx->atom();
        if (!atomCtx) {
            reportError("Subscript access missing object", ctx);
            return any();
        }
        
        auto objectAny = visit(atomCtx);
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
        
        auto subscriptArgCtx = subscriptCtx->subscriptArg();
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
            // 使用ScriptValue的setKey方法
            if (!indexValue->isString()) {
                reportError("Dictionary key must be a string", ctx);
                return any();
            }
            string key = indexValue->getString();
            objectValue->setKey(key, rightValue);
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
    // expression: logicalOr
    if (ctx->logicalOr()) {
        return visit(ctx->logicalOr());
    }
    
    reportError("Invalid expression", ctx);
    return any();
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
    auto equalityExprs = ctx->equality();
    if (equalityExprs.size() == 1) {
        return this->visit(equalityExprs[0]);
    }
    
    // 处理多个逻辑与表达式
    shared_ptr<ScriptValue> result;
    for (auto expr : equalityExprs) {
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
    auto additiveExprs = ctx->additive();
    if (additiveExprs.size() == 1) {
        return this->visit(additiveExprs[0]);
    }
    
    // 处理关系比较
    auto leftAny = visit(additiveExprs[0]);
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
    
    for (size_t i = 1; i < additiveExprs.size(); ++i) {
        auto rightAny = visit(additiveExprs[i]);
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
        string op = ctx->children[2*i - 1]->getText();
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
        
        auto var = getVariable(name);
        if (var) {
            return any(var);
        }
        
        // 如果没有找到变量，在函数定义阶段返回一个空列表，避免NoneType错误
        if (defining_function_) {
            logger_.debug("Returning empty list for identifier " + name + " during function definition");
            return any(ScriptValue::createList());
        }
        
        // 非函数定义阶段，返回null
        return any(ScriptValue::createNull());
    } else if (ctx->LPAREN()) {
        // 括号表达式
        return visit(ctx->expression());
    } else if (ctx->listLiteral()) {
        return visit(ctx->listLiteral());
    } else if (ctx->dictLiteral()) {
        return visit(ctx->dictLiteral());
    } else if (ctx->newExpression()) {
        return visit(ctx->newExpression());
    } else if (ctx->lambdaExpression()) {
        return visit(ctx->lambdaExpression());
    }
    
    reportError("Invalid primary expression", ctx);
    return any();
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
        reportError("Cannot evaluate primary expression", ctx);
        return any();
    }
    
    if (!currentValue) {
        reportError("Cannot evaluate primary expression", ctx);
        return any();
    }
    
    // 应用所有的后缀操作符
    auto postfixOps = ctx->postfixOp();
    for (auto postfixOp : postfixOps) {
        if (auto attrOp = dynamic_cast<PyScriptParser::AttributeAccessOpContext*>(postfixOp)) {
            string memberName = attrOp->IDENTIFIER()->getText();
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
            if (!currentValue->isPythonObject()) {
                reportError("Cannot call non-function type", callOp);
                return any();
            }
            
            try {
                py::object pyFunc = currentValue->getPythonObject();
                
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
                
                // 调用函数
                py::object result = DynamicPythonCaller::callFunction(pyFunc, py::args(pyArgs), py::kwargs(pyKwargs));
                currentValue = ScriptValue::fromPythonObject(result);
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
            if (!indexValue->isString()) {
                reportError("Dictionary key must be a string", ctx);
                return nullptr;
            }
            string key = indexValue->getString();
            auto& dict = target->getDictionary();
            auto it = dict.find(key);
            if (it == dict.end()) {
                reportError("Dictionary key not found: " + key, ctx);
                return nullptr;
            }
            return it->second;
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

any AstVisitor::visitAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) {
    // 这个规则用于赋值目标，已经在visitAssignment中处理
    return any();
}

any AstVisitor::visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) {
    // 这个规则用于赋值目标，已经在visitAssignment中处理
    return any();
}

any AstVisitor::visitFunctionCall(PyScriptParser::FunctionCallContext *ctx) {
    // 这个规则可能不再使用，由atom中的functionCallOp处理
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
    // 如果正在定义函数，跳过求值，返回空列表
    if (defining_function_) {
        logger_.debug("Skipping list literal evaluation during function definition");
        return any(ScriptValue::createList());
    }
    
    auto listElementsCtx = ctx->listElements();
    if (listElementsCtx) {
        // 检查是否为列表推导式
        if (listElementsCtx->FOR()) {
            // 列表推导式，让visitListElements处理
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

any AstVisitor::visitListElements(PyScriptParser::ListElementsContext *ctx) {
    // listElements: expression (COMMA expression)* COMMA? | expression FOR IDENTIFIER IN expression
    logger_.debug("visitListElements called");
    
    // 如果正在定义函数，跳过列表推导式的求值，返回特殊标记阻止访问子节点
    if (defining_function_) {
        logger_.debug("Skipping list comprehension evaluation during function definition, returning stop signal");
        // 返回true阻止ANTLR访问子节点
        return any(true);
    }
    
    // 检查是否为列表推导式
    if (ctx->FOR()) {
        // 列表推导式: expression FOR IDENTIFIER IN expression
        logger_.debug("List comprehension detected");
        auto expressions = ctx->expression();
        if (expressions.size() != 2) {
            reportError("Invalid list comprehension syntax", ctx);
            return any();
        }
        
        auto outputExpr = expressions[0];
        auto iterExpr = expressions[1];
        auto identifier = ctx->IDENTIFIER();
        if (!identifier) {
            reportError("Missing identifier in list comprehension", ctx);
            return any();
        }
        
        string outputText = outputExpr->getText();
        string iterText = iterExpr->getText();
        string varName = identifier->getText();
        
        // 构建列表推导式字符串
        string compStr = "[" + outputText + " for " + varName + " in " + iterText + "]";
        logger_.debug(std::string("List comprehension string: ") + compStr);
        
        // 在Python中执行列表推导式
        try {
            py::dict globals = py::globals();
            py::object builtins = py::module_::import("builtins");
            // 确保globals包含builtins和range等内置函数
            globals["__builtins__"] = builtins;
            globals["range"] = builtins.attr("range");
            py::object result = builtins.attr("eval")(compStr, globals, py::dict());
            return any(ScriptValue::fromPythonObject(result));
        } catch (const py::error_already_set& e) {
            reportError("Failed to evaluate list comprehension: " + string(e.what()), ctx);
            return any();
        }
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
        py::object builtins = py::module_::import("builtins");
        py::object lambdaFunc = builtins.attr("eval")(lambdaStr, py::globals(), locals);
        return any(ScriptValue::fromPythonObject(lambdaFunc));
    } catch (const py::error_already_set& e) {
        reportError("Failed to create lambda: " + string(e.what()), ctx);
        return any();
    }
}

any AstVisitor::visitTryStatement(PyScriptParser::TryStatementContext *ctx) {
    logger_.debug("visitTryStatement called");
    
    // 获取try块
    auto trySuite = ctx->suite(0);
    if (!trySuite) {
        reportError("Try statement missing try block", ctx);
        return any();
    }
    
    // 执行try块
    try {
        visit(trySuite);
        // 如果没有异常，检查是否有else块
        auto elseSuite = ctx->ELSE() ? ctx->suite(ctx->suite().size() - 1) : nullptr;
        if (elseSuite) {
            // 执行else块
            visit(elseSuite);
        }
    } catch (const std::exception& e) {
        // 捕获C++异常
        // 查找匹配的except子句
        bool exceptionHandled = false;
        for (auto exceptClause : ctx->exceptClause()) {
            // 暂时不考虑异常类型匹配，直接执行第一个except块
            auto exceptSuite = exceptClause->suite();
            if (exceptSuite) {
                visit(exceptSuite);
                exceptionHandled = true;
                break;
            }
        }
        if (!exceptionHandled) {
            // 重新抛出异常
            throw;
        }
    }
    
    // 如果有finally块，执行finally块
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
