//=============================================================================
// Alias.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Alias
//-----------------------------------------------------------------------------
Alias::Alias() : _cntRef(1)
{
}

bool Alias::Parse(Environment &env, const char *str)
{
	enum {
		STAT_KeyPre,
		STAT_Key,
		STAT_KeyPost,
		STAT_ArgNumPre,
		STAT_ArgNum,
		STAT_ArgNumPost,
		STAT_Assign,
		STAT_Quote,
		STAT_String,
		STAT_QuoteLast,
		STAT_BackSlash,
		STAT_BackSlashAlpha,
		STAT_ArgRef,
	} stat = STAT_KeyPre;
	size_t num = 0;
	String field;
	String strAhead;
	char chSlashed = '\0';
	bool quotedFlag = false;
	for (const char *p = str; ; p++) {
		char ch = *p;
		Gura_BeginPushbackRegion();
		switch (stat) {
		case STAT_KeyPre: {
			if (ch == ' ' || ch == '\t' || ch == '\n') {
				// nothing to do
			} else if (IsKeyCharBegin(ch)) {
				field.clear();
				Gura_Pushback();
				stat = STAT_Key;
			} else { // including '\0'
				env.SetError(ERR_SyntaxError, "invalid character for alias key");
				return false;
			}
			break;
		}
		case STAT_Key: {
			if (IsKeyChar(ch)) {
				field += ch;
			} else { // including '\0'
				Gura_Pushback(); 
				stat = STAT_KeyPost;
			}
			break;
		}
		case STAT_KeyPost: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '{') {
				field += ch;
				stat = STAT_ArgNumPre;
			} else if (ch == '=') {
				_key = field;
				stat = STAT_Quote;
			} else {
				env.SetError(ERR_SyntaxError, "invalid syntax for alias assignment");
				return false;
			}
			break;
		}
		case STAT_ArgNumPre: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (IsDigit(ch)) {
				Gura_Pushback();
				stat = STAT_ArgNum;
			} else {
				env.SetError(ERR_SyntaxError, "invalid declaration of argument number");
				return false;
			}
			break;
		}
		case STAT_ArgNum: {
			if (IsDigit(ch)) {
				field += ch;
			} else {
				Gura_Pushback();
				stat = STAT_ArgNumPost;
			}
			break;
		}
		case STAT_ArgNumPost: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '}') {
				field += ch;
				stat = STAT_Assign;
			} else {
				env.SetError(ERR_SyntaxError, "invalid declaration of argument number");
				return false;
			}
			break;
		}
		case STAT_Assign: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '=') {
				_key = field;
				stat = STAT_Quote;
			} else {
				env.SetError(ERR_SyntaxError, "assignment operator is expected");
				return false;
			}
			break;
		}
		case STAT_Quote: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '"') {
				quotedFlag = true;
				field.clear();
				stat = STAT_String;
			} else {
				Gura_Pushback();
				quotedFlag = false;
				field.clear();
				stat = STAT_String;
			}
			break;
		}
		case STAT_String: {
			if (ch == '\\') {
				stat = STAT_BackSlash;
			} else if (ch == '\0') {
				if (!field.empty()) {
					_elemOwner.push_back(new Elem_String(field));
				}
			} else if (quotedFlag && ch == '"') {
				strAhead.clear();
				strAhead += ch;
				stat = STAT_QuoteLast;
			} else {
				field += ch;
			}
			break;
		}
		case STAT_QuoteLast: {
			if (ch == ' ' || ch == '\t') {
				strAhead += ch;
			} else if (ch == '\0') {
				if (!field.empty()) {
					_elemOwner.push_back(new Elem_String(field));
				}
			} else {
				field += strAhead;
				Gura_Pushback();
				stat = STAT_String;
			}
			break;
		}
		case STAT_BackSlash: {
			if (IsDigit(ch)) {
				if (!field.empty()) {
					_elemOwner.push_back(new Elem_String(field));
				}
				num = 0;
				Gura_Pushback();
				stat = STAT_ArgRef;
			} else if (ch == '"') {
				Gura_Pushback();
				stat = STAT_String;
			} else if (ch == 't') {
				chSlashed = ch;
				stat = STAT_BackSlashAlpha;
			} else if (ch == 'n') {
				chSlashed = ch;
				stat = STAT_BackSlashAlpha;
			} else {
				Gura_Pushback();
				field += '\\';
				stat = STAT_String;
			}
			break;
		}
		case STAT_BackSlashAlpha: {
			if (IsAlpha(ch)) {
				field += '\\';
				field += chSlashed;
				Gura_Pushback();
				stat = STAT_String;
			} else {
				field += (chSlashed == 't')? '\t' : (chSlashed == 'n')? '\n' : '?';
				Gura_Pushback();
				stat = STAT_String;
			}
			break;
		}
		case STAT_ArgRef: {
			if (IsDigit(ch)) {
				num = num * 10 + (ch - '0');
			} else {
				if (num == 0) {
					env.SetError(ERR_OutOfRangeError, "argument index is out of range");
					return false;
				}
				_elemOwner.push_back(new Elem_ArgRef(num - 1));
				Gura_Pushback();
				field.clear();
				stat = STAT_String;
			}
			break;
		}
		}
		Gura_EndPushbackRegion();
		if (ch == '\0') break;
	}
	return true;
}

bool Alias::Evaluate(Environment &env, String &rtn, const StringList &strArgs) const
{
	return _elemOwner.Evaluate(env, rtn, strArgs);
}

void Alias::Print() const
{
	::printf("%s =\n  '%s'\n", _key.c_str(), _elemOwner.ToString().c_str());
}

//-----------------------------------------------------------------------------
// Alias::Elem
//-----------------------------------------------------------------------------
Alias::Elem::~Elem()
{
}

//-----------------------------------------------------------------------------
// Alias::Elem_String
//-----------------------------------------------------------------------------
bool Alias::Elem_String::Evaluate(Environment &env, String &rtn, const StringList &strArgs) const
{
	rtn += _str;
	return true;
}

String Alias::Elem_String::ToString() const
{
	return _str;
}

//-----------------------------------------------------------------------------
// Alias::Elem_ArgRef
//-----------------------------------------------------------------------------
bool Alias::Elem_ArgRef::Evaluate(Environment &env, String &rtn, const StringList &strArgs) const
{
	if (_iArg >= strArgs.size()) {
		env.SetError(ERR_OutOfRangeError, "argument index is out of range");
		return false;
	}
	rtn += strArgs[_iArg];
	return true;
}

String Alias::Elem_ArgRef::ToString() const
{
	char buff[32];
	::sprintf(buff, "\\%ld", _iArg + 1);
	return buff;
}

//-----------------------------------------------------------------------------
// Alias::ElemList
//-----------------------------------------------------------------------------
bool Alias::ElemList::Evaluate(Environment &env, String &rtn, const StringList &strArgs) const
{
	foreach_const (ElemList, ppElem, *this) {
		const Elem *pElem = *ppElem;
		if (!pElem->Evaluate(env, rtn, strArgs)) return false;
	}
	return true;
}

String Alias::ElemList::ToString() const
{
	String rtn;
	foreach_const (ElemList, ppElem, *this) {
		const Elem *pElem = *ppElem;
		rtn += pElem->ToString();
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Alias::ElemOwner
//-----------------------------------------------------------------------------
Alias::ElemOwner::~ElemOwner()
{
	Clear();
}

void Alias::ElemOwner::Clear()
{
	foreach (ElemOwner, ppElem, *this) {
		delete *ppElem;
	}
	clear();
}

//-----------------------------------------------------------------------------
// AliasDict
//-----------------------------------------------------------------------------
AliasDict::~AliasDict()
{
	Clear();
}

void AliasDict::Clear()
{
	foreach (AliasDict, iter, *this) {
		Alias::Delete(iter->second);
	}
	clear();
}

void AliasDict::Print() const
{
	foreach_const (AliasDict, iter, *this) {
		iter->second->Print();
	}
}

//-----------------------------------------------------------------------------
// Aliases
//-----------------------------------------------------------------------------
Aliases::Aliases() : _cntRef(1)
{
}

bool Aliases::AddSource(Environment &env, const char *str)
{
	AutoPtr<Alias> pAlias(new Alias());
	if (!pAlias->Parse(env, str)) return false;
	_aliasDict[pAlias->GetKey()] = pAlias->Reference();
	return true;
}

const Alias *Aliases::Lookup(const char *cmdName, size_t nArgs) const
{
	String key = cmdName;
	if (nArgs > 0) {
		char buff[32];
		::sprintf(buff, "{%ld}", nArgs);
		key += buff;
	}
	AliasDict::const_iterator iter = _aliasDict.find(key);
	return (iter == _aliasDict.end())? nullptr : iter->second;
}

void Aliases::Print() const
{
	_aliasDict.Print();
}

Gura_EndModuleScope(doxygen)
