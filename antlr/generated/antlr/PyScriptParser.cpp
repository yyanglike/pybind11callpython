
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
      "passStatement", "returnStatement", "raiseStatement", "delStatement", 
      "delTargets", "delTarget", "globalStatement", "nonlocalStatement", 
      "importStatement", "importItem", "assignment", "assignmentTarget", 
      "expressionStatement", "expression", "assignmentExpression", "conditionalExpression", 
      "yieldExpression", "logicalOr", "logicalAnd", "bitwiseOr", "bitwiseXor", 
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
      "'new'", "'lambda'", "'yield'", "'raise'", "'del'", "'global'", "'nonlocal'", 
      "'try'", "'except'", "'finally'", "'with'", "'async'", "'await'", 
      "'class'", "'@'", "'true'", "'false'", "'none'", "'and'", "'or'", 
      "'not'", "'is'", "'is not'", "'not in'", "'+'", "'-'", "'*'", "'/'", 
      "'//'", "'%'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'<<'", 
      "'>>'", "'&'", "'|'", "'^'", "'~'", "'='", "':='", "'+='", "'-='", 
      "'*='", "'/='", "'//='", "'%='", "'**='", "'&='", "'|='", "'^='", 
      "'<<='", "'>>='", "';'", "'('", "')'", "'['", "']'", "'{'", "'}'", 
      "','", "':'", "'.'", "'**'"
    },
    std::vector<std::string>{
      "", "DEF", "IF", "ELSE", "ELIF", "FOR", "WHILE", "RETURN", "IMPORT", 
      "FROM", "AS", "IN", "PASS", "BREAK", "CONTINUE", "NEW", "LAMBDA", 
      "YIELD", "RAISE", "DEL", "GLOBAL", "NONLOCAL", "TRY", "EXCEPT", "FINALLY", 
      "WITH", "ASYNC", "AWAIT", "CLASS", "AT", "TRUE", "FALSE", "NONE", 
      "AND", "OR", "NOT", "IS", "IS_NOT", "NOT_IN", "PLUS", "MINUS", "MUL", 
      "DIV", "FLOOR_DIV", "MOD", "EQ", "NE", "LT", "LE", "GT", "GE", "LEFT_SHIFT", 
      "RIGHT_SHIFT", "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", 
      "ASSIGN", "WALRUS", "PLUS_ASSIGN", "MINUS_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", 
      "FLOOR_DIV_ASSIGN", "MOD_ASSIGN", "POW_ASSIGN", "BITWISE_AND_ASSIGN", 
      "BITWISE_OR_ASSIGN", "BITWISE_XOR_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN", 
      "SEMI", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", 
      "COMMA", "COLON", "DOT", "DOUBLE_STAR", "NEWLINE", "IDENTIFIER", "INTEGER", 
      "FLOAT", "STRING", "WS", "COMMENT", "INDENT", "DEDENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,90,809,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,70,7,
  	70,2,71,7,71,2,72,7,72,2,73,7,73,1,0,5,0,150,8,0,10,0,12,0,153,9,0,1,
  	0,1,0,1,1,1,1,3,1,159,8,1,1,2,1,2,1,2,5,2,164,8,2,10,2,12,2,167,9,2,1,
  	2,3,2,170,8,2,1,2,3,2,173,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,3,3,186,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,199,8,
  	4,1,5,1,5,1,5,1,5,5,5,205,8,5,10,5,12,5,208,9,5,1,5,1,5,1,5,3,5,213,8,
  	5,1,5,1,5,1,5,3,5,218,8,5,1,6,1,6,1,6,1,6,3,6,224,8,6,3,6,226,8,6,1,6,
  	1,6,1,6,1,7,1,7,1,7,1,7,5,7,235,8,7,10,7,12,7,238,9,7,1,7,1,7,1,7,1,8,
  	1,8,1,8,3,8,246,8,8,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,
  	12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,5,13,266,8,13,10,13,12,13,269,9,
  	13,1,13,3,13,272,8,13,1,13,1,13,3,13,276,8,13,1,13,3,13,279,8,13,1,13,
  	1,13,1,13,1,14,1,14,1,14,3,14,287,8,14,1,15,4,15,290,8,15,11,15,12,15,
  	291,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,4,17,302,8,17,11,17,12,17,
  	303,1,17,1,17,3,17,308,8,17,1,18,1,18,1,18,1,18,3,18,314,8,18,1,18,1,
  	18,1,18,1,18,1,19,1,19,1,19,5,19,323,8,19,10,19,12,19,326,9,19,1,19,3,
  	19,329,8,19,1,20,1,20,1,20,3,20,334,8,20,1,20,1,20,3,20,338,8,20,1,20,
  	1,20,3,20,342,8,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,5,21,
  	353,8,21,10,21,12,21,356,9,21,1,21,1,21,1,21,3,21,361,8,21,1,22,1,22,
  	1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,25,1,25,
  	3,25,379,8,25,1,26,1,26,3,26,383,8,26,1,26,1,26,3,26,387,8,26,1,27,1,
  	27,1,27,1,28,1,28,1,28,5,28,395,8,28,10,28,12,28,398,9,28,1,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,410,8,29,1,30,1,30,1,30,1,
  	30,5,30,416,8,30,10,30,12,30,419,9,30,1,31,1,31,1,31,1,31,5,31,425,8,
  	31,10,31,12,31,428,9,31,1,32,1,32,1,32,1,32,3,32,434,8,32,1,32,1,32,1,
  	32,1,32,1,32,1,32,5,32,442,8,32,10,32,12,32,445,9,32,3,32,447,8,32,1,
  	33,1,33,1,33,3,33,452,8,33,1,34,1,34,1,34,1,34,1,35,1,35,1,35,1,35,1,
  	35,1,35,1,35,1,35,1,35,1,35,3,35,468,8,35,1,36,1,36,1,37,1,37,3,37,474,
  	8,37,1,38,1,38,1,38,1,38,1,38,3,38,481,8,38,1,39,1,39,1,39,1,39,1,39,
  	1,39,3,39,489,8,39,1,40,1,40,3,40,493,8,40,1,40,1,40,1,40,3,40,498,8,
  	40,1,41,1,41,1,41,5,41,503,8,41,10,41,12,41,506,9,41,1,42,1,42,1,42,5,
  	42,511,8,42,10,42,12,42,514,9,42,1,43,1,43,1,43,5,43,519,8,43,10,43,12,
  	43,522,9,43,1,44,1,44,1,44,5,44,527,8,44,10,44,12,44,530,9,44,1,45,1,
  	45,1,45,5,45,535,8,45,10,45,12,45,538,9,45,1,46,1,46,1,46,5,46,543,8,
  	46,10,46,12,46,546,9,46,1,47,1,47,1,47,5,47,551,8,47,10,47,12,47,554,
  	9,47,1,48,1,48,1,48,5,48,559,8,48,10,48,12,48,562,9,48,1,49,1,49,1,49,
  	5,49,567,8,49,10,49,12,49,570,9,49,1,50,1,50,1,50,5,50,575,8,50,10,50,
  	12,50,578,9,50,1,51,1,51,1,51,3,51,583,8,51,1,52,3,52,586,8,52,1,52,1,
  	52,3,52,590,8,52,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,
  	53,1,53,1,53,1,53,1,53,1,53,1,53,3,53,609,8,53,1,54,1,54,1,54,1,54,1,
  	54,5,54,616,8,54,10,54,12,54,619,9,54,1,54,3,54,622,8,54,1,54,3,54,625,
  	8,54,1,54,1,54,1,54,3,54,630,8,54,1,55,1,55,1,55,1,55,3,55,636,8,55,1,
  	55,1,55,1,56,1,56,5,56,642,8,56,10,56,12,56,645,9,56,1,57,1,57,1,57,1,
  	57,1,57,1,57,1,57,1,57,3,57,655,8,57,1,57,3,57,658,8,57,1,58,3,58,661,
  	8,58,1,58,1,58,3,58,665,8,58,1,58,1,58,3,58,669,8,58,3,58,671,8,58,3,
  	58,673,8,58,1,59,1,59,1,59,5,59,678,8,59,10,59,12,59,681,9,59,1,59,3,
  	59,684,8,59,1,60,1,60,1,60,1,60,1,60,1,60,1,60,1,60,3,60,694,8,60,1,61,
  	1,61,3,61,698,8,61,1,61,1,61,1,62,1,62,1,62,5,62,705,8,62,10,62,12,62,
  	708,9,62,1,62,3,62,711,8,62,1,62,3,62,714,8,62,1,63,1,63,4,63,718,8,63,
  	11,63,12,63,719,1,64,1,64,1,64,3,64,725,8,64,1,64,1,64,1,64,1,64,3,64,
  	731,8,64,1,65,1,65,1,65,1,65,1,65,5,65,738,8,65,10,65,12,65,741,9,65,
  	1,65,3,65,744,8,65,3,65,746,8,65,3,65,748,8,65,1,65,1,65,1,66,1,66,1,
  	66,1,66,4,66,756,8,66,11,66,12,66,757,1,67,1,67,1,67,1,67,1,67,1,67,3,
  	67,766,8,67,1,68,1,68,3,68,770,8,68,1,68,1,68,1,69,1,69,1,69,5,69,777,
  	8,69,10,69,12,69,780,9,69,1,69,3,69,783,8,69,1,69,3,69,786,8,69,1,70,
  	1,70,1,70,1,70,1,71,1,71,1,72,1,72,3,72,796,8,72,1,72,1,72,1,72,1,73,
  	1,73,1,73,5,73,804,8,73,10,73,12,73,807,9,73,1,73,0,0,74,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,
  	58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,
  	104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,
  	140,142,144,146,0,8,2,0,57,57,59,70,1,0,45,46,3,0,11,11,36,38,47,50,1,
  	0,51,52,1,0,39,40,1,0,41,44,3,0,35,35,39,40,56,56,2,0,30,32,84,86,863,
  	0,151,1,0,0,0,2,158,1,0,0,0,4,160,1,0,0,0,6,185,1,0,0,0,8,198,1,0,0,0,
  	10,200,1,0,0,0,12,219,1,0,0,0,14,230,1,0,0,0,16,242,1,0,0,0,18,247,1,
  	0,0,0,20,250,1,0,0,0,22,253,1,0,0,0,24,256,1,0,0,0,26,259,1,0,0,0,28,
  	283,1,0,0,0,30,289,1,0,0,0,32,293,1,0,0,0,34,307,1,0,0,0,36,309,1,0,0,
  	0,38,319,1,0,0,0,40,341,1,0,0,0,42,343,1,0,0,0,44,362,1,0,0,0,46,367,
  	1,0,0,0,48,374,1,0,0,0,50,376,1,0,0,0,52,380,1,0,0,0,54,388,1,0,0,0,56,
  	391,1,0,0,0,58,409,1,0,0,0,60,411,1,0,0,0,62,420,1,0,0,0,64,446,1,0,0,
  	0,66,448,1,0,0,0,68,453,1,0,0,0,70,467,1,0,0,0,72,469,1,0,0,0,74,473,
  	1,0,0,0,76,480,1,0,0,0,78,482,1,0,0,0,80,497,1,0,0,0,82,499,1,0,0,0,84,
  	507,1,0,0,0,86,515,1,0,0,0,88,523,1,0,0,0,90,531,1,0,0,0,92,539,1,0,0,
  	0,94,547,1,0,0,0,96,555,1,0,0,0,98,563,1,0,0,0,100,571,1,0,0,0,102,579,
  	1,0,0,0,104,589,1,0,0,0,106,608,1,0,0,0,108,629,1,0,0,0,110,631,1,0,0,
  	0,112,639,1,0,0,0,114,657,1,0,0,0,116,660,1,0,0,0,118,674,1,0,0,0,120,
  	693,1,0,0,0,122,695,1,0,0,0,124,713,1,0,0,0,126,715,1,0,0,0,128,721,1,
  	0,0,0,130,732,1,0,0,0,132,751,1,0,0,0,134,765,1,0,0,0,136,767,1,0,0,0,
  	138,785,1,0,0,0,140,787,1,0,0,0,142,791,1,0,0,0,144,793,1,0,0,0,146,800,
  	1,0,0,0,148,150,3,2,1,0,149,148,1,0,0,0,150,153,1,0,0,0,151,149,1,0,0,
  	0,151,152,1,0,0,0,152,154,1,0,0,0,153,151,1,0,0,0,154,155,5,0,0,1,155,
  	1,1,0,0,0,156,159,3,4,2,0,157,159,3,8,4,0,158,156,1,0,0,0,158,157,1,0,
  	0,0,159,3,1,0,0,0,160,165,3,6,3,0,161,162,5,71,0,0,162,164,3,6,3,0,163,
  	161,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,0,166,169,1,
  	0,0,0,167,165,1,0,0,0,168,170,5,71,0,0,169,168,1,0,0,0,169,170,1,0,0,
  	0,170,172,1,0,0,0,171,173,5,82,0,0,172,171,1,0,0,0,172,173,1,0,0,0,173,
  	5,1,0,0,0,174,186,3,68,34,0,175,186,3,50,25,0,176,186,3,72,36,0,177,186,
  	3,64,32,0,178,186,3,48,24,0,179,186,3,52,26,0,180,186,3,54,27,0,181,186,
  	3,60,30,0,182,186,3,62,31,0,183,186,5,13,0,0,184,186,5,14,0,0,185,174,
  	1,0,0,0,185,175,1,0,0,0,185,176,1,0,0,0,185,177,1,0,0,0,185,178,1,0,0,
  	0,185,179,1,0,0,0,185,180,1,0,0,0,185,181,1,0,0,0,185,182,1,0,0,0,185,
  	183,1,0,0,0,185,184,1,0,0,0,186,7,1,0,0,0,187,199,3,28,14,0,188,199,3,
  	36,18,0,189,199,3,18,9,0,190,199,3,26,13,0,191,199,3,42,21,0,192,199,
  	3,44,22,0,193,199,3,46,23,0,194,199,3,20,10,0,195,199,3,10,5,0,196,199,
  	3,14,7,0,197,199,3,22,11,0,198,187,1,0,0,0,198,188,1,0,0,0,198,189,1,
  	0,0,0,198,190,1,0,0,0,198,191,1,0,0,0,198,192,1,0,0,0,198,193,1,0,0,0,
  	198,194,1,0,0,0,198,195,1,0,0,0,198,196,1,0,0,0,198,197,1,0,0,0,199,9,
  	1,0,0,0,200,201,5,22,0,0,201,202,5,79,0,0,202,206,3,34,17,0,203,205,3,
  	12,6,0,204,203,1,0,0,0,205,208,1,0,0,0,206,204,1,0,0,0,206,207,1,0,0,
  	0,207,212,1,0,0,0,208,206,1,0,0,0,209,210,5,3,0,0,210,211,5,79,0,0,211,
  	213,3,34,17,0,212,209,1,0,0,0,212,213,1,0,0,0,213,217,1,0,0,0,214,215,
  	5,24,0,0,215,216,5,79,0,0,216,218,3,34,17,0,217,214,1,0,0,0,217,218,1,
  	0,0,0,218,11,1,0,0,0,219,225,5,23,0,0,220,223,3,146,73,0,221,222,5,10,
  	0,0,222,224,5,83,0,0,223,221,1,0,0,0,223,224,1,0,0,0,224,226,1,0,0,0,
  	225,220,1,0,0,0,225,226,1,0,0,0,226,227,1,0,0,0,227,228,5,79,0,0,228,
  	229,3,34,17,0,229,13,1,0,0,0,230,231,5,25,0,0,231,236,3,16,8,0,232,233,
  	5,78,0,0,233,235,3,16,8,0,234,232,1,0,0,0,235,238,1,0,0,0,236,234,1,0,
  	0,0,236,237,1,0,0,0,237,239,1,0,0,0,238,236,1,0,0,0,239,240,5,79,0,0,
  	240,241,3,34,17,0,241,15,1,0,0,0,242,245,3,74,37,0,243,244,5,10,0,0,244,
  	246,5,83,0,0,245,243,1,0,0,0,245,246,1,0,0,0,246,17,1,0,0,0,247,248,5,
  	26,0,0,248,249,3,36,18,0,249,19,1,0,0,0,250,251,5,26,0,0,251,252,3,46,
  	23,0,252,21,1,0,0,0,253,254,5,26,0,0,254,255,3,14,7,0,255,23,1,0,0,0,
  	256,257,5,27,0,0,257,258,3,74,37,0,258,25,1,0,0,0,259,260,5,28,0,0,260,
  	275,5,83,0,0,261,262,5,72,0,0,262,267,3,74,37,0,263,264,5,78,0,0,264,
  	266,3,74,37,0,265,263,1,0,0,0,266,269,1,0,0,0,267,265,1,0,0,0,267,268,
  	1,0,0,0,268,271,1,0,0,0,269,267,1,0,0,0,270,272,5,78,0,0,271,270,1,0,
  	0,0,271,272,1,0,0,0,272,273,1,0,0,0,273,274,5,73,0,0,274,276,1,0,0,0,
  	275,261,1,0,0,0,275,276,1,0,0,0,276,278,1,0,0,0,277,279,3,30,15,0,278,
  	277,1,0,0,0,278,279,1,0,0,0,279,280,1,0,0,0,280,281,5,79,0,0,281,282,
  	3,34,17,0,282,27,1,0,0,0,283,286,3,30,15,0,284,287,3,36,18,0,285,287,
  	3,26,13,0,286,284,1,0,0,0,286,285,1,0,0,0,287,29,1,0,0,0,288,290,3,32,
  	16,0,289,288,1,0,0,0,290,291,1,0,0,0,291,289,1,0,0,0,291,292,1,0,0,0,
  	292,31,1,0,0,0,293,294,5,29,0,0,294,295,3,74,37,0,295,296,5,82,0,0,296,
  	33,1,0,0,0,297,308,3,4,2,0,298,299,5,82,0,0,299,301,5,89,0,0,300,302,
  	3,2,1,0,301,300,1,0,0,0,302,303,1,0,0,0,303,301,1,0,0,0,303,304,1,0,0,
  	0,304,305,1,0,0,0,305,306,5,90,0,0,306,308,1,0,0,0,307,297,1,0,0,0,307,
  	298,1,0,0,0,308,35,1,0,0,0,309,310,5,1,0,0,310,311,5,83,0,0,311,313,5,
  	72,0,0,312,314,3,38,19,0,313,312,1,0,0,0,313,314,1,0,0,0,314,315,1,0,
  	0,0,315,316,5,73,0,0,316,317,5,79,0,0,317,318,3,34,17,0,318,37,1,0,0,
  	0,319,324,3,40,20,0,320,321,5,78,0,0,321,323,3,40,20,0,322,320,1,0,0,
  	0,323,326,1,0,0,0,324,322,1,0,0,0,324,325,1,0,0,0,325,328,1,0,0,0,326,
  	324,1,0,0,0,327,329,5,78,0,0,328,327,1,0,0,0,328,329,1,0,0,0,329,39,1,
  	0,0,0,330,333,5,83,0,0,331,332,5,57,0,0,332,334,3,74,37,0,333,331,1,0,
  	0,0,333,334,1,0,0,0,334,342,1,0,0,0,335,337,5,41,0,0,336,338,5,83,0,0,
  	337,336,1,0,0,0,337,338,1,0,0,0,338,342,1,0,0,0,339,340,5,81,0,0,340,
  	342,5,83,0,0,341,330,1,0,0,0,341,335,1,0,0,0,341,339,1,0,0,0,342,41,1,
  	0,0,0,343,344,5,2,0,0,344,345,3,74,37,0,345,346,5,79,0,0,346,354,3,34,
  	17,0,347,348,5,4,0,0,348,349,3,74,37,0,349,350,5,79,0,0,350,351,3,34,
  	17,0,351,353,1,0,0,0,352,347,1,0,0,0,353,356,1,0,0,0,354,352,1,0,0,0,
  	354,355,1,0,0,0,355,360,1,0,0,0,356,354,1,0,0,0,357,358,5,3,0,0,358,359,
  	5,79,0,0,359,361,3,34,17,0,360,357,1,0,0,0,360,361,1,0,0,0,361,43,1,0,
  	0,0,362,363,5,6,0,0,363,364,3,74,37,0,364,365,5,79,0,0,365,366,3,34,17,
  	0,366,45,1,0,0,0,367,368,5,5,0,0,368,369,5,83,0,0,369,370,5,11,0,0,370,
  	371,3,74,37,0,371,372,5,79,0,0,372,373,3,34,17,0,373,47,1,0,0,0,374,375,
  	5,12,0,0,375,49,1,0,0,0,376,378,5,7,0,0,377,379,3,74,37,0,378,377,1,0,
  	0,0,378,379,1,0,0,0,379,51,1,0,0,0,380,382,5,18,0,0,381,383,3,74,37,0,
  	382,381,1,0,0,0,382,383,1,0,0,0,383,386,1,0,0,0,384,385,5,9,0,0,385,387,
  	3,74,37,0,386,384,1,0,0,0,386,387,1,0,0,0,387,53,1,0,0,0,388,389,5,19,
  	0,0,389,390,3,56,28,0,390,55,1,0,0,0,391,396,3,58,29,0,392,393,5,78,0,
  	0,393,395,3,58,29,0,394,392,1,0,0,0,395,398,1,0,0,0,396,394,1,0,0,0,396,
  	397,1,0,0,0,397,57,1,0,0,0,398,396,1,0,0,0,399,400,3,106,53,0,400,401,
  	5,74,0,0,401,402,3,116,58,0,402,403,5,75,0,0,403,410,1,0,0,0,404,405,
  	3,106,53,0,405,406,5,80,0,0,406,407,5,83,0,0,407,410,1,0,0,0,408,410,
  	5,83,0,0,409,399,1,0,0,0,409,404,1,0,0,0,409,408,1,0,0,0,410,59,1,0,0,
  	0,411,412,5,20,0,0,412,417,5,83,0,0,413,414,5,78,0,0,414,416,5,83,0,0,
  	415,413,1,0,0,0,416,419,1,0,0,0,417,415,1,0,0,0,417,418,1,0,0,0,418,61,
  	1,0,0,0,419,417,1,0,0,0,420,421,5,21,0,0,421,426,5,83,0,0,422,423,5,78,
  	0,0,423,425,5,83,0,0,424,422,1,0,0,0,425,428,1,0,0,0,426,424,1,0,0,0,
  	426,427,1,0,0,0,427,63,1,0,0,0,428,426,1,0,0,0,429,430,5,8,0,0,430,433,
  	3,146,73,0,431,432,5,10,0,0,432,434,5,83,0,0,433,431,1,0,0,0,433,434,
  	1,0,0,0,434,447,1,0,0,0,435,436,5,9,0,0,436,437,3,146,73,0,437,438,5,
  	8,0,0,438,443,3,66,33,0,439,440,5,78,0,0,440,442,3,66,33,0,441,439,1,
  	0,0,0,442,445,1,0,0,0,443,441,1,0,0,0,443,444,1,0,0,0,444,447,1,0,0,0,
  	445,443,1,0,0,0,446,429,1,0,0,0,446,435,1,0,0,0,447,65,1,0,0,0,448,451,
  	5,83,0,0,449,450,5,10,0,0,450,452,5,83,0,0,451,449,1,0,0,0,451,452,1,
  	0,0,0,452,67,1,0,0,0,453,454,3,70,35,0,454,455,7,0,0,0,455,456,3,74,37,
  	0,456,69,1,0,0,0,457,468,5,83,0,0,458,459,3,106,53,0,459,460,5,80,0,0,
  	460,461,5,83,0,0,461,468,1,0,0,0,462,463,3,106,53,0,463,464,5,74,0,0,
  	464,465,3,116,58,0,465,466,5,75,0,0,466,468,1,0,0,0,467,457,1,0,0,0,467,
  	458,1,0,0,0,467,462,1,0,0,0,468,71,1,0,0,0,469,470,3,74,37,0,470,73,1,
  	0,0,0,471,474,3,76,38,0,472,474,3,80,40,0,473,471,1,0,0,0,473,472,1,0,
  	0,0,474,75,1,0,0,0,475,481,3,78,39,0,476,477,3,70,35,0,477,478,5,58,0,
  	0,478,479,3,78,39,0,479,481,1,0,0,0,480,475,1,0,0,0,480,476,1,0,0,0,481,
  	77,1,0,0,0,482,488,3,82,41,0,483,484,5,2,0,0,484,485,3,82,41,0,485,486,
  	5,3,0,0,486,487,3,78,39,0,487,489,1,0,0,0,488,483,1,0,0,0,488,489,1,0,
  	0,0,489,79,1,0,0,0,490,492,5,17,0,0,491,493,3,78,39,0,492,491,1,0,0,0,
  	492,493,1,0,0,0,493,498,1,0,0,0,494,495,5,17,0,0,495,496,5,9,0,0,496,
  	498,3,78,39,0,497,490,1,0,0,0,497,494,1,0,0,0,498,81,1,0,0,0,499,504,
  	3,84,42,0,500,501,5,34,0,0,501,503,3,84,42,0,502,500,1,0,0,0,503,506,
  	1,0,0,0,504,502,1,0,0,0,504,505,1,0,0,0,505,83,1,0,0,0,506,504,1,0,0,
  	0,507,512,3,86,43,0,508,509,5,33,0,0,509,511,3,86,43,0,510,508,1,0,0,
  	0,511,514,1,0,0,0,512,510,1,0,0,0,512,513,1,0,0,0,513,85,1,0,0,0,514,
  	512,1,0,0,0,515,520,3,88,44,0,516,517,5,54,0,0,517,519,3,88,44,0,518,
  	516,1,0,0,0,519,522,1,0,0,0,520,518,1,0,0,0,520,521,1,0,0,0,521,87,1,
  	0,0,0,522,520,1,0,0,0,523,528,3,90,45,0,524,525,5,55,0,0,525,527,3,90,
  	45,0,526,524,1,0,0,0,527,530,1,0,0,0,528,526,1,0,0,0,528,529,1,0,0,0,
  	529,89,1,0,0,0,530,528,1,0,0,0,531,536,3,92,46,0,532,533,5,53,0,0,533,
  	535,3,92,46,0,534,532,1,0,0,0,535,538,1,0,0,0,536,534,1,0,0,0,536,537,
  	1,0,0,0,537,91,1,0,0,0,538,536,1,0,0,0,539,544,3,94,47,0,540,541,7,1,
  	0,0,541,543,3,94,47,0,542,540,1,0,0,0,543,546,1,0,0,0,544,542,1,0,0,0,
  	544,545,1,0,0,0,545,93,1,0,0,0,546,544,1,0,0,0,547,552,3,96,48,0,548,
  	549,7,2,0,0,549,551,3,96,48,0,550,548,1,0,0,0,551,554,1,0,0,0,552,550,
  	1,0,0,0,552,553,1,0,0,0,553,95,1,0,0,0,554,552,1,0,0,0,555,560,3,98,49,
  	0,556,557,7,3,0,0,557,559,3,98,49,0,558,556,1,0,0,0,559,562,1,0,0,0,560,
  	558,1,0,0,0,560,561,1,0,0,0,561,97,1,0,0,0,562,560,1,0,0,0,563,568,3,
  	100,50,0,564,565,7,4,0,0,565,567,3,100,50,0,566,564,1,0,0,0,567,570,1,
  	0,0,0,568,566,1,0,0,0,568,569,1,0,0,0,569,99,1,0,0,0,570,568,1,0,0,0,
  	571,576,3,102,51,0,572,573,7,5,0,0,573,575,3,102,51,0,574,572,1,0,0,0,
  	575,578,1,0,0,0,576,574,1,0,0,0,576,577,1,0,0,0,577,101,1,0,0,0,578,576,
  	1,0,0,0,579,582,3,104,52,0,580,581,5,81,0,0,581,583,3,102,51,0,582,580,
  	1,0,0,0,582,583,1,0,0,0,583,103,1,0,0,0,584,586,7,6,0,0,585,584,1,0,0,
  	0,585,586,1,0,0,0,586,587,1,0,0,0,587,590,3,112,56,0,588,590,3,24,12,
  	0,589,585,1,0,0,0,589,588,1,0,0,0,590,105,1,0,0,0,591,609,3,142,71,0,
  	592,609,5,83,0,0,593,594,5,72,0,0,594,595,3,108,54,0,595,596,5,73,0,0,
  	596,609,1,0,0,0,597,598,5,72,0,0,598,599,3,74,37,0,599,600,5,73,0,0,600,
  	609,1,0,0,0,601,609,3,122,61,0,602,609,3,130,65,0,603,609,3,136,68,0,
  	604,609,3,140,70,0,605,609,3,110,55,0,606,609,3,144,72,0,607,609,3,24,
  	12,0,608,591,1,0,0,0,608,592,1,0,0,0,608,593,1,0,0,0,608,597,1,0,0,0,
  	608,601,1,0,0,0,608,602,1,0,0,0,608,603,1,0,0,0,608,604,1,0,0,0,608,605,
  	1,0,0,0,608,606,1,0,0,0,608,607,1,0,0,0,609,107,1,0,0,0,610,611,3,74,
  	37,0,611,617,5,78,0,0,612,613,3,74,37,0,613,614,5,78,0,0,614,616,1,0,
  	0,0,615,612,1,0,0,0,616,619,1,0,0,0,617,615,1,0,0,0,617,618,1,0,0,0,618,
  	621,1,0,0,0,619,617,1,0,0,0,620,622,3,74,37,0,621,620,1,0,0,0,621,622,
  	1,0,0,0,622,624,1,0,0,0,623,625,5,78,0,0,624,623,1,0,0,0,624,625,1,0,
  	0,0,625,630,1,0,0,0,626,627,3,74,37,0,627,628,5,78,0,0,628,630,1,0,0,
  	0,629,610,1,0,0,0,629,626,1,0,0,0,630,109,1,0,0,0,631,632,5,15,0,0,632,
  	633,3,146,73,0,633,635,5,72,0,0,634,636,3,118,59,0,635,634,1,0,0,0,635,
  	636,1,0,0,0,636,637,1,0,0,0,637,638,5,73,0,0,638,111,1,0,0,0,639,643,
  	3,106,53,0,640,642,3,114,57,0,641,640,1,0,0,0,642,645,1,0,0,0,643,641,
  	1,0,0,0,643,644,1,0,0,0,644,113,1,0,0,0,645,643,1,0,0,0,646,647,5,80,
  	0,0,647,658,5,83,0,0,648,649,5,74,0,0,649,650,3,116,58,0,650,651,5,75,
  	0,0,651,658,1,0,0,0,652,654,5,72,0,0,653,655,3,118,59,0,654,653,1,0,0,
  	0,654,655,1,0,0,0,655,656,1,0,0,0,656,658,5,73,0,0,657,646,1,0,0,0,657,
  	648,1,0,0,0,657,652,1,0,0,0,658,115,1,0,0,0,659,661,3,74,37,0,660,659,
  	1,0,0,0,660,661,1,0,0,0,661,672,1,0,0,0,662,664,5,79,0,0,663,665,3,74,
  	37,0,664,663,1,0,0,0,664,665,1,0,0,0,665,670,1,0,0,0,666,668,5,79,0,0,
  	667,669,3,74,37,0,668,667,1,0,0,0,668,669,1,0,0,0,669,671,1,0,0,0,670,
  	666,1,0,0,0,670,671,1,0,0,0,671,673,1,0,0,0,672,662,1,0,0,0,672,673,1,
  	0,0,0,673,117,1,0,0,0,674,679,3,120,60,0,675,676,5,78,0,0,676,678,3,120,
  	60,0,677,675,1,0,0,0,678,681,1,0,0,0,679,677,1,0,0,0,679,680,1,0,0,0,
  	680,683,1,0,0,0,681,679,1,0,0,0,682,684,5,78,0,0,683,682,1,0,0,0,683,
  	684,1,0,0,0,684,119,1,0,0,0,685,686,5,83,0,0,686,687,5,57,0,0,687,694,
  	3,74,37,0,688,694,3,74,37,0,689,690,5,41,0,0,690,694,3,74,37,0,691,692,
  	5,81,0,0,692,694,3,74,37,0,693,685,1,0,0,0,693,688,1,0,0,0,693,689,1,
  	0,0,0,693,691,1,0,0,0,694,121,1,0,0,0,695,697,5,74,0,0,696,698,3,124,
  	62,0,697,696,1,0,0,0,697,698,1,0,0,0,698,699,1,0,0,0,699,700,5,75,0,0,
  	700,123,1,0,0,0,701,706,3,74,37,0,702,703,5,78,0,0,703,705,3,74,37,0,
  	704,702,1,0,0,0,705,708,1,0,0,0,706,704,1,0,0,0,706,707,1,0,0,0,707,710,
  	1,0,0,0,708,706,1,0,0,0,709,711,5,78,0,0,710,709,1,0,0,0,710,711,1,0,
  	0,0,711,714,1,0,0,0,712,714,3,126,63,0,713,701,1,0,0,0,713,712,1,0,0,
  	0,714,125,1,0,0,0,715,717,3,74,37,0,716,718,3,128,64,0,717,716,1,0,0,
  	0,718,719,1,0,0,0,719,717,1,0,0,0,719,720,1,0,0,0,720,127,1,0,0,0,721,
  	724,5,5,0,0,722,725,5,83,0,0,723,725,3,108,54,0,724,722,1,0,0,0,724,723,
  	1,0,0,0,725,726,1,0,0,0,726,727,5,11,0,0,727,730,3,74,37,0,728,729,5,
  	2,0,0,729,731,3,74,37,0,730,728,1,0,0,0,730,731,1,0,0,0,731,129,1,0,0,
  	0,732,747,5,76,0,0,733,748,3,132,66,0,734,739,3,134,67,0,735,736,5,78,
  	0,0,736,738,3,134,67,0,737,735,1,0,0,0,738,741,1,0,0,0,739,737,1,0,0,
  	0,739,740,1,0,0,0,740,743,1,0,0,0,741,739,1,0,0,0,742,744,5,78,0,0,743,
  	742,1,0,0,0,743,744,1,0,0,0,744,746,1,0,0,0,745,734,1,0,0,0,745,746,1,
  	0,0,0,746,748,1,0,0,0,747,733,1,0,0,0,747,745,1,0,0,0,748,749,1,0,0,0,
  	749,750,5,77,0,0,750,131,1,0,0,0,751,752,3,74,37,0,752,753,5,79,0,0,753,
  	755,3,74,37,0,754,756,3,128,64,0,755,754,1,0,0,0,756,757,1,0,0,0,757,
  	755,1,0,0,0,757,758,1,0,0,0,758,133,1,0,0,0,759,760,3,74,37,0,760,761,
  	5,79,0,0,761,762,3,74,37,0,762,766,1,0,0,0,763,764,5,81,0,0,764,766,3,
  	74,37,0,765,759,1,0,0,0,765,763,1,0,0,0,766,135,1,0,0,0,767,769,5,76,
  	0,0,768,770,3,138,69,0,769,768,1,0,0,0,769,770,1,0,0,0,770,771,1,0,0,
  	0,771,772,5,77,0,0,772,137,1,0,0,0,773,778,3,74,37,0,774,775,5,78,0,0,
  	775,777,3,74,37,0,776,774,1,0,0,0,777,780,1,0,0,0,778,776,1,0,0,0,778,
  	779,1,0,0,0,779,782,1,0,0,0,780,778,1,0,0,0,781,783,5,78,0,0,782,781,
  	1,0,0,0,782,783,1,0,0,0,783,786,1,0,0,0,784,786,3,126,63,0,785,773,1,
  	0,0,0,785,784,1,0,0,0,786,139,1,0,0,0,787,788,5,72,0,0,788,789,3,126,
  	63,0,789,790,5,73,0,0,790,141,1,0,0,0,791,792,7,7,0,0,792,143,1,0,0,0,
  	793,795,5,16,0,0,794,796,3,38,19,0,795,794,1,0,0,0,795,796,1,0,0,0,796,
  	797,1,0,0,0,797,798,5,79,0,0,798,799,3,74,37,0,799,145,1,0,0,0,800,805,
  	5,83,0,0,801,802,5,80,0,0,802,804,5,83,0,0,803,801,1,0,0,0,804,807,1,
  	0,0,0,805,803,1,0,0,0,805,806,1,0,0,0,806,147,1,0,0,0,807,805,1,0,0,0,
  	96,151,158,165,169,172,185,198,206,212,217,223,225,236,245,267,271,275,
  	278,286,291,303,307,313,324,328,333,337,341,354,360,378,382,386,396,409,
  	417,426,433,443,446,451,467,473,480,488,492,497,504,512,520,528,536,544,
  	552,560,568,576,582,585,589,608,617,621,624,629,635,643,654,657,660,664,
  	668,670,672,679,683,693,697,706,710,713,719,724,730,739,743,745,747,757,
  	765,769,778,782,785,795,805
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
    setState(151);
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
      | (1ULL << PyScriptParser::YIELD)
      | (1ULL << PyScriptParser::RAISE)
      | (1ULL << PyScriptParser::DEL)
      | (1ULL << PyScriptParser::GLOBAL)
      | (1ULL << PyScriptParser::NONLOCAL)
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
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
      | (1ULL << (PyScriptParser::LBRACK - 72))
      | (1ULL << (PyScriptParser::LBRACE - 72))
      | (1ULL << (PyScriptParser::IDENTIFIER - 72))
      | (1ULL << (PyScriptParser::INTEGER - 72))
      | (1ULL << (PyScriptParser::FLOAT - 72))
      | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
      setState(148);
      statement();
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(154);
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
    setState(158);
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
      case PyScriptParser::YIELD:
      case PyScriptParser::RAISE:
      case PyScriptParser::DEL:
      case PyScriptParser::GLOBAL:
      case PyScriptParser::NONLOCAL:
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
        setState(156);
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
        setState(157);
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
    setState(160);
    smallStatement();
    setState(165);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(161);
        match(PyScriptParser::SEMI);
        setState(162);
        smallStatement(); 
      }
      setState(167);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(169);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::SEMI) {
      setState(168);
      match(PyScriptParser::SEMI);
    }
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::NEWLINE) {
      setState(171);
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

PyScriptParser::RaiseStatementContext* PyScriptParser::SmallStatementContext::raiseStatement() {
  return getRuleContext<PyScriptParser::RaiseStatementContext>(0);
}

PyScriptParser::DelStatementContext* PyScriptParser::SmallStatementContext::delStatement() {
  return getRuleContext<PyScriptParser::DelStatementContext>(0);
}

PyScriptParser::GlobalStatementContext* PyScriptParser::SmallStatementContext::globalStatement() {
  return getRuleContext<PyScriptParser::GlobalStatementContext>(0);
}

PyScriptParser::NonlocalStatementContext* PyScriptParser::SmallStatementContext::nonlocalStatement() {
  return getRuleContext<PyScriptParser::NonlocalStatementContext>(0);
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
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(174);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(175);
      returnStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(176);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(177);
      importStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(178);
      passStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(179);
      raiseStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(180);
      delStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(181);
      globalStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(182);
      nonlocalStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(183);
      match(PyScriptParser::BREAK);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(184);
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
    setState(198);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(187);
      decoratedDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(188);
      functionDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(189);
      asyncFunctionDef();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(190);
      classDef();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(191);
      ifStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(192);
      whileStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(193);
      forStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(194);
      asyncForStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(195);
      tryStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(196);
      withStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(197);
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
    setState(200);
    match(PyScriptParser::TRY);
    setState(201);
    match(PyScriptParser::COLON);
    setState(202);
    suite();
    setState(206);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::EXCEPT) {
      setState(203);
      exceptClause();
      setState(208);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(209);
      match(PyScriptParser::ELSE);
      setState(210);
      match(PyScriptParser::COLON);
      setState(211);
      suite();
    }
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::FINALLY) {
      setState(214);
      match(PyScriptParser::FINALLY);
      setState(215);
      match(PyScriptParser::COLON);
      setState(216);
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
    setState(219);
    match(PyScriptParser::EXCEPT);
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IDENTIFIER) {
      setState(220);
      dottedName();
      setState(223);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::AS) {
        setState(221);
        match(PyScriptParser::AS);
        setState(222);
        match(PyScriptParser::IDENTIFIER);
      }
    }
    setState(227);
    match(PyScriptParser::COLON);
    setState(228);
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
    setState(230);
    match(PyScriptParser::WITH);
    setState(231);
    withItem();
    setState(236);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(232);
      match(PyScriptParser::COMMA);
      setState(233);
      withItem();
      setState(238);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(239);
    match(PyScriptParser::COLON);
    setState(240);
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
    setState(242);
    expression();
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(243);
      match(PyScriptParser::AS);
      setState(244);
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
    setState(247);
    match(PyScriptParser::ASYNC);
    setState(248);
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
    setState(250);
    match(PyScriptParser::ASYNC);
    setState(251);
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
    setState(253);
    match(PyScriptParser::ASYNC);
    setState(254);
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
    setState(256);
    match(PyScriptParser::AWAIT);
    setState(257);
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
    setState(259);
    match(PyScriptParser::CLASS);
    setState(260);
    match(PyScriptParser::IDENTIFIER);
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::LPAREN) {
      setState(261);
      match(PyScriptParser::LPAREN);
      setState(262);
      expression();
      setState(267);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(263);
          match(PyScriptParser::COMMA);
          setState(264);
          expression(); 
        }
        setState(269);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      }
      setState(271);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(270);
        match(PyScriptParser::COMMA);
      }
      setState(273);
      match(PyScriptParser::RPAREN);
    }
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AT) {
      setState(277);
      decorators();
    }
    setState(280);
    match(PyScriptParser::COLON);
    setState(281);
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
    setState(283);
    decorators();
    setState(286);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DEF: {
        setState(284);
        functionDef();
        break;
      }

      case PyScriptParser::CLASS: {
        setState(285);
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
    setState(289); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(288);
      decorator();
      setState(291); 
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
    setState(293);
    match(PyScriptParser::AT);
    setState(294);
    expression();
    setState(295);
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
    setState(307);
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
      case PyScriptParser::YIELD:
      case PyScriptParser::RAISE:
      case PyScriptParser::DEL:
      case PyScriptParser::GLOBAL:
      case PyScriptParser::NONLOCAL:
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
        setState(297);
        simpleStatement();
        break;
      }

      case PyScriptParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(298);
        match(PyScriptParser::NEWLINE);
        setState(299);
        match(PyScriptParser::INDENT);
        setState(301); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(300);
          statement();
          setState(303); 
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
          | (1ULL << PyScriptParser::YIELD)
          | (1ULL << PyScriptParser::RAISE)
          | (1ULL << PyScriptParser::DEL)
          | (1ULL << PyScriptParser::GLOBAL)
          | (1ULL << PyScriptParser::NONLOCAL)
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
          | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
          | (1ULL << (PyScriptParser::LBRACK - 72))
          | (1ULL << (PyScriptParser::LBRACE - 72))
          | (1ULL << (PyScriptParser::IDENTIFIER - 72))
          | (1ULL << (PyScriptParser::INTEGER - 72))
          | (1ULL << (PyScriptParser::FLOAT - 72))
          | (1ULL << (PyScriptParser::STRING - 72)))) != 0));
        setState(305);
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
    setState(309);
    match(PyScriptParser::DEF);
    setState(310);
    match(PyScriptParser::IDENTIFIER);
    setState(311);
    match(PyScriptParser::LPAREN);
    setState(313);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 41) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 41)) & ((1ULL << (PyScriptParser::MUL - 41))
      | (1ULL << (PyScriptParser::DOUBLE_STAR - 41))
      | (1ULL << (PyScriptParser::IDENTIFIER - 41)))) != 0)) {
      setState(312);
      parameterList();
    }
    setState(315);
    match(PyScriptParser::RPAREN);
    setState(316);
    match(PyScriptParser::COLON);
    setState(317);
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
    setState(319);
    parameter();
    setState(324);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(320);
        match(PyScriptParser::COMMA);
        setState(321);
        parameter(); 
      }
      setState(326);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(327);
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
    setState(341);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(330);
        match(PyScriptParser::IDENTIFIER);
        setState(333);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::ASSIGN) {
          setState(331);
          match(PyScriptParser::ASSIGN);
          setState(332);
          expression();
        }
        break;
      }

      case PyScriptParser::MUL: {
        enterOuterAlt(_localctx, 2);
        setState(335);
        match(PyScriptParser::MUL);
        setState(337);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::IDENTIFIER) {
          setState(336);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 3);
        setState(339);
        match(PyScriptParser::DOUBLE_STAR);
        setState(340);
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
    setState(343);
    match(PyScriptParser::IF);
    setState(344);
    expression();
    setState(345);
    match(PyScriptParser::COLON);
    setState(346);
    suite();
    setState(354);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::ELIF) {
      setState(347);
      match(PyScriptParser::ELIF);
      setState(348);
      expression();
      setState(349);
      match(PyScriptParser::COLON);
      setState(350);
      suite();
      setState(356);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(357);
      match(PyScriptParser::ELSE);
      setState(358);
      match(PyScriptParser::COLON);
      setState(359);
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
    setState(362);
    match(PyScriptParser::WHILE);
    setState(363);
    expression();
    setState(364);
    match(PyScriptParser::COLON);
    setState(365);
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
    setState(367);
    match(PyScriptParser::FOR);
    setState(368);
    match(PyScriptParser::IDENTIFIER);
    setState(369);
    match(PyScriptParser::IN);
    setState(370);
    expression();
    setState(371);
    match(PyScriptParser::COLON);
    setState(372);
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
    setState(374);
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
    setState(376);
    match(PyScriptParser::RETURN);
    setState(378);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(377);
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

//----------------- RaiseStatementContext ------------------------------------------------------------------

PyScriptParser::RaiseStatementContext::RaiseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::RaiseStatementContext::RAISE() {
  return getToken(PyScriptParser::RAISE, 0);
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::RaiseStatementContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::RaiseStatementContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* PyScriptParser::RaiseStatementContext::FROM() {
  return getToken(PyScriptParser::FROM, 0);
}


size_t PyScriptParser::RaiseStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleRaiseStatement;
}

void PyScriptParser::RaiseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRaiseStatement(this);
}

void PyScriptParser::RaiseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRaiseStatement(this);
}


std::any PyScriptParser::RaiseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitRaiseStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::RaiseStatementContext* PyScriptParser::raiseStatement() {
  RaiseStatementContext *_localctx = _tracker.createInstance<RaiseStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, PyScriptParser::RuleRaiseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(PyScriptParser::RAISE);
    setState(382);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(381);
      expression();
      break;
    }

    default:
      break;
    }
    setState(386);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(384);
      match(PyScriptParser::FROM);
      setState(385);
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

//----------------- DelStatementContext ------------------------------------------------------------------

PyScriptParser::DelStatementContext::DelStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::DelStatementContext::DEL() {
  return getToken(PyScriptParser::DEL, 0);
}

PyScriptParser::DelTargetsContext* PyScriptParser::DelStatementContext::delTargets() {
  return getRuleContext<PyScriptParser::DelTargetsContext>(0);
}


size_t PyScriptParser::DelStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleDelStatement;
}

void PyScriptParser::DelStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelStatement(this);
}

void PyScriptParser::DelStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelStatement(this);
}


std::any PyScriptParser::DelStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDelStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DelStatementContext* PyScriptParser::delStatement() {
  DelStatementContext *_localctx = _tracker.createInstance<DelStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, PyScriptParser::RuleDelStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    match(PyScriptParser::DEL);
    setState(389);
    delTargets();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DelTargetsContext ------------------------------------------------------------------

PyScriptParser::DelTargetsContext::DelTargetsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::DelTargetContext *> PyScriptParser::DelTargetsContext::delTarget() {
  return getRuleContexts<PyScriptParser::DelTargetContext>();
}

PyScriptParser::DelTargetContext* PyScriptParser::DelTargetsContext::delTarget(size_t i) {
  return getRuleContext<PyScriptParser::DelTargetContext>(i);
}

std::vector<tree::TerminalNode *> PyScriptParser::DelTargetsContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::DelTargetsContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::DelTargetsContext::getRuleIndex() const {
  return PyScriptParser::RuleDelTargets;
}

void PyScriptParser::DelTargetsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelTargets(this);
}

void PyScriptParser::DelTargetsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelTargets(this);
}


std::any PyScriptParser::DelTargetsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDelTargets(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DelTargetsContext* PyScriptParser::delTargets() {
  DelTargetsContext *_localctx = _tracker.createInstance<DelTargetsContext>(_ctx, getState());
  enterRule(_localctx, 56, PyScriptParser::RuleDelTargets);
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
    delTarget();
    setState(396);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(392);
      match(PyScriptParser::COMMA);
      setState(393);
      delTarget();
      setState(398);
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

//----------------- DelTargetContext ------------------------------------------------------------------

PyScriptParser::DelTargetContext::DelTargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::DelTargetContext::getRuleIndex() const {
  return PyScriptParser::RuleDelTarget;
}

void PyScriptParser::DelTargetContext::copyFrom(DelTargetContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DelAttributeContext ------------------------------------------------------------------

PyScriptParser::PrimaryContext* PyScriptParser::DelAttributeContext::primary() {
  return getRuleContext<PyScriptParser::PrimaryContext>(0);
}

tree::TerminalNode* PyScriptParser::DelAttributeContext::DOT() {
  return getToken(PyScriptParser::DOT, 0);
}

tree::TerminalNode* PyScriptParser::DelAttributeContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::DelAttributeContext::DelAttributeContext(DelTargetContext *ctx) { copyFrom(ctx); }

void PyScriptParser::DelAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelAttribute(this);
}
void PyScriptParser::DelAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelAttribute(this);
}

std::any PyScriptParser::DelAttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDelAttribute(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DelVariableContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::DelVariableContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::DelVariableContext::DelVariableContext(DelTargetContext *ctx) { copyFrom(ctx); }

void PyScriptParser::DelVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelVariable(this);
}
void PyScriptParser::DelVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelVariable(this);
}

std::any PyScriptParser::DelVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDelVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DelSubscriptContext ------------------------------------------------------------------

PyScriptParser::PrimaryContext* PyScriptParser::DelSubscriptContext::primary() {
  return getRuleContext<PyScriptParser::PrimaryContext>(0);
}

tree::TerminalNode* PyScriptParser::DelSubscriptContext::LBRACK() {
  return getToken(PyScriptParser::LBRACK, 0);
}

PyScriptParser::SubscriptArgContext* PyScriptParser::DelSubscriptContext::subscriptArg() {
  return getRuleContext<PyScriptParser::SubscriptArgContext>(0);
}

tree::TerminalNode* PyScriptParser::DelSubscriptContext::RBRACK() {
  return getToken(PyScriptParser::RBRACK, 0);
}

PyScriptParser::DelSubscriptContext::DelSubscriptContext(DelTargetContext *ctx) { copyFrom(ctx); }

void PyScriptParser::DelSubscriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelSubscript(this);
}
void PyScriptParser::DelSubscriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelSubscript(this);
}

std::any PyScriptParser::DelSubscriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDelSubscript(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::DelTargetContext* PyScriptParser::delTarget() {
  DelTargetContext *_localctx = _tracker.createInstance<DelTargetContext>(_ctx, getState());
  enterRule(_localctx, 58, PyScriptParser::RuleDelTarget);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(409);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PyScriptParser::DelSubscriptContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(399);
      primary();
      setState(400);
      match(PyScriptParser::LBRACK);
      setState(401);
      subscriptArg();
      setState(402);
      match(PyScriptParser::RBRACK);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PyScriptParser::DelAttributeContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(404);
      primary();
      setState(405);
      match(PyScriptParser::DOT);
      setState(406);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PyScriptParser::DelVariableContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(408);
      match(PyScriptParser::IDENTIFIER);
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

//----------------- GlobalStatementContext ------------------------------------------------------------------

PyScriptParser::GlobalStatementContext::GlobalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::GlobalStatementContext::GLOBAL() {
  return getToken(PyScriptParser::GLOBAL, 0);
}

std::vector<tree::TerminalNode *> PyScriptParser::GlobalStatementContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::GlobalStatementContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::GlobalStatementContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::GlobalStatementContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::GlobalStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleGlobalStatement;
}

void PyScriptParser::GlobalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalStatement(this);
}

void PyScriptParser::GlobalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalStatement(this);
}


std::any PyScriptParser::GlobalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitGlobalStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::GlobalStatementContext* PyScriptParser::globalStatement() {
  GlobalStatementContext *_localctx = _tracker.createInstance<GlobalStatementContext>(_ctx, getState());
  enterRule(_localctx, 60, PyScriptParser::RuleGlobalStatement);
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
    match(PyScriptParser::GLOBAL);
    setState(412);
    match(PyScriptParser::IDENTIFIER);
    setState(417);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(413);
      match(PyScriptParser::COMMA);
      setState(414);
      match(PyScriptParser::IDENTIFIER);
      setState(419);
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

//----------------- NonlocalStatementContext ------------------------------------------------------------------

PyScriptParser::NonlocalStatementContext::NonlocalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::NonlocalStatementContext::NONLOCAL() {
  return getToken(PyScriptParser::NONLOCAL, 0);
}

std::vector<tree::TerminalNode *> PyScriptParser::NonlocalStatementContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::NonlocalStatementContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> PyScriptParser::NonlocalStatementContext::COMMA() {
  return getTokens(PyScriptParser::COMMA);
}

tree::TerminalNode* PyScriptParser::NonlocalStatementContext::COMMA(size_t i) {
  return getToken(PyScriptParser::COMMA, i);
}


size_t PyScriptParser::NonlocalStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleNonlocalStatement;
}

void PyScriptParser::NonlocalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonlocalStatement(this);
}

void PyScriptParser::NonlocalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonlocalStatement(this);
}


std::any PyScriptParser::NonlocalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitNonlocalStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::NonlocalStatementContext* PyScriptParser::nonlocalStatement() {
  NonlocalStatementContext *_localctx = _tracker.createInstance<NonlocalStatementContext>(_ctx, getState());
  enterRule(_localctx, 62, PyScriptParser::RuleNonlocalStatement);
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
    setState(420);
    match(PyScriptParser::NONLOCAL);
    setState(421);
    match(PyScriptParser::IDENTIFIER);
    setState(426);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::COMMA) {
      setState(422);
      match(PyScriptParser::COMMA);
      setState(423);
      match(PyScriptParser::IDENTIFIER);
      setState(428);
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
  enterRule(_localctx, 64, PyScriptParser::RuleImportStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(446);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::IMPORT: {
        _localctx = _tracker.createInstance<PyScriptParser::SimpleImportContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(429);
        match(PyScriptParser::IMPORT);
        setState(430);
        dottedName();
        setState(433);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::AS) {
          setState(431);
          match(PyScriptParser::AS);
          setState(432);
          match(PyScriptParser::IDENTIFIER);
        }
        break;
      }

      case PyScriptParser::FROM: {
        _localctx = _tracker.createInstance<PyScriptParser::FromImportContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(435);
        match(PyScriptParser::FROM);
        setState(436);
        dottedName();
        setState(437);
        match(PyScriptParser::IMPORT);
        setState(438);
        importItem();
        setState(443);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PyScriptParser::COMMA) {
          setState(439);
          match(PyScriptParser::COMMA);
          setState(440);
          importItem();
          setState(445);
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
  enterRule(_localctx, 66, PyScriptParser::RuleImportItem);
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
    setState(448);
    match(PyScriptParser::IDENTIFIER);
    setState(451);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(449);
      match(PyScriptParser::AS);
      setState(450);
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
  enterRule(_localctx, 68, PyScriptParser::RuleAssignment);
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
    setState(453);
    assignmentTarget();
    setState(454);
    _la = _input->LA(1);
    if (!(((((_la - 57) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 57)) & ((1ULL << (PyScriptParser::ASSIGN - 57))
      | (1ULL << (PyScriptParser::PLUS_ASSIGN - 57))
      | (1ULL << (PyScriptParser::MINUS_ASSIGN - 57))
      | (1ULL << (PyScriptParser::MUL_ASSIGN - 57))
      | (1ULL << (PyScriptParser::DIV_ASSIGN - 57))
      | (1ULL << (PyScriptParser::FLOOR_DIV_ASSIGN - 57))
      | (1ULL << (PyScriptParser::MOD_ASSIGN - 57))
      | (1ULL << (PyScriptParser::POW_ASSIGN - 57))
      | (1ULL << (PyScriptParser::BITWISE_AND_ASSIGN - 57))
      | (1ULL << (PyScriptParser::BITWISE_OR_ASSIGN - 57))
      | (1ULL << (PyScriptParser::BITWISE_XOR_ASSIGN - 57))
      | (1ULL << (PyScriptParser::LEFT_SHIFT_ASSIGN - 57))
      | (1ULL << (PyScriptParser::RIGHT_SHIFT_ASSIGN - 57)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(455);
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
  enterRule(_localctx, 70, PyScriptParser::RuleAssignmentTarget);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(467);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(457);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(458);
      primary();
      setState(459);
      match(PyScriptParser::DOT);
      setState(460);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(462);
      primary();
      setState(463);
      match(PyScriptParser::LBRACK);
      setState(464);
      subscriptArg();
      setState(465);
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
  enterRule(_localctx, 72, PyScriptParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(469);
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

//----------------- AssignmentExprContext ------------------------------------------------------------------

PyScriptParser::AssignmentExpressionContext* PyScriptParser::AssignmentExprContext::assignmentExpression() {
  return getRuleContext<PyScriptParser::AssignmentExpressionContext>(0);
}

PyScriptParser::AssignmentExprContext::AssignmentExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::AssignmentExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpr(this);
}
void PyScriptParser::AssignmentExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpr(this);
}

std::any PyScriptParser::AssignmentExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- YieldExprContext ------------------------------------------------------------------

PyScriptParser::YieldExpressionContext* PyScriptParser::YieldExprContext::yieldExpression() {
  return getRuleContext<PyScriptParser::YieldExpressionContext>(0);
}

PyScriptParser::YieldExprContext::YieldExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::YieldExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYieldExpr(this);
}
void PyScriptParser::YieldExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYieldExpr(this);
}

std::any PyScriptParser::YieldExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitYieldExpr(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::ExpressionContext* PyScriptParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 74, PyScriptParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(473);
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
        _localctx = _tracker.createInstance<PyScriptParser::AssignmentExprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(471);
        assignmentExpression();
        break;
      }

      case PyScriptParser::YIELD: {
        _localctx = _tracker.createInstance<PyScriptParser::YieldExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(472);
        yieldExpression();
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

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

PyScriptParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::AssignmentExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleAssignmentExpression;
}

void PyScriptParser::AssignmentExpressionContext::copyFrom(AssignmentExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WalrusExprContext ------------------------------------------------------------------

PyScriptParser::AssignmentTargetContext* PyScriptParser::WalrusExprContext::assignmentTarget() {
  return getRuleContext<PyScriptParser::AssignmentTargetContext>(0);
}

tree::TerminalNode* PyScriptParser::WalrusExprContext::WALRUS() {
  return getToken(PyScriptParser::WALRUS, 0);
}

PyScriptParser::ConditionalExpressionContext* PyScriptParser::WalrusExprContext::conditionalExpression() {
  return getRuleContext<PyScriptParser::ConditionalExpressionContext>(0);
}

PyScriptParser::WalrusExprContext::WalrusExprContext(AssignmentExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::WalrusExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWalrusExpr(this);
}
void PyScriptParser::WalrusExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWalrusExpr(this);
}

std::any PyScriptParser::WalrusExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitWalrusExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConditionalExprContext ------------------------------------------------------------------

PyScriptParser::ConditionalExpressionContext* PyScriptParser::ConditionalExprContext::conditionalExpression() {
  return getRuleContext<PyScriptParser::ConditionalExpressionContext>(0);
}

PyScriptParser::ConditionalExprContext::ConditionalExprContext(AssignmentExpressionContext *ctx) { copyFrom(ctx); }

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
PyScriptParser::AssignmentExpressionContext* PyScriptParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 76, PyScriptParser::RuleAssignmentExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(480);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PyScriptParser::ConditionalExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(475);
      conditionalExpression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PyScriptParser::WalrusExprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(476);
      assignmentTarget();
      setState(477);
      match(PyScriptParser::WALRUS);
      setState(478);
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
  enterRule(_localctx, 78, PyScriptParser::RuleConditionalExpression);

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
    setState(482);
    logicalOr();
    setState(488);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(483);
      match(PyScriptParser::IF);
      setState(484);
      logicalOr();
      setState(485);
      match(PyScriptParser::ELSE);
      setState(486);
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

//----------------- YieldExpressionContext ------------------------------------------------------------------

PyScriptParser::YieldExpressionContext::YieldExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::YieldExpressionContext::YIELD() {
  return getToken(PyScriptParser::YIELD, 0);
}

PyScriptParser::ConditionalExpressionContext* PyScriptParser::YieldExpressionContext::conditionalExpression() {
  return getRuleContext<PyScriptParser::ConditionalExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::YieldExpressionContext::FROM() {
  return getToken(PyScriptParser::FROM, 0);
}


size_t PyScriptParser::YieldExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleYieldExpression;
}

void PyScriptParser::YieldExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYieldExpression(this);
}

void PyScriptParser::YieldExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYieldExpression(this);
}


std::any PyScriptParser::YieldExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitYieldExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::YieldExpressionContext* PyScriptParser::yieldExpression() {
  YieldExpressionContext *_localctx = _tracker.createInstance<YieldExpressionContext>(_ctx, getState());
  enterRule(_localctx, 80, PyScriptParser::RuleYieldExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(497);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(490);
      match(PyScriptParser::YIELD);
      setState(492);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
      case 1: {
        setState(491);
        conditionalExpression();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(494);
      match(PyScriptParser::YIELD);
      setState(495);
      match(PyScriptParser::FROM);
      setState(496);
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
  enterRule(_localctx, 82, PyScriptParser::RuleLogicalOr);

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
    setState(499);
    logicalAnd();
    setState(504);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(500);
        match(PyScriptParser::OR);
        setState(501);
        logicalAnd(); 
      }
      setState(506);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
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
  enterRule(_localctx, 84, PyScriptParser::RuleLogicalAnd);

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
    setState(507);
    bitwiseOr();
    setState(512);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(508);
        match(PyScriptParser::AND);
        setState(509);
        bitwiseOr(); 
      }
      setState(514);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
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
  enterRule(_localctx, 86, PyScriptParser::RuleBitwiseOr);

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
    setState(515);
    bitwiseXor();
    setState(520);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(516);
        match(PyScriptParser::BITWISE_OR);
        setState(517);
        bitwiseXor(); 
      }
      setState(522);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
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
  enterRule(_localctx, 88, PyScriptParser::RuleBitwiseXor);

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
    setState(523);
    bitwiseAnd();
    setState(528);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(524);
        match(PyScriptParser::BITWISE_XOR);
        setState(525);
        bitwiseAnd(); 
      }
      setState(530);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
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
  enterRule(_localctx, 90, PyScriptParser::RuleBitwiseAnd);

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
    setState(531);
    equality();
    setState(536);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(532);
        match(PyScriptParser::BITWISE_AND);
        setState(533);
        equality(); 
      }
      setState(538);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
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
  enterRule(_localctx, 92, PyScriptParser::RuleEquality);
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
    setState(539);
    comparison();
    setState(544);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(540);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::EQ

        || _la == PyScriptParser::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(541);
        comparison(); 
      }
      setState(546);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
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
  enterRule(_localctx, 94, PyScriptParser::RuleComparison);
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
    setState(547);
    shift();
    setState(552);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(548);
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
        setState(549);
        shift(); 
      }
      setState(554);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
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
  enterRule(_localctx, 96, PyScriptParser::RuleShift);
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
    setState(555);
    additive();
    setState(560);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(556);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::LEFT_SHIFT

        || _la == PyScriptParser::RIGHT_SHIFT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(557);
        additive(); 
      }
      setState(562);
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
  enterRule(_localctx, 98, PyScriptParser::RuleAdditive);
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
    setState(563);
    multiplicative();
    setState(568);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(564);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::PLUS

        || _la == PyScriptParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(565);
        multiplicative(); 
      }
      setState(570);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
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
  enterRule(_localctx, 100, PyScriptParser::RuleMultiplicative);
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
    setState(571);
    power();
    setState(576);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(572);
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
        setState(573);
        power(); 
      }
      setState(578);
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
  enterRule(_localctx, 102, PyScriptParser::RulePower);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    unary();
    setState(582);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      setState(580);
      match(PyScriptParser::DOUBLE_STAR);
      setState(581);
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
  enterRule(_localctx, 104, PyScriptParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(589);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(585);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS)
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0)) {
        setState(584);
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
      setState(587);
      atom();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(588);
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
  enterRule(_localctx, 106, PyScriptParser::RulePrimary);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(591);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(592);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(593);
      match(PyScriptParser::LPAREN);
      setState(594);
      tupleLiteral();
      setState(595);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(597);
      match(PyScriptParser::LPAREN);
      setState(598);
      expression();
      setState(599);
      match(PyScriptParser::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(601);
      listLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(602);
      dictLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(603);
      setLiteral();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(604);
      generatorExpression();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(605);
      newExpression();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(606);
      lambdaExpression();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(607);
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
  enterRule(_localctx, 108, PyScriptParser::RuleTupleLiteral);
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
    setState(629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PyScriptParser::MultiElementTupleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(610);
      expression();
      setState(611);
      match(PyScriptParser::COMMA);
      setState(617);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(612);
          expression();
          setState(613);
          match(PyScriptParser::COMMA); 
        }
        setState(619);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
      }
      setState(621);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
        | (1ULL << PyScriptParser::LAMBDA)
        | (1ULL << PyScriptParser::YIELD)
        | (1ULL << PyScriptParser::AWAIT)
        | (1ULL << PyScriptParser::TRUE)
        | (1ULL << PyScriptParser::FALSE)
        | (1ULL << PyScriptParser::NONE)
        | (1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS)
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
        | (1ULL << (PyScriptParser::LBRACK - 72))
        | (1ULL << (PyScriptParser::LBRACE - 72))
        | (1ULL << (PyScriptParser::IDENTIFIER - 72))
        | (1ULL << (PyScriptParser::INTEGER - 72))
        | (1ULL << (PyScriptParser::FLOAT - 72))
        | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
        setState(620);
        expression();
      }
      setState(624);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(623);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PyScriptParser::SingleElementTupleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(626);
      expression();
      setState(627);
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
  enterRule(_localctx, 110, PyScriptParser::RuleNewExpression);
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
    setState(631);
    match(PyScriptParser::NEW);
    setState(632);
    dottedName();
    setState(633);
    match(PyScriptParser::LPAREN);
    setState(635);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::YIELD)
      | (1ULL << PyScriptParser::AWAIT)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::MUL)
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
      | (1ULL << (PyScriptParser::LBRACK - 72))
      | (1ULL << (PyScriptParser::LBRACE - 72))
      | (1ULL << (PyScriptParser::DOUBLE_STAR - 72))
      | (1ULL << (PyScriptParser::IDENTIFIER - 72))
      | (1ULL << (PyScriptParser::INTEGER - 72))
      | (1ULL << (PyScriptParser::FLOAT - 72))
      | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
      setState(634);
      argumentList();
    }
    setState(637);
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
  enterRule(_localctx, 112, PyScriptParser::RuleAtom);

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
    setState(639);
    primary();
    setState(643);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(640);
        postfixOp(); 
      }
      setState(645);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
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
  enterRule(_localctx, 114, PyScriptParser::RulePostfixOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(657);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::DOT: {
        _localctx = _tracker.createInstance<PyScriptParser::AttributeAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(646);
        match(PyScriptParser::DOT);
        setState(647);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::LBRACK: {
        _localctx = _tracker.createInstance<PyScriptParser::SubscriptAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(648);
        match(PyScriptParser::LBRACK);
        setState(649);
        subscriptArg();
        setState(650);
        match(PyScriptParser::RBRACK);
        break;
      }

      case PyScriptParser::LPAREN: {
        _localctx = _tracker.createInstance<PyScriptParser::FunctionCallOpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(652);
        match(PyScriptParser::LPAREN);
        setState(654);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::YIELD)
          | (1ULL << PyScriptParser::AWAIT)
          | (1ULL << PyScriptParser::TRUE)
          | (1ULL << PyScriptParser::FALSE)
          | (1ULL << PyScriptParser::NONE)
          | (1ULL << PyScriptParser::NOT)
          | (1ULL << PyScriptParser::PLUS)
          | (1ULL << PyScriptParser::MINUS)
          | (1ULL << PyScriptParser::MUL)
          | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
          | (1ULL << (PyScriptParser::LBRACK - 72))
          | (1ULL << (PyScriptParser::LBRACE - 72))
          | (1ULL << (PyScriptParser::DOUBLE_STAR - 72))
          | (1ULL << (PyScriptParser::IDENTIFIER - 72))
          | (1ULL << (PyScriptParser::INTEGER - 72))
          | (1ULL << (PyScriptParser::FLOAT - 72))
          | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
          setState(653);
          argumentList();
        }
        setState(656);
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
  enterRule(_localctx, 116, PyScriptParser::RuleSubscriptArg);
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
    setState(660);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::YIELD)
      | (1ULL << PyScriptParser::AWAIT)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
      | (1ULL << (PyScriptParser::LBRACK - 72))
      | (1ULL << (PyScriptParser::LBRACE - 72))
      | (1ULL << (PyScriptParser::IDENTIFIER - 72))
      | (1ULL << (PyScriptParser::INTEGER - 72))
      | (1ULL << (PyScriptParser::FLOAT - 72))
      | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
      setState(659);
      expression();
    }
    setState(672);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COLON) {
      setState(662);
      match(PyScriptParser::COLON);
      setState(664);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
        | (1ULL << PyScriptParser::LAMBDA)
        | (1ULL << PyScriptParser::YIELD)
        | (1ULL << PyScriptParser::AWAIT)
        | (1ULL << PyScriptParser::TRUE)
        | (1ULL << PyScriptParser::FALSE)
        | (1ULL << PyScriptParser::NONE)
        | (1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS)
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
        | (1ULL << (PyScriptParser::LBRACK - 72))
        | (1ULL << (PyScriptParser::LBRACE - 72))
        | (1ULL << (PyScriptParser::IDENTIFIER - 72))
        | (1ULL << (PyScriptParser::INTEGER - 72))
        | (1ULL << (PyScriptParser::FLOAT - 72))
        | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
        setState(663);
        expression();
      }
      setState(670);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COLON) {
        setState(666);
        match(PyScriptParser::COLON);
        setState(668);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::YIELD)
          | (1ULL << PyScriptParser::AWAIT)
          | (1ULL << PyScriptParser::TRUE)
          | (1ULL << PyScriptParser::FALSE)
          | (1ULL << PyScriptParser::NONE)
          | (1ULL << PyScriptParser::NOT)
          | (1ULL << PyScriptParser::PLUS)
          | (1ULL << PyScriptParser::MINUS)
          | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
          | (1ULL << (PyScriptParser::LBRACK - 72))
          | (1ULL << (PyScriptParser::LBRACE - 72))
          | (1ULL << (PyScriptParser::IDENTIFIER - 72))
          | (1ULL << (PyScriptParser::INTEGER - 72))
          | (1ULL << (PyScriptParser::FLOAT - 72))
          | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
          setState(667);
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
  enterRule(_localctx, 118, PyScriptParser::RuleArgumentList);
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
    setState(674);
    argument();
    setState(679);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(675);
        match(PyScriptParser::COMMA);
        setState(676);
        argument(); 
      }
      setState(681);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    }
    setState(683);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::COMMA) {
      setState(682);
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
  enterRule(_localctx, 120, PyScriptParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(693);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(685);
      match(PyScriptParser::IDENTIFIER);
      setState(686);
      match(PyScriptParser::ASSIGN);
      setState(687);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(688);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(689);
      match(PyScriptParser::MUL);
      setState(690);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(691);
      match(PyScriptParser::DOUBLE_STAR);
      setState(692);
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
  enterRule(_localctx, 122, PyScriptParser::RuleListLiteral);
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
    setState(695);
    match(PyScriptParser::LBRACK);
    setState(697);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::YIELD)
      | (1ULL << PyScriptParser::AWAIT)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
      | (1ULL << (PyScriptParser::LBRACK - 72))
      | (1ULL << (PyScriptParser::LBRACE - 72))
      | (1ULL << (PyScriptParser::IDENTIFIER - 72))
      | (1ULL << (PyScriptParser::INTEGER - 72))
      | (1ULL << (PyScriptParser::FLOAT - 72))
      | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
      setState(696);
      listElements();
    }
    setState(699);
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
  enterRule(_localctx, 124, PyScriptParser::RuleListElements);
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
    setState(713);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(701);
      expression();
      setState(706);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(702);
          match(PyScriptParser::COMMA);
          setState(703);
          expression(); 
        }
        setState(708);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
      }
      setState(710);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(709);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(712);
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
  enterRule(_localctx, 126, PyScriptParser::RuleComprehension);
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
    setState(715);
    expression();
    setState(717); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(716);
      compFor();
      setState(719); 
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
  enterRule(_localctx, 128, PyScriptParser::RuleCompFor);
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
    setState(721);
    match(PyScriptParser::FOR);
    setState(724);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      setState(722);
      match(PyScriptParser::IDENTIFIER);
      break;
    }

    case 2: {
      setState(723);
      tupleLiteral();
      break;
    }

    default:
      break;
    }
    setState(726);
    match(PyScriptParser::IN);
    setState(727);
    expression();
    setState(730);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IF) {
      setState(728);
      match(PyScriptParser::IF);
      setState(729);
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
  enterRule(_localctx, 130, PyScriptParser::RuleDictLiteral);
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
    setState(732);
    match(PyScriptParser::LBRACE);
    setState(747);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(733);
      dictComprehension();
      break;
    }

    case 2: {
      setState(745);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
        | (1ULL << PyScriptParser::LAMBDA)
        | (1ULL << PyScriptParser::YIELD)
        | (1ULL << PyScriptParser::AWAIT)
        | (1ULL << PyScriptParser::TRUE)
        | (1ULL << PyScriptParser::FALSE)
        | (1ULL << PyScriptParser::NONE)
        | (1ULL << PyScriptParser::NOT)
        | (1ULL << PyScriptParser::PLUS)
        | (1ULL << PyScriptParser::MINUS)
        | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
        | (1ULL << (PyScriptParser::LBRACK - 72))
        | (1ULL << (PyScriptParser::LBRACE - 72))
        | (1ULL << (PyScriptParser::DOUBLE_STAR - 72))
        | (1ULL << (PyScriptParser::IDENTIFIER - 72))
        | (1ULL << (PyScriptParser::INTEGER - 72))
        | (1ULL << (PyScriptParser::FLOAT - 72))
        | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
        setState(734);
        dictItem();
        setState(739);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(735);
            match(PyScriptParser::COMMA);
            setState(736);
            dictItem(); 
          }
          setState(741);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
        }
        setState(743);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PyScriptParser::COMMA) {
          setState(742);
          match(PyScriptParser::COMMA);
        }
      }
      break;
    }

    default:
      break;
    }
    setState(749);
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
  enterRule(_localctx, 132, PyScriptParser::RuleDictComprehension);
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
    setState(751);
    expression();
    setState(752);
    match(PyScriptParser::COLON);
    setState(753);
    expression();
    setState(755); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(754);
      compFor();
      setState(757); 
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
  enterRule(_localctx, 134, PyScriptParser::RuleDictItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(765);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::NEW:
      case PyScriptParser::LAMBDA:
      case PyScriptParser::YIELD:
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
        setState(759);
        expression();
        setState(760);
        match(PyScriptParser::COLON);
        setState(761);
        expression();
        break;
      }

      case PyScriptParser::DOUBLE_STAR: {
        enterOuterAlt(_localctx, 2);
        setState(763);
        match(PyScriptParser::DOUBLE_STAR);
        setState(764);
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
  enterRule(_localctx, 136, PyScriptParser::RuleSetLiteral);
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
    setState(767);
    match(PyScriptParser::LBRACE);
    setState(769);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::YIELD)
      | (1ULL << PyScriptParser::AWAIT)
      | (1ULL << PyScriptParser::TRUE)
      | (1ULL << PyScriptParser::FALSE)
      | (1ULL << PyScriptParser::NONE)
      | (1ULL << PyScriptParser::NOT)
      | (1ULL << PyScriptParser::PLUS)
      | (1ULL << PyScriptParser::MINUS)
      | (1ULL << PyScriptParser::BITWISE_NOT))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (PyScriptParser::LPAREN - 72))
      | (1ULL << (PyScriptParser::LBRACK - 72))
      | (1ULL << (PyScriptParser::LBRACE - 72))
      | (1ULL << (PyScriptParser::IDENTIFIER - 72))
      | (1ULL << (PyScriptParser::INTEGER - 72))
      | (1ULL << (PyScriptParser::FLOAT - 72))
      | (1ULL << (PyScriptParser::STRING - 72)))) != 0)) {
      setState(768);
      setElements();
    }
    setState(771);
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
  enterRule(_localctx, 138, PyScriptParser::RuleSetElements);
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
    setState(785);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(773);
      expression();
      setState(778);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(774);
          match(PyScriptParser::COMMA);
          setState(775);
          expression(); 
        }
        setState(780);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      }
      setState(782);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PyScriptParser::COMMA) {
        setState(781);
        match(PyScriptParser::COMMA);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(784);
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
  enterRule(_localctx, 140, PyScriptParser::RuleGeneratorExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(787);
    match(PyScriptParser::LPAREN);
    setState(788);
    comprehension();
    setState(789);
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
  enterRule(_localctx, 142, PyScriptParser::RuleLiteral);
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
    setState(791);
    _la = _input->LA(1);
    if (!(((((_la - 30) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 30)) & ((1ULL << (PyScriptParser::TRUE - 30))
      | (1ULL << (PyScriptParser::FALSE - 30))
      | (1ULL << (PyScriptParser::NONE - 30))
      | (1ULL << (PyScriptParser::INTEGER - 30))
      | (1ULL << (PyScriptParser::FLOAT - 30))
      | (1ULL << (PyScriptParser::STRING - 30)))) != 0))) {
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
  enterRule(_localctx, 144, PyScriptParser::RuleLambdaExpression);
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
    setState(793);
    match(PyScriptParser::LAMBDA);
    setState(795);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 41) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 41)) & ((1ULL << (PyScriptParser::MUL - 41))
      | (1ULL << (PyScriptParser::DOUBLE_STAR - 41))
      | (1ULL << (PyScriptParser::IDENTIFIER - 41)))) != 0)) {
      setState(794);
      parameterList();
    }
    setState(797);
    match(PyScriptParser::COLON);
    setState(798);
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
  enterRule(_localctx, 146, PyScriptParser::RuleDottedName);
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
    setState(800);
    match(PyScriptParser::IDENTIFIER);
    setState(805);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::DOT) {
      setState(801);
      match(PyScriptParser::DOT);
      setState(802);
      match(PyScriptParser::IDENTIFIER);
      setState(807);
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
