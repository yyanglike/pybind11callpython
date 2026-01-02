
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
    NONLOCAL = 21, ASSERT = 22, TRY = 23, EXCEPT = 24, FINALLY = 25, WITH = 26, 
    ASYNC = 27, AWAIT = 28, CLASS = 29, AT = 30, TRUE = 31, FALSE = 32, 
    NONE = 33, AND = 34, OR = 35, NOT = 36, IS = 37, IS_NOT = 38, NOT_IN = 39, 
    PLUS = 40, MINUS = 41, MUL = 42, DIV = 43, FLOOR_DIV = 44, MOD = 45, 
    EQ = 46, NE = 47, LT = 48, LE = 49, GT = 50, GE = 51, LEFT_SHIFT = 52, 
    RIGHT_SHIFT = 53, BITWISE_AND = 54, BITWISE_OR = 55, BITWISE_XOR = 56, 
    BITWISE_NOT = 57, ASSIGN = 58, WALRUS = 59, PLUS_ASSIGN = 60, MINUS_ASSIGN = 61, 
    MUL_ASSIGN = 62, DIV_ASSIGN = 63, FLOOR_DIV_ASSIGN = 64, MOD_ASSIGN = 65, 
    POW_ASSIGN = 66, BITWISE_AND_ASSIGN = 67, BITWISE_OR_ASSIGN = 68, BITWISE_XOR_ASSIGN = 69, 
    LEFT_SHIFT_ASSIGN = 70, RIGHT_SHIFT_ASSIGN = 71, SEMI = 72, LPAREN = 73, 
    RPAREN = 74, LBRACK = 75, RBRACK = 76, LBRACE = 77, RBRACE = 78, COMMA = 79, 
    COLON = 80, DOT = 81, DOUBLE_STAR = 82, ARROW = 83, NEWLINE = 84, IDENTIFIER = 85, 
    INTEGER = 86, FLOAT = 87, STRING = 88, WS = 89, COMMENT = 90
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

