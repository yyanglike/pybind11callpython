# 股票数据获取系统 (C++ + Python)

这是一个使用C++和Python混合编程的股票数据获取系统。C++程序通过pybind11调用Python的股票数据获取函数，将所有股票数据从Python传递到C++，并在C++端进行处理和分析。

## 项目架构

```
pybind11callpython/
├── CMakeLists.txt              # CMake构建配置
├── build.sh                    # 构建脚本
├── README.md                   # 项目说明文档
├── include/                    # C++头文件
│   └── stock_data_processor.h  # 股票数据处理器头文件
├── src/                        # C++源文件
│   ├── main.cpp                # 主程序入口
│   └── stock_data_processor.cpp # 股票数据处理器实现
└── python/                     # Python模块
    ├── get_data.py             # 数据获取接口
    ├── tdx_data_handler.py     # 通达信数据处理器
    └── code.csv                # 股票代码列表
```

## 功能特性

1. **数据获取**: 使用Python从通达信获取所有股票的历史数据
2. **数据传递**: 通过pybind11将Python的DataFrame数据一次性传递到C++
3. **数据结构转换**: 自动将Python的dict[str, DataFrame]转换为C++的map<string, vector<StockData>>
4. **数据分析**: 在C++端对股票数据进行统计分析
5. **数据导出**: 支持将股票数据导出为CSV文件

## 技术栈

- **C++17**: 主程序语言
- **Python 3.x**: 数据获取语言
- **pybind11**: C++与Python绑定
- **CMake**: 构建系统
- **pandas**: Python数据处理
- **mootdx**: 通达信数据接口

## 前置要求

### 系统要求
- macOS / Linux (已在macOS上测试)
- C++ 编译器 (支持C++17)
- Python 3.x
- CMake 3.15+
- Git

### Python依赖
```bash
pip install pandas mootdx tqdm
```

## 快速开始

### 1. 克隆pybind11（如果尚未克隆）
```bash
git clone https://github.com/pybind/pybind11.git
```

### 2. 构建项目
```bash
# 使用构建脚本（推荐）
./build.sh

# 或手动构建
mkdir build && cd build
cmake ..
make
```

### 3. 运行程序
```bash
# 在项目根目录下运行
cd build
./stock_data_app

# 指定回溯天数（默认365天）
./stock_data_app 100
```

## 核心代码说明

### Python端 (get_data.py)

```python
def get_all_stock_data(LOOKBACK_DAYS=365):
    """
    获取所有股票的历史数据
    
    参数:
        LOOKBACK_DAYS: 回溯天数
    
    返回:
        dict[str, DataFrame]: 股票代码 -> DataFrame的映射
    """
    code_file = "code.csv"
    filtered_data = pd.read_csv(code_file, dtype={"ts_code": str})
    from tdx_data_handler import TDXDataHandler
    tdx_handler = TDXDataHandler(market="std", tdxdir="C:/new_tdx")
    all_stock_data = tdx_handler.process_all_stocks(
        code_file=code_file, 
        kline_count=LOOKBACK_DAYS
    )
    return all_stock_data
```

### C++端 (stock_data_processor.cpp)

主要流程：

1. **初始化Python解释器**
```cpp
py::scoped_interpreter guard{};
```

2. **导入Python模块并调用函数**
```cpp
py::module_ get_data = py::module_::import("get_data");
py::object pyData = get_data.attr("get_all_stock_data")(lookbackDays);
```

3. **数据转换**
```cpp
// 将Python的dict转换为C++的map
py::dict stockDict = pyData.cast<py::dict>();

// 遍历每只股票的DataFrame
for (auto item : stockDict) {
    std::string stockCode = item.first.cast<std::string>();
    py::object df = py::reinterpret_borrow<py::object>(item.second);
    
    // 提取DataFrame的数据并转换为C++结构
    // ...
}
```

## 数据结构

### C++ StockData结构
```cpp
struct StockData {
    std::string date;   // 日期
    double open;        // 开盘价
    double high;        // 最高价
    double low;         // 最低价
    double close;       // 收盘价
    double volume;      // 成交量
    double amount;      // 成交额
    double factor;      // 复权因子
};
```

### 数据存储
```cpp
std::map<std::string, std::vector<StockData>> stockDataMap_;
```
- Key: 股票代码 (如 "000001")
- Value: 该股票的历史数据序列

## API接口

### StockDataProcessor类

#### 公共方法

- `bool fetchAllStockData(int lookbackDays = 365)`
  - 从Python获取所有股票数据
  - 参数：回溯天数
  - 返回：成功返回true，失败返回false

- `const std::map<std::string, std::vector<StockData>>& getAllStockData() const`
  - 获取所有股票数据
  - 返回：股票数据的map引用

- `void printStatistics() const`
  - 打印股票数据统计信息

- `std::vector<StockData> getStockData(const std::string& stockCode) const`
  - 获取指定股票的数据
  - 参数：股票代码
  - 返回：该股票的数据序列

- `bool exportToCSV(const std::string& stockCode, const std::string& filename) const`
  - 导出股票数据到CSV文件
  - 参数：股票代码、文件名
  - 返回：成功返回true，失败返回false

## 使用示例

### 获取并处理股票数据

```cpp
#include "stock_data_processor.h"
#include <pybind11/embed.h>

int main() {
    // 初始化Python解释器
    py::scoped_interpreter guard{};
    
    // 创建处理器
    StockDataProcessor processor;
    
    // 获取数据（回溯100天）
    if (processor.fetchAllStockData(100)) {
        // 打印统计信息
        processor.printStatistics();
        
        // 获取特定股票数据
        auto stockData = processor.getStockData("000001");
        
        // 处理数据...
        for (const auto& data : stockData) {
            std::cout << data.date << ": " << data.close << std::endl;
        }
        
        // 导出数据
        processor.exportToCSV("000001", "000001.csv");
    }
    
    return 0;
}
```

## 工作流程

1. **C++程序启动**: main.cpp中初始化Python解释器
2. **调用Python函数**: 通过pybind11调用`get_all_stock_data()`
3. **Python获取数据**: 从通达信获取所有股票的历史数据
4. **返回Python对象**: 返回dict[str, DataFrame]
5. **数据转换**: C++端将Python对象转换为C++数据结构
6. **数据处理**: 在C++端进行数据分析和处理
7. **结果输出**: 显示统计信息、导出CSV等

## 性能优化

1. **批量获取**: Python端每20只股票一批获取行情数据
2. **进度显示**: 使用tqdm显示处理进度
3. **内存管理**: 使用std::map和std::vector高效存储数据
4. **异常处理**: 完善的错误处理机制

## 高级功能与问题解决

### 异步执行模式

系统支持同步和异步两种数据获取模式：

#### 同步模式（默认）
```bash
./stock_data_app [回溯天数]
```

#### 异步模式
```bash
./stock_data_app -a [回溯天数]
```

#### 异步模式特点
- **非阻塞下载**: 主线程不会被数据获取阻塞
- **进度回调**: 实时显示下载进度状态
- **信号屏蔽**: 异步线程屏蔽中断信号，确保任务完整执行
- **线程安全**: 使用pthread信号屏蔽确保数据完整性

### 进程锁与单例保护

系统实现了基于PID的文件锁，防止程序重复运行：

#### 主要功能
1. **PID检查**: 检测锁文件中的进程是否仍在运行
2. **僵尸进程清理**: 自动清理已死亡的进程锁
3. **信号处理**: 支持Ctrl+C优雅中断并清理锁文件
4. **子进程检测**: 自动忽略multiprocessing模块创建的子进程

#### 技术实现
```cpp
class ProcessLock {
    // 文件锁 + PID检查
    // 信号处理器注册
    // 自动清理机制
};
```

### Python环境自动配置

系统自动检测和配置Python环境：

1. **虚拟环境优先**: 自动使用项目中的`.venv`虚拟环境
2. **多进程配置**: 强制设置`spawn`启动方式，避免进程重复
3. **路径管理**: 自动添加python目录到sys.path
4. **输出控制**: 重定向Python stdout，保留stderr显示错误信息

### 常见问题解决记录

#### 问题：异步执行文件没有下载下来
**现象**: 用户反馈异步模式看似没有下载文件
**实际**: 文件已成功下载（python/data/目录包含190个CSV文件）
**原因**: 异步模式可能被Ctrl+C中断，导致用户没有看到完整输出
**解决方案**: 实施信号屏蔽，确保异步任务完整执行

#### 问题：程序重复启动
**现象**: 多个stock_data_app进程同时运行
**原因**: Python multiprocessing模块创建子进程
**解决方案**: 
- 子进程检测并直接退出
- 设置环境变量`PYTHONMULTIPROCESSING=spawn`
- 在Python代码中强制设置多进程启动方式

#### 问题：Python输出干扰
**现象**: Python的tqdm进度条和程序输出重叠
**解决方案**: 重定向Python stdout到空设备，保留stderr显示错误信息

### 验证方法

#### 检查文件下载
```bash
ls -l python/data/ | wc -l      # 检查文件数量
ls -lt python/data/ | head -5   # 检查最新文件
```

#### 检查进程状态
```bash
ps aux | grep stock_data_app | grep -v grep
```

#### 清理系统状态
```bash
pkill -9 -f stock_data_app
pkill -9 -f "multiprocessing.resource_tracker"
rm -f /tmp/stock_data_app.lock
```

## 中断机制优化与GIL管理

### 问题背景
用户反馈异步模式下执行`get_all_stock_data()`函数时无法及时响应中断。原因在于：
1. Python函数一旦开始执行，需要完成所有股票处理才能返回
2. 仅C++端设置取消标志，Python端仍在继续执行
3. Python全局解释器锁(GIL)管理不当导致线程阻塞

### 解决方案：文件标志中断机制

#### 1. C++端改进 (`src/stock_data_processor.cpp`)
```cpp
void StockDataProcessor::cancelFetch() {
    shouldCancel_ = true;
    // 创建中断标志文件，通知Python端中断
    std::ofstream flagFile("/tmp/stock_fetch_interrupt");
    if (flagFile) {
        flagFile << "INTERRUPT" << std::endl;
        flagFile.close();
    }
    // 原有清理逻辑...
    // 清理标志文件
    std::remove("/tmp/stock_fetch_interrupt");
}
```

#### 2. Python端增强检查点 (`python/tdx_data_handler.py`)
在三个关键位置添加中断检查：
```python
# 外层循环：每处理一组股票（20只）前
if os.path.exists('/tmp/stock_fetch_interrupt'):
    raise RuntimeError("Interrupted by user")

# 内层循环：每处理单只股票前
if os.path.exists('/tmp/stock_fetch_interrupt'):
    raise RuntimeError("Interrupted by user")

# 数据获取函数开始处
if os.path.exists('/tmp/stock_fetch_interrupt'):
    raise RuntimeError("Interrupted by user")
```

### 中断检查点分布

| 检查位置 | 检查频率 | 说明 |
|---------|---------|------|
| 外层循环 | 每20只股票一次 | 分组处理开始前检查 |
| 内层循环 | 每只股票一次 | 单个股票处理前检查 |
| `get_stock_data()`开始 | 每次调用 | 数据获取函数入口检查 |
| 网络数据获取前 | 每次远程调用前 | 防止长时间网络阻塞 |

### 中断响应流程

```
1. 用户发送中断信号 (Ctrl+C)
2. C++主线程设置 g_interrupted = true
3. C++调用 processor.cancelFetch()
4. C++创建 /tmp/stock_fetch_interrupt 标志文件
5. Python端在下一个检查点发现标志文件
6. Python抛出 RuntimeError("Interrupted by user")
7. 异常传递回C++，异步线程安全退出
```

### GIL管理优化

#### 主线程GIL释放
```cpp
// main.cpp中异步等待时释放GIL
{
    py::gil_scoped_release release;  // 主线程释放GIL
    // 等待异步任务完成...
}
// future.get()前自动重新获取GIL
```

#### 异步线程GIL获取
```cpp
// stock_data_processor.cpp中
bool fetchAllStockDataImpl(...) {
    py::gil_scoped_acquire acquire;  // 异步线程获取GIL
    // 执行Python代码...
    // 自动释放GIL（析构时）
}
```

#### 长时间数据转换优化
```cpp
// 每处理10个股票，短暂释放GIL
if (count % 10 == 0 && count > 0) {
    {
        py::gil_scoped_release release;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
```

### 实际效果验证

#### 文件下载验证 ✅
- 异步模式成功下载 **1342个CSV文件** 到 `build/data/`
- 文件时间戳为最新，证明异步执行完成

#### 中断响应优化 ✅
1. **响应时间**：最坏情况下等待当前股票处理完成（约1-2秒）
2. **数据完整性**：中断时已处理的数据保留在`build/data/`目录
3. **资源清理**：中断后清理标志文件，避免残留影响

### 使用建议

#### 同步模式（默认）
```bash
./stock_data_app [回溯天数]
```
- **无法中断**：一旦开始必须完成所有股票处理

#### 异步模式（支持中断）
```bash
./stock_data_app -a [回溯天数]
```
- **支持中断**：可通过Ctrl+C中断
- **文件保存**：已下载的数据保留在`build/data/`
- **响应时间**：最多等待当前股票处理完成

### 验证中断功能
```bash
# 清理系统状态
pkill -9 -f stock_data_app
rm -f /tmp/stock_fetch_interrupt
rm -rf build/data/*

# 测试异步模式（可尝试中断）
cd build && ./stock_data_app -a 0
```

## 注意事项

1. **Python路径**: 确保python目录在程序运行目录下
2. **数据文件**: code.csv必须存在于python目录
3. **通达信路径**: 根据实际情况修改`tdx_data_handler.py`中的tdxdir路径
4. **Python版本**: 确保系统Python版本与编译时使用的版本一致
5. **依赖库**: 运行前安装所有Python依赖

## 故障排查

### 问题1: 找不到Python模块
```
错误：No module named 'get_data'
解决：确保python目录在当前工作目录下，或正确设置sys.path
```

### 问题2: CMake找不到Python
```
错误：Could NOT find Python3
解决：安装Python3开发包，macOS使用brew install python@3
```

### 问题3: pybind11未找到
```
错误：CMake Error: add_subdirectory given source "pybind11"
解决：运行 git clone https://github.com/pybind/pybind11.git
```

### 问题4: 编译时找不到Python.h
```
错误：fatal error: 'Python.h' file not found
解决：安装Python开发包，确保Python3_INCLUDE_DIRS正确
```

## 扩展开发

### 添加新的数据字段
1. 在`StockData`结构中添加字段
2. 在`convertPythonDataToCpp()`中添加提取逻辑
3. 在输出函数中添加显示逻辑

### 添加新的分析功能
1. 在`StockDataProcessor`类中添加新方法
2. 在头文件中声明
3. 在main.cpp中调用

## 许可证

本项目仅供学习和研究使用。

## 作者

Stock Data System Development Team

## 更新日志

### v1.0.0 (2025-12-12)
- 初始版本发布
- 支持从Python获取股票数据并传递到C++
- 实现基本的数据统计和导出功能




cd antlr && java -jar /usr/local/lib/antlr-4.10.1-complete.jar -Dlanguage=Cpp -visitor -o generated PyScript.g4 2>&1

pybind11callpython % antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4 2>&1