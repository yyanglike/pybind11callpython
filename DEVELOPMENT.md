# 开发文档

本文档整合了项目开发过程中的编译修复、语法分析和开发指南。

## 目录

- [编译错误修复](#编译错误修复)
- [语法分析](#语法分析)
- [最新修复](#最新修复)

---

## 编译错误修复

### 问题

ANTLR 没有为以下规则生成对应的 context 类：
- `BreakStatementContext` / `ContinueStatementContext` - 已修复，改为直接检查 token
- `ShiftContext`, `BitwiseOrContext`, `BitwiseXorContext`, `BitwiseAndContext` - 已修复，改为使用实际存在的方法
- `ConditionalExpressionContext` - 需要删除实现
- `TupleLiteralContext` - 需要删除实现
- `ComprehensionContext`, `CompForContext` - 需要删除实现

### 已完成的修复

1. **`break`/`continue` 语句**：
   - 修改了 `visitSmallStatement` 来直接检查 token 类型
   - 删除了 `visitBreakStatement` 和 `visitContinueStatement` 的声明和实现

2. **`visitLogicalAnd` 和 `visitComparison` 方法**：
   - 修复了 `visitLogicalAnd`：将 `ctx->bitwiseOr()` 改为 `ctx->equality()`
   - 修复了 `visitComparison`：将 `ctx->shift()` 改为 `ctx->additive()`
   - 原因：ANTLR 生成的 context 类中没有 `bitwiseOr()` 和 `shift()` 方法，这些规则被内联到了父规则中

3. **语法文件更新**：
   - 在 `smallStatement` 规则中使用标签 `# breakStatement` 和 `# continueStatement`
   - 删除了独立的 `breakStatement` 和 `continueStatement` 规则

### 需要删除的方法

#### 在 `include/ast_visitor.h` 中删除：
- `visitShift`
- `visitBitwiseOr`
- `visitBitwiseXor`
- `visitBitwiseAnd`
- `visitConditionalExpression`
- `visitTupleLiteral`
- `visitComprehension`
- `visitCompFor`

#### 在 `src/ast_visitor.cpp` 中删除实现：
- `visitShift` (约 2000 行)
- `visitBitwiseOr` (约 2048 行)
- `visitBitwiseXor` (约 2096 行)
- `visitBitwiseAnd` (约 2146 行)
- `visitConditionalExpression` (约 1770 行)
- `visitTupleLiteral` (约 1070 行)
- `visitComprehension` (约 1092 行)
- `visitCompFor` (约 1099 行)

### 需要修改的调用

1. **条件表达式**：在 `visitExpression` 中直接处理 `conditionalExpression`
2. **位运算符**：在 `visitComparison` 和 `visitLogicalAnd` 中直接处理（已修复）
3. **元组字面量**：在 `visitPrimary` 中直接处理
4. **推导式**：在 `visitListElements` 等中直接处理

---

## 语法分析

### ✅ 已实现但语法文件缺少的运算符

以下运算符在 `ExpressionEvaluator` 中已实现，但语法文件中缺少token定义：

1. **`//` (FLOOR_DIV)** - 向下取整除法
2. **`&` (BITWISE_AND)** - 按位与
3. **`|` (BITWISE_OR)** - 按位或
4. **`^` (BITWISE_XOR)** - 按位异或
5. **`<<` (LEFT_SHIFT)** - 左移
6. **`>>` (RIGHT_SHIFT)** - 右移
7. **`~` (BITWISE_NOT)** - 按位取反（一元）

### ❌ 完全缺失的Python特性

1. **`is` 和 `is not` 运算符**
2. **`not in` 运算符**
3. **`elif` 关键字**
4. **`break` 和 `continue` 语句**
5. **`yield` 关键字**
6. **`raise` 语句**
7. **`del` 语句**
8. **`global` 和 `nonlocal` 关键字**
9. **赋值运算符**
10. **三引号字符串**
11. **嵌套推导式**
12. **元组字面量**
13. **切片赋值**
14. **条件表达式（三元运算符）**
15. **Walrus运算符（海象运算符）**

### 优先级问题

当前语法文件的运算符优先级可能不完整：
1. **位运算符优先级**：`&`, `^`, `|` 应该在逻辑运算符之前
2. **`is`/`is not`优先级**：应该在比较运算符之后，逻辑运算符之前
3. **`not in`优先级**：应该与 `in` 相同

### 语法结构问题

#### 1. if语句结构

当前使用 `ELSE IF` 而不是 `ELIF`，不符合Python习惯。

#### 2. 推导式结构

当前只支持单层for循环，不支持嵌套for循环和多个if条件。

#### 3. 字符串字面量

当前不支持三引号、原始字符串和字节字符串。

---

## 最新修复

### 1. 修复了 `visitLogicalAnd` 和 `visitComparison` 方法

修复了对不存在方法的调用：
- `visitLogicalAnd`: `ctx->bitwiseOr()` → `ctx->equality()`
- `visitComparison`: `ctx->shift()` → `ctx->additive()`

这些修复解决了编译错误，因为 ANTLR 生成的 context 类中没有 `bitwiseOr()` 和 `shift()` 方法。

### 2. 修复了 ANTLR 语法文件中的标签不一致问题

修复了 `antlr/PyScript.g4` 中的标签错误：
- `smallStatement` 规则：移除了 `BREAK` 和 `CONTINUE` 的标签（`# breakStatement` 和 `# continueStatement`），因为其他替代项没有标签
- `primary` 规则：移除了 `LPAREN expression RPAREN` 和 `LPAREN tupleLiteral RPAREN` 的标签（`# parenExpr` 和 `# parenTuple`），因为其他替代项没有标签

ANTLR 要求规则中的所有替代项要么全部有标签，要么全部没有标签。现在语法文件符合这个要求。

### 3. 修复了函数定义完成后解释器仍访问函数体内节点的问题

**问题描述**：
- 函数定义完成后，ANTLR 的访问器仍在访问函数体内的节点
- 导致函数体内的表达式（如列表推导式）被错误地求值

**修复方案**：
- 添加函数定义行号范围跟踪机制
- 在 `visitFunctionDef` 中记录每个函数的行号范围
- 实现 `isNodeInsideFunctionDef` 方法，通过行号范围检测节点是否在函数体内
- 在 `visitAssignment` 和 `visitListElements` 中使用新的检测机制

**代码变更**：
- 在 `AstVisitor` 类中添加了 `function_ranges_` 成员变量
- 定义了 `FunctionRange` 结构体来存储函数的起始和结束行号
- 创建了 `isNodeInsideFunctionDef` 方法来检测节点是否在函数定义体内

