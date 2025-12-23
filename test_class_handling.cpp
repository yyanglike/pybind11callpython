#include "include/dynamic_python_caller.h"
#include <iostream>
#include <vector>
#include <map>
#include <any>

namespace py = pybind11;

#include "logger.h"
static Logger s_logger;

#if 0
int main() {
    // 初始化Python解释器
    py::scoped_interpreter guard{};
    
    try {
        // 配置Python路径
        py::module_ sys = py::module_::import("sys");
        py::list path = sys.attr("path");
        // 添加项目根目录下的python目录（相对于build目录）
        std::string pythonPath = "../python";
        path.insert(0, pythonPath);
        
        std::cout << "========================================" << std::endl;
        std::cout << "Python类处理功能测试" << std::endl;
        std::cout << "========================================" << std::endl;
        
        // 测试模块名称
        std::string moduleName = "class_module";
        
        // 测试1：列出模块中的所有类
        std::cout << "\n1. 列出模块 '" << moduleName << "' 中的所有类:" << std::endl;
        std::vector<std::string> classes = DynamicPythonCaller::listModuleClasses(moduleName);
        
        std::cout << "  找到 " << classes.size() << " 个类:" << std::endl;
        for (size_t i = 0; i < classes.size(); ++i) {
            std::cout << "    " << (i + 1) << ". " << classes[i] << std::endl;
        }
        
        // 测试2：检查模块是否包含特定类
        std::cout << "\n2. 检查模块是否包含特定类:" << std::endl;
        std::vector<std::string> testClasses = {"SimpleClass", "Calculator", "Person", "Student", "NonExistentClass"};
        
        for (const auto& className : testClasses) {
            bool hasClass = DynamicPythonCaller::moduleHasClass(moduleName, className);
            std::cout << "   " << moduleName << " 包含 " << className << "? " 
                      << (hasClass ? "是" : "否") << std::endl;
        }
        
        // 测试3：创建类的实例
        std::cout << "\n3. 创建类的实例:" << std::endl;
        
        // 创建SimpleClass实例
        std::cout << "   创建 SimpleClass 实例:" << std::endl;
        py::object simpleInstance = DynamicPythonCaller::createClassInstance(moduleName, "SimpleClass", 
                                                                             py::make_tuple("test_name", 100));
        std::cout << "   实例创建成功: " << py::str(simpleInstance).cast<std::string>() << std::endl;
        
        // 创建Calculator实例
        std::cout << "   创建 Calculator 实例:" << std::endl;
        py::object calcInstance = DynamicPythonCaller::createClassInstance(moduleName, "Calculator", 
                                                                           py::make_tuple(10));
        std::cout << "   实例创建成功" << std::endl;
        
        // 创建Person实例
        std::cout << "   创建 Person 实例:" << std::endl;
        py::object personInstance = DynamicPythonCaller::createClassInstance(moduleName, "Person", 
                                                                             py::make_tuple("Alice", 25));
        std::cout << "   实例创建成功" << std::endl;
        
        // 测试4：调用实例方法
        std::cout << "\n4. 调用实例方法:" << std::endl;
        
        // 调用SimpleClass的实例方法
        std::cout << "   调用 SimpleClass.instance_method(2):" << std::endl;
        py::object result1 = DynamicPythonCaller::callClassMethod(simpleInstance, "instance_method", 
                                                                  py::make_tuple(2));
        std::cout << "   结果: " << result1.cast<std::string>() << std::endl;
        
        // 调用Calculator的add方法
        std::cout << "   调用 Calculator.add(5):" << std::endl;
        py::object result2 = DynamicPythonCaller::callClassMethod(calcInstance, "add", 
                                                                  py::make_tuple(5));
        std::cout << "   结果: " << result2.cast<double>() << std::endl;
        
        // 调用Person的introduce方法
        std::cout << "   调用 Person.introduce():" << std::endl;
        py::object result3 = DynamicPythonCaller::callClassMethod(personInstance, "introduce");
        std::cout << "   结果: " << result3.cast<std::string>() << std::endl;

        // 测试8：检查实例类型
        std::cout << "\n8. 检查实例类型:" << std::endl;
        
        bool isSimpleClass = DynamicPythonCaller::isInstanceOf(simpleInstance, moduleName, "SimpleClass");
        std::cout << "   simpleInstance 是 SimpleClass 的实例? " << (isSimpleClass ? "是" : "否") << std::endl;
        
        bool isPerson = DynamicPythonCaller::isInstanceOf(personInstance, moduleName, "Person");
        std::cout << "   personInstance 是 Person 的实例? " << (isPerson ? "是" : "否") << std::endl;
        
        // 测试9：获取类的方法和属性列表
        std::cout << "\n9. 获取类的方法和属性列表:" << std::endl;
        
        std::cout << "   获取 SimpleClass 的方法（包含继承的）:" << std::endl;
        std::vector<std::string> methods = DynamicPythonCaller::getClassMethods(moduleName, "SimpleClass", true);
        std::cout << "   共有 " << methods.size() << " 个方法:" << std::endl;
        for (size_t i = 0; i < methods.size() && i < 5; ++i) {
            std::cout << "     - " << methods[i] << std::endl;
        }
        if (methods.size() > 5) {
            std::cout << "     ... 和其他 " << (methods.size() - 5) << " 个方法" << std::endl;
        }
        
        std::cout << "   获取 SimpleClass 的属性（不包含继承的）:" << std::endl;
        std::vector<std::string> attributes = DynamicPythonCaller::getClassAttributes(moduleName, "SimpleClass", false);
        std::cout << "   共有 " << attributes.size() << " 个属性:" << std::endl;
        for (size_t i = 0; i < attributes.size() && i < 5; ++i) {
            std::cout << "     - " << attributes[i] << std::endl;
        }
        if (attributes.size() > 5) {
            std::cout << "     ... 和其他 " << (attributes.size() - 5) << " 个属性" << std::endl;
        }
        
        // 测试10：测试继承
        std::cout << "\n10. 测试继承:" << std::endl;
        
        // 创建Student实例
        std::cout << "   创建 Student 实例:" << std::endl;
        py::object studentInstance = DynamicPythonCaller::createClassInstance(moduleName, "Student", 
                                                                              py::make_tuple("Bob", 20, "S12345"));
        
        // 调用继承的方法
        std::cout << "   调用 Student.introduce() (继承自Person):" << std::endl;
        py::object result8 = DynamicPythonCaller::callClassMethod(studentInstance, "introduce");
        std::cout << "   结果: " << result8.cast<std::string>() << std::endl;
        
        // 调用Student特有的方法
        std::cout << "   调用 Student.add_grade(90):" << std::endl;
        py::object result9 = DynamicPythonCaller::callClassMethod(studentInstance, "add_grade", 
                                                           py::make_tuple(90));
        std::cout << "   结果: 添加成绩成功" << std::endl;
        
        std::cout << "   调用 Student.average_grade():" << std::endl;
        py::object result10 = DynamicPythonCaller::callClassMethod(studentInstance, "average_grade");
        std::cout << "   结果: " << result10.cast<double>() << std::endl;
        
        // 检查继承关系
        bool isStudentPerson = DynamicPythonCaller::isInstanceOf(studentInstance, moduleName, "Person");
        std::cout << "   studentInstance 是 Person 的实例? " << (isStudentPerson ? "是" : "否") << std::endl;
        
        bool isStudentStudent = DynamicPythonCaller::isInstanceOf(studentInstance, moduleName, "Student");
        std::cout << "   studentInstance 是 Student 的实例? " << (isStudentStudent ? "是" : "否") << std::endl;
        
        // 测试11：错误处理测试
        std::cout << "\n11. 错误处理测试:" << std::endl;
        
        try {
            std::cout << "   尝试调用不存在的方法:" << std::endl;
            py::object result11 = DynamicPythonCaller::callClassMethod(simpleInstance, "non_existent_method");
            std::cout << "   结果: " << result11.cast<std::string>() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "   预期错误: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "   尝试获取不存在的属性:" << std::endl;
            py::object result12 = DynamicPythonCaller::getInstanceAttribute(simpleInstance, "non_existent_attr");
            std::cout << "   结果: " << result12.cast<std::string>() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "   预期错误: " << e.what() << std::endl;
        }
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "类处理测试完成!" << std::endl;
        std::cout << "========================================" << std::endl;
        
    } catch (const py::error_already_set& e) {
        s_logger.error(std::string("Python错误: ") + e.what());
        
        // 尝试获取详细的错误信息
        try {
            py::module_ traceback = py::module_::import("traceback");
            py::object formatted_exc = traceback.attr("format_exc")();
            s_logger.error(std::string("详细错误:\n") + formatted_exc.cast<std::string>());
        } catch (...) {
            // 忽略
        }
        
        return 1;
    } catch (const std::exception& e) {
        s_logger.error(std::string("C++错误: ") + e.what());
        return 1;
    }
    
    return 0;
}
#endif // disable standalone main

int main() { return 0; }
