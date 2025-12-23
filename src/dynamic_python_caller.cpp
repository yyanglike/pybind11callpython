#include "dynamic_python_caller.h"
#include <iostream>

// Static logger for static helper methods
static Logger s_logger;

DynamicPythonCaller::DynamicPythonCaller(const std::string& moduleName, const std::string& functionName)
    : moduleName_(moduleName), functionName_(functionName) {
    if (!moduleName.empty() && !functionName.empty()) {
        importAndGetFunction();
    }
}

void DynamicPythonCaller::setModule(const std::string& moduleName) {
    moduleName_ = moduleName;
    if (!moduleName_.empty() && !functionName_.empty()) {
        importAndGetFunction();
    }
}

void DynamicPythonCaller::setFunction(const std::string& functionName) {
    functionName_ = functionName;
    if (!moduleName_.empty() && !functionName_.empty()) {
        importAndGetFunction();
    }
}

void DynamicPythonCaller::importAndGetFunction() {
    try {
        py::module_ module = py::module_::import(moduleName_.c_str());
        function_ = module.attr(functionName_.c_str());
    } catch (const py::error_already_set& e) {
        logger_.error(std::string("Error importing module/function: ") + moduleName_ + "." + functionName_);
        function_ = py::none();
    }
}

py::object DynamicPythonCaller::call(py::args args, py::kwargs kwargs) {
    if (function_.is_none()) {
        throw std::runtime_error("Function not set or not found");
    }
    return function_(*args, **kwargs);
}

py::object DynamicPythonCaller::callFunction(py::object func, py::args args, py::kwargs kwargs) {
    return func(*args, **kwargs);
}

py::object DynamicPythonCaller::getFunction() const {
    return function_;
}

bool DynamicPythonCaller::functionExists() const {
    return !function_.is_none();
}

std::string DynamicPythonCaller::getSignature() const {
    if (function_.is_none()) {
        return "Function not available";
    }
    try {
        py::module_ inspect = py::module_::import("inspect");
        py::object signature = inspect.attr("signature")(function_);
        return py::str(signature).cast<std::string>();
    } catch (const py::error_already_set& e) {
        return "Unable to get signature";
    }
}

std::vector<std::pair<std::string, std::string>> DynamicPythonCaller::getParameters() const {
    std::vector<std::pair<std::string, std::string>> params;
    if (function_.is_none()) {
        return params;
    }
    try {
        py::module_ inspect = py::module_::import("inspect");
        py::object signature = inspect.attr("signature")(function_);
        py::object parameters = signature.attr("parameters");
        
        for (auto item : parameters) {
            py::object param_name = py::reinterpret_borrow<py::object>(item);  // 键是参数名
            py::object param_obj = parameters[param_name];
            
            std::string name = param_name.cast<std::string>();
            py::object default_value = param_obj.attr("default");
            std::string default_str = "No default";
            if (!default_value.is(py::none())) {
                default_str = py::str(default_value).cast<std::string>();
            }
            params.emplace_back(name, default_str);
        }
    } catch (const py::error_already_set& e) {
        // 静默处理错误
    }
    return params;
}

std::map<std::string, py::object> DynamicPythonCaller::getDefaultValues() const {
    std::map<std::string, py::object> defaults;
    if (function_.is_none()) {
        return defaults;
    }
    try {
        py::module_ inspect = py::module_::import("inspect");
        py::object signature = inspect.attr("signature")(function_);
        py::object parameters = signature.attr("parameters");
        
        for (auto item : parameters) {
            py::object param_name = py::reinterpret_borrow<py::object>(item);  // 键是参数名
            py::object param_obj = parameters[param_name];
            
            std::string name = param_name.cast<std::string>();
            py::object default_value = param_obj.attr("default");
            if (!default_value.is(py::none())) {
                defaults[name] = default_value;
            }
        }
    } catch (const py::error_already_set& e) {
        // 静默处理错误
    }
    return defaults;
}

// ===== 新增静态方法实现 =====

py::object DynamicPythonCaller::callModuleFunction(const std::string& moduleName, 
                                                   const std::string& functionName,
                                                   py::args args, 
                                                   py::kwargs kwargs) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object func = module.attr(functionName.c_str());
        return func(*args, **kwargs);
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Failed to call module function: " + moduleName + "." + functionName + 
                                 "\nPython error: " + std::string(e.what()));
    }
}

bool DynamicPythonCaller::isCallableFunction(py::object obj) {
    try {
        // 检查是否为可调用对象
        if (!py::hasattr(obj, "__call__")) {
            return false;
        }
        
        // 排除内置函数和类型（可选，根据需求调整）
        py::module_ builtins = py::module_::import("builtins");
        py::object builtin_types = py::module_::import("types");
        
        // 获取对象类型
        py::object obj_type = py::type::of(obj);
        
        // 检查是否为内置函数或方法
        py::object builtin_function_type = builtin_types.attr("BuiltinFunctionType");
        py::object builtin_method_type = builtin_types.attr("BuiltinMethodType");
        
        if (obj_type.is(builtin_function_type) || obj_type.is(builtin_method_type)) {
            return false; // 排除内置函数和方法
        }
        
        // 检查是否为类（我们通常只想调用函数，而不是类）
        py::object class_type = py::type::of(py::module_::import("builtins").attr("object"));
        if (py::isinstance(obj, class_type)) {
            // 如果是类，检查是否有__call__（即是否是可调用的类）
            // 这里我们选择排除类，只返回普通函数
            return false;
        }
        
        return true;
    } catch (...) {
        return false;
    }
}

bool DynamicPythonCaller::isPrivateFunction(const std::string& functionName) {
    // 私有函数通常以_或__开头
    return !functionName.empty() && (functionName[0] == '_');
}

std::vector<std::string> DynamicPythonCaller::listModuleFunctions(const std::string& moduleName) {
    std::vector<std::string> functions;
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        
        // 获取模块的所有属性名
        py::list attr_names = module.attr("__dict__").attr("keys")();
        
        for (auto item : attr_names) {
            std::string name = py::str(item).cast<std::string>();
            
            // 跳过私有函数
            if (isPrivateFunction(name)) {
                continue;
            }
            
            try {
                py::object attr = module.attr(name.c_str());
                
                // 检查是否为可调用函数
                if (isCallableFunction(attr)) {
                    functions.push_back(name);
                }
            } catch (...) {
                // 如果获取属性失败，跳过
                continue;
            }
        }
        
        // 按字母顺序排序
        std::sort(functions.begin(), functions.end());
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Error listing module functions: ") + e.what());
    }
    
    return functions;
}

std::map<std::string, py::object> DynamicPythonCaller::getModuleFunctionMap(const std::string& moduleName) {
    std::map<std::string, py::object> functionMap;
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        
        // 获取模块的所有属性名
        py::list attr_names = module.attr("__dict__").attr("keys")();
        
        for (auto item : attr_names) {
            std::string name = py::str(item).cast<std::string>();
            
            // 跳过私有函数
            if (isPrivateFunction(name)) {
                continue;
            }
            
            try {
                py::object attr = module.attr(name.c_str());
                
                // 检查是否为可调用函数
                if (isCallableFunction(attr)) {
                    functionMap[name] = attr;
                }
            } catch (...) {
                // 如果获取属性失败，跳过
                continue;
            }
        }
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Error getting module function map: ") + e.what());
    }
    
    return functionMap;
}

bool DynamicPythonCaller::moduleHasFunction(const std::string& moduleName, const std::string& functionName) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        
        // 检查模块是否有该属性
        if (!py::hasattr(module, functionName.c_str())) {
            return false;
        }
        
        py::object attr = module.attr(functionName.c_str());
        
        // 检查是否为可调用函数
        return isCallableFunction(attr);
        
    } catch (const py::error_already_set& e) {
        return false;
    }
}

std::map<std::string, std::any> DynamicPythonCaller::getModuleInfo(const std::string& moduleName) {
    std::map<std::string, std::any> info;
    
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        
        // 获取模块文档
        if (py::hasattr(module, "__doc__")) {
            py::object doc = module.attr("__doc__");
            if (!doc.is_none()) {
                info["doc"] = py::str(doc).cast<std::string>();
            }
        }
        
        // 获取模块文件路径
        if (py::hasattr(module, "__file__")) {
            py::object file = module.attr("__file__");
            if (!file.is_none()) {
                info["file"] = py::str(file).cast<std::string>();
            }
        }
        
        // 获取函数列表
        std::vector<std::string> functions = listModuleFunctions(moduleName);
        info["function_count"] = static_cast<int>(functions.size());
        info["functions"] = functions;
        
        // 获取函数签名示例（取第一个函数）
        if (!functions.empty()) {
            try {
                py::object func = module.attr(functions[0].c_str());
                py::module_ inspect = py::module_::import("inspect");
                py::object signature = inspect.attr("signature")(func);
                info["example_signature"] = py::str(signature).cast<std::string>();
            } catch (...) {
                // 忽略错误
            }
        }
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Error getting module info: ") + e.what());
    }
    
    return info;
}

py::object DynamicPythonCaller::dynamicCall(const std::string& moduleName, 
                                            const std::string& functionName,
                                            py::args args, 
                                            py::kwargs kwargs) {
    return callModuleFunction(moduleName, functionName, args, kwargs);
}

std::map<std::string, py::object> DynamicPythonCaller::batchCall(const std::string& moduleName,
                                                                 const std::vector<std::string>& functionNames,
                                                                 py::args args,
                                                                 py::kwargs kwargs) {
    std::map<std::string, py::object> results;
    
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        
        for (const auto& funcName : functionNames) {
            try {
                if (moduleHasFunction(moduleName, funcName)) {
                    py::object func = module.attr(funcName.c_str());
                    py::object result = func(*args, **kwargs);
                    results[funcName] = result;
                } else {
                    // 如果函数不存在，添加一个none对象
                    results[funcName] = py::none();
                }
            } catch (const py::error_already_set& e) {
                // 函数调用失败，记录错误信息
                results[funcName] = py::str(e.what());
            }
        }
        
    } catch (const py::error_already_set& e) {
        // 模块导入失败
        for (const auto& funcName : functionNames) {
            results[funcName] = py::str("Module import failed: " + std::string(e.what()));
        }
    }
    
    return results;
}

// ===== Python类处理功能实现 =====

bool DynamicPythonCaller::isPythonClass(py::object obj) {
    try {
        // 检查是否为type类型（Python中类都是type的实例）
        py::module_ builtins = py::module_::import("builtins");
        py::object type_class = builtins.attr("type");
        
        // 使用isinstance检查是否为类
        bool is_class = py::isinstance(obj, type_class);
        
        if (!is_class) {
            return false;
        }
        
        // 进一步检查：排除内置类型如int, str等
        py::object module_name = py::getattr(obj, "__module__", py::none());
        if (!module_name.is_none()) {
            std::string module_str = py::str(module_name).cast<std::string>();
            // 排除builtins模块中的类型
            if (module_str == "builtins") {
                // 可以选择排除某些内置类型，或者全部排除
                // 这里我们排除常见的内置类型
                py::object class_name = py::getattr(obj, "__name__", py::none());
                if (!class_name.is_none()) {
                    std::string name_str = py::str(class_name).cast<std::string>();
                    // 常见内置类型
                    std::vector<std::string> builtin_types = {
                        "int", "str", "float", "bool", "list", "dict", 
                        "tuple", "set", "bytes", "bytearray", "complex"
                    };
                    for (const auto& type_name : builtin_types) {
                        if (name_str == type_name) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    } catch (...) {
        return false;
    }
}

std::vector<std::string> DynamicPythonCaller::listModuleClasses(const std::string& moduleName) {
    std::vector<std::string> classes;
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        
        // 获取模块的所有属性名
        py::list attr_names = module.attr("__dict__").attr("keys")();
        
        for (auto item : attr_names) {
            std::string name = py::str(item).cast<std::string>();
            
            // 跳过私有类
            if (isPrivateFunction(name)) {
                continue;
            }
            
            try {
                py::object attr = module.attr(name.c_str());
                
                // 检查是否为类
                if (isPythonClass(attr)) {
                    classes.push_back(name);
                }
            } catch (...) {
                // 如果获取属性失败，跳过
                continue;
            }
        }
        
        // 按字母顺序排序
        std::sort(classes.begin(), classes.end());
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Error listing module classes: ") + e.what());
    }
    
    return classes;
}

std::map<std::string, py::object> DynamicPythonCaller::getModuleClassMap(const std::string& moduleName) {
    std::map<std::string, py::object> classMap;
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        
        // 获取模块的所有属性名
        py::list attr_names = module.attr("__dict__").attr("keys")();
        
        for (auto item : attr_names) {
            std::string name = py::str(item).cast<std::string>();
            
            // 跳过私有类
            if (isPrivateFunction(name)) {
                continue;
            }
            
            try {
                py::object attr = module.attr(name.c_str());
                
                // 检查是否为类
                if (isPythonClass(attr)) {
                    classMap[name] = attr;
                }
            } catch (...) {
                // 如果获取属性失败，跳过
                continue;
            }
        }
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Error getting module class map: ") + e.what());
    }
    
    return classMap;
}

bool DynamicPythonCaller::moduleHasClass(const std::string& moduleName, const std::string& className) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        
        // 检查模块是否有该属性
        if (!py::hasattr(module, className.c_str())) {
            return false;
        }
        
        py::object attr = module.attr(className.c_str());
        
        // 检查是否为类
        return isPythonClass(attr);
        
    } catch (const py::error_already_set& e) {
        return false;
    }
}

py::object DynamicPythonCaller::createClassInstance(const std::string& moduleName,
                                                    const std::string& className,
                                                    py::args args,
                                                    py::kwargs kwargs) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        // 创建类的实例
        return classObj(*args, **kwargs);
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Failed to create instance of class: " + moduleName + "." + className + 
                                 "\nPython error: " + std::string(e.what()));
    }
}

py::object DynamicPythonCaller::callClassMethod(py::object instance,
                                                const std::string& methodName,
                                                py::args args,
                                                py::kwargs kwargs) {
    try {
        // 检查实例是否有该方法
        if (!py::hasattr(instance, methodName.c_str())) {
            throw std::runtime_error("Instance does not have method: " + methodName);
        }
        
        py::object method = instance.attr(methodName.c_str());
        return method(*args, **kwargs);
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Failed to call class method: " + methodName + 
                                 "\nPython error: " + std::string(e.what()));
    }
}

py::object DynamicPythonCaller::callStaticMethod(const std::string& moduleName,
                                                 const std::string& className,
                                                 const std::string& methodName,
                                                 py::args args,
                                                 py::kwargs kwargs) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        // 检查类是否有该静态方法
        if (!py::hasattr(classObj, methodName.c_str())) {
            throw std::runtime_error("Class does not have static method: " + methodName);
        }
        
        py::object method = classObj.attr(methodName.c_str());
        return method(*args, **kwargs);
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Failed to call static method: " + moduleName + "." + className + "." + methodName + 
                                 "\nPython error: " + std::string(e.what()));
    }
}

py::object DynamicPythonCaller::getClassAttribute(const std::string& moduleName,
                                                  const std::string& className,
                                                  const std::string& attributeName) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        // 检查类是否有该属性
        if (!py::hasattr(classObj, attributeName.c_str())) {
            throw std::runtime_error("Class does not have attribute: " + attributeName);
        }
        
        return classObj.attr(attributeName.c_str());
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Failed to get class attribute: " + moduleName + "." + className + "." + attributeName + 
                                 "\nPython error: " + std::string(e.what()));
    }
}

void DynamicPythonCaller::setClassAttribute(const std::string& moduleName,
                                            const std::string& className,
                                            const std::string& attributeName,
                                            py::object value) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        // 设置类的属性
        classObj.attr(attributeName.c_str()) = value;
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Failed to set class attribute: " + moduleName + "." + className + "." + attributeName + 
                                 "\nPython error: " + std::string(e.what()));
    }
}

py::object DynamicPythonCaller::getInstanceAttribute(py::object instance,
                                                     const std::string& attributeName) {
    try {
        // 检查实例是否有该属性
        if (!py::hasattr(instance, attributeName.c_str())) {
            throw std::runtime_error("Instance does not have attribute: " + attributeName);
        }
        
        return instance.attr(attributeName.c_str());
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Failed to get instance attribute: " + attributeName + 
                                 "\nPython error: " + std::string(e.what()));
    }
}

void DynamicPythonCaller::setInstanceAttribute(py::object instance,
                                               const std::string& attributeName,
                                               py::object value) {
    try {
        // 设置实例的属性
        instance.attr(attributeName.c_str()) = value;
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Failed to set instance attribute: " + attributeName + 
                                 "\nPython error: " + std::string(e.what()));
    }
}

bool DynamicPythonCaller::isInstanceOf(py::object obj, const std::string& moduleName, const std::string& className) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        // 使用isinstance检查
        return py::isinstance(obj, classObj);
        
    } catch (const py::error_already_set& e) {
        return false;
    }
}

std::vector<std::string> DynamicPythonCaller::getClassMembers(py::object classObj,
                                                              const std::string& memberType,
                                                              bool includeInherited) {
    std::vector<std::string> members;
    try {
        py::module_ inspect = py::module_::import("inspect");
        
        // 根据成员类型选择不同的inspect方法
        if (memberType == "methods") {
            // 获取方法
            py::object method_list;
            if (includeInherited) {
                // 获取所有方法（包括继承的）
                py::object getmembers = inspect.attr("getmembers");
                py::list all_members = getmembers(classObj);
                
                for (auto item : all_members) {
                    py::tuple member_tuple = item.cast<py::tuple>();
                    if (py::len(member_tuple) < 2) continue;
                    
                    std::string name = py::str(member_tuple[0]).cast<std::string>();
                    py::object member_obj = member_tuple[1];
                    
                    // 检查是否为方法（可调用且不是私有方法）
                    if (!isPrivateFunction(name) && py::hasattr(member_obj, "__call__")) {
                        members.push_back(name);
                    }
                }
            } else {
                // 只获取类自身的方法
                py::dict class_dict = classObj.attr("__dict__");
                py::list dict_keys = class_dict.attr("keys")();
                
                for (auto item : dict_keys) {
                    std::string name = py::str(item).cast<std::string>();
                    
                    // 跳过私有方法
                    if (isPrivateFunction(name)) {
                        continue;
                    }
                    
                    py::object member_obj = class_dict[item];
                    
                    // 检查是否为方法（可调用）
                    if (py::hasattr(member_obj, "__call__")) {
                        members.push_back(name);
                    }
                }
            }
        } else if (memberType == "attributes") {
            // 获取属性
            py::object getmembers = inspect.attr("getmembers");
            py::list all_members = getmembers(classObj);
            
            for (auto item : all_members) {
                py::tuple member_tuple = item.cast<py::tuple>();
                if (py::len(member_tuple) < 2) continue;
                
                std::string name = py::str(member_tuple[0]).cast<std::string>();
                py::object member_obj = member_tuple[1];
                
                // 跳过私有属性
                if (isPrivateFunction(name)) {
                    continue;
                }
                
                // 检查是否为属性（不是方法）
                if (!py::hasattr(member_obj, "__call__")) {
                    // 排除特殊属性
                    if (name.find("__") == 0 && name.rfind("__") == name.length() - 2) {
                        continue; // 跳过__xxx__形式的特殊属性
                    }
                    members.push_back(name);
                }
            }
            
            // 如果不包含继承的属性，需要过滤
            if (!includeInherited) {
                std::vector<std::string> filtered_members;
                py::dict class_dict = classObj.attr("__dict__");
                
                for (const auto& name : members) {
                    if (py::hasattr(class_dict, name.c_str())) {
                        filtered_members.push_back(name);
                    }
                }
                members = filtered_members;
            }
        }
        
        // 按字母顺序排序
        std::sort(members.begin(), members.end());
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Error getting class members: ") + e.what());
    }
    
    return members;
}

std::vector<std::string> DynamicPythonCaller::getClassMethods(const std::string& moduleName,
                                                              const std::string& className,
                                                              bool includeInherited) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        return getClassMembers(classObj, "methods", includeInherited);
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Error getting class methods: ") + e.what());
        return {};
    }
}

std::vector<std::string> DynamicPythonCaller::getClassAttributes(const std::string& moduleName,
                                                                 const std::string& className,
                                                                 bool includeInherited) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        return getClassMembers(classObj, "attributes", includeInherited);
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Error getting class attributes: ") + e.what());
        return {};
    }
}
