# 测试文档

本文档整合了测试执行指南、测试修复总结和新功能测试报告。

## 目录

- [测试准备](#测试准备)
- [运行测试](#运行测试)
- [测试覆盖范围](#测试覆盖范围)
- [测试修复总结](#测试修复总结)
- [新功能测试报告](#新功能测试报告)

---

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

---

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

### 方法3：运行所有测试用例
```bash
find python -name "*.pys" -type f | while read f; do
    echo "Testing $f..."
    ./build/run_pys_script "$f" > /dev/null 2>&1 && echo "  PASS" || echo "  FAIL"
done
```

---

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

---

## 测试修复总结

### 1. 赋值运算符获取方式改进

**问题**: 之前通过遍历children并匹配文本字符串来获取赋值运算符，不够可靠。

**修复**: 
- 改为通过检查token类型来获取赋值运算符
- 使用 `dynamic_cast<antlr4::tree::TerminalNode*>` 和 `getSymbol()->getType()` 来准确识别token类型
- 支持所有赋值运算符：`+=`, `-=`, `*=`, `/=`, `//=`, `%=`, `**=`, `&=`, `|=`, `^=`, `<<=`, `>>=`

**影响范围**:
- `visitAssignment` - 标识符赋值
- `visitAssignment` - 属性赋值（新增支持）
- `visitAssignment` - 下标赋值（新增支持）

### 2. 条件表达式实现修复

**问题**: 条件表达式的实现逻辑需要确保正确处理三元运算符的语法结构。

**修复**:
- 正确解析 `logicalOr (IF logicalOr ELSE conditionalExpression)?` 语法
- 确保条件为真时返回IF后的表达式，条件为假时返回ELSE后的表达式
- 支持嵌套条件表达式

### 3. 比较运算符中的 `is`/`is not`/`not in` 支持

**问题**: `visitComparison` 中通过 `getText()` 获取操作符，无法正确处理多词操作符（`is not`, `not in`）。

**修复**:
- 改为通过检查token类型来获取操作符
- 正确识别 `IS`, `IS_NOT`, `NOT_IN` token类型
- 确保这些操作符能正确传递给 `ExpressionEvaluator`

### 4. 元组字面量优先级修复

**问题**: 在 `visitPrimary` 中，如果同时存在 `expression()` 和 `tupleLiteral()`，优先检查 `expression()` 可能导致元组被误解析为表达式。

**修复**:
- 调整优先级：优先检查 `tupleLiteral()`，因为元组需要逗号分隔，更容易识别
- 确保 `(1, 2, 3)` 被正确解析为元组而不是表达式

### 5. 属性赋值和下标赋值支持赋值运算符

**问题**: 之前只有标识符赋值支持赋值运算符（如 `+=`, `-=` 等），属性赋值和下标赋值不支持。

**修复**:
- 为属性赋值添加赋值运算符支持（如 `obj.attr += 1`）
- 为下标赋值添加赋值运算符支持（如 `arr[0] += 1`）
- 实现逻辑：先获取当前值，执行运算，再赋值

---

## 新功能测试报告

### 第一阶段：位运算符和 `//`
✅ **已完成**
- 添加了 `FLOOR_DIV`, `BITWISE_AND`, `BITWISE_OR`, `BITWISE_XOR`, `LEFT_SHIFT`, `RIGHT_SHIFT`, `BITWISE_NOT` tokens
- 更新了表达式优先级规则（添加了 `shift`, `bitwiseOr`, `bitwiseXor`, `bitwiseAnd`）
- 实现了 `visitShift`, `visitBitwiseOr`, `visitBitwiseXor`, `visitBitwiseAnd` 访问器方法
- 更新了 `visitUnary` 支持 `~` 运算符
- 更新了 `visitMultiplicative` 支持 `//` 运算符

**测试用例**: `python/test_bitwise_operators.pys`

### 第二阶段：常用 Python 特性
✅ **已完成**

#### 2.1 is/is not/not in 运算符
- 添加了 `IS`, `IS_NOT`, `NOT_IN` tokens
- 更新了 `comparison` 规则
- 在 `ExpressionEvaluator` 中实现了这些运算符的逻辑

**测试用例**: `python/test_is_not_in.pys`

#### 2.2 elif 关键字
- 添加了 `ELIF` token
- 更新了 `ifStatement` 规则使用 `ELIF` 而不是 `ELSE IF`
- 更新了 `visitIfStatement` 支持多个 `elif` 分支

**测试用例**: `python/test_elif.pys`

#### 2.3 break/continue 语句
- 添加了 `BREAK`, `CONTINUE` tokens
- 添加了 `breakStatement`, `continueStatement` 规则
- 实现了 `visitBreakStatement`, `visitContinueStatement`
- 添加了 `break_flag_` 和 `continue_flag_` 控制流标志
- 更新了 `visitWhileStatement` 和 `visitForStatement` 支持 break/continue

**测试用例**: `python/test_break_continue.pys`

#### 2.4 赋值运算符
- 添加了所有赋值运算符 tokens (`+=`, `-=`, `*=`, `/=`, `//=`, `%=`, `**=`, `&=`, `|=`, `^=`, `<<=`, `>>=`)
- 更新了 `assignment` 规则
- 更新了 `visitAssignment` 支持赋值运算符（先获取当前值，执行运算，再赋值）

**测试用例**: `python/test_assignment_operators.pys`

### 第三阶段：语法完整性
✅ **已完成**

#### 3.1 三引号字符串
- 扩展了 `STRING` 规则支持 `"""` 和 `'''`
- 支持多行字符串

**测试用例**: `python/test_triple_quotes.pys`

#### 3.2 嵌套推导式
- 添加了 `comprehension` 和 `compFor` 规则
- 更新了 `listElements`, `dictComprehension`, `setElements`, `generatorExpression` 支持多个 `for` 和 `if` 子句
- 实现了 `visitComprehension` 和 `visitCompFor`（占位实现，实际处理在现有推导式代码中）

**测试用例**: `python/test_nested_comprehension.pys`

#### 3.3 条件表达式（三元运算符）
- 添加了 `conditionalExpression` 规则：`logicalOr (IF logicalOr ELSE conditionalExpression)?`
- 实现了 `visitConditionalExpression`
- 支持嵌套条件表达式

**测试用例**: `python/test_conditional_expression.pys`

#### 3.4 元组字面量
- 添加了 `tupleLiteral` 规则
- 更新了 `primary` 规则支持 `tupleLiteral`
- 实现了 `visitTupleLiteral`（使用列表表示元组）

**测试用例**: `python/test_tuple_literal.pys`

---

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

---

## 已知限制

1. **元组实现**: 当前使用列表表示元组，不是真正的不可变元组类型
2. **切片赋值**: 不支持切片赋值（如 `arr[1:3] = [10, 20]`）
3. **嵌套推导式**: `visitComprehension` 和 `visitCompFor` 是占位实现，实际处理在现有的推导式代码中

