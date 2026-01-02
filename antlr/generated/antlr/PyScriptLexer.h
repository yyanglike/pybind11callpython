
#include "PyScriptParser.h"


// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  PyScriptLexer : public antlr4::Lexer {
public:
  enum {
    DEF = 1, IF = 2, ELSE = 3, ELIF = 4, FOR = 5, WHILE = 6, RETURN = 7, 
    IMPORT = 8, FROM = 9, AS = 10, IN = 11, PASS = 12, BREAK = 13, CONTINUE = 14, 
    NEW = 15, LAMBDA = 16, TRY = 17, EXCEPT = 18, FINALLY = 19, WITH = 20, 
    ASYNC = 21, AWAIT = 22, CLASS = 23, AT = 24, TRUE = 25, FALSE = 26, 
    NONE = 27, AND = 28, OR = 29, NOT = 30, IS = 31, IS_NOT = 32, NOT_IN = 33, 
    PLUS = 34, MINUS = 35, MUL = 36, DIV = 37, FLOOR_DIV = 38, MOD = 39, 
    EQ = 40, NE = 41, LT = 42, LE = 43, GT = 44, GE = 45, LEFT_SHIFT = 46, 
    RIGHT_SHIFT = 47, BITWISE_AND = 48, BITWISE_OR = 49, BITWISE_XOR = 50, 
    BITWISE_NOT = 51, ASSIGN = 52, PLUS_ASSIGN = 53, MINUS_ASSIGN = 54, 
    MUL_ASSIGN = 55, DIV_ASSIGN = 56, FLOOR_DIV_ASSIGN = 57, MOD_ASSIGN = 58, 
    POW_ASSIGN = 59, BITWISE_AND_ASSIGN = 60, BITWISE_OR_ASSIGN = 61, BITWISE_XOR_ASSIGN = 62, 
    LEFT_SHIFT_ASSIGN = 63, RIGHT_SHIFT_ASSIGN = 64, SEMI = 65, LPAREN = 66, 
    RPAREN = 67, LBRACK = 68, RBRACK = 69, LBRACE = 70, RBRACE = 71, COMMA = 72, 
    COLON = 73, DOT = 74, DOUBLE_STAR = 75, NEWLINE = 76, IDENTIFIER = 77, 
    INTEGER = 78, FLOAT = 79, STRING = 80, WS = 81, COMMENT = 82
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

