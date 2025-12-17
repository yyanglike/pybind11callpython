
// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "PyScriptListener.h"


/**
 * This class provides an empty implementation of PyScriptListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PyScriptBaseListener : public PyScriptListener {
public:

  virtual void enterProgram(PyScriptParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(PyScriptParser::ProgramContext * /*ctx*/) override { }

  virtual void enterImportStmt(PyScriptParser::ImportStmtContext * /*ctx*/) override { }
  virtual void exitImportStmt(PyScriptParser::ImportStmtContext * /*ctx*/) override { }

  virtual void enterAssignStmt(PyScriptParser::AssignStmtContext * /*ctx*/) override { }
  virtual void exitAssignStmt(PyScriptParser::AssignStmtContext * /*ctx*/) override { }

  virtual void enterExprStmt(PyScriptParser::ExprStmtContext * /*ctx*/) override { }
  virtual void exitExprStmt(PyScriptParser::ExprStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(PyScriptParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(PyScriptParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(PyScriptParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(PyScriptParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(PyScriptParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(PyScriptParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterImportStatement(PyScriptParser::ImportStatementContext * /*ctx*/) override { }
  virtual void exitImportStatement(PyScriptParser::ImportStatementContext * /*ctx*/) override { }

  virtual void enterBinaryAssignment(PyScriptParser::BinaryAssignmentContext * /*ctx*/) override { }
  virtual void exitBinaryAssignment(PyScriptParser::BinaryAssignmentContext * /*ctx*/) override { }

  virtual void enterAttributeAssignment(PyScriptParser::AttributeAssignmentContext * /*ctx*/) override { }
  virtual void exitAttributeAssignment(PyScriptParser::AttributeAssignmentContext * /*ctx*/) override { }

  virtual void enterSubscriptAssignment(PyScriptParser::SubscriptAssignmentContext * /*ctx*/) override { }
  virtual void exitSubscriptAssignment(PyScriptParser::SubscriptAssignmentContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(PyScriptParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(PyScriptParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(PyScriptParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(PyScriptParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(PyScriptParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(PyScriptParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(PyScriptParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(PyScriptParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBlock(PyScriptParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(PyScriptParser::BlockContext * /*ctx*/) override { }

  virtual void enterExpression(PyScriptParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(PyScriptParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterTernaryExpression(PyScriptParser::TernaryExpressionContext * /*ctx*/) override { }
  virtual void exitTernaryExpression(PyScriptParser::TernaryExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext * /*ctx*/) override { }

  virtual void enterEqualityExpression(PyScriptParser::EqualityExpressionContext * /*ctx*/) override { }
  virtual void exitEqualityExpression(PyScriptParser::EqualityExpressionContext * /*ctx*/) override { }

  virtual void enterRelationalExpression(PyScriptParser::RelationalExpressionContext * /*ctx*/) override { }
  virtual void exitRelationalExpression(PyScriptParser::RelationalExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(PyScriptParser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(PyScriptParser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryExpression(PyScriptParser::UnaryExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryExpression(PyScriptParser::UnaryExpressionContext * /*ctx*/) override { }

  virtual void enterLiteralPrimary(PyScriptParser::LiteralPrimaryContext * /*ctx*/) override { }
  virtual void exitLiteralPrimary(PyScriptParser::LiteralPrimaryContext * /*ctx*/) override { }

  virtual void enterIdentifierPrimary(PyScriptParser::IdentifierPrimaryContext * /*ctx*/) override { }
  virtual void exitIdentifierPrimary(PyScriptParser::IdentifierPrimaryContext * /*ctx*/) override { }

  virtual void enterParenPrimary(PyScriptParser::ParenPrimaryContext * /*ctx*/) override { }
  virtual void exitParenPrimary(PyScriptParser::ParenPrimaryContext * /*ctx*/) override { }

  virtual void enterNewInstancePrimary(PyScriptParser::NewInstancePrimaryContext * /*ctx*/) override { }
  virtual void exitNewInstancePrimary(PyScriptParser::NewInstancePrimaryContext * /*ctx*/) override { }

  virtual void enterPostfixExpression(PyScriptParser::PostfixExpressionContext * /*ctx*/) override { }
  virtual void exitPostfixExpression(PyScriptParser::PostfixExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionCallPostfix(PyScriptParser::FunctionCallPostfixContext * /*ctx*/) override { }
  virtual void exitFunctionCallPostfix(PyScriptParser::FunctionCallPostfixContext * /*ctx*/) override { }

  virtual void enterMemberAccessPostfix(PyScriptParser::MemberAccessPostfixContext * /*ctx*/) override { }
  virtual void exitMemberAccessPostfix(PyScriptParser::MemberAccessPostfixContext * /*ctx*/) override { }

  virtual void enterSubscriptPostfix(PyScriptParser::SubscriptPostfixContext * /*ctx*/) override { }
  virtual void exitSubscriptPostfix(PyScriptParser::SubscriptPostfixContext * /*ctx*/) override { }

  virtual void enterArgumentList(PyScriptParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(PyScriptParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterIntegerLiteral(PyScriptParser::IntegerLiteralContext * /*ctx*/) override { }
  virtual void exitIntegerLiteral(PyScriptParser::IntegerLiteralContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(PyScriptParser::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(PyScriptParser::FloatLiteralContext * /*ctx*/) override { }

  virtual void enterStringLiteral(PyScriptParser::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(PyScriptParser::StringLiteralContext * /*ctx*/) override { }

  virtual void enterBooleanLiteral(PyScriptParser::BooleanLiteralContext * /*ctx*/) override { }
  virtual void exitBooleanLiteral(PyScriptParser::BooleanLiteralContext * /*ctx*/) override { }

  virtual void enterNullLiteral(PyScriptParser::NullLiteralContext * /*ctx*/) override { }
  virtual void exitNullLiteral(PyScriptParser::NullLiteralContext * /*ctx*/) override { }

  virtual void enterListLiteral(PyScriptParser::ListLiteralContext * /*ctx*/) override { }
  virtual void exitListLiteral(PyScriptParser::ListLiteralContext * /*ctx*/) override { }

  virtual void enterDictLiteral(PyScriptParser::DictLiteralContext * /*ctx*/) override { }
  virtual void exitDictLiteral(PyScriptParser::DictLiteralContext * /*ctx*/) override { }

  virtual void enterExpressionList(PyScriptParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(PyScriptParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterKeyValuePairList(PyScriptParser::KeyValuePairListContext * /*ctx*/) override { }
  virtual void exitKeyValuePairList(PyScriptParser::KeyValuePairListContext * /*ctx*/) override { }

  virtual void enterKeyValuePair(PyScriptParser::KeyValuePairContext * /*ctx*/) override { }
  virtual void exitKeyValuePair(PyScriptParser::KeyValuePairContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

