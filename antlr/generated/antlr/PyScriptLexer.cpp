
#include "PyScriptParser.h"


// Generated from antlr/PyScript.g4 by ANTLR 4.10.1


#include "PyScriptLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct PyScriptLexerStaticData final {
  PyScriptLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PyScriptLexerStaticData(const PyScriptLexerStaticData&) = delete;
  PyScriptLexerStaticData(PyScriptLexerStaticData&&) = delete;
  PyScriptLexerStaticData& operator=(const PyScriptLexerStaticData&) = delete;
  PyScriptLexerStaticData& operator=(PyScriptLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag pyscriptlexerLexerOnceFlag;
PyScriptLexerStaticData *pyscriptlexerLexerStaticData = nullptr;

void pyscriptlexerLexerInitialize() {
  assert(pyscriptlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<PyScriptLexerStaticData>(
    std::vector<std::string>{
      "DEF", "IF", "ELSE", "FOR", "WHILE", "RETURN", "IMPORT", "FROM", "AS", 
      "IN", "PASS", "NEW", "LAMBDA", "TRY", "EXCEPT", "FINALLY", "WITH", 
      "ASYNC", "AWAIT", "CLASS", "TRUE", "FALSE", "NONE", "AND", "OR", "NOT", 
      "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "NE", "LT", "LE", "GT", 
      "GE", "ASSIGN", "SEMI", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", 
      "RBRACE", "COMMA", "COLON", "DOT", "DOUBLE_STAR", "NEWLINE", "IDENTIFIER", 
      "INTEGER", "FLOAT", "STRING", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
      "INTEGER", "FLOAT", "STRING", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,56,383,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,1,0,
  	1,0,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,
  	1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,
  	1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,
  	1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,23,
  	1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,26,1,26,1,27,1,27,
  	1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,
  	1,34,1,34,1,34,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,38,1,38,1,39,1,39,
  	1,39,1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,43,1,43,1,43,1,44,
  	1,44,1,44,1,45,1,45,1,46,1,46,1,47,1,47,1,48,1,48,1,48,1,49,3,49,304,
  	8,49,1,49,1,49,5,49,308,8,49,10,49,12,49,311,9,49,1,49,1,49,1,50,1,50,
  	5,50,317,8,50,10,50,12,50,320,9,50,1,51,4,51,323,8,51,11,51,12,51,324,
  	1,52,4,52,328,8,52,11,52,12,52,329,1,52,1,52,4,52,334,8,52,11,52,12,52,
  	335,1,52,1,52,4,52,340,8,52,11,52,12,52,341,3,52,344,8,52,1,53,1,53,1,
  	53,1,53,5,53,350,8,53,10,53,12,53,353,9,53,1,53,1,53,1,53,1,53,1,53,5,
  	53,360,8,53,10,53,12,53,363,9,53,1,53,3,53,366,8,53,1,54,4,54,369,8,54,
  	11,54,12,54,370,1,54,1,54,1,55,1,55,5,55,377,8,55,10,55,12,55,380,9,55,
  	1,55,1,55,0,0,56,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,
  	23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,
  	23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,
  	69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,
  	46,93,47,95,48,97,49,99,50,101,51,103,52,105,53,107,54,109,55,111,56,
  	1,0,7,2,0,9,9,32,32,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,
  	1,0,48,57,4,0,10,10,13,13,34,34,92,92,4,0,10,10,13,13,39,39,92,92,2,0,
  	10,10,13,13,397,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,
  	0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,
  	0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,
  	31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,
  	0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,
  	0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,
  	63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,
  	0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,
  	0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,
  	95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,
  	1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,1,113,1,0,0,0,3,117,
  	1,0,0,0,5,120,1,0,0,0,7,125,1,0,0,0,9,129,1,0,0,0,11,135,1,0,0,0,13,142,
  	1,0,0,0,15,149,1,0,0,0,17,154,1,0,0,0,19,157,1,0,0,0,21,160,1,0,0,0,23,
  	165,1,0,0,0,25,169,1,0,0,0,27,176,1,0,0,0,29,180,1,0,0,0,31,187,1,0,0,
  	0,33,195,1,0,0,0,35,200,1,0,0,0,37,206,1,0,0,0,39,212,1,0,0,0,41,218,
  	1,0,0,0,43,223,1,0,0,0,45,229,1,0,0,0,47,234,1,0,0,0,49,238,1,0,0,0,51,
  	241,1,0,0,0,53,245,1,0,0,0,55,247,1,0,0,0,57,249,1,0,0,0,59,251,1,0,0,
  	0,61,253,1,0,0,0,63,255,1,0,0,0,65,258,1,0,0,0,67,261,1,0,0,0,69,263,
  	1,0,0,0,71,266,1,0,0,0,73,268,1,0,0,0,75,271,1,0,0,0,77,273,1,0,0,0,79,
  	275,1,0,0,0,81,278,1,0,0,0,83,281,1,0,0,0,85,284,1,0,0,0,87,287,1,0,0,
  	0,89,290,1,0,0,0,91,293,1,0,0,0,93,295,1,0,0,0,95,297,1,0,0,0,97,299,
  	1,0,0,0,99,303,1,0,0,0,101,314,1,0,0,0,103,322,1,0,0,0,105,343,1,0,0,
  	0,107,365,1,0,0,0,109,368,1,0,0,0,111,374,1,0,0,0,113,114,5,100,0,0,114,
  	115,5,101,0,0,115,116,5,102,0,0,116,2,1,0,0,0,117,118,5,105,0,0,118,119,
  	5,102,0,0,119,4,1,0,0,0,120,121,5,101,0,0,121,122,5,108,0,0,122,123,5,
  	115,0,0,123,124,5,101,0,0,124,6,1,0,0,0,125,126,5,102,0,0,126,127,5,111,
  	0,0,127,128,5,114,0,0,128,8,1,0,0,0,129,130,5,119,0,0,130,131,5,104,0,
  	0,131,132,5,105,0,0,132,133,5,108,0,0,133,134,5,101,0,0,134,10,1,0,0,
  	0,135,136,5,114,0,0,136,137,5,101,0,0,137,138,5,116,0,0,138,139,5,117,
  	0,0,139,140,5,114,0,0,140,141,5,110,0,0,141,12,1,0,0,0,142,143,5,105,
  	0,0,143,144,5,109,0,0,144,145,5,112,0,0,145,146,5,111,0,0,146,147,5,114,
  	0,0,147,148,5,116,0,0,148,14,1,0,0,0,149,150,5,102,0,0,150,151,5,114,
  	0,0,151,152,5,111,0,0,152,153,5,109,0,0,153,16,1,0,0,0,154,155,5,97,0,
  	0,155,156,5,115,0,0,156,18,1,0,0,0,157,158,5,105,0,0,158,159,5,110,0,
  	0,159,20,1,0,0,0,160,161,5,112,0,0,161,162,5,97,0,0,162,163,5,115,0,0,
  	163,164,5,115,0,0,164,22,1,0,0,0,165,166,5,110,0,0,166,167,5,101,0,0,
  	167,168,5,119,0,0,168,24,1,0,0,0,169,170,5,108,0,0,170,171,5,97,0,0,171,
  	172,5,109,0,0,172,173,5,98,0,0,173,174,5,100,0,0,174,175,5,97,0,0,175,
  	26,1,0,0,0,176,177,5,116,0,0,177,178,5,114,0,0,178,179,5,121,0,0,179,
  	28,1,0,0,0,180,181,5,101,0,0,181,182,5,120,0,0,182,183,5,99,0,0,183,184,
  	5,101,0,0,184,185,5,112,0,0,185,186,5,116,0,0,186,30,1,0,0,0,187,188,
  	5,102,0,0,188,189,5,105,0,0,189,190,5,110,0,0,190,191,5,97,0,0,191,192,
  	5,108,0,0,192,193,5,108,0,0,193,194,5,121,0,0,194,32,1,0,0,0,195,196,
  	5,119,0,0,196,197,5,105,0,0,197,198,5,116,0,0,198,199,5,104,0,0,199,34,
  	1,0,0,0,200,201,5,97,0,0,201,202,5,115,0,0,202,203,5,121,0,0,203,204,
  	5,110,0,0,204,205,5,99,0,0,205,36,1,0,0,0,206,207,5,97,0,0,207,208,5,
  	119,0,0,208,209,5,97,0,0,209,210,5,105,0,0,210,211,5,116,0,0,211,38,1,
  	0,0,0,212,213,5,99,0,0,213,214,5,108,0,0,214,215,5,97,0,0,215,216,5,115,
  	0,0,216,217,5,115,0,0,217,40,1,0,0,0,218,219,5,116,0,0,219,220,5,114,
  	0,0,220,221,5,117,0,0,221,222,5,101,0,0,222,42,1,0,0,0,223,224,5,102,
  	0,0,224,225,5,97,0,0,225,226,5,108,0,0,226,227,5,115,0,0,227,228,5,101,
  	0,0,228,44,1,0,0,0,229,230,5,110,0,0,230,231,5,111,0,0,231,232,5,110,
  	0,0,232,233,5,101,0,0,233,46,1,0,0,0,234,235,5,97,0,0,235,236,5,110,0,
  	0,236,237,5,100,0,0,237,48,1,0,0,0,238,239,5,111,0,0,239,240,5,114,0,
  	0,240,50,1,0,0,0,241,242,5,110,0,0,242,243,5,111,0,0,243,244,5,116,0,
  	0,244,52,1,0,0,0,245,246,5,43,0,0,246,54,1,0,0,0,247,248,5,45,0,0,248,
  	56,1,0,0,0,249,250,5,42,0,0,250,58,1,0,0,0,251,252,5,47,0,0,252,60,1,
  	0,0,0,253,254,5,37,0,0,254,62,1,0,0,0,255,256,5,61,0,0,256,257,5,61,0,
  	0,257,64,1,0,0,0,258,259,5,33,0,0,259,260,5,61,0,0,260,66,1,0,0,0,261,
  	262,5,60,0,0,262,68,1,0,0,0,263,264,5,60,0,0,264,265,5,61,0,0,265,70,
  	1,0,0,0,266,267,5,62,0,0,267,72,1,0,0,0,268,269,5,62,0,0,269,270,5,61,
  	0,0,270,74,1,0,0,0,271,272,5,61,0,0,272,76,1,0,0,0,273,274,5,59,0,0,274,
  	78,1,0,0,0,275,276,5,40,0,0,276,277,6,39,0,0,277,80,1,0,0,0,278,279,5,
  	41,0,0,279,280,6,40,1,0,280,82,1,0,0,0,281,282,5,91,0,0,282,283,6,41,
  	2,0,283,84,1,0,0,0,284,285,5,93,0,0,285,286,6,42,3,0,286,86,1,0,0,0,287,
  	288,5,123,0,0,288,289,6,43,4,0,289,88,1,0,0,0,290,291,5,125,0,0,291,292,
  	6,44,5,0,292,90,1,0,0,0,293,294,5,44,0,0,294,92,1,0,0,0,295,296,5,58,
  	0,0,296,94,1,0,0,0,297,298,5,46,0,0,298,96,1,0,0,0,299,300,5,42,0,0,300,
  	301,5,42,0,0,301,98,1,0,0,0,302,304,5,13,0,0,303,302,1,0,0,0,303,304,
  	1,0,0,0,304,305,1,0,0,0,305,309,5,10,0,0,306,308,7,0,0,0,307,306,1,0,
  	0,0,308,311,1,0,0,0,309,307,1,0,0,0,309,310,1,0,0,0,310,312,1,0,0,0,311,
  	309,1,0,0,0,312,313,6,49,6,0,313,100,1,0,0,0,314,318,7,1,0,0,315,317,
  	7,2,0,0,316,315,1,0,0,0,317,320,1,0,0,0,318,316,1,0,0,0,318,319,1,0,0,
  	0,319,102,1,0,0,0,320,318,1,0,0,0,321,323,7,3,0,0,322,321,1,0,0,0,323,
  	324,1,0,0,0,324,322,1,0,0,0,324,325,1,0,0,0,325,104,1,0,0,0,326,328,7,
  	3,0,0,327,326,1,0,0,0,328,329,1,0,0,0,329,327,1,0,0,0,329,330,1,0,0,0,
  	330,331,1,0,0,0,331,333,5,46,0,0,332,334,7,3,0,0,333,332,1,0,0,0,334,
  	335,1,0,0,0,335,333,1,0,0,0,335,336,1,0,0,0,336,344,1,0,0,0,337,339,5,
  	46,0,0,338,340,7,3,0,0,339,338,1,0,0,0,340,341,1,0,0,0,341,339,1,0,0,
  	0,341,342,1,0,0,0,342,344,1,0,0,0,343,327,1,0,0,0,343,337,1,0,0,0,344,
  	106,1,0,0,0,345,351,5,34,0,0,346,350,8,4,0,0,347,348,5,92,0,0,348,350,
  	9,0,0,0,349,346,1,0,0,0,349,347,1,0,0,0,350,353,1,0,0,0,351,349,1,0,0,
  	0,351,352,1,0,0,0,352,354,1,0,0,0,353,351,1,0,0,0,354,366,5,34,0,0,355,
  	361,5,39,0,0,356,360,8,5,0,0,357,358,5,92,0,0,358,360,9,0,0,0,359,356,
  	1,0,0,0,359,357,1,0,0,0,360,363,1,0,0,0,361,359,1,0,0,0,361,362,1,0,0,
  	0,362,364,1,0,0,0,363,361,1,0,0,0,364,366,5,39,0,0,365,345,1,0,0,0,365,
  	355,1,0,0,0,366,108,1,0,0,0,367,369,7,0,0,0,368,367,1,0,0,0,369,370,1,
  	0,0,0,370,368,1,0,0,0,370,371,1,0,0,0,371,372,1,0,0,0,372,373,6,54,7,
  	0,373,110,1,0,0,0,374,378,5,35,0,0,375,377,8,6,0,0,376,375,1,0,0,0,377,
  	380,1,0,0,0,378,376,1,0,0,0,378,379,1,0,0,0,379,381,1,0,0,0,380,378,1,
  	0,0,0,381,382,6,55,7,0,382,112,1,0,0,0,16,0,303,309,318,324,329,335,341,
  	343,349,351,359,361,365,370,378,8,1,39,0,1,40,1,1,41,2,1,42,3,1,43,4,
  	1,44,5,1,49,6,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pyscriptlexerLexerStaticData = staticData.release();
}

}

PyScriptLexer::PyScriptLexer(CharStream *input) : Lexer(input) {
  PyScriptLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *pyscriptlexerLexerStaticData->atn, pyscriptlexerLexerStaticData->decisionToDFA, pyscriptlexerLexerStaticData->sharedContextCache);
}

PyScriptLexer::~PyScriptLexer() {
  delete _interpreter;
}

std::string PyScriptLexer::getGrammarFileName() const {
  return "PyScript.g4";
}

const std::vector<std::string>& PyScriptLexer::getRuleNames() const {
  return pyscriptlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& PyScriptLexer::getChannelNames() const {
  return pyscriptlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& PyScriptLexer::getModeNames() const {
  return pyscriptlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& PyScriptLexer::getVocabulary() const {
  return pyscriptlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PyScriptLexer::getSerializedATN() const {
  return pyscriptlexerLexerStaticData->serializedATN;
}

const atn::ATN& PyScriptLexer::getATN() const {
  return *pyscriptlexerLexerStaticData->atn;
}


void PyScriptLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 39: LPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: RPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: LBRACKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: RBRACKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 43: LBRACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: RBRACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 49: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void PyScriptLexer::LPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  opened++;  break;

  default:
    break;
  }
}

void PyScriptLexer::RPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:  opened--;  break;

  default:
    break;
  }
}

void PyScriptLexer::LBRACKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:  opened++;  break;

  default:
    break;
  }
}

void PyScriptLexer::RBRACKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  opened--;  break;

  default:
    break;
  }
}

void PyScriptLexer::LBRACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  opened++;  break;

  default:
    break;
  }
}

void PyScriptLexer::RBRACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  opened--;  break;

  default:
    break;
  }
}

void PyScriptLexer::NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6: 
            // 如果在括号内，则忽略缩进
            if (opened > 0) {
                skip();
            } else {
                // 提取缩进部分（换行后的空格/制表符）
                std::string text = getText();
                size_t lastNewline = text.find_last_of('\n');
                std::string spaces = (lastNewline == std::string::npos) ? text : text.substr(lastNewline + 1);
                int indent = indentationCount(spaces);
                int prev = indents.empty() ? 0 : indents.back();

                if (indent > prev) {
                    // 增加缩进
                    indents.push_back(indent);
                    emitToken(std::make_unique<antlr4::CommonToken>(PyScriptParser::INDENT));
                } else if (indent < prev) {
                    // 减少缩进，可能需要多个DEDENT
                    while (!indents.empty() && indents.back() > indent) {
                        emitToken(std::make_unique<antlr4::CommonToken>(PyScriptParser::DEDENT));
                        indents.pop_back();
                    }
                }
                // 如果缩进相同，则不需要INDENT/DEDENT，跳过空格
            }
           break;

  default:
    break;
  }
}



void PyScriptLexer::initialize() {
  std::call_once(pyscriptlexerLexerOnceFlag, pyscriptlexerLexerInitialize);
}
