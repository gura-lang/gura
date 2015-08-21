//-----------------------------------------------------------------------------
// Gura module: re
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(re)

//-----------------------------------------------------------------------------
// IteratorSplit
//-----------------------------------------------------------------------------
IteratorSplit::IteratorSplit(Object_pattern *pObjPattern, const String &str, int cntMax) :
		Iterator(false), _pObjPattern(pObjPattern), _str(str),
		_cnt(cntMax), _idx(0),
		_len(static_cast<int>(str.size())), _doneFlag(false),
		_pRegion(::onig_region_new())
{
}

IteratorSplit::~IteratorSplit()
{
	::onig_region_free(_pRegion, 1); // 1:free self, 0:free contents only
}

Iterator *IteratorSplit::GetSource()
{
	return nullptr;
}

bool IteratorSplit::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	const char *str = _str.c_str();
	if (_doneFlag) return false;
	if (_cnt == 0) {
		value = Value(str + _idx);
		_idx = _len;
		return true;
	} else if (_idx >= _len) {
		value = Value("");
		_doneFlag = true;
		return true;
	}
	int rtn = ::onig_search(_pObjPattern->GetRegEx(),
					reinterpret_cast<const OnigUChar *>(str),
					reinterpret_cast<const OnigUChar *>(str + _len),
					reinterpret_cast<const OnigUChar *>(str + _idx),
					reinterpret_cast<const OnigUChar *>(str + _len),
					_pRegion, ONIG_OPTION_NONE);
	if (rtn >= 0) {
		if (rtn < _idx || _pRegion->num_regs == 0 || _pRegion->end[0] < _idx) {
			SetError_FailInOniguruma(sig);
			return false;
		}
		if (_pRegion->end[0] == _idx) {
			value = Value(str + _idx);
			_doneFlag = true;
			return true;
		}
		value = Value(String(str + _idx, rtn - _idx));
		_idx = _pRegion->end[0];
	} else if (rtn == ONIG_MISMATCH) {
		value = Value(str + _idx);
		_idx = _len;
		_doneFlag = true;
	} else { // error
		SetError_OnigurumaError(sig, rtn);
		return false;
	}
	if (_cnt > 0) _cnt--;
	return true;
}

String IteratorSplit::ToString() const
{
	return String("<iterator:re.split>");
}

void IteratorSplit::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// IteratorScan
//-----------------------------------------------------------------------------
IteratorScan::IteratorScan(Object_pattern *pObjPattern, const String &str, int pos, int posEnd) :
		Iterator(false), _pObjPattern(pObjPattern), _str(str),
		_len(static_cast<int>(str.size())), _pRegion(::onig_region_new())
{
	_idx = static_cast<int>(CalcCharOffset(str.c_str(), pos));
	_idxEnd = (posEnd < 0)? _len : static_cast<int>(CalcCharOffset(str.c_str(), posEnd));
}

IteratorScan::~IteratorScan()
{
	::onig_region_free(_pRegion, 1); // 1:free self, 0:free contents only
}

Iterator *IteratorScan::GetSource()
{
	return nullptr;
}

bool IteratorScan::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_idx >= _idxEnd) return false;
	const char *str = _str.c_str();
	int rtn = ::onig_search(_pObjPattern->GetRegEx(),
					reinterpret_cast<const OnigUChar *>(str),
					reinterpret_cast<const OnigUChar *>(str + _len),
					reinterpret_cast<const OnigUChar *>(str + _idx),
					reinterpret_cast<const OnigUChar *>(str + _idxEnd),
					_pRegion, ONIG_OPTION_NONE);
	if (rtn >= 0) {
		if (rtn < _idx || _pRegion->num_regs == 0 || _pRegion->end[0] < _idx) {
			SetError_FailInOniguruma(sig);
			return false;
		}
		if (_pRegion->end[0] == _idx) {
			return false;
		}
		Object_match *pObj = new Object_match();
		if (!pObj->SetMatchInfo(str, _pObjPattern->GetRegEx(), _pRegion, 0)) {
			SetError_FailInOniguruma(sig);
			delete pObj;
			return false;
		}
		value = Value(pObj);
		_idx = _pRegion->end[0];
	} else if (rtn == ONIG_MISMATCH) {
		value = Value(str + _idx);
		_idx = _idxEnd;
		return false;
	} else { // error
		SetError_OnigurumaError(sig, rtn);
		return false;
	}
	return true;
}

String IteratorScan::ToString() const
{
	return String("<iterator:re.scan>");
}

void IteratorScan::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// IteratorGrep
//-----------------------------------------------------------------------------
IteratorGrep::IteratorGrep(Iterator *pIteratorSrc, Object_pattern *pObjPattern) :
		Iterator(pIteratorSrc->IsInfinite()),
		_pIteratorSrc(pIteratorSrc), _pObjPattern(pObjPattern)
{
}

Iterator *IteratorGrep::GetSource()
{
	return _pIteratorSrc.get();
}

bool IteratorGrep::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	const int pos = 0, posEnd = -1;
	while (_pIteratorSrc->Next(env, value)) {
		String str = value.ToString(false);
		if (sig.IsSignalled()) return false;
		value = DoMatch(env, sig,
					_pObjPattern->GetRegEx(), str.c_str(), pos, posEnd);
		if (sig.IsSignalled()) return false;
		if (value.IsValid()) return true;
	}
	return false;
}

String IteratorGrep::ToString() const
{
	String rtn;
	rtn += "<iterator:re.grep:";
	rtn += _pIteratorSrc->ToString();
	rtn += ">";
	return rtn;
}

void IteratorGrep::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIteratorSrc->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// IteratorGroup
//-----------------------------------------------------------------------------
IteratorGroup::IteratorGroup(Object_match *pObjMatch) :
						Iterator(false), _pObjMatch(pObjMatch), _iGroup(1)
{
}

Iterator *IteratorGroup::GetSource()
{
	return nullptr;
}

bool IteratorGroup::DoNext(Environment &env, Value &value)
{
	const GroupList &groupList = _pObjMatch->GetGroupList();
	if (_iGroup < groupList.size()) {
		value = Value(new Object_group(groupList[_iGroup]));
		_iGroup++;
		return true;
	}
	return false;
}

String IteratorGroup::ToString() const
{
	String rtn;
	rtn += "<iterator:re.group:";
	rtn += ">";
	return rtn;
}

void IteratorGroup::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_match
//-----------------------------------------------------------------------------
Object_match::~Object_match()
{
}

Object *Object_match::Clone() const
{
	return new Object_match(*this);
}

Value Object_match::IndexGet(Environment &env, const Value &valueIdx)
{
	Signal &sig = GetSignal();
	const Group *pGroup = GetGroup(sig, valueIdx);
	if (pGroup == nullptr) return Value::Nil;
	return Value(pGroup->GetString());
}

bool Object_match::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(source));
	symbols.insert(Gura_Symbol(string));
	symbols.insert(Gura_Symbol(begin));
	symbols.insert(Gura_Symbol(end));
	return true;
}

Value Object_match::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	const Group &group = _groupList.front();
	if (pSymbol->IsIdentical(Gura_Symbol(source))) {
		return Value(GetString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(group.GetString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(begin))) {
		return Value(group.GetPosBegin());
	} else if (pSymbol->IsIdentical(Gura_Symbol(end))) {
		return Value(group.GetPosEnd());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_match::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<match:";
	const Group &group = _groupList.front();
	char str[80];
	::sprintf(str, "%d-%d", group.GetPosBegin(), group.GetPosEnd());
	rtn += str;
	rtn += ">";
	return rtn;
}

bool Object_match::SetMatchInfo(const char *str,
				regex_t *pRegEx, const OnigRegion *pRegion, int posOffset)
{
	if (pRegion->num_regs == 0) return false;
	::onig_foreach_name(pRegEx, &ForeachNameCallbackStub, this);
	_pStrShrd.reset(new StringShared(str));
	for (int iGroup = 0; iGroup < pRegion->num_regs; iGroup++) {
		int idxBegin = pRegion->beg[iGroup];
		int idxEnd = pRegion->end[iGroup];
		if (idxBegin > idxEnd) return false;
		int posBegin = static_cast<int>(CalcCharPos(str, idxBegin)) + posOffset;
		int posEnd = static_cast<int>(CalcCharPos(str, idxEnd)) + posOffset;
		_groupList.push_back(Group(_pStrShrd->Reference(), posBegin, posEnd));
	}
	return true;
}

const Group *Object_match::GetGroup(Signal &sig, const Value &index) const
{
	if (index.Is_number()) {
		size_t indexNum = static_cast<size_t>(index.GetNumber());
		if (indexNum >= _groupList.size()) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return nullptr;
		}
		return &_groupList[indexNum];
	} else if (index.Is_string()) {
		const char *name = index.GetString();
		GroupNameDict::const_iterator iter = _groupNameDict.find(name);
		if (iter == _groupNameDict.end()) {
			sig.SetError(ERR_IndexError,
				"regular expression doesn't have a group named '%s%", name);
			return nullptr;
		}
		return &_groupList[iter->second];
	} else {
		sig.SetError(ERR_TypeError, "invalid argument type");
		return nullptr;
	}
}

int Object_match::ForeachNameCallback(const String &name, int nGroups,
											int *idxGroupTbl, regex_t *pRegEx)
{
	if (nGroups > 0) _groupNameDict[name] = idxGroupTbl[0];
	return 0;
}

int Object_match::ForeachNameCallbackStub(
			const UChar *nameRaw, const UChar *nameRawEnd,
			int nGroups, int *idxGroupTbl, regex_t *pRegEx, void *pArg)
{
	String name(reinterpret_cast<const char *>(nameRaw), nameRawEnd - nameRaw);
	return reinterpret_cast<Object_match *>(pArg)->
					ForeachNameCallback(name, nGroups, idxGroupTbl, pRegEx);
}

//-----------------------------------------------------------------------------
// Gura interfaces for re.match
//-----------------------------------------------------------------------------
// re.match(pattern:pattern, str:string, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareFunction(match)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(match));
	LinkHelp(env.LookupClass(VTYPE_string), Symbol::Add("match"));
}

Gura_ImplementFunction(match)
{
	Signal &sig = env.GetSignal();
	regex_t *pRegEx = dynamic_cast<Object_pattern *>(args.GetObject(0))->GetRegEx();
	Value result = DoMatch(env, sig, pRegEx, args.GetString(1),
			args.GetInt(2), args.Is_number(3)? args.GetInt(3) : -1);
	if (result.IsInvalid()) return result;
	return ReturnValue(env, args, result);
}

// re.match#group(index):map
Gura_DeclareMethod(match, group)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a `re.group` instance that is positioned by the specified index.\n"
		"\n"
		"The argument `index` is a value of `number` or `string`.\n"
		"\n"
		"The value of `number` indicates the group index number that starts from zero.\n"
		"The group indexed by zero is special and represents the whole region of the match.\n"
		"The groups indexed by numbers greater than zero correspond to matching patterns of grouping.\n"
		"Below is an example:\n"
		"\n"
		"    str = '12:34:56'\n"
		"    m = str.match(r'(\\d\\d):(\\d\\d):(\\d\\d)')\n"
		"    m.group(0).string // returns the whole region of matching: 12:34:56\n"
		"    m.group(1).string // returns the 1st group: 12\n"
		"    m.group(2).string // returns the 2nd group: 34\n"
		"    m.group(3).string // returns the 3rd group: 56\n"
		"\n"
		"The value of `string` is used to point out a named capturing group\n"
		"that is described in a regular expression as \"`(?<name>group)`\".\n"
		"\n"
		"Below is an example:\n"
		"\n"
		"    str = '12:34:56'\n"
		"    m = str.match(r'(?<hour>\\d\\d):(?<min>\\d\\d):(?<sec>\\d\\d)')\n"
		"    m.group('hour').string // returns the group named 'hour': 12\n"
		"    m.group('min').string  // returns the group named 'min': 34\n"
		"    m.group('sec').string  // returns the group named 'sec': 56\n");
}

Gura_ImplementMethod(match, group)
{
	Signal &sig = env.GetSignal();
	Object_match *pThis = Object_match::GetThisObj(args);
	const Group *pGroup = pThis->GetGroup(sig, args.GetValue(0));
	if (pGroup == nullptr) return Value::Nil;
	return Value(new Object_group(*pGroup));
}

// re.match#groups() {block?}
Gura_DeclareMethod(match, groups)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that returns `re.group` instances.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(match, groups)
{
	Object_match *pThis = Object_match::GetThisObj(args);
	AutoPtr<Iterator> pIterator(new IteratorGroup(pThis->Reference()));
	return ReturnIterator(env, args, pIterator.release());
}

//-----------------------------------------------------------------------------
// Class implementation for re.match
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(match)
{
	Gura_AssignFunction(match);
	Gura_AssignMethod(match, group);
	Gura_AssignMethod(match, groups);
}

//-----------------------------------------------------------------------------
// Object_group
//-----------------------------------------------------------------------------
Object_group::~Object_group()
{
}

Object *Object_group::Clone() const
{
	return new Object_group(*this);
}

bool Object_group::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(string));
	symbols.insert(Gura_Symbol(begin));
	symbols.insert(Gura_Symbol(end));
	return true;
}

Value Object_group::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(_group.GetString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(begin))) {
		return Value(_group.GetPosBegin());
	} else if (pSymbol->IsIdentical(Gura_Symbol(end))) {
		return Value(_group.GetPosEnd());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_group::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<group:";
	char str[80];
	::sprintf(str, "%d-%d", _group.GetPosBegin(), _group.GetPosEnd());
	rtn += str;
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Class implementation for re.group
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(group)
{
	Gura_AssignValue(group, Reference());
}

//-----------------------------------------------------------------------------
// Object_pattern
//-----------------------------------------------------------------------------
Object_pattern::~Object_pattern()
{
	if (_pRegEx != nullptr) {
		::onig_free(_pRegEx);
	}
}

Object *Object_pattern::Clone() const
{
	return nullptr;
}

String Object_pattern::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<re.pattern:'";
	rtn += _pattern;
	rtn += "'>";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for re.pattern
//-----------------------------------------------------------------------------
// re.pattern(pattern:string):map:[icase,multiline] {block?}
Gura_DeclareFunction(pattern)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string);
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_UserSymbol(multiline));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(pattern));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `re.pattern` instance from the given pattern string.\n"
		"\n"
		"Following attributes would customize some traits of the pattern:\n"
		"\n"
		"- `:icase` .. Ignores character cases.\n"
		"- `:multiline` .. Matches \"`.`\" with a line break.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("pat", "re.pattern"));
}

Gura_ImplementFunction(pattern)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pObjPattern = new Object_pattern();
	if (!pObjPattern->SetPattern(sig, args.GetString(0), args.GetAttrs())) {
		delete pObjPattern;
		return Value::Nil;
	}
	return ReturnValue(env, args, Value(pObjPattern));
}

// re.pattern#match(str:string, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareMethod(pattern, match)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_string), Symbol::Add("match"));
}

Gura_ImplementMethod(pattern, match)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	Value result = DoMatch(env, sig, pThis->GetRegEx(), args.GetString(0),
			args.GetInt(1), args.Is_number(2)? args.GetInt(2) : -1);
	if (result.IsInvalid()) return result;
	return ReturnValue(env, args, result);
}

// re.pattern#sub(replace, str:string, count?:number):map {block?}
Gura_DeclareMethod(pattern, sub)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_string), Symbol::Add("sub"));
}

Gura_ImplementMethod(pattern, sub)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	int cnt = args.Is_number(2)? static_cast<int>(args.GetNumber(2)) : -1;
	String result;
	if (args.Is_string(0)) {
		result = DoSubWithString(env, sig, pThis->GetRegEx(),
						args.GetString(0), args.GetString(1), cnt);
	} else if (args.Is_function(0)) {
		result = DoSubWithFunc(env, sig, pThis->GetRegEx(),
						args.GetFunction(0), args.GetString(1), cnt);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Nil;
	}
	if (sig.IsSignalled()) return Value::Nil;
	if (!args.IsBlockSpecified()) return Value(result);
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(result));
	valListArg.push_back(Value(result != args.GetStringSTL(1)));
	return ReturnValues(env, args, valListArg);
}

// re.pattern#split(str:string, count?:number):map {block?}
Gura_DeclareMethod(pattern, split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_string), Symbol::Add("splitreg"));
}

Gura_ImplementMethod(pattern, split)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	Object_pattern *pObjPattern = Object_pattern::Reference(pThis);
	String str = args.GetStringSTL(0);
	int cntMax = args.Is_number(1)? static_cast<int>(args.GetNumber(1)) : -1;
	AutoPtr<Iterator> pIterator(new IteratorSplit(pObjPattern, str, cntMax));
	return ReturnIterator(env, args, pIterator.release());
}

// re.pattern#scan(str:string, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareMethod(pattern, scan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_string), Symbol::Add("scan"));
}

Gura_ImplementMethod(pattern, scan)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	Object_pattern *pObjPattern = Object_pattern::Reference(pThis);
	String str = args.GetStringSTL(0);
	int posEnd = args.Is_number(2)? args.GetInt(2) : -1;
	AutoPtr<Iterator> pIterator(new IteratorScan(pObjPattern, str, args.GetInt(1), posEnd));
	return ReturnIterator(env, args, pIterator.release());
}

//-----------------------------------------------------------------------------
// Class implementation for re.pattern
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(pattern)
{
	Gura_AssignFunction(pattern);
	Gura_AssignMethod(pattern, match);
	Gura_AssignMethod(pattern, sub);
	Gura_AssignMethod(pattern, split);
	Gura_AssignMethod(pattern, scan);
}

Gura_ImplementCastFrom(pattern)
{
	Signal &sig = GetSignal();
	if (value.Is_string()) {
		Object_pattern *pObjPattern = new Object_pattern();
		if (!pObjPattern->SetPattern(sig, value.GetString(), SymbolSet::Empty)) {
			delete pObjPattern;
			return false;
		}
		value = Value(pObjPattern);
		return true;
	}
	return false;
}

Gura_ImplementCastTo(pattern)
{
	return false;
}

//-----------------------------------------------------------------------------
// Gura interfaces for string
//-----------------------------------------------------------------------------
// string#match(pattern:pattern, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareMethod(string, match)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Applies a pattern matching to the given string and returns a `re.match` instance\n"
		"if the matching successes. If not, it would return `nil`.\n"
		"\n"
		"The argument `pos` specifies the starting position for matching process.\n"
		"If omitted, it starts from the beginning of the string.\n"
		"\n"
		"The argument `endpos` specifies the ending position for matching process.\n"
		"If omitted, it would be processed until the end of the string.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("m", "re.match"));
}

Gura_ImplementMethod(string, match)
{
	Signal &sig = env.GetSignal();
	const char *strThis = args.GetThis().GetString();
	regex_t *pRegEx = dynamic_cast<Object_pattern *>(args.GetObject(0))->GetRegEx();
	Value result = DoMatch(env, sig, pRegEx, strThis,
			args.GetInt(1), args.Is_number(2)? args.GetInt(2) : -1);
	if (result.IsInvalid()) return result;
	return ReturnValue(env, args, result);
}

// string#sub(pattern:pattern, replace, count?:number):map {block?}
Gura_DeclareMethod(string, sub)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Substitutes strings that matches `pattern` with the specified replacer.\n"
		"\n"
		"The argument `replace` takes a `string` or `function`.\n"
		"\n"
		"If a `string` is specified, it would be used as a substituting string,\n"
		"in which you can use macros `\\0`, `\\1`, `\\2` .. to refer to matched groups.\n"
		"\n"
		"If a `function` is specified, it would be called with an argument `m:re.match`\n"
		"and is expected to return a string for subsitution.\n"
		"\n"
		"The argument `count` specifies the maximum number of substitutions.\n"
		"If omitted, no limit would be applied.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("str", "string"));
}

Gura_ImplementMethod(string, sub)
{
	Signal &sig = env.GetSignal();
	const char *strThis = args.GetThis().GetString();
	regex_t *pRegEx = dynamic_cast<Object_pattern *>(args.GetObject(0))->GetRegEx();
	int cnt = args.Is_number(2)? static_cast<int>(args.GetNumber(2)) : -1;
	String result;
	if (args.Is_string(1)) {
		result = DoSubWithString(env, sig, pRegEx,
						args.GetString(1), strThis, cnt);
	} else if (args.Is_function(1)) {
		result = DoSubWithFunc(env, sig, pRegEx,
						args.GetFunction(1), strThis, cnt);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Nil;
	}
	if (sig.IsSignalled()) return Value::Nil;
	if (!args.IsBlockSpecified()) return Value(result);
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(result));
	valListArg.push_back(Value(result != strThis));
	return ReturnValues(env, args, valListArg);
}

// string#splitreg(pattern:pattern, count?:number):map {block?}
Gura_DeclareMethod(string, splitreg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that splits the source string with the specified pattern.\n"
		"\n"
		"The argument `count` specifies the maximum number for splitting.\n"
		"If omitted, no limit would be applied.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(string, splitreg)
{
	const char *strThis = args.GetThis().GetString();
	Object_pattern *pObjPattern =
			dynamic_cast<Object_pattern *>(Object::Reference(args.GetObject(0)));
	int cntMax = args.Is_number(1)? static_cast<int>(args.GetNumber(1)) : -1;
	AutoPtr<Iterator> pIterator(new IteratorSplit(pObjPattern, strThis, cntMax));
	return ReturnIterator(env, args, pIterator.release());
}

// string#scan(pattern:pattern, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareMethod(string, scan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that returns strings that match the specified pattern.\n"
		"\n"
		"The argument `pos` specifies the starting position for matching process.\n"
		"If omitted, it starts from the beginning of the string.\n"
		"\n"
		"The argument `endpos` specifies the ending position for matching process.\n"
		"If omitted, it would be processed until the end of the string.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(string, scan)
{
	const char *strThis = args.GetThis().GetString();
	Object_pattern *pObjPattern =
			dynamic_cast<Object_pattern *>(Object::Reference(args.GetObject(0)));
	int posEnd = args.Is_number(2)? args.GetInt(2) : -1;
	AutoPtr<Iterator> pIterator(new IteratorScan(pObjPattern, strThis, args.GetInt(1), posEnd));
	return ReturnIterator(env, args, pIterator.release());
}

//-----------------------------------------------------------------------------
// Gura interfaces for list and iterator
//-----------------------------------------------------------------------------
// list#grep(pattern:pattern) {block?}
Gura_DeclareMethod(list, grep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(list, grep)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_pattern *pObjPattern = Object_pattern::GetObject(args, 0);
	AutoPtr<Iterator> pIteratorSrc(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(new IteratorGrep(pIteratorSrc.release(),
									Object_pattern::Reference(pObjPattern)));
	return ReturnIterator(env, args, pIterator.release());
}

// iterator#grep(pattern:pattern) {block?}
Gura_DeclareMethod(iterator, grep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(iterator, grep)
{
	Signal &sig = env.GetSignal();
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Object_pattern *pObjPattern = Object_pattern::GetObject(args, 0);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(new IteratorGrep(pIteratorSrc.release(),
									Object_pattern::Reference(pObjPattern)));
	return ReturnIterator(env, args, pIterator.release());
}

//-----------------------------------------------------------------------------
// Gura module functions: re
//-----------------------------------------------------------------------------
// re.sub(pattern:pattern, replace, str:string, count?:number):map {block?}
Gura_DeclareFunction(sub)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_string), Symbol::Add("sub"));
}

Gura_ImplementFunction(sub)
{
	Signal &sig = env.GetSignal();
	regex_t *pRegEx = dynamic_cast<Object_pattern *>(args.GetObject(0))->GetRegEx();
	int cnt = args.Is_number(3)? static_cast<int>(args.GetNumber(3)) : -1;
	String result;
	if (args.Is_string(1)) {
		result = DoSubWithString(env, sig, pRegEx,
						args.GetString(1), args.GetString(2), cnt);
	} else if (args.Is_function(1)) {
		result = DoSubWithFunc(env, sig, pRegEx,
						args.GetFunction(1), args.GetString(2), cnt);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Nil;
	}
	if (sig.IsSignalled()) return Value::Nil;
	if (!args.IsBlockSpecified()) return Value(result);
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(result));
	valListArg.push_back(Value(result != args.GetStringSTL(2)));
	return ReturnValues(env, args, valListArg);
}

// re.split(pattern:pattern, str:string, count?:number):map {block?}
Gura_DeclareFunction(split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_string), Symbol::Add("splitreg"));
}

Gura_ImplementFunction(split)
{
	Object_pattern *pObjPattern =
			dynamic_cast<Object_pattern *>(Object::Reference(args.GetObject(0)));
	String str = args.GetStringSTL(1);
	int cntMax = args.Is_number(2)? static_cast<int>(args.GetNumber(2)) : -1;
	AutoPtr<Iterator> pIterator(new IteratorSplit(pObjPattern, str, cntMax));
	return ReturnIterator(env, args, pIterator.release());
}

// re.scan(pattern:pattern, str:string, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareFunction(scan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_string), Symbol::Add("scan"));
}

Gura_ImplementFunction(scan)
{
	Object_pattern *pObjPattern =
			dynamic_cast<Object_pattern *>(Object::Reference(args.GetObject(0)));
	String str = args.GetStringSTL(1);
	int posEnd = args.Is_number(3)? args.GetInt(3) : -1;
	AutoPtr<Iterator> pIterator(new IteratorScan(pObjPattern, str, args.GetInt(2), posEnd));
	return ReturnIterator(env, args, pIterator.release());
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(re);
	Gura_RealizeUserSymbol(string);
	Gura_RealizeUserSymbol(multiline);
	// class realization
	Gura_RealizeUserClass(match, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(group, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(pattern, env.LookupClass(VTYPE_object));
	// method assignment to string
	Gura_AssignMethodTo(VTYPE_string, string, match);
	Gura_AssignMethodTo(VTYPE_string, string, sub);
	Gura_AssignMethodTo(VTYPE_string, string, splitreg);
	Gura_AssignMethodTo(VTYPE_string, string, scan);
	// class preparation
	Gura_PrepareUserClass(match);
	Gura_PrepareUserClass(group);
	Gura_PrepareUserClass(pattern);
	// function assignment
	Gura_AssignFunction(sub);
	Gura_AssignFunction(split);
	Gura_AssignFunction(scan);
	// method assignment to list
	Gura_AssignMethodTo(VTYPE_list, list, grep);
	// method assignment to iterator
	Gura_AssignMethodTo(VTYPE_iterator, iterator, grep);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
regex_t *CreateRegEx(Signal &sig, const char *pattern, const SymbolSet &attrs)
{
	// ::onig_end() call may be necessary when module is destroyed
	regex_t *pRegEx = nullptr;
	OnigOptionType option = ONIG_OPTION_CAPTURE_GROUP;
	OnigEncoding enc = ONIG_ENCODING_UTF8;
	OnigErrorInfo errInfo;
	size_t len = ::strlen(pattern);
	if (attrs.IsSet(Gura_Symbol(icase))) {
		option |= ONIG_OPTION_IGNORECASE;
	}
	if (attrs.IsSet(Gura_UserSymbol(multiline))) {
		option |= ONIG_OPTION_MULTILINE;
	}
	int rtn = ::onig_new(&pRegEx,
				reinterpret_cast<const OnigUChar *>(pattern),
				reinterpret_cast<const OnigUChar *>(pattern + len),
				option, enc, ONIG_SYNTAX_DEFAULT, &errInfo);
	if (rtn != ONIG_NORMAL) {
		SetError_OnigurumaError(sig, rtn);
		return nullptr;
	}
	return pRegEx;
}

Value DoMatch(Environment &env, Signal &sig, regex_t *pRegEx,
										const char *str, int pos, int posEnd)
{
	Value result;
	size_t len = ::strlen(str);
	const char *strStart = Forward(str, pos);
	const char *strEnd = (posEnd < 0)? str + len : Forward(str, posEnd);
	OnigRegion *pRegion = ::onig_region_new();
	int rtn = ::onig_search(pRegEx,
				reinterpret_cast<const OnigUChar *>(strStart),
				reinterpret_cast<const OnigUChar *>(str + len),
				reinterpret_cast<const OnigUChar *>(strStart),
				reinterpret_cast<const OnigUChar *>(strEnd),
				pRegion, ONIG_OPTION_NONE);
	if (rtn >= 0) {
		Object_match *pObj = new Object_match();
		if (pObj->SetMatchInfo(str, pRegEx, pRegion, pos)) {
			result.InitAsObject(pObj);
		} else {
			SetError_FailInOniguruma(sig);
			delete pObj;
		}
	} else if (rtn == ONIG_MISMATCH) {
		// nothing to do
	} else { // error
		SetError_OnigurumaError(sig, rtn);
	}
	::onig_region_free(pRegion, 1); // 1:free self, 0:free contents only
	return result;
}

String DoSubWithString(Environment &env, Signal &sig, regex_t *pRegEx,
							const char *replace, const char *str, int cnt)
{
	enum Stat { STAT_Start, STAT_Escape };
	size_t len = ::strlen(str);
	String result;
	OnigRegion *pRegion = ::onig_region_new();
	int idx = 0;
	for ( ; cnt != 0; cnt--) {
		int rtn = ::onig_search(pRegEx,
						reinterpret_cast<const OnigUChar *>(str),
						reinterpret_cast<const OnigUChar *>(str + len),
						reinterpret_cast<const OnigUChar *>(str + idx),
						reinterpret_cast<const OnigUChar *>(str + len),
						pRegion, ONIG_OPTION_NONE);
		if (rtn >= 0) {
			if (rtn < idx || pRegion->num_regs == 0 || pRegion->end[0] <= idx) {
				SetError_FailInOniguruma(sig);
				goto error_done;
			}
			result += String(str + idx, rtn - idx);
			Stat stat = STAT_Start;
			for (const char *p = replace; *p != '\0'; p++) {
				char ch = *p;
				if (stat == STAT_Start) {
					if (ch == '\\') {
						stat = STAT_Escape;
					} else {
						result.push_back(*p);
					}
				} else if (stat == STAT_Escape) {
					if (IsDigit(ch)) {
						int iGroup = ch - '0';
						if (iGroup < pRegion->num_regs) {
							int idxBegin = pRegion->beg[iGroup];
							int idxEnd = pRegion->end[iGroup];
							result += String(str + idxBegin, idxEnd - idxBegin);
						}
						stat = STAT_Start;
					} else {
						result.push_back(GetEscaped(ch));
						stat = STAT_Start;
					}
				}
			}
			idx = pRegion->end[0];
		} else if (rtn == ONIG_MISMATCH) {
			break;
		} else { // error
			SetError_OnigurumaError(sig, rtn);
			goto error_done;
		}
	}
	::onig_region_free(pRegion, 1); // 1:free self, 0:free contents only
	result += String(str + idx);
	return result;
error_done:
	::onig_region_free(pRegion, 1); // 1:free self, 0:free contents only
	return "";
}

String DoSubWithFunc(Environment &env, Signal &sig, regex_t *pRegEx,
						const Function *pFunc, const char *str, int cnt)
{
	enum Stat { STAT_Start, STAT_Escape };
	size_t len = ::strlen(str);
	String result;
	OnigRegion *pRegion = ::onig_region_new();
	int idx = 0;
	for ( ; cnt != 0; cnt--) {
		int rtn = ::onig_search(pRegEx,
					reinterpret_cast<const OnigUChar *>(str),
					reinterpret_cast<const OnigUChar *>(str + len),
					reinterpret_cast<const OnigUChar *>(str + idx),
					reinterpret_cast<const OnigUChar *>(str + len),
					pRegion, ONIG_OPTION_NONE);
		if (rtn >= 0) {
			Object_match *pObj = new Object_match();
			if (!pObj->SetMatchInfo(str, pRegEx, pRegion, 0)) {
				SetError_FailInOniguruma(sig);
				delete pObj;
				goto error_done;
			}
			//Value value(pObj);
			//ValueList valListArg(value);
			AutoPtr<Args> pArgs(new Args());
			pArgs->AddValue(Value(pObj));
			Value resultFunc = pFunc->Eval(env, *pArgs);
			if (sig.IsSignalled()) goto error_done;
			result += String(str + idx, rtn - idx);
			result += resultFunc.ToString(false);
			if (sig.IsSignalled()) goto error_done;
			idx = pRegion->end[0];
		} else if (rtn == ONIG_MISMATCH) {
			break;
		} else { // error
			SetError_OnigurumaError(sig, rtn);
			goto error_done;
		}
	}
	::onig_region_free(pRegion, 1); // 1:free self, 0:free contents only
	result += String(str + idx);
	return result;
error_done:
	::onig_region_free(pRegion, 1); // 1:free self, 0:free contents only
	return "";
}

void SetError_OnigurumaError(Signal &sig, int errCode)
{
	char errMsg[ONIG_MAX_ERROR_MESSAGE_LEN];
	::onig_error_code_to_str(reinterpret_cast<OnigUChar *>(errMsg), errCode);
	sig.SetError(ERR_ValueError, "oniguruma: %s", errMsg);
}

void SetError_FailInOniguruma(Signal &sig)
{
	sig.SetError(ERR_SystemError,
				"something's wrong in the process of Oniguruma library");
}

Gura_EndModuleBody(re, re)

Gura_RegisterModule(re)
