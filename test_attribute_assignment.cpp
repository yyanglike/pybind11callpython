#include <gtest/gtest.h>
#include <memory>
#include "script_interpreter.h"
#include "include/dynamic_python_caller.h"

namespace py = pybind11;

// Global test environment to ensure Python interpreter is initialized once
class PythonEnv : public ::testing::Environment {
public:
    void SetUp() override {
        if (!Py_IsInitialized()) {
            guard_ = std::make_unique<py::scoped_interpreter>();
            py::module_ sys = py::module_::import("sys");
            sys.attr("path").attr("insert")(0, ".");
            sys.attr("path").attr("insert")(0, "./python");
        }
    }

    static std::unique_ptr<py::scoped_interpreter> guard_;
};

std::unique_ptr<py::scoped_interpreter> PythonEnv::guard_ = nullptr;

::testing::Environment* const py_env = ::testing::AddGlobalTestEnvironment(new PythonEnv());

using namespace script_interpreter;

TEST(AttributeAssignment, PythonObjectAttribute) {
    ScriptInterpreter interp;
    interp.setLogLevel(LogLevel::Error);
    bool ok = interp.execute("import complex_test_script as cts\nobj = cts.ComplexData(2)\nobj.new_attr = 42\nobj.new_attr\n");
    EXPECT_TRUE(ok);
    auto res = interp.getResult();
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isInteger());
    EXPECT_EQ(res->getInteger(), 42);
}

TEST(AttributeAssignment, DictionaryMember) {
    ScriptInterpreter interp;
    interp.setLogLevel(LogLevel::Error);
    bool ok = interp.execute("d = {\"a\": 1}\nd.b = 2\nd.b\n");
    EXPECT_TRUE(ok);
    auto res = interp.getResult();
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isInteger());
    EXPECT_EQ(res->getInteger(), 2);
}

// Helper to ensure Python is initialized for tests
static void ensurePython() {
    static std::unique_ptr<py::scoped_interpreter> guard;
    if (!Py_IsInitialized()) {
        guard = std::make_unique<py::scoped_interpreter>();
        py::module_ sys = py::module_::import("sys");
        sys.attr("path").attr("insert")(0, ".");
        sys.attr("path").attr("insert")(0, "./python");
    }
}

TEST(EnhancedFeatures, ArgumentList) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
obj = new cts.ComplexData("test", {"value": 100});
result = obj.add_record("test_record", 50);
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto result = interpreter.getVariable("result");
    ASSERT_NE(result, nullptr);
}

TEST(EnhancedFeatures, ExpressionList) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
mixed_list = [42, 3.14159, "hello world", [1,2,3], {"k":"v"}, true, null];
result = mixed_list;
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto result = interpreter.getVariable("result");
    ASSERT_NE(result, nullptr);
    EXPECT_TRUE(result->isList());
}

TEST(EnhancedFeatures, DictOperations) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
base_config = {"server": "localhost", "port": 8080};
auth_config = {"username": "admin", "password": "secret"};
logging_config = {"level": "debug", "file": "app.log"};
full_config = {**base_config, **auth_config, **logging_config, "timeout": 30};
result = full_config;
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto result = interpreter.getVariable("result");
    ASSERT_NE(result, nullptr);
    EXPECT_TRUE(result->isDictionary());
}

TEST(EnhancedFeatures, PythonDataExchange) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import json;

 data = {"name": "test", "values": [1, 2, 3, 4, 5]};
json_str = json.dumps(data, indent=2);
parsed_back = json.loads(json_str);
result = {"original": data, "json_string": json_str, "parsed": parsed_back};
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto result = interpreter.getVariable("result");
    ASSERT_NE(result, nullptr);
}

TEST(SubscriptAssignment, DictSubscriptAssignment) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
my_dict = {"a": 100, "b": 200};
my_dict["c"] = 300;
result = my_dict["c"];
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto result = interpreter.getVariable("result");
    ASSERT_NE(result, nullptr);
    EXPECT_TRUE(result->isInteger());
    EXPECT_EQ(result->getInteger(), 300);
}

TEST(SubscriptAssignment, ListSubscriptAssignment) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
my_list = [1, 2, 3, 4, 5];
my_list[2] = 999;
result = my_list[2];
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto result = interpreter.getVariable("result");
    ASSERT_NE(result, nullptr);
    EXPECT_TRUE(result->isInteger());
    EXPECT_EQ(result->getInteger(), 999);
}

TEST(SubscriptAssignment, DictSubscriptAccess) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
my_dict = {"x": 10, "y": 20};
result = my_dict["x"];
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto result = interpreter.getVariable("result");
    ASSERT_NE(result, nullptr);
    EXPECT_TRUE(result->isInteger());
    EXPECT_EQ(result->getInteger(), 10);
}

TEST(ScriptInterpreter, BasicScript) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = "x = 10; y = 20; z = x + y;";
    EXPECT_TRUE(interpreter.execute(script));
    auto z = interpreter.getVariable("z");
    ASSERT_NE(z, nullptr);
    EXPECT_TRUE(z->isInteger());
    EXPECT_EQ(z->getInteger(), 30);
}

TEST(ScriptInterpreter, PythonIntegration) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    // Ensure python path includes ../python for module import if needed
    py::module_ sys = py::module_::import("sys");
    sys.attr("path").attr("insert")(0, "../python");

    std::string script = R"(
import class_module;
Person = class_module.Person;
person = new Person("Alice", 25);
intro = person.introduce();
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto intro = interpreter.getVariable("intro");
    ASSERT_NE(intro, nullptr);
}

TEST(ScriptInterpreter, ControlFlow) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = "x = 10; if (x > 5) { result = \"x is greater than 5\"; } else { result = \"x is not greater than 5\"; }";
    EXPECT_TRUE(interpreter.execute(script));
    auto result = interpreter.getVariable("result");
    ASSERT_NE(result, nullptr);
    EXPECT_TRUE(result->isString());
    EXPECT_EQ(result->getString(), "x is greater than 5");
}

TEST(ScriptInterpreter, ErrorHandling) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    // Syntax error
    std::string script1 = "x = ;";
    EXPECT_FALSE(interpreter.execute(script1));
    EXPECT_FALSE(interpreter.getErrorMessage().empty());

    // Undefined variable
    interpreter.clearEnvironment();
    std::string script2 = "x = undefined_var;";
    EXPECT_FALSE(interpreter.execute(script2));
    EXPECT_FALSE(interpreter.getErrorMessage().empty());

    // Type error (some implementations may treat as error, others coerce)
    interpreter.clearEnvironment();
    std::string script3 = "x = 10 + \"hello\";";
    bool exec_ok = interpreter.execute(script3);
    if (!exec_ok) {
        EXPECT_FALSE(interpreter.getErrorMessage().empty());
    } else {
        auto xval = interpreter.getVariable("x");
        ASSERT_NE(xval, nullptr);
        // If executed, expect the result is not an integer (likely string coercion)
        EXPECT_FALSE(xval->isInteger());
    }
}

TEST(ModuleEnum, ListDynamicFuncs) {
    ensurePython();
    auto functions = DynamicPythonCaller::listModuleFunctions("dynamic_funcs");
    EXPECT_FALSE(functions.empty());
}

TEST(ClassHandling, CreateAndCallPerson) {
    ensurePython();
    py::module_ sys = py::module_::import("sys");
    sys.attr("path").attr("insert")(0, "../python");

    py::object person = DynamicPythonCaller::createClassInstance("class_module", "Person", py::make_tuple("Alice", 25));
    ASSERT_FALSE(person.is_none());
    bool isPerson = DynamicPythonCaller::isInstanceOf(person, "class_module", "Person");
    EXPECT_TRUE(isPerson);

    py::object intro = DynamicPythonCaller::callClassMethod(person, "introduce");
    ASSERT_FALSE(intro.is_none());
}

TEST(DynamicCall, DynamicInvocation) {
    ensurePython();
    py::module_ sys = py::module_::import("sys");
    sys.attr("path").attr("insert")(0, "../python");

    py::object res = DynamicPythonCaller::dynamicCall("dynamic_funcs", "func_one_arg", py::make_tuple(123));
    ASSERT_FALSE(res.is_none());
}

TEST(EnhancedArguments, StarUnpack) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
def f(a, b): { return a + b; }
arr = [1, 2];
result = f(*arr);
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isInteger());
    EXPECT_EQ(res->getInteger(), 3);
}

TEST(EnhancedArguments, DoubleStarUnpack) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
def g(a=0, b=0): { return a * b; }
d = {"a": 3, "b": 4};
result = g(**d);
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isInteger());
    EXPECT_EQ(res->getInteger(), 12);
}

TEST(Operators, PowerRightAssociative) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = "result = 2 ** 3 ** 2;";
    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isInteger());
    EXPECT_EQ(res->getInteger(), 512);
}

TEST(DictMerge, MultipleUnpackOrder) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
d1 = {"x": 1};
d2 = {"x": 2};
result = {**d1, **d2, "y": 3};
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isDictionary());
    auto dict = res->getDictionary();
    auto itx = dict.find("x");
    ASSERT_NE(itx, dict.end());
    EXPECT_TRUE(itx->second->isInteger());
    EXPECT_EQ(itx->second->getInteger(), 2);
}

// From test_complex_scenario: basic variable storage and simple for-loop
TEST(ComplexScenario, VariableStorage) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
// 简单赋值测试
x = 42;
y = "hello";
z = true;
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto x = interpreter.getVariable("x");
    auto y = interpreter.getVariable("y");
    auto z = interpreter.getVariable("z");
    ASSERT_NE(x, nullptr);
    ASSERT_NE(y, nullptr);
    ASSERT_NE(z, nullptr);
    EXPECT_TRUE(x->isInteger());
    EXPECT_EQ(x->getInteger(), 42);
    EXPECT_TRUE(y->isString());
    EXPECT_TRUE(z->isBoolean());
    EXPECT_TRUE(z->getBoolean());
}

TEST(ComplexScenario, InstanceCreationAndMethod) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
// 创建复杂数据结构实例
obj = new cts.ComplexData("test_instance");
count = obj.add_record("k", 123);
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto obj = interpreter.getVariable("obj");
    auto count = interpreter.getVariable("count");
    ASSERT_NE(obj, nullptr);
    ASSERT_NE(count, nullptr);
}

TEST(ComplexScenario, ForLoopNestedData) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
nested_data = [];
for (i = 0; i < 3; i = i + 1) {
    nested_data = nested_data + [{"id": i, "value": i * 10}];
}
result = nested_data;
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isList());
    EXPECT_EQ(res->listSize(), 3);
}

TEST(ComplexSyntax, FunctionDefinitionVisitor) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
def visitor(node_value, depth): {
    return node_value + ":" + str(depth);
}
result = visitor("node1", 2);
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isString());
    EXPECT_EQ(res->getString(), "node1:2");
}

TEST(ComplexSyntax, LambdaDictDoubleValue) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
double_value = lambda x: {**x, "value": x["value"] * 2};
result = double_value({"name": "test", "value": 5});
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isDictionary());
    auto dict = res->getDictionary();
    auto it = dict.find("value");
    ASSERT_NE(it, dict.end());
    EXPECT_TRUE(it->second->isInteger());
    EXPECT_EQ(it->second->getInteger(), 10);
}

TEST(ComplexScenario, ModuleSelfTestReturns) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
results = cts.run_all_tests();
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto r = interpreter.getVariable("results");
    ASSERT_NE(r, nullptr);
}

TEST(ComplexScenario, MathOperations) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
m = new cts.MathOperations(10);
r1 = m.calculate("add", 1, 2, 3, 4);
r2 = m.calculate("multiply", 2, 3, 4);
r3 = m.calculate("power", 2, 3);
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto r1 = interpreter.getVariable("r1");
    auto r2 = interpreter.getVariable("r2");
    auto r3 = interpreter.getVariable("r3");
    ASSERT_NE(r1, nullptr);
    ASSERT_NE(r2, nullptr);
    ASSERT_NE(r3, nullptr);
    EXPECT_TRUE(r1->isInteger());
    EXPECT_TRUE(r2->isInteger());
    EXPECT_TRUE(r3->isInteger());
    EXPECT_EQ(r1->getInteger(), 20);
    EXPECT_EQ(r2->getInteger(), 34);
    EXPECT_EQ(r3->getInteger(), 18);
}

TEST(ComplexScenario, TreeNodeChildren) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
root = new cts.TreeNode("root");
child = new cts.TreeNode("child");
root.add_child(child);
root_is_leaf = root.is_leaf;
child_is_leaf = child.is_leaf;
result = {"root_leaf": root_is_leaf, "child_leaf": child_is_leaf};
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    ASSERT_TRUE(res->isDictionary());
    auto dict = res->getDictionary();
    auto itRoot = dict.find("root_leaf");
    auto itChild = dict.find("child_leaf");
    ASSERT_NE(itRoot, dict.end());
    ASSERT_NE(itChild, dict.end());
    // Use toBoolean() for truthiness (accepts booleans or truthy values)
    EXPECT_FALSE(itRoot->second->toBoolean());
    EXPECT_TRUE(itChild->second->toBoolean());
}

TEST(ComplexScenario, ComplexDataMergeInstances) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
data2 = new cts.ComplexData("d2");
data3 = cts.ComplexData.create_from_dict("d3", {"a": 1, "b": 2});
merged = cts.ComplexData.merge_instances(data2, data3);
merged_name = merged.name;
merged_data_size = len(merged.data);
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto merged_name = interpreter.getVariable("merged_name");
    auto merged_data_size = interpreter.getVariable("merged_data_size");
    ASSERT_NE(merged_name, nullptr);
    ASSERT_NE(merged_data_size, nullptr);
    EXPECT_TRUE(merged_name->isString());
    EXPECT_TRUE(merged_data_size->isInteger());
}

TEST(ComplexScenario, PerformanceTest) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
performance_data = cts.performance_test(1);
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto pd = interpreter.getVariable("performance_data");
    ASSERT_NE(pd, nullptr);
}

TEST(ComplexSyntax, ChainedMethodAndDictExpand) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
data_obj = new cts.ComplexData("chain_test", {"initial": 100});
result = data_obj.add_record("added", 200).toString();
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isString());
}

TEST(ComplexSyntax, ListComprehension) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
result = [{"id": i, "value": i * 10} for i in range(3)];
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto res = interpreter.getVariable("result");
    ASSERT_NE(res, nullptr);
    EXPECT_TRUE(res->isList());
    EXPECT_EQ(res->listSize(), 3);
}

TEST(ComplexScenario, ModuleSelfTest) {
    ensurePython();
    ScriptInterpreter interpreter;
    interpreter.setLogLevel(LogLevel::Error);

    std::string script = R"(
import complex_test_script as cts;
test_results = cts.run_all_tests();
)";

    EXPECT_TRUE(interpreter.execute(script));
    auto tr = interpreter.getVariable("test_results");
    // Accept either dict or non-empty result
    ASSERT_NE(tr, nullptr);
}
