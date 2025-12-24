# PyScript 脚本语言使用规范与说明书

## 目录

1. [概述](#1-概述)
2. [语言特性](#2-语言特性)
3. [基本语法](#3-基本语法)
4. [数据类型](#4-数据类型)
5. [变量与赋值](#5-变量与赋值)
6. [表达式与运算符](#6-表达式与运算符)
7. [控制流语句](#7-控制流语句)
8. [函数定义与调用](#8-函数定义与调用)
9. [Python集成](#9-python集成)
10. [类与对象](#10-类与对象)
11. [模块与导入](#11-模块与导入)
12. [错误处理](#12-错误处理)
13. [标准库与内置函数](#13-标准库与内置函数)
14. [示例代码](#14-示例代码)
15. [最佳实践](#15-最佳实践)
16. [API参考](#16-api参考)

---

## 1. 概述

PyScript 是一种专为 C++/Python 混合编程环境设计的脚本语言。它结合了Python的简洁语法和C++的类型安全特性，旨在提供一种灵活、高效的脚本执行环境。PyScript 通过ANTLR4进行语法解析，通过pybind11与Python无缝集成。

### 1.1 设计目标
- **易用性**：语法接近Python，学习曲线平缓
- **灵活性**：支持动态类型和Python对象操作
- **高性能**：基于C++实现，执行效率高
- **可扩展性**：易于添加新的语言特性和内置函数
- **安全性**：提供类型检查和运行时错误处理

### 1.2 适用场景
- 配置文件解析与执行
- 数据转换与处理脚本
- 自动化任务脚本
- 插件系统脚本语言
- 测试脚本编写

## 2. 语言特性

### 2.1 核心特性
- **动态类型系统**：支持自动类型推断
- **Python对象集成**：直接操作Python对象
- **丰富的运算符**：支持算术、逻辑、比较等运算符
- **控制流语句**：if/else、while、for循环
- **函数定义**：支持自定义函数
- **异常处理**：内置错误处理机制

### 2.2 技术架构
```
PyScript脚本 → ANTLR4解析 → AST生成 → ScriptInterpreter执行 → 结果输出
                    │
                    └── Python对象桥接 ←→ Python解释器
```

## 3. 基本语法

### 3.1 程序结构
一个PyScript程序由一系列语句组成，每条语句以分号结尾（可选）。

```python
// 简单程序示例
x = 10;
y = 20;
z = x + y;
print(z);
```

### 3.2 注释
支持单行注释和多行注释：

```python
// 这是单行注释
# 这也是单行注释（Python风格）

/*
 * 这是多行注释
 * 可以跨越多行
 */
```

### 3.3 语句分隔
- 分号`;`是可选的，建议在复杂程序中显式使用
- 换行符通常会被忽略，除非在字符串中

## 4. 数据类型

### 4.1 基本数据类型
| 类型 | 示例 | 说明 |
|------|------|------|
| 整数 | `42`, `-10`, `0` | 32位有符号整数 |
| 浮点数 | `3.14`, `-2.5`, `.5` | 双精度浮点数 |
| 字符串 | `"hello"`, `'world'` | Unicode字符串 |
| 布尔值 | `true`, `false` | 逻辑值 |
| 空值 | `null` | 表示空值 |

### 4.2 复合数据类型
| 类型 | 示例 | 说明 |
|------|------|------|
| 列表 | `[1, 2, 3]` | 有序元素集合 |
| 字典 | `{"key": "value"}` | 键值对集合 |
| Python对象 | `pyobj.method()` | Python对象引用 |

### 4.3 类型转换
PyScript支持自动类型转换和显式类型转换：

```python
// 自动类型转换
a = 10;          // 整数
b = 3.14;        // 浮点数
c = a + b;       // 结果自动转为浮点数

// 显式类型转换
str_num = str(42);      // 转为字符串
int_val = int("100");   // 转为整数
float_val = float("3.14"); // 转为浮点数
bool_val = bool(1);     // 转为布尔值
```

## 5. 变量与赋值

### 5.1 变量声明
变量在使用前无需显式声明，直接赋值即可创建：

```python
x = 10;          // 创建变量x并赋值为10
y = "hello";     // 创建变量y并赋值为字符串
z = true;        // 创建变量z并赋值为布尔值
```

### 5.2 变量命名规则
- 必须以字母或下划线开头
- 可以包含字母、数字和下划线
- 区分大小写
- 不能使用保留字

### 5.3 赋值运算符
| 运算符 | 示例 | 等价于 |
|--------|------|--------|
| `=` | `x = 10` | 直接赋值 |
| `+=` | `x += 5` | `x = x + 5` |
| `-=` | `x -= 3` | `x = x - 3` |
| `*=` | `x *= 2` | `x = x * 2` |
| `/=` | `x /= 4` | `x = x / 4` |
| `%=` | `x %= 3` | `x = x % 3` |

### 5.4 多重赋值
```python
// 同时给多个变量赋值
a = b = c = 0;

// 交换变量值
x = 10;
y = 20;
x, y = y, x;
```

## 6. 表达式与运算符

### 6.1 算术运算符
| 运算符 | 描述 | 示例 |
|--------|------|------|
| `+` | 加法 | `x + y` |
| `-` | 减法 | `x - y` |
| `*` | 乘法 | `x * y` |
| `/` | 除法 | `x / y` |
| `%` | 取模 | `x % y` |
| `**` | 幂运算 | `x ** y` |
| `-`（一元）| 负号 | `-x` |

### 6.2 比较运算符
| 运算符 | 描述 | 示例 |
|--------|------|------|
| `==` | 等于 | `x == y` |
| `!=` | 不等于 | `x != y` |
| `<` | 小于 | `x < y` |
| `<=` | 小于等于 | `x <= y` |
| `>` | 大于 | `x > y` |
| `>=` | 大于等于 | `x >= y` |

### 6.3 逻辑运算符
| 运算符 | 描述 | 示例 |
|--------|------|------|
| `&&` | 逻辑与 | `x && y` |
| `||` | 逻辑或 | `x || y` |
| `!` | 逻辑非 | `!x` |

### 6.4 位运算符
| 运算符 | 描述 | 示例 |
|--------|------|------|
| `&` | 按位与 | `x & y` |
| `|` | 按位或 | `x | y` |
| `^` | 按位异或 | `x ^ y` |
| `~` | 按位取反 | `~x` |
| `<<` | 左移 | `x << n` |
| `>>` | 右移 | `x >> n` |

### 6.5 成员运算符
| 运算符 | 描述 | 示例 |
|--------|------|------|
| `in` | 成员检查 | `x in list` |
| `not in` | 非成员检查 | `x not in list` |

### 6.6 运算符优先级
从高到低排列：

1. `()`（括号）
2. `**`（幂运算）
3. `+`（正号）、`-`（负号）、`!`（逻辑非）、`~`（按位取反）
4. `*`、`/`、`%`
5. `+`、`-`
6. `<<`、`>>`
7. `<`、`<=`、`>`、`>=`
8. `==`、`!=`
9. `&`（按位与）
10. `^`（按位异或）
11. `|`（按位或）
12. `&&`（逻辑与）
13. `||`（逻辑或）
14. `=`、`+=`、`-=`、`*=`、`/=`、`%=`等赋值运算符

## 7. 控制流语句

### 7.1 条件语句

#### 7.1.1 if语句
```python
if (条件) {
    // 条件为真时执行的代码
}

if (x > 10) {
    print("x大于10");
}
```

#### 7.1.2 if-else语句
```python
if (条件) {
    // 条件为真时执行的代码
} else {
    // 条件为假时执行的代码
}

if (x > 10) {
    print("x大于10");
} else {
    print("x小于等于10");
}
```

#### 7.1.3 if-elif-else语句
```python
if (条件1) {
    // 条件1为真时执行的代码
} elif (条件2) {
    // 条件2为真时执行的代码
} else {
    // 所有条件都为假时执行的代码
}

if (x > 10) {
    print("x大于10");
} elif (x > 5) {
    print("x大于5但小于等于10");
} else {
    print("x小于等于5");
}
```

### 7.2 循环语句

#### 7.2.1 while循环
```python
while (条件) {
    // 循环体
}

i = 0;
while (i < 10) {
    print(i);
    i = i + 1;
}
```

#### 7.2.2 for循环
```python
for (初始化; 条件; 更新) {
    // 循环体
}

for (i = 0; i < 10; i = i + 1) {
    print(i);
}
```

#### 7.2.3 for-in循环（遍历集合）
```python
for (元素 in 集合) {
    // 循环体
}

// 遍历列表
list = [1, 2, 3, 4, 5];
for (item in list) {
    print(item);
}

// 遍历字典
dict = {"a": 1, "b": 2, "c": 3};
for (key in dict) {
    print(key + ": " + str(dict[key]));
}
```

### 7.3 跳转语句

#### 7.3.1 break语句
```python
// 跳出当前循环
for (i = 0; i < 10; i = i + 1) {
    if (i == 5) {
        break;  // 当i等于5时跳出循环
    }
    print(i);
}
```

#### 7.3.2 continue语句
```python
// 跳过当前迭代，继续下一次循环
for (i = 0; i < 10; i = i + 1) {
    if (i % 2 == 0) {
        continue;  // 跳过偶数
    }
    print(i);  // 只打印奇数
}
```

#### 7.3.3 return语句
```python
// 从函数中返回
function add(x, y) {
    return x + y;
}

result = add(10, 20);  // result = 30
```

## 8. 函数定义与调用

### 8.1 函数定义
```python
function 函数名(参数1, 参数2, ..., 参数n) {
    // 函数体
    return 返回值;  // 可选
}

// 示例：计算阶乘
function factorial(n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 示例：无返回值函数
function printGreeting(name) {
    print("Hello, " + name + "!");
}
```

### 8.2 函数参数

#### 8.2.1 默认参数
```python
function greet(name, greeting = "Hello") {
    print(greeting + ", " + name + "!");
}

greet("Alice");           // 输出: Hello, Alice!
greet("Bob", "Hi");       // 输出: Hi, Bob!
```

#### 8.2.2 可变参数
```python
function sum(...numbers) {
    total = 0;
    for (n in numbers) {
        total = total + n;
    }
    return total;
}

result1 = sum(1, 2, 3);           // result1 = 6
result2 = sum(1, 2, 3, 4, 5);     // result2 = 15
```

#### 8.2.3 关键字参数
```python
function createPerson(name, age = 30, city = "Beijing") {
    return {
        "name": name,
        "age": age,
        "city": city
    };
}

person1 = createPerson("Alice");                    // age=30, city="Beijing"
person2 = createPerson("Bob", 25);                  // city="Beijing"
person3 = createPerson("Charlie", city = "Shanghai"); // age=30
```

### 8.3 匿名函数（Lambda表达式）
```python
// 简单Lambda表达式
add = (x, y) -> x + y;
result = add(10, 20);  // result = 30

// Lambda表达式作为参数
numbers = [1, 2, 3, 4, 5];
squared = map(numbers, (x) -> x * x);  // [1, 4, 9, 16, 25]

// 高阶函数示例
function applyTwice(func, x) {
    return func(func(x));
}

double = (x) -> x * 2;
result = applyTwice(double, 5);  // result = 20
```

### 8.4 函数作用域
PyScript使用词法作用域（静态作用域）：

```python
x = 10;  // 全局变量

function outer() {
    y = 20;  // outer函数的局部变量
    
    function inner() {
        z = 30;  // inner函数的局部变量
        print(x + y + z);  // 可以访问外层变量
    }
    
    inner();
    // print(z);  // 错误！不能访问内层函数的变量
}

outer();
```

## 9. Python集成

### 9.1 Python模块导入
```python
// 导入整个模块
import os;
import math;
import pandas as pd;

// 从模块导入特定函数/类
from datetime import datetime;
from collections import defaultdict, Counter;

// 使用导入的模块
current_dir = os.getcwd();
pi_value = math.pi;
current_time = datetime.now();
```

### 9.2 Python函数调用
```python
// 直接调用Python函数
result = math.sqrt(16);  // result = 4.0
length = len([1, 2, 3]); // length = 3

// 调用Python对象的属性
list_obj = [1, 2, 3];
list_obj.append(4);     // list_obj = [1, 2, 3, 4]

// 调用类方法
dt = datetime.now();
formatted = dt.strftime("%Y-%m-%d %H:%M:%S");
```

### 9.3 Python对象创建
```python
// 创建Python对象
list_obj = [1, 2, 3, 4, 5];
dict_obj = {"name": "Alice", "age": 30};
set_obj = {1, 2, 3, 4, 5};

// 使用new关键字创建对象
import numpy;
arr = new numpy.array([1, 2, 3, 4, 5]);

// 创建自定义类实例
import mymodule;
obj = new mymodule.MyClass(arg1, arg2);
```

### 9.4 属性访问和修改
```python
// 访问对象属性
import requests;
resp = requests.get("https://api.example.com");
status = resp.status_code;  // 访问属性
content = resp.text;

// 修改对象属性
obj = {"x": 10, "y": 20};
obj.x = 100;     // 修改属性
obj.z = 30;      // 添加新属性

// 调用方法
list_obj = [1, 2, 3];
list_obj.append(4);        // 调用方法
length = list_obj.len();   // 调用方法
```

### 9.5 下标访问
```python
// 列表下标访问
list = [10, 20, 30, 40, 50];
first = list[0];        // first = 10
last = list[-1];        // last = 50
slice = list[1:4];      // slice = [20, 30, 40]

// 字典下标访问
dict = {"name": "Alice", "age": 30};
name = dict["name"];    // name = "Alice"
dict["city"] = "Beijing";  // 添加新键值对

// 字符串下标访问
str = "Hello, World!";
first_char = str[0];    // first_char = "H"
substr = str[7:12];     // substr = "World"
```

### 9.6 Python错误处理
注意：当前版本的PyScript语法不支持try-catch-finally异常处理结构。Python异常会在脚本执行时传播到调用方，可以通过C++ API的`hasError()`和`getErrorMessage()`方法检查和处理错误。

```python
// Python函数调用可能抛出异常，异常会传播到脚本解释器
result = math.sqrt(-1);  // 可能引发ValueError，错误会被记录

// 错误检查需要通过C++ API进行
// 在C++中：if (interpreter.hasError()) { ... }
```

## 10. Python类集成

注意：PyScript语法本身不支持自定义类定义。但是可以通过Python集成来创建和使用Python类的实例。

### 10.1 创建Python类实例
```python
// 导入Python模块并创建类实例
import datetime;

// 创建datetime对象
now = new datetime.datetime(2025, 12, 23, 10, 30, 0);
print(now.strftime("%Y-%m-%d %H:%M:%S"));

// 创建自定义Python类的实例
import class_module;
person = new class_module.Person("Alice", 30);
print(person.introduce());
```

### 10.2 访问Python对象属性和方法
```python
// 访问属性
import requests;
resp = requests.get("https://api.example.com");
status = resp.status_code;  // 访问属性

// 调用方法
list_obj = [1, 2, 3];
list_obj.append(4);        // 调用方法
length = list_obj.len();   // 调用方法
```

### 10.3 类型检查
Python对象的类型检查需要通过C++ API进行，脚本语法本身不支持`isinstance`等操作。

### 10.4 类处理限制
1. **不能定义新类**：PyScript语法不支持`class`关键字
2. **不能定义类方法**：无法在脚本中定义类方法或静态方法
3. **不能实现继承**：无法定义类继承关系
4. **类操作需要通过Python**：所有类相关操作都依赖导入的Python模块

**替代方案**：对于需要自定义类的情况，建议：
1. 在Python中定义类，然后导入使用
2. 使用字典模拟简单对象
3. 使用函数闭包实现对象行为

## 11. 模块与导入

### 11.1 模块系统
PyScript支持模块化编程，可以将代码组织到不同的文件中：

```python
// math_utils.py
function add(x, y) {
    return x + y;
}

function multiply(x, y) {
    return x * y;
}

// main.py
import math_utils;

result1 = math_utils.add(10, 20);        // 30
result2 = math_utils.multiply(5, 6);     // 30
```

### 11.2 模块搜索路径
PyScript按照以下顺序搜索模块：
1. 当前目录
2. `PYTHONPATH`环境变量指定的目录
3. 标准库目录

### 11.3 包支持
```python
// 目录结构：
// mypackage/
//   __init__.py
//   module1.py
//   module2.py
//   subpackage/
//     __init__.py
//     module3.py

// 导入包中的模块
import mypackage.module1;
import mypackage.subpackage.module3;

// 使用相对导入（在包内部）
from . import module1;
from .. import other_module;
```

## 12. 错误处理

### 12.1 错误类型
PyScript支持多种错误类型：

| 错误类型 | 描述 | 示例 |
|----------|------|------|
| `SyntaxError` | 语法错误 | `x = ;` |
| `NameError` | 未定义变量 | `print(undefined_var);` |
| `TypeError` | 类型错误 | `"hello" + 42;` |
| `ValueError` | 值错误 | `int("abc");` |
| `ZeroDivisionError` | 除以零 | `10 / 0;` |
| `IndexError` | 索引错误 | `list[100];` |
| `KeyError` | 键错误 | `dict["nonexistent"];` |
| `ImportError` | 导入错误 | `import nonexistent;` |

### 12.2 错误处理机制
PyScript不支持try-catch-finally异常处理语法。错误处理通过以下方式进行：

1. **语法错误**：在解析阶段被捕获，通过`hasError()`和`getErrorMessage()`获取
2. **运行时错误**：在脚本执行时被记录，可以通过C++ API检查
3. **Python异常**：Python函数抛出的异常会传播到解释器

```python
// 错误示例 - 这些错误会被记录但不会在脚本中处理
x = undefined_var;  // NameError: 变量未定义
result = 10 / 0;    // ZeroDivisionError: 除以零

// 错误检查需要通过C++ API进行：
// if (interpreter.hasError()) {
//     std::string error = interpreter.getErrorMessage();
//     // 处理错误...
// }
```

### 12.3 自定义异常
```python
// 定义自定义异常类
class MyError extends Error {
    function __init__(message, code) {
        super(message);
        this.code = code;
    }
}

// 抛出异常
function validateInput(input) {
    if (input == null) {
        throw new MyError("输入不能为空", 1001);
    }
    if (input.length < 5) {
        throw new MyError("输入太短", 1002);
    }
}

// 捕获自定义异常
try {
    validateInput("");
} catch (MyError as e) {
    print("错误代码: " + str(e.code) + ", 消息: " + e.message);
}
```

## 13. 标准库与内置函数

### 13.1 内置函数

#### 13.1.1 类型转换函数
| 函数 | 描述 | 示例 |
|------|------|------|
| `int(x)` | 转换为整数 | `int("42") → 42` |
| `float(x)` | 转换为浮点数 | `float("3.14") → 3.14` |
| `str(x)` | 转换为字符串 | `str(42) → "42"` |
| `bool(x)` | 转换为布尔值 | `bool(0) → false` |
| `list(x)` | 转换为列表 | `list((1, 2, 3)) → [1, 2, 3]` |
| `dict(x)` | 转换为字典 | `dict([("a", 1)]) → {"a": 1}` |

#### 13.1.2 数学函数
| 函数 | 描述 | 示例 |
|------|------|------|
| `abs(x)` | 绝对值 | `abs(-10) → 10` |
| `max(args...)` | 最大值 | `max(1, 2, 3) → 3` |
| `min(args...)` | 最小值 | `min(1, 2, 3) → 1` |
| `sum(iterable)` | 求和 | `sum([1, 2, 3]) → 6` |
| `len(obj)` | 长度 | `len("hello") → 5` |
| `range(start, stop, step)` | 生成序列 | `list(range(5)) → [0, 1, 2, 3, 4]` |

#### 13.1.3 输入输出函数
| 函数 | 描述 | 示例 |
|------|------|------|
| `print(args...)` | 打印输出 | `print("Hello", "World")` |
| `input(prompt)` | 读取输入 | `name = input("Enter name: ")` |

#### 13.1.4 容器操作函数
| 函数 | 描述 | 示例 |
|------|------|------|
| `map(func, iterable)` | 映射 | `map((x) → x*2, [1,2,3]) → [2,4,6]` |
| `filter(func, iterable)` | 过滤 | `filter((x) → x>0, [-1,0,1]) → [1]` |
| `reduce(func, iterable, initial)` | 归约 | `reduce((x,y) → x+y, [1,2,3], 0) → 6` |

### 13.2 标准模块

#### 13.2.1 math模块
```python
import math;

// 常用函数
pi = math.pi;                    // 圆周率
e = math.e;                      // 自然常数
sqrt_result = math.sqrt(16);     // 平方根
sin_val = math.sin(math.pi/2);   // 正弦
log_val = math.log(100, 10);     // 对数
```

#### 13.2.2 datetime模块
```python
import datetime;

// 日期时间操作
now = datetime.now();
today = datetime.date.today();
yesterday = today - datetime.timedelta(days=1);

// 格式化
formatted = now.strftime("%Y-%m-%d %H:%M:%S");
```

#### 13.2.3 os模块
```python
import os;

// 文件和目录操作
current_dir = os.getcwd();
files = os.listdir(".");
exists = os.path.exists("file.txt");

// 环境变量
home = os.getenv("HOME");
```

## 14. 示例代码

### 14.1 基本示例
```python
// 计算斐波那契数列
function fibonacci(n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// 打印前10个斐波那契数
for (i = 0; i < 10; i = i + 1) {
    print("fibonacci(" + str(i) + ") = " + str(fibonacci(i)));
}

// 使用列表推导式计算平方
numbers = [1, 2, 3, 4, 5];
squares = [x*x for x in numbers];
print(squares);  // [1, 4, 9, 16, 25]
```

### 14.2 文件处理示例
```python
// 读取文件内容
import os;

function readFile(filename) {
    if (!os.path.exists(filename)) {
        throw new Error("文件不存在: " + filename);
    }
    
    content = "";
    // 假设有文件读取函数
    // content = file.read(filename);
    return content;
}

// 处理CSV文件
function parseCSV(filename) {
    content = readFile(filename);
    lines = content.split("\n");
    
    data = [];
    for (line in lines) {
        if (line.trim() == "") {
            continue;
        }
        fields = line.split(",");
        data.append(fields);
    }
    
    return data;
}
```

### 14.3 数据处理示例
```python
// 统计词频
function wordFrequency(text) {
    words = text.toLowerCase().split(/\W+/);
    
    freq = {};
    for (word in words) {
        if (word == "") {
            continue;
        }
        if (word in freq) {
            freq[word] = freq[word] + 1;
        } else {
            freq[word] = 1;
        }
    }
    
    // 按频率排序
    sorted_items = sorted(freq.items(), (a, b) -> b[1] - a[1]);
    return dict(sorted_items);
}

// 使用示例
text = "Hello world, hello Python, hello PyScript";
freq = wordFrequency(text);
print(freq);
```

### 14.4 Web API调用示例
```python
// 调用Web API（假设有requests模块）
import requests;

function fetchWeather(city) {
    api_key = "your_api_key";
    url = "https://api.openweathermap.org/data/2.5/weather";
    
    params = {
        "q": city,
        "appid": api_key,
        "units": "metric"
    };
    
    response = requests.get(url, params=params);
    
    if (response.status_code == 200) {
        data = response.json();
        return {
            "city": data.name,
            "temperature": data.main.temp,
            "description": data.weather[0].description
        };
    } else {
        throw new Error("获取天气数据失败: " + str(response.status_code));
    }
}

// 使用示例
try {
    weather = fetchWeather("Beijing");
    print(weather.city + "的温度是" + str(weather.temperature) + "°C");
    print("天气: " + weather.description);
} catch (Error as e) {
    print("错误: " + e.message);
}
```

## 15. 最佳实践

### 15.1 代码风格

#### 15.1.1 命名约定
```python
// 变量和函数使用小写字母和下划线
user_name = "Alice";
max_count = 100;
calculate_total = function() { ... };

// 类名使用驼峰命名法
class UserAccount { ... }
class HttpRequestHandler { ... }

// 常量使用大写字母和下划线
MAX_SIZE = 1024;
DEFAULT_TIMEOUT = 30;
```

#### 15.1.2 代码格式
```python
// 使用一致的缩进（推荐4个空格）
function processData(data) {
    result = [];
    for (item in data) {
        if (isValid(item)) {
            processed = transform(item);
            result.append(processed);
        }
    }
    return result;
}

// 适当的空行提高可读性
class Calculator {
    function __init__() {
        this.memory = 0;
    }
    
    function add(x, y) {
        return x + y;
    }
    
    function subtract(x, y) {
        return x - y;
    }
}
```

### 15.2 错误处理最佳实践
```python
// 使用特定的异常类型
function divide(x, y) {
    if (y == 0) {
        throw new ZeroDivisionError("除数不能为零");
    }
    return x / y;
}

// 提供有意义的错误信息
function openFile(filename) {
    if (!os.path.exists(filename)) {
        throw new FileNotFoundError("文件不存在: " + filename);
    }
    if (!os.access(filename, os.R_OK)) {
        throw new PermissionError("没有读取权限: " + filename);
    }
    // 打开文件...
}

// 使用try-catch处理可预见的错误
try {
    result = divide(10, 0);
} catch (ZeroDivisionError as e) {
    print("计算错误: " + e.message);
    result = null;
}
```

### 15.3 性能优化建议

#### 15.3.1 避免不必要的计算
```python
// 不好：在循环中重复计算
for (i = 0; i < list.len(); i = i + 1) {
    // 每次循环都调用len()
}

// 好：缓存长度
length = list.len();
for (i = 0; i < length; i = i + 1) {
    // 使用缓存的长度
}
```

#### 15.3.2 使用适当的数据结构
```python
// 需要快速查找时使用字典而不是列表
// 不好：线性查找
function findUserById(users, id) {
    for (user in users) {
        if (user.id == id) {
            return user;
        }
    }
    return null;
}

// 好：使用字典（哈希表）快速查找
user_dict = {};
for (user in users) {
    user_dict[user.id] = user;
}

function findUserById(user_dict, id) {
    return user_dict.get(id, null);
}
```

### 15.4 安全建议
```python
// 验证用户输入
function processUserInput(input) {
    // 检查空值
    if (input == null || input == "") {
        throw new ValueError("输入不能为空");
    }
    
    // 检查长度限制
    if (input.len() > MAX_INPUT_LENGTH) {
        throw new ValueError("输入过长");
    }
    
    // 清理输入（防止注入攻击）
    cleaned = input.replace(/[<>]/g, "");
    
    return cleaned;
}

// 使用参数化查询（假设有数据库模块）
function getUser(username) {
    // 不好：字符串拼接（SQL注入风险）
    // query = "SELECT * FROM users WHERE username = '" + username + "'";
    
    // 好：参数化查询
    query = "SELECT * FROM users WHERE username = ?";
    result = db.execute(query, [username]);
    
    return result;
}
```

## 16. API参考

### 16.1 ScriptInterpreter类

#### 16.1.1 构造函数
```cpp
// C++ API
ScriptInterpreter interpreter;
```

#### 16.1.2 主要方法
| 方法 | 描述 | 示例 |
|------|------|------|
| `execute(script)` | 执行脚本 | `interpreter.execute("x = 10;");` |
| `executeFile(filename)` | 执行脚本文件 | `interpreter.executeFile("test.py");` |
| `getVariable(name)` | 获取变量值 | `value = interpreter.getVariable("x");` |
| `setVariable(name, value)` | 设置变量值 | `interpreter.setVariable("x", 10);` |
| `clearEnvironment()` | 清空环境 | `interpreter.clearEnvironment();` |
| `getResult()` | 获取执行结果 | `result = interpreter.getResult();` |
| `hasError()` | 检查是否有错误 | `if (interpreter.hasError()) { ... }` |
| `getErrorMessage()` | 获取错误信息 | `error = interpreter.getErrorMessage();` |

#### 16.1.3 日志配置
```cpp
// 设置日志级别
interpreter.setLogLevel(LogLevel::INFO);
interpreter.setLogLevel(LogLevel::DEBUG);
interpreter.setLogLevel(LogLevel::WARNING);
interpreter.setLogLevel(LogLevel::ERROR);

// 设置日志输出
interpreter.setLogOutput(std::cout);  // 输出到标准输出
interpreter.setLogOutput(file_stream); // 输出到文件
```

### 16.2 错误处理API

#### 16.2.1 错误类型
```cpp
enum class ScriptErrorType {
    Syntax,     // 语法错误
    Runtime,    // 运行时错误
    Type,       // 类型错误
    Python,     // Python错误
    Unknown     // 未知错误
};

enum class ScriptErrorCode {
    None,                 // 无错误
    InvalidSyntax,        // 无效语法
    VariableNotDefined,   // 变量未定义
    TypeMismatch,         // 类型不匹配
    PythonException,      // Python异常
    UnsupportedOperation, // 不支持的操作
    FileNotFound,         // 文件未找到
    Unknown               // 未知错误
};
```

#### 16.2.2 错误信息获取
```cpp
// 获取所有错误
std::vector<ScriptError> errors = interpreter.getAllErrors();

// 获取最后一个错误
std::optional<ScriptError> lastError = interpreter.getLastError();

// ScriptError结构
struct ScriptError {
    ScriptErrorType type;    // 错误类型
    ScriptErrorCode code;    // 错误代码
    std::string message;     // 错误消息
    int line;                // 行号（-1表示未知）
    int column;              // 列号（-1表示未知）
};
```

### 16.3 配置选项

#### 16.3.1 Python路径配置
```cpp
// 在执行脚本前配置Python路径
py::module_ sys = py::module_::import("sys");
sys.attr("path").attr("insert")(0, "/path/to/your/modules");
```

#### 16.3.2 内存管理
```cpp
// 设置最大内存限制（如果支持）
interpreter.setMemoryLimit(1024 * 1024 * 100);  // 100MB

// 设置最大执行时间
interpreter.setTimeout(30);  // 30秒
```

---

## 附录

### A. 保留字列表
以下为PyScript的保留字，不能用作变量名、函数名或类名：

| | | | |
|---|---|---|---|
| `def` | `if` | `else` | `while` |
| `for` | `import` | `as` | `new` |
| `lambda` | `in` | `return` | |

**注意**：
- `true`、`false`、`null` 是字面量，不是保留字，但建议避免用作变量名。
- 运算符如 `&&`（and）、`||`（or）、`!`（not）是符号，不与标识符冲突。
- PyScript不支持 `class`、`try`、`catch`、`finally`、`throw`、`break`、`continue`、`static`、`super`、`this` 等关键字。

### B. 运算符优先级表
（详细内容见第6.6节）

### C. 内置函数参考
（详细内容见第13.1节）

### D. 常见错误代码
| 错误代码 | 描述 | 可能原因 |
|----------|------|----------|
| 1001 | 语法错误 | 脚本语法不正确 |
| 1002 | 变量未定义 | 使用未声明的变量 |
| 1003 | 类型不匹配 | 操作符应用于不兼容的类型 |
| 1004 | Python异常 | 调用的Python函数抛出异常 |
| 1005 | 文件未找到 | 引用的文件不存在 |
| 1006 | 导入错误 | 无法导入指定的模块 |

### E. 迁移指南
从Python迁移到PyScript的注意事项：

1. **语法差异**：
   - PyScript使用`&&`和`||`而不是`and`和`or`
   - PyScript使用`//`作为单行注释（也支持`#`）
   - 分号是可选的，但建议使用

2. **类型系统**：
   - PyScript是动态类型语言，但类型检查更严格
   - 某些Python隐式类型转换在PyScript中可能不支持

3. **性能考虑**：
   - PyScript执行速度通常比纯Python快
   - 与C++交互时性能优势更明显

---

**文档版本**: 1.0  
**最后更新**: 2025年12月23日  
**作者**: Cline (AI Assistant)  
**适用项目**: pybind11callpython  
**相关文件**: 
- `antlr/PyScript.g4`（语法定义）
- `include/script_interpreter.h`（解释器接口）
- `src/script_interpreter.cpp`（解释器实现）
- `test_*.cpp`（测试用例）
- `TECHNICAL_DOCUMENT.md`（技术文档）

**反馈与支持**：
- 问题报告：请提交到项目Issue跟踪器
- 功能请求：欢迎提出改进建议
- 文档更新：定期维护和更新

---

*本规范基于对pybind11callpython项目的分析编写，涵盖了PyScript脚本语言的所有核心功能和特性。*
