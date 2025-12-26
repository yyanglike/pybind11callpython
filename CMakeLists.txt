cmake_minimum_required(VERSION 3.15)
project(StockDataCppProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定使用虚拟环境中的 Python 3.12
set(Python3_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.venv)
set(Python3_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/.venv/bin/python3.12)

# 查找Python3
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# 添加pybind11
add_subdirectory(pybind11)

# 包含目录
include_directories(
    ${Python3_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/antlr/generated
    ${CMAKE_CURRENT_SOURCE_DIR}/antlr/generated/antlr
)

# 下载并构建ANTLR4运行时
include(FetchContent)
FetchContent_Declare(
    antlr4
    GIT_REPOSITORY https://github.com/antlr/antlr4.git
    GIT_TAG 4.10.1
)
FetchContent_MakeAvailable(antlr4)

# 添加antlr4运行时库
add_subdirectory(${antlr4_SOURCE_DIR}/runtime/Cpp ${antlr4_BINARY_DIR}/runtime/Cpp)

# 设置ANTLR4的包含目录
include_directories(${antlr4_SOURCE_DIR}/runtime/Cpp/runtime/src)

# 创建可执行文件
add_executable(stock_data_app
    src/main.cpp
    src/stock_data_processor.cpp
)

# 链接Python库
target_link_libraries(stock_data_app
    ${Python3_LIBRARIES}
    pybind11::embed
)

# 设置运行时库路径
if(APPLE)
    set_target_properties(stock_data_app PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "@executable_path/../lib"
    )
endif()

# 动态调用测试程序
add_executable(test_dynamic_call
    test_dynamic_call.cpp
    src/dynamic_python_caller.cpp
)

target_link_libraries(test_dynamic_call
    ${Python3_LIBRARIES}
    pybind11::embed
)

# 模块枚举测试程序
add_executable(test_module_enum
    test_module_enum.cpp
    src/dynamic_python_caller.cpp
)

target_link_libraries(test_module_enum
    ${Python3_LIBRARIES}
    pybind11::embed
)

# 类处理测试程序
add_executable(test_class_handling
    test_class_handling.cpp
    src/dynamic_python_caller.cpp
)

target_link_libraries(test_class_handling
    ${Python3_LIBRARIES}
    pybind11::embed
)

# 脚本解释器测试程序
add_executable(test_script_interpreter
    test_script_interpreter.cpp
    src/script_interpreter.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
    src/python_bridge.cpp
    src/error_handler.cpp
    src/variable_manager.cpp
    src/expression_evaluator.cpp
    src/ast_visitor.cpp
    antlr/generated/antlr/PyScriptLexer.cpp
    antlr/generated/antlr/PyScriptParser.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptVisitor.cpp
    antlr/generated/antlr/PyScriptBaseListener.cpp
    antlr/generated/antlr/PyScriptListener.cpp
)

target_link_libraries(test_script_interpreter
    ${Python3_LIBRARIES}
    pybind11::embed
    antlr4_static
)

# 复杂场景测试程序
add_executable(test_complex_scenario
    test_complex_scenario.cpp
    src/script_interpreter.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
    src/python_bridge.cpp
    src/error_handler.cpp
    src/variable_manager.cpp
    src/expression_evaluator.cpp
    src/ast_visitor.cpp
    antlr/generated/antlr/PyScriptLexer.cpp
    antlr/generated/antlr/PyScriptParser.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptVisitor.cpp
    antlr/generated/antlr/PyScriptBaseListener.cpp
    antlr/generated/antlr/PyScriptListener.cpp
)

target_link_libraries(test_complex_scenario
    ${Python3_LIBRARIES}
    pybind11::embed
    antlr4_static
)

# 简单测试程序
add_executable(test_simple
    test_simple.cpp
    src/script_interpreter.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
    src/python_bridge.cpp
    src/error_handler.cpp
    src/variable_manager.cpp
    src/expression_evaluator.cpp
    src/ast_visitor.cpp
    antlr/generated/antlr/PyScriptLexer.cpp
    antlr/generated/antlr/PyScriptParser.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptVisitor.cpp
    antlr/generated/antlr/PyScriptBaseListener.cpp
    antlr/generated/antlr/PyScriptListener.cpp
)

target_link_libraries(test_simple
    ${Python3_LIBRARIES}
    pybind11::embed
    antlr4_static
)

# 下标赋值测试程序
add_executable(test_subscript_assignment
    test_subscript_assignment.cpp
    src/script_interpreter.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
    src/python_bridge.cpp
    src/error_handler.cpp
    src/variable_manager.cpp
    src/expression_evaluator.cpp
    src/ast_visitor.cpp
    antlr/generated/antlr/PyScriptLexer.cpp
    antlr/generated/antlr/PyScriptParser.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptVisitor.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptListener.cpp
)

target_link_libraries(test_subscript_assignment
    ${Python3_LIBRARIES}
    pybind11::embed
    antlr4_static
)

# 复杂语法测试程序
add_executable(test_complex_syntax
    test_complex_syntax.cpp
    src/script_interpreter.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
    src/python_bridge.cpp
    src/error_handler.cpp
    src/variable_manager.cpp
    src/expression_evaluator.cpp
    src/ast_visitor.cpp
    antlr/generated/antlr/PyScriptLexer.cpp
    antlr/generated/antlr/PyScriptParser.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptVisitor.cpp
    antlr/generated/antlr/PyScriptBaseListener.cpp
    antlr/generated/antlr/PyScriptListener.cpp
)

target_link_libraries(test_complex_syntax
    ${Python3_LIBRARIES}
    pybind11::embed
    antlr4_static
)

# 属性赋值测试程序
add_executable(test_attribute_assignment
    test_attribute_assignment.cpp
    src/script_interpreter.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
    src/python_bridge.cpp
    src/error_handler.cpp
    src/variable_manager.cpp
    src/expression_evaluator.cpp
    src/ast_visitor.cpp
    antlr/generated/antlr/PyScriptLexer.cpp
    antlr/generated/antlr/PyScriptParser.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptVisitor.cpp
    antlr/generated/antlr/PyScriptBaseListener.cpp
    antlr/generated/antlr/PyScriptListener.cpp
)

target_link_libraries(test_attribute_assignment
    ${Python3_LIBRARIES}
    pybind11::embed
    antlr4_static
    gtest_main
)

# 增强功能测试程序
add_executable(test_enhanced_features
    test_enhanced_features.cpp
    src/script_interpreter.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
    src/python_bridge.cpp
    src/error_handler.cpp
    src/variable_manager.cpp
    src/expression_evaluator.cpp
    src/ast_visitor.cpp
    antlr/generated/antlr/PyScriptLexer.cpp
    antlr/generated/antlr/PyScriptParser.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptVisitor.cpp
    antlr/generated/antlr/PyScriptBaseListener.cpp
    antlr/generated/antlr/PyScriptListener.cpp
)

target_link_libraries(test_enhanced_features
    ${Python3_LIBRARIES}
    pybind11::embed
    antlr4_static
)

# Simple runner to execute arbitrary Python scripts from command line
add_executable(run_python_script
    src/run_python_script.cpp
    src/python_bridge.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
)

target_link_libraries(run_python_script
    ${Python3_LIBRARIES}
    pybind11::embed
)

# Runner for .pys scripts (uses ScriptInterpreter)
add_executable(run_pys_script
    src/run_pys_script.cpp
    src/script_interpreter.cpp
    src/script_value.cpp
    src/dynamic_python_caller.cpp
    src/python_bridge.cpp
    src/error_handler.cpp
    src/variable_manager.cpp
    src/expression_evaluator.cpp
    src/ast_visitor.cpp
    antlr/generated/antlr/PyScriptLexer.cpp
    antlr/generated/antlr/PyScriptParser.cpp
    antlr/generated/antlr/PyScriptBaseVisitor.cpp
    antlr/generated/antlr/PyScriptVisitor.cpp
    antlr/generated/antlr/PyScriptBaseListener.cpp
    antlr/generated/antlr/PyScriptListener.cpp
)

target_link_libraries(run_pys_script
    ${Python3_LIBRARIES}
    pybind11::embed
    antlr4_static
)

if(APPLE)
    set_target_properties(test_dynamic_call test_module_enum test_class_handling test_script_interpreter test_complex_scenario test_simple test_subscript_assignment test_complex_syntax test_enhanced_features run_python_script PROPERTIES
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "@executable_path/../lib"
    )
endif()
