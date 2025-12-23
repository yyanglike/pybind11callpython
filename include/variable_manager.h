/**
 * @file variable_manager.h
 * @brief 变量管理模块，负责变量和模块的存储、查找和管理
 * 
 * 该模块提供了变量和模块的存储管理功能，支持变量的增删改查，
 * 模块的导入和缓存，以及作用域管理（未来扩展）。
 */

#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <optional>
#include <pybind11/pybind11.h>

namespace py = pybind11;

class ScriptValue;

namespace script_interpreter {

/**
 * @class VariableManager
 * @brief 变量管理器类
 * 
 * 负责管理脚本执行过程中的变量和导入的Python模块。
 * 提供变量和模块的存储、查找、更新和删除功能。
 */
class VariableManager {
public:
    VariableManager();
    
    /**
     * @brief 设置变量
     * @param name 变量名
     * @param value 变量值
     */
    void setVariable(const std::string& name, std::shared_ptr<ScriptValue> value);
    
    /**
     * @brief 获取变量
     * @param name 变量名
     * @return 变量值，如果不存在返回nullptr
     */
    std::shared_ptr<ScriptValue> getVariable(const std::string& name) const;
    
    /**
     * @brief 检查变量是否存在
     * @param name 变量名
     * @return 如果存在返回true，否则false
     */
    bool hasVariable(const std::string& name) const;
    
    /**
     * @brief 删除变量
     * @param name 变量名
     * @return 如果成功删除返回true，如果变量不存在返回false
     */
    bool removeVariable(const std::string& name);
    
    /**
     * @brief 导入Python模块
     * @param moduleName 模块名
     * @param module Python模块对象
     */
    void importModule(const std::string& moduleName, py::module_ module);
    
    /**
     * @brief 获取导入的Python模块
     * @param moduleName 模块名
     * @return Python模块对象，如果不存在返回空对象
     */
    py::module_ getModule(const std::string& moduleName) const;
    
    /**
     * @brief 检查模块是否已导入
     * @param moduleName 模块名
     * @return 如果已导入返回true，否则false
     */
    bool hasModule(const std::string& moduleName) const;
    
    /**
     * @brief 清空所有变量（保留导入的模块）
     */
    void clearVariables();
    
    /**
     * @brief 清空所有模块
     */
    void clearModules();
    
    /**
     * @brief 清空所有变量和模块
     */
    void clearAll();
    
    /**
     * @brief 获取所有变量名
     * @return 变量名列表
     */
    std::vector<std::string> getAllVariableNames() const;
    
    /**
     * @brief 获取所有模块名
     * @return 模块名列表
     */
    std::vector<std::string> getAllModuleNames() const;
    
    /**
     * @brief 获取变量数量
     * @return 变量数量
     */
    size_t getVariableCount() const;
    
    /**
     * @brief 获取模块数量
     * @return 模块数量
     */
    size_t getModuleCount() const;
    
    /**
     * @brief 设置内置Python模块（如builtins）
     * @param builtins 内置模块对象
     */
    void setBuiltins(py::object builtins);
    
    /**
     * @brief 获取内置Python模块
     * @return 内置模块对象
     */
    py::object getBuiltins() const;
    
    /**
     * @brief 检查是否设置了内置模块
     * @return 如果已设置返回true，否则false
     */
    bool hasBuiltins() const;
    
private:
    // 变量存储
    std::unordered_map<std::string, std::shared_ptr<ScriptValue>> variables_;
    
    // 导入的Python模块存储
    std::unordered_map<std::string, py::module_> imported_modules_;
    
    // 内置Python模块（如builtins）
    py::object builtins_;
};

} // namespace script_interpreter
