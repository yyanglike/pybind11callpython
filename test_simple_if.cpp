#include <iostream>
#include "script_interpreter.h"

int main() {
    std::cout << "Testing simple if statement..." << std::endl;
    
    // 初始化Python解释器（如果需要）
    if (!Py_IsInitialized()) {
        py::scoped_interpreter guard{};
    }
    
    ScriptInterpreter interpreter;
    
    // 测试简单的if语句
    std::string script = "x = 10; if (x > 5) { result = \"greater\"; }";
    
    std::cout << "Executing script: " << script << std::endl;
    
    if (interpreter.execute(script)) {
        auto result = interpreter.getVariable("result");
        if (result) {
            std::cout << "Success! result = " << result->toString() << std::endl;
        } else {
            std::cout << "No result variable found" << std::endl;
        }
    } else {
        std::cout << "Script execution failed: " << interpreter.getErrorMessage() << std::endl;
    }
    
    return 0;
}
