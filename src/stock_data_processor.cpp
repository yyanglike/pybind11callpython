#include "stock_data_processor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <future>
#include <thread>
#include <chrono>
#include <signal.h>
#include <pthread.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

StockDataProcessor::StockDataProcessor() : interpreter_(nullptr), isRunning_(false), shouldCancel_(false) {
    // Python解释器在main中初始化，这里不需要再初始化
}

StockDataProcessor::~StockDataProcessor() {
    // Python解释器在main中管理生命周期
    cancelFetch();
    if (fetchThread_ && fetchThread_->joinable()) {
        fetchThread_->join();
    }
}

// 异步获取所有股票数据
std::future<bool> StockDataProcessor::fetchAllStockDataAsync(int lookbackDays, ProgressCallback callback) {
    // 如果已经在运行，返回一个表示失败的future
    if (isRunning_) {
        std::promise<bool> promise;
        promise.set_value(false);
        return promise.get_future();
    }
    
    // 创建一个promise来返回结果
    auto promise = std::make_shared<std::promise<bool>>();
    std::future<bool> future = promise->get_future();
    
    // 启动异步线程
    fetchThread_ = std::make_unique<std::thread>([this, lookbackDays, callback, promise]() {
        // 在异步线程中屏蔽SIGINT和SIGTERM信号，避免被中断
        sigset_t mask;
        sigemptyset(&mask);
        sigaddset(&mask, SIGINT);
        sigaddset(&mask, SIGTERM);
        pthread_sigmask(SIG_BLOCK, &mask, nullptr);
        
        bool result = fetchAllStockDataImpl(lookbackDays, callback);
        promise->set_value(result);
    });
    
    return future;
}

// 取消异步操作
void StockDataProcessor::cancelFetch() {
    shouldCancel_ = true;
    // 创建中断标志文件，通知Python端中断
    std::ofstream flagFile("/tmp/stock_fetch_interrupt");
    if (flagFile) {
        flagFile << "INTERRUPT" << std::endl;
        flagFile.close();
    }
    if (fetchThread_ && fetchThread_->joinable()) {
        fetchThread_->join();
        fetchThread_.reset();
    }
    shouldCancel_ = false;
    isRunning_ = false;
    // 清理标志文件
    std::remove("/tmp/stock_fetch_interrupt");
}

// 检查是否正在运行
bool StockDataProcessor::isRunning() const {
    return isRunning_;
}

// 异步执行的内部函数
bool StockDataProcessor::fetchAllStockDataImpl(int lookbackDays, ProgressCallback callback) {
    isRunning_ = true;
    shouldCancel_ = false;
    
    // 在子线程中获取GIL，确保可以调用Python代码
    py::gil_scoped_acquire acquire;
    
    try {
        if (shouldCancel_) {
            isRunning_ = false;
            return false;
        }
        if (callback) callback(0, 1, "开始连接Python环境...");
        
        // 添加python目录到sys.path
        py::module_ sys = py::module_::import("sys");
        py::list path = sys.attr("path");
        
        // 获取项目根目录下的python目录（相对于build目录）
        std::string pythonPath = "../python";
        path.insert(0, pythonPath);
        
        if (shouldCancel_) {
            isRunning_ = false;
            return false;
        }
        if (callback) callback(0, 1, "导入Python模块...");
        
        // 导入get_data模块
        py::module_ get_data = py::module_::import("get_data");
        
        if (shouldCancel_) {
            isRunning_ = false;
            return false;
        }
        if (callback) callback(0, 1, "调用Python函数获取数据...");
        
        // 调用get_all_stock_data函数
        py::object pyData = get_data.attr("get_all_stock_data")(lookbackDays);
        
        if (shouldCancel_) {
            isRunning_ = false;
            return false;
        }
        if (callback) callback(0, 1, "转换Python数据到C++...");
        
        // 将Python数据转换为C++数据结构
        bool success = convertPythonDataToCpp(pyData);
        
        if (shouldCancel_) {
            isRunning_ = false;
            return false;
        }
        if (callback) callback(1, 1, success ? "数据获取完成" : "数据获取失败");
        
        isRunning_ = false;
        return success;
        
    } catch (const py::error_already_set& e) {
        // 输出详细错误信息到stderr以便调试
        std::cerr << "\n[ERROR] Python错误: " << e.what() << std::endl;
        // 获取Python错误详细信息
        try {
            py::module_ traceback = py::module_::import("traceback");
            py::object formatted_exc = traceback.attr("format_exc")();
            std::string error_details = formatted_exc.cast<std::string>();
            std::cerr << error_details << std::endl;
        } catch (...) {
            // 忽略获取详细错误的错误
        }
        if (callback) callback(1, 1, std::string("Python错误: ") + e.what());
        isRunning_ = false;
        return false;
    } catch (const std::exception& e) {
        std::cerr << "\n[ERROR] C++错误: " << e.what() << std::endl;
        if (callback) callback(1, 1, std::string("C++错误: ") + e.what());
        isRunning_ = false;
        return false;
    }
}

bool StockDataProcessor::fetchAllStockData(int lookbackDays) {
    try {
        // 添加python目录到sys.path
        py::module_ sys = py::module_::import("sys");
        py::list path = sys.attr("path");
        
        // 获取项目根目录下的python目录（相对于build目录）
        std::string pythonPath = "../python";
        path.insert(0, pythonPath);
        
        // 导入get_data模块
        py::module_ get_data = py::module_::import("get_data");
        
        // 调用get_all_stock_data函数
        py::object pyData = get_data.attr("get_all_stock_data")(lookbackDays);
        
        // 将Python数据转换为C++数据结构
        bool success = convertPythonDataToCpp(pyData);
        
        return success;
        
    } catch (const py::error_already_set& e) {
        return false;
    } catch (const std::exception& e) {
        return false;
    }
}

bool StockDataProcessor::convertPythonDataToCpp(const py::object& pyData) {
    try {
        // pyData是一个字典，键是股票代码，值是pandas DataFrame
        py::dict stockDict = pyData.cast<py::dict>();
        
        int count = 0;
        for (auto item : stockDict) {
            std::string stockCode = item.first.cast<std::string>();
            py::object df = py::reinterpret_borrow<py::object>(item.second);
            
            // 创建该股票的数据向量
            std::vector<StockData> stockDataVec;
            
            try {
                // 获取DataFrame的索引（日期）
                py::object index = df.attr("index");
                py::object values = df.attr("values");
                
                // 获取列名
                py::list columns = df.attr("columns").cast<py::list>();
                
                // 创建列名到索引的映射
                std::map<std::string, int> colMap;
                for (size_t i = 0; i < columns.size(); ++i) {
                    std::string colName = columns[i].cast<std::string>();
                    colMap[colName] = i;
                }
                
                // 获取行数
                int numRows = py::len(index);
                
                // 遍历每一行
                for (int i = 0; i < numRows; ++i) {
                    StockData data;
                    
                    // 获取日期
                    py::object dateObj = index[py::int_(i)];
                    // 将Timestamp转换为字符串
                    py::object dateStr = dateObj.attr("strftime")("%Y-%m-%d");
                    data.date = dateStr.cast<std::string>();
                    
                    // 获取该行的数据
                    py::object rowData = values[py::int_(i)];
                    
                    // 提取各字段数据
                    if (colMap.find("open") != colMap.end()) {
                        data.open = rowData[py::int_(colMap["open"])].cast<double>();
                    }
                    if (colMap.find("high") != colMap.end()) {
                        data.high = rowData[py::int_(colMap["high"])].cast<double>();
                    }
                    if (colMap.find("low") != colMap.end()) {
                        data.low = rowData[py::int_(colMap["low"])].cast<double>();
                    }
                    if (colMap.find("close") != colMap.end()) {
                        data.close = rowData[py::int_(colMap["close"])].cast<double>();
                    }
                    if (colMap.find("volume") != colMap.end()) {
                        data.volume = rowData[py::int_(colMap["volume"])].cast<double>();
                    }
                    if (colMap.find("amount") != colMap.end()) {
                        data.amount = rowData[py::int_(colMap["amount"])].cast<double>();
                    }
                    if (colMap.find("factor") != colMap.end()) {
                        data.factor = rowData[py::int_(colMap["factor"])].cast<double>();
                    }
                    
                    stockDataVec.push_back(data);
                }
                
                // 将该股票的数据添加到map中
                stockDataMap_[stockCode] = stockDataVec;
                
                count++;
                
            } catch (const std::exception& e) {
                // 静默处理错误
                continue;
            }
        }
        
        return true;
        
    } catch (const std::exception& e) {
        return false;
    }
}

const std::map<std::string, std::vector<StockData>>& StockDataProcessor::getAllStockData() const {
    return stockDataMap_;
}

void StockDataProcessor::printStatistics() const {
    std::cout << "\n====== 股票数据统计 ======" << std::endl;
    std::cout << "总股票数量: " << stockDataMap_.size() << std::endl;
    
    if (stockDataMap_.empty()) {
        std::cout << "没有数据可显示" << std::endl;
        return;
    }
    
    // 显示前5只股票的详细信息
    int displayCount = 0;
    for (const auto& pair : stockDataMap_) {
        if (displayCount >= 5) break;
        
        const std::string& code = pair.first;
        const std::vector<StockData>& dataVec = pair.second;
        
        std::cout << "\n股票代码: " << code << std::endl;
        std::cout << "数据条数: " << dataVec.size() << std::endl;
        
        if (!dataVec.empty()) {
            const StockData& latest = dataVec.back();
            std::cout << "最新日期: " << latest.date << std::endl;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "  开盘: " << latest.open 
                      << " 最高: " << latest.high 
                      << " 最低: " << latest.low 
                      << " 收盘: " << latest.close << std::endl;
            std::cout << "  成交量: " << latest.volume 
                      << " 成交额: " << latest.amount << std::endl;
        }
        
        displayCount++;
    }
    
    std::cout << "\n（显示前5只股票，总共 " << stockDataMap_.size() << " 只）" << std::endl;
    std::cout << "========================\n" << std::endl;
}

std::vector<StockData> StockDataProcessor::getStockData(const std::string& stockCode) const {
    auto it = stockDataMap_.find(stockCode);
    if (it != stockDataMap_.end()) {
        return it->second;
    }
    return std::vector<StockData>();
}

bool StockDataProcessor::exportToCSV(const std::string& stockCode, const std::string& filename) const {
    auto it = stockDataMap_.find(stockCode);
    if (it == stockDataMap_.end()) {
        std::cerr << "未找到股票代码: " << stockCode << std::endl;
        return false;
    }
    
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false;
    }
    
    // 写入CSV头
    file << "date,open,high,low,close,volume,amount,factor\n";
    
    // 写入数据
    file << std::fixed << std::setprecision(2);
    for (const auto& data : it->second) {
        file << data.date << ","
             << data.open << ","
             << data.high << ","
             << data.low << ","
             << data.close << ","
             << data.volume << ","
             << data.amount << ","
             << data.factor << "\n";
    }
    
    file.close();
    std::cout << "数据已导出到: " << filename << std::endl;
    return true;
}
