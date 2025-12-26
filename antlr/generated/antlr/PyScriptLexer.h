
#include "PyScriptParser.h"


// Generated from antlr/PyScript.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  PyScriptLexer : public antlr4::Lexer {
public:
  enum {
    DEF = 1, IF = 2, ELSE = 3, FOR = 4, WHILE = 5, RETURN = 6, IMPORT = 7, 
    FROM = 8, AS = 9, IN = 10, PASS = 11, NEW = 12, LAMBDA = 13, TRY = 14, 
    EXCEPT = 15, FINALLY = 16, TRUE = 17, FALSE = 18, NONE = 19, AND = 20, 
    OR = 21, NOT = 22, PLUS = 23, MINUS = 24, MUL = 25, DIV = 26, MOD = 27, 
    EQ = 28, NE = 29, LT = 30, LE = 31, GT = 32, GE = 33, ASSIGN = 34, SEMI = 35, 
    LPAREN = 36, RPAREN = 37, LBRACK = 38, RBRACK = 39, LBRACE = 40, RBRACE = 41, 
    COMMA = 42, COLON = 43, DOT = 44, DOUBLE_STAR = 45, NEWLINE = 46, IDENTIFIER = 47, 
    INTEGER = 48, FLOAT = 49, STRING = 50, WS = 51, COMMENT = 52
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

