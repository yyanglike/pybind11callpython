#pragma once

#include <pybind11/pybind11.h>
#include "script_value.h"
#include "variable_manager.h"
#include "logger.h"
#include <memory>

namespace script_interpreter {

namespace py = pybind11;

// Python 可迭代/迭代器包装，用于无 eval 的生成器表达式
class GeneratorWrapper : public std::enable_shared_from_this<GeneratorWrapper> {
public:
    GeneratorWrapper(py::iterator source_iter,
                     const std::string& var_name,
                     py::object body_callable,
                     VariableManager* var_mgr)
        : iter_(std::move(source_iter))
        , var_name_(var_name)
        , body_callable_(std::move(body_callable))
        , var_mgr_(var_mgr) {
        if (var_mgr_) {
            old_var_ = var_mgr_->getVariable(var_name_);
        }
    }

    ~GeneratorWrapper() {
        // 退出时恢复原变量
        if (old_var_ && var_mgr_) {
            var_mgr_->setVariable(var_name_, old_var_);
        }
    }

    // Python 迭代协议：__iter__ -> self
    py::object iter() {
        py::print("_GeneratorWrapper.__iter__");
        return py::cast(shared_from_this(), py::return_value_policy::reference_internal);
    }

    // Python 迭代协议：__next__
    py::object next() {
        try {
            if (!iter_) {
                throw py::stop_iteration();
            }
            if (!iter_.equal(py::iterator::sentinel())) {
                py::print("_GeneratorWrapper.__next__");
                py::object item = py::reinterpret_borrow<py::object>(*iter_);
                ++iter_;
                if (var_mgr_) {
                    var_mgr_->setVariable(var_name_, ScriptValue::fromPythonObject(item));
                }
                py::object result = body_callable_();
                return result;
            }
            throw py::stop_iteration();
        } catch (const py::error_already_set& e) {
            throw;
        } catch (const std::exception& e) {
            throw py::value_error(std::string("GeneratorWrapper: ") + e.what());
        }
    }

    static void bind(py::module_ &m) {
        py::class_<GeneratorWrapper, std::shared_ptr<GeneratorWrapper>>(m, "_GeneratorWrapper")
            .def(py::init([](py::iterator it, const std::string& name, py::object body, py::capsule vm_caps) {
                    auto* vm = reinterpret_cast<VariableManager*>(vm_caps.get_pointer());
                    return new GeneratorWrapper(it, name, body, vm);
                 }),
                 py::keep_alive<1, 2>(), py::keep_alive<1, 3>(), py::keep_alive<1, 4>())
            .def("__iter__", &GeneratorWrapper::iter)
            .def("__next__", &GeneratorWrapper::next);
    }

private:
    py::iterator iter_;
    std::string var_name_;
    py::object body_callable_;
    VariableManager* var_mgr_;
    std::shared_ptr<ScriptValue> old_var_;
};

} // namespace script_interpreter


