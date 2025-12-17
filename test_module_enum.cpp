#include "include/dynamic_python_caller.h"
#include <iostream>
#include <vector>
#include <map>
#include <any>

namespace py = pybind11;

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
        std::cout << "Python模块枚举与动态调用测试" << std::endl;
        std::cout << "========================================" << std::endl;
        
        // 测试模块名称
        std::string moduleName = "dynamic_funcs";
        
        // 测试1：列出模块中的所有函数
        std::cout << "\n1. 列出模块 '" << moduleName << "' 中的所有函数:" << std::endl;
        std::vector<std::string> functions = DynamicPythonCaller::listModuleFunctions(moduleName);
        
        std::cout << "  找到 " << functions.size() << " 个函数:" << std::endl;
        for (size_t i = 0; i < functions.size(); ++i) {
            std::cout << "    " << (i + 1) << ". " << functions[i] << std::endl;
        }
        
        // 测试2：获取模块信息
        std::cout << "\n2. 获取模块信息:" << std::endl;
        std::map<std::string, std::any> moduleInfo = DynamicPythonCaller::getModuleInfo(moduleName);
        
        if (moduleInfo.find("function_count") != moduleInfo.end()) {
            int count = std::any_cast<int>(moduleInfo["function_count"]);
            std::cout << "   函数数量: " << count << std::endl;
        }
        
        if (moduleInfo.find("example_signature") != moduleInfo.end()) {
            std::string exampleSig = std::any_cast<std::string>(moduleInfo["example_signature"]);
            std::cout << "   示例函数签名: " << exampleSig << std::endl;
        }
        
        // 测试3：检查模块是否包含特定函数
        std::cout << "\n3. 检查模块是否包含特定函数:" << std::endl;
        std::vector<std::string> testFunctions = {"func_no_args", "func_one_arg", "non_existent_func"};
        
        for (const auto& funcName : testFunctions) {
            bool hasFunc = DynamicPythonCaller::moduleHasFunction(moduleName, funcName);
            std::cout << "   " << moduleName << " 包含 " << funcName << "? " 
                      << (hasFunc ? "是" : "否") << std::endl;
        }
        
        // 测试4：获取模块函数映射
        std::cout << "\n4. 获取模块函数映射:" << std::endl;
        std::map<std::string, py::object> funcMap = DynamicPythonCaller::getModuleFunctionMap(moduleName);
        
        std::cout << "   映射中包含 " << funcMap.size() << " 个函数" << std::endl;
        
        // 显示前几个函数的类型信息
        int count = 0;
        for (const auto& pair : funcMap) {
            if (count >= 3) break; // 只显示前3个
            
            std::cout << "   " << pair.first << " -> " 
                      << py::str(py::type::of(pair.second)).cast<std::string>() << std::endl;
            count++;
        }
        
        // 测试5：使用动态调用接口
        std::cout << "\n5. 使用动态调用接口:" << std::endl;
        
        // 调用无参数函数
        std::cout << "   调用 func_no_args():" << std::endl;
        py::object result1 = DynamicPythonCaller::dynamicCall(moduleName, "func_no_args");
        std::cout << "   结果: " << result1.cast<std::string>() << std::endl;
        
        // 调用带参数函数
        std::cout << "   调用 func_one_arg(123):" << std::endl;
        py::object result2 = DynamicPythonCaller::dynamicCall(moduleName, "func_one_arg", 
                                                              py::make_tuple(123));
        std::cout << "   结果: " << result2.cast<std::string>() << std::endl;
        
        // 调用带默认参数的函数
        std::cout << "   调用 func_default_args() 使用默认参数:" << std::endl;
        py::object result3 = DynamicPythonCaller::dynamicCall(moduleName, "func_default_args");
        std::cout << "   结果: " << result3.cast<std::string>() << std::endl;
        
        std::cout << "   调用 func_default_args(99, 88) 提供参数:" << std::endl;
        py::object result4 = DynamicPythonCaller::dynamicCall(moduleName, "func_default_args",
                                                              py::make_tuple(99, 88));
        std::cout << "   结果: " << result4.cast<std::string>() << std::endl;
        
        // 测试6：批量调用
        std::cout << "\n6. 批量调用多个函数:" << std::endl;
        std::vector<std::string> batchFunctions = {"func_no_args", "func_one_arg", "func_two_args"};
        
        std::map<std::string, py::object> batchResults = 
            DynamicPythonCaller::batchCall(moduleName, batchFunctions, 
                                          py::make_tuple(999),  // 注意：这里所有函数使用相同参数
                                          py::kwargs());        // 对于func_no_args和func_two_args，参数可能不匹配
        
        for (const auto& pair : batchResults) {
            std::cout << "   " << pair.first << ": ";
            if (pair.second.is_none()) {
                std::cout << "函数不存在或调用失败" << std::endl;
            } else {
                try {
                    std::string strResult = py::str(pair.second).cast<std::string>();
                    std::cout << strResult << std::endl;
                } catch (...) {
                    std::cout << "无法转换为字符串" << std::endl;
                }
            }
        }
        
        // 测试7：使用callModuleFunction静态方法
        std::cout << "\n7. 使用callModuleFunction静态方法:" << std::endl;
        py::object result5 = DynamicPythonCaller::callModuleFunction(moduleName, "func_two_args",
                                                                     py::make_tuple(10, 20));
        std::cout << "   func_two_args(10, 20) 结果: " << result5.cast<std::string>() << std::endl;
        
        // 测试8：测试灵活的Python API模块（如果存在）
        std::cout << "\n8. 测试灵活的API模块:" << std::endl;
        std::string flexibleModule = "flexible_api";
        
        if (DynamicPythonCaller::moduleHasFunction(flexibleModule, "get_stock_data")) {
            std::cout << "   " << flexibleModule << " 模块存在，包含 get_stock_data 函数" << std::endl;
            
            // 获取函数列表
            std::vector<std::string> flexibleFuncs = DynamicPythonCaller::listModuleFunctions(flexibleModule);
            std::cout << "   模块包含 " << flexibleFuncs.size() << " 个函数:" << std::endl;
            for (size_t i = 0; i < flexibleFuncs.size() && i < 5; ++i) {
                std::cout << "     - " << flexibleFuncs[i] << std::endl;
            }
            if (flexibleFuncs.size() > 5) {
                std::cout << "     ... 和其他 " << (flexibleFuncs.size() - 5) << " 个函数" << std::endl;
            }
        } else {
            std::cout << "   " << flexibleModule << " 模块不存在或没有 get_stock_data 函数" << std::endl;
        }
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "测试完成!" << std::endl;
        std::cout << "========================================" << std::endl;
        
    } catch (const py::error_already_set& e) {
        std::cerr << "Python错误: " << e.what() << std::endl;
        
        // 尝试获取详细的错误信息
        try {
            py::module_ traceback = py::module_::import("traceback");
            py::object formatted_exc = traceback.attr("format_exc")();
            std::cerr << "详细错误:\n" << formatted_exc.cast<std::string>() << std::endl;
        } catch (...) {
            // 忽略
        }
        
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "C++错误: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
