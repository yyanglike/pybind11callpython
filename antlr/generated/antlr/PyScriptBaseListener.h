
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

  virtual void enterSimpleStatement(PyScriptParser::SimpleStatementContext * /*ctx*/) override { }
  virtual void exitSimpleStatement(PyScriptParser::SimpleStatementContext * /*ctx*/) override { }

  virtual void enterSmallStatement(PyScriptParser::SmallStatementContext * /*ctx*/) override { }
  virtual void exitSmallStatement(PyScriptParser::SmallStatementContext * /*ctx*/) override { }

  virtual void enterCompoundStatement(PyScriptParser::CompoundStatementContext * /*ctx*/) override { }
  virtual void exitCompoundStatement(PyScriptParser::CompoundStatementContext * /*ctx*/) override { }

  virtual void enterTryStatement(PyScriptParser::TryStatementContext * /*ctx*/) override { }
  virtual void exitTryStatement(PyScriptParser::TryStatementContext * /*ctx*/) override { }

  virtual void enterExceptClause(PyScriptParser::ExceptClauseContext * /*ctx*/) override { }
  virtual void exitExceptClause(PyScriptParser::ExceptClauseContext * /*ctx*/) override { }

  virtual void enterSuite(PyScriptParser::SuiteContext * /*ctx*/) override { }
  virtual void exitSuite(PyScriptParser::SuiteContext * /*ctx*/) override { }

  virtual void enterFunctionDef(PyScriptParser::FunctionDefContext * /*ctx*/) override { }
  virtual void exitFunctionDef(PyScriptParser::FunctionDefContext * /*ctx*/) override { }

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

  virtual void enterPassStatement(PyScriptParser::PassStatementContext * /*ctx*/) override { }
  virtual void exitPassStatement(PyScriptParser::PassStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(PyScriptParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(PyScriptParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterSimpleImport(PyScriptParser::SimpleImportContext * /*ctx*/) override { }
  virtual void exitSimpleImport(PyScriptParser::SimpleImportContext * /*ctx*/) override { }

  virtual void enterFromImport(PyScriptParser::FromImportContext * /*ctx*/) override { }
  virtual void exitFromImport(PyScriptParser::FromImportContext * /*ctx*/) override { }

  virtual void enterImportItem(PyScriptParser::ImportItemContext * /*ctx*/) override { }
  virtual void exitImportItem(PyScriptParser::ImportItemContext * /*ctx*/) override { }

  virtual void enterAssignment(PyScriptParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(PyScriptParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(PyScriptParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(PyScriptParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterExpression(PyScriptParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(PyScriptParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalOr(PyScriptParser::LogicalOrContext * /*ctx*/) override { }
  virtual void exitLogicalOr(PyScriptParser::LogicalOrContext * /*ctx*/) override { }

  virtual void enterLogicalAnd(PyScriptParser::LogicalAndContext * /*ctx*/) override { }
  virtual void exitLogicalAnd(PyScriptParser::LogicalAndContext * /*ctx*/) override { }

  virtual void enterEquality(PyScriptParser::EqualityContext * /*ctx*/) override { }
  virtual void exitEquality(PyScriptParser::EqualityContext * /*ctx*/) override { }

  virtual void enterComparison(PyScriptParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(PyScriptParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterAdditive(PyScriptParser::AdditiveContext * /*ctx*/) override { }
  virtual void exitAdditive(PyScriptParser::AdditiveContext * /*ctx*/) override { }

  virtual void enterMultiplicative(PyScriptParser::MultiplicativeContext * /*ctx*/) override { }
  virtual void exitMultiplicative(PyScriptParser::MultiplicativeContext * /*ctx*/) override { }

  virtual void enterPower(PyScriptParser::PowerContext * /*ctx*/) override { }
  virtual void exitPower(PyScriptParser::PowerContext * /*ctx*/) override { }

  virtual void enterUnary(PyScriptParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(PyScriptParser::UnaryContext * /*ctx*/) override { }

  virtual void enterPrimary(PyScriptParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(PyScriptParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterNewExpression(PyScriptParser::NewExpressionContext * /*ctx*/) override { }
  virtual void exitNewExpression(PyScriptParser::NewExpressionContext * /*ctx*/) override { }

  virtual void enterAtom(PyScriptParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(PyScriptParser::AtomContext * /*ctx*/) override { }

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

  virtual void enterSubscriptArg(PyScriptParser::SubscriptArgContext * /*ctx*/) override { }
  virtual void exitSubscriptArg(PyScriptParser::SubscriptArgContext * /*ctx*/) override { }

  virtual void enterFunctionCall(PyScriptParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(PyScriptParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterArgumentList(PyScriptParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(PyScriptParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterArgument(PyScriptParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(PyScriptParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterListLiteral(PyScriptParser::ListLiteralContext * /*ctx*/) override { }
  virtual void exitListLiteral(PyScriptParser::ListLiteralContext * /*ctx*/) override { }

  virtual void enterListElements(PyScriptParser::ListElementsContext * /*ctx*/) override { }
  virtual void exitListElements(PyScriptParser::ListElementsContext * /*ctx*/) override { }

  virtual void enterDictLiteral(PyScriptParser::DictLiteralContext * /*ctx*/) override { }
  virtual void exitDictLiteral(PyScriptParser::DictLiteralContext * /*ctx*/) override { }

  virtual void enterDictItem(PyScriptParser::DictItemContext * /*ctx*/) override { }
  virtual void exitDictItem(PyScriptParser::DictItemContext * /*ctx*/) override { }

  virtual void enterLiteral(PyScriptParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(PyScriptParser::LiteralContext * /*ctx*/) override { }

  virtual void enterLambdaExpression(PyScriptParser::LambdaExpressionContext * /*ctx*/) override { }
  virtual void exitLambdaExpression(PyScriptParser::LambdaExpressionContext * /*ctx*/) override { }

  virtual void enterDottedName(PyScriptParser::DottedNameContext * /*ctx*/) override { }
  virtual void exitDottedName(PyScriptParser::DottedNameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

