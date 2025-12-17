
// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "PyScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PyScriptParser.
 */
class  PyScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PyScriptParser.
   */
    virtual std::any visitProgram(PyScriptParser::ProgramContext *context) = 0;

    virtual std::any visitImportStmt(PyScriptParser::ImportStmtContext *context) = 0;

    virtual std::any visitAssignStmt(PyScriptParser::AssignStmtContext *context) = 0;

    virtual std::any visitExprStmt(PyScriptParser::ExprStmtContext *context) = 0;

    virtual std::any visitIfStmt(PyScriptParser::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(PyScriptParser::WhileStmtContext *context) = 0;

    virtual std::any visitReturnStmt(PyScriptParser::ReturnStmtContext *context) = 0;

    virtual std::any visitImportStatement(PyScriptParser::ImportStatementContext *context) = 0;

    virtual std::any visitBinaryAssignment(PyScriptParser::BinaryAssignmentContext *context) = 0;

    virtual std::any visitAttributeAssignment(PyScriptParser::AttributeAssignmentContext *context) = 0;

    virtual std::any visitSubscriptAssignment(PyScriptParser::SubscriptAssignmentContext *context) = 0;

    virtual std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitIfStatement(PyScriptParser::IfStatementContext *context) = 0;

    virtual std::any visitWhileStatement(PyScriptParser::WhileStatementContext *context) = 0;

    virtual std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *context) = 0;

    virtual std::any visitBlock(PyScriptParser::BlockContext *context) = 0;

    virtual std::any visitExpression(PyScriptParser::ExpressionContext *context) = 0;

    virtual std::any visitTernaryExpression(PyScriptParser::TernaryExpressionContext *context) = 0;

    virtual std::any visitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *context) = 0;

    virtual std::any visitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *context) = 0;

    virtual std::any visitEqualityExpression(PyScriptParser::EqualityExpressionContext *context) = 0;

    virtual std::any visitRelationalExpression(PyScriptParser::RelationalExpressionContext *context) = 0;

    virtual std::any visitAdditiveExpression(PyScriptParser::AdditiveExpressionContext *context) = 0;

    virtual std::any visitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *context) = 0;

    virtual std::any visitUnaryExpression(PyScriptParser::UnaryExpressionContext *context) = 0;

    virtual std::any visitLiteralPrimary(PyScriptParser::LiteralPrimaryContext *context) = 0;

    virtual std::any visitIdentifierPrimary(PyScriptParser::IdentifierPrimaryContext *context) = 0;

    virtual std::any visitParenPrimary(PyScriptParser::ParenPrimaryContext *context) = 0;

    virtual std::any visitNewInstancePrimary(PyScriptParser::NewInstancePrimaryContext *context) = 0;

    virtual std::any visitPostfixExpression(PyScriptParser::PostfixExpressionContext *context) = 0;

    virtual std::any visitFunctionCallPostfix(PyScriptParser::FunctionCallPostfixContext *context) = 0;

    virtual std::any visitMemberAccessPostfix(PyScriptParser::MemberAccessPostfixContext *context) = 0;

    virtual std::any visitSubscriptPostfix(PyScriptParser::SubscriptPostfixContext *context) = 0;

    virtual std::any visitArgumentList(PyScriptParser::ArgumentListContext *context) = 0;

    virtual std::any visitIntegerLiteral(PyScriptParser::IntegerLiteralContext *context) = 0;

    virtual std::any visitFloatLiteral(PyScriptParser::FloatLiteralContext *context) = 0;

    virtual std::any visitStringLiteral(PyScriptParser::StringLiteralContext *context) = 0;

    virtual std::any visitBooleanLiteral(PyScriptParser::BooleanLiteralContext *context) = 0;

    virtual std::any visitNullLiteral(PyScriptParser::NullLiteralContext *context) = 0;

    virtual std::any visitListLiteral(PyScriptParser::ListLiteralContext *context) = 0;

    virtual std::any visitDictLiteral(PyScriptParser::DictLiteralContext *context) = 0;

    virtual std::any visitExpressionList(PyScriptParser::ExpressionListContext *context) = 0;

    virtual std::any visitKeyValuePairList(PyScriptParser::KeyValuePairListContext *context) = 0;

    virtual std::any visitKeyValuePair(PyScriptParser::KeyValuePairContext *context) = 0;


};

