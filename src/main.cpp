#include "stock_data_processor.h"
#include <iostream>
#include <pybind11/embed.h>
#include <filesystem>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
#include <csignal>
#include <atomic>
#include <thread>
#include <chrono>
#include <future>
#include <fstream>

namespace py = pybind11;

// 全局中断标志
std::atomic<bool> g_interrupted(false);

// 信号处理器（不立即退出，只设置标志）
void signalHandler(int sig) {
    std::cout << "\n\n接收到中断信号，正在优雅退出..." << std::endl;
    g_interrupted = true;
}

// 文件锁防止程序重复运行，使用PID检查避免僵尸锁
class ProcessLock {
private:
    int lock_fd;
    std::string lock_file;
    pid_t my_pid;
    
    // 检查指定PID的进程是否仍在运行
    static bool isProcessAlive(pid_t pid) {
        if (pid <= 0) return false;
        // 发送0信号不会杀死进程，但可以检查进程是否存在
        return (kill(pid, 0) == 0);
    }
    
    // 从锁文件中读取PID
    static pid_t readPidFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return 0;
        pid_t pid = 0;
        file >> pid;
        file.close();
        return pid;
    }
    
    // 将PID写入锁文件
    bool writePidToFile() {
        if (lock_fd == -1) return false;
        // 将文件截断为0，然后写入当前PID
        if (ftruncate(lock_fd, 0) == -1) return false;
        std::string pid_str = std::to_string(my_pid);
        if (write(lock_fd, pid_str.c_str(), pid_str.size()) != static_cast<ssize_t>(pid_str.size())) {
            return false;
        }
        return true;
    }
    
public:
    ProcessLock(const std::string& filename) : lock_fd(-1), lock_file(filename), my_pid(getpid()) {
        // 首先检查是否存在锁文件，以及锁文件中的进程是否还在运行
        if (access(lock_file.c_str(), F_OK) == 0) {
            pid_t old_pid = readPidFromFile(lock_file);
            if (old_pid > 0 && !isProcessAlive(old_pid)) {
                // 进程已死，删除旧的锁文件
                unlink(lock_file.c_str());
            }
        }
        
        // 打开锁文件
        lock_fd = open(lock_file.c_str(), O_CREAT | O_RDWR, 0666);
        if (lock_fd == -1) {
            std::cerr << "无法创建锁文件: " << lock_file << std::endl;
            return;
        }
        
        // 尝试获取排他锁（非阻塞）
        if (flock(lock_fd, LOCK_EX | LOCK_NB) == -1) {
            // 获取锁失败，可能是另一个实例正在运行
            std::cerr << "错误：程序已经在运行中（PID: " << readPidFromFile(lock_file) << "），请等待或终止其他实例" << std::endl;
            close(lock_fd);
            lock_fd = -1;
            return;
        }
        
        // 获取锁成功，写入当前PID
        if (!writePidToFile()) {
            std::cerr << "警告：无法将PID写入锁文件" << std::endl;
            // 但继续运行，因为我们已经有锁了
        }
    }
    
    ~ProcessLock() {
        if (lock_fd != -1) {
            // 释放锁并删除文件
            flock(lock_fd, LOCK_UN);
            close(lock_fd);
            unlink(lock_file.c_str());
        }
    }
    
    // 禁止拷贝
    ProcessLock(const ProcessLock&) = delete;
    ProcessLock& operator=(const ProcessLock&) = delete;
    
    bool isLocked() const {
        return lock_fd != -1;
    }
};

// 辅助函数：执行命令并获取输出
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

// 获取Python基础路径（base_prefix）
std::string getPythonBasePrefix(const std::filesystem::path& projectRoot) {
    // 首先尝试可执行文件所在目录下的.venv
    std::filesystem::path exeDir = std::filesystem::current_path(); // 注意：当前目录可能与可执行文件目录不同
    // 我们需要获取可执行文件的路径，但这里使用当前目录作为近似
    // 更准确的方法是通过argv[0]，但这里我们假设可执行文件在当前目录下运行
    std::filesystem::path localVenv = exeDir / ".venv";
    
    #ifdef _WIN32
        std::filesystem::path venvPython = localVenv / "Scripts" / "python.exe";
    #else
        std::filesystem::path venvPython = localVenv / "bin" / "python";
    #endif
    
    if (std::filesystem::exists(venvPython)) {
        try {
            std::string cmd = venvPython.string() + " -c \"import sys; print(sys.base_prefix)\"";
            std::string output = exec(cmd.c_str());
            // 去除末尾的换行符
            output.erase(output.find_last_not_of("\n\r") + 1);
            if (!output.empty()) {
                return output;
            }
        } catch (const std::exception& e) {
            std::cerr << "Warning: Failed to get base prefix from local venv Python: " << e.what() << std::endl;
        }
    }
    
    // 然后尝试项目根目录下的虚拟环境
    std::filesystem::path projectVenvPython;
    #ifdef _WIN32
        projectVenvPython = projectRoot / ".venv" / "Scripts" / "python.exe";
    #else
        projectVenvPython = projectRoot / ".venv" / "bin" / "python";
    #endif
    
    if (std::filesystem::exists(projectVenvPython)) {
        try {
            std::string cmd = projectVenvPython.string() + " -c \"import sys; print(sys.base_prefix)\"";
            std::string output = exec(cmd.c_str());
            // 去除末尾的换行符
            output.erase(output.find_last_not_of("\n\r") + 1);
            if (!output.empty()) {
                return output;
            }
        } catch (const std::exception& e) {
            std::cerr << "Warning: Failed to get base prefix from project venv Python: " << e.what() << std::endl;
        }
    }
    
    // 尝试系统Python
    try {
        std::string cmd = "python3 -c \"import sys; print(sys.base_prefix)\"";
        std::string output = exec(cmd.c_str());
        output.erase(output.find_last_not_of("\n\r") + 1);
        if (!output.empty()) {
            return output;
        }
    } catch (const std::exception& e) {
        std::cerr << "Warning: Failed to get base prefix from system Python: " << e.what() << std::endl;
    }
    
    // 回退到默认值（根据平台）
    #ifdef __APPLE__
        // macOS Homebrew 默认路径
        return "/opt/homebrew/opt/python@3.14/Frameworks/Python.framework/Versions/3.14";
    #elif defined(_WIN32)
        // Windows 默认路径（假设安装在C盘）
        return "C:\\Python314";
    #else
        // Linux 默认路径
        return "/usr";
    #endif
}

int main(int argc, char* argv[]) {
    // 检查是否为multiprocessing模块创建的子进程
    // 子进程通常会有-c参数，后面跟着multiprocessing的代码
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-c" && i + 1 < argc) {
            std::string next_arg = argv[i + 1];
            // 如果下一个参数包含"multiprocessing"，则认为是子进程
            if (next_arg.find("multiprocessing") != std::string::npos) {
                // 子进程直接退出，不执行任何操作
                return 0;
            }
        }
    }
    
    // 进程锁防止程序重复运行
    ProcessLock lock("/tmp/stock_data_app.lock");
    if (!lock.isLocked()) {
        std::cerr << "错误：程序已经在运行中，请等待其他实例完成" << std::endl;
        return 1;
    }
    
    // 防止重复输出的静态标志
    static bool headerPrinted = false;
    if (!headerPrinted) {
        std::cout << "========================================" << std::endl;
        std::cout << "股票数据获取系统 (C++ + Python)" << std::endl;
        std::cout << "========================================\n" << std::endl;
        headerPrinted = true;
    }
    
    // 注册信号处理器
    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);
    
    // 设置Python多进程启动方式为spawn，避免fork导致进程重复
    setenv("PYTHONMULTIPROCESSING", "spawn", 1);
    // 设置Python不生成子进程资源跟踪器
    setenv("PYTHONWARNINGS", "ignore", 1);
    
    // 获取项目根目录（假设可执行文件在build目录中运行）
    std::filesystem::path projectRoot = std::filesystem::current_path().parent_path();
    
    // 获取Python基础路径（base_prefix）
    std::string basePrefix = getPythonBasePrefix(projectRoot);
    setenv("PYTHONHOME", basePrefix.c_str(), 1);
    
    // 获取Python版本
    std::string pythonVersion = "3.14"; // 默认版本
    std::filesystem::path venvPython = projectRoot / ".venv" / "bin" / "python";
    if (std::filesystem::exists(venvPython)) {
        try {
            std::string cmd = venvPython.string() + " -c \"import sys; print(f'{sys.version_info.major}.{sys.version_info.minor}')\"";
            std::string output = exec(cmd.c_str());
            output.erase(output.find_last_not_of("\n\r") + 1);
            if (!output.empty()) {
                pythonVersion = output;
            }
        } catch (const std::exception& e) {
            std::cerr << "Warning: Failed to get Python version: " << e.what() << std::endl;
        }
    }
    
    // 设置PYTHONPATH以包含虚拟环境的site-packages
    std::filesystem::path venvSitePackages = projectRoot / ".venv" / "lib" / ("python" + pythonVersion) / "site-packages";
    std::string pythonPath = venvSitePackages.string();
    // 获取现有的PYTHONPATH（如果有）并追加
    const char* existingPythonPath = getenv("PYTHONPATH");
    if (existingPythonPath != nullptr) {
        pythonPath = std::string(existingPythonPath) + ":" + pythonPath;
    }
    setenv("PYTHONPATH", pythonPath.c_str(), 1);
    
    // 初始化Python解释器
    py::scoped_interpreter guard{};
    
    // 在导入任何模块之前，设置Python多进程启动方式为spawn，避免fork导致进程重复
    try {
        py::module_ multiprocessing = py::module_::import("multiprocessing");
        // 检查是否已经设置过启动方式，如果没有则设置为spawn
        py::object get_start_method = multiprocessing.attr("get_start_method");
        py::object set_start_method = multiprocessing.attr("set_start_method");
        try {
            py::str current_method = get_start_method();
            if (current_method.cast<std::string>() != "spawn") {
                set_start_method("spawn", true); // force=True
            }
        } catch (const py::error_already_set& e) {
            // 如果还没有设置启动方式，则设置
            set_start_method("spawn", true);
        }
    } catch (const py::error_already_set& e) {
        // 如果导入multiprocessing失败，忽略错误
    }
    
    // 重定向Python的stdout到空设备，减少输出干扰，但保留stderr以便显示错误
    try {
        py::module_ sys = py::module_::import("sys");
        py::module_ io = py::module_::import("io");
        // 跨平台的方式创建空设备
        #ifdef _WIN32
            py::object devnull = io.attr("open")("NUL", "w");
        #else
            py::object devnull = io.attr("open")("/dev/null", "w");
        #endif
        // 只重定向stdout，stderr保持不变以便显示错误信息
        sys.attr("stdout") = devnull;
    } catch (...) {
        // 如果重定向失败，静默处理
    }
    
    try {
        // 创建股票数据处理器
        StockDataProcessor processor;
        
        // 解析命令行参数
        int lookbackDays = 365;
        bool useAsync = false;
        bool showHelp = false;
        
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "-h" || arg == "--help") {
                showHelp = true;
            } else if (arg == "-a" || arg == "--async") {
                useAsync = true;
            } else if (arg[0] != '-') {
                // 应该是回溯天数
                lookbackDays = std::atoi(arg.c_str());
            }
        }
        
        if (showHelp) {
            std::cout << "股票数据获取系统 使用说明:" << std::endl;
            std::cout << "  ./stock_data_app [选项] [回溯天数]" << std::endl;
            std::cout << "选项:" << std::endl;
            std::cout << "  -h, --help     显示帮助信息" << std::endl;
            std::cout << "  -a, --async    使用异步模式获取数据" << std::endl;
            std::cout << "参数:" << std::endl;
            std::cout << "  回溯天数       要获取的历史数据天数 (默认: 365)" << std::endl;
            return 0;
        }
        
        std::cout << "使用命令行参数，回溯天数: " << lookbackDays << std::endl;
        if (useAsync) {
            std::cout << "使用异步模式获取数据" << std::endl;
        }
        
        std::cout << "\n开始获取股票数据...\n" << std::endl;
        
        bool success = false;
        
        if (useAsync) {
            // 异步模式：使用fetchAllStockDataAsync
            std::cout << "启动异步数据下载..." << std::endl;
            
            // 简单的进度回调
            auto progressCallback = [](int current, int total, const std::string& message) {
                if (current == 0 && total == 1) {
                    std::cout << message << std::endl;
                }
            };
            
            // 启动异步任务
            auto future = processor.fetchAllStockDataAsync(lookbackDays, progressCallback);
            
            // 等待异步任务完成，同时检查中断标志
            std::cout << "等待异步任务完成..." << std::endl;
            
            // 释放GIL，以便异步线程可以获取GIL执行Python代码
            {
                py::gil_scoped_release release;
                
                // 使用future::wait_for来等待，同时允许响应信号
                auto status = future.wait_for(std::chrono::milliseconds(100));
                while (status != std::future_status::ready) {
                    if (g_interrupted) {
                        std::cout << "\n检测到中断信号，正在取消异步任务..." << std::endl;
                        processor.cancelFetch();
                        std::cout << "异步任务已取消" << std::endl;
                        return 1;
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    status = future.wait_for(std::chrono::milliseconds(100));
                }
            }
            
            // 获取结果（此时需要重新获取GIL）
            success = future.get();
            std::cout << "异步任务完成，结果：" << (success ? "成功" : "失败") << std::endl;
        } else {
            // 同步模式：使用fetchAllStockData
            success = processor.fetchAllStockData(lookbackDays);
        }
        
        if (!success) {
            std::cerr << "\n错误：获取股票数据失败！" << std::endl;
            return 1;
        }
        
        // 打印统计信息
        processor.printStatistics();
        
        // 获取所有股票数据
        const auto& allData = processor.getAllStockData();
        
        // 示例：访问特定股票的数据
        std::cout << "\n========================================" << std::endl;
        std::cout << "示例：访问特定股票数据" << std::endl;
        std::cout << "========================================" << std::endl;
        
        if (!allData.empty()) {
            // 获取第一只股票的代码
            std::string firstStockCode = allData.begin()->first;
            std::cout << "\n查询股票: " << firstStockCode << std::endl;
            
            std::vector<StockData> stockData = processor.getStockData(firstStockCode);
            
            if (!stockData.empty()) {
                std::cout << "该股票共有 " << stockData.size() << " 条数据" << std::endl;
                
                // 显示最近5天的数据
                int displayCount = std::min(5, (int)stockData.size());
                std::cout << "\n最近 " << displayCount << " 天的数据:" << std::endl;
                std::cout << "-----------------------------------------------------" << std::endl;
                std::cout << "日期          开盘      最高      最低      收盘        成交量" << std::endl;
                std::cout << "-----------------------------------------------------" << std::endl;
                
                for (int i = stockData.size() - displayCount; i < stockData.size(); ++i) {
                    const StockData& data = stockData[i];
                    printf("%-12s  %8.2f  %8.2f  %8.2f  %8.2f  %12.0f\n",
                           data.date.c_str(),
                           data.open,
                           data.high,
                           data.low,
                           data.close,
                           data.volume);
                }
                std::cout << "-----------------------------------------------------" << std::endl;
                
                // 导出该股票数据到CSV
                std::string csvFilename = firstStockCode + "_export.csv";
                std::cout << "\n导出数据到CSV文件..." << std::endl;
                processor.exportToCSV(firstStockCode, csvFilename);
            }
        }
        
        // 示例：对所有股票数据进行统计分析
        std::cout << "\n========================================" << std::endl;
        std::cout << "数据分析示例" << std::endl;
        std::cout << "========================================" << std::endl;
        
        double totalVolume = 0.0;
        int totalRecords = 0;
        
        for (const auto& pair : allData) {
            const std::vector<StockData>& dataVec = pair.second;
            totalRecords += dataVec.size();
            
            for (const auto& data : dataVec) {
                totalVolume += data.volume;
            }
        }
        
        std::cout << "总数据记录数: " << totalRecords << std::endl;
        std::cout << "总成交量: " << totalVolume << std::endl;
        if (totalRecords > 0) {
            std::cout << "平均成交量: " << (totalVolume / totalRecords) << std::endl;
        }
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "程序执行完成！" << std::endl;
        std::cout << "========================================" << std::endl;
        
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "\n致命错误: " << e.what() << std::endl;
        return 1;
    }
}
