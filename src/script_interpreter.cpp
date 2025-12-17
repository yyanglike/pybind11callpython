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

// 构造函数
ScriptInterpreter::ScriptInterpreter() 
    : result_(nullptr), 
      has_error_(false), 
      python_initialized_(false) {
    
    std::cerr << "ScriptInterpreter constructor started" << std::endl;
    // 检查Python解释器是否已初始化
    if (!Py_IsInitialized()) {
        try {
            py::initialize_interpreter();
            python_initialized_ = true;
            std::cerr << "Python interpreter initialized" << std::endl;
        } catch (const exception& e) {
            cerr << "Failed to initialize Python interpreter: " << e.what() << endl;
        }
    } else {
        std::cerr << "Python interpreter already initialized" << std::endl;
    }
    
    // 配置Python路径
    try {
        py::module_ sys = py::module_::import("sys");
        // 将当前目录下的python目录添加到Python路径
        py::str python_path = "../python";
        sys.attr("path").attr("insert")(0, python_path);
        std::cerr << "Python path configured: " << python_path.cast<std::string>() << std::endl;
    } catch (const exception& e) {
        cerr << "Failed to configure Python path: " << e.what() << endl;
    }
    
    // 导入builtins模块以供内置函数使用
    try {
        builtins_ = py::module_::import("builtins");
        std::cerr << "Builtins imported successfully" << std::endl;
    } catch (const exception& e) {
        cerr << "Failed to import builtins: " << e.what() << endl;
        // 将builtins_设置为none，后续使用时再尝试导入
        builtins_ = py::none();
    }
    std::cerr << "ScriptInterpreter constructor finished" << std::endl;
}

// 析构函数
ScriptInterpreter::~ScriptInterpreter() {
    if (python_initialized_) {
        try {
            py::finalize_interpreter();
        } catch (...) {
            // 忽略清理错误
        }
    }
}

// 执行脚本
bool ScriptInterpreter::execute(const string& script) {
    std::cerr << "ScriptInterpreter::execute() called with script: " << script << std::endl;
    has_error_ = false;
    error_message_.clear();
    result_ = nullptr;
    
    try {
        std::cerr << "Creating ANTLRInputStream..." << std::endl;
        ANTLRInputStream input(script);
        std::cerr << "Creating PyScriptLexer..." << std::endl;
        PyScriptLexer lexer(&input);
        std::cerr << "Creating CommonTokenStream..." << std::endl;
        CommonTokenStream tokens(&lexer);
        
        // 填充token流
        std::cerr << "Filling tokens..." << std::endl;
        tokens.fill();
        
        std::cerr << "Creating PyScriptParser..." << std::endl;
        PyScriptParser parser(&tokens);
        
        // 设置错误处理器
        parser.removeErrorListeners();
        
        std::cerr << "Parsing program..." << std::endl;
        auto tree = parser.program();
        std::cerr << "Parse tree created successfully" << std::endl;
        
        if (has_error_) {
            std::cerr << "Has error before visiting" << std::endl;
            return false;
        }
        
        // 遍历AST
        std::cerr << "Visiting program tree..." << std::endl;
        visitProgram(tree);
        std::cerr << "Visit completed" << std::endl;
        
        return !has_error_;
        
    } catch (const exception& e) {
        std::cerr << "Exception in execute: " << e.what() << std::endl;
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
    auto it = variables_.find(name);
    if (it != variables_.end()) {
        return it->second;
    }
    return nullptr;
}

void ScriptInterpreter::setVariable(const string& name, shared_ptr<ScriptValue> value) {
    variables_[name] = value;
}

void ScriptInterpreter::clearEnvironment() {
    variables_.clear();
    imported_modules_.clear();
    result_ = nullptr;
    has_error_ = false;
    error_message_.clear();
}

// ========== 错误报告 ==========

void ScriptInterpreter::reportError(const string& message) {
    error_message_ = message;
    has_error_ = true;
    cerr << "Script Error: " << message << endl;
}

void ScriptInterpreter::reportError(const string& message, antlr4::ParserRuleContext *ctx) {
    string fullMessage = message;
    
    if (ctx) {
        auto token = ctx->getStart();
        if (token) {
            fullMessage += " at line " + to_string(token->getLine()) +
                          ", column " + to_string(token->getCharPositionInLine());
        }
    }
    
    reportError(fullMessage);
}

// ========== 基础Visitor方法 ==========

any ScriptInterpreter::visitProgram(PyScriptParser::ProgramContext *ctx) {
    // 执行所有语句
    for (auto stmt : ctx->statement()) {
        visit(stmt);
        if (has_error_) {
            break;
        }
    }
    
    // 如果没有return语句，最后一条语句的值作为结果
    if (result_ == nullptr && ctx->statement().size() > 0) {
        // 尝试获取最后一个表达式语句的结果
        auto lastStmt = ctx->statement().back();
        if (auto exprStmt = dynamic_cast<PyScriptParser::ExprStmtContext*>(lastStmt)) {
            result_ = evaluateExpression(exprStmt->expressionStatement()->expression());
        }
    }
    
    return any();
}

any ScriptInterpreter::visitImportStmt(PyScriptParser::ImportStmtContext *ctx) {
    return visitImportStatement(ctx->importStatement());
}

any ScriptInterpreter::visitAssignStmt(PyScriptParser::AssignStmtContext *ctx) {
    return visit(ctx->assignment());
}

any ScriptInterpreter::visitExprStmt(PyScriptParser::ExprStmtContext *ctx) {
    return visitExpressionStatement(ctx->expressionStatement());
}

any ScriptInterpreter::visitIfStmt(PyScriptParser::IfStmtContext *ctx) {
    return visitIfStatement(ctx->ifStatement());
}

any ScriptInterpreter::visitWhileStmt(PyScriptParser::WhileStmtContext *ctx) {
    return visitWhileStatement(ctx->whileStatement());
}

any ScriptInterpreter::visitReturnStmt(PyScriptParser::ReturnStmtContext *ctx) {
    return visitReturnStatement(ctx->returnStatement());
}

// ========== 语句Visitor方法 ==========

any ScriptInterpreter::visitImportStatement(PyScriptParser::ImportStatementContext *ctx) {
    try {
        auto identifiers = ctx->IDENTIFIER();
        if (identifiers.empty()) {
            reportError("Import statement must specify a module name", ctx);
            return any();
        }
        
        // 检查是否有'as'关键字
        bool hasAs = false;
        for (auto child : ctx->children) {
            if (child->getText() == "as") {
                hasAs = true;
                break;
            }
        }
        
        string moduleName;
        string alias;
        
        if (hasAs) {
            // 有'as'，则最后一个标识符是别名，前面的所有标识符组成模块名
            for (size_t i = 0; i < identifiers.size() - 1; ++i) {
                if (!moduleName.empty()) moduleName += ".";
                moduleName += identifiers[i]->getText();
            }
            alias = identifiers.back()->getText();
        } else {
            // 没有'as'，所有标识符组成模块名
            for (auto id : identifiers) {
                if (!moduleName.empty()) moduleName += ".";
                moduleName += id->getText();
            }
        }
        
        // 如果模块名为空（例如，只有一个标识符且被当作别名），则使用标识符本身作为模块名
        if (moduleName.empty()) {
            moduleName = identifiers[0]->getText();
        }
        
        // 导入Python模块
        py::module_ module = py::module_::import(moduleName.c_str());
        imported_modules_[moduleName] = module;
        
        // 存储模块引用
        if (!alias.empty()) {
            variables_[alias] = ScriptValue::createPythonObject(module);
        } else {
            // 使用模块名的最后一部分作为变量名
            size_t dotPos = moduleName.find_last_of('.');
            string shortName = (dotPos != string::npos) ? 
                              moduleName.substr(dotPos + 1) : moduleName;
            variables_[shortName] = ScriptValue::createPythonObject(module);
        }
        
    } catch (const py::error_already_set& e) {
        reportError("Failed to import module: " + string(e.what()), ctx);
    } catch (const exception& e) {
        reportError("Import error: " + string(e.what()), ctx);
    }
    
    return any();
}

any ScriptInterpreter::visitBinaryAssignment(PyScriptParser::BinaryAssignmentContext *ctx) {
    try {
        // 获取左侧标识符
        auto identifierNode = ctx->IDENTIFIER();
        if (!identifierNode) {
            reportError("Left-hand side of assignment is missing", ctx);
            return any();
        }
        string varName = identifierNode->getText();
        
        // 现在语法规则要求必须有操作符和右侧表达式：IDENTIFIER ('=' | '+=' | '-=' | '*=' | '/=' | '%=') ternaryExpression
        auto rightTernaryCtx = ctx->ternaryExpression();
        if (!rightTernaryCtx) {
            reportError("Right-hand side of assignment is missing", ctx);
            return any();
        }
        
        // 调试输出右侧文本
        std::cerr << "DEBUG assignment right text: " << rightTernaryCtx->getText() << std::endl;
        
        // 计算右侧表达式的值
        auto rightValue = visit(rightTernaryCtx);
        if (has_error_) return any();
        
        // 获取右侧的ScriptValue
        shared_ptr<ScriptValue> rightVal;
        try {
            rightVal = any_cast<shared_ptr<ScriptValue>>(rightValue);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right-hand side of assignment", ctx);
            return any();
        }
        
        if (!rightVal) {
            reportError("Right-hand side of assignment is null", ctx);
            return any();
        }
        
        // 调试输出
        std::cerr << "DEBUG assignment: varName=" << varName 
                  << ", rightVal type=" << static_cast<int>(rightVal->getType())
                  << ", rightVal=" << rightVal->toString() << std::endl;
        
        // 获取赋值操作符
        // 语法规则：IDENTIFIER ('=' | '+=' | '-=' | '*=' | '/=' | '%=') ternaryExpression
        // 操作符应该是children中的第二个元素（索引1）
        string op = "";
        if (ctx->children.size() >= 2) {
            op = ctx->children[1]->getText();
        } else {
            // 备用方法：查找操作符token
            for (auto child : ctx->children) {
                auto text = child->getText();
                if (text == "=" || text == "+=" || text == "-=" || text == "*=" || text == "/=" || text == "%=") {
                    op = text;
                    break;
                }
            }
        }
        
        if (op == "=") {
            // 简单赋值
            variables_[varName] = rightVal;
        } else if (!op.empty()) {
            // 复合赋值操作符
            auto leftVal = getVariable(varName);
            if (!leftVal) {
                reportError("Variable '" + varName + "' not defined for compound assignment", ctx);
                return any();
            }
            
            // 执行复合运算
            string baseOp = op.substr(0, op.size() - 1); // 去掉'='
            auto result = evaluateBinaryOperation(baseOp, leftVal, rightVal);
            if (!result) {
                reportError("Unsupported compound assignment operator: " + op, ctx);
                return any();
            }
            
            variables_[varName] = result;
        } else {
            reportError("Unknown assignment operator", ctx);
            return any();
        }
        
    } catch (const exception& e) {
        reportError("Assignment error: " + string(e.what()), ctx);
    }
    
    return any();
}

any ScriptInterpreter::visitAttributeAssignment(PyScriptParser::AttributeAssignmentContext *ctx) {
    // TODO: 实现属性赋值
    reportError("Attribute assignment not implemented yet", ctx);
    return any();
}

any ScriptInterpreter::visitSubscriptAssignment(PyScriptParser::SubscriptAssignmentContext *ctx) {
    // TODO: 实现下标赋值
    reportError("Subscript assignment not implemented yet", ctx);
    return any();
}

any ScriptInterpreter::visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) {
    auto value = evaluateExpression(ctx->expression());
    // 表达式语句的值可以忽略
    return any(value);
}

any ScriptInterpreter::visitIfStatement(PyScriptParser::IfStatementContext *ctx) {
    std::cerr << "visitIfStatement: 进入函数, ctx = " << ctx << std::endl;
    if (!ctx) {
        std::cerr << "visitIfStatement: ctx is null!" << std::endl;
        return any();
    }
    
    // 安全地获取条件表达式上下文
    auto exprCtx = ctx->expression();
    std::cerr << "visitIfStatement: exprCtx = " << exprCtx << std::endl;
    if (!exprCtx) {
        reportError("If statement condition is missing", ctx);
        return any();
    }
    
    // 打印exprCtx的类型信息
    std::cerr << "visitIfStatement: exprCtx type: " << typeid(*exprCtx).name() << std::endl;
    
    // 直接使用visit而不是evaluateExpression，添加异常处理
    try {
        std::cerr << "visitIfStatement: 准备调用 visit(exprCtx)..." << std::endl;
        auto condAny = visit(exprCtx);
        std::cerr << "visitIfStatement: visit(exprCtx) 调用成功" << std::endl;
        shared_ptr<ScriptValue> condValue;
        try {
            condValue = any_cast<shared_ptr<ScriptValue>>(condAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate condition: not a valid value", ctx);
            return any();
        }
        
        if (!condValue) {
            reportError("Cannot evaluate condition: null value", ctx);
            return any();
        }
        
        // 详细调试信息
        std::cerr << "visitIfStatement: condValue type = " << static_cast<int>(condValue->getType()) << std::endl;
        std::cerr << "visitIfStatement: condValue debug = " << condValue->toDebugString() << std::endl;
        
        // 检查条件值是否为Python对象，并验证其指针
        if (condValue->getType() == ScriptValue::Type::PythonObject) {
            std::cerr << "visitIfStatement: 条件值是Python对象" << std::endl;
            try {
                py::object obj = condValue->getPythonObject();
                if (!obj.ptr()) {
                    std::cerr << "visitIfStatement: Python对象指针为null，视为False" << std::endl;
                    // 视为False，执行else块（如果有）
                    if (ctx->block().size() > 1) {
                        auto elseBlock = ctx->block(1);
                        if (elseBlock) {
                            return visit(elseBlock);
                        }
                    }
                    return any();
                }
                std::cerr << "visitIfStatement: Python对象指针有效" << std::endl;
            } catch (const exception& e) {
                std::cerr << "visitIfStatement: 获取Python对象时异常: " << e.what() << std::endl;
                // 视为False，执行else块（如果有）
                if (ctx->block().size() > 1) {
                    auto elseBlock = ctx->block(1);
                    if (elseBlock) {
                        return visit(elseBlock);
                    }
                }
                return any();
            }
        }
        
        // 使用isTruthy检查条件
        std::cerr << "visitIfStatement: 调用isTruthy..." << std::endl;
        bool truthy = isTruthy(condValue);
        std::cerr << "visitIfStatement: isTruthy 结果为: " << truthy << std::endl;
        
        if (truthy) {
            auto thenBlock = ctx->block(0);
            if (!thenBlock) {
                std::cerr << "visitIfStatement: then block is null!" << std::endl;
                reportError("Then block is null", ctx);
                return any();
            }
            return visit(thenBlock);
        } else if (ctx->block().size() > 1) {
            auto elseBlock = ctx->block(1);
            if (!elseBlock) {
                std::cerr << "visitIfStatement: else block is null!" << std::endl;
                reportError("Else block is null", ctx);
                return any();
            }
            return visit(elseBlock);
        }
        
    } catch (const exception& e) {
        std::cerr << "visitIfStatement: 捕获到异常: " << e.what() << std::endl;
        reportError("Exception in if statement condition: " + string(e.what()), ctx);
        return any();
    } catch (...) {
        std::cerr << "visitIfStatement: 捕获到未知异常" << std::endl;
        reportError("Unknown exception in if statement condition", ctx);
        return any();
    }
    
    std::cerr << "visitIfStatement: 正常结束" << std::endl;
    return any();
}

any ScriptInterpreter::visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) {
    while (true) {
        auto condValue = evaluateExpression(ctx->expression());
        
        if (!condValue) {
            reportError("Cannot evaluate condition", ctx);
            break;
        }
        
        if (!isTruthy(condValue)) {
            break;
        }
        
        visit(ctx->block());
        
        if (has_error_) {
            break;
        }
    }
    
    return any();
}

any ScriptInterpreter::visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) {
    if (ctx->expression()) {
        result_ = evaluateExpression(ctx->expression());
    } else {
        result_ = ScriptValue::createNull();
    }
    return any();
}

any ScriptInterpreter::visitBlock(PyScriptParser::BlockContext *ctx) {
    if (ctx->statement().empty()) {
        // 空代码块
        return any();
    }
    
    // 执行代码块中的所有语句
    for (auto stmt : ctx->statement()) {
        visit(stmt);
        if (has_error_) {
            break;
        }
    }
    
    return any();
}

any ScriptInterpreter::visitExpression(PyScriptParser::ExpressionContext *ctx) {
    if (!ctx) {
        std::cerr << "visitExpression: ctx is null!" << std::endl;
        return any();
    }
    
    std::cerr << "visitExpression: 检查表达式类型..." << std::endl;
    
    // 检查是否是赋值表达式
    auto assignmentCtx = ctx->assignment();
    if (assignmentCtx) {
        std::cerr << "visitExpression: 是赋值表达式" << std::endl;
        return visit(assignmentCtx);
    }
    
    // 检查是否是三元表达式
    auto ternaryCtx = ctx->ternaryExpression();
    if (ternaryCtx) {
        std::cerr << "visitExpression: 是三元表达式" << std::endl;
        return visit(ternaryCtx);
    }
    
    std::cerr << "visitExpression: 既不是赋值也不是三元表达式" << std::endl;
    reportError("Invalid expression: neither assignment nor ternary expression", ctx);
    return any();
}

// ========== 表达式Visitor方法 ==========

any ScriptInterpreter::visitTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) {
    if (ctx->children.size() == 1) {
        // 没有三元操作符，直接返回逻辑或表达式
        return visit(ctx->logicalOrExpression());
    }
    
    // 有三元操作符：condition ? trueExpr : falseExpr
    auto condValue = evaluateExpression(ctx->expression());
    if (!condValue) {
        reportError("Cannot evaluate condition in ternary expression", ctx);
        return any();
    }
    
    if (isTruthy(condValue)) {
        return visit(ctx->ternaryExpression());
    } else {
        return evaluateExpression(ctx->expression());
    }
}

any ScriptInterpreter::visitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *ctx) {
    auto logicalAndExprs = ctx->logicalAndExpression();
    if (logicalAndExprs.size() == 1) {
        return visit(logicalAndExprs[0]);
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
        
        if (isTruthy(val)) {
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
    if (!ctx) {
        std::cerr << "visitLogicalAndExpression: ctx is null!" << std::endl;
        return any();
    }
    
    std::cerr << "visitLogicalAndExpression: number of equalityExprs: " << ctx->equalityExpression().size() << std::endl;
    
    auto equalityExprs = ctx->equalityExpression();
    if (equalityExprs.empty()) {
        std::cerr << "visitLogicalAndExpression: no equality expressions!" << std::endl;
        reportError("Logical AND expression has no subexpressions", ctx);
        return any();
    }
    
    if (equalityExprs.size() == 1) {
        std::cerr << "visitLogicalAndExpression: single expression case" << std::endl;
        auto expr = equalityExprs[0];
        if (!expr) {
            std::cerr << "visitLogicalAndExpression: single expression is null!" << std::endl;
            reportError("Expression is null in logical AND", ctx);
            return any();
        }
        return visit(expr);
    }
    
    // 处理多个逻辑与表达式
    shared_ptr<ScriptValue> result;
    for (size_t i = 0; i < equalityExprs.size(); ++i) {
        auto expr = equalityExprs[i];
        if (!expr) {
            std::cerr << "visitLogicalAndExpression: equalityExpr[" << i << "] is null!" << std::endl;
            reportError("Expression is null in logical AND", ctx);
            return any();
        }
        
        std::cerr << "visitLogicalAndExpression: evaluating equalityExpr " << i << std::endl;
        auto valAny = visit(expr);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            std::cerr << "visitLogicalAndExpression: cannot cast value for equalityExpr " << i << std::endl;
            reportError("Cannot evaluate logical AND expression", ctx);
            return any();
        }
        if (!val) {
            std::cerr << "visitLogicalAndExpression: value for equalityExpr " << i << " is null!" << std::endl;
            reportError("Cannot evaluate logical AND expression", ctx);
            return any();
        }
        
        std::cerr << "visitLogicalAndExpression: value " << i << " isTruthy: " << isTruthy(val) << std::endl;
        
        if (!isTruthy(val)) {
            result = val;
            break;
        }
        
        if (!result) {
            result = val;
        }
    }
    
    std::cerr << "visitLogicalAndExpression: returning result" << std::endl;
    return any(result);
}

any ScriptInterpreter::visitEqualityExpression(PyScriptParser::EqualityExpressionContext *ctx) {
    auto relationalExprs = ctx->relationalExpression();
    if (relationalExprs.size() == 1) {
        return visit(relationalExprs[0]);
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
        auto result = evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported equality operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any ScriptInterpreter::visitRelationalExpression(PyScriptParser::RelationalExpressionContext *ctx) {
    if (!ctx) {
        std::cerr << "visitRelationalExpression: ctx is null!" << std::endl;
        return any();
    }
    
    auto additiveExprs = ctx->additiveExpression();
    if (additiveExprs.empty()) {
        std::cerr << "visitRelationalExpression: no additive expressions!" << std::endl;
        reportError("Relational expression has no subexpressions", ctx);
        return any();
    }
    
    if (additiveExprs.size() == 1) {
        auto expr = additiveExprs[0];
        if (!expr) {
            std::cerr << "visitRelationalExpression: single additive expression is null!" << std::endl;
            reportError("Additive expression is null", ctx);
            return any();
        }
        return visit(expr);
    }
    
    // 处理关系比较
    auto leftExpr = additiveExprs[0];
    if (!leftExpr) {
        std::cerr << "visitRelationalExpression: left additive expression is null!" << std::endl;
        reportError("Left additive expression is null", ctx);
        return any();
    }
    auto leftAny = visit(leftExpr);
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
        auto rightExpr = additiveExprs[i];
        if (!rightExpr) {
            std::cerr << "visitRelationalExpression: additiveExprs[" << i << "] is null!" << std::endl;
            reportError("Right additive expression is null", ctx);
            return any();
        }
        auto rightAny = visit(rightExpr);
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
        auto result = evaluateBinaryOperation(op, left, right);
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
        return visit(multiplicativeExprs[0]);
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
        auto result = evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported additive operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any ScriptInterpreter::visitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *ctx) {
    auto unaryExprs = ctx->unaryExpression();
    if (unaryExprs.size() == 1) {
        return visit(unaryExprs[0]);
    }
    
    // 处理乘除取模运算
    auto leftAny = visit(unaryExprs[0]);
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
    
    for (size_t i = 1; i < unaryExprs.size(); ++i) {
        auto rightAny = visit(unaryExprs[i]);
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
        auto result = evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported multiplicative operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any ScriptInterpreter::visitUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) {
    auto postfixCtx = ctx->postfixExpression();
    auto postfixAny = visit(postfixCtx);
    shared_ptr<ScriptValue> postfixValue;
    try {
        postfixValue = any_cast<shared_ptr<ScriptValue>>(postfixAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate postfix expression in unary expression", ctx);
        return any();
    }
    
    if (!postfixValue) {
        reportError("Cannot evaluate postfix expression in unary expression", ctx);
        return any();
    }
    
    // 检查是否有前缀操作符
    if (ctx->children.size() > 1) {
        string op = ctx->children[0]->getText();
        auto result = evaluateUnaryOperation(op, postfixValue);
        if (!result) {
            reportError("Unsupported unary operator: " + op, ctx);
            return any();
        }
        return any(result);
    }
    
    return any(postfixValue);
}

// ========== 后缀表达式Visitor方法 ==========

any ScriptInterpreter::visitPostfixExpression(PyScriptParser::PostfixExpressionContext *ctx) {
    std::cerr << "DEBUG_POSTFIX: visitPostfixExpression called" << std::endl;
    
    // 首先处理基本表达式
    auto primaryCtx = ctx->primaryExpression();
    auto primaryAny = visit(primaryCtx);
    shared_ptr<ScriptValue> currentValue;
    try {
        currentValue = any_cast<shared_ptr<ScriptValue>>(primaryAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate primary expression in postfix expression", ctx);
        return any();
    }
    
    if (!currentValue) {
        reportError("Cannot evaluate primary expression in postfix expression", ctx);
        return any();
    }
    
    std::cerr << "DEBUG_POSTFIX: initial value type=" << static_cast<int>(currentValue->getType())
              << ", value=" << currentValue->toString() << std::endl;
    
    // 处理所有后缀操作符
    for (auto opCtx : ctx->postfixOperator()) {
        std::cerr << "DEBUG_POSTFIX: processing postfix operator" << std::endl;
        
        if (auto funcCallCtx = dynamic_cast<PyScriptParser::FunctionCallPostfixContext*>(opCtx)) {
            // 函数调用
            std::cerr << "DEBUG_POSTFIX: function call postfix" << std::endl;
            auto funcValue = currentValue;
            
            // 收集参数
            vector<shared_ptr<ScriptValue>> args;
            if (funcCallCtx->argumentList()) {
                auto argList = funcCallCtx->argumentList()->expression();
                std::cerr << "DEBUG_POSTFIX: argument count=" << argList.size() << std::endl;
                for (size_t i = 0; i < argList.size(); ++i) {
                    auto arg = argList[i];
                    auto argValue = evaluateExpression(arg);
                    if (argValue) {
                        args.push_back(argValue);
                        std::cerr << "DEBUG_POSTFIX: arg[" << i << "] type=" << static_cast<int>(argValue->getType())
                                  << ", value=" << argValue->toString() << std::endl;
                    } else {
                        reportError("Cannot evaluate argument", funcCallCtx);
                        return any();
                    }
                }
            }
            
            try {
                if (funcValue->isPythonObject()) {
                    py::object pyFunc = funcValue->getPythonObject();
                    std::cerr << "DEBUG_POSTFIX: pyFunc type=" << py::str(pyFunc.get_type()).cast<std::string>() << std::endl;
                    
                    // 直接调用Python函数
                    py::tuple pyArgs(args.size());
                    for (size_t i = 0; i < args.size(); ++i) {
                        pyArgs[i] = args[i]->toPythonObject();
                        std::cerr << "DEBUG_POSTFIX: pyArgs[" << i << "]=" << py::str(pyArgs[i]).cast<std::string>() << std::endl;
                    }
                    
                    py::object result = pyFunc(*pyArgs);
                    std::cerr << "DEBUG_POSTFIX: result type=" << py::str(result.get_type()).cast<std::string>() 
                              << ", result=" << py::str(result).cast<std::string>() << std::endl;
                    currentValue = ScriptValue::fromPythonObject(result);
                } else {
                    reportError("Cannot call non-function type", funcCallCtx);
                    return any();
                }
            } catch (const py::error_already_set& e) {
                std::cerr << "DEBUG_POSTFIX: Python error=" << e.what() << std::endl;
                reportError("Python function call error: " + string(e.what()), funcCallCtx);
                return any();
            } catch (const exception& e) {
                std::cerr << "DEBUG_POSTFIX: Exception=" << e.what() << std::endl;
                reportError("Function call error: " + string(e.what()), funcCallCtx);
                return any();
            }
        } else if (auto memberAccessCtx = dynamic_cast<PyScriptParser::MemberAccessPostfixContext*>(opCtx)) {
            // 成员访问
            std::cerr << "DEBUG_POSTFIX: member access postfix" << std::endl;
            string memberName = memberAccessCtx->IDENTIFIER()->getText();
            
            if (!currentValue) {
                reportError("Cannot access member of null object", memberAccessCtx);
                return any();
            }
            
            auto member = getMember(currentValue, memberName);
            if (!member) {
                reportError("Object has no member: " + memberName, memberAccessCtx);
                return any();
            }
            
            currentValue = member;
        } else if (auto subscriptCtx = dynamic_cast<PyScriptParser::SubscriptPostfixContext*>(opCtx)) {
            // 下标访问
            std::cerr << "DEBUG_POSTFIX: subscript postfix" << std::endl;
            auto indexValue = evaluateExpression(subscriptCtx->expression());
            
            if (!currentValue || !indexValue) {
                reportError("Cannot evaluate subscript expression", subscriptCtx);
                return any();
            }
            
            if (currentValue->isPythonObject()) {
                py::object pyObj = currentValue->getPythonObject();
                
                try {
                    py::object pyIndex = indexValue->toPythonObject();
                    py::object result = pyObj[pyIndex];
                    currentValue = ScriptValue::fromPythonObject(result);
                } catch (const py::error_already_set& e) {
                    reportError("Python subscript error: " + string(e.what()), subscriptCtx);
                    return any();
                }
            } else if (currentValue->isList()) {
                auto& list = currentValue->getList();
                
                // 索引必须是整数
                if (!indexValue->isInteger()) {
                    reportError("List index must be an integer", subscriptCtx);
                    return any();
                }
                
                long long index = indexValue->getInteger();
                
                if (index < 0 || index >= static_cast<long long>(list.size())) {
                    reportError("List index out of bounds: " + to_string(index) + 
                               " (list size: " + to_string(list.size()) + ")", subscriptCtx);
                    return any();
                }
                
                currentValue = list[index];
            } else if (currentValue->isDictionary()) {
                auto& dict = currentValue->getDictionary();
                
                // 索引必须是字符串
                if (!indexValue->isString()) {
                    reportError("Dictionary key must be a string", subscriptCtx);
                    return any();
                }
                
                string key = indexValue->getString();
                
                auto it = dict.find(key);
                if (it == dict.end()) {
                    reportError("Dictionary key not found: " + key, subscriptCtx);
                    return any();
                }
                
                currentValue = it->second;
            } else {
                reportError("Subscript not supported for this type", subscriptCtx);
                return any();
            }
        } else {
            reportError("Unknown postfix operator", opCtx);
            return any();
        }
        
        if (!currentValue) {
            reportError("Postfix operator evaluation returned null", opCtx);
            return any();
        }
        
        std::cerr << "DEBUG_POSTFIX: after operator, value type=" << static_cast<int>(currentValue->getType())
                  << ", value=" << currentValue->toString() << std::endl;
    }
    
    std::cerr << "DEBUG_POSTFIX: returning value" << std::endl;
    return any(currentValue);
}

any ScriptInterpreter::visitFunctionCallPostfix(PyScriptParser::FunctionCallPostfixContext *ctx) {
    // 这个函数不会被直接调用，因为我们在visitPostfixExpression中处理了所有postfixOperator
    // 但为了满足接口要求，我们仍然实现它
    std::cerr << "DEBUG_POSTFIX: visitFunctionCallPostfix called (should not happen)" << std::endl;
    return any();
}

any ScriptInterpreter::visitMemberAccessPostfix(PyScriptParser::MemberAccessPostfixContext *ctx) {
    // 这个函数不会被直接调用，因为我们在visitPostfixExpression中处理了所有postfixOperator
    // 但为了满足接口要求，我们仍然实现它
    std::cerr << "DEBUG_POSTFIX: visitMemberAccessPostfix called (should not happen)" << std::endl;
    return any();
}

any ScriptInterpreter::visitSubscriptPostfix(PyScriptParser::SubscriptPostfixContext *ctx) {
    // 这个函数不会被直接调用，因为我们在visitPostfixExpression中处理了所有postfixOperator
    // 但为了满足接口要求，我们仍然实现它
    std::cerr << "DEBUG_POSTFIX: visitSubscriptPostfix called (should not happen)" << std::endl;
    return any();
}

// ========== 基础表达式Visitor方法 ==========

any ScriptInterpreter::visitIdentifierPrimary(PyScriptParser::IdentifierPrimaryContext *ctx) {
    string name = ctx->IDENTIFIER()->getText();
    std::cerr << "DEBUG_IDENTIFIER: visitIdentifierPrimary called with name: " << name << std::endl;
    std::cerr << "DEBUG_IDENTIFIER: variables_ size = " << variables_.size() << std::endl;
    
    // 首先检查变量
    auto varIt = variables_.find(name);
    if (varIt != variables_.end()) {
        std::cerr << "DEBUG_IDENTIFIER: found in variables, value type=" << static_cast<int>(varIt->second->getType()) << ", value=" << varIt->second->toString() << std::endl;
        return any(varIt->second);
    } else {
        std::cerr << "DEBUG_IDENTIFIER: not found in variables" << std::endl;
    }
    
    // 检查导入的模块
    auto modIt = imported_modules_.find(name);
    if (modIt != imported_modules_.end()) {
        std::cerr << "DEBUG_IDENTIFIER: found in imported_modules" << std::endl;
        return any(ScriptValue::createPythonObject(modIt->second));
    }
    
    // 检查内置Python对象（如True, False, None）
    if (name == "True" || name == "true") {
        std::cerr << "DEBUG_IDENTIFIER: returning True" << std::endl;
        return any(ScriptValue::createBoolean(true));
    } else if (name == "False" || name == "false") {
        std::cerr << "DEBUG_IDENTIFIER: returning False" << std::endl;
        return any(ScriptValue::createBoolean(false));
    } else if (name == "None" || name == "none") {
        std::cerr << "DEBUG_IDENTIFIER: returning None" << std::endl;
        return any(ScriptValue::createNull());
    }
    
    // 检查是否为内置函数（如len, str, int等）
    static const unordered_set<string> builtin_funcs = {
        "len", "str", "int", "float", "bool", "list", "dict", "tuple", "set",
        "abs", "max", "min", "sum", "range", "enumerate", "zip", "sorted"
    };
    if (builtin_funcs.find(name) != builtin_funcs.end()) {
        std::cerr << "DEBUG_IDENTIFIER: name is in builtin_funcs, trying to get from Python" << std::endl;
        try {
            if (builtins_.is_none()) {
                builtins_ = py::module_::import("builtins");
            }
            py::object builtin_func = builtins_.attr(name.c_str());
            std::cerr << "DEBUG_IDENTIFIER: got builtin function: " << name << std::endl;
            return any(ScriptValue::createPythonObject(builtin_func));
        } catch (const exception& e) {
            cerr << "Warning: Failed to get builtin function " << name << ": " << e.what() << endl;
            // 继续向下，报告错误
        }
    } else {
        std::cerr << "DEBUG_IDENTIFIER: name is not in builtin_funcs" << std::endl;
    }
    
    reportError("Undefined identifier: " + name, ctx);
    return any();
}

any ScriptInterpreter::visitParenPrimary(PyScriptParser::ParenPrimaryContext *ctx) {
    return any(evaluateExpression(ctx->expression()));
}

any ScriptInterpreter::visitNewInstancePrimary(PyScriptParser::NewInstancePrimaryContext *ctx) {
    std::cerr << "visitNewInstancePrimary开始" << std::endl;
    
    if (!ctx) {
        std::cerr << "visitNewInstancePrimary: ctx is null!" << std::endl;
        return any();
    }
    
    auto identifiers = ctx->IDENTIFIER();
    
    if (identifiers.empty()) {
        reportError("New expression must specify a class name", ctx);
        return any();
    }
    
    std::cerr << "visitNewInstancePrimary: 标识符数量: " << identifiers.size() << std::endl;
    
    // 收集参数
    vector<shared_ptr<ScriptValue>> args;
    if (ctx->argumentList()) {
        auto argList = ctx->argumentList()->expression();
        std::cerr << "visitNewInstancePrimary: 参数数量: " << argList.size() << std::endl;
        
        for (size_t i = 0; i < argList.size(); ++i) {
            auto argCtx = argList[i];
            if (!argCtx) continue;
            
            auto argValue = evaluateExpression(argCtx);
            if (argValue) {
                args.push_back(argValue);
            } else {
                args.push_back(ScriptValue::createNull());
            }
        }
    }
    
    // 处理标识符列表
    vector<string> idNames;
    for (auto id : identifiers) {
        if (id) {
            idNames.push_back(id->getText());
        }
    }
    
    if (idNames.empty()) {
        reportError("No valid identifiers found in new expression", ctx);
        return any();
    }
    
    // 如果有多个标识符，最后一个为类名，前面的为模块路径
    if (idNames.size() == 1) {
        string className = idNames[0];
        
        // 先检查变量环境中是否有这个类对象
        auto varIt = variables_.find(className);
        if (varIt != variables_.end() && varIt->second->isPythonObject()) {
            py::object classObj = varIt->second->getPythonObject();
            if (!classObj.is_none()) {
                try {
                    py::tuple pyArgs(args.size());
                    for (size_t i = 0; i < args.size(); ++i) {
                        pyArgs[i] = args[i]->toPythonObject();
                    }
                    py::object instance = classObj(*pyArgs);
                    return any(ScriptValue::fromPythonObject(instance));
                } catch (const py::error_already_set& e) {
                    reportError("Failed to create instance from variable: " + string(e.what()), ctx);
                    return any();
                }
            }
        }
        
        // 如果没有在变量中找到，尝试从已导入的模块中查找
        for (const auto& [modName, modObj] : imported_modules_) {
            try {
                py::object testClass = modObj.attr(className.c_str());
                if (!testClass.is_none()) {
                    auto instance = createPythonInstance(modName, className, args);
                    return any(instance);
                }
            } catch (...) {
                // 继续查找
            }
        }
        
        reportError("Cannot find class " + className + " in imported modules", ctx);
        return any();
    } else {
        // 多个标识符的情况
        string className = idNames.back();
        vector<string> modulePath(idNames.begin(), idNames.end() - 1);
        
        string modulePathStr;
        for (size_t i = 0; i < modulePath.size(); ++i) {
            if (i > 0) modulePathStr += ".";
            modulePathStr += modulePath[i];
        }
        
        try {
            py::module_ module;
            auto modIt = imported_modules_.find(modulePathStr);
            if (modIt != imported_modules_.end()) {
                module = modIt->second;
            } else {
                module = py::module_::import(modulePathStr.c_str());
                imported_modules_[modulePathStr] = module;
            }
            
            auto instance = createPythonInstance(modulePathStr, className, args);
            return any(instance);
            
        } catch (const py::error_already_set& e) {
            reportError("Failed to create instance " + modulePathStr + "." + className + 
                       ": " + string(e.what()), ctx);
            return any();
        }
    }
}

any ScriptInterpreter::visitLiteralPrimary(PyScriptParser::LiteralPrimaryContext *ctx) {
    return visit(ctx->literal());
}

// ========== 字面量Visitor方法 ==========

any ScriptInterpreter::visitIntegerLiteral(PyScriptParser::IntegerLiteralContext *ctx) {
    long long value = stoll(ctx->INTEGER()->getText());
    return any(ScriptValue::createInteger(value));
}

any ScriptInterpreter::visitFloatLiteral(PyScriptParser::FloatLiteralContext *ctx) {
    double value = stod(ctx->FLOAT()->getText());
    return any(ScriptValue::createDouble(value));
}

any ScriptInterpreter::visitStringLiteral(PyScriptParser::StringLiteralContext *ctx) {
    string text = ctx->STRING()->getText();
    // 去掉引号
    if (text.length() >= 2) {
        text = text.substr(1, text.length() - 2);
    }
    return any(ScriptValue::createString(text));
}

any ScriptInterpreter::visitBooleanLiteral(PyScriptParser::BooleanLiteralContext *ctx) {
    bool value = (ctx->BOOL()->getText() == "true");
    return any(ScriptValue::createBoolean(value));
}

any ScriptInterpreter::visitNullLiteral(PyScriptParser::NullLiteralContext *ctx) {
    return any(ScriptValue::createNull());
}

any ScriptInterpreter::visitListLiteral(PyScriptParser::ListLiteralContext *ctx) {
    auto listVal = ScriptValue::createList();
    
    if (ctx->expressionList()) {
        auto exprList = ctx->expressionList()->expression();
        for (auto expr : exprList) {
            auto value = evaluateExpression(expr);
            if (value) {
                listVal->append(value);
            } else {
                reportError("Cannot evaluate list element", ctx);
                return any();
            }
        }
    }
    
    return any(listVal);
}

any ScriptInterpreter::visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) {
    auto dictVal = ScriptValue::createDictionary();
    
    if (ctx->keyValuePairList()) {
        auto kvList = ctx->keyValuePairList()->keyValuePair();
        for (auto kv : kvList) {
            auto keyValue = evaluateExpression(kv->expression(0));
            auto valValue = evaluateExpression(kv->expression(1));
            
            if (!keyValue || !valValue) {
                reportError("Cannot evaluate dictionary key-value pair", ctx);
                return any();
            }
            
            string keyStr = keyValue->toString();
            dictVal->setKey(keyStr, valValue);
        }
    }
    
    return any(dictVal);
}

any ScriptInterpreter::visitExpressionList(PyScriptParser::ExpressionListContext *ctx) {
    // 表达式列表已经在其他上下文中处理
    return any();
}

any ScriptInterpreter::visitKeyValuePairList(PyScriptParser::KeyValuePairListContext *ctx) {
    // 键值对列表已经在字典字面量中处理
    return any();
}

any ScriptInterpreter::visitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) {
    // 键值对已经在字典字面量中处理
    return any();
}

any ScriptInterpreter::visitArgumentList(PyScriptParser::ArgumentListContext *ctx) {
    // 参数列表已经在函数调用中处理
    return any();
}

// ========== 辅助方法 ==========

shared_ptr<ScriptValue> ScriptInterpreter::evaluateExpression(PyScriptParser::ExpressionContext *ctx) {
    if (!ctx) {
        std::cerr << "evaluateExpression: ctx is null!" << std::endl;
        return nullptr;
    }
    auto result = visit(ctx);
    try {
        return any_cast<shared_ptr<ScriptValue>>(result);
    } catch (const bad_any_cast&) {
        return nullptr;
    }
}

shared_ptr<ScriptValue> ScriptInterpreter::evaluateBinaryOperation(
    const string& op,
    shared_ptr<ScriptValue> left,
    shared_ptr<ScriptValue> right) {
    
    try {
        if (op == "+") {
            // 数字相加或字符串连接
            if (left->isInteger() && right->isInteger()) {
                return ScriptValue::createInteger(left->getInteger() + right->getInteger());
            } else if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createDouble(left->toDouble() + right->toDouble());
            } else if (left->isString() || right->isString()) {
                return ScriptValue::createString(left->toString() + right->toString());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::object result = left->toPythonObject() + right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "-") {
            if (left->isNumber() && right->isNumber()) {
                if (left->isInteger() && right->isInteger()) {
                    return ScriptValue::createInteger(left->getInteger() - right->getInteger());
                } else {
                    return ScriptValue::createDouble(left->toDouble() - right->toDouble());
                }
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::object result = left->toPythonObject() - right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "*") {
            if (left->isNumber() && right->isNumber()) {
                if (left->isInteger() && right->isInteger()) {
                    return ScriptValue::createInteger(left->getInteger() * right->getInteger());
                } else {
                    return ScriptValue::createDouble(left->toDouble() * right->toDouble());
                }
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::object result = left->toPythonObject() * right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "/") {
            if (left->isNumber() && right->isNumber()) {
                double divisor = right->toDouble();
                if (abs(divisor) < 1e-10) {
                    throw runtime_error("Division by zero");
                }
                return ScriptValue::createDouble(left->toDouble() / divisor);
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::object result = left->toPythonObject() / right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "%") {
            if (left->isInteger() && right->isInteger()) {
                long long divisor = right->getInteger();
                if (divisor == 0) {
                    throw runtime_error("Modulo by zero");
                }
                return ScriptValue::createInteger(left->getInteger() % divisor);
            } else {
                throw runtime_error("Modulo operation requires integer operands");
            }
        } else if (op == "==") {
            bool equal = (*left == *right);
            return ScriptValue::createBoolean(equal);
        } else if (op == "!=") {
            bool notEqual = !(*left == *right);
            return ScriptValue::createBoolean(notEqual);
        } else if (op == "<") {
            if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createBoolean(left->toDouble() < right->toDouble());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_LT));
                if (!result.ptr() || result.is_none()) {
                    throw py::error_already_set();
                }
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == ">") {
            if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createBoolean(left->toDouble() > right->toDouble());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::object lhs = left->toPythonObject();
            return ScriptValue::createBoolean(left->toBoolean() || right->toBoolean());
        }
        
        throw runtime_error("Unsupported binary operator: " + op);
        
    } catch (const exception& e) {
        throw runtime_error("Binary operation error: " + string(e.what()));
    }
}

shared_ptr<ScriptValue> ScriptInterpreter::evaluateUnaryOperation(
    const string& op,
    shared_ptr<ScriptValue> value) {
    
    try {
        if (op == "-") {
            if (value->isInteger()) {
                return ScriptValue::createInteger(-value->getInteger());
            } else if (value->isDouble()) {
                return ScriptValue::createDouble(-value->getDouble());
            } else if (value->isPythonObject()) {
                py::object result = -value->getPythonObject();
                return ScriptValue::fromPythonObject(result);
            } else {
                throw runtime_error("Unary - operator not supported for this type");
            }
        } else if (op == "!") {
            return ScriptValue::createBoolean(!value->toBoolean());
        }
        
        throw runtime_error("Unsupported unary operator: " + op);
        
    } catch (const exception& e) {
        throw runtime_error("Unary operation error: " + string(e.what()));
    }
}

bool ScriptInterpreter::isTruthy(shared_ptr<ScriptValue> value) const {
    if (!value) return false;
    return value->toBoolean();
}

shared_ptr<ScriptValue> ScriptInterpreter::callPythonFunction(
    py::object func,
    const vector<shared_ptr<ScriptValue>>& args) {
    
    try {
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
        }
        
        py::object result = func(*pyArgs);
        return ScriptValue::fromPythonObject(result);
        
    } catch (const py::error_already_set& e) {
        throw runtime_error("Python function call error: " + string(e.what()));
    }
}

shared_ptr<ScriptValue> ScriptInterpreter::createPythonInstance(
    const string& moduleName,
    const string& className,
    const vector<shared_ptr<ScriptValue>>& args) {
    
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
        }
        
        py::object instance = classObj(*pyArgs);
        return ScriptValue::fromPythonObject(instance);
        
    } catch (const py::error_already_set& e) {
        throw runtime_error("Python instance creation error: " + string(e.what()));
    }
}

shared_ptr<ScriptValue> ScriptInterpreter::getMember(
    shared_ptr<ScriptValue> object,
    const string& memberName) {
    
    if (!object) {
        return nullptr;
    }
    
    if (object->isPythonObject()) {
        py::object pyObj = object->getPythonObject();
        
        try {
            if (py::isinstance<py::module_>(pyObj)) {
                py::module_ module = pyObj.cast<py::module_>();
                py::object member = module.attr(memberName.c_str());
                return ScriptValue::fromPythonObject(member);
            } else if (py::hasattr(pyObj, memberName.c_str())) {
                py::object member = pyObj.attr(memberName.c_str());
                return ScriptValue::fromPythonObject(member);
            }
        } catch (const py::error_already_set&) {
            // 属性不存在
        }
    }
    
    return nullptr;
}

void ScriptInterpreter::setMember(
    shared_ptr<ScriptValue> object,
    const string& memberName,
    shared_ptr<ScriptValue> value) {
    
    if (!object || !object->isPythonObject()) {
        throw runtime_error("Cannot set member on non-object type");
    }
    
    py::object pyObj = object->getPythonObject();
    py::object pyValue = value->toPythonObject();
    
    try {
        pyObj.attr(memberName.c_str()) = pyValue;
    } catch (const py::error_already_set& e) {
        throw runtime_error("Python attribute assignment error: " + string(e.what()));
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
        auto result = visit(stmt);
        if (has_error_) {
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
