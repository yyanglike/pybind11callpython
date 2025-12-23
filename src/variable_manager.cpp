/**
 * @file variable_manager.cpp
 * @brief 变量管理模块实现
 */

#include "variable_manager.h"
#include "script_value.h"
#include <algorithm>

namespace script_interpreter {

VariableManager::VariableManager() : builtins_(py::none()) {}

void VariableManager::setVariable(const std::string& name, std::shared_ptr<ScriptValue> value) {
    variables_[name] = value;
}

std::shared_ptr<ScriptValue> VariableManager::getVariable(const std::string& name) const {
    auto it = variables_.find(name);
    if (it != variables_.end()) {
        return it->second;
    }
    return nullptr;
}

bool VariableManager::hasVariable(const std::string& name) const {
    return variables_.find(name) != variables_.end();
}

bool VariableManager::removeVariable(const std::string& name) {
    auto it = variables_.find(name);
    if (it != variables_.end()) {
        variables_.erase(it);
        return true;
    }
    return false;
}

void VariableManager::importModule(const std::string& moduleName, py::module_ module) {
    imported_modules_[moduleName] = module;
}

py::module_ VariableManager::getModule(const std::string& moduleName) const {
    auto it = imported_modules_.find(moduleName);
    if (it != imported_modules_.end()) {
        return it->second;
    }
    return py::module_(); // 返回空模块对象
}

bool VariableManager::hasModule(const std::string& moduleName) const {
    return imported_modules_.find(moduleName) != imported_modules_.end();
}

void VariableManager::clearVariables() {
    variables_.clear();
}

void VariableManager::clearModules() {
    imported_modules_.clear();
}

void VariableManager::clearAll() {
    clearVariables();
    clearModules();
    builtins_ = py::none();
}

std::vector<std::string> VariableManager::getAllVariableNames() const {
    std::vector<std::string> names;
    names.reserve(variables_.size());
    for (const auto& kv : variables_) {
        names.push_back(kv.first);
    }
    std::sort(names.begin(), names.end());
    return names;
}

std::vector<std::string> VariableManager::getAllModuleNames() const {
    std::vector<std::string> names;
    names.reserve(imported_modules_.size());
    for (const auto& kv : imported_modules_) {
        names.push_back(kv.first);
    }
    std::sort(names.begin(), names.end());
    return names;
}

size_t VariableManager::getVariableCount() const {
    return variables_.size();
}

size_t VariableManager::getModuleCount() const {
    return imported_modules_.size();
}

void VariableManager::setBuiltins(py::object builtins) {
    builtins_ = builtins;
}

py::object VariableManager::getBuiltins() const {
    return builtins_;
}

bool VariableManager::hasBuiltins() const {
    return !builtins_.is_none();
}

} // namespace script_interpreter
