
// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "PyScriptVisitor.h"


/**
 * This class provides an empty implementation of PyScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PyScriptBaseVisitor : public PyScriptVisitor {
public:

  virtual std::any visitProgram(PyScriptParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(PyScriptParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleStatement(PyScriptParser::SimpleStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSmallStatement(PyScriptParser::SmallStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundStatement(PyScriptParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTryStatement(PyScriptParser::TryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExceptClause(PyScriptParser::ExceptClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithStatement(PyScriptParser::WithStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithItem(PyScriptParser::WithItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsyncFunctionDef(PyScriptParser::AsyncFunctionDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsyncForStatement(PyScriptParser::AsyncForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsyncWithStatement(PyScriptParser::AsyncWithStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAwaitExpr(PyScriptParser::AwaitExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDef(PyScriptParser::ClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecoratedDef(PyScriptParser::DecoratedDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecorators(PyScriptParser::DecoratorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecorator(PyScriptParser::DecoratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuite(PyScriptParser::SuiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDef(PyScriptParser::FunctionDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterList(PyScriptParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(PyScriptParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(PyScriptParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(PyScriptParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPassStatement(PyScriptParser::PassStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleImport(PyScriptParser::SimpleImportContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromImport(PyScriptParser::FromImportContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportItem(PyScriptParser::ImportItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(PyScriptParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentTarget(PyScriptParser::AssignmentTargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConditionalExpr(PyScriptParser::ConditionalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConditional(PyScriptParser::ConditionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOr(PyScriptParser::LogicalOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalAnd(PyScriptParser::LogicalAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseOrExpr(PyScriptParser::BitwiseOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseXorExpr(PyScriptParser::BitwiseXorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseAndExpr(PyScriptParser::BitwiseAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEquality(PyScriptParser::EqualityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(PyScriptParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShiftExpr(PyScriptParser::ShiftExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditive(PyScriptParser::AdditiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicative(PyScriptParser::MultiplicativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPower(PyScriptParser::PowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary(PyScriptParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(PyScriptParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiElementTuple(PyScriptParser::MultiElementTupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleElementTuple(PyScriptParser::SingleElementTupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpression(PyScriptParser::NewExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom(PyScriptParser::AtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscriptArg(PyScriptParser::SubscriptArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(PyScriptParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument(PyScriptParser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListLiteral(PyScriptParser::ListLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListElements(PyScriptParser::ListElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComprehension(PyScriptParser::ComprehensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompFor(PyScriptParser::CompForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictComprehension(PyScriptParser::DictComprehensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictItem(PyScriptParser::DictItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetLiteral(PyScriptParser::SetLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetElements(PyScriptParser::SetElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGeneratorExpression(PyScriptParser::GeneratorExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(PyScriptParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDottedName(PyScriptParser::DottedNameContext *ctx) override {
    return visitChildren(ctx);
  }


};

