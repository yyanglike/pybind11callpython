
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
      "program", "statement", "simpleStatement", "smallStatement", "compoundStatement", 
      "tryStatement", "exceptClause", "suite", "functionDef", "parameterList", 
      "parameter", "ifStatement", "whileStatement", "forStatement", "passStatement", 
      "returnStatement", "importStatement", "importItem", "assignment", 
      "expressionStatement", "expression", "logicalOr", "logicalAnd", "equality", 
      "comparison", "additive", "multiplicative", "power", "unary", "primary", 
      "newExpression", "atom", "postfixOp", "attributeAccess", "subscriptAccess", 
      "subscriptArg", "functionCall", "argumentList", "argument", "listLiteral", 
      "listElements", "dictLiteral", "dictComprehension", "dictItem", "setLiteral", 
      "setElements", "generatorExpression", "literal", "lambdaExpression", 
      "dottedName"
    },
    std::vector<std::string>{
      "", "'def'", "'if'", "'else'", "'for'", "'while'", "'return'", "'import'", 
      "'from'", "'as'", "'in'", "'pass'", "'new'", "'lambda'", "'try'", 
      "'except'", "'finally'", "'true'", "'false'", "'none'", "'and'", "'or'", 
      "'not'", "'+'", "'-'", "'*'", "'/'", "'%'", "'=='", "'!='", "'<'", 
      "'<='", "'>'", "'>='", "'='", "';'", "'('", "')'", "'['", "']'", "'{'", 
      "'}'", "','", "':'", "'.'", "'**'"
    },
    std::vector<std::string>{
      "", "DEF", "IF", "ELSE", "FOR", "WHILE", "RETURN", "IMPORT", "FROM", 
      "AS", "IN", "PASS", "NEW", "LAMBDA", "TRY", "EXCEPT", "FINALLY", "TRUE", 
      "FALSE", "NONE", "AND", "OR", "NOT", "PLUS", "MINUS", "MUL", "DIV", 
      "MOD", "EQ", "NE", "LT", "LE", "GT", "GE", "ASSIGN", "SEMI", "LPAREN", 
      "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "COMMA", "COLON", 
      "DOT", "DOUBLE_STAR", "NEWLINE", "IDENTIFIER", "INTEGER", "FLOAT", 
      "STRING", "WS", "COMMENT", "INDENT", "DEDENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,54,553,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,1,0,5,0,102,8,0,10,0,12,0,105,9,0,1,0,1,0,1,1,1,1,3,1,111,8,1,1,2,
  	1,2,1,2,5,2,116,8,2,10,2,12,2,119,9,2,1,2,3,2,122,8,2,1,2,3,2,125,8,2,
  	1,3,1,3,1,3,1,3,1,3,3,3,132,8,3,1,4,1,4,1,4,1,4,1,4,3,4,139,8,4,1,5,1,
  	5,1,5,1,5,5,5,145,8,5,10,5,12,5,148,9,5,1,5,1,5,1,5,3,5,153,8,5,1,5,1,
  	5,1,5,3,5,158,8,5,1,6,1,6,1,6,1,6,3,6,164,8,6,3,6,166,8,6,1,6,1,6,1,6,
  	1,7,1,7,1,7,1,7,4,7,175,8,7,11,7,12,7,176,1,7,1,7,3,7,181,8,7,1,8,1,8,
  	1,8,1,8,3,8,187,8,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,5,9,196,8,9,10,9,12,9,
  	199,9,9,1,9,3,9,202,8,9,1,10,1,10,1,10,3,10,207,8,10,1,10,1,10,3,10,211,
  	8,10,1,10,1,10,3,10,215,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,5,11,227,8,11,10,11,12,11,230,9,11,1,11,1,11,1,11,3,11,235,
  	8,11,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,
  	1,14,1,15,1,15,3,15,253,8,15,1,16,1,16,1,16,1,16,3,16,259,8,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,5,16,267,8,16,10,16,12,16,270,9,16,3,16,272,8,
  	16,1,17,1,17,1,17,3,17,277,8,17,1,18,1,18,1,18,3,18,282,8,18,1,18,1,18,
  	1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,21,5,21,294,8,21,10,21,12,21,297,
  	9,21,1,22,1,22,1,22,5,22,302,8,22,10,22,12,22,305,9,22,1,23,1,23,1,23,
  	5,23,310,8,23,10,23,12,23,313,9,23,1,24,1,24,1,24,5,24,318,8,24,10,24,
  	12,24,321,9,24,1,25,1,25,1,25,5,25,326,8,25,10,25,12,25,329,9,25,1,26,
  	1,26,1,26,5,26,334,8,26,10,26,12,26,337,9,26,1,27,1,27,1,27,3,27,342,
  	8,27,1,28,3,28,345,8,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,3,29,361,8,29,1,30,1,30,1,30,1,30,3,30,367,8,
  	30,1,30,1,30,1,31,1,31,5,31,373,8,31,10,31,12,31,376,9,31,1,32,1,32,1,
  	32,1,32,1,32,1,32,1,32,1,32,3,32,386,8,32,1,32,3,32,389,8,32,1,33,1,33,
  	1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,35,3,35,401,8,35,1,35,1,35,3,35,
  	405,8,35,1,35,1,35,3,35,409,8,35,3,35,411,8,35,3,35,413,8,35,1,36,1,36,
  	1,36,3,36,418,8,36,1,36,1,36,1,37,1,37,1,37,5,37,425,8,37,10,37,12,37,
  	428,9,37,1,37,3,37,431,8,37,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,3,
  	38,441,8,38,1,39,1,39,3,39,445,8,39,1,39,1,39,1,40,1,40,1,40,5,40,452,
  	8,40,10,40,12,40,455,9,40,1,40,3,40,458,8,40,1,40,1,40,1,40,1,40,1,40,
  	1,40,3,40,466,8,40,1,41,1,41,1,41,1,41,1,41,5,41,473,8,41,10,41,12,41,
  	476,9,41,1,41,3,41,479,8,41,3,41,481,8,41,3,41,483,8,41,1,41,1,41,1,42,
  	1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,43,1,43,3,43,
  	501,8,43,1,44,1,44,3,44,505,8,44,1,44,1,44,1,45,1,45,1,45,5,45,512,8,
  	45,10,45,12,45,515,9,45,1,45,3,45,518,8,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,3,45,526,8,45,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,46,1,47,1,47,1,
  	48,1,48,3,48,540,8,48,1,48,1,48,1,48,1,49,1,49,1,49,5,49,548,8,49,10,
  	49,12,49,551,9,49,1,49,0,0,50,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,
  	76,78,80,82,84,86,88,90,92,94,96,98,0,6,1,0,28,29,1,0,30,33,1,0,23,24,
  	1,0,25,27,1,0,22,24,2,0,17,19,48,50,585,0,103,1,0,0,0,2,110,1,0,0,0,4,
  	112,1,0,0,0,6,131,1,0,0,0,8,138,1,0,0,0,10,140,1,0,0,0,12,159,1,0,0,0,
  	14,180,1,0,0,0,16,182,1,0,0,0,18,192,1,0,0,0,20,214,1,0,0,0,22,216,1,
  	0,0,0,24,236,1,0,0,0,26,241,1,0,0,0,28,248,1,0,0,0,30,250,1,0,0,0,32,
  	271,1,0,0,0,34,273,1,0,0,0,36,281,1,0,0,0,38,286,1,0,0,0,40,288,1,0,0,
  	0,42,290,1,0,0,0,44,298,1,0,0,0,46,306,1,0,0,0,48,314,1,0,0,0,50,322,
  	1,0,0,0,52,330,1,0,0,0,54,338,1,0,0,0,56,344,1,0,0,0,58,360,1,0,0,0,60,
  	362,1,0,0,0,62,370,1,0,0,0,64,388,1,0,0,0,66,390,1,0,0,0,68,394,1,0,0,
  	0,70,400,1,0,0,0,72,414,1,0,0,0,74,421,1,0,0,0,76,440,1,0,0,0,78,442,
  	1,0,0,0,80,465,1,0,0,0,82,467,1,0,0,0,84,486,1,0,0,0,86,500,1,0,0,0,88,
  	502,1,0,0,0,90,525,1,0,0,0,92,527,1,0,0,0,94,535,1,0,0,0,96,537,1,0,0,
  	0,98,544,1,0,0,0,100,102,3,2,1,0,101,100,1,0,0,0,102,105,1,0,0,0,103,
  	101,1,0,0,0,103,104,1,0,0,0,104,106,1,0,0,0,105,103,1,0,0,0,106,107,5,
  	0,0,1,107,1,1,0,0,0,108,111,3,4,2,0,109,111,3,8,4,0,110,108,1,0,0,0,110,
  	109,1,0,0,0,111,3,1,0,0,0,112,117,3,6,3,0,113,114,5,35,0,0,114,116,3,
  	6,3,0,115,113,1,0,0,0,116,119,1,0,0,0,117,115,1,0,0,0,117,118,1,0,0,0,
  	118,121,1,0,0,0,119,117,1,0,0,0,120,122,5,35,0,0,121,120,1,0,0,0,121,
  	122,1,0,0,0,122,124,1,0,0,0,123,125,5,46,0,0,124,123,1,0,0,0,124,125,
  	1,0,0,0,125,5,1,0,0,0,126,132,3,36,18,0,127,132,3,30,15,0,128,132,3,38,
  	19,0,129,132,3,32,16,0,130,132,3,28,14,0,131,126,1,0,0,0,131,127,1,0,
  	0,0,131,128,1,0,0,0,131,129,1,0,0,0,131,130,1,0,0,0,132,7,1,0,0,0,133,
  	139,3,16,8,0,134,139,3,22,11,0,135,139,3,24,12,0,136,139,3,26,13,0,137,
  	139,3,10,5,0,138,133,1,0,0,0,138,134,1,0,0,0,138,135,1,0,0,0,138,136,
  	1,0,0,0,138,137,1,0,0,0,139,9,1,0,0,0,140,141,5,14,0,0,141,142,5,43,0,
  	0,142,146,3,14,7,0,143,145,3,12,6,0,144,143,1,0,0,0,145,148,1,0,0,0,146,
  	144,1,0,0,0,146,147,1,0,0,0,147,152,1,0,0,0,148,146,1,0,0,0,149,150,5,
  	3,0,0,150,151,5,43,0,0,151,153,3,14,7,0,152,149,1,0,0,0,152,153,1,0,0,
  	0,153,157,1,0,0,0,154,155,5,16,0,0,155,156,5,43,0,0,156,158,3,14,7,0,
  	157,154,1,0,0,0,157,158,1,0,0,0,158,11,1,0,0,0,159,165,5,15,0,0,160,163,
  	3,98,49,0,161,162,5,9,0,0,162,164,5,47,0,0,163,161,1,0,0,0,163,164,1,
  	0,0,0,164,166,1,0,0,0,165,160,1,0,0,0,165,166,1,0,0,0,166,167,1,0,0,0,
  	167,168,5,43,0,0,168,169,3,14,7,0,169,13,1,0,0,0,170,181,3,4,2,0,171,
  	172,5,46,0,0,172,174,5,53,0,0,173,175,3,2,1,0,174,173,1,0,0,0,175,176,
  	1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,178,1,0,0,0,178,179,5,54,
  	0,0,179,181,1,0,0,0,180,170,1,0,0,0,180,171,1,0,0,0,181,15,1,0,0,0,182,
  	183,5,1,0,0,183,184,5,47,0,0,184,186,5,36,0,0,185,187,3,18,9,0,186,185,
  	1,0,0,0,186,187,1,0,0,0,187,188,1,0,0,0,188,189,5,37,0,0,189,190,5,43,
  	0,0,190,191,3,14,7,0,191,17,1,0,0,0,192,197,3,20,10,0,193,194,5,42,0,
  	0,194,196,3,20,10,0,195,193,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,
  	198,1,0,0,0,198,201,1,0,0,0,199,197,1,0,0,0,200,202,5,42,0,0,201,200,
  	1,0,0,0,201,202,1,0,0,0,202,19,1,0,0,0,203,206,5,47,0,0,204,205,5,34,
  	0,0,205,207,3,40,20,0,206,204,1,0,0,0,206,207,1,0,0,0,207,215,1,0,0,0,
  	208,210,5,25,0,0,209,211,5,47,0,0,210,209,1,0,0,0,210,211,1,0,0,0,211,
  	215,1,0,0,0,212,213,5,45,0,0,213,215,5,47,0,0,214,203,1,0,0,0,214,208,
  	1,0,0,0,214,212,1,0,0,0,215,21,1,0,0,0,216,217,5,2,0,0,217,218,3,40,20,
  	0,218,219,5,43,0,0,219,228,3,14,7,0,220,221,5,3,0,0,221,222,5,2,0,0,222,
  	223,3,40,20,0,223,224,5,43,0,0,224,225,3,14,7,0,225,227,1,0,0,0,226,220,
  	1,0,0,0,227,230,1,0,0,0,228,226,1,0,0,0,228,229,1,0,0,0,229,234,1,0,0,
  	0,230,228,1,0,0,0,231,232,5,3,0,0,232,233,5,43,0,0,233,235,3,14,7,0,234,
  	231,1,0,0,0,234,235,1,0,0,0,235,23,1,0,0,0,236,237,5,5,0,0,237,238,3,
  	40,20,0,238,239,5,43,0,0,239,240,3,14,7,0,240,25,1,0,0,0,241,242,5,4,
  	0,0,242,243,5,47,0,0,243,244,5,10,0,0,244,245,3,40,20,0,245,246,5,43,
  	0,0,246,247,3,14,7,0,247,27,1,0,0,0,248,249,5,11,0,0,249,29,1,0,0,0,250,
  	252,5,6,0,0,251,253,3,40,20,0,252,251,1,0,0,0,252,253,1,0,0,0,253,31,
  	1,0,0,0,254,255,5,7,0,0,255,258,3,98,49,0,256,257,5,9,0,0,257,259,5,47,
  	0,0,258,256,1,0,0,0,258,259,1,0,0,0,259,272,1,0,0,0,260,261,5,8,0,0,261,
  	262,3,98,49,0,262,263,5,7,0,0,263,268,3,34,17,0,264,265,5,42,0,0,265,
  	267,3,34,17,0,266,264,1,0,0,0,267,270,1,0,0,0,268,266,1,0,0,0,268,269,
  	1,0,0,0,269,272,1,0,0,0,270,268,1,0,0,0,271,254,1,0,0,0,271,260,1,0,0,
  	0,272,33,1,0,0,0,273,276,5,47,0,0,274,275,5,9,0,0,275,277,5,47,0,0,276,
  	274,1,0,0,0,276,277,1,0,0,0,277,35,1,0,0,0,278,282,5,47,0,0,279,282,3,
  	66,33,0,280,282,3,68,34,0,281,278,1,0,0,0,281,279,1,0,0,0,281,280,1,0,
  	0,0,282,283,1,0,0,0,283,284,5,34,0,0,284,285,3,40,20,0,285,37,1,0,0,0,
  	286,287,3,40,20,0,287,39,1,0,0,0,288,289,3,42,21,0,289,41,1,0,0,0,290,
  	295,3,44,22,0,291,292,5,21,0,0,292,294,3,44,22,0,293,291,1,0,0,0,294,
  	297,1,0,0,0,295,293,1,0,0,0,295,296,1,0,0,0,296,43,1,0,0,0,297,295,1,
  	0,0,0,298,303,3,46,23,0,299,300,5,20,0,0,300,302,3,46,23,0,301,299,1,
  	0,0,0,302,305,1,0,0,0,303,301,1,0,0,0,303,304,1,0,0,0,304,45,1,0,0,0,
  	305,303,1,0,0,0,306,311,3,48,24,0,307,308,7,0,0,0,308,310,3,48,24,0,309,
  	307,1,0,0,0,310,313,1,0,0,0,311,309,1,0,0,0,311,312,1,0,0,0,312,47,1,
  	0,0,0,313,311,1,0,0,0,314,319,3,50,25,0,315,316,7,1,0,0,316,318,3,50,
  	25,0,317,315,1,0,0,0,318,321,1,0,0,0,319,317,1,0,0,0,319,320,1,0,0,0,
  	320,49,1,0,0,0,321,319,1,0,0,0,322,327,3,52,26,0,323,324,7,2,0,0,324,
  	326,3,52,26,0,325,323,1,0,0,0,326,329,1,0,0,0,327,325,1,0,0,0,327,328,
  	1,0,0,0,328,51,1,0,0,0,329,327,1,0,0,0,330,335,3,54,27,0,331,332,7,3,
  	0,0,332,334,3,54,27,0,333,331,1,0,0,0,334,337,1,0,0,0,335,333,1,0,0,0,
  	335,336,1,0,0,0,336,53,1,0,0,0,337,335,1,0,0,0,338,341,3,56,28,0,339,
  	340,5,45,0,0,340,342,3,54,27,0,341,339,1,0,0,0,341,342,1,0,0,0,342,55,
  	1,0,0,0,343,345,7,4,0,0,344,343,1,0,0,0,344,345,1,0,0,0,345,346,1,0,0,
  	0,346,347,3,62,31,0,347,57,1,0,0,0,348,361,3,94,47,0,349,361,5,47,0,0,
  	350,351,5,36,0,0,351,352,3,40,20,0,352,353,5,37,0,0,353,361,1,0,0,0,354,
  	361,3,78,39,0,355,361,3,82,41,0,356,361,3,88,44,0,357,361,3,92,46,0,358,
  	361,3,60,30,0,359,361,3,96,48,0,360,348,1,0,0,0,360,349,1,0,0,0,360,350,
  	1,0,0,0,360,354,1,0,0,0,360,355,1,0,0,0,360,356,1,0,0,0,360,357,1,0,0,
  	0,360,358,1,0,0,0,360,359,1,0,0,0,361,59,1,0,0,0,362,363,5,12,0,0,363,
  	364,3,98,49,0,364,366,5,36,0,0,365,367,3,74,37,0,366,365,1,0,0,0,366,
  	367,1,0,0,0,367,368,1,0,0,0,368,369,5,37,0,0,369,61,1,0,0,0,370,374,3,
  	58,29,0,371,373,3,64,32,0,372,371,1,0,0,0,373,376,1,0,0,0,374,372,1,0,
  	0,0,374,375,1,0,0,0,375,63,1,0,0,0,376,374,1,0,0,0,377,378,5,44,0,0,378,
  	389,5,47,0,0,379,380,5,38,0,0,380,381,3,70,35,0,381,382,5,39,0,0,382,
  	389,1,0,0,0,383,385,5,36,0,0,384,386,3,74,37,0,385,384,1,0,0,0,385,386,
  	1,0,0,0,386,387,1,0,0,0,387,389,5,37,0,0,388,377,1,0,0,0,388,379,1,0,
  	0,0,388,383,1,0,0,0,389,65,1,0,0,0,390,391,3,62,31,0,391,392,5,44,0,0,
  	392,393,5,47,0,0,393,67,1,0,0,0,394,395,3,62,31,0,395,396,5,38,0,0,396,
  	397,3,70,35,0,397,398,5,39,0,0,398,69,1,0,0,0,399,401,3,40,20,0,400,399,
  	1,0,0,0,400,401,1,0,0,0,401,412,1,0,0,0,402,404,5,43,0,0,403,405,3,40,
  	20,0,404,403,1,0,0,0,404,405,1,0,0,0,405,410,1,0,0,0,406,408,5,43,0,0,
  	407,409,3,40,20,0,408,407,1,0,0,0,408,409,1,0,0,0,409,411,1,0,0,0,410,
  	406,1,0,0,0,410,411,1,0,0,0,411,413,1,0,0,0,412,402,1,0,0,0,412,413,1,
  	0,0,0,413,71,1,0,0,0,414,415,3,62,31,0,415,417,5,36,0,0,416,418,3,74,
  	37,0,417,416,1,0,0,0,417,418,1,0,0,0,418,419,1,0,0,0,419,420,5,37,0,0,
  	420,73,1,0,0,0,421,426,3,76,38,0,422,423,5,42,0,0,423,425,3,76,38,0,424,
  	422,1,0,0,0,425,428,1,0,0,0,426,424,1,0,0,0,426,427,1,0,0,0,427,430,1,
  	0,0,0,428,426,1,0,0,0,429,431,5,42,0,0,430,429,1,0,0,0,430,431,1,0,0,
  	0,431,75,1,0,0,0,432,433,5,47,0,0,433,434,5,34,0,0,434,441,3,40,20,0,
  	435,441,3,40,20,0,436,437,5,25,0,0,437,441,3,40,20,0,438,439,5,45,0,0,
  	439,441,3,40,20,0,440,432,1,0,0,0,440,435,1,0,0,0,440,436,1,0,0,0,440,
  	438,1,0,0,0,441,77,1,0,0,0,442,444,5,38,0,0,443,445,3,80,40,0,444,443,
  	1,0,0,0,444,445,1,0,0,0,445,446,1,0,0,0,446,447,5,39,0,0,447,79,1,0,0,
  	0,448,453,3,40,20,0,449,450,5,42,0,0,450,452,3,40,20,0,451,449,1,0,0,
  	0,452,455,1,0,0,0,453,451,1,0,0,0,453,454,1,0,0,0,454,457,1,0,0,0,455,
  	453,1,0,0,0,456,458,5,42,0,0,457,456,1,0,0,0,457,458,1,0,0,0,458,466,
  	1,0,0,0,459,460,3,40,20,0,460,461,5,4,0,0,461,462,5,47,0,0,462,463,5,
  	10,0,0,463,464,3,40,20,0,464,466,1,0,0,0,465,448,1,0,0,0,465,459,1,0,
  	0,0,466,81,1,0,0,0,467,482,5,40,0,0,468,483,3,84,42,0,469,474,3,86,43,
  	0,470,471,5,42,0,0,471,473,3,86,43,0,472,470,1,0,0,0,473,476,1,0,0,0,
  	474,472,1,0,0,0,474,475,1,0,0,0,475,478,1,0,0,0,476,474,1,0,0,0,477,479,
  	5,42,0,0,478,477,1,0,0,0,478,479,1,0,0,0,479,481,1,0,0,0,480,469,1,0,
  	0,0,480,481,1,0,0,0,481,483,1,0,0,0,482,468,1,0,0,0,482,480,1,0,0,0,483,
  	484,1,0,0,0,484,485,5,41,0,0,485,83,1,0,0,0,486,487,3,40,20,0,487,488,
  	5,43,0,0,488,489,3,40,20,0,489,490,5,4,0,0,490,491,5,47,0,0,491,492,5,
  	10,0,0,492,493,3,40,20,0,493,85,1,0,0,0,494,495,3,40,20,0,495,496,5,43,
  	0,0,496,497,3,40,20,0,497,501,1,0,0,0,498,499,5,45,0,0,499,501,3,40,20,
  	0,500,494,1,0,0,0,500,498,1,0,0,0,501,87,1,0,0,0,502,504,5,40,0,0,503,
  	505,3,90,45,0,504,503,1,0,0,0,504,505,1,0,0,0,505,506,1,0,0,0,506,507,
  	5,41,0,0,507,89,1,0,0,0,508,513,3,40,20,0,509,510,5,42,0,0,510,512,3,
  	40,20,0,511,509,1,0,0,0,512,515,1,0,0,0,513,511,1,0,0,0,513,514,1,0,0,
  	0,514,517,1,0,0,0,515,513,1,0,0,0,516,518,5,42,0,0,517,516,1,0,0,0,517,
  	518,1,0,0,0,518,526,1,0,0,0,519,520,3,40,20,0,520,521,5,4,0,0,521,522,
  	5,47,0,0,522,523,5,10,0,0,523,524,3,40,20,0,524,526,1,0,0,0,525,508,1,
  	0,0,0,525,519,1,0,0,0,526,91,1,0,0,0,527,528,5,36,0,0,528,529,3,40,20,
  	0,529,530,5,4,0,0,530,531,5,47,0,0,531,532,5,10,0,0,532,533,3,40,20,0,
  	533,534,5,37,0,0,534,93,1,0,0,0,535,536,7,5,0,0,536,95,1,0,0,0,537,539,
  	5,13,0,0,538,540,3,18,9,0,539,538,1,0,0,0,539,540,1,0,0,0,540,541,1,0,
  	0,0,541,542,5,43,0,0,542,543,3,40,20,0,543,97,1,0,0,0,544,549,5,47,0,
  	0,545,546,5,44,0,0,546,548,5,47,0,0,547,545,1,0,0,0,548,551,1,0,0,0,549,
  	547,1,0,0,0,549,550,1,0,0,0,550,99,1,0,0,0,551,549,1,0,0,0,65,103,110,
  	117,121,124,131,138,146,152,157,163,165,176,180,186,197,201,206,210,214,
  	228,234,252,258,268,271,276,281,295,303,311,319,327,335,341,344,360,366,
  	374,385,388,400,404,408,410,412,417,426,430,440,444,453,457,465,474,478,
  	480,482,500,504,513,517,525,539,549
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
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::DEF)
      | (1ULL << PyScriptParser::IF)
      | (1ULL << PyScriptParser::FOR)
      | (1ULL << PyScriptParser::WHILE)
      | (1ULL << PyScriptParser::RETURN)
      | (1ULL << PyScriptParser::IMPORT)
      | (1ULL << PyScriptParser::FROM)
      | (1ULL << PyScriptParser::PASS)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::TRY)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING))) != 0)) {
      setState(100);
      statement();
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(106);
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

PyScriptParser::SimpleStatementContext* PyScriptParser::StatementContext::simpleStatement() {
  return getRuleContext<PyScriptParser::SimpleStatementContext>(0);
}

PyScriptParser::CompoundStatementContext* PyScriptParser::StatementContext::compoundStatement() {
  return getRuleContext<PyScriptParser::CompoundStatementContext>(0);
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
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::RETURN:
      case PyScriptParser::IMPORT:
      case PyScriptParser::FROM:
      case PyScriptParser::PASS:
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::TRUE:
      case PyScriptParser::FALSE:
      case PyScriptParser::NONE:
      case PyScriptParser::NOT:
      case PyScriptParser::PLUS:
      case PyScriptParser::MINUS:
      case PyScriptParser::LPAREN:
      case PyScriptParser::LBRACK:
      case PyScriptParser::LBRACE:
      case PyScriptParser::IDENTIFIER:
      case PyScriptParser::INTEGER:
      case PyScriptParser::FLOAT:
      case PyScriptParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(108);
        simpleStatement();
        break;
      }

      case PyScriptParser::DEF:
      case PyScriptParser::IF:
      case PyScriptParser::FOR:
      case PyScriptParser::WHILE:
      case PyScriptParser::TRY: {
        enterOuterAlt(_localctx, 2);
        setState(109);
        compoundStatement();
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

//----------------- SimpleStatementContext ------------------------------------------------------------------

PyScriptParser::SimpleStatementContext::SimpleStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::SmallStatementContext *> PyScriptParser::SimpleStatementContext::smallStatement() {
  return getRuleContexts<PyScriptParser::SmallStatementContext>();
}

PyScriptParser::SmallStatementContext* PyScriptParser::SimpleStatementContext::smallStatement(size_t i) {
  return getRuleContext<PyScriptParser::SmallStatementContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::SimpleStatementContext::SEMI() {
  return getTokens(PyScriptParser::SEMI);
}

tree::TerminalNode* PyScriptParser::SimpleStatementContext::SEMI(size_t i) {
  return getToken(PyScriptParser::SEMI, i);
}

tree::TerminalNode* PyScriptParser::SimpleStatementContext::NEWLINE() {
  return getToken(PyScriptParser::NEWLINE, 0);
}


size_t PyScriptParser::SimpleStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleSimpleStatement;
}

void PyScriptParser::SimpleStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleStatement(this);
}

void PyScriptParser::SimpleStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleStatement(this);
}


std::any PyScriptParser::SimpleStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSimpleStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::SimpleStatementContext* PyScriptParser::simpleStatement() {
  SimpleStatementContext *_localctx = _tracker.createInstance<SimpleStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, PyScriptParser::RuleSimpleStatement);
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
    setState(112);
    smallStatement();
    setState(117);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(113);
        match(PyScriptParser::SEMI);
        setState(114);
        smallStatement(); 
      }
      setState(119);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::SEMI) {
      setState(120);
      match(PyScriptParser::SEMI);
    }
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::NEWLINE) {
      setState(123);
      match(PyScriptParser::NEWLINE);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SmallStatementContext ------------------------------------------------------------------

PyScriptParser::SmallStatementContext::SmallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::AssignmentContext* PyScriptParser::SmallStatementContext::assignment() {
  return getRuleContext<PyScriptParser::AssignmentContext>(0);
}

PyScriptParser::ReturnStatementContext* PyScriptParser::SmallStatementContext::returnStatement() {
  return getRuleContext<PyScriptParser::ReturnStatementContext>(0);
}

PyScriptParser::ExpressionStatementContext* PyScriptParser::SmallStatementContext::expressionStatement() {
  return getRuleContext<PyScriptParser::ExpressionStatementContext>(0);
}

PyScriptParser::ImportStatementContext* PyScriptParser::SmallStatementContext::importStatement() {
  return getRuleContext<PyScriptParser::ImportStatementContext>(0);
}

PyScriptParser::PassStatementContext* PyScriptParser::SmallStatementContext::passStatement() {
  return getRuleContext<PyScriptParser::PassStatementContext>(0);
}


size_t PyScriptParser::SmallStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleSmallStatement;
}

void PyScriptParser::SmallStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSmallStatement(this);
}

void PyScriptParser::SmallStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSmallStatement(this);
}


std::any PyScriptParser::SmallStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSmallStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::SmallStatementContext* PyScriptParser::smallStatement() {
  SmallStatementContext *_localctx = _tracker.createInstance<SmallStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, PyScriptParser::RuleSmallStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(131);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(126);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(127);
      returnStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(128);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(129);
      importStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(130);
      passStatement();
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

//----------------- CompoundStatementContext ------------------------------------------------------------------

PyScriptParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::FunctionDefContext* PyScriptParser::CompoundStatementContext::functionDef() {
  return getRuleContext<PyScriptParser::FunctionDefContext>(0);
}

PyScriptParser::IfStatementContext* PyScriptParser::CompoundStatementContext::ifStatement() {
  return getRuleContext<PyScriptParser::IfStatementContext>(0);
}

PyScriptParser::WhileStatementContext* PyScriptParser::CompoundStatementContext::whileStatement() {
  return getRuleContext<PyScriptParser::WhileStatementContext>(0);
}

PyScriptParser::ForStatementContext* PyScriptParser::CompoundStatementContext::forStatement() {
  return getRuleContext<PyScriptParser::ForStatementContext>(0);
}

PyScriptParser::TryStatementContext* PyScriptParser::CompoundStatementContext::tryStatement() {
  return getRuleContext<PyScriptParser::TryStatementContext>(0);
}


size_t PyScriptParser::CompoundStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleCompoundStatement;
}

void PyScriptParser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void PyScriptParser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}


std::any PyScriptParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::CompoundStatementContext* PyScriptParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, PyScriptParser::RuleCompoundStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DEF: {
        enterOuterAlt(_localctx, 1);
        setState(133);
        functionDef();
        break;
      }

      case PyScriptParser::IF: {
        enterOuterAlt(_localctx, 2);
        setState(134);
        ifStatement();
        break;
      }

      case PyScriptParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(135);
        whileStatement();
        break;
      }

      case PyScriptParser::FOR: {
        enterOuterAlt(_localctx, 4);
        setState(136);
        forStatement();
        break;
      }

      case PyScriptParser::TRY: {
        enterOuterAlt(_localctx, 5);
        setState(137);
        tryStatement();
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

//----------------- TryStatementContext ------------------------------------------------------------------

PyScriptParser::TryStatementContext::TryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::TryStatementContext::TRY() {
  return getToken(PyScriptParser::TRY, 0);
}

std::vector<tree::TerminalNode *> PyScriptParser::TryStatementContext::COLON() {
  return getTokens(PyScriptParser::COLON);
}

tree::TerminalNode* PyScriptParser::TryStatementContext::COLON(size_t i) {
  return getToken(PyScriptParser::COLON, i);
}

std::vector<PyScriptParser::SuiteContext *> PyScriptParser::TryStatementContext::suite() {
  return getRuleContexts<PyScriptParser::SuiteContext>();
}

PyScriptParser::SuiteContext* PyScriptParser::TryStatementContext::suite(size_t i) {
  return getRuleContext<PyScriptParser::SuiteContext>(i);
}

std::vector<PyScriptParser::ExceptClauseContext *> PyScriptParser::TryStatementContext::exceptClause() {
  return getRuleContexts<PyScriptParser::ExceptClauseContext>();
}

PyScriptParser::ExceptClauseContext* PyScriptParser::TryStatementContext::exceptClause(size_t i) {
  return getRuleContext<PyScriptParser::ExceptClauseContext>(i);
}

tree::TerminalNode* PyScriptParser::TryStatementContext::ELSE() {
  return getToken(PyScriptParser::ELSE, 0);
}

tree::TerminalNode* PyScriptParser::TryStatementContext::FINALLY() {
  return getToken(PyScriptParser::FINALLY, 0);
}


size_t PyScriptParser::TryStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleTryStatement;
}

void PyScriptParser::TryStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryStatement(this);
}

void PyScriptParser::TryStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryStatement(this);
}


std::any PyScriptParser::TryStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitTryStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::TryStatementContext* PyScriptParser::tryStatement() {
  TryStatementContext *_localctx = _tracker.createInstance<TryStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, PyScriptParser::RuleTryStatement);
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
    setState(140);
    match(PyScriptParser::TRY);
    setState(141);
    match(PyScriptParser::COLON);
    setState(142);
    suite();
    setState(146);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::EXCEPT) {
      setState(143);
      exceptClause();
      setState(148);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(152);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(149);
      match(PyScriptParser::ELSE);
      setState(150);
      match(PyScriptParser::COLON);
      setState(151);
      suite();
    }
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::FINALLY) {
      setState(154);
      match(PyScriptParser::FINALLY);
      setState(155);
      match(PyScriptParser::COLON);
      setState(156);
      suite();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExceptClauseContext ------------------------------------------------------------------

PyScriptParser::ExceptClauseContext::ExceptClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ExceptClauseContext::EXCEPT() {
  return getToken(PyScriptParser::EXCEPT, 0);
}

tree::TerminalNode* PyScriptParser::ExceptClauseContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

PyScriptParser::SuiteContext* PyScriptParser::ExceptClauseContext::suite() {
  return getRuleContext<PyScriptParser::SuiteContext>(0);
}

PyScriptParser::DottedNameContext* PyScriptParser::ExceptClauseContext::dottedName() {
  return getRuleContext<PyScriptParser::DottedNameContext>(0);
}

tree::TerminalNode* PyScriptParser::ExceptClauseContext::AS() {
  return getToken(PyScriptParser::AS, 0);
}

tree::TerminalNode* PyScriptParser::ExceptClauseContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}


size_t PyScriptParser::ExceptClauseContext::getRuleIndex() const {
  return PyScriptParser::RuleExceptClause;
}

void PyScriptParser::ExceptClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExceptClause(this);
}

void PyScriptParser::ExceptClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExceptClause(this);
}


std::any PyScriptParser::ExceptClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitExceptClause(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ExceptClauseContext* PyScriptParser::exceptClause() {
  ExceptClauseContext *_localctx = _tracker.createInstance<ExceptClauseContext>(_ctx, getState());
  enterRule(_localctx, 12, PyScriptParser::RuleExceptClause);
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
    setState(159);
    match(PyScriptParser::EXCEPT);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IDENTIFIER) {
      setState(160);
      dottedName();
      setState(163);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::AS) {
        setState(161);
        match(PyScriptParser::AS);
        setState(162);
        match(PyScriptParser::IDENTIFIER);
      }
    }
    setState(167);
    match(PyScriptParser::COLON);
    setState(168);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuiteContext ------------------------------------------------------------------

PyScriptParser::SuiteContext::SuiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::SimpleStatementContext* PyScriptParser::SuiteContext::simpleStatement() {
  return getRuleContext<PyScriptParser::SimpleStatementContext>(0);
}

tree::TerminalNode* PyScriptParser::SuiteContext::NEWLINE() {
  return getToken(PyScriptParser::NEWLINE, 0);
}

tree::TerminalNode* PyScriptParser::SuiteContext::INDENT() {
  return getToken(PyScriptParser::INDENT, 0);
}

tree::TerminalNode* PyScriptParser::SuiteContext::DEDENT() {
  return getToken(PyScriptParser::DEDENT, 0);
}

std::vector<PyScriptParser::StatementContext *> PyScriptParser::SuiteContext::statement() {
  return getRuleContexts<PyScriptParser::StatementContext>();
}

PyScriptParser::StatementContext* PyScriptParser::SuiteContext::statement(size_t i) {
  return getRuleContext<PyScriptParser::StatementContext>(i);
}


size_t PyScriptParser::SuiteContext::getRuleIndex() const {
  return PyScriptParser::RuleSuite;
}

void PyScriptParser::SuiteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuite(this);
}

void PyScriptParser::SuiteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuite(this);
}


std::any PyScriptParser::SuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSuite(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::SuiteContext* PyScriptParser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 14, PyScriptParser::RuleSuite);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::RETURN:
      case PyScriptParser::IMPORT:
      case PyScriptParser::FROM:
      case PyScriptParser::PASS:
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::TRUE:
      case PyScriptParser::FALSE:
      case PyScriptParser::NONE:
      case PyScriptParser::NOT:
      case PyScriptParser::PLUS:
      case PyScriptParser::MINUS:
      case PyScriptParser::LPAREN:
      case PyScriptParser::LBRACK:
      case PyScriptParser::LBRACE:
      case PyScriptParser::IDENTIFIER:
      case PyScriptParser::INTEGER:
      case PyScriptParser::FLOAT:
      case PyScriptParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(170);
        simpleStatement();
        break;
      }

      case PyScriptParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(171);
        match(PyScriptParser::NEWLINE);
        setState(172);
        match(PyScriptParser::INDENT);
        setState(174); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(173);
          statement();
          setState(176); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::DEF)
          | (1ULL << PyScriptParser::IF)
          | (1ULL << PyScriptParser::FOR)
          | (1ULL << PyScriptParser::WHILE)
          | (1ULL << PyScriptParser::RETURN)
          | (1ULL << PyScriptParser::IMPORT)
          | (1ULL << PyScriptParser::FROM)
          | (1ULL << PyScriptParser::PASS)
          | (1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::TRY)
          | (1ULL << PyScriptParser::TRUE)
          | (1ULL << PyScriptParser::FALSE)
          | (1ULL << PyScriptParser::NONE)
          | (1ULL << PyScriptParser::NOT)
          | (1ULL << PyScriptParser::PLUS)
          | (1ULL << PyScriptParser::MINUS)
          | (1ULL << PyScriptParser::LPAREN)
          | (1ULL << PyScriptParser::LBRACK)
          | (1ULL << PyScriptParser::LBRACE)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING))) != 0));
        setState(178);
        match(PyScriptParser::DEDENT);
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

//----------------- FunctionDefContext ------------------------------------------------------------------

PyScriptParser::FunctionDefContext::FunctionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::FunctionDefContext::DEF() {
  return getToken(PyScriptParser::DEF, 0);
}

tree::TerminalNode* PyScriptParser::FunctionDefContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::FunctionDefContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

tree::TerminalNode* PyScriptParser::FunctionDefContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

tree::TerminalNode* PyScriptParser::FunctionDefContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

PyScriptParser::SuiteContext* PyScriptParser::FunctionDefContext::suite() {
  return getRuleContext<PyScriptParser::SuiteContext>(0);
}

PyScriptParser::ParameterListContext* PyScriptParser::FunctionDefContext::parameterList() {
  return getRuleContext<PyScriptParser::ParameterListContext>(0);
}


size_t PyScriptParser::FunctionDefContext::getRuleIndex() const {
  return PyScriptParser::RuleFunctionDef;
}

void PyScriptParser::FunctionDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDef(this);
}

void PyScriptParser::FunctionDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDef(this);
}


std::any PyScriptParser::FunctionDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionDef(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::FunctionDefContext* PyScriptParser::functionDef() {
  FunctionDefContext *_localctx = _tracker.createInstance<FunctionDefContext>(_ctx, getState());
  enterRule(_localctx, 16, PyScriptParser::RuleFunctionDef);
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
    setState(182);
    match(PyScriptParser::DEF);
    setState(183);
    match(PyScriptParser::IDENTIFIER);
    setState(184);
    match(PyScriptParser::LPAREN);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::IDENTIFIER))) != 0)) {
      setState(185);
      parameterList();
    }
    setState(188);
    match(PyScriptParser::RPAREN);
    setState(189);
    match(PyScriptParser::COLON);
    setState(190);
    suite();
   
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
  enterRule(_localctx, 18, PyScriptParser::RuleParameterList);
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
    setState(192);
    parameter();
    setState(197);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(193);
        match(PyScriptParser::COMMA);
        setState(194);
        parameter(); 
      }
      setState(199);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(200);
      match(PyScriptParser::COMMA);
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
  enterRule(_localctx, 20, PyScriptParser::RuleParameter);
  size_t _la = 0;

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
    switch (_input->LA(1)) {
      case PyScriptParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(203);
        match(PyScriptParser::IDENTIFIER);
        setState(206);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::ASSIGN) {
          setState(204);
          match(PyScriptParser::ASSIGN);
          setState(205);
          expression();
        }
        break;
      }

      case PyScriptParser::MUL: {
        enterOuterAlt(_localctx, 2);
        setState(208);
        match(PyScriptParser::MUL);
        setState(210);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::IDENTIFIER) {
          setState(209);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 3);
        setState(212);
        match(PyScriptParser::DOUBLE_STAR);
        setState(213);
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

std::vector<tree::TerminalNode *> PyScriptParser::IfStatementContext::IF() {
  return getTokens(PyScriptParser::IF);
}

tree::TerminalNode* PyScriptParser::IfStatementContext::IF(size_t i) {
  return getToken(PyScriptParser::IF, i);
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::IfStatementContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::IfStatementContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::IfStatementContext::COLON() {
  return getTokens(PyScriptParser::COLON);
}

tree::TerminalNode* PyScriptParser::IfStatementContext::COLON(size_t i) {
  return getToken(PyScriptParser::COLON, i);
}

std::vector<PyScriptParser::SuiteContext *> PyScriptParser::IfStatementContext::suite() {
  return getRuleContexts<PyScriptParser::SuiteContext>();
}

PyScriptParser::SuiteContext* PyScriptParser::IfStatementContext::suite(size_t i) {
  return getRuleContext<PyScriptParser::SuiteContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::IfStatementContext::ELSE() {
  return getTokens(PyScriptParser::ELSE);
}

tree::TerminalNode* PyScriptParser::IfStatementContext::ELSE(size_t i) {
  return getToken(PyScriptParser::ELSE, i);
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
  enterRule(_localctx, 22, PyScriptParser::RuleIfStatement);
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
    setState(216);
    match(PyScriptParser::IF);
    setState(217);
    expression();
    setState(218);
    match(PyScriptParser::COLON);
    setState(219);
    suite();
    setState(228);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(220);
        match(PyScriptParser::ELSE);
        setState(221);
        match(PyScriptParser::IF);
        setState(222);
        expression();
        setState(223);
        match(PyScriptParser::COLON);
        setState(224);
        suite(); 
      }
      setState(230);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(231);
      match(PyScriptParser::ELSE);
      setState(232);
      match(PyScriptParser::COLON);
      setState(233);
      suite();
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

PyScriptParser::ExpressionContext* PyScriptParser::WhileStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::WhileStatementContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

PyScriptParser::SuiteContext* PyScriptParser::WhileStatementContext::suite() {
  return getRuleContext<PyScriptParser::SuiteContext>(0);
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
  enterRule(_localctx, 24, PyScriptParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(PyScriptParser::WHILE);
    setState(237);
    expression();
    setState(238);
    match(PyScriptParser::COLON);
    setState(239);
    suite();
   
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

tree::TerminalNode* PyScriptParser::ForStatementContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::ForStatementContext::IN() {
  return getToken(PyScriptParser::IN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::ForStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::ForStatementContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

PyScriptParser::SuiteContext* PyScriptParser::ForStatementContext::suite() {
  return getRuleContext<PyScriptParser::SuiteContext>(0);
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
  enterRule(_localctx, 26, PyScriptParser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(PyScriptParser::FOR);
    setState(242);
    match(PyScriptParser::IDENTIFIER);
    setState(243);
    match(PyScriptParser::IN);
    setState(244);
    expression();
    setState(245);
    match(PyScriptParser::COLON);
    setState(246);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PassStatementContext ------------------------------------------------------------------

PyScriptParser::PassStatementContext::PassStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::PassStatementContext::PASS() {
  return getToken(PyScriptParser::PASS, 0);
}


size_t PyScriptParser::PassStatementContext::getRuleIndex() const {
  return PyScriptParser::RulePassStatement;
}

void PyScriptParser::PassStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPassStatement(this);
}

void PyScriptParser::PassStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPassStatement(this);
}


std::any PyScriptParser::PassStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitPassStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::PassStatementContext* PyScriptParser::passStatement() {
  PassStatementContext *_localctx = _tracker.createInstance<PassStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, PyScriptParser::RulePassStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(PyScriptParser::PASS);
   
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
  enterRule(_localctx, 30, PyScriptParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(PyScriptParser::RETURN);
    setState(252);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(251);
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

//----------------- ImportStatementContext ------------------------------------------------------------------

PyScriptParser::ImportStatementContext::ImportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::ImportStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleImportStatement;
}

void PyScriptParser::ImportStatementContext::copyFrom(ImportStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FromImportContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::FromImportContext::FROM() {
  return getToken(PyScriptParser::FROM, 0);
}

PyScriptParser::DottedNameContext* PyScriptParser::FromImportContext::dottedName() {
  return getRuleContext<PyScriptParser::DottedNameContext>(0);
}

tree::TerminalNode* PyScriptParser::FromImportContext::IMPORT() {
  return getToken(PyScriptParser::IMPORT, 0);
}

std::vector<PyScriptParser::ImportItemContext *> PyScriptParser::FromImportContext::importItem() {
  return getRuleContexts<PyScriptParser::ImportItemContext>();
}

PyScriptParser::ImportItemContext* PyScriptParser::FromImportContext::importItem(size_t i) {
  return getRuleContext<PyScriptParser::ImportItemContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::FromImportContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::FromImportContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}

PyScriptParser::FromImportContext::FromImportContext(ImportStatementContext *ctx) { copyFrom(ctx); }

void PyScriptParser::FromImportContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFromImport(this);
}
void PyScriptParser::FromImportContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFromImport(this);
}

std::any PyScriptParser::FromImportContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFromImport(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleImportContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::SimpleImportContext::IMPORT() {
  return getToken(PyScriptParser::IMPORT, 0);
}

PyScriptParser::DottedNameContext* PyScriptParser::SimpleImportContext::dottedName() {
  return getRuleContext<PyScriptParser::DottedNameContext>(0);
}

tree::TerminalNode* PyScriptParser::SimpleImportContext::AS() {
  return getToken(PyScriptParser::AS, 0);
}

tree::TerminalNode* PyScriptParser::SimpleImportContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::SimpleImportContext::SimpleImportContext(ImportStatementContext *ctx) { copyFrom(ctx); }

void PyScriptParser::SimpleImportContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleImport(this);
}
void PyScriptParser::SimpleImportContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleImport(this);
}

std::any PyScriptParser::SimpleImportContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSimpleImport(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::ImportStatementContext* PyScriptParser::importStatement() {
  ImportStatementContext *_localctx = _tracker.createInstance<ImportStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, PyScriptParser::RuleImportStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IMPORT: {
        _localctx = _tracker.createInstance<PyScriptParser::SimpleImportContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(254);
        match(PyScriptParser::IMPORT);
        setState(255);
        dottedName();
        setState(258);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::AS) {
          setState(256);
          match(PyScriptParser::AS);
          setState(257);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::FROM: {
        _localctx = _tracker.createInstance<PyScriptParser::FromImportContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(260);
        match(PyScriptParser::FROM);
        setState(261);
        dottedName();
        setState(262);
        match(PyScriptParser::IMPORT);
        setState(263);
        importItem();
        setState(268);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PyScriptParser::COMMA) {
          setState(264);
          match(PyScriptParser::COMMA);
          setState(265);
          importItem();
          setState(270);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
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

//----------------- ImportItemContext ------------------------------------------------------------------

PyScriptParser::ImportItemContext::ImportItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> PyScriptParser::ImportItemContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::ImportItemContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
}

tree::TerminalNode* PyScriptParser::ImportItemContext::AS() {
  return getToken(PyScriptParser::AS, 0);
}


size_t PyScriptParser::ImportItemContext::getRuleIndex() const {
  return PyScriptParser::RuleImportItem;
}

void PyScriptParser::ImportItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportItem(this);
}

void PyScriptParser::ImportItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportItem(this);
}


std::any PyScriptParser::ImportItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitImportItem(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ImportItemContext* PyScriptParser::importItem() {
  ImportItemContext *_localctx = _tracker.createInstance<ImportItemContext>(_ctx, getState());
  enterRule(_localctx, 34, PyScriptParser::RuleImportItem);
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
    setState(273);
    match(PyScriptParser::IDENTIFIER);
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(274);
      match(PyScriptParser::AS);
      setState(275);
      match(PyScriptParser::IDENTIFIER);
    }
   
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

tree::TerminalNode* PyScriptParser::AssignmentContext::ASSIGN() {
  return getToken(PyScriptParser::ASSIGN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::AssignmentContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::AttributeAccessContext* PyScriptParser::AssignmentContext::attributeAccess() {
  return getRuleContext<PyScriptParser::AttributeAccessContext>(0);
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
  enterRule(_localctx, 36, PyScriptParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(278);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 2: {
      setState(279);
      attributeAccess();
      break;
    }

    case 3: {
      setState(280);
      subscriptAccess();
      break;
    }

    default:
      break;
    }
    setState(283);
    match(PyScriptParser::ASSIGN);
    setState(284);
    expression();
   
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
  enterRule(_localctx, 38, PyScriptParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    expression();
   
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

PyScriptParser::LogicalOrContext* PyScriptParser::ExpressionContext::logicalOr() {
  return getRuleContext<PyScriptParser::LogicalOrContext>(0);
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
  enterRule(_localctx, 40, PyScriptParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    logicalOr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOrContext ------------------------------------------------------------------

PyScriptParser::LogicalOrContext::LogicalOrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::LogicalAndContext *> PyScriptParser::LogicalOrContext::logicalAnd() {
  return getRuleContexts<PyScriptParser::LogicalAndContext>();
}

PyScriptParser::LogicalAndContext* PyScriptParser::LogicalOrContext::logicalAnd(size_t i) {
  return getRuleContext<PyScriptParser::LogicalAndContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::LogicalOrContext::OR() {
  return getTokens(PyScriptParser::OR);
}

tree::TerminalNode* PyScriptParser::LogicalOrContext::OR(size_t i) {
  return getToken(PyScriptParser::OR, i);
}


size_t PyScriptParser::LogicalOrContext::getRuleIndex() const {
  return PyScriptParser::RuleLogicalOr;
}

void PyScriptParser::LogicalOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOr(this);
}

void PyScriptParser::LogicalOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOr(this);
}


std::any PyScriptParser::LogicalOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLogicalOr(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LogicalOrContext* PyScriptParser::logicalOr() {
  LogicalOrContext *_localctx = _tracker.createInstance<LogicalOrContext>(_ctx, getState());
  enterRule(_localctx, 42, PyScriptParser::RuleLogicalOr);

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
    setState(290);
    logicalAnd();
    setState(295);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(291);
        match(PyScriptParser::OR);
        setState(292);
        logicalAnd(); 
      }
      setState(297);
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

//----------------- LogicalAndContext ------------------------------------------------------------------

PyScriptParser::LogicalAndContext::LogicalAndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::EqualityContext *> PyScriptParser::LogicalAndContext::equality() {
  return getRuleContexts<PyScriptParser::EqualityContext>();
}

PyScriptParser::EqualityContext* PyScriptParser::LogicalAndContext::equality(size_t i) {
  return getRuleContext<PyScriptParser::EqualityContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::LogicalAndContext::AND() {
  return getTokens(PyScriptParser::AND);
}

tree::TerminalNode* PyScriptParser::LogicalAndContext::AND(size_t i) {
  return getToken(PyScriptParser::AND, i);
}


size_t PyScriptParser::LogicalAndContext::getRuleIndex() const {
  return PyScriptParser::RuleLogicalAnd;
}

void PyScriptParser::LogicalAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAnd(this);
}

void PyScriptParser::LogicalAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAnd(this);
}


std::any PyScriptParser::LogicalAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLogicalAnd(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LogicalAndContext* PyScriptParser::logicalAnd() {
  LogicalAndContext *_localctx = _tracker.createInstance<LogicalAndContext>(_ctx, getState());
  enterRule(_localctx, 44, PyScriptParser::RuleLogicalAnd);

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
    setState(298);
    equality();
    setState(303);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(299);
        match(PyScriptParser::AND);
        setState(300);
        equality(); 
      }
      setState(305);
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

//----------------- EqualityContext ------------------------------------------------------------------

PyScriptParser::EqualityContext::EqualityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ComparisonContext *> PyScriptParser::EqualityContext::comparison() {
  return getRuleContexts<PyScriptParser::ComparisonContext>();
}

PyScriptParser::ComparisonContext* PyScriptParser::EqualityContext::comparison(size_t i) {
  return getRuleContext<PyScriptParser::ComparisonContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::EqualityContext::EQ() {
  return getTokens(PyScriptParser::EQ);
}

tree::TerminalNode* PyScriptParser::EqualityContext::EQ(size_t i) {
  return getToken(PyScriptParser::EQ, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::EqualityContext::NE() {
  return getTokens(PyScriptParser::NE);
}

tree::TerminalNode* PyScriptParser::EqualityContext::NE(size_t i) {
  return getToken(PyScriptParser::NE, i);
}


size_t PyScriptParser::EqualityContext::getRuleIndex() const {
  return PyScriptParser::RuleEquality;
}

void PyScriptParser::EqualityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEquality(this);
}

void PyScriptParser::EqualityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEquality(this);
}


std::any PyScriptParser::EqualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitEquality(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::EqualityContext* PyScriptParser::equality() {
  EqualityContext *_localctx = _tracker.createInstance<EqualityContext>(_ctx, getState());
  enterRule(_localctx, 46, PyScriptParser::RuleEquality);
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
    setState(306);
    comparison();
    setState(311);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(307);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::EQ

        || _la == PyScriptParser::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(308);
        comparison(); 
      }
      setState(313);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonContext ------------------------------------------------------------------

PyScriptParser::ComparisonContext::ComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::AdditiveContext *> PyScriptParser::ComparisonContext::additive() {
  return getRuleContexts<PyScriptParser::AdditiveContext>();
}

PyScriptParser::AdditiveContext* PyScriptParser::ComparisonContext::additive(size_t i) {
  return getRuleContext<PyScriptParser::AdditiveContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ComparisonContext::LT() {
  return getTokens(PyScriptParser::LT);
}

tree::TerminalNode* PyScriptParser::ComparisonContext::LT(size_t i) {
  return getToken(PyScriptParser::LT, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ComparisonContext::LE() {
  return getTokens(PyScriptParser::LE);
}

tree::TerminalNode* PyScriptParser::ComparisonContext::LE(size_t i) {
  return getToken(PyScriptParser::LE, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ComparisonContext::GT() {
  return getTokens(PyScriptParser::GT);
}

tree::TerminalNode* PyScriptParser::ComparisonContext::GT(size_t i) {
  return getToken(PyScriptParser::GT, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ComparisonContext::GE() {
  return getTokens(PyScriptParser::GE);
}

tree::TerminalNode* PyScriptParser::ComparisonContext::GE(size_t i) {
  return getToken(PyScriptParser::GE, i);
}


size_t PyScriptParser::ComparisonContext::getRuleIndex() const {
  return PyScriptParser::RuleComparison;
}

void PyScriptParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}

void PyScriptParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}


std::any PyScriptParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ComparisonContext* PyScriptParser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 48, PyScriptParser::RuleComparison);
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
    setState(314);
    additive();
    setState(319);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(315);
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
        setState(316);
        additive(); 
      }
      setState(321);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveContext ------------------------------------------------------------------

PyScriptParser::AdditiveContext::AdditiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::MultiplicativeContext *> PyScriptParser::AdditiveContext::multiplicative() {
  return getRuleContexts<PyScriptParser::MultiplicativeContext>();
}

PyScriptParser::MultiplicativeContext* PyScriptParser::AdditiveContext::multiplicative(size_t i) {
  return getRuleContext<PyScriptParser::MultiplicativeContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::AdditiveContext::PLUS() {
  return getTokens(PyScriptParser::PLUS);
}

tree::TerminalNode* PyScriptParser::AdditiveContext::PLUS(size_t i) {
  return getToken(PyScriptParser::PLUS, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::AdditiveContext::MINUS() {
  return getTokens(PyScriptParser::MINUS);
}

tree::TerminalNode* PyScriptParser::AdditiveContext::MINUS(size_t i) {
  return getToken(PyScriptParser::MINUS, i);
}


size_t PyScriptParser::AdditiveContext::getRuleIndex() const {
  return PyScriptParser::RuleAdditive;
}

void PyScriptParser::AdditiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditive(this);
}

void PyScriptParser::AdditiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditive(this);
}


std::any PyScriptParser::AdditiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAdditive(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AdditiveContext* PyScriptParser::additive() {
  AdditiveContext *_localctx = _tracker.createInstance<AdditiveContext>(_ctx, getState());
  enterRule(_localctx, 50, PyScriptParser::RuleAdditive);
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
    setState(322);
    multiplicative();
    setState(327);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(323);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::PLUS

        || _la == PyScriptParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(324);
        multiplicative(); 
      }
      setState(329);
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

//----------------- MultiplicativeContext ------------------------------------------------------------------

PyScriptParser::MultiplicativeContext::MultiplicativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::PowerContext *> PyScriptParser::MultiplicativeContext::power() {
  return getRuleContexts<PyScriptParser::PowerContext>();
}

PyScriptParser::PowerContext* PyScriptParser::MultiplicativeContext::power(size_t i) {
  return getRuleContext<PyScriptParser::PowerContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::MultiplicativeContext::MUL() {
  return getTokens(PyScriptParser::MUL);
}

tree::TerminalNode* PyScriptParser::MultiplicativeContext::MUL(size_t i) {
  return getToken(PyScriptParser::MUL, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::MultiplicativeContext::DIV() {
  return getTokens(PyScriptParser::DIV);
}

tree::TerminalNode* PyScriptParser::MultiplicativeContext::DIV(size_t i) {
  return getToken(PyScriptParser::DIV, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::MultiplicativeContext::MOD() {
  return getTokens(PyScriptParser::MOD);
}

tree::TerminalNode* PyScriptParser::MultiplicativeContext::MOD(size_t i) {
  return getToken(PyScriptParser::MOD, i);
}


size_t PyScriptParser::MultiplicativeContext::getRuleIndex() const {
  return PyScriptParser::RuleMultiplicative;
}

void PyScriptParser::MultiplicativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicative(this);
}

void PyScriptParser::MultiplicativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicative(this);
}


std::any PyScriptParser::MultiplicativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitMultiplicative(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::MultiplicativeContext* PyScriptParser::multiplicative() {
  MultiplicativeContext *_localctx = _tracker.createInstance<MultiplicativeContext>(_ctx, getState());
  enterRule(_localctx, 52, PyScriptParser::RuleMultiplicative);
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
    setState(330);
    power();
    setState(335);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(331);
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
        setState(332);
        power(); 
      }
      setState(337);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PowerContext ------------------------------------------------------------------

PyScriptParser::PowerContext::PowerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::UnaryContext* PyScriptParser::PowerContext::unary() {
  return getRuleContext<PyScriptParser::UnaryContext>(0);
}

tree::TerminalNode* PyScriptParser::PowerContext::DOUBLE_STAR() {
  return getToken(PyScriptParser::DOUBLE_STAR, 0);
}

PyScriptParser::PowerContext* PyScriptParser::PowerContext::power() {
  return getRuleContext<PyScriptParser::PowerContext>(0);
}


size_t PyScriptParser::PowerContext::getRuleIndex() const {
  return PyScriptParser::RulePower;
}

void PyScriptParser::PowerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPower(this);
}

void PyScriptParser::PowerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPower(this);
}


std::any PyScriptParser::PowerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitPower(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::PowerContext* PyScriptParser::power() {
  PowerContext *_localctx = _tracker.createInstance<PowerContext>(_ctx, getState());
  enterRule(_localctx, 54, PyScriptParser::RulePower);

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
    unary();
    setState(341);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(339);
      match(PyScriptParser::DOUBLE_STAR);
      setState(340);
      power();
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

//----------------- UnaryContext ------------------------------------------------------------------

PyScriptParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::AtomContext* PyScriptParser::UnaryContext::atom() {
  return getRuleContext<PyScriptParser::AtomContext>(0);
}

tree::TerminalNode* PyScriptParser::UnaryContext::NOT() {
  return getToken(PyScriptParser::NOT, 0);
}

tree::TerminalNode* PyScriptParser::UnaryContext::PLUS() {
  return getToken(PyScriptParser::PLUS, 0);
}

tree::TerminalNode* PyScriptParser::UnaryContext::MINUS() {
  return getToken(PyScriptParser::MINUS, 0);
}


size_t PyScriptParser::UnaryContext::getRuleIndex() const {
  return PyScriptParser::RuleUnary;
}

void PyScriptParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}

void PyScriptParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}


std::any PyScriptParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::UnaryContext* PyScriptParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 56, PyScriptParser::RuleUnary);
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
    setState(344);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS))) != 0)) {
      setState(343);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(346);
    atom();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

PyScriptParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::LiteralContext* PyScriptParser::PrimaryContext::literal() {
  return getRuleContext<PyScriptParser::LiteralContext>(0);
}

tree::TerminalNode* PyScriptParser::PrimaryContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::PrimaryContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::PrimaryContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::PrimaryContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::ListLiteralContext* PyScriptParser::PrimaryContext::listLiteral() {
  return getRuleContext<PyScriptParser::ListLiteralContext>(0);
}

PyScriptParser::DictLiteralContext* PyScriptParser::PrimaryContext::dictLiteral() {
  return getRuleContext<PyScriptParser::DictLiteralContext>(0);
}

PyScriptParser::SetLiteralContext* PyScriptParser::PrimaryContext::setLiteral() {
  return getRuleContext<PyScriptParser::SetLiteralContext>(0);
}

PyScriptParser::GeneratorExpressionContext* PyScriptParser::PrimaryContext::generatorExpression() {
  return getRuleContext<PyScriptParser::GeneratorExpressionContext>(0);
}

PyScriptParser::NewExpressionContext* PyScriptParser::PrimaryContext::newExpression() {
  return getRuleContext<PyScriptParser::NewExpressionContext>(0);
}

PyScriptParser::LambdaExpressionContext* PyScriptParser::PrimaryContext::lambdaExpression() {
  return getRuleContext<PyScriptParser::LambdaExpressionContext>(0);
}


size_t PyScriptParser::PrimaryContext::getRuleIndex() const {
  return PyScriptParser::RulePrimary;
}

void PyScriptParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void PyScriptParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


std::any PyScriptParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::PrimaryContext* PyScriptParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 58, PyScriptParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(360);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(348);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(349);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(350);
      match(PyScriptParser::LPAREN);
      setState(351);
      expression();
      setState(352);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(354);
      listLiteral();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(355);
      dictLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(356);
      setLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(357);
      generatorExpression();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(358);
      newExpression();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(359);
      lambdaExpression();
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
  enterRule(_localctx, 60, PyScriptParser::RuleNewExpression);
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
    setState(362);
    match(PyScriptParser::NEW);
    setState(363);
    dottedName();
    setState(364);
    match(PyScriptParser::LPAREN);
    setState(366);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING))) != 0)) {
      setState(365);
      argumentList();
    }
    setState(368);
    match(PyScriptParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

PyScriptParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::PrimaryContext* PyScriptParser::AtomContext::primary() {
  return getRuleContext<PyScriptParser::PrimaryContext>(0);
}

std::vector<PyScriptParser::PostfixOpContext *> PyScriptParser::AtomContext::postfixOp() {
  return getRuleContexts<PyScriptParser::PostfixOpContext>();
}

PyScriptParser::PostfixOpContext* PyScriptParser::AtomContext::postfixOp(size_t i) {
  return getRuleContext<PyScriptParser::PostfixOpContext>(i);
}


size_t PyScriptParser::AtomContext::getRuleIndex() const {
  return PyScriptParser::RuleAtom;
}

void PyScriptParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void PyScriptParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}


std::any PyScriptParser::AtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAtom(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AtomContext* PyScriptParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 62, PyScriptParser::RuleAtom);

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
    setState(370);
    primary();
    setState(374);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(371);
        postfixOp(); 
      }
      setState(376);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
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

PyScriptParser::SubscriptArgContext* PyScriptParser::SubscriptAccessOpContext::subscriptArg() {
  return getRuleContext<PyScriptParser::SubscriptArgContext>(0);
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
  enterRule(_localctx, 64, PyScriptParser::RulePostfixOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DOT: {
        _localctx = _tracker.createInstance<PyScriptParser::AttributeAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(377);
        match(PyScriptParser::DOT);
        setState(378);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::LBRACK: {
        _localctx = _tracker.createInstance<PyScriptParser::SubscriptAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(379);
        match(PyScriptParser::LBRACK);
        setState(380);
        subscriptArg();
        setState(381);
        match(PyScriptParser::RBRACK);
        break;
      }

      case PyScriptParser::LPAREN: {
        _localctx = _tracker.createInstance<PyScriptParser::FunctionCallOpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(383);
        match(PyScriptParser::LPAREN);
        setState(385);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::TRUE)
          | (1ULL << PyScriptParser::FALSE)
          | (1ULL << PyScriptParser::NONE)
          | (1ULL << PyScriptParser::NOT)
          | (1ULL << PyScriptParser::PLUS)
          | (1ULL << PyScriptParser::MINUS)
          | (1ULL << PyScriptParser::MUL)
          | (1ULL << PyScriptParser::LPAREN)
          | (1ULL << PyScriptParser::LBRACK)
          | (1ULL << PyScriptParser::LBRACE)
          | (1ULL << PyScriptParser::DOUBLE_STAR)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING))) != 0)) {
          setState(384);
          argumentList();
        }
        setState(387);
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

PyScriptParser::AtomContext* PyScriptParser::AttributeAccessContext::atom() {
  return getRuleContext<PyScriptParser::AtomContext>(0);
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
  enterRule(_localctx, 66, PyScriptParser::RuleAttributeAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    atom();
    setState(391);
    match(PyScriptParser::DOT);
    setState(392);
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

PyScriptParser::AtomContext* PyScriptParser::SubscriptAccessContext::atom() {
  return getRuleContext<PyScriptParser::AtomContext>(0);
}

tree::TerminalNode* PyScriptParser::SubscriptAccessContext::LBRACK() {
  return getToken(PyScriptParser::LBRACK, 0);
}

PyScriptParser::SubscriptArgContext* PyScriptParser::SubscriptAccessContext::subscriptArg() {
  return getRuleContext<PyScriptParser::SubscriptArgContext>(0);
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
  enterRule(_localctx, 68, PyScriptParser::RuleSubscriptAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    atom();
    setState(395);
    match(PyScriptParser::LBRACK);
    setState(396);
    subscriptArg();
    setState(397);
    match(PyScriptParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubscriptArgContext ------------------------------------------------------------------

PyScriptParser::SubscriptArgContext::SubscriptArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::SubscriptArgContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::SubscriptArgContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::SubscriptArgContext::COLON() {
  return getTokens(PyScriptParser::COLON);
}

tree::TerminalNode* PyScriptParser::SubscriptArgContext::COLON(size_t i) {
  return getToken(PyScriptParser::COLON, i);
}


size_t PyScriptParser::SubscriptArgContext::getRuleIndex() const {
  return PyScriptParser::RuleSubscriptArg;
}

void PyScriptParser::SubscriptArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscriptArg(this);
}

void PyScriptParser::SubscriptArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscriptArg(this);
}


std::any PyScriptParser::SubscriptArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSubscriptArg(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::SubscriptArgContext* PyScriptParser::subscriptArg() {
  SubscriptArgContext *_localctx = _tracker.createInstance<SubscriptArgContext>(_ctx, getState());
  enterRule(_localctx, 70, PyScriptParser::RuleSubscriptArg);
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
    setState(400);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING))) != 0)) {
      setState(399);
      expression();
    }
    setState(412);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COLON) {
      setState(402);
      match(PyScriptParser::COLON);
      setState(404);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
        | (1ULL << PyScriptParser::LAMBDA)
        | (1ULL << PyScriptParser::TRUE)
        | (1ULL << PyScriptParser::FALSE)
        | (1ULL << PyScriptParser::NONE)
        | (1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS)
        | (1ULL << PyScriptParser::LPAREN)
        | (1ULL << PyScriptParser::LBRACK)
        | (1ULL << PyScriptParser::LBRACE)
        | (1ULL << PyScriptParser::IDENTIFIER)
        | (1ULL << PyScriptParser::INTEGER)
        | (1ULL << PyScriptParser::FLOAT)
        | (1ULL << PyScriptParser::STRING))) != 0)) {
        setState(403);
        expression();
      }
      setState(410);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COLON) {
        setState(406);
        match(PyScriptParser::COLON);
        setState(408);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::TRUE)
          | (1ULL << PyScriptParser::FALSE)
          | (1ULL << PyScriptParser::NONE)
          | (1ULL << PyScriptParser::NOT)
          | (1ULL << PyScriptParser::PLUS)
          | (1ULL << PyScriptParser::MINUS)
          | (1ULL << PyScriptParser::LPAREN)
          | (1ULL << PyScriptParser::LBRACK)
          | (1ULL << PyScriptParser::LBRACE)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING))) != 0)) {
          setState(407);
          expression();
        }
      }
    }
   
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

PyScriptParser::AtomContext* PyScriptParser::FunctionCallContext::atom() {
  return getRuleContext<PyScriptParser::AtomContext>(0);
}

tree::TerminalNode* PyScriptParser::FunctionCallContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

tree::TerminalNode* PyScriptParser::FunctionCallContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
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
  enterRule(_localctx, 72, PyScriptParser::RuleFunctionCall);
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
    setState(414);
    atom();
    setState(415);
    match(PyScriptParser::LPAREN);
    setState(417);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING))) != 0)) {
      setState(416);
      argumentList();
    }
    setState(419);
    match(PyScriptParser::RPAREN);
   
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
  enterRule(_localctx, 74, PyScriptParser::RuleArgumentList);
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
    setState(421);
    argument();
    setState(426);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(422);
        match(PyScriptParser::COMMA);
        setState(423);
        argument(); 
      }
      setState(428);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
    setState(430);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(429);
      match(PyScriptParser::COMMA);
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

tree::TerminalNode* PyScriptParser::ArgumentContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::ArgumentContext::ASSIGN() {
  return getToken(PyScriptParser::ASSIGN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::ArgumentContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
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
  enterRule(_localctx, 76, PyScriptParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(440);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(432);
      match(PyScriptParser::IDENTIFIER);
      setState(433);
      match(PyScriptParser::ASSIGN);
      setState(434);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(435);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(436);
      match(PyScriptParser::MUL);
      setState(437);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(438);
      match(PyScriptParser::DOUBLE_STAR);
      setState(439);
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

PyScriptParser::ListElementsContext* PyScriptParser::ListLiteralContext::listElements() {
  return getRuleContext<PyScriptParser::ListElementsContext>(0);
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
  enterRule(_localctx, 78, PyScriptParser::RuleListLiteral);
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
    setState(442);
    match(PyScriptParser::LBRACK);
    setState(444);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING))) != 0)) {
      setState(443);
      listElements();
    }
    setState(446);
    match(PyScriptParser::RBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListElementsContext ------------------------------------------------------------------

PyScriptParser::ListElementsContext::ListElementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::ListElementsContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::ListElementsContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ListElementsContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::ListElementsContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}

tree::TerminalNode* PyScriptParser::ListElementsContext::FOR() {
  return getToken(PyScriptParser::FOR, 0);
}

tree::TerminalNode* PyScriptParser::ListElementsContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::ListElementsContext::IN() {
  return getToken(PyScriptParser::IN, 0);
}


size_t PyScriptParser::ListElementsContext::getRuleIndex() const {
  return PyScriptParser::RuleListElements;
}

void PyScriptParser::ListElementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListElements(this);
}

void PyScriptParser::ListElementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListElements(this);
}


std::any PyScriptParser::ListElementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitListElements(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ListElementsContext* PyScriptParser::listElements() {
  ListElementsContext *_localctx = _tracker.createInstance<ListElementsContext>(_ctx, getState());
  enterRule(_localctx, 80, PyScriptParser::RuleListElements);
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
    setState(465);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(448);
      expression();
      setState(453);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(449);
          match(PyScriptParser::COMMA);
          setState(450);
          expression(); 
        }
        setState(455);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      }
      setState(457);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(456);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(459);
      expression();
      setState(460);
      match(PyScriptParser::FOR);
      setState(461);
      match(PyScriptParser::IDENTIFIER);
      setState(462);
      match(PyScriptParser::IN);
      setState(463);
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

PyScriptParser::DictComprehensionContext* PyScriptParser::DictLiteralContext::dictComprehension() {
  return getRuleContext<PyScriptParser::DictComprehensionContext>(0);
}

std::vector<PyScriptParser::DictItemContext *> PyScriptParser::DictLiteralContext::dictItem() {
  return getRuleContexts<PyScriptParser::DictItemContext>();
}

PyScriptParser::DictItemContext* PyScriptParser::DictLiteralContext::dictItem(size_t i) {
  return getRuleContext<PyScriptParser::DictItemContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::DictLiteralContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::DictLiteralContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
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
  enterRule(_localctx, 82, PyScriptParser::RuleDictLiteral);
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
    setState(467);
    match(PyScriptParser::LBRACE);
    setState(482);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      setState(468);
      dictComprehension();
      break;
    }

    case 2: {
      setState(480);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
        | (1ULL << PyScriptParser::LAMBDA)
        | (1ULL << PyScriptParser::TRUE)
        | (1ULL << PyScriptParser::FALSE)
        | (1ULL << PyScriptParser::NONE)
        | (1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS)
        | (1ULL << PyScriptParser::LPAREN)
        | (1ULL << PyScriptParser::LBRACK)
        | (1ULL << PyScriptParser::LBRACE)
        | (1ULL << PyScriptParser::DOUBLE_STAR)
        | (1ULL << PyScriptParser::IDENTIFIER)
        | (1ULL << PyScriptParser::INTEGER)
        | (1ULL << PyScriptParser::FLOAT)
        | (1ULL << PyScriptParser::STRING))) != 0)) {
        setState(469);
        dictItem();
        setState(474);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(470);
            match(PyScriptParser::COMMA);
            setState(471);
            dictItem(); 
          }
          setState(476);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
        }
        setState(478);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::COMMA) {
          setState(477);
          match(PyScriptParser::COMMA);
        }
      }
      break;
    }

    default:
      break;
    }
    setState(484);
    match(PyScriptParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictComprehensionContext ------------------------------------------------------------------

PyScriptParser::DictComprehensionContext::DictComprehensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::DictComprehensionContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::DictComprehensionContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::DictComprehensionContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

tree::TerminalNode* PyScriptParser::DictComprehensionContext::FOR() {
  return getToken(PyScriptParser::FOR, 0);
}

tree::TerminalNode* PyScriptParser::DictComprehensionContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::DictComprehensionContext::IN() {
  return getToken(PyScriptParser::IN, 0);
}


size_t PyScriptParser::DictComprehensionContext::getRuleIndex() const {
  return PyScriptParser::RuleDictComprehension;
}

void PyScriptParser::DictComprehensionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictComprehension(this);
}

void PyScriptParser::DictComprehensionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictComprehension(this);
}


std::any PyScriptParser::DictComprehensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDictComprehension(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DictComprehensionContext* PyScriptParser::dictComprehension() {
  DictComprehensionContext *_localctx = _tracker.createInstance<DictComprehensionContext>(_ctx, getState());
  enterRule(_localctx, 84, PyScriptParser::RuleDictComprehension);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(486);
    expression();
    setState(487);
    match(PyScriptParser::COLON);
    setState(488);
    expression();
    setState(489);
    match(PyScriptParser::FOR);
    setState(490);
    match(PyScriptParser::IDENTIFIER);
    setState(491);
    match(PyScriptParser::IN);
    setState(492);
    expression();
   
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

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::DictItemContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::DictItemContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::DictItemContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

tree::TerminalNode* PyScriptParser::DictItemContext::DOUBLE_STAR() {
  return getToken(PyScriptParser::DOUBLE_STAR, 0);
}


size_t PyScriptParser::DictItemContext::getRuleIndex() const {
  return PyScriptParser::RuleDictItem;
}

void PyScriptParser::DictItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictItem(this);
}

void PyScriptParser::DictItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictItem(this);
}


std::any PyScriptParser::DictItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDictItem(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DictItemContext* PyScriptParser::dictItem() {
  DictItemContext *_localctx = _tracker.createInstance<DictItemContext>(_ctx, getState());
  enterRule(_localctx, 86, PyScriptParser::RuleDictItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(500);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::TRUE:
      case PyScriptParser::FALSE:
      case PyScriptParser::NONE:
      case PyScriptParser::NOT:
      case PyScriptParser::PLUS:
      case PyScriptParser::MINUS:
      case PyScriptParser::LPAREN:
      case PyScriptParser::LBRACK:
      case PyScriptParser::LBRACE:
      case PyScriptParser::IDENTIFIER:
      case PyScriptParser::INTEGER:
      case PyScriptParser::FLOAT:
      case PyScriptParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(494);
        expression();
        setState(495);
        match(PyScriptParser::COLON);
        setState(496);
        expression();
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 2);
        setState(498);
        match(PyScriptParser::DOUBLE_STAR);
        setState(499);
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

//----------------- SetLiteralContext ------------------------------------------------------------------

PyScriptParser::SetLiteralContext::SetLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::SetLiteralContext::LBRACE() {
  return getToken(PyScriptParser::LBRACE, 0);
}

tree::TerminalNode* PyScriptParser::SetLiteralContext::RBRACE() {
  return getToken(PyScriptParser::RBRACE, 0);
}

PyScriptParser::SetElementsContext* PyScriptParser::SetLiteralContext::setElements() {
  return getRuleContext<PyScriptParser::SetElementsContext>(0);
}


size_t PyScriptParser::SetLiteralContext::getRuleIndex() const {
  return PyScriptParser::RuleSetLiteral;
}

void PyScriptParser::SetLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetLiteral(this);
}

void PyScriptParser::SetLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetLiteral(this);
}


std::any PyScriptParser::SetLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSetLiteral(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::SetLiteralContext* PyScriptParser::setLiteral() {
  SetLiteralContext *_localctx = _tracker.createInstance<SetLiteralContext>(_ctx, getState());
  enterRule(_localctx, 88, PyScriptParser::RuleSetLiteral);
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
    setState(502);
    match(PyScriptParser::LBRACE);
    setState(504);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::LPAREN)
      | (1ULL << PyScriptParser::LBRACK)
      | (1ULL << PyScriptParser::LBRACE)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING))) != 0)) {
      setState(503);
      setElements();
    }
    setState(506);
    match(PyScriptParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetElementsContext ------------------------------------------------------------------

PyScriptParser::SetElementsContext::SetElementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::SetElementsContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::SetElementsContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::SetElementsContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::SetElementsContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}

tree::TerminalNode* PyScriptParser::SetElementsContext::FOR() {
  return getToken(PyScriptParser::FOR, 0);
}

tree::TerminalNode* PyScriptParser::SetElementsContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::SetElementsContext::IN() {
  return getToken(PyScriptParser::IN, 0);
}


size_t PyScriptParser::SetElementsContext::getRuleIndex() const {
  return PyScriptParser::RuleSetElements;
}

void PyScriptParser::SetElementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetElements(this);
}

void PyScriptParser::SetElementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetElements(this);
}


std::any PyScriptParser::SetElementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSetElements(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::SetElementsContext* PyScriptParser::setElements() {
  SetElementsContext *_localctx = _tracker.createInstance<SetElementsContext>(_ctx, getState());
  enterRule(_localctx, 90, PyScriptParser::RuleSetElements);
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
    setState(525);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(508);
      expression();
      setState(513);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(509);
          match(PyScriptParser::COMMA);
          setState(510);
          expression(); 
        }
        setState(515);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
      }
      setState(517);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(516);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(519);
      expression();
      setState(520);
      match(PyScriptParser::FOR);
      setState(521);
      match(PyScriptParser::IDENTIFIER);
      setState(522);
      match(PyScriptParser::IN);
      setState(523);
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

//----------------- GeneratorExpressionContext ------------------------------------------------------------------

PyScriptParser::GeneratorExpressionContext::GeneratorExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::GeneratorExpressionContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::GeneratorExpressionContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::GeneratorExpressionContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::GeneratorExpressionContext::FOR() {
  return getToken(PyScriptParser::FOR, 0);
}

tree::TerminalNode* PyScriptParser::GeneratorExpressionContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::GeneratorExpressionContext::IN() {
  return getToken(PyScriptParser::IN, 0);
}

tree::TerminalNode* PyScriptParser::GeneratorExpressionContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}


size_t PyScriptParser::GeneratorExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleGeneratorExpression;
}

void PyScriptParser::GeneratorExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneratorExpression(this);
}

void PyScriptParser::GeneratorExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneratorExpression(this);
}


std::any PyScriptParser::GeneratorExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitGeneratorExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::GeneratorExpressionContext* PyScriptParser::generatorExpression() {
  GeneratorExpressionContext *_localctx = _tracker.createInstance<GeneratorExpressionContext>(_ctx, getState());
  enterRule(_localctx, 92, PyScriptParser::RuleGeneratorExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(527);
    match(PyScriptParser::LPAREN);
    setState(528);
    expression();
    setState(529);
    match(PyScriptParser::FOR);
    setState(530);
    match(PyScriptParser::IDENTIFIER);
    setState(531);
    match(PyScriptParser::IN);
    setState(532);
    expression();
    setState(533);
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

tree::TerminalNode* PyScriptParser::LiteralContext::TRUE() {
  return getToken(PyScriptParser::TRUE, 0);
}

tree::TerminalNode* PyScriptParser::LiteralContext::FALSE() {
  return getToken(PyScriptParser::FALSE, 0);
}

tree::TerminalNode* PyScriptParser::LiteralContext::NONE() {
  return getToken(PyScriptParser::NONE, 0);
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
  enterRule(_localctx, 94, PyScriptParser::RuleLiteral);
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
    setState(535);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING))) != 0))) {
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

PyScriptParser::ParameterListContext* PyScriptParser::LambdaExpressionContext::parameterList() {
  return getRuleContext<PyScriptParser::ParameterListContext>(0);
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
  enterRule(_localctx, 96, PyScriptParser::RuleLambdaExpression);
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
    setState(537);
    match(PyScriptParser::LAMBDA);
    setState(539);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::IDENTIFIER))) != 0)) {
      setState(538);
      parameterList();
    }
    setState(541);
    match(PyScriptParser::COLON);
    setState(542);
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
  enterRule(_localctx, 98, PyScriptParser::RuleDottedName);
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
    setState(544);
    match(PyScriptParser::IDENTIFIER);
    setState(549);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::DOT) {
      setState(545);
      match(PyScriptParser::DOT);
      setState(546);
      match(PyScriptParser::IDENTIFIER);
      setState(551);
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

void PyScriptParser::initialize() {
  std::call_once(pyscriptParserOnceFlag, pyscriptParserInitialize);
}
