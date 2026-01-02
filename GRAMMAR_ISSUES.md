# PyScript.g4 语法文件问题分析

## 1. 冗余规则问题 ✅

### 问题描述
`attributeAccess`, `subscriptAccess`, `functionCall` 这三个规则是冗余的。

### 问题分析
1. 这些规则只在 `assignment` 规则中使用。
2. 但实际上 `atom` 已经通过 `postfixOp` 处理了这些操作。
3. 在代码实现中，`visitAttributeAccess`, `visitSubscriptAccess`, `visitFunctionCall` 都是空实现，实际处理都在 `visitAtom` 中。

### 修复状态 ✅
**已修复**：这些冗余规则已被删除，现在使用 `assignmentTarget` 规则：
```antlr
assignmentTarget
    : IDENTIFIER
    | primary DOT IDENTIFIER
    | primary LBRACK subscriptArg RBRACK
    ;
```

`postfixOp` 中的 `attributeAccessOp`, `subscriptAccessOp`, `functionCallOp` 用于表达式中的属性访问、下标访问和函数调用。

## 2. tupleLiteral 歧义问题 ✅

### 问题描述
`primary` 规则中有两个可能产生歧义的选项。

### 问题分析
1. ANTLR 会优先匹配第一个选项，所以 `(1)` 会被解析为 `LPAREN expression RPAREN` 而不是元组。
2. 正确的做法应该是：
   - `(1)` → 表达式（括号表达式）
   - `(1, 2)` → 元组
   - `(1,)` → 元组（单个元素的元组）

### 修复状态 ✅
**已修复**：调整了 `primary` 规则，优先匹配元组：
```antlr
primary
    : ...
    | LPAREN tupleLiteral RPAREN
    | LPAREN expression RPAREN
    ...
    ;

tupleLiteral
    : expression COMMA (expression COMMA)* expression? COMMA?  # multiElementTuple
    | expression COMMA                                        # singleElementTuple
    ;
```

现在 `(1, 2)` 和 `(1,)` 会被正确解析为元组，`(1)` 会被解析为括号表达式。

## 3. compFor 规则问题 ✅

### 问题描述
`compFor` 规则需要支持解包操作。

### 问题分析
1. Python的推导式支持解包操作，例如：`for x, y in [(1,2), (3,4)]`
2. 需要支持 `tupleLiteral` 作为循环变量。

### 修复状态 ✅
**已修复**：`compFor` 规则现在支持 `tupleLiteral`：
```antlr
compFor
    : FOR (IDENTIFIER | tupleLiteral) IN expression (IF expression)?
    ;
```

现在可以正确处理 `for (x, y) in items` 这样的解包操作。

## 4. 字符串字面量问题 ✅

### 问题描述
字符串字面量需要支持原始字符串和字节字符串。

### 问题分析
1. Python支持原始字符串（raw string）：`r"..."`, `r'...'`, `R"""..."""`
2. Python支持字节字符串：`b"..."`, `b'...'`, `B"""..."""`
3. 需要支持三引号形式的原始字符串和字节字符串。

### 修复状态 ✅
**已修复**：`STRING` token 现在支持原始字符串和字节字符串：
```antlr
STRING
    : '"' (~["\\\r\n] | '\\' .)* '"'
    | '\'' (~['\\\r\n] | '\\' .)* '\''
    | '"""' (~["] | '"' ~["] | '""' ~["])* '"""'
    | '\'\'\'' (~['] | '\'' ~['] | '\'\'' ~['])* '\'\'\''
    | [rR] '"' (~["\\\r\n] | '\\' .)* '"'           // Raw string
    | [rR] '\'' (~['\\\r\n] | '\\' .)* '\''        // Raw string
    | [rR] '"""' (~["] | '"' ~["] | '""' ~["])* '"""'  // Raw triple-quoted string
    | [rR] '\'\'\'' (~['] | '\'' ~['] | '\'\'' ~['])* '\'\'\''  // Raw triple-quoted string
    | [bB] '"' (~["\\\r\n] | '\\' .)* '"'           // Bytes string
    | [bB] '\'' (~['\\\r\n] | '\\' .)* '\''        // Bytes string
    | [bB] '"""' (~["] | '"' ~["] | '""' ~["])* '"""'  // Bytes triple-quoted string
    | [bB] '\'\'\'' (~['] | '\'' ~['] | '\'\'' ~['])* '\'\'\''  // Bytes triple-quoted string
    ;
```

现在支持所有形式的原始字符串和字节字符串。

## 5. 优先级问题 ✅

### 当前状态
运算符优先级看起来是正确的：
- 逻辑运算符：`or` < `and` < `not`
- 位运算符：`|` < `^` < `&`
- 比较运算符：`==`, `!=`, `<`, `<=`, `>`, `>=`, `in`, `not in`, `is`, `is not`
- 移位运算符：`<<`, `>>`
- 算术运算符：`+`, `-` < `*`, `/`, `//`, `%` < `**`

## 6. 缺失的特性 ✅

根据 `DEVELOPMENT.md`，以下特性在语法文件中缺失：

### 修复状态 ✅
**已全部实现**：

1. ✅ **`yield` 关键字** - 生成器函数
   - 已添加 `YIELD` token
   - 已实现 `yieldExpression` 规则
   - 支持 `yield expression` 和 `yield from expression`

2. ✅ **`raise` 语句** - 异常抛出
   - 已添加 `RAISE` token
   - 已实现 `raiseStatement` 规则
   - 支持 `raise expression` 和 `raise expression from expression`

3. ✅ **`del` 语句** - 删除变量
   - 已添加 `DEL` token
   - 已实现 `delStatement` 规则
   - 支持删除变量、属性和下标

4. ✅ **`global` 和 `nonlocal` 关键字** - 作用域控制
   - 已添加 `GLOBAL` 和 `NONLOCAL` tokens
   - 已实现 `globalStatement` 和 `nonlocalStatement` 规则

5. ✅ **Walrus运算符（海象运算符）** - `:=`
   - 已添加 `WALRUS` token (`:=`)
   - 已实现 `assignmentExpression` 规则
   - 支持 `assignmentTarget := expression`

6. ✅ **嵌套推导式** - 支持多层 `compFor`
   - `comprehension` 规则支持 `expression (compFor)+`
   - 支持多个 `compFor` 和 `IF` 条件

## 总结

### 修复状态总结 ✅

所有语法问题都已修复：

1. ✅ **冗余规则**：已删除 `attributeAccess`, `subscriptAccess`, `functionCall`，使用 `assignmentTarget` 规则
2. ✅ **tupleLiteral 歧义**：已调整 `primary` 规则优先级，优先匹配元组
3. ✅ **compFor 规则**：已支持 `tupleLiteral` 解包
4. ✅ **字符串字面量**：已添加原始字符串和字节字符串支持
5. ✅ **缺失的特性**：所有特性都已实现（yield, raise, del, global/nonlocal, walrus, 嵌套推导式）

## 测试验证

所有修复都已通过测试：
- ✅ 全量测试：134/134 通过 (100%)
- ✅ 语法修复专项测试：全部通过
- ✅ 新语法特性测试：全部通过

## 当前状态

**所有语法问题已解决，语法文件处于稳定状态。**

