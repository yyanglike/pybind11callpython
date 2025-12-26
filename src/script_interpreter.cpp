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
        logger_.debug("Creating ANTLRInputStream...");
        ANTLRInputStream input(script);
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
