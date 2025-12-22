#include <iostream>
#include "script_interpreter.h"

int main() {
    if (!Py_IsInitialized()) {
        py::scoped_interpreter guard{};
        
        py::module_ sys = py::module_::import("sys");
        sys.attr("path").attr("insert")(0, ".");
        sys.attr("path").attr("insert")(0, "./python");
        
        ScriptInterpreter interpreter;
        
        std::cout << "=== 测试原始测试7中的复杂语法 ===\n" << std::endl;
        
        // 测试1：链式方法调用 data_obj.add_record("added", 200).toString()
        std::cout << "测试1：链式方法调用" << std::endl;
        std::string script1 = R"(
import complex_test_script as cts;
data_obj = new cts.ComplexData("chain_test", {"initial": 100});
result = data_obj.add_record("added", 200).toString();
)";
        
        if (interpreter.execute(script1)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "✓ 成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "✗ 失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "✗ 脚本执行失败" << std::endl;
        }
        
        interpreter.clearEnvironment();
        
        // 测试2：字典展开语法 {**x, "value": x["value"] * 10}
        std::cout << "\n测试2：字典展开语法" << std::endl;
        std::string script2 = R"(
x = {"name": "test", "value": 5};
result = {**x, "value": x["value"] * 10};
)";
        
        if (interpreter.execute(script2)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "✓ 成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "✗ 失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "✗ 脚本执行失败" << std::endl;
        }
        
        interpreter.clearEnvironment();
        
        // 测试3：列表推导式 [{"id": i, "value": i * 10} for i in range(3)]
        std::cout << "\n测试3：列表推导式" << std::endl;
        std::string script3 = R"(
result = [{"id": i, "value": i * 10} for i in range(3)];
)";
        
        if (interpreter.execute(script3)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "✓ 成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "✗ 失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "✗ 脚本执行失败" << std::endl;
        }
        
        interpreter.clearEnvironment();
        
        // 测试4：条件表达式在字典字面量中
        std::cout << "\n测试4：条件表达式在字典字面量中" << std::endl;
        std::string script4 = R"(
processed_list = [{"name": "第一项", "value": 10}];
result = {"first_item": processed_list[0] if len(processed_list) > 0 else null};
)";
        
        if (interpreter.execute(script4)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "✓ 成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "✗ 失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "✗ 脚本执行失败" << std::endl;
        }
        
        interpreter.clearEnvironment();
        
        // 测试5：函数定义
        std::cout << "\n测试5：函数定义" << std::endl;
        std::string script5 = R"(
def visitor(node_value, depth): {
    return node_value + ":" + str(depth);
}

result = visitor("node1", 2);
)";
        
        if (interpreter.execute(script5)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "✓ 成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "✗ 失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "✗ 脚本执行失败" << std::endl;
        }
        
        interpreter.clearEnvironment();
        
        // 测试6：复杂lambda表达式（字典操作）
        std::cout << "\n测试6：复杂lambda表达式（字典操作）" << std::endl;
        std::string script6 = R"(
double_value = lambda x: {**x, "value": x["value"] * 2};
result = double_value({"name": "test", "value": 5});
)";
        
        if (interpreter.execute(script6)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "✓ 成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "✗ 失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "✗ 脚本执行失败" << std::endl;
        }
        
        interpreter.clearEnvironment();
        
        // 测试7：for循环（列表推导式的替代）
        std::cout << "\n测试7：for循环" << std::endl;
        std::string script7 = R"(
nested_data = [];
for (i = 0; i < 3; i = i + 1) {
    nested_data = nested_data + [{"id": i, "value": i * 10}];
}
result = nested_data;
)";
        
        if (interpreter.execute(script7)) {
            auto result = interpreter.getVariable("result");
            if (result) {
                std::cout << "✓ 成功，result: " << result->toString() << std::endl;
            } else {
                std::cout << "✗ 失败，未找到result变量" << std::endl;
            }
        } else {
            std::cout << "✗ 脚本执行失败" << std::endl;
        }
        
        return 0;
    } else {
        std::cerr << "Python解释器未正确初始化" << std::endl;
        return 1;
    }
}
