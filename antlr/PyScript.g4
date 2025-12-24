grammar PyScript;

/* =======================
 * Program
 * ======================= */

program
    : statement+ EOF
    ;

/* =======================
 * Statements
 * ======================= */

statement
    : importStatement
    | functionDefinition
    | assignment
    | ifStatement
    | whileStatement
    | forStatement
    | returnStatement
    | expressionStatement
    ;

/* =======================
 * Import
 * ======================= */

importStatement
    : IMPORT dottedName (AS IDENTIFIER)? SEMI?
    ;

/* =======================
 * Function Definition
 * ======================= */

functionDefinition
    : DEF IDENTIFIER LPAREN parameterList? RPAREN block
    ;

parameterList
    : parameter (COMMA parameter)*
    ;

parameter
    : IDENTIFIER (ASSIGN expression)?
    | MUL IDENTIFIER?
    | DOUBLE_STAR IDENTIFIER
    ;

/* =======================
 * Control Flow
 * ======================= */

ifStatement
    : IF LPAREN expression RPAREN block (ELSE block)?
    ;

whileStatement
    : WHILE LPAREN expression RPAREN block
    ;

forStatement
    : FOR LPAREN forControl RPAREN block
    ;

forControl
    : forInit? SEMI expression? SEMI forUpdate?
    ;

forInit
    : assignment
    ;

forUpdate
    : assignment
    ;

returnStatement
    : RETURN expression? SEMI?
    ;

block
    : LBRACE statement* RBRACE
    ;

/* =======================
 * Assignment
 * ======================= */

assignment
    : IDENTIFIER assignmentOperator expression SEMI?
    | attributeAccess ASSIGN expression SEMI?
    | subscriptAccess ASSIGN expression SEMI?
    ;

assignmentOperator
    : ASSIGN | PLUS_ASSIGN | MINUS_ASSIGN | MUL_ASSIGN | DIV_ASSIGN | MOD_ASSIGN
    ;

/* =======================
 * Expression Statement
 * ======================= */

expressionStatement
    : expression SEMI?
    ;

/* =======================
 * Expressions
 * ======================= */

expression
    : assignment
    | ternaryExpression
    ;

/* --- Ternary / Python Conditional Expression --- */

ternaryExpression
    : logicalOrExpression (IF logicalOrExpression ELSE ternaryExpression)?
    | logicalOrExpression (QUESTION expression COLON ternaryExpression)?
    ;

/* --- Non-assignment expression for positional arguments --- */

nonAssignmentExpression
    : ternaryExpression
    ;

/* --- Logical --- */

logicalOrExpression
    : logicalAndExpression (OR logicalAndExpression)*
    ;

logicalAndExpression
    : equalityExpression (AND equalityExpression)*
    ;

/* --- Equality --- */

equalityExpression
    : relationalExpression ((EQ | NE) relationalExpression)*
    ;

/* --- Relational --- */

relationalExpression
    : additiveExpression ((LT | GT | LE | GE) additiveExpression)*
    ;

/* --- Arithmetic --- */

additiveExpression
    : multiplicativeExpression ((PLUS | MINUS) multiplicativeExpression)*
    ;

multiplicativeExpression
    : unaryExpression ((MUL | DIV | MOD) unaryExpression)*
    ;

/* --- Unary --- */

unaryExpression
    : (NOT | MINUS)? powerExpression
    ;

/* --- Power (right associative) --- */

powerExpression
    : callOrPrimary (DOUBLE_STAR powerExpression)?
    ;

/* =======================
 * Call / Access
 * ======================= */

callOrPrimary
    : primaryExpression (postfixOp)*
    ;

postfixOp
    : DOT IDENTIFIER                 # attributeAccessOp
    | LBRACK expression RBRACK       # subscriptAccessOp
    | LPAREN argumentList? RPAREN    # functionCallOp
    ;

// 辅助规则用于赋值目标
attributeAccess
    : primaryExpression DOT IDENTIFIER
    ;

subscriptAccess
    : primaryExpression LBRACK expression RBRACK
    ;

functionCall
    : (dottedName | attributeAccess | subscriptAccess | LPAREN expression RPAREN) LPAREN argumentList? RPAREN
    ;

/* =======================
 * Primary Expressions
 * ======================= */

primaryExpression
    : literal
    | dottedName
    | LPAREN expression RPAREN
    | listLiteral
    | dictLiteral
    | newExpression
    | lambdaExpression
    | listComprehension
    ;

/* --- new --- */

newExpression
    : NEW dottedName LPAREN argumentList? RPAREN
    ;

/* =======================
 * Literals
 * ======================= */

literal
    : INTEGER
    | FLOAT
    | STRING
    | BOOL
    | NULL_LIT
    ;

listLiteral
    : LBRACK expressionList? RBRACK
    ;

dictLiteral
    : LBRACE dictItemList? RBRACE
    ;

/* =======================
 * Comprehensions
 * ======================= */

listComprehension
    : LBRACK expression FOR IDENTIFIER IN expression RBRACK
    ;

/* =======================
 * Helpers
 * ======================= */

lambdaExpression
    : LAMBDA ( IDENTIFIER (COMMA IDENTIFIER)* )? COLON expression
    ;

dottedName
    : IDENTIFIER (DOT IDENTIFIER)*
    ;

argumentList
    : argument (COMMA argument)*
    ;

argument
    : IDENTIFIER ASSIGN expression           # keywordArgument  
    | nonAssignmentExpression                # positionalArgument
    | MUL expression                         # starArgument
    | DOUBLE_STAR expression                 # doubleStarArgument
    ;

expressionList
    : expression (COMMA expression)*
    ;

dictItemList
    : dictItem (COMMA dictItem)*
    ;

dictItem
    : expression COLON expression  # keyValuePair
    | DOUBLE_STAR expression       # dictUnpack
    ;

/* =======================
 * Lexer
 * ======================= */

// 首先定义操作符和标点符号
SEMI: ';';
COMMA: ',';
DOT: '.';
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';

ASSIGN: '=';
PLUS_ASSIGN: '+=';
MINUS_ASSIGN: '-=';
MUL_ASSIGN: '*=';
DIV_ASSIGN: '/=';
MOD_ASSIGN: '%=';

EQ: '==';
NE: '!=';
LT: '<';
LE: '<=';
GT: '>';
GE: '>=';

PLUS: '+';
MINUS: '-';
MUL: '*';
DIV: '/';
MOD: '%';

NOT: '!';
AND: '&&';
OR: '||';
QUESTION: '?';
COLON: ':';
DOUBLE_STAR: '**';

// 关键字必须放在IDENTIFIER之前，以确保优先匹配
RETURN : 'return';
IF : 'if';
ELSE : 'else';
WHILE : 'while';
FOR : 'for';
DEF : 'def';
IMPORT : 'import';
AS : 'as';
NEW : 'new';
LAMBDA : 'lambda';
IN : 'in';

IDENTIFIER
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;

INTEGER
    : [0-9]+
    ;

FLOAT
    : [0-9]+ '.' [0-9]*
    | '.' [0-9]+
    ;

STRING
    : '"' (~["\\\r\n] | '\\' .)* '"'
    | '\'' (~['\\\r\n] | '\\' .)* '\''
    ;

BOOL
    : 'true' | 'false'
    ;

NULL_LIT
    : 'null'
    ;

WS
    : [ \t\r\n]+ -> skip
    ;

COMMENT
    : ('//' | '#') ~[\r\n]* -> skip
    ;

MULTILINE_COMMENT
    : '/*' .*? '*/' -> skip
    ;
