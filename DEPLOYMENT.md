# 部署指南

本文档详细说明如何部署PyScript Interpreter项目，包括虚拟环境管理、依赖安装、构建和运行。

## 快速开始

### 方法1: 一键设置（推荐）

```bash
# 运行一键设置脚本
./setup.sh

# 运行脚本
./build/run_pys_script python/test_hello.pys
```

这个脚本会自动：
1. 检查系统依赖（Python、CMake、ANTLR4）
2. 创建Python虚拟环境
3. 安装Python依赖
4. 克隆pybind11（如果不存在）
5. 生成ANTLR代码
6. 构建项目

### 方法2: 使用Makefile

```bash
# 查看所有可用命令
make help

# 一键设置
make setup

# 运行脚本
make run SCRIPT=python/test_hello.pys

# 运行测试
make test
```

## 系统要求

### 必需依赖

- **Python** 3.12+（推荐3.12）
- **CMake** 3.15+
- **C++17编译器**（g++/clang++）
- **ANTLR4**（用于生成语法解析器）

### 安装系统依赖

#### macOS
```bash
# 使用Homebrew
brew install python@3.12 cmake antlr
```

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install -y \
    python3.12 \
    python3.12-venv \
    cmake \
    build-essential \
    antlr4
```

#### CentOS/RHEL
```bash
sudo yum install -y \
    python3.12 \
    python3.12-devel \
    cmake \
    gcc-c++ \
    antlr4
```

## 详细部署步骤

### 1. 克隆项目

```bash
git clone <repository-url>
cd pybind11callpython
```

### 2. 创建虚拟环境

```bash
# 创建虚拟环境
python3 -m venv .venv

# 激活虚拟环境
source .venv/bin/activate  # Linux/macOS
# 或
.venv\Scripts\activate  # Windows
```

### 3. 安装Python依赖

```bash
# 确保虚拟环境已激活
pip install --upgrade pip
pip install -r requirements.txt
```

### 4. 准备ANTLR代码

```bash
# 检查ANTLR4是否安装
antlr4 --version

# 生成ANTLR代码
antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4
```

### 5. 构建项目

```bash
# 创建构建目录
mkdir -p build
cd build

# 配置CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# 编译
cmake --build . --target run_pys_script -j$(nproc)  # Linux
# 或
cmake --build . --target run_pys_script -j$(sysctl -n hw.ncpu)  # macOS
```

### 6. 验证安装

```bash
# 运行测试脚本
./build/run_pys_script python/test_hello.pys

# 查看帮助
./build/run_pys_script --help
```

## 虚拟环境管理

### 激活虚拟环境

```bash
# Linux/macOS
source .venv/bin/activate

# Windows
.venv\Scripts\activate
```

### 退出虚拟环境

```bash
deactivate
```

### 重新创建虚拟环境

如果虚拟环境出现问题，可以删除并重新创建：

```bash
# 删除旧环境
rm -rf .venv

# 重新创建
python3 -m venv .venv
source .venv/bin/activate
pip install --upgrade pip
pip install -r requirements.txt
```

## 安装到系统（可选）

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

## Docker部署

### 构建Docker镜像

```bash
docker build -t pyscript-interpreter .
```

### 运行容器

```bash
# 运行脚本
docker run --rm pyscript-interpreter python/test_hello.pys

# 挂载本地脚本目录
docker run --rm -v $(pwd)/python:/scripts pyscript-interpreter /scripts/test_hello.pys

# 交互式运行
docker run --rm -it -v $(pwd):/workspace pyscript-interpreter bash
```

### Docker Compose（可选）

创建 `docker-compose.yml`：

```yaml
version: '3.8'
services:
  pyscript:
    build: .
    volumes:
      - ./python:/scripts
    command: /scripts/test_hello.pys
```

运行：
```bash
docker-compose up
```

## 环境变量

可以通过环境变量控制程序行为：

```bash
# 禁用缓存
export PYS_CACHE=0
./build/run_pys_script python/test_hello.pys

# 启用性能统计
export PYS_STATS=1
./build/run_pys_script python/test_hello.pys

# 组合使用
PYS_CACHE=0 PYS_STATS=1 ./build/run_pys_script python/test_hello.pys
```

## 常见问题

### 1. Python版本不匹配

**问题**：CMake找不到正确的Python版本

**解决**：
```bash
# 指定Python路径
cmake .. -DPython3_EXECUTABLE=$(which python3.12)
```

### 2. 虚拟环境路径问题

**问题**：CMakeLists.txt中硬编码了虚拟环境路径

**解决**：确保虚拟环境在项目根目录的 `.venv/` 下，或修改 `CMakeLists.txt` 中的路径。

### 3. ANTLR4未找到

**问题**：`antlr4: command not found`

**解决**：
```bash
# macOS
brew install antlr

# Ubuntu/Debian
sudo apt-get install antlr4

# 或从官网下载
# https://www.antlr.org/download.html
```

### 4. 依赖安装失败

**问题**：`pip install` 失败

**解决**：
```bash
# 升级pip
pip install --upgrade pip

# 使用国内镜像（可选）
pip install -r requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple
```

### 5. 构建失败

**问题**：CMake配置或编译失败

**解决**：
```bash
# 清理构建目录
rm -rf build

# 重新构建
mkdir build && cd build
cmake ..
cmake --build . --target run_pys_script
```

## 生产环境部署

### 1. 构建发布版本

```bash
mkdir -p build-release
cd build-release
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target run_pys_script -j$(nproc)
```

### 2. 打包部署

```bash
# 使用部署脚本
./deploy.sh

# 或手动打包
tar -czf pyscript-interpreter.tar.gz \
    build/run_pys_script \
    python/ \
    .venv/
```

### 3. 在目标机器上部署

```bash
# 解压
tar -xzf pyscript-interpreter.tar.gz

# 设置权限
chmod +x run_pys_script

# 运行
./run_pys_script python/test_hello.pys
```

## 持续集成（CI）

### GitHub Actions示例

```yaml
name: Build and Test

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-python@v4
        with:
          python-version: '3.12'
      - name: Install dependencies
        run: |
          sudo apt-get update
          sudo apt-get install -y cmake antlr4
      - name: Setup
        run: ./setup.sh
      - name: Test
        run: make test
```

## 性能优化

### 构建优化

```bash
# 使用多核编译
cmake --build . --target run_pys_script -j$(nproc)

# Release模式
cmake .. -DCMAKE_BUILD_TYPE=Release
```

### 运行时优化

```bash
# 启用缓存（默认）
./build/run_pys_script --cache script.pys

# 查看性能统计
./build/run_pys_script --stats script.pys
```

## 安全考虑

1. **虚拟环境隔离**：使用虚拟环境避免污染系统Python
2. **依赖管理**：定期更新 `requirements.txt` 中的依赖版本
3. **权限控制**：不要以root用户运行脚本
4. **输入验证**：在生产环境中验证输入脚本的安全性

## 参考

- [README.md](README.md) - 项目主文档
- [TECHNICAL_DOCUMENT.md](TECHNICAL_DOCUMENT.md) - 技术文档
- [SCRIPT_LANGUAGE_SPECIFICATION.md](SCRIPT_LANGUAGE_SPECIFICATION.md) - 语言规范

