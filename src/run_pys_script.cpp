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

static Logger s_logger;

namespace py = pybind11;
using namespace script_interpreter;

int main(int argc, char **argv) {
    if (argc < 2) {
        s_logger.error("Usage: run_pys_script <script.pys> [args...]");
        return 2;
    }

    const std::string script_path = argv[1];
    std::vector<std::string> script_args;
    for (int i = 1; i < argc; ++i) script_args.emplace_back(argv[i]);

    // Minimal environment setup similar to src/main.cpp: allow a project .venv by respecting PYTHONPATH
    // (Users may override environment via existing PYTHONHOME/PYTHONPATH)
    // Optionally we could detect .venv and set PYTHONHOME; keep minimal to avoid platform issues.

    // --- 自动检测 .venv 并设置 PYTHONPATH（不要设置 PYTHONHOME，可能会破坏嵌入式启动） ---
    try {
        std::filesystem::path projectRoot = std::filesystem::current_path();
        std::filesystem::path venv = projectRoot / ".venv";
        if (std::filesystem::exists(venv)) {
            // Build a PYTHONPATH that includes the venv stdlib (lib/pythonX.Y) and any site-packages
            std::string composed_paths;

            // try to find the lib/pythonX.Y directory inside the venv
            std::filesystem::path libdir = venv / "lib";
            if (std::filesystem::exists(libdir) && std::filesystem::is_directory(libdir)) {
                for (auto &e : std::filesystem::directory_iterator(libdir)) {
                    if (e.is_directory()) {
                        std::string name = e.path().filename().string();
                        // look for directory names like "python3.14"
                        if (name.rfind("python", 0) == 0) {
                            if (!composed_paths.empty()) composed_paths += ":";
                            composed_paths += e.path().string();
                            break;
                        }
                    }
                }
            }

            // include all site-packages directories under the venv
            for (auto &entry : std::filesystem::recursive_directory_iterator(venv)) {
                if (entry.is_directory()) {
                    std::string p = entry.path().string();
                    if (p.find("site-packages") != std::string::npos) {
                        if (!composed_paths.empty()) composed_paths += ":";
                        composed_paths += p;
                    }
                }
            }

            if (!composed_paths.empty()) {
                const char* prev = getenv("PYTHONPATH");
                std::string new_py_path = composed_paths;
                if (prev) new_py_path = std::string(prev) + ":" + new_py_path;
                setenv("PYTHONPATH", new_py_path.c_str(), 1);
                s_logger.info(std::string("[pys runner] PYTHONPATH=") + new_py_path);
            } else {
                s_logger.info("[pys runner] .venv detected but no python stdlib or site-packages found inside it");
            }
        }
    } catch (const std::exception &e) {
        s_logger.warn(std::string("[pys runner] .venv detection failed: ") + e.what());
    }

    try {
        py::scoped_interpreter guard{};
        py::module_ sys = py::module_::import("sys");
        s_logger.info(std::string("[debug] sys.executable=") + std::string(py::str(sys.attr("executable"))));
        s_logger.info(std::string("[debug] sys.path(before patch)=") + std::string(py::str(sys.attr("path"))));

        // --- 强制插入 .venv 的 site-packages 路径 ---
        py::list sys_path = sys.attr("path");
        sys_path.insert(0, "/Users/yangyi/company/python/pybind11callpython/.venv/lib/python3.14/site-packages");
        sys.attr("path") = sys_path;
        s_logger.info(std::string("[fix] sys.path(after patch)=") + std::string(py::str(sys.attr("path"))));

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

    } catch (const std::exception &ex) {
        s_logger.error(std::string("Fatal error initializing Python runtime or executing script: ") + ex.what());
        return 1;
    }

    return 0;
}
