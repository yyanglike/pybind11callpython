#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <pybind11/embed.h>
#include "python_bridge.h"
#include "logger.h"

static Logger s_logger;

namespace py = pybind11;
using namespace script_interpreter;

int main(int argc, char **argv) {
    if (argc < 2) {
        s_logger.error("Usage: run_python_script <script.py> [args...]");
        return 2;
    }

    const std::string script_path = argv[1];
    std::vector<std::string> script_args;
    for (int i = 1; i < argc; ++i) script_args.emplace_back(argv[i]);

    try {
        py::scoped_interpreter guard{}; // start the interpreter
        PythonBridge bridge; // configure python path

        // set sys.argv for the script
        py::module_ sys = py::module_::import("sys");
        py::list py_argv;
        for (const auto &s : script_args) py_argv.append(s);
        sys.attr("argv") = py_argv;

        // read script file
        std::ifstream ifs(script_path);
        if (!ifs.is_open()) {
            s_logger.error(std::string("Failed to open script file: ") + script_path);
            return 3;
        }
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        const std::string code = buffer.str();

        // prepare globals and set __name__ to __main__
        py::dict globals = bridge.globals();
        globals["__name__"] = "__main__";
        globals["__file__"] = script_path;

        // execute the script in a safe try/catch
        try {
            bridge.exec(code, globals, py::dict());
        } catch (const py::error_already_set &e) {
            s_logger.error(std::string("Python exception while executing script:\n") + e.what());
            return 4;
        }

    } catch (const std::exception &ex) {
        s_logger.error(std::string("Fatal error initializing Python runtime: ") + ex.what());
        return 1;
    }

    return 0;
}
