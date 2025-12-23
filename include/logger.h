#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <mutex>

enum class LogLevel {
    Debug = 0,
    Info,
    Warn,
    Error,
    Off
};

class Logger {
public:
    Logger() : level_(LogLevel::Info), out_(&std::cerr) {}

    void setLevel(LogLevel level) { level_ = level; }
    LogLevel getLevel() const { return level_; }

    void setOutput(std::ostream& os) { std::lock_guard<std::mutex> lk(mu_); out_ = &os; }

    void log(LogLevel lvl, const std::string& message) {
        if (lvl < level_ || level_ == LogLevel::Off) return;
        std::lock_guard<std::mutex> lk(mu_);
        (*out_) << '[' << levelToString(lvl) << "] " << message << std::endl;
    }

    void debug(const std::string& msg) { log(LogLevel::Debug, msg); }
    void info(const std::string& msg) { log(LogLevel::Info, msg); }
    void warn(const std::string& msg) { log(LogLevel::Warn, msg); }
    void error(const std::string& msg) { log(LogLevel::Error, msg); }

private:
    const char* levelToString(LogLevel lvl) const {
        switch (lvl) {
            case LogLevel::Debug: return "DEBUG";
            case LogLevel::Info: return "INFO";
            case LogLevel::Warn: return "WARN";
            case LogLevel::Error: return "ERROR";
            default: return "UNKNOWN";
        }
    }

    LogLevel level_;
    std::ostream* out_;
    std::mutex mu_;
};
