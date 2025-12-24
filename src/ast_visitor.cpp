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
      defining_function_(false) {
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

// 求值表达式
shared_ptr<ScriptValue> AstVisitor::evaluateExpression(PyScriptParser::ExpressionContext *ctx) {
    if (!ctx) {
        logger_.error("evaluateExpression: ctx is null!");
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

// 执行代码块
shared_ptr<ScriptValue> AstVisitor::executeBlock(PyScriptParser::BlockContext *ctx) {
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

any AstVisitor::visitProgram(PyScriptParser::ProgramContext *ctx) {
    // 执行所有语句
    for (auto stmt : ctx->statement()) {
        this->visit(stmt);
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

any AstVisitor::visitStatement(PyScriptParser::StatementContext *ctx) {
    // 根据实际的子节点类型进行分发
    if (ctx->importStatement()) {
        return this->visit(ctx->importStatement());
    } else if (ctx->functionDefinition()) {
        return this->visit(ctx->functionDefinition());
    } else if (ctx->assignment()) {
        return this->visit(ctx->assignment());
    } else if (ctx->ifStatement()) {
        return this->visit(ctx->ifStatement());
    } else if (ctx->whileStatement()) {
        return this->visit(ctx->whileStatement());
    } else if (ctx->forStatement()) {
        return this->visit(ctx->forStatement());
    } else if (ctx->returnStatement()) {
        return this->visit(ctx->returnStatement());
    } else if (ctx->expressionStatement()) {
        return this->visit(ctx->expressionStatement());
    }
    
    reportError("Unknown statement type", ctx);
    return any();
}

any AstVisitor::visitImportStatement(PyScriptParser::ImportStatementContext *ctx) {
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

// 其他visitor方法将逐步从script_interpreter.cpp迁移过来
// 由于时间有限，我们先迁移以上几个方法作为示例

any AstVisitor::visitFunctionDefinition(PyScriptParser::FunctionDefinitionContext *ctx) {
    logger_.debug("visitFunctionDefinition called");
    
    string funcName = ctx->IDENTIFIER()->getText();
    logger_.debug(std::string("Function name: ") + funcName);
    
    // 获取参数列表（支持默认值、*args 和 **kwargs）
    vector<string> paramNames;
    if (ctx->parameterList()) {
        for (auto* p : ctx->parameterList()->parameter()) {
            if (p->IDENTIFIER() && !p->MUL() && !p->DOUBLE_STAR()) {
                std::string name = p->IDENTIFIER()->getText();
                if (p->ASSIGN() && p->expression()) {
                    // 使用原始文本作为默认值表示
                    std::string defText = p->expression()->getText();
                    paramNames.push_back(name + "=" + defText);
                } else {
                    paramNames.push_back(name);
                }
            } else if (p->MUL() && p->IDENTIFIER()) {
                paramNames.push_back("*" + p->IDENTIFIER()->getText());
            } else if (p->DOUBLE_STAR() && p->IDENTIFIER()) {
                paramNames.push_back("**" + p->IDENTIFIER()->getText());
            }
        }
    }
    
    // 获取函数体
    auto blockCtx = ctx->block();
    if (!blockCtx) {
        reportError("Function definition missing body", ctx);
        return any();
    }
    
    // 获取函数体中的所有语句
    auto statements = blockCtx->statement();
    logger_.debug(std::string("Number of statements in function body: ") + std::to_string(statements.size()));
    
    // 打印语句类型信息
    for (size_t i = 0; i < statements.size(); ++i) {
        auto stmt = statements[i];
        logger_.debug(std::string("Statement ") + std::to_string(i) + " type: " + typeid(*stmt).name());
        logger_.debug(std::string("Statement ") + std::to_string(i) + " text: " + stmt->getText());
        
        // 检查是否是return语句
        auto returnStmt = dynamic_cast<PyScriptParser::ReturnStatementContext*>(stmt);
        if (returnStmt) {
            logger_.debug(std::string("Statement ") + std::to_string(i) + " is a return statement");
            if (returnStmt->expression()) {
                logger_.debug(std::string("Return expression: ") + returnStmt->expression()->getText());
            }
        }
    }
    
    // 设置标志防止在函数定义体中报错
    defining_function_ = true;
    
    // 构建函数定义字符串
    string funcDef = "def " + funcName + "(";
    for (size_t i = 0; i < paramNames.size(); ++i) {
        if (i > 0) funcDef += ", ";
        funcDef += paramNames[i];
    }
    funcDef += "):\n";
    
    if (statements.empty()) {
        funcDef += "    pass";
        logger_.warn("Warning: Function body is empty, using 'pass'");
    } else {
    // 遍历所有语句，将它们添加到函数体中
    for (auto stmt : statements) {
        // 检查是否是return语句 - 使用StatementContext的方法
        auto returnStmt = stmt->returnStatement();
        if (returnStmt) {
            // 获取return语句中的表达式
            auto exprCtx = returnStmt->expression();
            if (exprCtx) {
                string exprText = exprCtx->getText();
                funcDef += "    return " + exprText + "\n";
            } else {
                funcDef += "    return\n";
            }
        } else {
            // 其他语句，使用原始文本
            string stmtText = stmt->getText();
            // 移除末尾的分号（如果有）
            if (!stmtText.empty() && stmtText.back() == ';') {
                stmtText.pop_back();
            }
            funcDef += "    " + stmtText + "\n";
        }
    }
    }
    
    logger_.debug(std::string("Function definition string:\n") + funcDef + "\n");
    
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
    
    try {
        py::object builtins_module = py::module_::import("builtins");
        builtins_module.attr("exec")(funcDef, globals, globals);
        py::object func = globals[funcName.c_str()];
        variable_manager_.setVariable(funcName, ScriptValue::fromPythonObject(func));
        logger_.info(std::string("Function defined: ") + funcName);
    } catch (const py::error_already_set& e) {
        reportError("Failed to define function " + funcName + ": " + string(e.what()), ctx);
    }
    
    // 重置标志
    defining_function_ = false;
    // 返回非空值阻止访问子节点
    return any(true);
}

any AstVisitor::visitParameterList(PyScriptParser::ParameterListContext *ctx) {
    // 参数列表已经在函数定义中处理
    return any();
}

any AstVisitor::visitIfStatement(PyScriptParser::IfStatementContext *ctx) {
    logger_.debug("visitIfStatement called");

    auto exprCtx = ctx->expression();
    if (!exprCtx) {
        reportError("If statement condition is missing", ctx);
        return any();
    }

    auto condValue = evaluateExpression(exprCtx);
    if (!condValue) {
        reportError("Cannot evaluate condition", ctx);
        return any();
    }

    if (expression_evaluator_.isTruthy(condValue)) {
        auto thenBlock = ctx->block(0);
        if (thenBlock) {
            return this->visit(thenBlock);
        }
    } else if (ctx->block().size() > 1) {
        auto elseBlock = ctx->block(1);
        if (elseBlock) {
            return this->visit(elseBlock);
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

        visit(ctx->block());

        if (error_handler_.hasError()) {
            break;
        }
    }

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

any AstVisitor::visitBlock(PyScriptParser::BlockContext *ctx) {
    if (ctx->statement().empty()) {
        // 空代码块
        return any();
    }

    // 执行代码块中的所有语句
    for (auto stmt : ctx->statement()) {
        visit(stmt);
        if (error_handler_.hasError()) {
            break;
        }
    }

    return any();
}

any AstVisitor::visitAssignment(PyScriptParser::AssignmentContext *ctx) {
    // 有三种赋值形式：标识符赋值、属性赋值、下标赋值
    if (ctx->IDENTIFIER()) {
        // 标识符赋值: IDENTIFIER assignmentOperator expression
        string varName = ctx->IDENTIFIER()->getText();
        auto op = ctx->assignmentOperator();
        if (!op) {
            reportError("Missing assignment operator", ctx);
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
        
        string opText = op->getText();
        if (opText == "=") {
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
        } else {
            // 复合赋值操作符
            auto leftVal = getVariable(varName);
            if (!leftVal) {
                reportError("Variable '" + varName + "' not defined for compound assignment", ctx);
                return any();
            }
            
            // 执行复合运算
            string baseOp = opText.substr(0, opText.size() - 1); // 去掉'='
            auto result = expression_evaluator_.evaluateBinaryOperation(baseOp, leftVal, rightValue);
            if (!result) {
                reportError("Unsupported compound assignment operator: " + opText, ctx);
                return any();
            }
            
            variable_manager_.setVariable(varName, result);
        }
    } else if (ctx->attributeAccess()) {
        // 属性赋值: attributeAccess '=' expression
        auto attrCtx = ctx->attributeAccess();
        auto primaryCtx = attrCtx->primaryExpression();
        if (!primaryCtx) {
            reportError("Attribute assignment missing object", ctx, ScriptErrorType::Runtime, ScriptErrorCode::Unknown);
            return any();
        }

        auto objectAny = visit(primaryCtx);
        shared_ptr<ScriptValue> objectValue;
        try {
            objectValue = any_cast<shared_ptr<ScriptValue>>(objectAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate object in attribute assignment", ctx, ScriptErrorType::Runtime, ScriptErrorCode::Unknown);
            return any();
        }

        if (!objectValue) {
            reportError("Cannot evaluate object in attribute assignment", ctx, ScriptErrorType::Runtime, ScriptErrorCode::Unknown);
            return any();
        }

        auto identifier = attrCtx->IDENTIFIER();
        if (!identifier) {
            reportError("Missing identifier in attribute assignment", ctx, ScriptErrorType::Syntax, ScriptErrorCode::InvalidSyntax);
            return any();
        }
        string memberName = identifier->getText();

        auto rightExpr = ctx->expression();
        if (!rightExpr) {
            reportError("Missing right-hand side expression", ctx, ScriptErrorType::Syntax, ScriptErrorCode::InvalidSyntax);
            return any();
        }

        auto rightValue = evaluateExpression(rightExpr);
        if (!rightValue) {
            reportError("Cannot evaluate right-hand side", ctx, ScriptErrorType::Runtime, ScriptErrorCode::Unknown);
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
                reportError(string("Python attribute assignment error: ") + e.what(), ctx, ScriptErrorType::Python, ScriptErrorCode::PythonException);
                return any();
            }
        } else {
            // 非Python对象，尝试通过ScriptValue的setMember方法
            try {
                objectValue->setMember(memberName, rightValue);
                return any(rightValue);
            } catch (const exception& e) {
                reportError(string("Attribute assignment error: ") + e.what(), ctx, ScriptErrorType::Runtime, ScriptErrorCode::UnsupportedOperation);
                return any();
            }
        }
    } else if (ctx->subscriptAccess()) {
        // 下标赋值: subscriptAccess '=' expression
        auto subscriptCtx = ctx->subscriptAccess();
        auto primaryCtx = subscriptCtx->primaryExpression();
        if (!primaryCtx) {
            reportError("Subscript access missing object", ctx);
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
        
        auto indexExpr = subscriptCtx->expression();
        if (!indexExpr) {
            reportError("Missing subscript index", ctx);
            return any();
        }
        
        auto indexValue = evaluateExpression(indexExpr);
        if (!indexValue) {
            reportError("Cannot evaluate subscript index", ctx);
            return any();
        }
        
        // 对于下标赋值，直接获取右侧表达式（语法是 subscriptAccess '=' expression）
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
            reportError("Subscript assignment not supported for this type", ctx);
            return any();
        }
    }
    
    return any();
}

any AstVisitor::visitAssignmentOperator(PyScriptParser::AssignmentOperatorContext *ctx) {
    // 赋值操作符已经在visitAssignment中处理
    return any();
}

any AstVisitor::visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) {
    auto value = evaluateExpression(ctx->expression());
    // 表达式语句的值可以忽略
    return any(value);
}

any AstVisitor::visitExpression(PyScriptParser::ExpressionContext *ctx) {
    // expression: assignment | ternaryExpression
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    } else if (ctx->ternaryExpression()) {
        return visit(ctx->ternaryExpression());
    }
    
    reportError("Invalid expression", ctx);
    return any();
}

any AstVisitor::visitTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) {
    logger_.debug("visitTernaryExpression called");
    
    // 检查是否有三元操作符
    if (ctx->children.size() == 1) {
        // 没有三元操作符，直接返回逻辑或表达式
        auto logicalOrExprs = ctx->logicalOrExpression();
        if (!logicalOrExprs.empty()) {
            return visit(logicalOrExprs[0]);
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
            auto trueExprCtx = logicalOrExprs[0];
            auto condExprCtx = logicalOrExprs[1];
            
            auto condAny = visit(condExprCtx);
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
                return visit(trueExprCtx);
            } else {
                return visit(falseExpr);
            }
        } else {
            reportError("Invalid Python-style ternary expression", ctx);
            return any();
        }
    } else {
        // C风格：condition ? trueExpr : falseExpr
        auto logicalOrExprs = ctx->logicalOrExpression();
        if (logicalOrExprs.empty()) {
            reportError("Missing condition in C-style ternary expression", ctx);
            return any();
        }
        auto condExprCtx = logicalOrExprs[0];
        PyScriptParser::ExpressionContext* trueExprCtx = nullptr;
        PyScriptParser::TernaryExpressionContext* falseExprCtx = nullptr;
        
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
            auto condAny = visit(condExprCtx);
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
                return visit(falseExprCtx);
            }
        } else {
            reportError("Invalid C-style ternary expression", ctx);
            return any();
        }
    }
}

any AstVisitor::visitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *ctx) {
    auto logicalAndExprs = ctx->logicalAndExpression();
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

any AstVisitor::visitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *ctx) {
    auto equalityExprs = ctx->equalityExpression();
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

any AstVisitor::visitEqualityExpression(PyScriptParser::EqualityExpressionContext *ctx) {
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

any AstVisitor::visitRelationalExpression(PyScriptParser::RelationalExpressionContext *ctx) {
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

any AstVisitor::visitAdditiveExpression(PyScriptParser::AdditiveExpressionContext *ctx) {
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

any AstVisitor::visitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *ctx) {
    auto unaryExprs = ctx->unaryExpression();
    if (unaryExprs.size() == 1) {
        return this->visit(unaryExprs[0]);
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
        auto result = expression_evaluator_.evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported multiplicative operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any AstVisitor::visitUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) {
    auto powerExprCtx = ctx->powerExpression();
    auto powerExprAny = this->visit(powerExprCtx);
    shared_ptr<ScriptValue> powerExprValue;
    try {
        powerExprValue = any_cast<shared_ptr<ScriptValue>>(powerExprAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate expression in unary expression", ctx);
        return any();
    }
    
    if (!powerExprValue) {
        reportError("Cannot evaluate expression in unary expression", ctx);
        return any();
    }
    
    // 检查是否有前缀操作符
    if (ctx->children.size() > 1) {
        string op = ctx->children[0]->getText();
        auto result = expression_evaluator_.evaluateUnaryOperation(op, powerExprValue);
        if (!result) {
            reportError("Unsupported unary operator: " + op, ctx);
            return any();
        }
        return any(result);
    }
    
    return any(powerExprValue);
}

any AstVisitor::visitCallOrPrimary(PyScriptParser::CallOrPrimaryContext *ctx) {
    logger_.debug("visitCallOrPrimary called");
    
    auto primary = ctx->primaryExpression();
    if (!primary) {
        reportError("Missing primary expression in callOrPrimary", ctx);
        return any();
    }
    
    // 获取primaryExpression的值
    auto primaryAny = this->visit(primary);
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
    
    // 应用所有的postfix操作符
    auto postfixOps = ctx->postfixOp();
    for (auto postfixOp : postfixOps) {
        // 检查postfixOp的类型
        auto* attrOp = dynamic_cast<PyScriptParser::AttributeAccessOpContext*>(postfixOp);
        auto* subscriptOp = dynamic_cast<PyScriptParser::SubscriptAccessOpContext*>(postfixOp);
        auto* funcCallOp = dynamic_cast<PyScriptParser::FunctionCallOpContext*>(postfixOp);
        
        if (attrOp) {
            // 属性访问: '.' IDENTIFIER
            auto identifier = attrOp->IDENTIFIER();
            if (!identifier) {
                reportError("Missing identifier in attribute access", postfixOp);
                return any();
            }
            string memberName = identifier->getText();
            auto member = python_bridge_.getMember(currentValue, memberName);
            if (!member) {
                reportError("Object has no member: " + memberName, postfixOp);
                return any();
            }
            currentValue = member;
        } else if (subscriptOp) {
            // 下标访问: '[' expression ']'
            auto indexExpr = subscriptOp->expression();
            if (!indexExpr) {
                reportError("Missing index expression in subscript access", postfixOp);
                return any();
            }
            auto indexValue = evaluateExpression(indexExpr);
            if (!indexValue) {
                reportError("Cannot evaluate subscript index", postfixOp);
                return any();
            }
            
            if (currentValue->isPythonObject()) {
                py::object pyObj = currentValue->getPythonObject();
                // 检查是否是函数对象，函数对象不可下标
                if (py::isinstance<py::function>(pyObj)) {
                    reportError("Cannot use function object as subscriptable", postfixOp);
                    return any();
                }
                try {
                    py::object pyIndex = indexValue->toPythonObject();
                    py::object result = pyObj[pyIndex];
                    currentValue = ScriptValue::fromPythonObject(result);
                } catch (const py::error_already_set& e) {
                    reportError("Python subscript error: " + string(e.what()), postfixOp);
                    return any();
                }
            } else if (currentValue->isList()) {
                auto& list = currentValue->getList();
                // 索引必须是整数
                if (!indexValue->isInteger()) {
                    reportError("List index must be an integer", postfixOp);
                    return any();
                }
                long long index = indexValue->getInteger();
                if (index < 0 || index >= static_cast<long long>(list.size())) {
                    reportError("List index out of bounds: " + to_string(index) + 
                               " (list size: " + to_string(list.size()) + ")", postfixOp);
                    return any();
                }
                currentValue = list[index];
            } else if (currentValue->isDictionary()) {
                auto& dict = currentValue->getDictionary();
                // 索引必须是字符串
                if (!indexValue->isString()) {
                    reportError("Dictionary key must be a string", postfixOp);
                    return any();
                }
                string key = indexValue->getString();
                auto it = dict.find(key);
                if (it == dict.end()) {
                    reportError("Dictionary key not found: " + key, postfixOp);
                    return any();
                }
                currentValue = it->second;
            } else {
                reportError("Subscript not supported for this type", postfixOp);
                return any();
            }
        } else if (funcCallOp) {
            // 函数调用: '(' argumentList? ')'
            vector<shared_ptr<ScriptValue>> positional;
            unordered_map<string, shared_ptr<ScriptValue>> keywords;
            vector<shared_ptr<ScriptValue>> starPos;
            vector<shared_ptr<ScriptValue>> starKw;

            auto argList = funcCallOp->argumentList();
            if (argList) {
                for (auto* a : argList->argument()) {
                    // Try to cast to each alternative
                    if (auto* keywordArg = dynamic_cast<PyScriptParser::KeywordArgumentContext*>(a)) {
                        auto val = evaluateExpression(keywordArg->expression());
                        if (!val) { reportError("Cannot evaluate keyword argument", postfixOp); return any(); }
                        keywords[keywordArg->IDENTIFIER()->getText()] = val;
                        logger_.debug(std::string("Keyword arg: ") + keywordArg->IDENTIFIER()->getText());
                    } else if (auto* starArg = dynamic_cast<PyScriptParser::StarArgumentContext*>(a)) {
                        auto val = evaluateExpression(starArg->expression());
                        if (!val) { reportError("Cannot evaluate * argument", postfixOp); return any(); }
                        starPos.push_back(val);
                        logger_.debug("Star positional arg detected (inline)");
                    } else if (auto* doubleStarArg = dynamic_cast<PyScriptParser::DoubleStarArgumentContext*>(a)) {
                        auto val = evaluateExpression(doubleStarArg->expression());
                        if (!val) { reportError("Cannot evaluate ** argument", postfixOp); return any(); }
                        starKw.push_back(val);
                        logger_.debug("Star keyword arg detected (inline)");
                    } else if (auto* positionalArg = dynamic_cast<PyScriptParser::PositionalArgumentContext*>(a)) {
                        std::string argText = positionalArg->getText();
                        logger_.debug(std::string("Evaluating inline positional argument: ") + argText);
                        auto valAny = visit(positionalArg->nonAssignmentExpression());
                        shared_ptr<ScriptValue> val;
                        try {
                            val = any_cast<shared_ptr<ScriptValue>>(valAny);
                        } catch (const bad_any_cast&) {
                            reportError(std::string("Cannot evaluate positional argument: ") + argText, postfixOp); 
                            return any();
                        }
                        if (!val) { reportError(std::string("Cannot evaluate positional argument: ") + argText, postfixOp); return any(); }
                        positional.push_back(val);
                        logger_.debug(std::string("Positional arg=") + val->toString());
                    } else {
                        reportError("Invalid argument", postfixOp);
                        return any();
                    }
                }
            }

            if (!currentValue->isPythonObject()) {
                reportError("Cannot call non-function type", postfixOp);
                return any();
            }

            try {
                py::object pyFunc = currentValue->getPythonObject();

                // 构建py::tuple
                py::tuple pyTuple(positional.size());
                size_t idx = 0;
                for (auto &p : positional) {
                    pyTuple[idx++] = p->toPythonObject();
                }
                // 处理 *args 展开 (inline)
                for (auto &p : starPos) {
                    if (p->isList()) {
                        for (auto &elem : p->getList()) {
                            py::list tmp = py::list(pyTuple);
                            tmp.append(elem->toPythonObject());
                            pyTuple = py::tuple(tmp);
                        }
                    } else if (p->isPythonObject()) {
                        try {
                            py::object pyObj = p->toPythonObject();
                            if (py::isinstance<py::iterable>(pyObj)) {
                                for (auto item : pyObj) {
                                    py::list tmp = py::list(pyTuple);
                                    tmp.append(item);
                                    pyTuple = py::tuple(tmp);
                                }
                            } else {
                                py::list tmp = py::list(pyTuple);
                                tmp.append(pyObj);
                                pyTuple = py::tuple(tmp);
                            }
                        } catch (...) {
                            reportError("Failed to expand *args", postfixOp);
                            return any();
                        }
                    } else {
                        py::list tmp = py::list(pyTuple);
                        tmp.append(p->toPythonObject());
                        pyTuple = py::tuple(tmp);
                    }
                }

                // 构建kwargs (inline)
                py::dict pyKwargs;
                for (auto &kv : keywords) {
                    pyKwargs[kv.first.c_str()] = kv.second->toPythonObject();
                }
                // 处理 **kwargs 展开
                for (auto &p : starKw) {
                    if (p->isDictionary()) {
                        for (auto &kv : p->getDictionary()) {
                            pyKwargs[kv.first.c_str()] = kv.second->toPythonObject();
                        }
                    } else if (p->isPythonObject()) {
                        try {
                            py::object pyObj = p->toPythonObject();
                            if (py::isinstance<py::dict>(pyObj)) {
                                py::dict pyD = pyObj.cast<py::dict>();
                                for (auto item : pyD) {
                                    std::string key = py::str(item.first).cast<std::string>();
                                    pyKwargs[key.c_str()] = item.second;
                                }
                            } else {
                                reportError("** unpack requires a mapping", postfixOp);
                                return any();
                            }
                        } catch (...) {
                            reportError("Failed to expand **kwargs", postfixOp);
                            return any();
                        }
                    } else {
                        reportError("** unpack requires a mapping", postfixOp);
                        return any();
                    }
                }

                // 使用DynamicPythonCaller来调用函数以传递args和kwargs
                py::object result = DynamicPythonCaller::callFunction(pyFunc, py::args(pyTuple), py::kwargs(pyKwargs));
                currentValue = ScriptValue::fromPythonObject(result);
            } catch (const py::error_already_set& e) {
                reportError("Python function call error: " + string(e.what()), postfixOp);
                return any();
            } catch (const exception& e) {
                reportError("Function call error: " + string(e.what()), postfixOp);
                return any();
            }
        } else {
            reportError("Unknown postfix operator type", postfixOp);
            return any();
        }
    }
    
    return any(currentValue);
}

any AstVisitor::visitFunctionCall(PyScriptParser::FunctionCallContext *ctx) {
    logger_.debug("visitFunctionCall called");
    
    // 新的语法允许更复杂的函数调用表达式
    // 获取被调用对象：可以是dottedName、attributeAccess、subscriptAccess或括号表达式
    antlr4::tree::ParseTree* callee = nullptr;
    if (ctx->dottedName()) {
        callee = ctx->dottedName();
    } else if (ctx->attributeAccess()) {
        callee = ctx->attributeAccess();
    } else if (ctx->subscriptAccess()) {
        callee = ctx->subscriptAccess();
    } else if (ctx->expression()) {
        // 括号表达式
        callee = ctx->expression();
    }
    
    if (!callee) {
        reportError("Function call missing callee", ctx);
        return any();
    }
    
    // 计算被调用对象的值
    auto calleeAny = this->visit(callee);
    shared_ptr<ScriptValue> calleeValue;
    try {
        calleeValue = any_cast<shared_ptr<ScriptValue>>(calleeAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate function callee", ctx);
        return any();
    }
    
    if (!calleeValue) {
        reportError("Cannot evaluate function callee", ctx);
        return any();
    }
    
    if (!calleeValue->isPythonObject()) {
        reportError("Cannot call non-function type", ctx);
        return any();
    }
    
    // 收集参数（支持位置参数、关键字参数以及 * / ** 展开）
    vector<shared_ptr<ScriptValue>> positional;
    unordered_map<string, shared_ptr<ScriptValue>> keywords;
    vector<shared_ptr<ScriptValue>> starPos;
    vector<shared_ptr<ScriptValue>> starKw;

    if (ctx->argumentList()) {
        auto argCtxs = ctx->argumentList()->argument();
        logger_.debug(std::string("Argument count: ") + std::to_string(argCtxs.size()));
        for (size_t i = 0; i < argCtxs.size(); ++i) {
            auto a = argCtxs[i];
            // Try to cast to each alternative
            if (auto* keywordArg = dynamic_cast<PyScriptParser::KeywordArgumentContext*>(a)) {
                auto val = evaluateExpression(keywordArg->expression());
                if (!val) { reportError("Cannot evaluate keyword argument", ctx); return any(); }
                keywords[keywordArg->IDENTIFIER()->getText()] = val;
                logger_.debug(std::string("Keyword arg: ") + keywordArg->IDENTIFIER()->getText());
            } else if (auto* starArg = dynamic_cast<PyScriptParser::StarArgumentContext*>(a)) {
                auto val = evaluateExpression(starArg->expression());
                if (!val) { reportError("Cannot evaluate * argument", ctx); return any(); }
                starPos.push_back(val);
                logger_.debug("Star positional arg detected");
            } else if (auto* doubleStarArg = dynamic_cast<PyScriptParser::DoubleStarArgumentContext*>(a)) {
                auto val = evaluateExpression(doubleStarArg->expression());
                if (!val) { reportError("Cannot evaluate ** argument", ctx); return any(); }
                starKw.push_back(val);
                logger_.debug("Star keyword arg detected");
            } else if (auto* positionalArg = dynamic_cast<PyScriptParser::PositionalArgumentContext*>(a)) {
                std::string argText = positionalArg->getText();
                logger_.debug(std::string("Evaluating positional argument expression: ") + argText);
                auto valAny = visit(positionalArg->nonAssignmentExpression());
                shared_ptr<ScriptValue> val;
                try {
                    val = any_cast<shared_ptr<ScriptValue>>(valAny);
                } catch (const bad_any_cast&) {
                    reportError(std::string("Cannot evaluate positional argument: ") + argText, ctx); 
                    return any();
                }
                if (!val) { reportError(std::string("Cannot evaluate positional argument: ") + argText, ctx); return any(); }
                positional.push_back(val);
                logger_.debug(std::string("Positional arg[") + std::to_string(i) + "]=" + val->toString());
            } else {
                reportError("Invalid argument", ctx);
                return any();
            }
        }
    }

    try {
        py::object pyFunc = calleeValue->getPythonObject();
        logger_.debug(std::string("Python function type: ") + py::str(py::type::of(pyFunc)).cast<std::string>() );

        // 构建py::tuple
        py::tuple pyTuple(positional.size());
        size_t idx = 0;
        for (auto &p : positional) {
            pyTuple[idx++] = p->toPythonObject();
        }
        // 处理 *args 展开
        for (auto &p : starPos) {
            if (p->isList()) {
                for (auto &elem : p->getList()) {
                    // 需要扩展到tuple末端：创建新的tuple并追加
                    py::list tmp = py::list(pyTuple);
                    tmp.append(elem->toPythonObject());
                    pyTuple = py::tuple(tmp);
                }
            } else if (p->isPythonObject()) {
                try {
                    py::object pyObj = p->toPythonObject();
                    if (py::isinstance<py::iterable>(pyObj)) {
                        for (auto item : pyObj) {
                            py::list tmp = py::list(pyTuple);
                            tmp.append(item);
                            pyTuple = py::tuple(tmp);
                        }
                    } else {
                        py::list tmp = py::list(pyTuple);
                        tmp.append(pyObj);
                        pyTuple = py::tuple(tmp);
                    }
                } catch (...) {
                    reportError("Failed to expand *args", ctx);
                    return any();
                }
            } else {
                py::list tmp = py::list(pyTuple);
                tmp.append(p->toPythonObject());
                pyTuple = py::tuple(tmp);
            }
        }

        // 构建kwargs
        py::dict pyKwargs;
        for (auto &kv : keywords) {
            pyKwargs[kv.first.c_str()] = kv.second->toPythonObject();
        }
        // 处理 **kwargs 展开
        for (auto &p : starKw) {
            if (p->isDictionary()) {
                for (auto &kv : p->getDictionary()) {
                    pyKwargs[kv.first.c_str()] = kv.second->toPythonObject();
                }
            } else if (p->isPythonObject()) {
                try {
                    py::object pyObj = p->toPythonObject();
                    if (py::isinstance<py::dict>(pyObj)) {
                        py::dict pyD = pyObj.cast<py::dict>();
                        for (auto item : pyD) {
                            std::string key = py::str(item.first).cast<std::string>();
                            pyKwargs[key.c_str()] = item.second;
                        }
                    } else {
                        reportError("** unpack requires a mapping", ctx);
                        return any();
                    }
                } catch (...) {
                    reportError("Failed to expand **kwargs", ctx);
                    return any();
                }
            } else {
                reportError("** unpack requires a mapping", ctx);
                return any();
            }
        }

        // 使用DynamicPythonCaller来调用函数以传递args和kwargs
        py::object result = DynamicPythonCaller::callFunction(pyFunc, py::args(pyTuple), py::kwargs(pyKwargs));
        logger_.debug(std::string("Result type=") + py::str(py::type::of(result)).cast<std::string>() 
                  + ", result=" + py::str(result).cast<std::string>());
        return any(ScriptValue::fromPythonObject(result));
    } catch (const py::error_already_set& e) {
        logger_.error(std::string("Python error=") + e.what());
        reportError("Python function call error: " + string(e.what()), ctx);
        return any();
    } catch (const exception& e) {
        logger_.error(std::string("Exception=") + e.what());
        reportError("Function call error: " + string(e.what()), ctx);
        return any();
    } 
}

any AstVisitor::visitAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) {
    logger_.debug("visitAttributeAccess called");
    
    auto primaryCtx = ctx->primaryExpression();
    if (!primaryCtx) {
        reportError("Attribute access missing object", ctx);
        return any();
    }
    
    auto objectAny = this->visit(primaryCtx);
    shared_ptr<ScriptValue> objectValue;
    try {
        objectValue = any_cast<shared_ptr<ScriptValue>>(objectAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate object in attribute access", ctx);
        return any();
    }
    
    if (!objectValue) {
        reportError("Cannot evaluate object in attribute access", ctx);
        return any();
    }
    
    string memberName = ctx->IDENTIFIER()->getText();
    logger_.debug(std::string("Member name: ") + memberName);

    auto member = python_bridge_.getMember(objectValue, memberName);
    if (!member) {
        reportError("Object has no member: " + memberName, ctx);
        return any();
    }

    logger_.debug(std::string("Member type=") + std::to_string(static_cast<int>(member->getType())) + ", value=" + member->toString());
    
    return any(member);
}

any AstVisitor::visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) {
    logger_.debug("visitSubscriptAccess called");
    
    auto primaryCtx = ctx->primaryExpression();
    if (!primaryCtx) {
        reportError("Subscript access missing object", ctx);
        return any();
    }
    
    auto objectAny = visit(primaryCtx);
    shared_ptr<ScriptValue> objectValue;
    try {
        objectValue = any_cast<shared_ptr<ScriptValue>>(objectAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate object in subscript access", ctx);
        return any();
    }
    
    if (!objectValue) {
        reportError("Cannot evaluate object in subscript access", ctx);
        return any();
    }
    
    auto indexValue = evaluateExpression(ctx->expression());
    if (!indexValue) {
        reportError("Cannot evaluate subscript index", ctx);
        return any();
    }
    
    if (objectValue->isPythonObject()) {
        py::object pyObj = objectValue->getPythonObject();
        
        // 检查是否是函数对象，函数对象不可下标
        if (py::isinstance<py::function>(pyObj)) {
            reportError("Cannot use function object as subscriptable", ctx);
            return any();
        }
        
        try {
            py::object pyIndex = indexValue->toPythonObject();
            py::object result = pyObj[pyIndex];
            return any(ScriptValue::fromPythonObject(result));
        } catch (const py::error_already_set& e) {
            reportError("Python subscript error: " + string(e.what()), ctx);
            return any();
        }
    } else if (objectValue->isList()) {
        auto& list = objectValue->getList();
        
        // 索引必须是整数
        if (!indexValue->isInteger()) {
            reportError("List index must be an integer", ctx);
            return any();
        }
        
        long long index = indexValue->getInteger();
        
        if (index < 0 || index >= static_cast<long long>(list.size())) {
            reportError("List index out of bounds: " + to_string(index) + 
                       " (list size: " + to_string(list.size()) + ")", ctx);
            return any();
        }
        
        return any(list[index]);
    } else if (objectValue->isDictionary()) {
        auto& dict = objectValue->getDictionary();
        
        // 索引必须是字符串
        if (!indexValue->isString()) {
            reportError("Dictionary key must be a string", ctx);
            return any();
        }
        
        string key = indexValue->getString();
        
        auto it = dict.find(key);
        if (it == dict.end()) {
            reportError("Dictionary key not found: " + key, ctx);
            return any();
        }
        
        return any(it->second);
    } else {
        reportError("Subscript not supported for this type", ctx);
        return any();
    }
}

any AstVisitor::visitPrimaryExpression(PyScriptParser::PrimaryExpressionContext *ctx) {
    if (ctx->literal()) {
        return visit(ctx->literal());
    } else if (ctx->dottedName()) {
        return visit(ctx->dottedName());
    } else if (ctx->expression()) {
        auto value = evaluateExpression(ctx->expression());
        return any(value);
    } else if (ctx->listLiteral()) {
        return visit(ctx->listLiteral());
    } else if (ctx->dictLiteral()) {
        return visit(ctx->dictLiteral());
    } else if (ctx->newExpression()) {
        return visit(ctx->newExpression());
    } else if (ctx->lambdaExpression()) {
        return visit(ctx->lambdaExpression());
    } else if (ctx->listComprehension()) {
        return visit(ctx->listComprehension());
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
    
    // 收集参数（支持位置参数、关键字参数以及 * / ** 展开）
    vector<shared_ptr<ScriptValue>> positional;
    unordered_map<string, shared_ptr<ScriptValue>> keywords;
    vector<shared_ptr<ScriptValue>> starPos;
    vector<shared_ptr<ScriptValue>> starKw;

    if (ctx->argumentList()) {
        auto argCtxs = ctx->argumentList()->argument();
        logger_.debug(std::string("Argument count: ") + std::to_string(argCtxs.size()));
        for (size_t i = 0; i < argCtxs.size(); ++i) {
            auto a = argCtxs[i];
            // Try to cast to each alternative
            if (auto* keywordArg = dynamic_cast<PyScriptParser::KeywordArgumentContext*>(a)) {
                auto val = evaluateExpression(keywordArg->expression());
                if (!val) { reportError("Cannot evaluate keyword argument", ctx); return any(); }
                keywords[keywordArg->IDENTIFIER()->getText()] = val;
            } else if (auto* starArg = dynamic_cast<PyScriptParser::StarArgumentContext*>(a)) {
                auto val = evaluateExpression(starArg->expression());
                if (!val) { reportError("Cannot evaluate * argument", ctx); return any(); }
                starPos.push_back(val);
            } else if (auto* doubleStarArg = dynamic_cast<PyScriptParser::DoubleStarArgumentContext*>(a)) {
                auto val = evaluateExpression(doubleStarArg->expression());
                if (!val) { reportError("Cannot evaluate ** argument", ctx); return any(); }
                starKw.push_back(val);
            } else if (auto* positionalArg = dynamic_cast<PyScriptParser::PositionalArgumentContext*>(a)) {
                auto valAny = visit(positionalArg->nonAssignmentExpression());
                shared_ptr<ScriptValue> val;
                try {
                    val = any_cast<shared_ptr<ScriptValue>>(valAny);
                } catch (const bad_any_cast&) {
                    // 如果转换失败，则使用null
                    val = ScriptValue::createNull();
                }
                positional.push_back(val ? val : ScriptValue::createNull());
            } else {
                reportError("Invalid argument", ctx);
                return any();
            }
        }
    }

    // 构建py::tuple
    py::tuple pyTuple(positional.size());
    size_t idx = 0;
    for (auto &p : positional) {
        pyTuple[idx++] = p->toPythonObject();
    }
    for (auto &p : starPos) {
        if (p->isList()) {
            for (auto &elem : p->getList()) {
                py::list tmp = py::list(pyTuple);
                tmp.append(elem->toPythonObject());
                pyTuple = py::tuple(tmp);
            }
        } else if (p->isPythonObject()) {
            try {
                py::object pyObj = p->toPythonObject();
                if (py::isinstance<py::iterable>(pyObj)) {
                    for (auto item : pyObj) {
                        py::list tmp = py::list(pyTuple);
                        tmp.append(item);
                        pyTuple = py::tuple(tmp);
                    }
                } else {
                    py::list tmp = py::list(pyTuple);
                    tmp.append(pyObj);
                    pyTuple = py::tuple(tmp);
                }
            } catch (...) {
                reportError("Failed to expand *args", ctx);
                return any();
            }
        } else {
            py::list tmp = py::list(pyTuple);
            tmp.append(p->toPythonObject());
            pyTuple = py::tuple(tmp);
        }
    }

    // 构建kwargs
    py::dict pyKwargs;
    for (auto &kv : keywords) {
        pyKwargs[kv.first.c_str()] = kv.second->toPythonObject();
    }
    for (auto &p : starKw) {
        if (p->isDictionary()) {
            for (auto &kv : p->getDictionary()) {
                pyKwargs[kv.first.c_str()] = kv.second->toPythonObject();
            }
        } else if (p->isPythonObject()) {
            try {
                py::object pyObj = p->toPythonObject();
                if (py::isinstance<py::dict>(pyObj)) {
                    py::dict pyD = pyObj.cast<py::dict>();
                    for (auto item : pyD) {
                        std::string key = py::str(item.first).cast<std::string>();
                        pyKwargs[key.c_str()] = item.second;
                    }
                } else {
                    reportError("** unpack requires a mapping", ctx);
                    return any();
                }
            } catch (...) {
                reportError("Failed to expand **kwargs", ctx);
                return any();
            }
        } else {
            reportError("** unpack requires a mapping", ctx);
            return any();
        }
    }
    
    string className = dottedNameCtx->getText();
    logger_.debug(std::string("Class name: ") + className);
    
    // 将点分名称拆分为部分
    vector<string> parts;
    size_t start = 0;
    size_t dotPos;
    while ((dotPos = className.find('.', start)) != string::npos) {
        parts.push_back(className.substr(start, dotPos - start));
        start = dotPos + 1;
    }
    parts.push_back(className.substr(start));
    
    if (parts.empty()) {
        reportError("Empty class name", ctx);
        return any();
    }
    
    // 获取基础对象（第一个部分）
    string firstPart = parts[0];
    shared_ptr<ScriptValue> currentValue = getVariable(firstPart);
    if (!currentValue) {
        // 检查是否是导入的模块
        auto module = variable_manager_.getModule(firstPart);
        if (module) {
            currentValue = ScriptValue::createPythonObject(module);
        } else {
            // 不是变量也不是已导入的模块，尝试作为模块导入
            try {
                py::module_ module = py::module_::import(firstPart.c_str());
                variable_manager_.importModule(firstPart, module);
                currentValue = ScriptValue::createPythonObject(module);
            } catch (const py::error_already_set& e) {
                reportError("Failed to import module " + firstPart + 
                           ": " + string(e.what()), ctx);
                return any();
            }
        }
    }
    
    // 逐级获取属性（除了最后一部分）
    for (size_t i = 1; i < parts.size() - 1; ++i) {
        currentValue = python_bridge_.getMember(currentValue, parts[i]);
        if (!currentValue) {
            reportError("Cannot get member '" + parts[i] + "' in " + className, ctx);
            return any();
        }
    }
    
    // 获取类对象（最后一部分）
    string lastPart = parts.back();
    shared_ptr<ScriptValue> classValue;
    if (parts.size() == 1) {
        // 只有一部分，当前值就是类对象
        classValue = currentValue;
    } else {
        classValue = python_bridge_.getMember(currentValue, lastPart);
        if (!classValue) {
            reportError("Cannot get class '" + lastPart + "' in " + className, ctx);
            return any();
        }
    }
    
    if (!classValue->isPythonObject()) {
        reportError("Cannot instantiate non-class type", ctx);
        return any();
    }
    
    try {
        py::object pyClass = classValue->getPythonObject();
        py::object instance = DynamicPythonCaller::callFunction(pyClass, py::args(pyTuple), py::kwargs(pyKwargs));
        return any(ScriptValue::fromPythonObject(instance));
    } catch (const py::error_already_set& e) {
        reportError("Failed to create instance " + className + 
                   ": " + string(e.what()), ctx);
        return any();
    } catch (const exception& e) {
        reportError("Instance creation error: " + string(e.what()), ctx);
        return any();
    }
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
    } else if (ctx->BOOL()) {
        bool value = (ctx->BOOL()->getText() == "true");
        return any(ScriptValue::createBoolean(value));
    } else if (ctx->NULL_LIT()) {
        return any(ScriptValue::createNull());
    }
    
    reportError("Invalid literal", ctx);
    return any();
}

any AstVisitor::visitListLiteral(PyScriptParser::ListLiteralContext *ctx) {
    logger_.debug("visitListLiteral called");
    auto listVal = ScriptValue::createList();
    
    if (ctx->expressionList()) {
        // 使用增强的visitExpressionList方法获取表达式值向量
        auto exprListResult = visitExpressionList(ctx->expressionList());
        try {
            auto values = any_cast<vector<shared_ptr<ScriptValue>>>(exprListResult);
            for (const auto& value : values) {
                listVal->append(value);
                logger_.debug(std::string("List element added: type=") + 
                            std::to_string(static_cast<int>(value->getType())) + 
                            ", value=" + value->toString());
            }
        } catch (const bad_any_cast&) {
            // 如果类型转换失败，回退到旧的方法
            logger_.debug("Failed to get expression list values, falling back to old method");
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
    }
    
    logger_.debug(std::string("Created list with ") + std::to_string(listVal->listSize()) + " elements");
    return any(listVal);
}

any AstVisitor::visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) {
    logger_.debug("visitDictLiteral called");
    auto dictVal = ScriptValue::createDictionary();
    
    if (ctx->dictItemList()) {
        // 使用增强的visitDictItemList方法获取字典项向量
        auto dictItemListResult = visitDictItemList(ctx->dictItemList());
        try {
            auto items = any_cast<vector<pair<shared_ptr<ScriptValue>, shared_ptr<ScriptValue>>>>(dictItemListResult);
            for (const auto& item : items) {
                if (item.first) {
                    string keyStr = item.first->toString();
                    dictVal->setKey(keyStr, item.second);
                    logger_.debug(std::string("Dict item added: key=") + keyStr + 
                                ", value type=" + std::to_string(static_cast<int>(item.second->getType())));
                } else {
                    // 展开项：合并字典或Python映射
                    auto unpackValue = item.second;
                    if (!unpackValue) {
                        reportError("Cannot evaluate dictionary unpack expression", ctx);
                        return any();
                    }

                    if (unpackValue->isPythonObject()) {
                        try {
                            py::object pyObj = unpackValue->getPythonObject();
                            py::module_ builtins = py::module_::import("builtins");
                            py::object dictType = builtins.attr("dict");
                            if (py::isinstance(pyObj, dictType)) {
                                py::dict pyDict = pyObj.cast<py::dict>();
                                for (auto item : pyDict) {
                                    py::object key = py::reinterpret_borrow<py::object>(item.first);
                                    py::object value = py::reinterpret_borrow<py::object>(item.second);
                                    string keyStr = key.cast<string>();
                                    auto val = ScriptValue::fromPythonObject(value);
                                    dictVal->setKey(keyStr, val);
                                }
                            } else {
                                reportError("Cannot unpack non-dictionary object", ctx);
                                return any();
                            }
                        } catch (const py::error_already_set& e) {
                            reportError("Dictionary unpack error: " + string(e.what()), ctx);
                            return any();
                        }
                    } else if (unpackValue->isDictionary()) {
                        auto& unpackDict = unpackValue->getDictionary();
                        for (auto& kv : unpackDict) {
                            dictVal->setKey(kv.first, kv.second);
                        }
                    } else {
                        reportError("Cannot unpack non-dictionary object", ctx);
                        return any();
                    }
                }
            }
        } catch (const bad_any_cast&) {
            // 如果类型转换失败，回退到旧的方法
            logger_.debug("Failed to get dict item list values, falling back to old method");
            auto items = ctx->dictItemList()->dictItem();
            for (auto item : items) {
                // 使用 dynamic_cast 来检查具体的类型
                auto* kv = dynamic_cast<PyScriptParser::KeyValuePairContext*>(item);
                auto* unpack = dynamic_cast<PyScriptParser::DictUnpackContext*>(item);
                
                if (kv) {
                    auto keyValue = evaluateExpression(kv->expression(0));
                    auto valValue = evaluateExpression(kv->expression(1));
                    
                    if (!keyValue || !valValue) {
                        reportError("Cannot evaluate dictionary key-value pair", ctx);
                        return any();
                    }
                    
                    string keyStr = keyValue->toString();
                    dictVal->setKey(keyStr, valValue);
                } else if (unpack) {
                    // 字典展开：**expression
                    auto unpackExpr = unpack->expression();
                    auto unpackValue = evaluateExpression(unpackExpr);
                    
                    if (!unpackValue) {
                        reportError("Cannot evaluate dictionary unpack expression", ctx);
                        return any();
                    }
                    
                    // 如果展开的值是字典，合并到当前字典
                    if (unpackValue->isPythonObject()) {
                        try {
                            py::object pyObj = unpackValue->getPythonObject();
                            // 检查是否是字典
                            py::module_ builtins = py::module_::import("builtins");
                            py::object dictType = builtins.attr("dict");
                            
                            if (py::isinstance(pyObj, dictType)) {
                                // 合并字典
                                py::dict pyDict = pyObj.cast<py::dict>();
                                for (auto item : pyDict) {
                                    py::object key = py::reinterpret_borrow<py::object>(item.first);
                                    py::object value = py::reinterpret_borrow<py::object>(item.second);
                                    string keyStr = key.cast<string>();
                                    auto val = ScriptValue::fromPythonObject(value);
                                    dictVal->setKey(keyStr, val);
                                }
                            } else {
                                reportError("Cannot unpack non-dictionary object", ctx);
                                return any();
                            }
                        } catch (const py::error_already_set& e) {
                            reportError("Dictionary unpack error: " + string(e.what()), ctx);
                            return any();
                        }
                    } else if (unpackValue->isDictionary()) {
                        // 如果是ScriptValue字典，直接合并
                        auto& unpackDict = unpackValue->getDictionary();
                        for (auto& kv : unpackDict) {
                            dictVal->setKey(kv.first, kv.second);
                        }
                    } else {
                        reportError("Cannot unpack non-dictionary object", ctx);
                        return any();
                    }
                } else {
                    reportError("Unknown dictionary item type", ctx);
                    return any();
                }
            }
        }
    }
    
    logger_.debug(std::string("Created dictionary with ") + std::to_string(dictVal->getDictionary().size()) + " entries");
    return any(dictVal);
}

any AstVisitor::visitDottedName(PyScriptParser::DottedNameContext *ctx) {
    // 点分隔的名称可能表示一个模块、模块的属性，或者一个变量
    string name = ctx->getText();
    logger_.debug(std::string("visitDottedName: ") + name);
    
    // 如果正在定义函数，则返回一个占位符，不报错
    if (defining_function_) {
        logger_.debug(std::string("Defining function, returning placeholder for: ") + name);
        // 返回一个null值作为占位符
        return any(ScriptValue::createNull());
    }
    
    // 首先检查变量
    auto var = variable_manager_.getVariable(name);
    if (var) {
        logger_.debug("Found in variables");
        return any(var);
    }
    
    // 检查导入的模块
    auto module = variable_manager_.getModule(name);
    if (module) {
        logger_.debug("Found in imported_modules");
        return any(ScriptValue::createPythonObject(module));
    }
    
    // 检查是否为内置Python对象
    if (name == "True" || name == "true") {
        return any(ScriptValue::createBoolean(true));
    } else if (name == "False" || name == "false") {
        return any(ScriptValue::createBoolean(false));
    } else if (name == "None" || name == "none" || name == "null") {
        return any(ScriptValue::createNull());
    }
    
    // 检查是否为Python内置函数
    auto builtins = variable_manager_.getBuiltins();
    if (!builtins.is_none()) {
        try {
            if (py::hasattr(builtins, name.c_str())) {
                py::object builtin_func = builtins.attr(name.c_str());
                return any(ScriptValue::fromPythonObject(builtin_func));
            }
        } catch (const py::error_already_set&) {
            // 忽略错误，继续向下
        }
    }
    
    // 尝试解析点分隔的名称：可能是模块的属性
    // 例如 os.path -> 先获取os模块，然后获取path属性
    vector<string> parts;
    size_t start = 0;
    size_t dotPos;
    while ((dotPos = name.find('.', start)) != string::npos) {
        parts.push_back(name.substr(start, dotPos - start));
        start = dotPos + 1;
    }
    parts.push_back(name.substr(start));
    
    if (parts.size() > 1) {
        // 尝试获取第一个部分作为模块或变量
        string firstPart = parts[0];
        auto firstVar = variable_manager_.getVariable(firstPart);
        if (firstVar) {
            // 如果第一个部分是Python对象，直接使用py::attr链访问
            if (firstVar->isPythonObject()) {
                py::object current = firstVar->getPythonObject();
                try {
                    for (size_t i = 1; i < parts.size(); ++i) {
                        current = current.attr(parts[i].c_str());
                    }
                    try {
                        logger_.debug(std::string("Dotted resolved to python object: ") + py::str(current).cast<std::string>() );
                    } catch (...) {
                        logger_.debug("Dotted resolved to python object (no str available)");
                    }
                    return any(ScriptValue::fromPythonObject(current));
                } catch (const py::error_already_set&) {
                    // 属性不存在，继续向下
                }
            } else {
                // 否则以ScriptValue链式获取成员（支持字典等）
                std::shared_ptr<ScriptValue> currentValue = firstVar;
                bool failed = false;
                for (size_t i = 1; i < parts.size(); ++i) {
                    currentValue = python_bridge_.getMember(currentValue, parts[i]);
                    if (!currentValue) {
                        failed = true;
                        break;
                    }
                }
                if (!failed && currentValue) {
                    return any(currentValue);
                }
            }
        } else {
            // 如果不是变量，则检查是否是已导入的模块
            auto module = variable_manager_.getModule(firstPart);
            if (module) {
                py::object current = module;
                try {
                    for (size_t i = 1; i < parts.size(); ++i) {
                        current = current.attr(parts[i].c_str());
                    }
                    try {
                        logger_.debug(std::string("Dotted resolved to module object: ") + py::str(current).cast<std::string>() );
                    } catch (...) {
                        logger_.debug("Dotted resolved to module object (no str available)");
                    }
                    return any(ScriptValue::fromPythonObject(current));
                } catch (const py::error_already_set&) {
                    // 属性不存在，继续向下
                }
            } else {
                // 不是变量也不是已导入模块，尝试导入第一个部分作为模块
                try {
                    py::module_ module = py::module_::import(firstPart.c_str());
                    variable_manager_.importModule(firstPart, module);
                    py::object current = module;
                    for (size_t i = 1; i < parts.size(); ++i) {
                        current = current.attr(parts[i].c_str());
                    }
                    return any(ScriptValue::fromPythonObject(current));
                } catch (const py::error_already_set&) {
                    // 失败，继续后续解析
                }
            }
        }
    }
    
    reportError("Undefined identifier: " + name, ctx);
    return any();
}

any AstVisitor::visitArgumentList(PyScriptParser::ArgumentListContext *ctx) {
    logger_.debug("visitArgumentList called");

    vector<shared_ptr<ScriptValue>> args;
    if (ctx) {
        auto arguments = ctx->argument();
        logger_.debug(std::string("Number of arguments: ") + std::to_string(arguments.size()));
        for (size_t i = 0; i < arguments.size(); ++i) {
            auto argCtx = arguments[i];
            // Try to cast to each alternative
            if (auto* positionalArg = dynamic_cast<PyScriptParser::PositionalArgumentContext*>(argCtx)) {
                auto argValueAny = visit(positionalArg->nonAssignmentExpression());
                shared_ptr<ScriptValue> argValue;
                try {
                    argValue = any_cast<shared_ptr<ScriptValue>>(argValueAny);
                } catch (const bad_any_cast&) {
                    reportError("Cannot evaluate argument", ctx);
                    return any();
                }
                if (argValue) {
                    args.push_back(argValue);
                    logger_.debug(std::string("Arg[") + std::to_string(i) + "] type=" + std::to_string(static_cast<int>(argValue->getType())) + ", value=" + argValue->toString());
                } else {
                    reportError("Cannot evaluate argument", ctx);
                    return any();
                }
            } else if (auto* keywordArg = dynamic_cast<PyScriptParser::KeywordArgumentContext*>(argCtx)) {
                // keyword arg - handled at call sites, we just skip here
                logger_.debug(std::string("Keyword argument detected: ") + keywordArg->IDENTIFIER()->getText());
                continue;
            } else if (auto* starArg = dynamic_cast<PyScriptParser::StarArgumentContext*>(argCtx)) {
                // star/unpack - handled at call sites
                logger_.debug("Star/unpack argument detected");
                continue;
            } else if (auto* doubleStarArg = dynamic_cast<PyScriptParser::DoubleStarArgumentContext*>(argCtx)) {
                // double star/unpack - handled at call sites
                logger_.debug("Double star/unpack argument detected");
                continue;
            } else {
                reportError("Invalid argument", ctx);
                return any();
            }
        }
    }
    return any(args);
}

any AstVisitor::visitExpressionList(PyScriptParser::ExpressionListContext *ctx) {
    logger_.debug("visitExpressionList called");
    
    vector<shared_ptr<ScriptValue>> values;
    if (ctx) {
        auto expressions = ctx->expression();
        logger_.debug(std::string("Number of expressions: ") + std::to_string(expressions.size()));
        for (size_t i = 0; i < expressions.size(); ++i) {
            auto exprValue = evaluateExpression(expressions[i]);
            if (exprValue) {
                values.push_back(exprValue);
                logger_.debug(std::string("Expression[") + std::to_string(i) + "] type=" + 
                            std::to_string(static_cast<int>(exprValue->getType())) + 
                            ", value=" + exprValue->toString());
            } else {
                reportError("Cannot evaluate expression in expression list", ctx);
                return any();
            }
        }
    }
    return any(values);
}

any AstVisitor::visitDictItemList(PyScriptParser::DictItemListContext *ctx) {
    logger_.debug("visitDictItemList called");
    
    vector<pair<shared_ptr<ScriptValue>, shared_ptr<ScriptValue>>> items;
    if (ctx) {
        auto dictItems = ctx->dictItem();
        logger_.debug(std::string("Number of dict items: ") + std::to_string(dictItems.size()));
        for (size_t i = 0; i < dictItems.size(); ++i) {
            auto itemResult = visit(dictItems[i]);
            // 首先尝试读取为键值对
            try {
                auto itemPair = any_cast<pair<shared_ptr<ScriptValue>, shared_ptr<ScriptValue>>>(itemResult);
                items.push_back(itemPair);
                logger_.debug(std::string("DictItem[") + std::to_string(i) + "] kv added");
                continue;
            } catch (const bad_any_cast&) {
                // 不是键值对，尝试判断是否为展开标记（单个ScriptValue）
            }

            try {
                auto unpackVal = any_cast<shared_ptr<ScriptValue>>(itemResult);
                // 表示这是一个展开项：用一个空的key来表示展开（first==nullptr）
                items.push_back(make_pair(shared_ptr<ScriptValue>(nullptr), unpackVal));
                logger_.debug(std::string("DictItem[") + std::to_string(i) + "] unpack added");
                continue;
            } catch (const bad_any_cast&) {
                // 都不是，报错
                reportError("Invalid dictionary item", ctx);
                return any();
            }
        }
    }
    return any(items);
}

// 新增：参数/Argument 和 power 表达式的基础实现


any AstVisitor::visitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) {
    logger_.debug("visitKeyValuePair called");
    
    if (!ctx || ctx->expression().size() < 2) {
        reportError("Invalid key-value pair", ctx);
        return any();
    }
    
    auto keyExpr = ctx->expression(0);
    auto valueExpr = ctx->expression(1);
    
    auto keyValue = evaluateExpression(keyExpr);
    auto valueValue = evaluateExpression(valueExpr);
    
    if (!keyValue || !valueValue) {
        reportError("Cannot evaluate key-value pair", ctx);
        return any();
    }
    
    logger_.debug(std::string("Key: type=") + std::to_string(static_cast<int>(keyValue->getType())) + 
                ", value=" + keyValue->toString());
    logger_.debug(std::string("Value: type=") + std::to_string(static_cast<int>(valueValue->getType())) + 
                ", value=" + valueValue->toString());
    
    return any(make_pair(keyValue, valueValue));
}

any AstVisitor::visitDictUnpack(PyScriptParser::DictUnpackContext *ctx) {
    logger_.debug("visitDictUnpack called");
    
    if (!ctx || !ctx->expression()) {
        reportError("Invalid dictionary unpack", ctx);
        return any();
    }
    
    auto expr = ctx->expression();
    auto unpackValue = evaluateExpression(expr);
    
    if (!unpackValue) {
        reportError("Cannot evaluate dictionary unpack expression", ctx);
        return any();
    }
    
    // 返回一个特殊的标记，表示这是一个字典展开操作
    // 在visitDictLiteral中会处理这个标记
    return any(unpackValue);
}

any AstVisitor::visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) {
    logger_.debug("visitLambdaExpression called");
    
    // 获取表达式文本
    auto exprCtx = ctx->expression();
    if (!exprCtx) {
        reportError("Lambda expression must have a body", ctx);
        return any();
    }
    
    std::string exprText = exprCtx->getText();
    logger_.debug(std::string("Lambda expression body: ") + exprText);
    
    // 获取参数列表
    std::vector<std::string> paramNames;
    auto identifiers = ctx->IDENTIFIER();
    for (auto* id : identifiers) {
        paramNames.push_back(id->getText());
    }
    
    // 构建Python lambda字符串
    std::string lambdaStr = "lambda ";
    if (!paramNames.empty()) {
        for (size_t i = 0; i < paramNames.size(); ++i) {
            if (i > 0) lambdaStr += ", ";
            lambdaStr += paramNames[i];
        }
    }
    lambdaStr += ": ";
    lambdaStr += exprText;
    
    logger_.debug(std::string("Python lambda string: ") + lambdaStr);
    
    // 捕获当前变量环境
    py::dict locals;
    auto varNames = variable_manager_.getAllVariableNames();
    for (const auto& varName : varNames) {
        auto var = variable_manager_.getVariable(varName);
        if (var) {
            try {
                locals[py::str(varName)] = var->toPythonObject();
            } catch (const std::exception& e) {
                std::cerr << "Warning: Failed to convert variable '" << varName << "' to Python object: " << e.what() << std::endl;
            }
        }
    }
    
    // 确保globals包含必要的内置函数
    py::dict globals = py::globals();
    if (!globals.contains("__builtins__")) {
        try {
            py::module_ builtins = py::module_::import("builtins");
            globals["__builtins__"] = builtins;
        } catch (...) {
            // 忽略错误
        }
    }
    
    // 使用Python的eval创建lambda函数
    try {
        py::object builtins = py::module_::import("builtins");
        py::object lambdaFunc = builtins.attr("eval")(lambdaStr, globals, locals);
        logger_.debug("Lambda function created successfully");
        return any(ScriptValue::fromPythonObject(lambdaFunc));
    } catch (const py::error_already_set& e) {
        logger_.error(std::string("Python eval error: ") + e.what());
        reportError("Failed to create lambda function: " + std::string(e.what()), ctx);
        return any();
    } catch (const std::exception& e) {
        logger_.error(std::string("General error: ") + e.what());
        reportError("Failed to create lambda function: " + std::string(e.what()), ctx);
        return any();
    }
}

any AstVisitor::visitForStatement(PyScriptParser::ForStatementContext *ctx) {
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

any AstVisitor::visitForControl(PyScriptParser::ForControlContext *ctx) {
    // for控制已经在visitForStatement中处理
    return any();
}

any AstVisitor::visitForInit(PyScriptParser::ForInitContext *ctx) {
    // 执行初始化赋值
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    }
    return any();
}

any AstVisitor::visitForUpdate(PyScriptParser::ForUpdateContext *ctx) {
    // 执行更新赋值
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    }
    return any();
}

any AstVisitor::visitListComprehension(PyScriptParser::ListComprehensionContext *ctx) {
    logger_.debug("visitListComprehension called");
    
    auto expr = ctx->expression(0);  // 表达式部分
    auto varName = ctx->IDENTIFIER();
    auto iterableExpr = ctx->expression(1);  // 可迭代对象
    
    if (!expr || !varName || !iterableExpr) {
        reportError("Invalid list comprehension syntax", ctx);
        return any();
    }
    
    // 获取可迭代对象的值
    auto iterableValue = evaluateExpression(iterableExpr);
    if (!iterableValue) {
        reportError("Cannot evaluate iterable in list comprehension", ctx);
        return any();
    }
    
    // 构建Python列表推导式字符串
    std::string compStr = "[";
    compStr += expr->getText();
    compStr += " for ";
    compStr += varName->getText();
    compStr += " in ";
    compStr += iterableExpr->getText();
    compStr += "]";
    
    logger_.debug(std::string("Python list comprehension string: ") + compStr);
    
    // 捕获当前变量环境
    py::dict locals;
    auto varNames = variable_manager_.getAllVariableNames();
    for (const auto& varName : varNames) {
        auto var = variable_manager_.getVariable(varName);
        if (var) {
            try {
                locals[py::str(varName)] = var->toPythonObject();
            } catch (const std::exception& e) {
                std::cerr << "Warning: Failed to convert variable '" << varName << "' to Python object: " << e.what() << std::endl;
            }
        }
    }
    
    // 确保globals包含必要的内置函数
    py::dict globals = py::globals();
    if (!globals.contains("__builtins__")) {
        try {
            py::module_ builtins = py::module_::import("builtins");
            globals["__builtins__"] = builtins;
        } catch (...) {
            // 忽略错误
        }
    }
    
    // 使用Python的eval创建列表
    try {
        py::object builtins = py::module_::import("builtins");
        py::object resultList = builtins.attr("eval")(compStr, globals, locals);
        logger_.debug("List comprehension created successfully");
        return any(ScriptValue::fromPythonObject(resultList));
    } catch (const py::error_already_set& e) {
        std::cerr << "Python eval error: " << e.what() << std::endl;
        reportError("Failed to create list comprehension: " + std::string(e.what()), ctx);
        return any();
    } catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << std::endl;
        reportError("Failed to create list comprehension: " + std::string(e.what()), ctx);
        return any();
    }
}

any AstVisitor::visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) {
    logger_.debug("visitAttributeAccessOp called");

    // 获取当前对象值（来自callOrPrimary中的primaryExpression）
    // 注意：attributeAccessOp的父节点是postfixOp，postfixOp的父节点是callOrPrimary
    // 我们需要获取到当前的对象值，这应该通过上下文传递，这里简化处理
    // 实际实现中，callOrPrimary应该累积应用postfixOp

    // 临时实现：报告错误
    reportError("Attribute access operator not fully implemented yet", ctx);
    return any();
}

any AstVisitor::visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) {
    logger_.debug("visitSubscriptAccessOp called");

    // 临时实现：报告错误
    reportError("Subscript access operator not fully implemented yet", ctx);
    return any();
}

any AstVisitor::visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) {
    logger_.debug("visitFunctionCallOp called");

    // 临时实现：报告错误
    reportError("Function call operator not fully implemented yet", ctx);
    return any();
}

// 新增的visitor方法实现
any AstVisitor::visitParameter(PyScriptParser::ParameterContext *ctx) {
    logger_.debug("visitParameter called");
    // 参数解析在函数定义阶段处理，这里保持占位
    return any();
}

any AstVisitor::visitPositionalArgument(PyScriptParser::PositionalArgumentContext *ctx) {
    logger_.debug("visitPositionalArgument called");
    // 根据新的语法，PositionalArgumentContext包含nonAssignmentExpression
    if (ctx->nonAssignmentExpression()) {
        return visit(ctx->nonAssignmentExpression());
    }
    reportError("Invalid positional argument", ctx);
    return any();
}

any AstVisitor::visitKeywordArgument(PyScriptParser::KeywordArgumentContext *ctx) {
    logger_.debug("visitKeywordArgument called");
    // 关键字参数已经在visitArgumentList中处理，这里只返回占位符
    return any();
}

any AstVisitor::visitStarArgument(PyScriptParser::StarArgumentContext *ctx) {
    logger_.debug("visitStarArgument called");
    // 星号参数已经在visitArgumentList中处理，这里只返回占位符
    return any();
}

any AstVisitor::visitDoubleStarArgument(PyScriptParser::DoubleStarArgumentContext *ctx) {
    logger_.debug("visitDoubleStarArgument called");
    // 双星号参数已经在visitArgumentList中处理，这里只返回占位符
    return any();
}

any AstVisitor::visitNonAssignmentExpression(PyScriptParser::NonAssignmentExpressionContext *ctx) {
    logger_.debug("visitNonAssignmentExpression called");
    // nonAssignmentExpression只是ternaryExpression的别名，所以直接委托给visitTernaryExpression
    if (ctx->ternaryExpression()) {
        return visit(ctx->ternaryExpression());
    }
    reportError("Invalid non-assignment expression", ctx);
    return any();
}

any AstVisitor::visitPowerExpression(PyScriptParser::PowerExpressionContext *ctx) {
    logger_.debug("visitPowerExpression called");
    
    // 获取左边表达式（callOrPrimary）
    auto leftAny = visit(ctx->callOrPrimary());
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
    
    // 检查是否有幂运算（DOUBLE_STAR）
    if (ctx->powerExpression()) {
        // 获取右边表达式（递归处理幂运算，因为幂运算是右结合的）
        auto rightAny = visit(ctx->powerExpression());
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
        
        // 执行幂运算：a ** b
        auto result = expression_evaluator_.evaluateBinaryOperation("**", left, right);
        if (!result) {
            reportError("Unsupported power operation", ctx);
            return any();
        }
        return any(result);
    }
    
    // 没有幂运算符，直接返回左值
    return any(left);
}
