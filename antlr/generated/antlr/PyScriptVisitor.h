
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

    virtual std::any visitStatement(PyScriptParser::StatementContext *context) = 0;

    virtual std::any visitImportStatement(PyScriptParser::ImportStatementContext *context) = 0;

    virtual std::any visitFunctionDefinition(PyScriptParser::FunctionDefinitionContext *context) = 0;

    virtual std::any visitParameterList(PyScriptParser::ParameterListContext *context) = 0;

    virtual std::any visitParameter(PyScriptParser::ParameterContext *context) = 0;

    virtual std::any visitIfStatement(PyScriptParser::IfStatementContext *context) = 0;

    virtual std::any visitWhileStatement(PyScriptParser::WhileStatementContext *context) = 0;

    virtual std::any visitForStatement(PyScriptParser::ForStatementContext *context) = 0;

    virtual std::any visitForControl(PyScriptParser::ForControlContext *context) = 0;

    virtual std::any visitForInit(PyScriptParser::ForInitContext *context) = 0;

    virtual std::any visitForUpdate(PyScriptParser::ForUpdateContext *context) = 0;

    virtual std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *context) = 0;

    virtual std::any visitBlock(PyScriptParser::BlockContext *context) = 0;

    virtual std::any visitAssignment(PyScriptParser::AssignmentContext *context) = 0;

    virtual std::any visitAssignmentOperator(PyScriptParser::AssignmentOperatorContext *context) = 0;

    virtual std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitExpression(PyScriptParser::ExpressionContext *context) = 0;

    virtual std::any visitTernaryExpression(PyScriptParser::TernaryExpressionContext *context) = 0;

    virtual std::any visitLogicalOrExpression(PyScriptParser::LogicalOrExpressionContext *context) = 0;

    virtual std::any visitLogicalAndExpression(PyScriptParser::LogicalAndExpressionContext *context) = 0;

    virtual std::any visitEqualityExpression(PyScriptParser::EqualityExpressionContext *context) = 0;

    virtual std::any visitRelationalExpression(PyScriptParser::RelationalExpressionContext *context) = 0;

    virtual std::any visitAdditiveExpression(PyScriptParser::AdditiveExpressionContext *context) = 0;

    virtual std::any visitMultiplicativeExpression(PyScriptParser::MultiplicativeExpressionContext *context) = 0;

    virtual std::any visitPowerExpression(PyScriptParser::PowerExpressionContext *context) = 0;

    virtual std::any visitUnaryExpression(PyScriptParser::UnaryExpressionContext *context) = 0;

    virtual std::any visitCallOrPrimary(PyScriptParser::CallOrPrimaryContext *context) = 0;

    virtual std::any visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *context) = 0;

    virtual std::any visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *context) = 0;

    virtual std::any visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *context) = 0;

    virtual std::any visitAttributeAccess(PyScriptParser::AttributeAccessContext *context) = 0;

    virtual std::any visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *context) = 0;

    virtual std::any visitFunctionCall(PyScriptParser::FunctionCallContext *context) = 0;

    virtual std::any visitPrimaryExpression(PyScriptParser::PrimaryExpressionContext *context) = 0;

    virtual std::any visitNewExpression(PyScriptParser::NewExpressionContext *context) = 0;

    virtual std::any visitLiteral(PyScriptParser::LiteralContext *context) = 0;

    virtual std::any visitListLiteral(PyScriptParser::ListLiteralContext *context) = 0;

    virtual std::any visitDictLiteral(PyScriptParser::DictLiteralContext *context) = 0;

    virtual std::any visitListComprehension(PyScriptParser::ListComprehensionContext *context) = 0;

    virtual std::any visitLambdaExpression(PyScriptParser::LambdaExpressionContext *context) = 0;

    virtual std::any visitDottedName(PyScriptParser::DottedNameContext *context) = 0;

    virtual std::any visitArgumentList(PyScriptParser::ArgumentListContext *context) = 0;

    virtual std::any visitArgument(PyScriptParser::ArgumentContext *context) = 0;

    virtual std::any visitExpressionList(PyScriptParser::ExpressionListContext *context) = 0;

    virtual std::any visitDictItemList(PyScriptParser::DictItemListContext *context) = 0;

    virtual std::any visitKeyValuePair(PyScriptParser::KeyValuePairContext *context) = 0;

    virtual std::any visitDictUnpack(PyScriptParser::DictUnpackContext *context) = 0;


};

