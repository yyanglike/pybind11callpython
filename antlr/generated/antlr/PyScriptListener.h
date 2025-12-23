
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

  virtual void enterImportStatement(PyScriptParser::ImportStatementContext *ctx) = 0;
  virtual void exitImportStatement(PyScriptParser::ImportStatementContext *ctx) = 0;

  virtual void enterFunctionDefinition(PyScriptParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(PyScriptParser::FunctionDefinitionContext *ctx) = 0;

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

  virtual void enterForControl(PyScriptParser::ForControlContext *ctx) = 0;
  virtual void exitForControl(PyScriptParser::ForControlContext *ctx) = 0;

  virtual void enterForInit(PyScriptParser::ForInitContext *ctx) = 0;
  virtual void exitForInit(PyScriptParser::ForInitContext *ctx) = 0;

  virtual void enterForUpdate(PyScriptParser::ForUpdateContext *ctx) = 0;
  virtual void exitForUpdate(PyScriptParser::ForUpdateContext *ctx) = 0;

  virtual void enterReturnStatement(PyScriptParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBlock(PyScriptParser::BlockContext *ctx) = 0;
  virtual void exitBlock(PyScriptParser::BlockContext *ctx) = 0;

  virtual void enterAssignment(PyScriptParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(PyScriptParser::AssignmentContext *ctx) = 0;

  virtual void enterAssignmentOperator(PyScriptParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(PyScriptParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterExpression(PyScriptParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(PyScriptParser::ExpressionContext *ctx) = 0;

  virtual void enterTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) = 0;
  virtual void exitTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) = 0;

  virtual void enterLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *ctx) = 0;
  virtual void exitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(PyScriptParser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(PyScriptParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(PyScriptParser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(PyScriptParser::RelationalExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(PyScriptParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(PyScriptParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterPowerExpression(PyScriptParser::PowerExpressionContext *ctx) = 0;
  virtual void exitPowerExpression(PyScriptParser::PowerExpressionContext *ctx) = 0;

  virtual void enterUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) = 0;

  virtual void enterCallOrPrimary(PyScriptParser::CallOrPrimaryContext *ctx) = 0;
  virtual void exitCallOrPrimary(PyScriptParser::CallOrPrimaryContext *ctx) = 0;

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

  virtual void enterFunctionCall(PyScriptParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(PyScriptParser::FunctionCallContext *ctx) = 0;

  virtual void enterPrimaryExpression(PyScriptParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(PyScriptParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterNewExpression(PyScriptParser::NewExpressionContext *ctx) = 0;
  virtual void exitNewExpression(PyScriptParser::NewExpressionContext *ctx) = 0;

  virtual void enterLiteral(PyScriptParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(PyScriptParser::LiteralContext *ctx) = 0;

  virtual void enterListLiteral(PyScriptParser::ListLiteralContext *ctx) = 0;
  virtual void exitListLiteral(PyScriptParser::ListLiteralContext *ctx) = 0;

  virtual void enterDictLiteral(PyScriptParser::DictLiteralContext *ctx) = 0;
  virtual void exitDictLiteral(PyScriptParser::DictLiteralContext *ctx) = 0;

  virtual void enterListComprehension(PyScriptParser::ListComprehensionContext *ctx) = 0;
  virtual void exitListComprehension(PyScriptParser::ListComprehensionContext *ctx) = 0;

  virtual void enterLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) = 0;
  virtual void exitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) = 0;

  virtual void enterDottedName(PyScriptParser::DottedNameContext *ctx) = 0;
  virtual void exitDottedName(PyScriptParser::DottedNameContext *ctx) = 0;

  virtual void enterArgumentList(PyScriptParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(PyScriptParser::ArgumentListContext *ctx) = 0;

  virtual void enterArgument(PyScriptParser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(PyScriptParser::ArgumentContext *ctx) = 0;

  virtual void enterExpressionList(PyScriptParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(PyScriptParser::ExpressionListContext *ctx) = 0;

  virtual void enterDictItemList(PyScriptParser::DictItemListContext *ctx) = 0;
  virtual void exitDictItemList(PyScriptParser::DictItemListContext *ctx) = 0;

  virtual void enterKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) = 0;
  virtual void exitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) = 0;

  virtual void enterDictUnpack(PyScriptParser::DictUnpackContext *ctx) = 0;
  virtual void exitDictUnpack(PyScriptParser::DictUnpackContext *ctx) = 0;


};

