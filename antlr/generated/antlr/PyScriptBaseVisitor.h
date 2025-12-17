
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

  virtual std::any visitImportStmt(PyScriptParser::ImportStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignStmt(PyScriptParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(PyScriptParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(PyScriptParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(PyScriptParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(PyScriptParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportStatement(PyScriptParser::ImportStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryAssignment(PyScriptParser::BinaryAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttributeAssignment(PyScriptParser::AttributeAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscriptAssignment(PyScriptParser::SubscriptAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(PyScriptParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(PyScriptParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(PyScriptParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(PyScriptParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernaryExpression(PyScriptParser::TernaryExpressionContext *ctx) override {
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

  virtual std::any visitLiteralPrimary(PyScriptParser::LiteralPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierPrimary(PyScriptParser::IdentifierPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenPrimary(PyScriptParser::ParenPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewInstancePrimary(PyScriptParser::NewInstancePrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostfixExpression(PyScriptParser::PostfixExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallPostfix(PyScriptParser::FunctionCallPostfixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberAccessPostfix(PyScriptParser::MemberAccessPostfixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscriptPostfix(PyScriptParser::SubscriptPostfixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(PyScriptParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerLiteral(PyScriptParser::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatLiteral(PyScriptParser::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteral(PyScriptParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanLiteral(PyScriptParser::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullLiteral(PyScriptParser::NullLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListLiteral(PyScriptParser::ListLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictLiteral(PyScriptParser::DictLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionList(PyScriptParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyValuePairList(PyScriptParser::KeyValuePairListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyValuePair(PyScriptParser::KeyValuePairContext *ctx) override {
    return visitChildren(ctx);
  }


};

