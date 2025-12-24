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
                py::object result = left->toPythonObject() + right->toPythonObject();
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
                py::object result = left->toPythonObject() / right->toPythonObject();
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "%") {
            if (left->isInteger() && right->isInteger()) {
                long long divisor = right->getInteger();
                if (divisor == 0) {
                    throw runtime_error("Modulo by zero");
                }
                return ScriptValue::createInteger(left->getInteger() % divisor);
            } else {
                throw runtime_error("Modulo operation requires integer operands");
            }
        } else if (op == "==") {
            bool equal = (*left == *right);
            return ScriptValue::createBoolean(equal);
        } else if (op == "!=") {
            bool notEqual = !(*left == *right);
            return ScriptValue::createBoolean(notEqual);
        } else if (op == "<") {
            if (left->isNumber() && right->isNumber()) {
                return ScriptValue::createBoolean(left->toDouble() < right->toDouble());
            } else if (left->isPythonObject() || right->isPythonObject()) {
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
                py::object lhs = left->toPythonObject();
                py::object rhs = right->toPythonObject();
                py::object result = py::reinterpret_steal<py::object>(PyObject_RichCompare(lhs.ptr(), rhs.ptr(), Py_GE));
                if (result.is_none()) {
                    throw py::error_already_set();
                }
                return ScriptValue::fromPythonObject(result);
            }
        } else if (op == "&&") {
            return ScriptValue::createBoolean(left->toBoolean() && right->toBoolean());
        } else if (op == "||") {
            return ScriptValue::createBoolean(left->toBoolean() || right->toBoolean());
        }
        
        throw runtime_error("Unsupported binary operator: " + op);
        
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
                py::object result = -value->getPythonObject();
                return ScriptValue::fromPythonObject(result);
            } else {
                throw runtime_error("Unary - operator not supported for this type");
            }
        } else if (op == "!") {
            return ScriptValue::createBoolean(!value->toBoolean());
        }
        
        throw runtime_error("Unsupported unary operator: " + op);
        
    } catch (const exception& e) {
        throw runtime_error("Unary operation error: " + string(e.what()));
    }
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

shared_ptr<ScriptValue> ExpressionEvaluator::executeBlock(PyScriptParser::BlockContext* ctx) {
    // 这个函数需要在AST Visitor中实现，这里暂时返回null
    logger_.error("executeBlock should be implemented in AST Visitor");
    return nullptr;
}

void ExpressionEvaluator::reportError(const string& message, int line, int column) {
    error_handler_.reportError(message, ScriptErrorType::Runtime, ScriptErrorCode::Unknown, line, column);
    logger_.error("ExpressionEvaluator Error: " + message);
}

} // namespace script_interpreter
