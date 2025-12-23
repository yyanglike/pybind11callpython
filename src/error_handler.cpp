/**
 * @file error_handler.cpp
 * @brief 错误处理模块实现
 */

#include "error_handler.h"
#include <sstream>

namespace script_interpreter {

// ScriptError 实现

ScriptError::ScriptError(ScriptErrorType type, 
                         ScriptErrorCode code, 
                         const std::string& message,
                         int line,
                         int column)
    : type_(type), code_(code), message_(message), line_(line), column_(column) {}

std::string ScriptError::toString() const {
    std::ostringstream oss;
    
    // 添加错误类型
    switch (type_) {
        case ScriptErrorType::Syntax:
            oss << "[Syntax Error] ";
            break;
        case ScriptErrorType::Semantic:
            oss << "[Semantic Error] ";
            break;
        case ScriptErrorType::Runtime:
            oss << "[Runtime Error] ";
            break;
        case ScriptErrorType::Python:
            oss << "[Python Error] ";
            break;
        case ScriptErrorType::System:
            oss << "[System Error] ";
            break;
        default:
            oss << "[Error] ";
            break;
    }
    
    // 添加位置信息（如果有）
    if (hasLocation()) {
        oss << "at line " << line_ << ", column " << column_ << ": ";
    }
    
    // 添加错误消息
    oss << message_;
    
    return oss.str();
}

// ErrorHandler 实现

ErrorHandler::ErrorHandler() : has_error_(false) {}

void ErrorHandler::reportError(const ScriptError& error) {
    errors_.push_back(error);
    has_error_ = true;
}

void ErrorHandler::reportError(const std::string& message,
                              ScriptErrorType type,
                              ScriptErrorCode code,
                              int line,
                              int column) {
    reportError(ScriptError(type, code, message, line, column));
}

std::optional<ScriptError> ErrorHandler::getLastError() const {
    if (errors_.empty()) {
        return std::nullopt;
    }
    return errors_.back();
}

std::string ErrorHandler::getErrorMessage() const {
    auto lastError = getLastError();
    if (lastError) {
        return lastError->toString();
    }
    return "";
}

void ErrorHandler::clearErrors() {
    errors_.clear();
    has_error_ = false;
}

} // namespace script_interpreter
