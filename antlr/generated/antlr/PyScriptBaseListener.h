
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

  virtual void enterStatement(PyScriptParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(PyScriptParser::StatementContext * /*ctx*/) override { }

  virtual void enterImportStatement(PyScriptParser::ImportStatementContext * /*ctx*/) override { }
  virtual void exitImportStatement(PyScriptParser::ImportStatementContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(PyScriptParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(PyScriptParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterParameterList(PyScriptParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(PyScriptParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameter(PyScriptParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(PyScriptParser::ParameterContext * /*ctx*/) override { }

  virtual void enterIfStatement(PyScriptParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(PyScriptParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(PyScriptParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(PyScriptParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(PyScriptParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(PyScriptParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterForControl(PyScriptParser::ForControlContext * /*ctx*/) override { }
  virtual void exitForControl(PyScriptParser::ForControlContext * /*ctx*/) override { }

  virtual void enterForInit(PyScriptParser::ForInitContext * /*ctx*/) override { }
  virtual void exitForInit(PyScriptParser::ForInitContext * /*ctx*/) override { }

  virtual void enterForUpdate(PyScriptParser::ForUpdateContext * /*ctx*/) override { }
  virtual void exitForUpdate(PyScriptParser::ForUpdateContext * /*ctx*/) override { }

  virtual void enterReturnStatement(PyScriptParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(PyScriptParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBlock(PyScriptParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(PyScriptParser::BlockContext * /*ctx*/) override { }

  virtual void enterAssignment(PyScriptParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(PyScriptParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(PyScriptParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(PyScriptParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(PyScriptParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(PyScriptParser::ExpressionStatementContext * /*ctx*/) override { }

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

  virtual void enterPowerExpression(PyScriptParser::PowerExpressionContext * /*ctx*/) override { }
  virtual void exitPowerExpression(PyScriptParser::PowerExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryExpression(PyScriptParser::UnaryExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryExpression(PyScriptParser::UnaryExpressionContext * /*ctx*/) override { }

  virtual void enterCallOrPrimary(PyScriptParser::CallOrPrimaryContext * /*ctx*/) override { }
  virtual void exitCallOrPrimary(PyScriptParser::CallOrPrimaryContext * /*ctx*/) override { }

  virtual void enterAttributeAccessOp(PyScriptParser::AttributeAccessOpContext * /*ctx*/) override { }
  virtual void exitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext * /*ctx*/) override { }

  virtual void enterSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext * /*ctx*/) override { }
  virtual void exitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext * /*ctx*/) override { }

  virtual void enterFunctionCallOp(PyScriptParser::FunctionCallOpContext * /*ctx*/) override { }
  virtual void exitFunctionCallOp(PyScriptParser::FunctionCallOpContext * /*ctx*/) override { }

  virtual void enterAttributeAccess(PyScriptParser::AttributeAccessContext * /*ctx*/) override { }
  virtual void exitAttributeAccess(PyScriptParser::AttributeAccessContext * /*ctx*/) override { }

  virtual void enterSubscriptAccess(PyScriptParser::SubscriptAccessContext * /*ctx*/) override { }
  virtual void exitSubscriptAccess(PyScriptParser::SubscriptAccessContext * /*ctx*/) override { }

  virtual void enterFunctionCall(PyScriptParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(PyScriptParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(PyScriptParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(PyScriptParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterNewExpression(PyScriptParser::NewExpressionContext * /*ctx*/) override { }
  virtual void exitNewExpression(PyScriptParser::NewExpressionContext * /*ctx*/) override { }

  virtual void enterLiteral(PyScriptParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(PyScriptParser::LiteralContext * /*ctx*/) override { }

  virtual void enterListLiteral(PyScriptParser::ListLiteralContext * /*ctx*/) override { }
  virtual void exitListLiteral(PyScriptParser::ListLiteralContext * /*ctx*/) override { }

  virtual void enterDictLiteral(PyScriptParser::DictLiteralContext * /*ctx*/) override { }
  virtual void exitDictLiteral(PyScriptParser::DictLiteralContext * /*ctx*/) override { }

  virtual void enterListComprehension(PyScriptParser::ListComprehensionContext * /*ctx*/) override { }
  virtual void exitListComprehension(PyScriptParser::ListComprehensionContext * /*ctx*/) override { }

  virtual void enterLambdaExpression(PyScriptParser::LambdaExpressionContext * /*ctx*/) override { }
  virtual void exitLambdaExpression(PyScriptParser::LambdaExpressionContext * /*ctx*/) override { }

  virtual void enterDottedName(PyScriptParser::DottedNameContext * /*ctx*/) override { }
  virtual void exitDottedName(PyScriptParser::DottedNameContext * /*ctx*/) override { }

  virtual void enterArgumentList(PyScriptParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(PyScriptParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterArgument(PyScriptParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(PyScriptParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterExpressionList(PyScriptParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(PyScriptParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterDictItemList(PyScriptParser::DictItemListContext * /*ctx*/) override { }
  virtual void exitDictItemList(PyScriptParser::DictItemListContext * /*ctx*/) override { }

  virtual void enterKeyValuePair(PyScriptParser::KeyValuePairContext * /*ctx*/) override { }
  virtual void exitKeyValuePair(PyScriptParser::KeyValuePairContext * /*ctx*/) override { }

  virtual void enterDictUnpack(PyScriptParser::DictUnpackContext * /*ctx*/) override { }
  virtual void exitDictUnpack(PyScriptParser::DictUnpackContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

