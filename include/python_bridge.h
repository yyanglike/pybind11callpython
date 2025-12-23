/**
 * @file python_bridge.h
 * @brief Python桥接模块，负责C++与Python之间的交互
 * 
 * 该模块封装了所有与Python解释器交互的细节，包括：
 * - Python函数调用
 * - Python对象创建和操作
 * - Python模块导入
 * - Python表达式执行
 */

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <pybind11/pybind11.h>

namespace py = pybind11;

class ScriptValue;

namespace script_interpreter {

/**
 * @class PythonBridge
 * @brief Python桥接类，管理与Python解释器的所有交互
 * 
 * 封装了与Python解释器交互的底层细节，提供高层接口供其他模块使用。
 * 注意：Python解释器的生命周期管理由外部代码负责（如ScriptInterpreter）。
 */
class PythonBridge {
public:
    /**
     * @brief 构造函数
     * 
     * 配置Python路径，不初始化Python解释器（由外部管理）。
     */
    PythonBridge();
    
    /**
     * @brief 析构函数
     * 
     * 不销毁Python解释器（由外部管理）。
     */
    ~PythonBridge();
    
    /**
     * @brief 调用Python函数
     * @param func Python函数对象
     * @param args 参数列表
     * @return 函数返回值，封装为ScriptValue
     */
    std::shared_ptr<ScriptValue> callPythonFunction(
        py::object func,
        const std::vector<std::shared_ptr<ScriptValue>>& args);
    
    /**
     * @brief 创建Python类实例
     * @param moduleName 模块名
     * @param className 类名
     * @param args 构造函数参数
     * @return Python实例，封装为ScriptValue
     */
    std::shared_ptr<ScriptValue> createPythonInstance(
        const std::string& moduleName,
        const std::string& className,
        const std::vector<std::shared_ptr<ScriptValue>>& args);
    
    /**
     * @brief 获取对象成员
     * @param object Python对象
     * @param memberName 成员名
     * @return 成员值，封装为ScriptValue
     */
    std::shared_ptr<ScriptValue> getMember(
        std::shared_ptr<ScriptValue> object,
        const std::string& memberName);
    
    /**
     * @brief 设置对象成员
     * @param object Python对象
     * @param memberName 成员名
     * @param value 要设置的值
     */
    void setMember(
        std::shared_ptr<ScriptValue> object,
        const std::string& memberName,
        std::shared_ptr<ScriptValue> value);
    
    /**
     * @brief 导入Python模块
     * @param moduleName 模块名
     * @return Python模块对象
     */
    py::module_ importModule(const std::string& moduleName);
    
    /**
     * @brief 执行Python代码
     * @param code Python代码字符串
     * @param globals 全局命名空间
     * @param locals 局部命名空间
     * @return 执行结果
     */
    py::object eval(const std::string& code, 
                    py::dict globals = py::dict(),
                    py::dict locals = py::dict());
    
    /**
     * @brief 执行Python代码（语句）
     * @param code Python代码字符串
     * @param globals 全局命名空间
     * @param locals 局部命名空间
     */
    void exec(const std::string& code,
              py::dict globals = py::dict(),
              py::dict locals = py::dict());
    
    /**
     * @brief 获取Python全局命名空间
     * @return 全局命名空间字典
     */
    py::dict globals() const;
    
    /**
     * @brief 检查Python对象是否是字典
     * @param obj Python对象
     * @return 如果是字典返回true，否则false
     */
    bool isDict(py::object obj) const;
    
    /**
     * @brief 检查Python对象是否是函数
     * @param obj Python对象
     * @return 如果是函数返回true，否则false
     */
    bool isFunction(py::object obj) const;
    
    /**
     * @brief 检查Python对象是否是模块
     * @param obj Python对象
     * @return 如果是模块返回true，否则false
     */
    bool isModule(py::object obj) const;
    
    /**
     * @brief 检查对象是否具有指定属性
     * @param obj Python对象
     * @param attrName 属性名
     * @return 如果有该属性返回true，否则false
     */
    bool hasAttr(py::object obj, const std::string& attrName) const;
    
    /**
     * @brief 获取对象属性
     * @param obj Python对象
     * @param attrName 属性名
     * @return 属性值
     */
    py::object getAttr(py::object obj, const std::string& attrName) const;
    
    /**
     * @brief 设置对象属性
     * @param obj Python对象
     * @param attrName 属性名
     * @param value 属性值
     */
    void setAttr(py::object obj, const std::string& attrName, py::object value);
    
    /**
     * @brief 获取对象的字符串表示
     * @param obj Python对象
     * @return 字符串表示
     */
    std::string str(py::object obj) const;
    
    /**
     * @brief 获取对象的类型名
     * @param obj Python对象
     * @return 类型名
     */
    std::string typeName(py::object obj) const;
    
    /**
     * @brief 检查对象是否可调用
     * @param obj Python对象
     * @return 如果可调用返回true，否则false
     */
    bool isCallable(py::object obj) const;
    
    /**
     * @brief 获取Python内置函数
     * @param name 内置函数名
     * @return 内置函数对象，如果不存在返回空对象
     */
    py::object getBuiltin(const std::string& name) const;
    
private:
    /**
     * @brief 配置Python路径
     */
    void configurePythonPath();
};

} // namespace script_interpreter
