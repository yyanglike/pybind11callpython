#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <filesystem>

#include <pybind11/embed.h>
#include "script_interpreter.h"
#include "logger.h"

extern "C" int Py_NoSiteFlag;

static Logger s_logger;

namespace py = pybind11;
using namespace script_interpreter;

int main(int argc, char **argv) {
    bool show_stats = false;
    std::string script_path;
    std::vector<std::string> script_args;
    
    // 解析命令行参数
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--stats" || arg == "-s") {
            show_stats = true;
        } else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: run_pys_script [--stats|-s] <script.pys> [args...]\n"
                      << "Options:\n"
                      << "  --stats, -s    Show performance statistics after execution\n"
                      << "  --help, -h     Show this help message\n";
            return 0;
        } else if (script_path.empty()) {
            script_path = arg;
        } else {
            script_args.emplace_back(arg);
        }
    }
    
    if (script_path.empty()) {
        s_logger.error("Usage: run_pys_script [--stats|-s] <script.pys> [args...]");
        return 2;
    }
    
    // 也检查环境变量
    const char* env_stats = std::getenv("PYS_STATS");
    if (env_stats && (std::string(env_stats) == "1" || std::string(env_stats) == "true")) {
        show_stats = true;
    }

    // Disable Python sitecustomize module to avoid circular import errors
    setenv("PYTHONNOUSERSITE", "1", 1);
    setenv("PYTHONNOUSERSITE", "1", 1);  // Double protection
    unsetenv("PYTHONVERBOSE");  // Clear any verbose setting that might trigger the error

    // Disable site module entirely to prevent sitecustomize errors
    Py_NoSiteFlag = 1;

    try {
        py::scoped_interpreter guard{};
        py::module_ sys = py::module_::import("sys");
        // s_logger.info(std::string("[debug] sys.executable=") + std::string(py::str(sys.attr("executable"))));
        // s_logger.info(std::string("[debug] sys.path(before patch)=") + std::string(py::str(sys.attr("path"))));

        // --- 自动检测并插入 .venv 的 site-packages 路径 ---
        py::list sys_path = sys.attr("path");
        
        // 自动查找当前虚拟环境的site-packages路径
        std::filesystem::path venv_path = std::filesystem::current_path() / ".venv";
        std::string site_packages_path;
        
        if (std::filesystem::exists(venv_path)) {
            for (const auto& entry : std::filesystem::directory_iterator(venv_path / "lib")) {
                if (entry.is_directory()) {
                    std::string dir_name = entry.path().filename().string();
                    if (dir_name.find("python") == 0) {
                        site_packages_path = (entry.path() / "site-packages").string();
                        if (std::filesystem::exists(site_packages_path)) {
                            break;
                        }
                    }
                }
            }
        }
        
        if (!site_packages_path.empty()) {
            sys_path.insert(0, site_packages_path);
            sys.attr("path") = sys_path;
            s_logger.info(std::string("[fix] Added site-packages: ") + site_packages_path);
        } else {
            s_logger.warn("[fix] No site-packages directory found in .venv");
        }

        // Also try to suppress the site module
        py::module_ site = py::module_::import("site");
        site.attr("ENABLE_USER_SITE") = false;

        // configure sys.argv for the script
        py::list py_argv;
        for (const auto &s : script_args) py_argv.append(s);
        sys.attr("argv") = py_argv;

        // Instantiate interpreter and execute the .pys file
        ScriptInterpreter interp;

        bool ok = interp.executeFile(script_path);
        if (!ok) {
            s_logger.error(std::string("Script execution failed: ") + interp.getErrorMessage());
            return 4;
        }

        // Optionally fetch result and print representation
        auto result = interp.getResult();
        if (result) {
            try {
                auto pyobj = result->toPythonObject();
                std::cout << "[pys runner] script returned: " << py::str(pyobj).cast<std::string>() << std::endl;
            } catch (...) {
                // ignore conversion errors
            }
        }
        
        // 显示性能统计数据（如果启用）
        if (show_stats) {
            std::cout << "\n" << interp.getPerformanceStats() << std::endl;
        }

    } catch (const std::exception &ex) {
        s_logger.error(std::string("Fatal error initializing Python runtime or executing script: ") + ex.what());
        return 1;
    }

    return 0;
}
