
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

  virtual void enterImportStmt(PyScriptParser::ImportStmtContext *ctx) = 0;
  virtual void exitImportStmt(PyScriptParser::ImportStmtContext *ctx) = 0;

  virtual void enterAssignStmt(PyScriptParser::AssignStmtContext *ctx) = 0;
  virtual void exitAssignStmt(PyScriptParser::AssignStmtContext *ctx) = 0;

  virtual void enterExprStmt(PyScriptParser::ExprStmtContext *ctx) = 0;
  virtual void exitExprStmt(PyScriptParser::ExprStmtContext *ctx) = 0;

  virtual void enterIfStmt(PyScriptParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(PyScriptParser::IfStmtContext *ctx) = 0;

  virtual void enterWhileStmt(PyScriptParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(PyScriptParser::WhileStmtContext *ctx) = 0;

  virtual void enterReturnStmt(PyScriptParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(PyScriptParser::ReturnStmtContext *ctx) = 0;

  virtual void enterImportStatement(PyScriptParser::ImportStatementContext *ctx) = 0;
  virtual void exitImportStatement(PyScriptParser::ImportStatementContext *ctx) = 0;

  virtual void enterBinaryAssignment(PyScriptParser::BinaryAssignmentContext *ctx) = 0;
  virtual void exitBinaryAssignment(PyScriptParser::BinaryAssignmentContext *ctx) = 0;

  virtual void enterAttributeAssignment(PyScriptParser::AttributeAssignmentContext *ctx) = 0;
  virtual void exitAttributeAssignment(PyScriptParser::AttributeAssignmentContext *ctx) = 0;

  virtual void enterSubscriptAssignment(PyScriptParser::SubscriptAssignmentContext *ctx) = 0;
  virtual void exitSubscriptAssignment(PyScriptParser::SubscriptAssignmentContext *ctx) = 0;

  virtual void enterExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterIfStatement(PyScriptParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(PyScriptParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileStatement(PyScriptParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(PyScriptParser::WhileStatementContext *ctx) = 0;

  virtual void enterReturnStatement(PyScriptParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBlock(PyScriptParser::BlockContext *ctx) = 0;
  virtual void exitBlock(PyScriptParser::BlockContext *ctx) = 0;

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

  virtual void enterUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) = 0;

  virtual void enterLiteralPrimary(PyScriptParser::LiteralPrimaryContext *ctx) = 0;
  virtual void exitLiteralPrimary(PyScriptParser::LiteralPrimaryContext *ctx) = 0;

  virtual void enterIdentifierPrimary(PyScriptParser::IdentifierPrimaryContext *ctx) = 0;
  virtual void exitIdentifierPrimary(PyScriptParser::IdentifierPrimaryContext *ctx) = 0;

  virtual void enterParenPrimary(PyScriptParser::ParenPrimaryContext *ctx) = 0;
  virtual void exitParenPrimary(PyScriptParser::ParenPrimaryContext *ctx) = 0;

  virtual void enterNewInstancePrimary(PyScriptParser::NewInstancePrimaryContext *ctx) = 0;
  virtual void exitNewInstancePrimary(PyScriptParser::NewInstancePrimaryContext *ctx) = 0;

  virtual void enterPostfixExpression(PyScriptParser::PostfixExpressionContext *ctx) = 0;
  virtual void exitPostfixExpression(PyScriptParser::PostfixExpressionContext *ctx) = 0;

  virtual void enterFunctionCallPostfix(PyScriptParser::FunctionCallPostfixContext *ctx) = 0;
  virtual void exitFunctionCallPostfix(PyScriptParser::FunctionCallPostfixContext *ctx) = 0;

  virtual void enterMemberAccessPostfix(PyScriptParser::MemberAccessPostfixContext *ctx) = 0;
  virtual void exitMemberAccessPostfix(PyScriptParser::MemberAccessPostfixContext *ctx) = 0;

  virtual void enterSubscriptPostfix(PyScriptParser::SubscriptPostfixContext *ctx) = 0;
  virtual void exitSubscriptPostfix(PyScriptParser::SubscriptPostfixContext *ctx) = 0;

  virtual void enterArgumentList(PyScriptParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(PyScriptParser::ArgumentListContext *ctx) = 0;

  virtual void enterIntegerLiteral(PyScriptParser::IntegerLiteralContext *ctx) = 0;
  virtual void exitIntegerLiteral(PyScriptParser::IntegerLiteralContext *ctx) = 0;

  virtual void enterFloatLiteral(PyScriptParser::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(PyScriptParser::FloatLiteralContext *ctx) = 0;

  virtual void enterStringLiteral(PyScriptParser::StringLiteralContext *ctx) = 0;
  virtual void exitStringLiteral(PyScriptParser::StringLiteralContext *ctx) = 0;

  virtual void enterBooleanLiteral(PyScriptParser::BooleanLiteralContext *ctx) = 0;
  virtual void exitBooleanLiteral(PyScriptParser::BooleanLiteralContext *ctx) = 0;

  virtual void enterNullLiteral(PyScriptParser::NullLiteralContext *ctx) = 0;
  virtual void exitNullLiteral(PyScriptParser::NullLiteralContext *ctx) = 0;

  virtual void enterListLiteral(PyScriptParser::ListLiteralContext *ctx) = 0;
  virtual void exitListLiteral(PyScriptParser::ListLiteralContext *ctx) = 0;

  virtual void enterDictLiteral(PyScriptParser::DictLiteralContext *ctx) = 0;
  virtual void exitDictLiteral(PyScriptParser::DictLiteralContext *ctx) = 0;

  virtual void enterExpressionList(PyScriptParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(PyScriptParser::ExpressionListContext *ctx) = 0;

  virtual void enterKeyValuePairList(PyScriptParser::KeyValuePairListContext *ctx) = 0;
  virtual void exitKeyValuePairList(PyScriptParser::KeyValuePairListContext *ctx) = 0;

  virtual void enterKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) = 0;
  virtual void exitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) = 0;


};

