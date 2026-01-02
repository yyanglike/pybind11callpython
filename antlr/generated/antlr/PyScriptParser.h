
// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  PyScriptParser : public antlr4::Parser {
public:
  enum {
    DEF = 1, IF = 2, ELSE = 3, ELIF = 4, FOR = 5, WHILE = 6, RETURN = 7, 
    IMPORT = 8, FROM = 9, AS = 10, IN = 11, PASS = 12, BREAK = 13, CONTINUE = 14, 
    NEW = 15, LAMBDA = 16, TRY = 17, EXCEPT = 18, FINALLY = 19, WITH = 20, 
    ASYNC = 21, AWAIT = 22, CLASS = 23, AT = 24, TRUE = 25, FALSE = 26, 
    NONE = 27, AND = 28, OR = 29, NOT = 30, IS = 31, IS_NOT = 32, NOT_IN = 33, 
    PLUS = 34, MINUS = 35, MUL = 36, DIV = 37, FLOOR_DIV = 38, MOD = 39, 
    EQ = 40, NE = 41, LT = 42, LE = 43, GT = 44, GE = 45, LEFT_SHIFT = 46, 
    RIGHT_SHIFT = 47, BITWISE_AND = 48, BITWISE_OR = 49, BITWISE_XOR = 50, 
    BITWISE_NOT = 51, ASSIGN = 52, PLUS_ASSIGN = 53, MINUS_ASSIGN = 54, 
    MUL_ASSIGN = 55, DIV_ASSIGN = 56, FLOOR_DIV_ASSIGN = 57, MOD_ASSIGN = 58, 
    POW_ASSIGN = 59, BITWISE_AND_ASSIGN = 60, BITWISE_OR_ASSIGN = 61, BITWISE_XOR_ASSIGN = 62, 
    LEFT_SHIFT_ASSIGN = 63, RIGHT_SHIFT_ASSIGN = 64, SEMI = 65, LPAREN = 66, 
    RPAREN = 67, LBRACK = 68, RBRACK = 69, LBRACE = 70, RBRACE = 71, COMMA = 72, 
    COLON = 73, DOT = 74, DOUBLE_STAR = 75, NEWLINE = 76, IDENTIFIER = 77, 
    INTEGER = 78, FLOAT = 79, STRING = 80, WS = 81, COMMENT = 82, INDENT = 83, 
    DEDENT = 84
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleSimpleStatement = 2, RuleSmallStatement = 3, 
    RuleCompoundStatement = 4, RuleTryStatement = 5, RuleExceptClause = 6, 
    RuleWithStatement = 7, RuleWithItem = 8, RuleAsyncFunctionDef = 9, RuleAsyncForStatement = 10, 
    RuleAsyncWithStatement = 11, RuleAwaitExpr = 12, RuleClassDef = 13, 
    RuleDecoratedDef = 14, RuleDecorators = 15, RuleDecorator = 16, RuleSuite = 17, 
    RuleFunctionDef = 18, RuleParameterList = 19, RuleParameter = 20, RuleIfStatement = 21, 
    RuleWhileStatement = 22, RuleForStatement = 23, RulePassStatement = 24, 
    RuleReturnStatement = 25, RuleImportStatement = 26, RuleImportItem = 27, 
    RuleAssignment = 28, RuleExpressionStatement = 29, RuleExpression = 30, 
    RuleConditionalExpression = 31, RuleLogicalOr = 32, RuleLogicalAnd = 33, 
    RuleBitwiseOr = 34, RuleBitwiseXor = 35, RuleBitwiseAnd = 36, RuleEquality = 37, 
    RuleComparison = 38, RuleShift = 39, RuleAdditive = 40, RuleMultiplicative = 41, 
    RulePower = 42, RuleUnary = 43, RulePrimary = 44, RuleTupleLiteral = 45, 
    RuleNewExpression = 46, RuleAtom = 47, RulePostfixOp = 48, RuleAttributeAccess = 49, 
    RuleSubscriptAccess = 50, RuleSubscriptArg = 51, RuleFunctionCall = 52, 
    RuleArgumentList = 53, RuleArgument = 54, RuleListLiteral = 55, RuleListElements = 56, 
    RuleComprehension = 57, RuleCompFor = 58, RuleDictLiteral = 59, RuleDictComprehension = 60, 
    RuleDictItem = 61, RuleSetLiteral = 62, RuleSetElements = 63, RuleGeneratorExpression = 64, 
    RuleLiteral = 65, RuleLambdaExpression = 66, RuleDottedName = 67
  };

  explicit PyScriptParser(antlr4::TokenStream *input);

  PyScriptParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~PyScriptParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class StatementContext;
  class SimpleStatementContext;
  class SmallStatementContext;
  class CompoundStatementContext;
  class TryStatementContext;
  class ExceptClauseContext;
  class WithStatementContext;
  class WithItemContext;
  class AsyncFunctionDefContext;
  class AsyncForStatementContext;
  class AsyncWithStatementContext;
  class AwaitExprContext;
  class ClassDefContext;
  class DecoratedDefContext;
  class DecoratorsContext;
  class DecoratorContext;
  class SuiteContext;
  class FunctionDefContext;
  class ParameterListContext;
  class ParameterContext;
  class IfStatementContext;
  class WhileStatementContext;
  class ForStatementContext;
  class PassStatementContext;
  class ReturnStatementContext;
  class ImportStatementContext;
  class ImportItemContext;
  class AssignmentContext;
  class ExpressionStatementContext;
  class ExpressionContext;
  class ConditionalExpressionContext;
  class LogicalOrContext;
  class LogicalAndContext;
  class BitwiseOrContext;
  class BitwiseXorContext;
  class BitwiseAndContext;
  class EqualityContext;
  class ComparisonContext;
  class ShiftContext;
  class AdditiveContext;
  class MultiplicativeContext;
  class PowerContext;
  class UnaryContext;
  class PrimaryContext;
  class TupleLiteralContext;
  class NewExpressionContext;
  class AtomContext;
  class PostfixOpContext;
  class AttributeAccessContext;
  class SubscriptAccessContext;
  class SubscriptArgContext;
  class FunctionCallContext;
  class ArgumentListContext;
  class ArgumentContext;
  class ListLiteralContext;
  class ListElementsContext;
  class ComprehensionContext;
  class CompForContext;
  class DictLiteralContext;
  class DictComprehensionContext;
  class DictItemContext;
  class SetLiteralContext;
  class SetElementsContext;
  class GeneratorExpressionContext;
  class LiteralContext;
  class LambdaExpressionContext;
  class DottedNameContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleStatementContext *simpleStatement();
    CompoundStatementContext *compoundStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  SimpleStatementContext : public antlr4::ParserRuleContext {
  public:
    SimpleStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SmallStatementContext *> smallStatement();
    SmallStatementContext* smallStatement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleStatementContext* simpleStatement();

  class  SmallStatementContext : public antlr4::ParserRuleContext {
  public:
    SmallStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentContext *assignment();
    ReturnStatementContext *returnStatement();
    ExpressionStatementContext *expressionStatement();
    ImportStatementContext *importStatement();
    PassStatementContext *passStatement();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *CONTINUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SmallStatementContext* smallStatement();

  class  CompoundStatementContext : public antlr4::ParserRuleContext {
  public:
    CompoundStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DecoratedDefContext *decoratedDef();
    FunctionDefContext *functionDef();
    AsyncFunctionDefContext *asyncFunctionDef();
    ClassDefContext *classDef();
    IfStatementContext *ifStatement();
    WhileStatementContext *whileStatement();
    ForStatementContext *forStatement();
    AsyncForStatementContext *asyncForStatement();
    TryStatementContext *tryStatement();
    WithStatementContext *withStatement();
    AsyncWithStatementContext *asyncWithStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompoundStatementContext* compoundStatement();

  class  TryStatementContext : public antlr4::ParserRuleContext {
  public:
    TryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRY();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<SuiteContext *> suite();
    SuiteContext* suite(size_t i);
    std::vector<ExceptClauseContext *> exceptClause();
    ExceptClauseContext* exceptClause(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *FINALLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TryStatementContext* tryStatement();

  class  ExceptClauseContext : public antlr4::ParserRuleContext {
  public:
    ExceptClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCEPT();
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();
    DottedNameContext *dottedName();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExceptClauseContext* exceptClause();

  class  WithStatementContext : public antlr4::ParserRuleContext {
  public:
    WithStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    std::vector<WithItemContext *> withItem();
    WithItemContext* withItem(size_t i);
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WithStatementContext* withStatement();

  class  WithItemContext : public antlr4::ParserRuleContext {
  public:
    WithItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WithItemContext* withItem();

  class  AsyncFunctionDefContext : public antlr4::ParserRuleContext {
  public:
    AsyncFunctionDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASYNC();
    FunctionDefContext *functionDef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AsyncFunctionDefContext* asyncFunctionDef();

  class  AsyncForStatementContext : public antlr4::ParserRuleContext {
  public:
    AsyncForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASYNC();
    ForStatementContext *forStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AsyncForStatementContext* asyncForStatement();

  class  AsyncWithStatementContext : public antlr4::ParserRuleContext {
  public:
    AsyncWithStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASYNC();
    WithStatementContext *withStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AsyncWithStatementContext* asyncWithStatement();

  class  AwaitExprContext : public antlr4::ParserRuleContext {
  public:
    AwaitExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AWAIT();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AwaitExprContext* awaitExpr();

  class  ClassDefContext : public antlr4::ParserRuleContext {
  public:
    ClassDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    DecoratorsContext *decorators();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDefContext* classDef();

  class  DecoratedDefContext : public antlr4::ParserRuleContext {
  public:
    DecoratedDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DecoratorsContext *decorators();
    FunctionDefContext *functionDef();
    ClassDefContext *classDef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DecoratedDefContext* decoratedDef();

  class  DecoratorsContext : public antlr4::ParserRuleContext {
  public:
    DecoratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DecoratorContext *> decorator();
    DecoratorContext* decorator(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DecoratorsContext* decorators();

  class  DecoratorContext : public antlr4::ParserRuleContext {
  public:
    DecoratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DecoratorContext* decorator();

  class  SuiteContext : public antlr4::ParserRuleContext {
  public:
    SuiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleStatementContext *simpleStatement();
    antlr4::tree::TerminalNode *NEWLINE();
    antlr4::tree::TerminalNode *INDENT();
    antlr4::tree::TerminalNode *DEDENT();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SuiteContext* suite();

  class  FunctionDefContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();
    ParameterListContext *parameterList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDefContext* functionDef();

  class  ParameterListContext : public antlr4::ParserRuleContext {
  public:
    ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterListContext* parameterList();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DOUBLE_STAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<SuiteContext *> suite();
    SuiteContext* suite(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELIF();
    antlr4::tree::TerminalNode* ELIF(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *IN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *COLON();
    SuiteContext *suite();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatementContext* forStatement();

  class  PassStatementContext : public antlr4::ParserRuleContext {
  public:
    PassStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PASS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PassStatementContext* passStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  ImportStatementContext : public antlr4::ParserRuleContext {
  public:
    ImportStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ImportStatementContext() = default;
    void copyFrom(ImportStatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FromImportContext : public ImportStatementContext {
  public:
    FromImportContext(ImportStatementContext *ctx);

    antlr4::tree::TerminalNode *FROM();
    DottedNameContext *dottedName();
    antlr4::tree::TerminalNode *IMPORT();
    std::vector<ImportItemContext *> importItem();
    ImportItemContext* importItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimpleImportContext : public ImportStatementContext {
  public:
    SimpleImportContext(ImportStatementContext *ctx);

    antlr4::tree::TerminalNode *IMPORT();
    DottedNameContext *dottedName();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ImportStatementContext* importStatement();

  class  ImportItemContext : public antlr4::ParserRuleContext {
  public:
    ImportItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportItemContext* importItem();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *PLUS_ASSIGN();
    antlr4::tree::TerminalNode *MINUS_ASSIGN();
    antlr4::tree::TerminalNode *MUL_ASSIGN();
    antlr4::tree::TerminalNode *DIV_ASSIGN();
    antlr4::tree::TerminalNode *FLOOR_DIV_ASSIGN();
    antlr4::tree::TerminalNode *MOD_ASSIGN();
    antlr4::tree::TerminalNode *POW_ASSIGN();
    antlr4::tree::TerminalNode *BITWISE_AND_ASSIGN();
    antlr4::tree::TerminalNode *BITWISE_OR_ASSIGN();
    antlr4::tree::TerminalNode *BITWISE_XOR_ASSIGN();
    antlr4::tree::TerminalNode *LEFT_SHIFT_ASSIGN();
    antlr4::tree::TerminalNode *RIGHT_SHIFT_ASSIGN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    AttributeAccessContext *attributeAccess();
    SubscriptAccessContext *subscriptAccess();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    ExpressionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionStatementContext* expressionStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConditionalExprContext : public ExpressionContext {
  public:
    ConditionalExprContext(ExpressionContext *ctx);

    ConditionalExpressionContext *conditionalExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();

  class  ConditionalExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConditionalExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConditionalExpressionContext() = default;
    void copyFrom(ConditionalExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConditionalContext : public ConditionalExpressionContext {
  public:
    ConditionalContext(ConditionalExpressionContext *ctx);

    std::vector<LogicalOrContext *> logicalOr();
    LogicalOrContext* logicalOr(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    ConditionalExpressionContext *conditionalExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConditionalExpressionContext* conditionalExpression();

  class  LogicalOrContext : public antlr4::ParserRuleContext {
  public:
    LogicalOrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LogicalAndContext *> logicalAnd();
    LogicalAndContext* logicalAnd(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalOrContext* logicalOr();

  class  LogicalAndContext : public antlr4::ParserRuleContext {
  public:
    LogicalAndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BitwiseOrContext *> bitwiseOr();
    BitwiseOrContext* bitwiseOr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalAndContext* logicalAnd();

  class  BitwiseOrContext : public antlr4::ParserRuleContext {
  public:
    BitwiseOrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BitwiseOrContext() = default;
    void copyFrom(BitwiseOrContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BitwiseOrExprContext : public BitwiseOrContext {
  public:
    BitwiseOrExprContext(BitwiseOrContext *ctx);

    std::vector<BitwiseXorContext *> bitwiseXor();
    BitwiseXorContext* bitwiseXor(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BITWISE_OR();
    antlr4::tree::TerminalNode* BITWISE_OR(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BitwiseOrContext* bitwiseOr();

  class  BitwiseXorContext : public antlr4::ParserRuleContext {
  public:
    BitwiseXorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BitwiseXorContext() = default;
    void copyFrom(BitwiseXorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BitwiseXorExprContext : public BitwiseXorContext {
  public:
    BitwiseXorExprContext(BitwiseXorContext *ctx);

    std::vector<BitwiseAndContext *> bitwiseAnd();
    BitwiseAndContext* bitwiseAnd(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BITWISE_XOR();
    antlr4::tree::TerminalNode* BITWISE_XOR(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BitwiseXorContext* bitwiseXor();

  class  BitwiseAndContext : public antlr4::ParserRuleContext {
  public:
    BitwiseAndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BitwiseAndContext() = default;
    void copyFrom(BitwiseAndContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BitwiseAndExprContext : public BitwiseAndContext {
  public:
    BitwiseAndExprContext(BitwiseAndContext *ctx);

    std::vector<EqualityContext *> equality();
    EqualityContext* equality(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BITWISE_AND();
    antlr4::tree::TerminalNode* BITWISE_AND(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BitwiseAndContext* bitwiseAnd();

  class  EqualityContext : public antlr4::ParserRuleContext {
  public:
    EqualityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ComparisonContext *> comparison();
    ComparisonContext* comparison(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQ();
    antlr4::tree::TerminalNode* EQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NE();
    antlr4::tree::TerminalNode* NE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualityContext* equality();

  class  ComparisonContext : public antlr4::ParserRuleContext {
  public:
    ComparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ShiftContext *> shift();
    ShiftContext* shift(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LT();
    antlr4::tree::TerminalNode* LT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LE();
    antlr4::tree::TerminalNode* LE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GT();
    antlr4::tree::TerminalNode* GT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GE();
    antlr4::tree::TerminalNode* GE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IN();
    antlr4::tree::TerminalNode* IN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NOT_IN();
    antlr4::tree::TerminalNode* NOT_IN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IS();
    antlr4::tree::TerminalNode* IS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IS_NOT();
    antlr4::tree::TerminalNode* IS_NOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparisonContext* comparison();

  class  ShiftContext : public antlr4::ParserRuleContext {
  public:
    ShiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ShiftContext() = default;
    void copyFrom(ShiftContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ShiftExprContext : public ShiftContext {
  public:
    ShiftExprContext(ShiftContext *ctx);

    std::vector<AdditiveContext *> additive();
    AdditiveContext* additive(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LEFT_SHIFT();
    antlr4::tree::TerminalNode* LEFT_SHIFT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RIGHT_SHIFT();
    antlr4::tree::TerminalNode* RIGHT_SHIFT(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ShiftContext* shift();

  class  AdditiveContext : public antlr4::ParserRuleContext {
  public:
    AdditiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultiplicativeContext *> multiplicative();
    MultiplicativeContext* multiplicative(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveContext* additive();

  class  MultiplicativeContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PowerContext *> power();
    PowerContext* power(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MUL();
    antlr4::tree::TerminalNode* MUL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIV();
    antlr4::tree::TerminalNode* DIV(size_t i);
    std::vector<antlr4::tree::TerminalNode *> FLOOR_DIV();
    antlr4::tree::TerminalNode* FLOOR_DIV(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MOD();
    antlr4::tree::TerminalNode* MOD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeContext* multiplicative();

  class  PowerContext : public antlr4::ParserRuleContext {
  public:
    PowerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryContext *unary();
    antlr4::tree::TerminalNode *DOUBLE_STAR();
    PowerContext *power();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PowerContext* power();

  class  UnaryContext : public antlr4::ParserRuleContext {
  public:
    UnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *BITWISE_NOT();
    AwaitExprContext *awaitExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryContext* unary();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    TupleLiteralContext *tupleLiteral();
    ListLiteralContext *listLiteral();
    DictLiteralContext *dictLiteral();
    SetLiteralContext *setLiteral();
    GeneratorExpressionContext *generatorExpression();
    NewExpressionContext *newExpression();
    LambdaExpressionContext *lambdaExpression();
    AwaitExprContext *awaitExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();

  class  TupleLiteralContext : public antlr4::ParserRuleContext {
  public:
    TupleLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TupleLiteralContext() = default;
    void copyFrom(TupleLiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TupleContext : public TupleLiteralContext {
  public:
    TupleContext(TupleLiteralContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TupleLiteralContext* tupleLiteral();

  class  NewExpressionContext : public antlr4::ParserRuleContext {
  public:
    NewExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    DottedNameContext *dottedName();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ArgumentListContext *argumentList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewExpressionContext* newExpression();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    std::vector<PostfixOpContext *> postfixOp();
    PostfixOpContext* postfixOp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AtomContext* atom();

  class  PostfixOpContext : public antlr4::ParserRuleContext {
  public:
    PostfixOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PostfixOpContext() = default;
    void copyFrom(PostfixOpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AttributeAccessOpContext : public PostfixOpContext {
  public:
    AttributeAccessOpContext(PostfixOpContext *ctx);

    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallOpContext : public PostfixOpContext {
  public:
    FunctionCallOpContext(PostfixOpContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ArgumentListContext *argumentList();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubscriptAccessOpContext : public PostfixOpContext {
  public:
    SubscriptAccessOpContext(PostfixOpContext *ctx);

    antlr4::tree::TerminalNode *LBRACK();
    SubscriptArgContext *subscriptArg();
    antlr4::tree::TerminalNode *RBRACK();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PostfixOpContext* postfixOp();

  class  AttributeAccessContext : public antlr4::ParserRuleContext {
  public:
    AttributeAccessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeAccessContext* attributeAccess();

  class  SubscriptAccessContext : public antlr4::ParserRuleContext {
  public:
    SubscriptAccessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *LBRACK();
    SubscriptArgContext *subscriptArg();
    antlr4::tree::TerminalNode *RBRACK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubscriptAccessContext* subscriptAccess();

  class  SubscriptArgContext : public antlr4::ParserRuleContext {
  public:
    SubscriptArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubscriptArgContext* subscriptArg();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ArgumentListContext *argumentList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionCallContext* functionCall();

  class  ArgumentListContext : public antlr4::ParserRuleContext {
  public:
    ArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentListContext* argumentList();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DOUBLE_STAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentContext* argument();

  class  ListLiteralContext : public antlr4::ParserRuleContext {
  public:
    ListLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    ListElementsContext *listElements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListLiteralContext* listLiteral();

  class  ListElementsContext : public antlr4::ParserRuleContext {
  public:
    ListElementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ComprehensionContext *comprehension();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListElementsContext* listElements();

  class  ComprehensionContext : public antlr4::ParserRuleContext {
  public:
    ComprehensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<CompForContext *> compFor();
    CompForContext* compFor(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComprehensionContext* comprehension();

  class  CompForContext : public antlr4::ParserRuleContext {
  public:
    CompForContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *IN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *IF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompForContext* compFor();

  class  DictLiteralContext : public antlr4::ParserRuleContext {
  public:
    DictLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    DictComprehensionContext *dictComprehension();
    std::vector<DictItemContext *> dictItem();
    DictItemContext* dictItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictLiteralContext* dictLiteral();

  class  DictComprehensionContext : public antlr4::ParserRuleContext {
  public:
    DictComprehensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *COLON();
    std::vector<CompForContext *> compFor();
    CompForContext* compFor(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictComprehensionContext* dictComprehension();

  class  DictItemContext : public antlr4::ParserRuleContext {
  public:
    DictItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *DOUBLE_STAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictItemContext* dictItem();

  class  SetLiteralContext : public antlr4::ParserRuleContext {
  public:
    SetLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    SetElementsContext *setElements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetLiteralContext* setLiteral();

  class  SetElementsContext : public antlr4::ParserRuleContext {
  public:
    SetElementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ComprehensionContext *comprehension();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetElementsContext* setElements();

  class  GeneratorExpressionContext : public antlr4::ParserRuleContext {
  public:
    GeneratorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ComprehensionContext *comprehension();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GeneratorExpressionContext* generatorExpression();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *NONE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  LambdaExpressionContext : public antlr4::ParserRuleContext {
  public:
    LambdaExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LAMBDA();
    antlr4::tree::TerminalNode *COLON();
    ExpressionContext *expression();
    ParameterListContext *parameterList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaExpressionContext* lambdaExpression();

  class  DottedNameContext : public antlr4::ParserRuleContext {
  public:
    DottedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DottedNameContext* dottedName();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

