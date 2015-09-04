//=============================================================================
// Gura class: list
//=============================================================================
#include "stdafx.h"
#include "combination.hpp"

//-----------------------------------------------------------------------------
// extra
//-----------------------------------------------------------------------------
namespace std {

// extracted from combination.hpp which is supposed to be used with boost
template <class BidirectionalIterator>
  bool next_partial_permutation(BidirectionalIterator first,
                                BidirectionalIterator middle,
                                BidirectionalIterator last)
{
  reverse (middle, last);
  return next_permutation(first, last);
}

}

namespace Gura {

//-----------------------------------------------------------------------------
// Object_list
//-----------------------------------------------------------------------------
Object *Object_list::Clone() const
{
	return new Object_list(*this);
}

Value Object_list::IndexGet(Environment &env, const Value &valueIdx)
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for list");
		return Value::Nil;
	}
	int idx = valueIdx.GetInt();
	if (idx < 0) idx += _valList.size();
	if (idx < 0 || idx >= static_cast<int>(GetList().size())) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Nil;
	}
	return GetList()[idx];
}

void Object_list::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for list");
		return;
	}
	int idx = valueIdx.GetInt();
	if (idx < 0) idx += _valList.size();
	if (idx < 0 || idx >= static_cast<int>(GetList().size())) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return;
	}
	GetList()[idx] = value;
}

Iterator *Object_list::CreateIterator(Signal &sig)
{
	return new IteratorEach(Object_list::Reference(this));
}

String Object_list::ToString(bool exprFlag)
{
	bool limitLenFlag = true;
	String str;
	const ValueList &valList = GetList();
	str += "[";
	foreach_const (ValueList, pValue, valList) {
		if (pValue != valList.begin()) str += ", ";
		if (limitLenFlag && str.size() > 4096) {
			str += "...";
			break;
		}
		str += pValue->ToString();
	}
	str += "]";
	return str;
}

Object_list *Object_list::SortRank(Signal &sig, const Value &valDirective,
					const ValueList *pValListKey, bool rankFlag, bool stableFlag)
{
	typedef std::map<const Value *, const Value *> ValuePtrMap;
	Environment &env = *this;
	enum { MODE_Ascend, MODE_Descend, MODE_Custom } mode = MODE_Ascend;
	const Function *pFunc = nullptr;
	const ValueList &valList = GetList();
	if (valDirective.IsInvalid()) {
		// nothing to do
	} else if (valDirective.Is_symbol()) {
		const Symbol *pSymbol = valDirective.GetSymbol();
		if (pSymbol->IsIdentical(Gura_Symbol(ascend))) {
			mode = MODE_Ascend;
		} else if (pSymbol->IsIdentical(Gura_Symbol(descend))) {
			mode = MODE_Descend;
		} else {
			sig.SetError(ERR_ValueError,
				"invalid symbol '%s'", pSymbol->GetName());
			return nullptr;
		}
	} else if (valDirective.Is_function()) {
		mode = MODE_Custom;
		pFunc = valDirective.GetFunction();
		if (pFunc->GetDeclOwner().size() != 2) {
			sig.SetError(ERR_TypeError,
				"only a binary function can be specified");
			return nullptr;
		}
	} else {
		sig.SetError(ERR_TypeError, "invalid argument");
		return nullptr;
	}
	ValuePtrList valPtrList;
	ValuePtrMap valuePtrMap;
	if (rankFlag || pValListKey == nullptr) {
		foreach_const (ValueList, pValue, valList) {
			valPtrList.push_back(&(*pValue));
		}
	} else {
		ValueList::const_iterator pValueKey = pValListKey->begin();
		ValueList::const_iterator pValue = valList.begin();
		for ( ; pValueKey != pValListKey->end() && pValue != valList.end();
														pValueKey++, pValue++) {
			valPtrList.push_back(&(*pValueKey));
			valuePtrMap[&(*pValueKey)] = &(*pValue);
		}
	}
	if (stableFlag) {
		if (mode == MODE_Ascend) {
			std::stable_sort(valPtrList.begin(), valPtrList.end(), Comparator_Ascend(env));
		} else if (mode == MODE_Descend) {
			std::stable_sort(valPtrList.begin(), valPtrList.end(), Comparator_Descend(env));
		} else { // mode == MODE_Custom
			std::stable_sort(valPtrList.begin(), valPtrList.end(),
											Comparator_Custom(env, pFunc));
		}
	} else {
		if (mode == MODE_Ascend) {
			std::sort(valPtrList.begin(), valPtrList.end(), Comparator_Ascend(env));
		} else if (mode == MODE_Descend) {
			std::sort(valPtrList.begin(), valPtrList.end(), Comparator_Descend(env));
		} else { // mode == MODE_Custom
			std::sort(valPtrList.begin(), valPtrList.end(),
											Comparator_Custom(env, pFunc));
		}
	}
	Value result;
	ValueList &valListResult = result.InitAsList(env);
	if (rankFlag) {
		foreach_const (ValueList, pValue, valList) {
			ValuePtrList::iterator ppValue = valPtrList.begin();
			for ( ; ppValue != valPtrList.end(); ppValue++) {
				int rtn = Value::Compare(env, *pValue, **ppValue);
				if (sig.IsSignalled()) return nullptr;
				if (rtn == 0) break;
			}
			if (ppValue == valPtrList.end()) {
				sig.SetError(ERR_SystemError, "fatal error in rank() operation");
				return nullptr;
			} else {
				int idx = static_cast<int>(ppValue - valPtrList.begin());
				valListResult.push_back(Value(idx));
			}
		}
	} else if (pValListKey == nullptr) {
		foreach_const (ValuePtrList, ppValue, valPtrList) {
			valListResult.push_back(**ppValue);
		}
	} else {
		foreach_const (ValuePtrList, ppValueKey, valPtrList) {
			const Value *pValueKey = *ppValueKey;
			valListResult.push_back(*valuePtrMap[pValueKey]);
		}
	}
	return Object_list::Reference(Object_list::GetObject(result));
}

bool Object_list::ValueVisitor_Index::Visit(const Value &value)
{
	GURA_ASSUME(_env, value.Is_number());
	Signal &sig = _env.GetSignal();
	int idx = value.GetInt();
	if (idx < 0) idx += _valList.size();
	if (std::find(_indexList.begin(), _indexList.end(), idx) != _indexList.end()) {
		// nothing to do
	} else if (idx < static_cast<int>(_valList.size())) {
		_indexList.push_back(idx);
	} else {
		sig.SetError(ERR_IndexError, "index is out of range");
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Object_list::IteratorEach
//-----------------------------------------------------------------------------
Object_list::IteratorEach::~IteratorEach()
{
}

Iterator *Object_list::IteratorEach::GetSource()
{
	return nullptr;
}

bool Object_list::IteratorEach::DoNext(Environment &env, Value &value)
{
	if (_pValue == _pValueEnd) return false;
	value = *_pValue;
	_pValue++;
	return true;
}

String Object_list::IteratorEach::ToString() const
{
	return String("list#each");
}

void Object_list::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_list::IteratorReverse
//-----------------------------------------------------------------------------
Object_list::IteratorReverse::~IteratorReverse()
{
}

Iterator *Object_list::IteratorReverse::GetSource()
{
	return nullptr;
}

bool Object_list::IteratorReverse::DoNext(Environment &env, Value &value)
{
	ValueList &valList = _pObj->GetList();
	if (_pValue == valList.rend()) return false;
	value = *_pValue;
	_pValue++;
	return true;
}

String Object_list::IteratorReverse::ToString() const
{
	return String("list#reverse");
}

void Object_list::IteratorReverse::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_list::IteratorCycle
//-----------------------------------------------------------------------------
Object_list::IteratorCycle::~IteratorCycle()
{
}

Iterator *Object_list::IteratorCycle::GetSource()
{
	return nullptr;
}

bool Object_list::IteratorCycle::DoNext(Environment &env, Value &value)
{
	ValueList &valList = _pObj->GetList();
	if (_pValue == valList.end() || _cnt == 0) return false;
	value = *_pValue;
	_pValue++;
	if (_cnt > 0) _cnt--;
	if (_pValue == valList.end()) _pValue = valList.begin();
	return true;
}

String Object_list::IteratorCycle::ToString() const
{
	return String("list#cycle");
}

void Object_list::IteratorCycle::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_list::IteratorPingpong
//-----------------------------------------------------------------------------
Object_list::IteratorPingpong::~IteratorPingpong()
{
}

Iterator *Object_list::IteratorPingpong::GetSource()
{
	return nullptr;
}

bool Object_list::IteratorPingpong::DoNext(Environment &env, Value &value)
{
	ValueList &valList = _pObj->GetList();
	if (_forwardFlag) {
		if (_pValueFwd == valList.end() || _cnt == 0) return false;
		value = *_pValueFwd;
		_pValueFwd++;
		if (_cnt > 0) _cnt--;
		if (_pValueFwd == valList.end() ||
				(!_stickyFlagBtm && _pValueFwd + 1 == valList.end())) {
			_forwardFlag = false;
			_pValueBwd = valList.rbegin();
		}
	} else {
		if (_pValueBwd == valList.rend() || _cnt == 0) return false;
		value = *_pValueBwd;
		_pValueBwd++;
		if (_cnt > 0) _cnt--;
		if (_pValueBwd == valList.rend() ||
				(!_stickyFlagTop && _pValueBwd + 1 == valList.rend())) {
			_forwardFlag = true;
			_pValueFwd = valList.begin();
		}
	}
	return true;
}

String Object_list::IteratorPingpong::ToString() const
{
	return String("list#pingpong");
}

void Object_list::IteratorPingpong::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_list::IteratorFold
//-----------------------------------------------------------------------------
Object_list::IteratorFold::IteratorFold(Object_list *pObj, size_t cntPerFold,
										size_t cntStep, bool listItemFlag, bool neatFlag) :
		Iterator(false), _pObj(pObj), _offset(0),
		_cntPerFold(cntPerFold), _cntStep(cntStep),
		_listItemFlag(listItemFlag), _neatFlag(neatFlag), _doneFlag(false)
{
}

Object_list::IteratorFold::~IteratorFold()
{
}

Iterator *Object_list::IteratorFold::GetSource()
{
	return nullptr;
}

bool Object_list::IteratorFold::DoNext(Environment &env, Value &value)
{
	if (_doneFlag) return false;
	ValueList &valList = _pObj->GetList();
	if (_offset >= valList.size()) return false;
	if (_neatFlag && (_offset + _cntPerFold) > valList.size()) return false;
	AutoPtr<Iterator> pIterator(new IteratorEach(
					Object_list::Reference(_pObj.get()), _offset, _cntPerFold));
	if (_listItemFlag) {
		bool excludeNilFlag = false;
		value = pIterator->ToList(env, true, excludeNilFlag);
	} else {
		value = Value(new Object_iterator(env, pIterator.release()));
	}
	if (_offset + _cntPerFold >= valList.size()) _doneFlag = true;
	_offset += _cntStep;
	return true;
}

String Object_list::IteratorFold::ToString() const
{
	return String("list#fold");
}

void Object_list::IteratorFold::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_list::IteratorPermutation
//-----------------------------------------------------------------------------
Object_list::IteratorPermutation::IteratorPermutation(Object_list *pObj, int cnt) :
							Iterator(false), _pObj(pObj), _cnt(cnt), _validFlag(true)
{
	ValueList &valList = _pObj->GetList();
	_indexList.reserve(valList.size());
	for (size_t index = 0; index < valList.size(); index++) {
		_indexList.push_back(index);
	}
}

Object_list::IteratorPermutation::~IteratorPermutation()
{
}

Iterator *Object_list::IteratorPermutation::GetSource()
{
	return nullptr;
}

bool Object_list::IteratorPermutation::DoNext(Environment &env, Value &value)
{
	if (!_validFlag) return false;
	ValueList &valList = value.InitAsList(*_pObj);
	ValueList &valListSrc = _pObj->GetList();
	if (_cnt < 0) {
		foreach (IndexList, pIndex, _indexList) {
			valList.push_back(valListSrc[*pIndex]);
		}
		_validFlag = std::next_permutation(_indexList.begin(), _indexList.end());
	} else {
		IndexList::iterator pIndex = _indexList.begin();
		for (int i = 0; i < _cnt; pIndex++, i++) {
			valList.push_back(valListSrc[*pIndex]);
		}
		_validFlag = std::next_partial_permutation(
				_indexList.begin(), _indexList.begin() + _cnt, _indexList.end());
	}
	return true;
}

String Object_list::IteratorPermutation::ToString() const
{
	return String("list#permutation");
}

void Object_list::IteratorPermutation::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_list::IteratorCombination
//-----------------------------------------------------------------------------
Object_list::IteratorCombination::IteratorCombination(Object_list *pObj, int cnt) :
							Iterator(false), _pObj(pObj), _cnt(cnt), _validFlag(true)
{
	ValueList &valList = _pObj->GetList();
	_indexList.reserve(valList.size());
	for (size_t index = 0; index < valList.size(); index++) {
		_indexList.push_back(index);
	}
}

Object_list::IteratorCombination::~IteratorCombination()
{
}

Iterator *Object_list::IteratorCombination::GetSource()
{
	return nullptr;
}

bool Object_list::IteratorCombination::DoNext(Environment &env, Value &value)
{
	if (!_validFlag) return false;
	ValueList &valList = value.InitAsList(*_pObj);
	ValueList &valListSrc = _pObj->GetList();
	IndexList::iterator pIndex = _indexList.begin();
	for (int i = 0; i < _cnt; pIndex++, i++) {
		valList.push_back(valListSrc[*pIndex]);
	}
	// the following function is implemented in combination.hpp
	_validFlag = boost::next_combination(
			_indexList.begin(), _indexList.begin() + _cnt, _indexList.end());
	return true;
}

String Object_list::IteratorCombination::ToString() const
{
	return String("list#combination");
}

void Object_list::IteratorCombination::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_list::Comparator_Custom
//-----------------------------------------------------------------------------
bool Object_list::Comparator_Custom::
				operator()(const Value *pValue1, const Value *pValue2) const
{
	Signal &sig = _env.GetSignal();
	if (sig.IsSignalled()) return false;
	AutoPtr<Argument> pArgSub(new Argument(_pFunc));
	if (!pArgSub->AddValue(_env, *pValue1, *pValue2)) return false;
	Value value = _pFunc->Eval(_env, *pArgSub);
	return value.GetNumber() < 0;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// list(value+)
// xlist(value+)
Gura_DeclareFunctionBegin(list_xlist)
	bool _acceptInvalidFlag;
Gura_DeclareFunctionEnd(list_xlist)
{
	_acceptInvalidFlag = (::strcmp(GetName(), "list") == 0);
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_OnceOrMore);
	SetClassToConstruct(env.LookupClass(VTYPE_list));
	String text = _acceptInvalidFlag?
		"Creates a new list from given values in its argument list.\n" :
		"Creates a new list from given values except for `nil` in its argument list.\n";
	text +=
		"If the value is a list or an iteartor, its elements are added to the created list.\n";
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, text.c_str());
}

Gura_ImplementFunction(list_xlist)
{
	Signal &sig = env.GetSignal();
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ValueList, pValueArg, arg.GetList(0)) {
		if (pValueArg->Is_list() || pValueArg->Is_iterator()) {
			AutoPtr<Iterator> pIterator(pValueArg->CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Nil;
			if (pIterator->IsInfinite()) {
				Iterator::SetError_InfiniteNotAllowed(sig);
				return Value::Nil;
			}
			Value value;
			while (pIterator->Next(env, value)) {
				if (_acceptInvalidFlag || value.IsValid()) {
					valList.push_back(value);
				}
			}
			if (sig.IsSignalled()) return Value::Nil;
		} else if (_acceptInvalidFlag || pValueArg->IsValid()) {
			valList.push_back(*pValueArg);
		} else {
			// nothing to do
		}
	}
	return result;
}

// set(iter+:iterator):[and,xor,or]
// xset(iter+:iterator):[and,xor,or]
Gura_DeclareFunctionBegin(set_xset)
	bool _acceptInvalidFlag;
Gura_DeclareFunctionEnd(set_xset)
{
	_acceptInvalidFlag = (::strcmp(GetName(), "set") == 0);
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "iter", VTYPE_iterator, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(or));
	DeclareAttr(Gura_Symbol(and));
	DeclareAttr(Gura_Symbol(xor));
	String text = _acceptInvalidFlag?
		"Creates a new list that contains unique values from given iterators in its argument list.\n" :
		"Creates a new list that contains unique values except for `nil` from given iterators in its argument list.\n";
	text += 
		"\n"
		"In default, all the elements in each iterators are added to the created list.\n"
		"Specifying the following attributes would apply a filtering condition.\n"
		"\n"
		"- `:and` .. Elements that exist in all the iterators are added.\n"
		"- `:or` .. All the elements are added. This is the default behavior.\n"
		"- `:xor` .. Elements that exist in only one iterator are added.\n";
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		text.c_str());
}

Gura_ImplementFunction(set_xset)
{
	Signal &sig = env.GetSignal();
	Value result;
	ValueList &valList = result.InitAsList(env);
	if (arg.IsSet(Gura_Symbol(and))) {			// AND combination
		ValueList valList1, valList2;
		ValueList::const_reverse_iterator pValueArg = arg.GetList(0).rbegin();
		Value value;
		for (Iterator *pIterator = pValueArg->GetIterator();
											pIterator->Next(env, value); ) {
			if ((_acceptInvalidFlag || value.IsValid()) &&
										!valList1.DoesContain(env, value)) {
				valList1.push_back(value);
			}
			if (sig.IsSignalled()) return Value::Nil;
		}
		if (sig.IsSignalled()) return Value::Nil;
		pValueArg++;
		ValueList *pValListAnd = &valList1;
		ValueList *pValListWork = &valList2;
		for ( ; pValueArg != arg.GetList(0).rend() &&
										!pValListAnd->empty(); pValueArg++) {
			Value value;
			for (Iterator *pIterator = pValueArg->GetIterator();
											pIterator->Next(env, value); ) {
				if (pValListAnd->DoesContain(env, value) &&
								!pValListWork->DoesContain(env, value)) {
					pValListWork->push_back(value);
				}
				if (sig.IsSignalled()) return Value::Nil;
			}
			ValueList *pValListTmp = pValListAnd;
			pValListAnd = pValListWork, pValListWork = pValListTmp;
			pValListWork->clear();
		}
		foreach_const (ValueList, pValue, *pValListAnd) {
			valList.push_back(*pValue);
		}
	} else if (arg.IsSet(Gura_Symbol(xor))) {	// XOR combination
		ValueList valList1, valList2;
		ValueList *pValListAnd = &valList1;
		ValueList valListOr;
		ValueList::const_iterator pValueArg = arg.GetList(0).begin();
		Value value;
		for (Iterator *pIterator = pValueArg->GetIterator();
										pIterator->Next(env, value); ) {
			if (!valList1.DoesContain(env, value)) valList1.push_back(value);
			if (sig.IsSignalled()) return Value::Nil;
			if ((_acceptInvalidFlag || value.IsValid()) &&
										!valListOr.DoesContain(env, value)) {
				valListOr.push_back(value);
			}
			if (sig.IsSignalled()) return Value::Nil;
		}
		if (sig.IsSignalled()) return Value::Nil;
		pValueArg++;
		ValueList *pValListWork = &valList2;
		for ( ; pValueArg != arg.GetList(0).end() &&
										!pValListAnd->empty(); pValueArg++) {
			Value value;
			for (Iterator *pIterator = pValueArg->GetIterator();
										pIterator->Next(env, value); ) {
				if (pValListAnd->DoesContain(env, value)) pValListWork->push_back(value);
				if (sig.IsSignalled()) return Value::Nil;
				if ((_acceptInvalidFlag || value.IsValid()) &&
										!valListOr.DoesContain(env, value)) {
					valListOr.push_back(value);
				}
				if (sig.IsSignalled()) return Value::Nil;
			}
			if (sig.IsSignalled()) return Value::Nil;
			ValueList *pValListTmp = pValListAnd;
			pValListAnd = pValListWork, pValListWork = pValListTmp;
			pValListWork->clear();
		}
		foreach_const (ValueList, pValue, valListOr) {
			if (!pValListAnd->DoesContain(env, *pValue)) {
				valList.push_back(*pValue);
			}
			if (sig.IsSignalled()) return Value::Nil;
		}
	} else {										// OR combination
		foreach_const (ValueList, pValue, arg.GetList(0)) {
			Value value;
			for (Iterator *pIterator = pValue->GetIterator();
												pIterator->Next(env, value); ) {
				if ((_acceptInvalidFlag || value.IsValid()) &&
											!valList.DoesContain(env, value)) {
					valList.push_back(value);
				}
				if (sig.IsSignalled()) return Value::Nil;
			}
			if (sig.IsSignalled()) return Value::Nil;
		}
	}
	return result;
}

// @(func?:Function) {block?}
Gura_DeclareFunction(ListInit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "func", VTYPE_function, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a list from the content of `block`.\n"
		"If `block` is not specified, an empty list will be created.\n"
		"\n"
		"Below is an example to create a list containing four values.\n"
		"\n"
		"    x = @{1, 2, 3, 4}\n"
		"\n"
		"When the argument `func` is specified, it will be evaluated with each element of the block,\n"
		"and then the result will be stored in the list.\n");
}

Gura_ImplementFunction(ListInit)
{
	Signal &sig = env.GetSignal();
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	if (sig.IsSignalled()) return Value::Nil;
	const Value &valueFunc = arg.GetValue(0);
	Value result;
	if (pExprBlock == nullptr) {
		result.InitAsList(env);
	} else if (valueFunc.Is_function()) {
		const Function *pFunc = valueFunc.GetFunction();
		size_t cntArgs = pFunc->GetDeclOwner().size();
		if (cntArgs == 0) {
			sig.SetError(ERR_TypeError, "function '%s' needs no argument", pFunc->GetName());
			return Value::Nil;
		}
		AutoPtr<Environment> pEnvLister(new Environment(&env, ENVTYPE_lister));
		ValueList &valList = result.InitAsList(env);
		foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
			Value value = (*ppExpr)->Exec(*pEnvLister);
			if (sig.IsSignalled()) {
				sig.AddExprCause(*ppExpr);
				return Value::Nil;
			}
			if (!value.Is_list()) {
				sig.SetError(ERR_SyntaxError, "invalid format in list initializer");
				return Value::Nil;
			}
			AutoPtr<Argument> pArgSub(new Argument(pFunc));
			if (!pArgSub->AddValue(env, value.GetList())) return Value::Nil;
			Value valueElem = pFunc->Eval(env, *pArgSub);
			if (sig.IsSignalled()) return Value::Nil;
			valList.push_back(valueElem);
		}
	} else {
		AutoPtr<Environment> pEnvLister(new Environment(&env, ENVTYPE_lister));
		result = pExprBlock->Exec(*pEnvLister, nullptr);
	}
	return result;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// list.zip(values+) {block?}
Gura_DeclareClassMethod(list, zip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Creates an iterator generating lists that bind given argument values.\n"
		"When the value is a list or an iterator, each item in it would be zipped.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementClassMethod(list, zip)
{
	Signal &sig = env.GetSignal();
	IteratorOwner iterOwner;
	bool listFlag = false;
	bool iteratorFlag = false;
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		if (pValue->Is_list()) {
			listFlag = true;
		} else if (pValue->Is_iterator()) {
			iteratorFlag = true;
			break;
		}
	}
	if (!listFlag && !iteratorFlag) {
		Value result;
		ValueList &valList = result.InitAsList(env);
		foreach_const (ValueList, pValue, arg.GetList(0)) {
			valList.push_back(*pValue);
		}
		return ReturnValue(env, arg, result);
	}
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		Iterator *pIteratorArg = nullptr;
		if (pValue->Is_list() || pValue->Is_iterator()) {
			pIteratorArg = pValue->CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Nil;
		} else {
			pIteratorArg = new Iterator_Constant(*pValue);
		}
		iterOwner.push_back(pIteratorArg);
	}
	AutoPtr<Iterator> pIterator(new Iterator_Zipv(iterOwner));
	if (iteratorFlag) return ReturnIterator(env, arg, pIterator.release());
	Value result = pIterator->ToList(env, true, false);
	return ReturnValue(env, arg, result);
}

//-----------------------------------------------------------------------------
// Implementation of instance methods specific to list
//-----------------------------------------------------------------------------
// list#add(elem+):reduce
Gura_DeclareMethod(list, add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "elem", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Add specified items to the list.");
}

Gura_ImplementMethod(list, add)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		valList.push_back(*pValue);
	}
	return arg.GetValueThis();
}

// list#append(elem+):reduce
Gura_DeclareMethod(list, append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "elem", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Adds specified items to the list. If the item is a list or an iterator,\n"
		"each element in such an item is added to the list.");
}

Gura_ImplementMethod(list, append)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		if (pValue->Is_list() || pValue->Is_iterator()) {
			AutoPtr<Iterator> pIterator(pValue->CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Nil;
			if (pIterator->IsInfinite()) {
				Iterator::SetError_InfiniteNotAllowed(sig);
				return Value::Nil;
			}
			Value value;
			while (pIterator->Next(env, value)) {
				valList.push_back(value);
			}
			if (sig.IsSignalled()) return Value::Nil;
		} else {
			valList.push_back(*pValue);
		}
	}
	return arg.GetValueThis();
}

// list#clear():reduce
Gura_DeclareMethod(list, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Clear the content of the list.");
}

Gura_ImplementMethod(list, clear)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	pThis->GetList().clear();
	return arg.GetValueThis();
}

// list#combination(n:number) {block?}
Gura_DeclareMethod(list, combination)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Creates an iterator that generates lists that contain elements picked up\n"
		"from the original list in a combination manner.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(list, combination)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	int cnt = arg.GetInt(0);
	if (pThis->GetList().size() < static_cast<size_t>(cnt)) {
		sig.SetError(ERR_ValueError, "specified size is out of range");
		return Value::Nil;
	}
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorCombination(pObj, cnt);
	return ReturnIterator(env, arg, pIterator);
}

// list#erase(idx*:number):reduce
Gura_DeclareMethod(list, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Erases elements at the specified indices.");
}

Gura_ImplementMethod(list, erase)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	Object_list::ValueVisitor_Index visitor(env, valList);
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		pValue->Accept(visitor);
	}
	Object_list::IndexList &indexList = visitor.GetIndexList();
	if (!indexList.empty()) {
		std::sort(indexList.begin(), indexList.end());
		size_t offset = 0;
		foreach_const (Object_list::IndexList, pIdx, indexList) {
			size_t idx = *pIdx;
			valList.erase(valList.begin() + idx - offset);
			offset++;
		}
	}
	return arg.GetValueThis();
}

// list#first()
Gura_DeclareMethod(list, first)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a first value in the list. An error occurs when the list is empty.");
}

Gura_ImplementMethod(list, first)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	if (valList.empty()) {
		sig.SetError(ERR_ValueError, "list is empty");
		return Value::Nil;
	}
	return valList.front();
}

// list#get(index:number):map:flat
Gura_DeclareMethod(list, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a value stored at the specified index in the list.\n"
		"An error occurs when the index is out of range.");
}

Gura_ImplementMethod(list, get)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	return pThis->IndexGet(env, arg.GetValue(0));
}

// list#insert(idx:number, elem+):reduce
Gura_DeclareMethod(list, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "idx", VTYPE_number);
	DeclareArg(env, "elem", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Insert specified items to the list from the selected index.");
}

Gura_ImplementMethod(list, insert)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	size_t idx = arg.GetSizeT(0);
	if (idx > valList.size()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Nil;
	}
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		valList.insert(valList.begin() + idx, *pValue);
		idx++;
	}
	return arg.GetValueThis();
}

// list#isempty()
Gura_DeclareMethod(list, isempty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Return true if the list is empty.");
}

Gura_ImplementMethod(list, isempty)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	return Value(pThis->GetList().empty());
}

// list#last()
Gura_DeclareMethod(list, last)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a last value in the list. An error occurs when the list is empty.");
}

Gura_ImplementMethod(list, last)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	if (valList.empty()) {
		sig.SetError(ERR_ValueError, "list is empty");
		return Value::Nil;
	}
	return valList.back();
}

// list#permutation(n?:number) {block?}
Gura_DeclareMethod(list, permutation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Creates an iterator that generates lists that contain elements picked up\n"
		"from the original list in a permutation manner.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(list, permutation)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	int cnt = arg.Is_number(0)? arg.GetInt(0) : -1;
	if (cnt > 0 && pThis->GetList().size() < static_cast<size_t>(cnt)) {
		sig.SetError(ERR_ValueError, "specified size is out of range");
		return Value::Nil;
	}
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorPermutation(pObj, cnt);
	return ReturnIterator(env, arg, pIterator);
}

// list#put(index:number, value:nomap):reduce:map
Gura_DeclareMethod(list, put)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_Once, FLAG_NoMap);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Stores a value at the specified index in the list.\n"
		"An error occurs when the index is out of range.");
}

Gura_ImplementMethod(list, put)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	pThis->IndexSet(env, arg.GetValue(0), arg.GetValue(1));
	return arg.GetValueThis();
}

// list#shuffle():reduce
Gura_DeclareMethod(list, shuffle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Shuffle the order of the list content based on random numbers.");
}

Gura_ImplementMethod(list, shuffle)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	Random random;
	std::random_shuffle(valList.begin(), valList.end(), random);
	return arg.GetValueThis();
}

// list#shift():[raise]
Gura_DeclareMethod(list, shift)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(raise));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Shifts the elements of the list. If the content of the list is [1, 2, 3, 4],\n"
		"it becomes [2, 3, 4] after calling this method. In default, no error occurs\n"
		"even when the list is empty. To raise an error for executing this method on\n"
		"an empty list, specify :raise attribute.");
}

Gura_ImplementMethod(list, shift)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	if (valList.empty()) {
		if (arg.IsSet(Gura_Symbol(raise))) {
			sig.SetError(ERR_ValueError, "no items");
		}
		return Value::Nil;
	}
	Value result = valList.front();
	valList.erase(valList.begin());
	return result;
}

//-----------------------------------------------------------------------------
// Implementation of methods that are common between iterator and list
//-----------------------------------------------------------------------------
// list#after(criteria) {block?}
Gura_DeclareMethod(list, after)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, after)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(pIteratorSrc->Since(env, arg.GetValue(0), false));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator.release());
}

// list#align(n:number, value?):map {block?}
Gura_DeclareMethod(list, align)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, align)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_Align(pIterator, arg.GetInt(0), arg.GetValue(1));
	return ReturnIterator(env, arg, pIterator);
}

// list#and()
Gura_DeclareMethodAlias(list, and_, "and")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, and_)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value result = pIterator->And(env);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#average()
Gura_DeclareMethod(list, average)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, average)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt;
	Value result = pIterator->Average(env, cnt);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#before(criteria) {block?}
Gura_DeclareMethod(list, before)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, before)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(pIteratorSrc->Until(env, arg.GetValue(0), false));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator.release());
}

// list#contains(value)
Gura_DeclareMethod(list, contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, contains)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	bool result = pIterator->DoesContain(env, arg.GetValue(0));
	if (sig.IsSignalled()) return Value::Nil;
	return Value(result);
}

// list#count(criteria?)
Gura_DeclareMethod(list, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, count)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt = arg.IsValid(0)?
		pIterator->Count(env, arg.GetValue(0)) : pIterator->CountTrue(env);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(static_cast<UInt>(cnt));
}

// list#cycle(n?:number) {block?}
Gura_DeclareMethod(list, cycle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, cycle)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	int cnt = arg.Is_number(0)? arg.GetInt(0) : -1;
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorCycle(pObj, cnt);
	return ReturnIterator(env, arg, pIterator);
}

// list#each() {block?}
Gura_DeclareMethod(list, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, each)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, arg, pIterator);
}

// list#filter(criteria?) {block?}
Gura_DeclareMethod(list, filter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, filter)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator;
	if (arg.IsValid(0)) {
		pIterator.reset(pIteratorSrc->Filter(env, arg.GetValue(0)));
		if (sig.IsSignalled()) return Value::Nil;
	} else {
		pIterator.reset(new Iterator_SkipFalse(pIteratorSrc));
	}
	return ReturnIterator(env, arg, pIterator.release());
}

// list#find(criteria?):[index]
Gura_DeclareMethod(list, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, find)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value value;
	size_t idx = arg.IsValid(0)?
			pIterator->Find(env, arg.GetValue(0), value) :
			pIterator->FindTrue(env, value);
	if (idx == InvalidSize) return Value::Nil;
	if (arg.IsSet(Gura_Symbol(index))) return Value(static_cast<UInt>(idx));
	return value;
}

// list#flat():[dfs,bfs] {block?}
Gura_DeclareMethod(list, flat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(dfs));
	DeclareAttr(Gura_Symbol(bfs));
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, flat)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator_Walk::Mode mode = arg.IsSet(Gura_Symbol(bfs))?
		Iterator_Walk::MODE_BreadthFirstSearch : Iterator_Walk::MODE_DepthFirstSearch;
	bool walkListFlag = true;
	bool walkIteratorFlag = true;
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(new Iterator_Walk(
									pIteratorSrc, mode, walkListFlag, walkIteratorFlag));
	pIterator->SetInfiniteFlag(false);
	//return pIterator->ToList(env, true, false);
	return ReturnIterator(env, arg, pIterator.release());
}

// list#fold(n:number, nstep?:number):map:[iteritem,neat] {block?}
Gura_DeclareMethod(list, fold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "nstep", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(iteritem));
	DeclareAttr(Gura_Symbol(neat));
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, fold)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	size_t cnt = arg.GetSizeT(0);
	size_t cntStep = arg.Is_number(1)? arg.GetSizeT(1) : cnt;
	bool listItemFlag = !arg.IsSet(Gura_Symbol(iteritem));
	bool neatFlag = arg.IsSet(Gura_Symbol(neat));
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorFold(pObj,
									cnt, cntStep, listItemFlag, neatFlag);
	return ReturnIterator(env, arg, pIterator);
}

// list#format(format:string):map {block?}
Gura_DeclareMethod(list, format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, format)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	return ReturnValue(env, arg,
					   Value(Formatter::FormatValueList(sig, arg.GetString(0), pThis->GetList())));
}

// list#head(n:number):map {block?}
Gura_DeclareMethod(list, head)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, head)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	int cnt = arg.GetInt(0);
	Iterator *pIterator = new Object_list::IteratorEach(pObj, 0, cnt);
	return ReturnIterator(env, arg, pIterator);
}

// list#join(sep?:string):map
Gura_DeclareMethod(list, join)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, join)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	const char *sep = arg.Is_string(0)? arg.GetString(0) : "";
	ValueList &valList = pThis->GetList();
	return Value(valList.Join(sep));
}

// list#joinb()
Gura_DeclareMethod(list, joinb)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, joinb)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	ValueList &valList = pThis->GetList();
	Binary rtn = valList.Joinb(sig);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(new Object_binary(env, rtn, true));
}

// list#len()
Gura_DeclareMethod(list, len)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, len)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	size_t cnt = pThis->GetList().size();
	return Value(static_cast<UInt>(cnt));
}

// list#map(func:function) {block?}
Gura_DeclareMethod(list, map)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "func", VTYPE_function);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, map)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	Iterator *pIterator = new Iterator_ExplicitMap(new Environment(env), pIteratorSrc,
			Object_function::Reference(Object_function::GetObject(arg, 0)));
	return ReturnIterator(env, arg, pIterator);
}

// list#max():[index,last_index,indices]
Gura_DeclareMethod(list, max)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, max)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value result = pIterator->MinMax(env, true, arg.GetAttrs());
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#min():[index,last_index,indices]
Gura_DeclareMethod(list, min)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, min)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value result = pIterator->MinMax(env, false, arg.GetAttrs());
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#nilto(replace) {block?}
Gura_DeclareMethod(list, nilto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, nilto)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_ReplaceInvalid(pIterator, arg.GetValue(0));
	return ReturnIterator(env, arg, pIterator);
}

// list#offset(n:number):map {block?}
Gura_DeclareMethod(list, offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, offset)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	size_t offset = arg.GetSizeT(0);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj, offset);
	return ReturnIterator(env, arg, pIterator);
}

// list#or()
Gura_DeclareMethodAlias(list, or_, "or")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, or_)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value result = pIterator->Or(env);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#pack(format:string)
Gura_DeclareMethod(list, pack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, pack)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	size_t offset = 0;
	pObjBinary->GetBinary().Pack(env, offset, arg.GetString(0), pThis->GetList());
	if (sig.IsSignalled()) return Value::Nil;
	return Value(pObjBinary.release());
}

// list#pingpong(n?:number):[sticky,sticky@top,sticky@btm] {block?}
Gura_DeclareMethod(list, pingpong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(sticky));
	DeclareAttr(Gura_Symbol(sticky_at_top));
	DeclareAttr(Gura_Symbol(sticky_at_btm));
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, pingpong)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	int cnt = arg.Is_number(0)? arg.GetInt(0) : -1;
	bool stickyFlagTop = arg.IsSet(Gura_Symbol(sticky)) ||
						arg.IsSet(Gura_Symbol(sticky_at_top));
	bool stickyFlagBtm = arg.IsSet(Gura_Symbol(sticky)) ||
						arg.IsSet(Gura_Symbol(sticky_at_btm));
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator =
		new Object_list::IteratorPingpong(pObj, cnt, stickyFlagTop, stickyFlagBtm);
	return ReturnIterator(env, arg, pIterator);
}

// list#print(stream?:stream:w):void
Gura_DeclareMethod(list, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, print)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Stream *pStream = arg.IsValid(0)? &arg.GetStream(0) : env.GetConsole();
	pThis->GetList().PrintEach(env, pStream);
	return Value::Nil;
}

// list#printf(format:string, stream?:stream:w):void
Gura_DeclareMethod(list, printf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, printf)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	const char *format = arg.GetString(0);
	Stream *pStream = arg.IsValid(1)? &arg.GetStream(1) : env.GetConsole();
	pThis->GetList().PrintfEach(env, pStream, format);
	return Value::Nil;
}

// list#println(stream?:stream:w):void
Gura_DeclareMethod(list, println)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, println)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Stream *pStream = arg.IsValid(0)? &arg.GetStream(0) : env.GetConsole();
	pThis->GetList().PrintlnEach(env, pStream);
	return Value::Nil;
}

// list#prod()
Gura_DeclareMethod(list, prod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, prod)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	Value result = pIterator->Prod(env);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#rank(directive?):[stable] {block?}
Gura_DeclareMethod(list, rank)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stable));
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, rank)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = pThis->SortRank(sig, arg.GetValue(0), nullptr,
							true, arg.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Nil;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, arg, pIterator);
}

// list#reduce(accum) {block}
Gura_DeclareMethod(list, reduce)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "accum", VTYPE_any);
	DeclareBlock(OCCUR_Once);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, reduce)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						arg.GetBlockFunc(*pEnvBlock, GetSymbolForBlock());
	if (pFuncBlock == nullptr) {
		return Value::Nil;
	}
	return pIterator->Reduce(env, arg.GetValue(0), pFuncBlock);
}

// list#replace(value, replace) {block?}
Gura_DeclareMethod(list, replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "replace", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, replace)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_Replace(pIterator,
								arg.GetValue(0), arg.GetValue(1));
	return ReturnIterator(env, arg, pIterator);
}

// list#reverse() {block?}
Gura_DeclareMethod(list, reverse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, reverse)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorReverse(pObj);
	return ReturnIterator(env, arg, pIterator);
}

// list#roundoff(threshold:number => 1e-10) {block?}
Gura_DeclareMethod(list, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, roundoff)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_RoundOff(pIterator, arg.GetNumber(0));
	return ReturnIterator(env, arg, pIterator);
}

// list#runlength() {block?}
Gura_DeclareMethod(list, runlength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, runlength)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_RunLength(pIterator);
	return ReturnIterator(env, arg, pIterator);
}

// list#since(criteria) {block?}
Gura_DeclareMethod(list, since)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, since)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(pIteratorSrc->Since(env, arg.GetValue(0), true));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator.release());
}

// list#skip(n:number):map {block?}
Gura_DeclareMethod(list, skip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, skip)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_Skip(pIterator, static_cast<int>(arg.GetSizeT(0)));
	return ReturnIterator(env, arg, pIterator);
}

// list#skipnil() {block?}
Gura_DeclareMethod(list, skipnil)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, skipnil)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_SkipInvalid(pIterator);
	return ReturnIterator(env, arg, pIterator);
}

// list#sort(directive?, keys[]?):[stable] {block?}
Gura_DeclareMethod(list, sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "keys", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareAttr(Gura_Symbol(stable));
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, sort)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = pThis->SortRank(sig, arg.GetValue(0),
						arg.Is_list(1)? &arg.GetList(1) : nullptr,
						false, arg.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Nil;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, arg, pIterator);
}

// list#stddev()
Gura_DeclareMethod(list, stddev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, stddev)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt;
	Value result = pIterator->StandardDeviation(env, cnt);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#sum()
Gura_DeclareMethod(list, sum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, sum)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt;
	Value result = pIterator->Sum(env, cnt);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#tail(n:number):map {block?}
Gura_DeclareMethod(list, tail)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, tail)
{
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Object_list *pObj = Object_list::Reference(pThis);
	int cnt = arg.GetInt(0);
	int cntMax = static_cast<int>(pObj->GetList().size());
	size_t offset = (cntMax > cnt)? cntMax - cnt : cntMax;
	Iterator *pIterator = new Object_list::IteratorEach(pObj, offset);
	return ReturnIterator(env, arg, pIterator);
}

// list#until(criteria) {block?}
Gura_DeclareMethod(list, until)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, until)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(pIteratorSrc->Until(env, arg.GetValue(0), true));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator.release());
}

// list#variance()
Gura_DeclareMethod(list, variance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, variance)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Nil;
	size_t cnt;
	Value result = pIterator->Variance(env, cnt);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

// list#walk():[dfs,bfs] {block?}
Gura_DeclareMethod(list, walk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(dfs));
	DeclareAttr(Gura_Symbol(bfs));
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, walk)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator_Walk::Mode mode = arg.IsSet(Gura_Symbol(bfs))?
		Iterator_Walk::MODE_BreadthFirstSearch : Iterator_Walk::MODE_DepthFirstSearch;
	bool walkListFlag = true;
	bool walkIteratorFlag = true;
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(new Iterator_Walk(
									pIteratorSrc, mode, walkListFlag, walkIteratorFlag));
	return ReturnIterator(env, arg, pIterator.release());
}

// list#while(criteria) {block?}
Gura_DeclareMethodAlias(list, while_, "while")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	LinkHelp(env.LookupClass(VTYPE_iterator), GetSymbol());
}

Gura_ImplementMethod(list, while_)
{
	Signal &sig = env.GetSignal();
	Object_list *pThis = Object_list::GetObjectThis(arg);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<Iterator> pIterator(pIteratorSrc->While(env, arg.GetValue(0)));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnIterator(env, arg, pIterator.release());
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_list::Class_list(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_list)
{
}

void Class_list::Prepare(Environment &env)
{
	Gura_AssignFunctionEx(list_xlist, "list");
	Gura_AssignFunctionEx(list_xlist, "xlist");
	Gura_AssignFunctionEx(set_xset, "set");
	Gura_AssignFunctionEx(set_xset, "xset");
	Gura_AssignFunctionEx(ListInit, "@");
	// assignment of class methods
	Gura_AssignMethod(list, zip);
	// assignment of instance methods
	Gura_AssignMethod(list, add);
	Gura_AssignMethod(list, append);
	Gura_AssignMethod(list, clear);
	Gura_AssignMethod(list, combination);
	Gura_AssignMethod(list, erase);
	Gura_AssignMethod(list, first);
	Gura_AssignMethod(list, get);
	Gura_AssignMethod(list, insert);
	Gura_AssignMethod(list, isempty);
	Gura_AssignMethod(list, last);
	Gura_AssignMethod(list, permutation);
	Gura_AssignMethod(list, put);
	Gura_AssignMethod(list, shift);
	Gura_AssignMethod(list, shuffle);
	// assignment of common methods with iterator
	Gura_AssignMethod(list, after);
	Gura_AssignMethod(list, align);
	Gura_AssignMethod(list, and_);
	Gura_AssignMethod(list, average);
	Gura_AssignMethod(list, before);
	Gura_AssignMethod(list, contains);
	Gura_AssignMethod(list, count);
	Gura_AssignMethod(list, cycle);
	Gura_AssignMethod(list, each);
	Gura_AssignMethod(list, filter);
	Gura_AssignMethod(list, find);
	Gura_AssignMethod(list, flat);
	Gura_AssignMethod(list, fold);
	Gura_AssignMethod(list, format);
	Gura_AssignMethod(list, head);
	Gura_AssignMethod(list, join);
	Gura_AssignMethod(list, joinb);
	Gura_AssignMethod(list, len);
	Gura_AssignMethod(list, map);
	Gura_AssignMethod(list, max);
	Gura_AssignMethod(list, min);
	Gura_AssignMethod(list, nilto);
	Gura_AssignMethod(list, offset);
	Gura_AssignMethod(list, or_);
	Gura_AssignMethod(list, pack);
	Gura_AssignMethod(list, pingpong);
	Gura_AssignMethod(list, print);
	Gura_AssignMethod(list, printf);
	Gura_AssignMethod(list, println);
	Gura_AssignMethod(list, prod);
	Gura_AssignMethod(list, rank);
	Gura_AssignMethod(list, reduce);
	Gura_AssignMethod(list, replace);
	Gura_AssignMethod(list, reverse);
	Gura_AssignMethod(list, roundoff);
	Gura_AssignMethod(list, runlength);
	Gura_AssignMethod(list, since);
	Gura_AssignMethod(list, skip);
	Gura_AssignMethod(list, skipnil);
	Gura_AssignMethod(list, sort);
	Gura_AssignMethod(list, stddev);
	Gura_AssignMethod(list, sum);
	Gura_AssignMethod(list, tail);
	Gura_AssignMethod(list, until);
	Gura_AssignMethod(list, variance);
	Gura_AssignMethod(list, walk);
	Gura_AssignMethod(list, while_);
}

bool Class_list::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	Signal &sig = GetSignal();
	if (value.IsType(VTYPE_nil)) {
		value.InitAsList(env);
		return true;
	} else if (value.Is_iterator()) {
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		Value result = pIterator->ToList(env, true, false);
		if (sig.IsSignalled()) return false;
		value = result;
		return true;
	} else if (value.Is_matrix()) {
		const Object_matrix *pObjMat = Object_matrix::GetObject(value);
		if (pObjMat->GetMatrix()->GetRows() == 1) {
			Value result = pObjMat->GetMatrix()->GetRow(env, 0);
			value = result;
		} else if (pObjMat->GetMatrix()->GetCols() == 1) {
			Value result = pObjMat->GetMatrix()->GetCol(env, 0);
			value = result;
		}
		return true;
	}
	return false;
}

bool Class_list::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return value.GetList().Serialize(env, stream);
}

bool Class_list::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	ValueList &valList = value.InitAsList(env);
	return valList.Deserialize(env, stream);
}

Object *Class_list::CreateDescendant(Environment &env, Class *pClass)
{
	return (pClass == nullptr)? new Object_list(env) : new Object_list(pClass);
}

}
