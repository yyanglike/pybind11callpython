#include "script_interpreter.h"
#include "antlr/PyScriptLexer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>

using namespace antlr4;
using namespace std;

using namespace script_interpreter;

py::object ScriptInterpreter::evalInlineExpression(const std::string& expr_text) {
    try {
        ANTLRInputStream input(expr_text);
        PyScriptLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        tokens.fill();
        PyScriptParser parser(&tokens);
        parser.removeErrorListeners();
        auto exprCtx = parser.expression();
        auto anyVal = ast_visitor_.visit(exprCtx);
        if (anyVal.has_value()) {
            try {
                auto sv = any_cast<std::shared_ptr<ScriptValue>>(anyVal);
                if (sv) {
                    return sv->toPythonObject();
                }
            } catch (const bad_any_cast&) {
                // ignore
            }
        }
    } catch (...) {
        // ignore and fallthrough
    }
    return py::none();
}

// 构造函数
ScriptInterpreter::ScriptInterpreter()
    : result_(nullptr),
      defining_function_(false),
      expression_evaluator_(variable_manager_, error_handler_, logger_, python_bridge_),
      ast_visitor_(variable_manager_, error_handler_, logger_, python_bridge_, expression_evaluator_) {

    logger_.info("ScriptInterpreter constructor started");
    // Python桥接器自动初始化Python解释器
    logger_.debug("PythonBridge initialized");
    
    // 导入builtins模块以供内置函数使用
    try {
        py::module_ builtins = py::module_::import("builtins");
        variable_manager_.setBuiltins(builtins);
        logger_.info("Builtins imported successfully");
    } catch (const exception& e) {
        logger_.error(std::string("Failed to import builtins: ") + e.what());
        // 将builtins设置为none，后续使用时再尝试导入
        variable_manager_.setBuiltins(py::none());
    }
    logger_.debug("ScriptInterpreter constructor finished");
}
// 析构函数
ScriptInterpreter::~ScriptInterpreter() {
    try {
        // 清理所有可能持有Python对象的成员，避免在Python解释器已终止后析构时导致崩溃
        variable_manager_.clearAll();
        result_.reset();
    } catch (...) {
        // 忽略清理错误
    }
}
bool ScriptInterpreter::execute(const string& script) {
    logger_.debug(std::string("ScriptInterpreter::execute() called with script: ") + script);
    error_handler_.clearErrors();
    result_ = nullptr;
    
    try {
        // 预处理：将 f-string 转为 __fstr__('f"...' 或三引号形式) 形式，避免语法不支持
        auto transform_fstrings = [](const std::string& in) -> std::string {
            std::string out;
            out.reserve(in.size());
            size_t i = 0;
            while (i < in.size()) {
                char c = in[i];
                if ((c == 'f' || c == 'F') && i + 1 < in.size() && (in[i + 1] == '"' || in[i + 1] == '\'')) {
                    // 检测单引号/双引号/三引号
                    bool triple = false;
                    char quote = in[i + 1];
                    size_t j = i + 2;
                    if (j + 1 < in.size() && in[j] == quote && in[j + 1] == quote) {
                        triple = true;
                        j += 2;
                    }
                    bool closed = false;
                    while (j < in.size()) {
                        char cc = in[j];
                        if (cc == '\\') {
                            j += 2; // skip escaped
                            continue;
                        }
                        if (!triple) {
                            if (cc == quote) {
                                closed = true;
                                ++j;
                                break;
                            }
                        } else {
                            if (cc == quote && j + 2 < in.size() && in[j + 1] == quote && in[j + 2] == quote) {
                                closed = true;
                                j += 3;
                                break;
                            }
                        }
                        ++j;
                    }
                    std::string raw = in.substr(i, j - i); // f"...", f'''...''' 或 f"""..."""
                    // 选择包裹引号：若原串用单引号（含三引号），则用双引号作为包裹，反之亦然
                    char wrapper = (quote == '\'') ? '"' : '\'';
                    // 对包裹引号、反斜线以及换行/回车做转义（换行转为 \n，避免单行字符串解析失败）
                    std::string escaped;
                    escaped.reserve(raw.size() * 2);
                    for (char rc : raw) {
                        if (rc == '\n') {
                            escaped += "\\n";
                        } else if (rc == '\r') {
                            escaped += "\\r";
                        } else {
                            if (rc == '\\' || rc == wrapper) escaped.push_back('\\');
                            escaped.push_back(rc);
                        }
                    }
                    out += "__fstr__(";
                    out.push_back(wrapper);
                    out += escaped;
                    out.push_back(wrapper);
                    out += ")";
                    i = j;
                    if (!closed) {
                        // 未闭合时保留剩余文本，避免截断
                        out += in.substr(i);
                        break;
                    }
                    continue;
                }
                out.push_back(c);
                ++i;
            }
            return out;
        };
        std::string preprocessed = transform_fstrings(script);

        logger_.debug("Creating ANTLRInputStream...");
        ANTLRInputStream input(preprocessed);
        logger_.debug("Creating PyScriptLexer...");
        PyScriptLexer lexer(&input);
        logger_.debug("Creating CommonTokenStream...");
        CommonTokenStream tokens(&lexer);
        
        // 填充token流
        logger_.debug("Filling tokens...");
        tokens.fill();
        
        logger_.debug("Creating PyScriptParser...");
        PyScriptParser parser(&tokens);
        
        // 设置错误处理器
        parser.removeErrorListeners();
        
        logger_.debug("Parsing program...");
        auto tree = parser.program();
        logger_.debug("Parse tree created successfully");

        // 提供 __fstr__ 辅助：使用 Python eval 计算 f-string
        try {
            auto fstr_func = py::cpp_function([this](py::str fmt) {
                std::string raw = py::cast<std::string>(fmt);
                // 去掉前缀 f/F 及引号，保留内容
                size_t pos = 0;
                if (!raw.empty() && (raw[0] == 'f' || raw[0] == 'F')) {
                    pos = 1;
                }
                if (pos >= raw.size()) return fmt;
                char quote = raw[pos];
                bool triple = false;
                if (pos + 2 < raw.size() && raw[pos] == raw[pos + 1] && raw[pos] == raw[pos + 2]) {
                    triple = true;
                }
                size_t start = pos + (triple ? 3 : 1);
                size_t end = raw.size();
                if (end >= (triple ? 3 : 1)) {
                    end -= (triple ? 3 : 1);
                }
                std::string content = raw.substr(start, end - start);

                std::string result;
                result.reserve(content.size());
                size_t i = 0;
                auto eval_expr = [this](const std::string& expr) -> py::object {
                    return evalInlineExpression(expr);
                };
                while (i < content.size()) {
                    char c = content[i];
                    if (c == '{') {
                        if (i + 1 < content.size() && content[i + 1] == '{') {
                            result.push_back('{');
                            i += 2;
                            continue;
                        }
                        size_t j = i + 1;
                        int depth = 1;
                        while (j < content.size() && depth > 0) {
                            if (content[j] == '{') depth++;
                            else if (content[j] == '}') depth--;
                            j++;
                        }
                        size_t expr_end = j - 1; // position of closing }
                        std::string expr_raw = content.substr(i + 1, expr_end - (i + 1));
                        // 解析转换和格式
                        std::string expr_part = expr_raw;
                        std::string fmt_part;
                        std::string conv_part;
                        // 找到顶层的 '!' 或 ':' 分隔
                        int brace_depth = 0;
                        for (size_t k = 0; k < expr_raw.size(); ++k) {
                            char ek = expr_raw[k];
                            if (ek == '{') brace_depth++;
                            else if (ek == '}') brace_depth--;
                            if (brace_depth == 0 && (ek == '!' || ek == ':')) {
                                expr_part = expr_raw.substr(0, k);
                                if (ek == '!') {
                                    if (k + 1 < expr_raw.size()) {
                                        conv_part = std::string(1, expr_raw[k + 1]);
                                        if (k + 2 < expr_raw.size() && expr_raw[k + 2] == ':') {
                                            fmt_part = expr_raw.substr(k + 3);
                                        }
                                    }
                                } else { // ':'
                                    fmt_part = expr_raw.substr(k + 1);
                                }
                                break;
                            }
                        }
                        py::object val = eval_expr(expr_part);
                        try {
                            if (!conv_part.empty()) {
                                if (conv_part == "r") val = py::repr(val);
                                else if (conv_part == "s") val = py::str(val);
                                else if (conv_part == "a") val = py::reinterpret_borrow<py::object>(PyObject_ASCII(val.ptr()));
                            }
                            if (!fmt_part.empty()) {
                                std::string pat = "{:" + fmt_part + "}";
                                py::str formatted = py::str(pat).attr("format")(val);
                                result += std::string(formatted);
                            } else {
                                result += std::string(py::str(val));
                            }
                        } catch (...) {
                            result += "{ERR}";
                        }
                        i = j;
                        continue;
                    } else if (c == '}' && i + 1 < content.size() && content[i + 1] == '}') {
                        result.push_back('}');
                        i += 2;
                        continue;
                    } else {
                        result.push_back(c);
                        ++i;
                    }
                }
                return py::str(result);
            });
            py::globals()["__fstr__"] = fstr_func;
            variable_manager_.setVariable("__fstr__", ScriptValue::fromPythonObject(fstr_func));
        } catch (...) {
            // 忽略
        }

        // 统一初始化 sys.argv，避免脚本访问 sys.argv 为 None/非列表
        try {
            py::module_ sys_mod = py::module_::import("sys");
            py::list argv_list;
            argv_list.append(py::cast(""));  // 占位脚本名
            sys_mod.attr("argv") = argv_list;
        } catch (...) {
            // 忽略
        }

        // 提供容错版 range：None->0，其他尝试 int 转换，失败返回 range(0)，仅注入脚本 globals
        try {
            py::module_ builtins_mod = py::module_::import("builtins");
            py::object orig_range = builtins_mod.attr("range");
            py::object safe_range = py::cpp_function([orig_range](py::args args) {
                py::list coerced;
                try {
                    for (auto a : args) {
                        py::object obj = py::reinterpret_borrow<py::object>(a);
                        if (obj.is_none()) {
                            coerced.append(0);
                        } else {
                            coerced.append(py::int_(obj));
                        }
                    }
                    return orig_range(*coerced);
                } catch (...) {
                    return orig_range(0);
                }
            });
            py::globals()["range"] = safe_range;
            variable_manager_.setVariable("range", ScriptValue::fromPythonObject(safe_range));
        } catch (...) {
            // 忽略
        }
        
        if (error_handler_.hasError()) {
            logger_.warn("Has error before visiting");
            return false;
        }
        
        // 遍历AST
        logger_.debug("Visiting program tree...");
        visitProgram(tree);
        logger_.debug("Visit completed");
        // 返回是否执行成功（无错误）
        return !error_handler_.hasError();
    } catch (const exception& e) {
        logger_.error(std::string("Script execution error: ") + e.what());
        reportError("Script execution error: " + string(e.what()), ScriptErrorType::Runtime, ScriptErrorCode::Unknown);
        return false;
    }
}

// ========== Visitor方法实现 ==========

any ScriptInterpreter::visitProgram(PyScriptParser::ProgramContext *ctx) {
    // 执行所有语句
    for (auto stmt : ctx->statement()) {
        ast_visitor_.visit(stmt);
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

any ScriptInterpreter::visitStatement(PyScriptParser::StatementContext *ctx) {
    // 根据实际的子节点类型进行分发
    if (ctx->simpleStatement()) {
        return ast_visitor_.visit(ctx->simpleStatement());
    } else if (ctx->compoundStatement()) {
        return ast_visitor_.visit(ctx->compoundStatement());
    }
    
    reportError("Unknown statement type", ctx);
    return any();
}

any ScriptInterpreter::visitSimpleImport(PyScriptParser::SimpleImportContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitSimpleImport(ctx);
}

any ScriptInterpreter::visitFromImport(PyScriptParser::FromImportContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitFromImport(ctx);
}

any ScriptInterpreter::visitImportItem(PyScriptParser::ImportItemContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitImportItem(ctx);
}

any ScriptInterpreter::visitFunctionDef(PyScriptParser::FunctionDefContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitFunctionDef(ctx);
}

any ScriptInterpreter::visitParameterList(PyScriptParser::ParameterListContext *ctx) {
    // 参数列表已经在函数定义中处理
    return any();
}

any ScriptInterpreter::visitIfStatement(PyScriptParser::IfStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitIfStatement(ctx);
}

any ScriptInterpreter::visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitWhileStatement(ctx);
}

any ScriptInterpreter::visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitReturnStatement(ctx);
}

any ScriptInterpreter::visitSuite(PyScriptParser::SuiteContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitSuite(ctx);
}

any ScriptInterpreter::visitSimpleStatement(PyScriptParser::SimpleStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitSimpleStatement(ctx);
}

any ScriptInterpreter::visitSmallStatement(PyScriptParser::SmallStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitSmallStatement(ctx);
}

any ScriptInterpreter::visitCompoundStatement(PyScriptParser::CompoundStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitCompoundStatement(ctx);
}

any ScriptInterpreter::visitPassStatement(PyScriptParser::PassStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitPassStatement(ctx);
}


any ScriptInterpreter::visitAssignment(PyScriptParser::AssignmentContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitAssignment(ctx);
}


any ScriptInterpreter::visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitExpressionStatement(ctx);
}

any ScriptInterpreter::visitExpression(PyScriptParser::ExpressionContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitExpression(ctx);
}

any ScriptInterpreter::visitConditionalExpr(PyScriptParser::ConditionalExprContext *ctx){
    return ast_visitor_.visitConditionalExpr(ctx);
}

any ScriptInterpreter::visitConditional(PyScriptParser::ConditionalContext *ctx){
    return ast_visitor_.visitConditional(ctx);
}

any ScriptInterpreter::visitBitwiseOrExpr(PyScriptParser::BitwiseOrExprContext *ctx){
    return ast_visitor_.visitBitwiseOrExpr(ctx);
}

any ScriptInterpreter::visitBitwiseXorExpr(PyScriptParser::BitwiseXorExprContext *ctx){
    return ast_visitor_.visitBitwiseXorExpr(ctx);
}

any ScriptInterpreter::visitBitwiseAndExpr(PyScriptParser::BitwiseAndExprContext *ctx){
    return ast_visitor_.visitBitwiseAndExpr(ctx);
}

any ScriptInterpreter::visitShiftExpr(PyScriptParser::ShiftExprContext *ctx){
    return ast_visitor_.visitShiftExpr(ctx);
}

any ScriptInterpreter::visitTuple(PyScriptParser::TupleContext *ctx){
    return ast_visitor_.visitTuple(ctx);
}

any ScriptInterpreter::visitComprehension(PyScriptParser::ComprehensionContext *ctx){
    return ast_visitor_.visitComprehension(ctx);
}

any ScriptInterpreter::visitCompFor(PyScriptParser::CompForContext *ctx){
    return ast_visitor_.visitCompFor(ctx);
}

any ScriptInterpreter::visitFunctionCall(PyScriptParser::FunctionCallContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitFunctionCall(ctx);
}

any ScriptInterpreter::visitAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitAttributeAccess(ctx);
}

any ScriptInterpreter::visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitSubscriptAccess(ctx);
}

any ScriptInterpreter::visitNewExpression(PyScriptParser::NewExpressionContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitNewExpression(ctx);
}

any ScriptInterpreter::visitLiteral(PyScriptParser::LiteralContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitLiteral(ctx);
}

any ScriptInterpreter::visitListLiteral(PyScriptParser::ListLiteralContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitListLiteral(ctx);
}

any ScriptInterpreter::visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitDictLiteral(ctx);
}

any ScriptInterpreter::visitSetLiteral(PyScriptParser::SetLiteralContext *ctx) {
    return ast_visitor_.visitSetLiteral(ctx);
}

any ScriptInterpreter::visitSetElements(PyScriptParser::SetElementsContext *ctx) {
    return ast_visitor_.visitSetElements(ctx);
}

any ScriptInterpreter::visitGeneratorExpression(PyScriptParser::GeneratorExpressionContext *ctx) {
    return ast_visitor_.visitGeneratorExpression(ctx);
}

any ScriptInterpreter::visitDictComprehension(PyScriptParser::DictComprehensionContext *ctx) {
    return ast_visitor_.visitDictComprehension(ctx);
}

any ScriptInterpreter::visitDottedName(PyScriptParser::DottedNameContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitDottedName(ctx);
}

any ScriptInterpreter::visitArgumentList(PyScriptParser::ArgumentListContext *ctx) {
    // 参数列表已经在函数调用中处理
    return any();
}




any ScriptInterpreter::visitForStatement(PyScriptParser::ForStatementContext *ctx) {
    return ast_visitor_.visitForStatement(ctx);
}






// 新的visitor方法实现

any ScriptInterpreter::visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitAttributeAccessOp(ctx);
}

any ScriptInterpreter::visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitSubscriptAccessOp(ctx);
}

any ScriptInterpreter::visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitFunctionCallOp(ctx);
}

// 新增的参数和参数相关方法实现
any ScriptInterpreter::visitParameter(PyScriptParser::ParameterContext *ctx) {
    logger_.debug("visitParameter called");
    // 参数解析在函数定义阶段处理，这里保持占位
    return any();
}


// 缺失的成员函数实现
shared_ptr<ScriptValue> ScriptInterpreter::getVariable(const string& name) {
    return variable_manager_.getVariable(name);
}

void ScriptInterpreter::setVariable(const string& name, shared_ptr<ScriptValue> value) {
    variable_manager_.setVariable(name, value);
}

void ScriptInterpreter::clearEnvironment() {
    variable_manager_.clearAll();
}

shared_ptr<ScriptValue> ScriptInterpreter::evaluateExpression(PyScriptParser::ExpressionContext *ctx) {
    return ast_visitor_.evaluateExpression(ctx);
}

shared_ptr<ScriptValue> ScriptInterpreter::executeSuite(PyScriptParser::SuiteContext *ctx) {
    return ast_visitor_.executeSuite(ctx);
}



void ScriptInterpreter::reportError(const string& message,
                                    ScriptErrorType type,
                                    ScriptErrorCode code,
                                    int line, int column) {
    error_handler_.reportError(message, type, code, line, column);
}

void ScriptInterpreter::reportError(const string& message, antlr4::ParserRuleContext *ctx,
                                    ScriptErrorType type,
                                    ScriptErrorCode code) {
    int line = -1, column = -1;
    if (ctx) {
        auto token = ctx->getStart();
        if (token) {
            line = token->getLine();
            column = token->getCharPositionInLine();
        }
    }
    error_handler_.reportError(message, type, code, line, column);
}

bool ScriptInterpreter::executeFile(const string& filename) {
    logger_.debug(std::string("ScriptInterpreter::executeFile() called with file: ") + filename);
    error_handler_.clearErrors();
    result_ = nullptr;

    try {
        // 打开文件
        ifstream file(filename);
        if (!file.is_open()) {
            reportError("Cannot open file: " + filename, ScriptErrorType::Runtime, ScriptErrorCode::FileNotFound);
            return false;
        }

        // 读取文件内容
        stringstream buffer;
        buffer << file.rdbuf();
        string script = buffer.str();
        file.close();

        logger_.debug(std::string("File content length: ") + to_string(script.length()));

        // 执行脚本
        return execute(script);
    } catch (const exception& e) {
        logger_.error(std::string("File execution error: ") + e.what());
        reportError("File execution error: " + string(e.what()), ScriptErrorType::Runtime, ScriptErrorCode::Unknown);
        return false;
    }
}

any ScriptInterpreter::visitLogicalOr(PyScriptParser::LogicalOrContext *ctx) {
    return ast_visitor_.visitLogicalOr(ctx);
}

any ScriptInterpreter::visitLogicalAnd(PyScriptParser::LogicalAndContext *ctx) {
    return ast_visitor_.visitLogicalAnd(ctx);
}


any ScriptInterpreter::visitEquality(PyScriptParser::EqualityContext *ctx) {
    return ast_visitor_.visitEquality(ctx);
}

any ScriptInterpreter::visitComparison(PyScriptParser::ComparisonContext *ctx) {
    return ast_visitor_.visitComparison(ctx);
}


any ScriptInterpreter::visitAdditive(PyScriptParser::AdditiveContext *ctx) {
    return ast_visitor_.visitAdditive(ctx);
}

any ScriptInterpreter::visitMultiplicative(PyScriptParser::MultiplicativeContext *ctx) {
    return ast_visitor_.visitMultiplicative(ctx);
}

any ScriptInterpreter::visitUnary(PyScriptParser::UnaryContext *ctx) {
    return ast_visitor_.visitUnary(ctx);
}

any ScriptInterpreter::visitPrimary(PyScriptParser::PrimaryContext *ctx) {
    return ast_visitor_.visitPrimary(ctx);
}


any ScriptInterpreter::visitAtom(PyScriptParser::AtomContext *ctx) {
    return ast_visitor_.visitAtom(ctx);
}

any ScriptInterpreter::visitArgument(PyScriptParser::ArgumentContext *ctx) {
    return ast_visitor_.visitArgument(ctx);
}

any ScriptInterpreter::visitDictItem(PyScriptParser::DictItemContext *ctx) {
    return ast_visitor_.visitDictItem(ctx);
}

any ScriptInterpreter::visitPower(PyScriptParser::PowerContext *ctx) {
    return ast_visitor_.visitPower(ctx);
}

any ScriptInterpreter::visitListElements(PyScriptParser::ListElementsContext *ctx) {
    return ast_visitor_.visitListElements(ctx);
}


any ScriptInterpreter::visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) {
    return ast_visitor_.visitLambdaExpression(ctx);
}

any ScriptInterpreter::visitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) {
    // Delegate to AstVisitor's implementation
    return ast_visitor_.visitSubscriptArg(ctx);
}

any ScriptInterpreter::visitTryStatement(PyScriptParser::TryStatementContext *ctx) {
    return ast_visitor_.visitTryStatement(ctx);
}

any ScriptInterpreter::visitExceptClause(PyScriptParser::ExceptClauseContext *ctx) {
    return ast_visitor_.visitExceptClause(ctx);
}

any ScriptInterpreter::visitWithStatement(PyScriptParser::WithStatementContext *ctx) {
    return ast_visitor_.visitWithStatement(ctx);
}

any ScriptInterpreter::visitWithItem(PyScriptParser::WithItemContext *ctx) {
    return ast_visitor_.visitWithItem(ctx);
}

any ScriptInterpreter::visitAsyncFunctionDef(PyScriptParser::AsyncFunctionDefContext *ctx) {
    return ast_visitor_.visitAsyncFunctionDef(ctx);
}

any ScriptInterpreter::visitAsyncForStatement(PyScriptParser::AsyncForStatementContext *ctx) {
    return ast_visitor_.visitAsyncForStatement(ctx);
}

any ScriptInterpreter::visitAsyncWithStatement(PyScriptParser::AsyncWithStatementContext *ctx) {
    return ast_visitor_.visitAsyncWithStatement(ctx);
}

any ScriptInterpreter::visitAwaitExpr(PyScriptParser::AwaitExprContext *ctx) {
    return ast_visitor_.visitAwaitExpr(ctx);
}

any ScriptInterpreter::visitDecorators(PyScriptParser::DecoratorsContext *ctx) {
    return ast_visitor_.visitDecorators(ctx);
}

any ScriptInterpreter::visitDecorator(PyScriptParser::DecoratorContext *ctx) {
    return ast_visitor_.visitDecorator(ctx);
}

any ScriptInterpreter::visitDecoratedDef(PyScriptParser::DecoratedDefContext *ctx) {
    return ast_visitor_.visitDecoratedDef(ctx);
}

any ScriptInterpreter::visitClassDef(PyScriptParser::ClassDefContext *ctx) {
    return ast_visitor_.visitClassDef(ctx);
}
