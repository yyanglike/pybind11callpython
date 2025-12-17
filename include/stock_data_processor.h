#ifndef STOCK_DATA_PROCESSOR_H
#define STOCK_DATA_PROCESSOR_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <atomic>
#include <future>
#include <thread>
#include <pybind11/embed.h>
#include <pybind11/stl.h>

namespace py = pybind11;

// 股票数据结构
struct StockData {
    std::string date;
    double open;
    double high;
    double low;
    double close;
    double volume;
    double amount;
    double factor;
};

// 进度回调函数类型
using ProgressCallback = std::function<void(int current, int total, const std::string& message)>;

// 股票数据处理器类
class StockDataProcessor {
public:
    StockDataProcessor();
    ~StockDataProcessor();

    // 从Python获取所有股票数据（同步版本）
    bool fetchAllStockData(int lookbackDays = 365);
    
    // 异步获取所有股票数据
    std::future<bool> fetchAllStockDataAsync(int lookbackDays = 365, 
                                            ProgressCallback callback = nullptr);
    
    // 取消异步操作
    void cancelFetch();
    
    // 检查是否正在运行
    bool isRunning() const;
    
    // 获取处理后的数据
    const std::map<std::string, std::vector<StockData>>& getAllStockData() const;
    
    // 打印统计信息
    void printStatistics() const;
    
    // 获取指定股票的数据
    std::vector<StockData> getStockData(const std::string& stockCode) const;
    
    // 导出数据到CSV（可选）
    bool exportToCSV(const std::string& stockCode, const std::string& filename) const;

private:
    // 将Python对象转换为C++数据结构
    bool convertPythonDataToCpp(const py::object& pyData);
    
    // 异步执行的内部函数
    bool fetchAllStockDataImpl(int lookbackDays, ProgressCallback callback);
    
    // 存储所有股票数据：股票代码 -> 数据序列
    std::map<std::string, std::vector<StockData>> stockDataMap_;
    
    // Python解释器守护
    py::scoped_interpreter* interpreter_;
    
    // 异步控制
    std::atomic<bool> isRunning_;
    std::atomic<bool> shouldCancel_;
    std::unique_ptr<std::thread> fetchThread_;
};

#endif // STOCK_DATA_PROCESSOR_H
