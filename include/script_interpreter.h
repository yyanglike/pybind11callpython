#include <string>
#include <optional>
#include <ostream>

// 错误类型枚举
enum class ScriptErrorType {
    Syntax,
    Runtime,
    Type,
    Python,
    Unknown
};

// 错误码枚举
enum class ScriptErrorCode {
    None,
    InvalidSyntax,
    VariableNotDefined,
    TypeMismatch,
    PythonException,
    UnsupportedOperation,
    FileNotFound,
    Unknown
};

// 错误对象
struct ScriptError {
    ScriptErrorType type;
    ScriptErrorCode code;
    std::string message;
    int line = -1;
    int column = -1;
    ScriptError(ScriptErrorType t, ScriptErrorCode c, const std::string& msg, int l = -1, int col = -1)
        : type(t), code(c), message(msg), line(l), column(col) {}
};
#ifndef SCRIPT_INTERPRETER_H
#define SCRIPT_INTERPRETER_H

#include <string>
#include <memory>
#include <optional>
#include "script_value.h"
#include "antlr/PyScriptVisitor.h"
#include "logger.h"
#include "error_handler.h"
#include "variable_manager.h"
#include "python_bridge.h"
#include "expression_evaluator.h"
#include "ast_visitor.h"
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

namespace py = pybind11;

namespace script_interpreter {

/**
 * @class ScriptInterpreter
 * @brief 脚本解释器主类，负责协调各个模块执行脚本
 * 
 * 该类是整个脚本解释系统的核心，负责语法解析、表达式求值、
 * Python交互等功能的协调。通过模块化设计，将不同职责分离到
 * 专门的模块中，提高代码的可维护性和可扩展性。
 */
class ScriptInterpreter : public PyScriptVisitor {
public:
    // 构造函数和析构函数
    ScriptInterpreter();
    ~ScriptInterpreter();
    
    // 执行脚本
    bool execute(const std::string& script);
    bool executeFile(const std::string& filename);
    
    // 变量管理接口
    std::shared_ptr<ScriptValue> getVariable(const std::string& name);
    void setVariable(const std::string& name, std::shared_ptr<ScriptValue> value);
    void clearEnvironment();
    
    // 日志配置
    void setLogLevel(LogLevel level) { logger_.setLevel(level); }
    void setLogOutput(std::ostream& os) { logger_.setOutput(os); }
    
    // 执行结果获取
    std::shared_ptr<ScriptValue> getResult() const { return result_; }
    
    // 错误处理接口
    bool hasError() const { return error_handler_.hasError(); }
    std::string getErrorMessage() const { return error_handler_.getErrorMessage(); }
    std::optional<ScriptError> getLastError() const { return error_handler_.getLastError(); }
    std::vector<ScriptError> getAllErrors() const { return error_handler_.getAllErrors(); }
    
    // Visitor接口实现 - 根据新的语法规则更新
    std::any visitProgram(PyScriptParser::ProgramContext *ctx) override;
    std::any visitStatement(PyScriptParser::StatementContext *ctx) override;
    std::any visitSimpleStatement(PyScriptParser::SimpleStatementContext *ctx) override;
    std::any visitSmallStatement(PyScriptParser::SmallStatementContext *ctx) override;
    std::any visitCompoundStatement(PyScriptParser::CompoundStatementContext *ctx) override;
    std::any visitSimpleImport(PyScriptParser::SimpleImportContext *ctx) override;
    std::any visitFromImport(PyScriptParser::FromImportContext *ctx) override;
    std::any visitImportItem(PyScriptParser::ImportItemContext *ctx) override;
    std::any visitFunctionDef(PyScriptParser::FunctionDefContext *ctx) override;
    std::any visitParameterList(PyScriptParser::ParameterListContext *ctx) override;
    std::any visitParameter(PyScriptParser::ParameterContext *ctx) override;
    std::any visitIfStatement(PyScriptParser::IfStatementContext *ctx) override;
    std::any visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) override;
    std::any visitForStatement(PyScriptParser::ForStatementContext *ctx) override;
    std::any visitPassStatement(PyScriptParser::PassStatementContext *ctx) override;
    std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) override;
    std::any visitSuite(PyScriptParser::SuiteContext *ctx) override;
    std::any visitAssignment(PyScriptParser::AssignmentContext *ctx) override;
    std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) override;
    std::any visitExpression(PyScriptParser::ExpressionContext *ctx) override;
    std::any visitLogicalOr(PyScriptParser::LogicalOrContext *ctx) override;
    std::any visitLogicalAnd(PyScriptParser::LogicalAndContext *ctx) override;
    std::any visitEquality(PyScriptParser::EqualityContext *ctx) override;
    std::any visitComparison(PyScriptParser::ComparisonContext *ctx) override;
    std::any visitAdditive(PyScriptParser::AdditiveContext *ctx) override;
    std::any visitMultiplicative(PyScriptParser::MultiplicativeContext *ctx) override;
    std::any visitUnary(PyScriptParser::UnaryContext *ctx) override;
    std::any visitPrimary(PyScriptParser::PrimaryContext *ctx) override;
    std::any visitNewExpression(PyScriptParser::NewExpressionContext *ctx) override;
    std::any visitAtom(PyScriptParser::AtomContext *ctx) override;
    std::any visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) override;
    std::any visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) override;
    std::any visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) override;
    std::any visitAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) override;
    std::any visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) override;
    std::any visitFunctionCall(PyScriptParser::FunctionCallContext *ctx) override;
    std::any visitArgumentList(PyScriptParser::ArgumentListContext *ctx) override;
    std::any visitArgument(PyScriptParser::ArgumentContext *ctx) override;
    std::any visitListLiteral(PyScriptParser::ListLiteralContext *ctx) override;
    std::any visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) override;
    std::any visitDictItem(PyScriptParser::DictItemContext *ctx) override;
    std::any visitLiteral(PyScriptParser::LiteralContext *ctx) override;
    std::any visitListElements(PyScriptParser::ListElementsContext *ctx) override;
    std::any visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) override;
    std::any visitDottedName(PyScriptParser::DottedNameContext *ctx) override;
    std::any visitPower(PyScriptParser::PowerContext *ctx) override;
    std::any visitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) override;
    std::any visitTryStatement(PyScriptParser::TryStatementContext *ctx) override;
    std::any visitExceptClause(PyScriptParser::ExceptClauseContext *ctx) override;
    
    // 以下方法在新的语法中可能不存在，提供空实现或移除
    // 注意：这些方法在生成的Visitor中可能不存在，我们需要检查
    // 暂时保留但标记为未使用
    // std::any visitForControl(PyScriptParser::ForControlContext *ctx) override;
    // std::any visitForInit(PyScriptParser::ForInitContext *ctx) override;
    // std::any visitForUpdate(PyScriptParser::ForUpdateContext *ctx) override;
    // std::any visitPositionalArgument(PyScriptParser::PositionalArgumentContext *ctx) override;
    // std::any visitKeywordArgument(PyScriptParser::KeywordArgumentContext *ctx) override;
    // std::any visitStarArgument(PyScriptParser::StarArgumentContext *ctx) override;
    // std::any visitDoubleStarArgument(PyScriptParser::DoubleStarArgumentContext *ctx) override;
    // std::any visitNonAssignmentExpression(PyScriptParser::NonAssignmentExpressionContext *ctx) override;
    // std::any visitPowerExpression(PyScriptParser::PowerExpressionContext *ctx) override;

private:
    // 模块化组件
    Logger logger_;                    ///< 日志记录器
    ErrorHandler error_handler_;       ///< 错误处理器
    VariableManager variable_manager_; ///< 变量管理器
    PythonBridge python_bridge_;       ///< Python桥接器
    AstVisitor ast_visitor_;           ///< AST访问器
    
    // 执行状态
    std::shared_ptr<ScriptValue> result_; ///< 执行结果
    bool defining_function_;               ///< 是否正在定义函数
    
    // 辅助方法
    void reportError(const std::string& message,
                    ScriptErrorType type = ScriptErrorType::Runtime,
                    ScriptErrorCode code = ScriptErrorCode::Unknown,
                    int line = -1, int column = -1);
    void reportError(const std::string& message, antlr4::ParserRuleContext *ctx,
                    ScriptErrorType type = ScriptErrorType::Runtime,
                    ScriptErrorCode code = ScriptErrorCode::Unknown);
    
    // 表达式求值引擎
    ExpressionEvaluator expression_evaluator_;
    
    // 表达式求值辅助方法（委托给expression_evaluator_）
    std::shared_ptr<ScriptValue> evaluateExpression(PyScriptParser::ExpressionContext *ctx);
    std::shared_ptr<ScriptValue> executeSuite(PyScriptParser::SuiteContext *ctx);
};

} // namespace script_interpreter

#endif // SCRIPT_INTERPRETER_H
