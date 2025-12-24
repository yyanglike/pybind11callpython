
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

  virtual std::any visitImportStatement(PyScriptParser::ImportStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDefinition(PyScriptParser::FunctionDefinitionContext *ctx) override {
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

  virtual std::any visitForControl(PyScriptParser::ForControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForInit(PyScriptParser::ForInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForUpdate(PyScriptParser::ForUpdateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(PyScriptParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(PyScriptParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentOperator(PyScriptParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(PyScriptParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonAssignmentExpression(PyScriptParser::NonAssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpression(PyScriptParser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationalExpression(PyScriptParser::RelationalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveExpression(PyScriptParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpression(PyScriptParser::UnaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPowerExpression(PyScriptParser::PowerExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallOrPrimary(PyScriptParser::CallOrPrimaryContext *ctx) override {
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

  virtual std::any visitAttributeAccess(PyScriptParser::AttributeAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(PyScriptParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpression(PyScriptParser::PrimaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpression(PyScriptParser::NewExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(PyScriptParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListLiteral(PyScriptParser::ListLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListComprehension(PyScriptParser::ListComprehensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaExpression(PyScriptParser::LambdaExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDottedName(PyScriptParser::DottedNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(PyScriptParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeywordArgument(PyScriptParser::KeywordArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPositionalArgument(PyScriptParser::PositionalArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStarArgument(PyScriptParser::StarArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoubleStarArgument(PyScriptParser::DoubleStarArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionList(PyScriptParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictItemList(PyScriptParser::DictItemListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictUnpack(PyScriptParser::DictUnpackContext *ctx) override {
    return visitChildren(ctx);
  }


};

