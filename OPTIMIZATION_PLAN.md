# 性能优化方案

## 当前性能问题分析

根据性能测试结果，缓存机制在某些场景下反而更慢（0.83x）。主要原因：

1. **缓存键计算开销大**：需要遍历所有变量并构建字符串
2. **重复遍历**：构建缓存键和检查 PythonObject 时都遍历变量
3. **字符串拼接开销**：多次字符串拼接和内存分配
4. **不必要的模块导入**：每次函数定义都导入 `builtins` 模块

## 优化方案

### 1. 缓存键计算优化 ⭐⭐⭐

**问题**：当前遍历所有变量构建缓存键，开销大

**优化方案**：
- **方案A（推荐）**：两级缓存策略
  - 第一级：仅使用函数源代码哈希（快速路径）
  - 第二级：源代码哈希 + 变量状态哈希（完整路径）
  - 先检查第一级，命中且无 PythonObject 时直接使用
  
- **方案B**：增量哈希
  - 使用 `std::hash_combine` 替代字符串拼接
  - 减少内存分配和字符串操作

**预期收益**：减少 30-50% 的缓存键计算时间

```cpp
// 优化前
std::string cache_key_str = funcDef;
for (const auto& varName : variable_manager_.getAllVariableNames()) {
    cache_key_str += varName + ":" + val->toString() + ";";
}
size_t cache_key = hashString(cache_key_str);

// 优化后（方案A）
size_t source_hash = hashString(funcDef);
auto source_it = exec_cache_source_.find(source_hash);
if (source_it != exec_cache_source_.end() && !has_python_objects) {
    // 快速路径：仅源代码匹配
    return source_it->second;
}
// 完整路径：源代码 + 变量状态
size_t full_hash = combineHash(source_hash, variable_state_hash);
```

### 2. 合并变量遍历 ⭐⭐

**问题**：构建缓存键和检查 PythonObject 时重复遍历

**优化方案**：
- 合并为一次遍历，同时收集：
  - 变量状态（用于缓存键）
  - 是否有 PythonObject（用于缓存策略）

**预期收益**：减少 50% 的变量遍历时间

```cpp
// 优化前
// 第一次遍历：构建缓存键
for (const auto& varName : variable_manager_.getAllVariableNames()) { ... }
// 第二次遍历：检查 PythonObject
for (const auto& varName : variable_manager_.getAllVariableNames()) { ... }

// 优化后
bool has_python_objects = false;
size_t variable_state_hash = 0;
for (const auto& varName : variable_manager_.getAllVariableNames()) {
    auto val = variable_manager_.getVariable(varName);
    if (val) {
        if (val->isPythonObject()) {
            has_python_objects = true;
            variable_state_hash = combineHash(variable_state_hash, 
                reinterpret_cast<size_t>(val->toPythonObject().ptr()));
        } else {
            variable_state_hash = combineHash(variable_state_hash, 
                hashString(val->toString()));
        }
    }
}
```

### 3. 缓存 builtins 模块 ⭐⭐

**问题**：每次函数定义都导入 `builtins` 模块

**优化方案**：
- 在 `AstVisitor` 构造函数中导入并缓存 `builtins` 模块
- 或者使用 `py::exec` 的默认行为（不需要显式导入）

**预期收益**：减少模块导入开销（每次 ~0.001-0.01ms）

```cpp
// 优化前
py::object builtins_module = py::module_::import("builtins");
builtins_module.attr("exec")(funcDef, globals, globals);

// 优化后
// 在构造函数中
builtins_module_ = py::module_::import("builtins");
// 使用时
builtins_module_.attr("exec")(funcDef, globals, globals);
```

### 4. 字符串拼接优化 ⭐

**问题**：多次字符串拼接和内存分配

**优化方案**：
- 使用 `std::ostringstream` 或预分配字符串大小
- 或者直接使用增量哈希，避免字符串拼接

**预期收益**：减少 10-20% 的字符串操作时间

### 5. 延迟缓存策略 ⭐⭐⭐

**问题**：对于单次定义的函数，缓存没有优势

**优化方案**：
- 只在函数被定义多次时才启用缓存
- 使用计数器跟踪函数定义次数
- 或者使用"热函数"检测（定义次数 > 1）

**预期收益**：避免单次定义函数的缓存开销

```cpp
// 跟踪函数定义次数
std::unordered_map<std::string, size_t> func_def_count_;

// 在 visitFunctionDef 中
func_def_count_[funcName]++;
bool should_cache = cache_enabled_ && func_def_count_[funcName] > 1;
```

### 6. 缓存键预计算 ⭐

**问题**：每次函数定义都重新计算缓存键

**优化方案**：
- 如果函数源代码相同，可以复用之前的缓存键
- 使用 `std::unordered_map<std::string, size_t>` 缓存源代码到哈希的映射

**预期收益**：减少重复函数的哈希计算

### 7. 减少 Python 对象转换 ⭐⭐

**问题**：频繁的 `toPythonObject()` 和 `fromPythonObject()` 转换

**优化方案**：
- 在缓存键计算时，避免不必要的 `toPythonObject()` 调用
- 对于 PythonObject，直接使用指针地址，不进行转换

**预期收益**：减少 Python 调用开销

## 实施优先级

### 高优先级（立即实施）
1. ✅ **合并变量遍历** - 简单、收益明显
2. ✅ **缓存 builtins 模块** - 简单、无副作用
3. ✅ **延迟缓存策略** - 解决单次定义函数的性能问题

### 中优先级（后续优化）
4. **两级缓存策略** - 需要重构缓存逻辑
5. **增量哈希** - 需要实现 `hash_combine`

### 低优先级（可选）
6. **字符串拼接优化** - 收益较小
7. **缓存键预计算** - 需要额外内存

## 预期性能提升

实施高优先级优化后：
- **单次定义函数**：性能提升 20-30%（避免缓存开销）
- **重复定义函数**：性能提升 10-20%（减少缓存键计算）
- **整体性能**：预计提升 15-25%

## 实施建议

1. **第一步**：实施合并变量遍历和缓存 builtins 模块（简单、安全）
2. **第二步**：实施延迟缓存策略（需要测试）
3. **第三步**：根据实际效果决定是否实施两级缓存策略

## 注意事项

1. **正确性优先**：所有优化必须保证结果一致性
2. **渐进式优化**：每次只优化一个点，测试验证后再继续
3. **性能测试**：使用 `verify_cache_consistency.sh` 验证优化效果
4. **回归测试**：确保所有测试用例仍然通过

