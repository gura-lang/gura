//
// Object_list
//

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

Value Object_list::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for list");
		return Value::Null;
	}
	//size_t idx = valueIdx.GetSizeT();
	int idx = valueIdx.GetInt();
	if (idx < 0) idx += _valList.size();
	if (idx >= static_cast<int>(GetList().size())) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Null;
	}
	return GetList()[idx];
}

void Object_list::IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value)
{
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_IndexError, "index must be a number for list");
		return;
	}
	//size_t idx = valueIdx.GetSizeT();
	int idx = valueIdx.GetInt();
	if (idx < 0) idx += _valList.size();
	if (idx >= static_cast<int>(GetList().size())) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return;
	}
	GetList()[idx] = value;
}

Iterator *Object_list::CreateIterator(Signal sig)
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

Object_list *Object_list::SortRank(Signal sig, const Value &valDirective,
					const ValueList *pValListKey, bool rankFlag, bool stableFlag)
{
	typedef std::map<const Value *, const Value *> ValuePtrMap;
	Environment &env = *this;
	enum { MODE_Ascend, MODE_Descend, MODE_Custom } mode = MODE_Ascend;
	const Function *pFunc = NULL;
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
			return NULL;
		}
	} else if (valDirective.Is_function()) {
		mode = MODE_Custom;
		pFunc = valDirective.GetFunction();
		if (pFunc->GetDeclOwner().size() != 2) {
			sig.SetError(ERR_TypeError,
				"only a binary function can be specified");
			return NULL;
		}
	} else {
		sig.SetError(ERR_TypeError, "invalid argument");
		return NULL;
	}
	ValuePtrList valPtrList;
	ValuePtrMap valuePtrMap;
	if (rankFlag || pValListKey == NULL) {
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
			std::stable_sort(valPtrList.begin(), valPtrList.end(), Comparator_Ascend());
		} else if (mode == MODE_Descend) {
			std::stable_sort(valPtrList.begin(), valPtrList.end(), Comparator_Descend());
		} else { // mode == MODE_Custom
			std::stable_sort(valPtrList.begin(), valPtrList.end(),
											Comparator_Custom(env, sig, pFunc));
		}
	} else {
		if (mode == MODE_Ascend) {
			std::sort(valPtrList.begin(), valPtrList.end(), Comparator_Ascend());
		} else if (mode == MODE_Descend) {
			std::sort(valPtrList.begin(), valPtrList.end(), Comparator_Descend());
		} else { // mode == MODE_Custom
			std::sort(valPtrList.begin(), valPtrList.end(),
											Comparator_Custom(env, sig, pFunc));
		}
	}
	Value result;
	ValueList &valListResult = result.InitAsList(env);
	if (rankFlag) {
		foreach_const (ValueList, pValue, valList) {
			ValuePtrList::iterator ppValue = valPtrList.begin();
			for ( ; ppValue != valPtrList.end(); ppValue++) {
				if (Value::Compare(*pValue, **ppValue) == 0) break;
			}
			if (ppValue == valPtrList.end()) {
				sig.SetError(ERR_SystemError, "fatal error in rank() operation");
				return NULL;
			} else {
				int idx = static_cast<int>(ppValue - valPtrList.begin());
				valListResult.push_back(Value(idx));
			}
		}
	} else if (pValListKey == NULL) {
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
	int idx = value.GetInt();
	if (idx < 0) idx += _valList.size();
	if (std::find(_indexList.begin(), _indexList.end(), idx) != _indexList.end()) {
		// nothing to do
	} else if (idx < static_cast<int>(_valList.size())) {
		_indexList.push_back(idx);
	} else {
		_sig.SetError(ERR_IndexError, "index is out of range");
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
	return NULL;
}

bool Object_list::IteratorEach::DoNext(Environment &env, Signal sig, Value &value)
{
	ValueList &valList = _pObj->GetList();
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
	return NULL;
}

bool Object_list::IteratorReverse::DoNext(Environment &env, Signal sig, Value &value)
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
// Object_list::IteratorRound
//-----------------------------------------------------------------------------
Object_list::IteratorRound::~IteratorRound()
{
}

Iterator *Object_list::IteratorRound::GetSource()
{
	return NULL;
}

bool Object_list::IteratorRound::DoNext(Environment &env, Signal sig, Value &value)
{
	ValueList &valList = _pObj->GetList();
	if (_pValue == valList.end() || _cnt == 0) return false;
	value = *_pValue;
	_pValue++;
	if (_cnt > 0) _cnt--;
	if (_pValue == valList.end()) _pValue = valList.begin();
	return true;
}

String Object_list::IteratorRound::ToString() const
{
	return String("list#round");
}

void Object_list::IteratorRound::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
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
	return NULL;
}

bool Object_list::IteratorPingpong::DoNext(Environment &env, Signal sig, Value &value)
{
	ValueList &valList = _pObj->GetList();
	if (_forwardFlag) {
		if (_pValueFwd == valList.end() || _cnt == 0) return false;
		value = *_pValueFwd;
		_pValueFwd++;
		if (_cnt > 0) _cnt--;
		if (_pValueFwd == valList.end() ||
				(!_stickyFlagR && _pValueFwd + 1 == valList.end())) {
			_forwardFlag = false;
			_pValueBwd = valList.rbegin();
		}
	} else {
		if (_pValueBwd == valList.rend() || _cnt == 0) return false;
		value = *_pValueBwd;
		_pValueBwd++;
		if (_cnt > 0) _cnt--;
		if (_pValueBwd == valList.rend() ||
				(!_stickyFlagL && _pValueBwd + 1 == valList.rend())) {
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
Object_list::IteratorFold::IteratorFold(Object_list *pObj, size_t cntPerFold, size_t cntStep, bool listItemFlag) :
		Iterator(false), _pObj(pObj), _offset(0),
		_cntPerFold(cntPerFold), _cntStep(cntStep), _listItemFlag(listItemFlag)
{
}

Object_list::IteratorFold::~IteratorFold()
{
}

Iterator *Object_list::IteratorFold::GetSource()
{
	return NULL;
}

bool Object_list::IteratorFold::DoNext(Environment &env, Signal sig, Value &value)
{
	ValueList &valList = _pObj->GetList();
	if (_offset >= valList.size()) return false;
	AutoPtr<Iterator> pIterator(new IteratorEach(
					Object_list::Reference(_pObj.get()), _offset, _cntPerFold));
	if (_listItemFlag) {
		bool excludeNilFlag = false;
		value = pIterator->ToList(env, sig, true, excludeNilFlag);
	} else {
		value = Value(new Object_iterator(env, pIterator.release()));
	}
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
	return NULL;
}

bool Object_list::IteratorPermutation::DoNext(Environment &env, Signal sig, Value &value)
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
	return NULL;
}

bool Object_list::IteratorCombination::DoNext(Environment &env, Signal sig, Value &value)
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
	if (_sig.IsSignalled()) return false;
	AutoPtr<Args> pArgsSub(new Args());
	pArgsSub->SetValues(*pValue1, *pValue2);
	Value value = _pFunc->Eval(_env, _sig, *pArgsSub);
	return value.GetNumber() < 0;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// list(value+)
Gura_DeclareFunction(list)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_OnceOrMore);
	SetClassToConstruct(env.LookupClass(VTYPE_list));
}

Gura_ImplementFunction(list)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ValueList, pValue, args.GetList(0)) {
		Iterator *pIterator = NULL;
		if (pValue->Is_list() || pValue->Is_iterator()) {
			pIterator = pValue->CreateIterator(sig);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			pIterator = new Iterator_OneShot(*pValue);
		}
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return Value::Null;
		}
		Value value;
		while (pIterator->Next(env, sig, value)) {
			valList.push_back(value);
		}
		if (sig.IsSignalled()) return Value::Null;
	}
	return result;
}

// xlist(iter+:iterator)
Gura_DeclareFunction(xlist)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "iter", VTYPE_iterator, OCCUR_OnceOrMore);
}

Gura_ImplementFunction(xlist)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ValueList, pValue, args.GetList(0)) {
		Value value;
		Iterator *pIterator = pValue->GetIterator();
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return Value::Null;
		}
		while (pIterator->Next(env, sig, value)) {
			if (value.IsValid()) valList.push_back(value);
		}
		if (sig.IsSignalled()) return Value::Null;
	}
	return result;
}

// set(iter+:iterator):[and,xor,or]
// xset(iter+:iterator):[and,xor,or]
Gura_DeclareFunctionBegin(set_xset)
	bool _acceptInvalidFlag;
Gura_DeclareFunctionEnd(set_xset)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	_acceptInvalidFlag = (::strcmp(GetName(), "set") == 0);
	DeclareArg(env, "iter", VTYPE_iterator, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(or));
	DeclareAttr(Gura_Symbol(and));
	DeclareAttr(Gura_Symbol(xor));
}

Gura_ImplementFunction(set_xset)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	if (args.IsSet(Gura_Symbol(and))) {			// AND combination
		ValueList valList1, valList2;
		ValueList::const_reverse_iterator pValueArg = args.GetList(0).rbegin();
		Value value;
		for (Iterator *pIterator = pValueArg->GetIterator();
											pIterator->Next(env, sig, value); ) {
			if ((_acceptInvalidFlag || value.IsValid()) &&
											!valList1.DoesContain(value)) {
				valList1.push_back(value);
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		pValueArg++;
		ValueList *pValListAnd = &valList1;
		ValueList *pValListWork = &valList2;
		for ( ; pValueArg != args.GetList(0).rend() &&
										!pValListAnd->empty(); pValueArg++) {
			Value value;
			for (Iterator *pIterator = pValueArg->GetIterator();
											pIterator->Next(env, sig, value); ) {
				if (pValListAnd->DoesContain(value) && !pValListWork->DoesContain(value)) {
					pValListWork->push_back(value);
				}
			}
			ValueList *pValListTmp = pValListAnd;
			pValListAnd = pValListWork, pValListWork = pValListTmp;
			pValListWork->clear();
		}
		foreach_const (ValueList, pValue, *pValListAnd) {
			valList.push_back(*pValue);
		}
	} else if (args.IsSet(Gura_Symbol(xor))) {	// XOR combination
		ValueList valList1, valList2;
		ValueList *pValListAnd = &valList1;
		ValueList valListOr;
		ValueList::const_iterator pValueArg = args.GetList(0).begin();
		Value value;
		for (Iterator *pIterator = pValueArg->GetIterator();
										pIterator->Next(env, sig, value); ) {
			if (!valList1.DoesContain(value)) valList1.push_back(value);
			if ((_acceptInvalidFlag || value.IsValid()) &&
											!valListOr.DoesContain(value)) {
				valListOr.push_back(value);
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		pValueArg++;
		ValueList *pValListWork = &valList2;
		for ( ; pValueArg != args.GetList(0).end() &&
										!pValListAnd->empty(); pValueArg++) {
			Value value;
			for (Iterator *pIterator = pValueArg->GetIterator();
										pIterator->Next(env, sig, value); ) {
				if (pValListAnd->DoesContain(value)) pValListWork->push_back(value);
				if ((_acceptInvalidFlag || value.IsValid()) &&
												!valListOr.DoesContain(value)) {
					valListOr.push_back(value);
				}
			}
			if (sig.IsSignalled()) return Value::Null;
			ValueList *pValListTmp = pValListAnd;
			pValListAnd = pValListWork, pValListWork = pValListTmp;
			pValListWork->clear();
		}
		foreach_const (ValueList, pValue, valListOr) {
			if (!pValListAnd->DoesContain(*pValue)) {
				valList.push_back(*pValue);
			}
		}
	} else {										// OR combination
		foreach_const (ValueList, pValue, args.GetList(0)) {
			Value value;
			for (Iterator *pIterator = pValue->GetIterator();
												pIterator->Next(env, sig, value); ) {
				if ((_acceptInvalidFlag || value.IsValid()) &&
												!valList.DoesContain(value)) {
					valList.push_back(value);
				}
			}
			if (sig.IsSignalled()) return Value::Null;
		}
	}
	return result;
}

// @(func?:Function) {block?}
Gura_DeclareFunction(ListInit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "func", VTYPE_function, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListInit)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	const Value &valueFunc = args.GetValue(0);
	Value result;
	if (pExprBlock == NULL) {
		result.InitAsList(env);
	} else if (valueFunc.Is_function()) {
		const Function *pFunc = valueFunc.GetFunction();
		size_t cntArgs = pFunc->GetDeclOwner().size();
		if (cntArgs == 0) {
			sig.SetError(ERR_TypeError, "function '%s' needs no argument", pFunc->GetName());
			return Value::Null;
		}
		AutoPtr<Environment> pEnvLister(new Environment(&env, ENVTYPE_lister));
		ValueList &valList = result.InitAsList(env);
		foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
			SeqPostHandler *pSeqPostHandler = NULL;
			Value value = (*ppExpr)->Exec2(*pEnvLister, sig, pSeqPostHandler);
			if (sig.IsSignalled()) {
				sig.AddExprCause(*ppExpr);
				return Value::Null;
			}
			if (!value.Is_list()) {
				sig.SetError(ERR_SyntaxError, "invalid format in list initializer");
				return Value::Null;
			}
			AutoPtr<Args> pArgsSub(new Args());
			pArgsSub->SetValueListArg(value.GetList());
			Value valueElem = pFunc->Eval(env, sig, *pArgsSub);
			if (sig.IsSignalled()) return Value::Null;
			valList.push_back(valueElem);
		}
	} else {
#if 0
		AutoPtr<Environment> pEnvLister(new Environment(&env, ENVTYPE_lister));
		ValueList &valList = result.InitAsList(env);
		foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
			SeqPostHandler *pSeqPostHandler = NULL;
			Value value = (*ppExpr)->Exec2(*pEnvLister, sig, pSeqPostHandler);
			if (sig.IsSignalled()) {
				sig.AddExprCause(*ppExpr);
				return Value::Null;
			}
			valList.push_back(value);
		}
#endif
		AutoPtr<Environment> pEnvLister(new Environment(&env, ENVTYPE_lister));
		result = pExprBlock->Exec(*pEnvLister, sig, NULL);
	}
	return result;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_list
//-----------------------------------------------------------------------------
// list#clear():reduce
Gura_DeclareMethod(list, clear)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Clear the content of the list.");
}

Gura_ImplementMethod(list, clear)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	pThis->GetList().clear();
	return args.GetThis();
}

// list#isempty()
Gura_DeclareMethod(list, isempty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Return true if the list is empty.");
}

Gura_ImplementMethod(list, isempty)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	return Value(pThis->GetList().empty());
}

// list#shuffle():reduce
Gura_DeclareMethod(list, shuffle)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Shuffle the order of the list content based on random numbers.");
}

Gura_ImplementMethod(list, shuffle)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	RandomGenerator randomGenerator;
	std::random_shuffle(valList.begin(), valList.end(), randomGenerator);
	return args.GetThis();
}

// list#add(elem+):reduce
Gura_DeclareMethod(list, add)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "elem", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Add specified items to the list.");
}

Gura_ImplementMethod(list, add)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	foreach_const (ValueList, pValue, args.GetList(0)) {
		valList.push_back(*pValue);
	}
	return args.GetThis();
}

// list#insert(idx:number, elem+):reduce
Gura_DeclareMethod(list, insert)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "idx", VTYPE_number);
	DeclareArg(env, "elem", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Insert specified items to the list from the selected index.");
}

Gura_ImplementMethod(list, insert)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	size_t idx = args.GetSizeT(0);
	if (idx > valList.size()) {
		sig.SetError(ERR_IndexError, "index is out of range");
		return Value::Null;
	}
	foreach_const (ValueList, pValue, args.GetList(1)) {
		valList.insert(valList.begin() + idx, *pValue);
		idx++;
	}
	return args.GetThis();
}

// list#append(elem+):reduce
Gura_DeclareMethod(list, append)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "elem", VTYPE_any, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Adds specified items to the list. If the item is a list or an iterator,\n"
	"each element in such an item is added to the list.");
}

Gura_ImplementMethod(list, append)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	foreach_const (ValueList, pValue, args.GetList(0)) {
		if (pValue->Is_list() || pValue->Is_iterator()) {
			AutoPtr<Iterator> pIterator(pValue->CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Null;
			if (pIterator->IsInfinite()) {
				Iterator::SetError_InfiniteNotAllowed(sig);
				return Value::Null;
			}
			Value value;
			while (pIterator->Next(env, sig, value)) {
				valList.push_back(value);
			}
			if (sig.IsSignalled()) return Value::Null;
		} else {
			valList.push_back(*pValue);
		}
	}
	return args.GetThis();
}

// list#shift():[raise]
Gura_DeclareMethod(list, shift)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(raise));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Shifts the elements of the list. If the content of the list is [1, 2, 3, 4],\n"
	"it becomes [2, 3, 4] after calling this method. In default, no error occurs\n"
	"even when the list is empty. To raise an error for executing this method on\n"
	"an empty list, specify :raise attribute.");
}

Gura_ImplementMethod(list, shift)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	if (valList.empty()) {
		if (args.IsSet(Gura_Symbol(raise))) {
			sig.SetError(ERR_ValueError, "no items");
		}
		return Value::Null;
	}
	Value result = valList.front();
	valList.erase(valList.begin());
	return result;
}

// list#erase(idx*:number):reduce
Gura_DeclareMethod(list, erase)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_ZeroOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Erases elements at the specified indices.");
}

Gura_ImplementMethod(list, erase)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	Object_list::ValueVisitor_Index visitor(env, sig, valList);
	foreach_const (ValueList, pValue, args.GetList(0)) {
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
	return args.GetThis();
}

// list#get(index:number):map:flat
Gura_DeclareMethod(list, get)
{
	SetMode(RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a value stored at the specified index in the list.\n"
	"An error occurs when the index is out of range.");
}

Gura_ImplementMethod(list, get)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	return pThis->IndexGet(env, sig, args.GetValue(0));
}

// list#first()
Gura_DeclareMethod(list, first)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a first value in the list. An error occurs when the list is empty.");
}

Gura_ImplementMethod(list, first)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	if (valList.empty()) {
		sig.SetError(ERR_ValueError, "list is empty");
		return Value::Null;
	}
	return valList.front();
}

// list#last()
Gura_DeclareMethod(list, last)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a last value in the list. An error occurs when the list is empty.");
}

Gura_ImplementMethod(list, last)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	if (valList.empty()) {
		sig.SetError(ERR_ValueError, "list is empty");
		return Value::Null;
	}
	return valList.back();
}

// list#permutation(n?:number) {block?}
Gura_DeclareMethod(list, permutation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that generates lists that contain elements picked up\n"
	"from the original list in a permutation manner.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value:list, idx:number|");
}

Gura_ImplementMethod(list, permutation)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	int cnt = args.Is_number(0)? args.GetInt(0) : -1;
	if (cnt > 0 && pThis->GetList().size() < static_cast<size_t>(cnt)) {
		sig.SetError(ERR_ValueError, "specified size is out of range");
		return Value::Null;
	}
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorPermutation(pObj, cnt);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#combination(n:number) {block?}
Gura_DeclareMethod(list, combination)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that generates lists that contain elements picked up\n"
	"from the original list in a combination manner.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value:list, idx:number|");
}

Gura_ImplementMethod(list, combination)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	int cnt = args.GetInt(0);
	if (pThis->GetList().size() < static_cast<size_t>(cnt)) {
		sig.SetError(ERR_ValueError, "specified size is out of range");
		return Value::Null;
	}
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorCombination(pObj, cnt);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#flat()
Gura_DeclareMethod(list, flat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns the flattened list.");
}

Gura_ImplementMethod(list, flat)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Value result;
	ValueList &valList = result.InitAsList(env);
	pThis->GetList().ExtractFlat(valList);
	return result;
}

// list#printf(format:string, stream?:stream:w):void
Gura_DeclareMethod(list, printf)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Prints items in the list by using the format.");
}

Gura_ImplementMethod(list, printf)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	const char *format = args.GetString(0);
	Stream *pConsole = args.IsInstanceOf(1, VTYPE_stream)?
				&args.GetStream(1) : env.GetConsole();
	if (pConsole == NULL) return Value::Null;
	pConsole->Printf(sig, args.GetString(0), pThis->GetList());
	return Value::Null;
}

// list#len()
Gura_DeclareMethod(list, len)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns the length of the list.");
}

Gura_ImplementMethod(list, len)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	size_t cnt = pThis->GetList().size();
	return Value(static_cast<UInt>(cnt));
}

// list#min():[index,last_index,indices]
Gura_DeclareMethod(list, min)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns the minimum value in the list when no attribute is specified.\n"
	"With an attribute :index, it returns an index of the minimum value.\n"
	"With an attribute :last_index, it returns the last index of the minimum value\n"
	"when more than one elements have the same value.\n"
	"With an attribute :indices, it returns a list of indices of elements that\n"
	"has the minimum value.");
}

Gura_ImplementMethod(list, min)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	Value result = pIterator->MinMax(env, sig, false, args.GetAttrs());
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// list#max():[index,last_index,indices]
Gura_DeclareMethod(list, max)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareAttr(Gura_Symbol(indices));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns the maximum value in the list when no attribute is specified.\n"
	"With an attribute :index, it returns an index of the maximum value.\n"
	"With an attribute :last_index, it returns the last index of the maximum value\n"
	"when more than one elements have the same value.\n"
	"With an attribute :indices, it returns a list of indices of elements that\n"
	"has the maximum value.");
}

Gura_ImplementMethod(list, max)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	Value result = pIterator->MinMax(env, sig, true, args.GetAttrs());
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// list#sum()
Gura_DeclareMethod(list, sum)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a sum of values in the list.");
}

Gura_ImplementMethod(list, sum)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt;
	Value result = pIterator->Sum(env, sig, cnt);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// list#average()
Gura_DeclareMethod(list, average)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an average of values in the list.");
}

Gura_ImplementMethod(list, average)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt;
	Value result = pIterator->Average(env, sig, cnt);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// list#variance()
Gura_DeclareMethod(list, variance)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a variance of values in the list.");
}

Gura_ImplementMethod(list, variance)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt;
	Value result = pIterator->Variance(env, sig, cnt);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// list#stddev()
Gura_DeclareMethod(list, stddev)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a standard deviation of values in the list.");
}

Gura_ImplementMethod(list, stddev)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt;
	Value result = pIterator->StandardDeviation(env, sig, cnt);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// list#and()
Gura_DeclareMethodAlias(list, and_, "and")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Calculates a logical AND result of all the values in the list.\n"
	"Values of boolean type's false and nil are recognized as false\n"
	"while others are true.");
}

Gura_ImplementMethod(list, and_)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	Value result = pIterator->And(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// list#or()
Gura_DeclareMethodAlias(list, or_, "or")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Calculates a logical OR result of all the values in the list.\n"
	"Values of boolean type's false and nil are recognized as false\n"
	"while others are true.");
}

Gura_ImplementMethod(list, or_)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	Value result = pIterator->Or(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

// list#contains(value)
Gura_DeclareMethod(list, contains)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns true if a specified value exists in the list.");
}

Gura_ImplementMethod(list, contains)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	bool result = pIterator->DoesContain(env, sig, args.GetValue(0));
	if (sig.IsSignalled()) return Value::Null;
	return Value(result);
}

// list#filter(criteria?) {block?}
Gura_DeclareMethod(list, filter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a list that consists of elements of the original list after filtering\n"
	"by a criteria. A criteria can be an iterator or a function object.\n"
	"When an iterator is supplied as a criteria, it picks up true value in the iterator\n"
	"and creates a list that contains elements at corresponding position in the original list\n"
	"When a function object is applied, each element is passed to the function\n"
	"as an argument, and it collects values with evaluated results being true.");
}

Gura_ImplementMethod(list, filter)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = NULL;
	if (args.IsValid(0)) {
		pIterator = pIteratorSrc->Filter(env, sig, args.GetValue(0));
		if (sig.IsSignalled()) return Value::Null;
	} else {
		pIterator = new Iterator_SkipFalse(pIteratorSrc);
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// list#while(criteria) {block?}
Gura_DeclareMethodAlias(list, while_, "while")
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that picks up each element in the list while criteria\n"
	"is evaluated as true. You can specify a function object, a list or an iterator\n"
	"as the criteria.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value:list, idx:number|");
}

Gura_ImplementMethod(list, while_)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = pIteratorSrc->While(env, sig, args.GetValue(0));
	if (sig.IsSignalled()) {
		Iterator::Delete(pIteratorSrc);
		return Value::Null;
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// list#since(criteria) {block?}
Gura_DeclareMethod(list, since)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that picks up each element in the list since criteria\n"
	"is evaluated as true. You can specify a function object, a list or an iterator\n"
	"as the criteria.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value:list, idx:number|");
}

Gura_ImplementMethod(list, since)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = pIteratorSrc->Since(env, sig, args.GetValue(0), true);
	if (sig.IsSignalled()) {
		Iterator::Delete(pIteratorSrc);
		return Value::Null;
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// list#after(criteria) {block?}
Gura_DeclareMethod(list, after)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that picks up each element in the list after criteria\n"
	"is evaluated as true. You can specify a function object, a list or an iterator\n"
	"as the criteria.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value:list, idx:number|");
}

Gura_ImplementMethod(list, after)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = pIteratorSrc->Since(env, sig, args.GetValue(0), false);
	if (sig.IsSignalled()) {
		Iterator::Delete(pIteratorSrc);
		return Value::Null;
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// list#until(criteria) {block?}
Gura_DeclareMethod(list, until)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that picks up each element in the list until criteria\n"
	"is evaluated as true. You can specify a function object, a list or an iterator\n"
	"as the criteria.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value:list, idx:number|");
}

Gura_ImplementMethod(list, until)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = pIteratorSrc->Until(env, sig, args.GetValue(0), true);
	if (sig.IsSignalled()) {
		Iterator::Delete(pIteratorSrc);
		return Value::Null;
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// list#before(criteria) {block?}
Gura_DeclareMethod(list, before)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that picks up each element in the list before criteria\n"
	"is evaluated as true. You can specify a function object, a list or an iterator\n"
	"as the criteria.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value:list, idx:number|");
}

Gura_ImplementMethod(list, before)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = pIteratorSrc->Until(env, sig, args.GetValue(0), false);
	if (sig.IsSignalled()) {
		Iterator::Delete(pIteratorSrc);
		return Value::Null;
	}
	return ReturnIterator(env, sig, args, pIterator);
}

// list#map(func:function) {block?}
Gura_DeclareMethod(list, map)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "func", VTYPE_function);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that generates element values after applying the specfied\n"
	"function on them. The function must take one argument.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value, idx:number|");
}

Gura_ImplementMethod(list, map)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Iterator *pIteratorSrc = pThis->CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = new Iterator_ExplicitMap(new Environment(env), sig, pIteratorSrc,
			Object_function::Reference(Object_function::GetObject(args, 0)));
	return ReturnIterator(env, sig, args, pIterator);
}

// list#reduce(accum) {block}
Gura_DeclareMethod(list, reduce)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "accum", VTYPE_any);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Evaluates a block with a parameter format |value, accum| and leaves the result\n"
	"as the next accum value. It returns the final accum value as its result.");
}

Gura_ImplementMethod(list, reduce)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	const Function *pFuncBlock =
						args.GetBlockFunc(*pEnvBlock, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) {
		return Value::Null;
	}
	return pIterator->Reduce(env, sig, args.GetValue(0), pFuncBlock);
}

// list#find(criteria?):[index]
Gura_DeclareMethod(list, find)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(index));
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, find)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	Value value;
	size_t idx = args.IsValid(0)?
			pIterator->Find(env, sig, args.GetValue(0), value) :
			pIterator->FindTrue(env, sig, value);
	if (idx == InvalidSize) return Value::Null;
	if (args.IsSet(Gura_Symbol(index))) return Value(static_cast<UInt>(idx));
	return value;
}

// list#count(criteria?)
Gura_DeclareMethod(list, count)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "criteria", VTYPE_any, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a number of elements that matches the given criteria which is a single-argument\n"
	"function or a value. When a function is applied, it counts the number of true after\n"
	"evaluating element value with the function. If a value is applied, it counts the number\n"
	"of elements that are equal to the value.");
}

Gura_ImplementMethod(list, count)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Iterator> pIterator(pThis->CreateIterator(sig));
	if (sig.IsSignalled()) return Value::Null;
	size_t cnt = args.IsValid(0)?
		pIterator->Count(env, sig, args.GetValue(0)) : pIterator->CountTrue(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return Value(static_cast<UInt>(cnt));
}

// list#sort(directive?, keys[]?):[stable] {block?}
Gura_DeclareMethod(list, sort)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "keys", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareAttr(Gura_Symbol(stable));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns an iterator of elements after sorting them.\n"
	"In default, they are sorted in an ascending order. You can specify the following\n"
	"directives for sorting.\n"
	"\n"
	"- `` `ascend`` .. ascending order\n"
	"- `` `descend`` .. descending order\n"
	"- function .. it takes two element values x and y and returns zero for x == y,\n"
	"           plus value for x < y and minus value for x > y.\n"
	"\n"
	"If keys is specified, it shall be used as a key instead of element values.\n"
	"When an attribute :stable is specified, the original order shall be kept for\n"
	"elements that are determined as the same.");
}

Gura_ImplementMethod(list, sort)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = pThis->SortRank(sig, args.GetValue(0),
						args.Is_list(1)? &args.GetList(1) : NULL,
						false, args.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#rank(directive?):[stable]
Gura_DeclareMethod(list, rank)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "directive", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stable));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a list of rank numbers for elements after sorting them.\n"
	"In default, they are sorted in an ascending order. You can specify the following\n"
	"directives for sorting.\n"
	"\n"
	"- `` `ascend`` .. ascending order\n"
	"- `` `descend`` .. descending order\n"
	"- function .. it takes two element values x and y and returns zero for x == y,\n"
	"           plus value for x < y and minus value for x > y.\n"
	"\n"
	"When an attribute :stable is specified, the original order shall be kept for\n"
	"elements that are determined as the same.");
}

Gura_ImplementMethod(list, rank)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = pThis->SortRank(sig, args.GetValue(0), NULL,
							true, args.IsSet(Gura_Symbol(stable)));
	if (sig.IsSignalled()) return Value::Null;
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#join(sep:string => "")
Gura_DeclareMethod(list, join)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "sep", VTYPE_string, OCCUR_Once, FLAG_None, new Expr_String(""));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string that joins strings of elements with the specified separator.");
}

Gura_ImplementMethod(list, join)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	ValueList &valList = pThis->GetList();
	return Value(Join(valList, args.GetString(0)));
}

// list#format(format:string):map
Gura_DeclareMethod(list, format)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Applies element values in the list to format string that contains C printf"
	"specifiers	and returns a formatted string.");
}

Gura_ImplementMethod(list, format)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	return Value(Formatter::Format(sig, args.GetString(0), pThis->GetList()));
}

// list#pack(format:string)
Gura_DeclareMethod(list, pack)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a binary object packing elements values according to a format string.\n"
	"Following markers specify the order of how a multi-byte number is stored.\n"
	"\n"
	"- `@` .. sets as a native order for the current platform\n"
	"- `=` .. sets as a native order for the current platform\n"
	"- `<` .. sets as a little-endian order\n"
	"- `>` .. sets as a big-endian order\n"
	"- `!` .. sets as a big-endian order\n"
	"\n"
	"Following markers specify a storing format. They can be preceded by a number\n"
	"that specifies the number of values.\n"
	"\n"
	"- `x` .. just skips one byte\n"
	"- `c` .. takes a string that contains one character and stores it as a byte value\n"
	"- `b` .. stores a number as a signed byte value\n"
	"- `B` .. stores a number as an unsigned byte value\n"
	"- `h` .. stores a number as a signed half-word (2 bytes) value\n"
	"- `H` .. stores a number as an unsigned half-word (2 bytes) value\n"
	"- `i` .. stores a number as a signed integer (4 bytes) value\n"
	"- `I` .. stores a number as an unsigned integer (4 bytes) value\n"
	"- `l` .. stores a number as a signed integer (4 bytes) value\n"
	"- `L` .. stores a number as an unsigned integer (4 bytes) value\n"
	"- `q` .. stores a number as a signed long integer (8 bytes) value\n"
	"- `Q` .. stores a number as an unsigned long integer (8 bytes) value\n"
	"- `f` .. stores a number as a float (4 bytes) value\n"
	"- `d` .. stores a number as a double (8 bytes) value\n"
	"- `s` .. stores a string after character encoding\n");
}

Gura_ImplementMethod(list, pack)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	size_t offset = 0;
	pObjBinary->GetBinary().Pack(env, sig, offset, args.GetString(0), pThis->GetList());
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObjBinary.release());
}

// list#each() {block?}
Gura_DeclareMethod(list, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that iterates each element in the list.\n"
	GURA_ITERATOR_HELP
	"Block parameter format: |value, idx:number|");
}

Gura_ImplementMethod(list, each)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#offset(n:number):map {block?}
Gura_DeclareMethod(list, offset)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, offset)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	size_t offset = args.GetSizeT(0);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj, offset);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#runlength() {block?}
Gura_DeclareMethod(list, runlength)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, runlength)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_RunLength(pIterator);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#align(n:number, value?):map {block?}
Gura_DeclareMethod(list, align)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, align)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_Align(pIterator, args.GetInt(0), args.GetValue(1));
	return ReturnIterator(env, sig, args, pIterator);
}

// list#skip(n:number):map {block?}
Gura_DeclareMethod(list, skip)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, skip)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_Skip(pIterator, static_cast<int>(args.GetSizeT(0)));
	return ReturnIterator(env, sig, args, pIterator);
}

// list#skipnil() {block?}
Gura_DeclareMethod(list, skipnil)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, skipnil)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_SkipInvalid(pIterator);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#roundoff(threshold:number => 1e-10) {block?}
Gura_DeclareMethod(list, roundoff)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, roundoff)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_RoundOff(pIterator, args.GetNumber(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// list#nilto(replace) {block?}
Gura_DeclareMethod(list, nilto)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "replace", VTYPE_any);
}

Gura_ImplementMethod(list, nilto)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_ReplaceInvalid(pIterator, args.GetValue(0));
	return ReturnIterator(env, sig, args, pIterator);
}

// list#replace(value, replace) {block?}
Gura_DeclareMethod(list, replace)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any);
	DeclareArg(env, "replace", VTYPE_any);
}

Gura_ImplementMethod(list, replace)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorEach(pObj);
	pIterator = new Iterator_Replace(pIterator,
								args.GetValue(0), args.GetValue(1));
	return ReturnIterator(env, sig, args, pIterator);
}

// list#head(n:number):map {block?}
Gura_DeclareMethod(list, head)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, head)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	int cnt = args.GetInt(0);
	Iterator *pIterator = new Object_list::IteratorEach(pObj, 0, cnt);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#tail(n:number):map {block?}
Gura_DeclareMethod(list, tail)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, tail)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	int cnt = args.GetInt(0);
	int cntMax = static_cast<int>(pObj->GetList().size());
	size_t offset = (cntMax > cnt)? cntMax - cnt : cntMax;
	Iterator *pIterator = new Object_list::IteratorEach(pObj, offset);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#reverse() {block?}
Gura_DeclareMethod(list, reverse)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, reverse)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorReverse(pObj);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#round(n?:number) {block?}
Gura_DeclareMethod(list, round)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(list, round)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	int cnt = args.Is_number(0)? args.GetInt(0) : -1;
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorRound(pObj, cnt);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#pingpong(n?:number):[sticky,sticky_l,sticky_r] {block?}
Gura_DeclareMethod(list, pingpong)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(sticky));
	DeclareAttr(Gura_Symbol(sticky_l));
	DeclareAttr(Gura_Symbol(sticky_r));
}

Gura_ImplementMethod(list, pingpong)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	int cnt = args.Is_number(0)? args.GetInt(0) : -1;
	bool stickyFlagL = args.IsSet(Gura_Symbol(sticky)) ||
						args.IsSet(Gura_Symbol(sticky_l));
	bool stickyFlagR = args.IsSet(Gura_Symbol(sticky)) ||
						args.IsSet(Gura_Symbol(sticky_r));
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator =
		new Object_list::IteratorPingpong(pObj, cnt, stickyFlagL, stickyFlagR);
	return ReturnIterator(env, sig, args, pIterator);
}

// list#fold(n:number, nstep?:number):[iteritem] {block?}
Gura_DeclareMethod(list, fold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "nstep", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(iteritem));
}

Gura_ImplementMethod(list, fold)
{
	Object_list *pThis = Object_list::GetThisObj(args);
	size_t cnt = args.GetSizeT(0);
	size_t cntStep = args.Is_number(1)? args.GetSizeT(1) : cnt;
	bool listItemFlag = !args.IsSet(Gura_Symbol(iteritem));
	Object_list *pObj = Object_list::Reference(pThis);
	Iterator *pIterator = new Object_list::IteratorFold(pObj, cnt, cntStep, listItemFlag);
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_list::Class_list(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_list)
{
}

void Class_list::Prepare(Environment &env)
{
	Gura_AssignFunction(list);
	Gura_AssignFunction(xlist);
	Gura_AssignFunctionEx(set_xset, "set");
	Gura_AssignFunctionEx(set_xset, "xset");
	Gura_AssignFunctionEx(ListInit, "@");
	Gura_AssignMethod(list, clear);
	Gura_AssignMethod(list, isempty);
	Gura_AssignMethod(list, shuffle);
	Gura_AssignMethod(list, add);
	Gura_AssignMethod(list, insert);
	Gura_AssignMethod(list, append);
	Gura_AssignMethod(list, shift);
	Gura_AssignMethod(list, erase);
	Gura_AssignMethod(list, get);
	Gura_AssignMethod(list, first);
	Gura_AssignMethod(list, last);
	Gura_AssignMethod(list, permutation);
	Gura_AssignMethod(list, combination);
	Gura_AssignMethod(list, flat);
	Gura_AssignMethod(list, printf);
	// common operations with iterator
	Gura_AssignMethod(list, len);
	Gura_AssignMethod(list, min);
	Gura_AssignMethod(list, max);
	Gura_AssignMethod(list, sum);
	Gura_AssignMethod(list, average);
	Gura_AssignMethod(list, variance);
	Gura_AssignMethod(list, stddev);
	Gura_AssignMethod(list, and_);
	Gura_AssignMethod(list, or_);
	Gura_AssignMethod(list, contains);
	Gura_AssignMethod(list, filter);
	Gura_AssignMethod(list, while_);
	Gura_AssignMethod(list, since);
	Gura_AssignMethod(list, after);
	Gura_AssignMethod(list, until);
	Gura_AssignMethod(list, before);
	Gura_AssignMethod(list, map);
	Gura_AssignMethod(list, reduce);
	Gura_AssignMethod(list, find);
	Gura_AssignMethod(list, count);
	Gura_AssignMethod(list, sort);
	Gura_AssignMethod(list, rank);
	Gura_AssignMethod(list, join);
	Gura_AssignMethod(list, format);
	Gura_AssignMethod(list, pack);
	Gura_AssignMethod(list, each);
	Gura_AssignMethod(list, offset);
	Gura_AssignMethod(list, runlength);
	Gura_AssignMethod(list, align);
	Gura_AssignMethod(list, skip);
	Gura_AssignMethod(list, skipnil);
	Gura_AssignMethod(list, roundoff);
	Gura_AssignMethod(list, nilto);
	Gura_AssignMethod(list, replace);
	Gura_AssignMethod(list, head);
	Gura_AssignMethod(list, tail);
	Gura_AssignMethod(list, reverse);
	Gura_AssignMethod(list, round);
	Gura_AssignMethod(list, pingpong);
	Gura_AssignMethod(list, fold);
}

bool Class_list::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsType(VTYPE_nil)) {
		value.InitAsList(env);
		return true;
	} else if (value.Is_iterator()) {
		AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
		if (sig.IsSignalled()) return false;
		Value result = pIterator->ToList(env, sig, true, false);
		if (sig.IsSignalled()) return false;
		value = result;
		return true;
	} else if (value.Is_matrix()) {
		const Object_matrix *pObjMat = Object_matrix::GetObject(value);
		if (pObjMat->GetMatrix()->GetRows() == 1) {
			Value result = pObjMat->GetMatrix()->GetRow(env, sig, 0);
			value = result;
		} else if (pObjMat->GetMatrix()->GetCols() == 1) {
			Value result = pObjMat->GetMatrix()->GetCol(env, sig, 0);
			value = result;
		}
		return true;
	}
	return false;
}

bool Class_list::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return value.GetList().Serialize(env, sig, stream);
}

bool Class_list::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	ValueList &valList = value.InitAsList(env);
	return valList.Deserialize(env, sig, stream);
}

Object *Class_list::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return (pClass == NULL)? new Object_list(env) : new Object_list(pClass);
}

}
