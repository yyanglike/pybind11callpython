# 测试执行指南

## 测试准备

1. **确保项目已编译**
   ```bash
   cd /Users/yangyi/company/python/pybind11callpython
   cmake --build build
   ```

2. **确保可执行文件存在**
   ```bash
   ls -la build/run_pys_script
   ```

## 运行测试

### 方法1：使用批量测试脚本
```bash
./run_tests.sh
```

测试结果会保存到 `test_results.txt` 文件中。

### 方法2：逐个运行测试
```bash
# 测试位运算符和//运算符
./build/run_pys_script python/test_bitwise_operators.pys

# 测试is/is not/not in运算符
./build/run_pys_script python/test_is_not_in.pys

# 测试elif关键字
./build/run_pys_script python/test_elif.pys

# 测试break/continue语句
./build/run_pys_script python/test_break_continue.pys

# 测试赋值运算符
./build/run_pys_script python/test_assignment_operators.pys

# 测试三引号字符串
./build/run_pys_script python/test_triple_quotes.pys

# 测试嵌套推导式
./build/run_pys_script python/test_nested_comprehension.pys

# 测试条件表达式（三元运算符）
./build/run_pys_script python/test_conditional_expression.pys

# 测试元组字面量
./build/run_pys_script python/test_tuple_literal.pys

# 综合测试所有新功能
./build/run_pys_script python/test_all_new_features.pys
```

## 预期结果

所有测试应该通过，输出应该包含：
- 各种运算符的计算结果
- 断言检查通过
- 最终输出 "All tests passed!" 或类似消息

## 常见问题排查

### 1. 如果测试失败，检查：
- 编译是否有错误
- ANTLR代码是否已重新生成
- Python环境是否正确配置

### 2. 如果出现语法错误：
- 检查 `.pys` 文件是否有语法错误
- 检查 ANTLR 语法文件是否正确

### 3. 如果出现运行时错误：
- 检查错误信息中的行号和列号
- 查看 `src/ast_visitor.cpp` 中对应的访问器方法实现

## 测试覆盖范围

1. **位运算符** (`test_bitwise_operators.pys`)
   - `&`, `|`, `^`, `<<`, `>>`, `~`
   - `//` (地板除)

2. **比较运算符** (`test_is_not_in.pys`)
   - `is`, `is not`, `not in`

3. **控制流** (`test_elif.pys`, `test_break_continue.pys`)
   - `elif` 关键字
   - `break` 和 `continue` 语句

4. **赋值运算符** (`test_assignment_operators.pys`)
   - `+=`, `-=`, `*=`, `/=`, `//=`, `%=`, `**=`
   - `&=`, `|=`, `^=`, `<<=`, `>>=`

5. **字符串** (`test_triple_quotes.pys`)
   - 三引号字符串（`"""` 和 `'''`）

6. **推导式** (`test_nested_comprehension.pys`)
   - 嵌套列表推导式
   - 嵌套字典推导式
   - 嵌套集合推导式
   - 生成器表达式

7. **条件表达式** (`test_conditional_expression.pys`)
   - 三元运算符：`condition if true_expr else false_expr`

8. **元组** (`test_tuple_literal.pys`)
   - 元组字面量创建
   - 元组解包

9. **综合测试** (`test_all_new_features.pys`)
   - 所有新功能的综合测试

## 测试结果分析

运行测试后，检查：
1. 所有测试是否通过
2. 输出是否符合预期
3. 是否有任何警告或错误信息

如果有失败的测试，请查看 `test_results.txt` 文件中的详细错误信息。

