# PyScript语法文件问题分析和增强建议

## 当前状态分析

### ✅ 已实现但语法文件缺少的运算符

以下运算符在 `ExpressionEvaluator` 中已实现，但语法文件中缺少token定义：

1. **`//` (FLOOR_DIV)** - 向下取整除法
   - 实现位置：`src/expression_evaluator.cpp:59`
   - 语法文件状态：❌ 缺少token定义
   - 影响：无法在语法层面识别 `//` 运算符

2. **`&` (BITWISE_AND)** - 按位与
   - 实现位置：`src/expression_evaluator.cpp:75`
   - 语法文件状态：❌ 缺少token定义
   - 影响：与 `MUL` 冲突（`*` 用于解包）

3. **`|` (BITWISE_OR)** - 按位或
   - 实现位置：`src/expression_evaluator.cpp:82`
   - 语法文件状态：❌ 缺少token定义
   - 影响：无法识别按位或运算符

4. **`^` (BITWISE_XOR)** - 按位异或
   - 实现位置：`src/expression_evaluator.cpp:89`
   - 语法文件状态：❌ 缺少token定义
   - 影响：无法识别按位异或运算符

5. **`<<` (LEFT_SHIFT)** - 左移
   - 实现位置：`src/expression_evaluator.cpp:96`
   - 语法文件状态：❌ 缺少token定义
   - 影响：无法识别左移运算符

6. **`>>` (RIGHT_SHIFT)** - 右移
   - 实现位置：`src/expression_evaluator.cpp:103`
   - 语法文件状态：❌ 缺少token定义
   - 影响：无法识别右移运算符

7. **`~` (BITWISE_NOT)** - 按位取反（一元）
   - 实现位置：`src/expression_evaluator.cpp:342`
   - 语法文件状态：❌ 缺少token定义
   - 影响：无法识别按位取反运算符

### ❌ 完全缺失的Python特性

1. **`is` 和 `is not` 运算符**
   - Python标准：`x is y`, `x is not y`
   - 当前状态：❌ 完全缺失
   - 优先级：应该高于比较运算符，低于 `not in`

2. **`not in` 运算符**
   - Python标准：`x not in y`
   - 当前状态：❌ 只有 `in`，没有 `not in`
   - 影响：无法表达 `x not in list`

3. **`elif` 关键字**
   - Python标准：`elif condition:`
   - 当前状态：使用 `ELSE IF` 代替
   - 影响：不符合Python习惯，但功能可用

4. **`break` 和 `continue` 语句**
   - Python标准：循环控制语句
   - 当前状态：❌ 完全缺失
   - 影响：无法提前退出循环

5. **`yield` 关键字**
   - Python标准：生成器函数
   - 当前状态：❌ 完全缺失
   - 影响：无法定义生成器函数

6. **`raise` 语句**
   - Python标准：抛出异常
   - 当前状态：❌ 完全缺失
   - 影响：无法在脚本中抛出异常

7. **`del` 语句**
   - Python标准：删除变量或元素
   - 当前状态：❌ 完全缺失
   - 影响：无法删除变量或字典/列表元素

8. **`global` 和 `nonlocal` 关键字**
   - Python标准：作用域控制
   - 当前状态：❌ 完全缺失
   - 影响：函数内无法修改全局变量

9. **赋值运算符**
   - Python标准：`+=`, `-=`, `*=`, `/=`, `%=`, `//=`, `**=`, `&=`, `|=`, `^=`, `<<=`, `>>=`
   - 当前状态：❌ 完全缺失
   - 影响：无法使用 `x += 1` 这样的语法

10. **三引号字符串**
    - Python标准：`"""..."""` 或 `'''...'''`
    - 当前状态：❌ 只支持单引号和双引号
    - 影响：无法定义多行字符串字面量

11. **嵌套推导式**
    - Python标准：`[x*y for x in range(3) for y in range(2)]`
    - 当前状态：❌ 只支持单层for循环
    - 影响：无法使用嵌套循环的推导式

12. **元组字面量**
    - Python标准：`(1, 2, 3)` 或 `1, 2, 3`
    - 当前状态：❌ 完全缺失
    - 影响：无法创建元组

13. **切片赋值**
    - Python标准：`list[1:3] = [10, 20]`
    - 当前状态：❌ 不支持切片赋值
    - 影响：无法批量修改列表元素

14. **条件表达式（三元运算符）**
    - Python标准：`x if condition else y`
    - 当前状态：❌ 完全缺失
    - 影响：无法使用三元运算符

15. **Walrus运算符（海象运算符）**
    - Python标准：`:=` (Python 3.8+)
    - 当前状态：❌ 完全缺失
    - 影响：无法在表达式中赋值

## 优先级问题

### 运算符优先级不完整

当前语法文件的运算符优先级可能不完整：

1. **位运算符优先级**：`&`, `^`, `|` 应该在逻辑运算符之前
2. **`is`/`is not`优先级**：应该在比较运算符之后，逻辑运算符之前
3. **`not in`优先级**：应该与 `in` 相同

## 语法结构问题

### 1. if语句结构

当前：
```antlr
ifStatement
    : IF expression COLON suite
      (ELSE IF expression COLON suite)*
      (ELSE COLON suite)?
    ;
```

问题：使用 `ELSE IF` 而不是 `ELIF`，不符合Python习惯。

### 2. 推导式结构

当前：
```antlr
listElements
    : expression (COMMA expression)* COMMA?
    | expression FOR IDENTIFIER IN expression (IF expression)?
    ;
```

问题：
- 只支持单层for循环
- 不支持嵌套for循环：`[x*y for x in range(3) for y in range(2)]`
- 不支持多个if条件

### 3. 字符串字面量

当前：
```antlr
STRING
    : '"' (~["\\\r\n] | '\\' .)* '"'
    | '\'' (~['\\\r\n] | '\\' .)* '\''
    ;
```

问题：
- 不支持三引号：`"""..."""` 或 `'''...'''`
- 不支持原始字符串：`r"..."` 或 `R"..."`
- 不支持字节字符串：`b"..."` 或 `B"..."`

## 建议的增强方案

### 高优先级（立即修复）

1. **添加缺失的运算符token**
   - `FLOOR_DIV : '//';`
   - `BITWISE_AND : '&';`
   - `BITWISE_OR : '|';`
   - `BITWISE_XOR : '^';`
   - `LEFT_SHIFT : '<<';`
   - `RIGHT_SHIFT : '>>';`
   - `BITWISE_NOT : '~';`

2. **添加 `is` 和 `is not` 运算符**
   - `IS : 'is';`
   - `IS_NOT : 'is not';`

3. **添加 `not in` 运算符**
   - `NOT_IN : 'not in';`

4. **添加 `elif` 关键字**
   - `ELIF : 'elif';`
   - 修改if语句使用 `ELIF` 而不是 `ELSE IF`

### 中优先级（功能增强）

5. **添加 `break` 和 `continue`**
   - `BREAK : 'break';`
   - `CONTINUE : 'continue';`
   - 添加到 `smallStatement`

6. **添加赋值运算符**
   - `PLUS_ASSIGN : '+=';`
   - `MINUS_ASSIGN : '-=';`
   - `MUL_ASSIGN : '*=';`
   - `DIV_ASSIGN : '/=';`
   - `MOD_ASSIGN : '%=';`
   - `FLOOR_DIV_ASSIGN : '//=';`
   - `POW_ASSIGN : '**=';`
   - `BITWISE_AND_ASSIGN : '&=';`
   - `BITWISE_OR_ASSIGN : '|=';`
   - `BITWISE_XOR_ASSIGN : '^=';`
   - `LEFT_SHIFT_ASSIGN : '<<=';`
   - `RIGHT_SHIFT_ASSIGN : '>>=';`

7. **添加三引号字符串支持**
   - 扩展 `STRING` 规则支持 `"""` 和 `'''`

8. **添加嵌套推导式支持**
   - 修改推导式规则支持多个 `for` 和 `if` 子句

### 低优先级（可选增强）

9. **添加 `yield` 关键字**
   - `YIELD : 'yield';`
   - 添加到表达式或语句

10. **添加 `raise` 语句**
    - `RAISE : 'raise';`
    - `raiseStatement : RAISE expression?;`

11. **添加 `del` 语句**
    - `DEL : 'del';`
    - `delStatement : DEL (IDENTIFIER | attributeAccess | subscriptAccess) (COMMA (IDENTIFIER | attributeAccess | subscriptAccess))*;`

12. **添加 `global` 和 `nonlocal`**
    - `GLOBAL : 'global';`
    - `NONLOCAL : 'nonlocal';`
    - `globalStatement : GLOBAL IDENTIFIER (COMMA IDENTIFIER)*;`
    - `nonlocalStatement : NONLOCAL IDENTIFIER (COMMA IDENTIFIER)*;`

13. **添加条件表达式（三元运算符）**
    - `conditionalExpression : expression IF expression ELSE expression;`

14. **添加元组字面量**
    - `tupleLiteral : LPAREN (expression (COMMA expression)* COMMA?)? RPAREN;`

15. **添加Walrus运算符**
    - `WALRUS : ':=';`
    - 修改赋值规则支持 `:=`

## 实现优先级建议

### 第一阶段：修复已实现但语法缺失的功能
1. 添加位运算符和 `//` 的token定义
2. 更新表达式规则以支持这些运算符
3. 测试确保功能正常

### 第二阶段：添加常用Python特性
1. 添加 `is`/`is not` 和 `not in`
2. 添加 `elif` 关键字
3. 添加 `break`/`continue`
4. 添加赋值运算符

### 第三阶段：增强语法完整性
1. 添加三引号字符串
2. 添加嵌套推导式
3. 添加条件表达式
4. 添加元组字面量

### 第四阶段：高级特性（可选）
1. 添加 `yield`
2. 添加 `raise`
3. 添加 `del`
4. 添加 `global`/`nonlocal`
5. 添加Walrus运算符

## 测试建议

对于每个新增特性，应该：
1. 添加语法测试用例
2. 添加功能测试用例
3. 更新文档
4. 确保向后兼容

## 注意事项

1. **向后兼容性**：所有更改应该保持向后兼容
2. **优先级正确性**：确保运算符优先级符合Python标准
3. **错误处理**：新增特性应该有适当的错误处理
4. **性能影响**：新增特性不应该显著影响性能

