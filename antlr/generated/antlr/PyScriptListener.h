
// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "PyScriptParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PyScriptParser.
 */
class  PyScriptListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(PyScriptParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(PyScriptParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(PyScriptParser::StatementContext *ctx) = 0;
  virtual void exitStatement(PyScriptParser::StatementContext *ctx) = 0;

  virtual void enterSimpleStatement(PyScriptParser::SimpleStatementContext *ctx) = 0;
  virtual void exitSimpleStatement(PyScriptParser::SimpleStatementContext *ctx) = 0;

  virtual void enterSmallStatement(PyScriptParser::SmallStatementContext *ctx) = 0;
  virtual void exitSmallStatement(PyScriptParser::SmallStatementContext *ctx) = 0;

  virtual void enterCompoundStatement(PyScriptParser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(PyScriptParser::CompoundStatementContext *ctx) = 0;

  virtual void enterTryStatement(PyScriptParser::TryStatementContext *ctx) = 0;
  virtual void exitTryStatement(PyScriptParser::TryStatementContext *ctx) = 0;

  virtual void enterExceptClause(PyScriptParser::ExceptClauseContext *ctx) = 0;
  virtual void exitExceptClause(PyScriptParser::ExceptClauseContext *ctx) = 0;

  virtual void enterSuite(PyScriptParser::SuiteContext *ctx) = 0;
  virtual void exitSuite(PyScriptParser::SuiteContext *ctx) = 0;

  virtual void enterFunctionDef(PyScriptParser::FunctionDefContext *ctx) = 0;
  virtual void exitFunctionDef(PyScriptParser::FunctionDefContext *ctx) = 0;

  virtual void enterParameterList(PyScriptParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(PyScriptParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(PyScriptParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(PyScriptParser::ParameterContext *ctx) = 0;

  virtual void enterIfStatement(PyScriptParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(PyScriptParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileStatement(PyScriptParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(PyScriptParser::WhileStatementContext *ctx) = 0;

  virtual void enterForStatement(PyScriptParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(PyScriptParser::ForStatementContext *ctx) = 0;

  virtual void enterPassStatement(PyScriptParser::PassStatementContext *ctx) = 0;
  virtual void exitPassStatement(PyScriptParser::PassStatementContext *ctx) = 0;

  virtual void enterReturnStatement(PyScriptParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) = 0;

  virtual void enterSimpleImport(PyScriptParser::SimpleImportContext *ctx) = 0;
  virtual void exitSimpleImport(PyScriptParser::SimpleImportContext *ctx) = 0;

  virtual void enterFromImport(PyScriptParser::FromImportContext *ctx) = 0;
  virtual void exitFromImport(PyScriptParser::FromImportContext *ctx) = 0;

  virtual void enterImportItem(PyScriptParser::ImportItemContext *ctx) = 0;
  virtual void exitImportItem(PyScriptParser::ImportItemContext *ctx) = 0;

  virtual void enterAssignment(PyScriptParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(PyScriptParser::AssignmentContext *ctx) = 0;

  virtual void enterExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterExpression(PyScriptParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(PyScriptParser::ExpressionContext *ctx) = 0;

  virtual void enterLogicalOr(PyScriptParser::LogicalOrContext *ctx) = 0;
  virtual void exitLogicalOr(PyScriptParser::LogicalOrContext *ctx) = 0;

  virtual void enterLogicalAnd(PyScriptParser::LogicalAndContext *ctx) = 0;
  virtual void exitLogicalAnd(PyScriptParser::LogicalAndContext *ctx) = 0;

  virtual void enterEquality(PyScriptParser::EqualityContext *ctx) = 0;
  virtual void exitEquality(PyScriptParser::EqualityContext *ctx) = 0;

  virtual void enterComparison(PyScriptParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(PyScriptParser::ComparisonContext *ctx) = 0;

  virtual void enterAdditive(PyScriptParser::AdditiveContext *ctx) = 0;
  virtual void exitAdditive(PyScriptParser::AdditiveContext *ctx) = 0;

  virtual void enterMultiplicative(PyScriptParser::MultiplicativeContext *ctx) = 0;
  virtual void exitMultiplicative(PyScriptParser::MultiplicativeContext *ctx) = 0;

  virtual void enterPower(PyScriptParser::PowerContext *ctx) = 0;
  virtual void exitPower(PyScriptParser::PowerContext *ctx) = 0;

  virtual void enterUnary(PyScriptParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(PyScriptParser::UnaryContext *ctx) = 0;

  virtual void enterPrimary(PyScriptParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(PyScriptParser::PrimaryContext *ctx) = 0;

  virtual void enterNewExpression(PyScriptParser::NewExpressionContext *ctx) = 0;
  virtual void exitNewExpression(PyScriptParser::NewExpressionContext *ctx) = 0;

  virtual void enterAtom(PyScriptParser::AtomContext *ctx) = 0;
  virtual void exitAtom(PyScriptParser::AtomContext *ctx) = 0;

  virtual void enterAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) = 0;
  virtual void exitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) = 0;

  virtual void enterSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) = 0;
  virtual void exitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) = 0;

  virtual void enterFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) = 0;
  virtual void exitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) = 0;

  virtual void enterAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) = 0;
  virtual void exitAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) = 0;

  virtual void enterSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) = 0;
  virtual void exitSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) = 0;

  virtual void enterSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) = 0;
  virtual void exitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) = 0;

  virtual void enterFunctionCall(PyScriptParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(PyScriptParser::FunctionCallContext *ctx) = 0;

  virtual void enterArgumentList(PyScriptParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(PyScriptParser::ArgumentListContext *ctx) = 0;

  virtual void enterArgument(PyScriptParser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(PyScriptParser::ArgumentContext *ctx) = 0;

  virtual void enterListLiteral(PyScriptParser::ListLiteralContext *ctx) = 0;
  virtual void exitListLiteral(PyScriptParser::ListLiteralContext *ctx) = 0;

  virtual void enterListElements(PyScriptParser::ListElementsContext *ctx) = 0;
  virtual void exitListElements(PyScriptParser::ListElementsContext *ctx) = 0;

  virtual void enterDictLiteral(PyScriptParser::DictLiteralContext *ctx) = 0;
  virtual void exitDictLiteral(PyScriptParser::DictLiteralContext *ctx) = 0;

  virtual void enterDictItem(PyScriptParser::DictItemContext *ctx) = 0;
  virtual void exitDictItem(PyScriptParser::DictItemContext *ctx) = 0;

  virtual void enterLiteral(PyScriptParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(PyScriptParser::LiteralContext *ctx) = 0;

  virtual void enterLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) = 0;
  virtual void exitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) = 0;

  virtual void enterDottedName(PyScriptParser::DottedNameContext *ctx) = 0;
  virtual void exitDottedName(PyScriptParser::DottedNameContext *ctx) = 0;


};

