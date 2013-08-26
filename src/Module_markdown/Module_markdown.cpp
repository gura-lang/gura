//-----------------------------------------------------------------------------
// Gura test module
//-----------------------------------------------------------------------------
#include "Module_markdown.h"

Gura_BeginModule(test)

class Parser {
public:
	class Dispatcher {
	public:
		virtual void OnSpan(Parser *pParser) = 0;
		virtual void OnEmphasis(Parser *pParser) = 0;
		virtual void OnStrong(Parser *pParser) = 0;
	};
private:
	enum Stat {
		STAT_LineTop,
		STAT_HyphenFirst,
		STAT_ItemPre,
		STAT_Line,
		STAT_EmphasisPre, STAT_Emphasis,
		STAT_Strong, STAT_StrongEnd,
	};
private:
	Dispatcher *_pDispatcher;
	Stat _stat;
	String _str;
public:
	Parser(Dispatcher *pDispatcher);
	bool ParseChar(Environment &env, Signal sig, char ch);
	inline const char *GetString() const { return _str.c_str(); }
};

class Dispatcher : public Parser::Dispatcher {
public:
	virtual void OnSpan(Parser *pParser);
	virtual void OnEmphasis(Parser *pParser);
	virtual void OnStrong(Parser *pParser);
};

void Dispatcher::OnSpan(Parser *pParser)
{
	::printf("[Span]%s\n", pParser->GetString());
}

void Dispatcher::OnEmphasis(Parser *pParser)
{
	::printf("[Emphasis]%s\n", pParser->GetString());
}

void Dispatcher::OnStrong(Parser *pParser)
{
	::printf("[Strong]%s\n", pParser->GetString());
}

Parser::Parser(Dispatcher *pDispatcher) : _pDispatcher(pDispatcher), _stat(STAT_LineTop)
{
}

bool Parser::ParseChar(Environment &env, Signal sig, char ch)
{
	bool continueFlag = false;
	do 	{
	continueFlag = false;
	switch (_stat) {
	case STAT_LineTop: {
		if (ch == ' ' || ch == '\t') {
			
		} else if (ch == '-') {
			if (!_str.empty()) {
				_pDispatcher->OnSpan(this);
				_str.clear();
			}
			_stat = STAT_HyphenFirst;
		} else if (ch == '\n') {
			if (!_str.empty()) {
				_pDispatcher->OnSpan(this);
				_str.clear();
			}
		} else if (ch == '\0') {
			if (!_str.empty()) {
				_pDispatcher->OnSpan(this);
				_str.clear();
			}
		} else {
			if (!_str.empty()) _str += ' ';
			continueFlag = true;
			_stat = STAT_Line;
		}
		break;
	}
	case STAT_HyphenFirst: {
		if (ch == '-') {
			
		} else if (ch == '\n' || ch == '\0') {
			_stat = STAT_LineTop;
		} else {
			continueFlag = true;
			_stat = STAT_ItemPre;
		}
		break;
	}
	case STAT_ItemPre: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			continueFlag = true;
			_stat = STAT_Line;
		}
		break;
	}
	case STAT_Line: {
		if (ch == '*') {
			if (!_str.empty()) {
				_pDispatcher->OnSpan(this);
				_str.clear();
			}
			_stat = STAT_EmphasisPre;
		} else if (ch == '\n') {
			_stat = STAT_LineTop;
		} else if (ch == '\0') {
			continueFlag = true;
			_stat = STAT_LineTop;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_EmphasisPre: {
		if (ch == '*') {
			_stat = STAT_Strong;
		} else if (ch == '\n' || ch == '\0') {
			_stat = STAT_LineTop;
		} else {
			continueFlag = true;
			_stat = STAT_Emphasis;
		}
		break;
	}
	case STAT_Emphasis: {
		if (ch == '*') {
			if (!_str.empty()) {
				_pDispatcher->OnEmphasis(this);
				_str.clear();
			}
			_stat = STAT_Line;
		} else if (ch == '\n' || ch == '\0') {
			if (!_str.empty()) {
				_pDispatcher->OnEmphasis(this);
				_str.clear();
			}
			_stat = STAT_LineTop;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_Strong: {
		if (ch == '*') {
			if (!_str.empty()) {
				_pDispatcher->OnStrong(this);
				_str.clear();
			}
			_stat = STAT_StrongEnd;
		} else if (ch == '\n' || ch == '\0') {
			if (!_str.empty()) {
				_pDispatcher->OnStrong(this);
				_str.clear();
			}
			_stat = STAT_LineTop;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_StrongEnd: {
		if (ch == '*') {
			_stat = STAT_Line;
		} else {
			continueFlag = true;
			_stat = STAT_Line;
		}
		break;
	}
	}
	} while (continueFlag);
	return true;
}

//-----------------------------------------------------------------------------
// Gura module functions: test
//-----------------------------------------------------------------------------
// test.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
}

Gura_ImplementFunction(test)
{
	Dispatcher dispatcher;
	Parser parser(&dispatcher);
	Stream &stream = args.GetStream(0);
	for (;;) {
		int chRaw = stream.GetChar(sig);
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		if (!parser.ParseChar(env, sig, ch)) return false;
		if (chRaw < 0) break;
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(test, test)

Gura_RegisterModule(test)
