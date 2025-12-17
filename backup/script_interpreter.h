#ifndef SCRIPT_INTERPRETER_H
#define SCRIPT_INTERPRETER_H

#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include <antlr4-runtime.h>
#include "PyScriptBaseVisitor.h"
#include "dynamic_python_caller.h"

namespace py = pybind11;

// 脚本解释器类
class ScriptInterpreter : public PyScriptBaseVisitor {
public:
    // 脚本值类型前向声明
    struct ScriptValue;
    
    // 脚本值类型定义
    using ScriptValueVariant = std::variant<
        int,
        double,
        std::string,
        bool,
        py::object,
        std::vector<std::shared_ptr<ScriptValue>>,
        std::unordered_map<std::string, std::shared_ptr<ScriptValue>>
    >;
    
    // ScriptValue 结构定义
    struct ScriptValue {
        ScriptValueVariant value;
        
        template<typename T>
        ScriptValue(T&& val) : value(std::forward<T>(val)) {}
        
        template<typename T>
        bool holds_alternative() const {
            return std::holds_alternative<T>(value);
        }
        
        template<typename T>
        T& get() {
            return std::get<T>(value);
        }
        
        template<typename T>
        const T& get() const {
            return std::get<T>(value);
        }
        
        size_t index() const {
            return value.index();
        }
    };
public:
    ScriptInterpreter();
    ~ScriptInterpreter();
    
    // 执行脚本
    bool execute(const std::string& script);
    
    // 执行脚本文件
    bool executeFile(const std::string& filename);
    
    // 获取执行结果
    std::shared_ptr<ScriptValue> getResult() const { return result_; }
    
    // 获取变量
    std::shared_ptr<ScriptValue> getVariable(const std::string& name);
    
    // 设置变量
    void setVariable(const std::string& name, std::shared_ptr<ScriptValue> value);
    
    // 清空变量环境
    void clearEnvironment();
    
    // Visitor接口实现
    virtual antlrcpp::Any visitProgram(PyScriptParser::ProgramContext *ctx) override;
    virtual antlrcpp::Any visitImportStatement(PyScriptParser::ImportStatementContext *ctx) override;
    virtual antlrcpp::Any visitAssignment(PyScriptParser::AssignmentContext *ctx) override;
    virtual antlrcpp::Any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) override;
    virtual antlrcpp::Any visitIfStatement(PyScriptParser::IfStatementContext *ctx) override;
    virtual antlrcpp::Any visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) override;
    virtual antlrcpp::Any visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) override;
    
    virtual antlrcpp::Any visitLiteralExpr(PyScriptParser::LiteralExprContext *ctx) override;
    virtual antlrcpp::Any visitIdentifierExpr(PyScriptParser::IdentifierExprContext *ctx) override;
    virtual antlrcpp::Any visitParenExpr(PyScriptParser::ParenExprContext *ctx) override;
    virtual antlrcpp::Any visitMemberAccessExpr(PyScriptParser::MemberAccessExprContext *ctx) override;
    virtual antlrcpp::Any visitFunctionCallExpr(PyScriptParser::FunctionCallExprContext *ctx) override;
    virtual antlrcpp::Any visitNewInstanceExpr(PyScriptParser::NewInstanceExprContext *ctx) override;
    virtual antlrcpp::Any visitSubscriptExpr(PyScriptParser::SubscriptExprContext *ctx) override;
    virtual antlrcpp::Any visitAttributeAssignmentExpr(PyScriptParser::AttributeAssignmentExprContext *ctx) override;
    virtual antlrcpp::Any visitSubscriptAssignmentExpr(PyScriptParser::SubscriptAssignmentExprContext *ctx) override;
    virtual antlrcpp::Any visitBinaryExpr(PyScriptParser::BinaryExprContext *ctx) override;
    virtual antlrcpp::Any visitUnaryExpr(PyScriptParser::UnaryExprContext *ctx) override;
    virtual antlrcpp::Any visitTernaryExpr(PyScriptParser::TernaryExprContext *ctx) override;
    
    virtual antlrcpp::Any visitIntegerLiteral(PyScriptParser::IntegerLiteralContext *ctx) override;
    virtual antlrcpp::Any visitFloatLiteral(PyScriptParser::FloatLiteralContext *ctx) override;
    virtual antlrcpp::Any visitStringLiteral(PyScriptParser::StringLiteralContext *ctx) override;
    virtual antlrcpp::Any visitBooleanLiteral(PyScriptParser::BooleanLiteralContext *ctx) override;
    virtual antlrcpp::Any visitNullLiteral(PyScriptParser::NullLiteralContext *ctx) override;
    virtual antlrcpp::Any visitListLiteral(PyScriptParser::ListLiteralContext *ctx) override;
    virtual antlrcpp::Any visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) override;
    
public:
    // 类型转换和检查
    bool isTruthy(std::shared_ptr<ScriptValue> value);
    std::string valueToString(std::shared_ptr<ScriptValue> value);
    double valueToNumber(std::shared_ptr<ScriptValue> value);
    bool valueToBool(std::shared_ptr<ScriptValue> value);
    
private:
    // 变量环境
    std::unordered_map<std::string, std::shared_ptr<ScriptValue>> variables_;
    
    // 导入的模块缓存
    std::unordered_map<std::string, py::object> imported_modules_;
    
    // 内置模块缓存
    py::module_ builtins_;
    
    // 执行结果
    std::shared_ptr<ScriptValue> result_;
    
    // Python解释器标志
    bool python_initialized_;
    
    // 辅助方法
    std::shared_ptr<ScriptValue> evaluateExpression(PyScriptParser::ExpressionContext *ctx);
    std::shared_ptr<ScriptValue> evaluateBinaryOp(const std::string& op, 
                                                  std::shared_ptr<ScriptValue> left, 
                                                  std::shared_ptr<ScriptValue> right);
    std::shared_ptr<ScriptValue> evaluateUnaryOp(const std::string& op, 
                                                 std::shared_ptr<ScriptValue> value);
    
    // Python集成方法
    std::shared_ptr<ScriptValue> callPythonFunction(py::object func, 
                                                   const std::vector<std::shared_ptr<ScriptValue>>& args);
    std::shared_ptr<ScriptValue> createPythonInstance(const std::string& moduleName,
                                                     const std::string& className,
                                                     const std::vector<std::shared_ptr<ScriptValue>>& args);
    std::shared_ptr<ScriptValue> scriptValueToPyObject(std::shared_ptr<ScriptValue> value);
    std::shared_ptr<ScriptValue> pyObjectToScriptValue(py::object obj);
    
    // 错误处理
    void reportError(const std::string& message, antlr4::ParserRuleContext *ctx = nullptr);
    
    // 当前错误标志
    bool has_error_;
};

#endif // SCRIPT_INTERPRETER_H
