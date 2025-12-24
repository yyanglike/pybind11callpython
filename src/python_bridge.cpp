/**
 * @file python_bridge.cpp
 * @brief Python桥接模块实现
 */

#include "python_bridge.h"
#include "script_value.h"
#include "logger.h"
#include <atomic>
#include <pybind11/eval.h>

static Logger s_logger;

namespace script_interpreter {

PythonBridge::PythonBridge() {
    configurePythonPath();
}

PythonBridge::~PythonBridge() {
    // 不做任何事，解释器由外部管理
}

void PythonBridge::configurePythonPath() {
    try {
        py::module_ sys = py::module_::import("sys");
        // 将当前目录下的python目录添加到Python路径
        py::str python_path = "../python";
        sys.attr("path").attr("insert")(0, python_path);
        s_logger.info(std::string("[PythonBridge] Python path configured: ") + python_path.cast<std::string>() );
    } catch (const std::exception& e) {
        s_logger.error(std::string("[PythonBridge] Failed to configure Python path: ") + e.what());
    }
}

std::shared_ptr<ScriptValue> PythonBridge::callPythonFunction(
    py::object func,
    const std::vector<std::shared_ptr<ScriptValue>>& args) {
    
    try {
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
        }
        
        py::object result = func(*pyArgs);
        return ScriptValue::fromPythonObject(result);
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Python function call error: " + std::string(e.what()));
    }
}

std::shared_ptr<ScriptValue> PythonBridge::createPythonInstance(
    const std::string& moduleName,
    const std::string& className,
    const std::vector<std::shared_ptr<ScriptValue>>& args) {
    
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
        }
        
        py::object instance = classObj(*pyArgs);
        return ScriptValue::fromPythonObject(instance);
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Python instance creation error: " + std::string(e.what()));
    }
}

std::shared_ptr<ScriptValue> PythonBridge::getMember(
    std::shared_ptr<ScriptValue> object,
    const std::string& memberName) {
    
    if (!object) {
        return nullptr;
    }
    
    if (object->isPythonObject()) {
        py::object pyObj = object->getPythonObject();
        
        // 特殊处理 toString 方法
        if (memberName == "toString" || memberName == "toString()") {
            // 对于Python对象，返回一个调用 str(obj) 的 lambda 函数
            try {
                py::object str_func = py::module_::import("builtins").attr("str");
                py::object lambda_func = py::cpp_function([pyObj, str_func]() {
                    return str_func(pyObj);
                });
                return ScriptValue::fromPythonObject(lambda_func);
            } catch (const py::error_already_set& e) {
                s_logger.error(std::string("[PythonBridge] Error creating toString lambda: ") + e.what());
                return nullptr;
            }
        }
        
        try {
            if (py::isinstance<py::module_>(pyObj)) {
                py::module_ module = pyObj.cast<py::module_>();
                py::object member = module.attr(memberName.c_str());
                return ScriptValue::fromPythonObject(member);
            } else if (py::hasattr(pyObj, memberName.c_str())) {
                py::object member = pyObj.attr(memberName.c_str());
                return ScriptValue::fromPythonObject(member);
            }
        } catch (const py::error_already_set&) {
            // 属性不存在，检查是否是Python内置方法
            // 对于Python对象，检查是否有__str__、__repr__等方法
            if (memberName == "__str__" || memberName == "__repr__") {
                try {
                    py::object member = pyObj.attr(memberName.c_str());
                    return ScriptValue::fromPythonObject(member);
                } catch (const py::error_already_set&) {
                    // 方法不存在
                }
            }
        }
    }

    // 支持字典对象成员访问
    if (object->isDictionary()) {
        try {
            if (object->hasKey(memberName)) {
                return object->getKey(memberName);
            }
            return nullptr;
        } catch (const std::exception& e) {
            s_logger.error(std::string("[PythonBridge] Error accessing dictionary member: ") + e.what());
            return nullptr;
        }
    }
    
    // 对于非Python对象，也可以支持toString方法
    if (memberName == "toString" || memberName == "toString()") {
        // 返回一个返回对象字符串表示的lambda
        try {
            py::object str_func = py::module_::import("builtins").attr("str");
            py::object obj_py = object->toPythonObject();
            py::object lambda_func = py::cpp_function([obj_py, str_func]() {
                return str_func(obj_py);
            });
            return ScriptValue::fromPythonObject(lambda_func);
        } catch (const py::error_already_set& e) {
            s_logger.error(std::string("[PythonBridge] Error creating toString lambda for non-Python object: ") + e.what());
            return nullptr;
        }
    }
    
    return nullptr;
}

void PythonBridge::setMember(
    std::shared_ptr<ScriptValue> object,
    const std::string& memberName,
    std::shared_ptr<ScriptValue> value) {
    
    if (!object || !object->isPythonObject()) {
        throw std::runtime_error("Cannot set member on non-object type");
    }
    
    py::object pyObj = object->getPythonObject();
    py::object pyValue = value->toPythonObject();
    
    try {
        pyObj.attr(memberName.c_str()) = pyValue;
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Python attribute assignment error: " + std::string(e.what()));
    }
}

py::module_ PythonBridge::importModule(const std::string& moduleName) {
    return py::module_::import(moduleName.c_str());
}

py::object PythonBridge::eval(const std::string& code, 
                            py::dict globals,
                            py::dict locals) {
    return ::pybind11::eval(code, globals, locals);
}

void PythonBridge::exec(const std::string& code,
                      py::dict globals,
                      py::dict locals) {
    ::pybind11::exec(code, globals, locals);
}

py::dict PythonBridge::globals() const {
    return py::globals();
}

bool PythonBridge::isDict(py::object obj) const {
    py::module_ builtins = py::module_::import("builtins");
    py::object dictType = builtins.attr("dict");
    return py::isinstance(obj, dictType);
}

bool PythonBridge::isFunction(py::object obj) const {
    return py::isinstance<py::function>(obj);
}

bool PythonBridge::isModule(py::object obj) const {
    return py::isinstance<py::module_>(obj);
}

bool PythonBridge::hasAttr(py::object obj, const std::string& attrName) const {
    return py::hasattr(obj, attrName.c_str());
}

py::object PythonBridge::getAttr(py::object obj, const std::string& attrName) const {
    return obj.attr(attrName.c_str());
}

void PythonBridge::setAttr(py::object obj, const std::string& attrName, py::object value) {
    obj.attr(attrName.c_str()) = value;
}

std::string PythonBridge::str(py::object obj) const {
    return py::str(obj).cast<std::string>();
}

std::string PythonBridge::typeName(py::object obj) const {
    return py::str(py::type::of(obj)).cast<std::string>();
}

bool PythonBridge::isCallable(py::object obj) const {
    return py::hasattr(obj, "__call__");
}

py::object PythonBridge::getBuiltin(const std::string& name) const {
    try {
        py::module_ builtins = py::module_::import("builtins");
        if (py::hasattr(builtins, name.c_str())) {
            return builtins.attr(name.c_str());
        }
    } catch (...) {
        // 忽略错误
    }
    return py::object();
}

} // namespace script_interpreter
