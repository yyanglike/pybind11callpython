/**
 * @file error_handler.h
 * @brief 错误处理模块，负责统一的错误报告和处理
 * 
 * 该模块提供了一套完整的错误处理机制，包括错误类型定义、
 * 错误信息收集、错误报告和日志记录等功能。
 */

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <optional>

namespace script_interpreter {

/**
 * @enum ScriptErrorType
 * @brief 脚本错误类型
 */
enum class ScriptErrorType {
    Syntax,     ///< 语法错误
    Semantic,   ///< 语义错误
    Runtime,    ///< 运行时错误
    Python,     ///< Python相关错误
    System      ///< 系统错误
};

/**
 * @enum ScriptErrorCode
 * @brief 脚本错误代码
 */
enum class ScriptErrorCode {
    Unknown,                ///< 未知错误
    InvalidSyntax,          ///< 无效语法
    UndefinedIdentifier,    ///< 未定义标识符
    TypeMismatch,           ///< 类型不匹配
    DivisionByZero,         ///< 除以零
    OutOfBounds,            ///< 下标越界
    PythonException,        ///< Python异常
    UnsupportedOperation,   ///< 不支持的操作
    FileNotFound,           ///< 文件未找到
    ImportError,            ///< 导入错误
    MaxErrorCode            ///< 最大错误代码（用于边界检查）
};

/**
 * @class ScriptError
 * @brief 脚本错误信息类
 * 
 * 封装了错误的详细信息，包括错误类型、错误代码、错误消息、
 * 发生位置（行号和列号）等。
 */
class ScriptError {
public:
    /**
     * @brief 构造函数
     * @param type 错误类型
     * @param code 错误代码
     * @param message 错误消息
     * @param line 行号（默认-1表示未知）
     * @param column 列号（默认-1表示未知）
     */
    ScriptError(ScriptErrorType type, 
                ScriptErrorCode code, 
                const std::string& message,
                int line = -1,
                int column = -1);
    
    /**
     * @brief 获取错误类型
     * @return 错误类型
     */
    ScriptErrorType getType() const { return type_; }
    
    /**
     * @brief 获取错误代码
     * @return 错误代码
     */
    ScriptErrorCode getCode() const { return code_; }
    
    /**
     * @brief 获取错误消息
     * @return 错误消息
     */
    const std::string& getMessage() const { return message_; }
    
    /**
     * @brief 获取行号
     * @return 行号，-1表示未知
     */
    int getLine() const { return line_; }
    
    /**
     * @brief 获取列号
     * @return 列号，-1表示未知
     */
    int getColumn() const { return column_; }
    
    /**
     * @brief 获取完整的错误信息字符串
     * @return 格式化的错误信息
     */
    std::string toString() const;
    
    /**
     * @brief 检查是否发生在特定位置
     * @return 如果有位置信息返回true，否则false
     */
    bool hasLocation() const { return line_ >= 0 && column_ >= 0; }
    
private:
    ScriptErrorType type_;      ///< 错误类型
    ScriptErrorCode code_;      ///< 错误代码
    std::string message_;       ///< 错误消息
    int line_;                  ///< 行号
    int column_;                ///< 列号
};

/**
 * @class ErrorHandler
 * @brief 错误处理器类
 * 
 * 负责收集、管理和报告错误信息，提供错误状态查询和错误信息
 * 获取功能。支持链式错误报告。
 */
class ErrorHandler {
public:
    ErrorHandler();
    
    /**
     * @brief 报告错误
     * @param error 错误对象
     */
    void reportError(const ScriptError& error);
    
    /**
     * @brief 报告错误（便捷方法）
     * @param message 错误消息
     * @param type 错误类型（默认Runtime）
     * @param code 错误代码（默认Unknown）
     * @param line 行号（默认-1）
     * @param column 列号（默认-1）
     */
    void reportError(const std::string& message,
                    ScriptErrorType type = ScriptErrorType::Runtime,
                    ScriptErrorCode code = ScriptErrorCode::Unknown,
                    int line = -1,
                    int column = -1);
    
    /**
     * @brief 检查是否有错误发生
     * @return 如果有错误返回true，否则false
     */
    bool hasError() const { return has_error_; }
    
    /**
     * @brief 获取最后一个错误
     * @return 最后一个错误对象，如果没有错误返回std::nullopt
     */
    std::optional<ScriptError> getLastError() const;
    
    /**
     * @brief 获取错误消息
     * @return 最后一个错误的错误消息，如果没有错误返回空字符串
     */
    std::string getErrorMessage() const;
    
    /**
     * @brief 获取所有错误
     * @return 所有错误对象的向量
     */
    std::vector<ScriptError> getAllErrors() const { return errors_; }
    
    /**
     * @brief 清除所有错误
     */
    void clearErrors();
    
    /**
     * @brief 获取错误数量
     * @return 错误数量
     */
    size_t getErrorCount() const { return errors_.size(); }
    
private:
    bool has_error_;                    ///< 是否有错误发生
    std::vector<ScriptError> errors_;   ///< 错误列表
};

} // namespace script_interpreter
