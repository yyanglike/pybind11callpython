
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
      "tryStatement", "exceptClause", "withStatement", "withItem", "asyncFunctionDef", 
      "asyncForStatement", "asyncWithStatement", "awaitExpr", "classDef", 
      "suite", "functionDef", "parameterList", "parameter", "ifStatement", 
      "whileStatement", "forStatement", "passStatement", "returnStatement", 
      "importStatement", "importItem", "assignment", "expressionStatement", 
      "expression", "logicalOr", "logicalAnd", "equality", "comparison", 
      "additive", "multiplicative", "power", "unary", "primary", "newExpression", 
      "atom", "postfixOp", "attributeAccess", "subscriptAccess", "subscriptArg", 
      "functionCall", "argumentList", "argument", "listLiteral", "listElements", 
      "dictLiteral", "dictComprehension", "dictItem", "setLiteral", "setElements", 
      "generatorExpression", "literal", "lambdaExpression", "dottedName"
    },
    std::vector<std::string>{
      "", "'def'", "'if'", "'else'", "'for'", "'while'", "'return'", "'import'", 
      "'from'", "'as'", "'in'", "'pass'", "'new'", "'lambda'", "'try'", 
      "'except'", "'finally'", "'with'", "'async'", "'await'", "'class'", 
      "'true'", "'false'", "'none'", "'and'", "'or'", "'not'", "'+'", "'-'", 
      "'*'", "'/'", "'%'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", 
      "'='", "';'", "'('", "')'", "'['", "']'", "'{'", "'}'", "','", "':'", 
      "'.'", "'**'"
    },
    std::vector<std::string>{
      "", "DEF", "IF", "ELSE", "FOR", "WHILE", "RETURN", "IMPORT", "FROM", 
      "AS", "IN", "PASS", "NEW", "LAMBDA", "TRY", "EXCEPT", "FINALLY", "WITH", 
      "ASYNC", "AWAIT", "CLASS", "TRUE", "FALSE", "NONE", "AND", "OR", "NOT", 
      "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "NE", "LT", "LE", "GT", 
      "GE", "ASSIGN", "SEMI", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", 
      "RBRACE", "COMMA", "COLON", "DOT", "DOUBLE_STAR", "NEWLINE", "IDENTIFIER", 
      "INTEGER", "FLOAT", "STRING", "WS", "COMMENT", "INDENT", "DEDENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,58,622,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,1,0,5,0,116,8,0,10,0,12,0,119,9,0,1,0,1,0,1,1,1,1,3,1,125,8,1,1,2,
  	1,2,1,2,5,2,130,8,2,10,2,12,2,133,9,2,1,2,3,2,136,8,2,1,2,3,2,139,8,2,
  	1,3,1,3,1,3,1,3,1,3,3,3,146,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,3,4,158,8,4,1,5,1,5,1,5,1,5,5,5,164,8,5,10,5,12,5,167,9,5,1,5,1,5,1,
  	5,3,5,172,8,5,1,5,1,5,1,5,3,5,177,8,5,1,6,1,6,1,6,1,6,3,6,183,8,6,3,6,
  	185,8,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,5,7,194,8,7,10,7,12,7,197,9,7,1,7,
  	1,7,1,7,1,8,1,8,1,8,3,8,205,8,8,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,
  	1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,4,14,
  	228,8,14,11,14,12,14,229,1,14,1,14,3,14,234,8,14,1,15,1,15,1,15,1,15,
  	3,15,240,8,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,5,16,249,8,16,10,16,
  	12,16,252,9,16,1,16,3,16,255,8,16,1,17,1,17,1,17,3,17,260,8,17,1,17,1,
  	17,3,17,264,8,17,1,17,1,17,3,17,268,8,17,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,5,18,280,8,18,10,18,12,18,283,9,18,1,18,1,18,1,18,
  	3,18,288,8,18,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,21,1,21,1,22,1,22,3,22,306,8,22,1,23,1,23,1,23,1,23,3,23,312,8,
  	23,1,23,1,23,1,23,1,23,1,23,1,23,5,23,320,8,23,10,23,12,23,323,9,23,3,
  	23,325,8,23,1,24,1,24,1,24,3,24,330,8,24,1,25,1,25,1,25,3,25,335,8,25,
  	1,25,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,28,5,28,347,8,28,10,28,
  	12,28,350,9,28,1,29,1,29,1,29,5,29,355,8,29,10,29,12,29,358,9,29,1,30,
  	1,30,1,30,5,30,363,8,30,10,30,12,30,366,9,30,1,31,1,31,1,31,5,31,371,
  	8,31,10,31,12,31,374,9,31,1,32,1,32,1,32,5,32,379,8,32,10,32,12,32,382,
  	9,32,1,33,1,33,1,33,5,33,387,8,33,10,33,12,33,390,9,33,1,34,1,34,1,34,
  	3,34,395,8,34,1,35,3,35,398,8,35,1,35,1,35,3,35,402,8,35,1,36,1,36,1,
  	36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,3,36,417,8,36,1,
  	37,1,37,1,37,1,37,3,37,423,8,37,1,37,1,37,1,38,1,38,5,38,429,8,38,10,
  	38,12,38,432,9,38,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,3,39,442,8,
  	39,1,39,3,39,445,8,39,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,
  	42,3,42,457,8,42,1,42,1,42,3,42,461,8,42,1,42,1,42,3,42,465,8,42,3,42,
  	467,8,42,3,42,469,8,42,1,43,1,43,1,43,3,43,474,8,43,1,43,1,43,1,44,1,
  	44,1,44,5,44,481,8,44,10,44,12,44,484,9,44,1,44,3,44,487,8,44,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,3,45,497,8,45,1,46,1,46,3,46,501,8,46,
  	1,46,1,46,1,47,1,47,1,47,5,47,508,8,47,10,47,12,47,511,9,47,1,47,3,47,
  	514,8,47,1,47,1,47,1,47,1,47,1,47,1,47,1,47,3,47,523,8,47,3,47,525,8,
  	47,1,48,1,48,1,48,1,48,1,48,5,48,532,8,48,10,48,12,48,535,9,48,1,48,3,
  	48,538,8,48,3,48,540,8,48,3,48,542,8,48,1,48,1,48,1,49,1,49,1,49,1,49,
  	1,49,1,49,1,49,1,49,1,49,3,49,555,8,49,1,50,1,50,1,50,1,50,1,50,1,50,
  	3,50,563,8,50,1,51,1,51,3,51,567,8,51,1,51,1,51,1,52,1,52,1,52,5,52,574,
  	8,52,10,52,12,52,577,9,52,1,52,3,52,580,8,52,1,52,1,52,1,52,1,52,1,52,
  	1,52,1,52,3,52,589,8,52,3,52,591,8,52,1,53,1,53,1,53,1,53,1,53,1,53,1,
  	53,1,53,3,53,601,8,53,1,53,1,53,1,54,1,54,1,55,1,55,3,55,609,8,55,1,55,
  	1,55,1,55,1,56,1,56,1,56,5,56,617,8,56,10,56,12,56,620,9,56,1,56,0,0,
  	57,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,
  	48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,
  	94,96,98,100,102,104,106,108,110,112,0,6,1,0,32,33,1,0,34,37,1,0,27,28,
  	1,0,29,31,1,0,26,28,2,0,21,23,52,54,660,0,117,1,0,0,0,2,124,1,0,0,0,4,
  	126,1,0,0,0,6,145,1,0,0,0,8,157,1,0,0,0,10,159,1,0,0,0,12,178,1,0,0,0,
  	14,189,1,0,0,0,16,201,1,0,0,0,18,206,1,0,0,0,20,209,1,0,0,0,22,212,1,
  	0,0,0,24,215,1,0,0,0,26,218,1,0,0,0,28,233,1,0,0,0,30,235,1,0,0,0,32,
  	245,1,0,0,0,34,267,1,0,0,0,36,269,1,0,0,0,38,289,1,0,0,0,40,294,1,0,0,
  	0,42,301,1,0,0,0,44,303,1,0,0,0,46,324,1,0,0,0,48,326,1,0,0,0,50,334,
  	1,0,0,0,52,339,1,0,0,0,54,341,1,0,0,0,56,343,1,0,0,0,58,351,1,0,0,0,60,
  	359,1,0,0,0,62,367,1,0,0,0,64,375,1,0,0,0,66,383,1,0,0,0,68,391,1,0,0,
  	0,70,401,1,0,0,0,72,416,1,0,0,0,74,418,1,0,0,0,76,426,1,0,0,0,78,444,
  	1,0,0,0,80,446,1,0,0,0,82,450,1,0,0,0,84,456,1,0,0,0,86,470,1,0,0,0,88,
  	477,1,0,0,0,90,496,1,0,0,0,92,498,1,0,0,0,94,524,1,0,0,0,96,526,1,0,0,
  	0,98,545,1,0,0,0,100,562,1,0,0,0,102,564,1,0,0,0,104,590,1,0,0,0,106,
  	592,1,0,0,0,108,604,1,0,0,0,110,606,1,0,0,0,112,613,1,0,0,0,114,116,3,
  	2,1,0,115,114,1,0,0,0,116,119,1,0,0,0,117,115,1,0,0,0,117,118,1,0,0,0,
  	118,120,1,0,0,0,119,117,1,0,0,0,120,121,5,0,0,1,121,1,1,0,0,0,122,125,
  	3,4,2,0,123,125,3,8,4,0,124,122,1,0,0,0,124,123,1,0,0,0,125,3,1,0,0,0,
  	126,131,3,6,3,0,127,128,5,39,0,0,128,130,3,6,3,0,129,127,1,0,0,0,130,
  	133,1,0,0,0,131,129,1,0,0,0,131,132,1,0,0,0,132,135,1,0,0,0,133,131,1,
  	0,0,0,134,136,5,39,0,0,135,134,1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,
  	0,137,139,5,50,0,0,138,137,1,0,0,0,138,139,1,0,0,0,139,5,1,0,0,0,140,
  	146,3,50,25,0,141,146,3,44,22,0,142,146,3,52,26,0,143,146,3,46,23,0,144,
  	146,3,42,21,0,145,140,1,0,0,0,145,141,1,0,0,0,145,142,1,0,0,0,145,143,
  	1,0,0,0,145,144,1,0,0,0,146,7,1,0,0,0,147,158,3,30,15,0,148,158,3,18,
  	9,0,149,158,3,26,13,0,150,158,3,36,18,0,151,158,3,38,19,0,152,158,3,40,
  	20,0,153,158,3,20,10,0,154,158,3,10,5,0,155,158,3,14,7,0,156,158,3,22,
  	11,0,157,147,1,0,0,0,157,148,1,0,0,0,157,149,1,0,0,0,157,150,1,0,0,0,
  	157,151,1,0,0,0,157,152,1,0,0,0,157,153,1,0,0,0,157,154,1,0,0,0,157,155,
  	1,0,0,0,157,156,1,0,0,0,158,9,1,0,0,0,159,160,5,14,0,0,160,161,5,47,0,
  	0,161,165,3,28,14,0,162,164,3,12,6,0,163,162,1,0,0,0,164,167,1,0,0,0,
  	165,163,1,0,0,0,165,166,1,0,0,0,166,171,1,0,0,0,167,165,1,0,0,0,168,169,
  	5,3,0,0,169,170,5,47,0,0,170,172,3,28,14,0,171,168,1,0,0,0,171,172,1,
  	0,0,0,172,176,1,0,0,0,173,174,5,16,0,0,174,175,5,47,0,0,175,177,3,28,
  	14,0,176,173,1,0,0,0,176,177,1,0,0,0,177,11,1,0,0,0,178,184,5,15,0,0,
  	179,182,3,112,56,0,180,181,5,9,0,0,181,183,5,51,0,0,182,180,1,0,0,0,182,
  	183,1,0,0,0,183,185,1,0,0,0,184,179,1,0,0,0,184,185,1,0,0,0,185,186,1,
  	0,0,0,186,187,5,47,0,0,187,188,3,28,14,0,188,13,1,0,0,0,189,190,5,17,
  	0,0,190,195,3,16,8,0,191,192,5,46,0,0,192,194,3,16,8,0,193,191,1,0,0,
  	0,194,197,1,0,0,0,195,193,1,0,0,0,195,196,1,0,0,0,196,198,1,0,0,0,197,
  	195,1,0,0,0,198,199,5,47,0,0,199,200,3,28,14,0,200,15,1,0,0,0,201,204,
  	3,54,27,0,202,203,5,9,0,0,203,205,5,51,0,0,204,202,1,0,0,0,204,205,1,
  	0,0,0,205,17,1,0,0,0,206,207,5,18,0,0,207,208,3,30,15,0,208,19,1,0,0,
  	0,209,210,5,18,0,0,210,211,3,40,20,0,211,21,1,0,0,0,212,213,5,18,0,0,
  	213,214,3,14,7,0,214,23,1,0,0,0,215,216,5,19,0,0,216,217,3,54,27,0,217,
  	25,1,0,0,0,218,219,5,20,0,0,219,220,5,51,0,0,220,221,5,47,0,0,221,222,
  	3,28,14,0,222,27,1,0,0,0,223,234,3,4,2,0,224,225,5,50,0,0,225,227,5,57,
  	0,0,226,228,3,2,1,0,227,226,1,0,0,0,228,229,1,0,0,0,229,227,1,0,0,0,229,
  	230,1,0,0,0,230,231,1,0,0,0,231,232,5,58,0,0,232,234,1,0,0,0,233,223,
  	1,0,0,0,233,224,1,0,0,0,234,29,1,0,0,0,235,236,5,1,0,0,236,237,5,51,0,
  	0,237,239,5,40,0,0,238,240,3,32,16,0,239,238,1,0,0,0,239,240,1,0,0,0,
  	240,241,1,0,0,0,241,242,5,41,0,0,242,243,5,47,0,0,243,244,3,28,14,0,244,
  	31,1,0,0,0,245,250,3,34,17,0,246,247,5,46,0,0,247,249,3,34,17,0,248,246,
  	1,0,0,0,249,252,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,254,1,0,0,
  	0,252,250,1,0,0,0,253,255,5,46,0,0,254,253,1,0,0,0,254,255,1,0,0,0,255,
  	33,1,0,0,0,256,259,5,51,0,0,257,258,5,38,0,0,258,260,3,54,27,0,259,257,
  	1,0,0,0,259,260,1,0,0,0,260,268,1,0,0,0,261,263,5,29,0,0,262,264,5,51,
  	0,0,263,262,1,0,0,0,263,264,1,0,0,0,264,268,1,0,0,0,265,266,5,49,0,0,
  	266,268,5,51,0,0,267,256,1,0,0,0,267,261,1,0,0,0,267,265,1,0,0,0,268,
  	35,1,0,0,0,269,270,5,2,0,0,270,271,3,54,27,0,271,272,5,47,0,0,272,281,
  	3,28,14,0,273,274,5,3,0,0,274,275,5,2,0,0,275,276,3,54,27,0,276,277,5,
  	47,0,0,277,278,3,28,14,0,278,280,1,0,0,0,279,273,1,0,0,0,280,283,1,0,
  	0,0,281,279,1,0,0,0,281,282,1,0,0,0,282,287,1,0,0,0,283,281,1,0,0,0,284,
  	285,5,3,0,0,285,286,5,47,0,0,286,288,3,28,14,0,287,284,1,0,0,0,287,288,
  	1,0,0,0,288,37,1,0,0,0,289,290,5,5,0,0,290,291,3,54,27,0,291,292,5,47,
  	0,0,292,293,3,28,14,0,293,39,1,0,0,0,294,295,5,4,0,0,295,296,5,51,0,0,
  	296,297,5,10,0,0,297,298,3,54,27,0,298,299,5,47,0,0,299,300,3,28,14,0,
  	300,41,1,0,0,0,301,302,5,11,0,0,302,43,1,0,0,0,303,305,5,6,0,0,304,306,
  	3,54,27,0,305,304,1,0,0,0,305,306,1,0,0,0,306,45,1,0,0,0,307,308,5,7,
  	0,0,308,311,3,112,56,0,309,310,5,9,0,0,310,312,5,51,0,0,311,309,1,0,0,
  	0,311,312,1,0,0,0,312,325,1,0,0,0,313,314,5,8,0,0,314,315,3,112,56,0,
  	315,316,5,7,0,0,316,321,3,48,24,0,317,318,5,46,0,0,318,320,3,48,24,0,
  	319,317,1,0,0,0,320,323,1,0,0,0,321,319,1,0,0,0,321,322,1,0,0,0,322,325,
  	1,0,0,0,323,321,1,0,0,0,324,307,1,0,0,0,324,313,1,0,0,0,325,47,1,0,0,
  	0,326,329,5,51,0,0,327,328,5,9,0,0,328,330,5,51,0,0,329,327,1,0,0,0,329,
  	330,1,0,0,0,330,49,1,0,0,0,331,335,5,51,0,0,332,335,3,80,40,0,333,335,
  	3,82,41,0,334,331,1,0,0,0,334,332,1,0,0,0,334,333,1,0,0,0,335,336,1,0,
  	0,0,336,337,5,38,0,0,337,338,3,54,27,0,338,51,1,0,0,0,339,340,3,54,27,
  	0,340,53,1,0,0,0,341,342,3,56,28,0,342,55,1,0,0,0,343,348,3,58,29,0,344,
  	345,5,25,0,0,345,347,3,58,29,0,346,344,1,0,0,0,347,350,1,0,0,0,348,346,
  	1,0,0,0,348,349,1,0,0,0,349,57,1,0,0,0,350,348,1,0,0,0,351,356,3,60,30,
  	0,352,353,5,24,0,0,353,355,3,60,30,0,354,352,1,0,0,0,355,358,1,0,0,0,
  	356,354,1,0,0,0,356,357,1,0,0,0,357,59,1,0,0,0,358,356,1,0,0,0,359,364,
  	3,62,31,0,360,361,7,0,0,0,361,363,3,62,31,0,362,360,1,0,0,0,363,366,1,
  	0,0,0,364,362,1,0,0,0,364,365,1,0,0,0,365,61,1,0,0,0,366,364,1,0,0,0,
  	367,372,3,64,32,0,368,369,7,1,0,0,369,371,3,64,32,0,370,368,1,0,0,0,371,
  	374,1,0,0,0,372,370,1,0,0,0,372,373,1,0,0,0,373,63,1,0,0,0,374,372,1,
  	0,0,0,375,380,3,66,33,0,376,377,7,2,0,0,377,379,3,66,33,0,378,376,1,0,
  	0,0,379,382,1,0,0,0,380,378,1,0,0,0,380,381,1,0,0,0,381,65,1,0,0,0,382,
  	380,1,0,0,0,383,388,3,68,34,0,384,385,7,3,0,0,385,387,3,68,34,0,386,384,
  	1,0,0,0,387,390,1,0,0,0,388,386,1,0,0,0,388,389,1,0,0,0,389,67,1,0,0,
  	0,390,388,1,0,0,0,391,394,3,70,35,0,392,393,5,49,0,0,393,395,3,68,34,
  	0,394,392,1,0,0,0,394,395,1,0,0,0,395,69,1,0,0,0,396,398,7,4,0,0,397,
  	396,1,0,0,0,397,398,1,0,0,0,398,399,1,0,0,0,399,402,3,76,38,0,400,402,
  	3,24,12,0,401,397,1,0,0,0,401,400,1,0,0,0,402,71,1,0,0,0,403,417,3,108,
  	54,0,404,417,5,51,0,0,405,406,5,40,0,0,406,407,3,54,27,0,407,408,5,41,
  	0,0,408,417,1,0,0,0,409,417,3,92,46,0,410,417,3,96,48,0,411,417,3,102,
  	51,0,412,417,3,106,53,0,413,417,3,74,37,0,414,417,3,110,55,0,415,417,
  	3,24,12,0,416,403,1,0,0,0,416,404,1,0,0,0,416,405,1,0,0,0,416,409,1,0,
  	0,0,416,410,1,0,0,0,416,411,1,0,0,0,416,412,1,0,0,0,416,413,1,0,0,0,416,
  	414,1,0,0,0,416,415,1,0,0,0,417,73,1,0,0,0,418,419,5,12,0,0,419,420,3,
  	112,56,0,420,422,5,40,0,0,421,423,3,88,44,0,422,421,1,0,0,0,422,423,1,
  	0,0,0,423,424,1,0,0,0,424,425,5,41,0,0,425,75,1,0,0,0,426,430,3,72,36,
  	0,427,429,3,78,39,0,428,427,1,0,0,0,429,432,1,0,0,0,430,428,1,0,0,0,430,
  	431,1,0,0,0,431,77,1,0,0,0,432,430,1,0,0,0,433,434,5,48,0,0,434,445,5,
  	51,0,0,435,436,5,42,0,0,436,437,3,84,42,0,437,438,5,43,0,0,438,445,1,
  	0,0,0,439,441,5,40,0,0,440,442,3,88,44,0,441,440,1,0,0,0,441,442,1,0,
  	0,0,442,443,1,0,0,0,443,445,5,41,0,0,444,433,1,0,0,0,444,435,1,0,0,0,
  	444,439,1,0,0,0,445,79,1,0,0,0,446,447,3,76,38,0,447,448,5,48,0,0,448,
  	449,5,51,0,0,449,81,1,0,0,0,450,451,3,76,38,0,451,452,5,42,0,0,452,453,
  	3,84,42,0,453,454,5,43,0,0,454,83,1,0,0,0,455,457,3,54,27,0,456,455,1,
  	0,0,0,456,457,1,0,0,0,457,468,1,0,0,0,458,460,5,47,0,0,459,461,3,54,27,
  	0,460,459,1,0,0,0,460,461,1,0,0,0,461,466,1,0,0,0,462,464,5,47,0,0,463,
  	465,3,54,27,0,464,463,1,0,0,0,464,465,1,0,0,0,465,467,1,0,0,0,466,462,
  	1,0,0,0,466,467,1,0,0,0,467,469,1,0,0,0,468,458,1,0,0,0,468,469,1,0,0,
  	0,469,85,1,0,0,0,470,471,3,76,38,0,471,473,5,40,0,0,472,474,3,88,44,0,
  	473,472,1,0,0,0,473,474,1,0,0,0,474,475,1,0,0,0,475,476,5,41,0,0,476,
  	87,1,0,0,0,477,482,3,90,45,0,478,479,5,46,0,0,479,481,3,90,45,0,480,478,
  	1,0,0,0,481,484,1,0,0,0,482,480,1,0,0,0,482,483,1,0,0,0,483,486,1,0,0,
  	0,484,482,1,0,0,0,485,487,5,46,0,0,486,485,1,0,0,0,486,487,1,0,0,0,487,
  	89,1,0,0,0,488,489,5,51,0,0,489,490,5,38,0,0,490,497,3,54,27,0,491,497,
  	3,54,27,0,492,493,5,29,0,0,493,497,3,54,27,0,494,495,5,49,0,0,495,497,
  	3,54,27,0,496,488,1,0,0,0,496,491,1,0,0,0,496,492,1,0,0,0,496,494,1,0,
  	0,0,497,91,1,0,0,0,498,500,5,42,0,0,499,501,3,94,47,0,500,499,1,0,0,0,
  	500,501,1,0,0,0,501,502,1,0,0,0,502,503,5,43,0,0,503,93,1,0,0,0,504,509,
  	3,54,27,0,505,506,5,46,0,0,506,508,3,54,27,0,507,505,1,0,0,0,508,511,
  	1,0,0,0,509,507,1,0,0,0,509,510,1,0,0,0,510,513,1,0,0,0,511,509,1,0,0,
  	0,512,514,5,46,0,0,513,512,1,0,0,0,513,514,1,0,0,0,514,525,1,0,0,0,515,
  	516,3,54,27,0,516,517,5,4,0,0,517,518,5,51,0,0,518,519,5,10,0,0,519,522,
  	3,54,27,0,520,521,5,2,0,0,521,523,3,54,27,0,522,520,1,0,0,0,522,523,1,
  	0,0,0,523,525,1,0,0,0,524,504,1,0,0,0,524,515,1,0,0,0,525,95,1,0,0,0,
  	526,541,5,44,0,0,527,542,3,98,49,0,528,533,3,100,50,0,529,530,5,46,0,
  	0,530,532,3,100,50,0,531,529,1,0,0,0,532,535,1,0,0,0,533,531,1,0,0,0,
  	533,534,1,0,0,0,534,537,1,0,0,0,535,533,1,0,0,0,536,538,5,46,0,0,537,
  	536,1,0,0,0,537,538,1,0,0,0,538,540,1,0,0,0,539,528,1,0,0,0,539,540,1,
  	0,0,0,540,542,1,0,0,0,541,527,1,0,0,0,541,539,1,0,0,0,542,543,1,0,0,0,
  	543,544,5,45,0,0,544,97,1,0,0,0,545,546,3,54,27,0,546,547,5,47,0,0,547,
  	548,3,54,27,0,548,549,5,4,0,0,549,550,5,51,0,0,550,551,5,10,0,0,551,554,
  	3,54,27,0,552,553,5,2,0,0,553,555,3,54,27,0,554,552,1,0,0,0,554,555,1,
  	0,0,0,555,99,1,0,0,0,556,557,3,54,27,0,557,558,5,47,0,0,558,559,3,54,
  	27,0,559,563,1,0,0,0,560,561,5,49,0,0,561,563,3,54,27,0,562,556,1,0,0,
  	0,562,560,1,0,0,0,563,101,1,0,0,0,564,566,5,44,0,0,565,567,3,104,52,0,
  	566,565,1,0,0,0,566,567,1,0,0,0,567,568,1,0,0,0,568,569,5,45,0,0,569,
  	103,1,0,0,0,570,575,3,54,27,0,571,572,5,46,0,0,572,574,3,54,27,0,573,
  	571,1,0,0,0,574,577,1,0,0,0,575,573,1,0,0,0,575,576,1,0,0,0,576,579,1,
  	0,0,0,577,575,1,0,0,0,578,580,5,46,0,0,579,578,1,0,0,0,579,580,1,0,0,
  	0,580,591,1,0,0,0,581,582,3,54,27,0,582,583,5,4,0,0,583,584,5,51,0,0,
  	584,585,5,10,0,0,585,588,3,54,27,0,586,587,5,2,0,0,587,589,3,54,27,0,
  	588,586,1,0,0,0,588,589,1,0,0,0,589,591,1,0,0,0,590,570,1,0,0,0,590,581,
  	1,0,0,0,591,105,1,0,0,0,592,593,5,40,0,0,593,594,3,54,27,0,594,595,5,
  	4,0,0,595,596,5,51,0,0,596,597,5,10,0,0,597,600,3,54,27,0,598,599,5,2,
  	0,0,599,601,3,54,27,0,600,598,1,0,0,0,600,601,1,0,0,0,601,602,1,0,0,0,
  	602,603,5,41,0,0,603,107,1,0,0,0,604,605,7,5,0,0,605,109,1,0,0,0,606,
  	608,5,13,0,0,607,609,3,32,16,0,608,607,1,0,0,0,608,609,1,0,0,0,609,610,
  	1,0,0,0,610,611,5,47,0,0,611,612,3,54,27,0,612,111,1,0,0,0,613,618,5,
  	51,0,0,614,615,5,48,0,0,615,617,5,51,0,0,616,614,1,0,0,0,617,620,1,0,
  	0,0,618,616,1,0,0,0,618,619,1,0,0,0,619,113,1,0,0,0,620,618,1,0,0,0,72,
  	117,124,131,135,138,145,157,165,171,176,182,184,195,204,229,233,239,250,
  	254,259,263,267,281,287,305,311,321,324,329,334,348,356,364,372,380,388,
  	394,397,401,416,422,430,441,444,456,460,464,466,468,473,482,486,496,500,
  	509,513,522,524,533,537,539,541,554,562,566,575,579,588,590,600,608,618
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
    setState(117);
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
      | (1ULL << PyScriptParser::WITH)
      | (1ULL << PyScriptParser::ASYNC)
      | (1ULL << PyScriptParser::AWAIT)
      | (1ULL << PyScriptParser::CLASS)
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
      setState(114);
      statement();
      setState(119);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(120);
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
    setState(124);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::RETURN:
      case PyScriptParser::IMPORT:
      case PyScriptParser::FROM:
      case PyScriptParser::PASS:
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::AWAIT:
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
        setState(122);
        simpleStatement();
        break;
      }

      case PyScriptParser::DEF:
      case PyScriptParser::IF:
      case PyScriptParser::FOR:
      case PyScriptParser::WHILE:
      case PyScriptParser::TRY:
      case PyScriptParser::WITH:
      case PyScriptParser::ASYNC:
      case PyScriptParser::CLASS: {
        enterOuterAlt(_localctx, 2);
        setState(123);
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
    setState(126);
    smallStatement();
    setState(131);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(127);
        match(PyScriptParser::SEMI);
        setState(128);
        smallStatement(); 
      }
      setState(133);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::SEMI) {
      setState(134);
      match(PyScriptParser::SEMI);
    }
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::NEWLINE) {
      setState(137);
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
    setState(145);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(141);
      returnStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(142);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(143);
      importStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(144);
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

PyScriptParser::AsyncFunctionDefContext* PyScriptParser::CompoundStatementContext::asyncFunctionDef() {
  return getRuleContext<PyScriptParser::AsyncFunctionDefContext>(0);
}

PyScriptParser::ClassDefContext* PyScriptParser::CompoundStatementContext::classDef() {
  return getRuleContext<PyScriptParser::ClassDefContext>(0);
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

PyScriptParser::AsyncForStatementContext* PyScriptParser::CompoundStatementContext::asyncForStatement() {
  return getRuleContext<PyScriptParser::AsyncForStatementContext>(0);
}

PyScriptParser::TryStatementContext* PyScriptParser::CompoundStatementContext::tryStatement() {
  return getRuleContext<PyScriptParser::TryStatementContext>(0);
}

PyScriptParser::WithStatementContext* PyScriptParser::CompoundStatementContext::withStatement() {
  return getRuleContext<PyScriptParser::WithStatementContext>(0);
}

PyScriptParser::AsyncWithStatementContext* PyScriptParser::CompoundStatementContext::asyncWithStatement() {
  return getRuleContext<PyScriptParser::AsyncWithStatementContext>(0);
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
    setState(157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(147);
      functionDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(148);
      asyncFunctionDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(149);
      classDef();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(150);
      ifStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(151);
      whileStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(152);
      forStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(153);
      asyncForStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(154);
      tryStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(155);
      withStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(156);
      asyncWithStatement();
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
    setState(159);
    match(PyScriptParser::TRY);
    setState(160);
    match(PyScriptParser::COLON);
    setState(161);
    suite();
    setState(165);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::EXCEPT) {
      setState(162);
      exceptClause();
      setState(167);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(171);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(168);
      match(PyScriptParser::ELSE);
      setState(169);
      match(PyScriptParser::COLON);
      setState(170);
      suite();
    }
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::FINALLY) {
      setState(173);
      match(PyScriptParser::FINALLY);
      setState(174);
      match(PyScriptParser::COLON);
      setState(175);
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
    setState(178);
    match(PyScriptParser::EXCEPT);
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IDENTIFIER) {
      setState(179);
      dottedName();
      setState(182);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::AS) {
        setState(180);
        match(PyScriptParser::AS);
        setState(181);
        match(PyScriptParser::IDENTIFIER);
      }
    }
    setState(186);
    match(PyScriptParser::COLON);
    setState(187);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithStatementContext ------------------------------------------------------------------

PyScriptParser::WithStatementContext::WithStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::WithStatementContext::WITH() {
  return getToken(PyScriptParser::WITH, 0);
}

std::vector<PyScriptParser::WithItemContext *> PyScriptParser::WithStatementContext::withItem() {
  return getRuleContexts<PyScriptParser::WithItemContext>();
}

PyScriptParser::WithItemContext* PyScriptParser::WithStatementContext::withItem(size_t i) {
  return getRuleContext<PyScriptParser::WithItemContext>(i);
}

tree::TerminalNode* PyScriptParser::WithStatementContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

PyScriptParser::SuiteContext* PyScriptParser::WithStatementContext::suite() {
  return getRuleContext<PyScriptParser::SuiteContext>(0);
}

std::vector<tree::TerminalNode *> PyScriptParser::WithStatementContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::WithStatementContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::WithStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleWithStatement;
}

void PyScriptParser::WithStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithStatement(this);
}

void PyScriptParser::WithStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithStatement(this);
}


std::any PyScriptParser::WithStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitWithStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::WithStatementContext* PyScriptParser::withStatement() {
  WithStatementContext *_localctx = _tracker.createInstance<WithStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, PyScriptParser::RuleWithStatement);
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
    setState(189);
    match(PyScriptParser::WITH);
    setState(190);
    withItem();
    setState(195);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(191);
      match(PyScriptParser::COMMA);
      setState(192);
      withItem();
      setState(197);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(198);
    match(PyScriptParser::COLON);
    setState(199);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithItemContext ------------------------------------------------------------------

PyScriptParser::WithItemContext::WithItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::ExpressionContext* PyScriptParser::WithItemContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::WithItemContext::AS() {
  return getToken(PyScriptParser::AS, 0);
}

tree::TerminalNode* PyScriptParser::WithItemContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}


size_t PyScriptParser::WithItemContext::getRuleIndex() const {
  return PyScriptParser::RuleWithItem;
}

void PyScriptParser::WithItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithItem(this);
}

void PyScriptParser::WithItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithItem(this);
}


std::any PyScriptParser::WithItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitWithItem(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::WithItemContext* PyScriptParser::withItem() {
  WithItemContext *_localctx = _tracker.createInstance<WithItemContext>(_ctx, getState());
  enterRule(_localctx, 16, PyScriptParser::RuleWithItem);
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
    setState(201);
    expression();
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(202);
      match(PyScriptParser::AS);
      setState(203);
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

//----------------- AsyncFunctionDefContext ------------------------------------------------------------------

PyScriptParser::AsyncFunctionDefContext::AsyncFunctionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::AsyncFunctionDefContext::ASYNC() {
  return getToken(PyScriptParser::ASYNC, 0);
}

PyScriptParser::FunctionDefContext* PyScriptParser::AsyncFunctionDefContext::functionDef() {
  return getRuleContext<PyScriptParser::FunctionDefContext>(0);
}


size_t PyScriptParser::AsyncFunctionDefContext::getRuleIndex() const {
  return PyScriptParser::RuleAsyncFunctionDef;
}

void PyScriptParser::AsyncFunctionDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsyncFunctionDef(this);
}

void PyScriptParser::AsyncFunctionDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsyncFunctionDef(this);
}


std::any PyScriptParser::AsyncFunctionDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAsyncFunctionDef(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AsyncFunctionDefContext* PyScriptParser::asyncFunctionDef() {
  AsyncFunctionDefContext *_localctx = _tracker.createInstance<AsyncFunctionDefContext>(_ctx, getState());
  enterRule(_localctx, 18, PyScriptParser::RuleAsyncFunctionDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(PyScriptParser::ASYNC);
    setState(207);
    functionDef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsyncForStatementContext ------------------------------------------------------------------

PyScriptParser::AsyncForStatementContext::AsyncForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::AsyncForStatementContext::ASYNC() {
  return getToken(PyScriptParser::ASYNC, 0);
}

PyScriptParser::ForStatementContext* PyScriptParser::AsyncForStatementContext::forStatement() {
  return getRuleContext<PyScriptParser::ForStatementContext>(0);
}


size_t PyScriptParser::AsyncForStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleAsyncForStatement;
}

void PyScriptParser::AsyncForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsyncForStatement(this);
}

void PyScriptParser::AsyncForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsyncForStatement(this);
}


std::any PyScriptParser::AsyncForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAsyncForStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AsyncForStatementContext* PyScriptParser::asyncForStatement() {
  AsyncForStatementContext *_localctx = _tracker.createInstance<AsyncForStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, PyScriptParser::RuleAsyncForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(PyScriptParser::ASYNC);
    setState(210);
    forStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsyncWithStatementContext ------------------------------------------------------------------

PyScriptParser::AsyncWithStatementContext::AsyncWithStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::AsyncWithStatementContext::ASYNC() {
  return getToken(PyScriptParser::ASYNC, 0);
}

PyScriptParser::WithStatementContext* PyScriptParser::AsyncWithStatementContext::withStatement() {
  return getRuleContext<PyScriptParser::WithStatementContext>(0);
}


size_t PyScriptParser::AsyncWithStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleAsyncWithStatement;
}

void PyScriptParser::AsyncWithStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsyncWithStatement(this);
}

void PyScriptParser::AsyncWithStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsyncWithStatement(this);
}


std::any PyScriptParser::AsyncWithStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAsyncWithStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AsyncWithStatementContext* PyScriptParser::asyncWithStatement() {
  AsyncWithStatementContext *_localctx = _tracker.createInstance<AsyncWithStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, PyScriptParser::RuleAsyncWithStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(PyScriptParser::ASYNC);
    setState(213);
    withStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AwaitExprContext ------------------------------------------------------------------

PyScriptParser::AwaitExprContext::AwaitExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::AwaitExprContext::AWAIT() {
  return getToken(PyScriptParser::AWAIT, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::AwaitExprContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}


size_t PyScriptParser::AwaitExprContext::getRuleIndex() const {
  return PyScriptParser::RuleAwaitExpr;
}

void PyScriptParser::AwaitExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAwaitExpr(this);
}

void PyScriptParser::AwaitExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAwaitExpr(this);
}


std::any PyScriptParser::AwaitExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAwaitExpr(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AwaitExprContext* PyScriptParser::awaitExpr() {
  AwaitExprContext *_localctx = _tracker.createInstance<AwaitExprContext>(_ctx, getState());
  enterRule(_localctx, 24, PyScriptParser::RuleAwaitExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(PyScriptParser::AWAIT);
    setState(216);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefContext ------------------------------------------------------------------

PyScriptParser::ClassDefContext::ClassDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::ClassDefContext::CLASS() {
  return getToken(PyScriptParser::CLASS, 0);
}

tree::TerminalNode* PyScriptParser::ClassDefContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* PyScriptParser::ClassDefContext::COLON() {
  return getToken(PyScriptParser::COLON, 0);
}

PyScriptParser::SuiteContext* PyScriptParser::ClassDefContext::suite() {
  return getRuleContext<PyScriptParser::SuiteContext>(0);
}


size_t PyScriptParser::ClassDefContext::getRuleIndex() const {
  return PyScriptParser::RuleClassDef;
}

void PyScriptParser::ClassDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDef(this);
}

void PyScriptParser::ClassDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDef(this);
}


std::any PyScriptParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ClassDefContext* PyScriptParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 26, PyScriptParser::RuleClassDef);

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
    match(PyScriptParser::CLASS);
    setState(219);
    match(PyScriptParser::IDENTIFIER);
    setState(220);
    match(PyScriptParser::COLON);
    setState(221);
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
  enterRule(_localctx, 28, PyScriptParser::RuleSuite);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(233);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::RETURN:
      case PyScriptParser::IMPORT:
      case PyScriptParser::FROM:
      case PyScriptParser::PASS:
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::AWAIT:
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
        setState(223);
        simpleStatement();
        break;
      }

      case PyScriptParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(224);
        match(PyScriptParser::NEWLINE);
        setState(225);
        match(PyScriptParser::INDENT);
        setState(227); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(226);
          statement();
          setState(229); 
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
          | (1ULL << PyScriptParser::WITH)
          | (1ULL << PyScriptParser::ASYNC)
          | (1ULL << PyScriptParser::AWAIT)
          | (1ULL << PyScriptParser::CLASS)
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
        setState(231);
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
  enterRule(_localctx, 30, PyScriptParser::RuleFunctionDef);
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
    setState(235);
    match(PyScriptParser::DEF);
    setState(236);
    match(PyScriptParser::IDENTIFIER);
    setState(237);
    match(PyScriptParser::LPAREN);
    setState(239);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::IDENTIFIER))) != 0)) {
      setState(238);
      parameterList();
    }
    setState(241);
    match(PyScriptParser::RPAREN);
    setState(242);
    match(PyScriptParser::COLON);
    setState(243);
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
  enterRule(_localctx, 32, PyScriptParser::RuleParameterList);
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
    setState(245);
    parameter();
    setState(250);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(246);
        match(PyScriptParser::COMMA);
        setState(247);
        parameter(); 
      }
      setState(252);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(254);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(253);
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
  enterRule(_localctx, 34, PyScriptParser::RuleParameter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(267);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(256);
        match(PyScriptParser::IDENTIFIER);
        setState(259);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::ASSIGN) {
          setState(257);
          match(PyScriptParser::ASSIGN);
          setState(258);
          expression();
        }
        break;
      }

      case PyScriptParser::MUL: {
        enterOuterAlt(_localctx, 2);
        setState(261);
        match(PyScriptParser::MUL);
        setState(263);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::IDENTIFIER) {
          setState(262);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 3);
        setState(265);
        match(PyScriptParser::DOUBLE_STAR);
        setState(266);
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
  enterRule(_localctx, 36, PyScriptParser::RuleIfStatement);
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
    setState(269);
    match(PyScriptParser::IF);
    setState(270);
    expression();
    setState(271);
    match(PyScriptParser::COLON);
    setState(272);
    suite();
    setState(281);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(273);
        match(PyScriptParser::ELSE);
        setState(274);
        match(PyScriptParser::IF);
        setState(275);
        expression();
        setState(276);
        match(PyScriptParser::COLON);
        setState(277);
        suite(); 
      }
      setState(283);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(287);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(284);
      match(PyScriptParser::ELSE);
      setState(285);
      match(PyScriptParser::COLON);
      setState(286);
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
  enterRule(_localctx, 38, PyScriptParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(PyScriptParser::WHILE);
    setState(290);
    expression();
    setState(291);
    match(PyScriptParser::COLON);
    setState(292);
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
  enterRule(_localctx, 40, PyScriptParser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    match(PyScriptParser::FOR);
    setState(295);
    match(PyScriptParser::IDENTIFIER);
    setState(296);
    match(PyScriptParser::IN);
    setState(297);
    expression();
    setState(298);
    match(PyScriptParser::COLON);
    setState(299);
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
  enterRule(_localctx, 42, PyScriptParser::RulePassStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
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
  enterRule(_localctx, 44, PyScriptParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(PyScriptParser::RETURN);
    setState(305);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(304);
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
  enterRule(_localctx, 46, PyScriptParser::RuleImportStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(324);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IMPORT: {
        _localctx = _tracker.createInstance<PyScriptParser::SimpleImportContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(307);
        match(PyScriptParser::IMPORT);
        setState(308);
        dottedName();
        setState(311);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::AS) {
          setState(309);
          match(PyScriptParser::AS);
          setState(310);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::FROM: {
        _localctx = _tracker.createInstance<PyScriptParser::FromImportContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(313);
        match(PyScriptParser::FROM);
        setState(314);
        dottedName();
        setState(315);
        match(PyScriptParser::IMPORT);
        setState(316);
        importItem();
        setState(321);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PyScriptParser::COMMA) {
          setState(317);
          match(PyScriptParser::COMMA);
          setState(318);
          importItem();
          setState(323);
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
  enterRule(_localctx, 48, PyScriptParser::RuleImportItem);
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
    setState(326);
    match(PyScriptParser::IDENTIFIER);
    setState(329);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(327);
      match(PyScriptParser::AS);
      setState(328);
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
  enterRule(_localctx, 50, PyScriptParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(334);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(331);
      match(PyScriptParser::IDENTIFIER);
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

    default:
      break;
    }
    setState(336);
    match(PyScriptParser::ASSIGN);
    setState(337);
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
  enterRule(_localctx, 52, PyScriptParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
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
  enterRule(_localctx, 54, PyScriptParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
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
  enterRule(_localctx, 56, PyScriptParser::RuleLogicalOr);

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
    setState(343);
    logicalAnd();
    setState(348);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(344);
        match(PyScriptParser::OR);
        setState(345);
        logicalAnd(); 
      }
      setState(350);
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
  enterRule(_localctx, 58, PyScriptParser::RuleLogicalAnd);

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
    setState(351);
    equality();
    setState(356);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(352);
        match(PyScriptParser::AND);
        setState(353);
        equality(); 
      }
      setState(358);
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
  enterRule(_localctx, 60, PyScriptParser::RuleEquality);
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
    setState(359);
    comparison();
    setState(364);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(360);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::EQ

        || _la == PyScriptParser::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(361);
        comparison(); 
      }
      setState(366);
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
  enterRule(_localctx, 62, PyScriptParser::RuleComparison);
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
    setState(367);
    additive();
    setState(372);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(368);
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
        setState(369);
        additive(); 
      }
      setState(374);
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
  enterRule(_localctx, 64, PyScriptParser::RuleAdditive);
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
    setState(375);
    multiplicative();
    setState(380);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(376);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::PLUS

        || _la == PyScriptParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(377);
        multiplicative(); 
      }
      setState(382);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
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
  enterRule(_localctx, 66, PyScriptParser::RuleMultiplicative);
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
    setState(383);
    power();
    setState(388);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(384);
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
        setState(385);
        power(); 
      }
      setState(390);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
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
  enterRule(_localctx, 68, PyScriptParser::RulePower);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    unary();
    setState(394);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(392);
      match(PyScriptParser::DOUBLE_STAR);
      setState(393);
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

PyScriptParser::AwaitExprContext* PyScriptParser::UnaryContext::awaitExpr() {
  return getRuleContext<PyScriptParser::AwaitExprContext>(0);
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
  enterRule(_localctx, 70, PyScriptParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(401);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(397);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS))) != 0)) {
        setState(396);
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
      setState(399);
      atom();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(400);
      awaitExpr();
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

PyScriptParser::AwaitExprContext* PyScriptParser::PrimaryContext::awaitExpr() {
  return getRuleContext<PyScriptParser::AwaitExprContext>(0);
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
  enterRule(_localctx, 72, PyScriptParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(416);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(403);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(404);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(405);
      match(PyScriptParser::LPAREN);
      setState(406);
      expression();
      setState(407);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(409);
      listLiteral();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(410);
      dictLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(411);
      setLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(412);
      generatorExpression();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(413);
      newExpression();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(414);
      lambdaExpression();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(415);
      awaitExpr();
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
  enterRule(_localctx, 74, PyScriptParser::RuleNewExpression);
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
    setState(418);
    match(PyScriptParser::NEW);
    setState(419);
    dottedName();
    setState(420);
    match(PyScriptParser::LPAREN);
    setState(422);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::AWAIT)
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
      setState(421);
      argumentList();
    }
    setState(424);
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
  enterRule(_localctx, 76, PyScriptParser::RuleAtom);

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
    setState(426);
    primary();
    setState(430);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(427);
        postfixOp(); 
      }
      setState(432);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
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
  enterRule(_localctx, 78, PyScriptParser::RulePostfixOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(444);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DOT: {
        _localctx = _tracker.createInstance<PyScriptParser::AttributeAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(433);
        match(PyScriptParser::DOT);
        setState(434);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::LBRACK: {
        _localctx = _tracker.createInstance<PyScriptParser::SubscriptAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(435);
        match(PyScriptParser::LBRACK);
        setState(436);
        subscriptArg();
        setState(437);
        match(PyScriptParser::RBRACK);
        break;
      }

      case PyScriptParser::LPAREN: {
        _localctx = _tracker.createInstance<PyScriptParser::FunctionCallOpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(439);
        match(PyScriptParser::LPAREN);
        setState(441);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::AWAIT)
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
          setState(440);
          argumentList();
        }
        setState(443);
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
  enterRule(_localctx, 80, PyScriptParser::RuleAttributeAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    atom();
    setState(447);
    match(PyScriptParser::DOT);
    setState(448);
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
  enterRule(_localctx, 82, PyScriptParser::RuleSubscriptAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(450);
    atom();
    setState(451);
    match(PyScriptParser::LBRACK);
    setState(452);
    subscriptArg();
    setState(453);
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
  enterRule(_localctx, 84, PyScriptParser::RuleSubscriptArg);
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
    setState(456);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::AWAIT)
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
      setState(455);
      expression();
    }
    setState(468);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COLON) {
      setState(458);
      match(PyScriptParser::COLON);
      setState(460);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
        | (1ULL << PyScriptParser::LAMBDA)
        | (1ULL << PyScriptParser::AWAIT)
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
        setState(459);
        expression();
      }
      setState(466);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COLON) {
        setState(462);
        match(PyScriptParser::COLON);
        setState(464);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::AWAIT)
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
          setState(463);
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
  enterRule(_localctx, 86, PyScriptParser::RuleFunctionCall);
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
    setState(470);
    atom();
    setState(471);
    match(PyScriptParser::LPAREN);
    setState(473);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::AWAIT)
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
      setState(472);
      argumentList();
    }
    setState(475);
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
  enterRule(_localctx, 88, PyScriptParser::RuleArgumentList);
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
    setState(477);
    argument();
    setState(482);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(478);
        match(PyScriptParser::COMMA);
        setState(479);
        argument(); 
      }
      setState(484);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    }
    setState(486);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(485);
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
  enterRule(_localctx, 90, PyScriptParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(496);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(488);
      match(PyScriptParser::IDENTIFIER);
      setState(489);
      match(PyScriptParser::ASSIGN);
      setState(490);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(491);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(492);
      match(PyScriptParser::MUL);
      setState(493);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(494);
      match(PyScriptParser::DOUBLE_STAR);
      setState(495);
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
  enterRule(_localctx, 92, PyScriptParser::RuleListLiteral);
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
    setState(498);
    match(PyScriptParser::LBRACK);
    setState(500);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::AWAIT)
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
      setState(499);
      listElements();
    }
    setState(502);
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

tree::TerminalNode* PyScriptParser::ListElementsContext::IF() {
  return getToken(PyScriptParser::IF, 0);
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
  enterRule(_localctx, 94, PyScriptParser::RuleListElements);
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
    setState(524);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(504);
      expression();
      setState(509);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(505);
          match(PyScriptParser::COMMA);
          setState(506);
          expression(); 
        }
        setState(511);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
      }
      setState(513);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(512);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(515);
      expression();
      setState(516);
      match(PyScriptParser::FOR);
      setState(517);
      match(PyScriptParser::IDENTIFIER);
      setState(518);
      match(PyScriptParser::IN);
      setState(519);
      expression();
      setState(522);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::IF) {
        setState(520);
        match(PyScriptParser::IF);
        setState(521);
        expression();
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
  enterRule(_localctx, 96, PyScriptParser::RuleDictLiteral);
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
    setState(526);
    match(PyScriptParser::LBRACE);
    setState(541);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      setState(527);
      dictComprehension();
      break;
    }

    case 2: {
      setState(539);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
        | (1ULL << PyScriptParser::LAMBDA)
        | (1ULL << PyScriptParser::AWAIT)
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
        setState(528);
        dictItem();
        setState(533);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(529);
            match(PyScriptParser::COMMA);
            setState(530);
            dictItem(); 
          }
          setState(535);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
        }
        setState(537);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::COMMA) {
          setState(536);
          match(PyScriptParser::COMMA);
        }
      }
      break;
    }

    default:
      break;
    }
    setState(543);
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

tree::TerminalNode* PyScriptParser::DictComprehensionContext::IF() {
  return getToken(PyScriptParser::IF, 0);
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
  enterRule(_localctx, 98, PyScriptParser::RuleDictComprehension);
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
    setState(545);
    expression();
    setState(546);
    match(PyScriptParser::COLON);
    setState(547);
    expression();
    setState(548);
    match(PyScriptParser::FOR);
    setState(549);
    match(PyScriptParser::IDENTIFIER);
    setState(550);
    match(PyScriptParser::IN);
    setState(551);
    expression();
    setState(554);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IF) {
      setState(552);
      match(PyScriptParser::IF);
      setState(553);
      expression();
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
  enterRule(_localctx, 100, PyScriptParser::RuleDictItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(562);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::AWAIT:
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
        setState(556);
        expression();
        setState(557);
        match(PyScriptParser::COLON);
        setState(558);
        expression();
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 2);
        setState(560);
        match(PyScriptParser::DOUBLE_STAR);
        setState(561);
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
  enterRule(_localctx, 102, PyScriptParser::RuleSetLiteral);
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
    setState(564);
    match(PyScriptParser::LBRACE);
    setState(566);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::AWAIT)
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
      setState(565);
      setElements();
    }
    setState(568);
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

tree::TerminalNode* PyScriptParser::SetElementsContext::IF() {
  return getToken(PyScriptParser::IF, 0);
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
  enterRule(_localctx, 104, PyScriptParser::RuleSetElements);
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
    setState(590);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(570);
      expression();
      setState(575);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(571);
          match(PyScriptParser::COMMA);
          setState(572);
          expression(); 
        }
        setState(577);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      }
      setState(579);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(578);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(581);
      expression();
      setState(582);
      match(PyScriptParser::FOR);
      setState(583);
      match(PyScriptParser::IDENTIFIER);
      setState(584);
      match(PyScriptParser::IN);
      setState(585);
      expression();
      setState(588);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::IF) {
        setState(586);
        match(PyScriptParser::IF);
        setState(587);
        expression();
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

tree::TerminalNode* PyScriptParser::GeneratorExpressionContext::IF() {
  return getToken(PyScriptParser::IF, 0);
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
  enterRule(_localctx, 106, PyScriptParser::RuleGeneratorExpression);
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
    setState(592);
    match(PyScriptParser::LPAREN);
    setState(593);
    expression();
    setState(594);
    match(PyScriptParser::FOR);
    setState(595);
    match(PyScriptParser::IDENTIFIER);
    setState(596);
    match(PyScriptParser::IN);
    setState(597);
    expression();
    setState(600);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IF) {
      setState(598);
      match(PyScriptParser::IF);
      setState(599);
      expression();
    }
    setState(602);
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
  enterRule(_localctx, 108, PyScriptParser::RuleLiteral);
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
    setState(604);
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
  enterRule(_localctx, 110, PyScriptParser::RuleLambdaExpression);
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
    setState(606);
    match(PyScriptParser::LAMBDA);
    setState(608);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::DOUBLE_STAR)
      | (1ULL << PyScriptParser::IDENTIFIER))) != 0)) {
      setState(607);
      parameterList();
    }
    setState(610);
    match(PyScriptParser::COLON);
    setState(611);
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
  enterRule(_localctx, 112, PyScriptParser::RuleDottedName);
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
    setState(613);
    match(PyScriptParser::IDENTIFIER);
    setState(618);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::DOT) {
      setState(614);
      match(PyScriptParser::DOT);
      setState(615);
      match(PyScriptParser::IDENTIFIER);
      setState(620);
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
