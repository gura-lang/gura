//-----------------------------------------------------------------------------
// Gura test module
//-----------------------------------------------------------------------------
#include "Module_markdown.h"

Gura_BeginModule(test)

//-----------------------------------------------------------------------------
// Element
//-----------------------------------------------------------------------------
class Element {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Element);
public:
	Element();
private:
	inline ~Element() {}
public:
	
};

//-----------------------------------------------------------------------------
// ElementList
//-----------------------------------------------------------------------------
class ElementList : public std::vector<Element *> {
};

//-----------------------------------------------------------------------------
// ElementOwner
//-----------------------------------------------------------------------------
class ElementOwner : public ElementList {
public:
	~ElementOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Element
//-----------------------------------------------------------------------------
Element::Element() : _cntRef(1)
{
}

//-----------------------------------------------------------------------------
// ElementList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ElementOwner
//-----------------------------------------------------------------------------
ElementOwner::~ElementOwner()
{
	Clear();
}

void ElementOwner::Clear()
{
	foreach (ElementOwner, ppElement, *this) {
		Element *pElement = *ppElement;
		Element::Delete(pElement);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
class Document {
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
	Stat _stat;
	String _str;
	ElementOwner _elemOwner;
public:
	Document();
	bool ParseChar(Environment &env, Signal sig, char ch);
	inline const char *GetString() const { return _str.c_str(); }
};

Document::Document() : _stat(STAT_LineTop)
{
}

bool Document::ParseChar(Environment &env, Signal sig, char ch)
{
	bool continueFlag = false;
	do 	{
	continueFlag = false;
	switch (_stat) {
	case STAT_LineTop: {
		if (ch == ' ' || ch == '\t') {
			
		} else if (ch == '-') {
			if (!_str.empty()) {
				//_pDispatcher->OnSpan(this);
				_str.clear();
			}
			_stat = STAT_HyphenFirst;
		} else if (ch == '\n') {
			if (!_str.empty()) {
				//_pDispatcher->OnSpan(this);
				_str.clear();
			}
		} else if (ch == '\0') {
			if (!_str.empty()) {
				//_pDispatcher->OnSpan(this);
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
				//_pDispatcher->OnSpan(this);
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
				//_pDispatcher->OnEmphasis(this);
				_str.clear();
			}
			_stat = STAT_Line;
		} else if (ch == '\n' || ch == '\0') {
			if (!_str.empty()) {
				//_pDispatcher->OnEmphasis(this);
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
				//_pDispatcher->OnStrong(this);
				_str.clear();
			}
			_stat = STAT_StrongEnd;
		} else if (ch == '\n' || ch == '\0') {
			if (!_str.empty()) {
				//_pDispatcher->OnStrong(this);
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
// Gura module functions: markdown
//-----------------------------------------------------------------------------
// markdown.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
}

Gura_ImplementFunction(test)
{
	Document doc;
	Stream &stream = args.GetStream(0);
	for (;;) {
		int chRaw = stream.GetChar(sig);
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		if (!doc.ParseChar(env, sig, ch)) return false;
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
