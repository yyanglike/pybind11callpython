/**
 * @file expression_evaluator.h
 * @brief 表达式求值引擎模块
 * 
 * 该模块负责所有表达式的求值操作，包括：
 * - 二元运算（加减乘除、比较、逻辑运算等）
 * - 一元运算（负号、逻辑非等）
 * - 真值判断
 * - 表达式求值
 * - 代码块执行
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
#include "antlr/PyScriptParser.h"

namespace py = pybind11;

namespace antlr4 {
namespace tree {
class ParseTree;
}
}

namespace script_interpreter {

/**
 * @class ExpressionEvaluator
 * @brief 表达式求值引擎类
 * 
 * 封装所有表达式求值相关的逻辑，提供独立的表达式求值服务。
 * 与具体的语法解析器解耦，专注于表达式的计算。
 */
class ExpressionEvaluator {
public:
    /**
     * @brief 构造函数
     * @param variable_manager 变量管理器引用
     * @param error_handler 错误处理器引用
     * @param logger 日志记录器引用
     * @param python_bridge Python桥接器引用
     */
    ExpressionEvaluator(VariableManager& variable_manager,
                       ErrorHandler& error_handler,
                       Logger& logger,
                       PythonBridge& python_bridge);
    
    /**
     * @brief 求值二元运算
     * @param op 操作符字符串
     * @param left 左操作数
     * @param right 右操作数
     * @return 运算结果，如果出错返回nullptr
     */
    std::shared_ptr<ScriptValue> evaluateBinaryOperation(
        const std::string& op,
        std::shared_ptr<ScriptValue> left,
        std::shared_ptr<ScriptValue> right);
    
    /**
     * @brief 求值一元运算
     * @param op 操作符字符串
     * @param value 操作数
     * @return 运算结果，如果出错返回nullptr
     */
    std::shared_ptr<ScriptValue> evaluateUnaryOperation(
        const std::string& op,
        std::shared_ptr<ScriptValue> value);
    
    /**
     * @brief 判断值的真值性
     * @param value 要判断的值
     * @return 如果值为真返回true，否则false
     */
    bool isTruthy(std::shared_ptr<ScriptValue> value) const;
    
    /**
     * @brief 求值表达式上下文
     * @param ctx 表达式上下文
     * @return 表达式求值结果，封装为any
     */
    std::any evaluateExpression(PyScriptParser::ExpressionContext* ctx);
    
    /**
     * @brief 执行代码块
     * @param ctx 代码块上下文
     * @return 代码块中最后一条语句的值
     */
    std::shared_ptr<ScriptValue> executeBlock(PyScriptParser::BlockContext* ctx);
    
    /**
     * @brief 获取变量管理器引用
     * @return 变量管理器引用
     */
    VariableManager& getVariableManager() { return variable_manager_; }
    
    /**
     * @brief 获取错误处理器引用
     * @return 错误处理器引用
     */
    ErrorHandler& getErrorHandler() { return error_handler_; }
    
    /**
     * @brief 获取日志记录器引用
     * @return 日志记录器引用
     */
    Logger& getLogger() { return logger_; }
    
    /**
     * @brief 获取Python桥接器引用
     * @return Python桥接器引用
     */
    PythonBridge& getPythonBridge() { return python_bridge_; }
    
private:
    VariableManager& variable_manager_;
    ErrorHandler& error_handler_;
    Logger& logger_;
    PythonBridge& python_bridge_;
    
    /**
     * @brief 报告错误
     * @param message 错误消息
     * @param line 行号（可选）
     * @param column 列号（可选）
     */
    void reportError(const std::string& message, int line = -1, int column = -1);
};

} // namespace script_interpreter
