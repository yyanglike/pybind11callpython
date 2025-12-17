#include "script_interpreter.h"
#include "PyScriptLexer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace antlr4;

ScriptInterpreter::ScriptInterpreter() 
    : result_(nullptr), python_initialized_(false), has_error_(false) {
    
    // 检查Python解释器是否已初始化
    if (!Py_IsInitialized()) {
        try {
            py::initialize_interpreter();
            python_initialized_ = true;
        } catch (const std::exception& e) {
            std::cerr << "Failed to initialize Python interpreter: " << e.what() << std::endl;
        }
    }
    
    // 配置Python路径并导入内置模块
    try {
        py::module_ sys = py::module_::import("sys");
        sys.attr("path").attr("insert")(0, "../python");
        
        // 导入builtins模块以供内置函数使用
        builtins_ = py::module_::import("builtins");
    } catch (const std::exception& e) {
        std::cerr << "Failed to setup Python environment: " << e.what() << std::endl;
    }
}

ScriptInterpreter::~ScriptInterpreter() {
    if (python_initialized_) {
        try {
            py::finalize_interpreter();
        } catch (...) {
            // 忽略清理错误
        }
    }
}

bool ScriptInterpreter::execute(const std::string& script) {
    has_error_ = false;
    result_ = nullptr;
    
    std::cout << "DEBUG: Executing script: " << script << std::endl;
    
    try {
        ANTLRInputStream input(script);
        PyScriptLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        
        // 填充token流
        tokens.fill();
        
        // 打印所有词法符号
        std::cout << "DEBUG: Tokens: ";
        for (auto token : tokens.getTokens()) {
            if (token->getType() == antlr4::Token::EOF) {
                std::cout << "<EOF> ";
            } else {
                std::cout << token->getText() << "[" << token->getType() << "] ";
            }
        }
        std::cout << std::endl;
        
        PyScriptParser parser(&tokens);
        
        // 设置错误处理器
        parser.removeErrorListeners();
        // 可以添加自定义错误监听器
        
        std::cout << "DEBUG: Parser created, starting parse..." << std::endl;
        
        auto tree = parser.program();
        
        std::cout << "DEBUG: Parse tree obtained" << std::endl;
        
        if (has_error_) {
            std::cout << "DEBUG: Has error flag is true" << std::endl;
            return false;
        }
        
        std::cout << "DEBUG: Starting to visit program tree..." << std::endl;
        
        // 遍历AST
        visitProgram(tree);
        
        std::cout << "DEBUG: Finished visiting program tree" << std::endl;
        std::cout << "DEBUG: Variables count: " << variables_.size() << std::endl;
        
        return !has_error_;
        
    } catch (const std::exception& e) {
        std::cerr << "Script execution error: " << e.what() << std::endl;
        return false;
    }
}

bool ScriptInterpreter::executeFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return false;
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    
    return execute(buffer.str());
}

std::shared_ptr<ScriptInterpreter::ScriptValue> ScriptInterpreter::getVariable(const std::string& name) {
    auto it = variables_.find(name);
    if (it != variables_.end()) {
        return it->second;
    }
    return nullptr;
}

void ScriptInterpreter::setVariable(const std::string& name, std::shared_ptr<ScriptInterpreter::ScriptValue> value) {
    variables_[name] = value;
}

void ScriptInterpreter::clearEnvironment() {
    variables_.clear();
    imported_modules_.clear();
    result_ = nullptr;
}

// ========== Visitor 方法实现 ==========

antlrcpp::Any ScriptInterpreter::visitProgram(PyScriptParser::ProgramContext *ctx) {
    std::cout << "DEBUG: visitProgram called, statement count: " << ctx->statement().size() << std::endl;
    
    // 执行所有语句
    for (size_t i = 0; i < ctx->statement().size(); ++i) {
        auto stmt = ctx->statement(i);
        std::cout << "DEBUG: Processing statement " << i << std::endl;
        
        // 检查具体类型 - 使用dynamic_cast检测具体的语句类型
        if (auto importStmt = dynamic_cast<PyScriptParser::ImportStmtContext*>(stmt)) {
            std::cout << "DEBUG: It's an ImportStmtContext" << std::endl;
            visitImportStatement(importStmt->importStatement());
        } else if (auto assignStmt = dynamic_cast<PyScriptParser::AssignStmtContext*>(stmt)) {
            std::cout << "DEBUG: It's an AssignStmtContext" << std::endl;
            visitAssignment(assignStmt->assignment());
        } else if (auto exprStmt = dynamic_cast<PyScriptParser::ExprStmtContext*>(stmt)) {
            std::cout << "DEBUG: It's an ExprStmtContext" << std::endl;
            visitExpressionStatement(exprStmt->expressionStatement());
        } else if (auto ifStmt = dynamic_cast<PyScriptParser::IfStmtContext*>(stmt)) {
            std::cout << "DEBUG: It's an IfStmtContext" << std::endl;
            visitIfStatement(ifStmt->ifStatement());
        } else if (auto whileStmt = dynamic_cast<PyScriptParser::WhileStmtContext*>(stmt)) {
            std::cout << "DEBUG: It's a WhileStmtContext" << std::endl;
            visitWhileStatement(whileStmt->whileStatement());
        } else if (auto returnStmt = dynamic_cast<PyScriptParser::ReturnStmtContext*>(stmt)) {
            std::cout << "DEBUG: It's a ReturnStmtContext" << std::endl;
            visitReturnStatement(returnStmt->returnStatement());
        } else {
            std::cout << "DEBUG: Unknown statement type" << std::endl;
            visitChildren(stmt);
        }
        
        if (has_error_) {
            std::cout << "DEBUG: Error detected, breaking" << std::endl;
            break;
        }
    }
    
    // 如果没有return语句，最后一条语句的值作为结果
    if (result_ == nullptr && ctx->statement().size() > 0) {
        auto lastStmt = ctx->statement().back();
        if (auto exprStmt = dynamic_cast<PyScriptParser::ExprStmtContext*>(lastStmt)) {
            result_ = evaluateExpression(exprStmt->expressionStatement()->expression());
        }
    }
    
    std::cout << "DEBUG: visitProgram finished" << std::endl;
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitImportStatement(PyScriptParser::ImportStatementContext *ctx) {
    try {
        // 获取所有IDENTIFIER令牌
        auto identifiers = ctx->IDENTIFIER();
        if (identifiers.empty()) {
            reportError("Import statement must specify a module name", ctx);
            return antlrcpp::Any();
        }
        
        // 检查是否有'as'关键字
        bool hasAs = false;
        for (auto child : ctx->children) {
            if (child->getText() == "as") {
                hasAs = true;
                break;
            }
        }
        
        std::string moduleName;
        std::string alias;
        
        if (hasAs) {
            // 有'as'，则最后一个标识符是别名，前面的所有标识符组成模块名
            for (size_t i = 0; i < identifiers.size() - 1; ++i) {
                if (!moduleName.empty()) {
                    moduleName += ".";
                }
                moduleName += identifiers[i]->getText();
            }
            alias = identifiers.back()->getText();
        } else {
            // 没有'as'，所有标识符组成模块名
            for (auto id : identifiers) {
                if (!moduleName.empty()) {
                    moduleName += ".";
                }
                moduleName += id->getText();
            }
        }
        
        // 如果模块名为空（例如，只有一个标识符且被当作别名），则使用标识符本身作为模块名
        if (moduleName.empty()) {
            moduleName = identifiers[0]->getText();
        }
        
        // 导入Python模块
        py::module_ module = py::module_::import(moduleName.c_str());
        imported_modules_[moduleName] = module;
        
        // 存储模块引用
        if (!alias.empty()) {
            variables_[alias] = std::make_shared<ScriptValue>(module);
        } else {
            // 使用模块名的最后一部分作为变量名
            size_t dotPos = moduleName.find_last_of('.');
            std::string shortName = (dotPos != std::string::npos) ? 
                                   moduleName.substr(dotPos + 1) : moduleName;
            variables_[shortName] = std::make_shared<ScriptValue>(module);
        }
        
    } catch (const py::error_already_set& e) {
        reportError("Failed to import module: " + std::string(e.what()), ctx);
    } catch (const std::exception& e) {
        reportError("Import error: " + std::string(e.what()), ctx);
    }
    
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitAssignment(PyScriptParser::AssignmentContext *ctx) {
    std::string varName = ctx->IDENTIFIER()->getText();
    auto value = evaluateExpression(ctx->expression());
    
    if (value) {
        variables_[varName] = value;
        std::cout << "DEBUG: assigned variable '" << varName << "' with value: " << valueToString(value) << std::endl;
    } else {
        std::cout << "DEBUG: evaluateExpression returned nullptr for variable '" << varName << "'" << std::endl;
        reportError("Cannot evaluate expression for assignment", ctx);
    }
    
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) {
    auto value = evaluateExpression(ctx->expression());
    // 表达式语句的值可以忽略，但我们可以存储它
    if (value) {
        // 可选：存储最后一个表达式的结果
        // result_ = value;
    }
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitIfStatement(PyScriptParser::IfStatementContext *ctx) {
    auto condValue = evaluateExpression(ctx->expression());
    
    if (!condValue) {
        reportError("Cannot evaluate condition", ctx);
        return antlrcpp::Any();
    }
    
    if (isTruthy(condValue)) {
        visit(ctx->block(0));
    } else if (ctx->block().size() > 1) {
        visit(ctx->block(1));
    }
    
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) {
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
    
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) {
    if (ctx->expression()) {
        result_ = evaluateExpression(ctx->expression());
    } else {
        result_ = nullptr;
    }
    return antlrcpp::Any();
}

// ========== 表达式访问方法 ==========

antlrcpp::Any ScriptInterpreter::visitLiteralExpr(PyScriptParser::LiteralExprContext *ctx) {
    std::cout << "DEBUG visitLiteralExpr: called" << std::endl;
    // 字面量表达式应该直接访问字面量子节点
    if (auto literal = ctx->literal()) {
        std::cout << "DEBUG visitLiteralExpr: has literal" << std::endl;
        auto result = visit(literal);
        std::cout << "DEBUG visitLiteralExpr: result.has_value() = " << result.has_value() << std::endl;
        return result;
    }
    std::cout << "DEBUG visitLiteralExpr: no literal, returning empty" << std::endl;
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitIdentifierExpr(PyScriptParser::IdentifierExprContext *ctx) {
    std::string name = ctx->IDENTIFIER()->getText();
    
    // 首先检查变量
    auto varIt = variables_.find(name);
    if (varIt != variables_.end()) {
        return antlrcpp::Any(varIt->second);
    }
    
    // 检查导入的模块
    auto modIt = imported_modules_.find(name);
    if (modIt != imported_modules_.end()) {
        return antlrcpp::Any(std::make_shared<ScriptValue>(modIt->second));
    }
    
    // 检查是否为内置Python函数（如len, str, int等）
    static const std::set<std::string> builtin_funcs = {
        "len", "str", "int", "float", "bool", "list", "dict", "tuple", "set", 
        "abs", "max", "min", "sum", "range", "enumerate", "zip", "sorted"
    };
    
    if (builtin_funcs.find(name) != builtin_funcs.end()) {
        try {
            if (builtins_.is_none()) {
                builtins_ = py::module_::import("builtins");
            }
            py::object builtin_func = builtins_.attr(name.c_str());
            return antlrcpp::Any(std::make_shared<ScriptValue>(builtin_func));
        } catch (const std::exception& e) {
            std::cerr << "Warning: Failed to get builtin function " << name << ": " << e.what() << std::endl;
        }
    }
    
    // 检查内置Python对象（如True, False, None）
    if (name == "True" || name == "true") {
        return antlrcpp::Any(std::make_shared<ScriptValue>(true));
    } else if (name == "False" || name == "false") {
        return antlrcpp::Any(std::make_shared<ScriptValue>(false));
    } else if (name == "None" || name == "none") {
        return antlrcpp::Any(std::make_shared<ScriptValue>(py::none()));
    }
    
    // 检查内置函数或模块（可以扩展）
    reportError("Undefined identifier: " + name, ctx);
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitParenExpr(PyScriptParser::ParenExprContext *ctx) {
    return antlrcpp::Any(evaluateExpression(ctx->expression()));
}

antlrcpp::Any ScriptInterpreter::visitMemberAccessExpr(PyScriptParser::MemberAccessExprContext *ctx) {
    auto objValue = evaluateExpression(ctx->expression());
    std::string memberName = ctx->IDENTIFIER()->getText();
    
    if (!objValue) {
        reportError("Cannot access member of null object", ctx);
        return antlrcpp::Any();
    }
    
    try {
        // 检查是否为Python对象
        if (objValue->holds_alternative<py::object>()) {
            py::object pyObj = objValue->get<py::object>();
            
            // 检查是否为模块
            if (py::isinstance<py::module_>(pyObj)) {
                py::module_ module = pyObj.cast<py::module_>();
                py::object member = module.attr(memberName.c_str());
                return antlrcpp::Any(std::make_shared<ScriptValue>(member));
            }
            // 检查是否为类实例
            else if (py::hasattr(pyObj, "__dict__")) {
                if (py::hasattr(pyObj, memberName.c_str())) {
                    py::object member = pyObj.attr(memberName.c_str());
                    return antlrcpp::Any(std::make_shared<ScriptValue>(member));
                } else {
                    reportError("Object has no attribute: " + memberName, ctx);
                    return antlrcpp::Any();
                }
            }
            // 其他Python对象
            else if (py::hasattr(pyObj, memberName.c_str())) {
                py::object member = pyObj.attr(memberName.c_str());
                return antlrcpp::Any(std::make_shared<ScriptValue>(member));
            } else {
                reportError("Object has no attribute: " + memberName, ctx);
                return antlrcpp::Any();
            }
        }
        // 其他类型暂不支持成员访问
        else {
            reportError("Cannot access member of non-object type", ctx);
            return antlrcpp::Any();
        }
    } catch (const py::error_already_set& e) {
        reportError("Python error accessing member: " + std::string(e.what()), ctx);
        return antlrcpp::Any();
    }
}

antlrcpp::Any ScriptInterpreter::visitFunctionCallExpr(PyScriptParser::FunctionCallExprContext *ctx) {
    auto funcValue = evaluateExpression(ctx->expression());
    
    if (!funcValue) {
        reportError("Cannot call null function", ctx);
        return antlrcpp::Any();
    }
    
    // 收集参数
    std::vector<std::shared_ptr<ScriptValue>> args;
    if (ctx->argumentList()) {
        auto argList = ctx->argumentList()->expression();
        for (auto arg : argList) {
            auto argValue = evaluateExpression(arg);
            if (argValue) {
                args.push_back(argValue);
            } else {
                reportError("Cannot evaluate argument", ctx);
                return antlrcpp::Any();
            }
        }
    }
    
    try {
        // 检查是否为Python可调用对象
        if (funcValue->holds_alternative<py::object>()) {
            py::object pyFunc = funcValue->get<py::object>();
            
            if (py::hasattr(pyFunc, "__call__")) {
                auto result = callPythonFunction(pyFunc, args);
                return antlrcpp::Any(result);
            } else {
                reportError("Object is not callable", ctx);
                return antlrcpp::Any();
            }
        }
        // 可以扩展支持内置函数
        else {
            reportError("Cannot call non-function type", ctx);
            return antlrcpp::Any();
        }
    } catch (const std::exception& e) {
        reportError("Function call error: " + std::string(e.what()), ctx);
        return antlrcpp::Any();
    }
}

antlrcpp::Any ScriptInterpreter::visitNewInstanceExpr(PyScriptParser::NewInstanceExprContext *ctx) {
    // 获取所有标识符（支持 module.ClassName 格式）
    auto identifiers = ctx->IDENTIFIER();
    
    if (identifiers.empty()) {
        reportError("New expression must specify a class name", ctx);
        return antlrcpp::Any();
    }
    
    // 收集参数
    std::vector<std::shared_ptr<ScriptValue>> args;
    if (ctx->argumentList()) {
        auto argList = ctx->argumentList()->expression();
        for (auto arg : argList) {
            auto argValue = evaluateExpression(arg);
            if (argValue) {
                args.push_back(argValue);
            } else {
                reportError("Cannot evaluate argument", ctx);
                return antlrcpp::Any();
            }
        }
    }
    
    // 处理标识符列表，构建完整的类路径
    std::vector<std::string> idNames;
    for (auto id : identifiers) {
        idNames.push_back(id->getText());
    }
    
    // 如果有多个标识符，最后一个为类名，前面的为模块路径
    if (idNames.size() == 1) {
        // 只有一个标识符的情况
        std::string fullName = idNames[0];
        
        // 先检查变量环境中是否有这个类对象
        auto varIt = variables_.find(fullName);
        if (varIt != variables_.end() && varIt->second->holds_alternative<py::object>()) {
            py::object classObj = varIt->second->get<py::object>();
            // 检查是否为Python类
            try {
                py::module_ builtins = py::module_::import("builtins");
                py::object typeClass = builtins.attr("type");
                if (py::isinstance(classObj, typeClass)) {
                    // 这是一个Python类，直接创建实例
                    try {
                        // 准备构造函数参数
                        py::tuple pyArgs(args.size());
                        for (size_t i = 0; i < args.size(); ++i) {
                            pyArgs[i] = scriptValueToPyObject(args[i])->get<py::object>();
                        }
                        
                        // 创建实例
                        py::object instance = classObj(*pyArgs);
                        return antlrcpp::Any(pyObjectToScriptValue(instance));
                    } catch (const py::error_already_set& e) {
                        reportError("Failed to create instance from variable: " + std::string(e.what()), ctx);
                        return antlrcpp::Any();
                    }
                }
            } catch (...) {
                // 不是Python类，继续下面的查找
            }
        }
        
        // 如果没有在变量中找到，尝试从已导入的模块中查找
        std::string moduleName;
        std::string className = fullName;
        for (const auto& [modName, modObj] : imported_modules_) {
            try {
                py::object testClass = modObj.attr(fullName.c_str());
                if (!testClass.is_none()) {
                    moduleName = modName;
                    break;
                }
            } catch (...) {
                // 继续查找
            }
        }
        if (moduleName.empty()) {
            reportError("Cannot find class " + fullName + " in imported modules", ctx);
            return antlrcpp::Any();
        }
        
        try {
            // 创建Python实例
            auto instance = createPythonInstance(moduleName, className, args);
            return antlrcpp::Any(instance);
        } catch (const std::exception& e) {
            reportError("Failed to create instance: " + std::string(e.what()), ctx);
            return antlrcpp::Any();
        }
    } else {
        // 多个标识符的情况，如 cts.ComplexData
        // 先检查第一个标识符是否是变量（模块对象）
        std::string firstId = idNames[0];
        auto varIt = variables_.find(firstId);
        if (varIt != variables_.end() && varIt->second->holds_alternative<py::object>()) {
            py::object firstObj = varIt->second->get<py::object>();
            // 尝试作为模块处理（不严格检查类型）
            try {
                // 构建属性路径（剩余标识符）
                std::string attrPath;
                for (size_t i = 1; i < idNames.size(); ++i) {
                    if (i > 1) attrPath += ".";
                    attrPath += idNames[i];
                }
                // 获取类对象
                py::object classObj = firstObj.attr(attrPath.c_str());
                
                // 准备构造函数参数
                py::tuple pyArgs(args.size());
                for (size_t i = 0; i < args.size(); ++i) {
                    pyArgs[i] = scriptValueToPyObject(args[i])->get<py::object>();
                }
                
                // 创建实例
                py::object instance = classObj(*pyArgs);
                return antlrcpp::Any(pyObjectToScriptValue(instance));
            } catch (const py::error_already_set& e) {
                // 如果失败，继续尝试模块路径导入
                // 不报告错误，因为可能还有其他方式
            }
        }
        
        // 否则，按照模块路径导入
        std::string className = idNames.back();
        std::vector<std::string> modulePath(idNames.begin(), idNames.end() - 1);
        
        // 尝试按路径查找模块
        std::string modulePathStr;
        for (size_t i = 0; i < modulePath.size(); ++i) {
            if (i > 0) modulePathStr += ".";
            modulePathStr += modulePath[i];
        }
        
        try {
            // 首先检查是否已导入该模块
            py::module_ module;
            auto modIt = imported_modules_.find(modulePathStr);
            if (modIt != imported_modules_.end()) {
                module = modIt->second;
            } else {
                // 尝试导入模块
                module = py::module_::import(modulePathStr.c_str());
                imported_modules_[modulePathStr] = module;
            }
            
            // 从模块中获取类
            py::object classObj = module.attr(className.c_str());
            
            // 准备构造函数参数
            py::tuple pyArgs(args.size());
            for (size_t i = 0; i < args.size(); ++i) {
                pyArgs[i] = scriptValueToPyObject(args[i])->get<py::object>();
            }
            
            // 创建实例
            py::object instance = classObj(*pyArgs);
            return antlrcpp::Any(pyObjectToScriptValue(instance));
            
        } catch (const py::error_already_set& e) {
            reportError("Failed to create instance " + modulePathStr + "." + className + 
                       ": " + std::string(e.what()), ctx);
            return antlrcpp::Any();
        } catch (const std::exception& e) {
            reportError("Failed to create instance: " + std::string(e.what()), ctx);
            return antlrcpp::Any();
        }
    }
}

antlrcpp::Any ScriptInterpreter::visitSubscriptExpr(PyScriptParser::SubscriptExprContext *ctx) {
    auto objValue = evaluateExpression(ctx->expression(0));
    auto indexValue = evaluateExpression(ctx->expression(1));
    
    if (!objValue || !indexValue) {
        reportError("Cannot evaluate subscript expression", ctx);
        return antlrcpp::Any();
    }
    
    // 支持Python对象
    if (objValue->holds_alternative<py::object>()) {
        py::object pyObj = objValue->get<py::object>();
        
        try {
            // 将索引转换为Python对象
            auto pyIndexWrapper = scriptValueToPyObject(indexValue);
            py::object pyIndex = pyIndexWrapper->get<py::object>();
            py::object result = pyObj[pyIndex];
            
            return antlrcpp::Any(pyObjectToScriptValue(result));
        } catch (const py::error_already_set& e) {
            reportError("Python subscript error: " + std::string(e.what()), ctx);
            return antlrcpp::Any();
        }
    }
    // 支持脚本列表
    else if (objValue->holds_alternative<std::vector<std::shared_ptr<ScriptValue>>>()) {
        auto& list = objValue->get<std::vector<std::shared_ptr<ScriptValue>>>();
        
        // 索引必须是整数
        if (!indexValue->holds_alternative<int>()) {
            reportError("List index must be an integer", ctx);
            return antlrcpp::Any();
        }
        
        int index = indexValue->get<int>();
        
        // 检查边界
        if (index < 0 || index >= static_cast<int>(list.size())) {
            reportError("List index out of bounds: " + std::to_string(index) + 
                       " (list size: " + std::to_string(list.size()) + ")", ctx);
            return antlrcpp::Any();
        }
        
        return antlrcpp::Any(list[index]);
    }
    // 支持脚本字典
    else if (objValue->holds_alternative<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>>()) {
        auto& dict = objValue->get<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>>();
        
        // 索引必须是字符串
        if (!indexValue->holds_alternative<std::string>()) {
            reportError("Dictionary key must be a string", ctx);
            return antlrcpp::Any();
        }
        
        std::string key = indexValue->get<std::string>();
        
        auto it = dict.find(key);
        if (it == dict.end()) {
            reportError("Dictionary key not found: " + key, ctx);
            return antlrcpp::Any();
        }
        
        return antlrcpp::Any(it->second);
    }
    
    reportError("Subscript not supported for this type", ctx);
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitAttributeAssignmentExpr(PyScriptParser::AttributeAssignmentExprContext *ctx) {
    auto objValue = evaluateExpression(ctx->expression(0));
    std::string attrName = ctx->IDENTIFIER()->getText();
    auto value = evaluateExpression(ctx->expression(1));
    
    if (!objValue || !value) {
        reportError("Cannot evaluate attribute assignment", ctx);
        return antlrcpp::Any();
    }
    
    if (objValue->holds_alternative<py::object>()) {
        py::object pyObj = objValue->get<py::object>();
        auto pyValueWrapper = scriptValueToPyObject(value);
        py::object pyValue = pyValueWrapper->get<py::object>();
        
        try {
            pyObj.attr(attrName.c_str()) = pyValue;
            return antlrcpp::Any(value);
        } catch (const py::error_already_set& e) {
            reportError("Python attribute assignment error: " + std::string(e.what()), ctx);
            return antlrcpp::Any();
        }
    }
    
    reportError("Attribute assignment not supported for this type", ctx);
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitSubscriptAssignmentExpr(PyScriptParser::SubscriptAssignmentExprContext *ctx) {
    auto objValue = evaluateExpression(ctx->expression(0));
    auto indexValue = evaluateExpression(ctx->expression(1));
    auto value = evaluateExpression(ctx->expression(2));
    
    if (!objValue || !indexValue || !value) {
        reportError("Cannot evaluate subscript assignment", ctx);
        return antlrcpp::Any();
    }
    
    // 支持Python对象
    if (objValue->holds_alternative<py::object>()) {
        py::object pyObj = objValue->get<py::object>();
        
        try {
            // 将索引和值转换为Python对象
            auto pyIndexWrapper = scriptValueToPyObject(indexValue);
            py::object pyIndex = pyIndexWrapper->get<py::object>();
            auto pyValueWrapper = scriptValueToPyObject(value);
            py::object pyValue = pyValueWrapper->get<py::object>();
            
            pyObj[pyIndex] = pyValue;
            return antlrcpp::Any(value);
        } catch (const py::error_already_set& e) {
            reportError("Python subscript assignment error: " + std::string(e.what()), ctx);
            return antlrcpp::Any();
        }
    }
    // 支持脚本列表
    else if (objValue->holds_alternative<std::vector<std::shared_ptr<ScriptValue>>>()) {
        auto& list = objValue->get<std::vector<std::shared_ptr<ScriptValue>>>();
        
        // 索引必须是整数
        if (!indexValue->holds_alternative<int>()) {
            reportError("List index must be an integer", ctx);
            return antlrcpp::Any();
        }
        
        int index = indexValue->get<int>();
        
        // 检查边界
        if (index < 0 || index >= static_cast<int>(list.size())) {
            // 对于赋值操作，如果索引等于列表大小，则允许追加
            if (index == static_cast<int>(list.size())) {
                list.push_back(value);
                return antlrcpp::Any(value);
            }
            reportError("List index out of bounds: " + std::to_string(index) + 
                       " (list size: " + std::to_string(list.size()) + ")", ctx);
            return antlrcpp::Any();
        }
        
        // 更新列表元素
        list[index] = value;
        return antlrcpp::Any(value);
    }
    // 支持脚本字典
    else if (objValue->holds_alternative<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>>()) {
        auto& dict = objValue->get<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>>();
        
        // 索引必须是字符串
        if (!indexValue->holds_alternative<std::string>()) {
            reportError("Dictionary key must be a string", ctx);
            return antlrcpp::Any();
        }
        
        std::string key = indexValue->get<std::string>();
        
        // 更新或插入字典元素
        dict[key] = value;
        return antlrcpp::Any(value);
    }
    
    reportError("Subscript assignment not supported for this type", ctx);
    return antlrcpp::Any();
}

antlrcpp::Any ScriptInterpreter::visitBinaryExpr(PyScriptParser::BinaryExprContext *ctx) {
    auto left = evaluateExpression(ctx->expression(0));
    auto right = evaluateExpression(ctx->expression(1));
    
    if (!left || !right) {
        reportError("Cannot evaluate binary expression", ctx);
        return antlrcpp::Any();
    }
    
    std::string op = ctx->binaryOp()->getText();
    auto result = evaluateBinaryOp(op, left, right);
    
    if (!result) {
        reportError("Unsupported binary operation: " + op, ctx);
    }
    
    return antlrcpp::Any(result);
}

antlrcpp::Any ScriptInterpreter::visitUnaryExpr(PyScriptParser::UnaryExprContext *ctx) {
    auto value = evaluateExpression(ctx->expression());
    
    if (!value) {
        reportError("Cannot evaluate unary expression", ctx);
        return antlrcpp::Any();
    }
    
    std::string op = ctx->unaryOp()->getText();
    auto result = evaluateUnaryOp(op, value);
    
    if (!result) {
        reportError("Unsupported unary operation: " + op, ctx);
    }
    
    return antlrcpp::Any(result);
}

antlrcpp::Any ScriptInterpreter::visitTernaryExpr(PyScriptParser::TernaryExprContext *ctx) {
    auto cond = evaluateExpression(ctx->expression(0));
    
    if (!cond) {
        reportError("Cannot evaluate condition in ternary expression", ctx);
        return antlrcpp::Any();
    }
    
    if (isTruthy(cond)) {
        return antlrcpp::Any(evaluateExpression(ctx->expression(1)));
    } else {
        return antlrcpp::Any(evaluateExpression(ctx->expression(2)));
    }
}

// ========== 字面量访问方法 ==========

antlrcpp::Any ScriptInterpreter::visitIntegerLiteral(PyScriptParser::IntegerLiteralContext *ctx) {
    std::cout << "DEBUG visitIntegerLiteral: called with text " << ctx->INTEGER()->getText() << std::endl;
    int value = std::stoi(ctx->INTEGER()->getText());
    auto ptr = std::make_shared<ScriptValue>(value);
    std::cout << "DEBUG visitIntegerLiteral: returning shared_ptr with value " << value << std::endl;
    return antlrcpp::Any(ptr);
}

antlrcpp::Any ScriptInterpreter::visitFloatLiteral(PyScriptParser::FloatLiteralContext *ctx) {
    double value = std::stod(ctx->FLOAT()->getText());
    return antlrcpp::Any(std::make_shared<ScriptValue>(value));
}

antlrcpp::Any ScriptInterpreter::visitStringLiteral(PyScriptParser::StringLiteralContext *ctx) {
    std::string text = ctx->STRING()->getText();
    // 去掉引号
    if (text.length() >= 2) {
        text = text.substr(1, text.length() - 2);
    }
    return antlrcpp::Any(std::make_shared<ScriptValue>(text));
}

antlrcpp::Any ScriptInterpreter::visitBooleanLiteral(PyScriptParser::BooleanLiteralContext *ctx) {
    bool value = (ctx->BOOL()->getText() == "true");
    return antlrcpp::Any(std::make_shared<ScriptValue>(value));
}

antlrcpp::Any ScriptInterpreter::visitNullLiteral(PyScriptParser::NullLiteralContext *ctx) {
    // 使用空的Python对象表示null
    return antlrcpp::Any(std::make_shared<ScriptValue>(py::none()));
}

antlrcpp::Any ScriptInterpreter::visitListLiteral(PyScriptParser::ListLiteralContext *ctx) {
    std::vector<std::shared_ptr<ScriptValue>> list;
    
    if (ctx->expressionList()) {
        auto exprList = ctx->expressionList()->expression();
        for (auto expr : exprList) {
            auto value = evaluateExpression(expr);
            if (value) {
                list.push_back(value);
            } else {
                reportError("Cannot evaluate list element", ctx);
                return antlrcpp::Any();
            }
        }
    }
    
    return antlrcpp::Any(std::make_shared<ScriptValue>(list));
}

antlrcpp::Any ScriptInterpreter::visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) {
    std::unordered_map<std::string, std::shared_ptr<ScriptValue>> dict;
    
    if (ctx->keyValuePairList()) {
        auto kvList = ctx->keyValuePairList()->keyValuePair();
        for (auto kv : kvList) {
            auto keyValue = evaluateExpression(kv->expression(0));
            auto valValue = evaluateExpression(kv->expression(1));
            
            if (!keyValue || !valValue) {
                reportError("Cannot evaluate dictionary key-value pair", ctx);
                return antlrcpp::Any();
            }
            
            std::string keyStr = valueToString(keyValue);
            dict[keyStr] = valValue;
        }
    }
    
    return antlrcpp::Any(std::make_shared<ScriptValue>(dict));
}

// ========== 辅助方法 ==========

std::shared_ptr<ScriptInterpreter::ScriptValue> ScriptInterpreter::evaluateExpression(PyScriptParser::ExpressionContext *ctx) {
    auto result = visit(ctx);
    std::cout << "DEBUG evaluateExpression: result.has_value() = " << result.has_value() << std::endl;
    if (result.has_value()) {
        std::cout << "DEBUG evaluateExpression: result.type().name() = " << result.type().name() << std::endl;
        std::cout << "DEBUG evaluateExpression: typeid(std::shared_ptr<ScriptValue>).name() = " << typeid(std::shared_ptr<ScriptValue>).name() << std::endl;
        if (result.type() == typeid(std::shared_ptr<ScriptValue>)) {
            try {
                auto val = std::any_cast<std::shared_ptr<ScriptValue>>(result);
                std::cout << "DEBUG evaluateExpression: success, returning value" << std::endl;
                return val;
            } catch (const std::bad_any_cast& e) {
                std::cerr << "DEBUG evaluateExpression: bad any cast: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "DEBUG evaluateExpression: returning nullptr" << std::endl;
    return nullptr;
}

std::shared_ptr<ScriptInterpreter::ScriptValue> ScriptInterpreter::evaluateBinaryOp(const std::string& op, 
                                                                std::shared_ptr<ScriptValue> left, 
                                                                std::shared_ptr<ScriptValue> right) {
    try {
        if (op == "+") {
            // 数字相加或字符串连接
            if (left->holds_alternative<int>() && right->holds_alternative<int>()) {
                int l = left->get<int>();
                int r = right->get<int>();
                return std::make_shared<ScriptValue>(l + r);
            } else if (left->holds_alternative<double>() || right->holds_alternative<double>()) {
                double l = valueToNumber(left);
                double r = valueToNumber(right);
                return std::make_shared<ScriptValue>(l + r);
            } else if (left->holds_alternative<std::string>() || right->holds_alternative<std::string>()) {
                std::string l = valueToString(left);
                std::string r = valueToString(right);
                return std::make_shared<ScriptValue>(l + r);
            } else if (left->holds_alternative<py::object>() || right->holds_alternative<py::object>()) {
                // Python对象相加
                auto lWrapper = scriptValueToPyObject(left);
                py::object l = lWrapper->get<py::object>();
                auto rWrapper = scriptValueToPyObject(right);
                py::object r = rWrapper->get<py::object>();
                py::object result = l + r;
                return pyObjectToScriptValue(result);
            }
        } else if (op == "-") {
            double l = valueToNumber(left);
            double r = valueToNumber(right);
            return std::make_shared<ScriptValue>(l - r);
        } else if (op == "*") {
            double l = valueToNumber(left);
            double r = valueToNumber(right);
            return std::make_shared<ScriptValue>(l * r);
        } else if (op == "/") {
            double l = valueToNumber(left);
            double r = valueToNumber(right);
            if (std::abs(r) < 1e-10) {
                throw std::runtime_error("Division by zero");
            }
            return std::make_shared<ScriptValue>(l / r);
        } else if (op == "%") {
            if (left->holds_alternative<int>() && right->holds_alternative<int>()) {
                int l = left->get<int>();
                int r = right->get<int>();
                if (r == 0) throw std::runtime_error("Modulo by zero");
                return std::make_shared<ScriptValue>(l % r);
            } else {
                throw std::runtime_error("Modulo operation requires integer operands");
            }
        } else if (op == "==") {
            bool equal = false;
            if (left->index() == right->index()) {
                // 相同类型比较
                equal = std::visit([&](auto&& l, auto&& r) -> bool {
                    using T1 = std::decay_t<decltype(l)>;
                    using T2 = std::decay_t<decltype(r)>;
                    if constexpr (std::is_same_v<T1, T2>) {
                        if constexpr (std::is_same_v<T1, py::object>) {
                            try {
                                return l.is(r);
                            } catch (...) {
                                return py::isinstance(l, r) && py::isinstance(r, l);
                            }
                        } else {
                            return l == r;
                        }
                    } else {
                        return false;
                    }
                }, left->value, right->value);
            } else if (left->holds_alternative<py::object>() || right->holds_alternative<py::object>()) {
                // 尝试Python对象比较
                auto lWrapper = scriptValueToPyObject(left);
                py::object l = lWrapper->get<py::object>();
                auto rWrapper = scriptValueToPyObject(right);
                py::object r = rWrapper->get<py::object>();
                try {
                    equal = l.is(r);
                } catch (...) {
                    equal = false;
                }
            }
            return std::make_shared<ScriptValue>(equal);
        } else if (op == "!=") {
            auto eqResult = evaluateBinaryOp("==", left, right);
            if (eqResult && eqResult->holds_alternative<bool>()) {
                return std::make_shared<ScriptValue>(!eqResult->get<bool>());
            }
            return std::make_shared<ScriptValue>(true);
        } else if (op == "<") {
            double l = valueToNumber(left);
            double r = valueToNumber(right);
            return std::make_shared<ScriptValue>(l < r);
        } else if (op == ">") {
            double l = valueToNumber(left);
            double r = valueToNumber(right);
            return std::make_shared<ScriptValue>(l > r);
        } else if (op == "<=") {
            double l = valueToNumber(left);
            double r = valueToNumber(right);
            return std::make_shared<ScriptValue>(l <= r);
        } else if (op == ">=") {
            double l = valueToNumber(left);
            double r = valueToNumber(right);
            return std::make_shared<ScriptValue>(l >= r);
        } else if (op == "&&") {
            bool l = valueToBool(left);
            bool r = valueToBool(right);
            return std::make_shared<ScriptValue>(l && r);
        } else if (op == "||") {
            bool l = valueToBool(left);
            bool r = valueToBool(right);
            return std::make_shared<ScriptValue>(l || r);
        } else if (op == "=") {
            // 赋值操作应该在assignment中处理
            throw std::runtime_error("Assignment operator = should be handled in assignment statement");
        } else if (op == "+=" || op == "-=" || op == "*=" || op == "/=") {
            // 复合赋值操作符
            throw std::runtime_error("Compound assignment operators not yet implemented");
        }
        
        throw std::runtime_error("Unsupported binary operator: " + op);
        
    } catch (const std::exception& e) {
        throw std::runtime_error("Binary operation error: " + std::string(e.what()));
    }
}

std::shared_ptr<ScriptInterpreter::ScriptValue> ScriptInterpreter::evaluateUnaryOp(const std::string& op, 
                                                               std::shared_ptr<ScriptValue> value) {
    try {
        if (op == "-") {
            if (value->holds_alternative<int>()) {
                int v = value->get<int>();
                return std::make_shared<ScriptValue>(-v);
            } else if (value->holds_alternative<double>()) {
                double v = value->get<double>();
                return std::make_shared<ScriptValue>(-v);
            } else if (value->holds_alternative<py::object>()) {
                // Python对象取负
                py::object pyVal = value->get<py::object>();
                py::object result = -pyVal;
                return pyObjectToScriptValue(result);
            } else {
                throw std::runtime_error("Unary - operator not supported for this type");
            }
        } else if (op == "!") {
            bool v = valueToBool(value);
            return std::make_shared<ScriptValue>(!v);
        } else if (op == "+") {
            // 一元加号，通常返回原值，但需要确保类型正确
            if (value->holds_alternative<int>()) {
                return value;
            } else if (value->holds_alternative<double>()) {
                return value;
            } else if (value->holds_alternative<py::object>()) {
                // Python对象一元加
                py::object pyVal = value->get<py::object>();
                // 一元加操作通常返回原对象
                return pyObjectToScriptValue(pyVal);
            } else {
                throw std::runtime_error("Unary + operator not supported for this type");
            }
        }
        
        throw std::runtime_error("Unsupported unary operator: " + op);
        
    } catch (const std::exception& e) {
        throw std::runtime_error("Unary operation error: " + std::string(e.what()));
    }
}

bool ScriptInterpreter::isTruthy(std::shared_ptr<ScriptValue> value) {
    if (!value) return false;
    
    return std::visit([](auto&& arg) -> bool {
        using T = std::decay_t<decltype(arg)>;
        
        if constexpr (std::is_same_v<T, int>) {
            return arg != 0;
        } else if constexpr (std::is_same_v<T, double>) {
            return std::abs(arg) > 1e-10;
        } else if constexpr (std::is_same_v<T, std::string>) {
            return !arg.empty();
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg;
        } else if constexpr (std::is_same_v<T, py::object>) {
            // 检查Python对象是否为真
            try {
                return py::bool_(arg).cast<bool>();
            } catch (...) {
                return true; // 非空对象默认为真
            }
        } else if constexpr (std::is_same_v<T, std::vector<std::shared_ptr<ScriptValue>>>) {
            return !arg.empty();
        } else if constexpr (std::is_same_v<T, std::unordered_map<std::string, std::shared_ptr<ScriptValue>>>) {
            return !arg.empty();
        }
        
        return false;
    }, value->value);
}

std::string ScriptInterpreter::valueToString(std::shared_ptr<ScriptValue> value) {
    if (!value) return "null";
    
    return std::visit([](auto&& arg) -> std::string {
        using T = std::decay_t<decltype(arg)>;
        
        if constexpr (std::is_same_v<T, int>) {
            return std::to_string(arg);
        } else if constexpr (std::is_same_v<T, double>) {
            return std::to_string(arg);
        } else if constexpr (std::is_same_v<T, std::string>) {
            return arg;
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg ? "true" : "false";
        } else if constexpr (std::is_same_v<T, py::object>) {
            try {
                return py::str(arg).cast<std::string>();
            } catch (...) {
                return "<Python object>";
            }
        } else if constexpr (std::is_same_v<T, std::vector<std::shared_ptr<ScriptValue>>>) {
            return "<list>";
        } else if constexpr (std::is_same_v<T, std::unordered_map<std::string, std::shared_ptr<ScriptValue>>>) {
            return "<dict>";
        }
        
        return "<unknown>";
    }, value->value);
}

double ScriptInterpreter::valueToNumber(std::shared_ptr<ScriptValue> value) {
    if (!value) return 0.0;
    
    return std::visit([](auto&& arg) -> double {
        using T = std::decay_t<decltype(arg)>;
        
        if constexpr (std::is_same_v<T, int>) {
            return static_cast<double>(arg);
        } else if constexpr (std::is_same_v<T, double>) {
            return arg;
        } else if constexpr (std::is_same_v<T, std::string>) {
            try {
                return std::stod(arg);
            } catch (...) {
                return 0.0;
            }
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg ? 1.0 : 0.0;
        } else {
            return 0.0;
        }
    }, value->value);
}

bool ScriptInterpreter::valueToBool(std::shared_ptr<ScriptValue> value) {
    return isTruthy(value);
}

// ========== Python集成方法 ==========

std::shared_ptr<ScriptInterpreter::ScriptValue> ScriptInterpreter::callPythonFunction(py::object func, 
                                                                  const std::vector<std::shared_ptr<ScriptValue>>& args) {
    try {
        // 准备Python参数
        py::tuple pyArgs(args.size());
        
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = scriptValueToPyObject(args[i])->get<py::object>();
        }
        
        // 调用函数
        py::object result = func(*pyArgs);
        
        // 转换回脚本值
        return pyObjectToScriptValue(result);
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Python function call error: " + std::string(e.what()));
    }
}

std::shared_ptr<ScriptInterpreter::ScriptValue> ScriptInterpreter::createPythonInstance(const std::string& moduleName,
                                                                    const std::string& className,
                                                                    const std::vector<std::shared_ptr<ScriptValue>>& args) {
    try {
        py::module_ module = py::module_::import(moduleName.c_str());
        py::object classObj = module.attr(className.c_str());
        
        // 准备构造函数参数
        py::tuple pyArgs(args.size());
        for (size_t i = 0; i < args.size(); ++i) {
            pyArgs[i] = scriptValueToPyObject(args[i])->get<py::object>();
        }
        
        // 创建实例
        py::object instance = classObj(*pyArgs);
        return pyObjectToScriptValue(instance);
        
    } catch (const py::error_already_set& e) {
        throw std::runtime_error("Python instance creation error: " + std::string(e.what()));
    }
}

std::shared_ptr<ScriptInterpreter::ScriptValue> ScriptInterpreter::scriptValueToPyObject(std::shared_ptr<ScriptValue> value) {
    if (!value) {
        return std::make_shared<ScriptValue>(py::none());
    }
    
    // 使用switch语句处理variant，避免模板推导问题
    switch (value->index()) {
        case 0: { // int
            int arg = value->get<int>();
            return std::make_shared<ScriptValue>(py::cast(arg));
        }
        case 1: { // double
            double arg = value->get<double>();
            return std::make_shared<ScriptValue>(py::cast(arg));
        }
        case 2: { // string
            std::string arg = value->get<std::string>();
            return std::make_shared<ScriptValue>(py::cast(arg));
        }
        case 3: { // bool
            bool arg = value->get<bool>();
            return std::make_shared<ScriptValue>(py::cast(arg));
        }
        case 4: { // py::object
            py::object arg = value->get<py::object>();
            return std::make_shared<ScriptValue>(arg);
        }
        case 5: { // vector
            const auto& vec = value->get<std::vector<std::shared_ptr<ScriptValue>>>();
            py::list pyList;
            for (const auto& item : vec) {
                auto pyItem = scriptValueToPyObject(item);
                pyList.append(pyItem->get<py::object>());
            }
            return std::make_shared<ScriptValue>(pyList);
        }
        case 6: { // unordered_map
            const auto& dict = value->get<std::unordered_map<std::string, std::shared_ptr<ScriptValue>>>();
            py::dict pyDict;
            for (const auto& [key, val] : dict) {
                auto pyVal = scriptValueToPyObject(val);
                pyDict[py::cast(key)] = pyVal->get<py::object>();
            }
            return std::make_shared<ScriptValue>(pyDict);
        }
        default:
            return std::make_shared<ScriptValue>(py::none());
    }
}

std::shared_ptr<ScriptInterpreter::ScriptValue> ScriptInterpreter::pyObjectToScriptValue(py::object obj) {
    try {
        // 检查类型并转换
        if (obj.is_none()) {
            return std::make_shared<ScriptValue>(obj);
        } else if (py::isinstance<py::int_>(obj)) {
            return std::make_shared<ScriptValue>(obj.cast<int>());
        } else if (py::isinstance<py::float_>(obj)) {
            return std::make_shared<ScriptValue>(obj.cast<double>());
        } else if (py::isinstance<py::str>(obj)) {
            return std::make_shared<ScriptValue>(obj.cast<std::string>());
        } else if (py::isinstance<py::bool_>(obj)) {
            return std::make_shared<ScriptValue>(obj.cast<bool>());
        } else if (py::isinstance<py::list>(obj) || py::isinstance<py::tuple>(obj)) {
            std::vector<std::shared_ptr<ScriptValue>> list;
            for (auto item : obj) {
                list.push_back(pyObjectToScriptValue(py::reinterpret_borrow<py::object>(item)));
            }
            return std::make_shared<ScriptValue>(list);
        } else if (py::isinstance<py::dict>(obj)) {
            std::unordered_map<std::string, std::shared_ptr<ScriptValue>> dict;
            py::dict pyDict = obj.cast<py::dict>();
            for (auto item : pyDict) {
                std::string key = py::str(item.first).cast<std::string>();
                auto value = pyObjectToScriptValue(py::reinterpret_borrow<py::object>(item.second));
                dict[key] = value;
            }
            return std::make_shared<ScriptValue>(dict);
        } else {
            // 其他Python对象原样存储
            return std::make_shared<ScriptValue>(obj);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error converting Python object: " << e.what() << std::endl;
        return std::make_shared<ScriptValue>(obj); // 至少保持Python对象
    }
}

void ScriptInterpreter::reportError(const std::string& message, antlr4::ParserRuleContext *ctx) {
    std::cerr << "Script Error: " << message;
    
    if (ctx) {
        auto token = ctx->getStart();
        if (token) {
            std::cerr << " at line " << token->getLine() 
                      << ", column " << token->getCharPositionInLine();
        }
    }
    
    std::cerr << std::endl;
    has_error_ = true;
}
