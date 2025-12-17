
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
      "program", "statement", "importStatement", "assignment", "expressionStatement", 
      "ifStatement", "whileStatement", "returnStatement", "block", "expression", 
      "ternaryExpression", "logicalOrExpression", "logicalAndExpression", 
      "equalityExpression", "relationalExpression", "additiveExpression", 
      "multiplicativeExpression", "unaryExpression", "primaryExpression", 
      "postfixExpression", "postfixOperator", "argumentList", "literal", 
      "expressionList", "keyValuePairList", "keyValuePair"
    },
    std::vector<std::string>{
      "", "'import'", "'.'", "'as'", "';'", "'='", "'+='", "'-='", "'*='", 
      "'/='", "'%='", "'['", "']'", "'if'", "'('", "')'", "'else'", "'while'", 
      "'return'", "'{'", "'}'", "'\\u003F'", "':'", "'||'", "'&&'", "'=='", 
      "'!='", "'<'", "'>'", "'<='", "'>='", "'+'", "'-'", "'*'", "'/'", 
      "'%'", "'!'", "'new'", "','", "", "", "", "", "", "'null'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "IDENTIFIER", "INTEGER", "FLOAT", "STRING", "BOOL", 
      "NULL_LIT", "WS", "COMMENT", "MULTILINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,47,289,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,4,0,54,8,0,11,0,12,0,55,
  	1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,3,1,66,8,1,1,2,1,2,1,2,1,2,5,2,72,8,2,
  	10,2,12,2,75,9,2,1,2,1,2,3,2,79,8,2,1,2,3,2,82,8,2,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,100,8,3,1,4,1,4,3,4,
  	104,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,113,8,5,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,7,1,7,3,7,123,8,7,1,7,3,7,126,8,7,1,8,1,8,5,8,130,8,8,10,8,12,8,133,
  	9,8,1,8,1,8,1,9,1,9,3,9,139,8,9,1,10,1,10,1,10,1,10,1,10,1,10,3,10,147,
  	8,10,1,11,1,11,1,11,5,11,152,8,11,10,11,12,11,155,9,11,1,12,1,12,1,12,
  	5,12,160,8,12,10,12,12,12,163,9,12,1,13,1,13,1,13,5,13,168,8,13,10,13,
  	12,13,171,9,13,1,14,1,14,1,14,5,14,176,8,14,10,14,12,14,179,9,14,1,15,
  	1,15,1,15,5,15,184,8,15,10,15,12,15,187,9,15,1,16,1,16,1,16,5,16,192,
  	8,16,10,16,12,16,195,9,16,1,17,3,17,198,8,17,1,17,1,17,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,212,8,18,10,18,12,18,215,9,18,
  	1,18,1,18,3,18,219,8,18,1,18,3,18,222,8,18,1,19,1,19,5,19,226,8,19,10,
  	19,12,19,229,9,19,1,20,1,20,3,20,233,8,20,1,20,1,20,1,20,1,20,1,20,1,
  	20,1,20,3,20,242,8,20,1,21,1,21,1,21,5,21,247,8,21,10,21,12,21,250,9,
  	21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,259,8,22,1,22,1,22,1,22,3,
  	22,264,8,22,1,22,3,22,267,8,22,1,23,1,23,1,23,5,23,272,8,23,10,23,12,
  	23,275,9,23,1,24,1,24,1,24,5,24,280,8,24,10,24,12,24,283,9,24,1,25,1,
  	25,1,25,1,25,1,25,0,0,26,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,42,44,46,48,50,0,6,1,0,5,10,1,0,25,26,1,0,27,30,1,0,31,32,
  	1,0,33,35,2,0,32,32,36,36,307,0,53,1,0,0,0,2,65,1,0,0,0,4,67,1,0,0,0,
  	6,99,1,0,0,0,8,101,1,0,0,0,10,105,1,0,0,0,12,114,1,0,0,0,14,120,1,0,0,
  	0,16,127,1,0,0,0,18,138,1,0,0,0,20,140,1,0,0,0,22,148,1,0,0,0,24,156,
  	1,0,0,0,26,164,1,0,0,0,28,172,1,0,0,0,30,180,1,0,0,0,32,188,1,0,0,0,34,
  	197,1,0,0,0,36,221,1,0,0,0,38,223,1,0,0,0,40,241,1,0,0,0,42,243,1,0,0,
  	0,44,266,1,0,0,0,46,268,1,0,0,0,48,276,1,0,0,0,50,284,1,0,0,0,52,54,3,
  	2,1,0,53,52,1,0,0,0,54,55,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,57,1,
  	0,0,0,57,58,5,0,0,1,58,1,1,0,0,0,59,66,3,4,2,0,60,66,3,6,3,0,61,66,3,
  	8,4,0,62,66,3,10,5,0,63,66,3,12,6,0,64,66,3,14,7,0,65,59,1,0,0,0,65,60,
  	1,0,0,0,65,61,1,0,0,0,65,62,1,0,0,0,65,63,1,0,0,0,65,64,1,0,0,0,66,3,
  	1,0,0,0,67,68,5,1,0,0,68,73,5,39,0,0,69,70,5,2,0,0,70,72,5,39,0,0,71,
  	69,1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,78,1,0,0,0,75,
  	73,1,0,0,0,76,77,5,3,0,0,77,79,5,39,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,
  	81,1,0,0,0,80,82,5,4,0,0,81,80,1,0,0,0,81,82,1,0,0,0,82,5,1,0,0,0,83,
  	84,5,39,0,0,84,85,7,0,0,0,85,100,3,20,10,0,86,87,3,36,18,0,87,88,5,2,
  	0,0,88,89,5,39,0,0,89,90,5,5,0,0,90,91,3,20,10,0,91,100,1,0,0,0,92,93,
  	3,36,18,0,93,94,5,11,0,0,94,95,3,18,9,0,95,96,5,12,0,0,96,97,5,5,0,0,
  	97,98,3,20,10,0,98,100,1,0,0,0,99,83,1,0,0,0,99,86,1,0,0,0,99,92,1,0,
  	0,0,100,7,1,0,0,0,101,103,3,18,9,0,102,104,5,4,0,0,103,102,1,0,0,0,103,
  	104,1,0,0,0,104,9,1,0,0,0,105,106,5,13,0,0,106,107,5,14,0,0,107,108,3,
  	18,9,0,108,109,5,15,0,0,109,112,3,16,8,0,110,111,5,16,0,0,111,113,3,16,
  	8,0,112,110,1,0,0,0,112,113,1,0,0,0,113,11,1,0,0,0,114,115,5,17,0,0,115,
  	116,5,14,0,0,116,117,3,18,9,0,117,118,5,15,0,0,118,119,3,16,8,0,119,13,
  	1,0,0,0,120,122,5,18,0,0,121,123,3,18,9,0,122,121,1,0,0,0,122,123,1,0,
  	0,0,123,125,1,0,0,0,124,126,5,4,0,0,125,124,1,0,0,0,125,126,1,0,0,0,126,
  	15,1,0,0,0,127,131,5,19,0,0,128,130,3,2,1,0,129,128,1,0,0,0,130,133,1,
  	0,0,0,131,129,1,0,0,0,131,132,1,0,0,0,132,134,1,0,0,0,133,131,1,0,0,0,
  	134,135,5,20,0,0,135,17,1,0,0,0,136,139,3,20,10,0,137,139,3,6,3,0,138,
  	136,1,0,0,0,138,137,1,0,0,0,139,19,1,0,0,0,140,146,3,22,11,0,141,142,
  	5,21,0,0,142,143,3,18,9,0,143,144,5,22,0,0,144,145,3,20,10,0,145,147,
  	1,0,0,0,146,141,1,0,0,0,146,147,1,0,0,0,147,21,1,0,0,0,148,153,3,24,12,
  	0,149,150,5,23,0,0,150,152,3,24,12,0,151,149,1,0,0,0,152,155,1,0,0,0,
  	153,151,1,0,0,0,153,154,1,0,0,0,154,23,1,0,0,0,155,153,1,0,0,0,156,161,
  	3,26,13,0,157,158,5,24,0,0,158,160,3,26,13,0,159,157,1,0,0,0,160,163,
  	1,0,0,0,161,159,1,0,0,0,161,162,1,0,0,0,162,25,1,0,0,0,163,161,1,0,0,
  	0,164,169,3,28,14,0,165,166,7,1,0,0,166,168,3,28,14,0,167,165,1,0,0,0,
  	168,171,1,0,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,27,1,0,0,0,171,169,
  	1,0,0,0,172,177,3,30,15,0,173,174,7,2,0,0,174,176,3,30,15,0,175,173,1,
  	0,0,0,176,179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,29,1,0,0,0,
  	179,177,1,0,0,0,180,185,3,32,16,0,181,182,7,3,0,0,182,184,3,32,16,0,183,
  	181,1,0,0,0,184,187,1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,31,1,
  	0,0,0,187,185,1,0,0,0,188,193,3,34,17,0,189,190,7,4,0,0,190,192,3,34,
  	17,0,191,189,1,0,0,0,192,195,1,0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,
  	194,33,1,0,0,0,195,193,1,0,0,0,196,198,7,5,0,0,197,196,1,0,0,0,197,198,
  	1,0,0,0,198,199,1,0,0,0,199,200,3,38,19,0,200,35,1,0,0,0,201,222,3,44,
  	22,0,202,222,5,39,0,0,203,204,5,14,0,0,204,205,3,18,9,0,205,206,5,15,
  	0,0,206,222,1,0,0,0,207,208,5,37,0,0,208,213,5,39,0,0,209,210,5,2,0,0,
  	210,212,5,39,0,0,211,209,1,0,0,0,212,215,1,0,0,0,213,211,1,0,0,0,213,
  	214,1,0,0,0,214,216,1,0,0,0,215,213,1,0,0,0,216,218,5,14,0,0,217,219,
  	3,42,21,0,218,217,1,0,0,0,218,219,1,0,0,0,219,220,1,0,0,0,220,222,5,15,
  	0,0,221,201,1,0,0,0,221,202,1,0,0,0,221,203,1,0,0,0,221,207,1,0,0,0,222,
  	37,1,0,0,0,223,227,3,36,18,0,224,226,3,40,20,0,225,224,1,0,0,0,226,229,
  	1,0,0,0,227,225,1,0,0,0,227,228,1,0,0,0,228,39,1,0,0,0,229,227,1,0,0,
  	0,230,232,5,14,0,0,231,233,3,42,21,0,232,231,1,0,0,0,232,233,1,0,0,0,
  	233,234,1,0,0,0,234,242,5,15,0,0,235,236,5,2,0,0,236,242,5,39,0,0,237,
  	238,5,11,0,0,238,239,3,18,9,0,239,240,5,12,0,0,240,242,1,0,0,0,241,230,
  	1,0,0,0,241,235,1,0,0,0,241,237,1,0,0,0,242,41,1,0,0,0,243,248,3,18,9,
  	0,244,245,5,38,0,0,245,247,3,18,9,0,246,244,1,0,0,0,247,250,1,0,0,0,248,
  	246,1,0,0,0,248,249,1,0,0,0,249,43,1,0,0,0,250,248,1,0,0,0,251,267,5,
  	40,0,0,252,267,5,41,0,0,253,267,5,42,0,0,254,267,5,43,0,0,255,267,5,44,
  	0,0,256,258,5,11,0,0,257,259,3,46,23,0,258,257,1,0,0,0,258,259,1,0,0,
  	0,259,260,1,0,0,0,260,267,5,12,0,0,261,263,5,19,0,0,262,264,3,48,24,0,
  	263,262,1,0,0,0,263,264,1,0,0,0,264,265,1,0,0,0,265,267,5,20,0,0,266,
  	251,1,0,0,0,266,252,1,0,0,0,266,253,1,0,0,0,266,254,1,0,0,0,266,255,1,
  	0,0,0,266,256,1,0,0,0,266,261,1,0,0,0,267,45,1,0,0,0,268,273,3,18,9,0,
  	269,270,5,38,0,0,270,272,3,18,9,0,271,269,1,0,0,0,272,275,1,0,0,0,273,
  	271,1,0,0,0,273,274,1,0,0,0,274,47,1,0,0,0,275,273,1,0,0,0,276,281,3,
  	50,25,0,277,278,5,38,0,0,278,280,3,50,25,0,279,277,1,0,0,0,280,283,1,
  	0,0,0,281,279,1,0,0,0,281,282,1,0,0,0,282,49,1,0,0,0,283,281,1,0,0,0,
  	284,285,3,18,9,0,285,286,5,22,0,0,286,287,3,18,9,0,287,51,1,0,0,0,32,
  	55,65,73,78,81,99,103,112,122,125,131,138,146,153,161,169,177,185,193,
  	197,213,218,221,227,232,241,248,258,263,266,273,281
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
    setState(53); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(52);
      statement();
      setState(55); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__0)
      | (1ULL << PyScriptParser::T__10)
      | (1ULL << PyScriptParser::T__12)
      | (1ULL << PyScriptParser::T__13)
      | (1ULL << PyScriptParser::T__16)
      | (1ULL << PyScriptParser::T__17)
      | (1ULL << PyScriptParser::T__18)
      | (1ULL << PyScriptParser::T__31)
      | (1ULL << PyScriptParser::T__35)
      | (1ULL << PyScriptParser::T__36)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0));
    setState(57);
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


size_t PyScriptParser::StatementContext::getRuleIndex() const {
  return PyScriptParser::RuleStatement;
}

void PyScriptParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ImportStmtContext ------------------------------------------------------------------

PyScriptParser::ImportStatementContext* PyScriptParser::ImportStmtContext::importStatement() {
  return getRuleContext<PyScriptParser::ImportStatementContext>(0);
}

PyScriptParser::ImportStmtContext::ImportStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void PyScriptParser::ImportStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStmt(this);
}
void PyScriptParser::ImportStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStmt(this);
}

std::any PyScriptParser::ImportStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitImportStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStmtContext ------------------------------------------------------------------

PyScriptParser::ExpressionStatementContext* PyScriptParser::ExprStmtContext::expressionStatement() {
  return getRuleContext<PyScriptParser::ExpressionStatementContext>(0);
}

PyScriptParser::ExprStmtContext::ExprStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void PyScriptParser::ExprStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStmt(this);
}
void PyScriptParser::ExprStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStmt(this);
}

std::any PyScriptParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

PyScriptParser::WhileStatementContext* PyScriptParser::WhileStmtContext::whileStatement() {
  return getRuleContext<PyScriptParser::WhileStatementContext>(0);
}

PyScriptParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void PyScriptParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}
void PyScriptParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}

std::any PyScriptParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

PyScriptParser::IfStatementContext* PyScriptParser::IfStmtContext::ifStatement() {
  return getRuleContext<PyScriptParser::IfStatementContext>(0);
}

PyScriptParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void PyScriptParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void PyScriptParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}

std::any PyScriptParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

PyScriptParser::AssignmentContext* PyScriptParser::AssignStmtContext::assignment() {
  return getRuleContext<PyScriptParser::AssignmentContext>(0);
}

PyScriptParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void PyScriptParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}
void PyScriptParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}

std::any PyScriptParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

PyScriptParser::ReturnStatementContext* PyScriptParser::ReturnStmtContext::returnStatement() {
  return getRuleContext<PyScriptParser::ReturnStatementContext>(0);
}

PyScriptParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void PyScriptParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}
void PyScriptParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}

std::any PyScriptParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
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
    setState(65);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PyScriptParser::ImportStmtContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(59);
      importStatement();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PyScriptParser::AssignStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(60);
      assignment();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PyScriptParser::ExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(61);
      expressionStatement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<PyScriptParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(62);
      ifStatement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<PyScriptParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(63);
      whileStatement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<PyScriptParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(64);
      returnStatement();
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

std::vector<tree::TerminalNode *> PyScriptParser::ImportStatementContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::ImportStatementContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
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
    setState(67);
    match(PyScriptParser::T__0);
    setState(68);
    match(PyScriptParser::IDENTIFIER);
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__1) {
      setState(69);
      match(PyScriptParser::T__1);
      setState(70);
      match(PyScriptParser::IDENTIFIER);
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__2) {
      setState(76);
      match(PyScriptParser::T__2);
      setState(77);
      match(PyScriptParser::IDENTIFIER);
    }
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__3) {
      setState(80);
      match(PyScriptParser::T__3);
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


size_t PyScriptParser::AssignmentContext::getRuleIndex() const {
  return PyScriptParser::RuleAssignment;
}

void PyScriptParser::AssignmentContext::copyFrom(AssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::BinaryAssignmentContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::TernaryExpressionContext* PyScriptParser::BinaryAssignmentContext::ternaryExpression() {
  return getRuleContext<PyScriptParser::TernaryExpressionContext>(0);
}

PyScriptParser::BinaryAssignmentContext::BinaryAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }

void PyScriptParser::BinaryAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryAssignment(this);
}
void PyScriptParser::BinaryAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryAssignment(this);
}

std::any PyScriptParser::BinaryAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitBinaryAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AttributeAssignmentContext ------------------------------------------------------------------

PyScriptParser::PrimaryExpressionContext* PyScriptParser::AttributeAssignmentContext::primaryExpression() {
  return getRuleContext<PyScriptParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode* PyScriptParser::AttributeAssignmentContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::TernaryExpressionContext* PyScriptParser::AttributeAssignmentContext::ternaryExpression() {
  return getRuleContext<PyScriptParser::TernaryExpressionContext>(0);
}

PyScriptParser::AttributeAssignmentContext::AttributeAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }

void PyScriptParser::AttributeAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeAssignment(this);
}
void PyScriptParser::AttributeAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeAssignment(this);
}

std::any PyScriptParser::AttributeAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitAttributeAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptAssignmentContext ------------------------------------------------------------------

PyScriptParser::PrimaryExpressionContext* PyScriptParser::SubscriptAssignmentContext::primaryExpression() {
  return getRuleContext<PyScriptParser::PrimaryExpressionContext>(0);
}

PyScriptParser::ExpressionContext* PyScriptParser::SubscriptAssignmentContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::TernaryExpressionContext* PyScriptParser::SubscriptAssignmentContext::ternaryExpression() {
  return getRuleContext<PyScriptParser::TernaryExpressionContext>(0);
}

PyScriptParser::SubscriptAssignmentContext::SubscriptAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }

void PyScriptParser::SubscriptAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscriptAssignment(this);
}
void PyScriptParser::SubscriptAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscriptAssignment(this);
}

std::any PyScriptParser::SubscriptAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSubscriptAssignment(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::AssignmentContext* PyScriptParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 6, PyScriptParser::RuleAssignment);
  size_t _la = 0;

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PyScriptParser::BinaryAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(83);
      match(PyScriptParser::IDENTIFIER);
      setState(84);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::T__4)
        | (1ULL << PyScriptParser::T__5)
        | (1ULL << PyScriptParser::T__6)
        | (1ULL << PyScriptParser::T__7)
        | (1ULL << PyScriptParser::T__8)
        | (1ULL << PyScriptParser::T__9))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(85);
      ternaryExpression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<PyScriptParser::AttributeAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(86);
      primaryExpression();
      setState(87);
      match(PyScriptParser::T__1);
      setState(88);
      match(PyScriptParser::IDENTIFIER);
      setState(89);
      match(PyScriptParser::T__4);
      setState(90);
      ternaryExpression();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PyScriptParser::SubscriptAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(92);
      primaryExpression();
      setState(93);
      match(PyScriptParser::T__10);
      setState(94);
      expression();
      setState(95);
      match(PyScriptParser::T__11);
      setState(96);
      match(PyScriptParser::T__4);
      setState(97);
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
  enterRule(_localctx, 8, PyScriptParser::RuleExpressionStatement);
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
    expression();
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__3) {
      setState(102);
      match(PyScriptParser::T__3);
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

PyScriptParser::ExpressionContext* PyScriptParser::IfStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

std::vector<PyScriptParser::BlockContext *> PyScriptParser::IfStatementContext::block() {
  return getRuleContexts<PyScriptParser::BlockContext>();
}

PyScriptParser::BlockContext* PyScriptParser::IfStatementContext::block(size_t i) {
  return getRuleContext<PyScriptParser::BlockContext>(i);
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
    setState(105);
    match(PyScriptParser::T__12);
    setState(106);
    match(PyScriptParser::T__13);
    setState(107);
    expression();
    setState(108);
    match(PyScriptParser::T__14);
    setState(109);
    block();
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__15) {
      setState(110);
      match(PyScriptParser::T__15);
      setState(111);
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

PyScriptParser::ExpressionContext* PyScriptParser::WhileStatementContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
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
    setState(114);
    match(PyScriptParser::T__16);
    setState(115);
    match(PyScriptParser::T__13);
    setState(116);
    expression();
    setState(117);
    match(PyScriptParser::T__14);
    setState(118);
    block();
   
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
  enterRule(_localctx, 14, PyScriptParser::RuleReturnStatement);
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
    setState(120);
    match(PyScriptParser::T__17);
    setState(122);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(121);
      expression();
      break;
    }

    default:
      break;
    }
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__3) {
      setState(124);
      match(PyScriptParser::T__3);
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
  enterRule(_localctx, 16, PyScriptParser::RuleBlock);
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
    match(PyScriptParser::T__18);
    setState(131);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__0)
      | (1ULL << PyScriptParser::T__10)
      | (1ULL << PyScriptParser::T__12)
      | (1ULL << PyScriptParser::T__13)
      | (1ULL << PyScriptParser::T__16)
      | (1ULL << PyScriptParser::T__17)
      | (1ULL << PyScriptParser::T__18)
      | (1ULL << PyScriptParser::T__31)
      | (1ULL << PyScriptParser::T__35)
      | (1ULL << PyScriptParser::T__36)
      | (1ULL << PyScriptParser::IDENTIFIER)
      | (1ULL << PyScriptParser::INTEGER)
      | (1ULL << PyScriptParser::FLOAT)
      | (1ULL << PyScriptParser::STRING)
      | (1ULL << PyScriptParser::BOOL)
      | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
      setState(128);
      statement();
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(134);
    match(PyScriptParser::T__19);
   
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

PyScriptParser::TernaryExpressionContext* PyScriptParser::ExpressionContext::ternaryExpression() {
  return getRuleContext<PyScriptParser::TernaryExpressionContext>(0);
}

PyScriptParser::AssignmentContext* PyScriptParser::ExpressionContext::assignment() {
  return getRuleContext<PyScriptParser::AssignmentContext>(0);
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
  enterRule(_localctx, 18, PyScriptParser::RuleExpression);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(136);
      ternaryExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(137);
      assignment();
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

PyScriptParser::LogicalOrExpressionContext* PyScriptParser::TernaryExpressionContext::logicalOrExpression() {
  return getRuleContext<PyScriptParser::LogicalOrExpressionContext>(0);
}

PyScriptParser::ExpressionContext* PyScriptParser::TernaryExpressionContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::TernaryExpressionContext* PyScriptParser::TernaryExpressionContext::ternaryExpression() {
  return getRuleContext<PyScriptParser::TernaryExpressionContext>(0);
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
  enterRule(_localctx, 20, PyScriptParser::RuleTernaryExpression);
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
    logicalOrExpression();
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__20) {
      setState(141);
      match(PyScriptParser::T__20);
      setState(142);
      expression();
      setState(143);
      match(PyScriptParser::T__21);
      setState(144);
      ternaryExpression();
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
  enterRule(_localctx, 22, PyScriptParser::RuleLogicalOrExpression);
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
    setState(148);
    logicalAndExpression();
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__22) {
      setState(149);
      match(PyScriptParser::T__22);
      setState(150);
      logicalAndExpression();
      setState(155);
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
  enterRule(_localctx, 24, PyScriptParser::RuleLogicalAndExpression);
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
    setState(156);
    equalityExpression();
    setState(161);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__23) {
      setState(157);
      match(PyScriptParser::T__23);
      setState(158);
      equalityExpression();
      setState(163);
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
  enterRule(_localctx, 26, PyScriptParser::RuleEqualityExpression);
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
    setState(164);
    relationalExpression();
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__24

    || _la == PyScriptParser::T__25) {
      setState(165);
      _la = _input->LA(1);
      if (!(_la == PyScriptParser::T__24

      || _la == PyScriptParser::T__25)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(166);
      relationalExpression();
      setState(171);
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
  enterRule(_localctx, 28, PyScriptParser::RuleRelationalExpression);
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
    setState(172);
    additiveExpression();
    setState(177);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__26)
      | (1ULL << PyScriptParser::T__27)
      | (1ULL << PyScriptParser::T__28)
      | (1ULL << PyScriptParser::T__29))) != 0)) {
      setState(173);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::T__26)
        | (1ULL << PyScriptParser::T__27)
        | (1ULL << PyScriptParser::T__28)
        | (1ULL << PyScriptParser::T__29))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(174);
      additiveExpression();
      setState(179);
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
  enterRule(_localctx, 30, PyScriptParser::RuleAdditiveExpression);
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
    setState(180);
    multiplicativeExpression();
    setState(185);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(181);
        _la = _input->LA(1);
        if (!(_la == PyScriptParser::T__30

        || _la == PyScriptParser::T__31)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(182);
        multiplicativeExpression(); 
      }
      setState(187);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
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
  enterRule(_localctx, 32, PyScriptParser::RuleMultiplicativeExpression);
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
    setState(188);
    unaryExpression();
    setState(193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PyScriptParser::T__32)
      | (1ULL << PyScriptParser::T__33)
      | (1ULL << PyScriptParser::T__34))) != 0)) {
      setState(189);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PyScriptParser::T__32)
        | (1ULL << PyScriptParser::T__33)
        | (1ULL << PyScriptParser::T__34))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(190);
      unaryExpression();
      setState(195);
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

//----------------- UnaryExpressionContext ------------------------------------------------------------------

PyScriptParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::PostfixExpressionContext* PyScriptParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<PyScriptParser::PostfixExpressionContext>(0);
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
  enterRule(_localctx, 34, PyScriptParser::RuleUnaryExpression);
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
    setState(197);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PyScriptParser::T__31

    || _la == PyScriptParser::T__35) {
      setState(196);
      _la = _input->LA(1);
      if (!(_la == PyScriptParser::T__31

      || _la == PyScriptParser::T__35)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(199);
    postfixExpression();
   
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


size_t PyScriptParser::PrimaryExpressionContext::getRuleIndex() const {
  return PyScriptParser::RulePrimaryExpression;
}

void PyScriptParser::PrimaryExpressionContext::copyFrom(PrimaryExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdentifierPrimaryContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::IdentifierPrimaryContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::IdentifierPrimaryContext::IdentifierPrimaryContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::IdentifierPrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierPrimary(this);
}
void PyScriptParser::IdentifierPrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierPrimary(this);
}

std::any PyScriptParser::IdentifierPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitIdentifierPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenPrimaryContext ------------------------------------------------------------------

PyScriptParser::ExpressionContext* PyScriptParser::ParenPrimaryContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::ParenPrimaryContext::ParenPrimaryContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::ParenPrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenPrimary(this);
}
void PyScriptParser::ParenPrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenPrimary(this);
}

std::any PyScriptParser::ParenPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitParenPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewInstancePrimaryContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> PyScriptParser::NewInstancePrimaryContext::IDENTIFIER() {
  return getTokens(PyScriptParser::IDENTIFIER);
}

tree::TerminalNode* PyScriptParser::NewInstancePrimaryContext::IDENTIFIER(size_t i) {
  return getToken(PyScriptParser::IDENTIFIER, i);
}

PyScriptParser::ArgumentListContext* PyScriptParser::NewInstancePrimaryContext::argumentList() {
  return getRuleContext<PyScriptParser::ArgumentListContext>(0);
}

PyScriptParser::NewInstancePrimaryContext::NewInstancePrimaryContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::NewInstancePrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewInstancePrimary(this);
}
void PyScriptParser::NewInstancePrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewInstancePrimary(this);
}

std::any PyScriptParser::NewInstancePrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitNewInstancePrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralPrimaryContext ------------------------------------------------------------------

PyScriptParser::LiteralContext* PyScriptParser::LiteralPrimaryContext::literal() {
  return getRuleContext<PyScriptParser::LiteralContext>(0);
}

PyScriptParser::LiteralPrimaryContext::LiteralPrimaryContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void PyScriptParser::LiteralPrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralPrimary(this);
}
void PyScriptParser::LiteralPrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralPrimary(this);
}

std::any PyScriptParser::LiteralPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitLiteralPrimary(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::PrimaryExpressionContext* PyScriptParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 36, PyScriptParser::RulePrimaryExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::T__10:
      case PyScriptParser::T__18:
      case PyScriptParser::INTEGER:
      case PyScriptParser::FLOAT:
      case PyScriptParser::STRING:
      case PyScriptParser::BOOL:
      case PyScriptParser::NULL_LIT: {
        _localctx = _tracker.createInstance<PyScriptParser::LiteralPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(201);
        literal();
        break;
      }

      case PyScriptParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<PyScriptParser::IdentifierPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(202);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::T__13: {
        _localctx = _tracker.createInstance<PyScriptParser::ParenPrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(203);
        match(PyScriptParser::T__13);
        setState(204);
        expression();
        setState(205);
        match(PyScriptParser::T__14);
        break;
      }

      case PyScriptParser::T__36: {
        _localctx = _tracker.createInstance<PyScriptParser::NewInstancePrimaryContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(207);
        match(PyScriptParser::T__36);
        setState(208);
        match(PyScriptParser::IDENTIFIER);
        setState(213);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PyScriptParser::T__1) {
          setState(209);
          match(PyScriptParser::T__1);
          setState(210);
          match(PyScriptParser::IDENTIFIER);
          setState(215);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(216);
        match(PyScriptParser::T__13);
        setState(218);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::T__10)
          | (1ULL << PyScriptParser::T__13)
          | (1ULL << PyScriptParser::T__18)
          | (1ULL << PyScriptParser::T__31)
          | (1ULL << PyScriptParser::T__35)
          | (1ULL << PyScriptParser::T__36)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING)
          | (1ULL << PyScriptParser::BOOL)
          | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
          setState(217);
          argumentList();
        }
        setState(220);
        match(PyScriptParser::T__14);
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

//----------------- PostfixExpressionContext ------------------------------------------------------------------

PyScriptParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PyScriptParser::PrimaryExpressionContext* PyScriptParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<PyScriptParser::PrimaryExpressionContext>(0);
}

std::vector<PyScriptParser::PostfixOperatorContext *> PyScriptParser::PostfixExpressionContext::postfixOperator() {
  return getRuleContexts<PyScriptParser::PostfixOperatorContext>();
}

PyScriptParser::PostfixOperatorContext* PyScriptParser::PostfixExpressionContext::postfixOperator(size_t i) {
  return getRuleContext<PyScriptParser::PostfixOperatorContext>(i);
}


size_t PyScriptParser::PostfixExpressionContext::getRuleIndex() const {
  return PyScriptParser::RulePostfixExpression;
}

void PyScriptParser::PostfixExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void PyScriptParser::PostfixExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}


std::any PyScriptParser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::PostfixExpressionContext* PyScriptParser::postfixExpression() {
  PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, getState());
  enterRule(_localctx, 38, PyScriptParser::RulePostfixExpression);

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
    setState(223);
    primaryExpression();
    setState(227);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(224);
        postfixOperator(); 
      }
      setState(229);
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

//----------------- PostfixOperatorContext ------------------------------------------------------------------

PyScriptParser::PostfixOperatorContext::PostfixOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::PostfixOperatorContext::getRuleIndex() const {
  return PyScriptParser::RulePostfixOperator;
}

void PyScriptParser::PostfixOperatorContext::copyFrom(PostfixOperatorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MemberAccessPostfixContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::MemberAccessPostfixContext::IDENTIFIER() {
  return getToken(PyScriptParser::IDENTIFIER, 0);
}

PyScriptParser::MemberAccessPostfixContext::MemberAccessPostfixContext(PostfixOperatorContext *ctx) { copyFrom(ctx); }

void PyScriptParser::MemberAccessPostfixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberAccessPostfix(this);
}
void PyScriptParser::MemberAccessPostfixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberAccessPostfix(this);
}

std::any PyScriptParser::MemberAccessPostfixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitMemberAccessPostfix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptPostfixContext ------------------------------------------------------------------

PyScriptParser::ExpressionContext* PyScriptParser::SubscriptPostfixContext::expression() {
  return getRuleContext<PyScriptParser::ExpressionContext>(0);
}

PyScriptParser::SubscriptPostfixContext::SubscriptPostfixContext(PostfixOperatorContext *ctx) { copyFrom(ctx); }

void PyScriptParser::SubscriptPostfixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscriptPostfix(this);
}
void PyScriptParser::SubscriptPostfixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscriptPostfix(this);
}

std::any PyScriptParser::SubscriptPostfixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitSubscriptPostfix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallPostfixContext ------------------------------------------------------------------

PyScriptParser::ArgumentListContext* PyScriptParser::FunctionCallPostfixContext::argumentList() {
  return getRuleContext<PyScriptParser::ArgumentListContext>(0);
}

PyScriptParser::FunctionCallPostfixContext::FunctionCallPostfixContext(PostfixOperatorContext *ctx) { copyFrom(ctx); }

void PyScriptParser::FunctionCallPostfixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallPostfix(this);
}
void PyScriptParser::FunctionCallPostfixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallPostfix(this);
}

std::any PyScriptParser::FunctionCallPostfixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionCallPostfix(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::PostfixOperatorContext* PyScriptParser::postfixOperator() {
  PostfixOperatorContext *_localctx = _tracker.createInstance<PostfixOperatorContext>(_ctx, getState());
  enterRule(_localctx, 40, PyScriptParser::RulePostfixOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(241);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::T__13: {
        _localctx = _tracker.createInstance<PyScriptParser::FunctionCallPostfixContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(230);
        match(PyScriptParser::T__13);
        setState(232);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::T__10)
          | (1ULL << PyScriptParser::T__13)
          | (1ULL << PyScriptParser::T__18)
          | (1ULL << PyScriptParser::T__31)
          | (1ULL << PyScriptParser::T__35)
          | (1ULL << PyScriptParser::T__36)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING)
          | (1ULL << PyScriptParser::BOOL)
          | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
          setState(231);
          argumentList();
        }
        setState(234);
        match(PyScriptParser::T__14);
        break;
      }

      case PyScriptParser::T__1: {
        _localctx = _tracker.createInstance<PyScriptParser::MemberAccessPostfixContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(235);
        match(PyScriptParser::T__1);
        setState(236);
        match(PyScriptParser::IDENTIFIER);
        break;
      }

      case PyScriptParser::T__10: {
        _localctx = _tracker.createInstance<PyScriptParser::SubscriptPostfixContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(237);
        match(PyScriptParser::T__10);
        setState(238);
        expression();
        setState(239);
        match(PyScriptParser::T__11);
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
  enterRule(_localctx, 42, PyScriptParser::RuleArgumentList);
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
    setState(243);
    expression();
    setState(248);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__37) {
      setState(244);
      match(PyScriptParser::T__37);
      setState(245);
      expression();
      setState(250);
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

//----------------- LiteralContext ------------------------------------------------------------------

PyScriptParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PyScriptParser::LiteralContext::getRuleIndex() const {
  return PyScriptParser::RuleLiteral;
}

void PyScriptParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NullLiteralContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::NullLiteralContext::NULL_LIT() {
  return getToken(PyScriptParser::NULL_LIT, 0);
}

PyScriptParser::NullLiteralContext::NullLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void PyScriptParser::NullLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNullLiteral(this);
}
void PyScriptParser::NullLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNullLiteral(this);
}

std::any PyScriptParser::NullLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitNullLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DictLiteralContext ------------------------------------------------------------------

PyScriptParser::KeyValuePairListContext* PyScriptParser::DictLiteralContext::keyValuePairList() {
  return getRuleContext<PyScriptParser::KeyValuePairListContext>(0);
}

PyScriptParser::DictLiteralContext::DictLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

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
//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::StringLiteralContext::STRING() {
  return getToken(PyScriptParser::STRING, 0);
}

PyScriptParser::StringLiteralContext::StringLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void PyScriptParser::StringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiteral(this);
}
void PyScriptParser::StringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiteral(this);
}

std::any PyScriptParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListLiteralContext ------------------------------------------------------------------

PyScriptParser::ExpressionListContext* PyScriptParser::ListLiteralContext::expressionList() {
  return getRuleContext<PyScriptParser::ExpressionListContext>(0);
}

PyScriptParser::ListLiteralContext::ListLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

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
//----------------- IntegerLiteralContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::IntegerLiteralContext::INTEGER() {
  return getToken(PyScriptParser::INTEGER, 0);
}

PyScriptParser::IntegerLiteralContext::IntegerLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void PyScriptParser::IntegerLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerLiteral(this);
}
void PyScriptParser::IntegerLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerLiteral(this);
}

std::any PyScriptParser::IntegerLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitIntegerLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatLiteralContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::FloatLiteralContext::FLOAT() {
  return getToken(PyScriptParser::FLOAT, 0);
}

PyScriptParser::FloatLiteralContext::FloatLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void PyScriptParser::FloatLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLiteral(this);
}
void PyScriptParser::FloatLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLiteral(this);
}

std::any PyScriptParser::FloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanLiteralContext ------------------------------------------------------------------

tree::TerminalNode* PyScriptParser::BooleanLiteralContext::BOOL() {
  return getToken(PyScriptParser::BOOL, 0);
}

PyScriptParser::BooleanLiteralContext::BooleanLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void PyScriptParser::BooleanLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanLiteral(this);
}
void PyScriptParser::BooleanLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanLiteral(this);
}

std::any PyScriptParser::BooleanLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitBooleanLiteral(this);
  else
    return visitor->visitChildren(this);
}
PyScriptParser::LiteralContext* PyScriptParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 44, PyScriptParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PyScriptParser::INTEGER: {
        _localctx = _tracker.createInstance<PyScriptParser::IntegerLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(251);
        match(PyScriptParser::INTEGER);
        break;
      }

      case PyScriptParser::FLOAT: {
        _localctx = _tracker.createInstance<PyScriptParser::FloatLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(252);
        match(PyScriptParser::FLOAT);
        break;
      }

      case PyScriptParser::STRING: {
        _localctx = _tracker.createInstance<PyScriptParser::StringLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(253);
        match(PyScriptParser::STRING);
        break;
      }

      case PyScriptParser::BOOL: {
        _localctx = _tracker.createInstance<PyScriptParser::BooleanLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(254);
        match(PyScriptParser::BOOL);
        break;
      }

      case PyScriptParser::NULL_LIT: {
        _localctx = _tracker.createInstance<PyScriptParser::NullLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(255);
        match(PyScriptParser::NULL_LIT);
        break;
      }

      case PyScriptParser::T__10: {
        _localctx = _tracker.createInstance<PyScriptParser::ListLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(256);
        match(PyScriptParser::T__10);
        setState(258);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::T__10)
          | (1ULL << PyScriptParser::T__13)
          | (1ULL << PyScriptParser::T__18)
          | (1ULL << PyScriptParser::T__31)
          | (1ULL << PyScriptParser::T__35)
          | (1ULL << PyScriptParser::T__36)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING)
          | (1ULL << PyScriptParser::BOOL)
          | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
          setState(257);
          expressionList();
        }
        setState(260);
        match(PyScriptParser::T__11);
        break;
      }

      case PyScriptParser::T__18: {
        _localctx = _tracker.createInstance<PyScriptParser::DictLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(261);
        match(PyScriptParser::T__18);
        setState(263);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PyScriptParser::T__10)
          | (1ULL << PyScriptParser::T__13)
          | (1ULL << PyScriptParser::T__18)
          | (1ULL << PyScriptParser::T__31)
          | (1ULL << PyScriptParser::T__35)
          | (1ULL << PyScriptParser::T__36)
          | (1ULL << PyScriptParser::IDENTIFIER)
          | (1ULL << PyScriptParser::INTEGER)
          | (1ULL << PyScriptParser::FLOAT)
          | (1ULL << PyScriptParser::STRING)
          | (1ULL << PyScriptParser::BOOL)
          | (1ULL << PyScriptParser::NULL_LIT))) != 0)) {
          setState(262);
          keyValuePairList();
        }
        setState(265);
        match(PyScriptParser::T__19);
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
  enterRule(_localctx, 46, PyScriptParser::RuleExpressionList);
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
    setState(268);
    expression();
    setState(273);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__37) {
      setState(269);
      match(PyScriptParser::T__37);
      setState(270);
      expression();
      setState(275);
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

//----------------- KeyValuePairListContext ------------------------------------------------------------------

PyScriptParser::KeyValuePairListContext::KeyValuePairListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::KeyValuePairContext *> PyScriptParser::KeyValuePairListContext::keyValuePair() {
  return getRuleContexts<PyScriptParser::KeyValuePairContext>();
}

PyScriptParser::KeyValuePairContext* PyScriptParser::KeyValuePairListContext::keyValuePair(size_t i) {
  return getRuleContext<PyScriptParser::KeyValuePairContext>(i);
}


size_t PyScriptParser::KeyValuePairListContext::getRuleIndex() const {
  return PyScriptParser::RuleKeyValuePairList;
}

void PyScriptParser::KeyValuePairListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyValuePairList(this);
}

void PyScriptParser::KeyValuePairListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PyScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyValuePairList(this);
}


std::any PyScriptParser::KeyValuePairListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PyScriptVisitor*>(visitor))
    return parserVisitor->visitKeyValuePairList(this);
  else
    return visitor->visitChildren(this);
}

PyScriptParser::KeyValuePairListContext* PyScriptParser::keyValuePairList() {
  KeyValuePairListContext *_localctx = _tracker.createInstance<KeyValuePairListContext>(_ctx, getState());
  enterRule(_localctx, 48, PyScriptParser::RuleKeyValuePairList);
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
    keyValuePair();
    setState(281);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PyScriptParser::T__37) {
      setState(277);
      match(PyScriptParser::T__37);
      setState(278);
      keyValuePair();
      setState(283);
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

//----------------- KeyValuePairContext ------------------------------------------------------------------

PyScriptParser::KeyValuePairContext::KeyValuePairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PyScriptParser::ExpressionContext *> PyScriptParser::KeyValuePairContext::expression() {
  return getRuleContexts<PyScriptParser::ExpressionContext>();
}

PyScriptParser::ExpressionContext* PyScriptParser::KeyValuePairContext::expression(size_t i) {
  return getRuleContext<PyScriptParser::ExpressionContext>(i);
}


size_t PyScriptParser::KeyValuePairContext::getRuleIndex() const {
  return PyScriptParser::RuleKeyValuePair;
}

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

PyScriptParser::KeyValuePairContext* PyScriptParser::keyValuePair() {
  KeyValuePairContext *_localctx = _tracker.createInstance<KeyValuePairContext>(_ctx, getState());
  enterRule(_localctx, 50, PyScriptParser::RuleKeyValuePair);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    expression();
    setState(285);
    match(PyScriptParser::T__21);
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

void PyScriptParser::initialize() {
  std::call_once(pyscriptParserOnceFlag, pyscriptParserInitialize);
}
