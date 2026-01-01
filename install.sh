#!/bin/bash
# 安装脚本：将程序安装到系统路径（可选）

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "=========================================="
echo "PyScript Interpreter - 安装脚本"
echo "=========================================="
echo ""

# 检查可执行文件是否存在
if [ ! -f "./build/run_pys_script" ]; then
    echo "错误：可执行文件不存在"
    echo "请先运行 'make build' 或 './setup.sh' 构建项目"
    exit 1
fi

# 询问安装路径
INSTALL_PREFIX="${INSTALL_PREFIX:-/usr/local}"
BIN_DIR="$INSTALL_PREFIX/bin"

echo "安装配置："
echo "  可执行文件: ./build/run_pys_script"
echo "  安装路径: $BIN_DIR/pyscript"
echo ""

read -p "确认安装？(y/n) " -n 1 -r
echo
if [[ ! $REPLY =~ ^[Yy]$ ]]; then
    echo "安装已取消"
    exit 0
fi

# 创建目录
echo "创建安装目录..."
sudo mkdir -p "$BIN_DIR"

# 复制可执行文件
echo "复制可执行文件..."
sudo cp "./build/run_pys_script" "$BIN_DIR/pyscript"
sudo chmod +x "$BIN_DIR/pyscript"

echo ""
echo "=========================================="
echo "安装完成！"
echo "=========================================="
echo ""
echo "现在可以使用 'pyscript' 命令运行.pys脚本："
echo "  pyscript python/test_hello.pys"
echo ""
echo "卸载方法："
echo "  sudo rm $BIN_DIR/pyscript"
echo "  或运行: make uninstall"
echo ""

