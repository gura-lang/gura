//
// Object_string
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_string
//-----------------------------------------------------------------------------
Object_string::Object_string(const Object_string &obj) : Object(obj), _str(obj._str)
{
}

Object_string::~Object_string()
{
}

Object *Object_string::Clone() const
{
	return new Object_string(*this);
}

Value Object_string::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (!valueIdx.IsNumber()) {
		sig.SetError(ERR_IndexError, "index must be a number for string");
		return Value::Null;
	}
	int idx = valueIdx.GetInt();
	int len = static_cast<int>(Length(_str.c_str()));
	if (idx >= 0) {
		if (idx >= len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return Value::Null;
		}
		return Value(*this, PickChar(_str, idx).c_str());
	} else {
		if (-idx > len) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return Value::Null;
		}
		return Value(*this, PickChar(_str, len + idx).c_str());
	}
}

Iterator *Object_string::CreateIterator(Signal sig)
{
	return new IteratorEach(_str, -1, IteratorEach::ATTR_None);
}

String Object_string::ToString(Signal sig, bool exprFlag)
{
	return ToString(sig, _str.c_str(), exprFlag);
}

String Object_string::ToString(Signal sig, const char *str, bool exprFlag)
{
	if (exprFlag) return MakeQuotedString(str);
	return String(str);
}

//-----------------------------------------------------------------------------
// Object_string::IteratorEach
//-----------------------------------------------------------------------------
Object_string::IteratorEach::IteratorEach(const String &str, int cntMax, Attr attr) :
	Iterator(false), _str(str), _cnt(cntMax), _cntMax(cntMax), _attr(attr)
{
	_pCur = _str.begin();
}

Object_string::IteratorEach::~IteratorEach()
{
}

bool Object_string::IteratorEach::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _str.end()) return false;
	if (_attr == ATTR_UTF8) {
		uint64 codeUTF8;
		_pCur = NextUTF8(_str, _pCur, codeUTF8);
		value = Value(codeUTF8);
	} else if (_attr == ATTR_UTF32) {
		unsigned long codeUTF32;
		_pCur = NextUTF32(_str, _pCur, codeUTF32);
		value = Value(codeUTF32);
	} else {
		String::const_iterator pLeft = _pCur;
		if (_cnt == 0) {
			_pCur = _str.end();
		} else {
			_pCur = NextChar(_str, _pCur);
			if (_cnt > 0) _cnt--;
		}
		value = Value(env, String(pLeft, _pCur).c_str());
	}
	return true;
}

String Object_string::IteratorEach::ToString(Signal sig) const
{
	return String("<iterator:string:each>");
}

void Object_string::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_string::IteratorLine
//-----------------------------------------------------------------------------
Object_string::IteratorLine::IteratorLine(const String &str,
											int cntMax, bool includeEOLFlag) :
			Iterator(false), _str(str), _cnt(cntMax), _cntMax(cntMax),
			_includeEOLFlag(includeEOLFlag)
{
	_pCur = _str.begin();
}

Object_string::IteratorLine::~IteratorLine()
{
}

bool Object_string::IteratorLine::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _str.end() || _cnt == 0) return false;
	String::const_iterator pLeft = _pCur;
	String::const_iterator pNext = _str.end();
	for ( ; _pCur != _str.end(); _pCur++) {
		if (*_pCur == '\r') {
			pNext = _pCur + 1;
			if (pNext != _str.end() && *pNext == '\n') pNext++;
			break;
		} else if (*_pCur == '\n') {
			pNext = _pCur + 1;
			break;
		}
	}
	value = Value(env, String(pLeft, _includeEOLFlag? pNext : _pCur).c_str());
	_pCur = pNext;
	if (_cnt > 0) _cnt--;
	return true;
}

String Object_string::IteratorLine::ToString(Signal sig) const
{
	return String("<iterator>");
}

void Object_string::IteratorLine::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_string::IteratorSplit
//-----------------------------------------------------------------------------
Object_string::IteratorSplit::IteratorSplit(const String &str, const char *sep,
											int cntMax, bool ignoreCaseFlag) :
	Iterator(false), _str(str), _sep(sep), _cnt(cntMax), _cntMax(cntMax),
	_ignoreCaseFlag(ignoreCaseFlag), _doneFlag(false)
{
	_pCur = _str.begin();
}

Object_string::IteratorSplit::~IteratorSplit()
{
}

bool Object_string::IteratorSplit::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) {
		return false;
	} else if (_pCur == _str.end()) {
		value = Value(env, "");
		_doneFlag = true;
	} else if (_cnt == 0) {
		String::const_iterator pEnd = _str.end();
		value = Value(env, String(_pCur, pEnd).c_str());
		_pCur = _str.end();
		_doneFlag = true;
	} else {
		String::const_iterator pRight =
							FindString(_pCur, _str.end(), _sep, _ignoreCaseFlag);
		value = Value(env, String(_pCur, pRight).c_str());
		if (pRight == _str.end()) {
			_pCur = _str.end();
			_doneFlag = true;
		} else {
			_pCur = pRight + _sep.size();
		}
		if (_cnt > 0) _cnt--;
	}
	return true;
}

String Object_string::IteratorSplit::ToString(Signal sig) const
{
	return String("<iterator>");
}

void Object_string::IteratorSplit::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_string::IteratorFold
//-----------------------------------------------------------------------------
Object_string::IteratorFold::IteratorFold(const String &str,
										size_t cntPerFold, size_t cntStep) :
	Iterator(false), _str(str), _cntPerFold(cntPerFold), _cntStep(cntStep)
{
	_pCur = _str.begin();
}

Object_string::IteratorFold::~IteratorFold()
{
}

bool Object_string::IteratorFold::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _str.end()) {
		return false;
	} else {
		String::const_iterator pNext, pTail;
		if (_cntStep <= _cntPerFold) {
			pNext = Forward(_pCur, _str.end(), _cntStep);
			pTail = Forward(pNext, _str.end(), _cntPerFold - _cntStep);
		} else {
			pTail = Forward(_pCur, _str.end(), _cntPerFold);
			pNext = Forward(pTail, _str.end(), _cntStep - _cntPerFold);
		}
		value = Value(env, String(_pCur, pTail).c_str());
		_pCur = pNext;
	}
	return true;
}

String Object_string::IteratorFold::ToString(Signal sig) const
{
	return String("<iterator>");
}

void Object_string::IteratorFold::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_string
//-----------------------------------------------------------------------------
// string#len()
Gura_DeclareMethod(string, len)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp("Returns the length of the string in characters.");
}

Gura_ImplementMethod(string, len)
{
	return Value(static_cast<unsigned int>(Length(args.GetSelf().GetString())));
}

// string#isempty()
Gura_DeclareMethod(string, isempty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp("Returns true if the string is empty.");
}

Gura_ImplementMethod(string, isempty)
{
	return Value(*args.GetSelf().GetString() == '\0');
}

// string#capitalize()
Gura_DeclareMethod(string, capitalize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp(
	"Returns a string copied from the original one but with the first character\n"
	"capitalized.");
}

Gura_ImplementMethod(string, capitalize)
{
	return Value(env, Capitalize(args.GetSelf().GetString()).c_str());
}

// string#lower()
Gura_DeclareMethod(string, lower)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp("Returns a string of lowercase characters of the original one");
}

Gura_ImplementMethod(string, lower)
{
	return Value(env, Lower(args.GetSelf().GetString()).c_str());
}

// string#upper()
Gura_DeclareMethod(string, upper)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp("Returns a string of uppercase characters of the original one");
}

Gura_ImplementMethod(string, upper)
{
	return Value(env, Upper(args.GetSelf().GetString()).c_str());
}

// string#zentohan()
Gura_DeclareMethod(string, zentohan)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp("Converts zenkaku to hankaku characters");
}

Gura_ImplementMethod(string, zentohan)
{
	return Value(env, ZenToHan(args.GetSelf().GetString()).c_str());
}

// string#strip():[both,left,right]
Gura_DeclareMethod(string, strip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(both));
	DeclareAttr(Gura_Symbol(left));
	DeclareAttr(Gura_Symbol(right));
	SetHelp(
	"Returns a string that removes space characters on left, right or both of\n"
	"the original one. An attribute :both removes spaces on both sides, :left on left\n"
	"and :right on right. An attribut :both is the default behaviour.");
}

Gura_ImplementMethod(string, strip)
{
	return Value(env, Strip(args.GetSelf().GetString(), args.GetAttrs()).c_str());
}

// string#chop(suffix*:string):[eol,icase]
Gura_DeclareMethod(string, chop)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "suffix", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareAttr(Gura_Symbol(eol));
	DeclareAttr(Gura_Symbol(icase));
	SetHelp(
	"Returns a string that removes a last character.\n"
	"If an attribute :eol is specified, only the end-of-line character shall be\n"
	"removed. In this case, if the end-of-line has a sequence of CR-LF, CR code\n"
	"shall be removed as well.");
}

Gura_ImplementMethod(string, chop)
{
	bool eolOnlyFlag = args.IsSet(Gura_Symbol(eol));
	const ValueList &valList = args.GetList(0);
	if (valList.empty()) {
		return Value(env, Chop(args.GetSelf().GetString(), eolOnlyFlag).c_str());
	}
	String rtn = args.GetSelf().GetStringSTL();
	if (eolOnlyFlag) rtn = Chop(rtn.c_str(), true);
	foreach_const (ValueList, pValue, valList) {
		const char *p1 = rtn.c_str();
		const char *p2 = EndsWith(p1, pValue->GetString(), args.IsSet(Gura_Symbol(icase)));
		if (p2 != NULL) return Value(env, String(p1, p2).c_str());
	}
	return Value(env, rtn.c_str());
}

// string#align(len:number, padding:string => " "):map:[center,left,right]
Gura_DeclareMethod(string, align)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number);
	DeclareArg(env, "padding", VTYPE_string, OCCUR_Once, FLAG_None, new Expr_String(" "));
	DeclareAttr(Gura_Symbol(center));
	DeclareAttr(Gura_Symbol(left));
	DeclareAttr(Gura_Symbol(right));
	SetHelp(
	"Returns a string aligned in left, right or center within a specified length.\n"
	"An attribute :center aligns the string in center, :left in left and :right in right\n"
	"An attribute :center is the default behaviour.\n"
	"It fills a padding area with a character specified by an argument padding,\n"
	"and a white space is used when itt is omitted");
}


Gura_ImplementMethod(string, align)
{
	size_t len = args.GetSizeT(0);
	const char *padding = args.GetString(1);
	if (Length(padding) != 1) {
		sig.SetError(ERR_ValueError, "padding must consist of a single character");
		return Value::Null;
	}
	String str;
	if (args.IsSet(Gura_Symbol(right))) {
		str = RJust(args.GetSelf().GetString(), len, padding);
	} else if (args.IsSet(Gura_Symbol(left))) {
		str = LJust(args.GetSelf().GetString(), len, padding);
	} else {
		str = Center(args.GetSelf().GetString(), len, padding);
	}
	return Value(env, str.c_str());
}

// string#left(len?:number):map
Gura_DeclareMethod(string, left)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	SetHelp("Returns a copy of the string in len characters from its left side");
}

Gura_ImplementMethod(string, left)
{
	if (!args.IsNumber(0)) return args.GetSelf();
	return Value(env, Left(args.GetSelf().GetString(), args.GetSizeT(0)).c_str());
}

// string#right(len?:number):map
Gura_DeclareMethod(string, right)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	SetHelp("Returns a copy of the string in len characters from its right side");
}

Gura_ImplementMethod(string, right)
{
	if (!args.IsNumber(0)) return args.GetSelf();
	return Value(env, Right(args.GetSelf().GetString(), args.GetSizeT(0)).c_str());
}

// string#mid(pos:number => 0, len?:number):map
Gura_DeclareMethod(string, mid)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "len", VTYPE_number, OCCUR_ZeroOrOnce);
	SetHelp(
	"Returns a copy of part of the string in len characters starting from pos.\n"
	"If an argument len is omitted, it returns a string from pos to its end.\n"
	"Number of an argument pos starts from zero.\n"
	"Example:\n"
	">>> \"Hello world\".mid(3, 2)\n"
	"lo\n"
	">>> \"Hello world\".mid(5)\n"
	"world");
}

Gura_ImplementMethod(string, mid)
{
	return Value(env, Middle(args.GetSelf().GetString(), args.GetInt(0),
						args.IsNumber(1)? args.GetInt(1) : -1).c_str());
}

// string#find(sub:string, pos?:number => 0):map:[icase,rev]
Gura_DeclareMethod(string, find)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sub",	VTYPE_string);
	DeclareArg(env, "pos",	VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_Symbol(rev));
	SetHelp(
	"Finds a sub string from the string and returns its position.\n"
	"Number of position starts from zero. You can specify a position to start\n"
	"finding by an argument pos. It returns nil if finding fails.\n"
	"With an attribute :icase, case of characters are ignored while finding.\n"
	"When an attribute :rev is specified, finding starts from tail of the string\n");
}

Gura_ImplementMethod(string, find)
{
	return FindString(env, sig, args.GetSelf().GetString(), args.GetString(0),
									args.GetInt(1), args.GetAttrs());
}

// string#startswith(prefix:string, pos:number => 0):map:[rest,icase]
Gura_DeclareMethod(string, startswith)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prefix",	VTYPE_string);
	DeclareArg(env, "pos",		VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareAttr(Gura_Symbol(rest));
	DeclareAttr(Gura_Symbol(icase));
	SetHelp(
	"Returns true if the string starts with prefix. If attribute :rest is specified,\n"
	"it returns the rest part if the string starts with prefix, or nil otherewise.\n"
	"You can specify a top position for the matching by an argument pos.\n"
	"With an attribute :icase, case of characters are ignored while finding.");
}

Gura_ImplementMethod(string, startswith)
{
	const char *rtn = StartsWith(args.GetSelf().GetString(), args.GetString(0),
					args.GetInt(1), args.IsSet(Gura_Symbol(icase)));
	if (args.IsSet(Gura_Symbol(rest))) {
		if (rtn == NULL) return Value::Null;
		return Value(env, rtn);
	}
	return rtn != NULL;
}

// string#endswith(suffix:string, endpos?:number):map:[rest,icase]
Gura_DeclareMethod(string, endswith)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "suffix",	VTYPE_string);
	DeclareArg(env, "endpos",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(rest));
	DeclareAttr(Gura_Symbol(icase));
	SetHelp(
	"Returns true if the string ends with suffix. If attribute :rest is specified,\n"
	"it returns the rest part if the string ends with suffix, or nil otherewise.\n"
	"You can specify a bottom position for the matching by an argument endpos.\n"
	"With an attribute :icase, case of characters are ignored while finding.");
}

Gura_ImplementMethod(string, endswith)
{
	const char *str = args.GetSelf().GetString();
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	const char *rtn = args.IsNumber(1)?
		EndsWith(str, args.GetString(0), args.GetInt(1), ignoreCaseFlag) :
		EndsWith(str, args.GetString(0), ignoreCaseFlag);
	if (args.IsSet(Gura_Symbol(rest))) {
		if (rtn == NULL) return Value::Null;
		return Value(env, str, rtn - str);
	}
	return rtn != NULL;
}

// string#replace(sub:string, replace:string, count?:number):map:[icase]
Gura_DeclareMethod(string, replace)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sub",		VTYPE_string);
	DeclareArg(env, "replace",	VTYPE_string);
	DeclareArg(env, "count",	VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(icase));
	SetHelp(
	"Returns a string that substitutes sub strings in the string with replace.\n"
	"An argument count limits the maximum number of substitution\n"
	"and there's no limit if it's omitted.\n"
	"With an attribute :icase,	case of characgters are ignored while finding.");
}

Gura_ImplementMethod(string, replace)
{
	String result = Replace(args.GetSelf().GetString(),
			args.GetString(0), args.GetString(1),
			args.IsNumber(2)? args.GetInt(2) : -1, args.GetAttrs());
	return Value(env, result.c_str());
}

// string#split(sep?:string, count?:number):[icase] {block?}
Gura_DeclareMethod(string, split)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetHelp(
	"Creates an iterator generating sub strings extracted from the original one\n"
	"separated by a specified string sep.\n"
	"With an attribute :icase, case of characgters are ignored while finding.\n"
	ITERATOR_HELP
	"Block parameter format: |sub:string, idx:number|");
}

Gura_ImplementMethod(string, split)
{
	int maxSplit = args.IsNumber(1)? args.GetInt(1) : -1;
	Iterator *pIterator = NULL;
	if (args.IsString(0) && *args.GetString(0) != '\0') {
		const char *sep = args.GetString(0);
		bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
		pIterator = new Object_string::IteratorSplit(
						args.GetSelf().GetStringSTL(), sep, maxSplit, ignoreCaseFlag);
	} else {
		pIterator = new Object_string::IteratorEach(args.GetSelf().GetStringSTL(),
							maxSplit, Object_string::IteratorEach::ATTR_None);
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// string#fold(n:number, nstep?:number) {block?}
Gura_DeclareMethod(string, fold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "nstep", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetHelp(
	"Creates an iterator that folds string in a specified length.\n"
	ITERATOR_HELP
	"Block parameter format: |sub:string, idx:number|");
}

Gura_ImplementMethod(string, fold)
{
	int cntPerFold = args.GetInt(0);
	int cntStep = args.IsNumber(1)? args.GetInt(1) : cntPerFold;
	Iterator *pIterator = new Object_string::IteratorFold(
						args.GetSelf().GetStringSTL(), cntPerFold, cntStep);
	return ReturnIterator(env, sig, args, pIterator);
}

// string#each():[utf8,utf32] {block?}
Gura_DeclareMethod(string, each)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareAttr(Gura_Symbol(utf8));
	DeclareAttr(Gura_Symbol(utf32));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetHelp(
	"Creates an iterator generating strings of each character in the original one.\n"
	ITERATOR_HELP
	"Block parameter format: |char:string, idx:number|");
}

Gura_ImplementMethod(string, each)
{
	Object_string::IteratorEach::Attr attr =
		args.IsSet(Gura_Symbol(utf8))? Object_string::IteratorEach::ATTR_UTF8 :
		args.IsSet(Gura_Symbol(utf32))? Object_string::IteratorEach::ATTR_UTF32 :
		Object_string::IteratorEach::ATTR_None;
	Iterator *pIterator = new Object_string::IteratorEach(
								args.GetSelf().GetStringSTL(), -1, attr);
	return ReturnIterator(env, sig, args, pIterator);
}

// string#eachline(nlines?:number):[chop] {block?}
// conrresponding to file#readlines()
Gura_DeclareMethod(string, eachline)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nlines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(chop));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetHelp(
	"Creates an iterator generating strings of each line in the original one.\n"
	"In default, end-of-line characters are involved in the result,\n"
	"and you can eliminates them by specifying :chop attribute.\n"
	ITERATOR_HELP
	"Block parameter format: |line:string, idx:number|");
}

Gura_ImplementMethod(string, eachline)
{
	int maxSplit = args.IsNumber(0)? args.GetInt(0) : -1;
	bool includeEOLFlag = !args.IsSet(Gura_Symbol(chop));
	return ReturnIterator(env, sig, args, new Object_string::IteratorLine(
					args.GetSelf().GetStringSTL(), maxSplit, includeEOLFlag));
}

// string#format(values*):map
Gura_DeclareMethod(string, format)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
	SetHelp(
	"Parses the content of the string object as a format specifier similar to\n"
	"C language's printf and returns a formatted string of argument values.");
}

Gura_ImplementMethod(string, format)
{
	return Value(env, Formatter::Format(sig,
					args.GetSelf().GetString(), args.GetList(0)).c_str());
}

// string#escapeuri()
Gura_DeclareMethod(string, escapeuri)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp(
	"Returns a string that converts characters into escape sequences.");
}

Gura_ImplementMethod(string, escapeuri)
{
	return Value(env, EscapeURI(args.GetSelf().GetString()).c_str());
}

// string#unescapeuri()
Gura_DeclareMethod(string, unescapeuri)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp(
	"Returns a string that reverts escaped sequences into characters.");
}

Gura_ImplementMethod(string, unescapeuri)
{
	return Value(env, UnescapeURI(args.GetSelf().GetString()).c_str());
}

// string#escapehtml()
Gura_DeclareMethod(string, escapehtml)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp(
	"Returns a string that converts characters into escape sequences.");
}

Gura_ImplementMethod(string, escapehtml)
{
	return Value(env, EscapeHtml(args.GetSelf().GetString(), false).c_str());
}

// string#unescapehtml()
Gura_DeclareMethod(string, unescapehtml)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetHelp(
	"Returns a string that reverts escaped sequences into characters.");
}

Gura_ImplementMethod(string, unescapehtml)
{
	return Value(env, UnescapeHtml(args.GetSelf().GetString()).c_str());
}

// string#print(stream?:stream:w):void
Gura_DeclareMethodPrimitive(string, print)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(string, print)
{
	if (args.IsInstanceOf(0, VTYPE_stream)) {
		args.GetStream(0).Print(sig, args.GetSelf().GetString());
	} else {
		Stream *pConsole = env.GetConsole(false);
		if (pConsole == NULL) return Value::Null;
		pConsole->Print(sig, args.GetSelf().GetString());
	}
	return Value::Null;
}

// string#println(stream?:stream:w):void
Gura_DeclareMethodPrimitive(string, println)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(string, println)
{
	if (args.IsInstanceOf(0, VTYPE_stream)) {
		args.GetStream(0).Println(sig, args.GetSelf().GetString());
	} else {
		Stream *pConsole = env.GetConsole(false);
		if (pConsole == NULL) return Value::Null;
		pConsole->Println(sig, args.GetSelf().GetString());
	}
	return Value::Null;
}

// string#binary()
Gura_DeclareMethodPrimitive(string, binary)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(string, binary)
{
	Value result;
	const char *str = args.GetSelf().GetString();
	result.InitAsBinary(env, str, ::strlen(str), true);
	return result;
}

// string#encode(codec:codec)
Gura_DeclareMethodPrimitive(string, encode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "codec", VTYPE_codec);
}

Gura_ImplementMethod(string, encode)
{
	Object_codec *pObjCodec = dynamic_cast<Object_codec *>(args.GetObject(0));
	Binary buff;
	if (!pObjCodec->GetEncoder()->Encode(sig, buff, args.GetSelf().GetString())) {
		return Value::Null;
	}
	Value result;
	result.InitAsBinary(env, buff, true);
	return result;
}

// string#reader() {block?}
Gura_DeclareMethod(string, reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, reader)
{
	return ReturnValue(env, sig, args, Value(new Object_stream(env,
				new Stream_StringReader(sig, args.GetSelf().GetStringSTL()))));
}

// string#parse() {block?}
Gura_DeclareMethod(string, parse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetHelp("Parse a string returns an expr object.");
}

Gura_ImplementMethod(string, parse)
{
	Expr *pExpr = Parser().ParseString(env, sig,
							"<parse function>", args.GetSelf().GetString());
	if (pExpr == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Value(env, pExpr));
}

// string#template(dst?:stream:w):[noindent,lasteol]
Gura_DeclareMethod(string, template_)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	SetHelp(
	"Evaluate script coded that is embedded in a string. If stream object dst is\n"
	"specified, the result shall be a destination of the result. Otherwise, it shall\n"
	"be returned as a string value.");
}

Gura_ImplementMethod(string, template_)
{
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	String strSrc = args.GetSelf().GetStringSTL();
	SimpleStream_StringRead streamSrc(strSrc.begin(), strSrc.end());
	if (args.IsStream(0)) {
		Stream &streamDst = args.GetStream(0);
		Parser().ParseTemplate(env, sig, streamSrc, streamDst,
								autoIndentFlag, appendLastEOLFlag);
		return Value::Null;
	} else {
		String strDst;
		SimpleStream_StringWrite streamDst(strDst);
		if (!Parser().ParseTemplate(env, sig, streamSrc, streamDst,
					autoIndentFlag, appendLastEOLFlag)) return Value::Null;
		return Value(env, strDst.c_str());
	}
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_string::Class_string(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_string)
{
	Gura_AssignMethod(string, len);
	Gura_AssignMethod(string, isempty);
	Gura_AssignMethod(string, capitalize);
	Gura_AssignMethod(string, lower);
	Gura_AssignMethod(string, upper);
	Gura_AssignMethod(string, zentohan);
	Gura_AssignMethod(string, strip);
	Gura_AssignMethod(string, chop);
	Gura_AssignMethod(string, align);
	Gura_AssignMethod(string, left);
	Gura_AssignMethod(string, right);
	Gura_AssignMethod(string, mid);
	Gura_AssignMethod(string, find);
	Gura_AssignMethod(string, startswith);
	Gura_AssignMethod(string, endswith);
	Gura_AssignMethod(string, replace);
	Gura_AssignMethod(string, split);
	Gura_AssignMethod(string, fold);
	Gura_AssignMethod(string, each);
	Gura_AssignMethod(string, eachline);
	Gura_AssignMethod(string, format);
	Gura_AssignMethod(string, escapeuri);
	Gura_AssignMethod(string, unescapeuri);
	Gura_AssignMethod(string, escapehtml);
	Gura_AssignMethod(string, unescapehtml);
	Gura_AssignMethod(string, print);
	Gura_AssignMethod(string, println);
	Gura_AssignMethod(string, binary);
	Gura_AssignMethod(string, encode);
	Gura_AssignMethod(string, reader);
	Gura_AssignMethod(string, parse);
	Gura_AssignMethodEx(string, template_, "template");
}

bool Class_string::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	value = Value(env, value.ToString(sig, false).c_str());
	return !sig.IsSignalled();
}

bool Class_string::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return stream.SerializeString(sig, value.GetString());
}

bool Class_string::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	String str;
	if (!stream.DeserializeString(sig, str)) return false;
	value = Value(env, str.c_str());
	return true;
}

Object *Class_string::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return new Object_string((pClass == NULL)? this : pClass);
}

void Class_string::OnModuleEntry(Environment &env, Signal sig)
{
}

//-----------------------------------------------------------------------------
// Stream_StringReader
//-----------------------------------------------------------------------------
Stream_StringReader::Stream_StringReader(Signal sig, const String &str) :
					Stream(sig, ATTR_Readable), _str(str), _offset(0)
{
}

Stream_StringReader::~Stream_StringReader()
{
}

const char *Stream_StringReader::GetName() const
{
	return "string";
}

const char *Stream_StringReader::GetIdentifier() const
{
	return NULL;
}

size_t Stream_StringReader::DoRead(Signal sig, void *buff, size_t len)
{
	if (_offset > _str.size()) {
		sig.SetError(ERR_IndexError, "out of range");
		return 0;
	}
	len = ChooseMin(_str.size() - _offset, len);
	::memcpy(buff, _str.data() + _offset, len);
	_offset += len;
	return len;
}

size_t Stream_StringReader::DoWrite(Signal sig, const void *buff, size_t len)
{
	return 0;
}

bool Stream_StringReader::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	if (seekMode == SeekSet) {
		_offset = static_cast<size_t>(offset);
	} else if (seekMode == SeekCur) {
		_offset += offset;
	}
	return true;
}

bool Stream_StringReader::DoFlush(Signal sig)
{
	return true;
}

bool Stream_StringReader::DoClose(Signal sig)
{
	return true;
}

size_t Stream_StringReader::DoGetSize()
{
	return _str.size();
}

}
