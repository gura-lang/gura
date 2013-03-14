//-----------------------------------------------------------------------------
// Gura re module
//-----------------------------------------------------------------------------
#include "Module_re.h"

Gura_BeginModule(re)

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
	return NULL;
}

bool IteratorSplit::DoNext(Environment &env, Signal sig, Value &value)
{
	const char *str = _str.c_str();
	if (_doneFlag) return false;
	if (_cnt == 0) {
		value = Value(env, str + _idx);
		_idx = _len;
		return true;
	} else if (_idx >= _len) {
		value = Value(env, "");
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
			value = Value(env, str + _idx);
			_doneFlag = true;
			return true;
		}
		value = Value(env, String(str + _idx, rtn - _idx).c_str());
		_idx = _pRegion->end[0];
	} else if (rtn == ONIG_MISMATCH) {
		value = Value(env, str + _idx);
		_idx = _len;
		_doneFlag = true;
	} else { // error
		SetError_OnigurumaError(sig, rtn);
		return false;
	}
	if (_cnt > 0) _cnt--;
	return true;
}

String IteratorSplit::ToString(Signal sig) const
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
	return NULL;
}

bool IteratorScan::DoNext(Environment &env, Signal sig, Value &value)
{
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
		Object_match *pObj = new Object_match(env);
		if (!pObj->SetMatchInfo(str, _pObjPattern->GetRegEx(), _pRegion, 0)) {
			SetError_FailInOniguruma(sig);
			delete pObj;
			return false;
		}
		value = Value(pObj);
		_idx = _pRegion->end[0];
	} else if (rtn == ONIG_MISMATCH) {
		value = Value(env, str + _idx);
		_idx = _idxEnd;
		return false;
	} else { // error
		SetError_OnigurumaError(sig, rtn);
		return false;
	}
	return true;
}

String IteratorScan::ToString(Signal sig) const
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
	return NULL;
}

bool IteratorGrep::DoNext(Environment &env, Signal sig, Value &value)
{
	const int pos = 0, posEnd = -1;
	while (_pIteratorSrc->Next(env, sig, value)) {
		String str = value.ToString(sig, false);
		if (sig.IsSignalled()) return false;
		value = DoMatch(env, sig,
					_pObjPattern->GetRegEx(), str.c_str(), pos, posEnd);
		if (sig.IsSignalled()) return false;
		if (value.IsValid()) return true;
	}
	return false;
}

String IteratorGrep::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:re.grep:";
	rtn += _pIteratorSrc->ToString(sig);
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
// Object_pattern
//-----------------------------------------------------------------------------
Object_pattern::~Object_pattern()
{
	if (_pRegEx != NULL) {
		::onig_free(_pRegEx);
	}
}

Object *Object_pattern::Clone() const
{
	return NULL;
}

String Object_pattern::ToString(Signal sig, bool exprFlag)
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
// re.pattern#match(str:string, pos:number => 0):map {block?}
Gura_DeclareMethod(pattern, match)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), 
	"Applies a pattern matching to a string and returns a match object.");
}

Gura_ImplementMethod(pattern, match)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	Value result = DoMatch(env, sig, pThis->GetRegEx(), args.GetString(0),
			args.GetInt(1), args.IsNumber(2)? args.GetInt(2) : -1);
	if (result.IsInvalid()) return result;
	return ReturnValue(env, sig, args, result);
}

// re.pattern#sub(replace, str:string, count?:number):map {block?}
Gura_DeclareMethod(pattern, sub)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(pattern, sub)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	int cnt = args.IsNumber(2)? static_cast<int>(args.GetNumber(2)) : -1;
	Value result;
	if (args.IsString(0)) {
		result = DoSubWithString(env, sig, pThis->GetRegEx(),
						args.GetString(0), args.GetString(1), cnt);
	} else if (args.IsFunction(0)) {
		result = DoSubWithFunc(env, sig, pThis->GetRegEx(),
						args.GetFunction(0), args.GetString(1), cnt);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
	}
	return ReturnValue(env, sig, args, result);
}

// re.pattern#split(str:string, count?:number):map {block?}
Gura_DeclareMethod(pattern, split)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(pattern, split)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	Object_pattern *pObjPattern = Object_pattern::Reference(pThis);
	String str = args.GetStringSTL(0);
	int cntMax = args.IsNumber(1)? static_cast<int>(args.GetNumber(1)) : -1;
	return ReturnIterator(env, sig, args,
							new IteratorSplit(pObjPattern, str, cntMax));
}

// re.pattern#scan(str:string, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareMethod(pattern, scan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(pattern, scan)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	Object_pattern *pObjPattern = Object_pattern::Reference(pThis);
	String str = args.GetStringSTL(0);
	int posEnd = args.IsNumber(2)? args.GetInt(2) : -1;
	return ReturnIterator(env, sig, args,
				new IteratorScan(pObjPattern, str, args.GetInt(1), posEnd));
}

//-----------------------------------------------------------------------------
// Class implementation for re.pattern
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(pattern)
{
	Gura_AssignMethod(pattern, match);
	Gura_AssignMethod(pattern, sub);
	Gura_AssignMethod(pattern, split);
	Gura_AssignMethod(pattern, scan);
}

Gura_ImplementCastFrom(pattern)
{
	if (value.IsString()) {
		Object_pattern *pObjPattern = new Object_pattern(env);
		if (!pObjPattern->SetPattern(sig, value.GetString(), SymbolSet::Null)) {
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
// Object_match
//-----------------------------------------------------------------------------
Object_match::~Object_match()
{
}

Object *Object_match::Clone() const
{
	return new Object_match(*this);
}

Value Object_match::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	const Group *pGroup = GetGroup(sig, valueIdx);
	if (pGroup == NULL) return Value::Null;
	return Value(env, GetGroupString(*pGroup).c_str());
}

bool Object_match::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(string));
	return true;
}

Value Object_match::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(env, _str);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_match::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<match:";
	foreach_const (GroupList, pGroup, _groupList) {
		if (pGroup != _groupList.begin()) rtn += ",";
		char str[80];
		::sprintf(str, "%d-%d", pGroup->GetPosBegin(), pGroup->GetPosEnd());
		rtn += str;
	}
	rtn += ">";
	return rtn;
}

bool Object_match::SetMatchInfo(const char *str,
				regex_t *pRegEx, const OnigRegion *pRegion, int posOffset)
{
	if (pRegion->num_regs == 0) return false;
	::onig_foreach_name(pRegEx, &ForeachNameCallbackStub, this);
	_str = str;
	for (int iGroup = 0; iGroup < pRegion->num_regs; iGroup++) {
		int idxBegin = pRegion->beg[iGroup];
		int idxEnd = pRegion->end[iGroup];
		if (idxBegin > idxEnd) return false;
		int posBegin = static_cast<int>(CalcCharPos(str, idxBegin)) + posOffset;
		int posEnd = static_cast<int>(CalcCharPos(str, idxEnd)) + posOffset;
		_groupList.push_back(Group(posBegin, posEnd));
	}
	return true;
}

const Object_match::Group *Object_match::GetGroup(Signal sig, const Value &index) const
{
	if (index.IsNumber()) {
		size_t indexNum = static_cast<size_t>(index.GetNumber());
		if (indexNum >= _groupList.size()) {
			sig.SetError(ERR_IndexError, "index is out of range");
			return NULL;
		}
		return &_groupList[indexNum];
	} else if (index.IsString()) {
		const char *name = index.GetString();
		GroupNameDict::const_iterator iter = _groupNameDict.find(name);
		if (iter == _groupNameDict.end()) {
			sig.SetError(ERR_IndexError,
				"regular expression doesn't have a group named '%s%", name);
			return NULL;
		}
		return &_groupList[iter->second];
	} else {
		sig.SetError(ERR_TypeError, "invalid argument type");
		return NULL;
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
// re.match#group(index):map
Gura_DeclareMethod(match, group)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_any);
}

Gura_ImplementMethod(match, group)
{
	Object_match *pThis = Object_match::GetThisObj(args);
	return pThis->IndexGet(env, sig, args.GetValue(0));
}

// re.match#groups()
Gura_DeclareMethod(match, groups)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(match, groups)
{
	Object_match *pThis = Object_match::GetThisObj(args);
	Value result;
	ValueList &valList = result.InitAsList(env);
	const Object_match::GroupList &groupList = pThis->GetGroupList();
	Object_match::GroupList::const_iterator pGroup = groupList.begin();
	if (pGroup != groupList.end()) pGroup++;
	for ( ; pGroup != groupList.end(); pGroup++) {
		valList.push_back(Value(env, pThis->GetGroupString(*pGroup).c_str()));
	}
	return result;
}

// re.match#start(index):map
Gura_DeclareMethod(match, start)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_any);
}

Gura_ImplementMethod(match, start)
{
	Object_match *pThis = Object_match::GetThisObj(args);
	const Object_match::Group *pGroup = pThis->GetGroup(sig, args.GetValue(0));
	if (pGroup == NULL) return Value::Null;
	return Value(pGroup->GetPosBegin());
}

// re.match#end(index):map
Gura_DeclareMethod(match, end)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_any);
}

Gura_ImplementMethod(match, end)
{
	Object_match *pThis = Object_match::GetThisObj(args);
	const Object_match::Group *pGroup = pThis->GetGroup(sig, args.GetValue(0));
	if (pGroup == NULL) return Value::Null;
	return Value(pGroup->GetPosEnd());
}

//-----------------------------------------------------------------------------
// Class implementation for re.match
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(match)
{
	Gura_AssignMethod(match, group);
	Gura_AssignMethod(match, groups);
	Gura_AssignMethod(match, start);
	Gura_AssignMethod(match, end);
}

//-----------------------------------------------------------------------------
// Gura interfaces for string
//-----------------------------------------------------------------------------
// string#match(pattern:pattern, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareMethod(string, match)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, match)
{
	Object_string *pThis = Object_string::GetThisObj(args);
	regex_t *pRegEx = dynamic_cast<Object_pattern *>(args.GetObject(0))->GetRegEx();
	Value result = DoMatch(env, sig, pRegEx, pThis->GetString(),
			args.GetInt(1), args.IsNumber(2)? args.GetInt(2) : -1);
	if (result.IsInvalid()) return result;
	return ReturnValue(env, sig, args, result);
}

// string#sub(pattern:pattern, replace, count?:number):map {block?}
Gura_DeclareMethod(string, sub)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, sub)
{
	Object_string *pThis = Object_string::GetThisObj(args);
	regex_t *pRegEx = dynamic_cast<Object_pattern *>(args.GetObject(0))->GetRegEx();
	int cnt = args.IsNumber(2)? static_cast<int>(args.GetNumber(2)) : -1;
	Value result;
	if (args.IsString(1)) {
		result = DoSubWithString(env, sig, pRegEx,
						args.GetString(1), pThis->GetString(), cnt);
	} else if (args.IsFunction(1)) {
		result = DoSubWithFunc(env, sig, pRegEx,
						args.GetFunction(1), pThis->GetString(), cnt);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
	}
	return ReturnValue(env, sig, args, result);
}

// string#splitreg(pattern:pattern, count?:number):map {block?}
Gura_DeclareMethod(string, splitreg)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, splitreg)
{
	Object_string *pThis = Object_string::GetThisObj(args);
	Object_pattern *pObjPattern =
			dynamic_cast<Object_pattern *>(Object::Reference(args.GetObject(0)));
	int cntMax = args.IsNumber(1)? static_cast<int>(args.GetNumber(1)) : -1;
	return ReturnIterator(env, sig, args,
				new IteratorSplit(pObjPattern, pThis->GetStringSTL(), cntMax));
}

// string#scan(pattern:pattern, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareMethod(string, scan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, scan)
{
	Object_string *pThis = Object_string::GetThisObj(args);
	Object_pattern *pObjPattern =
			dynamic_cast<Object_pattern *>(Object::Reference(args.GetObject(0)));
	int posEnd = args.IsNumber(2)? args.GetInt(2) : -1;
	return ReturnIterator(env, sig, args,
			new IteratorScan(pObjPattern, pThis->GetStringSTL(), args.GetInt(1), posEnd));
}

//-----------------------------------------------------------------------------
// Gura interfaces for list and iterator
//-----------------------------------------------------------------------------
// list#grep(pattern:pattern) {block?}
Gura_DeclareMethod(list, grep)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, grep)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_pattern *pObjPattern = Object_pattern::GetObject(args, 0);
	AutoPtr<Iterator> pIteratorSrc(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Iterator> pIterator(new IteratorGrep(pIteratorSrc.release(),
									Object_pattern::Reference(pObjPattern)));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// iterator#grep(pattern:pattern) {block?}
Gura_DeclareMethod(iterator, grep)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(iterator, grep)
{
	Object_iterator *pThis = Object_iterator::GetThisObj(args);
	Object_pattern *pObjPattern = Object_pattern::GetObject(args, 0);
	AutoPtr<Iterator> pIteratorSrc(pThis->GetIterator()->Clone());
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Iterator> pIterator(new IteratorGrep(pIteratorSrc.release(),
									Object_pattern::Reference(pObjPattern)));
	return ReturnIterator(env, sig, args, pIterator.release());
}

//-----------------------------------------------------------------------------
// Gura module functions: re
//-----------------------------------------------------------------------------
// re.pattern(pattern:string):map:[icase,multiline] {block?}
Gura_DeclareFunction(pattern)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string);
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_UserSymbol(multiline));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(pattern));
}

Gura_ImplementFunction(pattern)
{
	Object_pattern *pObjPattern = new Object_pattern(env);
	if (!pObjPattern->SetPattern(sig, args.GetString(0), args.GetAttrs())) {
		delete pObjPattern;
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObjPattern));
}

// re.match(pattern:pattern, str:string, pos:number => 0):map {block?}
Gura_DeclareFunction(match)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(match));
}

Gura_ImplementFunction(match)
{
	regex_t *pRegEx = dynamic_cast<Object_pattern *>(args.GetObject(0))->GetRegEx();
	Value result = DoMatch(env, sig, pRegEx, args.GetString(1),
			args.GetInt(2), args.IsNumber(3)? args.GetInt(3) : -1);
	if (result.IsInvalid()) return result;
	return ReturnValue(env, sig, args, result);
}

// re.sub(pattern:pattern, replace, str:string, count?:number):map {block?}
Gura_DeclareFunction(sub)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(sub)
{
	regex_t *pRegEx = dynamic_cast<Object_pattern *>(args.GetObject(0))->GetRegEx();
	int cnt = args.IsNumber(3)? static_cast<int>(args.GetNumber(3)) : -1;
	Value result;
	if (args.IsString(1)) {
		result = DoSubWithString(env, sig, pRegEx,
						args.GetString(1), args.GetString(2), cnt);
	} else if (args.IsFunction(1)) {
		result = DoSubWithFunc(env, sig, pRegEx,
						args.GetFunction(1), args.GetString(2), cnt);
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
	}
	return ReturnValue(env, sig, args, result);
}

// re.split(pattern:pattern, str:string, count?:number):map {block?}
Gura_DeclareFunction(split)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(split)
{
	Object_pattern *pObjPattern =
			dynamic_cast<Object_pattern *>(Object::Reference(args.GetObject(0)));
	String str = args.GetStringSTL(1);
	int cntMax = args.IsNumber(2)? static_cast<int>(args.GetNumber(2)) : -1;
	return ReturnIterator(env, sig, args,
							new IteratorSplit(pObjPattern, str, cntMax));
}

// re.scan(pattern:pattern, str:string, pos:number => 0, endpos?:number):map {block?}
Gura_DeclareFunction(scan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_pattern);
	DeclareArg(env, "str", VTYPE_string);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "endpos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(scan)
{
	Object_pattern *pObjPattern =
			dynamic_cast<Object_pattern *>(Object::Reference(args.GetObject(0)));
	String str = args.GetStringSTL(1);
	int posEnd = args.IsNumber(3)? args.GetInt(3) : -1;
	return ReturnIterator(env, sig, args,
				new IteratorScan(pObjPattern, str, args.GetInt(2), posEnd));
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
	Gura_RealizeUserClass(pattern, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(pattern);
	Gura_AssignFunction(match);
	Gura_AssignFunction(sub);
	Gura_AssignFunction(split);
	Gura_AssignFunction(scan);
	// method assignment
	Gura_AssignMethodTo(VTYPE_string, string, match);
	Gura_AssignMethodTo(VTYPE_string, string, sub);
	Gura_AssignMethodTo(VTYPE_string, string, splitreg);
	Gura_AssignMethodTo(VTYPE_string, string, scan);
	Gura_AssignMethodTo(VTYPE_list, list, grep);
	Gura_AssignMethodTo(VTYPE_iterator, iterator, grep);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
regex_t *CreateRegEx(Signal sig, const char *pattern, const SymbolSet &attrs)
{
	// ::onig_end() call may be necessary when module is destroyed
	regex_t *pRegEx = NULL;
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
		return NULL;
	}
	return pRegEx;
}

Value DoMatch(Environment &env, Signal sig, regex_t *pRegEx,
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
		Object_match *pObj = new Object_match(env);
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

Value DoSubWithString(Environment &env, Signal sig, regex_t *pRegEx,
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
	return Value(env, result.c_str());
error_done:
	::onig_region_free(pRegion, 1); // 1:free self, 0:free contents only
	return Value::Null;
}

Value DoSubWithFunc(Environment &env, Signal sig, regex_t *pRegEx,
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
			Object_match *pObj = new Object_match(env);
			if (!pObj->SetMatchInfo(str, pRegEx, pRegion, 0)) {
				SetError_FailInOniguruma(sig);
				delete pObj;
				goto error_done;
			}
			Value value(pObj);
			ValueList valListArg(value);
			Args args(valListArg);
			Value resultFunc = pFunc->Eval(env, sig, args);
			if (sig.IsSignalled()) goto error_done;
			result += String(str + idx, rtn - idx);
			result += resultFunc.ToString(sig, false);
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
	return Value(env, result.c_str());
error_done:
	::onig_region_free(pRegion, 1); // 1:free self, 0:free contents only
	return Value::Null;
}

void SetError_OnigurumaError(Signal sig, int errCode)
{
	char errMsg[ONIG_MAX_ERROR_MESSAGE_LEN];
	::onig_error_code_to_str(reinterpret_cast<OnigUChar *>(errMsg), errCode);
	sig.SetError(ERR_ValueError, "oniguruma: %s", errMsg);
}

void SetError_FailInOniguruma(Signal sig)
{
	sig.SetError(ERR_SystemError,
				"something's wrong in the process of Oniguruma library");
}

Gura_EndModule(re, re)

Gura_RegisterModule(re)
