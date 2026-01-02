
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
      "assignment", "expressionStatement", "expression", "conditionalExpression", 
      "logicalOr", "logicalAnd", "bitwiseOr", "bitwiseXor", "bitwiseAnd", 
      "equality", "comparison", "shift", "additive", "multiplicative", "power", 
      "unary", "primary", "tupleLiteral", "newExpression", "atom", "postfixOp", 
      "attributeAccess", "subscriptAccess", "subscriptArg", "functionCall", 
      "argumentList", "argument", "listLiteral", "listElements", "comprehension", 
      "compFor", "dictLiteral", "dictComprehension", "dictItem", "setLiteral", 
      "setElements", "generatorExpression", "literal", "lambdaExpression", 
      "dottedName"
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
  	4,1,84,728,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,1,0,5,0,138,8,0,10,0,12,0,
  	141,9,0,1,0,1,0,1,1,1,1,3,1,147,8,1,1,2,1,2,1,2,5,2,152,8,2,10,2,12,2,
  	155,9,2,1,2,3,2,158,8,2,1,2,3,2,161,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,
  	3,170,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,183,8,4,1,5,
  	1,5,1,5,1,5,5,5,189,8,5,10,5,12,5,192,9,5,1,5,1,5,1,5,3,5,197,8,5,1,5,
  	1,5,1,5,3,5,202,8,5,1,6,1,6,1,6,1,6,3,6,208,8,6,3,6,210,8,6,1,6,1,6,1,
  	6,1,7,1,7,1,7,1,7,5,7,219,8,7,10,7,12,7,222,9,7,1,7,1,7,1,7,1,8,1,8,1,
  	8,3,8,230,8,8,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,
  	1,13,1,13,1,13,1,13,1,13,1,13,5,13,250,8,13,10,13,12,13,253,9,13,1,13,
  	3,13,256,8,13,1,13,1,13,3,13,260,8,13,1,13,3,13,263,8,13,1,13,1,13,1,
  	13,1,14,1,14,1,14,3,14,271,8,14,1,15,4,15,274,8,15,11,15,12,15,275,1,
  	16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,4,17,286,8,17,11,17,12,17,287,1,
  	17,1,17,3,17,292,8,17,1,18,1,18,1,18,1,18,3,18,298,8,18,1,18,1,18,1,18,
  	1,18,1,19,1,19,1,19,5,19,307,8,19,10,19,12,19,310,9,19,1,19,3,19,313,
  	8,19,1,20,1,20,1,20,3,20,318,8,20,1,20,1,20,3,20,322,8,20,1,20,1,20,3,
  	20,326,8,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,5,21,337,8,21,
  	10,21,12,21,340,9,21,1,21,1,21,1,21,3,21,345,8,21,1,22,1,22,1,22,1,22,
  	1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,25,1,25,3,25,363,
  	8,25,1,26,1,26,1,26,1,26,3,26,369,8,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	5,26,377,8,26,10,26,12,26,380,9,26,3,26,382,8,26,1,27,1,27,1,27,3,27,
  	387,8,27,1,28,1,28,1,28,3,28,392,8,28,1,28,1,28,1,28,1,29,1,29,1,30,1,
  	30,1,31,1,31,1,31,1,31,1,31,1,31,3,31,407,8,31,1,32,1,32,1,32,5,32,412,
  	8,32,10,32,12,32,415,9,32,1,33,1,33,1,33,5,33,420,8,33,10,33,12,33,423,
  	9,33,1,34,1,34,1,34,5,34,428,8,34,10,34,12,34,431,9,34,1,35,1,35,1,35,
  	5,35,436,8,35,10,35,12,35,439,9,35,1,36,1,36,1,36,5,36,444,8,36,10,36,
  	12,36,447,9,36,1,37,1,37,1,37,5,37,452,8,37,10,37,12,37,455,9,37,1,38,
  	1,38,1,38,5,38,460,8,38,10,38,12,38,463,9,38,1,39,1,39,1,39,5,39,468,
  	8,39,10,39,12,39,471,9,39,1,40,1,40,1,40,5,40,476,8,40,10,40,12,40,479,
  	9,40,1,41,1,41,1,41,5,41,484,8,41,10,41,12,41,487,9,41,1,42,1,42,1,42,
  	3,42,492,8,42,1,43,3,43,495,8,43,1,43,1,43,3,43,499,8,43,1,44,1,44,1,
  	44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,
  	44,3,44,518,8,44,1,45,1,45,1,45,5,45,523,8,45,10,45,12,45,526,9,45,1,
  	45,3,45,529,8,45,1,46,1,46,1,46,1,46,3,46,535,8,46,1,46,1,46,1,47,1,47,
  	5,47,541,8,47,10,47,12,47,544,9,47,1,48,1,48,1,48,1,48,1,48,1,48,1,48,
  	1,48,3,48,554,8,48,1,48,3,48,557,8,48,1,49,1,49,1,49,1,49,1,50,1,50,1,
  	50,1,50,1,50,1,51,3,51,569,8,51,1,51,1,51,3,51,573,8,51,1,51,1,51,3,51,
  	577,8,51,3,51,579,8,51,3,51,581,8,51,1,52,1,52,1,52,3,52,586,8,52,1,52,
  	1,52,1,53,1,53,1,53,5,53,593,8,53,10,53,12,53,596,9,53,1,53,3,53,599,
  	8,53,1,54,1,54,1,54,1,54,1,54,1,54,1,54,1,54,3,54,609,8,54,1,55,1,55,
  	3,55,613,8,55,1,55,1,55,1,56,1,56,1,56,5,56,620,8,56,10,56,12,56,623,
  	9,56,1,56,3,56,626,8,56,1,56,3,56,629,8,56,1,57,1,57,4,57,633,8,57,11,
  	57,12,57,634,1,58,1,58,1,58,1,58,5,58,641,8,58,10,58,12,58,644,9,58,1,
  	58,1,58,1,58,1,58,3,58,650,8,58,1,59,1,59,1,59,1,59,1,59,5,59,657,8,59,
  	10,59,12,59,660,9,59,1,59,3,59,663,8,59,3,59,665,8,59,3,59,667,8,59,1,
  	59,1,59,1,60,1,60,1,60,1,60,4,60,675,8,60,11,60,12,60,676,1,61,1,61,1,
  	61,1,61,1,61,1,61,3,61,685,8,61,1,62,1,62,3,62,689,8,62,1,62,1,62,1,63,
  	1,63,1,63,5,63,696,8,63,10,63,12,63,699,9,63,1,63,3,63,702,8,63,1,63,
  	3,63,705,8,63,1,64,1,64,1,64,1,64,1,65,1,65,1,66,1,66,3,66,715,8,66,1,
  	66,1,66,1,66,1,67,1,67,1,67,5,67,723,8,67,10,67,12,67,726,9,67,1,67,0,
  	0,68,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,
  	92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,
  	130,132,134,0,8,1,0,52,64,1,0,40,41,3,0,11,11,31,33,42,45,1,0,46,47,1,
  	0,34,35,1,0,36,39,3,0,30,30,34,35,51,51,2,0,25,27,78,80,772,0,139,1,0,
  	0,0,2,146,1,0,0,0,4,148,1,0,0,0,6,169,1,0,0,0,8,182,1,0,0,0,10,184,1,
  	0,0,0,12,203,1,0,0,0,14,214,1,0,0,0,16,226,1,0,0,0,18,231,1,0,0,0,20,
  	234,1,0,0,0,22,237,1,0,0,0,24,240,1,0,0,0,26,243,1,0,0,0,28,267,1,0,0,
  	0,30,273,1,0,0,0,32,277,1,0,0,0,34,291,1,0,0,0,36,293,1,0,0,0,38,303,
  	1,0,0,0,40,325,1,0,0,0,42,327,1,0,0,0,44,346,1,0,0,0,46,351,1,0,0,0,48,
  	358,1,0,0,0,50,360,1,0,0,0,52,381,1,0,0,0,54,383,1,0,0,0,56,391,1,0,0,
  	0,58,396,1,0,0,0,60,398,1,0,0,0,62,400,1,0,0,0,64,408,1,0,0,0,66,416,
  	1,0,0,0,68,424,1,0,0,0,70,432,1,0,0,0,72,440,1,0,0,0,74,448,1,0,0,0,76,
  	456,1,0,0,0,78,464,1,0,0,0,80,472,1,0,0,0,82,480,1,0,0,0,84,488,1,0,0,
  	0,86,498,1,0,0,0,88,517,1,0,0,0,90,519,1,0,0,0,92,530,1,0,0,0,94,538,
  	1,0,0,0,96,556,1,0,0,0,98,558,1,0,0,0,100,562,1,0,0,0,102,568,1,0,0,0,
  	104,582,1,0,0,0,106,589,1,0,0,0,108,608,1,0,0,0,110,610,1,0,0,0,112,628,
  	1,0,0,0,114,630,1,0,0,0,116,636,1,0,0,0,118,651,1,0,0,0,120,670,1,0,0,
  	0,122,684,1,0,0,0,124,686,1,0,0,0,126,704,1,0,0,0,128,706,1,0,0,0,130,
  	710,1,0,0,0,132,712,1,0,0,0,134,719,1,0,0,0,136,138,3,2,1,0,137,136,1,
  	0,0,0,138,141,1,0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,142,1,0,0,0,
  	141,139,1,0,0,0,142,143,5,0,0,1,143,1,1,0,0,0,144,147,3,4,2,0,145,147,
  	3,8,4,0,146,144,1,0,0,0,146,145,1,0,0,0,147,3,1,0,0,0,148,153,3,6,3,0,
  	149,150,5,65,0,0,150,152,3,6,3,0,151,149,1,0,0,0,152,155,1,0,0,0,153,
  	151,1,0,0,0,153,154,1,0,0,0,154,157,1,0,0,0,155,153,1,0,0,0,156,158,5,
  	65,0,0,157,156,1,0,0,0,157,158,1,0,0,0,158,160,1,0,0,0,159,161,5,76,0,
  	0,160,159,1,0,0,0,160,161,1,0,0,0,161,5,1,0,0,0,162,170,3,56,28,0,163,
  	170,3,50,25,0,164,170,3,58,29,0,165,170,3,52,26,0,166,170,3,48,24,0,167,
  	170,5,13,0,0,168,170,5,14,0,0,169,162,1,0,0,0,169,163,1,0,0,0,169,164,
  	1,0,0,0,169,165,1,0,0,0,169,166,1,0,0,0,169,167,1,0,0,0,169,168,1,0,0,
  	0,170,7,1,0,0,0,171,183,3,28,14,0,172,183,3,36,18,0,173,183,3,18,9,0,
  	174,183,3,26,13,0,175,183,3,42,21,0,176,183,3,44,22,0,177,183,3,46,23,
  	0,178,183,3,20,10,0,179,183,3,10,5,0,180,183,3,14,7,0,181,183,3,22,11,
  	0,182,171,1,0,0,0,182,172,1,0,0,0,182,173,1,0,0,0,182,174,1,0,0,0,182,
  	175,1,0,0,0,182,176,1,0,0,0,182,177,1,0,0,0,182,178,1,0,0,0,182,179,1,
  	0,0,0,182,180,1,0,0,0,182,181,1,0,0,0,183,9,1,0,0,0,184,185,5,17,0,0,
  	185,186,5,73,0,0,186,190,3,34,17,0,187,189,3,12,6,0,188,187,1,0,0,0,189,
  	192,1,0,0,0,190,188,1,0,0,0,190,191,1,0,0,0,191,196,1,0,0,0,192,190,1,
  	0,0,0,193,194,5,3,0,0,194,195,5,73,0,0,195,197,3,34,17,0,196,193,1,0,
  	0,0,196,197,1,0,0,0,197,201,1,0,0,0,198,199,5,19,0,0,199,200,5,73,0,0,
  	200,202,3,34,17,0,201,198,1,0,0,0,201,202,1,0,0,0,202,11,1,0,0,0,203,
  	209,5,18,0,0,204,207,3,134,67,0,205,206,5,10,0,0,206,208,5,77,0,0,207,
  	205,1,0,0,0,207,208,1,0,0,0,208,210,1,0,0,0,209,204,1,0,0,0,209,210,1,
  	0,0,0,210,211,1,0,0,0,211,212,5,73,0,0,212,213,3,34,17,0,213,13,1,0,0,
  	0,214,215,5,20,0,0,215,220,3,16,8,0,216,217,5,72,0,0,217,219,3,16,8,0,
  	218,216,1,0,0,0,219,222,1,0,0,0,220,218,1,0,0,0,220,221,1,0,0,0,221,223,
  	1,0,0,0,222,220,1,0,0,0,223,224,5,73,0,0,224,225,3,34,17,0,225,15,1,0,
  	0,0,226,229,3,60,30,0,227,228,5,10,0,0,228,230,5,77,0,0,229,227,1,0,0,
  	0,229,230,1,0,0,0,230,17,1,0,0,0,231,232,5,21,0,0,232,233,3,36,18,0,233,
  	19,1,0,0,0,234,235,5,21,0,0,235,236,3,46,23,0,236,21,1,0,0,0,237,238,
  	5,21,0,0,238,239,3,14,7,0,239,23,1,0,0,0,240,241,5,22,0,0,241,242,3,60,
  	30,0,242,25,1,0,0,0,243,244,5,23,0,0,244,259,5,77,0,0,245,246,5,66,0,
  	0,246,251,3,60,30,0,247,248,5,72,0,0,248,250,3,60,30,0,249,247,1,0,0,
  	0,250,253,1,0,0,0,251,249,1,0,0,0,251,252,1,0,0,0,252,255,1,0,0,0,253,
  	251,1,0,0,0,254,256,5,72,0,0,255,254,1,0,0,0,255,256,1,0,0,0,256,257,
  	1,0,0,0,257,258,5,67,0,0,258,260,1,0,0,0,259,245,1,0,0,0,259,260,1,0,
  	0,0,260,262,1,0,0,0,261,263,3,30,15,0,262,261,1,0,0,0,262,263,1,0,0,0,
  	263,264,1,0,0,0,264,265,5,73,0,0,265,266,3,34,17,0,266,27,1,0,0,0,267,
  	270,3,30,15,0,268,271,3,36,18,0,269,271,3,26,13,0,270,268,1,0,0,0,270,
  	269,1,0,0,0,271,29,1,0,0,0,272,274,3,32,16,0,273,272,1,0,0,0,274,275,
  	1,0,0,0,275,273,1,0,0,0,275,276,1,0,0,0,276,31,1,0,0,0,277,278,5,24,0,
  	0,278,279,3,60,30,0,279,280,5,76,0,0,280,33,1,0,0,0,281,292,3,4,2,0,282,
  	283,5,76,0,0,283,285,5,83,0,0,284,286,3,2,1,0,285,284,1,0,0,0,286,287,
  	1,0,0,0,287,285,1,0,0,0,287,288,1,0,0,0,288,289,1,0,0,0,289,290,5,84,
  	0,0,290,292,1,0,0,0,291,281,1,0,0,0,291,282,1,0,0,0,292,35,1,0,0,0,293,
  	294,5,1,0,0,294,295,5,77,0,0,295,297,5,66,0,0,296,298,3,38,19,0,297,296,
  	1,0,0,0,297,298,1,0,0,0,298,299,1,0,0,0,299,300,5,67,0,0,300,301,5,73,
  	0,0,301,302,3,34,17,0,302,37,1,0,0,0,303,308,3,40,20,0,304,305,5,72,0,
  	0,305,307,3,40,20,0,306,304,1,0,0,0,307,310,1,0,0,0,308,306,1,0,0,0,308,
  	309,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,311,313,5,72,0,0,312,311,
  	1,0,0,0,312,313,1,0,0,0,313,39,1,0,0,0,314,317,5,77,0,0,315,316,5,52,
  	0,0,316,318,3,60,30,0,317,315,1,0,0,0,317,318,1,0,0,0,318,326,1,0,0,0,
  	319,321,5,36,0,0,320,322,5,77,0,0,321,320,1,0,0,0,321,322,1,0,0,0,322,
  	326,1,0,0,0,323,324,5,75,0,0,324,326,5,77,0,0,325,314,1,0,0,0,325,319,
  	1,0,0,0,325,323,1,0,0,0,326,41,1,0,0,0,327,328,5,2,0,0,328,329,3,60,30,
  	0,329,330,5,73,0,0,330,338,3,34,17,0,331,332,5,4,0,0,332,333,3,60,30,
  	0,333,334,5,73,0,0,334,335,3,34,17,0,335,337,1,0,0,0,336,331,1,0,0,0,
  	337,340,1,0,0,0,338,336,1,0,0,0,338,339,1,0,0,0,339,344,1,0,0,0,340,338,
  	1,0,0,0,341,342,5,3,0,0,342,343,5,73,0,0,343,345,3,34,17,0,344,341,1,
  	0,0,0,344,345,1,0,0,0,345,43,1,0,0,0,346,347,5,6,0,0,347,348,3,60,30,
  	0,348,349,5,73,0,0,349,350,3,34,17,0,350,45,1,0,0,0,351,352,5,5,0,0,352,
  	353,5,77,0,0,353,354,5,11,0,0,354,355,3,60,30,0,355,356,5,73,0,0,356,
  	357,3,34,17,0,357,47,1,0,0,0,358,359,5,12,0,0,359,49,1,0,0,0,360,362,
  	5,7,0,0,361,363,3,60,30,0,362,361,1,0,0,0,362,363,1,0,0,0,363,51,1,0,
  	0,0,364,365,5,8,0,0,365,368,3,134,67,0,366,367,5,10,0,0,367,369,5,77,
  	0,0,368,366,1,0,0,0,368,369,1,0,0,0,369,382,1,0,0,0,370,371,5,9,0,0,371,
  	372,3,134,67,0,372,373,5,8,0,0,373,378,3,54,27,0,374,375,5,72,0,0,375,
  	377,3,54,27,0,376,374,1,0,0,0,377,380,1,0,0,0,378,376,1,0,0,0,378,379,
  	1,0,0,0,379,382,1,0,0,0,380,378,1,0,0,0,381,364,1,0,0,0,381,370,1,0,0,
  	0,382,53,1,0,0,0,383,386,5,77,0,0,384,385,5,10,0,0,385,387,5,77,0,0,386,
  	384,1,0,0,0,386,387,1,0,0,0,387,55,1,0,0,0,388,392,5,77,0,0,389,392,3,
  	98,49,0,390,392,3,100,50,0,391,388,1,0,0,0,391,389,1,0,0,0,391,390,1,
  	0,0,0,392,393,1,0,0,0,393,394,7,0,0,0,394,395,3,60,30,0,395,57,1,0,0,
  	0,396,397,3,60,30,0,397,59,1,0,0,0,398,399,3,62,31,0,399,61,1,0,0,0,400,
  	406,3,64,32,0,401,402,5,2,0,0,402,403,3,64,32,0,403,404,5,3,0,0,404,405,
  	3,62,31,0,405,407,1,0,0,0,406,401,1,0,0,0,406,407,1,0,0,0,407,63,1,0,
  	0,0,408,413,3,66,33,0,409,410,5,29,0,0,410,412,3,66,33,0,411,409,1,0,
  	0,0,412,415,1,0,0,0,413,411,1,0,0,0,413,414,1,0,0,0,414,65,1,0,0,0,415,
  	413,1,0,0,0,416,421,3,68,34,0,417,418,5,28,0,0,418,420,3,68,34,0,419,
  	417,1,0,0,0,420,423,1,0,0,0,421,419,1,0,0,0,421,422,1,0,0,0,422,67,1,
  	0,0,0,423,421,1,0,0,0,424,429,3,70,35,0,425,426,5,49,0,0,426,428,3,70,
  	35,0,427,425,1,0,0,0,428,431,1,0,0,0,429,427,1,0,0,0,429,430,1,0,0,0,
  	430,69,1,0,0,0,431,429,1,0,0,0,432,437,3,72,36,0,433,434,5,50,0,0,434,
  	436,3,72,36,0,435,433,1,0,0,0,436,439,1,0,0,0,437,435,1,0,0,0,437,438,
  	1,0,0,0,438,71,1,0,0,0,439,437,1,0,0,0,440,445,3,74,37,0,441,442,5,48,
  	0,0,442,444,3,74,37,0,443,441,1,0,0,0,444,447,1,0,0,0,445,443,1,0,0,0,
  	445,446,1,0,0,0,446,73,1,0,0,0,447,445,1,0,0,0,448,453,3,76,38,0,449,
  	450,7,1,0,0,450,452,3,76,38,0,451,449,1,0,0,0,452,455,1,0,0,0,453,451,
  	1,0,0,0,453,454,1,0,0,0,454,75,1,0,0,0,455,453,1,0,0,0,456,461,3,78,39,
  	0,457,458,7,2,0,0,458,460,3,78,39,0,459,457,1,0,0,0,460,463,1,0,0,0,461,
  	459,1,0,0,0,461,462,1,0,0,0,462,77,1,0,0,0,463,461,1,0,0,0,464,469,3,
  	80,40,0,465,466,7,3,0,0,466,468,3,80,40,0,467,465,1,0,0,0,468,471,1,0,
  	0,0,469,467,1,0,0,0,469,470,1,0,0,0,470,79,1,0,0,0,471,469,1,0,0,0,472,
  	477,3,82,41,0,473,474,7,4,0,0,474,476,3,82,41,0,475,473,1,0,0,0,476,479,
  	1,0,0,0,477,475,1,0,0,0,477,478,1,0,0,0,478,81,1,0,0,0,479,477,1,0,0,
  	0,480,485,3,84,42,0,481,482,7,5,0,0,482,484,3,84,42,0,483,481,1,0,0,0,
  	484,487,1,0,0,0,485,483,1,0,0,0,485,486,1,0,0,0,486,83,1,0,0,0,487,485,
  	1,0,0,0,488,491,3,86,43,0,489,490,5,75,0,0,490,492,3,84,42,0,491,489,
  	1,0,0,0,491,492,1,0,0,0,492,85,1,0,0,0,493,495,7,6,0,0,494,493,1,0,0,
  	0,494,495,1,0,0,0,495,496,1,0,0,0,496,499,3,94,47,0,497,499,3,24,12,0,
  	498,494,1,0,0,0,498,497,1,0,0,0,499,87,1,0,0,0,500,518,3,130,65,0,501,
  	518,5,77,0,0,502,503,5,66,0,0,503,504,3,60,30,0,504,505,5,67,0,0,505,
  	518,1,0,0,0,506,507,5,66,0,0,507,508,3,90,45,0,508,509,5,67,0,0,509,518,
  	1,0,0,0,510,518,3,110,55,0,511,518,3,118,59,0,512,518,3,124,62,0,513,
  	518,3,128,64,0,514,518,3,92,46,0,515,518,3,132,66,0,516,518,3,24,12,0,
  	517,500,1,0,0,0,517,501,1,0,0,0,517,502,1,0,0,0,517,506,1,0,0,0,517,510,
  	1,0,0,0,517,511,1,0,0,0,517,512,1,0,0,0,517,513,1,0,0,0,517,514,1,0,0,
  	0,517,515,1,0,0,0,517,516,1,0,0,0,518,89,1,0,0,0,519,524,3,60,30,0,520,
  	521,5,72,0,0,521,523,3,60,30,0,522,520,1,0,0,0,523,526,1,0,0,0,524,522,
  	1,0,0,0,524,525,1,0,0,0,525,528,1,0,0,0,526,524,1,0,0,0,527,529,5,72,
  	0,0,528,527,1,0,0,0,528,529,1,0,0,0,529,91,1,0,0,0,530,531,5,15,0,0,531,
  	532,3,134,67,0,532,534,5,66,0,0,533,535,3,106,53,0,534,533,1,0,0,0,534,
  	535,1,0,0,0,535,536,1,0,0,0,536,537,5,67,0,0,537,93,1,0,0,0,538,542,3,
  	88,44,0,539,541,3,96,48,0,540,539,1,0,0,0,541,544,1,0,0,0,542,540,1,0,
  	0,0,542,543,1,0,0,0,543,95,1,0,0,0,544,542,1,0,0,0,545,546,5,74,0,0,546,
  	557,5,77,0,0,547,548,5,68,0,0,548,549,3,102,51,0,549,550,5,69,0,0,550,
  	557,1,0,0,0,551,553,5,66,0,0,552,554,3,106,53,0,553,552,1,0,0,0,553,554,
  	1,0,0,0,554,555,1,0,0,0,555,557,5,67,0,0,556,545,1,0,0,0,556,547,1,0,
  	0,0,556,551,1,0,0,0,557,97,1,0,0,0,558,559,3,94,47,0,559,560,5,74,0,0,
  	560,561,5,77,0,0,561,99,1,0,0,0,562,563,3,94,47,0,563,564,5,68,0,0,564,
  	565,3,102,51,0,565,566,5,69,0,0,566,101,1,0,0,0,567,569,3,60,30,0,568,
  	567,1,0,0,0,568,569,1,0,0,0,569,580,1,0,0,0,570,572,5,73,0,0,571,573,
  	3,60,30,0,572,571,1,0,0,0,572,573,1,0,0,0,573,578,1,0,0,0,574,576,5,73,
  	0,0,575,577,3,60,30,0,576,575,1,0,0,0,576,577,1,0,0,0,577,579,1,0,0,0,
  	578,574,1,0,0,0,578,579,1,0,0,0,579,581,1,0,0,0,580,570,1,0,0,0,580,581,
  	1,0,0,0,581,103,1,0,0,0,582,583,3,94,47,0,583,585,5,66,0,0,584,586,3,
  	106,53,0,585,584,1,0,0,0,585,586,1,0,0,0,586,587,1,0,0,0,587,588,5,67,
  	0,0,588,105,1,0,0,0,589,594,3,108,54,0,590,591,5,72,0,0,591,593,3,108,
  	54,0,592,590,1,0,0,0,593,596,1,0,0,0,594,592,1,0,0,0,594,595,1,0,0,0,
  	595,598,1,0,0,0,596,594,1,0,0,0,597,599,5,72,0,0,598,597,1,0,0,0,598,
  	599,1,0,0,0,599,107,1,0,0,0,600,601,5,77,0,0,601,602,5,52,0,0,602,609,
  	3,60,30,0,603,609,3,60,30,0,604,605,5,36,0,0,605,609,3,60,30,0,606,607,
  	5,75,0,0,607,609,3,60,30,0,608,600,1,0,0,0,608,603,1,0,0,0,608,604,1,
  	0,0,0,608,606,1,0,0,0,609,109,1,0,0,0,610,612,5,68,0,0,611,613,3,112,
  	56,0,612,611,1,0,0,0,612,613,1,0,0,0,613,614,1,0,0,0,614,615,5,69,0,0,
  	615,111,1,0,0,0,616,621,3,60,30,0,617,618,5,72,0,0,618,620,3,60,30,0,
  	619,617,1,0,0,0,620,623,1,0,0,0,621,619,1,0,0,0,621,622,1,0,0,0,622,625,
  	1,0,0,0,623,621,1,0,0,0,624,626,5,72,0,0,625,624,1,0,0,0,625,626,1,0,
  	0,0,626,629,1,0,0,0,627,629,3,114,57,0,628,616,1,0,0,0,628,627,1,0,0,
  	0,629,113,1,0,0,0,630,632,3,60,30,0,631,633,3,116,58,0,632,631,1,0,0,
  	0,633,634,1,0,0,0,634,632,1,0,0,0,634,635,1,0,0,0,635,115,1,0,0,0,636,
  	637,5,5,0,0,637,642,5,77,0,0,638,639,5,72,0,0,639,641,5,77,0,0,640,638,
  	1,0,0,0,641,644,1,0,0,0,642,640,1,0,0,0,642,643,1,0,0,0,643,645,1,0,0,
  	0,644,642,1,0,0,0,645,646,5,11,0,0,646,649,3,60,30,0,647,648,5,2,0,0,
  	648,650,3,60,30,0,649,647,1,0,0,0,649,650,1,0,0,0,650,117,1,0,0,0,651,
  	666,5,70,0,0,652,667,3,120,60,0,653,658,3,122,61,0,654,655,5,72,0,0,655,
  	657,3,122,61,0,656,654,1,0,0,0,657,660,1,0,0,0,658,656,1,0,0,0,658,659,
  	1,0,0,0,659,662,1,0,0,0,660,658,1,0,0,0,661,663,5,72,0,0,662,661,1,0,
  	0,0,662,663,1,0,0,0,663,665,1,0,0,0,664,653,1,0,0,0,664,665,1,0,0,0,665,
  	667,1,0,0,0,666,652,1,0,0,0,666,664,1,0,0,0,667,668,1,0,0,0,668,669,5,
  	71,0,0,669,119,1,0,0,0,670,671,3,60,30,0,671,672,5,73,0,0,672,674,3,60,
  	30,0,673,675,3,116,58,0,674,673,1,0,0,0,675,676,1,0,0,0,676,674,1,0,0,
  	0,676,677,1,0,0,0,677,121,1,0,0,0,678,679,3,60,30,0,679,680,5,73,0,0,
  	680,681,3,60,30,0,681,685,1,0,0,0,682,683,5,75,0,0,683,685,3,60,30,0,
  	684,678,1,0,0,0,684,682,1,0,0,0,685,123,1,0,0,0,686,688,5,70,0,0,687,
  	689,3,126,63,0,688,687,1,0,0,0,688,689,1,0,0,0,689,690,1,0,0,0,690,691,
  	5,71,0,0,691,125,1,0,0,0,692,697,3,60,30,0,693,694,5,72,0,0,694,696,3,
  	60,30,0,695,693,1,0,0,0,696,699,1,0,0,0,697,695,1,0,0,0,697,698,1,0,0,
  	0,698,701,1,0,0,0,699,697,1,0,0,0,700,702,5,72,0,0,701,700,1,0,0,0,701,
  	702,1,0,0,0,702,705,1,0,0,0,703,705,3,114,57,0,704,692,1,0,0,0,704,703,
  	1,0,0,0,705,127,1,0,0,0,706,707,5,66,0,0,707,708,3,114,57,0,708,709,5,
  	67,0,0,709,129,1,0,0,0,710,711,7,7,0,0,711,131,1,0,0,0,712,714,5,16,0,
  	0,713,715,3,38,19,0,714,713,1,0,0,0,714,715,1,0,0,0,715,716,1,0,0,0,716,
  	717,5,73,0,0,717,718,3,60,30,0,718,133,1,0,0,0,719,724,5,77,0,0,720,721,
  	5,74,0,0,721,723,5,77,0,0,722,720,1,0,0,0,723,726,1,0,0,0,724,722,1,0,
  	0,0,724,725,1,0,0,0,725,135,1,0,0,0,726,724,1,0,0,0,85,139,146,153,157,
  	160,169,182,190,196,201,207,209,220,229,251,255,259,262,270,275,287,291,
  	297,308,312,317,321,325,338,344,362,368,378,381,386,391,406,413,421,429,
  	437,445,453,461,469,477,485,491,494,498,517,524,528,534,542,553,556,568,
  	572,576,578,580,585,594,598,608,612,621,625,628,634,642,649,658,662,664,
  	666,676,684,688,697,701,704,714,724
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
    setState(139);
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
      setState(136);
      statement();
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
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
    setState(146);
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
        setState(144);
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
        setState(145);
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
    setState(148);
    smallStatement();
    setState(153);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(149);
        match(PyScriptParser::SEMI);
        setState(150);
        smallStatement(); 
      }
      setState(155);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::SEMI) {
      setState(156);
      match(PyScriptParser::SEMI);
    }
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::NEWLINE) {
      setState(159);
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
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(162);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(163);
      returnStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(164);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(165);
      importStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(166);
      passStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(167);
      match(PyScriptParser::BREAK);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(168);
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
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(171);
      decoratedDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(172);
      functionDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(173);
      asyncFunctionDef();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(174);
      classDef();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(175);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(176);
      whileStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(177);
      forStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(178);
      asyncForStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(179);
      tryStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(180);
      withStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(181);
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
    setState(184);
    match(PyScriptParser::TRY);
    setState(185);
    match(PyScriptParser::COLON);
    setState(186);
    suite();
    setState(190);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::EXCEPT) {
      setState(187);
      exceptClause();
      setState(192);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(193);
      match(PyScriptParser::ELSE);
      setState(194);
      match(PyScriptParser::COLON);
      setState(195);
      suite();
    }
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::FINALLY) {
      setState(198);
      match(PyScriptParser::FINALLY);
      setState(199);
      match(PyScriptParser::COLON);
      setState(200);
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
    setState(203);
    match(PyScriptParser::EXCEPT);
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IDENTIFIER) {
      setState(204);
      dottedName();
      setState(207);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::AS) {
        setState(205);
        match(PyScriptParser::AS);
        setState(206);
        match(PyScriptParser::IDENTIFIER);
      }
    }
    setState(211);
    match(PyScriptParser::COLON);
    setState(212);
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
    setState(214);
    match(PyScriptParser::WITH);
    setState(215);
    withItem();
    setState(220);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(216);
      match(PyScriptParser::COMMA);
      setState(217);
      withItem();
      setState(222);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(223);
    match(PyScriptParser::COLON);
    setState(224);
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
    setState(226);
    expression();
    setState(229);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(227);
      match(PyScriptParser::AS);
      setState(228);
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
    setState(231);
    match(PyScriptParser::ASYNC);
    setState(232);
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
    setState(234);
    match(PyScriptParser::ASYNC);
    setState(235);
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
    setState(237);
    match(PyScriptParser::ASYNC);
    setState(238);
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
    setState(240);
    match(PyScriptParser::AWAIT);
    setState(241);
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
    setState(243);
    match(PyScriptParser::CLASS);
    setState(244);
    match(PyScriptParser::IDENTIFIER);
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::LPAREN) {
      setState(245);
      match(PyScriptParser::LPAREN);
      setState(246);
      expression();
      setState(251);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(247);
          match(PyScriptParser::COMMA);
          setState(248);
          expression(); 
        }
        setState(253);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      }
      setState(255);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(254);
        match(PyScriptParser::COMMA);
      }
      setState(257);
      match(PyScriptParser::RPAREN);
    }
    setState(262);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AT) {
      setState(261);
      decorators();
    }
    setState(264);
    match(PyScriptParser::COLON);
    setState(265);
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
    setState(267);
    decorators();
    setState(270);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DEF: {
        setState(268);
        functionDef();
        break;
      }

      case PyScriptParser::CLASS: {
        setState(269);
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
    setState(273); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(272);
      decorator();
      setState(275); 
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
    setState(277);
    match(PyScriptParser::AT);
    setState(278);
    expression();
    setState(279);
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
    setState(291);
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
        setState(281);
        simpleStatement();
        break;
      }

      case PyScriptParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(282);
        match(PyScriptParser::NEWLINE);
        setState(283);
        match(PyScriptParser::INDENT);
        setState(285); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(284);
          statement();
          setState(287); 
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
        setState(289);
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
    setState(293);
    match(PyScriptParser::DEF);
    setState(294);
    match(PyScriptParser::IDENTIFIER);
    setState(295);
    match(PyScriptParser::LPAREN);
    setState(297);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 36) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 36)) & ((1ULL << (PyScriptParser::MUL - 36))
      | (1ULL << (PyScriptParser::DOUBLE_STAR - 36))
      | (1ULL << (PyScriptParser::IDENTIFIER - 36)))) != 0)) {
      setState(296);
      parameterList();
    }
    setState(299);
    match(PyScriptParser::RPAREN);
    setState(300);
    match(PyScriptParser::COLON);
    setState(301);
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
    setState(303);
    parameter();
    setState(308);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(304);
        match(PyScriptParser::COMMA);
        setState(305);
        parameter(); 
      }
      setState(310);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(311);
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
    setState(325);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(314);
        match(PyScriptParser::IDENTIFIER);
        setState(317);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::ASSIGN) {
          setState(315);
          match(PyScriptParser::ASSIGN);
          setState(316);
          expression();
        }
        break;
      }

      case PyScriptParser::MUL: {
        enterOuterAlt(_localctx, 2);
        setState(319);
        match(PyScriptParser::MUL);
        setState(321);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::IDENTIFIER) {
          setState(320);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 3);
        setState(323);
        match(PyScriptParser::DOUBLE_STAR);
        setState(324);
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
    setState(327);
    match(PyScriptParser::IF);
    setState(328);
    expression();
    setState(329);
    match(PyScriptParser::COLON);
    setState(330);
    suite();
    setState(338);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::ELIF) {
      setState(331);
      match(PyScriptParser::ELIF);
      setState(332);
      expression();
      setState(333);
      match(PyScriptParser::COLON);
      setState(334);
      suite();
      setState(340);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(344);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(341);
      match(PyScriptParser::ELSE);
      setState(342);
      match(PyScriptParser::COLON);
      setState(343);
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
    setState(346);
    match(PyScriptParser::WHILE);
    setState(347);
    expression();
    setState(348);
    match(PyScriptParser::COLON);
    setState(349);
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
    setState(351);
    match(PyScriptParser::FOR);
    setState(352);
    match(PyScriptParser::IDENTIFIER);
    setState(353);
    match(PyScriptParser::IN);
    setState(354);
    expression();
    setState(355);
    match(PyScriptParser::COLON);
    setState(356);
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
    setState(358);
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
    setState(360);
    match(PyScriptParser::RETURN);
    setState(362);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(361);
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
    setState(381);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IMPORT: {
        _localctx = _tracker.createInstance<PyScriptParser::SimpleImportContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(364);
        match(PyScriptParser::IMPORT);
        setState(365);
        dottedName();
        setState(368);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::AS) {
          setState(366);
          match(PyScriptParser::AS);
          setState(367);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::FROM: {
        _localctx = _tracker.createInstance<PyScriptParser::FromImportContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(370);
        match(PyScriptParser::FROM);
        setState(371);
        dottedName();
        setState(372);
        match(PyScriptParser::IMPORT);
        setState(373);
        importItem();
        setState(378);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PyScriptParser::COMMA) {
          setState(374);
          match(PyScriptParser::COMMA);
          setState(375);
          importItem();
          setState(380);
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
    setState(383);
    match(PyScriptParser::IDENTIFIER);
    setState(386);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(384);
      match(PyScriptParser::AS);
      setState(385);
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
    setState(391);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(388);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 2: {
      setState(389);
      attributeAccess();
      break;
    }

    case 3: {
      setState(390);
      subscriptAccess();
      break;
    }

    default:
      break;
    }
    setState(393);
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
    setState(394);
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
  enterRule(_localctx, 58, PyScriptParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
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
  enterRule(_localctx, 60, PyScriptParser::RuleExpression);

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
    setState(398);
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
  enterRule(_localctx, 62, PyScriptParser::RuleConditionalExpression);

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
    setState(400);
    logicalOr();
    setState(406);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(401);
      match(PyScriptParser::IF);
      setState(402);
      logicalOr();
      setState(403);
      match(PyScriptParser::ELSE);
      setState(404);
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
  enterRule(_localctx, 64, PyScriptParser::RuleLogicalOr);

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
    setState(408);
    logicalAnd();
    setState(413);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(409);
        match(PyScriptParser::OR);
        setState(410);
        logicalAnd(); 
      }
      setState(415);
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
  enterRule(_localctx, 66, PyScriptParser::RuleLogicalAnd);

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
    setState(416);
    bitwiseOr();
    setState(421);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(417);
        match(PyScriptParser::AND);
        setState(418);
        bitwiseOr(); 
      }
      setState(423);
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
  enterRule(_localctx, 68, PyScriptParser::RuleBitwiseOr);

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
    setState(424);
    bitwiseXor();
    setState(429);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(425);
        match(PyScriptParser::BITWISE_OR);
        setState(426);
        bitwiseXor(); 
      }
      setState(431);
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
  enterRule(_localctx, 70, PyScriptParser::RuleBitwiseXor);

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
    setState(432);
    bitwiseAnd();
    setState(437);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(433);
        match(PyScriptParser::BITWISE_XOR);
        setState(434);
        bitwiseAnd(); 
      }
      setState(439);
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
  enterRule(_localctx, 72, PyScriptParser::RuleBitwiseAnd);

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
    setState(440);
    equality();
    setState(445);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(441);
        match(PyScriptParser::BITWISE_AND);
        setState(442);
        equality(); 
      }
      setState(447);
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
  enterRule(_localctx, 74, PyScriptParser::RuleEquality);
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
    setState(448);
    comparison();
    setState(453);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(449);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::EQ

        || _la == PyScriptParser::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(450);
        comparison(); 
      }
      setState(455);
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
  enterRule(_localctx, 76, PyScriptParser::RuleComparison);
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
    setState(456);
    shift();
    setState(461);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(457);
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
        setState(458);
        shift(); 
      }
      setState(463);
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
  enterRule(_localctx, 78, PyScriptParser::RuleShift);
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
    setState(464);
    additive();
    setState(469);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(465);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::LEFT_SHIFT

        || _la == PyScriptParser::RIGHT_SHIFT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(466);
        additive(); 
      }
      setState(471);
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
  enterRule(_localctx, 80, PyScriptParser::RuleAdditive);
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
    setState(472);
    multiplicative();
    setState(477);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(473);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::PLUS

        || _la == PyScriptParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(474);
        multiplicative(); 
      }
      setState(479);
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
  enterRule(_localctx, 82, PyScriptParser::RuleMultiplicative);
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
    setState(480);
    power();
    setState(485);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(481);
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
        setState(482);
        power(); 
      }
      setState(487);
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
  enterRule(_localctx, 84, PyScriptParser::RulePower);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    unary();
    setState(491);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(489);
      match(PyScriptParser::DOUBLE_STAR);
      setState(490);
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
  enterRule(_localctx, 86, PyScriptParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(498);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(494);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS)
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0)) {
        setState(493);
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
      setState(496);
      atom();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(497);
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

PyScriptParser::TupleLiteralContext* PyScriptParser::PrimaryContext::tupleLiteral() {
  return getRuleContext<PyScriptParser::TupleLiteralContext>(0);
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
  enterRule(_localctx, 88, PyScriptParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(517);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(500);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(501);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(502);
      match(PyScriptParser::LPAREN);
      setState(503);
      expression();
      setState(504);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(506);
      match(PyScriptParser::LPAREN);
      setState(507);
      tupleLiteral();
      setState(508);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(510);
      listLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(511);
      dictLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(512);
      setLiteral();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(513);
      generatorExpression();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(514);
      newExpression();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(515);
      lambdaExpression();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(516);
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

//----------------- TupleContext ------------------------------------------------------------------

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::TupleContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::TupleContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::TupleContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::TupleContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}

PyScriptParser::TupleContext::TupleContext(TupleLiteralContext *ctx) { copyFrom(ctx); }

void PyScriptParser::TupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTuple(this);
}
void PyScriptParser::TupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTuple(this);
}

std::any PyScriptParser::TupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitTuple(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::TupleLiteralContext* PyScriptParser::tupleLiteral() {
  TupleLiteralContext *_localctx = _tracker.createInstance<TupleLiteralContext>(_ctx, getState());
  enterRule(_localctx, 90, PyScriptParser::RuleTupleLiteral);
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
    _localctx = _tracker.createInstance<PyScriptParser::TupleContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(519);
    expression();
    setState(524);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(520);
        match(PyScriptParser::COMMA);
        setState(521);
        expression(); 
      }
      setState(526);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    }
    setState(528);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(527);
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
  enterRule(_localctx, 92, PyScriptParser::RuleNewExpression);
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
    setState(530);
    match(PyScriptParser::NEW);
    setState(531);
    dottedName();
    setState(532);
    match(PyScriptParser::LPAREN);
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
      setState(533);
      argumentList();
    }
    setState(536);
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
  enterRule(_localctx, 94, PyScriptParser::RuleAtom);

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
    setState(538);
    primary();
    setState(542);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(539);
        postfixOp(); 
      }
      setState(544);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
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
  enterRule(_localctx, 96, PyScriptParser::RulePostfixOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(556);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DOT: {
        _localctx = _tracker.createInstance<PyScriptParser::AttributeAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(545);
        match(PyScriptParser::DOT);
        setState(546);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::LBRACK: {
        _localctx = _tracker.createInstance<PyScriptParser::SubscriptAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(547);
        match(PyScriptParser::LBRACK);
        setState(548);
        subscriptArg();
        setState(549);
        match(PyScriptParser::RBRACK);
        break;
      }

      case PyScriptParser::LPAREN: {
        _localctx = _tracker.createInstance<PyScriptParser::FunctionCallOpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(551);
        match(PyScriptParser::LPAREN);
        setState(553);
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
          setState(552);
          argumentList();
        }
        setState(555);
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
  enterRule(_localctx, 98, PyScriptParser::RuleAttributeAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(558);
    atom();
    setState(559);
    match(PyScriptParser::DOT);
    setState(560);
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
  enterRule(_localctx, 100, PyScriptParser::RuleSubscriptAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(562);
    atom();
    setState(563);
    match(PyScriptParser::LBRACK);
    setState(564);
    subscriptArg();
    setState(565);
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
  enterRule(_localctx, 102, PyScriptParser::RuleSubscriptArg);
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
    setState(568);
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
      setState(567);
      expression();
    }
    setState(580);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COLON) {
      setState(570);
      match(PyScriptParser::COLON);
      setState(572);
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
        setState(571);
        expression();
      }
      setState(578);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COLON) {
        setState(574);
        match(PyScriptParser::COLON);
        setState(576);
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
          setState(575);
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
  enterRule(_localctx, 104, PyScriptParser::RuleFunctionCall);
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
    setState(582);
    atom();
    setState(583);
    match(PyScriptParser::LPAREN);
    setState(585);
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
      setState(584);
      argumentList();
    }
    setState(587);
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
  enterRule(_localctx, 106, PyScriptParser::RuleArgumentList);
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
    setState(589);
    argument();
    setState(594);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(590);
        match(PyScriptParser::COMMA);
        setState(591);
        argument(); 
      }
      setState(596);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
    }
    setState(598);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(597);
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
  enterRule(_localctx, 108, PyScriptParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(608);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(600);
      match(PyScriptParser::IDENTIFIER);
      setState(601);
      match(PyScriptParser::ASSIGN);
      setState(602);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(603);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(604);
      match(PyScriptParser::MUL);
      setState(605);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(606);
      match(PyScriptParser::DOUBLE_STAR);
      setState(607);
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
  enterRule(_localctx, 110, PyScriptParser::RuleListLiteral);
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
    setState(610);
    match(PyScriptParser::LBRACK);
    setState(612);
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
      setState(611);
      listElements();
    }
    setState(614);
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
  enterRule(_localctx, 112, PyScriptParser::RuleListElements);
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
    setState(628);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(616);
      expression();
      setState(621);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(617);
          match(PyScriptParser::COMMA);
          setState(618);
          expression(); 
        }
        setState(623);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      setState(625);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(624);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(627);
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
  enterRule(_localctx, 114, PyScriptParser::RuleComprehension);
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
    setState(630);
    expression();
    setState(632); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(631);
      compFor();
      setState(634); 
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

std::vector<tree::TerminalNode *> PyScriptParser::CompForContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::CompForContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
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

std::vector<tree::TerminalNode *> PyScriptParser::CompForContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::CompForContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
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
  enterRule(_localctx, 116, PyScriptParser::RuleCompFor);
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
    setState(636);
    match(PyScriptParser::FOR);
    setState(637);
    match(PyScriptParser::IDENTIFIER);
    setState(642);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(638);
      match(PyScriptParser::COMMA);
      setState(639);
      match(PyScriptParser::IDENTIFIER);
      setState(644);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(645);
    match(PyScriptParser::IN);
    setState(646);
    expression();
    setState(649);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IF) {
      setState(647);
      match(PyScriptParser::IF);
      setState(648);
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
  enterRule(_localctx, 118, PyScriptParser::RuleDictLiteral);
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
    setState(651);
    match(PyScriptParser::LBRACE);
    setState(666);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
    case 1: {
      setState(652);
      dictComprehension();
      break;
    }

    case 2: {
      setState(664);
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
        setState(653);
        dictItem();
        setState(658);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(654);
            match(PyScriptParser::COMMA);
            setState(655);
            dictItem(); 
          }
          setState(660);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
        }
        setState(662);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::COMMA) {
          setState(661);
          match(PyScriptParser::COMMA);
        }
      }
      break;
    }

    default:
      break;
    }
    setState(668);
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
  enterRule(_localctx, 120, PyScriptParser::RuleDictComprehension);
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
    setState(670);
    expression();
    setState(671);
    match(PyScriptParser::COLON);
    setState(672);
    expression();
    setState(674); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(673);
      compFor();
      setState(676); 
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
  enterRule(_localctx, 122, PyScriptParser::RuleDictItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(684);
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
        setState(678);
        expression();
        setState(679);
        match(PyScriptParser::COLON);
        setState(680);
        expression();
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 2);
        setState(682);
        match(PyScriptParser::DOUBLE_STAR);
        setState(683);
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
  enterRule(_localctx, 124, PyScriptParser::RuleSetLiteral);
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
    setState(686);
    match(PyScriptParser::LBRACE);
    setState(688);
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
      setState(687);
      setElements();
    }
    setState(690);
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
  enterRule(_localctx, 126, PyScriptParser::RuleSetElements);
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
    setState(704);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(692);
      expression();
      setState(697);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(693);
          match(PyScriptParser::COMMA);
          setState(694);
          expression(); 
        }
        setState(699);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
      }
      setState(701);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(700);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(703);
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
  enterRule(_localctx, 128, PyScriptParser::RuleGeneratorExpression);

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
    match(PyScriptParser::LPAREN);
    setState(707);
    comprehension();
    setState(708);
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
  enterRule(_localctx, 130, PyScriptParser::RuleLiteral);
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
    setState(710);
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
  enterRule(_localctx, 132, PyScriptParser::RuleLambdaExpression);
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
    setState(712);
    match(PyScriptParser::LAMBDA);
    setState(714);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 36) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 36)) & ((1ULL << (PyScriptParser::MUL - 36))
      | (1ULL << (PyScriptParser::DOUBLE_STAR - 36))
      | (1ULL << (PyScriptParser::IDENTIFIER - 36)))) != 0)) {
      setState(713);
      parameterList();
    }
    setState(716);
    match(PyScriptParser::COLON);
    setState(717);
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
  enterRule(_localctx, 134, PyScriptParser::RuleDottedName);
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
    setState(719);
    match(PyScriptParser::IDENTIFIER);
    setState(724);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::DOT) {
      setState(720);
      match(PyScriptParser::DOT);
      setState(721);
      match(PyScriptParser::IDENTIFIER);
      setState(726);
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
