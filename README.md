# PyScript Interpreter (C++ + pybind11)

本项目提供一个简化的 Python 方言解释器与运行器，基于 ANTLR4 生成语法树，C++（pybind11）执行语义。核心目标：在 C++ 环境中解析并执行 `.pys` 脚本，支持常见 Python 语法特性（f-string、多种推导式、生成器表达式等），并可调用内置/外部 Python 模块。

## 目录与构建

```
pybind11callpython/
├── CMakeLists.txt
├── build.sh                  # 构建脚本（保留）
├── cleanup.sh
├── antlr/                    # 语法定义（PyScript.g4）
├── antlr/generated/          # ANTLR 生成文件（构建后产生）
├── include/                  # 头文件（解释器、AST 访问器等）
├── src/                      # C++ 源码
├── python/                   # 示例/测试脚本与数据
├── docs/                     # 技术文档与兼容性计划
└── README.md                 # 本文档
```

> 编译脚本 `build.sh` 请保留；也可使用手工 CMake 构建（见下）。

### 构建要求
- CMake ≥ 3.15，C++17 编译器
- Python 3.12（内嵌运行），pybind11 已作为子目录
- ANTLR4 工具（生成语法）：`antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4 2>&1`

### 一键构建
```bash
./build.sh
```

### 手动构建
```bash
mkdir -p build && cd build
cmake ..
cmake --build . --target run_pys_script
```

## 运行 `.pys` 脚本

构建完成后，使用运行器执行脚本：
```bash
./build/run_pys_script path/to/script.pys
```
示例批量运行（项目根目录下所有 `.pys`）：
```bash
for f in *.pys python/*.pys; do ./build/run_pys_script "$f" || break; done
```

## 支持的语言特性（已实现）
- **f-string**：支持单/双/三引号（含多行）与格式说明符（如 `:0>6.2f`），预处理为 `__fstr__` 调用并在当前变量/模块作用域内 `eval`。
- **推导式**：list/dict/set 推导显式循环求值，无 eval；生成器表达式通过 Python 辅助生成器保持惰性。
- **控制流与表达式**：if/while/for、算术/比较/逻辑运算、字典解包等。
- **函数定义**：完整 Python 语法，函数体文本通过缩进扫描提取并 `exec` 定义。
- **sys.argv**：执行前统一初始化为非空列表，避免脚本访问 None。

## 主要组件
- `antlr/PyScript.g4`：语法定义，运行 ANTLR 生成到 `antlr/generated/`。
- `src/script_interpreter.cpp`：入口解释器，负责 f-string 预处理、sys.argv 注入、AST 遍历入口。
- `src/ast_visitor.cpp`：语义执行核心，处理表达式、推导式、生成器、导入、函数定义等。
- `include/*.h`：对外接口、变量管理、错误处理、Python 桥接等。

## 常用指令
- 生成语法代码：`antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4 2>&1`
- 构建运行器：`cmake --build build --target run_pys_script`
- 运行单测脚本：`./build/run_pys_script test_xxx.pys`

## 现有能力与边界
- 已支持：f-string（含多行与格式）、list/dict/set 推导、生成器表达式惰性执行、局部 import、基本异常收集。
- 未覆盖：async/await 等异步语法；对 None 参与某些一元/关系运算仍需谨慎（将产生脚本错误）。
- 并发：单实例非线程安全；若多线程使用，请为每线程独立创建解释器实例并在进入 Python 时获取 GIL。

## 故障排查
- 构建缺少 ANTLR 生成物：先运行 ANTLR 命令生成 `antlr/generated/`，再重建。
- 运行时报 f-string/生成器语法：确认脚本路径与预处理开启，必要时在日志级别调高（logger 配置在源码中）。
- sys.argv 为 None：确认使用 `run_pys_script` 启动，运行器会自动注入占位 argv。

## 参考文档
- `docs/compatibility_plan.md`：特性兼容性与回归计划
- `SCRIPT_LANGUAGE_SPECIFICATION.md`：语言规范与示例
- `TECHNICAL_DOCUMENT.md`：架构与设计细节

