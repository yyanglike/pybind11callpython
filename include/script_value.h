#ifndef SCRIPT_VALUE_H
#define SCRIPT_VALUE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <variant>
#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

class ScriptValue {
public:
    // 支持的类型
    enum class Type {
        Null,
        Integer,
        Double,
        Boolean,
        String,
        PythonObject,
        List,
        Dictionary
    };

    // 使用variant存储实际值
    using ValueVariant = std::variant<
        std::nullptr_t,      // Null
        long long,           // Integer
        double,              // Double
        bool,                // Boolean
        std::string,         // String
        py::object,          // PythonObject
        std::vector<std::shared_ptr<ScriptValue>>,  // List
        std::unordered_map<std::string, std::shared_ptr<ScriptValue>>  // Dictionary
    >;

    // 构造函数
    ScriptValue() : value_(nullptr), type_(Type::Null) {}
    explicit ScriptValue(long long val) : value_(val), type_(Type::Integer) {}
    explicit ScriptValue(double val) : value_(val), type_(Type::Double) {}
    explicit ScriptValue(bool val) : value_(val), type_(Type::Boolean) {}
    explicit ScriptValue(const std::string& val) : value_(val), type_(Type::String) {}
    explicit ScriptValue(py::object val) : value_(val), type_(Type::PythonObject) {}
    explicit ScriptValue(const std::vector<std::shared_ptr<ScriptValue>>& val) : value_(val), type_(Type::List) {}
    explicit ScriptValue(const std::unordered_map<std::string, std::shared_ptr<ScriptValue>>& val) : value_(val), type_(Type::Dictionary) {}
    
    // 拷贝构造函数
    ScriptValue(const ScriptValue& other);
    
    // 移动构造函数
    ScriptValue(ScriptValue&& other) noexcept;
    
    // 赋值运算符
    ScriptValue& operator=(const ScriptValue& other);
    ScriptValue& operator=(ScriptValue&& other) noexcept;
    
    // 析构函数
    ~ScriptValue();

    // 类型检查
    Type getType() const { return type_; }
    bool isNull() const { return type_ == Type::Null; }
    bool isInteger() const { return type_ == Type::Integer; }
    bool isDouble() const { return type_ == Type::Double; }
    bool isBoolean() const { return type_ == Type::Boolean; }
    bool isString() const { return type_ == Type::String; }
    bool isPythonObject() const { return type_ == Type::PythonObject; }
    bool isList() const { return type_ == Type::List; }
    bool isDictionary() const { return type_ == Type::Dictionary; }
    bool isNumber() const { return isInteger() || isDouble(); }

    // 值获取（带类型检查）
    long long getInteger() const;
    double getDouble() const;
    bool getBoolean() const;
    const std::string& getString() const;
    py::object getPythonObject() const;
    const std::vector<std::shared_ptr<ScriptValue>>& getList() const;
    const std::unordered_map<std::string, std::shared_ptr<ScriptValue>>& getDictionary() const;

    // 安全转换（失败返回默认值）
    long long toInteger() const;
    double toDouble() const;
    bool toBoolean() const;
    std::string toString() const;

    // 修改值
    void setInteger(long long val);
    void setDouble(double val);
    void setBoolean(bool val);
    void setString(const std::string& val);
    void setPythonObject(py::object val);
    void setList(const std::vector<std::shared_ptr<ScriptValue>>& val);
    void setDictionary(const std::unordered_map<std::string, std::shared_ptr<ScriptValue>>& val);

    // 成员操作（用于对象属性赋值）
    void setMember(const std::string& name, std::shared_ptr<ScriptValue> val);

    // 列表操作
    void append(std::shared_ptr<ScriptValue> val);
    std::shared_ptr<ScriptValue> getAt(size_t index) const;
    void setAt(size_t index, std::shared_ptr<ScriptValue> val);
    size_t listSize() const;

    // 字典操作
    void setKey(const std::string& key, std::shared_ptr<ScriptValue> val);
    std::shared_ptr<ScriptValue> getKey(const std::string& key) const;
    bool hasKey(const std::string& key) const;

    // 比较操作
    bool operator==(const ScriptValue& other) const;
    bool operator!=(const ScriptValue& other) const { return !(*this == other); }

    // 转换为字符串表示
    std::string toDebugString() const;

    // 创建各种类型的值
    static std::shared_ptr<ScriptValue> createNull();
    static std::shared_ptr<ScriptValue> createInteger(long long val);
    static std::shared_ptr<ScriptValue> createDouble(double val);
    static std::shared_ptr<ScriptValue> createBoolean(bool val);
    static std::shared_ptr<ScriptValue> createString(const std::string& val);
    static std::shared_ptr<ScriptValue> createPythonObject(py::object val);
    static std::shared_ptr<ScriptValue> createList();
    static std::shared_ptr<ScriptValue> createDictionary();

    // Python对象转换
    static std::shared_ptr<ScriptValue> fromPythonObject(py::object obj);
    py::object toPythonObject() const;

private:
    ValueVariant value_;
    Type type_;
    
    // 辅助方法
    void cleanup();
    void copyFrom(const ScriptValue& other);
};

#endif // SCRIPT_VALUE_H
