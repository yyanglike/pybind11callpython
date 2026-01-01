# 性能统计功能使用指南

## 概述

解释器内置了性能统计功能，可以追踪脚本执行过程中的关键性能指标，帮助识别性能瓶颈和优化机会。

## 统计指标说明

性能统计包含以下5个指标：

1. **Python calls**: Python 函数调用次数
   - 统计所有通过 `DynamicPythonCaller::callFunction` 调用的 Python 函数

2. **ScriptValue->py::object conversions**: ScriptValue 到 Python 对象的转换次数
   - 统计所有 `toPythonObject()` 调用，主要用于函数参数传递

3. **py::object->ScriptValue conversions**: Python 对象到 ScriptValue 的转换次数
   - 统计所有 `fromPythonObject()` 调用，主要用于函数返回值处理

4. **Direct iterations (fast path)**: 直接迭代次数（快路径）
   - 统计直接使用 C++ 内部存储（`vector`、`unordered_map`）进行迭代的次数
   - 避免了 Python 对象转换的开销，性能更好

5. **Python iterations (slow path)**: Python 迭代次数（慢路径）
   - 统计需要通过 `py::iter()` 进行迭代的次数
   - 适用于 PythonObject 类型或其他需要 Python 迭代器的场景

## 使用方法

### 方法1：命令行选项

使用 `--stats` 或 `-s` 选项：

```bash
./build/run_pys_script --stats python/test_hello.pys
```

### 方法2：环境变量

设置环境变量 `PYS_STATS=1`：

```bash
PYS_STATS=1 ./build/run_pys_script python/test_hello.pys
```

### 方法3：程序化访问

在 C++ 代码中直接访问：

```cpp
#include "script_interpreter.h"

ScriptInterpreter interp;
interp.executeFile("script.pys");

// 获取性能统计
std::string stats = interp.getPerformanceStats();
std::cout << stats << std::endl;

// 重置计数器（如果需要）
interp.resetPerformanceStats();
```

## 示例输出

```
Performance Stats:
  Python calls: 8
  ScriptValue->py::object conversions: 11
  py::object->ScriptValue conversions: 8
  Direct iterations (fast path): 3
  Python iterations (slow path): 0
```

## 性能优化建议

1. **减少 Python 调用**: 如果 `Python calls` 很高，考虑使用 C++ 快路径（如 `len()`、容器方法等）

2. **减少类型转换**: 如果转换次数很高，考虑：
   - 使用直接迭代（快路径）而不是 Python 迭代
   - 优化函数调用，减少不必要的类型转换

3. **优先使用快路径**: 确保推导式使用直接迭代（`Direct iterations` > 0），而不是 Python 迭代（`Python iterations` = 0）

4. **批量处理**: 对于大量数据的处理，考虑批量操作而不是逐个处理

## 注意事项

- 性能统计会增加少量开销（原子计数器操作）
- 计数器在每次脚本执行时自动重置
- 可以通过 `resetPerformanceStats()` 手动重置计数器
- 统计数据是累积的，包括函数定义阶段的调用（如果有）

## 示例场景

### 场景1：简单脚本
```bash
$ ./build/run_pys_script --stats python/test_hello.pys
Performance Stats:
  Python calls: 1
  ScriptValue->py::object conversions: 1
  py::object->ScriptValue conversions: 1
  Direct iterations (fast path): 0
  Python iterations (slow path): 0
```

### 场景2：包含推导式的脚本
```bash
$ ./build/run_pys_script --stats python/test_comprehension_multifor_if.pys
Performance Stats:
  Python calls: 5
  ScriptValue->py::object conversions: 8
  py::object->ScriptValue conversions: 5
  Direct iterations (fast path): 3
  Python iterations (slow path): 0
```

可以看到，推导式使用了快路径（`Direct iterations: 3`），避免了 Python 迭代的开销。

