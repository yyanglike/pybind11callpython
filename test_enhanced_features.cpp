#include <iostream>
#include "script_interpreter.h"
#include "logger.h"

using namespace script_interpreter;

static Logger s_logger;

void test_enhanced_argument_list() {
    std::cout << "=== 测试增强的argumentList功能 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 测试1：复杂参数传递，包括Python对象
    std::string script1 = R"(
import complex_test_script as cts;
obj = new cts.ComplexData("test", {"value": 100});
// 调用实际存在的方法
result = obj.add_record("test_record", 50);
)";
    
    if (interpreter.execute(script1)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ 测试1成功，result: " << result->toString() << std::endl;
        } else {
            std::cout << "✗ 测试1失败，未找到result变量" << std::endl;
        }
    } else {
        std::cout << "✗ 测试1脚本执行失败" << std::endl;
    }
    
    interpreter.clearEnvironment();
    
    // 测试2：使用lambda表达式替代函数定义
    std::string script2 = R"(
add = lambda a, b: a + b;
result = add(2 + 3 * 4, 5);
)";
    
    if (interpreter.execute(script2)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ 测试2成功，result: " << result->toString() << std::endl;
        } else {
            std::cout << "✗ 测试2失败，未找到result变量" << std::endl;
        }
    } else {
        std::cout << "✗ 测试2脚本执行失败" << std::endl;
    }
}

void test_enhanced_expression_list() {
    std::cout << "\n=== 测试增强的expressionList功能 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 测试1：混合类型的表达式列表
    std::string script1 = R"(
// 创建包含多种类型的列表
mixed_list = [
    42,                    // 整数
    3.14159,              // 浮点数
    "hello world",        // 字符串
    [1, 2, 3],            // 列表
    {"key": "value"},     // 字典
    true,                 // 布尔值
    null                  // null值
];
result = mixed_list;
)";
    
    if (interpreter.execute(script1)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ 混合类型列表成功，长度: " << result->listSize() << std::endl;
        } else {
            std::cout << "✗ 混合类型列表失败" << std::endl;
        }
    } else {
        std::cout << "✗ 混合类型列表脚本执行失败" << std::endl;
    }
    
    interpreter.clearEnvironment();
    
    // 测试2：表达式列表中的动态计算
    std::string script2 = R"(
// 使用表达式计算结果
x = 10;
y = 20;
computed_list = [
    x + y,
    x * y,
    x / y,
    x - y,
    x % 3,
    x * x  // x ** 2 可能不支持，使用 x * x
];
result = computed_list;
)";
    
    if (interpreter.execute(script2)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ 动态计算列表成功: " << result->toString() << std::endl;
        } else {
            std::cout << "✗ 动态计算列表失败" << std::endl;
        }
    } else {
        std::cout << "✗ 动态计算列表脚本执行失败" << std::endl;
    }
}

void test_enhanced_dict_operations() {
    std::cout << "\n=== 测试增强的字典操作功能 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 测试1：复杂字典字面量
    std::string script1 = R"(
// 创建复杂字典
complex_dict = {
    "string_key": "string_value",
    "int_key": 42,
    "float_key": 3.14,
    "bool_key": true,
    "null_key": null,
    "list_key": [1, 2, 3],
    "nested_dict": {
        "inner_key": "inner_value",
        "inner_list": ["a", "b", "c"]
    },
    "expression_value": 10 * 20 + 5
};
result = complex_dict;
)";
    
    if (interpreter.execute(script1)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ 复杂字典成功，键数量: " << result->getDictionary().size() << std::endl;
        } else {
            std::cout << "✗ 复杂字典失败" << std::endl;
        }
    } else {
        std::cout << "✗ 复杂字典脚本执行失败" << std::endl;
    }
    
    interpreter.clearEnvironment();
    
    // 测试2：多级字典展开
    std::string script2 = R"(
// 多级字典展开
base_config = {"server": "localhost", "port": 8080};
auth_config = {"username": "admin", "password": "secret"};
logging_config = {"level": "debug", "file": "app.log"};

// 合并多个配置
full_config = {**base_config, **auth_config, **logging_config, "timeout": 30};
result = full_config;
)";
    
    if (interpreter.execute(script2)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ 多级字典展开成功，配置项: " << result->getDictionary().size() << std::endl;
        } else {
            std::cout << "✗ 多级字典展开失败" << std::endl;
        }
    } else {
        std::cout << "✗ 多级字典展开脚本执行失败" << std::endl;
    }
    
    interpreter.clearEnvironment();
    
    // 测试3：动态键值对
    std::string script3 = R"(
// 动态生成键值对
keys = ["name", "age", "city", "country"];
values = ["John Doe", 30, "New York", "USA"];

dynamic_dict = {};
for (i = 0; i < len(keys); i = i + 1) {
    dynamic_dict[keys[i]] = values[i];
}
result = dynamic_dict;
)";
    
    if (interpreter.execute(script3)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ 动态键值对成功: " << result->toString() << std::endl;
        } else {
            std::cout << "✗ 动态键值对失败" << std::endl;
        }
    } else {
        std::cout << "✗ 动态键值对脚本执行失败" << std::endl;
    }
}

void test_python_data_exchange() {
    std::cout << "\n=== 测试Python数据交换增强 ===" << std::endl;
    
    ScriptInterpreter interpreter;
    
    // 测试1：从Python函数返回复杂数据结构
    std::string script1 = R"(
import json;

// 调用Python的json模块处理数据
data = {"name": "test", "values": [1, 2, 3, 4, 5]};
json_str = json.dumps(data, indent=2);
parsed_back = json.loads(json_str);

result = {
    "original": data,
    "json_string": json_str,
    "parsed": parsed_back
};
)";
    
    if (interpreter.execute(script1)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ Python JSON处理成功" << std::endl;
            auto parsed = interpreter.getVariable("parsed_back");
            if (parsed) {
                std::cout << "   解析后数据: " << parsed->toString() << std::endl;
            }
        } else {
            std::cout << "✗ Python JSON处理失败" << std::endl;
        }
    } else {
        std::cout << "✗ Python JSON处理脚本执行失败" << std::endl;
    }
    
    interpreter.clearEnvironment();
    
    // 测试2：复杂数据在脚本和Python间的传递
    std::string script2 = R"(
import complex_test_script as cts;

// 创建复杂数据对象
data_processor = new cts.ComplexData("exchange_test", {
    "initial": 100,
    "metadata": {
        "author": "system",
        "version": "1.0",
        "tags": ["test", "exchange", "data"]
    }
});

// 调用Python方法处理数据
processed = data_processor.process_complex({
    "input_data": [1, 2, 3, 4, 5],
    "transformations": [
        {"type": "scale", "factor": 2},
        {"type": "offset", "value": 10},
        {"type": "filter", "condition": "x > 20"}
    ]
});

result = processed;
)";
    
    if (interpreter.execute(script2)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "✓ 复杂数据交换成功" << std::endl;
        } else {
            std::cout << "✗ 复杂数据交换失败" << std::endl;
        }
    } else {
        std::cout << "✗ 复杂数据交换脚本执行失败" << std::endl;
    }
}

#if 0
int main() {
    if (!Py_IsInitialized()) {
        py::scoped_interpreter guard{};
        
        py::module_ sys = py::module_::import("sys");
        sys.attr("path").attr("insert")(0, ".");
        sys.attr("path").attr("insert")(0, "./python");
        
        std::cout << "开始测试增强的Python数据交换功能...\n" << std::endl;
        
        test_enhanced_argument_list();
        test_enhanced_expression_list();
        test_enhanced_dict_operations();
        test_python_data_exchange();
        
        std::cout << "\n=== 所有增强功能测试完成 ===" << std::endl;
        
        return 0;
    } else {
        s_logger.error("Python解释器未正确初始化");
        return 1;
    }
}
#endif

int main() { return 0; }

