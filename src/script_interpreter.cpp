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

// 执行脚本
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
        
        return !error_handler_.hasError();
        
    } catch (const exception& e) {
        logger_.error(std::string("Exception in execute: ") + e.what());
        reportError("Script execution error: " + string(e.what()));
        return false;
    }
}

bool ScriptInterpreter::executeFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        reportError("Cannot open file: " + filename);
        return false;
    }
    
    stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    
    return execute(buffer.str());
}

shared_ptr<ScriptValue> ScriptInterpreter::getVariable(const string& name) {
    return variable_manager_.getVariable(name);
}

void ScriptInterpreter::setVariable(const string& name, shared_ptr<ScriptValue> value) {
    variable_manager_.setVariable(name, value);
}

void ScriptInterpreter::clearEnvironment() {
    variable_manager_.clearVariables();
    result_ = nullptr;
    error_handler_.clearErrors();
}

// ========== 错误报告 ===========

void ScriptInterpreter::reportError(const std::string& message,
                                    ScriptErrorType type,
                                    ScriptErrorCode code,
                                    int line, int column) {
    error_handler_.reportError(message, type, code, line, column);
    logger_.error(std::string("Script Error: ") + message + " [Type=" + to_string(static_cast<int>(type))
              + ", Code=" + to_string(static_cast<int>(code)) + ", Line=" + to_string(line) + ", Col=" + to_string(column) + "]");
}

void ScriptInterpreter::reportError(const std::string& message, antlr4::ParserRuleContext *ctx,
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
    logger_.error(std::string("Script Error: ") + message + " [Type=" + to_string(static_cast<int>(type))
              + ", Code=" + to_string(static_cast<int>(code)) + ", Line=" + to_string(line) + ", Col=" + to_string(column) + "]");
}

// ========== 辅助方法 ==========

shared_ptr<ScriptValue> ScriptInterpreter::evaluateExpression(PyScriptParser::ExpressionContext *ctx) {
    if (!ctx) {
        logger_.error("evaluateExpression: ctx is null!");
        return nullptr;
    }
    auto result = ast_visitor_.visit(ctx);
    try {
        return any_cast<shared_ptr<ScriptValue>>(result);
    } catch (const bad_any_cast&) {
        return nullptr;
    }
}







shared_ptr<ScriptValue> ScriptInterpreter::executeBlock(PyScriptParser::BlockContext *ctx) {
    if (!ctx) {
        return nullptr;
    }
    
    if (ctx->statement().empty()) {
        return ScriptValue::createNull();
    }
    
    // 执行代码块中的所有语句
    shared_ptr<ScriptValue> lastResult = nullptr;
    for (auto stmt : ctx->statement()) {
        auto result = ast_visitor_.visit(stmt);
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
    if (result_ == nullptr && ctx->statement().size() > 0) {
        // 尝试获取最后一个表达式语句的结果
        auto lastStmt = ctx->statement().back();
        // 使用ANTLR上下文方法检查是否是expressionStatement
        auto exprStmt = lastStmt->expressionStatement();
        if (exprStmt) {
            result_ = evaluateExpression(exprStmt->expression());
        }
    }
    
    return any();
}

any ScriptInterpreter::visitStatement(PyScriptParser::StatementContext *ctx) {
    // 根据实际的子节点类型进行分发
    if (ctx->importStatement()) {
        return ast_visitor_.visit(ctx->importStatement());
    } else if (ctx->functionDefinition()) {
        return ast_visitor_.visit(ctx->functionDefinition());
    } else if (ctx->assignment()) {
        return ast_visitor_.visit(ctx->assignment());
    } else if (ctx->ifStatement()) {
        return ast_visitor_.visit(ctx->ifStatement());
    } else if (ctx->whileStatement()) {
        return ast_visitor_.visit(ctx->whileStatement());
    } else if (ctx->forStatement()) {
        return ast_visitor_.visit(ctx->forStatement());
    } else if (ctx->returnStatement()) {
        return ast_visitor_.visit(ctx->returnStatement());
    } else if (ctx->expressionStatement()) {
        return ast_visitor_.visit(ctx->expressionStatement());
    }
    
    reportError("Unknown statement type", ctx);
    return any();
}

any ScriptInterpreter::visitImportStatement(PyScriptParser::ImportStatementContext *ctx) {
    logger_.debug("visitImportStatement called");
    
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
        if (ctx->IDENTIFIER()) {
            alias = ctx->IDENTIFIER()->getText();
            logger_.debug(std::string("Alias: ") + alias);
        }
        
        // 导入Python模块
        logger_.debug("Calling py::module_::import...");
        py::module_ module = py::module_::import(moduleName.c_str());
        logger_.info(std::string("Module imported successfully: ") + moduleName);
        
        // 存储模块到VariableManager
        variable_manager_.importModule(moduleName, module);
        
        // 存储模块引用到变量
        if (!alias.empty()) {
            variable_manager_.setVariable(alias, ScriptValue::createPythonObject(module));
            logger_.debug(std::string("Module stored in variables with alias: ") + alias);
        } else {
            // 使用模块名的最后一部分作为变量名
            size_t dotPos = moduleName.find_last_of('.');
            string shortName = (dotPos != string::npos) ? 
                              moduleName.substr(dotPos + 1) : moduleName;
            variable_manager_.setVariable(shortName, ScriptValue::createPythonObject(module));
            logger_.debug(std::string("Module stored in variables with short name: ") + shortName);
        }
        
        // 验证存储
        logger_.debug("Verifying storage...");
        if (!alias.empty()) {
            auto var = variable_manager_.getVariable(alias);
            if (var) {
                logger_.debug(std::string("Variable '") + alias + "' found in variables map");
            } else {
                logger_.error(std::string("ERROR: Variable '") + alias + "' NOT found in variables map!");
            }
        }
        
    } catch (const py::error_already_set& e) {
        logger_.error(std::string("Python import error: ") + e.what());
        reportError("Failed to import module: " + string(e.what()), ctx);
    } catch (const exception& e) {
        logger_.error(std::string("General import error: ") + e.what());
        reportError("Import error: " + string(e.what()), ctx);
    }
    
    return any();
}

any ScriptInterpreter::visitFunctionDefinition(PyScriptParser::FunctionDefinitionContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitFunctionDefinition(ctx);
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

any ScriptInterpreter::visitBlock(PyScriptParser::BlockContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitBlock(ctx);
}

any ScriptInterpreter::visitAssignment(PyScriptParser::AssignmentContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitAssignment(ctx);
}

any ScriptInterpreter::visitAssignmentOperator(PyScriptParser::AssignmentOperatorContext *ctx) {
    // 赋值操作符已经在visitAssignment中处理
    return any();
}

any ScriptInterpreter::visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitExpressionStatement(ctx);
}

any ScriptInterpreter::visitExpression(PyScriptParser::ExpressionContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitExpression(ctx);
}

any ScriptInterpreter::visitTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) {
    // 检查是否有三元操作符
    if (ctx->children.size() == 1) {
        // 没有三元操作符，直接返回逻辑或表达式
        // 注意：logicalOrExpression() 返回的是 vector，我们需要第一个元素
        auto logicalOrExprs = ctx->logicalOrExpression();
        if (!logicalOrExprs.empty()) {
            return ast_visitor_.visit(logicalOrExprs[0]);
        } else {
            reportError("Missing logical or expression in ternary expression", ctx);
            return any();
        }
    }
    
    // 检查是Python风格 (if-else) 还是C风格 (?:)
    bool pythonStyle = false;
    for (size_t i = 0; i < ctx->children.size(); ++i) {
        if (ctx->children[i]->getText() == "if") {
            pythonStyle = true;
            break;
        }
    }
    
    if (pythonStyle) {
        // Python风格: logicalOrExpression 'if' logicalOrExpression 'else' ternaryExpression
        // 我们需要找到各个部分
        std::vector<PyScriptParser::LogicalOrExpressionContext*> logicalOrExprs;
        PyScriptParser::TernaryExpressionContext* falseExpr = nullptr;
        
        for (auto child : ctx->children) {
            auto logicalOr = dynamic_cast<PyScriptParser::LogicalOrExpressionContext*>(child);
            if (logicalOr) {
                logicalOrExprs.push_back(logicalOr);
            }
            auto ternary = dynamic_cast<PyScriptParser::TernaryExpressionContext*>(child);
            if (ternary && child != ctx) {
                falseExpr = ternary;
            }
        }
        
        if (logicalOrExprs.size() >= 2 && falseExpr) {
            // 第一个logicalOrExpression是true表达式
            // 第二个logicalOrExpression是条件
            auto trueExprCtx = logicalOrExprs[0];
            auto condExprCtx = logicalOrExprs[1];
            
            // 使用ast_visitor_获取条件值
            auto condAny = ast_visitor_.visit(condExprCtx);
            shared_ptr<ScriptValue> condValue;
            try {
                condValue = any_cast<shared_ptr<ScriptValue>>(condAny);
            } catch (const bad_any_cast&) {
                reportError("Cannot evaluate condition in Python-style ternary expression", ctx);
                return any();
            }
            
            if (!condValue) {
                reportError("Cannot evaluate condition in Python-style ternary expression", ctx);
                return any();
            }
            
            if (expression_evaluator_.isTruthy(condValue)) {
                return ast_visitor_.visit(trueExprCtx);
            } else {
                return ast_visitor_.visit(falseExpr);
            }
        } else {
            reportError("Invalid Python-style ternary expression", ctx);
            return any();
        }
    } else {
        // C风格：condition ? trueExpr : falseExpr
        // 语法是 logicalOrExpression '?' expression ':' ternaryExpression
        auto logicalOrExprs = ctx->logicalOrExpression();
        if (logicalOrExprs.empty()) {
            reportError("Missing condition in C-style ternary expression", ctx);
            return any();
        }
        auto condExprCtx = logicalOrExprs[0];
        PyScriptParser::ExpressionContext* trueExprCtx = nullptr;
        PyScriptParser::TernaryExpressionContext* falseExprCtx = nullptr;
        
        // 找到expression和ternaryExpression
        for (auto child : ctx->children) {
            if (!trueExprCtx) {
                auto expr = dynamic_cast<PyScriptParser::ExpressionContext*>(child);
                if (expr) {
                    trueExprCtx = expr;
                    continue;
                }
            }
            if (!falseExprCtx) {
                auto ternary = dynamic_cast<PyScriptParser::TernaryExpressionContext*>(child);
                if (ternary && child != ctx) {
                    falseExprCtx = ternary;
                }
            }
        }
        
        if (condExprCtx && trueExprCtx && falseExprCtx) {
            // 使用ast_visitor_获取条件值
            auto condAny = ast_visitor_.visit(condExprCtx);
            shared_ptr<ScriptValue> condValue;
            try {
                condValue = any_cast<shared_ptr<ScriptValue>>(condAny);
            } catch (const bad_any_cast&) {
                reportError("Cannot evaluate condition in ternary expression", ctx);
                return any();
            }
            
            if (!condValue) {
                reportError("Cannot evaluate condition in ternary expression", ctx);
                return any();
            }
            
            if (expression_evaluator_.isTruthy(condValue)) {
                return evaluateExpression(trueExprCtx);
            } else {
                return ast_visitor_.visit(falseExprCtx);
            }
        } else {
            reportError("Invalid C-style ternary expression", ctx);
            return any();
        }
    }
}

any ScriptInterpreter::visitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *ctx) {
    auto logicalAndExprs = ctx->logicalAndExpression();
    if (logicalAndExprs.size() == 1) {
        return ast_visitor_.visit(logicalAndExprs[0]);
    }
    
    // 处理多个逻辑或表达式
    shared_ptr<ScriptValue> result;
    for (auto expr : logicalAndExprs) {
        auto valAny = ast_visitor_.visit(expr);
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

any ScriptInterpreter::visitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *ctx) {
    auto equalityExprs = ctx->equalityExpression();
    if (equalityExprs.size() == 1) {
        return ast_visitor_.visit(equalityExprs[0]);
    }
    
    // 处理多个逻辑与表达式
    shared_ptr<ScriptValue> result;
    for (auto expr : equalityExprs) {
        auto valAny = ast_visitor_.visit(expr);
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

any ScriptInterpreter::visitEqualityExpression(PyScriptParser::EqualityExpressionContext *ctx) {
    auto relationalExprs = ctx->relationalExpression();
    if (relationalExprs.size() == 1) {
        return this->visit(relationalExprs[0]);
    }
    
    // 处理相等性比较
    auto leftAny = visit(relationalExprs[0]);
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
    
    for (size_t i = 1; i < relationalExprs.size(); ++i) {
        auto rightAny = visit(relationalExprs[i]);
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

any ScriptInterpreter::visitRelationalExpression(PyScriptParser::RelationalExpressionContext *ctx) {
    auto additiveExprs = ctx->additiveExpression();
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

any ScriptInterpreter::visitAdditiveExpression(PyScriptParser::AdditiveExpressionContext *ctx) {
    auto multiplicativeExprs = ctx->multiplicativeExpression();
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

any ScriptInterpreter::visitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *ctx) {
    auto powerExprs = ctx->powerExpression();
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

any ScriptInterpreter::visitUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) {
    auto callOrPrimaryCtx = ctx->callOrPrimary();
    auto callOrPrimaryAny = this->visit(callOrPrimaryCtx);
    shared_ptr<ScriptValue> callOrPrimaryValue;
    try {
        callOrPrimaryValue = any_cast<shared_ptr<ScriptValue>>(callOrPrimaryAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate expression in unary expression", ctx);
        return any();
    }
    
    if (!callOrPrimaryValue) {
        reportError("Cannot evaluate expression in unary expression", ctx);
        return any();
    }
    
        // 检查是否有前缀操作符
        if (ctx->children.size() > 1) {
            string op = ctx->children[0]->getText();
            auto result = expression_evaluator_.evaluateUnaryOperation(op, callOrPrimaryValue);
            if (!result) {
                reportError("Unsupported unary operator: " + op, ctx);
                return any();
            }
            return any(result);
        }
    
    return any(callOrPrimaryValue);
}

any ScriptInterpreter::visitCallOrPrimary(PyScriptParser::CallOrPrimaryContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitCallOrPrimary(ctx);
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

any ScriptInterpreter::visitPrimaryExpression(PyScriptParser::PrimaryExpressionContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitPrimaryExpression(ctx);
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

any ScriptInterpreter::visitArgument(PyScriptParser::ArgumentContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitArgument(ctx);
}

any ScriptInterpreter::visitParameter(PyScriptParser::ParameterContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitParameter(ctx);
}

any ScriptInterpreter::visitPowerExpression(PyScriptParser::PowerExpressionContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitPowerExpression(ctx);
}

any ScriptInterpreter::visitExpressionList(PyScriptParser::ExpressionListContext *ctx) {
    // 表达式列表已经在列表字面量中处理
    return any();
}

any ScriptInterpreter::visitDictItemList(PyScriptParser::DictItemListContext *ctx) {
    // 字典项列表已经在字典字面量中处理
    return any();
}

any ScriptInterpreter::visitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) {
    // 键值对已经在字典字面量中处理
    return any();
}

any ScriptInterpreter::visitDictUnpack(PyScriptParser::DictUnpackContext *ctx) {
    // 字典展开已经在字典字面量中处理
    return any();
}

any ScriptInterpreter::visitForStatement(PyScriptParser::ForStatementContext *ctx) {
    logger_.debug("visitForStatement called");
    
    auto forControlCtx = ctx->forControl();
    if (!forControlCtx) {
        reportError("For statement missing control", ctx);
        return any();
    }
    
    // 执行初始化部分（如果有）
    if (forControlCtx->forInit()) {
        visit(forControlCtx->forInit());
        if (error_handler_.hasError()) {
            return any();
        }
    }
    
    // 循环条件
    auto condExpr = forControlCtx->expression();
    if (!condExpr) {
        // 如果没有条件表达式，默认为true（无限循环）
        // 在实际中应该避免无限循环，但这里简单处理
    }
    
    while (true) {
        if (condExpr) {
            auto condValue = evaluateExpression(condExpr);
            if (!condValue) {
                reportError("Cannot evaluate for loop condition", ctx);
                break;
            }
            if (!expression_evaluator_.isTruthy(condValue)) {
                break;
            }
        }
        
        // 执行循环体
        this->visit(ctx->block());
        if (error_handler_.hasError()) {
            break;
        }
        
        // 执行更新部分（如果有）
        if (forControlCtx->forUpdate()) {
            visit(forControlCtx->forUpdate());
            if (error_handler_.hasError()) {
                break;
            }
        }
    }
    
    return any();
}

any ScriptInterpreter::visitForControl(PyScriptParser::ForControlContext *ctx) {
    // for控制已经在visitForStatement中处理
    return any();
}

any ScriptInterpreter::visitForInit(PyScriptParser::ForInitContext *ctx) {
    // 执行初始化赋值
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    }
    return any();
}

any ScriptInterpreter::visitForUpdate(PyScriptParser::ForUpdateContext *ctx) {
    // 执行更新赋值
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    }
    return any();
}

any ScriptInterpreter::visitListComprehension(PyScriptParser::ListComprehensionContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitListComprehension(ctx);
}

any ScriptInterpreter::visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) {
    // 委托给AstVisitor处理
    return ast_visitor_.visitLambdaExpression(ctx);
}

// 新的visitor方法实现

any ScriptInterpreter::visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) {
    logger_.debug("visitAttributeAccessOp called");
    
    // 获取当前对象值（来自callOrPrimary中的primaryExpression）
    // 注意：attributeAccessOp的父节点是postfixOp，postfixOp的父节点是callOrPrimary
    // 我们需要获取到当前的对象值，这应该通过上下文传递，这里简化处理
    // 实际实现中，callOrPrimary应该累积应用postfixOp
    
    // 临时实现：报告错误
    reportError("Attribute access operator not fully implemented yet", ctx);
    return any();
}

any ScriptInterpreter::visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) {
    logger_.debug("visitSubscriptAccessOp called");
    
    // 临时实现：报告错误
    reportError("Subscript access operator not fully implemented yet", ctx);
    return any();
}

any ScriptInterpreter::visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) {
    logger_.debug("visitFunctionCallOp called");
    
    // 临时实现：报告错误
    reportError("Function call operator not fully implemented yet", ctx);
    return any();
}
