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
    : 'import' dottedName ('as' IDENTIFIER)? ';'?
    ;

/* =======================
 * Function Definition
 * ======================= */

functionDefinition
    : 'def' IDENTIFIER '(' parameterList? ')' block
    ;

parameterList
    : IDENTIFIER (',' IDENTIFIER)*
    ;

/* =======================
 * Control Flow
 * ======================= */

ifStatement
    : 'if' '(' expression ')' block ('else' block)?
    ;

whileStatement
    : 'while' '(' expression ')' block
    ;

forStatement
    : 'for' '(' forControl ')' block
    ;

forControl
    : forInit? ';' expression? ';' forUpdate?
    ;

forInit
    : assignment
    ;

forUpdate
    : assignment
    ;

returnStatement
    : 'return' expression? ';'?
    ;

block
    : '{' statement* '}'
    ;

/* =======================
 * Assignment
 * ======================= */

assignment
    : IDENTIFIER assignmentOperator expression ';'?
    | attributeAccess '=' expression ';'?
    | subscriptAccess '=' expression ';'?
    ;

assignmentOperator
    : '=' | '+=' | '-=' | '*=' | '/=' | '%='
    ;

/* =======================
 * Expression Statement
 * ======================= */

expressionStatement
    : expression ';'?
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
    : logicalOrExpression ('if' logicalOrExpression 'else' ternaryExpression)?
    | logicalOrExpression ('?' expression ':' ternaryExpression)?
    ;

/* --- Logical --- */

logicalOrExpression
    : logicalAndExpression ('||' logicalAndExpression)*
    ;

logicalAndExpression
    : equalityExpression ('&&' equalityExpression)*
    ;

/* --- Equality --- */

equalityExpression
    : relationalExpression (('==' | '!=') relationalExpression)*
    ;

/* --- Relational --- */

relationalExpression
    : additiveExpression (('<' | '>' | '<=' | '>=') additiveExpression)*
    ;

/* --- Arithmetic --- */

additiveExpression
    : multiplicativeExpression (('+' | '-') multiplicativeExpression)*
    ;

multiplicativeExpression
    : unaryExpression (('*' | '/' | '%') unaryExpression)*
    ;

/* --- Unary --- */

unaryExpression
    : ('!' | '-')? callOrPrimary
    ;

/* =======================
 * Call / Access
 * ======================= */

callOrPrimary
    : primaryExpression (postfixOp)*
    ;

postfixOp
    : '.' IDENTIFIER                 # attributeAccessOp
    | '[' expression ']'             # subscriptAccessOp
    | '(' argumentList? ')'          # functionCallOp
    ;

// 辅助规则用于赋值目标
attributeAccess
    : primaryExpression '.' IDENTIFIER
    ;

subscriptAccess
    : primaryExpression '[' expression ']'
    ;

functionCall
    : (dottedName | attributeAccess | subscriptAccess | '(' expression ')') '(' argumentList? ')'
    ;

/* =======================
 * Primary Expressions
 * ======================= */

primaryExpression
    : literal
    | dottedName
    | '(' expression ')'
    | listLiteral
    | dictLiteral
    | newExpression
    | lambdaExpression
    | listComprehension
    ;

/* --- new --- */

newExpression
    : 'new' dottedName '(' argumentList? ')'
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
    : '[' expressionList? ']'
    ;

dictLiteral
    : '{' dictItemList? '}'
    ;

/* =======================
 * Comprehensions
 * ======================= */

listComprehension
    : '[' expression 'for' IDENTIFIER 'in' expression ']'
    ;

/* =======================
 * Helpers
 * ======================= */

lambdaExpression
    : 'lambda' ( IDENTIFIER (',' IDENTIFIER)* )? ':' expression
    ;

dottedName
    : IDENTIFIER ('.' IDENTIFIER)*
    ;

argumentList
    : expression (',' expression)*
    ;

expressionList
    : expression (',' expression)*
    ;

dictItemList
    : dictItem (',' dictItem)*
    ;

dictItem
    : expression ':' expression  # keyValuePair
    | '**' expression            # dictUnpack
    ;

/* =======================
 * Lexer
 * ======================= */

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
    : '//' ~[\r\n]* -> skip
    ;

MULTILINE_COMMENT
    : '/*' .*? '*/' -> skip
    ;
