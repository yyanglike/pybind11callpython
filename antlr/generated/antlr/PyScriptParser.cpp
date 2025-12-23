
// Generated from antlr/PyScript.g4 by ANTLR 4.10.1


#include "PyScriptListener.h"
#include "PyScriptVisitor.h"

#include "PyScriptParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PyScriptParserStaticData final {
  PyScriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PyScriptParserStaticData(const PyScriptParserStaticData&) = delete;
  PyScriptParserStaticData(PyScriptParserStaticData&&) = delete;
  PyScriptParserStaticData& operator=(const PyScriptParserStaticData&) = delete;
  PyScriptParserStaticData& operator=(PyScriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag pyscriptParserOnceFlag;
PyScriptParserStaticData *pyscriptParserStaticData = nullptr;

void pyscriptParserInitialize() {
  assert(pyscriptParserStaticData == nullptr);
  auto staticData = std::make_unique<PyScriptParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "importStatement", "functionDefinition", "parameterList", 
      "parameter", "ifStatement", "whileStatement", "forStatement", "forControl", 
      "forInit", "forUpdate", "returnStatement", "block", "assignment", 
      "assignmentOperator", "expressionStatement", "expression", "ternaryExpression", 
      "logicalOrExpression", "logicalAndExpression", "equalityExpression", 
      "relationalExpression", "additiveExpression", "multiplicativeExpression", 
      "powerExpression", "unaryExpression", "callOrPrimary", "postfixOp", 
      "attributeAccess", "subscriptAccess", "functionCall", "primaryExpression", 
      "newExpression", "literal", "listLiteral", "dictLiteral", "listComprehension", 
      "lambdaExpression", "dottedName", "argumentList", "argument", "expressionList", 
      "dictItemList", "dictItem"
    },
    std::vector<std::string>{
      "", "';'", "','", "'.'", "'('", "')'", "'{'", "'}'", "'['", "']'", 
      "'='", "'+='", "'-='", "'*='", "'/='", "'%='", "'=='", "'!='", "'<'", 
      "'<='", "'>'", "'>='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'&&'", 
      "'||'", "'\\u003F'", "':'", "'**'", "'return'", "'if'", "'else'", 
      "'while'", "'for'", "'def'", "'import'", "'as'", "'new'", "'lambda'", 
      "'in'", "", "", "", "", "", "'null'"
    },
    std::vector<std::string>{
      "", "SEMI", "COMMA", "DOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
      "LBRACK", "RBRACK", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "MUL_ASSIGN", 
      "DIV_ASSIGN", "MOD_ASSIGN", "EQ", "NE", "LT", "LE", "GT", "GE", "PLUS", 
      "MINUS", "MUL", "DIV", "MOD", "NOT", "AND", "OR", "QUESTION", "COLON", 
      "DOUBLE_STAR", "RETURN", "IF", "ELSE", "WHILE", "FOR", "DEF", "IMPORT", 
      "AS", "NEW", "LAMBDA", "IN", "IDENTIFIER", "INTEGER", "FLOAT", "STRING", 
      "BOOL", "NULL_LIT", "WS", "COMMENT", "MULTILINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,52,454,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,1,0,4,0,92,8,0,11,0,12,0,93,1,0,1,0,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,3,1,106,8,1,1,2,1,2,1,2,1,2,3,2,112,8,2,1,2,3,2,
  	115,8,2,1,3,1,3,1,3,1,3,3,3,121,8,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,129,8,
  	4,10,4,12,4,132,9,4,1,5,1,5,1,5,3,5,137,8,5,1,5,1,5,1,5,1,5,3,5,143,8,
  	5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,152,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,9,3,9,167,8,9,1,9,1,9,3,9,171,8,9,1,9,1,9,3,9,175,
  	8,9,1,10,1,10,1,11,1,11,1,12,1,12,3,12,183,8,12,1,12,3,12,186,8,12,1,
  	13,1,13,5,13,190,8,13,10,13,12,13,193,9,13,1,13,1,13,1,14,1,14,1,14,1,
  	14,3,14,201,8,14,1,14,1,14,1,14,1,14,3,14,207,8,14,1,14,1,14,1,14,1,14,
  	3,14,213,8,14,3,14,215,8,14,1,15,1,15,1,16,1,16,3,16,221,8,16,1,17,1,
  	17,3,17,225,8,17,1,18,1,18,1,18,1,18,1,18,1,18,3,18,233,8,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,3,18,241,8,18,3,18,243,8,18,1,19,1,19,1,19,5,19,248,
  	8,19,10,19,12,19,251,9,19,1,20,1,20,1,20,5,20,256,8,20,10,20,12,20,259,
  	9,20,1,21,1,21,1,21,5,21,264,8,21,10,21,12,21,267,9,21,1,22,1,22,1,22,
  	5,22,272,8,22,10,22,12,22,275,9,22,1,23,1,23,1,23,5,23,280,8,23,10,23,
  	12,23,283,9,23,1,24,1,24,1,24,5,24,288,8,24,10,24,12,24,291,9,24,1,25,
  	1,25,1,25,3,25,296,8,25,1,26,3,26,299,8,26,1,26,1,26,1,27,1,27,5,27,305,
  	8,27,10,27,12,27,308,9,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,
  	318,8,28,1,28,3,28,321,8,28,1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,
  	30,1,31,1,31,1,31,1,31,1,31,1,31,1,31,3,31,339,8,31,1,31,1,31,3,31,343,
  	8,31,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,
  	3,32,358,8,32,1,33,1,33,1,33,1,33,3,33,364,8,33,1,33,1,33,1,34,1,34,1,
  	35,1,35,3,35,372,8,35,1,35,1,35,1,36,1,36,3,36,378,8,36,1,36,1,36,1,37,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,38,5,38,394,8,38,
  	10,38,12,38,397,9,38,3,38,399,8,38,1,38,1,38,1,38,1,39,1,39,1,39,5,39,
  	407,8,39,10,39,12,39,410,9,39,1,40,1,40,1,40,5,40,415,8,40,10,40,12,40,
  	418,9,40,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,3,41,428,8,41,1,42,1,
  	42,1,42,5,42,433,8,42,10,42,12,42,436,9,42,1,43,1,43,1,43,5,43,441,8,
  	43,10,43,12,43,444,9,43,1,44,1,44,1,44,1,44,1,44,1,44,3,44,452,8,44,1,
  	44,0,0,45,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,
  	44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,
  	0,7,1,0,10,15,1,0,16,17,1,0,18,21,1,0,22,23,1,0,24,26,2,0,23,23,27,27,
  	1,0,45,49,476,0,91,1,0,0,0,2,105,1,0,0,0,4,107,1,0,0,0,6,116,1,0,0,0,
  	8,125,1,0,0,0,10,142,1,0,0,0,12,144,1,0,0,0,14,153,1,0,0,0,16,159,1,0,
  	0,0,18,166,1,0,0,0,20,176,1,0,0,0,22,178,1,0,0,0,24,180,1,0,0,0,26,187,
  	1,0,0,0,28,214,1,0,0,0,30,216,1,0,0,0,32,218,1,0,0,0,34,224,1,0,0,0,36,
  	242,1,0,0,0,38,244,1,0,0,0,40,252,1,0,0,0,42,260,1,0,0,0,44,268,1,0,0,
  	0,46,276,1,0,0,0,48,284,1,0,0,0,50,292,1,0,0,0,52,298,1,0,0,0,54,302,
  	1,0,0,0,56,320,1,0,0,0,58,322,1,0,0,0,60,326,1,0,0,0,62,338,1,0,0,0,64,
  	357,1,0,0,0,66,359,1,0,0,0,68,367,1,0,0,0,70,369,1,0,0,0,72,375,1,0,0,
  	0,74,381,1,0,0,0,76,389,1,0,0,0,78,403,1,0,0,0,80,411,1,0,0,0,82,427,
  	1,0,0,0,84,429,1,0,0,0,86,437,1,0,0,0,88,451,1,0,0,0,90,92,3,2,1,0,91,
  	90,1,0,0,0,92,93,1,0,0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,95,1,0,0,0,95,
  	96,5,0,0,1,96,1,1,0,0,0,97,106,3,4,2,0,98,106,3,6,3,0,99,106,3,28,14,
  	0,100,106,3,12,6,0,101,106,3,14,7,0,102,106,3,16,8,0,103,106,3,24,12,
  	0,104,106,3,32,16,0,105,97,1,0,0,0,105,98,1,0,0,0,105,99,1,0,0,0,105,
  	100,1,0,0,0,105,101,1,0,0,0,105,102,1,0,0,0,105,103,1,0,0,0,105,104,1,
  	0,0,0,106,3,1,0,0,0,107,108,5,39,0,0,108,111,3,78,39,0,109,110,5,40,0,
  	0,110,112,5,44,0,0,111,109,1,0,0,0,111,112,1,0,0,0,112,114,1,0,0,0,113,
  	115,5,1,0,0,114,113,1,0,0,0,114,115,1,0,0,0,115,5,1,0,0,0,116,117,5,38,
  	0,0,117,118,5,44,0,0,118,120,5,4,0,0,119,121,3,8,4,0,120,119,1,0,0,0,
  	120,121,1,0,0,0,121,122,1,0,0,0,122,123,5,5,0,0,123,124,3,26,13,0,124,
  	7,1,0,0,0,125,130,3,10,5,0,126,127,5,2,0,0,127,129,3,10,5,0,128,126,1,
  	0,0,0,129,132,1,0,0,0,130,128,1,0,0,0,130,131,1,0,0,0,131,9,1,0,0,0,132,
  	130,1,0,0,0,133,136,5,44,0,0,134,135,5,10,0,0,135,137,3,34,17,0,136,134,
  	1,0,0,0,136,137,1,0,0,0,137,143,1,0,0,0,138,139,5,24,0,0,139,143,5,44,
  	0,0,140,141,5,32,0,0,141,143,5,44,0,0,142,133,1,0,0,0,142,138,1,0,0,0,
  	142,140,1,0,0,0,143,11,1,0,0,0,144,145,5,34,0,0,145,146,5,4,0,0,146,147,
  	3,34,17,0,147,148,5,5,0,0,148,151,3,26,13,0,149,150,5,35,0,0,150,152,
  	3,26,13,0,151,149,1,0,0,0,151,152,1,0,0,0,152,13,1,0,0,0,153,154,5,36,
  	0,0,154,155,5,4,0,0,155,156,3,34,17,0,156,157,5,5,0,0,157,158,3,26,13,
  	0,158,15,1,0,0,0,159,160,5,37,0,0,160,161,5,4,0,0,161,162,3,18,9,0,162,
  	163,5,5,0,0,163,164,3,26,13,0,164,17,1,0,0,0,165,167,3,20,10,0,166,165,
  	1,0,0,0,166,167,1,0,0,0,167,168,1,0,0,0,168,170,5,1,0,0,169,171,3,34,
  	17,0,170,169,1,0,0,0,170,171,1,0,0,0,171,172,1,0,0,0,172,174,5,1,0,0,
  	173,175,3,22,11,0,174,173,1,0,0,0,174,175,1,0,0,0,175,19,1,0,0,0,176,
  	177,3,28,14,0,177,21,1,0,0,0,178,179,3,28,14,0,179,23,1,0,0,0,180,182,
  	5,33,0,0,181,183,3,34,17,0,182,181,1,0,0,0,182,183,1,0,0,0,183,185,1,
  	0,0,0,184,186,5,1,0,0,185,184,1,0,0,0,185,186,1,0,0,0,186,25,1,0,0,0,
  	187,191,5,6,0,0,188,190,3,2,1,0,189,188,1,0,0,0,190,193,1,0,0,0,191,189,
  	1,0,0,0,191,192,1,0,0,0,192,194,1,0,0,0,193,191,1,0,0,0,194,195,5,7,0,
  	0,195,27,1,0,0,0,196,197,5,44,0,0,197,198,3,30,15,0,198,200,3,34,17,0,
  	199,201,5,1,0,0,200,199,1,0,0,0,200,201,1,0,0,0,201,215,1,0,0,0,202,203,
  	3,58,29,0,203,204,5,10,0,0,204,206,3,34,17,0,205,207,5,1,0,0,206,205,
  	1,0,0,0,206,207,1,0,0,0,207,215,1,0,0,0,208,209,3,60,30,0,209,210,5,10,
  	0,0,210,212,3,34,17,0,211,213,5,1,0,0,212,211,1,0,0,0,212,213,1,0,0,0,
  	213,215,1,0,0,0,214,196,1,0,0,0,214,202,1,0,0,0,214,208,1,0,0,0,215,29,
  	1,0,0,0,216,217,7,0,0,0,217,31,1,0,0,0,218,220,3,34,17,0,219,221,5,1,
  	0,0,220,219,1,0,0,0,220,221,1,0,0,0,221,33,1,0,0,0,222,225,3,28,14,0,
  	223,225,3,36,18,0,224,222,1,0,0,0,224,223,1,0,0,0,225,35,1,0,0,0,226,
  	232,3,38,19,0,227,228,5,34,0,0,228,229,3,38,19,0,229,230,5,35,0,0,230,
  	231,3,36,18,0,231,233,1,0,0,0,232,227,1,0,0,0,232,233,1,0,0,0,233,243,
  	1,0,0,0,234,240,3,38,19,0,235,236,5,30,0,0,236,237,3,34,17,0,237,238,
  	5,31,0,0,238,239,3,36,18,0,239,241,1,0,0,0,240,235,1,0,0,0,240,241,1,
  	0,0,0,241,243,1,0,0,0,242,226,1,0,0,0,242,234,1,0,0,0,243,37,1,0,0,0,
  	244,249,3,40,20,0,245,246,5,29,0,0,246,248,3,40,20,0,247,245,1,0,0,0,
  	248,251,1,0,0,0,249,247,1,0,0,0,249,250,1,0,0,0,250,39,1,0,0,0,251,249,
  	1,0,0,0,252,257,3,42,21,0,253,254,5,28,0,0,254,256,3,42,21,0,255,253,
  	1,0,0,0,256,259,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,41,1,0,0,
  	0,259,257,1,0,0,0,260,265,3,44,22,0,261,262,7,1,0,0,262,264,3,44,22,0,
  	263,261,1,0,0,0,264,267,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,43,
  	1,0,0,0,267,265,1,0,0,0,268,273,3,46,23,0,269,270,7,2,0,0,270,272,3,46,
  	23,0,271,269,1,0,0,0,272,275,1,0,0,0,273,271,1,0,0,0,273,274,1,0,0,0,
  	274,45,1,0,0,0,275,273,1,0,0,0,276,281,3,48,24,0,277,278,7,3,0,0,278,
  	280,3,48,24,0,279,277,1,0,0,0,280,283,1,0,0,0,281,279,1,0,0,0,281,282,
  	1,0,0,0,282,47,1,0,0,0,283,281,1,0,0,0,284,289,3,50,25,0,285,286,7,4,
  	0,0,286,288,3,50,25,0,287,285,1,0,0,0,288,291,1,0,0,0,289,287,1,0,0,0,
  	289,290,1,0,0,0,290,49,1,0,0,0,291,289,1,0,0,0,292,295,3,52,26,0,293,
  	294,5,32,0,0,294,296,3,50,25,0,295,293,1,0,0,0,295,296,1,0,0,0,296,51,
  	1,0,0,0,297,299,7,5,0,0,298,297,1,0,0,0,298,299,1,0,0,0,299,300,1,0,0,
  	0,300,301,3,54,27,0,301,53,1,0,0,0,302,306,3,64,32,0,303,305,3,56,28,
  	0,304,303,1,0,0,0,305,308,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,0,307,
  	55,1,0,0,0,308,306,1,0,0,0,309,310,5,3,0,0,310,321,5,44,0,0,311,312,5,
  	8,0,0,312,313,3,34,17,0,313,314,5,9,0,0,314,321,1,0,0,0,315,317,5,4,0,
  	0,316,318,3,80,40,0,317,316,1,0,0,0,317,318,1,0,0,0,318,319,1,0,0,0,319,
  	321,5,5,0,0,320,309,1,0,0,0,320,311,1,0,0,0,320,315,1,0,0,0,321,57,1,
  	0,0,0,322,323,3,64,32,0,323,324,5,3,0,0,324,325,5,44,0,0,325,59,1,0,0,
  	0,326,327,3,64,32,0,327,328,5,8,0,0,328,329,3,34,17,0,329,330,5,9,0,0,
  	330,61,1,0,0,0,331,339,3,78,39,0,332,339,3,58,29,0,333,339,3,60,30,0,
  	334,335,5,4,0,0,335,336,3,34,17,0,336,337,5,5,0,0,337,339,1,0,0,0,338,
  	331,1,0,0,0,338,332,1,0,0,0,338,333,1,0,0,0,338,334,1,0,0,0,339,340,1,
  	0,0,0,340,342,5,4,0,0,341,343,3,80,40,0,342,341,1,0,0,0,342,343,1,0,0,
  	0,343,344,1,0,0,0,344,345,5,5,0,0,345,63,1,0,0,0,346,358,3,68,34,0,347,
  	358,3,78,39,0,348,349,5,4,0,0,349,350,3,34,17,0,350,351,5,5,0,0,351,358,
  	1,0,0,0,352,358,3,70,35,0,353,358,3,72,36,0,354,358,3,66,33,0,355,358,
  	3,76,38,0,356,358,3,74,37,0,357,346,1,0,0,0,357,347,1,0,0,0,357,348,1,
  	0,0,0,357,352,1,0,0,0,357,353,1,0,0,0,357,354,1,0,0,0,357,355,1,0,0,0,
  	357,356,1,0,0,0,358,65,1,0,0,0,359,360,5,41,0,0,360,361,3,78,39,0,361,
  	363,5,4,0,0,362,364,3,80,40,0,363,362,1,0,0,0,363,364,1,0,0,0,364,365,
  	1,0,0,0,365,366,5,5,0,0,366,67,1,0,0,0,367,368,7,6,0,0,368,69,1,0,0,0,
  	369,371,5,8,0,0,370,372,3,84,42,0,371,370,1,0,0,0,371,372,1,0,0,0,372,
  	373,1,0,0,0,373,374,5,9,0,0,374,71,1,0,0,0,375,377,5,6,0,0,376,378,3,
  	86,43,0,377,376,1,0,0,0,377,378,1,0,0,0,378,379,1,0,0,0,379,380,5,7,0,
  	0,380,73,1,0,0,0,381,382,5,8,0,0,382,383,3,34,17,0,383,384,5,37,0,0,384,
  	385,5,44,0,0,385,386,5,43,0,0,386,387,3,34,17,0,387,388,5,9,0,0,388,75,
  	1,0,0,0,389,398,5,42,0,0,390,395,5,44,0,0,391,392,5,2,0,0,392,394,5,44,
  	0,0,393,391,1,0,0,0,394,397,1,0,0,0,395,393,1,0,0,0,395,396,1,0,0,0,396,
  	399,1,0,0,0,397,395,1,0,0,0,398,390,1,0,0,0,398,399,1,0,0,0,399,400,1,
  	0,0,0,400,401,5,31,0,0,401,402,3,34,17,0,402,77,1,0,0,0,403,408,5,44,
  	0,0,404,405,5,3,0,0,405,407,5,44,0,0,406,404,1,0,0,0,407,410,1,0,0,0,
  	408,406,1,0,0,0,408,409,1,0,0,0,409,79,1,0,0,0,410,408,1,0,0,0,411,416,
  	3,82,41,0,412,413,5,2,0,0,413,415,3,82,41,0,414,412,1,0,0,0,415,418,1,
  	0,0,0,416,414,1,0,0,0,416,417,1,0,0,0,417,81,1,0,0,0,418,416,1,0,0,0,
  	419,428,3,34,17,0,420,421,5,44,0,0,421,422,5,10,0,0,422,428,3,34,17,0,
  	423,424,5,24,0,0,424,428,3,34,17,0,425,426,5,32,0,0,426,428,3,34,17,0,
  	427,419,1,0,0,0,427,420,1,0,0,0,427,423,1,0,0,0,427,425,1,0,0,0,428,83,
  	1,0,0,0,429,434,3,34,17,0,430,431,5,2,0,0,431,433,3,34,17,0,432,430,1,
  	0,0,0,433,436,1,0,0,0,434,432,1,0,0,0,434,435,1,0,0,0,435,85,1,0,0,0,
  	436,434,1,0,0,0,437,442,3,88,44,0,438,439,5,2,0,0,439,441,3,88,44,0,440,
  	438,1,0,0,0,441,444,1,0,0,0,442,440,1,0,0,0,442,443,1,0,0,0,443,87,1,
  	0,0,0,444,442,1,0,0,0,445,446,3,34,17,0,446,447,5,31,0,0,447,448,3,34,
  	17,0,448,452,1,0,0,0,449,450,5,32,0,0,450,452,3,34,17,0,451,445,1,0,0,
  	0,451,449,1,0,0,0,452,89,1,0,0,0,49,93,105,111,114,120,130,136,142,151,
  	166,170,174,182,185,191,200,206,212,214,220,224,232,240,242,249,257,265,
  	273,281,289,295,298,306,317,320,338,342,357,363,371,377,395,398,408,416,
  	427,434,442,451
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pyscriptParserStaticData = staticData.release();
}

}

PyScriptParser::PyScriptParser(TokenStream *input) : PyScriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PyScriptParser::PyScriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PyScriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *pyscriptParserStaticData->atn, pyscriptParserStaticData->decisionToDFA, pyscriptParserStaticData->sharedContextCache, options);
}

PyScriptParser::~PyScriptParser() {
  delete _interpreter;
}

const atn::ATN& PyScriptParser::getATN() const {
  return *pyscriptParserStaticData->atn;
}

std::string PyScriptParser::getGrammarFileName() const {
  return "PyScript.g4";
}

const std::vector<std::string>& PyScriptParser::getRuleNames() const {
  return pyscriptParserStaticData->ruleNames;
}

const dfa::Vocabulary& PyScriptParser::getVocabulary() const {
  return pyscriptParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PyScriptParser::getSerializedATN() const {
  return pyscriptParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

PyScriptParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ProgramContext::EOF() {
  return getToken(PyScriptParser::EOF, 0);
}

std::vector<PyScriptParser::StatementContext *> PyScriptParser::ProgramContext::statement() {
  return getRuleContexts<PyScriptParser::StatementContext>();
}

PyScriptParser::StatementContext* PyScriptParser::ProgramContext::statement(size_t i) {
  return getRuleContext<PyScriptParser::StatementContext>(i);
}


size_t PyScriptParser::ProgramContext::getRuleIndex() const {
  return PyScriptParser::RuleProgram;
}

void PyScriptParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void PyScriptParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any PyScriptParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ProgramContext* PyScriptParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PyScriptParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(90);
      statement();
      setState(93); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::RETURN)
      | (1ULL << PyScriptParser::IF)
      | (1ULL << PyScriptParser::WHILE)
      | (1ULL << PyScriptParser::FOR)
      | (1ULL << PyScriptParser::DEF)
      | (1ULL << PyScriptParser::IMPORT)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0));
    setState(95);
    match(PyScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PyScriptParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::ImportStatementContext* PyScriptParser::StatementContext::importStatement() {
  return getRuleContext<PyScriptParser::ImportStatementContext>(0);
}

PyScriptParser::FunctionDefinitionContext* PyScriptParser::StatementContext::functionDefinition() {
  return getRuleContext<PyScriptParser::FunctionDefinitionContext>(0);
}

PyScriptParser::AssignmentContext* PyScriptParser::StatementContext::assignment() {
  return getRuleContext<PyScriptParser::AssignmentContext>(0);
}

PyScriptParser::IfStatementContext* PyScriptParser::StatementContext::ifStatement() {
  return getRuleContext<PyScriptParser::IfStatementContext>(0);
}

PyScriptParser::WhileStatementContext* PyScriptParser::StatementContext::whileStatement() {
  return getRuleContext<PyScriptParser::WhileStatementContext>(0);
}

PyScriptParser::ForStatementContext* PyScriptParser::StatementContext::forStatement() {
  return getRuleContext<PyScriptParser::ForStatementContext>(0);
}

PyScriptParser::ReturnStatementContext* PyScriptParser::StatementContext::returnStatement() {
  return getRuleContext<PyScriptParser::ReturnStatementContext>(0);
}

PyScriptParser::ExpressionStatementContext* PyScriptParser::StatementContext::expressionStatement() {
  return getRuleContext<PyScriptParser::ExpressionStatementContext>(0);
}


size_t PyScriptParser::StatementContext::getRuleIndex() const {
  return PyScriptParser::RuleStatement;
}

void PyScriptParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void PyScriptParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any PyScriptParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::StatementContext* PyScriptParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, PyScriptParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      importStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(98);
      functionDefinition();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(99);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(100);
      ifStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(101);
      whileStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(102);
      forStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(103);
      returnStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(104);
      expressionStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportStatementContext ------------------------------------------------------------------

PyScriptParser::ImportStatementContext::ImportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ImportStatementContext::IMPORT() {
  return getToken(PyScriptParser::IMPORT, 0);
}

PyScriptParser::DottedNameContext* PyScriptParser::ImportStatementContext::dottedName() {
  return getRuleContext<PyScriptParser::DottedNameContext>(0);
}

tree::TerminalNode* PyScriptParser::ImportStatementContext::AS() {
  return getToken(PyScriptParser::AS, 0);
}

tree::TerminalNode* PyScriptParser::ImportStatementContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::ImportStatementContext::SEMI() {
  return getToken(PyScriptParser::SEMI, 0);
}


size_t PyScriptParser::ImportStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleImportStatement;
}

void PyScriptParser::ImportStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStatement(this);
}

void PyScriptParser::ImportStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStatement(this);
}


std::any PyScriptParser::ImportStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitImportStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ImportStatementContext* PyScriptParser::importStatement() {
  ImportStatementContext *_localctx = _tracker.createInstance<ImportStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, PyScriptParser::RuleImportStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(PyScriptParser::IMPORT);
    setState(108);
    dottedName();
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(109);
      match(PyScriptParser::AS);
      setState(110);
      match(PyScriptParser::IDENTIFIER);
    }
    setState(114);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::SEMI) {
      setState(113);
      match(PyScriptParser::SEMI);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

PyScriptParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::FunctionDefinitionContext::DEF() {
  return getToken(PyScriptParser::DEF, 0);
}

tree::TerminalNode* PyScriptParser::FunctionDefinitionContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::FunctionDefinitionContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

tree::TerminalNode* PyScriptParser::FunctionDefinitionContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::BlockContext* PyScriptParser::FunctionDefinitionContext::block() {
  return getRuleContext<PyScriptParser::BlockContext>(0);
}

PyScriptParser::ParameterListContext* PyScriptParser::FunctionDefinitionContext::parameterList() {
  return getRuleContext<PyScriptParser::ParameterListContext>(0);
}


size_t PyScriptParser::FunctionDefinitionContext::getRuleIndex() const {
  return PyScriptParser::RuleFunctionDefinition;
}

void PyScriptParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void PyScriptParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


std::any PyScriptParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::FunctionDefinitionContext* PyScriptParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 6, PyScriptParser::RuleFunctionDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    match(PyScriptParser::DEF);
    setState(117);
    match(PyScriptParser::IDENTIFIER);
    setState(118);
    match(PyScriptParser::LPAREN);
    setState(120);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::IDENTIFIER))) != 0)) {
      setState(119);
      parameterList();
    }
    setState(122);
    match(PyScriptParser::RPAREN);
    setState(123);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

PyScriptParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ParameterContext *> PyScriptParser::ParameterListContext::parameter() {
  return getRuleContexts<PyScriptParser::ParameterContext>();
}

PyScriptParser::ParameterContext* PyScriptParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<PyScriptParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ParameterListContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::ParameterListContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::ParameterListContext::getRuleIndex() const {
  return PyScriptParser::RuleParameterList;
}

void PyScriptParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void PyScriptParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


std::any PyScriptParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ParameterListContext* PyScriptParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 8, PyScriptParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    parameter();
    setState(130);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(126);
      match(PyScriptParser::COMMA);
      setState(127);
      parameter();
      setState(132);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

PyScriptParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ParameterContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::ParameterContext::ASSIGN() {
  return getToken(PyScriptParser::ASSIGN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::ParameterContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::ParameterContext::MUL() {
  return getToken(PyScriptParser::MUL, 0);
}

tree::TerminalNode* PyScriptParser::ParameterContext::DOUBLE_STAR() {
  return getToken(PyScriptParser::DOUBLE_STAR, 0);
}


size_t PyScriptParser::ParameterContext::getRuleIndex() const {
  return PyScriptParser::RuleParameter;
}

void PyScriptParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void PyScriptParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


std::any PyScriptParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ParameterContext* PyScriptParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 10, PyScriptParser::RuleParameter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(133);
        match(PyScriptParser::IDENTIFIER);
        setState(136);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::ASSIGN) {
          setState(134);
          match(PyScriptParser::ASSIGN);
          setState(135);
          expression();
        }
        break;
      }

      case PyScriptParser::MUL: {
        enterOuterAlt(_localctx, 2);
        setState(138);
        match(PyScriptParser::MUL);
        setState(139);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 3);
        setState(140);
        match(PyScriptParser::DOUBLE_STAR);
        setState(141);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

PyScriptParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::IfStatementContext::IF() {
  return getToken(PyScriptParser::IF, 0);
}

tree::TerminalNode* PyScriptParser::IfStatementContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::IfStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::IfStatementContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

std::vector<PyScriptParser::BlockContext *> PyScriptParser::IfStatementContext::block() {
  return getRuleContexts<PyScriptParser::BlockContext>();
}

PyScriptParser::BlockContext* PyScriptParser::IfStatementContext::block(size_t i) {
  return getRuleContext<PyScriptParser::BlockContext>(i);
}

tree::TerminalNode* PyScriptParser::IfStatementContext::ELSE() {
  return getToken(PyScriptParser::ELSE, 0);
}


size_t PyScriptParser::IfStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleIfStatement;
}

void PyScriptParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void PyScriptParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


std::any PyScriptParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::IfStatementContext* PyScriptParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, PyScriptParser::RuleIfStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(PyScriptParser::IF);
    setState(145);
    match(PyScriptParser::LPAREN);
    setState(146);
    expression();
    setState(147);
    match(PyScriptParser::RPAREN);
    setState(148);
    block();
    setState(151);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(149);
      match(PyScriptParser::ELSE);
      setState(150);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

PyScriptParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::WhileStatementContext::WHILE() {
  return getToken(PyScriptParser::WHILE, 0);
}

tree::TerminalNode* PyScriptParser::WhileStatementContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::WhileStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::WhileStatementContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::BlockContext* PyScriptParser::WhileStatementContext::block() {
  return getRuleContext<PyScriptParser::BlockContext>(0);
}


size_t PyScriptParser::WhileStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleWhileStatement;
}

void PyScriptParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}

void PyScriptParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}


std::any PyScriptParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::WhileStatementContext* PyScriptParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, PyScriptParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(PyScriptParser::WHILE);
    setState(154);
    match(PyScriptParser::LPAREN);
    setState(155);
    expression();
    setState(156);
    match(PyScriptParser::RPAREN);
    setState(157);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

PyScriptParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ForStatementContext::FOR() {
  return getToken(PyScriptParser::FOR, 0);
}

tree::TerminalNode* PyScriptParser::ForStatementContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

PyScriptParser::ForControlContext* PyScriptParser::ForStatementContext::forControl() {
  return getRuleContext<PyScriptParser::ForControlContext>(0);
}

tree::TerminalNode* PyScriptParser::ForStatementContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::BlockContext* PyScriptParser::ForStatementContext::block() {
  return getRuleContext<PyScriptParser::BlockContext>(0);
}


size_t PyScriptParser::ForStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleForStatement;
}

void PyScriptParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void PyScriptParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}


std::any PyScriptParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ForStatementContext* PyScriptParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, PyScriptParser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(PyScriptParser::FOR);
    setState(160);
    match(PyScriptParser::LPAREN);
    setState(161);
    forControl();
    setState(162);
    match(PyScriptParser::RPAREN);
    setState(163);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForControlContext ------------------------------------------------------------------

PyScriptParser::ForControlContext::ForControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PyScriptParser::ForControlContext::SEMI() {
  return getTokens(PyScriptParser::SEMI);
}

tree::TerminalNode* PyScriptParser::ForControlContext::SEMI(size_t i) {
  return getToken(PyScriptParser::SEMI, i);
}

PyScriptParser::ForInitContext* PyScriptParser::ForControlContext::forInit() {
  return getRuleContext<PyScriptParser::ForInitContext>(0);
}

PyScriptParser::ExpressionContext* PyScriptParser::ForControlContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::ForUpdateContext* PyScriptParser::ForControlContext::forUpdate() {
  return getRuleContext<PyScriptParser::ForUpdateContext>(0);
}


size_t PyScriptParser::ForControlContext::getRuleIndex() const {
  return PyScriptParser::RuleForControl;
}

void PyScriptParser::ForControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForControl(this);
}

void PyScriptParser::ForControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForControl(this);
}


std::any PyScriptParser::ForControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitForControl(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ForControlContext* PyScriptParser::forControl() {
  ForControlContext *_localctx = _tracker.createInstance<ForControlContext>(_ctx, getState());
  enterRule(_localctx, 18, PyScriptParser::RuleForControl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(165);
      forInit();
    }
    setState(168);
    match(PyScriptParser::SEMI);
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(169);
      expression();
    }
    setState(172);
    match(PyScriptParser::SEMI);
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(173);
      forUpdate();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForInitContext ------------------------------------------------------------------

PyScriptParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::AssignmentContext* PyScriptParser::ForInitContext::assignment() {
  return getRuleContext<PyScriptParser::AssignmentContext>(0);
}


size_t PyScriptParser::ForInitContext::getRuleIndex() const {
  return PyScriptParser::RuleForInit;
}

void PyScriptParser::ForInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInit(this);
}

void PyScriptParser::ForInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInit(this);
}


std::any PyScriptParser::ForInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitForInit(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ForInitContext* PyScriptParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 20, PyScriptParser::RuleForInit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    assignment();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForUpdateContext ------------------------------------------------------------------

PyScriptParser::ForUpdateContext::ForUpdateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::AssignmentContext* PyScriptParser::ForUpdateContext::assignment() {
  return getRuleContext<PyScriptParser::AssignmentContext>(0);
}


size_t PyScriptParser::ForUpdateContext::getRuleIndex() const {
  return PyScriptParser::RuleForUpdate;
}

void PyScriptParser::ForUpdateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForUpdate(this);
}

void PyScriptParser::ForUpdateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForUpdate(this);
}


std::any PyScriptParser::ForUpdateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitForUpdate(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ForUpdateContext* PyScriptParser::forUpdate() {
  ForUpdateContext *_localctx = _tracker.createInstance<ForUpdateContext>(_ctx, getState());
  enterRule(_localctx, 22, PyScriptParser::RuleForUpdate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    assignment();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

PyScriptParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ReturnStatementContext::RETURN() {
  return getToken(PyScriptParser::RETURN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::ReturnStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::ReturnStatementContext::SEMI() {
  return getToken(PyScriptParser::SEMI, 0);
}


size_t PyScriptParser::ReturnStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleReturnStatement;
}

void PyScriptParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void PyScriptParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any PyScriptParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ReturnStatementContext* PyScriptParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, PyScriptParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(PyScriptParser::RETURN);
    setState(182);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(181);
      expression();
      break;
    }

    default:
      break;
    }
    setState(185);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::SEMI) {
      setState(184);
      match(PyScriptParser::SEMI);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

PyScriptParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::BlockContext::LBRACE() {
  return getToken(PyScriptParser::LBRACE, 0);
}

tree::TerminalNode* PyScriptParser::BlockContext::RBRACE() {
  return getToken(PyScriptParser::RBRACE, 0);
}

std::vector<PyScriptParser::StatementContext *> PyScriptParser::BlockContext::statement() {
  return getRuleContexts<PyScriptParser::StatementContext>();
}

PyScriptParser::StatementContext* PyScriptParser::BlockContext::statement(size_t i) {
  return getRuleContext<PyScriptParser::StatementContext>(i);
}


size_t PyScriptParser::BlockContext::getRuleIndex() const {
  return PyScriptParser::RuleBlock;
}

void PyScriptParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void PyScriptParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any PyScriptParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::BlockContext* PyScriptParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, PyScriptParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    match(PyScriptParser::LBRACE);
    setState(191);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::RETURN)
      | (1ULL << PyScriptParser::IF)
      | (1ULL << PyScriptParser::WHILE)
      | (1ULL << PyScriptParser::FOR)
      | (1ULL << PyScriptParser::DEF)
      | (1ULL << PyScriptParser::IMPORT)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(188);
      statement();
      setState(193);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(194);
    match(PyScriptParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

PyScriptParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::AssignmentContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::AssignmentOperatorContext* PyScriptParser::AssignmentContext::assignmentOperator() {
  return getRuleContext<PyScriptParser::AssignmentOperatorContext>(0);
}

PyScriptParser::ExpressionContext* PyScriptParser::AssignmentContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::SEMI() {
  return getToken(PyScriptParser::SEMI, 0);
}

PyScriptParser::AttributeAccessContext* PyScriptParser::AssignmentContext::attributeAccess() {
  return getRuleContext<PyScriptParser::AttributeAccessContext>(0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::ASSIGN() {
  return getToken(PyScriptParser::ASSIGN, 0);
}

PyScriptParser::SubscriptAccessContext* PyScriptParser::AssignmentContext::subscriptAccess() {
  return getRuleContext<PyScriptParser::SubscriptAccessContext>(0);
}


size_t PyScriptParser::AssignmentContext::getRuleIndex() const {
  return PyScriptParser::RuleAssignment;
}

void PyScriptParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void PyScriptParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any PyScriptParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AssignmentContext* PyScriptParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 28, PyScriptParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(214);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(196);
      match(PyScriptParser::IDENTIFIER);
      setState(197);
      assignmentOperator();
      setState(198);
      expression();
      setState(200);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(199);
        match(PyScriptParser::SEMI);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(202);
      attributeAccess();
      setState(203);
      match(PyScriptParser::ASSIGN);
      setState(204);
      expression();
      setState(206);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(205);
        match(PyScriptParser::SEMI);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(208);
      subscriptAccess();
      setState(209);
      match(PyScriptParser::ASSIGN);
      setState(210);
      expression();
      setState(212);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(211);
        match(PyScriptParser::SEMI);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

PyScriptParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::AssignmentOperatorContext::ASSIGN() {
  return getToken(PyScriptParser::ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentOperatorContext::PLUS_ASSIGN() {
  return getToken(PyScriptParser::PLUS_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentOperatorContext::MINUS_ASSIGN() {
  return getToken(PyScriptParser::MINUS_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentOperatorContext::MUL_ASSIGN() {
  return getToken(PyScriptParser::MUL_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentOperatorContext::DIV_ASSIGN() {
  return getToken(PyScriptParser::DIV_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentOperatorContext::MOD_ASSIGN() {
  return getToken(PyScriptParser::MOD_ASSIGN, 0);
}


size_t PyScriptParser::AssignmentOperatorContext::getRuleIndex() const {
  return PyScriptParser::RuleAssignmentOperator;
}

void PyScriptParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void PyScriptParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


std::any PyScriptParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AssignmentOperatorContext* PyScriptParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 30, PyScriptParser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::ASSIGN)
      | (1ULL << PyScriptParser::PLUS_ASSIGN)
      | (1ULL << PyScriptParser::MINUS_ASSIGN)
      | (1ULL << PyScriptParser::MUL_ASSIGN)
      | (1ULL << PyScriptParser::DIV_ASSIGN)
      | (1ULL << PyScriptParser::MOD_ASSIGN))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

PyScriptParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::ExpressionContext* PyScriptParser::ExpressionStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::ExpressionStatementContext::SEMI() {
  return getToken(PyScriptParser::SEMI, 0);
}


size_t PyScriptParser::ExpressionStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleExpressionStatement;
}

void PyScriptParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void PyScriptParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


std::any PyScriptParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ExpressionStatementContext* PyScriptParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, PyScriptParser::RuleExpressionStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    expression();
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::SEMI) {
      setState(219);
      match(PyScriptParser::SEMI);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PyScriptParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::AssignmentContext* PyScriptParser::ExpressionContext::assignment() {
  return getRuleContext<PyScriptParser::AssignmentContext>(0);
}

PyScriptParser::TernaryExpressionContext* PyScriptParser::ExpressionContext::ternaryExpression() {
  return getRuleContext<PyScriptParser::TernaryExpressionContext>(0);
}


size_t PyScriptParser::ExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleExpression;
}

void PyScriptParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void PyScriptParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any PyScriptParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ExpressionContext* PyScriptParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 34, PyScriptParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(222);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(223);
      ternaryExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TernaryExpressionContext ------------------------------------------------------------------

PyScriptParser::TernaryExpressionContext::TernaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::LogicalOrExpressionContext *> PyScriptParser::TernaryExpressionContext::logicalOrExpression() {
  return getRuleContexts<PyScriptParser::LogicalOrExpressionContext>();
}

PyScriptParser::LogicalOrExpressionContext* PyScriptParser::TernaryExpressionContext::logicalOrExpression(size_t i) {
  return getRuleContext<PyScriptParser::LogicalOrExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::TernaryExpressionContext::IF() {
  return getToken(PyScriptParser::IF, 0);
}

tree::TerminalNode* PyScriptParser::TernaryExpressionContext::ELSE() {
  return getToken(PyScriptParser::ELSE, 0);
}

PyScriptParser::TernaryExpressionContext* PyScriptParser::TernaryExpressionContext::ternaryExpression() {
  return getRuleContext<PyScriptParser::TernaryExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::TernaryExpressionContext::QUESTION() {
  return getToken(PyScriptParser::QUESTION, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::TernaryExpressionContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::TernaryExpressionContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}


size_t PyScriptParser::TernaryExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleTernaryExpression;
}

void PyScriptParser::TernaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTernaryExpression(this);
}

void PyScriptParser::TernaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTernaryExpression(this);
}


std::any PyScriptParser::TernaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitTernaryExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::TernaryExpressionContext* PyScriptParser::ternaryExpression() {
  TernaryExpressionContext *_localctx = _tracker.createInstance<TernaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 36, PyScriptParser::RuleTernaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(226);
      logicalOrExpression();
      setState(232);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
      case 1: {
        setState(227);
        match(PyScriptParser::IF);
        setState(228);
        logicalOrExpression();
        setState(229);
        match(PyScriptParser::ELSE);
        setState(230);
        ternaryExpression();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(234);
      logicalOrExpression();
      setState(240);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(235);
        match(PyScriptParser::QUESTION);
        setState(236);
        expression();
        setState(237);
        match(PyScriptParser::COLON);
        setState(238);
        ternaryExpression();
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

PyScriptParser::LogicalOrExpressionContext::LogicalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::LogicalAndExpressionContext *> PyScriptParser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContexts<PyScriptParser::LogicalAndExpressionContext>();
}

PyScriptParser::LogicalAndExpressionContext* PyScriptParser::LogicalOrExpressionContext::logicalAndExpression(size_t i) {
  return getRuleContext<PyScriptParser::LogicalAndExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::LogicalOrExpressionContext::OR() {
  return getTokens(PyScriptParser::OR);
}

tree::TerminalNode* PyScriptParser::LogicalOrExpressionContext::OR(size_t i) {
  return getToken(PyScriptParser::OR, i);
}


size_t PyScriptParser::LogicalOrExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleLogicalOrExpression;
}

void PyScriptParser::LogicalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}

void PyScriptParser::LogicalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}


std::any PyScriptParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LogicalOrExpressionContext* PyScriptParser::logicalOrExpression() {
  LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 38, PyScriptParser::RuleLogicalOrExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(244);
    logicalAndExpression();
    setState(249);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(245);
        match(PyScriptParser::OR);
        setState(246);
        logicalAndExpression(); 
      }
      setState(251);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

PyScriptParser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::EqualityExpressionContext *> PyScriptParser::LogicalAndExpressionContext::equalityExpression() {
  return getRuleContexts<PyScriptParser::EqualityExpressionContext>();
}

PyScriptParser::EqualityExpressionContext* PyScriptParser::LogicalAndExpressionContext::equalityExpression(size_t i) {
  return getRuleContext<PyScriptParser::EqualityExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::LogicalAndExpressionContext::AND() {
  return getTokens(PyScriptParser::AND);
}

tree::TerminalNode* PyScriptParser::LogicalAndExpressionContext::AND(size_t i) {
  return getToken(PyScriptParser::AND, i);
}


size_t PyScriptParser::LogicalAndExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleLogicalAndExpression;
}

void PyScriptParser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}

void PyScriptParser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}


std::any PyScriptParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LogicalAndExpressionContext* PyScriptParser::logicalAndExpression() {
  LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, PyScriptParser::RuleLogicalAndExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(252);
    equalityExpression();
    setState(257);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(253);
        match(PyScriptParser::AND);
        setState(254);
        equalityExpression(); 
      }
      setState(259);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

PyScriptParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::RelationalExpressionContext *> PyScriptParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContexts<PyScriptParser::RelationalExpressionContext>();
}

PyScriptParser::RelationalExpressionContext* PyScriptParser::EqualityExpressionContext::relationalExpression(size_t i) {
  return getRuleContext<PyScriptParser::RelationalExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::EqualityExpressionContext::EQ() {
  return getTokens(PyScriptParser::EQ);
}

tree::TerminalNode* PyScriptParser::EqualityExpressionContext::EQ(size_t i) {
  return getToken(PyScriptParser::EQ, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::EqualityExpressionContext::NE() {
  return getTokens(PyScriptParser::NE);
}

tree::TerminalNode* PyScriptParser::EqualityExpressionContext::NE(size_t i) {
  return getToken(PyScriptParser::NE, i);
}


size_t PyScriptParser::EqualityExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleEqualityExpression;
}

void PyScriptParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void PyScriptParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}


std::any PyScriptParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::EqualityExpressionContext* PyScriptParser::equalityExpression() {
  EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, getState());
  enterRule(_localctx, 42, PyScriptParser::RuleEqualityExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(260);
    relationalExpression();
    setState(265);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(261);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::EQ

        || _la == PyScriptParser::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(262);
        relationalExpression(); 
      }
      setState(267);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalExpressionContext ------------------------------------------------------------------

PyScriptParser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::AdditiveExpressionContext *> PyScriptParser::RelationalExpressionContext::additiveExpression() {
  return getRuleContexts<PyScriptParser::AdditiveExpressionContext>();
}

PyScriptParser::AdditiveExpressionContext* PyScriptParser::RelationalExpressionContext::additiveExpression(size_t i) {
  return getRuleContext<PyScriptParser::AdditiveExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::RelationalExpressionContext::LT() {
  return getTokens(PyScriptParser::LT);
}

tree::TerminalNode* PyScriptParser::RelationalExpressionContext::LT(size_t i) {
  return getToken(PyScriptParser::LT, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::RelationalExpressionContext::GT() {
  return getTokens(PyScriptParser::GT);
}

tree::TerminalNode* PyScriptParser::RelationalExpressionContext::GT(size_t i) {
  return getToken(PyScriptParser::GT, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::RelationalExpressionContext::LE() {
  return getTokens(PyScriptParser::LE);
}

tree::TerminalNode* PyScriptParser::RelationalExpressionContext::LE(size_t i) {
  return getToken(PyScriptParser::LE, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::RelationalExpressionContext::GE() {
  return getTokens(PyScriptParser::GE);
}

tree::TerminalNode* PyScriptParser::RelationalExpressionContext::GE(size_t i) {
  return getToken(PyScriptParser::GE, i);
}


size_t PyScriptParser::RelationalExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleRelationalExpression;
}

void PyScriptParser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}

void PyScriptParser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}


std::any PyScriptParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::RelationalExpressionContext* PyScriptParser::relationalExpression() {
  RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 44, PyScriptParser::RuleRelationalExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(268);
    additiveExpression();
    setState(273);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(269);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::LT)
          | (1ULL << PyScriptParser::LE)
          | (1ULL << PyScriptParser::GT)
          | (1ULL << PyScriptParser::GE))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(270);
        additiveExpression(); 
      }
      setState(275);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

PyScriptParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::MultiplicativeExpressionContext *> PyScriptParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContexts<PyScriptParser::MultiplicativeExpressionContext>();
}

PyScriptParser::MultiplicativeExpressionContext* PyScriptParser::AdditiveExpressionContext::multiplicativeExpression(size_t i) {
  return getRuleContext<PyScriptParser::MultiplicativeExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::AdditiveExpressionContext::PLUS() {
  return getTokens(PyScriptParser::PLUS);
}

tree::TerminalNode* PyScriptParser::AdditiveExpressionContext::PLUS(size_t i) {
  return getToken(PyScriptParser::PLUS, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::AdditiveExpressionContext::MINUS() {
  return getTokens(PyScriptParser::MINUS);
}

tree::TerminalNode* PyScriptParser::AdditiveExpressionContext::MINUS(size_t i) {
  return getToken(PyScriptParser::MINUS, i);
}


size_t PyScriptParser::AdditiveExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleAdditiveExpression;
}

void PyScriptParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void PyScriptParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


std::any PyScriptParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AdditiveExpressionContext* PyScriptParser::additiveExpression() {
  AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, PyScriptParser::RuleAdditiveExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(276);
    multiplicativeExpression();
    setState(281);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(277);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::PLUS

        || _la == PyScriptParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(278);
        multiplicativeExpression(); 
      }
      setState(283);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

PyScriptParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::PowerExpressionContext *> PyScriptParser::MultiplicativeExpressionContext::powerExpression() {
  return getRuleContexts<PyScriptParser::PowerExpressionContext>();
}

PyScriptParser::PowerExpressionContext* PyScriptParser::MultiplicativeExpressionContext::powerExpression(size_t i) {
  return getRuleContext<PyScriptParser::PowerExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::MultiplicativeExpressionContext::MUL() {
  return getTokens(PyScriptParser::MUL);
}

tree::TerminalNode* PyScriptParser::MultiplicativeExpressionContext::MUL(size_t i) {
  return getToken(PyScriptParser::MUL, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::MultiplicativeExpressionContext::DIV() {
  return getTokens(PyScriptParser::DIV);
}

tree::TerminalNode* PyScriptParser::MultiplicativeExpressionContext::DIV(size_t i) {
  return getToken(PyScriptParser::DIV, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::MultiplicativeExpressionContext::MOD() {
  return getTokens(PyScriptParser::MOD);
}

tree::TerminalNode* PyScriptParser::MultiplicativeExpressionContext::MOD(size_t i) {
  return getToken(PyScriptParser::MOD, i);
}


size_t PyScriptParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleMultiplicativeExpression;
}

void PyScriptParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void PyScriptParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


std::any PyScriptParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::MultiplicativeExpressionContext* PyScriptParser::multiplicativeExpression() {
  MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, getState());
  enterRule(_localctx, 48, PyScriptParser::RuleMultiplicativeExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(284);
    powerExpression();
    setState(289);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(285);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::MUL)
          | (1ULL << PyScriptParser::DIV)
          | (1ULL << PyScriptParser::MOD))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(286);
        powerExpression(); 
      }
      setState(291);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PowerExpressionContext ------------------------------------------------------------------

PyScriptParser::PowerExpressionContext::PowerExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::UnaryExpressionContext* PyScriptParser::PowerExpressionContext::unaryExpression() {
  return getRuleContext<PyScriptParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::PowerExpressionContext::DOUBLE_STAR() {
  return getToken(PyScriptParser::DOUBLE_STAR, 0);
}

PyScriptParser::PowerExpressionContext* PyScriptParser::PowerExpressionContext::powerExpression() {
  return getRuleContext<PyScriptParser::PowerExpressionContext>(0);
}


size_t PyScriptParser::PowerExpressionContext::getRuleIndex() const {
  return PyScriptParser::RulePowerExpression;
}

void PyScriptParser::PowerExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowerExpression(this);
}

void PyScriptParser::PowerExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowerExpression(this);
}


std::any PyScriptParser::PowerExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitPowerExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::PowerExpressionContext* PyScriptParser::powerExpression() {
  PowerExpressionContext *_localctx = _tracker.createInstance<PowerExpressionContext>(_ctx, getState());
  enterRule(_localctx, 50, PyScriptParser::RulePowerExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    unaryExpression();
    setState(295);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(293);
      match(PyScriptParser::DOUBLE_STAR);
      setState(294);
      powerExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

PyScriptParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::CallOrPrimaryContext* PyScriptParser::UnaryExpressionContext::callOrPrimary() {
  return getRuleContext<PyScriptParser::CallOrPrimaryContext>(0);
}

tree::TerminalNode* PyScriptParser::UnaryExpressionContext::NOT() {
  return getToken(PyScriptParser::NOT, 0);
}

tree::TerminalNode* PyScriptParser::UnaryExpressionContext::MINUS() {
  return getToken(PyScriptParser::MINUS, 0);
}


size_t PyScriptParser::UnaryExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleUnaryExpression;
}

void PyScriptParser::UnaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void PyScriptParser::UnaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}


std::any PyScriptParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::UnaryExpressionContext* PyScriptParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 52, PyScriptParser::RuleUnaryExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(298);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::MINUS

    || _la == PyScriptParser::NOT) {
      setState(297);
      _la = _input->LA(1);
      if (!(_la == PyScriptParser::MINUS

      || _la == PyScriptParser::NOT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(300);
    callOrPrimary();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallOrPrimaryContext ------------------------------------------------------------------

PyScriptParser::CallOrPrimaryContext::CallOrPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::PrimaryExpressionContext* PyScriptParser::CallOrPrimaryContext::primaryExpression() {
  return getRuleContext<PyScriptParser::PrimaryExpressionContext>(0);
}

std::vector<PyScriptParser::PostfixOpContext *> PyScriptParser::CallOrPrimaryContext::postfixOp() {
  return getRuleContexts<PyScriptParser::PostfixOpContext>();
}

PyScriptParser::PostfixOpContext* PyScriptParser::CallOrPrimaryContext::postfixOp(size_t i) {
  return getRuleContext<PyScriptParser::PostfixOpContext>(i);
}


size_t PyScriptParser::CallOrPrimaryContext::getRuleIndex() const {
  return PyScriptParser::RuleCallOrPrimary;
}

void PyScriptParser::CallOrPrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallOrPrimary(this);
}

void PyScriptParser::CallOrPrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallOrPrimary(this);
}


std::any PyScriptParser::CallOrPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitCallOrPrimary(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::CallOrPrimaryContext* PyScriptParser::callOrPrimary() {
  CallOrPrimaryContext *_localctx = _tracker.createInstance<CallOrPrimaryContext>(_ctx, getState());
  enterRule(_localctx, 54, PyScriptParser::RuleCallOrPrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(302);
    primaryExpression();
    setState(306);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(303);
        postfixOp(); 
      }
      setState(308);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixOpContext ------------------------------------------------------------------

PyScriptParser::PostfixOpContext::PostfixOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::PostfixOpContext::getRuleIndex() const {
  return PyScriptParser::RulePostfixOp;
}

void PyScriptParser::PostfixOpContext::copyFrom(PostfixOpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AttributeAccessOpContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::AttributeAccessOpContext::DOT() {
  return getToken(PyScriptParser::DOT, 0);
}

tree::TerminalNode* PyScriptParser::AttributeAccessOpContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::AttributeAccessOpContext::AttributeAccessOpContext(PostfixOpContext *ctx) { copyFrom(ctx); }

void PyScriptParser::AttributeAccessOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAccessOp(this);
}
void PyScriptParser::AttributeAccessOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAccessOp(this);
}

std::any PyScriptParser::AttributeAccessOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAttributeAccessOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallOpContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::FunctionCallOpContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

tree::TerminalNode* PyScriptParser::FunctionCallOpContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::ArgumentListContext* PyScriptParser::FunctionCallOpContext::argumentList() {
  return getRuleContext<PyScriptParser::ArgumentListContext>(0);
}

PyScriptParser::FunctionCallOpContext::FunctionCallOpContext(PostfixOpContext *ctx) { copyFrom(ctx); }

void PyScriptParser::FunctionCallOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallOp(this);
}
void PyScriptParser::FunctionCallOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallOp(this);
}

std::any PyScriptParser::FunctionCallOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionCallOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptAccessOpContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::SubscriptAccessOpContext::LBRACK() {
  return getToken(PyScriptParser::LBRACK, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::SubscriptAccessOpContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::SubscriptAccessOpContext::RBRACK() {
  return getToken(PyScriptParser::RBRACK, 0);
}

PyScriptParser::SubscriptAccessOpContext::SubscriptAccessOpContext(PostfixOpContext *ctx) { copyFrom(ctx); }

void PyScriptParser::SubscriptAccessOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscriptAccessOp(this);
}
void PyScriptParser::SubscriptAccessOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscriptAccessOp(this);
}

std::any PyScriptParser::SubscriptAccessOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSubscriptAccessOp(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::PostfixOpContext* PyScriptParser::postfixOp() {
  PostfixOpContext *_localctx = _tracker.createInstance<PostfixOpContext>(_ctx, getState());
  enterRule(_localctx, 56, PyScriptParser::RulePostfixOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DOT: {
        _localctx = _tracker.createInstance<PyScriptParser::AttributeAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(309);
        match(PyScriptParser::DOT);
        setState(310);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::LBRACK: {
        _localctx = _tracker.createInstance<PyScriptParser::SubscriptAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(311);
        match(PyScriptParser::LBRACK);
        setState(312);
        expression();
        setState(313);
        match(PyScriptParser::RBRACK);
        break;
      }

      case PyScriptParser::LPAREN: {
        _localctx = _tracker.createInstance<PyScriptParser::FunctionCallOpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(315);
        match(PyScriptParser::LPAREN);
        setState(317);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
          | (1ULL << PyScriptParser::LBRACE)
          | (1ULL << PyScriptParser::LBRACK)
          | (1ULL << PyScriptParser::MINUS)
          | (1ULL << PyScriptParser::MUL)
          | (1ULL << PyScriptParser::NOT)
          | (1ULL << PyScriptParser::DOUBLE_STAR)
          | (1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING)
          | (1ULL << PyScriptParser::BOOL)
          | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
          setState(316);
          argumentList();
        }
        setState(319);
        match(PyScriptParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeAccessContext ------------------------------------------------------------------

PyScriptParser::AttributeAccessContext::AttributeAccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::PrimaryExpressionContext* PyScriptParser::AttributeAccessContext::primaryExpression() {
  return getRuleContext<PyScriptParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::AttributeAccessContext::DOT() {
  return getToken(PyScriptParser::DOT, 0);
}

tree::TerminalNode* PyScriptParser::AttributeAccessContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}


size_t PyScriptParser::AttributeAccessContext::getRuleIndex() const {
  return PyScriptParser::RuleAttributeAccess;
}

void PyScriptParser::AttributeAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAccess(this);
}

void PyScriptParser::AttributeAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAccess(this);
}


std::any PyScriptParser::AttributeAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAttributeAccess(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AttributeAccessContext* PyScriptParser::attributeAccess() {
  AttributeAccessContext *_localctx = _tracker.createInstance<AttributeAccessContext>(_ctx, getState());
  enterRule(_localctx, 58, PyScriptParser::RuleAttributeAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    primaryExpression();
    setState(323);
    match(PyScriptParser::DOT);
    setState(324);
    match(PyScriptParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubscriptAccessContext ------------------------------------------------------------------

PyScriptParser::SubscriptAccessContext::SubscriptAccessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::PrimaryExpressionContext* PyScriptParser::SubscriptAccessContext::primaryExpression() {
  return getRuleContext<PyScriptParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::SubscriptAccessContext::LBRACK() {
  return getToken(PyScriptParser::LBRACK, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::SubscriptAccessContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::SubscriptAccessContext::RBRACK() {
  return getToken(PyScriptParser::RBRACK, 0);
}


size_t PyScriptParser::SubscriptAccessContext::getRuleIndex() const {
  return PyScriptParser::RuleSubscriptAccess;
}

void PyScriptParser::SubscriptAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscriptAccess(this);
}

void PyScriptParser::SubscriptAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscriptAccess(this);
}


std::any PyScriptParser::SubscriptAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSubscriptAccess(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::SubscriptAccessContext* PyScriptParser::subscriptAccess() {
  SubscriptAccessContext *_localctx = _tracker.createInstance<SubscriptAccessContext>(_ctx, getState());
  enterRule(_localctx, 60, PyScriptParser::RuleSubscriptAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326);
    primaryExpression();
    setState(327);
    match(PyScriptParser::LBRACK);
    setState(328);
    expression();
    setState(329);
    match(PyScriptParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

PyScriptParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PyScriptParser::FunctionCallContext::LPAREN() {
  return getTokens(PyScriptParser::LPAREN);
}

tree::TerminalNode* PyScriptParser::FunctionCallContext::LPAREN(size_t i) {
  return getToken(PyScriptParser::LPAREN, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::FunctionCallContext::RPAREN() {
  return getTokens(PyScriptParser::RPAREN);
}

tree::TerminalNode* PyScriptParser::FunctionCallContext::RPAREN(size_t i) {
  return getToken(PyScriptParser::RPAREN, i);
}

PyScriptParser::DottedNameContext* PyScriptParser::FunctionCallContext::dottedName() {
  return getRuleContext<PyScriptParser::DottedNameContext>(0);
}

PyScriptParser::AttributeAccessContext* PyScriptParser::FunctionCallContext::attributeAccess() {
  return getRuleContext<PyScriptParser::AttributeAccessContext>(0);
}

PyScriptParser::SubscriptAccessContext* PyScriptParser::FunctionCallContext::subscriptAccess() {
  return getRuleContext<PyScriptParser::SubscriptAccessContext>(0);
}

PyScriptParser::ExpressionContext* PyScriptParser::FunctionCallContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::ArgumentListContext* PyScriptParser::FunctionCallContext::argumentList() {
  return getRuleContext<PyScriptParser::ArgumentListContext>(0);
}


size_t PyScriptParser::FunctionCallContext::getRuleIndex() const {
  return PyScriptParser::RuleFunctionCall;
}

void PyScriptParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void PyScriptParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


std::any PyScriptParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::FunctionCallContext* PyScriptParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 62, PyScriptParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(331);
      dottedName();
      break;
    }

    case 2: {
      setState(332);
      attributeAccess();
      break;
    }

    case 3: {
      setState(333);
      subscriptAccess();
      break;
    }

    case 4: {
      setState(334);
      match(PyScriptParser::LPAREN);
      setState(335);
      expression();
      setState(336);
      match(PyScriptParser::RPAREN);
      break;
    }

    default:
      break;
    }
    setState(340);
    match(PyScriptParser::LPAREN);
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(341);
      argumentList();
    }
    setState(344);
    match(PyScriptParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

PyScriptParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::LiteralContext* PyScriptParser::PrimaryExpressionContext::literal() {
  return getRuleContext<PyScriptParser::LiteralContext>(0);
}

PyScriptParser::DottedNameContext* PyScriptParser::PrimaryExpressionContext::dottedName() {
  return getRuleContext<PyScriptParser::DottedNameContext>(0);
}

tree::TerminalNode* PyScriptParser::PrimaryExpressionContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::PrimaryExpressionContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::PrimaryExpressionContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::ListLiteralContext* PyScriptParser::PrimaryExpressionContext::listLiteral() {
  return getRuleContext<PyScriptParser::ListLiteralContext>(0);
}

PyScriptParser::DictLiteralContext* PyScriptParser::PrimaryExpressionContext::dictLiteral() {
  return getRuleContext<PyScriptParser::DictLiteralContext>(0);
}

PyScriptParser::NewExpressionContext* PyScriptParser::PrimaryExpressionContext::newExpression() {
  return getRuleContext<PyScriptParser::NewExpressionContext>(0);
}

PyScriptParser::LambdaExpressionContext* PyScriptParser::PrimaryExpressionContext::lambdaExpression() {
  return getRuleContext<PyScriptParser::LambdaExpressionContext>(0);
}

PyScriptParser::ListComprehensionContext* PyScriptParser::PrimaryExpressionContext::listComprehension() {
  return getRuleContext<PyScriptParser::ListComprehensionContext>(0);
}


size_t PyScriptParser::PrimaryExpressionContext::getRuleIndex() const {
  return PyScriptParser::RulePrimaryExpression;
}

void PyScriptParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void PyScriptParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


std::any PyScriptParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::PrimaryExpressionContext* PyScriptParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 64, PyScriptParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(357);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(346);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(347);
      dottedName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(348);
      match(PyScriptParser::LPAREN);
      setState(349);
      expression();
      setState(350);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(352);
      listLiteral();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(353);
      dictLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(354);
      newExpression();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(355);
      lambdaExpression();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(356);
      listComprehension();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewExpressionContext ------------------------------------------------------------------

PyScriptParser::NewExpressionContext::NewExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::NewExpressionContext::NEW() {
  return getToken(PyScriptParser::NEW, 0);
}

PyScriptParser::DottedNameContext* PyScriptParser::NewExpressionContext::dottedName() {
  return getRuleContext<PyScriptParser::DottedNameContext>(0);
}

tree::TerminalNode* PyScriptParser::NewExpressionContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

tree::TerminalNode* PyScriptParser::NewExpressionContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::ArgumentListContext* PyScriptParser::NewExpressionContext::argumentList() {
  return getRuleContext<PyScriptParser::ArgumentListContext>(0);
}


size_t PyScriptParser::NewExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleNewExpression;
}

void PyScriptParser::NewExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewExpression(this);
}

void PyScriptParser::NewExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewExpression(this);
}


std::any PyScriptParser::NewExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitNewExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::NewExpressionContext* PyScriptParser::newExpression() {
  NewExpressionContext *_localctx = _tracker.createInstance<NewExpressionContext>(_ctx, getState());
  enterRule(_localctx, 66, PyScriptParser::RuleNewExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    match(PyScriptParser::NEW);
    setState(360);
    dottedName();
    setState(361);
    match(PyScriptParser::LPAREN);
    setState(363);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(362);
      argumentList();
    }
    setState(365);
    match(PyScriptParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

PyScriptParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::LiteralContext::INTEGER() {
  return getToken(PyScriptParser::INTEGER, 0);
}

tree::TerminalNode* PyScriptParser::LiteralContext::FLOAT() {
  return getToken(PyScriptParser::FLOAT, 0);
}

tree::TerminalNode* PyScriptParser::LiteralContext::STRING() {
  return getToken(PyScriptParser::STRING, 0);
}

tree::TerminalNode* PyScriptParser::LiteralContext::BOOL() {
  return getToken(PyScriptParser::BOOL, 0);
}

tree::TerminalNode* PyScriptParser::LiteralContext::NULL_LIT() {
  return getToken(PyScriptParser::NULL_LIT, 0);
}


size_t PyScriptParser::LiteralContext::getRuleIndex() const {
  return PyScriptParser::RuleLiteral;
}

void PyScriptParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void PyScriptParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


std::any PyScriptParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LiteralContext* PyScriptParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 68, PyScriptParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListLiteralContext ------------------------------------------------------------------

PyScriptParser::ListLiteralContext::ListLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ListLiteralContext::LBRACK() {
  return getToken(PyScriptParser::LBRACK, 0);
}

tree::TerminalNode* PyScriptParser::ListLiteralContext::RBRACK() {
  return getToken(PyScriptParser::RBRACK, 0);
}

PyScriptParser::ExpressionListContext* PyScriptParser::ListLiteralContext::expressionList() {
  return getRuleContext<PyScriptParser::ExpressionListContext>(0);
}


size_t PyScriptParser::ListLiteralContext::getRuleIndex() const {
  return PyScriptParser::RuleListLiteral;
}

void PyScriptParser::ListLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListLiteral(this);
}

void PyScriptParser::ListLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListLiteral(this);
}


std::any PyScriptParser::ListLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitListLiteral(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ListLiteralContext* PyScriptParser::listLiteral() {
  ListLiteralContext *_localctx = _tracker.createInstance<ListLiteralContext>(_ctx, getState());
  enterRule(_localctx, 70, PyScriptParser::RuleListLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(PyScriptParser::LBRACK);
    setState(371);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(370);
      expressionList();
    }
    setState(373);
    match(PyScriptParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictLiteralContext ------------------------------------------------------------------

PyScriptParser::DictLiteralContext::DictLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::DictLiteralContext::LBRACE() {
  return getToken(PyScriptParser::LBRACE, 0);
}

tree::TerminalNode* PyScriptParser::DictLiteralContext::RBRACE() {
  return getToken(PyScriptParser::RBRACE, 0);
}

PyScriptParser::DictItemListContext* PyScriptParser::DictLiteralContext::dictItemList() {
  return getRuleContext<PyScriptParser::DictItemListContext>(0);
}


size_t PyScriptParser::DictLiteralContext::getRuleIndex() const {
  return PyScriptParser::RuleDictLiteral;
}

void PyScriptParser::DictLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictLiteral(this);
}

void PyScriptParser::DictLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictLiteral(this);
}


std::any PyScriptParser::DictLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDictLiteral(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DictLiteralContext* PyScriptParser::dictLiteral() {
  DictLiteralContext *_localctx = _tracker.createInstance<DictLiteralContext>(_ctx, getState());
  enterRule(_localctx, 72, PyScriptParser::RuleDictLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(375);
    match(PyScriptParser::LBRACE);
    setState(377);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(376);
      dictItemList();
    }
    setState(379);
    match(PyScriptParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListComprehensionContext ------------------------------------------------------------------

PyScriptParser::ListComprehensionContext::ListComprehensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ListComprehensionContext::LBRACK() {
  return getToken(PyScriptParser::LBRACK, 0);
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::ListComprehensionContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::ListComprehensionContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::ListComprehensionContext::FOR() {
  return getToken(PyScriptParser::FOR, 0);
}

tree::TerminalNode* PyScriptParser::ListComprehensionContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::ListComprehensionContext::IN() {
  return getToken(PyScriptParser::IN, 0);
}

tree::TerminalNode* PyScriptParser::ListComprehensionContext::RBRACK() {
  return getToken(PyScriptParser::RBRACK, 0);
}


size_t PyScriptParser::ListComprehensionContext::getRuleIndex() const {
  return PyScriptParser::RuleListComprehension;
}

void PyScriptParser::ListComprehensionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListComprehension(this);
}

void PyScriptParser::ListComprehensionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListComprehension(this);
}


std::any PyScriptParser::ListComprehensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitListComprehension(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ListComprehensionContext* PyScriptParser::listComprehension() {
  ListComprehensionContext *_localctx = _tracker.createInstance<ListComprehensionContext>(_ctx, getState());
  enterRule(_localctx, 74, PyScriptParser::RuleListComprehension);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    match(PyScriptParser::LBRACK);
    setState(382);
    expression();
    setState(383);
    match(PyScriptParser::FOR);
    setState(384);
    match(PyScriptParser::IDENTIFIER);
    setState(385);
    match(PyScriptParser::IN);
    setState(386);
    expression();
    setState(387);
    match(PyScriptParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaExpressionContext ------------------------------------------------------------------

PyScriptParser::LambdaExpressionContext::LambdaExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::LambdaExpressionContext::LAMBDA() {
  return getToken(PyScriptParser::LAMBDA, 0);
}

tree::TerminalNode* PyScriptParser::LambdaExpressionContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::LambdaExpressionContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> PyScriptParser::LambdaExpressionContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::LambdaExpressionContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::LambdaExpressionContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::LambdaExpressionContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::LambdaExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleLambdaExpression;
}

void PyScriptParser::LambdaExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaExpression(this);
}

void PyScriptParser::LambdaExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaExpression(this);
}


std::any PyScriptParser::LambdaExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLambdaExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LambdaExpressionContext* PyScriptParser::lambdaExpression() {
  LambdaExpressionContext *_localctx = _tracker.createInstance<LambdaExpressionContext>(_ctx, getState());
  enterRule(_localctx, 76, PyScriptParser::RuleLambdaExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    match(PyScriptParser::LAMBDA);
    setState(398);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IDENTIFIER) {
      setState(390);
      match(PyScriptParser::IDENTIFIER);
      setState(395);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PyScriptParser::COMMA) {
        setState(391);
        match(PyScriptParser::COMMA);
        setState(392);
        match(PyScriptParser::IDENTIFIER);
        setState(397);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(400);
    match(PyScriptParser::COLON);
    setState(401);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DottedNameContext ------------------------------------------------------------------

PyScriptParser::DottedNameContext::DottedNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PyScriptParser::DottedNameContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::DottedNameContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::DottedNameContext::DOT() {
  return getTokens(PyScriptParser::DOT);
}

tree::TerminalNode* PyScriptParser::DottedNameContext::DOT(size_t i) {
  return getToken(PyScriptParser::DOT, i);
}


size_t PyScriptParser::DottedNameContext::getRuleIndex() const {
  return PyScriptParser::RuleDottedName;
}

void PyScriptParser::DottedNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDottedName(this);
}

void PyScriptParser::DottedNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDottedName(this);
}


std::any PyScriptParser::DottedNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDottedName(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DottedNameContext* PyScriptParser::dottedName() {
  DottedNameContext *_localctx = _tracker.createInstance<DottedNameContext>(_ctx, getState());
  enterRule(_localctx, 78, PyScriptParser::RuleDottedName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(403);
    match(PyScriptParser::IDENTIFIER);
    setState(408);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(404);
        match(PyScriptParser::DOT);
        setState(405);
        match(PyScriptParser::IDENTIFIER); 
      }
      setState(410);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

PyScriptParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ArgumentContext *> PyScriptParser::ArgumentListContext::argument() {
  return getRuleContexts<PyScriptParser::ArgumentContext>();
}

PyScriptParser::ArgumentContext* PyScriptParser::ArgumentListContext::argument(size_t i) {
  return getRuleContext<PyScriptParser::ArgumentContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ArgumentListContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::ArgumentListContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::ArgumentListContext::getRuleIndex() const {
  return PyScriptParser::RuleArgumentList;
}

void PyScriptParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void PyScriptParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}


std::any PyScriptParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ArgumentListContext* PyScriptParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 80, PyScriptParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    argument();
    setState(416);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(412);
      match(PyScriptParser::COMMA);
      setState(413);
      argument();
      setState(418);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

PyScriptParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::ExpressionContext* PyScriptParser::ArgumentContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::ArgumentContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::ArgumentContext::ASSIGN() {
  return getToken(PyScriptParser::ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::ArgumentContext::MUL() {
  return getToken(PyScriptParser::MUL, 0);
}

tree::TerminalNode* PyScriptParser::ArgumentContext::DOUBLE_STAR() {
  return getToken(PyScriptParser::DOUBLE_STAR, 0);
}


size_t PyScriptParser::ArgumentContext::getRuleIndex() const {
  return PyScriptParser::RuleArgument;
}

void PyScriptParser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void PyScriptParser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}


std::any PyScriptParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ArgumentContext* PyScriptParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 82, PyScriptParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(427);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(419);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(420);
      match(PyScriptParser::IDENTIFIER);
      setState(421);
      match(PyScriptParser::ASSIGN);
      setState(422);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(423);
      match(PyScriptParser::MUL);
      setState(424);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(425);
      match(PyScriptParser::DOUBLE_STAR);
      setState(426);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

PyScriptParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::ExpressionListContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ExpressionListContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::ExpressionListContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::ExpressionListContext::getRuleIndex() const {
  return PyScriptParser::RuleExpressionList;
}

void PyScriptParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void PyScriptParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}


std::any PyScriptParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ExpressionListContext* PyScriptParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 84, PyScriptParser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    expression();
    setState(434);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(430);
      match(PyScriptParser::COMMA);
      setState(431);
      expression();
      setState(436);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictItemListContext ------------------------------------------------------------------

PyScriptParser::DictItemListContext::DictItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::DictItemContext *> PyScriptParser::DictItemListContext::dictItem() {
  return getRuleContexts<PyScriptParser::DictItemContext>();
}

PyScriptParser::DictItemContext* PyScriptParser::DictItemListContext::dictItem(size_t i) {
  return getRuleContext<PyScriptParser::DictItemContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::DictItemListContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::DictItemListContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::DictItemListContext::getRuleIndex() const {
  return PyScriptParser::RuleDictItemList;
}

void PyScriptParser::DictItemListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictItemList(this);
}

void PyScriptParser::DictItemListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictItemList(this);
}


std::any PyScriptParser::DictItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDictItemList(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DictItemListContext* PyScriptParser::dictItemList() {
  DictItemListContext *_localctx = _tracker.createInstance<DictItemListContext>(_ctx, getState());
  enterRule(_localctx, 86, PyScriptParser::RuleDictItemList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    dictItem();
    setState(442);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(438);
      match(PyScriptParser::COMMA);
      setState(439);
      dictItem();
      setState(444);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictItemContext ------------------------------------------------------------------

PyScriptParser::DictItemContext::DictItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::DictItemContext::getRuleIndex() const {
  return PyScriptParser::RuleDictItem;
}

void PyScriptParser::DictItemContext::copyFrom(DictItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- KeyValuePairContext ------------------------------------------------------------------

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::KeyValuePairContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::KeyValuePairContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::KeyValuePairContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

PyScriptParser::KeyValuePairContext::KeyValuePairContext(DictItemContext *ctx) { copyFrom(ctx); }

void PyScriptParser::KeyValuePairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyValuePair(this);
}
void PyScriptParser::KeyValuePairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyValuePair(this);
}

std::any PyScriptParser::KeyValuePairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitKeyValuePair(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DictUnpackContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::DictUnpackContext::DOUBLE_STAR() {
  return getToken(PyScriptParser::DOUBLE_STAR, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::DictUnpackContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::DictUnpackContext::DictUnpackContext(DictItemContext *ctx) { copyFrom(ctx); }

void PyScriptParser::DictUnpackContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictUnpack(this);
}
void PyScriptParser::DictUnpackContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictUnpack(this);
}

std::any PyScriptParser::DictUnpackContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDictUnpack(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::DictItemContext* PyScriptParser::dictItem() {
  DictItemContext *_localctx = _tracker.createInstance<DictItemContext>(_ctx, getState());
  enterRule(_localctx, 88, PyScriptParser::RuleDictItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(451);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::LPAREN:
      case PyScriptParser::LBRACE:
      case PyScriptParser::LBRACK:
      case PyScriptParser::MINUS:
      case PyScriptParser::NOT:
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::IDENTIFIER:
      case PyScriptParser::INTEGER:
      case PyScriptParser::FLOAT:
      case PyScriptParser::STRING:
      case PyScriptParser::BOOL:
      case PyScriptParser::NULL_LIT: {
        _localctx = _tracker.createInstance<PyScriptParser::KeyValuePairContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(445);
        expression();
        setState(446);
        match(PyScriptParser::COLON);
        setState(447);
        expression();
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        _localctx = _tracker.createInstance<PyScriptParser::DictUnpackContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(449);
        match(PyScriptParser::DOUBLE_STAR);
        setState(450);
        expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void PyScriptParser::initialize() {
  std::call_once(pyscriptParserOnceFlag, pyscriptParserInitialize);
}
