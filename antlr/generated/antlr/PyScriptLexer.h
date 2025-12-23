
// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  PyScriptLexer : public antlr4::Lexer {
public:
  enum {
    SEMI = 1, COMMA = 2, DOT = 3, LPAREN = 4, RPAREN = 5, LBRACE = 6, RBRACE = 7, 
    LBRACK = 8, RBRACK = 9, ASSIGN = 10, PLUS_ASSIGN = 11, MINUS_ASSIGN = 12, 
    MUL_ASSIGN = 13, DIV_ASSIGN = 14, MOD_ASSIGN = 15, EQ = 16, NE = 17, 
    LT = 18, LE = 19, GT = 20, GE = 21, PLUS = 22, MINUS = 23, MUL = 24, 
    DIV = 25, MOD = 26, NOT = 27, AND = 28, OR = 29, QUESTION = 30, COLON = 31, 
    DOUBLE_STAR = 32, RETURN = 33, IF = 34, ELSE = 35, WHILE = 36, FOR = 37, 
    DEF = 38, IMPORT = 39, AS = 40, NEW = 41, LAMBDA = 42, IN = 43, IDENTIFIER = 44, 
    INTEGER = 45, FLOAT = 46, STRING = 47, BOOL = 48, NULL_LIT = 49, WS = 50, 
    COMMENT = 51, MULTILINE_COMMENT = 52
  };

  explicit PyScriptLexer(antlr4::CharStream *input);

  ~PyScriptLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

