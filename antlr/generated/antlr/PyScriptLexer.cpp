
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
      "ASYNC", "AWAIT", "CLASS", "AT", "TRUE", "FALSE", "NONE", "AND", "OR", 
      "NOT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "NE", "LT", "LE", 
      "GT", "GE", "ASSIGN", "SEMI", "LPAREN", "RPAREN", "LBRACK", "RBRACK", 
      "LBRACE", "RBRACE", "COMMA", "COLON", "DOT", "DOUBLE_STAR", "NEWLINE", 
      "IDENTIFIER", "INTEGER", "FLOAT", "STRING", "WS", "COMMENT"
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
      "'@'", "'true'", "'false'", "'none'", "'and'", "'or'", "'not'", "'+'", 
      "'-'", "'*'", "'/'", "'%'", "'=='", "'!='", "'<'", "'<='", "'>'", 
      "'>='", "'='", "';'", "'('", "')'", "'['", "']'", "'{'", "'}'", "','", 
      "':'", "'.'", "'**'"
    },
    std::vector<std::string>{
      "", "DEF", "IF", "ELSE", "FOR", "WHILE", "RETURN", "IMPORT", "FROM", 
      "AS", "IN", "PASS", "NEW", "LAMBDA", "TRY", "EXCEPT", "FINALLY", "WITH", 
      "ASYNC", "AWAIT", "CLASS", "AT", "TRUE", "FALSE", "NONE", "AND", "OR", 
      "NOT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "NE", "LT", "LE", 
      "GT", "GE", "ASSIGN", "SEMI", "LPAREN", "RPAREN", "LBRACK", "RBRACK", 
      "LBRACE", "RBRACE", "COMMA", "COLON", "DOT", "DOUBLE_STAR", "NEWLINE", 
      "IDENTIFIER", "INTEGER", "FLOAT", "STRING", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,57,387,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,
  	1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,20,
  	1,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,
  	1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,26,
  	1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,32,1,33,
  	1,33,1,33,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,37,1,37,1,37,1,38,1,38,
  	1,39,1,39,1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,43,1,43,1,43,
  	1,44,1,44,1,44,1,45,1,45,1,45,1,46,1,46,1,47,1,47,1,48,1,48,1,49,1,49,
  	1,49,1,50,3,50,308,8,50,1,50,1,50,5,50,312,8,50,10,50,12,50,315,9,50,
  	1,50,1,50,1,51,1,51,5,51,321,8,51,10,51,12,51,324,9,51,1,52,4,52,327,
  	8,52,11,52,12,52,328,1,53,4,53,332,8,53,11,53,12,53,333,1,53,1,53,4,53,
  	338,8,53,11,53,12,53,339,1,53,1,53,4,53,344,8,53,11,53,12,53,345,3,53,
  	348,8,53,1,54,1,54,1,54,1,54,5,54,354,8,54,10,54,12,54,357,9,54,1,54,
  	1,54,1,54,1,54,1,54,5,54,364,8,54,10,54,12,54,367,9,54,1,54,3,54,370,
  	8,54,1,55,4,55,373,8,55,11,55,12,55,374,1,55,1,55,1,56,1,56,5,56,381,
  	8,56,10,56,12,56,384,9,56,1,56,1,56,0,0,57,1,1,3,2,5,3,7,4,9,5,11,6,13,
  	7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,
  	19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,
  	61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,
  	42,85,43,87,44,89,45,91,46,93,47,95,48,97,49,99,50,101,51,103,52,105,
  	53,107,54,109,55,111,56,113,57,1,0,7,2,0,9,9,32,32,3,0,65,90,95,95,97,
  	122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,4,0,10,10,13,13,34,34,92,92,
  	4,0,10,10,13,13,39,39,92,92,2,0,10,10,13,13,401,0,1,1,0,0,0,0,3,1,0,0,
  	0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,
  	0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,
  	0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,
  	1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,
  	0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,
  	0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,
  	0,111,1,0,0,0,0,113,1,0,0,0,1,115,1,0,0,0,3,119,1,0,0,0,5,122,1,0,0,0,
  	7,127,1,0,0,0,9,131,1,0,0,0,11,137,1,0,0,0,13,144,1,0,0,0,15,151,1,0,
  	0,0,17,156,1,0,0,0,19,159,1,0,0,0,21,162,1,0,0,0,23,167,1,0,0,0,25,171,
  	1,0,0,0,27,178,1,0,0,0,29,182,1,0,0,0,31,189,1,0,0,0,33,197,1,0,0,0,35,
  	202,1,0,0,0,37,208,1,0,0,0,39,214,1,0,0,0,41,220,1,0,0,0,43,222,1,0,0,
  	0,45,227,1,0,0,0,47,233,1,0,0,0,49,238,1,0,0,0,51,242,1,0,0,0,53,245,
  	1,0,0,0,55,249,1,0,0,0,57,251,1,0,0,0,59,253,1,0,0,0,61,255,1,0,0,0,63,
  	257,1,0,0,0,65,259,1,0,0,0,67,262,1,0,0,0,69,265,1,0,0,0,71,267,1,0,0,
  	0,73,270,1,0,0,0,75,272,1,0,0,0,77,275,1,0,0,0,79,277,1,0,0,0,81,279,
  	1,0,0,0,83,282,1,0,0,0,85,285,1,0,0,0,87,288,1,0,0,0,89,291,1,0,0,0,91,
  	294,1,0,0,0,93,297,1,0,0,0,95,299,1,0,0,0,97,301,1,0,0,0,99,303,1,0,0,
  	0,101,307,1,0,0,0,103,318,1,0,0,0,105,326,1,0,0,0,107,347,1,0,0,0,109,
  	369,1,0,0,0,111,372,1,0,0,0,113,378,1,0,0,0,115,116,5,100,0,0,116,117,
  	5,101,0,0,117,118,5,102,0,0,118,2,1,0,0,0,119,120,5,105,0,0,120,121,5,
  	102,0,0,121,4,1,0,0,0,122,123,5,101,0,0,123,124,5,108,0,0,124,125,5,115,
  	0,0,125,126,5,101,0,0,126,6,1,0,0,0,127,128,5,102,0,0,128,129,5,111,0,
  	0,129,130,5,114,0,0,130,8,1,0,0,0,131,132,5,119,0,0,132,133,5,104,0,0,
  	133,134,5,105,0,0,134,135,5,108,0,0,135,136,5,101,0,0,136,10,1,0,0,0,
  	137,138,5,114,0,0,138,139,5,101,0,0,139,140,5,116,0,0,140,141,5,117,0,
  	0,141,142,5,114,0,0,142,143,5,110,0,0,143,12,1,0,0,0,144,145,5,105,0,
  	0,145,146,5,109,0,0,146,147,5,112,0,0,147,148,5,111,0,0,148,149,5,114,
  	0,0,149,150,5,116,0,0,150,14,1,0,0,0,151,152,5,102,0,0,152,153,5,114,
  	0,0,153,154,5,111,0,0,154,155,5,109,0,0,155,16,1,0,0,0,156,157,5,97,0,
  	0,157,158,5,115,0,0,158,18,1,0,0,0,159,160,5,105,0,0,160,161,5,110,0,
  	0,161,20,1,0,0,0,162,163,5,112,0,0,163,164,5,97,0,0,164,165,5,115,0,0,
  	165,166,5,115,0,0,166,22,1,0,0,0,167,168,5,110,0,0,168,169,5,101,0,0,
  	169,170,5,119,0,0,170,24,1,0,0,0,171,172,5,108,0,0,172,173,5,97,0,0,173,
  	174,5,109,0,0,174,175,5,98,0,0,175,176,5,100,0,0,176,177,5,97,0,0,177,
  	26,1,0,0,0,178,179,5,116,0,0,179,180,5,114,0,0,180,181,5,121,0,0,181,
  	28,1,0,0,0,182,183,5,101,0,0,183,184,5,120,0,0,184,185,5,99,0,0,185,186,
  	5,101,0,0,186,187,5,112,0,0,187,188,5,116,0,0,188,30,1,0,0,0,189,190,
  	5,102,0,0,190,191,5,105,0,0,191,192,5,110,0,0,192,193,5,97,0,0,193,194,
  	5,108,0,0,194,195,5,108,0,0,195,196,5,121,0,0,196,32,1,0,0,0,197,198,
  	5,119,0,0,198,199,5,105,0,0,199,200,5,116,0,0,200,201,5,104,0,0,201,34,
  	1,0,0,0,202,203,5,97,0,0,203,204,5,115,0,0,204,205,5,121,0,0,205,206,
  	5,110,0,0,206,207,5,99,0,0,207,36,1,0,0,0,208,209,5,97,0,0,209,210,5,
  	119,0,0,210,211,5,97,0,0,211,212,5,105,0,0,212,213,5,116,0,0,213,38,1,
  	0,0,0,214,215,5,99,0,0,215,216,5,108,0,0,216,217,5,97,0,0,217,218,5,115,
  	0,0,218,219,5,115,0,0,219,40,1,0,0,0,220,221,5,64,0,0,221,42,1,0,0,0,
  	222,223,5,116,0,0,223,224,5,114,0,0,224,225,5,117,0,0,225,226,5,101,0,
  	0,226,44,1,0,0,0,227,228,5,102,0,0,228,229,5,97,0,0,229,230,5,108,0,0,
  	230,231,5,115,0,0,231,232,5,101,0,0,232,46,1,0,0,0,233,234,5,110,0,0,
  	234,235,5,111,0,0,235,236,5,110,0,0,236,237,5,101,0,0,237,48,1,0,0,0,
  	238,239,5,97,0,0,239,240,5,110,0,0,240,241,5,100,0,0,241,50,1,0,0,0,242,
  	243,5,111,0,0,243,244,5,114,0,0,244,52,1,0,0,0,245,246,5,110,0,0,246,
  	247,5,111,0,0,247,248,5,116,0,0,248,54,1,0,0,0,249,250,5,43,0,0,250,56,
  	1,0,0,0,251,252,5,45,0,0,252,58,1,0,0,0,253,254,5,42,0,0,254,60,1,0,0,
  	0,255,256,5,47,0,0,256,62,1,0,0,0,257,258,5,37,0,0,258,64,1,0,0,0,259,
  	260,5,61,0,0,260,261,5,61,0,0,261,66,1,0,0,0,262,263,5,33,0,0,263,264,
  	5,61,0,0,264,68,1,0,0,0,265,266,5,60,0,0,266,70,1,0,0,0,267,268,5,60,
  	0,0,268,269,5,61,0,0,269,72,1,0,0,0,270,271,5,62,0,0,271,74,1,0,0,0,272,
  	273,5,62,0,0,273,274,5,61,0,0,274,76,1,0,0,0,275,276,5,61,0,0,276,78,
  	1,0,0,0,277,278,5,59,0,0,278,80,1,0,0,0,279,280,5,40,0,0,280,281,6,40,
  	0,0,281,82,1,0,0,0,282,283,5,41,0,0,283,284,6,41,1,0,284,84,1,0,0,0,285,
  	286,5,91,0,0,286,287,6,42,2,0,287,86,1,0,0,0,288,289,5,93,0,0,289,290,
  	6,43,3,0,290,88,1,0,0,0,291,292,5,123,0,0,292,293,6,44,4,0,293,90,1,0,
  	0,0,294,295,5,125,0,0,295,296,6,45,5,0,296,92,1,0,0,0,297,298,5,44,0,
  	0,298,94,1,0,0,0,299,300,5,58,0,0,300,96,1,0,0,0,301,302,5,46,0,0,302,
  	98,1,0,0,0,303,304,5,42,0,0,304,305,5,42,0,0,305,100,1,0,0,0,306,308,
  	5,13,0,0,307,306,1,0,0,0,307,308,1,0,0,0,308,309,1,0,0,0,309,313,5,10,
  	0,0,310,312,7,0,0,0,311,310,1,0,0,0,312,315,1,0,0,0,313,311,1,0,0,0,313,
  	314,1,0,0,0,314,316,1,0,0,0,315,313,1,0,0,0,316,317,6,50,6,0,317,102,
  	1,0,0,0,318,322,7,1,0,0,319,321,7,2,0,0,320,319,1,0,0,0,321,324,1,0,0,
  	0,322,320,1,0,0,0,322,323,1,0,0,0,323,104,1,0,0,0,324,322,1,0,0,0,325,
  	327,7,3,0,0,326,325,1,0,0,0,327,328,1,0,0,0,328,326,1,0,0,0,328,329,1,
  	0,0,0,329,106,1,0,0,0,330,332,7,3,0,0,331,330,1,0,0,0,332,333,1,0,0,0,
  	333,331,1,0,0,0,333,334,1,0,0,0,334,335,1,0,0,0,335,337,5,46,0,0,336,
  	338,7,3,0,0,337,336,1,0,0,0,338,339,1,0,0,0,339,337,1,0,0,0,339,340,1,
  	0,0,0,340,348,1,0,0,0,341,343,5,46,0,0,342,344,7,3,0,0,343,342,1,0,0,
  	0,344,345,1,0,0,0,345,343,1,0,0,0,345,346,1,0,0,0,346,348,1,0,0,0,347,
  	331,1,0,0,0,347,341,1,0,0,0,348,108,1,0,0,0,349,355,5,34,0,0,350,354,
  	8,4,0,0,351,352,5,92,0,0,352,354,9,0,0,0,353,350,1,0,0,0,353,351,1,0,
  	0,0,354,357,1,0,0,0,355,353,1,0,0,0,355,356,1,0,0,0,356,358,1,0,0,0,357,
  	355,1,0,0,0,358,370,5,34,0,0,359,365,5,39,0,0,360,364,8,5,0,0,361,362,
  	5,92,0,0,362,364,9,0,0,0,363,360,1,0,0,0,363,361,1,0,0,0,364,367,1,0,
  	0,0,365,363,1,0,0,0,365,366,1,0,0,0,366,368,1,0,0,0,367,365,1,0,0,0,368,
  	370,5,39,0,0,369,349,1,0,0,0,369,359,1,0,0,0,370,110,1,0,0,0,371,373,
  	7,0,0,0,372,371,1,0,0,0,373,374,1,0,0,0,374,372,1,0,0,0,374,375,1,0,0,
  	0,375,376,1,0,0,0,376,377,6,55,7,0,377,112,1,0,0,0,378,382,5,35,0,0,379,
  	381,8,6,0,0,380,379,1,0,0,0,381,384,1,0,0,0,382,380,1,0,0,0,382,383,1,
  	0,0,0,383,385,1,0,0,0,384,382,1,0,0,0,385,386,6,56,7,0,386,114,1,0,0,
  	0,16,0,307,313,322,328,333,339,345,347,353,355,363,365,369,374,382,8,
  	1,40,0,1,41,1,1,42,2,1,43,3,1,44,4,1,45,5,1,50,6,6,0,0
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
    case 40: LPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: RPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: LBRACKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 43: RBRACKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: LBRACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 45: RBRACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 50: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

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
