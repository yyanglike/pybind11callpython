#!/bin/bash
# 一键设置脚本：创建虚拟环境、安装依赖、构建项目

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "=========================================="
echo "PyScript Interpreter - 一键设置脚本"
echo "=========================================="
echo ""

# 检查Python版本
echo "检查Python版本..."
if ! command -v python3 &> /dev/null; then
    echo "错误：未找到python3，请先安装Python 3.12或更高版本"
    exit 1
fi

PYTHON_VERSION=$(python3 --version | cut -d' ' -f2 | cut -d'.' -f1,2)
echo "Python版本: $(python3 --version)"
if [[ $(echo "$PYTHON_VERSION < 3.12" | bc -l 2>/dev/null || echo "1") == "1" ]]; then
    echo "警告：建议使用Python 3.12或更高版本"
fi

# 检查ANTLR4
echo ""
echo "检查ANTLR4..."
if ! command -v antlr4 &> /dev/null; then
    echo "警告：未找到antlr4命令"
    echo "请安装ANTLR4:"
    echo "  macOS: brew install antlr"
    echo "  Ubuntu/Debian: sudo apt-get install antlr4"
    echo "  或从 https://www.antlr.org/download.html 下载"
    echo ""
    read -p "是否继续？(y/n) " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        exit 1
    fi
else
    echo "ANTLR4已安装: $(antlr4 --version 2>&1 | head -1)"
fi

# 检查CMake
echo ""
echo "检查CMake..."
if ! command -v cmake &> /dev/null; then
    echo "错误：未找到cmake，请先安装CMake 3.15或更高版本"
    exit 1
fi
echo "CMake版本: $(cmake --version | head -1)"

# 创建虚拟环境
echo ""
echo "创建Python虚拟环境..."
if [ -d ".venv" ]; then
    echo "虚拟环境已存在，跳过创建"
else
    python3 -m venv .venv
    echo "虚拟环境创建成功"
fi

# 激活虚拟环境
echo ""
echo "激活虚拟环境并安装依赖..."
source .venv/bin/activate

# 升级pip
echo "升级pip..."
pip install --upgrade pip > /dev/null 2>&1

# 安装Python依赖
if [ -f "requirements.txt" ]; then
    echo "安装Python依赖..."
    pip install -r requirements.txt
else
    echo "警告：未找到requirements.txt，跳过Python依赖安装"
fi

# 检查pybind11
echo ""
echo "检查pybind11..."
if [ ! -d "pybind11" ]; then
    echo "pybind11不存在，正在克隆..."
    git clone --depth 1 https://github.com/pybind/pybind11.git
    echo "pybind11克隆成功"
else
    echo "pybind11已存在"
fi

# 生成ANTLR代码
echo ""
echo "生成ANTLR代码..."
if [ -f "antlr/PyScript.g4" ]; then
    if command -v antlr4 &> /dev/null; then
        mkdir -p antlr/generated
        echo "运行ANTLR生成器..."
        antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4 2>&1 | grep -v "warning" || true
        echo "ANTLR代码生成完成"
    else
        echo "警告：antlr4命令不可用，跳过代码生成"
        echo "请手动运行: antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4"
    fi
else
    echo "警告：未找到antlr/PyScript.g4"
fi

# 构建项目
echo ""
echo "构建项目..."
mkdir -p build
cd build

# 配置CMake
echo "运行CMake配置..."
cmake .. -DCMAKE_BUILD_TYPE=Release

# 编译
echo ""
echo "编译项目..."
cmake --build . --target run_pys_script -j$(sysctl -n hw.ncpu 2>/dev/null || nproc 2>/dev/null || echo 4)

cd ..

echo ""
echo "=========================================="
echo "设置完成！"
echo "=========================================="
echo ""
echo "使用方法："
echo "  1. 激活虚拟环境: source .venv/bin/activate"
echo "  2. 运行脚本: ./build/run_pys_script python/test_hello.pys"
echo ""
echo "或者使用便捷脚本："
echo "  make run SCRIPT=python/test_hello.pys"
echo ""

