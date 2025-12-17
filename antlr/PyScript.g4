grammar PyScript;

// 程序由多个语句组成
program: statement+ EOF;

// 语句可以是导入、赋值、表达式等
statement
    : importStatement                     # importStmt
    | assignment                          # assignStmt
    | expressionStatement                 # exprStmt
    | ifStatement                         # ifStmt
    | whileStatement                      # whileStmt
    | returnStatement                     # returnStmt
    ;

// 导入语句
importStatement: 'import' IDENTIFIER ('.' IDENTIFIER)* ('as' IDENTIFIER)? ';'?;

// 赋值语句（包括普通赋值、属性赋值、下标赋值）
assignment
    : IDENTIFIER ('=' | '+=' | '-=' | '*=' | '/=' | '%=') ternaryExpression  # binaryAssignment
    | primaryExpression '.' IDENTIFIER '=' ternaryExpression                          # attributeAssignment
    | primaryExpression '[' expression ']' '=' ternaryExpression                      # subscriptAssignment
    ;

// 表达式语句
expressionStatement: expression ';'?;

// if语句 - 修改：block必须用大括号
ifStatement: 'if' '(' expression ')' block ('else' block)?;

// while循环
whileStatement: 'while' '(' expression ')' block;

// return语句
returnStatement: 'return' expression? ';'?;

// 代码块 - 修改：只允许大括号包围的块，不允许单条语句
block: '{' statement* '}';

// 表达式（顶层，包括赋值）
expression: ternaryExpression | assignment;

// 三元条件表达式
ternaryExpression
    : logicalOrExpression ('?' expression ':' ternaryExpression)?
    ;

// 逻辑或表达式
logicalOrExpression
    : logicalAndExpression ('||' logicalAndExpression)*
    ;

// 逻辑与表达式
logicalAndExpression
    : equalityExpression ('&&' equalityExpression)*
    ;

// 相等性表达式
equalityExpression
    : relationalExpression (('==' | '!=') relationalExpression)*
    ;

// 关系表达式
relationalExpression
    : additiveExpression (('<' | '>' | '<=' | '>=') additiveExpression)*
    ;

// 加减表达式
additiveExpression
    : multiplicativeExpression (('+' | '-') multiplicativeExpression)*
    ;

// 乘除取模表达式
multiplicativeExpression
    : unaryExpression (('*' | '/' | '%') unaryExpression)*
    ;

// 一元表达式
unaryExpression
    : ('!' | '-')? postfixExpression
    ;

// 基础表达式
primaryExpression
    : literal                                   # literalPrimary
    | IDENTIFIER                                # identifierPrimary
    | '(' expression ')'                        # parenPrimary
    | 'new' IDENTIFIER ('.' IDENTIFIER)* '(' argumentList? ')'  # newInstancePrimary
    ;

// 后缀表达式（函数调用、成员访问、下标）
postfixExpression
    : primaryExpression (postfixOperator)*
    ;

postfixOperator
    : '(' argumentList? ')'                     # functionCallPostfix
    | '.' IDENTIFIER                            # memberAccessPostfix
    | '[' expression ']'                        # subscriptPostfix
    ;

// 参数列表
argumentList: expression (',' expression)*;

// 字面量
literal
    : INTEGER          # integerLiteral
    | FLOAT            # floatLiteral
    | STRING           # stringLiteral
    | BOOL             # booleanLiteral
    | NULL_LIT         # nullLiteral
    | '[' expressionList? ']'   # listLiteral
    | '{' keyValuePairList? '}' # dictLiteral
    ;

// 表达式列表
expressionList: expression (',' expression)*;

// 键值对列表
keyValuePairList: keyValuePair (',' keyValuePair)*;
keyValuePair: expression ':' expression;

// 词法规则

// 标识符
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;

// 整数
INTEGER: [0-9]+;

// 浮点数
FLOAT: [0-9]+ '.' [0-9]* | '.' [0-9]+;

// 字符串
STRING: '"' (~["\\\r\n] | '\\' .)* '"'
      | '\'' (~['\\\r\n] | '\\' .)* '\'';

// 布尔值
BOOL: 'true' | 'false';

// 空值
NULL_LIT: 'null';

// 空白字符
WS: [ \t\r\n]+ -> skip;

// 注释
COMMENT: '//' ~[\r\n]* -> skip;
MULTILINE_COMMENT: '/*' .*? '*/' -> skip;
