
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

  virtual void enterWithStatement(PyScriptParser::WithStatementContext * /*ctx*/) override { }
  virtual void exitWithStatement(PyScriptParser::WithStatementContext * /*ctx*/) override { }

  virtual void enterWithItem(PyScriptParser::WithItemContext * /*ctx*/) override { }
  virtual void exitWithItem(PyScriptParser::WithItemContext * /*ctx*/) override { }

  virtual void enterAsyncFunctionDef(PyScriptParser::AsyncFunctionDefContext * /*ctx*/) override { }
  virtual void exitAsyncFunctionDef(PyScriptParser::AsyncFunctionDefContext * /*ctx*/) override { }

  virtual void enterAsyncForStatement(PyScriptParser::AsyncForStatementContext * /*ctx*/) override { }
  virtual void exitAsyncForStatement(PyScriptParser::AsyncForStatementContext * /*ctx*/) override { }

  virtual void enterAsyncWithStatement(PyScriptParser::AsyncWithStatementContext * /*ctx*/) override { }
  virtual void exitAsyncWithStatement(PyScriptParser::AsyncWithStatementContext * /*ctx*/) override { }

  virtual void enterAwaitExpr(PyScriptParser::AwaitExprContext * /*ctx*/) override { }
  virtual void exitAwaitExpr(PyScriptParser::AwaitExprContext * /*ctx*/) override { }

  virtual void enterClassDef(PyScriptParser::ClassDefContext * /*ctx*/) override { }
  virtual void exitClassDef(PyScriptParser::ClassDefContext * /*ctx*/) override { }

  virtual void enterDecoratedDef(PyScriptParser::DecoratedDefContext * /*ctx*/) override { }
  virtual void exitDecoratedDef(PyScriptParser::DecoratedDefContext * /*ctx*/) override { }

  virtual void enterDecorators(PyScriptParser::DecoratorsContext * /*ctx*/) override { }
  virtual void exitDecorators(PyScriptParser::DecoratorsContext * /*ctx*/) override { }

  virtual void enterDecorator(PyScriptParser::DecoratorContext * /*ctx*/) override { }
  virtual void exitDecorator(PyScriptParser::DecoratorContext * /*ctx*/) override { }

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

  virtual void enterRaiseStatement(PyScriptParser::RaiseStatementContext * /*ctx*/) override { }
  virtual void exitRaiseStatement(PyScriptParser::RaiseStatementContext * /*ctx*/) override { }

  virtual void enterDelStatement(PyScriptParser::DelStatementContext * /*ctx*/) override { }
  virtual void exitDelStatement(PyScriptParser::DelStatementContext * /*ctx*/) override { }

  virtual void enterDelTargets(PyScriptParser::DelTargetsContext * /*ctx*/) override { }
  virtual void exitDelTargets(PyScriptParser::DelTargetsContext * /*ctx*/) override { }

  virtual void enterDelSubscript(PyScriptParser::DelSubscriptContext * /*ctx*/) override { }
  virtual void exitDelSubscript(PyScriptParser::DelSubscriptContext * /*ctx*/) override { }

  virtual void enterDelAttribute(PyScriptParser::DelAttributeContext * /*ctx*/) override { }
  virtual void exitDelAttribute(PyScriptParser::DelAttributeContext * /*ctx*/) override { }

  virtual void enterDelVariable(PyScriptParser::DelVariableContext * /*ctx*/) override { }
  virtual void exitDelVariable(PyScriptParser::DelVariableContext * /*ctx*/) override { }

  virtual void enterGlobalStatement(PyScriptParser::GlobalStatementContext * /*ctx*/) override { }
  virtual void exitGlobalStatement(PyScriptParser::GlobalStatementContext * /*ctx*/) override { }

  virtual void enterNonlocalStatement(PyScriptParser::NonlocalStatementContext * /*ctx*/) override { }
  virtual void exitNonlocalStatement(PyScriptParser::NonlocalStatementContext * /*ctx*/) override { }

  virtual void enterSimpleImport(PyScriptParser::SimpleImportContext * /*ctx*/) override { }
  virtual void exitSimpleImport(PyScriptParser::SimpleImportContext * /*ctx*/) override { }

  virtual void enterFromImport(PyScriptParser::FromImportContext * /*ctx*/) override { }
  virtual void exitFromImport(PyScriptParser::FromImportContext * /*ctx*/) override { }

  virtual void enterImportItem(PyScriptParser::ImportItemContext * /*ctx*/) override { }
  virtual void exitImportItem(PyScriptParser::ImportItemContext * /*ctx*/) override { }

  virtual void enterAssignment(PyScriptParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(PyScriptParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterAssignmentTarget(PyScriptParser::AssignmentTargetContext * /*ctx*/) override { }
  virtual void exitAssignmentTarget(PyScriptParser::AssignmentTargetContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(PyScriptParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(PyScriptParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterAssignmentExpr(PyScriptParser::AssignmentExprContext * /*ctx*/) override { }
  virtual void exitAssignmentExpr(PyScriptParser::AssignmentExprContext * /*ctx*/) override { }

  virtual void enterYieldExpr(PyScriptParser::YieldExprContext * /*ctx*/) override { }
  virtual void exitYieldExpr(PyScriptParser::YieldExprContext * /*ctx*/) override { }

  virtual void enterConditionalExpr(PyScriptParser::ConditionalExprContext * /*ctx*/) override { }
  virtual void exitConditionalExpr(PyScriptParser::ConditionalExprContext * /*ctx*/) override { }

  virtual void enterWalrusExpr(PyScriptParser::WalrusExprContext * /*ctx*/) override { }
  virtual void exitWalrusExpr(PyScriptParser::WalrusExprContext * /*ctx*/) override { }

  virtual void enterConditional(PyScriptParser::ConditionalContext * /*ctx*/) override { }
  virtual void exitConditional(PyScriptParser::ConditionalContext * /*ctx*/) override { }

  virtual void enterYieldExpression(PyScriptParser::YieldExpressionContext * /*ctx*/) override { }
  virtual void exitYieldExpression(PyScriptParser::YieldExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalOr(PyScriptParser::LogicalOrContext * /*ctx*/) override { }
  virtual void exitLogicalOr(PyScriptParser::LogicalOrContext * /*ctx*/) override { }

  virtual void enterLogicalAnd(PyScriptParser::LogicalAndContext * /*ctx*/) override { }
  virtual void exitLogicalAnd(PyScriptParser::LogicalAndContext * /*ctx*/) override { }

  virtual void enterBitwiseOrExpr(PyScriptParser::BitwiseOrExprContext * /*ctx*/) override { }
  virtual void exitBitwiseOrExpr(PyScriptParser::BitwiseOrExprContext * /*ctx*/) override { }

  virtual void enterBitwiseXorExpr(PyScriptParser::BitwiseXorExprContext * /*ctx*/) override { }
  virtual void exitBitwiseXorExpr(PyScriptParser::BitwiseXorExprContext * /*ctx*/) override { }

  virtual void enterBitwiseAndExpr(PyScriptParser::BitwiseAndExprContext * /*ctx*/) override { }
  virtual void exitBitwiseAndExpr(PyScriptParser::BitwiseAndExprContext * /*ctx*/) override { }

  virtual void enterEquality(PyScriptParser::EqualityContext * /*ctx*/) override { }
  virtual void exitEquality(PyScriptParser::EqualityContext * /*ctx*/) override { }

  virtual void enterComparison(PyScriptParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(PyScriptParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterShiftExpr(PyScriptParser::ShiftExprContext * /*ctx*/) override { }
  virtual void exitShiftExpr(PyScriptParser::ShiftExprContext * /*ctx*/) override { }

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

  virtual void enterMultiElementTuple(PyScriptParser::MultiElementTupleContext * /*ctx*/) override { }
  virtual void exitMultiElementTuple(PyScriptParser::MultiElementTupleContext * /*ctx*/) override { }

  virtual void enterSingleElementTuple(PyScriptParser::SingleElementTupleContext * /*ctx*/) override { }
  virtual void exitSingleElementTuple(PyScriptParser::SingleElementTupleContext * /*ctx*/) override { }

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

  virtual void enterSubscriptArg(PyScriptParser::SubscriptArgContext * /*ctx*/) override { }
  virtual void exitSubscriptArg(PyScriptParser::SubscriptArgContext * /*ctx*/) override { }

  virtual void enterArgumentList(PyScriptParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(PyScriptParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterArgument(PyScriptParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(PyScriptParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterListLiteral(PyScriptParser::ListLiteralContext * /*ctx*/) override { }
  virtual void exitListLiteral(PyScriptParser::ListLiteralContext * /*ctx*/) override { }

  virtual void enterListElements(PyScriptParser::ListElementsContext * /*ctx*/) override { }
  virtual void exitListElements(PyScriptParser::ListElementsContext * /*ctx*/) override { }

  virtual void enterComprehension(PyScriptParser::ComprehensionContext * /*ctx*/) override { }
  virtual void exitComprehension(PyScriptParser::ComprehensionContext * /*ctx*/) override { }

  virtual void enterCompFor(PyScriptParser::CompForContext * /*ctx*/) override { }
  virtual void exitCompFor(PyScriptParser::CompForContext * /*ctx*/) override { }

  virtual void enterDictLiteral(PyScriptParser::DictLiteralContext * /*ctx*/) override { }
  virtual void exitDictLiteral(PyScriptParser::DictLiteralContext * /*ctx*/) override { }

  virtual void enterDictComprehension(PyScriptParser::DictComprehensionContext * /*ctx*/) override { }
  virtual void exitDictComprehension(PyScriptParser::DictComprehensionContext * /*ctx*/) override { }

  virtual void enterDictItem(PyScriptParser::DictItemContext * /*ctx*/) override { }
  virtual void exitDictItem(PyScriptParser::DictItemContext * /*ctx*/) override { }

  virtual void enterSetLiteral(PyScriptParser::SetLiteralContext * /*ctx*/) override { }
  virtual void exitSetLiteral(PyScriptParser::SetLiteralContext * /*ctx*/) override { }

  virtual void enterSetElements(PyScriptParser::SetElementsContext * /*ctx*/) override { }
  virtual void exitSetElements(PyScriptParser::SetElementsContext * /*ctx*/) override { }

  virtual void enterGeneratorExpression(PyScriptParser::GeneratorExpressionContext * /*ctx*/) override { }
  virtual void exitGeneratorExpression(PyScriptParser::GeneratorExpressionContext * /*ctx*/) override { }

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

