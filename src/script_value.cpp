#include "script_value.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

using namespace std;

// 拷贝构造函数
ScriptValue::ScriptValue(const ScriptValue& other) {
    copyFrom(other);
}

// 移动构造函数
ScriptValue::ScriptValue(ScriptValue&& other) noexcept 
    : value_(move(other.value_)), type_(other.type_) {
    other.type_ = Type::Null;
    other.value_ = nullptr;
}

// 赋值运算符
ScriptValue& ScriptValue::operator=(const ScriptValue& other) {
    if (this != &other) {
        cleanup();
        copyFrom(other);
    }
    return *this;
}

// 移动赋值运算符
ScriptValue& ScriptValue::operator=(ScriptValue&& other) noexcept {
    if (this != &other) {
        cleanup();
        value_ = move(other.value_);
        type_ = other.type_;
        other.type_ = Type::Null;
        other.value_ = nullptr;
    }
    return *this;
}

// 析构函数
ScriptValue::~ScriptValue() {
    cleanup();
}

// 清理资源
void ScriptValue::cleanup() {
    // variant会自动管理内存，但需要确保Python对象引用计数正确
    if (type_ == Type::PythonObject) {
        try {
            // 确保Python对象被正确释放
            py::object obj = getPythonObject();
            // Python对象会在py::object析构时自动处理引用计数
        } catch (...) {
            // 忽略清理错误
        }
    }
    value_ = nullptr;
    type_ = Type::Null;
}

// 从其他对象拷贝
void ScriptValue::copyFrom(const ScriptValue& other) {
    type_ = other.type_;
    
    switch (type_) {
        case Type::Null:
            value_ = nullptr;
            break;
        case Type::Integer:
            value_ = other.getInteger();
            break;
        case Type::Double:
            value_ = other.getDouble();
            break;
        case Type::Boolean:
            value_ = other.getBoolean();
            break;
        case Type::String:
            value_ = other.getString();
            break;
        case Type::PythonObject:
            value_ = other.getPythonObject();
            break;
        case Type::List: {
            auto list = other.getList();
            vector<shared_ptr<ScriptValue>> newList;
            newList.reserve(list.size());
            for (const auto& item : list) {
                if (item) {
                    newList.push_back(make_shared<ScriptValue>(*item));
                } else {
                    newList.push_back(nullptr);
                }
            }
            value_ = newList;
            break;
        }
        case Type::Dictionary: {
            auto dict = other.getDictionary();
            unordered_map<string, shared_ptr<ScriptValue>> newDict;
            for (const auto& [key, val] : dict) {
                if (val) {
                    newDict[key] = make_shared<ScriptValue>(*val);
                } else {
                    newDict[key] = nullptr;
                }
            }
            value_ = newDict;
            break;
        }
    }
}

// 值获取方法（带类型检查）
long long ScriptValue::getInteger() const {
    if (type_ != Type::Integer) {
        throw runtime_error("ScriptValue is not an integer");
    }
    return get<long long>(value_);
}

double ScriptValue::getDouble() const {
    if (type_ != Type::Double) {
        throw runtime_error("ScriptValue is not a double");
    }
    return get<double>(value_);
}

bool ScriptValue::getBoolean() const {
    if (type_ != Type::Boolean) {
        throw runtime_error("ScriptValue is not a boolean");
    }
    return get<bool>(value_);
}

const string& ScriptValue::getString() const {
    if (type_ != Type::String) {
        throw runtime_error("ScriptValue is not a string");
    }
    return get<string>(value_);
}

py::object ScriptValue::getPythonObject() const {
    if (type_ != Type::PythonObject) {
        throw runtime_error("ScriptValue is not a Python object");
    }
    return get<py::object>(value_);
}

const vector<shared_ptr<ScriptValue>>& ScriptValue::getList() const {
    if (type_ != Type::List) {
        throw runtime_error("ScriptValue is not a list");
    }
    return get<vector<shared_ptr<ScriptValue>>>(value_);
}

const unordered_map<string, shared_ptr<ScriptValue>>& ScriptValue::getDictionary() const {
    if (type_ != Type::Dictionary) {
        throw runtime_error("ScriptValue is not a dictionary");
    }
    return get<unordered_map<string, shared_ptr<ScriptValue>>>(value_);
}

// 安全转换方法
long long ScriptValue::toInteger() const {
    switch (type_) {
        case Type::Integer:
            return getInteger();
        case Type::Double:
            return static_cast<long long>(getDouble());
        case Type::Boolean:
            return getBoolean() ? 1 : 0;
        case Type::String:
            try {
                return stoll(getString());
            } catch (...) {
                return 0;
            }
        default:
            return 0;
    }
}

double ScriptValue::toDouble() const {
    switch (type_) {
        case Type::Integer:
            return static_cast<double>(getInteger());
        case Type::Double:
            return getDouble();
        case Type::Boolean:
            return getBoolean() ? 1.0 : 0.0;
        case Type::String:
            try {
                return stod(getString());
            } catch (...) {
                return 0.0;
            }
        default:
            return 0.0;
    }
}

bool ScriptValue::toBoolean() const {
    switch (type_) {
        case Type::Boolean:
            return getBoolean();
        case Type::Integer:
            return getInteger() != 0;
        case Type::Double:
            return getDouble() != 0.0;
        case Type::String:
            return !getString().empty();
        case Type::Null:
            return false;
        case Type::List:
            return !getList().empty();
        case Type::Dictionary:
            return !getDictionary().empty();
        case Type::PythonObject:
            try {
                py::object obj = getPythonObject();
                // Check if the underlying pointer is valid
                if (!obj.ptr()) {
                    return false;
                }
                // Use py::bool_ to convert to boolean
                return py::bool_(obj).cast<bool>();
            } catch (...) {
                return true; // 非空Python对象默认为真
            }
        default:
            return false;
    }
}

string ScriptValue::toString() const {
    switch (type_) {
        case Type::String:
            return getString();
        case Type::Integer:
            return to_string(getInteger());
        case Type::Double:
            return to_string(getDouble());
        case Type::Boolean:
            return getBoolean() ? "true" : "false";
        case Type::Null:
            return "null";
        case Type::PythonObject:
            try {
                return py::str(getPythonObject()).cast<string>();
            } catch (...) {
                return "<Python object>";
            }
        case Type::List: {
            auto& list = getList();
            ostringstream oss;
            oss << "[";
            for (size_t i = 0; i < list.size(); ++i) {
                if (i > 0) oss << ", ";
                if (list[i]) {
                    oss << list[i]->toString();
                } else {
                    oss << "null";
                }
            }
            oss << "]";
            return oss.str();
        }
        case Type::Dictionary: {
            auto& dict = getDictionary();
            ostringstream oss;
            oss << "{";
            bool first = true;
            for (const auto& [key, val] : dict) {
                if (!first) oss << ", ";
                oss << "\"" << key << "\": ";
                if (val) {
                    oss << val->toString();
                } else {
                    oss << "null";
                }
                first = false;
            }
            oss << "}";
            return oss.str();
        }
        default:
            return "<unknown>";
    }
}

// 修改值方法
void ScriptValue::setInteger(long long val) {
    cleanup();
    type_ = Type::Integer;
    value_ = val;
}

void ScriptValue::setDouble(double val) {
    cleanup();
    type_ = Type::Double;
    value_ = val;
}

void ScriptValue::setBoolean(bool val) {
    cleanup();
    type_ = Type::Boolean;
    value_ = val;
}

void ScriptValue::setString(const string& val) {
    cleanup();
    type_ = Type::String;
    value_ = val;
}

void ScriptValue::setPythonObject(py::object val) {
    cleanup();
    type_ = Type::PythonObject;
    value_ = val;
}

void ScriptValue::setList(const vector<shared_ptr<ScriptValue>>& val) {
    cleanup();
    type_ = Type::List;
    value_ = val;
}

void ScriptValue::setDictionary(const unordered_map<string, shared_ptr<ScriptValue>>& val) {
    cleanup();
    type_ = Type::Dictionary;
    value_ = val;
}

// 列表操作方法
void ScriptValue::append(shared_ptr<ScriptValue> val) {
    if (type_ != Type::List) {
        throw runtime_error("ScriptValue is not a list");
    }
    auto& list = get<vector<shared_ptr<ScriptValue>>>(value_);
    list.push_back(val);
}

shared_ptr<ScriptValue> ScriptValue::getAt(size_t index) const {
    if (type_ != Type::List) {
        throw runtime_error("ScriptValue is not a list");
    }
    auto& list = get<vector<shared_ptr<ScriptValue>>>(value_);
    if (index >= list.size()) {
        throw out_of_range("List index out of range");
    }
    return list[index];
}

void ScriptValue::setAt(size_t index, shared_ptr<ScriptValue> val) {
    if (type_ != Type::List) {
        throw runtime_error("ScriptValue is not a list");
    }
    auto& list = get<vector<shared_ptr<ScriptValue>>>(value_);
    if (index >= list.size()) {
        throw out_of_range("List index out of range");
    }
    list[index] = val;
}

size_t ScriptValue::listSize() const {
    if (type_ != Type::List) {
        throw runtime_error("ScriptValue is not a list");
    }
    return get<vector<shared_ptr<ScriptValue>>>(value_).size();
}

// 字典操作方法
void ScriptValue::setKey(const string& key, shared_ptr<ScriptValue> val) {
    if (type_ != Type::Dictionary) {
        throw runtime_error("ScriptValue is not a dictionary");
    }
    auto& dict = get<unordered_map<string, shared_ptr<ScriptValue>>>(value_);
    dict[key] = val;
}

shared_ptr<ScriptValue> ScriptValue::getKey(const string& key) const {
    if (type_ != Type::Dictionary) {
        throw runtime_error("ScriptValue is not a dictionary");
    }
    auto& dict = get<unordered_map<string, shared_ptr<ScriptValue>>>(value_);
    auto it = dict.find(key);
    if (it == dict.end()) {
        throw runtime_error("Key not found: " + key);
    }
    return it->second;
}

bool ScriptValue::hasKey(const string& key) const {
    if (type_ != Type::Dictionary) {
        return false;
    }
    auto& dict = get<unordered_map<string, shared_ptr<ScriptValue>>>(value_);
    return dict.find(key) != dict.end();
}

void ScriptValue::setMember(const string& name, shared_ptr<ScriptValue> val) {
    // 如果是字典类型，则作为键值对处理
    if (type_ == Type::Dictionary) {
        setKey(name, val);
        return;
    }

    // 如果是Python对象，使用pybind11设置属性
    if (type_ == Type::PythonObject) {
        try {
            py::object obj = getPythonObject();
            obj.attr(name.c_str()) = val->toPythonObject();
            return;
        } catch (const py::error_already_set& e) {
            throw runtime_error(string("Python attribute assignment error: ") + e.what());
        }
    }

    // 其它类型不支持成员赋值
    throw runtime_error("Cannot set member on non-object type");
}

// 比较操作
bool ScriptValue::operator==(const ScriptValue& other) const {
    if (type_ != other.type_) {
        return false;
    }
    
    switch (type_) {
        case Type::Null:
            return true;
        case Type::Integer:
            return getInteger() == other.getInteger();
        case Type::Double:
            return getDouble() == other.getDouble();
        case Type::Boolean:
            return getBoolean() == other.getBoolean();
        case Type::String:
            return getString() == other.getString();
        case Type::PythonObject:
            try {
                return getPythonObject().is(other.getPythonObject());
            } catch (...) {
                return false;
            }
        case Type::List: {
            auto& list1 = getList();
            auto& list2 = other.getList();
            if (list1.size() != list2.size()) {
                return false;
            }
            for (size_t i = 0; i < list1.size(); ++i) {
                if (list1[i] && list2[i]) {
                    if (!(*list1[i] == *list2[i])) {
                        return false;
                    }
                } else if (list1[i] || list2[i]) {
                    return false;
                }
            }
            return true;
        }
        case Type::Dictionary: {
            auto& dict1 = getDictionary();
            auto& dict2 = other.getDictionary();
            if (dict1.size() != dict2.size()) {
                return false;
            }
            for (const auto& [key, val1] : dict1) {
                auto it = dict2.find(key);
                if (it == dict2.end()) {
                    return false;
                }
                auto val2 = it->second;
                if (val1 && val2) {
                    if (!(*val1 == *val2)) {
                        return false;
                    }
                } else if (val1 || val2) {
                    return false;
                }
            }
            return true;
        }
        default:
            return false;
    }
}

// 转换为调试字符串
string ScriptValue::toDebugString() const {
    ostringstream oss;
    oss << "ScriptValue{type=";
    
    switch (type_) {
        case Type::Null: oss << "Null"; break;
        case Type::Integer: oss << "Integer, value=" << getInteger(); break;
        case Type::Double: oss << "Double, value=" << getDouble(); break;
        case Type::Boolean: oss << "Boolean, value=" << (getBoolean() ? "true" : "false"); break;
        case Type::String: oss << "String, value=\"" << getString() << "\""; break;
        case Type::PythonObject: oss << "PythonObject"; break;
        case Type::List: oss << "List, size=" << getList().size(); break;
        case Type::Dictionary: oss << "Dictionary, size=" << getDictionary().size(); break;
    }
    
    oss << "}";
    return oss.str();
}

// 创建各种类型的值
shared_ptr<ScriptValue> ScriptValue::createNull() {
    return make_shared<ScriptValue>();
}

shared_ptr<ScriptValue> ScriptValue::createInteger(long long val) {
    return make_shared<ScriptValue>(val);
}

shared_ptr<ScriptValue> ScriptValue::createDouble(double val) {
    return make_shared<ScriptValue>(val);
}

shared_ptr<ScriptValue> ScriptValue::createBoolean(bool val) {
    return make_shared<ScriptValue>(val);
}

shared_ptr<ScriptValue> ScriptValue::createString(const string& val) {
    return make_shared<ScriptValue>(val);
}

shared_ptr<ScriptValue> ScriptValue::createPythonObject(py::object val) {
    return make_shared<ScriptValue>(val);
}

shared_ptr<ScriptValue> ScriptValue::createList() {
    return make_shared<ScriptValue>(vector<shared_ptr<ScriptValue>>());
}

shared_ptr<ScriptValue> ScriptValue::createDictionary() {
    return make_shared<ScriptValue>(unordered_map<string, shared_ptr<ScriptValue>>());
}

// Python对象转换
shared_ptr<ScriptValue> ScriptValue::fromPythonObject(py::object obj) {
    if (obj.is_none()) {
        return createNull();
    } else if (py::isinstance<py::int_>(obj)) {
        return createInteger(obj.cast<long long>());
    } else if (py::isinstance<py::float_>(obj)) {
        return createDouble(obj.cast<double>());
    } else if (py::isinstance<py::bool_>(obj)) {
        return createBoolean(obj.cast<bool>());
    } else if (py::isinstance<py::str>(obj)) {
        return createString(obj.cast<string>());
    } else if (py::isinstance<py::list>(obj) || py::isinstance<py::tuple>(obj)) {
        auto result = createList();
        for (auto item : obj) {
            result->append(fromPythonObject(py::reinterpret_borrow<py::object>(item)));
        }
        return result;
    } else if (py::isinstance<py::dict>(obj)) {
        auto result = createDictionary();
        py::dict pyDict = obj.cast<py::dict>();
        for (auto item : pyDict) {
            string key = py::str(item.first).cast<string>();
            auto value = fromPythonObject(py::reinterpret_borrow<py::object>(item.second));
            result->setKey(key, value);
        }
        return result;
    } else {
        // 其他Python对象直接包装
        return createPythonObject(obj);
    }
}

py::object ScriptValue::toPythonObject() const {
    switch (type_) {
        case Type::Null:
            return py::none();
        case Type::Integer:
            return py::cast(getInteger());
        case Type::Double:
            return py::cast(getDouble());
        case Type::Boolean:
            return py::cast(getBoolean());
        case Type::String:
            return py::cast(getString());
        case Type::PythonObject:
            return getPythonObject();
        case Type::List: {
            py::list pyList;
            for (const auto& item : getList()) {
                if (item) {
                    pyList.append(item->toPythonObject());
                } else {
                    pyList.append(py::none());
                }
            }
            return pyList;
        }
        case Type::Dictionary: {
            py::dict pyDict;
            for (const auto& [key, val] : getDictionary()) {
                if (val) {
                    pyDict[py::cast(key)] = val->toPythonObject();
                } else {
                    pyDict[py::cast(key)] = py::none();
                }
            }
            return pyDict;
        }
        default:
            return py::none();
    }
}
