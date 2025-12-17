#include <iostream>
#include "script_interpreter.h"

// 测试脚本语言的基本功能
void test_basic_script() {
    std::cout << "=== 测试基础脚本功能 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 测试1：基本表达式
    std::string script1 = "x = 10; y = 20; z = x + y;";
    if (interpreter.execute(script1)) {
        auto z_value = interpreter.getVariable("z");
        if (z_value && z_value->isInteger()) {
            std::cout << "测试1通过: x + y = " << z_value->getInteger() << std::endl;
        } else if (z_value) {
            std::cout << "测试1: z 类型为 " << static_cast<int>(z_value->getType()) 
                      << ", 值: " << z_value->toString() << std::endl;
        }
    } else {
        std::cout << "测试1失败" << std::endl;
    }
    
    // 测试2：字符串操作
    std::string script2 = "name = \"World\"; greeting = \"Hello, \" + name + \"!\";";
    interpreter.clearEnvironment();
    if (interpreter.execute(script2)) {
        auto greeting = interpreter.getVariable("greeting");
        if (greeting && greeting->isString()) {
            std::cout << "测试2通过: " << greeting->getString() << std::endl;
        } else if (greeting) {
            std::cout << "测试2: greeting 类型为 " << static_cast<int>(greeting->getType())
                      << ", 值: " << greeting->toString() << std::endl;
        }
    }
    
    // 测试3：布尔表达式
    std::string script3 = "a = true; b = false; c = a && b; d = a || b;";
    interpreter.clearEnvironment();
    if (interpreter.execute(script3)) {
        auto c_value = interpreter.getVariable("c");
        auto d_value = interpreter.getVariable("d");
        if (c_value && d_value && 
            c_value->isBoolean() && 
            d_value->isBoolean()) {
            std::cout << "测试3通过: true && false = " << c_value->getBoolean() 
                      << ", true || false = " << d_value->getBoolean() << std::endl;
        } else {
            if (c_value) std::cout << "c 类型: " << static_cast<int>(c_value->getType()) << std::endl;
            if (d_value) std::cout << "d 类型: " << static_cast<int>(d_value->getType()) << std::endl;
        }
    }
}

// 测试Python模块导入和函数调用
void test_python_integration() {
    std::cout << "\n=== 测试Python集成 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 测试导入Python模块
    std::string script1 = "import os;";
    if (interpreter.execute(script1)) {
        auto os_module = interpreter.getVariable("os");
        if (os_module && os_module->isPythonObject()) {
            std::cout << "Python模块导入成功: os" << std::endl;
        } else if (os_module) {
            std::cout << "os 类型: " << static_cast<int>(os_module->getType()) << std::endl;
        }
    }
    
    // 测试调用Python函数（需要已有Python模块）
    interpreter.clearEnvironment();
    
    // 首先设置Python路径以便导入我们的测试模块
    py::module_ sys = py::module_::import("sys");
    sys.attr("path").attr("insert")(0, "../python");
    
    std::string script2 = R"(
import class_module;
Person = class_module.Person;
person = new Person("Alice", 25);
intro = person.introduce();
)";
    
    if (interpreter.execute(script2)) {
        auto intro_value = interpreter.getVariable("intro");
        if (intro_value) {
            std::cout << "Python类实例创建和调用成功" << std::endl;
            std::cout << "结果: " << intro_value->toString() << std::endl;
        }
    } else {
        std::cout << "Python集成测试失败" << std::endl;
    }
    
    // 测试内置函数调用
    interpreter.clearEnvironment();
    std::string script3 = R"(
list = [1, 2, 3, 4, 5];
length = len(list);
)";
    if (interpreter.execute(script3)) {
        auto length = interpreter.getVariable("length");
        if (length && length->isInteger()) {
            std::cout << "内置函数调用测试: len([1,2,3,4,5]) = " << length->getInteger() << std::endl;
        } else if (length) {
            std::cout << "内置函数调用测试: length 类型 = " << static_cast<int>(length->getType()) 
                      << ", 值: " << length->toString() << std::endl;
        }
    }
}

// 测试控制流语句
void test_control_flow() {
    std::cout << "\n=== 测试控制流语句 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 测试if语句
    std::string script1 = "x = 10; if (x > 5) { result = \"x is greater than 5\"; } else { result = \"x is less than or equal to 5\"; }";
    
    if (interpreter.execute(script1)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "if语句测试: " << result->toString() << std::endl;
        }
    }
    
    // 测试while循环
    interpreter.clearEnvironment();
    std::string script2 = R"(
counter = 0;
sum = 0;
while (counter < 5) {
    sum = sum + counter;
    counter = counter + 1;
}
)";
    
    if (interpreter.execute(script2)) {
        auto sum_value = interpreter.getVariable("sum");
        if (sum_value && sum_value->isInteger()) {
            std::cout << "while循环测试: sum = " << sum_value->getInteger() << std::endl;
        } else if (sum_value) {
            std::cout << "sum 类型: " << static_cast<int>(sum_value->getType()) 
                      << ", 值: " << sum_value->toString() << std::endl;
        }
    }
}

// 测试复杂脚本示例
void test_complex_example() {
    std::cout << "\n=== 测试复杂脚本示例 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 复杂的脚本示例：使用Python进行数据操作
    std::string complex_script = R"(
// 导入必要的模块
import os;

// 定义一些变量
data_dir = "data";
max_files = 10;
current_count1 = 0;
status = "";

// 简单的数据处理逻辑
if (os.path.exists(data_dir)) {
    files = os.listdir(data_dir);
    current_count1 = len(files);
    
    if (current_count1 < max_files) {
        status = "可以添加更多文件";
    } else {
        status = "文件数量已达上限";
    }
} else {
    status = "数据目录不存在";
    os.mkdir(data_dir);
}

// 返回结果
result = {
    "status": status,
    "data_dir": data_dir,
    "current_count": current_count1,
    "max_files": max_files
};
)";
    
    if (interpreter.execute(complex_script)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "复杂脚本执行成功" << std::endl;
            std::cout << "结果: " << result->toString() << std::endl;
        }
    } else {
        std::cout << "复杂脚本执行失败" << std::endl;
    }
}

// 测试错误处理
void test_error_handling() {
    std::cout << "\n=== 测试错误处理 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 测试语法错误
    std::string script1 = "x = ;"; // 语法错误
    if (!interpreter.execute(script1)) {
        std::cout << "语法错误检测成功: " << interpreter.getErrorMessage() << std::endl;
    }
    
    // 测试未定义变量
    interpreter.clearEnvironment();
    std::string script2 = "x = undefined_var;";
    if (!interpreter.execute(script2)) {
        std::cout << "未定义变量错误检测成功: " << interpreter.getErrorMessage() << std::endl;
    }
    
    // 测试类型错误
    interpreter.clearEnvironment();
    std::string script3 = "x = 10 + \"hello\";"; // 类型不匹配
    if (!interpreter.execute(script3)) {
        std::cout << "类型错误检测成功: " << interpreter.getErrorMessage() << std::endl;
    }
}

int main() {
    std::cout << "脚本语言解释器测试程序" << std::endl;
    std::cout << "=========================" << std::endl;
    
    try {
        // 初始化Python解释器（如果尚未初始化）
        if (!Py_IsInitialized()) {
            py::scoped_interpreter guard{};
            
            // 配置Python路径
            py::module_ sys = py::module_::import("sys");
            sys.attr("path").attr("insert")(0, "../python");
            
            // 运行测试
            test_basic_script();
            test_python_integration();
            test_control_flow();
            test_complex_example();
            test_error_handling();
            
        } else {
            // Python解释器已初始化，直接运行测试
            test_basic_script();
            test_python_integration();
            test_control_flow();
            test_complex_example();
            test_error_handling();
        }
        
        std::cout << "\n=== 所有测试完成 ===" << std::endl;
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "测试过程中发生异常: " << e.what() << std::endl;
        return 1;
    }
}
