#include <iostream>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <string>
#include <vector>

namespace py = pybind11;

// 动态调用Python函数的辅助函数
py::object dynamic_call(py::object func, py::args args = py::args{}, py::kwargs kwargs = py::kwargs{}) {
    return func(*args, **kwargs);
}

// 获取函数签名的辅助函数
void print_function_signature(py::object func) {
    try {
        py::module_ inspect = py::module_::import("inspect");
        py::object signature = inspect.attr("signature")(func);
        std::cout << "函数签名: " << py::str(signature).cast<std::string>() << std::endl;
        
        // 获取参数信息
        py::object parameters = signature.attr("parameters");
        int param_count = py::len(parameters);
        std::cout << "参数数量: " << param_count << std::endl;
        
        // 遍历参数
        for (auto item : parameters) {
            py::object param_name = py::reinterpret_borrow<py::object>(item);  // 键是参数名
            py::object param_obj = parameters[param_name];
            
            std::string name = param_name.cast<std::string>();
            py::object default_value = param_obj.attr("default");
            bool has_default = !default_value.is(py::none());
            
            std::cout << "  参数: " << name;
            if (has_default) {
                std::cout << " (默认值: " << py::str(default_value).cast<std::string>() << ")";
            }
            std::cout << std::endl;
        }
    } catch (const py::error_already_set& e) {
        std::cout << "无法获取函数签名: " << e.what() << std::endl;
    }
}

#if 0
int main() {
    // 初始化Python解释器
    py::scoped_interpreter guard{};
    
    try {
        // 添加python目录到Python路径
        py::module_ sys = py::module_::import("sys");
        py::list path = sys.attr("path");
        // 添加项目根目录下的python目录（相对于build目录）
        std::string pythonPath = "../python";
        path.insert(0, pythonPath);
        
        // 导入动态函数模块
        py::module_ dynamic_funcs = py::module_::import("dynamic_funcs");
        
        std::cout << "========================================" << std::endl;
        std::cout << "Python函数动态调用演示" << std::endl;
        std::cout << "========================================" << std::endl;
        
        // 测试1: 无参数函数
        {
            std::cout << "\n1. 测试无参数函数:" << std::endl;
            py::object func = dynamic_funcs.attr("func_no_args");
            print_function_signature(func);
            
            py::object result = dynamic_call(func);
            std::cout << "结果: " << result.cast<std::string>() << std::endl;
        }
        
        // 测试2: 一个参数函数
        {
            std::cout << "\n2. 测试一个参数函数:" << std::endl;
            py::object func = dynamic_funcs.attr("func_one_arg");
            print_function_signature(func);
            
            py::object result = dynamic_call(func, py::make_tuple(100));
            std::cout << "结果: " << result.cast<std::string>() << std::endl;
        }
        
        // 测试3: 两个参数函数
        {
            std::cout << "\n3. 测试两个参数函数:" << std::endl;
            py::object func = dynamic_funcs.attr("func_two_args");
            print_function_signature(func);
            
            py::object result = dynamic_call(func, py::make_tuple(1, 2));
            std::cout << "结果: " << result.cast<std::string>() << std::endl;
        }
        
        // 测试4: 带默认参数的函数
        {
            std::cout << "\n4. 测试带默认参数的函数:" << std::endl;
            py::object func = dynamic_funcs.attr("func_default_args");
            print_function_signature(func);
            
            // 使用默认参数
            py::object result1 = dynamic_call(func);
            std::cout << "使用默认参数结果: " << result1.cast<std::string>() << std::endl;
            
            // 提供参数
            py::object result2 = dynamic_call(func, py::make_tuple(30, 40));
            std::cout << "提供参数结果: " << result2.cast<std::string>() << std::endl;
            
            // 只提供一个参数（使用一个默认值）
            py::object result3 = dynamic_call(func, py::make_tuple(50));
            std::cout << "提供一个参数结果: " << result3.cast<std::string>() << std::endl;
        }
        
        // 测试5: 可变位置参数函数
        {
            std::cout << "\n5. 测试可变位置参数函数:" << std::endl;
            py::object func = dynamic_funcs.attr("func_var_args");
            print_function_signature(func);
            
            // 传递多个位置参数
            py::object result = dynamic_call(func, py::make_tuple(1, 2, 3, 4, 5));
            std::cout << "结果: " << result.cast<std::string>() << std::endl;
        }
        
        // 测试6: 可变关键字参数函数
        {
            std::cout << "\n6. 测试可变关键字参数函数:" << std::endl;
            py::object func = dynamic_funcs.attr("func_kwargs");
            print_function_signature(func);
            
            // 使用kwargs传递参数
            py::kwargs kwargs;
            kwargs["a"] = 1;
            kwargs["b"] = 2;
            kwargs["c"] = "test";
            
            py::object result = dynamic_call(func, py::args{}, kwargs);
            std::cout << "结果: " << result.cast<std::string>() << std::endl;
        }
        
        // 测试7: 混合参数函数
        {
            std::cout << "\n7. 测试混合参数函数:" << std::endl;
            py::object func = dynamic_funcs.attr("func_mixed");
            print_function_signature(func);
            
            // 使用args和kwargs
            py::args args = py::make_tuple(10, 20, 30, 40);
            py::kwargs kwargs;
            kwargs["extra"] = 50;
            kwargs["name"] = "test";
            
            py::object result = dynamic_call(func, args, kwargs);
            std::cout << "结果: " << result.cast<std::string>() << std::endl;
        }
        
        // 测试8: 动态调用任意函数
        {
            std::cout << "\n8. 动态调用任意函数:" << std::endl;
            
            // 从字符串获取函数名
            std::vector<std::string> func_names = {
                "func_no_args",
                "func_one_arg", 
                "func_two_args"
            };
            
            for (const auto& func_name : func_names) {
                std::cout << "\n调用函数: " << func_name << std::endl;
                try {
                    py::object func = dynamic_funcs.attr(func_name.c_str());
                    
                    // 根据函数名决定参数
                    if (func_name == "func_no_args") {
                        py::object result = dynamic_call(func);
                        std::cout << "结果: " << result.cast<std::string>() << std::endl;
                    } else if (func_name == "func_one_arg") {
                        py::object result = dynamic_call(func, py::make_tuple(999));
                        std::cout << "结果: " << result.cast<std::string>() << std::endl;
                    } else if (func_name == "func_two_args") {
                        py::object result = dynamic_call(func, py::make_tuple(77, 88));
                        std::cout << "结果: " << result.cast<std::string>() << std::endl;
                    }
                } catch (const py::error_already_set& e) {
                    std::cout << "错误: " << e.what() << std::endl;
                }
            }
        }
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "演示完成!" << std::endl;
        std::cout << "========================================" << std::endl;
        
    } catch (const py::error_already_set& e) {
        std::cerr << "Python错误: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "C++错误: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
#endif

int main() { return 0; }
