#ifndef DYNAMIC_PYTHON_CALLER_H
#define DYNAMIC_PYTHON_CALLER_H

#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <string>
#include <vector>
#include <map>
#include <any>

namespace py = pybind11;

class DynamicPythonCaller {
public:
    // 构造函数，可以指定模块名和函数名
    DynamicPythonCaller(const std::string& moduleName = "", const std::string& functionName = "");
    
    // 设置模块名
    void setModule(const std::string& moduleName);
    
    // 设置函数名
    void setFunction(const std::string& functionName);
    
    // 调用函数，支持可变参数
    py::object call(py::args args = py::args{}, py::kwargs kwargs = py::kwargs{});
    
    // 直接调用指定模块和函数的静态方法
    static py::object callModuleFunction(const std::string& moduleName, 
                                         const std::string& functionName,
                                         py::args args = py::args{}, 
                                         py::kwargs kwargs = py::kwargs{});
    
    // 调用函数（使用函数对象，不需要提前设置模块和函数）
    static py::object callFunction(py::object func, 
                                   py::args args = py::args{}, 
                                   py::kwargs kwargs = py::kwargs{});
    
    // 获取函数对象
    py::object getFunction() const;
    
    // 检查函数是否存在
    bool functionExists() const;
    
    // 获取函数签名信息
    std::string getSignature() const;
    
    // 获取参数信息
    std::vector<std::pair<std::string, std::string>> getParameters() const;
    
    // 获取默认参数值
    std::map<std::string, py::object> getDefaultValues() const;
    
    // ==== 新增功能：模块函数枚举 ====
    
    // 列出模块中的所有可调用函数（排除内置函数和私有函数）
    static std::vector<std::string> listModuleFunctions(const std::string& moduleName);
    
    // 获取模块中所有可调用函数的映射（函数名 -> 函数对象）
    static std::map<std::string, py::object> getModuleFunctionMap(const std::string& moduleName);
    
    // 检查模块中是否包含指定函数
    static bool moduleHasFunction(const std::string& moduleName, const std::string& functionName);
    
    // 获取模块信息（函数数量、名称列表等）
    static std::map<std::string, std::any> getModuleInfo(const std::string& moduleName);
    
    // ==== 新增功能：动态调用 ====
    
    // 根据字符串动态调用模块中的函数
    static py::object dynamicCall(const std::string& moduleName, 
                                  const std::string& functionName,
                                  py::args args = py::args{}, 
                                  py::kwargs kwargs = py::kwargs{});
    
    // 批量调用多个函数
    static std::map<std::string, py::object> batchCall(const std::string& moduleName,
                                                       const std::vector<std::string>& functionNames,
                                                       py::args args = py::args{},
                                                       py::kwargs kwargs = py::kwargs{});
    
    // ==== 新增功能：Python类处理 ====
    
    // 检查对象是否为Python类
    static bool isPythonClass(py::object obj);
    
    // 列出模块中的所有类（排除私有类）
    static std::vector<std::string> listModuleClasses(const std::string& moduleName);
    
    // 获取模块中所有类的映射（类名 -> 类对象）
    static std::map<std::string, py::object> getModuleClassMap(const std::string& moduleName);
    
    // 检查模块中是否包含指定类
    static bool moduleHasClass(const std::string& moduleName, const std::string& className);
    
    // 创建类的实例
    static py::object createClassInstance(const std::string& moduleName,
                                          const std::string& className,
                                          py::args args = py::args{},
                                          py::kwargs kwargs = py::kwargs{});
    
    // 调用类的方法（实例方法）
    static py::object callClassMethod(py::object instance,
                                      const std::string& methodName,
                                      py::args args = py::args{},
                                      py::kwargs kwargs = py::kwargs{});
    
    // 调用类的静态方法
    static py::object callStaticMethod(const std::string& moduleName,
                                       const std::string& className,
                                       const std::string& methodName,
                                       py::args args = py::args{},
                                       py::kwargs kwargs = py::kwargs{});
    
    // 获取类的属性
    static py::object getClassAttribute(const std::string& moduleName,
                                        const std::string& className,
                                        const std::string& attributeName);
    
    // 设置类的属性
    static void setClassAttribute(const std::string& moduleName,
                                  const std::string& className,
                                  const std::string& attributeName,
                                  py::object value);
    
    // 获取实例的属性
    static py::object getInstanceAttribute(py::object instance,
                                           const std::string& attributeName);
    
    // 设置实例的属性
    static void setInstanceAttribute(py::object instance,
                                     const std::string& attributeName,
                                     py::object value);
    
    // 检查对象是否为类的实例
    static bool isInstanceOf(py::object obj, const std::string& moduleName, const std::string& className);
    
    // 获取类的所有方法（包括继承的）
    static std::vector<std::string> getClassMethods(const std::string& moduleName,
                                                    const std::string& className,
                                                    bool includeInherited = true);
    
    // 获取类的所有属性（包括继承的）
    static std::vector<std::string> getClassAttributes(const std::string& moduleName,
                                                       const std::string& className,
                                                       bool includeInherited = true);
    
private:
    std::string moduleName_;
    std::string functionName_;
    py::object function_;
    
    // 导入模块并获取函数
    void importAndGetFunction();
    
    // 内部辅助函数：检查对象是否为可调用函数
    static bool isCallableFunction(py::object obj);
    
    // 内部辅助函数：检查函数名是否为私有函数（以_开头）
    static bool isPrivateFunction(const std::string& functionName);
    
    // 内部辅助函数：获取类的所有成员
    static std::vector<std::string> getClassMembers(py::object classObj, 
                                                    const std::string& memberType,
                                                    bool includeInherited);
};

#endif // DYNAMIC_PYTHON_CALLER_H
