# 快速开始指南

## 一键构建和运行

### 步骤1: 安装依赖
```bash
# 安装Python依赖
pip install pandas mootdx tqdm

# 确保已安装CMake (如未安装)
# macOS: brew install cmake
```

### 步骤2: 克隆pybind11
```bash
git clone https://github.com/pybind/pybind11.git
```

### 步骤3: 构建项目
```bash
chmod +x build.sh
./build.sh
```

### 步骤4: 运行程序
```bash
cd build
./stock_data_app
```

## 运行参数

```bash
# 使用默认参数（回溯365天）
./stock_data_app

# 指定回溯天数
./stock_data_app 100    # 回溯100天
./stock_data_app 30     # 回溯30天
```

## 输出说明

程序运行后会：
1. 调用Python获取所有股票数据
2. 将数据转换为C++数据结构
3. 显示数据统计信息
4. 显示前5只股票的详细信息
5. 展示第一只股票的最近5天数据
6. 导出第一只股票数据到CSV文件
7. 进行数据分析（总成交量、平均成交量等）

## 常见问题

### Q1: 编译失败，找不到Python.h
```bash
# macOS
brew install python@3

# 或指定Python路径
export Python3_ROOT_DIR=/usr/local/opt/python@3
cmake ..
```

### Q2: 运行时找不到Python模块
确保在build目录下运行程序，因为程序会相对路径查找../python目录

### Q3: 权限错误
```bash
chmod +x build.sh
```

## 项目结构一览

```
项目根目录/
├── build/              ← 在这里运行可执行文件
│   └── stock_data_app
├── python/             ← Python模块
│   ├── get_data.py
│   ├── tdx_data_handler.py
│   └── code.csv
├── include/            ← C++头文件
├── src/                ← C++源文件
└── pybind11/           ← pybind11库
```

## 下一步

- 查看 README.md 了解详细文档
- 修改 main.cpp 添加自己的数据处理逻辑
- 扩展 StockDataProcessor 类添加新功能
