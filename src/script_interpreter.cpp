#include "script_interpreter.h"
#include "antlr/PyScriptLexer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>

using namespace antlr4;
using namespace std;

// 构造函数
ScriptInterpreter::ScriptInterpreter() 
    : result_(nullptr), 
      has_error_(false), 
      python_initialized_(false),
      defining_function_(false) {
    
    std::cerr << "ScriptInterpreter constructor started" << std::endl;
    // 检查Python解释器是否已初始化
    if (!Py_IsInitialized()) {
        try {
            py::initialize_interpreter();
            python_initialized_ = true;
            std::cerr << "Python interpreter initialized" << std::endl;
        } catch (const exception& e) {
            cerr << "Failed to initialize Python interpreter: " << e.what() << endl;
        }
    } else {
        std::cerr << "Python interpreter already initialized" << std::endl;
    }
    
    // 配置Python路径
    try {
        py::module_ sys = py::module_::import("sys");
        // 将当前目录下的python目录添加到Python路径
        py::str python_path = "../python";
        sys.attr("path").attr("insert")(0, python_path);
        std::cerr << "Python path configured: " << python_path.cast<std::string>() << std::endl;
    } catch (const exception& e) {
        cerr << "Failed to configure Python path: " << e.what() << endl;
    }
    
    // 导入builtins模块以供内置函数使用
    try {
        builtins_ = py::module_::import("builtins");
        std::cerr << "Builtins imported successfully" << std::endl;
    } catch (const exception& e) {
        cerr << "Failed to import builtins: " << e.what() << endl;
        // 将builtins_设置为none，后续使用时再尝试导入
        builtins_ = py::none();
    }
    std::cerr << "ScriptInterpreter constructor finished" << std::endl;
}

// 析构函数
ScriptInterpreter::~ScriptInterpreter() {
    if (python_initialized_) {
        try {
            py::finalize_interpreter();
        } catch (...) {
            // 忽略清理错误
        }
    }
}

// 执行脚本
bool ScriptInterpreter::execute(const string& script) {
    std::cerr << "ScriptInterpreter::execute() called with script: " << script << std::endl;
    has_error_ = false;
    error_message_.clear();
    result_ = nullptr;
    
    try {
        std::cerr << "Creating ANTLRInputStream..." << std::endl;
        ANTLRInputStream input(script);
        std::cerr << "Creating PyScriptLexer..." << std::endl;
        PyScriptLexer lexer(&input);
        std::cerr << "Creating CommonTokenStream..." << std::endl;
        CommonTokenStream tokens(&lexer);
        
        // 填充token流
        std::cerr << "Filling tokens..." << std::endl;
        tokens.fill();
        
        std::cerr << "Creating PyScriptParser..." << std::endl;
        PyScriptParser parser(&tokens);
        
        // 设置错误处理器
        parser.removeErrorListeners();
        
        std::cerr << "Parsing program..." << std::endl;
        auto tree = parser.program();
        std::cerr << "Parse tree created successfully" << std::endl;
        
        if (has_error_) {
            std::cerr << "Has error before visiting" << std::endl;
            return false;
        }
        
        // 遍历AST
        std::cerr << "Visiting program tree..." << std::endl;
        visitProgram(tree);
        std::cerr << "Visit completed" << std::endl;
        
        return !has_error_;
        
    } catch (const exception& e) {
        std::cerr << "Exception in execute: " << e.what() << std::endl;
        reportError("Script execution error: " + string(e.what()));
        return false;
    }
}

bool ScriptInterpreter::executeFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        reportError("Cannot open file: " + filename);
        return false;
    }
    
    stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    
    return execute(buffer.str());
}

shared_ptr<ScriptValue> ScriptInterpreter::getVariable(const string& name) {
    auto it = variables_.find(name);
    if (it != variables_.end()) {
        return it->second;
    }
    return nullptr;
}

void ScriptInterpreter::setVariable(const string& name, shared_ptr<ScriptValue> value) {
    variables_[name] = value;
}

void ScriptInterpreter::clearEnvironment() {
    variables_.clear();
    // imported_modules_.clear(); // 保留导入的模块，避免重复导入
    result_ = nullptr;
    has_error_ = false;
    error_message_.clear();
}

// ========== 错误报告 ==========

void ScriptInterpreter::reportError(const string& message) {
    error_message_ = message;
    has_error_ = true;
    cerr << "Script Error: " << message << endl;
}

void ScriptInterpreter::reportError(const string& message, antlr4::ParserRuleContext *ctx) {
    string fullMessage = message;
    
    if (ctx) {
        auto token = ctx->getStart();
        if (token) {
            fullMessage += " at line " + to_string(token->getLine()) +
                          ", column " + to_string(token->getCharPositionInLine());
        }
    }
    
    reportError(fullMessage);
}

// ========== 辅助方法 ==========

shared_ptr<ScriptValue> ScriptInterpreter::evaluateExpression(PyScriptParser::ExpressionContext *ctx) {
    if (!ctx) {
        std::cerr << "evaluateExpression: ctx is null!" << std::endl;
        return nullptr;
    }
    auto result = visit(ctx);
    try {
        return any_cast<shared_ptr<ScriptValue>>(result);
    } catch (const bad_any_cast&) {
        return nullptr;
    }
}

shared_ptr<ScriptValue> ScriptInterpreter::evaluateBinaryOperation(
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
                return std::make_shared<ScriptValue>(newList);
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

shared_ptr<ScriptValue> ScriptInterpreter::evaluateUnaryOperation(
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

bool ScriptInterpreter::isTruthy(shared_ptr<ScriptValue> value) const {
    if (!value) return false;
    return value->toBoolean();
}

shared_ptr<ScriptValue> ScriptInterpreter::callPythonFunction(
    py::object func,
    const vector<shared_ptr<ScriptValue>>& args) {
    
    try {
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
        }
        
        py::object result = func(*pyArgs);
        return ScriptValue::fromPythonObject(result);
        
    } catch (const py::error_already_set& e) {
        throw runtime_error("Python function call error: " + string(e.what()));
    }
}

shared_ptr<ScriptValue> ScriptInterpreter::createPythonInstance(
    const string& moduleName,
    const string& className,
    const vector<shared_ptr<ScriptValue>>& args) {
    
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
        }
        
        py::object instance = classObj(*pyArgs);
        return ScriptValue::fromPythonObject(instance);
        
    } catch (const py::error_already_set& e) {
        throw runtime_error("Python instance creation error: " + string(e.what()));
    }
}

shared_ptr<ScriptValue> ScriptInterpreter::getMember(
    shared_ptr<ScriptValue> object,
    const string& memberName) {
    
    if (!object) {
        return nullptr;
    }
    
    if (object->isPythonObject()) {
        py::object pyObj = object->getPythonObject();
        
        // 特殊处理 toString 方法
        if (memberName == "toString" || memberName == "toString()") {
            // 对于Python对象，返回一个调用 str(obj) 的 lambda 函数
            try {
                py::object str_func = py::module_::import("builtins").attr("str");
                py::object lambda_func = py::cpp_function([pyObj, str_func]() {
                    return str_func(pyObj);
                });
                return ScriptValue::fromPythonObject(lambda_func);
            } catch (const py::error_already_set& e) {
                std::cerr << "Error creating toString lambda: " << e.what() << std::endl;
                return nullptr;
            }
        }
        
        try {
            if (py::isinstance<py::module_>(pyObj)) {
                py::module_ module = pyObj.cast<py::module_>();
                py::object member = module.attr(memberName.c_str());
                return ScriptValue::fromPythonObject(member);
            } else if (py::hasattr(pyObj, memberName.c_str())) {
                py::object member = pyObj.attr(memberName.c_str());
                return ScriptValue::fromPythonObject(member);
            }
        } catch (const py::error_already_set&) {
            // 属性不存在，检查是否是Python内置方法
            // 对于Python对象，检查是否有__str__、__repr__等方法
            if (memberName == "__str__" || memberName == "__repr__") {
                try {
                    py::object member = pyObj.attr(memberName.c_str());
                    return ScriptValue::fromPythonObject(member);
                } catch (const py::error_already_set&) {
                    // 方法不存在
                }
            }
        }
    }
    
    // 对于非Python对象，也可以支持toString方法
    if (memberName == "toString" || memberName == "toString()") {
        // 返回一个返回对象字符串表示的lambda
        try {
            py::object str_func = py::module_::import("builtins").attr("str");
            py::object obj_py = object->toPythonObject();
            py::object lambda_func = py::cpp_function([obj_py, str_func]() {
                return str_func(obj_py);
            });
            return ScriptValue::fromPythonObject(lambda_func);
        } catch (const py::error_already_set& e) {
            std::cerr << "Error creating toString lambda for non-Python object: " << e.what() << std::endl;
            return nullptr;
        }
    }
    
    return nullptr;
}

void ScriptInterpreter::setMember(
    shared_ptr<ScriptValue> object,
    const string& memberName,
    shared_ptr<ScriptValue> value) {
    
    if (!object || !object->isPythonObject()) {
        throw runtime_error("Cannot set member on non-object type");
    }
    
    py::object pyObj = object->getPythonObject();
    py::object pyValue = value->toPythonObject();
    
    try {
        pyObj.attr(memberName.c_str()) = pyValue;
    } catch (const py::error_already_set& e) {
        throw runtime_error("Python attribute assignment error: " + string(e.what()));
    }
}

shared_ptr<ScriptValue> ScriptInterpreter::executeBlock(PyScriptParser::BlockContext *ctx) {
    if (!ctx) {
        return nullptr;
    }
    
    if (ctx->statement().empty()) {
        return ScriptValue::createNull();
    }
    
    // 执行代码块中的所有语句
    shared_ptr<ScriptValue> lastResult = nullptr;
    for (auto stmt : ctx->statement()) {
        auto result = visit(stmt);
        if (has_error_) {
            break;
        }
        
        try {
            lastResult = any_cast<shared_ptr<ScriptValue>>(result);
        } catch (const bad_any_cast&) {
            // 忽略非ScriptValue结果
        }
    }
    
    return lastResult ? lastResult : ScriptValue::createNull();
}

// ========== Visitor方法实现 ==========

any ScriptInterpreter::visitProgram(PyScriptParser::ProgramContext *ctx) {
    // 执行所有语句
    for (auto stmt : ctx->statement()) {
        visit(stmt);
        if (has_error_) {
            break;
        }
    }
    
    // 如果没有return语句，最后一条语句的值作为结果
    if (result_ == nullptr && ctx->statement().size() > 0) {
        // 尝试获取最后一个表达式语句的结果
        auto lastStmt = ctx->statement().back();
        // 注意：这里需要根据实际的statement类型来处理，暂时先简单处理
        // 实际上应该检查是否是expressionStatement
        auto exprStmt = dynamic_cast<PyScriptParser::ExpressionStatementContext*>(lastStmt);
        if (exprStmt) {
            result_ = evaluateExpression(exprStmt->expression());
        }
    }
    
    return any();
}

any ScriptInterpreter::visitStatement(PyScriptParser::StatementContext *ctx) {
    // 根据实际的子节点类型进行分发
    if (ctx->importStatement()) {
        return visit(ctx->importStatement());
    } else if (ctx->functionDefinition()) {
        return visit(ctx->functionDefinition());
    } else if (ctx->assignment()) {
        return visit(ctx->assignment());
    } else if (ctx->ifStatement()) {
        return visit(ctx->ifStatement());
    } else if (ctx->whileStatement()) {
        return visit(ctx->whileStatement());
    } else if (ctx->forStatement()) {
        return visit(ctx->forStatement());
    } else if (ctx->returnStatement()) {
        return visit(ctx->returnStatement());
    } else if (ctx->expressionStatement()) {
        return visit(ctx->expressionStatement());
    }
    
    reportError("Unknown statement type", ctx);
    return any();
}

any ScriptInterpreter::visitImportStatement(PyScriptParser::ImportStatementContext *ctx) {
    std::cerr << "visitImportStatement called" << std::endl;
    
    try {
        auto dottedNameCtx = ctx->dottedName();
        if (!dottedNameCtx) {
            reportError("Import statement must specify a module name", ctx);
            return any();
        }
        
        // 获取模块名
        string moduleName = dottedNameCtx->getText();
        std::cerr << "Importing module: " << moduleName << std::endl;
        
        // 检查是否有别名
        string alias;
        if (ctx->IDENTIFIER()) {
            alias = ctx->IDENTIFIER()->getText();
            std::cerr << "Alias: " << alias << std::endl;
        }
        
        // 导入Python模块
        std::cerr << "Calling py::module_::import..." << std::endl;
        py::module_ module = py::module_::import(moduleName.c_str());
        std::cerr << "Module imported successfully: " << moduleName << std::endl;
        
        imported_modules_[moduleName] = module;
        
        // 存储模块引用
        if (!alias.empty()) {
            variables_[alias] = ScriptValue::createPythonObject(module);
            std::cerr << "Module stored in variables with alias: " << alias << std::endl;
        } else {
            // 使用模块名的最后一部分作为变量名
            size_t dotPos = moduleName.find_last_of('.');
            string shortName = (dotPos != string::npos) ? 
                              moduleName.substr(dotPos + 1) : moduleName;
            variables_[shortName] = ScriptValue::createPythonObject(module);
            std::cerr << "Module stored in variables with short name: " << shortName << std::endl;
        }
        
        // 验证存储
        std::cerr << "Verifying storage..." << std::endl;
        if (!alias.empty()) {
            auto it = variables_.find(alias);
            if (it != variables_.end()) {
                std::cerr << "Variable '" << alias << "' found in variables map" << std::endl;
            } else {
                std::cerr << "ERROR: Variable '" << alias << "' NOT found in variables map!" << std::endl;
            }
        }
        
    } catch (const py::error_already_set& e) {
        std::cerr << "Python import error: " << e.what() << std::endl;
        reportError("Failed to import module: " + string(e.what()), ctx);
    } catch (const exception& e) {
        std::cerr << "General import error: " << e.what() << std::endl;
        reportError("Import error: " + string(e.what()), ctx);
    }
    
    return any();
}

any ScriptInterpreter::visitFunctionDefinition(PyScriptParser::FunctionDefinitionContext *ctx) {
    std::cerr << "visitFunctionDefinition called" << std::endl;
    
    string funcName = ctx->IDENTIFIER()->getText();
    std::cerr << "Function name: " << funcName << std::endl;
    
    // 获取参数列表
    vector<string> paramNames;
    if (ctx->parameterList()) {
        auto paramIds = ctx->parameterList()->IDENTIFIER();
        for (auto* id : paramIds) {
            paramNames.push_back(id->getText());
        }
    }
    
    // 获取函数体
    auto blockCtx = ctx->block();
    if (!blockCtx) {
        reportError("Function definition missing body", ctx);
        return any();
    }
    
    // 获取函数体中的所有语句
    auto statements = blockCtx->statement();
    std::cerr << "Number of statements in function body: " << statements.size() << std::endl;
    
    // 打印语句类型信息
    for (size_t i = 0; i < statements.size(); ++i) {
        auto stmt = statements[i];
        std::cerr << "Statement " << i << " type: " << typeid(*stmt).name() << std::endl;
        std::cerr << "Statement " << i << " text: " << stmt->getText() << std::endl;
        
        // 检查是否是return语句
        auto returnStmt = dynamic_cast<PyScriptParser::ReturnStatementContext*>(stmt);
        if (returnStmt) {
            std::cerr << "Statement " << i << " is a return statement" << std::endl;
            if (returnStmt->expression()) {
                std::cerr << "Return expression: " << returnStmt->expression()->getText() << std::endl;
            }
        }
    }
    
    // 设置标志防止在函数定义体中报错
    defining_function_ = true;
    
    // 构建函数定义字符串
    string funcDef = "def " + funcName + "(";
    for (size_t i = 0; i < paramNames.size(); ++i) {
        if (i > 0) funcDef += ", ";
        funcDef += paramNames[i];
    }
    funcDef += "):\n";
    
    if (statements.empty()) {
        funcDef += "    pass";
        std::cerr << "Warning: Function body is empty, using 'pass'" << std::endl;
    } else {
    // 遍历所有语句，将它们添加到函数体中
    for (auto stmt : statements) {
        // 检查是否是return语句 - 使用StatementContext的方法
        auto returnStmt = stmt->returnStatement();
        if (returnStmt) {
            // 获取return语句中的表达式
            auto exprCtx = returnStmt->expression();
            if (exprCtx) {
                string exprText = exprCtx->getText();
                funcDef += "    return " + exprText + "\n";
            } else {
                funcDef += "    return\n";
            }
        } else {
            // 其他语句，使用原始文本
            string stmtText = stmt->getText();
            // 移除末尾的分号（如果有）
            if (!stmtText.empty() && stmtText.back() == ';') {
                stmtText.pop_back();
            }
            funcDef += "    " + stmtText + "\n";
        }
    }
    }
    
    std::cerr << "Function definition string:\n" << funcDef << std::endl;
    
    // 在Python中执行函数定义
    py::dict globals = py::globals();
    // 确保globals包含__builtins__
    if (!globals.contains("__builtins__")) {
        try {
            py::module_ builtins = py::module_::import("builtins");
            globals["__builtins__"] = builtins;
        } catch (...) {
            // 忽略错误
        }
    }
    
    try {
        py::exec(funcDef, globals, globals);
        py::object func = globals[funcName.c_str()];
        variables_[funcName] = ScriptValue::fromPythonObject(func);
        std::cerr << "Function defined: " << funcName << std::endl;
    } catch (const py::error_already_set& e) {
        reportError("Failed to define function " + funcName + ": " + string(e.what()), ctx);
    }
    
    // 重置标志
    defining_function_ = false;
    // 返回非空值阻止访问子节点
    return any(true);
}

any ScriptInterpreter::visitParameterList(PyScriptParser::ParameterListContext *ctx) {
    // 参数列表已经在函数定义中处理
    return any();
}

any ScriptInterpreter::visitIfStatement(PyScriptParser::IfStatementContext *ctx) {
    std::cerr << "visitIfStatement called" << std::endl;
    
    auto exprCtx = ctx->expression();
    if (!exprCtx) {
        reportError("If statement condition is missing", ctx);
        return any();
    }
    
    auto condValue = evaluateExpression(exprCtx);
    if (!condValue) {
        reportError("Cannot evaluate condition", ctx);
        return any();
    }
    
    if (isTruthy(condValue)) {
        auto thenBlock = ctx->block(0);
        if (thenBlock) {
            return visit(thenBlock);
        }
    } else if (ctx->block().size() > 1) {
        auto elseBlock = ctx->block(1);
        if (elseBlock) {
            return visit(elseBlock);
        }
    }
    
    return any();
}

any ScriptInterpreter::visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) {
    while (true) {
        auto condValue = evaluateExpression(ctx->expression());
        
        if (!condValue) {
            reportError("Cannot evaluate condition", ctx);
            break;
        }
        
        if (!isTruthy(condValue)) {
            break;
        }
        
        visit(ctx->block());
        
        if (has_error_) {
            break;
        }
    }
    
    return any();
}

any ScriptInterpreter::visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) {
    // 如果正在定义函数，则跳过求值，只返回占位符
    if (defining_function_) {
        std::cerr << "Skipping return statement evaluation during function definition" << std::endl;
        return any();
    }
    
    if (ctx->expression()) {
        result_ = evaluateExpression(ctx->expression());
    } else {
        result_ = ScriptValue::createNull();
    }
    return any();
}

any ScriptInterpreter::visitBlock(PyScriptParser::BlockContext *ctx) {
    if (ctx->statement().empty()) {
        // 空代码块
        return any();
    }
    
    // 执行代码块中的所有语句
    for (auto stmt : ctx->statement()) {
        visit(stmt);
        if (has_error_) {
            break;
        }
    }
    
    return any();
}

any ScriptInterpreter::visitAssignment(PyScriptParser::AssignmentContext *ctx) {
    // 有三种赋值形式：标识符赋值、属性赋值、下标赋值
    if (ctx->IDENTIFIER()) {
        // 标识符赋值: IDENTIFIER assignmentOperator expression
        string varName = ctx->IDENTIFIER()->getText();
        auto op = ctx->assignmentOperator();
        if (!op) {
            reportError("Missing assignment operator", ctx);
            return any();
        }
        
        auto rightExpr = ctx->expression(); // 右侧表达式
        if (!rightExpr) {
            reportError("Missing right-hand side expression", ctx);
            return any();
        }
        
        auto rightValue = evaluateExpression(rightExpr);
        if (!rightValue) {
            reportError("Cannot evaluate right-hand side", ctx);
            return any();
        }
        
        string opText = op->getText();
        if (opText == "=") {
            // 简单赋值
            variables_[varName] = rightValue;
        } else {
            // 复合赋值操作符
            auto leftVal = getVariable(varName);
            if (!leftVal) {
                reportError("Variable '" + varName + "' not defined for compound assignment", ctx);
                return any();
            }
            
            // 执行复合运算
            string baseOp = opText.substr(0, opText.size() - 1); // 去掉'='
            auto result = evaluateBinaryOperation(baseOp, leftVal, rightValue);
            if (!result) {
                reportError("Unsupported compound assignment operator: " + opText, ctx);
                return any();
            }
            
            variables_[varName] = result;
        }
    } else if (ctx->attributeAccess()) {
        // 属性赋值: attributeAccess '=' expression
        // TODO: 实现属性赋值
        reportError("Attribute assignment not implemented yet", ctx);
        return any();
    } else if (ctx->subscriptAccess()) {
        // 下标赋值: subscriptAccess '=' expression
        auto subscriptCtx = ctx->subscriptAccess();
        auto primaryCtx = subscriptCtx->primaryExpression();
        if (!primaryCtx) {
            reportError("Subscript access missing object", ctx);
            return any();
        }
        
        auto objectAny = visit(primaryCtx);
        shared_ptr<ScriptValue> objectValue;
        try {
            objectValue = any_cast<shared_ptr<ScriptValue>>(objectAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate object in subscript assignment", ctx);
            return any();
        }
        
        if (!objectValue) {
            reportError("Cannot evaluate object in subscript assignment", ctx);
            return any();
        }
        
        auto indexExpr = subscriptCtx->expression();
        if (!indexExpr) {
            reportError("Missing subscript index", ctx);
            return any();
        }
        
        auto indexValue = evaluateExpression(indexExpr);
        if (!indexValue) {
            reportError("Cannot evaluate subscript index", ctx);
            return any();
        }
        
        // 对于下标赋值，直接获取右侧表达式（语法是 subscriptAccess '=' expression）
        auto rightExpr = ctx->expression(); // 右侧表达式
        if (!rightExpr) {
            reportError("Missing right-hand side expression", ctx);
            return any();
        }
        
        auto rightValue = evaluateExpression(rightExpr);
        if (!rightValue) {
            reportError("Cannot evaluate right-hand side", ctx);
            return any();
        }
        
        // 执行下标赋值
        if (objectValue->isPythonObject()) {
            py::object pyObj = objectValue->getPythonObject();
            try {
                py::object pyIndex = indexValue->toPythonObject();
                py::object pyRight = rightValue->toPythonObject();
                pyObj[pyIndex] = pyRight;
                // 下标赋值不产生新值，返回右侧值
                return any(rightValue);
            } catch (const py::error_already_set& e) {
                reportError("Python subscript assignment error: " + string(e.what()), ctx);
                return any();
            }
        } else if (objectValue->isList()) {
            // 列表赋值
            // 索引必须是整数
            if (!indexValue->isInteger()) {
                reportError("List index must be an integer", ctx);
                return any();
            }
            
            long long index = indexValue->getInteger();
            
            if (index < 0 || index >= static_cast<long long>(objectValue->listSize())) {
                reportError("List index out of bounds: " + to_string(index) + 
                           " (list size: " + to_string(objectValue->listSize()) + ")", ctx);
                return any();
            }
            
            // 更新列表元素
            objectValue->setAt(static_cast<size_t>(index), rightValue);
            return any(rightValue);
        } else if (objectValue->isDictionary()) {
            // 使用ScriptValue的setKey方法
            if (!indexValue->isString()) {
                reportError("Dictionary key must be a string", ctx);
                return any();
            }
            string key = indexValue->getString();
            objectValue->setKey(key, rightValue);
            return any(rightValue);
        } else {
            reportError("Subscript assignment not supported for this type", ctx);
            return any();
        }
    }
    
    return any();
}

any ScriptInterpreter::visitAssignmentOperator(PyScriptParser::AssignmentOperatorContext *ctx) {
    // 赋值操作符已经在visitAssignment中处理
    return any();
}

any ScriptInterpreter::visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) {
    auto value = evaluateExpression(ctx->expression());
    // 表达式语句的值可以忽略
    return any(value);
}

any ScriptInterpreter::visitExpression(PyScriptParser::ExpressionContext *ctx) {
    // expression: assignment | ternaryExpression
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    } else if (ctx->ternaryExpression()) {
        return visit(ctx->ternaryExpression());
    }
    
    reportError("Invalid expression", ctx);
    return any();
}

any ScriptInterpreter::visitTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) {
    // 检查是否有三元操作符
    if (ctx->children.size() == 1) {
        // 没有三元操作符，直接返回逻辑或表达式
        // 注意：logicalOrExpression() 返回的是 vector，我们需要第一个元素
        auto logicalOrExprs = ctx->logicalOrExpression();
        if (!logicalOrExprs.empty()) {
            return visit(logicalOrExprs[0]);
        } else {
            reportError("Missing logical or expression in ternary expression", ctx);
            return any();
        }
    }
    
    // 检查是Python风格 (if-else) 还是C风格 (?:)
    bool pythonStyle = false;
    for (size_t i = 0; i < ctx->children.size(); ++i) {
        if (ctx->children[i]->getText() == "if") {
            pythonStyle = true;
            break;
        }
    }
    
    if (pythonStyle) {
        // Python风格: logicalOrExpression 'if' logicalOrExpression 'else' ternaryExpression
        // 我们需要找到各个部分
        std::vector<PyScriptParser::LogicalOrExpressionContext*> logicalOrExprs;
        PyScriptParser::TernaryExpressionContext* falseExpr = nullptr;
        
        for (auto child : ctx->children) {
            auto logicalOr = dynamic_cast<PyScriptParser::LogicalOrExpressionContext*>(child);
            if (logicalOr) {
                logicalOrExprs.push_back(logicalOr);
            }
            auto ternary = dynamic_cast<PyScriptParser::TernaryExpressionContext*>(child);
            if (ternary && child != ctx) {
                falseExpr = ternary;
            }
        }
        
        if (logicalOrExprs.size() >= 2 && falseExpr) {
            // 第一个logicalOrExpression是true表达式
            // 第二个logicalOrExpression是条件
            auto trueExprCtx = logicalOrExprs[0];
            auto condExprCtx = logicalOrExprs[1];
            
            // 使用visit获取条件值
            auto condAny = visit(condExprCtx);
            shared_ptr<ScriptValue> condValue;
            try {
                condValue = any_cast<shared_ptr<ScriptValue>>(condAny);
            } catch (const bad_any_cast&) {
                reportError("Cannot evaluate condition in Python-style ternary expression", ctx);
                return any();
            }
            
            if (!condValue) {
                reportError("Cannot evaluate condition in Python-style ternary expression", ctx);
                return any();
            }
            
            if (isTruthy(condValue)) {
                return visit(trueExprCtx);
            } else {
                return visit(falseExpr);
            }
        } else {
            reportError("Invalid Python-style ternary expression", ctx);
            return any();
        }
    } else {
        // C风格：condition ? trueExpr : falseExpr
        // 语法是 logicalOrExpression '?' expression ':' ternaryExpression
        auto logicalOrExprs = ctx->logicalOrExpression();
        if (logicalOrExprs.empty()) {
            reportError("Missing condition in C-style ternary expression", ctx);
            return any();
        }
        auto condExprCtx = logicalOrExprs[0];
        PyScriptParser::ExpressionContext* trueExprCtx = nullptr;
        PyScriptParser::TernaryExpressionContext* falseExprCtx = nullptr;
        
        // 找到expression和ternaryExpression
        for (auto child : ctx->children) {
            if (!trueExprCtx) {
                auto expr = dynamic_cast<PyScriptParser::ExpressionContext*>(child);
                if (expr) {
                    trueExprCtx = expr;
                    continue;
                }
            }
            if (!falseExprCtx) {
                auto ternary = dynamic_cast<PyScriptParser::TernaryExpressionContext*>(child);
                if (ternary && child != ctx) {
                    falseExprCtx = ternary;
                }
            }
        }
        
        if (condExprCtx && trueExprCtx && falseExprCtx) {
            // 使用visit获取条件值
            auto condAny = visit(condExprCtx);
            shared_ptr<ScriptValue> condValue;
            try {
                condValue = any_cast<shared_ptr<ScriptValue>>(condAny);
            } catch (const bad_any_cast&) {
                reportError("Cannot evaluate condition in ternary expression", ctx);
                return any();
            }
            
            if (!condValue) {
                reportError("Cannot evaluate condition in ternary expression", ctx);
                return any();
            }
            
            if (isTruthy(condValue)) {
                return evaluateExpression(trueExprCtx);
            } else {
                return visit(falseExprCtx);
            }
        } else {
            reportError("Invalid C-style ternary expression", ctx);
            return any();
        }
    }
}

any ScriptInterpreter::visitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *ctx) {
    auto logicalAndExprs = ctx->logicalAndExpression();
    if (logicalAndExprs.size() == 1) {
        return visit(logicalAndExprs[0]);
    }
    
    // 处理多个逻辑或表达式
    shared_ptr<ScriptValue> result;
    for (auto expr : logicalAndExprs) {
        auto valAny = visit(expr);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate logical OR expression", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate logical OR expression", ctx);
            return any();
        }
        
        if (isTruthy(val)) {
            result = val;
            break;
        }
        
        if (!result) {
            result = val;
        }
    }
    
    return any(result);
}

any ScriptInterpreter::visitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *ctx) {
    auto equalityExprs = ctx->equalityExpression();
    if (equalityExprs.size() == 1) {
        return visit(equalityExprs[0]);
    }
    
    // 处理多个逻辑与表达式
    shared_ptr<ScriptValue> result;
    for (auto expr : equalityExprs) {
        auto valAny = visit(expr);
        shared_ptr<ScriptValue> val;
        try {
            val = any_cast<shared_ptr<ScriptValue>>(valAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate logical AND expression", ctx);
            return any();
        }
        if (!val) {
            reportError("Cannot evaluate logical AND expression", ctx);
            return any();
        }
        
        if (!isTruthy(val)) {
            result = val;
            break;
        }
        
        if (!result) {
            result = val;
        }
    }
    
    return any(result);
}

any ScriptInterpreter::visitEqualityExpression(PyScriptParser::EqualityExpressionContext *ctx) {
    auto relationalExprs = ctx->relationalExpression();
    if (relationalExprs.size() == 1) {
        return visit(relationalExprs[0]);
    }
    
    // 处理相等性比较
    auto leftAny = visit(relationalExprs[0]);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of equality expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of equality expression", ctx);
        return any();
    }
    
    for (size_t i = 1; i < relationalExprs.size(); ++i) {
        auto rightAny = visit(relationalExprs[i]);
        shared_ptr<ScriptValue> right;
        try {
            right = any_cast<shared_ptr<ScriptValue>>(rightAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right side of equality expression", ctx);
            return any();
        }
        if (!right) {
            reportError("Cannot evaluate right side of equality expression", ctx);
            return any();
        }
        
        // 获取操作符
        string op = ctx->children[2*i - 1]->getText();
        auto result = evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported equality operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any ScriptInterpreter::visitRelationalExpression(PyScriptParser::RelationalExpressionContext *ctx) {
    auto additiveExprs = ctx->additiveExpression();
    if (additiveExprs.size() == 1) {
        return visit(additiveExprs[0]);
    }
    
    // 处理关系比较
    auto leftAny = visit(additiveExprs[0]);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of relational expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of relational expression", ctx);
        return any();
    }
    
    for (size_t i = 1; i < additiveExprs.size(); ++i) {
        auto rightAny = visit(additiveExprs[i]);
        shared_ptr<ScriptValue> right;
        try {
            right = any_cast<shared_ptr<ScriptValue>>(rightAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right side of relational expression", ctx);
            return any();
        }
        if (!right) {
            reportError("Cannot evaluate right side of relational expression", ctx);
            return any();
        }
        
        // 获取操作符
        string op = ctx->children[2*i - 1]->getText();
        auto result = evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported relational operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any ScriptInterpreter::visitAdditiveExpression(PyScriptParser::AdditiveExpressionContext *ctx) {
    auto multiplicativeExprs = ctx->multiplicativeExpression();
    if (multiplicativeExprs.size() == 1) {
        return visit(multiplicativeExprs[0]);
    }
    
    // 处理加减运算
    auto leftAny = visit(multiplicativeExprs[0]);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of additive expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of additive expression", ctx);
        return any();
    }
    
    for (size_t i = 1; i < multiplicativeExprs.size(); ++i) {
        auto rightAny = visit(multiplicativeExprs[i]);
        shared_ptr<ScriptValue> right;
        try {
            right = any_cast<shared_ptr<ScriptValue>>(rightAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right side of additive expression", ctx);
            return any();
        }
        if (!right) {
            reportError("Cannot evaluate right side of additive expression", ctx);
            return any();
        }
        
        // 获取操作符
        string op = ctx->children[2*i - 1]->getText();
        auto result = evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported additive operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any ScriptInterpreter::visitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *ctx) {
    auto unaryExprs = ctx->unaryExpression();
    if (unaryExprs.size() == 1) {
        return visit(unaryExprs[0]);
    }
    
    // 处理乘除取模运算
    auto leftAny = visit(unaryExprs[0]);
    shared_ptr<ScriptValue> left;
    try {
        left = any_cast<shared_ptr<ScriptValue>>(leftAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate left side of multiplicative expression", ctx);
        return any();
    }
    if (!left) {
        reportError("Cannot evaluate left side of multiplicative expression", ctx);
        return any();
    }
    
    for (size_t i = 1; i < unaryExprs.size(); ++i) {
        auto rightAny = visit(unaryExprs[i]);
        shared_ptr<ScriptValue> right;
        try {
            right = any_cast<shared_ptr<ScriptValue>>(rightAny);
        } catch (const bad_any_cast&) {
            reportError("Cannot evaluate right side of multiplicative expression", ctx);
            return any();
        }
        if (!right) {
            reportError("Cannot evaluate right side of multiplicative expression", ctx);
            return any();
        }
        
        // 获取操作符
        string op = ctx->children[2*i - 1]->getText();
        auto result = evaluateBinaryOperation(op, left, right);
        if (!result) {
            reportError("Unsupported multiplicative operator: " + op, ctx);
            return any();
        }
        
        left = result;
    }
    
    return any(left);
}

any ScriptInterpreter::visitUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) {
    auto callOrPrimaryCtx = ctx->callOrPrimary();
    auto callOrPrimaryAny = visit(callOrPrimaryCtx);
    shared_ptr<ScriptValue> callOrPrimaryValue;
    try {
        callOrPrimaryValue = any_cast<shared_ptr<ScriptValue>>(callOrPrimaryAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate expression in unary expression", ctx);
        return any();
    }
    
    if (!callOrPrimaryValue) {
        reportError("Cannot evaluate expression in unary expression", ctx);
        return any();
    }
    
    // 检查是否有前缀操作符
    if (ctx->children.size() > 1) {
        string op = ctx->children[0]->getText();
        auto result = evaluateUnaryOperation(op, callOrPrimaryValue);
        if (!result) {
            reportError("Unsupported unary operator: " + op, ctx);
            return any();
        }
        return any(result);
    }
    
    return any(callOrPrimaryValue);
}

any ScriptInterpreter::visitCallOrPrimary(PyScriptParser::CallOrPrimaryContext *ctx) {
    // 新的语法：callOrPrimary: primaryExpression (postfixOp)*
    auto primary = ctx->primaryExpression();
    if (!primary) {
        reportError("Missing primary expression in callOrPrimary", ctx);
        return any();
    }
    
    // 获取primaryExpression的值
    auto primaryAny = visit(primary);
    shared_ptr<ScriptValue> currentValue;
    try {
        currentValue = any_cast<shared_ptr<ScriptValue>>(primaryAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate primary expression", ctx);
        return any();
    }
    
    if (!currentValue) {
        reportError("Cannot evaluate primary expression", ctx);
        return any();
    }
    
    // 应用所有的postfix操作符
    auto postfixOps = ctx->postfixOp();
    for (auto postfixOp : postfixOps) {
        // 检查postfixOp的类型
        auto* attrOp = dynamic_cast<PyScriptParser::AttributeAccessOpContext*>(postfixOp);
        auto* subscriptOp = dynamic_cast<PyScriptParser::SubscriptAccessOpContext*>(postfixOp);
        auto* funcCallOp = dynamic_cast<PyScriptParser::FunctionCallOpContext*>(postfixOp);
        
        if (attrOp) {
            // 属性访问: '.' IDENTIFIER
            auto identifier = attrOp->IDENTIFIER();
            if (!identifier) {
                reportError("Missing identifier in attribute access", postfixOp);
                return any();
            }
            string memberName = identifier->getText();
            auto member = getMember(currentValue, memberName);
            if (!member) {
                reportError("Object has no member: " + memberName, postfixOp);
                return any();
            }
            currentValue = member;
        } else if (subscriptOp) {
            // 下标访问: '[' expression ']'
            auto indexExpr = subscriptOp->expression();
            if (!indexExpr) {
                reportError("Missing index expression in subscript access", postfixOp);
                return any();
            }
            auto indexValue = evaluateExpression(indexExpr);
            if (!indexValue) {
                reportError("Cannot evaluate subscript index", postfixOp);
                return any();
            }
            
            if (currentValue->isPythonObject()) {
                py::object pyObj = currentValue->getPythonObject();
                // 检查是否是函数对象，函数对象不可下标
                if (py::isinstance<py::function>(pyObj)) {
                    reportError("Cannot use function object as subscriptable", postfixOp);
                    return any();
                }
                try {
                    py::object pyIndex = indexValue->toPythonObject();
                    py::object result = pyObj[pyIndex];
                    currentValue = ScriptValue::fromPythonObject(result);
                } catch (const py::error_already_set& e) {
                    reportError("Python subscript error: " + string(e.what()), postfixOp);
                    return any();
                }
            } else if (currentValue->isList()) {
                auto& list = currentValue->getList();
                // 索引必须是整数
                if (!indexValue->isInteger()) {
                    reportError("List index must be an integer", postfixOp);
                    return any();
                }
                long long index = indexValue->getInteger();
                if (index < 0 || index >= static_cast<long long>(list.size())) {
                    reportError("List index out of bounds: " + to_string(index) + 
                               " (list size: " + to_string(list.size()) + ")", postfixOp);
                    return any();
                }
                currentValue = list[index];
            } else if (currentValue->isDictionary()) {
                auto& dict = currentValue->getDictionary();
                // 索引必须是字符串
                if (!indexValue->isString()) {
                    reportError("Dictionary key must be a string", postfixOp);
                    return any();
                }
                string key = indexValue->getString();
                auto it = dict.find(key);
                if (it == dict.end()) {
                    reportError("Dictionary key not found: " + key, postfixOp);
                    return any();
                }
                currentValue = it->second;
            } else {
                reportError("Subscript not supported for this type", postfixOp);
                return any();
            }
        } else if (funcCallOp) {
            // 函数调用: '(' argumentList? ')'
            vector<shared_ptr<ScriptValue>> args;
            auto argList = funcCallOp->argumentList();
            if (argList) {
                auto expressions = argList->expression();
                for (auto expr : expressions) {
                    auto argValue = evaluateExpression(expr);
                    if (!argValue) {
                        reportError("Cannot evaluate argument", postfixOp);
                        return any();
                    }
                    args.push_back(argValue);
                }
            }
            
            if (!currentValue->isPythonObject()) {
                reportError("Cannot call non-function type", postfixOp);
                return any();
            }
            
            try {
                py::object pyFunc = currentValue->getPythonObject();
                py::tuple pyArgs(args.size());
                for (size_t i = 0; i < args.size(); ++i) {
                    pyArgs[i] = args[i]->toPythonObject();
                }
                py::object result = pyFunc(*pyArgs);
                currentValue = ScriptValue::fromPythonObject(result);
            } catch (const py::error_already_set& e) {
                reportError("Python function call error: " + string(e.what()), postfixOp);
                return any();
            } catch (const exception& e) {
                reportError("Function call error: " + string(e.what()), postfixOp);
                return any();
            }
        } else {
            reportError("Unknown postfix operator type", postfixOp);
            return any();
        }
    }
    
    return any(currentValue);
}

any ScriptInterpreter::visitFunctionCall(PyScriptParser::FunctionCallContext *ctx) {
    std::cerr << "visitFunctionCall called" << std::endl;
    
    // 新的语法允许更复杂的函数调用表达式
    // 获取被调用对象：可以是dottedName、attributeAccess、subscriptAccess或括号表达式
    antlr4::tree::ParseTree* callee = nullptr;
    if (ctx->dottedName()) {
        callee = ctx->dottedName();
    } else if (ctx->attributeAccess()) {
        callee = ctx->attributeAccess();
    } else if (ctx->subscriptAccess()) {
        callee = ctx->subscriptAccess();
    } else if (ctx->expression()) {
        // 括号表达式
        callee = ctx->expression();
    }
    
    if (!callee) {
        reportError("Function call missing callee", ctx);
        return any();
    }
    
    // 计算被调用对象的值
    auto calleeAny = visit(callee);
    shared_ptr<ScriptValue> calleeValue;
    try {
        calleeValue = any_cast<shared_ptr<ScriptValue>>(calleeAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate function callee", ctx);
        return any();
    }
    
    if (!calleeValue) {
        reportError("Cannot evaluate function callee", ctx);
        return any();
    }
    
    if (!calleeValue->isPythonObject()) {
        reportError("Cannot call non-function type", ctx);
        return any();
    }
    
    // 收集参数
    vector<shared_ptr<ScriptValue>> args;
    if (ctx->argumentList()) {
        auto argList = ctx->argumentList()->expression();
        std::cerr << "Argument count: " << argList.size() << std::endl;
        for (size_t i = 0; i < argList.size(); ++i) {
            auto arg = argList[i];
            auto argValue = evaluateExpression(arg);
            if (argValue) {
                args.push_back(argValue);
                std::cerr << "Arg[" << i << "] type=" << static_cast<int>(argValue->getType())
                          << ", value=" << argValue->toString() << std::endl;
            } else {
                reportError("Cannot evaluate argument", ctx);
                return any();
            }
        }
    }
    
    try {
        py::object pyFunc = calleeValue->getPythonObject();
        std::cerr << "Python function type: " << py::str(py::type::of(pyFunc)).cast<std::string>() << std::endl;
        
        // 直接调用Python函数
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
            std::cerr << "Python arg[" << i << "]=" << py::str(pyArgs[i]).cast<std::string>() << std::endl;
        }
        
        py::object result = pyFunc(*pyArgs);
        std::cerr << "Result type=" << py::str(py::type::of(result)).cast<std::string>() 
                  << ", result=" << py::str(result).cast<std::string>() << std::endl;
        return any(ScriptValue::fromPythonObject(result));
    } catch (const py::error_already_set& e) {
        std::cerr << "Python error=" << e.what() << std::endl;
        reportError("Python function call error: " + string(e.what()), ctx);
        return any();
    } catch (const exception& e) {
        std::cerr << "Exception=" << e.what() << std::endl;
        reportError("Function call error: " + string(e.what()), ctx);
        return any();
    }
}

any ScriptInterpreter::visitAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) {
    std::cerr << "visitAttributeAccess called" << std::endl;
    
    auto primaryCtx = ctx->primaryExpression();
    if (!primaryCtx) {
        reportError("Attribute access missing object", ctx);
        return any();
    }
    
    auto objectAny = visit(primaryCtx);
    shared_ptr<ScriptValue> objectValue;
    try {
        objectValue = any_cast<shared_ptr<ScriptValue>>(objectAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate object in attribute access", ctx);
        return any();
    }
    
    if (!objectValue) {
        reportError("Cannot evaluate object in attribute access", ctx);
        return any();
    }
    
    string memberName = ctx->IDENTIFIER()->getText();
    std::cerr << "Member name: " << memberName << std::endl;
    
    auto member = getMember(objectValue, memberName);
    if (!member) {
        reportError("Object has no member: " + memberName, ctx);
        return any();
    }
    
    std::cerr << "Member type=" << static_cast<int>(member->getType())
              << ", value=" << member->toString() << std::endl;
    
    return any(member);
}

any ScriptInterpreter::visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) {
    std::cerr << "visitSubscriptAccess called" << std::endl;
    
    auto primaryCtx = ctx->primaryExpression();
    if (!primaryCtx) {
        reportError("Subscript access missing object", ctx);
        return any();
    }
    
    auto objectAny = visit(primaryCtx);
    shared_ptr<ScriptValue> objectValue;
    try {
        objectValue = any_cast<shared_ptr<ScriptValue>>(objectAny);
    } catch (const bad_any_cast&) {
        reportError("Cannot evaluate object in subscript access", ctx);
        return any();
    }
    
    if (!objectValue) {
        reportError("Cannot evaluate object in subscript access", ctx);
        return any();
    }
    
    auto indexValue = evaluateExpression(ctx->expression());
    if (!indexValue) {
        reportError("Cannot evaluate subscript index", ctx);
        return any();
    }
    
    if (objectValue->isPythonObject()) {
        py::object pyObj = objectValue->getPythonObject();
        
        // 检查是否是函数对象，函数对象不可下标
        if (py::isinstance<py::function>(pyObj)) {
            reportError("Cannot use function object as subscriptable", ctx);
            return any();
        }
        
        try {
            py::object pyIndex = indexValue->toPythonObject();
            py::object result = pyObj[pyIndex];
            return any(ScriptValue::fromPythonObject(result));
        } catch (const py::error_already_set& e) {
            reportError("Python subscript error: " + string(e.what()), ctx);
            return any();
        }
    } else if (objectValue->isList()) {
        auto& list = objectValue->getList();
        
        // 索引必须是整数
        if (!indexValue->isInteger()) {
            reportError("List index must be an integer", ctx);
            return any();
        }
        
        long long index = indexValue->getInteger();
        
        if (index < 0 || index >= static_cast<long long>(list.size())) {
            reportError("List index out of bounds: " + to_string(index) + 
                       " (list size: " + to_string(list.size()) + ")", ctx);
            return any();
        }
        
        return any(list[index]);
    } else if (objectValue->isDictionary()) {
        auto& dict = objectValue->getDictionary();
        
        // 索引必须是字符串
        if (!indexValue->isString()) {
            reportError("Dictionary key must be a string", ctx);
            return any();
        }
        
        string key = indexValue->getString();
        
        auto it = dict.find(key);
        if (it == dict.end()) {
            reportError("Dictionary key not found: " + key, ctx);
            return any();
        }
        
        return any(it->second);
    } else {
        reportError("Subscript not supported for this type", ctx);
        return any();
    }
}

any ScriptInterpreter::visitPrimaryExpression(PyScriptParser::PrimaryExpressionContext *ctx) {
    if (ctx->literal()) {
        return visit(ctx->literal());
    } else if (ctx->dottedName()) {
        return visit(ctx->dottedName());
    } else if (ctx->expression()) {
        return any(evaluateExpression(ctx->expression()));
    } else if (ctx->listLiteral()) {
        return visit(ctx->listLiteral());
    } else if (ctx->dictLiteral()) {
        return visit(ctx->dictLiteral());
    } else if (ctx->newExpression()) {
        return visit(ctx->newExpression());
    } else if (ctx->lambdaExpression()) {
        return visit(ctx->lambdaExpression());
    } else if (ctx->listComprehension()) {
        return visit(ctx->listComprehension());
    }
    
    reportError("Invalid primary expression", ctx);
    return any();
}

any ScriptInterpreter::visitNewExpression(PyScriptParser::NewExpressionContext *ctx) {
    std::cerr << "visitNewExpression called" << std::endl;
    
    auto dottedNameCtx = ctx->dottedName();
    if (!dottedNameCtx) {
        reportError("New expression must specify a class name", ctx);
        return any();
    }
    
    // 收集参数
    vector<shared_ptr<ScriptValue>> args;
    if (ctx->argumentList()) {
        auto argList = ctx->argumentList()->expression();
        std::cerr << "Argument count: " << argList.size() << std::endl;
        for (size_t i = 0; i < argList.size(); ++i) {
            auto argCtx = argList[i];
            auto argValue = evaluateExpression(argCtx);
            if (argValue) {
                args.push_back(argValue);
            } else {
                args.push_back(ScriptValue::createNull());
            }
        }
    }
    
    string className = dottedNameCtx->getText();
    std::cerr << "Class name: " << className << std::endl;
    
    // 将点分名称拆分为部分
    vector<string> parts;
    size_t start = 0;
    size_t dotPos;
    while ((dotPos = className.find('.', start)) != string::npos) {
        parts.push_back(className.substr(start, dotPos - start));
        start = dotPos + 1;
    }
    parts.push_back(className.substr(start));
    
    if (parts.empty()) {
        reportError("Empty class name", ctx);
        return any();
    }
    
    // 获取基础对象（第一个部分）
    string firstPart = parts[0];
    shared_ptr<ScriptValue> currentValue = getVariable(firstPart);
    if (!currentValue) {
        // 检查是否是导入的模块
        auto modIt = imported_modules_.find(firstPart);
        if (modIt != imported_modules_.end()) {
            currentValue = ScriptValue::createPythonObject(modIt->second);
        } else {
            // 不是变量也不是已导入的模块，尝试作为模块导入
            try {
                py::module_ module = py::module_::import(firstPart.c_str());
                imported_modules_[firstPart] = module;
                currentValue = ScriptValue::createPythonObject(module);
            } catch (const py::error_already_set& e) {
                reportError("Failed to import module " + firstPart + 
                           ": " + string(e.what()), ctx);
                return any();
            }
        }
    }
    
    // 逐级获取属性（除了最后一部分）
    for (size_t i = 1; i < parts.size() - 1; ++i) {
        currentValue = getMember(currentValue, parts[i]);
        if (!currentValue) {
            reportError("Cannot get member '" + parts[i] + "' in " + className, ctx);
            return any();
        }
    }
    
    // 获取类对象（最后一部分）
    string lastPart = parts.back();
    shared_ptr<ScriptValue> classValue;
    if (parts.size() == 1) {
        // 只有一部分，当前值就是类对象
        classValue = currentValue;
    } else {
        classValue = getMember(currentValue, lastPart);
        if (!classValue) {
            reportError("Cannot get class '" + lastPart + "' in " + className, ctx);
            return any();
        }
    }
    
    if (!classValue->isPythonObject()) {
        reportError("Cannot instantiate non-class type", ctx);
        return any();
    }
    
    try {
        py::object pyClass = classValue->getPythonObject();
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = args[i]->toPythonObject();
        }
        
        py::object instance = pyClass(*pyArgs);
        return any(ScriptValue::fromPythonObject(instance));
        
    } catch (const py::error_already_set& e) {
        reportError("Failed to create instance " + className + 
                   ": " + string(e.what()), ctx);
        return any();
    } catch (const exception& e) {
        reportError("Instance creation error: " + string(e.what()), ctx);
        return any();
    }
}

any ScriptInterpreter::visitLiteral(PyScriptParser::LiteralContext *ctx) {
    if (ctx->INTEGER()) {
        long long value = stoll(ctx->INTEGER()->getText());
        return any(ScriptValue::createInteger(value));
    } else if (ctx->FLOAT()) {
        double value = stod(ctx->FLOAT()->getText());
        return any(ScriptValue::createDouble(value));
    } else if (ctx->STRING()) {
        string text = ctx->STRING()->getText();
        // 去掉引号
        if (text.length() >= 2) {
            text = text.substr(1, text.length() - 2);
        }
        return any(ScriptValue::createString(text));
    } else if (ctx->BOOL()) {
        bool value = (ctx->BOOL()->getText() == "true");
        return any(ScriptValue::createBoolean(value));
    } else if (ctx->NULL_LIT()) {
        return any(ScriptValue::createNull());
    }
    
    reportError("Invalid literal", ctx);
    return any();
}

any ScriptInterpreter::visitListLiteral(PyScriptParser::ListLiteralContext *ctx) {
    auto listVal = ScriptValue::createList();
    
    if (ctx->expressionList()) {
        auto exprList = ctx->expressionList()->expression();
        for (auto expr : exprList) {
            auto value = evaluateExpression(expr);
            if (value) {
                listVal->append(value);
            } else {
                reportError("Cannot evaluate list element", ctx);
                return any();
            }
        }
    }
    
    return any(listVal);
}

any ScriptInterpreter::visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) {
    auto dictVal = ScriptValue::createDictionary();
    
    if (ctx->dictItemList()) {
        auto items = ctx->dictItemList()->dictItem();
        for (auto item : items) {
            // 使用 dynamic_cast 来检查具体的类型
            auto* kv = dynamic_cast<PyScriptParser::KeyValuePairContext*>(item);
            auto* unpack = dynamic_cast<PyScriptParser::DictUnpackContext*>(item);
            
            if (kv) {
                auto keyValue = evaluateExpression(kv->expression(0));
                auto valValue = evaluateExpression(kv->expression(1));
                
                if (!keyValue || !valValue) {
                    reportError("Cannot evaluate dictionary key-value pair", ctx);
                    return any();
                }
                
                string keyStr = keyValue->toString();
                dictVal->setKey(keyStr, valValue);
            } else if (unpack) {
                // 字典展开：**expression
                auto unpackExpr = unpack->expression();
                auto unpackValue = evaluateExpression(unpackExpr);
                
                if (!unpackValue) {
                    reportError("Cannot evaluate dictionary unpack expression", ctx);
                    return any();
                }
                
                // 如果展开的值是字典，合并到当前字典
                if (unpackValue->isPythonObject()) {
                    try {
                        py::object pyObj = unpackValue->getPythonObject();
                        // 检查是否是字典
                        py::module_ builtins = py::module_::import("builtins");
                        py::object dictType = builtins.attr("dict");
                        
                        if (py::isinstance(pyObj, dictType)) {
                            // 合并字典
                            py::dict pyDict = pyObj.cast<py::dict>();
                            for (auto item : pyDict) {
                                py::object key = py::reinterpret_borrow<py::object>(item.first);
                                py::object value = py::reinterpret_borrow<py::object>(item.second);
                                string keyStr = key.cast<string>();
                                auto val = ScriptValue::fromPythonObject(value);
                                dictVal->setKey(keyStr, val);
                            }
                        } else {
                            reportError("Cannot unpack non-dictionary object", ctx);
                            return any();
                        }
                    } catch (const py::error_already_set& e) {
                        reportError("Dictionary unpack error: " + string(e.what()), ctx);
                        return any();
                    }
                } else if (unpackValue->isDictionary()) {
                    // 如果是ScriptValue字典，直接合并
                    auto& unpackDict = unpackValue->getDictionary();
                    for (auto& kv : unpackDict) {
                        dictVal->setKey(kv.first, kv.second);
                    }
                } else {
                    reportError("Cannot unpack non-dictionary object", ctx);
                    return any();
                }
            } else {
                reportError("Unknown dictionary item type", ctx);
                return any();
            }
        }
    }
    
    return any(dictVal);
}

any ScriptInterpreter::visitDottedName(PyScriptParser::DottedNameContext *ctx) {
    // 点分隔的名称可能表示一个模块、模块的属性，或者一个变量
    string name = ctx->getText();
    std::cerr << "visitDottedName: " << name << std::endl;
    
    // 如果正在定义函数，则返回一个占位符，不报错
    if (defining_function_) {
        std::cerr << "Defining function, returning placeholder for: " << name << std::endl;
        // 返回一个null值作为占位符
        return any(ScriptValue::createNull());
    }
    
    // 首先检查变量
    auto varIt = variables_.find(name);
    if (varIt != variables_.end()) {
        std::cerr << "Found in variables" << std::endl;
        return any(varIt->second);
    }
    
    // 检查导入的模块
    auto modIt = imported_modules_.find(name);
    if (modIt != imported_modules_.end()) {
        std::cerr << "Found in imported_modules" << std::endl;
        return any(ScriptValue::createPythonObject(modIt->second));
    }
    
    // 检查是否为内置Python对象
    if (name == "True" || name == "true") {
        return any(ScriptValue::createBoolean(true));
    } else if (name == "False" || name == "false") {
        return any(ScriptValue::createBoolean(false));
    } else if (name == "None" || name == "none" || name == "null") {
        return any(ScriptValue::createNull());
    }
    
    // 检查是否为Python内置函数
    if (!builtins_.is_none()) {
        try {
            if (py::hasattr(builtins_, name.c_str())) {
                py::object builtin_func = builtins_.attr(name.c_str());
                return any(ScriptValue::fromPythonObject(builtin_func));
            }
        } catch (const py::error_already_set&) {
            // 忽略错误，继续向下
        }
    }
    
    // 尝试解析点分隔的名称：可能是模块的属性
    // 例如 os.path -> 先获取os模块，然后获取path属性
    vector<string> parts;
    size_t start = 0;
    size_t dotPos;
    while ((dotPos = name.find('.', start)) != string::npos) {
        parts.push_back(name.substr(start, dotPos - start));
        start = dotPos + 1;
    }
    parts.push_back(name.substr(start));
    
    if (parts.size() > 1) {
        // 尝试获取第一个部分作为模块
        string firstPart = parts[0];
        auto firstVarIt = variables_.find(firstPart);
        if (firstVarIt != variables_.end() && firstVarIt->second->isPythonObject()) {
            py::object current = firstVarIt->second->getPythonObject();
            try {
                for (size_t i = 1; i < parts.size(); ++i) {
                    current = current.attr(parts[i].c_str());
                }
                return any(ScriptValue::fromPythonObject(current));
            } catch (const py::error_already_set&) {
                // 属性不存在，继续向下
            }
        }
    }
    
    reportError("Undefined identifier: " + name, ctx);
    return any();
}

any ScriptInterpreter::visitArgumentList(PyScriptParser::ArgumentListContext *ctx) {
    // 参数列表已经在函数调用中处理
    return any();
}

any ScriptInterpreter::visitExpressionList(PyScriptParser::ExpressionListContext *ctx) {
    // 表达式列表已经在列表字面量中处理
    return any();
}

any ScriptInterpreter::visitDictItemList(PyScriptParser::DictItemListContext *ctx) {
    // 字典项列表已经在字典字面量中处理
    return any();
}

any ScriptInterpreter::visitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) {
    // 键值对已经在字典字面量中处理
    return any();
}

any ScriptInterpreter::visitDictUnpack(PyScriptParser::DictUnpackContext *ctx) {
    // 字典展开已经在字典字面量中处理
    return any();
}

any ScriptInterpreter::visitForStatement(PyScriptParser::ForStatementContext *ctx) {
    std::cerr << "visitForStatement called" << std::endl;
    
    auto forControlCtx = ctx->forControl();
    if (!forControlCtx) {
        reportError("For statement missing control", ctx);
        return any();
    }
    
    // 执行初始化部分（如果有）
    if (forControlCtx->forInit()) {
        visit(forControlCtx->forInit());
        if (has_error_) {
            return any();
        }
    }
    
    // 循环条件
    auto condExpr = forControlCtx->expression();
    if (!condExpr) {
        // 如果没有条件表达式，默认为true（无限循环）
        // 在实际中应该避免无限循环，但这里简单处理
    }
    
    while (true) {
        if (condExpr) {
            auto condValue = evaluateExpression(condExpr);
            if (!condValue) {
                reportError("Cannot evaluate for loop condition", ctx);
                break;
            }
            if (!isTruthy(condValue)) {
                break;
            }
        }
        
        // 执行循环体
        visit(ctx->block());
        if (has_error_) {
            break;
        }
        
        // 执行更新部分（如果有）
        if (forControlCtx->forUpdate()) {
            visit(forControlCtx->forUpdate());
            if (has_error_) {
                break;
            }
        }
    }
    
    return any();
}

any ScriptInterpreter::visitForControl(PyScriptParser::ForControlContext *ctx) {
    // for控制已经在visitForStatement中处理
    return any();
}

any ScriptInterpreter::visitForInit(PyScriptParser::ForInitContext *ctx) {
    // 执行初始化赋值
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    }
    return any();
}

any ScriptInterpreter::visitForUpdate(PyScriptParser::ForUpdateContext *ctx) {
    // 执行更新赋值
    if (ctx->assignment()) {
        return visit(ctx->assignment());
    }
    return any();
}

any ScriptInterpreter::visitListComprehension(PyScriptParser::ListComprehensionContext *ctx) {
    std::cerr << "visitListComprehension called" << std::endl;
    
    auto expr = ctx->expression(0);  // 表达式部分
    auto varName = ctx->IDENTIFIER();
    auto iterableExpr = ctx->expression(1);  // 可迭代对象
    
    if (!expr || !varName || !iterableExpr) {
        reportError("Invalid list comprehension syntax", ctx);
        return any();
    }
    
    // 获取可迭代对象的值
    auto iterableValue = evaluateExpression(iterableExpr);
    if (!iterableValue) {
        reportError("Cannot evaluate iterable in list comprehension", ctx);
        return any();
    }
    
    // 构建Python列表推导式字符串
    std::string compStr = "[";
    compStr += expr->getText();
    compStr += " for ";
    compStr += varName->getText();
    compStr += " in ";
    compStr += iterableExpr->getText();
    compStr += "]";
    
    std::cerr << "Python list comprehension string: " << compStr << std::endl;
    
    // 捕获当前变量环境
    py::dict locals;
    for (const auto& kv : variables_) {
        try {
            locals[py::str(kv.first)] = kv.second->toPythonObject();
        } catch (const std::exception& e) {
            std::cerr << "Warning: Failed to convert variable '" << kv.first << "' to Python object: " << e.what() << std::endl;
        }
    }
    
    // 确保globals包含必要的内置函数
    py::dict globals = py::globals();
    if (!globals.contains("__builtins__")) {
        try {
            py::module_ builtins = py::module_::import("builtins");
            globals["__builtins__"] = builtins;
        } catch (...) {
            // 忽略错误
        }
    }
    
    // 使用Python的eval创建列表
    try {
        py::object resultList = py::eval(compStr, globals, locals);
        std::cerr << "List comprehension created successfully" << std::endl;
        return any(ScriptValue::fromPythonObject(resultList));
    } catch (const py::error_already_set& e) {
        std::cerr << "Python eval error: " << e.what() << std::endl;
        reportError("Failed to create list comprehension: " + std::string(e.what()), ctx);
        return any();
    } catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << std::endl;
        reportError("Failed to create list comprehension: " + std::string(e.what()), ctx);
        return any();
    }
}

any ScriptInterpreter::visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) {
    std::cerr << "visitLambdaExpression called" << std::endl;
    
    // 获取表达式文本
    auto exprCtx = ctx->expression();
    if (!exprCtx) {
        reportError("Lambda expression must have a body", ctx);
        return any();
    }
    
    std::string exprText = exprCtx->getText();
    std::cerr << "Lambda expression body: " << exprText << std::endl;
    
    // 获取参数列表
    std::vector<std::string> paramNames;
    auto identifiers = ctx->IDENTIFIER();
    for (auto* id : identifiers) {
        paramNames.push_back(id->getText());
    }
    
    // 构建Python lambda字符串
    std::string lambdaStr = "lambda ";
    if (!paramNames.empty()) {
        for (size_t i = 0; i < paramNames.size(); ++i) {
            if (i > 0) lambdaStr += ", ";
            lambdaStr += paramNames[i];
        }
    }
    lambdaStr += ": ";
    lambdaStr += exprText;
    
    std::cerr << "Python lambda string: " << lambdaStr << std::endl;
    
    // 捕获当前变量环境
    py::dict locals;
    for (const auto& kv : variables_) {
        try {
            locals[py::str(kv.first)] = kv.second->toPythonObject();
        } catch (const std::exception& e) {
            std::cerr << "Warning: Failed to convert variable '" << kv.first << "' to Python object: " << e.what() << std::endl;
        }
    }
    
    // 确保globals包含必要的内置函数
    py::dict globals = py::globals();
    if (!globals.contains("__builtins__")) {
        try {
            py::module_ builtins = py::module_::import("builtins");
            globals["__builtins__"] = builtins;
        } catch (...) {
            // 忽略错误
        }
    }
    
    // 使用Python的eval创建lambda函数
    try {
        py::object lambdaFunc = py::eval(lambdaStr, globals, locals);
        std::cerr << "Lambda function created successfully" << std::endl;
        return any(ScriptValue::fromPythonObject(lambdaFunc));
    } catch (const py::error_already_set& e) {
        std::cerr << "Python eval error: " << e.what() << std::endl;
        reportError("Failed to create lambda function: " + std::string(e.what()), ctx);
        return any();
    } catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << std::endl;
        reportError("Failed to create lambda function: " + std::string(e.what()), ctx);
        return any();
    }
}

// 新的visitor方法实现

any ScriptInterpreter::visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) {
    std::cerr << "visitAttributeAccessOp called" << std::endl;
    
    // 获取当前对象值（来自callOrPrimary中的primaryExpression）
    // 注意：attributeAccessOp的父节点是postfixOp，postfixOp的父节点是callOrPrimary
    // 我们需要获取到当前的对象值，这应该通过上下文传递，这里简化处理
    // 实际实现中，callOrPrimary应该累积应用postfixOp
    
    // 临时实现：报告错误
    reportError("Attribute access operator not fully implemented yet", ctx);
    return any();
}

any ScriptInterpreter::visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) {
    std::cerr << "visitSubscriptAccessOp called" << std::endl;
    
    // 临时实现：报告错误
    reportError("Subscript access operator not fully implemented yet", ctx);
    return any();
}

any ScriptInterpreter::visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) {
    std::cerr << "visitFunctionCallOp called" << std::endl;
    
    // 临时实现：报告错误
    reportError("Function call operator not fully implemented yet", ctx);
    return any();
}
