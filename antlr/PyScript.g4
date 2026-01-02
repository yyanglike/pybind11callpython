grammar PyScript;

options {
    language = Cpp;
}

tokens { INDENT, DEDENT }

@lexer::header {
#include "PyScriptParser.h"
}

@lexer::members {
    // Indentation stack
    std::vector<int> indents;
    // Parenthesis depth
    int opened = 0;
    // Pending tokens queue
    std::vector<std::unique_ptr<antlr4::Token>> pending;

    // Emit token to queue
    void emitToken(std::unique_ptr<antlr4::Token> t) {
        pending.push_back(std::move(t));
    }

    std::unique_ptr<antlr4::Token> nextToken() override {
        // Return queued tokens first
        if (!pending.empty()) {
            auto t = std::move(pending.front());
            pending.erase(pending.begin());
            return t;
        }

        auto next = Lexer::nextToken();

        // At EOF, emit pending DEDENTS
        if (next->getType() == EOF && !indents.empty()) {
            while (!indents.empty()) {
                emitToken(std::make_unique<antlr4::CommonToken>(PyScriptParser::DEDENT));
                indents.pop_back();
            }
            emitToken(std::make_unique<antlr4::CommonToken>(EOF));
            auto t = std::move(pending.front());
            pending.erase(pending.begin());
            return t;
        }

        return next;
    }

    // Calculate indentation length (tabs as 8 spaces)
    int indentationCount(const std::string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '\t') {
                count += 8 - (count % 8);
            } else {
                count++;
            }
        }
        return count;
    }
}

/* =========================
 * Program
 * ========================= */

program
    : statement* EOF
    ;

/* =========================
 * Statements
 * ========================= */

statement
    : simpleStatement
    | compoundStatement
    ;

simpleStatement
    : smallStatement (SEMI smallStatement)* SEMI? NEWLINE?
    ;

smallStatement
    : assignment
    | returnStatement
    | expressionStatement
    | importStatement
    | passStatement
    | BREAK
    | CONTINUE
    ;

compoundStatement
    : decoratedDef
    | functionDef
    | asyncFunctionDef
    | classDef
    | ifStatement
    | whileStatement
    | forStatement
    | asyncForStatement
    | tryStatement
    | withStatement
    | asyncWithStatement
    ;

/* =========================
 * Try-Except 语句
 * ========================= */

tryStatement
    : TRY COLON suite
      (exceptClause)*
      (ELSE COLON suite)?
      (FINALLY COLON suite)?
    ;

exceptClause
    : EXCEPT (dottedName (AS IDENTIFIER)?)? COLON suite
    ;

/* =========================
 * With 语句
 * ========================= */

withStatement
    : WITH withItem (COMMA withItem)* COLON suite
    ;

withItem
    : expression (AS IDENTIFIER)?
    ;

/* =========================
 * Async/await 扩展（同步执行，语义等同非 async）
 * ========================= */

asyncFunctionDef
    : ASYNC functionDef
    ;

asyncForStatement
    : ASYNC forStatement
    ;

asyncWithStatement
    : ASYNC withStatement
    ;

awaitExpr
    : AWAIT expression
    ;

classDef
    : CLASS IDENTIFIER (LPAREN expression (COMMA expression)* COMMA? RPAREN)? (decorators)? COLON suite
    ;

decoratedDef
    : decorators (functionDef | classDef)
    ;

decorators
    : decorator+
    ;

decorator
    : AT expression NEWLINE
    ;

/* =========================
 * Suite (缩进代码块)
 * ========================= */

suite
    : simpleStatement
    | NEWLINE INDENT statement+ DEDENT
    ;

/* =========================
 * 函数定义
 * ========================= */

functionDef
    : DEF IDENTIFIER LPAREN parameterList? RPAREN COLON suite
    ;

parameterList
    : parameter (COMMA parameter)* COMMA?
    ;

parameter
    : IDENTIFIER (ASSIGN expression)?
    | MUL IDENTIFIER?
    | DOUBLE_STAR IDENTIFIER
    ;

/* =========================
 * 控制流 (Python风格)
 * ========================= */

ifStatement
    : IF expression COLON suite
      (ELIF expression COLON suite)*
      (ELSE COLON suite)?
    ;

whileStatement
    : WHILE expression COLON suite
    ;

forStatement
    : FOR IDENTIFIER IN expression COLON suite
    ;

/* =========================
 * 简单语句
 * ========================= */

passStatement
    : PASS
    ;


returnStatement
    : RETURN expression?
    ;

importStatement
    : IMPORT dottedName (AS IDENTIFIER)?                    # simpleImport
    | FROM dottedName IMPORT importItem (COMMA importItem)* # fromImport
    ;

importItem
    : IDENTIFIER (AS IDENTIFIER)?
    ;

assignment
    : (IDENTIFIER | attributeAccess | subscriptAccess) (ASSIGN | PLUS_ASSIGN | MINUS_ASSIGN | MUL_ASSIGN | DIV_ASSIGN | FLOOR_DIV_ASSIGN | MOD_ASSIGN | POW_ASSIGN | BITWISE_AND_ASSIGN | BITWISE_OR_ASSIGN | BITWISE_XOR_ASSIGN | LEFT_SHIFT_ASSIGN | RIGHT_SHIFT_ASSIGN) expression
    ;

expressionStatement
    : expression
    ;

/* =========================
 * 表达式 (类Python)
 * ========================= */

expression
    : conditionalExpression # conditionalExpr
    ;

conditionalExpression
    : logicalOr (IF logicalOr ELSE conditionalExpression)? # conditional
    ;

logicalOr
    : logicalAnd (OR logicalAnd)*
    ;

logicalAnd
    : bitwiseOr (AND bitwiseOr)*
    ;

bitwiseOr
    : bitwiseXor (BITWISE_OR bitwiseXor)* # bitwiseOrExpr
    ;

bitwiseXor
    : bitwiseAnd (BITWISE_XOR bitwiseAnd)* # bitwiseXorExpr
    ;

bitwiseAnd
    : equality (BITWISE_AND equality)* # bitwiseAndExpr
    ;

equality
    : comparison ((EQ | NE) comparison)*
    ;

comparison
    : shift ((LT | LE | GT | GE | IN | NOT_IN | IS | IS_NOT) shift)*
    ;

shift
    : additive ((LEFT_SHIFT | RIGHT_SHIFT) additive)* # shiftExpr
    ;

additive
    : multiplicative ((PLUS | MINUS) multiplicative)*
    ;

multiplicative
    : power ((MUL | DIV | FLOOR_DIV | MOD) power)*
    ;

power
    : unary (DOUBLE_STAR power)?
    ;

unary
    : (NOT | PLUS | MINUS | BITWISE_NOT)? atom
    | awaitExpr
    ;

/* =========================
 * 调用 / 属性 / 主表达式
 * ========================= */

primary
    : literal
    | IDENTIFIER
    | LPAREN expression RPAREN
    | LPAREN tupleLiteral RPAREN
    | listLiteral
    | dictLiteral
    | setLiteral
    | generatorExpression
    | newExpression
    | lambdaExpression
    | awaitExpr
    ;

tupleLiteral
    : expression (COMMA expression)* COMMA? # tuple
    ;

newExpression
    : NEW dottedName LPAREN argumentList? RPAREN
    ;

atom
    : primary (postfixOp)*
    ;

postfixOp
    : DOT IDENTIFIER                 # attributeAccessOp
    | LBRACK subscriptArg RBRACK     # subscriptAccessOp  
    | LPAREN argumentList? RPAREN    # functionCallOp
    ;

// 辅助规则用于赋值目标
attributeAccess
    : atom DOT IDENTIFIER
    ;

subscriptAccess
    : atom LBRACK subscriptArg RBRACK
    ;

subscriptArg
    : expression? (COLON expression? (COLON expression?)?)?
    ;

functionCall
    : atom LPAREN argumentList? RPAREN
    ;

argumentList
    : argument (COMMA argument)* COMMA?
    ;

argument
    : IDENTIFIER ASSIGN expression  // 关键字参数
    | expression                     // 位置参数
    | MUL expression                // 可变位置参数
    | DOUBLE_STAR expression        // 可变关键字参数
    ;

/* =========================
 * 字面量
 * ========================= */

listLiteral
    : LBRACK (listElements)? RBRACK
    ;

listElements
    : expression (COMMA expression)* COMMA?
    | comprehension
    ;

comprehension
    : expression (compFor)+
    ;

compFor
    : FOR IDENTIFIER (COMMA IDENTIFIER)* IN expression (IF expression)?
    ;

dictLiteral
    : LBRACE (dictComprehension | (dictItem (COMMA dictItem)* COMMA?)?) RBRACE
    ;

dictComprehension
    : expression COLON expression (compFor)+
    ;

dictItem
    : expression COLON expression
    | DOUBLE_STAR expression
    ;

setLiteral
    : LBRACE (setElements)? RBRACE
    ;

setElements
    : expression (COMMA expression)* COMMA?
    | comprehension
    ;

generatorExpression
    : LPAREN comprehension RPAREN
    ;

literal
    : INTEGER
    | FLOAT
    | STRING
    | TRUE
    | FALSE
    | NONE
    ;

/* =========================
 * Lambda表达式
 * ========================= */

lambdaExpression
    : LAMBDA parameterList? COLON expression
    ;

/* =========================
 * 辅助规则
 * ========================= */

dottedName
    : IDENTIFIER (DOT IDENTIFIER)*
    ;

/* =========================
 * 关键词
 * ========================= */

DEF     : 'def';
IF      : 'if';
ELSE    : 'else';
ELIF    : 'elif';
FOR     : 'for';
WHILE   : 'while';
RETURN  : 'return';
IMPORT  : 'import';
FROM    : 'from';
AS      : 'as';
IN      : 'in';
PASS    : 'pass';
BREAK   : 'break';
CONTINUE: 'continue';
NEW     : 'new';
LAMBDA  : 'lambda';

TRY     : 'try';
EXCEPT  : 'except';
FINALLY : 'finally';
WITH    : 'with';
ASYNC   : 'async';
AWAIT   : 'await';
CLASS   : 'class';
AT      : '@';

TRUE    : 'true';
FALSE   : 'false';
NONE    : 'none';

AND     : 'and';
OR      : 'or';
NOT     : 'not';

IS      : 'is';
IS_NOT  : 'is not';
NOT_IN  : 'not in';

/* =========================
 * 操作符 / 分隔符
 * ========================= */

PLUS    : '+';
MINUS   : '-';
MUL     : '*';
DIV     : '/';
FLOOR_DIV : '//';
MOD     : '%';

EQ      : '==';
NE      : '!=';
LT      : '<';
LE      : '<=';
GT      : '>';
GE      : '>=';

LEFT_SHIFT  : '<<';
RIGHT_SHIFT : '>>';
BITWISE_AND : '&';
BITWISE_OR  : '|';
BITWISE_XOR : '^';
BITWISE_NOT : '~';

ASSIGN  : '=';
PLUS_ASSIGN    : '+=';
MINUS_ASSIGN   : '-=';
MUL_ASSIGN     : '*=';
DIV_ASSIGN     : '/=';
FLOOR_DIV_ASSIGN : '//=';
MOD_ASSIGN     : '%=';
POW_ASSIGN     : '**=';
BITWISE_AND_ASSIGN : '&=';
BITWISE_OR_ASSIGN  : '|=';
BITWISE_XOR_ASSIGN : '^=';
LEFT_SHIFT_ASSIGN  : '<<=';
RIGHT_SHIFT_ASSIGN : '>>=';
SEMI    : ';';

LPAREN  : '(' { opened++; };
RPAREN  : ')' { opened--; };
LBRACK  : '[' { opened++; };
RBRACK  : ']' { opened--; };
LBRACE  : '{' { opened++; };
RBRACE  : '}' { opened--; };

COMMA   : ',';
COLON   : ':';
DOT     : '.';
DOUBLE_STAR : '**';

/* =========================
 * 换行符 / 缩进处理
 * ========================= */

NEWLINE
    : '\r'? '\n' [ \t]*
      {
        // 如果在括号内，则忽略缩进
        if (opened > 0) {
            skip();
        } else {
            // 提取缩进部分（换行后的空格/制表符）
            std::string text = getText();
            size_t lastNewline = text.find_last_of('\n');
            std::string spaces = (lastNewline == std::string::npos) ? text : text.substr(lastNewline + 1);
            int indent = indentationCount(spaces);
            int prev = indents.empty() ? 0 : indents.back();

            if (indent > prev) {
                // 增加缩进
                indents.push_back(indent);
                emitToken(std::make_unique<antlr4::CommonToken>(PyScriptParser::INDENT));
            } else if (indent < prev) {
                // 减少缩进，可能需要多个DEDENT
                while (!indents.empty() && indents.back() > indent) {
                    emitToken(std::make_unique<antlr4::CommonToken>(PyScriptParser::DEDENT));
                    indents.pop_back();
                }
            }
            // 如果缩进相同，则不需要INDENT/DEDENT，跳过空格
        }
      }
    ;

/* =========================
 * 标识符和字面量
 * ========================= */

IDENTIFIER
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;

INTEGER
    : [0-9]+
    ;

FLOAT
    : [0-9]+ '.' [0-9]+
    | '.' [0-9]+
    ;

STRING
    : '"' (~["\\\r\n] | '\\' .)* '"'
    | '\'' (~['\\\r\n] | '\\' .)* '\''
    | '"""' (~["] | '"' ~["] | '""' ~["])* '"""'
    | '\'\'\'' (~['] | '\'' ~['] | '\'\'' ~['])* '\'\'\''
    ;

/* =========================
 * 空白和注释
 * ========================= */

WS
    : [ \t]+ -> skip
    ;

COMMENT
    : '#' ~[\r\n]* -> skip
    ;
