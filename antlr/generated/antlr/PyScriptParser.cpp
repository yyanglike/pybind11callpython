
// Generated from antlr/PyScript.g4 by ANTLR 4.10.1


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
      "ifStatement", "whileStatement", "forStatement", "forControl", "forInit", 
      "forUpdate", "returnStatement", "block", "assignment", "assignmentOperator", 
      "expressionStatement", "expression", "ternaryExpression", "logicalOrExpression", 
      "logicalAndExpression", "equalityExpression", "relationalExpression", 
      "additiveExpression", "multiplicativeExpression", "unaryExpression", 
      "callOrPrimary", "postfixOp", "attributeAccess", "subscriptAccess", 
      "functionCall", "primaryExpression", "newExpression", "literal", "listLiteral", 
      "dictLiteral", "listComprehension", "lambdaExpression", "dottedName", 
      "argumentList", "expressionList", "dictItemList", "dictItem"
    },
    std::vector<std::string>{
      "", "';'", "'('", "')'", "','", "'{'", "'}'", "'='", "'+='", "'-='", 
      "'*='", "'/='", "'%='", "'\\u003F'", "':'", "'||'", "'&&'", "'=='", 
      "'!='", "'<'", "'>'", "'<='", "'>='", "'+'", "'-'", "'*'", "'/'", 
      "'%'", "'!'", "'.'", "'['", "']'", "'in'", "'**'", "'return'", "'if'", 
      "'else'", "'while'", "'for'", "'def'", "'import'", "'as'", "'new'", 
      "'lambda'", "", "", "", "", "", "'null'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "RETURN", "IF", "ELSE", "WHILE", "FOR", "DEF", "IMPORT", "AS", "NEW", 
      "LAMBDA", "IDENTIFIER", "INTEGER", "FLOAT", "STRING", "BOOL", "NULL_LIT", 
      "WS", "COMMENT", "MULTILINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,52,422,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,1,0,4,
  	0,86,8,0,11,0,12,0,87,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,100,
  	8,1,1,2,1,2,1,2,1,2,3,2,106,8,2,1,2,3,2,109,8,2,1,3,1,3,1,3,1,3,3,3,115,
  	8,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,123,8,4,10,4,12,4,126,9,4,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,3,5,135,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,8,3,8,150,8,8,1,8,1,8,3,8,154,8,8,1,8,1,8,3,8,158,8,8,1,9,1,9,
  	1,10,1,10,1,11,1,11,3,11,166,8,11,1,11,3,11,169,8,11,1,12,1,12,5,12,173,
  	8,12,10,12,12,12,176,9,12,1,12,1,12,1,13,1,13,1,13,1,13,3,13,184,8,13,
  	1,13,1,13,1,13,1,13,3,13,190,8,13,1,13,1,13,1,13,1,13,3,13,196,8,13,3,
  	13,198,8,13,1,14,1,14,1,15,1,15,3,15,204,8,15,1,16,1,16,3,16,208,8,16,
  	1,17,1,17,1,17,1,17,1,17,1,17,3,17,216,8,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,3,17,224,8,17,3,17,226,8,17,1,18,1,18,1,18,5,18,231,8,18,10,18,12,
  	18,234,9,18,1,19,1,19,1,19,5,19,239,8,19,10,19,12,19,242,9,19,1,20,1,
  	20,1,20,5,20,247,8,20,10,20,12,20,250,9,20,1,21,1,21,1,21,5,21,255,8,
  	21,10,21,12,21,258,9,21,1,22,1,22,1,22,5,22,263,8,22,10,22,12,22,266,
  	9,22,1,23,1,23,1,23,5,23,271,8,23,10,23,12,23,274,9,23,1,24,3,24,277,
  	8,24,1,24,1,24,1,25,1,25,5,25,283,8,25,10,25,12,25,286,9,25,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,3,26,296,8,26,1,26,3,26,299,8,26,1,27,1,
  	27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,
  	29,3,29,317,8,29,1,29,1,29,3,29,321,8,29,1,29,1,29,1,30,1,30,1,30,1,30,
  	1,30,1,30,1,30,1,30,1,30,1,30,1,30,3,30,336,8,30,1,31,1,31,1,31,1,31,
  	3,31,342,8,31,1,31,1,31,1,32,1,32,1,33,1,33,3,33,350,8,33,1,33,1,33,1,
  	34,1,34,3,34,356,8,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,
  	35,1,36,1,36,1,36,1,36,5,36,372,8,36,10,36,12,36,375,9,36,3,36,377,8,
  	36,1,36,1,36,1,36,1,37,1,37,1,37,5,37,385,8,37,10,37,12,37,388,9,37,1,
  	38,1,38,1,38,5,38,393,8,38,10,38,12,38,396,9,38,1,39,1,39,1,39,5,39,401,
  	8,39,10,39,12,39,404,9,39,1,40,1,40,1,40,5,40,409,8,40,10,40,12,40,412,
  	9,40,1,41,1,41,1,41,1,41,1,41,1,41,3,41,420,8,41,1,41,0,0,42,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,60,62,64,66,68,70,72,74,76,78,80,82,0,7,1,0,7,12,1,0,17,18,1,0,
  	19,22,1,0,23,24,1,0,25,27,2,0,24,24,28,28,1,0,45,49,440,0,85,1,0,0,0,
  	2,99,1,0,0,0,4,101,1,0,0,0,6,110,1,0,0,0,8,119,1,0,0,0,10,127,1,0,0,0,
  	12,136,1,0,0,0,14,142,1,0,0,0,16,149,1,0,0,0,18,159,1,0,0,0,20,161,1,
  	0,0,0,22,163,1,0,0,0,24,170,1,0,0,0,26,197,1,0,0,0,28,199,1,0,0,0,30,
  	201,1,0,0,0,32,207,1,0,0,0,34,225,1,0,0,0,36,227,1,0,0,0,38,235,1,0,0,
  	0,40,243,1,0,0,0,42,251,1,0,0,0,44,259,1,0,0,0,46,267,1,0,0,0,48,276,
  	1,0,0,0,50,280,1,0,0,0,52,298,1,0,0,0,54,300,1,0,0,0,56,304,1,0,0,0,58,
  	316,1,0,0,0,60,335,1,0,0,0,62,337,1,0,0,0,64,345,1,0,0,0,66,347,1,0,0,
  	0,68,353,1,0,0,0,70,359,1,0,0,0,72,367,1,0,0,0,74,381,1,0,0,0,76,389,
  	1,0,0,0,78,397,1,0,0,0,80,405,1,0,0,0,82,419,1,0,0,0,84,86,3,2,1,0,85,
  	84,1,0,0,0,86,87,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,89,1,0,0,0,89,
  	90,5,0,0,1,90,1,1,0,0,0,91,100,3,4,2,0,92,100,3,6,3,0,93,100,3,26,13,
  	0,94,100,3,10,5,0,95,100,3,12,6,0,96,100,3,14,7,0,97,100,3,22,11,0,98,
  	100,3,30,15,0,99,91,1,0,0,0,99,92,1,0,0,0,99,93,1,0,0,0,99,94,1,0,0,0,
  	99,95,1,0,0,0,99,96,1,0,0,0,99,97,1,0,0,0,99,98,1,0,0,0,100,3,1,0,0,0,
  	101,102,5,40,0,0,102,105,3,74,37,0,103,104,5,41,0,0,104,106,5,44,0,0,
  	105,103,1,0,0,0,105,106,1,0,0,0,106,108,1,0,0,0,107,109,5,1,0,0,108,107,
  	1,0,0,0,108,109,1,0,0,0,109,5,1,0,0,0,110,111,5,39,0,0,111,112,5,44,0,
  	0,112,114,5,2,0,0,113,115,3,8,4,0,114,113,1,0,0,0,114,115,1,0,0,0,115,
  	116,1,0,0,0,116,117,5,3,0,0,117,118,3,24,12,0,118,7,1,0,0,0,119,124,5,
  	44,0,0,120,121,5,4,0,0,121,123,5,44,0,0,122,120,1,0,0,0,123,126,1,0,0,
  	0,124,122,1,0,0,0,124,125,1,0,0,0,125,9,1,0,0,0,126,124,1,0,0,0,127,128,
  	5,35,0,0,128,129,5,2,0,0,129,130,3,32,16,0,130,131,5,3,0,0,131,134,3,
  	24,12,0,132,133,5,36,0,0,133,135,3,24,12,0,134,132,1,0,0,0,134,135,1,
  	0,0,0,135,11,1,0,0,0,136,137,5,37,0,0,137,138,5,2,0,0,138,139,3,32,16,
  	0,139,140,5,3,0,0,140,141,3,24,12,0,141,13,1,0,0,0,142,143,5,38,0,0,143,
  	144,5,2,0,0,144,145,3,16,8,0,145,146,5,3,0,0,146,147,3,24,12,0,147,15,
  	1,0,0,0,148,150,3,18,9,0,149,148,1,0,0,0,149,150,1,0,0,0,150,151,1,0,
  	0,0,151,153,5,1,0,0,152,154,3,32,16,0,153,152,1,0,0,0,153,154,1,0,0,0,
  	154,155,1,0,0,0,155,157,5,1,0,0,156,158,3,20,10,0,157,156,1,0,0,0,157,
  	158,1,0,0,0,158,17,1,0,0,0,159,160,3,26,13,0,160,19,1,0,0,0,161,162,3,
  	26,13,0,162,21,1,0,0,0,163,165,5,34,0,0,164,166,3,32,16,0,165,164,1,0,
  	0,0,165,166,1,0,0,0,166,168,1,0,0,0,167,169,5,1,0,0,168,167,1,0,0,0,168,
  	169,1,0,0,0,169,23,1,0,0,0,170,174,5,5,0,0,171,173,3,2,1,0,172,171,1,
  	0,0,0,173,176,1,0,0,0,174,172,1,0,0,0,174,175,1,0,0,0,175,177,1,0,0,0,
  	176,174,1,0,0,0,177,178,5,6,0,0,178,25,1,0,0,0,179,180,5,44,0,0,180,181,
  	3,28,14,0,181,183,3,32,16,0,182,184,5,1,0,0,183,182,1,0,0,0,183,184,1,
  	0,0,0,184,198,1,0,0,0,185,186,3,54,27,0,186,187,5,7,0,0,187,189,3,32,
  	16,0,188,190,5,1,0,0,189,188,1,0,0,0,189,190,1,0,0,0,190,198,1,0,0,0,
  	191,192,3,56,28,0,192,193,5,7,0,0,193,195,3,32,16,0,194,196,5,1,0,0,195,
  	194,1,0,0,0,195,196,1,0,0,0,196,198,1,0,0,0,197,179,1,0,0,0,197,185,1,
  	0,0,0,197,191,1,0,0,0,198,27,1,0,0,0,199,200,7,0,0,0,200,29,1,0,0,0,201,
  	203,3,32,16,0,202,204,5,1,0,0,203,202,1,0,0,0,203,204,1,0,0,0,204,31,
  	1,0,0,0,205,208,3,26,13,0,206,208,3,34,17,0,207,205,1,0,0,0,207,206,1,
  	0,0,0,208,33,1,0,0,0,209,215,3,36,18,0,210,211,5,35,0,0,211,212,3,36,
  	18,0,212,213,5,36,0,0,213,214,3,34,17,0,214,216,1,0,0,0,215,210,1,0,0,
  	0,215,216,1,0,0,0,216,226,1,0,0,0,217,223,3,36,18,0,218,219,5,13,0,0,
  	219,220,3,32,16,0,220,221,5,14,0,0,221,222,3,34,17,0,222,224,1,0,0,0,
  	223,218,1,0,0,0,223,224,1,0,0,0,224,226,1,0,0,0,225,209,1,0,0,0,225,217,
  	1,0,0,0,226,35,1,0,0,0,227,232,3,38,19,0,228,229,5,15,0,0,229,231,3,38,
  	19,0,230,228,1,0,0,0,231,234,1,0,0,0,232,230,1,0,0,0,232,233,1,0,0,0,
  	233,37,1,0,0,0,234,232,1,0,0,0,235,240,3,40,20,0,236,237,5,16,0,0,237,
  	239,3,40,20,0,238,236,1,0,0,0,239,242,1,0,0,0,240,238,1,0,0,0,240,241,
  	1,0,0,0,241,39,1,0,0,0,242,240,1,0,0,0,243,248,3,42,21,0,244,245,7,1,
  	0,0,245,247,3,42,21,0,246,244,1,0,0,0,247,250,1,0,0,0,248,246,1,0,0,0,
  	248,249,1,0,0,0,249,41,1,0,0,0,250,248,1,0,0,0,251,256,3,44,22,0,252,
  	253,7,2,0,0,253,255,3,44,22,0,254,252,1,0,0,0,255,258,1,0,0,0,256,254,
  	1,0,0,0,256,257,1,0,0,0,257,43,1,0,0,0,258,256,1,0,0,0,259,264,3,46,23,
  	0,260,261,7,3,0,0,261,263,3,46,23,0,262,260,1,0,0,0,263,266,1,0,0,0,264,
  	262,1,0,0,0,264,265,1,0,0,0,265,45,1,0,0,0,266,264,1,0,0,0,267,272,3,
  	48,24,0,268,269,7,4,0,0,269,271,3,48,24,0,270,268,1,0,0,0,271,274,1,0,
  	0,0,272,270,1,0,0,0,272,273,1,0,0,0,273,47,1,0,0,0,274,272,1,0,0,0,275,
  	277,7,5,0,0,276,275,1,0,0,0,276,277,1,0,0,0,277,278,1,0,0,0,278,279,3,
  	50,25,0,279,49,1,0,0,0,280,284,3,60,30,0,281,283,3,52,26,0,282,281,1,
  	0,0,0,283,286,1,0,0,0,284,282,1,0,0,0,284,285,1,0,0,0,285,51,1,0,0,0,
  	286,284,1,0,0,0,287,288,5,29,0,0,288,299,5,44,0,0,289,290,5,30,0,0,290,
  	291,3,32,16,0,291,292,5,31,0,0,292,299,1,0,0,0,293,295,5,2,0,0,294,296,
  	3,76,38,0,295,294,1,0,0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,299,5,3,
  	0,0,298,287,1,0,0,0,298,289,1,0,0,0,298,293,1,0,0,0,299,53,1,0,0,0,300,
  	301,3,60,30,0,301,302,5,29,0,0,302,303,5,44,0,0,303,55,1,0,0,0,304,305,
  	3,60,30,0,305,306,5,30,0,0,306,307,3,32,16,0,307,308,5,31,0,0,308,57,
  	1,0,0,0,309,317,3,74,37,0,310,317,3,54,27,0,311,317,3,56,28,0,312,313,
  	5,2,0,0,313,314,3,32,16,0,314,315,5,3,0,0,315,317,1,0,0,0,316,309,1,0,
  	0,0,316,310,1,0,0,0,316,311,1,0,0,0,316,312,1,0,0,0,317,318,1,0,0,0,318,
  	320,5,2,0,0,319,321,3,76,38,0,320,319,1,0,0,0,320,321,1,0,0,0,321,322,
  	1,0,0,0,322,323,5,3,0,0,323,59,1,0,0,0,324,336,3,64,32,0,325,336,3,74,
  	37,0,326,327,5,2,0,0,327,328,3,32,16,0,328,329,5,3,0,0,329,336,1,0,0,
  	0,330,336,3,66,33,0,331,336,3,68,34,0,332,336,3,62,31,0,333,336,3,72,
  	36,0,334,336,3,70,35,0,335,324,1,0,0,0,335,325,1,0,0,0,335,326,1,0,0,
  	0,335,330,1,0,0,0,335,331,1,0,0,0,335,332,1,0,0,0,335,333,1,0,0,0,335,
  	334,1,0,0,0,336,61,1,0,0,0,337,338,5,42,0,0,338,339,3,74,37,0,339,341,
  	5,2,0,0,340,342,3,76,38,0,341,340,1,0,0,0,341,342,1,0,0,0,342,343,1,0,
  	0,0,343,344,5,3,0,0,344,63,1,0,0,0,345,346,7,6,0,0,346,65,1,0,0,0,347,
  	349,5,30,0,0,348,350,3,78,39,0,349,348,1,0,0,0,349,350,1,0,0,0,350,351,
  	1,0,0,0,351,352,5,31,0,0,352,67,1,0,0,0,353,355,5,5,0,0,354,356,3,80,
  	40,0,355,354,1,0,0,0,355,356,1,0,0,0,356,357,1,0,0,0,357,358,5,6,0,0,
  	358,69,1,0,0,0,359,360,5,30,0,0,360,361,3,32,16,0,361,362,5,38,0,0,362,
  	363,5,44,0,0,363,364,5,32,0,0,364,365,3,32,16,0,365,366,5,31,0,0,366,
  	71,1,0,0,0,367,376,5,43,0,0,368,373,5,44,0,0,369,370,5,4,0,0,370,372,
  	5,44,0,0,371,369,1,0,0,0,372,375,1,0,0,0,373,371,1,0,0,0,373,374,1,0,
  	0,0,374,377,1,0,0,0,375,373,1,0,0,0,376,368,1,0,0,0,376,377,1,0,0,0,377,
  	378,1,0,0,0,378,379,5,14,0,0,379,380,3,32,16,0,380,73,1,0,0,0,381,386,
  	5,44,0,0,382,383,5,29,0,0,383,385,5,44,0,0,384,382,1,0,0,0,385,388,1,
  	0,0,0,386,384,1,0,0,0,386,387,1,0,0,0,387,75,1,0,0,0,388,386,1,0,0,0,
  	389,394,3,32,16,0,390,391,5,4,0,0,391,393,3,32,16,0,392,390,1,0,0,0,393,
  	396,1,0,0,0,394,392,1,0,0,0,394,395,1,0,0,0,395,77,1,0,0,0,396,394,1,
  	0,0,0,397,402,3,32,16,0,398,399,5,4,0,0,399,401,3,32,16,0,400,398,1,0,
  	0,0,401,404,1,0,0,0,402,400,1,0,0,0,402,403,1,0,0,0,403,79,1,0,0,0,404,
  	402,1,0,0,0,405,410,3,82,41,0,406,407,5,4,0,0,407,409,3,82,41,0,408,406,
  	1,0,0,0,409,412,1,0,0,0,410,408,1,0,0,0,410,411,1,0,0,0,411,81,1,0,0,
  	0,412,410,1,0,0,0,413,414,3,32,16,0,414,415,5,14,0,0,415,416,3,32,16,
  	0,416,420,1,0,0,0,417,418,5,33,0,0,418,420,3,32,16,0,419,413,1,0,0,0,
  	419,417,1,0,0,0,420,83,1,0,0,0,45,87,99,105,108,114,124,134,149,153,157,
  	165,168,174,183,189,195,197,203,207,215,223,225,232,240,248,256,264,272,
  	276,284,295,298,316,320,335,341,349,355,373,376,386,394,402,410,419
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
    setState(85); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(84);
      statement();
      setState(87); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__23)
      | (1ULL << PyScriptParser::T__27)
      | (1ULL << PyScriptParser::T__29)
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
    setState(89);
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
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(91);
      importStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(92);
      functionDefinition();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(93);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(94);
      ifStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(95);
      whileStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(96);
      forStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(97);
      returnStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(98);
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


size_t PyScriptParser::ImportStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleImportStatement;
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
    setState(101);
    match(PyScriptParser::IMPORT);
    setState(102);
    dottedName();
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::AS) {
      setState(103);
      match(PyScriptParser::AS);
      setState(104);
      match(PyScriptParser::IDENTIFIER);
    }
    setState(108);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__0) {
      setState(107);
      match(PyScriptParser::T__0);
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

PyScriptParser::BlockContext* PyScriptParser::FunctionDefinitionContext::block() {
  return getRuleContext<PyScriptParser::BlockContext>(0);
}

PyScriptParser::ParameterListContext* PyScriptParser::FunctionDefinitionContext::parameterList() {
  return getRuleContext<PyScriptParser::ParameterListContext>(0);
}


size_t PyScriptParser::FunctionDefinitionContext::getRuleIndex() const {
  return PyScriptParser::RuleFunctionDefinition;
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
    setState(110);
    match(PyScriptParser::DEF);
    setState(111);
    match(PyScriptParser::IDENTIFIER);
    setState(112);
    match(PyScriptParser::T__1);
    setState(114);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IDENTIFIER) {
      setState(113);
      parameterList();
    }
    setState(116);
    match(PyScriptParser::T__2);
    setState(117);
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

std::vector<tree::TerminalNode *> PyScriptParser::ParameterListContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::ParameterListContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
}


size_t PyScriptParser::ParameterListContext::getRuleIndex() const {
  return PyScriptParser::RuleParameterList;
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
    setState(119);
    match(PyScriptParser::IDENTIFIER);
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__3) {
      setState(120);
      match(PyScriptParser::T__3);
      setState(121);
      match(PyScriptParser::IDENTIFIER);
      setState(126);
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

//----------------- IfStatementContext ------------------------------------------------------------------

PyScriptParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PyScriptParser::IfStatementContext::IF() {
  return getToken(PyScriptParser::IF, 0);
}

PyScriptParser::ExpressionContext* PyScriptParser::IfStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
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


std::any PyScriptParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::IfStatementContext* PyScriptParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, PyScriptParser::RuleIfStatement);
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
    setState(127);
    match(PyScriptParser::IF);
    setState(128);
    match(PyScriptParser::T__1);
    setState(129);
    expression();
    setState(130);
    match(PyScriptParser::T__2);
    setState(131);
    block();
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::ELSE) {
      setState(132);
      match(PyScriptParser::ELSE);
      setState(133);
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

PyScriptParser::ExpressionContext* PyScriptParser::WhileStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::BlockContext* PyScriptParser::WhileStatementContext::block() {
  return getRuleContext<PyScriptParser::BlockContext>(0);
}


size_t PyScriptParser::WhileStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleWhileStatement;
}


std::any PyScriptParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::WhileStatementContext* PyScriptParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, PyScriptParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(PyScriptParser::WHILE);
    setState(137);
    match(PyScriptParser::T__1);
    setState(138);
    expression();
    setState(139);
    match(PyScriptParser::T__2);
    setState(140);
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

PyScriptParser::ForControlContext* PyScriptParser::ForStatementContext::forControl() {
  return getRuleContext<PyScriptParser::ForControlContext>(0);
}

PyScriptParser::BlockContext* PyScriptParser::ForStatementContext::block() {
  return getRuleContext<PyScriptParser::BlockContext>(0);
}


size_t PyScriptParser::ForStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleForStatement;
}


std::any PyScriptParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ForStatementContext* PyScriptParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, PyScriptParser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(PyScriptParser::FOR);
    setState(143);
    match(PyScriptParser::T__1);
    setState(144);
    forControl();
    setState(145);
    match(PyScriptParser::T__2);
    setState(146);
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


std::any PyScriptParser::ForControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitForControl(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ForControlContext* PyScriptParser::forControl() {
  ForControlContext *_localctx = _tracker.createInstance<ForControlContext>(_ctx, getState());
  enterRule(_localctx, 16, PyScriptParser::RuleForControl);
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
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__29)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(148);
      forInit();
    }
    setState(151);
    match(PyScriptParser::T__0);
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__23)
      | (1ULL << PyScriptParser::T__27)
      | (1ULL << PyScriptParser::T__29)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(152);
      expression();
    }
    setState(155);
    match(PyScriptParser::T__0);
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__29)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(156);
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


std::any PyScriptParser::ForInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitForInit(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ForInitContext* PyScriptParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 18, PyScriptParser::RuleForInit);

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


std::any PyScriptParser::ForUpdateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitForUpdate(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ForUpdateContext* PyScriptParser::forUpdate() {
  ForUpdateContext *_localctx = _tracker.createInstance<ForUpdateContext>(_ctx, getState());
  enterRule(_localctx, 20, PyScriptParser::RuleForUpdate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
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


size_t PyScriptParser::ReturnStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleReturnStatement;
}


std::any PyScriptParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ReturnStatementContext* PyScriptParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, PyScriptParser::RuleReturnStatement);
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
    setState(163);
    match(PyScriptParser::RETURN);
    setState(165);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(164);
      expression();
      break;
    }

    default:
      break;
    }
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__0) {
      setState(167);
      match(PyScriptParser::T__0);
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

std::vector<PyScriptParser::StatementContext *> PyScriptParser::BlockContext::statement() {
  return getRuleContexts<PyScriptParser::StatementContext>();
}

PyScriptParser::StatementContext* PyScriptParser::BlockContext::statement(size_t i) {
  return getRuleContext<PyScriptParser::StatementContext>(i);
}


size_t PyScriptParser::BlockContext::getRuleIndex() const {
  return PyScriptParser::RuleBlock;
}


std::any PyScriptParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::BlockContext* PyScriptParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 24, PyScriptParser::RuleBlock);
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
    setState(170);
    match(PyScriptParser::T__4);
    setState(174);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__23)
      | (1ULL << PyScriptParser::T__27)
      | (1ULL << PyScriptParser::T__29)
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
      setState(171);
      statement();
      setState(176);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(177);
    match(PyScriptParser::T__5);
   
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

PyScriptParser::AttributeAccessContext* PyScriptParser::AssignmentContext::attributeAccess() {
  return getRuleContext<PyScriptParser::AttributeAccessContext>(0);
}

PyScriptParser::SubscriptAccessContext* PyScriptParser::AssignmentContext::subscriptAccess() {
  return getRuleContext<PyScriptParser::SubscriptAccessContext>(0);
}


size_t PyScriptParser::AssignmentContext::getRuleIndex() const {
  return PyScriptParser::RuleAssignment;
}


std::any PyScriptParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AssignmentContext* PyScriptParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 26, PyScriptParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(179);
      match(PyScriptParser::IDENTIFIER);
      setState(180);
      assignmentOperator();
      setState(181);
      expression();
      setState(183);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(182);
        match(PyScriptParser::T__0);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(185);
      attributeAccess();
      setState(186);
      match(PyScriptParser::T__6);
      setState(187);
      expression();
      setState(189);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(188);
        match(PyScriptParser::T__0);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(191);
      subscriptAccess();
      setState(192);
      match(PyScriptParser::T__6);
      setState(193);
      expression();
      setState(195);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(194);
        match(PyScriptParser::T__0);
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


size_t PyScriptParser::AssignmentOperatorContext::getRuleIndex() const {
  return PyScriptParser::RuleAssignmentOperator;
}


std::any PyScriptParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AssignmentOperatorContext* PyScriptParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 28, PyScriptParser::RuleAssignmentOperator);
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
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__6)
      | (1ULL << PyScriptParser::T__7)
      | (1ULL << PyScriptParser::T__8)
      | (1ULL << PyScriptParser::T__9)
      | (1ULL << PyScriptParser::T__10)
      | (1ULL << PyScriptParser::T__11))) != 0))) {
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


size_t PyScriptParser::ExpressionStatementContext::getRuleIndex() const {
  return PyScriptParser::RuleExpressionStatement;
}


std::any PyScriptParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ExpressionStatementContext* PyScriptParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, PyScriptParser::RuleExpressionStatement);
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
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__0) {
      setState(202);
      match(PyScriptParser::T__0);
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


std::any PyScriptParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ExpressionContext* PyScriptParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, PyScriptParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(205);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(206);
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

PyScriptParser::ExpressionContext* PyScriptParser::TernaryExpressionContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}


size_t PyScriptParser::TernaryExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleTernaryExpression;
}


std::any PyScriptParser::TernaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitTernaryExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::TernaryExpressionContext* PyScriptParser::ternaryExpression() {
  TernaryExpressionContext *_localctx = _tracker.createInstance<TernaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 34, PyScriptParser::RuleTernaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(209);
      logicalOrExpression();
      setState(215);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(210);
        match(PyScriptParser::IF);
        setState(211);
        logicalOrExpression();
        setState(212);
        match(PyScriptParser::ELSE);
        setState(213);
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
      setState(217);
      logicalOrExpression();
      setState(223);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(218);
        match(PyScriptParser::T__12);
        setState(219);
        expression();
        setState(220);
        match(PyScriptParser::T__13);
        setState(221);
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


size_t PyScriptParser::LogicalOrExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleLogicalOrExpression;
}


std::any PyScriptParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LogicalOrExpressionContext* PyScriptParser::logicalOrExpression() {
  LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 36, PyScriptParser::RuleLogicalOrExpression);

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
    setState(227);
    logicalAndExpression();
    setState(232);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(228);
        match(PyScriptParser::T__14);
        setState(229);
        logicalAndExpression(); 
      }
      setState(234);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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


size_t PyScriptParser::LogicalAndExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleLogicalAndExpression;
}


std::any PyScriptParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LogicalAndExpressionContext* PyScriptParser::logicalAndExpression() {
  LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, getState());
  enterRule(_localctx, 38, PyScriptParser::RuleLogicalAndExpression);

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
    setState(235);
    equalityExpression();
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(236);
        match(PyScriptParser::T__15);
        setState(237);
        equalityExpression(); 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
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


size_t PyScriptParser::EqualityExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleEqualityExpression;
}


std::any PyScriptParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::EqualityExpressionContext* PyScriptParser::equalityExpression() {
  EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, PyScriptParser::RuleEqualityExpression);
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
    relationalExpression();
    setState(248);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(244);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::T__16

        || _la == PyScriptParser::T__17)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(245);
        relationalExpression(); 
      }
      setState(250);
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


size_t PyScriptParser::RelationalExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleRelationalExpression;
}


std::any PyScriptParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::RelationalExpressionContext* PyScriptParser::relationalExpression() {
  RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 42, PyScriptParser::RuleRelationalExpression);
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
    setState(251);
    additiveExpression();
    setState(256);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(252);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::T__18)
          | (1ULL << PyScriptParser::T__19)
          | (1ULL << PyScriptParser::T__20)
          | (1ULL << PyScriptParser::T__21))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(253);
        additiveExpression(); 
      }
      setState(258);
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


size_t PyScriptParser::AdditiveExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleAdditiveExpression;
}


std::any PyScriptParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AdditiveExpressionContext* PyScriptParser::additiveExpression() {
  AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, getState());
  enterRule(_localctx, 44, PyScriptParser::RuleAdditiveExpression);
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
    multiplicativeExpression();
    setState(264);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(260);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::T__22

        || _la == PyScriptParser::T__23)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(261);
        multiplicativeExpression(); 
      }
      setState(266);
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

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

PyScriptParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::UnaryExpressionContext *> PyScriptParser::MultiplicativeExpressionContext::unaryExpression() {
  return getRuleContexts<PyScriptParser::UnaryExpressionContext>();
}

PyScriptParser::UnaryExpressionContext* PyScriptParser::MultiplicativeExpressionContext::unaryExpression(size_t i) {
  return getRuleContext<PyScriptParser::UnaryExpressionContext>(i);
}


size_t PyScriptParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleMultiplicativeExpression;
}


std::any PyScriptParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::MultiplicativeExpressionContext* PyScriptParser::multiplicativeExpression() {
  MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, PyScriptParser::RuleMultiplicativeExpression);
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
    setState(267);
    unaryExpression();
    setState(272);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(268);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::T__24)
          | (1ULL << PyScriptParser::T__25)
          | (1ULL << PyScriptParser::T__26))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(269);
        unaryExpression(); 
      }
      setState(274);
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

//----------------- UnaryExpressionContext ------------------------------------------------------------------

PyScriptParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::CallOrPrimaryContext* PyScriptParser::UnaryExpressionContext::callOrPrimary() {
  return getRuleContext<PyScriptParser::CallOrPrimaryContext>(0);
}


size_t PyScriptParser::UnaryExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleUnaryExpression;
}


std::any PyScriptParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::UnaryExpressionContext* PyScriptParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 48, PyScriptParser::RuleUnaryExpression);
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
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__23

    || _la == PyScriptParser::T__27) {
      setState(275);
      _la = _input->LA(1);
      if (!(_la == PyScriptParser::T__23

      || _la == PyScriptParser::T__27)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(278);
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


std::any PyScriptParser::CallOrPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitCallOrPrimary(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::CallOrPrimaryContext* PyScriptParser::callOrPrimary() {
  CallOrPrimaryContext *_localctx = _tracker.createInstance<CallOrPrimaryContext>(_ctx, getState());
  enterRule(_localctx, 50, PyScriptParser::RuleCallOrPrimary);

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
    setState(280);
    primaryExpression();
    setState(284);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(281);
        postfixOp(); 
      }
      setState(286);
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

tree::TerminalNode* PyScriptParser::AttributeAccessOpContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::AttributeAccessOpContext::AttributeAccessOpContext(PostfixOpContext *ctx) { copyFrom(ctx); }


std::any PyScriptParser::AttributeAccessOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAttributeAccessOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallOpContext ------------------------------------------------------------------

PyScriptParser::ArgumentListContext* PyScriptParser::FunctionCallOpContext::argumentList() {
  return getRuleContext<PyScriptParser::ArgumentListContext>(0);
}

PyScriptParser::FunctionCallOpContext::FunctionCallOpContext(PostfixOpContext *ctx) { copyFrom(ctx); }


std::any PyScriptParser::FunctionCallOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionCallOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptAccessOpContext ------------------------------------------------------------------

PyScriptParser::ExpressionContext* PyScriptParser::SubscriptAccessOpContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::SubscriptAccessOpContext::SubscriptAccessOpContext(PostfixOpContext *ctx) { copyFrom(ctx); }


std::any PyScriptParser::SubscriptAccessOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSubscriptAccessOp(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::PostfixOpContext* PyScriptParser::postfixOp() {
  PostfixOpContext *_localctx = _tracker.createInstance<PostfixOpContext>(_ctx, getState());
  enterRule(_localctx, 52, PyScriptParser::RulePostfixOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(298);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::T__28: {
        _localctx = _tracker.createInstance<PyScriptParser::AttributeAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(287);
        match(PyScriptParser::T__28);
        setState(288);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::T__29: {
        _localctx = _tracker.createInstance<PyScriptParser::SubscriptAccessOpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(289);
        match(PyScriptParser::T__29);
        setState(290);
        expression();
        setState(291);
        match(PyScriptParser::T__30);
        break;
      }

      case PyScriptParser::T__1: {
        _localctx = _tracker.createInstance<PyScriptParser::FunctionCallOpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(293);
        match(PyScriptParser::T__1);
        setState(295);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
          | (1ULL << PyScriptParser::T__4)
          | (1ULL << PyScriptParser::T__23)
          | (1ULL << PyScriptParser::T__27)
          | (1ULL << PyScriptParser::T__29)
          | (1ULL << PyScriptParser::NEW)
          | (1ULL << PyScriptParser::LAMBDA)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING)
          | (1ULL << PyScriptParser::BOOL)
          | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
          setState(294);
          argumentList();
        }
        setState(297);
        match(PyScriptParser::T__2);
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

tree::TerminalNode* PyScriptParser::AttributeAccessContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}


size_t PyScriptParser::AttributeAccessContext::getRuleIndex() const {
  return PyScriptParser::RuleAttributeAccess;
}


std::any PyScriptParser::AttributeAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAttributeAccess(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::AttributeAccessContext* PyScriptParser::attributeAccess() {
  AttributeAccessContext *_localctx = _tracker.createInstance<AttributeAccessContext>(_ctx, getState());
  enterRule(_localctx, 54, PyScriptParser::RuleAttributeAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    primaryExpression();
    setState(301);
    match(PyScriptParser::T__28);
    setState(302);
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

PyScriptParser::ExpressionContext* PyScriptParser::SubscriptAccessContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}


size_t PyScriptParser::SubscriptAccessContext::getRuleIndex() const {
  return PyScriptParser::RuleSubscriptAccess;
}


std::any PyScriptParser::SubscriptAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSubscriptAccess(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::SubscriptAccessContext* PyScriptParser::subscriptAccess() {
  SubscriptAccessContext *_localctx = _tracker.createInstance<SubscriptAccessContext>(_ctx, getState());
  enterRule(_localctx, 56, PyScriptParser::RuleSubscriptAccess);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    primaryExpression();
    setState(305);
    match(PyScriptParser::T__29);
    setState(306);
    expression();
    setState(307);
    match(PyScriptParser::T__30);
   
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


std::any PyScriptParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::FunctionCallContext* PyScriptParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 58, PyScriptParser::RuleFunctionCall);
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
    setState(316);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(309);
      dottedName();
      break;
    }

    case 2: {
      setState(310);
      attributeAccess();
      break;
    }

    case 3: {
      setState(311);
      subscriptAccess();
      break;
    }

    case 4: {
      setState(312);
      match(PyScriptParser::T__1);
      setState(313);
      expression();
      setState(314);
      match(PyScriptParser::T__2);
      break;
    }

    default:
      break;
    }
    setState(318);
    match(PyScriptParser::T__1);
    setState(320);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__23)
      | (1ULL << PyScriptParser::T__27)
      | (1ULL << PyScriptParser::T__29)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(319);
      argumentList();
    }
    setState(322);
    match(PyScriptParser::T__2);
   
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

PyScriptParser::ExpressionContext* PyScriptParser::PrimaryExpressionContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
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


std::any PyScriptParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::PrimaryExpressionContext* PyScriptParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 60, PyScriptParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(335);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(324);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(325);
      dottedName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(326);
      match(PyScriptParser::T__1);
      setState(327);
      expression();
      setState(328);
      match(PyScriptParser::T__2);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(330);
      listLiteral();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(331);
      dictLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(332);
      newExpression();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(333);
      lambdaExpression();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(334);
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

PyScriptParser::ArgumentListContext* PyScriptParser::NewExpressionContext::argumentList() {
  return getRuleContext<PyScriptParser::ArgumentListContext>(0);
}


size_t PyScriptParser::NewExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleNewExpression;
}


std::any PyScriptParser::NewExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitNewExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::NewExpressionContext* PyScriptParser::newExpression() {
  NewExpressionContext *_localctx = _tracker.createInstance<NewExpressionContext>(_ctx, getState());
  enterRule(_localctx, 62, PyScriptParser::RuleNewExpression);
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
    setState(337);
    match(PyScriptParser::NEW);
    setState(338);
    dottedName();
    setState(339);
    match(PyScriptParser::T__1);
    setState(341);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__23)
      | (1ULL << PyScriptParser::T__27)
      | (1ULL << PyScriptParser::T__29)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(340);
      argumentList();
    }
    setState(343);
    match(PyScriptParser::T__2);
   
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


std::any PyScriptParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LiteralContext* PyScriptParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 64, PyScriptParser::RuleLiteral);
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
    setState(345);
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

PyScriptParser::ExpressionListContext* PyScriptParser::ListLiteralContext::expressionList() {
  return getRuleContext<PyScriptParser::ExpressionListContext>(0);
}


size_t PyScriptParser::ListLiteralContext::getRuleIndex() const {
  return PyScriptParser::RuleListLiteral;
}


std::any PyScriptParser::ListLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitListLiteral(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ListLiteralContext* PyScriptParser::listLiteral() {
  ListLiteralContext *_localctx = _tracker.createInstance<ListLiteralContext>(_ctx, getState());
  enterRule(_localctx, 66, PyScriptParser::RuleListLiteral);
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
    setState(347);
    match(PyScriptParser::T__29);
    setState(349);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__23)
      | (1ULL << PyScriptParser::T__27)
      | (1ULL << PyScriptParser::T__29)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(348);
      expressionList();
    }
    setState(351);
    match(PyScriptParser::T__30);
   
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

PyScriptParser::DictItemListContext* PyScriptParser::DictLiteralContext::dictItemList() {
  return getRuleContext<PyScriptParser::DictItemListContext>(0);
}


size_t PyScriptParser::DictLiteralContext::getRuleIndex() const {
  return PyScriptParser::RuleDictLiteral;
}


std::any PyScriptParser::DictLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDictLiteral(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DictLiteralContext* PyScriptParser::dictLiteral() {
  DictLiteralContext *_localctx = _tracker.createInstance<DictLiteralContext>(_ctx, getState());
  enterRule(_localctx, 68, PyScriptParser::RuleDictLiteral);
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
    setState(353);
    match(PyScriptParser::T__4);
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__1)
      | (1ULL << PyScriptParser::T__4)
      | (1ULL << PyScriptParser::T__23)
      | (1ULL << PyScriptParser::T__27)
      | (1ULL << PyScriptParser::T__29)
      | (1ULL << PyScriptParser::T__32)
      | (1ULL << PyScriptParser::NEW)
      | (1ULL << PyScriptParser::LAMBDA)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(354);
      dictItemList();
    }
    setState(357);
    match(PyScriptParser::T__5);
   
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


size_t PyScriptParser::ListComprehensionContext::getRuleIndex() const {
  return PyScriptParser::RuleListComprehension;
}


std::any PyScriptParser::ListComprehensionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitListComprehension(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ListComprehensionContext* PyScriptParser::listComprehension() {
  ListComprehensionContext *_localctx = _tracker.createInstance<ListComprehensionContext>(_ctx, getState());
  enterRule(_localctx, 70, PyScriptParser::RuleListComprehension);

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
    match(PyScriptParser::T__29);
    setState(360);
    expression();
    setState(361);
    match(PyScriptParser::FOR);
    setState(362);
    match(PyScriptParser::IDENTIFIER);
    setState(363);
    match(PyScriptParser::T__31);
    setState(364);
    expression();
    setState(365);
    match(PyScriptParser::T__30);
   
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

PyScriptParser::ExpressionContext* PyScriptParser::LambdaExpressionContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> PyScriptParser::LambdaExpressionContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::LambdaExpressionContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
}


size_t PyScriptParser::LambdaExpressionContext::getRuleIndex() const {
  return PyScriptParser::RuleLambdaExpression;
}


std::any PyScriptParser::LambdaExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLambdaExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::LambdaExpressionContext* PyScriptParser::lambdaExpression() {
  LambdaExpressionContext *_localctx = _tracker.createInstance<LambdaExpressionContext>(_ctx, getState());
  enterRule(_localctx, 72, PyScriptParser::RuleLambdaExpression);
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
    match(PyScriptParser::LAMBDA);
    setState(376);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::IDENTIFIER) {
      setState(368);
      match(PyScriptParser::IDENTIFIER);
      setState(373);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PyScriptParser::T__3) {
        setState(369);
        match(PyScriptParser::T__3);
        setState(370);
        match(PyScriptParser::IDENTIFIER);
        setState(375);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(378);
    match(PyScriptParser::T__13);
    setState(379);
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


size_t PyScriptParser::DottedNameContext::getRuleIndex() const {
  return PyScriptParser::RuleDottedName;
}


std::any PyScriptParser::DottedNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDottedName(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DottedNameContext* PyScriptParser::dottedName() {
  DottedNameContext *_localctx = _tracker.createInstance<DottedNameContext>(_ctx, getState());
  enterRule(_localctx, 74, PyScriptParser::RuleDottedName);

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
    setState(381);
    match(PyScriptParser::IDENTIFIER);
    setState(386);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(382);
        match(PyScriptParser::T__28);
        setState(383);
        match(PyScriptParser::IDENTIFIER); 
      }
      setState(388);
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

//----------------- ArgumentListContext ------------------------------------------------------------------

PyScriptParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::ArgumentListContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::ArgumentListContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}


size_t PyScriptParser::ArgumentListContext::getRuleIndex() const {
  return PyScriptParser::RuleArgumentList;
}


std::any PyScriptParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ArgumentListContext* PyScriptParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 76, PyScriptParser::RuleArgumentList);
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
    expression();
    setState(394);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__3) {
      setState(390);
      match(PyScriptParser::T__3);
      setState(391);
      expression();
      setState(396);
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


size_t PyScriptParser::ExpressionListContext::getRuleIndex() const {
  return PyScriptParser::RuleExpressionList;
}


std::any PyScriptParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::ExpressionListContext* PyScriptParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 78, PyScriptParser::RuleExpressionList);
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
    setState(397);
    expression();
    setState(402);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__3) {
      setState(398);
      match(PyScriptParser::T__3);
      setState(399);
      expression();
      setState(404);
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


size_t PyScriptParser::DictItemListContext::getRuleIndex() const {
  return PyScriptParser::RuleDictItemList;
}


std::any PyScriptParser::DictItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDictItemList(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::DictItemListContext* PyScriptParser::dictItemList() {
  DictItemListContext *_localctx = _tracker.createInstance<DictItemListContext>(_ctx, getState());
  enterRule(_localctx, 80, PyScriptParser::RuleDictItemList);
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
    setState(405);
    dictItem();
    setState(410);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__3) {
      setState(406);
      match(PyScriptParser::T__3);
      setState(407);
      dictItem();
      setState(412);
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

PyScriptParser::KeyValuePairContext::KeyValuePairContext(DictItemContext *ctx) { copyFrom(ctx); }


std::any PyScriptParser::KeyValuePairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitKeyValuePair(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DictUnpackContext ------------------------------------------------------------------

PyScriptParser::ExpressionContext* PyScriptParser::DictUnpackContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::DictUnpackContext::DictUnpackContext(DictItemContext *ctx) { copyFrom(ctx); }


std::any PyScriptParser::DictUnpackContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitDictUnpack(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::DictItemContext* PyScriptParser::dictItem() {
  DictItemContext *_localctx = _tracker.createInstance<DictItemContext>(_ctx, getState());
  enterRule(_localctx, 82, PyScriptParser::RuleDictItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(419);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::T__1:
      case PyScriptParser::T__4:
      case PyScriptParser::T__23:
      case PyScriptParser::T__27:
      case PyScriptParser::T__29:
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
        setState(413);
        expression();
        setState(414);
        match(PyScriptParser::T__13);
        setState(415);
        expression();
        break;
      }

      case PyScriptParser::T__32: {
        _localctx = _tracker.createInstance<PyScriptParser::DictUnpackContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(417);
        match(PyScriptParser::T__32);
        setState(418);
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
