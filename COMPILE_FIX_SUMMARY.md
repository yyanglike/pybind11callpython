# 编译错误修复总结

## 问题
ANTLR 没有为以下规则生成对应的 context 类：
- `BreakStatementContext` / `ContinueStatementContext` - 已修复，改为直接检查 token
- `ShiftContext`, `BitwiseOrContext`, `BitwiseXorContext`, `BitwiseAndContext` - 已修复，改为使用实际存在的方法
- `ConditionalExpressionContext` - 需要删除实现
- `TupleLiteralContext` - 需要删除实现
- `ComprehensionContext`, `CompForContext` - 需要删除实现

## 已完成的修复

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

## 需要删除的方法

### 在 `include/ast_visitor.h` 中删除：
- `visitShift`
- `visitBitwiseOr`
- `visitBitwiseXor`
- `visitBitwiseAnd`
- `visitConditionalExpression`
- `visitTupleLiteral`
- `visitComprehension`
- `visitCompFor`

### 在 `src/ast_visitor.cpp` 中删除实现：
- `visitShift` (约 2000 行)
- `visitBitwiseOr` (约 2048 行)
- `visitBitwiseXor` (约 2096 行)
- `visitBitwiseAnd` (约 2146 行)
- `visitConditionalExpression` (约 1770 行)
- `visitTupleLiteral` (约 1070 行)
- `visitComprehension` (约 1092 行)
- `visitCompFor` (约 1099 行)

### 在 `include/script_interpreter.h` 和 `src/script_interpreter.cpp` 中删除：
- 对应的委托方法

## 需要修改的调用

1. **条件表达式**：在 `visitExpression` 中直接处理 `conditionalExpression`
2. **位运算符**：在 `visitComparison` 和 `visitLogicalAnd` 中直接处理（已修复）
3. **元组字面量**：在 `visitPrimary` 中直接处理
4. **推导式**：在 `visitListElements` 等中直接处理

## 下一步

1. 删除所有不存在的方法声明和实现
2. 修改调用这些方法的地方
3. 重新编译验证

## 最新修复（2024）

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
