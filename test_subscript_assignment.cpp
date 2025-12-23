#include <iostream>
#include "script_interpreter.h"
using namespace script_interpreter;

#if 0
int main() {
    if (!Py_IsInitialized()) {
        py::scoped_interpreter guard{};
        
        py::module_ sys = py::module_::import("sys");
        sys.attr("path").attr("insert")(0, ".");
        sys.attr("path").attr("insert")(0, "./python");
        
        ScriptInterpreter interpreter;
        
        // 测试1：字典下标赋值
        std::cout << "测试1：字典下标赋值" << std::endl;
        std::string script1 = R"(
my_dict = {"a": 100, "b": 200};
my_dict["c"] = 300;
result = my_dict["c"];
)";
        
        if (interpreter.execute(script1)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "脚本执行失败" << std::endl;
        }
        
        interpreter.clearEnvironment();
        
        // 测试2：列表下标赋值
        std::cout << "\n测试2：列表下标赋值" << std::endl;
        std::string script2 = R"(
my_list = [1, 2, 3, 4, 5];
my_list[2] = 999;
result = my_list[2];
)";
        
        if (interpreter.execute(script2)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "脚本执行失败" << std::endl;
        }
        
        interpreter.clearEnvironment();
        
        // 测试3：字典下标访问（只读）
        std::cout << "\n测试3：字典下标访问（只读）" << std::endl;
        std::string script3 = R"(
my_dict = {"x": 10, "y": 20};
result = my_dict["x"];
)";
        
        if (interpreter.execute(script3)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "脚本执行失败" << std::endl;
        }
        
        return 0;
    } else {
        std::cerr << "Python解释器未正确初始化" << std::endl;
        return 1;
    }
}
#endif

int main() { return 0; }
