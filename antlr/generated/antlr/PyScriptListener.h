
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

  virtual void enterWithStatement(PyScriptParser::WithStatementContext *ctx) = 0;
  virtual void exitWithStatement(PyScriptParser::WithStatementContext *ctx) = 0;

  virtual void enterWithItem(PyScriptParser::WithItemContext *ctx) = 0;
  virtual void exitWithItem(PyScriptParser::WithItemContext *ctx) = 0;

  virtual void enterAsyncFunctionDef(PyScriptParser::AsyncFunctionDefContext *ctx) = 0;
  virtual void exitAsyncFunctionDef(PyScriptParser::AsyncFunctionDefContext *ctx) = 0;

  virtual void enterAsyncForStatement(PyScriptParser::AsyncForStatementContext *ctx) = 0;
  virtual void exitAsyncForStatement(PyScriptParser::AsyncForStatementContext *ctx) = 0;

  virtual void enterAsyncWithStatement(PyScriptParser::AsyncWithStatementContext *ctx) = 0;
  virtual void exitAsyncWithStatement(PyScriptParser::AsyncWithStatementContext *ctx) = 0;

  virtual void enterAwaitExpr(PyScriptParser::AwaitExprContext *ctx) = 0;
  virtual void exitAwaitExpr(PyScriptParser::AwaitExprContext *ctx) = 0;

  virtual void enterClassDef(PyScriptParser::ClassDefContext *ctx) = 0;
  virtual void exitClassDef(PyScriptParser::ClassDefContext *ctx) = 0;

  virtual void enterDecoratedDef(PyScriptParser::DecoratedDefContext *ctx) = 0;
  virtual void exitDecoratedDef(PyScriptParser::DecoratedDefContext *ctx) = 0;

  virtual void enterDecorators(PyScriptParser::DecoratorsContext *ctx) = 0;
  virtual void exitDecorators(PyScriptParser::DecoratorsContext *ctx) = 0;

  virtual void enterDecorator(PyScriptParser::DecoratorContext *ctx) = 0;
  virtual void exitDecorator(PyScriptParser::DecoratorContext *ctx) = 0;

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

  virtual void enterRaiseStatement(PyScriptParser::RaiseStatementContext *ctx) = 0;
  virtual void exitRaiseStatement(PyScriptParser::RaiseStatementContext *ctx) = 0;

  virtual void enterDelStatement(PyScriptParser::DelStatementContext *ctx) = 0;
  virtual void exitDelStatement(PyScriptParser::DelStatementContext *ctx) = 0;

  virtual void enterDelTargets(PyScriptParser::DelTargetsContext *ctx) = 0;
  virtual void exitDelTargets(PyScriptParser::DelTargetsContext *ctx) = 0;

  virtual void enterDelSubscript(PyScriptParser::DelSubscriptContext *ctx) = 0;
  virtual void exitDelSubscript(PyScriptParser::DelSubscriptContext *ctx) = 0;

  virtual void enterDelAttribute(PyScriptParser::DelAttributeContext *ctx) = 0;
  virtual void exitDelAttribute(PyScriptParser::DelAttributeContext *ctx) = 0;

  virtual void enterDelVariable(PyScriptParser::DelVariableContext *ctx) = 0;
  virtual void exitDelVariable(PyScriptParser::DelVariableContext *ctx) = 0;

  virtual void enterGlobalStatement(PyScriptParser::GlobalStatementContext *ctx) = 0;
  virtual void exitGlobalStatement(PyScriptParser::GlobalStatementContext *ctx) = 0;

  virtual void enterNonlocalStatement(PyScriptParser::NonlocalStatementContext *ctx) = 0;
  virtual void exitNonlocalStatement(PyScriptParser::NonlocalStatementContext *ctx) = 0;

  virtual void enterSimpleImport(PyScriptParser::SimpleImportContext *ctx) = 0;
  virtual void exitSimpleImport(PyScriptParser::SimpleImportContext *ctx) = 0;

  virtual void enterFromImport(PyScriptParser::FromImportContext *ctx) = 0;
  virtual void exitFromImport(PyScriptParser::FromImportContext *ctx) = 0;

  virtual void enterImportItem(PyScriptParser::ImportItemContext *ctx) = 0;
  virtual void exitImportItem(PyScriptParser::ImportItemContext *ctx) = 0;

  virtual void enterAssignment(PyScriptParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(PyScriptParser::AssignmentContext *ctx) = 0;

  virtual void enterAssignmentTarget(PyScriptParser::AssignmentTargetContext *ctx) = 0;
  virtual void exitAssignmentTarget(PyScriptParser::AssignmentTargetContext *ctx) = 0;

  virtual void enterExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterAssignmentExpr(PyScriptParser::AssignmentExprContext *ctx) = 0;
  virtual void exitAssignmentExpr(PyScriptParser::AssignmentExprContext *ctx) = 0;

  virtual void enterYieldExpr(PyScriptParser::YieldExprContext *ctx) = 0;
  virtual void exitYieldExpr(PyScriptParser::YieldExprContext *ctx) = 0;

  virtual void enterConditionalExpr(PyScriptParser::ConditionalExprContext *ctx) = 0;
  virtual void exitConditionalExpr(PyScriptParser::ConditionalExprContext *ctx) = 0;

  virtual void enterWalrusExpr(PyScriptParser::WalrusExprContext *ctx) = 0;
  virtual void exitWalrusExpr(PyScriptParser::WalrusExprContext *ctx) = 0;

  virtual void enterConditional(PyScriptParser::ConditionalContext *ctx) = 0;
  virtual void exitConditional(PyScriptParser::ConditionalContext *ctx) = 0;

  virtual void enterYieldExpression(PyScriptParser::YieldExpressionContext *ctx) = 0;
  virtual void exitYieldExpression(PyScriptParser::YieldExpressionContext *ctx) = 0;

  virtual void enterLogicalOr(PyScriptParser::LogicalOrContext *ctx) = 0;
  virtual void exitLogicalOr(PyScriptParser::LogicalOrContext *ctx) = 0;

  virtual void enterLogicalAnd(PyScriptParser::LogicalAndContext *ctx) = 0;
  virtual void exitLogicalAnd(PyScriptParser::LogicalAndContext *ctx) = 0;

  virtual void enterBitwiseOrExpr(PyScriptParser::BitwiseOrExprContext *ctx) = 0;
  virtual void exitBitwiseOrExpr(PyScriptParser::BitwiseOrExprContext *ctx) = 0;

  virtual void enterBitwiseXorExpr(PyScriptParser::BitwiseXorExprContext *ctx) = 0;
  virtual void exitBitwiseXorExpr(PyScriptParser::BitwiseXorExprContext *ctx) = 0;

  virtual void enterBitwiseAndExpr(PyScriptParser::BitwiseAndExprContext *ctx) = 0;
  virtual void exitBitwiseAndExpr(PyScriptParser::BitwiseAndExprContext *ctx) = 0;

  virtual void enterEquality(PyScriptParser::EqualityContext *ctx) = 0;
  virtual void exitEquality(PyScriptParser::EqualityContext *ctx) = 0;

  virtual void enterComparison(PyScriptParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(PyScriptParser::ComparisonContext *ctx) = 0;

  virtual void enterShiftExpr(PyScriptParser::ShiftExprContext *ctx) = 0;
  virtual void exitShiftExpr(PyScriptParser::ShiftExprContext *ctx) = 0;

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

  virtual void enterMultiElementTuple(PyScriptParser::MultiElementTupleContext *ctx) = 0;
  virtual void exitMultiElementTuple(PyScriptParser::MultiElementTupleContext *ctx) = 0;

  virtual void enterSingleElementTuple(PyScriptParser::SingleElementTupleContext *ctx) = 0;
  virtual void exitSingleElementTuple(PyScriptParser::SingleElementTupleContext *ctx) = 0;

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

  virtual void enterSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) = 0;
  virtual void exitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) = 0;

  virtual void enterArgumentList(PyScriptParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(PyScriptParser::ArgumentListContext *ctx) = 0;

  virtual void enterArgument(PyScriptParser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(PyScriptParser::ArgumentContext *ctx) = 0;

  virtual void enterListLiteral(PyScriptParser::ListLiteralContext *ctx) = 0;
  virtual void exitListLiteral(PyScriptParser::ListLiteralContext *ctx) = 0;

  virtual void enterListElements(PyScriptParser::ListElementsContext *ctx) = 0;
  virtual void exitListElements(PyScriptParser::ListElementsContext *ctx) = 0;

  virtual void enterComprehension(PyScriptParser::ComprehensionContext *ctx) = 0;
  virtual void exitComprehension(PyScriptParser::ComprehensionContext *ctx) = 0;

  virtual void enterCompFor(PyScriptParser::CompForContext *ctx) = 0;
  virtual void exitCompFor(PyScriptParser::CompForContext *ctx) = 0;

  virtual void enterDictLiteral(PyScriptParser::DictLiteralContext *ctx) = 0;
  virtual void exitDictLiteral(PyScriptParser::DictLiteralContext *ctx) = 0;

  virtual void enterDictComprehension(PyScriptParser::DictComprehensionContext *ctx) = 0;
  virtual void exitDictComprehension(PyScriptParser::DictComprehensionContext *ctx) = 0;

  virtual void enterDictItem(PyScriptParser::DictItemContext *ctx) = 0;
  virtual void exitDictItem(PyScriptParser::DictItemContext *ctx) = 0;

  virtual void enterSetLiteral(PyScriptParser::SetLiteralContext *ctx) = 0;
  virtual void exitSetLiteral(PyScriptParser::SetLiteralContext *ctx) = 0;

  virtual void enterSetElements(PyScriptParser::SetElementsContext *ctx) = 0;
  virtual void exitSetElements(PyScriptParser::SetElementsContext *ctx) = 0;

  virtual void enterGeneratorExpression(PyScriptParser::GeneratorExpressionContext *ctx) = 0;
  virtual void exitGeneratorExpression(PyScriptParser::GeneratorExpressionContext *ctx) = 0;

  virtual void enterLiteral(PyScriptParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(PyScriptParser::LiteralContext *ctx) = 0;

  virtual void enterLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) = 0;
  virtual void exitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) = 0;

  virtual void enterDottedName(PyScriptParser::DottedNameContext *ctx) = 0;
  virtual void exitDottedName(PyScriptParser::DottedNameContext *ctx) = 0;


};

