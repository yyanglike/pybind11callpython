#include <iostream>
#include <string>
#include "script_interpreter.h"
using namespace script_interpreter;

#if 0
int main() {
    std::cout << "test_simple开始" << std::endl;
    try {
        // 初始化Python解释器
        std::cout << "检查Python是否初始化" << std::endl;
        if (!Py_IsInitialized()) {
            std::cout << "Python未初始化，创建scoped_interpreter" << std::endl;
            py::scoped_interpreter guard{};
            
            // 配置Python路径
            std::cout << "配置Python路径" << std::endl;
            py::module_ sys = py::module_::import("sys");
            sys.attr("path").attr("insert")(0, ".");
            sys.attr("path").attr("insert")(0, "./python");
            
            std::cout << "创建ScriptInterpreter对象" << std::endl;
            ScriptInterpreter interpreter;
            
            std::cout << "=== 简单测试 ===" << std::endl;
            
            // 测试1: 简单的整数赋值
            std::cout << "\n--- 测试1: 整数赋值 ---" << std::endl;
            std::string script1 = "x = 42;";
            
            std::cout << "开始执行脚本: " << script1 << std::endl;
            bool success = interpreter.execute(script1);
            std::cout << "execute返回: " << (success ? "true" : "false") << std::endl;
            if (success) {
                std::cout << "脚本执行成功" << std::endl;
                auto x = interpreter.getVariable("x");
                if (x) {
                    std::cout << "找到变量 'x', 值: " << x->toString() << std::endl;
                } else {
                    std::cout << "未找到变量 'x'" << std::endl;
                }
            } else {
                std::cout << "脚本执行失败" << std::endl;
            }
            
            std::cout << "\n=== 简单测试完成 ===" << std::endl;
            
        } else {
            std::cerr << "错误：Python解释器未正确初始化" << std::endl;
            return 1;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "测试过程中发生异常: " << e.what() << std::endl;
        return 1;
    } catch (const py::error_already_set& e) {
        std::cerr << "Python异常: " << e.what() << std::endl;
        
        // 尝试获取Python异常详细信息
        try {
            py::module_ traceback = py::module_::import("traceback");
            py::object formatted_exc = traceback.attr("format_exc")();
            std::cerr << "堆栈跟踪:\n" << formatted_exc.cast<std::string>() << std::endl;
        } catch (...) {
            // 忽略获取详细信息的错误
        }
        
        return 1;
    }
    
    std::cout << "test_simple结束" << std::endl;
    return 0;
}
#endif

int main() { return 0; }
