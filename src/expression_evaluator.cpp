/**
 * @file expression_evaluator.cpp
 * @brief 表达式求值引擎实现
 */

#include "expression_evaluator.h"
#include "script_value.h"
#include "variable_manager.h"
#include "error_handler.h"
#include "logger.h"
#include "python_bridge.h"
#include "antlr/PyScriptParser.h"

#include <cmath>
#include <stdexcept>

using namespace std;
using namespace antlr4;

namespace script_interpreter {

ExpressionEvaluator::ExpressionEvaluator(VariableManager& variable_manager,
                                       ErrorHandler& error_handler,
                                       Logger& logger,
                                       PythonBridge& python_bridge)
    : variable_manager_(variable_manager)
    , error_handler_(error_handler)
    , logger_(logger)
    , python_bridge_(python_bridge) {
}

shared_ptr<ScriptValue> ExpressionEvaluator::evaluateBinaryOperation(
    const string& op,
    shared_ptr<ScriptValue> left,
    shared_ptr<ScriptValue> right) {
    
    try {
        if (op == "+") {
            // 数字相加或字符串连接
            if (left->isInteger() && right->isInteger()) {
                return ScriptValue::createInteger(left->getInteger() + right->getInteger());
            } else if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createDouble(left->toDouble() + right->toDouble());
            } else if (left->isString() || right->isString()) {
                return ScriptValue::createString(left->toString() + right->toString());
            } else if (left->isList() && right->isList()) {
                // 列表合并
                auto leftList = left->getList();
                auto rightList = right->getList();
                vector<shared_ptr<ScriptValue>> newList;
                newList.reserve(leftList.size() + rightList.size());
                newList.insert(newList.end(), leftList.begin(), leftList.end());
                newList.insert(newList.end(), rightList.begin(), rightList.end());
                return make_shared<ScriptValue>(newList);
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = left->toPythonObject() + right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "//") {
            if (left->isNumber() && right->isNumber()) {
                double divisor = right->toDouble();
                if (abs(divisor) < 1e-10) {
                    throw runtime_error("Division by zero");
                }
                double res = std::floor(left->toDouble() / divisor);
                // if both are integers and division exact, keep integer
                if (left->isInteger() && right->isInteger()) {
                    return ScriptValue::createInteger(static_cast<long long>(res));
                }
                return ScriptValue::createDouble(res);
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = py::module_::import("operator").attr("floordiv")(left->toPythonObject(), right->toPythonObject());
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "&") {
            if (left->isInteger() && right->isInteger()) {
                return ScriptValue::createInteger(left->getInteger() & right->getInteger());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = lhs.attr("__and__")(rhs);
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "|") {
            if (left->isInteger() && right->isInteger()) {
                return ScriptValue::createInteger(left->getInteger() | right->getInteger());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = lhs.attr("__or__")(rhs);
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "^") {
            if (left->isInteger() && right->isInteger()) {
                return ScriptValue::createInteger(left->getInteger() ^ right->getInteger());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = lhs.attr("__xor__")(rhs);
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "<<") {
            if (left->isInteger() && right->isInteger()) {
                return ScriptValue::createInteger(left->getInteger() << right->getInteger());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = py::module_::import("operator").attr("lshift")(left->toPythonObject(), right->toPythonObject());
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == ">>") {
            if (left->isInteger() && right->isInteger()) {
                return ScriptValue::createInteger(left->getInteger() >> right->getInteger());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = py::module_::import("operator").attr("rshift")(left->toPythonObject(), right->toPythonObject());
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "-") {
            if (left->isNumber() && right->isNumber()) {
                if (left->isInteger() && right->isInteger()) {
                    return ScriptValue::createInteger(left->getInteger() - right->getInteger());
                } else {
                    return ScriptValue::createDouble(left->toDouble() - right->toDouble());
                }
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = left->toPythonObject() - right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "*") {
            if (left->isNumber() && right->isNumber()) {
                if (left->isInteger() && right->isInteger()) {
                    return ScriptValue::createInteger(left->getInteger() * right->getInteger());
                } else {
                    return ScriptValue::createDouble(left->toDouble() * right->toDouble());
                }
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = left->toPythonObject() * right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "**") {
            if (left->isNumber() && right->isNumber()) {
                // Try to compute integer power if both are integers and exponent non-negative
                if (left->isInteger() && right->isInteger() && right->getInteger() >= 0) {
                    long long base = left->getInteger();
                    long long exp = right->getInteger();
                    long long result = 1;
                    for (long long i = 0; i < exp; ++i) {
                        result *= base;
                    }
                    return ScriptValue::createInteger(result);
                } else {
                    // Fallback to floating point pow
                    double result = pow(left->toDouble(), right->toDouble());
                    // If both are integers but exponent negative, result is double anyway
                    return ScriptValue::createDouble(result);
                }
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                // Use Python's built-in pow function
                py::object pow_func = py::module_::import("builtins").attr("pow");
                py::object result = pow_func(left->toPythonObject(), right->toPythonObject());
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "/") {
            if (left->isNumber() && right->isNumber()) {
                double divisor = right->toDouble();
                if (abs(divisor) < 1e-10) {
                    throw runtime_error("Division by zero");
                }
                return ScriptValue::createDouble(left->toDouble() / divisor);
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = left->toPythonObject() / right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "%") {
            // If either operand is null, return null (this can happen during function definition)
            if (left->isNull() || right->isNull()) {
                return ScriptValue::createNull();
            }
            if (left->isInteger() && right->isInteger()) {
                long long divisor = right->getInteger();
                if (divisor == 0) {
                    throw runtime_error("Modulo by zero");
                }
                return ScriptValue::createInteger(left->getInteger() % divisor);
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                // Use Python's modulo operator for Python objects
                py::object mod_func = py::module_::import("operator").attr("mod");
                py::object result = mod_func(left->toPythonObject(), right->toPythonObject());
                return ScriptValue::fromPythonObject(result);
            } else {
                // For non-integer numeric types, attempt to perform modulo as Python would
                try {
                    py::gil_scoped_acquire acquire;
                    // Try to convert to Python objects and use Python's modulo
                    py::object lhs = left->toPythonObject();
                    py::object rhs = right->toPythonObject();
                    py::object mod_func = py::module_::import("operator").attr("mod");
                    py::object result = mod_func(lhs, rhs);
                    return ScriptValue::fromPythonObject(result);
                } catch (...) {
                    throw runtime_error("Modulo operation requires integer operands or Python objects");
                }
            }
        } else if (op == "==") {
            // 如果一个是 PythonObject，另一个是 List/Dictionary，转换为 PythonObject 再比较
            if ((left->isPythonObject() && (right->isList() || right->isDictionary())) ||
                (right->isPythonObject() && (left->isList() || left->isDictionary()))) {
                try {
                    py::gil_scoped_acquire acquire;
                    py::object lhs = left->toPythonObject();
                    py::object rhs = right->toPythonObject();
                    py::object result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_EQ));
                    if (!result.ptr() || result.is_none()) {
                        throw py::error_already_set();
                    }
                    bool equal = py::cast<bool>(result);
                    return ScriptValue::createBoolean(equal);
                } catch (const py::error_already_set& e) {
                    {
                        py::gil_scoped_acquire acquire;
                        PyErr_Clear();
                    }
                    // 如果 Python 比较失败，回退到原生比较
                    bool equal = (*left == *right);
                    return ScriptValue::createBoolean(equal);
                }
            }
            bool equal = (*left == *right);
            return ScriptValue::createBoolean(equal);
        } else if (op == "!=") {
            // 如果一个是 PythonObject，另一个是 List/Dictionary，转换为 PythonObject 再比较
            if ((left->isPythonObject() && (right->isList() || right->isDictionary())) ||
                (right->isPythonObject() && (left->isList() || left->isDictionary()))) {
                try {
                    py::gil_scoped_acquire acquire;
                    py::object lhs = left->toPythonObject();
                    py::object rhs = right->toPythonObject();
                    py::object result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_NE));
                    if (!result.ptr() || result.is_none()) {
                        throw py::error_already_set();
                    }
                    bool notEqual = py::cast<bool>(result);
                    return ScriptValue::createBoolean(notEqual);
                } catch (const py::error_already_set& e) {
                    {
                        py::gil_scoped_acquire acquire;
                        PyErr_Clear();
                    }
                    // 如果 Python 比较失败，回退到原生比较
                    bool notEqual = !(*left == *right);
                    return ScriptValue::createBoolean(notEqual);
                }
            }
            bool notEqual = !(*left == *right);
            return ScriptValue::createBoolean(notEqual);
        } else if (op == "<") {
            if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createBoolean(left->toDouble() < right->toDouble());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_LT));
                if (!result.ptr() || result.is_none()) {
                    throw py::error_already_set();
                }
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == ">") {
            if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createBoolean(left->toDouble() > right->toDouble());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_GT));
                if (result.is_none()) {
                    throw py::error_already_set();
                }
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "<=") {
            if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createBoolean(left->toDouble() <= right->toDouble());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_LE));
                if (result.is_none()) {
                    throw py::error_already_set();
                }
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == ">=") {
            if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createBoolean(left->toDouble() >= right->toDouble());
            } else if (left->isPythonObject() || right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_GE));
                if (result.is_none()) {
                    throw py::error_already_set();
                }
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "in") {
            return contains(right, left);
        } else if (op == "not in") {
            auto result = contains(right, left);
            if (!result) {
                return ScriptValue::createBoolean(true);
            }
            return ScriptValue::createBoolean(!result->toBoolean());
        } else if (op == "is") {
            // is运算符：检查对象身份（id）
            if (left->isPythonObject() && right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                bool is_same = lhs.ptr() == rhs.ptr();
                return ScriptValue::createBoolean(is_same);
            } else {
                // 对于非Python对象，使用==比较
                return evaluateBinaryOperation("==", left, right);
            }
        } else if (op == "is not") {
            // is not运算符：检查对象身份不相等
            if (left->isPythonObject() && right->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                bool is_same = lhs.ptr() == rhs.ptr();
                return ScriptValue::createBoolean(!is_same);
            } else {
                // 对于非Python对象，使用!=比较
                return evaluateBinaryOperation("!=", left, right);
            }
        } else if (op == "&&") {
            // 逻辑与，短路
            if (!isTruthy(left)) {
                return ScriptValue::createBoolean(false);
            }
            return ScriptValue::createBoolean(isTruthy(right));
        } else if (op == "||") {
            // 逻辑或，短路
            if (isTruthy(left)) {
                return ScriptValue::createBoolean(true);
            }
            return ScriptValue::createBoolean(isTruthy(right));
        }
        
        // 尝试统一回退到 Python 运算符
        if (!left->isNull() && !right->isNull()) {
            try {
                py::gil_scoped_acquire acquire;
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result;
                if (op == "+") {
                    result = py::module_::import("operator").attr("add")(lhs, rhs);
                } else if (op == "-") {
                    result = py::module_::import("operator").attr("sub")(lhs, rhs);
                } else if (op == "*") {
                    result = py::module_::import("operator").attr("mul")(lhs, rhs);
                } else if (op == "/") {
                    result = py::module_::import("operator").attr("truediv")(lhs, rhs);
                } else if (op == "%") {
                    result = py::module_::import("operator").attr("mod")(lhs, rhs);
                } else if (op == "**") {
                    result = py::module_::import("operator").attr("pow")(lhs, rhs);
                } else if (op == "<") {
                    result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_LT));
                } else if (op == ">") {
                    result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_GT));
                } else if (op == "<=") {
                    result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_LE));
                } else if (op == ">=") {
                    result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_GE));
                } else if (op == "==") {
                    result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_EQ));
                } else if (op == "!=") {
                    result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_NE));
                } else if (op == "&") {
                    result = lhs.attr("__and__")(rhs);
                } else if (op == "|") {
                    result = lhs.attr("__or__")(rhs);
                } else if (op == "^") {
                    result = lhs.attr("__xor__")(rhs);
                } else if (op == "<<") {
                    result = lhs.attr("__lshift__")(rhs);
                } else if (op == ">>") {
                    result = lhs.attr("__rshift__")(rhs);
                }
                if (result && !result.is_none()) {
                    return ScriptValue::fromPythonObject(result);
                }
            } catch (const py::error_already_set& e) {
                throw runtime_error("Binary operation error: " + string(e.what()));
            } catch (const exception& e) {
                throw runtime_error("Binary operation error: " + string(e.what()));
            }
        }
        
        throw runtime_error("Unsupported binary operator: " + op);
        
    } catch (const py::error_already_set& e) {
        throw runtime_error("Binary operation error: " + string(e.what()));
    } catch (const exception& e) {
        throw runtime_error("Binary operation error: " + string(e.what()));
    }
}

shared_ptr<ScriptValue> ExpressionEvaluator::evaluateUnaryOperation(
    const string& op,
    shared_ptr<ScriptValue> value) {
    
    try {
        if (op == "-") {
            if (value->isInteger()) {
                return ScriptValue::createInteger(-value->getInteger());
            } else if (value->isDouble()) {
                return ScriptValue::createDouble(-value->getDouble());
            } else if (value->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = -value->getPythonObject();
                return ScriptValue::fromPythonObject(result);
            } else {
                throw runtime_error("Unary - operator not supported for this type");
            }
        } else if (op == "!" || op == "not") {
            return ScriptValue::createBoolean(!value->toBoolean());
        } else if (op == "+") {
            if (value->isInteger() || value->isDouble() || value->isBoolean() || value->isString()) {
                return value;
            } else if (value->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = py::module_::import("operator").attr("pos")(value->toPythonObject());
                return ScriptValue::fromPythonObject(result);
            } else {
                return value; // treat as no-op
            }
        } else if (op == "~") {
            if (value->isInteger()) {
                return ScriptValue::createInteger(~value->getInteger());
            } else if (value->isPythonObject()) {
                py::gil_scoped_acquire acquire;
                py::object result = py::module_::import("operator").attr("invert")(value->toPythonObject());
                return ScriptValue::fromPythonObject(result);
            } else {
                throw runtime_error("Unary ~ operator not supported for this type");
            }
        }
        
        throw runtime_error("Unsupported unary operator: " + op);
        
    } catch (const exception& e) {
        throw runtime_error("Unary operation error: " + string(e.what()));
    }
}

shared_ptr<ScriptValue> ExpressionEvaluator::lenOf(const shared_ptr<ScriptValue>& value) {
    if (!value) return ScriptValue::createNull();
    if (value->isList()) {
        return ScriptValue::createInteger(static_cast<long long>(value->listSize()));
    }
    if (value->isDictionary()) {
        return ScriptValue::createInteger(static_cast<long long>(value->getDictionary().size()));
    }
    if (value->isString()) {
        return ScriptValue::createInteger(static_cast<long long>(value->getString().size()));
    }
    if (value->isPythonObject()) {
        try {
            py::gil_scoped_acquire acquire;
            py::object obj = value->toPythonObject();
            return ScriptValue::createInteger(static_cast<long long>(py::len(obj)));
        } catch (const py::error_already_set& e) {
            reportError("len() failed: " + string(e.what()));
            return ScriptValue::createNull();
        }
    }
    return ScriptValue::createNull();
}

shared_ptr<ScriptValue> ExpressionEvaluator::contains(const shared_ptr<ScriptValue>& container,
                                                      const shared_ptr<ScriptValue>& needle) {
    if (!container) return ScriptValue::createBoolean(false);
    if (container->isList()) {
        for (auto& item : container->getList()) {
            if (item && needle && *item == *needle) return ScriptValue::createBoolean(true);
            if (!item && !needle) return ScriptValue::createBoolean(true);
        }
        return ScriptValue::createBoolean(false);
    }
    if (container->isDictionary()) {
        std::string key = needle ? needle->toString() : "";
        return ScriptValue::createBoolean(container->getDictionary().count(key) > 0);
    }
    if (container->isString()) {
        if (!needle || !needle->isString()) return ScriptValue::createBoolean(false);
        return ScriptValue::createBoolean(container->getString().find(needle->getString()) != std::string::npos);
    }
    if (container->isPythonObject()) {
        try {
            py::gil_scoped_acquire acquire;
            py::object res = py::module_::import("operator").attr("contains")(container->toPythonObject(), needle ? needle->toPythonObject() : py::none());
            return ScriptValue::fromPythonObject(res);
        } catch (const py::error_already_set& e) {
            reportError("contains failed: " + string(e.what()));
            return ScriptValue::createBoolean(false);
        }
    }
    return ScriptValue::createBoolean(false);
}

bool ExpressionEvaluator::isTruthy(shared_ptr<ScriptValue> value) const {
    if (!value) return false;
    return value->toBoolean();
}

any ExpressionEvaluator::evaluateExpression(PyScriptParser::ExpressionContext* ctx) {
    // 这个函数需要在AST Visitor中实现，这里暂时返回null
    logger_.error("evaluateExpression should be implemented in AST Visitor");
    return any();
}

shared_ptr<ScriptValue> ExpressionEvaluator::executeSuite(PyScriptParser::SuiteContext* ctx) {
    // 这个函数需要在AST Visitor中实现，这里暂时返回null
    logger_.error("executeSuite should be implemented in AST Visitor");
    return nullptr;
}

void ExpressionEvaluator::reportError(const string& message, int line, int column) {
    error_handler_.reportError(message, ScriptErrorType::Runtime, ScriptErrorCode::Unknown, line, column);
    logger_.error("ExpressionEvaluator Error: " + message);
}

} // namespace script_interpreter
