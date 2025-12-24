/**
 * @file ast_visitor.h
 * @brief ANTLR语法树访问者模块
 * 
 * 该模块负责遍历ANTLR生成的抽象语法树（AST），执行相应的语义动作。
 * 将所有的visitor方法从ScriptInterpreter中分离出来，专注于语法树的遍历和解析。
 */

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <any>
#include <pybind11/pybind11.h>
#include "script_value.h"
#include "variable_manager.h"
#include "error_handler.h"
#include "logger.h"
#include "python_bridge.h"
#include "expression_evaluator.h"
#include "antlr/PyScriptVisitor.h"

namespace py = pybind11;

namespace antlr4 {
class ParserRuleContext;
}

namespace script_interpreter {

/**
 * @class AstVisitor
 * @brief 抽象语法树访问者类
 * 
 * 实现ANTLR的PyScriptVisitor接口，负责遍历语法树并执行相应的语义动作。
 * 与ScriptInterpreter解耦，专注于语法树的解析和转换。
 */
class AstVisitor : public PyScriptVisitor {
public:
    /**
     * @brief 构造函数
     * @param variable_manager 变量管理器引用
     * @param error_handler 错误处理器引用
     * @param logger 日志记录器引用
     * @param python_bridge Python桥接器引用
     * @param expression_evaluator 表达式求值引擎引用
     */
    AstVisitor(VariableManager& variable_manager,
               ErrorHandler& error_handler,
               Logger& logger,
               PythonBridge& python_bridge,
               ExpressionEvaluator& expression_evaluator);
    
    /**
     * @brief 析构函数
     */
    virtual ~AstVisitor() = default;
    
    // Visitor接口实现
    std::any visitProgram(PyScriptParser::ProgramContext *ctx) override;
    std::any visitStatement(PyScriptParser::StatementContext *ctx) override;
    std::any visitImportStatement(PyScriptParser::ImportStatementContext *ctx) override;
    std::any visitFunctionDefinition(PyScriptParser::FunctionDefinitionContext *ctx) override;
    std::any visitParameterList(PyScriptParser::ParameterListContext *ctx) override;
    std::any visitIfStatement(PyScriptParser::IfStatementContext *ctx) override;
    std::any visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) override;
    std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) override;
    std::any visitBlock(PyScriptParser::BlockContext *ctx) override;
    std::any visitAssignment(PyScriptParser::AssignmentContext *ctx) override;
    std::any visitAssignmentOperator(PyScriptParser::AssignmentOperatorContext *ctx) override;
    std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) override;
    std::any visitExpression(PyScriptParser::ExpressionContext *ctx) override;
    std::any visitTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) override;
    std::any visitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *ctx) override;
    std::any visitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *ctx) override;
    std::any visitEqualityExpression(PyScriptParser::EqualityExpressionContext *ctx) override;
    std::any visitRelationalExpression(PyScriptParser::RelationalExpressionContext *ctx) override;
    std::any visitAdditiveExpression(PyScriptParser::AdditiveExpressionContext *ctx) override;
    std::any visitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *ctx) override;
    std::any visitUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) override;
    std::any visitCallOrPrimary(PyScriptParser::CallOrPrimaryContext *ctx) override;
    std::any visitFunctionCall(PyScriptParser::FunctionCallContext *ctx) override;
    std::any visitAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) override;
    std::any visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) override;
    std::any visitPrimaryExpression(PyScriptParser::PrimaryExpressionContext *ctx) override;
    std::any visitNewExpression(PyScriptParser::NewExpressionContext *ctx) override;
    std::any visitLiteral(PyScriptParser::LiteralContext *ctx) override;
    std::any visitListLiteral(PyScriptParser::ListLiteralContext *ctx) override;
    std::any visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) override;
    std::any visitDottedName(PyScriptParser::DottedNameContext *ctx) override;
    std::any visitArgumentList(PyScriptParser::ArgumentListContext *ctx) override;
    std::any visitExpressionList(PyScriptParser::ExpressionListContext *ctx) override; 
    std::any visitDictItemList(PyScriptParser::DictItemListContext *ctx) override;
    std::any visitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) override;
    std::any visitDictUnpack(PyScriptParser::DictUnpackContext *ctx) override;
    std::any visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) override;
    std::any visitForStatement(PyScriptParser::ForStatementContext *ctx) override;
    std::any visitForControl(PyScriptParser::ForControlContext *ctx) override;
    std::any visitForInit(PyScriptParser::ForInitContext *ctx) override;
    std::any visitForUpdate(PyScriptParser::ForUpdateContext *ctx) override;
    std::any visitListComprehension(PyScriptParser::ListComprehensionContext *ctx) override;
    std::any visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) override;
    std::any visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) override;
    std::any visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) override;
    
    // 新增的参数和参数相关方法
    std::any visitParameter(PyScriptParser::ParameterContext *ctx) override;
    std::any visitPositionalArgument(PyScriptParser::PositionalArgumentContext *ctx) override;
    std::any visitKeywordArgument(PyScriptParser::KeywordArgumentContext *ctx) override;
    std::any visitStarArgument(PyScriptParser::StarArgumentContext *ctx) override;
    std::any visitDoubleStarArgument(PyScriptParser::DoubleStarArgumentContext *ctx) override;
    
    // 新增的非赋值表达式方法
    std::any visitNonAssignmentExpression(PyScriptParser::NonAssignmentExpressionContext *ctx) override;
    
    // 新增的幂表达式方法
    std::any visitPowerExpression(PyScriptParser::PowerExpressionContext *ctx) override;
    
    /**
     * @brief 设置定义函数标志
     * @param defining 是否正在定义函数
     */
    void setDefiningFunction(bool defining) { defining_function_ = defining; }
    
    /**
     * @brief 获取定义函数标志
     * @return 是否正在定义函数
     */
    bool isDefiningFunction() const { return defining_function_; }
    
    /**
     * @brief 设置执行结果
     * @param result 执行结果
     */
    void setResult(std::shared_ptr<ScriptValue> result) { result_ = result; }
    
    /**
     * @brief 获取执行结果
     * @return 执行结果
     */
    std::shared_ptr<ScriptValue> getResult() const { return result_; }
    
    /**
     * @brief 求值表达式
     * @param ctx 表达式上下文
     * @return 表达式求值结果
     */
    std::shared_ptr<ScriptValue> evaluateExpression(PyScriptParser::ExpressionContext *ctx);
    
    /**
     * @brief 报告错误
     * @param message 错误消息
     * @param type 错误类型（默认Runtime）
     * @param code 错误代码（默认Unknown）
     * @param line 行号（默认-1）
     * @param column 列号（默认-1）
     */
    void reportError(const std::string& message,
                    ScriptErrorType type = ScriptErrorType::Runtime,
                    ScriptErrorCode code = ScriptErrorCode::Unknown,
                    int line = -1, int column = -1);
    
    /**
     * @brief 报告错误（带上下文）
     * @param message 错误消息
     * @param ctx 解析器规则上下文
     * @param type 错误类型（默认Runtime）
     * @param code 错误代码（默认Unknown）
     */
    void reportError(const std::string& message, antlr4::ParserRuleContext *ctx,
                    ScriptErrorType type = ScriptErrorType::Runtime,
                    ScriptErrorCode code = ScriptErrorCode::Unknown);
    
    /**
     * @brief 获取变量
     * @param name 变量名
     * @return 变量值
     */
    std::shared_ptr<ScriptValue> getVariable(const std::string& name);
    
    /**
     * @brief 设置变量
     * @param name 变量名
     * @param value 变量值
     */
    void setVariable(const std::string& name, std::shared_ptr<ScriptValue> value);
    
    /**
     * @brief 执行代码块
     * @param ctx 代码块上下文
     * @return 代码块执行结果
     */
    std::shared_ptr<ScriptValue> executeBlock(PyScriptParser::BlockContext *ctx);
    
private:
    // 模块引用
    VariableManager& variable_manager_;
    ErrorHandler& error_handler_;
    Logger& logger_;
    PythonBridge& python_bridge_;
    ExpressionEvaluator& expression_evaluator_;
    
    // 执行状态
    std::shared_ptr<ScriptValue> result_; ///< 执行结果
    bool defining_function_;               ///< 是否正在定义函数
    
    /**
     * @brief 获取Python桥接器
     * @return Python桥接器引用
     */
    PythonBridge& getPythonBridge() { return python_bridge_; }
    
    /**
     * @brief 获取表达式求值引擎
     * @return 表达式求值引擎引用
     */
    ExpressionEvaluator& getExpressionEvaluator() { return expression_evaluator_; }
};

} // namespace script_interpreter
