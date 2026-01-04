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
#include <unordered_map>
#include <functional>
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
    
    // Visitor接口实现（根据生成的PyScriptVisitor.h更新）
    std::any visitProgram(PyScriptParser::ProgramContext *ctx) override;
    std::any visitStatement(PyScriptParser::StatementContext *ctx) override;
    std::any visitSimpleStatement(PyScriptParser::SimpleStatementContext *ctx) override;
    std::any visitSmallStatement(PyScriptParser::SmallStatementContext *ctx) override;
    std::any visitCompoundStatement(PyScriptParser::CompoundStatementContext *ctx) override;
    std::any visitSuite(PyScriptParser::SuiteContext *ctx) override;
    std::any visitFunctionDef(PyScriptParser::FunctionDefContext *ctx) override;
    std::any visitParameterList(PyScriptParser::ParameterListContext *ctx) override;
    std::any visitParameter(PyScriptParser::ParameterContext *ctx) override;
    std::any visitTryStatement(PyScriptParser::TryStatementContext *ctx) override;
    std::any visitExceptClause(PyScriptParser::ExceptClauseContext *ctx) override;
    std::any visitIfStatement(PyScriptParser::IfStatementContext *ctx) override;
    std::any visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) override;
    std::any visitForStatement(PyScriptParser::ForStatementContext *ctx) override;
    std::any visitPassStatement(PyScriptParser::PassStatementContext *ctx) override;
    std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) override;
    std::any visitRaiseStatement(PyScriptParser::RaiseStatementContext *ctx) override;
    std::any visitDelStatement(PyScriptParser::DelStatementContext *ctx) override;
    std::any visitDelTargets(PyScriptParser::DelTargetsContext *ctx) override;
    std::any visitDelVariable(PyScriptParser::DelVariableContext *ctx) override;
    std::any visitDelAttribute(PyScriptParser::DelAttributeContext *ctx) override;
    std::any visitDelSubscript(PyScriptParser::DelSubscriptContext *ctx) override;
    std::any visitGlobalStatement(PyScriptParser::GlobalStatementContext *ctx) override;
    std::any visitNonlocalStatement(PyScriptParser::NonlocalStatementContext *ctx) override;
    std::any visitAssertStatement(PyScriptParser::AssertStatementContext *ctx) override;
    std::any visitYieldExpr(PyScriptParser::YieldExprContext *ctx) override;
    std::any visitWalrusExpr(PyScriptParser::WalrusExprContext *ctx) override;
    std::any visitYieldExpression(PyScriptParser::YieldExpressionContext *ctx) override;
    std::any visitAssignmentExpr(PyScriptParser::AssignmentExprContext *ctx) override;
    std::any visitSimpleImport(PyScriptParser::SimpleImportContext *ctx) override;
    std::any visitFromImport(PyScriptParser::FromImportContext *ctx) override;
    std::any visitImportItem(PyScriptParser::ImportItemContext *ctx) override;
    std::any visitAssignment(PyScriptParser::AssignmentContext *ctx) override;
    std::any visitAssignmentTarget(PyScriptParser::AssignmentTargetContext *ctx) override;
    std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) override;
    std::any visitExpression(PyScriptParser::ExpressionContext *ctx);
    std::any visitConditionalExpr(PyScriptParser::ConditionalExprContext *ctx) override;
    std::any visitConditional(PyScriptParser::ConditionalContext *ctx) override;
    std::any visitLogicalOr(PyScriptParser::LogicalOrContext *ctx) override;
    std::any visitLogicalAnd(PyScriptParser::LogicalAndContext *ctx) override;
    std::any visitBitwiseOrExpr(PyScriptParser::BitwiseOrExprContext *ctx) override;
    std::any visitBitwiseXorExpr(PyScriptParser::BitwiseXorExprContext *ctx) override;
    std::any visitBitwiseAndExpr(PyScriptParser::BitwiseAndExprContext *ctx) override;
    std::any visitEquality(PyScriptParser::EqualityContext *ctx) override;
    std::any visitComparison(PyScriptParser::ComparisonContext *ctx) override;
    std::any visitShiftExpr(PyScriptParser::ShiftExprContext *ctx) override;
    std::any visitAdditive(PyScriptParser::AdditiveContext *ctx) override;
    std::any visitMultiplicative(PyScriptParser::MultiplicativeContext *ctx) override;
    std::any visitPower(PyScriptParser::PowerContext *ctx) override;
    std::any visitUnary(PyScriptParser::UnaryContext *ctx) override;
    std::any visitPrimary(PyScriptParser::PrimaryContext *ctx) override;
    std::any visitMultiElementTuple(PyScriptParser::MultiElementTupleContext *ctx) override;
    std::any visitSingleElementTuple(PyScriptParser::SingleElementTupleContext *ctx) override;
    std::any visitNewExpression(PyScriptParser::NewExpressionContext *ctx) override;
    std::any visitAtom(PyScriptParser::AtomContext *ctx) override;
    std::any visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) override;
    std::any visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) override;
    std::any visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) override;
    std::any visitArgumentList(PyScriptParser::ArgumentListContext *ctx) override;
    std::any visitArgument(PyScriptParser::ArgumentContext *ctx) override;
    std::any visitListLiteral(PyScriptParser::ListLiteralContext *ctx) override;
    std::any visitListElements(PyScriptParser::ListElementsContext *ctx) override;
    std::any visitComprehension(PyScriptParser::ComprehensionContext *ctx) override;
    std::any visitCompFor(PyScriptParser::CompForContext *ctx) override;
    std::any visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) override;
    std::any visitDictComprehension(PyScriptParser::DictComprehensionContext *ctx) override;
    std::any visitDictItem(PyScriptParser::DictItemContext *ctx) override;
    std::any visitSetLiteral(PyScriptParser::SetLiteralContext *ctx) override;
    std::any visitSetElements(PyScriptParser::SetElementsContext *ctx) override;
    std::any visitGeneratorExpression(PyScriptParser::GeneratorExpressionContext *ctx) override;
    std::any visitLiteral(PyScriptParser::LiteralContext *ctx) override;
    std::any visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) override;
    std::any visitDottedName(PyScriptParser::DottedNameContext *ctx) override;
    std::any visitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) override;
    std::any visitWithStatement(PyScriptParser::WithStatementContext *ctx) override;
    std::any visitWithItem(PyScriptParser::WithItemContext *ctx) override;
    std::any visitAsyncFunctionDef(PyScriptParser::AsyncFunctionDefContext *ctx) override;
    std::any visitAsyncForStatement(PyScriptParser::AsyncForStatementContext *ctx) override;
    std::any visitAsyncWithStatement(PyScriptParser::AsyncWithStatementContext *ctx) override;
    std::any visitAwaitExpr(PyScriptParser::AwaitExprContext *ctx) override;
    std::any visitClassDef(PyScriptParser::ClassDefContext *ctx) override;
    std::any visitDecorators(PyScriptParser::DecoratorsContext *ctx) override;
    std::any visitDecorator(PyScriptParser::DecoratorContext *ctx) override;
    std::any visitDecoratedDef(PyScriptParser::DecoratedDefContext *ctx) override;
    
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
    std::shared_ptr<ScriptValue> executeSuite(PyScriptParser::SuiteContext *ctx);
    
    /**
     * @brief 获取性能计数器统计信息
     * @return 计数器统计字符串
     */
    std::string getPerformanceStats() const;
    
    /**
     * @brief 重置性能计数器
     */
    void resetPerformanceStats();
    
    /**
     * @brief 重置访问者状态（用于多次执行之间）
     * 
     * 清除所有执行状态标志、缓存和临时数据，确保每次执行都是独立的。
     * 应该在每次脚本执行前调用。
     */
    void resetState();
    
    /**
     * @brief 启用/禁用函数/类定义缓存
     * @param enabled 是否启用缓存
     */
    void setCacheEnabled(bool enabled) { cache_enabled_ = enabled; }
    
    /**
     * @brief 获取缓存启用状态
     * @return 是否启用缓存
     */
    bool isCacheEnabled() const { return cache_enabled_; }
    
    /**
     * @brief 清空缓存
     */
    void clearCache() { exec_cache_.clear(); }
    
    /**
     * @brief 检查节点是否在函数定义体内（通过行号范围）
     * @param ctx 解析器规则上下文
     * @return 如果节点在函数定义体内返回 true，否则返回 false
     */
    bool isNodeInsideFunctionDef(antlr4::ParserRuleContext* ctx) const;
    
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
    bool break_flag_;                      ///< break标志（用于循环控制）
    bool continue_flag_;                    ///< continue标志（用于循环控制）
    
    // 性能计数器（用于优化分析）
    mutable std::atomic<size_t> py_call_count_{0};           ///< Python函数调用次数
    mutable std::atomic<size_t> sv_to_py_count_{0};          ///< ScriptValue->py::object转换次数
    mutable std::atomic<size_t> py_to_sv_count_{0};          ///< py::object->ScriptValue转换次数
    mutable std::atomic<size_t> iter_direct_count_{0};        ///< 直接迭代次数（快路径）
    mutable std::atomic<size_t> iter_py_count_{0};            ///< Python迭代次数（慢路径）
    
    // 函数/类定义执行结果缓存（基于源代码哈希）
    bool cache_enabled_{true};                                 ///< 缓存开关（默认启用）
    std::unordered_map<size_t, py::object> exec_cache_;      ///< 缓存 py::exec 的结果（完整路径：源代码+变量状态）
    std::unordered_map<size_t, py::object> exec_cache_source_; ///< 源代码缓存（快速路径：仅源代码）
    std::unordered_map<std::string, size_t> source_hash_cache_; ///< 源代码哈希缓存（避免重复计算）
    mutable std::atomic<size_t> exec_cache_hits_{0};          ///< 缓存命中次数
    mutable std::atomic<size_t> exec_cache_misses_{0};        ///< 缓存未命中次数
    
    // 缓存的模块（避免重复导入）
    py::object builtins_module_;                               ///< 缓存的 builtins 模块
    py::object sys_module_;                                    ///< 缓存的 sys 模块
    
    // 延迟缓存策略：跟踪函数定义次数
    std::unordered_map<std::string, size_t> func_def_count_;  ///< 函数定义次数计数器
    
    // 缓存的变量/模块名列表（避免重复创建和排序）
    mutable std::vector<std::string> cached_var_names_;      ///< 缓存的变量名列表
    mutable std::vector<std::string> cached_module_names_;    ///< 缓存的模块名列表
    mutable size_t cached_var_count_{0};                      ///< 缓存的变量数量（用于失效检测）
    mutable size_t cached_module_count_{0};                   ///< 缓存的模块数量（用于失效检测）
    
    // 函数定义的行号范围（用于检测节点是否在函数体内）
    struct FunctionRange {
        int start_line;
        int end_line;
    };
    std::unordered_map<std::string, FunctionRange> function_ranges_;  ///< 函数名到行号范围的映射

    
    /**
     * @brief 处理切片参数
     * @param ctx 切片参数上下文
     * @param target 目标对象
     * @return 切片访问结果
     */
    std::shared_ptr<ScriptValue> visitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx, 
                                                  std::shared_ptr<ScriptValue> target);
    
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
    
    /**
     * @brief 递归获取赋值目标的对象引用（用于嵌套赋值，如 a.b.c.d = 0）
     * @param ctx 赋值目标上下文
     * @return 对象引用（不是值）
     */
    std::shared_ptr<ScriptValue> getObjectReferenceForAssignment(PyScriptParser::AssignmentTargetContext *ctx);

private:
    py::object current_from_module_; ///< 当前from-import正在导入的模块
};

} // namespace script_interpreter
