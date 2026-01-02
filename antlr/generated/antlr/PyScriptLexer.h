
#include "PyScriptParser.h"


// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  PyScriptLexer : public antlr4::Lexer {
public:
  enum {
    DEF = 1, IF = 2, ELSE = 3, ELIF = 4, FOR = 5, WHILE = 6, RETURN = 7, 
    IMPORT = 8, FROM = 9, AS = 10, IN = 11, PASS = 12, BREAK = 13, CONTINUE = 14, 
    NEW = 15, LAMBDA = 16, YIELD = 17, RAISE = 18, DEL = 19, GLOBAL = 20, 
    NONLOCAL = 21, TRY = 22, EXCEPT = 23, FINALLY = 24, WITH = 25, ASYNC = 26, 
    AWAIT = 27, CLASS = 28, AT = 29, TRUE = 30, FALSE = 31, NONE = 32, AND = 33, 
    OR = 34, NOT = 35, IS = 36, IS_NOT = 37, NOT_IN = 38, PLUS = 39, MINUS = 40, 
    MUL = 41, DIV = 42, FLOOR_DIV = 43, MOD = 44, EQ = 45, NE = 46, LT = 47, 
    LE = 48, GT = 49, GE = 50, LEFT_SHIFT = 51, RIGHT_SHIFT = 52, BITWISE_AND = 53, 
    BITWISE_OR = 54, BITWISE_XOR = 55, BITWISE_NOT = 56, ASSIGN = 57, WALRUS = 58, 
    PLUS_ASSIGN = 59, MINUS_ASSIGN = 60, MUL_ASSIGN = 61, DIV_ASSIGN = 62, 
    FLOOR_DIV_ASSIGN = 63, MOD_ASSIGN = 64, POW_ASSIGN = 65, BITWISE_AND_ASSIGN = 66, 
    BITWISE_OR_ASSIGN = 67, BITWISE_XOR_ASSIGN = 68, LEFT_SHIFT_ASSIGN = 69, 
    RIGHT_SHIFT_ASSIGN = 70, SEMI = 71, LPAREN = 72, RPAREN = 73, LBRACK = 74, 
    RBRACK = 75, LBRACE = 76, RBRACE = 77, COMMA = 78, COLON = 79, DOT = 80, 
    DOUBLE_STAR = 81, NEWLINE = 82, IDENTIFIER = 83, INTEGER = 84, FLOAT = 85, 
    STRING = 86, WS = 87, COMMENT = 88
  };

  explicit PyScriptLexer(antlr4::CharStream *input);

  ~PyScriptLexer() override;


      // Indentation stack
      std::vector<int> indents;
      // Parenthesis depth
      int opened = 0;
      // Pending tokens queue
      std::vector<std::unique_ptr<antlr4::Token>> pending;

      // Emit token to queue
      void emitToken(std::unique_ptr<antlr4::Token> t) {
          pending.push_back(std::move(t));
      }

      std::unique_ptr<antlr4::Token> nextToken() override {
          // Return queued tokens first
          if (!pending.empty()) {
              auto t = std::move(pending.front());
              pending.erase(pending.begin());
              return t;
          }

          auto next = Lexer::nextToken();

          // At EOF, emit pending DEDENTS
          if (next->getType() == EOF && !indents.empty()) {
              while (!indents.empty()) {
                  emitToken(std::make_unique<antlr4::CommonToken>(PyScriptParser::DEDENT));
                  indents.pop_back();
              }
              emitToken(std::make_unique<antlr4::CommonToken>(EOF));
              auto t = std::move(pending.front());
              pending.erase(pending.begin());
              return t;
          }

          return next;
      }

      // Calculate indentation length (tabs as 8 spaces)
      int indentationCount(const std::string& s) {
          int count = 0;
          for (char c : s) {
              if (c == '\t') {
                  count += 8 - (count % 8);
              } else {
                  count++;
              }
          }
          return count;
      }


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void LPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void RPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void LBRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void RBRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void LBRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void RBRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

