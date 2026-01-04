# PyScript Interpreter (C++ + pybind11)

本项目提供一个简化的 Python 方言解释器与运行器，基于 ANTLR4 生成语法树，C++（pybind11）执行语义。核心目标：在 C++ 环境中解析并执行 `.pys` 脚本，支持常见 Python 语法特性（f-string、多种推导式、生成器表达式等），并可调用内置/外部 Python 模块。

## 目录与构建

```
pybind11callpython/
├── CMakeLists.txt
├── setup.sh                  # 一键设置脚本（推荐）
├── Makefile                  # 便捷命令
├── requirements.txt          # Python依赖
├── build.sh                  # 构建脚本（保留）
├── install.sh                # 安装脚本（可选）
├── Dockerfile                # Docker支持
├── antlr/                    # 语法定义（PyScript.g4）
├── antlr/generated/          # ANTLR 生成文件（构建后产生）
├── include/                  # 头文件（解释器、AST 访问器等）
├── src/                      # C++ 源码
├── python/                   # 示例/测试脚本与数据
├── docs/                     # 技术文档与兼容性计划
└── README.md                 # 本文档
```

### 构建要求
- **CMake** ≥ 3.15，C++17 编译器（g++/clang++）
- **Python** 3.12+（内嵌运行）
- **ANTLR4** 工具（用于生成语法解析器）
- **Git**（用于克隆pybind11）

### 快速开始（推荐）

#### 方法1: 使用一键设置脚本（最简单）
```bash
# 一键设置：创建虚拟环境、安装依赖、构建项目
./setup.sh

# 运行脚本
./build/run_pys_script python/test_hello.pys
```

#### 方法2: 使用Makefile（便捷）
```bash
# 一键设置
make setup

# 运行脚本
make run SCRIPT=python/test_hello.pys

# 运行测试
make test

# 查看所有命令
make help
```

#### 方法3: 手动构建（传统方式）
```bash
# 1. 创建虚拟环境
python3 -m venv .venv
source .venv/bin/activate

# 2. 安装Python依赖
pip install -r requirements.txt

# 3. 生成ANTLR代码
antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4

# 4. 构建项目
mkdir -p build && cd build
cmake ..
cmake --build . --target run_pys_script
```

### 安装到系统（可选）

安装后可以在任何地方使用 `pyscript` 命令：

```bash
# 方法1: 使用安装脚本
sudo ./install.sh

# 方法2: 使用Makefile
make install

# 使用
pyscript python/test_hello.pys

# 卸载
make uninstall
```

## 运行 `.pys` 脚本

构建完成后，使用运行器执行脚本：
```bash
./build/run_pys_script path/to/script.pys
```

### 运行测试

项目提供了统一的测试脚本：

```bash
# 运行所有测试
./scripts/test.sh

# 运行新功能测试
./scripts/test.sh new

# 运行简单测试
./scripts/test.sh simple

# 列出所有测试用例
./scripts/test.sh list

# 运行指定测试并生成报告
./scripts/test.sh all --report
```

### 缓存性能测试

```bash
# 快速缓存性能对比（前10个用例）
./scripts/test_cache.sh quick

# 完整缓存一致性验证（所有用例）
./scripts/test_cache.sh full

# 对比指定脚本的缓存性能
./scripts/test_cache.sh compare --script python/test_cache_performance.pys
```

示例批量运行（python 目录下所有 `.pys`）：
```bash
for f in python/*.pys; do ./build/run_pys_script "$f" || break; done
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

## 部署说明

### 虚拟环境管理

项目使用Python虚拟环境来隔离依赖。虚拟环境会自动创建在 `.venv/` 目录。

**激活虚拟环境**：
```bash
source .venv/bin/activate
```

**退出虚拟环境**：
```bash
deactivate
```

### Docker部署（可选）

```bash
# 构建Docker镜像
docker build -t pyscript-interpreter .

# 运行容器
docker run --rm pyscript-interpreter python/test_hello.pys

# 挂载本地脚本目录
docker run --rm -v $(pwd)/python:/scripts pyscript-interpreter /scripts/test_hello.pys
```

### 依赖管理

Python依赖定义在 `requirements.txt` 中。主要依赖包括：
- `numpy` - 数值计算（测试脚本使用）
- `pandas` - 数据处理（测试脚本使用）

**安装依赖**：
```bash
source .venv/bin/activate
pip install -r requirements.txt
```

**更新依赖**：
```bash
pip install --upgrade -r requirements.txt
```

### 环境变量

可以通过环境变量控制行为：

- `PYS_CACHE=0` - 禁用缓存（等同于 `--no-cache`）
- `PYS_CACHE=1` - 启用缓存（默认）
- `PYS_STATS=1` - 显示性能统计（等同于 `--stats`）

## 故障排查

- **构建缺少 ANTLR 生成物**：先运行 `make antlr` 或 `antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4`，再重建。
- **Python版本不匹配**：确保使用Python 3.12+，检查 `python3 --version`
- **虚拟环境问题**：删除 `.venv` 目录，重新运行 `./setup.sh`
- **运行时报 f-string/生成器语法**：确认脚本路径与预处理开启，必要时在日志级别调高（logger 配置在源码中）。
- **sys.argv 为 None**：确认使用 `run_pys_script` 启动，运行器会自动注入占位 argv。
- **找不到模块**：确保虚拟环境已激活，且已安装所需依赖

## 参考文档
- `docs/compatibility_plan.md`：特性兼容性与回归计划
- `SCRIPT_LANGUAGE_SPECIFICATION.md`：语言规范与示例
- `TECHNICAL_DOCUMENT.md`：架构与设计细节




cd /Users/yangyi/company/python/pybind11callpython && echo "=== 批量测试所有用例 ===" && echo "" && PASSED=0 && FAILED=0 && TOTAL=0 && for file in $(find python -name "*.pys" -type f | sort); do TOTAL=$((TOTAL + 1)); name=$(basename "$file"); echo -n "[$TOTAL/147] $name... "; if timeout 600 ./build/run_pys_script "$file" >/dev/null 2>&1; then echo "✓"; PASSED=$((PASSED + 1)); else echo "✗"; FAILED=$((FAILED + 1)); fi; if [ $((TOTAL % 20)) -eq 0 ]; then echo "[进度: $TOTAL/147, 通过: $PASSED, 失败: $FAILED]"; fi; done && echo "" && echo "=== 测试总结 ===" && echo "总计: $TOTAL" && echo "通过: $PASSED" && echo "失败: $FAILED"


test_new_grammar_features.pys
test_syntax_features.pys
test_tuple_literal.pys