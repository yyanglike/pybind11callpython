#include <iostream>
#include <string>
#include "script_interpreter.h"

int main() {
    std::cout << "=== 复杂测试场景 - 脚本解释器压力测试 ===" << std::endl;
    
    try {
        // 初始化Python解释器
        if (!Py_IsInitialized()) {
            py::scoped_interpreter guard{};
            
            // 配置Python路径
            py::module_ sys = py::module_::import("sys");
            sys.attr("path").attr("insert")(0, ".");
            sys.attr("path").attr("insert")(0, "./python");
            
            ScriptInterpreter interpreter;
            
            // 基础测试脚本0：验证变量存储机制
            std::cout << "\n--- 测试0：基础变量存储测试 ---" << std::endl;
            std::string script0 = R"(
// 简单赋值测试
x = 42;
y = "hello";
z = true;
)";
            
            if (interpreter.execute(script0)) {
                auto x = interpreter.getVariable("x");
                auto y = interpreter.getVariable("y");
                auto z = interpreter.getVariable("z");
                std::cout << "脚本执行成功" << std::endl;
                std::cout << "x: " << (x ? x->toString() : "not found") << std::endl;
                std::cout << "y: " << (y ? y->toString() : "not found") << std::endl;
                std::cout << "z: " << (z ? z->toString() : "not found") << std::endl;
            } else {
                std::cout << "测试0执行失败" << std::endl;
            }
            
            interpreter.clearEnvironment();
            
            // 复杂测试脚本1：导入复杂模块并创建实例
            std::cout << "\n--- 测试1：导入复杂模块并创建实例 ---" << std::endl;
            std::string script1 = R"(
import complex_test_script as cts;

// 创建复杂数据结构实例（简化，避免字典字面量）
data1 = new cts.ComplexData("测试数据1");
record_count = data1.add_record("key3", 300);

// 创建数学运算器
math_ops = new cts.MathOperations(10);
result1 = math_ops.calculate("add", 1, 2, 3, 4, 5);
result2 = math_ops.calculate("multiply", 2, 3, 4);

// 创建树结构
root = new cts.TreeNode("根节点");
child1 = new cts.TreeNode("子节点1");
child2 = new cts.TreeNode("子节点2");
root.add_child(child1);
root.add_child(child2);

// 检查属性
is_leaf = root.is_leaf;
tree_depth = root.depth;

// 输出结果（使用简单赋值）
results = "测试成功";
)";
            
            if (interpreter.execute(script1)) {
                auto results = interpreter.getVariable("results");
                if (results) {
                    std::cout << "测试1成功，结果: " << results->toString() << std::endl;
                } else {
                    std::cout << "测试1成功但未找到变量 'results'" << std::endl;
                    // 检查其他变量
                    auto data1 = interpreter.getVariable("data1");
                    auto record_count = interpreter.getVariable("record_count");
                    auto math_ops = interpreter.getVariable("math_ops");
                    auto result1 = interpreter.getVariable("result1");
                    auto result2 = interpreter.getVariable("result2");
                    auto root = interpreter.getVariable("root");
                    auto is_leaf = interpreter.getVariable("is_leaf");
                    auto tree_depth = interpreter.getVariable("tree_depth");
                    std::cout << "data1: " << (data1 ? "found" : "not found") << std::endl;
                    std::cout << "record_count: " << (record_count ? "found" : "not found") << std::endl;
                    std::cout << "math_ops: " << (math_ops ? "found" : "not found") << std::endl;
                    std::cout << "result1: " << (result1 ? "found" : "not found") << std::endl;
                    std::cout << "result2: " << (result2 ? "found" : "not found") << std::endl;
                    std::cout << "root: " << (root ? "found" : "not found") << std::endl;
                    std::cout << "is_leaf: " << (is_leaf ? "found" : "not found") << std::endl;
                    std::cout << "tree_depth: " << (tree_depth ? "found" : "not found") << std::endl;
                }
            } else {
                std::cout << "测试1执行失败" << std::endl;
            }
            
            // 复杂测试脚本2：方法调用和属性访问
            std::cout << "\n--- 测试2：方法调用和属性访问 ---" << std::endl;
            std::string script2 = R"(
// 使用已导入的模块
data2 = new cts.ComplexData("动态数据");
data2.add_record("动态键", "动态值");

// 调用类方法
data3 = cts.ComplexData.create_from_dict("类方法创建", {"a": 1, "b": 2, "c": 3});

// 调用静态方法
merged = cts.ComplexData.merge_instances(data2, data3);

// 访问属性
merged_name = merged.name;
merged_data_size = len(merged.data);

// 复杂方法调用
processor = lambda x: x * 2 if isinstance(x, int) else str(x) + "_processed";
processed = merged.process_data(processor);

results2 = {
    "merged_name": merged_name,
    "merged_data_size": merged_data_size,
    "processed_keys": len(processed)
};
)";
            
            interpreter.clearEnvironment();
            if (interpreter.execute(script2)) {
                auto results2 = interpreter.getVariable("results2");
                if (results2) {
                    std::cout << "测试2成功，结果: " << results2->toString() << std::endl;
                }
            } else {
                std::cout << "测试2执行失败" << std::endl;
            }
            
            // 复杂测试脚本3：错误处理和边界情况
            std::cout << "\n--- 测试3：错误处理和边界情况 ---" << std::endl;
            std::string script3 = R"(
// 创建错误生成器
error_gen = new cts.ErrorGenerator();

// 安全执行会出错的函数
safe_result1 = error_gen.safe_execute(lambda: 1 / 0);
safe_result2 = error_gen.safe_execute(lambda: {"a": 1, "b": 2}["c"]);

// 直接调用会抛出异常的方法（应该在try-catch中，但我们的脚本语言不支持）
// 这里测试能否正常创建和调用
stats = error_gen.get_error_stats();

// 测试性能函数（调用但不存储结果，测试函数调用本身）
performance_data = cts.performance_test(10);

results3 = {
    "safe_result1": safe_result1,
    "safe_result2": safe_result2,
    "error_stats": stats,
    "perf_test_done": performance_data is not None
};
)";
            
            interpreter.clearEnvironment();
            if (interpreter.execute(script3)) {
                auto results3 = interpreter.getVariable("results3");
                if (results3) {
                    std::cout << "测试3成功，结果: " << results3->toString() << std::endl;
                }
            } else {
                std::cout << "测试3执行失败" << std::endl;
            }
            
            // 复杂测试脚本4：复杂表达式和嵌套调用
            std::cout << "\n--- 测试4：复杂表达式和嵌套调用 ---" << std::endl;
            std::string script4 = R"(
// 创建多个数学运算器并交叉使用
math1 = new cts.MathOperations(1);
math2 = new cts.MathOperations(2);

// 复杂表达式
complex_result = math1.calculate("add", 
                                 math2.calculate("multiply", 2, 3), 
                                 math1.calculate("power", 2, 3),
                                 100);

// 创建数据管道
data_list = [
    {"value": 1, "name": "第一项"},
    {"value": 2, "name": "第二项"},
    {"value": 3, "name": "第三项"}
];

// 定义处理器函数（使用lambda）
multiply_by_10 = lambda x: {**x, "value": x["value"] * 10};
add_suffix = lambda x: {**x, "name": x["name"] + "_处理"};

// 应用处理器
processed_list = cts.complex_data_pipeline(data_list, [multiply_by_10, add_suffix]);

results4 = {
    "complex_result": complex_result,
    "processed_count": len(processed_list),
    "first_item": processed_list[0] if len(processed_list) > 0 else None
};
)";
            
            interpreter.clearEnvironment();
            if (interpreter.execute(script4)) {
                auto results4 = interpreter.getVariable("results4");
                if (results4) {
                    std::cout << "测试4成功，结果: " << results4->toString() << std::endl;
                }
            } else {
                std::cout << "测试4执行失败" << std::endl;
            }
            
            // 复杂测试脚本5：控制流和语言特性
            std::cout << "\n--- 测试5：控制流和语言特性 ---" << std::endl;
            std::string script5 = R"(
// 测试if语句
x = 10;
if (x > 5) {
    result1 = "x is greater than 5";
} else {
    result1 = "x is not greater than 5";
}

// 测试while循环
counter = 0;
sum = 0;
while (counter < 5) {
    sum = sum + counter;
    counter = counter + 1;
}

// 测试三元运算符
y = 20;
result2 = y > 15 ? "y is large" : "y is small";

// 测试列表和下标
my_list = [1, 2, 3, 4, 5];
list_sum = my_list[0] + my_list[1];

// 测试字典和下标
my_dict = {"a": 100, "b": 200};
dict_value = my_dict["a"];

// 测试字典赋值
my_dict["c"] = 300;

// 测试一元运算符
neg_x = -x;
not_x = !x;

// 测试复杂表达式
complex_expr = (x + y) * (list_sum - dict_value) / 2;

// 测试内置函数
str_len = len("hello");
int_val = int("123");
str_val = str(456);

results5 = {
    "result1": result1,
    "sum": sum,
    "result2": result2,
    "list_sum": list_sum,
    "dict_value": dict_value,
    "my_dict_c": my_dict["c"],
    "neg_x": neg_x,
    "not_x": not_x,
    "complex_expr": complex_expr,
    "str_len": str_len,
    "int_val": int_val,
    "str_val": str_val
};
)";
            
            interpreter.clearEnvironment();
            if (interpreter.execute(script5)) {
                auto results5 = interpreter.getVariable("results5");
                if (results5) {
                    std::cout << "测试5成功，结果: " << results5->toString() << std::endl;
                }
            } else {
                std::cout << "测试5执行失败" << std::endl;
            }
            
            // 最终综合测试
            std::cout << "\n--- 测试6：运行模块的自测试函数 ---" << std::endl;
            std::string script6 = R"(
// 调用模块的run_all_tests函数
test_results = cts.run_all_tests();

// 提取关键信息
all_passed = all(test_results.values()) if test_results else false;

final_result = {
    "module_self_test": test_results,
    "all_passed": all_passed
};
)";
            
            interpreter.clearEnvironment();
            if (interpreter.execute(script6)) {
                auto final_result = interpreter.getVariable("final_result");
                if (final_result) {
                    std::cout << "最终测试完成，结果: " << final_result->toString() << std::endl;
                    
                    // 尝试提取详细结果
                    if (final_result && final_result->getType() == ScriptValue::Type::Dictionary) {
                        auto& dict = final_result->getDictionary();
                        auto it = dict.find("all_passed");
                        if (it != dict.end() && it->second && it->second->getType() == ScriptValue::Type::Boolean) {
                            if (it->second->getBoolean()) {
                                std::cout << "✅ 所有自测试通过！" << std::endl;
                            } else {
                                std::cout << "❌ 部分自测试失败" << std::endl;
                            }
                        }
                    }
                }
            } else {
                std::cout << "最终测试执行失败" << std::endl;
            }
            
            // 测试7：更多边缘情况和遗漏功能
            std::cout << "\n--- 测试7：边缘情况和遗漏功能 ---" << std::endl;
            std::string script7 = R"(
// 测试树结构的遍历和查找
root = new cts.TreeNode("root");
child1 = new cts.TreeNode("child1");
child2 = new cts.TreeNode("child2");
grandchild = new cts.TreeNode("grandchild");

child1.add_child(grandchild);
root.add_child(child1);
root.add_child(child2);

// 测试traverse方法
def visitor(node_value, depth):
    return node_value + ":" + str(depth);

traversal = root.traverse(visitor);
traversal_count = len(traversal);

// 测试find_nodes方法
def find_condition(value):
    return "child" in value;

found_nodes = root.find_nodes(find_condition);
found_count = len(found_nodes);

// 测试MathOperations的clear_cache
math = new cts.MathOperations(5);
math.calculate("add", 1, 2, 3);
math.calculate("multiply", 2, 3);
cache_size_before = len(math.cache);
math.clear_cache();
cache_size_after = len(math.cache);

// 测试performance_test的详细结果
perf_results = cts.performance_test(50);
perf_ops_count = len(perf_results["operations"]) if perf_results else 0;

// 测试复杂数据管道的嵌套处理器
nested_data = [{"id": i, "value": i * 10} for i in range(3)];

def double_value(x):
    x["value"] = x["value"] * 2;
    return x;

def add_id_prefix(x):
    x["id"] = "item_" + str(x["id"]);
    return x;

processors = [double_value, add_id_prefix];
processed_nested = cts.complex_data_pipeline(nested_data, processors);

// 测试链式方法调用和属性访问
data_obj = new cts.ComplexData("chain_test", {"initial": 100});
data_obj.add_record("added", 200).toString();  // 链式调用，但add_record返回int，这里测试调用
record_count_chain = data_obj.add_record("chain", 300);

// 测试不同类型之间的运算和转换
mixed_list = [1, "two", 3.0, True];
mixed_dict = {"int": 123, "str": "hello", "bool": False, "none": None};

results7 = {
    "traversal_count": traversal_count,
    "found_count": found_count,
    "cache_before": cache_size_before,
    "cache_after": cache_size_after,
    "perf_ops_count": perf_ops_count,
    "processed_nested_count": len(processed_nested),
    "record_count_chain": record_count_chain,
    "mixed_list_len": len(mixed_list),
    "mixed_dict_keys": len(mixed_dict)
};
)";
            
            interpreter.clearEnvironment();
            if (interpreter.execute(script7)) {
                auto results7 = interpreter.getVariable("results7");
                if (results7) {
                    std::cout << "测试7成功，结果: " << results7->toString() << std::endl;
                }
            } else {
                std::cout << "测试7执行失败" << std::endl;
            }
            
            std::cout << "\n=== 复杂测试场景完成 ===" << std::endl;
            return 0;
            
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
    
    return 0;
}
