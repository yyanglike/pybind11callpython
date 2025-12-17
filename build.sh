#!/bin/bash

echo "=========================================="
echo "股票数据获取系统 - 构建脚本"
echo "=========================================="
echo ""

# 检查pybind11是否存在
if [ ! -d "pybind11" ]; then
    echo "未找到pybind11，正在克隆..."
    git clone https://github.com/pybind/pybind11.git
    if [ $? -ne 0 ]; then
        echo "错误：克隆pybind11失败！"
        exit 1
    fi
    echo "pybind11克隆成功"
else
    echo "pybind11已存在"
fi

echo ""
echo "开始构建项目..."
echo ""

# 创建build目录
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

# 运行CMake配置
echo "运行CMake配置..."
cmake ..
if [ $? -ne 0 ]; then
    echo "错误：CMake配置失败！"
    exit 1
fi

# 编译项目
echo ""
echo "编译项目..."
make
if [ $? -ne 0 ]; then
    echo "错误：编译失败！"
    exit 1
fi

echo ""
echo "=========================================="
echo "构建成功！"
echo "=========================================="
echo ""
echo "可执行文件位于: build/stock_data_app"
echo ""
echo "运行方式："
echo "  cd build && ./stock_data_app"
echo "  或指定回溯天数："
echo "  cd build && ./stock_data_app 100"
echo ""
