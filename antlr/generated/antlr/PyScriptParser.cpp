
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
      "decoratedDef", "decorators", "decorator", "suite", "functionDef", 
      "parameterList", "parameter", "ifStatement", "whileStatement", "forStatement", 
      "passStatement", "returnStatement", "importStatement", "importItem", 
      "assignment", "assignmentTarget", "expressionStatement", "expression", 
      "conditionalExpression", "logicalOr", "logicalAnd", "bitwiseOr", "bitwiseXor", 
      "bitwiseAnd", "equality", "comparison", "shift", "additive", "multiplicative", 
      "power", "unary", "primary", "tupleLiteral", "newExpression", "atom", 
      "postfixOp", "subscriptArg", "argumentList", "argument", "listLiteral", 
      "listElements", "comprehension", "compFor", "dictLiteral", "dictComprehension", 
      "dictItem", "setLiteral", "setElements", "generatorExpression", "literal", 
      "lambdaExpression", "dottedName"
    },
    std::vector<std::string>{
      "", "'def'", "'if'", "'else'", "'elif'", "'for'", "'while'", "'return'", 
      "'import'", "'from'", "'as'", "'in'", "'pass'", "'break'", "'continue'", 
      "'new'", "'lambda'", "'try'", "'except'", "'finally'", "'with'", "'async'", 
      "'await'", "'class'", "'@'", "'true'", "'false'", "'none'", "'and'", 
      "'or'", "'not'", "'is'", "'is not'", "'not in'", "'+'", "'-'", "'*'", 
      "'/'", "'//'", "'%'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", 
      "'<<'", "'>>'", "'&'", "'|'", "'^'", "'~'", "'='", "'+='", "'-='", 
      "'*='", "'/='", "'//='", "'%='", "'**='", "'&='", "'|='", "'^='", 
      "'<<='", "'>>='", "';'", "'('", "')'", "'['", "']'", "'{'", "'}'", 
      "','", "':'", "'.'", "'**'"
    },
    std::vector<std::string>{
      "", "DEF", "IF", "ELSE", "ELIF", "FOR", "WHILE", "RETURN", "IMPORT", 
      "FROM", "AS", "IN", "PASS", "BREAK", "CONTINUE", "NEW", "LAMBDA", 
      "TRY", "EXCEPT", "FINALLY", "WITH", "ASYNC", "AWAIT", "CLASS", "AT", 
      "TRUE", "FALSE", "NONE", "AND", "OR", "NOT", "IS", "IS_NOT", "NOT_IN", 
      "PLUS", "MINUS", "MUL", "DIV", "FLOOR_DIV", "MOD", "EQ", "NE", "LT", 
      "LE", "GT", "GE", "LEFT_SHIFT", "RIGHT_SHIFT", "BITWISE_AND", "BITWISE_OR", 
      "BITWISE_XOR", "BITWISE_NOT", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", 
      "MUL_ASSIGN", "DIV_ASSIGN", "FLOOR_DIV_ASSIGN", "MOD_ASSIGN", "POW_ASSIGN", 
      "BITWISE_AND_ASSIGN", "BITWISE_OR_ASSIGN", "BITWISE_XOR_ASSIGN", "LEFT_SHIFT_ASSIGN", 
      "RIGHT_SHIFT_ASSIGN", "SEMI", "LPAREN", "RPAREN", "LBRACK", "RBRACK", 
      "LBRACE", "RBRACE", "COMMA", "COLON", "DOT", "DOUBLE_STAR", "NEWLINE", 
      "IDENTIFIER", "INTEGER", "FLOAT", "STRING", "WS", "COMMENT", "INDENT", 
      "DEDENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,84,722,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,2,65,7,65,1,0,5,0,134,8,0,10,0,12,0,137,9,0,1,0,1,0,1,1,
  	1,1,3,1,143,8,1,1,2,1,2,1,2,5,2,148,8,2,10,2,12,2,151,9,2,1,2,3,2,154,
  	8,2,1,2,3,2,157,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,166,8,3,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,179,8,4,1,5,1,5,1,5,1,5,5,5,185,
  	8,5,10,5,12,5,188,9,5,1,5,1,5,1,5,3,5,193,8,5,1,5,1,5,1,5,3,5,198,8,5,
  	1,6,1,6,1,6,1,6,3,6,204,8,6,3,6,206,8,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,5,
  	7,215,8,7,10,7,12,7,218,9,7,1,7,1,7,1,7,1,8,1,8,1,8,3,8,226,8,8,1,9,1,
  	9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,5,13,246,8,13,10,13,12,13,249,9,13,1,13,3,13,252,8,13,1,13,
  	1,13,3,13,256,8,13,1,13,3,13,259,8,13,1,13,1,13,1,13,1,14,1,14,1,14,3,
  	14,267,8,14,1,15,4,15,270,8,15,11,15,12,15,271,1,16,1,16,1,16,1,16,1,
  	17,1,17,1,17,1,17,4,17,282,8,17,11,17,12,17,283,1,17,1,17,3,17,288,8,
  	17,1,18,1,18,1,18,1,18,3,18,294,8,18,1,18,1,18,1,18,1,18,1,19,1,19,1,
  	19,5,19,303,8,19,10,19,12,19,306,9,19,1,19,3,19,309,8,19,1,20,1,20,1,
  	20,3,20,314,8,20,1,20,1,20,3,20,318,8,20,1,20,1,20,3,20,322,8,20,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,5,21,333,8,21,10,21,12,21,336,
  	9,21,1,21,1,21,1,21,3,21,341,8,21,1,22,1,22,1,22,1,22,1,22,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,25,1,25,3,25,359,8,25,1,26,1,26,
  	1,26,1,26,3,26,365,8,26,1,26,1,26,1,26,1,26,1,26,1,26,5,26,373,8,26,10,
  	26,12,26,376,9,26,3,26,378,8,26,1,27,1,27,1,27,3,27,383,8,27,1,28,1,28,
  	1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,399,
  	8,29,1,30,1,30,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,3,32,411,8,32,
  	1,33,1,33,1,33,5,33,416,8,33,10,33,12,33,419,9,33,1,34,1,34,1,34,5,34,
  	424,8,34,10,34,12,34,427,9,34,1,35,1,35,1,35,5,35,432,8,35,10,35,12,35,
  	435,9,35,1,36,1,36,1,36,5,36,440,8,36,10,36,12,36,443,9,36,1,37,1,37,
  	1,37,5,37,448,8,37,10,37,12,37,451,9,37,1,38,1,38,1,38,5,38,456,8,38,
  	10,38,12,38,459,9,38,1,39,1,39,1,39,5,39,464,8,39,10,39,12,39,467,9,39,
  	1,40,1,40,1,40,5,40,472,8,40,10,40,12,40,475,9,40,1,41,1,41,1,41,5,41,
  	480,8,41,10,41,12,41,483,9,41,1,42,1,42,1,42,5,42,488,8,42,10,42,12,42,
  	491,9,42,1,43,1,43,1,43,3,43,496,8,43,1,44,3,44,499,8,44,1,44,1,44,3,
  	44,503,8,44,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,3,45,522,8,45,1,46,1,46,1,46,1,46,1,46,5,
  	46,529,8,46,10,46,12,46,532,9,46,1,46,3,46,535,8,46,1,46,3,46,538,8,46,
  	1,46,1,46,1,46,3,46,543,8,46,1,47,1,47,1,47,1,47,3,47,549,8,47,1,47,1,
  	47,1,48,1,48,5,48,555,8,48,10,48,12,48,558,9,48,1,49,1,49,1,49,1,49,1,
  	49,1,49,1,49,1,49,3,49,568,8,49,1,49,3,49,571,8,49,1,50,3,50,574,8,50,
  	1,50,1,50,3,50,578,8,50,1,50,1,50,3,50,582,8,50,3,50,584,8,50,3,50,586,
  	8,50,1,51,1,51,1,51,5,51,591,8,51,10,51,12,51,594,9,51,1,51,3,51,597,
  	8,51,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,3,52,607,8,52,1,53,1,53,
  	3,53,611,8,53,1,53,1,53,1,54,1,54,1,54,5,54,618,8,54,10,54,12,54,621,
  	9,54,1,54,3,54,624,8,54,1,54,3,54,627,8,54,1,55,1,55,4,55,631,8,55,11,
  	55,12,55,632,1,56,1,56,1,56,3,56,638,8,56,1,56,1,56,1,56,1,56,3,56,644,
  	8,56,1,57,1,57,1,57,1,57,1,57,5,57,651,8,57,10,57,12,57,654,9,57,1,57,
  	3,57,657,8,57,3,57,659,8,57,3,57,661,8,57,1,57,1,57,1,58,1,58,1,58,1,
  	58,4,58,669,8,58,11,58,12,58,670,1,59,1,59,1,59,1,59,1,59,1,59,3,59,679,
  	8,59,1,60,1,60,3,60,683,8,60,1,60,1,60,1,61,1,61,1,61,5,61,690,8,61,10,
  	61,12,61,693,9,61,1,61,3,61,696,8,61,1,61,3,61,699,8,61,1,62,1,62,1,62,
  	1,62,1,63,1,63,1,64,1,64,3,64,709,8,64,1,64,1,64,1,64,1,65,1,65,1,65,
  	5,65,717,8,65,10,65,12,65,720,9,65,1,65,0,0,66,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,
  	64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,
  	108,110,112,114,116,118,120,122,124,126,128,130,0,8,1,0,52,64,1,0,40,
  	41,3,0,11,11,31,33,42,45,1,0,46,47,1,0,34,35,1,0,36,39,3,0,30,30,34,35,
  	51,51,2,0,25,27,78,80,769,0,135,1,0,0,0,2,142,1,0,0,0,4,144,1,0,0,0,6,
  	165,1,0,0,0,8,178,1,0,0,0,10,180,1,0,0,0,12,199,1,0,0,0,14,210,1,0,0,
  	0,16,222,1,0,0,0,18,227,1,0,0,0,20,230,1,0,0,0,22,233,1,0,0,0,24,236,
  	1,0,0,0,26,239,1,0,0,0,28,263,1,0,0,0,30,269,1,0,0,0,32,273,1,0,0,0,34,
  	287,1,0,0,0,36,289,1,0,0,0,38,299,1,0,0,0,40,321,1,0,0,0,42,323,1,0,0,
  	0,44,342,1,0,0,0,46,347,1,0,0,0,48,354,1,0,0,0,50,356,1,0,0,0,52,377,
  	1,0,0,0,54,379,1,0,0,0,56,384,1,0,0,0,58,398,1,0,0,0,60,400,1,0,0,0,62,
  	402,1,0,0,0,64,404,1,0,0,0,66,412,1,0,0,0,68,420,1,0,0,0,70,428,1,0,0,
  	0,72,436,1,0,0,0,74,444,1,0,0,0,76,452,1,0,0,0,78,460,1,0,0,0,80,468,
  	1,0,0,0,82,476,1,0,0,0,84,484,1,0,0,0,86,492,1,0,0,0,88,502,1,0,0,0,90,
  	521,1,0,0,0,92,542,1,0,0,0,94,544,1,0,0,0,96,552,1,0,0,0,98,570,1,0,0,
  	0,100,573,1,0,0,0,102,587,1,0,0,0,104,606,1,0,0,0,106,608,1,0,0,0,108,
  	626,1,0,0,0,110,628,1,0,0,0,112,634,1,0,0,0,114,645,1,0,0,0,116,664,1,
  	0,0,0,118,678,1,0,0,0,120,680,1,0,0,0,122,698,1,0,0,0,124,700,1,0,0,0,
  	126,704,1,0,0,0,128,706,1,0,0,0,130,713,1,0,0,0,132,134,3,2,1,0,133,132,
  	1,0,0,0,134,137,1,0,0,0,135,133,1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,
  	0,137,135,1,0,0,0,138,139,5,0,0,1,139,1,1,0,0,0,140,143,3,4,2,0,141,143,
  	3,8,4,0,142,140,1,0,0,0,142,141,1,0,0,0,143,3,1,0,0,0,144,149,3,6,3,0,
  	145,146,5,65,0,0,146,148,3,6,3,0,147,145,1,0,0,0,148,151,1,0,0,0,149,
  	147,1,0,0,0,149,150,1,0,0,0,150,153,1,0,0,0,151,149,1,0,0,0,152,154,5,
  	65,0,0,153,152,1,0,0,0,153,154,1,0,0,0,154,156,1,0,0,0,155,157,5,76,0,
  	0,156,155,1,0,0,0,156,157,1,0,0,0,157,5,1,0,0,0,158,166,3,56,28,0,159,
  	166,3,50,25,0,160,166,3,60,30,0,161,166,3,52,26,0,162,166,3,48,24,0,163,
  	166,5,13,0,0,164,166,5,14,0,0,165,158,1,0,0,0,165,159,1,0,0,0,165,160,
  	1,0,0,0,165,161,1,0,0,0,165,162,1,0,0,0,165,163,1,0,0,0,165,164,1,0,0,
  	0,166,7,1,0,0,0,167,179,3,28,14,0,168,179,3,36,18,0,169,179,3,18,9,0,
  	170,179,3,26,13,0,171,179,3,42,21,0,172,179,3,44,22,0,173,179,3,46,23,
  	0,174,179,3,20,10,0,175,179,3,10,5,0,176,179,3,14,7,0,177,179,3,22,11,
  	0,178,167,1,0,0,0,178,168,1,0,0,0,178,169,1,0,0,0,178,170,1,0,0,0,178,
  	171,1,0,0,0,178,172,1,0,0,0,178,173,1,0,0,0,178,174,1,0,0,0,178,175,1,
  	0,0,0,178,176,1,0,0,0,178,177,1,0,0,0,179,9,1,0,0,0,180,181,5,17,0,0,
  	181,182,5,73,0,0,182,186,3,34,17,0,183,185,3,12,6,0,184,183,1,0,0,0,185,
  	188,1,0,0,0,186,184,1,0,0,0,186,187,1,0,0,0,187,192,1,0,0,0,188,186,1,
  	0,0,0,189,190,5,3,0,0,190,191,5,73,0,0,191,193,3,34,17,0,192,189,1,0,
  	0,0,192,193,1,0,0,0,193,197,1,0,0,0,194,195,5,19,0,0,195,196,5,73,0,0,
  	196,198,3,34,17,0,197,194,1,0,0,0,197,198,1,0,0,0,198,11,1,0,0,0,199,
  	205,5,18,0,0,200,203,3,130,65,0,201,202,5,10,0,0,202,204,5,77,0,0,203,
  	201,1,0,0,0,203,204,1,0,0,0,204,206,1,0,0,0,205,200,1,0,0,0,205,206,1,
  	0,0,0,206,207,1,0,0,0,207,208,5,73,0,0,208,209,3,34,17,0,209,13,1,0,0,
  	0,210,211,5,20,0,0,211,216,3,16,8,0,212,213,5,72,0,0,213,215,3,16,8,0,
  	214,212,1,0,0,0,215,218,1,0,0,0,216,214,1,0,0,0,216,217,1,0,0,0,217,219,
  	1,0,0,0,218,216,1,0,0,0,219,220,5,73,0,0,220,221,3,34,17,0,221,15,1,0,
  	0,0,222,225,3,62,31,0,223,224,5,10,0,0,224,226,5,77,0,0,225,223,1,0,0,
  	0,225,226,1,0,0,0,226,17,1,0,0,0,227,228,5,21,0,0,228,229,3,36,18,0,229,
  	19,1,0,0,0,230,231,5,21,0,0,231,232,3,46,23,0,232,21,1,0,0,0,233,234,
  	5,21,0,0,234,235,3,14,7,0,235,23,1,0,0,0,236,237,5,22,0,0,237,238,3,62,
  	31,0,238,25,1,0,0,0,239,240,5,23,0,0,240,255,5,77,0,0,241,242,5,66,0,
  	0,242,247,3,62,31,0,243,244,5,72,0,0,244,246,3,62,31,0,245,243,1,0,0,
  	0,246,249,1,0,0,0,247,245,1,0,0,0,247,248,1,0,0,0,248,251,1,0,0,0,249,
  	247,1,0,0,0,250,252,5,72,0,0,251,250,1,0,0,0,251,252,1,0,0,0,252,253,
  	1,0,0,0,253,254,5,67,0,0,254,256,1,0,0,0,255,241,1,0,0,0,255,256,1,0,
  	0,0,256,258,1,0,0,0,257,259,3,30,15,0,258,257,1,0,0,0,258,259,1,0,0,0,
  	259,260,1,0,0,0,260,261,5,73,0,0,261,262,3,34,17,0,262,27,1,0,0,0,263,
  	266,3,30,15,0,264,267,3,36,18,0,265,267,3,26,13,0,266,264,1,0,0,0,266,
  	265,1,0,0,0,267,29,1,0,0,0,268,270,3,32,16,0,269,268,1,0,0,0,270,271,
  	1,0,0,0,271,269,1,0,0,0,271,272,1,0,0,0,272,31,1,0,0,0,273,274,5,24,0,
  	0,274,275,3,62,31,0,275,276,5,76,0,0,276,33,1,0,0,0,277,288,3,4,2,0,278,
  	279,5,76,0,0,279,281,5,83,0,0,280,282,3,2,1,0,281,280,1,0,0,0,282,283,
  	1,0,0,0,283,281,1,0,0,0,283,284,1,0,0,0,284,285,1,0,0,0,285,286,5,84,
  	0,0,286,288,1,0,0,0,287,277,1,0,0,0,287,278,1,0,0,0,288,35,1,0,0,0,289,
  	290,5,1,0,0,290,291,5,77,0,0,291,293,5,66,0,0,292,294,3,38,19,0,293,292,
  	1,0,0,0,293,294,1,0,0,0,294,295,1,0,0,0,295,296,5,67,0,0,296,297,5,73,
  	0,0,297,298,3,34,17,0,298,37,1,0,0,0,299,304,3,40,20,0,300,301,5,72,0,
  	0,301,303,3,40,20,0,302,300,1,0,0,0,303,306,1,0,0,0,304,302,1,0,0,0,304,
  	305,1,0,0,0,305,308,1,0,0,0,306,304,1,0,0,0,307,309,5,72,0,0,308,307,
  	1,0,0,0,308,309,1,0,0,0,309,39,1,0,0,0,310,313,5,77,0,0,311,312,5,52,
  	0,0,312,314,3,62,31,0,313,311,1,0,0,0,313,314,1,0,0,0,314,322,1,0,0,0,
  	315,317,5,36,0,0,316,318,5,77,0,0,317,316,1,0,0,0,317,318,1,0,0,0,318,
  	322,1,0,0,0,319,320,5,75,0,0,320,322,5,77,0,0,321,310,1,0,0,0,321,315,
  	1,0,0,0,321,319,1,0,0,0,322,41,1,0,0,0,323,324,5,2,0,0,324,325,3,62,31,
  	0,325,326,5,73,0,0,326,334,3,34,17,0,327,328,5,4,0,0,328,329,3,62,31,
  	0,329,330,5,73,0,0,330,331,3,34,17,0,331,333,1,0,0,0,332,327,1,0,0,0,
  	333,336,1,0,0,0,334,332,1,0,0,0,334,335,1,0,0,0,335,340,1,0,0,0,336,334,
  	1,0,0,0,337,338,5,3,0,0,338,339,5,73,0,0,339,341,3,34,17,0,340,337,1,
  	0,0,0,340,341,1,0,0,0,341,43,1,0,0,0,342,343,5,6,0,0,343,344,3,62,31,
  	0,344,345,5,73,0,0,345,346,3,34,17,0,346,45,1,0,0,0,347,348,5,5,0,0,348,
  	349,5,77,0,0,349,350,5,11,0,0,350,351,3,62,31,0,351,352,5,73,0,0,352,
  	353,3,34,17,0,353,47,1,0,0,0,354,355,5,12,0,0,355,49,1,0,0,0,356,358,
  	5,7,0,0,357,359,3,62,31,0,358,357,1,0,0,0,358,359,1,0,0,0,359,51,1,0,
  	0,0,360,361,5,8,0,0,361,364,3,130,65,0,362,363,5,10,0,0,363,365,5,77,
  	0,0,364,362,1,0,0,0,364,365,1,0,0,0,365,378,1,0,0,0,366,367,5,9,0,0,367,
  	368,3,130,65,0,368,369,5,8,0,0,369,374,3,54,27,0,370,371,5,72,0,0,371,
  	373,3,54,27,0,372,370,1,0,0,0,373,376,1,0,0,0,374,372,1,0,0,0,374,375,
  	1,0,0,0,375,378,1,0,0,0,376,374,1,0,0,0,377,360,1,0,0,0,377,366,1,0,0,
  	0,378,53,1,0,0,0,379,382,5,77,0,0,380,381,5,10,0,0,381,383,5,77,0,0,382,
  	380,1,0,0,0,382,383,1,0,0,0,383,55,1,0,0,0,384,385,3,58,29,0,385,386,
  	7,0,0,0,386,387,3,62,31,0,387,57,1,0,0,0,388,399,5,77,0,0,389,390,3,90,
  	45,0,390,391,5,74,0,0,391,392,5,77,0,0,392,399,1,0,0,0,393,394,3,90,45,
  	0,394,395,5,68,0,0,395,396,3,100,50,0,396,397,5,69,0,0,397,399,1,0,0,
  	0,398,388,1,0,0,0,398,389,1,0,0,0,398,393,1,0,0,0,399,59,1,0,0,0,400,
  	401,3,62,31,0,401,61,1,0,0,0,402,403,3,64,32,0,403,63,1,0,0,0,404,410,
  	3,66,33,0,405,406,5,2,0,0,406,407,3,66,33,0,407,408,5,3,0,0,408,409,3,
  	64,32,0,409,411,1,0,0,0,410,405,1,0,0,0,410,411,1,0,0,0,411,65,1,0,0,
  	0,412,417,3,68,34,0,413,414,5,29,0,0,414,416,3,68,34,0,415,413,1,0,0,
  	0,416,419,1,0,0,0,417,415,1,0,0,0,417,418,1,0,0,0,418,67,1,0,0,0,419,
  	417,1,0,0,0,420,425,3,70,35,0,421,422,5,28,0,0,422,424,3,70,35,0,423,
  	421,1,0,0,0,424,427,1,0,0,0,425,423,1,0,0,0,425,426,1,0,0,0,426,69,1,
  	0,0,0,427,425,1,0,0,0,428,433,3,72,36,0,429,430,5,49,0,0,430,432,3,72,
  	36,0,431,429,1,0,0,0,432,435,1,0,0,0,433,431,1,0,0,0,433,434,1,0,0,0,
  	434,71,1,0,0,0,435,433,1,0,0,0,436,441,3,74,37,0,437,438,5,50,0,0,438,
  	440,3,74,37,0,439,437,1,0,0,0,440,443,1,0,0,0,441,439,1,0,0,0,441,442,
  	1,0,0,0,442,73,1,0,0,0,443,441,1,0,0,0,444,449,3,76,38,0,445,446,5,48,
  	0,0,446,448,3,76,38,0,447,445,1,0,0,0,448,451,1,0,0,0,449,447,1,0,0,0,
  	449,450,1,0,0,0,450,75,1,0,0,0,451,449,1,0,0,0,452,457,3,78,39,0,453,
  	454,7,1,0,0,454,456,3,78,39,0,455,453,1,0,0,0,456,459,1,0,0,0,457,455,
  	1,0,0,0,457,458,1,0,0,0,458,77,1,0,0,0,459,457,1,0,0,0,460,465,3,80,40,
  	0,461,462,7,2,0,0,462,464,3,80,40,0,463,461,1,0,0,0,464,467,1,0,0,0,465,
  	463,1,0,0,0,465,466,1,0,0,0,466,79,1,0,0,0,467,465,1,0,0,0,468,473,3,
  	82,41,0,469,470,7,3,0,0,470,472,3,82,41,0,471,469,1,0,0,0,472,475,1,0,
  	0,0,473,471,1,0,0,0,473,474,1,0,0,0,474,81,1,0,0,0,475,473,1,0,0,0,476,
  	481,3,84,42,0,477,478,7,4,0,0,478,480,3,84,42,0,479,477,1,0,0,0,480,483,
  	1,0,0,0,481,479,1,0,0,0,481,482,1,0,0,0,482,83,1,0,0,0,483,481,1,0,0,
  	0,484,489,3,86,43,0,485,486,7,5,0,0,486,488,3,86,43,0,487,485,1,0,0,0,
  	488,491,1,0,0,0,489,487,1,0,0,0,489,490,1,0,0,0,490,85,1,0,0,0,491,489,
  	1,0,0,0,492,495,3,88,44,0,493,494,5,75,0,0,494,496,3,86,43,0,495,493,
  	1,0,0,0,495,496,1,0,0,0,496,87,1,0,0,0,497,499,7,6,0,0,498,497,1,0,0,
  	0,498,499,1,0,0,0,499,500,1,0,0,0,500,503,3,96,48,0,501,503,3,24,12,0,
  	502,498,1,0,0,0,502,501,1,0,0,0,503,89,1,0,0,0,504,522,3,126,63,0,505,
  	522,5,77,0,0,506,507,5,66,0,0,507,508,3,92,46,0,508,509,5,67,0,0,509,
  	522,1,0,0,0,510,511,5,66,0,0,511,512,3,62,31,0,512,513,5,67,0,0,513,522,
  	1,0,0,0,514,522,3,106,53,0,515,522,3,114,57,0,516,522,3,120,60,0,517,
  	522,3,124,62,0,518,522,3,94,47,0,519,522,3,128,64,0,520,522,3,24,12,0,
  	521,504,1,0,0,0,521,505,1,0,0,0,521,506,1,0,0,0,521,510,1,0,0,0,521,514,
  	1,0,0,0,521,515,1,0,0,0,521,516,1,0,0,0,521,517,1,0,0,0,521,518,1,0,0,
  	0,521,519,1,0,0,0,521,520,1,0,0,0,522,91,1,0,0,0,523,524,3,62,31,0,524,
  	530,5,72,0,0,525,526,3,62,31,0,526,527,5,72,0,0,527,529,1,0,0,0,528,525,
  	1,0,0,0,529,532,1,0,0,0,530,528,1,0,0,0,530,531,1,0,0,0,531,534,1,0,0,
  	0,532,530,1,0,0,0,533,535,3,62,31,0,534,533,1,0,0,0,534,535,1,0,0,0,535,
  	537,1,0,0,0,536,538,5,72,0,0,537,536,1,0,0,0,537,538,1,0,0,0,538,543,
  	1,0,0,0,539,540,3,62,31,0,540,541,5,72,0,0,541,543,1,0,0,0,542,523,1,
  	0,0,0,542,539,1,0,0,0,543,93,1,0,0,0,544,545,5,15,0,0,545,546,3,130,65,
  	0,546,548,5,66,0,0,547,549,3,102,51,0,548,547,1,0,0,0,548,549,1,0,0,0,
  	549,550,1,0,0,0,550,551,5,67,0,0,551,95,1,0,0,0,552,556,3,90,45,0,553,
  	555,3,98,49,0,554,553,1,0,0,0,555,558,1,0,0,0,556,554,1,0,0,0,556,557,
  	1,0,0,0,557,97,1,0,0,0,558,556,1,0,0,0,559,560,5,74,0,0,560,571,5,77,
  	0,0,561,562,5,68,0,0,562,563,3,100,50,0,563,564,5,69,0,0,564,571,1,0,
  	0,0,565,567,5,66,0,0,566,568,3,102,51,0,567,566,1,0,0,0,567,568,1,0,0,
  	0,568,569,1,0,0,0,569,571,5,67,0,0,570,559,1,0,0,0,570,561,1,0,0,0,570,
  	565,1,0,0,0,571,99,1,0,0,0,572,574,3,62,31,0,573,572,1,0,0,0,573,574,
  	1,0,0,0,574,585,1,0,0,0,575,577,5,73,0,0,576,578,3,62,31,0,577,576,1,
  	0,0,0,577,578,1,0,0,0,578,583,1,0,0,0,579,581,5,73,0,0,580,582,3,62,31,
  	0,581,580,1,0,0,0,581,582,1,0,0,0,582,584,1,0,0,0,583,579,1,0,0,0,583,
  	584,1,0,0,0,584,586,1,0,0,0,585,575,1,0,0,0,585,586,1,0,0,0,586,101,1,
  	0,0,0,587,592,3,104,52,0,588,589,5,72,0,0,589,591,3,104,52,0,590,588,
  	1,0,0,0,591,594,1,0,0,0,592,590,1,0,0,0,592,593,1,0,0,0,593,596,1,0,0,
  	0,594,592,1,0,0,0,595,597,5,72,0,0,596,595,1,0,0,0,596,597,1,0,0,0,597,
  	103,1,0,0,0,598,599,5,77,0,0,599,600,5,52,0,0,600,607,3,62,31,0,601,607,
  	3,62,31,0,602,603,5,36,0,0,603,607,3,62,31,0,604,605,5,75,0,0,605,607,
  	3,62,31,0,606,598,1,0,0,0,606,601,1,0,0,0,606,602,1,0,0,0,606,604,1,0,
  	0,0,607,105,1,0,0,0,608,610,5,68,0,0,609,611,3,108,54,0,610,609,1,0,0,
  	0,610,611,1,0,0,0,611,612,1,0,0,0,612,613,5,69,0,0,613,107,1,0,0,0,614,
  	619,3,62,31,0,615,616,5,72,0,0,616,618,3,62,31,0,617,615,1,0,0,0,618,
  	621,1,0,0,0,619,617,1,0,0,0,619,620,1,0,0,0,620,623,1,0,0,0,621,619,1,
  	0,0,0,622,624,5,72,0,0,623,622,1,0,0,0,623,624,1,0,0,0,624,627,1,0,0,
  	0,625,627,3,110,55,0,626,614,1,0,0,0,626,625,1,0,0,0,627,109,1,0,0,0,
  	628,630,3,62,31,0,629,631,3,112,56,0,630,629,1,0,0,0,631,632,1,0,0,0,
  	632,630,1,0,0,0,632,633,1,0,0,0,633,111,1,0,0,0,634,637,5,5,0,0,635,638,
  	5,77,0,0,636,638,3,92,46,0,637,635,1,0,0,0,637,636,1,0,0,0,638,639,1,
  	0,0,0,639,640,5,11,0,0,640,643,3,62,31,0,641,642,5,2,0,0,642,644,3,62,
  	31,0,643,641,1,0,0,0,643,644,1,0,0,0,644,113,1,0,0,0,645,660,5,70,0,0,
  	646,661,3,116,58,0,647,652,3,118,59,0,648,649,5,72,0,0,649,651,3,118,
  	59,0,650,648,1,0,0,0,651,654,1,0,0,0,652,650,1,0,0,0,652,653,1,0,0,0,
  	653,656,1,0,0,0,654,652,1,0,0,0,655,657,5,72,0,0,656,655,1,0,0,0,656,
  	657,1,0,0,0,657,659,1,0,0,0,658,647,1,0,0,0,658,659,1,0,0,0,659,661,1,
  	0,0,0,660,646,1,0,0,0,660,658,1,0,0,0,661,662,1,0,0,0,662,663,5,71,0,
  	0,663,115,1,0,0,0,664,665,3,62,31,0,665,666,5,73,0,0,666,668,3,62,31,
  	0,667,669,3,112,56,0,668,667,1,0,0,0,669,670,1,0,0,0,670,668,1,0,0,0,
  	670,671,1,0,0,0,671,117,1,0,0,0,672,673,3,62,31,0,673,674,5,73,0,0,674,
  	675,3,62,31,0,675,679,1,0,0,0,676,677,5,75,0,0,677,679,3,62,31,0,678,
  	672,1,0,0,0,678,676,1,0,0,0,679,119,1,0,0,0,680,682,5,70,0,0,681,683,
  	3,122,61,0,682,681,1,0,0,0,682,683,1,0,0,0,683,684,1,0,0,0,684,685,5,
  	71,0,0,685,121,1,0,0,0,686,691,3,62,31,0,687,688,5,72,0,0,688,690,3,62,
  	31,0,689,687,1,0,0,0,690,693,1,0,0,0,691,689,1,0,0,0,691,692,1,0,0,0,
  	692,695,1,0,0,0,693,691,1,0,0,0,694,696,5,72,0,0,695,694,1,0,0,0,695,
  	696,1,0,0,0,696,699,1,0,0,0,697,699,3,110,55,0,698,686,1,0,0,0,698,697,
  	1,0,0,0,699,123,1,0,0,0,700,701,5,66,0,0,701,702,3,110,55,0,702,703,5,
  	67,0,0,703,125,1,0,0,0,704,705,7,7,0,0,705,127,1,0,0,0,706,708,5,16,0,
  	0,707,709,3,38,19,0,708,707,1,0,0,0,708,709,1,0,0,0,709,710,1,0,0,0,710,
  	711,5,73,0,0,711,712,3,62,31,0,712,129,1,0,0,0,713,718,5,77,0,0,714,715,
  	5,74,0,0,715,717,5,77,0,0,716,714,1,0,0,0,717,720,1,0,0,0,718,716,1,0,
  	0,0,718,719,1,0,0,0,719,131,1,0,0,0,720,718,1,0,0,0,86,135,142,149,153,
  	156,165,178,186,192,197,203,205,216,225,247,251,255,258,266,271,283,287,
  	293,304,308,313,317,321,334,340,358,364,374,377,382,398,410,417,425,433,
  	441,449,457,465,473,481,489,495,498,502,521,530,534,537,542,548,556,567,
  	570,573,577,581,583,585,592,596,606,610,619,623,626,632,637,643,652,656,
  	658,660,670,678,682,691,695,698,708,718
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
    setState(135);
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
      | (1ULL << PyScriptParser::BREAK)
      | (1ULL << PyScriptParser::CONTINUE)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::TRY)
      | (1ULL << PyScriptParser::WITH)
      | (1ULL << PyScriptParser::ASYNC)
      | (1ULL << PyScriptParser::AWAIT)
      | (1ULL << PyScriptParser::CLASS)
      | (1ULL << PyScriptParser::AT)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
      | (1ULL << (PyScriptParser::LBRACK - 66))
      | (1ULL << (PyScriptParser::LBRACE - 66))
      | (1ULL << (PyScriptParser::IDENTIFIER - 66))
      | (1ULL << (PyScriptParser::INTEGER - 66))
      | (1ULL << (PyScriptParser::FLOAT - 66))
      | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
      setState(132);
      statement();
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(138);
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
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::RETURN:
      case PyScriptParser::IMPORT:
      case PyScriptParser::FROM:
      case PyScriptParser::PASS:
      case PyScriptParser::BREAK:
      case PyScriptParser::CONTINUE:
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::AWAIT:
      case PyScriptParser::TRUE:
      case PyScriptParser::FALSE:
      case PyScriptParser::NONE:
      case PyScriptParser::NOT:
      case PyScriptParser::PLUS:
      case PyScriptParser::MINUS:
      case PyScriptParser::BITWISE_NOT:
      case PyScriptParser::LPAREN:
      case PyScriptParser::LBRACK:
      case PyScriptParser::LBRACE:
      case PyScriptParser::IDENTIFIER:
      case PyScriptParser::INTEGER:
      case PyScriptParser::FLOAT:
      case PyScriptParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(140);
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
      case PyScriptParser::CLASS:
      case PyScriptParser::AT: {
        enterOuterAlt(_localctx, 2);
        setState(141);
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
    setState(144);
    smallStatement();
    setState(149);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(145);
        match(PyScriptParser::SEMI);
        setState(146);
        smallStatement(); 
      }
      setState(151);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::SEMI) {
      setState(152);
      match(PyScriptParser::SEMI);
    }
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::NEWLINE) {
      setState(155);
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

tree::TerminalNode* PyScriptParser::SmallStatementContext::BREAK() {
  return getToken(PyScriptParser::BREAK, 0);
}

tree::TerminalNode* PyScriptParser::SmallStatementContext::CONTINUE() {
  return getToken(PyScriptParser::CONTINUE, 0);
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
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(158);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(159);
      returnStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(160);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(161);
      importStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(162);
      passStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(163);
      match(PyScriptParser::BREAK);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(164);
      match(PyScriptParser::CONTINUE);
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

PyScriptParser::DecoratedDefContext* PyScriptParser::CompoundStatementContext::decoratedDef() {
  return getRuleContext<PyScriptParser::DecoratedDefContext>(0);
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
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(167);
      decoratedDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
      functionDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(169);
      asyncFunctionDef();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(170);
      classDef();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(171);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(172);
      whileStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(173);
      forStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(174);
      asyncForStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(175);
      tryStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(176);
      withStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(177);
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
    setState(180);
    match(PyScriptParser::TRY);
    setState(181);
    match(PyScriptParser::COLON);
    setState(182);
    suite();
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::EXCEPT) {
      setState(183);
      exceptClause();
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(189);
      match(PyScriptParser::ELSE);
      setState(190);
      match(PyScriptParser::COLON);
      setState(191);
      suite();
    }
    setState(197);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::FINALLY) {
      setState(194);
      match(PyScriptParser::FINALLY);
      setState(195);
      match(PyScriptParser::COLON);
      setState(196);
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
    setState(199);
    match(PyScriptParser::EXCEPT);
    setState(205);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IDENTIFIER) {
      setState(200);
      dottedName();
      setState(203);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::AS) {
        setState(201);
        match(PyScriptParser::AS);
        setState(202);
        match(PyScriptParser::IDENTIFIER);
      }
    }
    setState(207);
    match(PyScriptParser::COLON);
    setState(208);
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
    setState(210);
    match(PyScriptParser::WITH);
    setState(211);
    withItem();
    setState(216);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(212);
      match(PyScriptParser::COMMA);
      setState(213);
      withItem();
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(219);
    match(PyScriptParser::COLON);
    setState(220);
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
    setState(222);
    expression();
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(223);
      match(PyScriptParser::AS);
      setState(224);
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
    setState(227);
    match(PyScriptParser::ASYNC);
    setState(228);
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
    setState(230);
    match(PyScriptParser::ASYNC);
    setState(231);
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
    setState(233);
    match(PyScriptParser::ASYNC);
    setState(234);
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
    setState(236);
    match(PyScriptParser::AWAIT);
    setState(237);
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

tree::TerminalNode* PyScriptParser::ClassDefContext::LPAREN() {
  return getToken(PyScriptParser::LPAREN, 0);
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::ClassDefContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::ClassDefContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::ClassDefContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::DecoratorsContext* PyScriptParser::ClassDefContext::decorators() {
  return getRuleContext<PyScriptParser::DecoratorsContext>(0);
}

std::vector<tree::TerminalNode *> PyScriptParser::ClassDefContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::ClassDefContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
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
    setState(239);
    match(PyScriptParser::CLASS);
    setState(240);
    match(PyScriptParser::IDENTIFIER);
    setState(255);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::LPAREN) {
      setState(241);
      match(PyScriptParser::LPAREN);
      setState(242);
      expression();
      setState(247);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(243);
          match(PyScriptParser::COMMA);
          setState(244);
          expression(); 
        }
        setState(249);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      }
      setState(251);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(250);
        match(PyScriptParser::COMMA);
      }
      setState(253);
      match(PyScriptParser::RPAREN);
    }
    setState(258);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AT) {
      setState(257);
      decorators();
    }
    setState(260);
    match(PyScriptParser::COLON);
    setState(261);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecoratedDefContext ------------------------------------------------------------------

PyScriptParser::DecoratedDefContext::DecoratedDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::DecoratorsContext* PyScriptParser::DecoratedDefContext::decorators() {
  return getRuleContext<PyScriptParser::DecoratorsContext>(0);
}

PyScriptParser::FunctionDefContext* PyScriptParser::DecoratedDefContext::functionDef() {
  return getRuleContext<PyScriptParser::FunctionDefContext>(0);
}

PyScriptParser::ClassDefContext* PyScriptParser::DecoratedDefContext::classDef() {
  return getRuleContext<PyScriptParser::ClassDefContext>(0);
}


size_t PyScriptParser::DecoratedDefContext::getRuleIndex() const {
  return PyScriptParser::RuleDecoratedDef;
}

void PyScriptParser::DecoratedDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecoratedDef(this);
}

void PyScriptParser::DecoratedDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecoratedDef(this);
}


std::any PyScriptParser::DecoratedDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDecoratedDef(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DecoratedDefContext* PyScriptParser::decoratedDef() {
  DecoratedDefContext *_localctx = _tracker.createInstance<DecoratedDefContext>(_ctx, getState());
  enterRule(_localctx, 28, PyScriptParser::RuleDecoratedDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    decorators();
    setState(266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DEF: {
        setState(264);
        functionDef();
        break;
      }

      case PyScriptParser::CLASS: {
        setState(265);
        classDef();
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

//----------------- DecoratorsContext ------------------------------------------------------------------

PyScriptParser::DecoratorsContext::DecoratorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::DecoratorContext *> PyScriptParser::DecoratorsContext::decorator() {
  return getRuleContexts<PyScriptParser::DecoratorContext>();
}

PyScriptParser::DecoratorContext* PyScriptParser::DecoratorsContext::decorator(size_t i) {
  return getRuleContext<PyScriptParser::DecoratorContext>(i);
}


size_t PyScriptParser::DecoratorsContext::getRuleIndex() const {
  return PyScriptParser::RuleDecorators;
}

void PyScriptParser::DecoratorsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecorators(this);
}

void PyScriptParser::DecoratorsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecorators(this);
}


std::any PyScriptParser::DecoratorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDecorators(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DecoratorsContext* PyScriptParser::decorators() {
  DecoratorsContext *_localctx = _tracker.createInstance<DecoratorsContext>(_ctx, getState());
  enterRule(_localctx, 30, PyScriptParser::RuleDecorators);
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
    setState(269); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(268);
      decorator();
      setState(271); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PyScriptParser::AT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecoratorContext ------------------------------------------------------------------

PyScriptParser::DecoratorContext::DecoratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::DecoratorContext::AT() {
  return getToken(PyScriptParser::AT, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::DecoratorContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::DecoratorContext::NEWLINE() {
  return getToken(PyScriptParser::NEWLINE, 0);
}


size_t PyScriptParser::DecoratorContext::getRuleIndex() const {
  return PyScriptParser::RuleDecorator;
}

void PyScriptParser::DecoratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecorator(this);
}

void PyScriptParser::DecoratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecorator(this);
}


std::any PyScriptParser::DecoratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDecorator(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DecoratorContext* PyScriptParser::decorator() {
  DecoratorContext *_localctx = _tracker.createInstance<DecoratorContext>(_ctx, getState());
  enterRule(_localctx, 32, PyScriptParser::RuleDecorator);

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
    match(PyScriptParser::AT);
    setState(274);
    expression();
    setState(275);
    match(PyScriptParser::NEWLINE);
   
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
  enterRule(_localctx, 34, PyScriptParser::RuleSuite);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::RETURN:
      case PyScriptParser::IMPORT:
      case PyScriptParser::FROM:
      case PyScriptParser::PASS:
      case PyScriptParser::BREAK:
      case PyScriptParser::CONTINUE:
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::AWAIT:
      case PyScriptParser::TRUE:
      case PyScriptParser::FALSE:
      case PyScriptParser::NONE:
      case PyScriptParser::NOT:
      case PyScriptParser::PLUS:
      case PyScriptParser::MINUS:
      case PyScriptParser::BITWISE_NOT:
      case PyScriptParser::LPAREN:
      case PyScriptParser::LBRACK:
      case PyScriptParser::LBRACE:
      case PyScriptParser::IDENTIFIER:
      case PyScriptParser::INTEGER:
      case PyScriptParser::FLOAT:
      case PyScriptParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(277);
        simpleStatement();
        break;
      }

      case PyScriptParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(278);
        match(PyScriptParser::NEWLINE);
        setState(279);
        match(PyScriptParser::INDENT);
        setState(281); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(280);
          statement();
          setState(283); 
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
          | (1ULL << PyScriptParser::BREAK)
          | (1ULL << PyScriptParser::CONTINUE)
          | (1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::TRY)
          | (1ULL << PyScriptParser::WITH)
          | (1ULL << PyScriptParser::ASYNC)
          | (1ULL << PyScriptParser::AWAIT)
          | (1ULL << PyScriptParser::CLASS)
          | (1ULL << PyScriptParser::AT)
          | (1ULL << PyScriptParser::TRUE)
          | (1ULL << PyScriptParser::FALSE)
          | (1ULL << PyScriptParser::NONE)
          | (1ULL << PyScriptParser::NOT)
          | (1ULL << PyScriptParser::PLUS)
          | (1ULL << PyScriptParser::MINUS)
          | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
          | (1ULL << (PyScriptParser::LBRACK - 66))
          | (1ULL << (PyScriptParser::LBRACE - 66))
          | (1ULL << (PyScriptParser::IDENTIFIER - 66))
          | (1ULL << (PyScriptParser::INTEGER - 66))
          | (1ULL << (PyScriptParser::FLOAT - 66))
          | (1ULL << (PyScriptParser::STRING - 66)))) != 0));
        setState(285);
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
  enterRule(_localctx, 36, PyScriptParser::RuleFunctionDef);
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
    setState(289);
    match(PyScriptParser::DEF);
    setState(290);
    match(PyScriptParser::IDENTIFIER);
    setState(291);
    match(PyScriptParser::LPAREN);
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 36) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 36)) & ((1ULL << (PyScriptParser::MUL - 36))
      | (1ULL << (PyScriptParser::DOUBLE_STAR - 36))
      | (1ULL << (PyScriptParser::IDENTIFIER - 36)))) != 0)) {
      setState(292);
      parameterList();
    }
    setState(295);
    match(PyScriptParser::RPAREN);
    setState(296);
    match(PyScriptParser::COLON);
    setState(297);
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
  enterRule(_localctx, 38, PyScriptParser::RuleParameterList);
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
    setState(299);
    parameter();
    setState(304);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(300);
        match(PyScriptParser::COMMA);
        setState(301);
        parameter(); 
      }
      setState(306);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
    setState(308);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(307);
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
  enterRule(_localctx, 40, PyScriptParser::RuleParameter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(310);
        match(PyScriptParser::IDENTIFIER);
        setState(313);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::ASSIGN) {
          setState(311);
          match(PyScriptParser::ASSIGN);
          setState(312);
          expression();
        }
        break;
      }

      case PyScriptParser::MUL: {
        enterOuterAlt(_localctx, 2);
        setState(315);
        match(PyScriptParser::MUL);
        setState(317);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::IDENTIFIER) {
          setState(316);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 3);
        setState(319);
        match(PyScriptParser::DOUBLE_STAR);
        setState(320);
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

std::vector<tree::TerminalNode *> PyScriptParser::IfStatementContext::ELIF() {
  return getTokens(PyScriptParser::ELIF);
}

tree::TerminalNode* PyScriptParser::IfStatementContext::ELIF(size_t i) {
  return getToken(PyScriptParser::ELIF, i);
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
  enterRule(_localctx, 42, PyScriptParser::RuleIfStatement);
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
    setState(323);
    match(PyScriptParser::IF);
    setState(324);
    expression();
    setState(325);
    match(PyScriptParser::COLON);
    setState(326);
    suite();
    setState(334);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::ELIF) {
      setState(327);
      match(PyScriptParser::ELIF);
      setState(328);
      expression();
      setState(329);
      match(PyScriptParser::COLON);
      setState(330);
      suite();
      setState(336);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(340);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(337);
      match(PyScriptParser::ELSE);
      setState(338);
      match(PyScriptParser::COLON);
      setState(339);
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
  enterRule(_localctx, 44, PyScriptParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(PyScriptParser::WHILE);
    setState(343);
    expression();
    setState(344);
    match(PyScriptParser::COLON);
    setState(345);
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
  enterRule(_localctx, 46, PyScriptParser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    match(PyScriptParser::FOR);
    setState(348);
    match(PyScriptParser::IDENTIFIER);
    setState(349);
    match(PyScriptParser::IN);
    setState(350);
    expression();
    setState(351);
    match(PyScriptParser::COLON);
    setState(352);
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
  enterRule(_localctx, 48, PyScriptParser::RulePassStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(354);
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
  enterRule(_localctx, 50, PyScriptParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(PyScriptParser::RETURN);
    setState(358);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(357);
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
  enterRule(_localctx, 52, PyScriptParser::RuleImportStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IMPORT: {
        _localctx = _tracker.createInstance<PyScriptParser::SimpleImportContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(360);
        match(PyScriptParser::IMPORT);
        setState(361);
        dottedName();
        setState(364);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::AS) {
          setState(362);
          match(PyScriptParser::AS);
          setState(363);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::FROM: {
        _localctx = _tracker.createInstance<PyScriptParser::FromImportContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(366);
        match(PyScriptParser::FROM);
        setState(367);
        dottedName();
        setState(368);
        match(PyScriptParser::IMPORT);
        setState(369);
        importItem();
        setState(374);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PyScriptParser::COMMA) {
          setState(370);
          match(PyScriptParser::COMMA);
          setState(371);
          importItem();
          setState(376);
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
  enterRule(_localctx, 54, PyScriptParser::RuleImportItem);
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
    setState(379);
    match(PyScriptParser::IDENTIFIER);
    setState(382);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(380);
      match(PyScriptParser::AS);
      setState(381);
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

PyScriptParser::AssignmentTargetContext* PyScriptParser::AssignmentContext::assignmentTarget() {
  return getRuleContext<PyScriptParser::AssignmentTargetContext>(0);
}

PyScriptParser::ExpressionContext* PyScriptParser::AssignmentContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::ASSIGN() {
  return getToken(PyScriptParser::ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::PLUS_ASSIGN() {
  return getToken(PyScriptParser::PLUS_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::MINUS_ASSIGN() {
  return getToken(PyScriptParser::MINUS_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::MUL_ASSIGN() {
  return getToken(PyScriptParser::MUL_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::DIV_ASSIGN() {
  return getToken(PyScriptParser::DIV_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::FLOOR_DIV_ASSIGN() {
  return getToken(PyScriptParser::FLOOR_DIV_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::MOD_ASSIGN() {
  return getToken(PyScriptParser::MOD_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::POW_ASSIGN() {
  return getToken(PyScriptParser::POW_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::BITWISE_AND_ASSIGN() {
  return getToken(PyScriptParser::BITWISE_AND_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::BITWISE_OR_ASSIGN() {
  return getToken(PyScriptParser::BITWISE_OR_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::BITWISE_XOR_ASSIGN() {
  return getToken(PyScriptParser::BITWISE_XOR_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::LEFT_SHIFT_ASSIGN() {
  return getToken(PyScriptParser::LEFT_SHIFT_ASSIGN, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentContext::RIGHT_SHIFT_ASSIGN() {
  return getToken(PyScriptParser::RIGHT_SHIFT_ASSIGN, 0);
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
  enterRule(_localctx, 56, PyScriptParser::RuleAssignment);
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
    setState(384);
    assignmentTarget();
    setState(385);
    _la = _input->LA(1);
    if (!(((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (PyScriptParser::ASSIGN - 52))
      | (1ULL << (PyScriptParser::PLUS_ASSIGN - 52))
      | (1ULL << (PyScriptParser::MINUS_ASSIGN - 52))
      | (1ULL << (PyScriptParser::MUL_ASSIGN - 52))
      | (1ULL << (PyScriptParser::DIV_ASSIGN - 52))
      | (1ULL << (PyScriptParser::FLOOR_DIV_ASSIGN - 52))
      | (1ULL << (PyScriptParser::MOD_ASSIGN - 52))
      | (1ULL << (PyScriptParser::POW_ASSIGN - 52))
      | (1ULL << (PyScriptParser::BITWISE_AND_ASSIGN - 52))
      | (1ULL << (PyScriptParser::BITWISE_OR_ASSIGN - 52))
      | (1ULL << (PyScriptParser::BITWISE_XOR_ASSIGN - 52))
      | (1ULL << (PyScriptParser::LEFT_SHIFT_ASSIGN - 52))
      | (1ULL << (PyScriptParser::RIGHT_SHIFT_ASSIGN - 52)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(386);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentTargetContext ------------------------------------------------------------------

PyScriptParser::AssignmentTargetContext::AssignmentTargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::AssignmentTargetContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::PrimaryContext* PyScriptParser::AssignmentTargetContext::primary() {
  return getRuleContext<PyScriptParser::PrimaryContext>(0);
}

tree::TerminalNode* PyScriptParser::AssignmentTargetContext::DOT() {
  return getToken(PyScriptParser::DOT, 0);
}

tree::TerminalNode* PyScriptParser::AssignmentTargetContext::LBRACK() {
  return getToken(PyScriptParser::LBRACK, 0);
}

PyScriptParser::SubscriptArgContext* PyScriptParser::AssignmentTargetContext::subscriptArg() {
  return getRuleContext<PyScriptParser::SubscriptArgContext>(0);
}

tree::TerminalNode* PyScriptParser::AssignmentTargetContext::RBRACK() {
  return getToken(PyScriptParser::RBRACK, 0);
}


size_t PyScriptParser::AssignmentTargetContext::getRuleIndex() const {
  return PyScriptParser::RuleAssignmentTarget;
}

void PyScriptParser::AssignmentTargetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentTarget(this);
}

void PyScriptParser::AssignmentTargetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentTarget(this);
}


std::any PyScriptParser::AssignmentTargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentTarget(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AssignmentTargetContext* PyScriptParser::assignmentTarget() {
  AssignmentTargetContext *_localctx = _tracker.createInstance<AssignmentTargetContext>(_ctx, getState());
  enterRule(_localctx, 58, PyScriptParser::RuleAssignmentTarget);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(388);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(389);
      primary();
      setState(390);
      match(PyScriptParser::DOT);
      setState(391);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(393);
      primary();
      setState(394);
      match(PyScriptParser::LBRACK);
      setState(395);
      subscriptArg();
      setState(396);
      match(PyScriptParser::RBRACK);
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
  enterRule(_localctx, 60, PyScriptParser::RuleExpressionStatement);

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


size_t PyScriptParser::ExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleExpression;
}

void PyScriptParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConditionalExprContext ------------------------------------------------------------------

PyScriptParser::ConditionalExpressionContext* PyScriptParser::ConditionalExprContext::conditionalExpression() {
  return getRuleContext<PyScriptParser::ConditionalExpressionContext>(0);
}

PyScriptParser::ConditionalExprContext::ConditionalExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::ConditionalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalExpr(this);
}
void PyScriptParser::ConditionalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalExpr(this);
}

std::any PyScriptParser::ConditionalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitConditionalExpr(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::ExpressionContext* PyScriptParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 62, PyScriptParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<PyScriptParser::ConditionalExprContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(402);
    conditionalExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalExpressionContext ------------------------------------------------------------------

PyScriptParser::ConditionalExpressionContext::ConditionalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::ConditionalExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleConditionalExpression;
}

void PyScriptParser::ConditionalExpressionContext::copyFrom(ConditionalExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConditionalContext ------------------------------------------------------------------

std::vector<PyScriptParser::LogicalOrContext *> PyScriptParser::ConditionalContext::logicalOr() {
  return getRuleContexts<PyScriptParser::LogicalOrContext>();
}

PyScriptParser::LogicalOrContext* PyScriptParser::ConditionalContext::logicalOr(size_t i) {
  return getRuleContext<PyScriptParser::LogicalOrContext>(i);
}

tree::TerminalNode* PyScriptParser::ConditionalContext::IF() {
  return getToken(PyScriptParser::IF, 0);
}

tree::TerminalNode* PyScriptParser::ConditionalContext::ELSE() {
  return getToken(PyScriptParser::ELSE, 0);
}

PyScriptParser::ConditionalExpressionContext* PyScriptParser::ConditionalContext::conditionalExpression() {
  return getRuleContext<PyScriptParser::ConditionalExpressionContext>(0);
}

PyScriptParser::ConditionalContext::ConditionalContext(ConditionalExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::ConditionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional(this);
}
void PyScriptParser::ConditionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional(this);
}

std::any PyScriptParser::ConditionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitConditional(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::ConditionalExpressionContext* PyScriptParser::conditionalExpression() {
  ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 64, PyScriptParser::RuleConditionalExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<PyScriptParser::ConditionalContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(404);
    logicalOr();
    setState(410);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(405);
      match(PyScriptParser::IF);
      setState(406);
      logicalOr();
      setState(407);
      match(PyScriptParser::ELSE);
      setState(408);
      conditionalExpression();
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
  enterRule(_localctx, 66, PyScriptParser::RuleLogicalOr);

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
    setState(412);
    logicalAnd();
    setState(417);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(413);
        match(PyScriptParser::OR);
        setState(414);
        logicalAnd(); 
      }
      setState(419);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
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

std::vector<PyScriptParser::BitwiseOrContext *> PyScriptParser::LogicalAndContext::bitwiseOr() {
  return getRuleContexts<PyScriptParser::BitwiseOrContext>();
}

PyScriptParser::BitwiseOrContext* PyScriptParser::LogicalAndContext::bitwiseOr(size_t i) {
  return getRuleContext<PyScriptParser::BitwiseOrContext>(i);
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
  enterRule(_localctx, 68, PyScriptParser::RuleLogicalAnd);

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
    setState(420);
    bitwiseOr();
    setState(425);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(421);
        match(PyScriptParser::AND);
        setState(422);
        bitwiseOr(); 
      }
      setState(427);
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

//----------------- BitwiseOrContext ------------------------------------------------------------------

PyScriptParser::BitwiseOrContext::BitwiseOrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::BitwiseOrContext::getRuleIndex() const {
  return PyScriptParser::RuleBitwiseOr;
}

void PyScriptParser::BitwiseOrContext::copyFrom(BitwiseOrContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitwiseOrExprContext ------------------------------------------------------------------

std::vector<PyScriptParser::BitwiseXorContext *> PyScriptParser::BitwiseOrExprContext::bitwiseXor() {
  return getRuleContexts<PyScriptParser::BitwiseXorContext>();
}

PyScriptParser::BitwiseXorContext* PyScriptParser::BitwiseOrExprContext::bitwiseXor(size_t i) {
  return getRuleContext<PyScriptParser::BitwiseXorContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::BitwiseOrExprContext::BITWISE_OR() {
  return getTokens(PyScriptParser::BITWISE_OR);
}

tree::TerminalNode* PyScriptParser::BitwiseOrExprContext::BITWISE_OR(size_t i) {
  return getToken(PyScriptParser::BITWISE_OR, i);
}

PyScriptParser::BitwiseOrExprContext::BitwiseOrExprContext(BitwiseOrContext *ctx) { copyFrom(ctx); }

void PyScriptParser::BitwiseOrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseOrExpr(this);
}
void PyScriptParser::BitwiseOrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseOrExpr(this);
}

std::any PyScriptParser::BitwiseOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitBitwiseOrExpr(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::BitwiseOrContext* PyScriptParser::bitwiseOr() {
  BitwiseOrContext *_localctx = _tracker.createInstance<BitwiseOrContext>(_ctx, getState());
  enterRule(_localctx, 70, PyScriptParser::RuleBitwiseOr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    _localctx = _tracker.createInstance<PyScriptParser::BitwiseOrExprContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(428);
    bitwiseXor();
    setState(433);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(429);
        match(PyScriptParser::BITWISE_OR);
        setState(430);
        bitwiseXor(); 
      }
      setState(435);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitwiseXorContext ------------------------------------------------------------------

PyScriptParser::BitwiseXorContext::BitwiseXorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::BitwiseXorContext::getRuleIndex() const {
  return PyScriptParser::RuleBitwiseXor;
}

void PyScriptParser::BitwiseXorContext::copyFrom(BitwiseXorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitwiseXorExprContext ------------------------------------------------------------------

std::vector<PyScriptParser::BitwiseAndContext *> PyScriptParser::BitwiseXorExprContext::bitwiseAnd() {
  return getRuleContexts<PyScriptParser::BitwiseAndContext>();
}

PyScriptParser::BitwiseAndContext* PyScriptParser::BitwiseXorExprContext::bitwiseAnd(size_t i) {
  return getRuleContext<PyScriptParser::BitwiseAndContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::BitwiseXorExprContext::BITWISE_XOR() {
  return getTokens(PyScriptParser::BITWISE_XOR);
}

tree::TerminalNode* PyScriptParser::BitwiseXorExprContext::BITWISE_XOR(size_t i) {
  return getToken(PyScriptParser::BITWISE_XOR, i);
}

PyScriptParser::BitwiseXorExprContext::BitwiseXorExprContext(BitwiseXorContext *ctx) { copyFrom(ctx); }

void PyScriptParser::BitwiseXorExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseXorExpr(this);
}
void PyScriptParser::BitwiseXorExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseXorExpr(this);
}

std::any PyScriptParser::BitwiseXorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitBitwiseXorExpr(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::BitwiseXorContext* PyScriptParser::bitwiseXor() {
  BitwiseXorContext *_localctx = _tracker.createInstance<BitwiseXorContext>(_ctx, getState());
  enterRule(_localctx, 72, PyScriptParser::RuleBitwiseXor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    _localctx = _tracker.createInstance<PyScriptParser::BitwiseXorExprContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(436);
    bitwiseAnd();
    setState(441);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(437);
        match(PyScriptParser::BITWISE_XOR);
        setState(438);
        bitwiseAnd(); 
      }
      setState(443);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitwiseAndContext ------------------------------------------------------------------

PyScriptParser::BitwiseAndContext::BitwiseAndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::BitwiseAndContext::getRuleIndex() const {
  return PyScriptParser::RuleBitwiseAnd;
}

void PyScriptParser::BitwiseAndContext::copyFrom(BitwiseAndContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitwiseAndExprContext ------------------------------------------------------------------

std::vector<PyScriptParser::EqualityContext *> PyScriptParser::BitwiseAndExprContext::equality() {
  return getRuleContexts<PyScriptParser::EqualityContext>();
}

PyScriptParser::EqualityContext* PyScriptParser::BitwiseAndExprContext::equality(size_t i) {
  return getRuleContext<PyScriptParser::EqualityContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::BitwiseAndExprContext::BITWISE_AND() {
  return getTokens(PyScriptParser::BITWISE_AND);
}

tree::TerminalNode* PyScriptParser::BitwiseAndExprContext::BITWISE_AND(size_t i) {
  return getToken(PyScriptParser::BITWISE_AND, i);
}

PyScriptParser::BitwiseAndExprContext::BitwiseAndExprContext(BitwiseAndContext *ctx) { copyFrom(ctx); }

void PyScriptParser::BitwiseAndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseAndExpr(this);
}
void PyScriptParser::BitwiseAndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseAndExpr(this);
}

std::any PyScriptParser::BitwiseAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitBitwiseAndExpr(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::BitwiseAndContext* PyScriptParser::bitwiseAnd() {
  BitwiseAndContext *_localctx = _tracker.createInstance<BitwiseAndContext>(_ctx, getState());
  enterRule(_localctx, 74, PyScriptParser::RuleBitwiseAnd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    _localctx = _tracker.createInstance<PyScriptParser::BitwiseAndExprContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(444);
    equality();
    setState(449);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(445);
        match(PyScriptParser::BITWISE_AND);
        setState(446);
        equality(); 
      }
      setState(451);
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
  enterRule(_localctx, 76, PyScriptParser::RuleEquality);
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
    setState(452);
    comparison();
    setState(457);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(453);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::EQ

        || _la == PyScriptParser::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(454);
        comparison(); 
      }
      setState(459);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
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

std::vector<PyScriptParser::ShiftContext *> PyScriptParser::ComparisonContext::shift() {
  return getRuleContexts<PyScriptParser::ShiftContext>();
}

PyScriptParser::ShiftContext* PyScriptParser::ComparisonContext::shift(size_t i) {
  return getRuleContext<PyScriptParser::ShiftContext>(i);
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

std::vector<tree::TerminalNode *> PyScriptParser::ComparisonContext::IN() {
  return getTokens(PyScriptParser::IN);
}

tree::TerminalNode* PyScriptParser::ComparisonContext::IN(size_t i) {
  return getToken(PyScriptParser::IN, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ComparisonContext::NOT_IN() {
  return getTokens(PyScriptParser::NOT_IN);
}

tree::TerminalNode* PyScriptParser::ComparisonContext::NOT_IN(size_t i) {
  return getToken(PyScriptParser::NOT_IN, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ComparisonContext::IS() {
  return getTokens(PyScriptParser::IS);
}

tree::TerminalNode* PyScriptParser::ComparisonContext::IS(size_t i) {
  return getToken(PyScriptParser::IS, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ComparisonContext::IS_NOT() {
  return getTokens(PyScriptParser::IS_NOT);
}

tree::TerminalNode* PyScriptParser::ComparisonContext::IS_NOT(size_t i) {
  return getToken(PyScriptParser::IS_NOT, i);
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
  enterRule(_localctx, 78, PyScriptParser::RuleComparison);
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
    setState(460);
    shift();
    setState(465);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(461);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::IN)
          | (1ULL << PyScriptParser::IS)
          | (1ULL << PyScriptParser::IS_NOT)
          | (1ULL << PyScriptParser::NOT_IN)
          | (1ULL << PyScriptParser::LT)
          | (1ULL << PyScriptParser::LE)
          | (1ULL << PyScriptParser::GT)
          | (1ULL << PyScriptParser::GE))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(462);
        shift(); 
      }
      setState(467);
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

//----------------- ShiftContext ------------------------------------------------------------------

PyScriptParser::ShiftContext::ShiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::ShiftContext::getRuleIndex() const {
  return PyScriptParser::RuleShift;
}

void PyScriptParser::ShiftContext::copyFrom(ShiftContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ShiftExprContext ------------------------------------------------------------------

std::vector<PyScriptParser::AdditiveContext *> PyScriptParser::ShiftExprContext::additive() {
  return getRuleContexts<PyScriptParser::AdditiveContext>();
}

PyScriptParser::AdditiveContext* PyScriptParser::ShiftExprContext::additive(size_t i) {
  return getRuleContext<PyScriptParser::AdditiveContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ShiftExprContext::LEFT_SHIFT() {
  return getTokens(PyScriptParser::LEFT_SHIFT);
}

tree::TerminalNode* PyScriptParser::ShiftExprContext::LEFT_SHIFT(size_t i) {
  return getToken(PyScriptParser::LEFT_SHIFT, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::ShiftExprContext::RIGHT_SHIFT() {
  return getTokens(PyScriptParser::RIGHT_SHIFT);
}

tree::TerminalNode* PyScriptParser::ShiftExprContext::RIGHT_SHIFT(size_t i) {
  return getToken(PyScriptParser::RIGHT_SHIFT, i);
}

PyScriptParser::ShiftExprContext::ShiftExprContext(ShiftContext *ctx) { copyFrom(ctx); }

void PyScriptParser::ShiftExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftExpr(this);
}
void PyScriptParser::ShiftExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftExpr(this);
}

std::any PyScriptParser::ShiftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitShiftExpr(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::ShiftContext* PyScriptParser::shift() {
  ShiftContext *_localctx = _tracker.createInstance<ShiftContext>(_ctx, getState());
  enterRule(_localctx, 80, PyScriptParser::RuleShift);
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
    _localctx = _tracker.createInstance<PyScriptParser::ShiftExprContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(468);
    additive();
    setState(473);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(469);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::LEFT_SHIFT

        || _la == PyScriptParser::RIGHT_SHIFT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(470);
        additive(); 
      }
      setState(475);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
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
  enterRule(_localctx, 82, PyScriptParser::RuleAdditive);
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
    setState(476);
    multiplicative();
    setState(481);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(477);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::PLUS

        || _la == PyScriptParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(478);
        multiplicative(); 
      }
      setState(483);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
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

std::vector<tree::TerminalNode *> PyScriptParser::MultiplicativeContext::FLOOR_DIV() {
  return getTokens(PyScriptParser::FLOOR_DIV);
}

tree::TerminalNode* PyScriptParser::MultiplicativeContext::FLOOR_DIV(size_t i) {
  return getToken(PyScriptParser::FLOOR_DIV, i);
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
  enterRule(_localctx, 84, PyScriptParser::RuleMultiplicative);
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
    setState(484);
    power();
    setState(489);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(485);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::MUL)
          | (1ULL << PyScriptParser::DIV)
          | (1ULL << PyScriptParser::FLOOR_DIV)
          | (1ULL << PyScriptParser::MOD))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(486);
        power(); 
      }
      setState(491);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
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
  enterRule(_localctx, 86, PyScriptParser::RulePower);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(492);
    unary();
    setState(495);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(493);
      match(PyScriptParser::DOUBLE_STAR);
      setState(494);
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

tree::TerminalNode* PyScriptParser::UnaryContext::BITWISE_NOT() {
  return getToken(PyScriptParser::BITWISE_NOT, 0);
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
  enterRule(_localctx, 88, PyScriptParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(502);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(498);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS)
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0)) {
        setState(497);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::NOT)
          | (1ULL << PyScriptParser::PLUS)
          | (1ULL << PyScriptParser::MINUS)
          | (1ULL << PyScriptParser::BITWISE_NOT))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(500);
      atom();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(501);
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

PyScriptParser::TupleLiteralContext* PyScriptParser::PrimaryContext::tupleLiteral() {
  return getRuleContext<PyScriptParser::TupleLiteralContext>(0);
}

tree::TerminalNode* PyScriptParser::PrimaryContext::RPAREN() {
  return getToken(PyScriptParser::RPAREN, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::PrimaryContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
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
  enterRule(_localctx, 90, PyScriptParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(521);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(504);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(505);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(506);
      match(PyScriptParser::LPAREN);
      setState(507);
      tupleLiteral();
      setState(508);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(510);
      match(PyScriptParser::LPAREN);
      setState(511);
      expression();
      setState(512);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(514);
      listLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(515);
      dictLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(516);
      setLiteral();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(517);
      generatorExpression();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(518);
      newExpression();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(519);
      lambdaExpression();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(520);
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

//----------------- TupleLiteralContext ------------------------------------------------------------------

PyScriptParser::TupleLiteralContext::TupleLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::TupleLiteralContext::getRuleIndex() const {
  return PyScriptParser::RuleTupleLiteral;
}

void PyScriptParser::TupleLiteralContext::copyFrom(TupleLiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultiElementTupleContext ------------------------------------------------------------------

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::MultiElementTupleContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::MultiElementTupleContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::MultiElementTupleContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::MultiElementTupleContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}

PyScriptParser::MultiElementTupleContext::MultiElementTupleContext(TupleLiteralContext *ctx) { copyFrom(ctx); }

void PyScriptParser::MultiElementTupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiElementTuple(this);
}
void PyScriptParser::MultiElementTupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiElementTuple(this);
}

std::any PyScriptParser::MultiElementTupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitMultiElementTuple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SingleElementTupleContext ------------------------------------------------------------------

PyScriptParser::ExpressionContext* PyScriptParser::SingleElementTupleContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::SingleElementTupleContext::COMMA() {
  return getToken(PyScriptParser::COMMA, 0);
}

PyScriptParser::SingleElementTupleContext::SingleElementTupleContext(TupleLiteralContext *ctx) { copyFrom(ctx); }

void PyScriptParser::SingleElementTupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleElementTuple(this);
}
void PyScriptParser::SingleElementTupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleElementTuple(this);
}

std::any PyScriptParser::SingleElementTupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSingleElementTuple(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::TupleLiteralContext* PyScriptParser::tupleLiteral() {
  TupleLiteralContext *_localctx = _tracker.createInstance<TupleLiteralContext>(_ctx, getState());
  enterRule(_localctx, 92, PyScriptParser::RuleTupleLiteral);
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
    setState(542);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PyScriptParser::MultiElementTupleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(523);
      expression();
      setState(524);
      match(PyScriptParser::COMMA);
      setState(530);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(525);
          expression();
          setState(526);
          match(PyScriptParser::COMMA); 
        }
        setState(532);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      }
      setState(534);
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
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
        | (1ULL << (PyScriptParser::LBRACK - 66))
        | (1ULL << (PyScriptParser::LBRACE - 66))
        | (1ULL << (PyScriptParser::IDENTIFIER - 66))
        | (1ULL << (PyScriptParser::INTEGER - 66))
        | (1ULL << (PyScriptParser::FLOAT - 66))
        | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
        setState(533);
        expression();
      }
      setState(537);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(536);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PyScriptParser::SingleElementTupleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(539);
      expression();
      setState(540);
      match(PyScriptParser::COMMA);
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
  enterRule(_localctx, 94, PyScriptParser::RuleNewExpression);
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
    match(PyScriptParser::NEW);
    setState(545);
    dottedName();
    setState(546);
    match(PyScriptParser::LPAREN);
    setState(548);
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
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
      | (1ULL << (PyScriptParser::LBRACK - 66))
      | (1ULL << (PyScriptParser::LBRACE - 66))
      | (1ULL << (PyScriptParser::DOUBLE_STAR - 66))
      | (1ULL << (PyScriptParser::IDENTIFIER - 66))
      | (1ULL << (PyScriptParser::INTEGER - 66))
      | (1ULL << (PyScriptParser::FLOAT - 66))
      | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
      setState(547);
      argumentList();
    }
    setState(550);
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
  enterRule(_localctx, 96, PyScriptParser::RuleAtom);

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
    setState(552);
    primary();
    setState(556);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(553);
        postfixOp(); 
      }
      setState(558);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
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
  enterRule(_localctx, 98, PyScriptParser::RulePostfixOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(570);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DOT: {
        _localctx = _tracker.createInstance<PyScriptParser::AttributeAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(559);
        match(PyScriptParser::DOT);
        setState(560);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::LBRACK: {
        _localctx = _tracker.createInstance<PyScriptParser::SubscriptAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(561);
        match(PyScriptParser::LBRACK);
        setState(562);
        subscriptArg();
        setState(563);
        match(PyScriptParser::RBRACK);
        break;
      }

      case PyScriptParser::LPAREN: {
        _localctx = _tracker.createInstance<PyScriptParser::FunctionCallOpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(565);
        match(PyScriptParser::LPAREN);
        setState(567);
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
          | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
          | (1ULL << (PyScriptParser::LBRACK - 66))
          | (1ULL << (PyScriptParser::LBRACE - 66))
          | (1ULL << (PyScriptParser::DOUBLE_STAR - 66))
          | (1ULL << (PyScriptParser::IDENTIFIER - 66))
          | (1ULL << (PyScriptParser::INTEGER - 66))
          | (1ULL << (PyScriptParser::FLOAT - 66))
          | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
          setState(566);
          argumentList();
        }
        setState(569);
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
  enterRule(_localctx, 100, PyScriptParser::RuleSubscriptArg);
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
    setState(573);
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
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
      | (1ULL << (PyScriptParser::LBRACK - 66))
      | (1ULL << (PyScriptParser::LBRACE - 66))
      | (1ULL << (PyScriptParser::IDENTIFIER - 66))
      | (1ULL << (PyScriptParser::INTEGER - 66))
      | (1ULL << (PyScriptParser::FLOAT - 66))
      | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
      setState(572);
      expression();
    }
    setState(585);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COLON) {
      setState(575);
      match(PyScriptParser::COLON);
      setState(577);
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
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
        | (1ULL << (PyScriptParser::LBRACK - 66))
        | (1ULL << (PyScriptParser::LBRACE - 66))
        | (1ULL << (PyScriptParser::IDENTIFIER - 66))
        | (1ULL << (PyScriptParser::INTEGER - 66))
        | (1ULL << (PyScriptParser::FLOAT - 66))
        | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
        setState(576);
        expression();
      }
      setState(583);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COLON) {
        setState(579);
        match(PyScriptParser::COLON);
        setState(581);
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
          | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
          | (1ULL << (PyScriptParser::LBRACK - 66))
          | (1ULL << (PyScriptParser::LBRACE - 66))
          | (1ULL << (PyScriptParser::IDENTIFIER - 66))
          | (1ULL << (PyScriptParser::INTEGER - 66))
          | (1ULL << (PyScriptParser::FLOAT - 66))
          | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
          setState(580);
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
  enterRule(_localctx, 102, PyScriptParser::RuleArgumentList);
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
    setState(587);
    argument();
    setState(592);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(588);
        match(PyScriptParser::COMMA);
        setState(589);
        argument(); 
      }
      setState(594);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    }
    setState(596);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(595);
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
  enterRule(_localctx, 104, PyScriptParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(606);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(598);
      match(PyScriptParser::IDENTIFIER);
      setState(599);
      match(PyScriptParser::ASSIGN);
      setState(600);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(601);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(602);
      match(PyScriptParser::MUL);
      setState(603);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(604);
      match(PyScriptParser::DOUBLE_STAR);
      setState(605);
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
  enterRule(_localctx, 106, PyScriptParser::RuleListLiteral);
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
    setState(608);
    match(PyScriptParser::LBRACK);
    setState(610);
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
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
      | (1ULL << (PyScriptParser::LBRACK - 66))
      | (1ULL << (PyScriptParser::LBRACE - 66))
      | (1ULL << (PyScriptParser::IDENTIFIER - 66))
      | (1ULL << (PyScriptParser::INTEGER - 66))
      | (1ULL << (PyScriptParser::FLOAT - 66))
      | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
      setState(609);
      listElements();
    }
    setState(612);
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

PyScriptParser::ComprehensionContext* PyScriptParser::ListElementsContext::comprehension() {
  return getRuleContext<PyScriptParser::ComprehensionContext>(0);
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
  enterRule(_localctx, 108, PyScriptParser::RuleListElements);
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
    setState(626);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(614);
      expression();
      setState(619);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(615);
          match(PyScriptParser::COMMA);
          setState(616);
          expression(); 
        }
        setState(621);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      }
      setState(623);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(622);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(625);
      comprehension();
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

//----------------- ComprehensionContext ------------------------------------------------------------------

PyScriptParser::ComprehensionContext::ComprehensionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::ExpressionContext* PyScriptParser::ComprehensionContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

std::vector<PyScriptParser::CompForContext *> PyScriptParser::ComprehensionContext::compFor() {
  return getRuleContexts<PyScriptParser::CompForContext>();
}

PyScriptParser::CompForContext* PyScriptParser::ComprehensionContext::compFor(size_t i) {
  return getRuleContext<PyScriptParser::CompForContext>(i);
}


size_t PyScriptParser::ComprehensionContext::getRuleIndex() const {
  return PyScriptParser::RuleComprehension;
}

void PyScriptParser::ComprehensionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComprehension(this);
}

void PyScriptParser::ComprehensionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComprehension(this);
}


std::any PyScriptParser::ComprehensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitComprehension(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ComprehensionContext* PyScriptParser::comprehension() {
  ComprehensionContext *_localctx = _tracker.createInstance<ComprehensionContext>(_ctx, getState());
  enterRule(_localctx, 110, PyScriptParser::RuleComprehension);
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
    setState(628);
    expression();
    setState(630); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(629);
      compFor();
      setState(632); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PyScriptParser::FOR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompForContext ------------------------------------------------------------------

PyScriptParser::CompForContext::CompForContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::CompForContext::FOR() {
  return getToken(PyScriptParser::FOR, 0);
}

tree::TerminalNode* PyScriptParser::CompForContext::IN() {
  return getToken(PyScriptParser::IN, 0);
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::CompForContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::CompForContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::CompForContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::TupleLiteralContext* PyScriptParser::CompForContext::tupleLiteral() {
  return getRuleContext<PyScriptParser::TupleLiteralContext>(0);
}

tree::TerminalNode* PyScriptParser::CompForContext::IF() {
  return getToken(PyScriptParser::IF, 0);
}


size_t PyScriptParser::CompForContext::getRuleIndex() const {
  return PyScriptParser::RuleCompFor;
}

void PyScriptParser::CompForContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompFor(this);
}

void PyScriptParser::CompForContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompFor(this);
}


std::any PyScriptParser::CompForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitCompFor(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::CompForContext* PyScriptParser::compFor() {
  CompForContext *_localctx = _tracker.createInstance<CompForContext>(_ctx, getState());
  enterRule(_localctx, 112, PyScriptParser::RuleCompFor);
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
    setState(634);
    match(PyScriptParser::FOR);
    setState(637);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(635);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 2: {
      setState(636);
      tupleLiteral();
      break;
    }

    default:
      break;
    }
    setState(639);
    match(PyScriptParser::IN);
    setState(640);
    expression();
    setState(643);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IF) {
      setState(641);
      match(PyScriptParser::IF);
      setState(642);
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
  enterRule(_localctx, 114, PyScriptParser::RuleDictLiteral);
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
    setState(645);
    match(PyScriptParser::LBRACE);
    setState(660);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      setState(646);
      dictComprehension();
      break;
    }

    case 2: {
      setState(658);
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
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
        | (1ULL << (PyScriptParser::LBRACK - 66))
        | (1ULL << (PyScriptParser::LBRACE - 66))
        | (1ULL << (PyScriptParser::DOUBLE_STAR - 66))
        | (1ULL << (PyScriptParser::IDENTIFIER - 66))
        | (1ULL << (PyScriptParser::INTEGER - 66))
        | (1ULL << (PyScriptParser::FLOAT - 66))
        | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
        setState(647);
        dictItem();
        setState(652);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(648);
            match(PyScriptParser::COMMA);
            setState(649);
            dictItem(); 
          }
          setState(654);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
        }
        setState(656);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::COMMA) {
          setState(655);
          match(PyScriptParser::COMMA);
        }
      }
      break;
    }

    default:
      break;
    }
    setState(662);
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

std::vector<PyScriptParser::CompForContext *> PyScriptParser::DictComprehensionContext::compFor() {
  return getRuleContexts<PyScriptParser::CompForContext>();
}

PyScriptParser::CompForContext* PyScriptParser::DictComprehensionContext::compFor(size_t i) {
  return getRuleContext<PyScriptParser::CompForContext>(i);
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
  enterRule(_localctx, 116, PyScriptParser::RuleDictComprehension);
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
    setState(664);
    expression();
    setState(665);
    match(PyScriptParser::COLON);
    setState(666);
    expression();
    setState(668); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(667);
      compFor();
      setState(670); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PyScriptParser::FOR);
   
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
  enterRule(_localctx, 118, PyScriptParser::RuleDictItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(678);
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
      case PyScriptParser::BITWISE_NOT:
      case PyScriptParser::LPAREN:
      case PyScriptParser::LBRACK:
      case PyScriptParser::LBRACE:
      case PyScriptParser::IDENTIFIER:
      case PyScriptParser::INTEGER:
      case PyScriptParser::FLOAT:
      case PyScriptParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(672);
        expression();
        setState(673);
        match(PyScriptParser::COLON);
        setState(674);
        expression();
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 2);
        setState(676);
        match(PyScriptParser::DOUBLE_STAR);
        setState(677);
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
  enterRule(_localctx, 120, PyScriptParser::RuleSetLiteral);
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
    setState(680);
    match(PyScriptParser::LBRACE);
    setState(682);
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
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (PyScriptParser::LPAREN - 66))
      | (1ULL << (PyScriptParser::LBRACK - 66))
      | (1ULL << (PyScriptParser::LBRACE - 66))
      | (1ULL << (PyScriptParser::IDENTIFIER - 66))
      | (1ULL << (PyScriptParser::INTEGER - 66))
      | (1ULL << (PyScriptParser::FLOAT - 66))
      | (1ULL << (PyScriptParser::STRING - 66)))) != 0)) {
      setState(681);
      setElements();
    }
    setState(684);
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

PyScriptParser::ComprehensionContext* PyScriptParser::SetElementsContext::comprehension() {
  return getRuleContext<PyScriptParser::ComprehensionContext>(0);
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
  enterRule(_localctx, 122, PyScriptParser::RuleSetElements);
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
    setState(698);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(686);
      expression();
      setState(691);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(687);
          match(PyScriptParser::COMMA);
          setState(688);
          expression(); 
        }
        setState(693);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      }
      setState(695);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(694);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(697);
      comprehension();
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

PyScriptParser::ComprehensionContext* PyScriptParser::GeneratorExpressionContext::comprehension() {
  return getRuleContext<PyScriptParser::ComprehensionContext>(0);
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
  enterRule(_localctx, 124, PyScriptParser::RuleGeneratorExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    match(PyScriptParser::LPAREN);
    setState(701);
    comprehension();
    setState(702);
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
  enterRule(_localctx, 126, PyScriptParser::RuleLiteral);
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
    setState(704);
    _la = _input->LA(1);
    if (!(((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & ((1ULL << (PyScriptParser::TRUE - 25))
      | (1ULL << (PyScriptParser::FALSE - 25))
      | (1ULL << (PyScriptParser::NONE - 25))
      | (1ULL << (PyScriptParser::INTEGER - 25))
      | (1ULL << (PyScriptParser::FLOAT - 25))
      | (1ULL << (PyScriptParser::STRING - 25)))) != 0))) {
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
  enterRule(_localctx, 128, PyScriptParser::RuleLambdaExpression);
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
    setState(706);
    match(PyScriptParser::LAMBDA);
    setState(708);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 36) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 36)) & ((1ULL << (PyScriptParser::MUL - 36))
      | (1ULL << (PyScriptParser::DOUBLE_STAR - 36))
      | (1ULL << (PyScriptParser::IDENTIFIER - 36)))) != 0)) {
      setState(707);
      parameterList();
    }
    setState(710);
    match(PyScriptParser::COLON);
    setState(711);
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
  enterRule(_localctx, 130, PyScriptParser::RuleDottedName);
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
    setState(713);
    match(PyScriptParser::IDENTIFIER);
    setState(718);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::DOT) {
      setState(714);
      match(PyScriptParser::DOT);
      setState(715);
      match(PyScriptParser::IDENTIFIER);
      setState(720);
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
