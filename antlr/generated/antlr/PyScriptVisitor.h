
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

    virtual std::any visitSimpleStatement(PyScriptParser::SimpleStatementContext *context) = 0;

    virtual std::any visitSmallStatement(PyScriptParser::SmallStatementContext *context) = 0;

    virtual std::any visitCompoundStatement(PyScriptParser::CompoundStatementContext *context) = 0;

    virtual std::any visitTryStatement(PyScriptParser::TryStatementContext *context) = 0;

    virtual std::any visitExceptClause(PyScriptParser::ExceptClauseContext *context) = 0;

    virtual std::any visitSuite(PyScriptParser::SuiteContext *context) = 0;

    virtual std::any visitFunctionDef(PyScriptParser::FunctionDefContext *context) = 0;

    virtual std::any visitParameterList(PyScriptParser::ParameterListContext *context) = 0;

    virtual std::any visitParameter(PyScriptParser::ParameterContext *context) = 0;

    virtual std::any visitIfStatement(PyScriptParser::IfStatementContext *context) = 0;

    virtual std::any visitWhileStatement(PyScriptParser::WhileStatementContext *context) = 0;

    virtual std::any visitForStatement(PyScriptParser::ForStatementContext *context) = 0;

    virtual std::any visitPassStatement(PyScriptParser::PassStatementContext *context) = 0;

    virtual std::any visitReturnStatement(PyScriptParser::ReturnStatementContext *context) = 0;

    virtual std::any visitSimpleImport(PyScriptParser::SimpleImportContext *context) = 0;

    virtual std::any visitFromImport(PyScriptParser::FromImportContext *context) = 0;

    virtual std::any visitImportItem(PyScriptParser::ImportItemContext *context) = 0;

    virtual std::any visitAssignment(PyScriptParser::AssignmentContext *context) = 0;

    virtual std::any visitExpressionStatement(PyScriptParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitExpression(PyScriptParser::ExpressionContext *context) = 0;

    virtual std::any visitLogicalOr(PyScriptParser::LogicalOrContext *context) = 0;

    virtual std::any visitLogicalAnd(PyScriptParser::LogicalAndContext *context) = 0;

    virtual std::any visitEquality(PyScriptParser::EqualityContext *context) = 0;

    virtual std::any visitComparison(PyScriptParser::ComparisonContext *context) = 0;

    virtual std::any visitAdditive(PyScriptParser::AdditiveContext *context) = 0;

    virtual std::any visitMultiplicative(PyScriptParser::MultiplicativeContext *context) = 0;

    virtual std::any visitPower(PyScriptParser::PowerContext *context) = 0;

    virtual std::any visitUnary(PyScriptParser::UnaryContext *context) = 0;

    virtual std::any visitPrimary(PyScriptParser::PrimaryContext *context) = 0;

    virtual std::any visitNewExpression(PyScriptParser::NewExpressionContext *context) = 0;

    virtual std::any visitAtom(PyScriptParser::AtomContext *context) = 0;

    virtual std::any visitAttributeAccessOp(PyScriptParser::AttributeAccessOpContext *context) = 0;

    virtual std::any visitSubscriptAccessOp(PyScriptParser::SubscriptAccessOpContext *context) = 0;

    virtual std::any visitFunctionCallOp(PyScriptParser::FunctionCallOpContext *context) = 0;

    virtual std::any visitAttributeAccess(PyScriptParser::AttributeAccessContext *context) = 0;

    virtual std::any visitSubscriptAccess(PyScriptParser::SubscriptAccessContext *context) = 0;

    virtual std::any visitSubscriptArg(PyScriptParser::SubscriptArgContext *context) = 0;

    virtual std::any visitFunctionCall(PyScriptParser::FunctionCallContext *context) = 0;

    virtual std::any visitArgumentList(PyScriptParser::ArgumentListContext *context) = 0;

    virtual std::any visitArgument(PyScriptParser::ArgumentContext *context) = 0;

    virtual std::any visitListLiteral(PyScriptParser::ListLiteralContext *context) = 0;

    virtual std::any visitListElements(PyScriptParser::ListElementsContext *context) = 0;

    virtual std::any visitDictLiteral(PyScriptParser::DictLiteralContext *context) = 0;

    virtual std::any visitDictItem(PyScriptParser::DictItemContext *context) = 0;

    virtual std::any visitLiteral(PyScriptParser::LiteralContext *context) = 0;

    virtual std::any visitLambdaExpression(PyScriptParser::LambdaExpressionContext *context) = 0;

    virtual std::any visitDottedName(PyScriptParser::DottedNameContext *context) = 0;


};

