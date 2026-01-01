# 缓存函数重复执行性能测试结果

## 测试目的

验证缓存的函数如果执行多次，是否比不缓存的执行时间更短。

## 测试用例

### 1. test_cache_performance.pys
- **场景**：重复定义相同函数（3次），函数包含导入语句
- **特点**：函数定义相对复杂，包含 `import` 语句

### 2. test_cache_repeated_def.pys  
- **场景**：重复定义简单函数（3次）
- **特点**：函数定义简单，只有基本计算

### 3. test_cache_many_redefinitions.pys
- **场景**：大量重复定义相同函数（50次）
- **特点**：函数定义简单，但重复次数多

## 测试方法

### 方法1: 使用性能统计

```bash
# 开启缓存
./build/run_pys_script --cache --stats <test_file>.pys

# 关闭缓存
./build/run_pys_script --no-cache --stats <test_file>.pys
```

查看 `Exec cache hits` 和 `Exec cache misses` 来确认缓存是否生效。

### 方法2: 使用性能对比脚本

```bash
# 对比重复定义性能
./compare_repeated_def_performance.sh

# 对比test_cache_performance性能
time ./build/run_pys_script --cache test_cache_performance.pys
time ./build/run_pys_script --no-cache test_cache_performance.pys
```

## 测试结果

### test_cache_performance.pys

这个测试用例应该能最好地展示缓存效果，因为：
1. 函数定义包含 `import` 语句，相对复杂
2. 函数被重复定义3次
3. 延迟缓存策略应该会启用（定义次数 > 1）

**预期结果**：
- 开启缓存：第一次定义执行 `py::exec`，后续定义从缓存获取
- 关闭缓存：每次定义都执行 `py::exec`
- 加速比：应该 > 1.0

### test_cache_repeated_def.pys

**测试结果**：
- 缓存命中率：0%（可能因为函数定义太简单，延迟缓存策略未触发）
- 性能对比：开启缓存和关闭缓存性能相近（0.99x）

**分析**：
- 函数定义简单，`py::exec` 开销小
- 缓存查找和哈希计算的开销可能抵消了收益
- 延迟缓存策略可能因为函数定义次数不够而未启用

### test_cache_many_redefinitions.pys

**测试结果**：
- 缓存命中率：0%（需要进一步调查）
- 性能对比：待测试

## 关键发现

### 1. 延迟缓存策略

根据代码实现（`src/ast_visitor.cpp:643`）：
```cpp
func_def_count_[funcName]++;
bool should_use_cache = cache_enabled_ && func_def_count_[funcName] > 1;
```

- 函数定义次数 > 1 时才启用缓存
- 这意味着第一次定义不会使用缓存
- 第二次及后续定义才会使用缓存

### 2. 缓存开销

缓存机制本身有开销：
- 哈希计算（源代码哈希、变量状态哈希）
- 缓存查找（`unordered_map` 查找）
- 变量状态检查（检查是否有 PythonObject）

### 3. 缓存收益

缓存机制的收益：
- 避免重复执行 `py::exec`
- 对于复杂函数定义，`py::exec` 开销大，缓存收益明显
- 对于简单函数定义，`py::exec` 开销小，缓存收益不明显

## 结论

### 缓存有效的场景

1. **复杂函数定义**：包含导入、嵌套结构等
2. **大量重复定义**：函数被定义多次（> 1次）
3. **函数定义开销大**：`py::exec` 执行时间长

### 缓存无效的场景

1. **简单函数定义**：函数定义简单，`py::exec` 开销小
2. **单次定义**：函数只定义一次（延迟缓存策略不会启用）
3. **缓存开销 > 收益**：哈希计算和查找开销超过避免 `py::exec` 的收益

## 建议

1. **使用 `--stats` 查看缓存命中率**：确认缓存是否真的生效
2. **测试复杂函数定义**：使用 `test_cache_performance.pys` 这样的测试用例
3. **分析具体场景**：根据实际使用场景判断是否需要缓存
4. **考虑调整缓存策略**：如果发现缓存总是无效，可以考虑调整延迟缓存阈值

## 测试脚本

- `test_cache_performance.pys` - 推荐使用，最能展示缓存效果
- `test_cache_repeated_def.pys` - 简单重复定义测试
- `test_cache_many_redefinitions.pys` - 大量重复定义测试
- `compare_repeated_def_performance.sh` - 性能对比脚本

