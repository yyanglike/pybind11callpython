#ifndef SCRIPT_INTERPRETER_H
#define SCRIPT_INTERPRETER_H

#include "script_value.h"
#include "antlr/PyScriptVisitor.h"
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

namespace py = pybind11;

class ScriptInterpreter : public PyScriptVisitor {
public:
    // 构造函数和析构函数
    ScriptInterpreter();
    ~ScriptInterpreter();
    
    // 执行脚本
    bool execute(const std::string& script);
    bool executeFile(const std::string& filename);
    
    // 获取变量
    std::shared_ptr<ScriptValue> getVariable(const std::string& name);
    
    // 设置变量
    void setVariable(const std::string& name, std::shared_ptr<ScriptValue> value);
    
    // 清空环境
    void clearEnvironment();
    
    // 获取执行结果
    std::shared_ptr<ScriptValue> getResult() const { return result_; }
    
    // 检查是否有错误
    bool hasError() const { return has_error_; }
    const std::string& getErrorMessage() const { return error_message_; }

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

    // 新增的Visitor方法，用于新的语法规则
    std::any visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) override;
    std::any visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) override;
    std::any visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) override;

private:
    // 变量环境
    std::unordered_map<std::string, std::shared_ptr<ScriptValue>> variables_;
    
    // 导入的Python模块
    std::unordered_map<std::string, py::module_> imported_modules_;
    
    // 执行结果
    std::shared_ptr<ScriptValue> result_;
    
    // 错误状态
    bool has_error_;
    std::string error_message_;
    
    // Python内置函数
    py::object builtins_;
    
    // 当前是否在Python解释器控制下
    bool python_initialized_;
    
    // 是否正在定义函数（用于避免在函数定义体中报错）
    bool defining_function_;
    
    // 辅助方法
    void reportError(const std::string& message);
    void reportError(const std::string& message, antlr4::ParserRuleContext *ctx);
    
    // 表达式求值辅助方法
    std::shared_ptr<ScriptValue> evaluateExpression(PyScriptParser::ExpressionContext *ctx);
    std::shared_ptr<ScriptValue> evaluateTernary(PyScriptParser::TernaryExpressionContext *ctx);
    std::shared_ptr<ScriptValue> evaluateLogicalOr(PyScriptParser::LogicalOrExpressionContext *ctx);
    std::shared_ptr<ScriptValue> evaluateLogicalAnd(PyScriptParser::LogicalAndExpressionContext *ctx);
    std::shared_ptr<ScriptValue> evaluateEquality(PyScriptParser::EqualityExpressionContext *ctx);
    std::shared_ptr<ScriptValue> evaluateRelational(PyScriptParser::RelationalExpressionContext *ctx);
    std::any evaluateAdditive(PyScriptParser::AdditiveExpressionContext *ctx);
    std::any evaluateMultiplicative(PyScriptParser::MultiplicativeExpressionContext *ctx);
    std::any evaluateUnary(PyScriptParser::UnaryExpressionContext *ctx);
    
    // 运算符求值
    std::shared_ptr<ScriptValue> evaluateBinaryOperation(
        const std::string& op,
        std::shared_ptr<ScriptValue> left,
        std::shared_ptr<ScriptValue> right);
    
    std::shared_ptr<ScriptValue> evaluateUnaryOperation(
        const std::string& op,
        std::shared_ptr<ScriptValue> value);
    
    // 类型转换
    bool isTruthy(std::shared_ptr<ScriptValue> value) const;
    
    // Python集成
    std::shared_ptr<ScriptValue> callPythonFunction(
        py::object func,
        const std::vector<std::shared_ptr<ScriptValue>>& args);
    
    std::shared_ptr<ScriptValue> createPythonInstance(
        const std::string& moduleName,
        const std::string& className,
        const std::vector<std::shared_ptr<ScriptValue>>& args);
    
    // 获取成员
    std::shared_ptr<ScriptValue> getMember(
        std::shared_ptr<ScriptValue> object,
        const std::string& memberName);
    
    // 设置成员
    void setMember(
        std::shared_ptr<ScriptValue> object,
        const std::string& memberName,
        std::shared_ptr<ScriptValue> value);
    
    // 执行代码块
    std::shared_ptr<ScriptValue> executeBlock(PyScriptParser::BlockContext *ctx);
};

#endif // SCRIPT_INTERPRETER_H
