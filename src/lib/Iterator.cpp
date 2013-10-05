#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Iterator
//-----------------------------------------------------------------------------
Iterator::~Iterator()
{
	// virtual destructor
}

bool Iterator::IsSequence() const { return false; }
bool Iterator::IsSequenceInf() const { return false; }

Iterator *Iterator::_Clone()
{
	if (_pShare.get() == NULL) _pShare.reset(new Share());
	int id = _pShare->Register();
	return new Iterator_GenericClone(Reference(this), id);
}

Iterator *Iterator::Clone() const
{
	return const_cast<Iterator *>(this)->_Clone();
}

bool Iterator::NextShared(Environment &env, Signal sig, int id, Value &value)
{
	if (_pShare.get() == NULL) {
		for (;;) {
			if (!DoNext(env, sig, value)) return false;
			if (!IsSkipInvalid() || value.IsValid()) break;
		}
	} else if (_pShare->Next(id, value)) {
		// nothing to do
	} else if (_pShare->IsDone()) {
		return false;
	} else {
		for (;;) {
			if (!DoNext(env, sig, value)) {
				_pShare->SetDone();
				return false;
			}
			if (!IsSkipInvalid() || value.IsValid()) break;
		}
		_pShare->Store(id, value);
	}
	return true;
}

bool Iterator::Consume(Environment &env, Signal sig)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return false;
	}
	Value value;
	while (Next(env, sig, value)) ;
	return !sig.IsSignalled();
}

Value Iterator::ToList(Environment &env, Signal sig,
							bool alwaysListFlag, bool excludeNilFlag)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value result;
	ValueList *pValList = NULL;
	size_t cnt = 0;
	Value value;
	if (alwaysListFlag) {
		pValList = &result.InitAsList(env);
	}
	while (Next(env, sig, value)) {
		if (pValList == NULL && !value.IsUndefined()) {
			pValList = &result.InitAsList(env, cnt, Value::Null);
		}
		if (value.IsValid()) {
			if (pValList == NULL) {
				pValList = &result.InitAsList(env, cnt, Value::Null);
			}
			pValList->push_back(value);
		} else if (excludeNilFlag) {
			// nothing to do
		} else if (pValList != NULL) {
			pValList->push_back(value);
		}
		cnt++;
	}
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

Value Iterator::Eval(Environment &env, Signal sig, Args &args)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value value, result;
	Function::ResultComposer resultComposer(env, args, result);
	while (Next(env, sig, value)) {
		resultComposer.Store(value);
	}
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

Value Iterator::Eval(Environment &env, Signal sig,
								Args &args, const Function *pFuncBlock)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value value, result;
	std::auto_ptr<Function::ResultComposer> pResultComposer;
	if (args.IsRsltList() || args.IsRsltXList() ||
								args.IsRsltSet() || args.IsRsltXSet()) {
		pResultComposer.reset(new Function::ResultComposer(env, args, result));
	}
	bool contFlag = true;
	const DeclarationOwner &declOwner = pFuncBlock->GetDeclOwner();
	size_t nArgs = declOwner.size();
	if (declOwner.IsVariableLength()) {
		nArgs = 1;
		for (Iterator *pIterator = this; pIterator != NULL;
								nArgs++, pIterator = pIterator->GetSource()) ;
	}
	while (contFlag && Next(env, sig, value)) {
		AutoPtr<Args> pArgsSub(new Args());
		pArgsSub->ReserveValueListArg(nArgs);
		size_t iArg = 0;
		if (iArg++ < nArgs) pArgsSub->AddValue(value);
		for (Iterator *pIterator = this; iArg < nArgs && pIterator != NULL;
								iArg++, pIterator = pIterator->GetSource()) {
			pArgsSub->AddValue(Value(pIterator->GetCountNext() - 1));
		}
		Value resultElem = pFuncBlock->Eval(env, sig, *pArgsSub);
		if (!sig.IsSignalled()) {
			// nothing to do
		} else if (sig.IsBreak()) {
			resultElem = sig.GetValue();
			sig.ClearSignal();
			if (resultElem.IsInvalid()) break;
			contFlag = false;
		} else if (sig.IsContinue()) {
			resultElem = sig.GetValue();
			sig.ClearSignal();
			if (resultElem.IsInvalid()) continue;
		} else if (sig.IsReturn()) {
			return Value::Null;
		} else {
			return Value::Null;
		}
		if (pResultComposer.get() == NULL) {
			result = resultElem;
		} else {
			pResultComposer->Store(resultElem);
		}
	}
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

Value Iterator::Reduce(Environment &env, Signal sig,
							Value valueAccum, const Function *pFuncBlock)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value value;
	while (Next(env, sig, value)) {
		AutoPtr<Args> pArgsSub(new Args());
		pArgsSub->SetValues(value, valueAccum);
		Value result = pFuncBlock->Eval(env, sig, *pArgsSub);
		if (!sig.IsSignalled()) {
			// nothing to do
		} else if (sig.IsBreak()) {
			result = sig.GetValue();
			sig.ClearSignal();
			if (result.IsValid()) return result;
			return valueAccum;
		} else if (sig.IsContinue()) {
			result = sig.GetValue();
			sig.ClearSignal();
			if (result.IsInvalid()) continue;
		} else if (sig.IsReturn()) {
			return Value::Null;
		} else {
			return Value::Null;
		}
		valueAccum = result;
	}
	if (sig.IsSignalled()) return Value::Null;
	return valueAccum;
}

Value Iterator::MinMax(Environment &env, Signal sig,
									bool maxFlag, const SymbolSet &attrs)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value valueHit;
	if (!Next(env, sig, valueHit)) return Value::Null;
	Value result;
	if (attrs.IsSet(Gura_Symbol(index))) {
		int idxHit = GetCountNext() - 1;
		Value value;
		while (Next(env, sig, value)) {
			int cmp = Value::Compare(valueHit, value);
			if (maxFlag) cmp = -cmp;
			if (cmp > 0) {
				valueHit = value;
				idxHit = GetCountNext() - 1;
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		result.SetNumber(idxHit);
	} else if (attrs.IsSet(Gura_Symbol(last_index))) {
		int idxHit = GetCountNext() - 1;
		Value value;
		while (Next(env, sig, value)) {
			int cmp = Value::Compare(valueHit, value);
			if (maxFlag) cmp = -cmp;
			if (cmp >= 0) {
				valueHit = value;
				idxHit = GetCountNext() - 1;
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		result.SetNumber(idxHit);
	} else if (attrs.IsSet(Gura_Symbol(indices))) {
		int idxHit = GetCountNext() - 1;
		ValueList &resultList = result.InitAsList(env);
		resultList.push_back(Value(idxHit));
		Value value;
		while (Next(env, sig, value)) {
			int cmp = Value::Compare(valueHit, value);
			if (maxFlag) cmp = -cmp;
			if (cmp > 0) {
				int idxHit = GetCountNext() - 1;
				valueHit = value;
				resultList.clear();
				resultList.push_back(Value(idxHit));
			} else if (cmp == 0) {
				int idxHit = GetCountNext() - 1;
				resultList.push_back(Value(static_cast<Number>(idxHit)));
			}
		}
		if (sig.IsSignalled()) return Value::Null;
	} else {
		Value value;
		while (Next(env, sig, value)) {
			int cmp = Value::Compare(valueHit, value);
			if (maxFlag) cmp = -cmp;
			if (cmp > 0) {
				valueHit = value;
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		result = valueHit;
	}
	return result;
}

void Iterator::SetError_InvalidDataTypeOfElement(Signal sig)
{
	sig.SetError(ERR_ValueError, "invalid data type of element");
}

void Iterator::SetError_InfiniteNotAllowed(Signal sig)
{
	sig.SetError(ERR_IteratorError, "cannot evaluate infinite iterator");
}

Value Iterator::Sum(Environment &env, Signal sig, size_t &cnt)
{
	cnt = 0;
	Value value;
	if (!Next(env, sig, value)) return Value::Null;
	cnt++;
	if (value.IsNumber()) {
		Number result = value.GetNumber();
		while (Next(env, sig, value)) {
			cnt++;
			if (value.IsNumber()) {
				result += value.GetNumber();
			} else if (value.IsComplex()) {
				Complex resultEx = result;
				while (Next(env, sig, value)) {
					cnt++;
					if (value.IsNumberOrComplex()) {
						resultEx += value.GetComplex();
					} else {
						SetError_InvalidDataTypeOfElement(sig);
						return Value::Null;
					}
				}
				if (sig.IsSignalled()) return Value::Null;
				return Value(resultEx);
			} else {
				SetError_InvalidDataTypeOfElement(sig);
				return Value::Null;
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		return Value(result);
	} else if (value.IsComplex()) {
		Complex result = value.GetComplex();
		while (Next(env, sig, value)) {
			cnt++;
			if (value.IsNumberOrComplex()) {
				result += value.GetComplex();
			} else {
				SetError_InvalidDataTypeOfElement(sig);
				return Value::Null;
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		return Value(result);
	} else {
		SetError_InvalidDataTypeOfElement(sig);
		return Value::Null;
	}
}

Value Iterator::Average(Environment &env, Signal sig, size_t &cnt)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value valueSum = Clone()->Sum(env, sig, cnt);
	if (valueSum.IsNumber()) {
		return Value(valueSum.GetNumber() / static_cast<Number>(cnt));
	} else if (valueSum.IsComplex()) {
		return Value(valueSum.GetComplex() / static_cast<Number>(cnt));
	} else {
		return Value::Null;
	}
}

Value Iterator::Variance(Environment &env, Signal sig, size_t &cnt)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	// this doesn't use a variance calculation formula V(x) = E(x**2) - E(x)**2
	// to minimize calculation error.
	Value valueAve = Clone()->Average(env, sig, cnt);
	if (!valueAve.IsNumberOrComplex()) return Value::Null;
	Value value;
	if (!Next(env, sig, value)) return Value::Null;
	if (value.IsNumber() && valueAve.IsNumber()) {
		Number result;
		Number average = valueAve.GetNumber();
		do {
			Number tmp = value.GetNumber() - average;
			result = tmp * tmp;
		} while (0);
		while (Next(env, sig, value)) {
			if (value.IsNumber()) {
				Number tmp = value.GetNumber() - average;
				result += tmp * tmp;
			} else if (value.IsComplex()) {
				while (Next(env, sig, value)) {
					if (value.IsNumberOrComplex()) {
						Complex tmp = value.GetComplex() - average;
						result += std::norm(tmp);
					} else {
						SetError_InvalidDataTypeOfElement(sig);
						return Value::Null;
					}
				}
			} else {
				SetError_InvalidDataTypeOfElement(sig);
				return Value::Null;
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		return Value(result / static_cast<Number>(cnt));
	} else if (value.IsNumberOrComplex()) {
		Number result;
		Complex average = valueAve.GetComplex();
		do {
			Complex tmp = value.GetComplex() - average;
			result = std::norm(tmp);
		} while (0);
		while (Next(env, sig, value)) {
			if (value.IsNumberOrComplex()) {
				Complex tmp = value.GetComplex() - average;
				result += std::norm(tmp);
			} else {
				SetError_InvalidDataTypeOfElement(sig);
				return Value::Null;
			}
		}
		if (sig.IsSignalled()) return Value::Null;
		return Value(result / static_cast<Number>(cnt));
	} else {
		SetError_InvalidDataTypeOfElement(sig);
		return Value::Null;
	}
}

Value Iterator::StandardDeviation(Environment &env, Signal sig, size_t &cnt)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value valueVar = Clone()->Variance(env, sig, cnt);
	if (!valueVar.IsNumber()) return Value::Null;
	return Value(::sqrt(valueVar.GetNumber()));
}

Value Iterator::And(Environment &env, Signal sig)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value value;
	if (!Next(env, sig, value)) return Value::Null;
	if (!value.GetBoolean()) return Value(false);
	while (Next(env, sig, value)) {
		if (!value.GetBoolean()) return Value(false);
	}
	if (sig.IsSignalled()) return Value::Null;
	return Value(true);
}

Value Iterator::Or(Environment &env, Signal sig)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return Value::Null;
	}
	Value value;
	if (!Next(env, sig, value)) return Value::Null;
	if (value.GetBoolean()) return Value(true);
	while (Next(env, sig, value)) {
		if (value.GetBoolean()) return Value(true);
	}
	if (sig.IsSignalled()) return Value::Null;
	return Value(false);
}

size_t Iterator::Find(Environment &env, Signal sig, const Value &criteria, Value &value)
{
	if (criteria.IsFunction()) {
		if (IsInfinite()) {
			SetError_InfiniteNotAllowed(sig);
			return InvalidSize;
		}
		const Function *pFunc = criteria.GetFunction();
		while (Next(env, sig, value)) {
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValue(value);
			Value valueFlag = pFunc->Eval(env, sig, *pArgs);
			if (sig.IsSignalled()) return InvalidSize;
			if (valueFlag.GetBoolean()) return GetCountNext() - 1;
		}
		if (sig.IsSignalled()) return InvalidSize;
	} else if (criteria.IsList() || criteria.IsIterator()) {
		AutoPtr<Iterator> pIteratorCriteria(criteria.CreateIterator(sig));
		if (sig.IsSignalled()) return InvalidSize;
		if (IsInfinite() && pIteratorCriteria->IsInfinite()) {
			SetError_InfiniteNotAllowed(sig);
			return InvalidSize;
		}
		while (Next(env, sig, value)) {
			Value valueCriteria;
			if (!pIteratorCriteria->Next(env, sig, valueCriteria)) break;
			if (valueCriteria.GetBoolean()) return GetCountNext() - 1;
		}
		return InvalidSize;
	} else {
		while (Next(env, sig, value)) {
			if (Value::Compare(value, criteria) == 0) return GetCountNext() - 1;
		}
	}
	return InvalidSize;
}

size_t Iterator::FindTrue(Environment &env, Signal sig, Value &value)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return 0;
	}
	while (Next(env, sig, value)) {
		if (value.GetBoolean()) return GetCountNext() - 1;
	}
	return InvalidSize;
}

size_t Iterator::Count(Environment &env, Signal sig, const Value &criteria)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return 0;
	}
	size_t cnt = 0;
	if (criteria.IsFunction()) {
		const Function *pFunc = criteria.GetFunction();
		Value value;
		while (Next(env, sig, value)) {
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValue(value);
			Value valueFlag = pFunc->Eval(env, sig, *pArgs);
			if (sig.IsSignalled()) return 0;
			if (valueFlag.GetBoolean()) cnt++;
		}
		if (sig.IsSignalled()) return 0;
	} else {
		Value value;
		while (Next(env, sig, value)) {
			if (Value::Compare(value, criteria) == 0) cnt++;
		}
	}
	return cnt;
}

size_t Iterator::CountTrue(Environment &env, Signal sig)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return 0;
	}
	size_t cnt = 0;
	Value value;
	while (Next(env, sig, value)) {
		if (value.GetBoolean()) cnt++;
	}
	return cnt;
}

Iterator *Iterator::Filter(Environment &env, Signal sig, const Value &criteria)
{
	if (criteria.IsFunction()) {
		Object_function *pFuncObjCriteria =
			Object_function::Reference(Object_function::GetObject(criteria));
		return new Iterator_FilterWithFunc(new Environment(env), this, pFuncObjCriteria);
	} else if (criteria.IsList() || criteria.IsIterator()) {
		Iterator *pIteratorCriteria = criteria.CreateIterator(sig);
		if (sig.IsSignalled()) return NULL;
		return new Iterator_FilterWithIter(this, pIteratorCriteria);
	} else {
		sig.SetError(ERR_ValueError, "invalid type of criteria for filter");
		return NULL;
	}
}

Iterator *Iterator::While(Environment &env, Signal sig, const Value &criteria)
{
	if (criteria.IsFunction()) {
		Object_function *pFuncObjCriteria = 
			Object_function::Reference(Object_function::GetObject(criteria));
		return new Iterator_WhileWithFunc(new Environment(env), this, pFuncObjCriteria);
	} else if (criteria.IsList() || criteria.IsIterator()) {
		Iterator *pIteratorCriteria = criteria.CreateIterator(sig);
		if (sig.IsSignalled()) return NULL;
		return new Iterator_WhileWithIter(this, pIteratorCriteria);
	} else {
		sig.SetError(ERR_ValueError, "invalid type of criteria for while");
		return NULL;
	}
}

Iterator *Iterator::Since(Environment &env, Signal sig,
									const Value &criteria, bool containFirstFlag)
{
	if (criteria.IsFunction()) {
		Object_function *pFuncObjCriteria = 
			Object_function::Reference(Object_function::GetObject(criteria));
		return new Iterator_SinceWithFunc(new Environment(env), this, pFuncObjCriteria, containFirstFlag);
	} else if (criteria.IsList() || criteria.IsIterator()) {
		Iterator *pIteratorCriteria = criteria.CreateIterator(sig);
		if (sig.IsSignalled()) return NULL;
		return new Iterator_SinceWithIter(this, pIteratorCriteria, containFirstFlag);
	} else {
		sig.SetError(ERR_ValueError, "invalid type of criteria for since");
		return NULL;
	}
}

Iterator *Iterator::Until(Environment &env, Signal sig,
									const Value &criteria, bool containLastFlag)
{
	if (criteria.IsFunction()) {
		Object_function *pFuncObjCriteria = 
			Object_function::Reference(Object_function::GetObject(criteria));
		return new Iterator_UntilWithFunc(new Environment(env), this, pFuncObjCriteria, containLastFlag);
	} else if (criteria.IsList() || criteria.IsIterator()) {
		Iterator *pIteratorCriteria = criteria.CreateIterator(sig);
		if (sig.IsSignalled()) return NULL;
		return new Iterator_UntilWithIter(this, pIteratorCriteria, containLastFlag);
	} else {
		sig.SetError(ERR_ValueError, "invalid type of criteria for since");
		return NULL;
	}
}

bool Iterator::IsContain(Environment &env, Signal sig, const Value &value)
{
	if (IsInfinite()) {
		SetError_InfiniteNotAllowed(sig);
		return false;
	}
	Value valueToFind;
	while (Next(env, sig, valueToFind)) {
		if (Value::Compare(value, valueToFind) == 0) return true;
	}
	return false;
}

String Iterator::ToString(Signal sig) const
{
	return String("<iterator>");
}

bool Iterator::PrepareRepeaterIterators(Environment &env, Signal sig,
						const ValueList &valListArg, ExprList &exprLeftList,
						IteratorOwner &iteratorOwner)
{
	foreach_const (ValueList, pValue, valListArg) {
		GURA_ASSUME(env, pValue->IsExpr());
		const Expr *pExpr = pValue->GetExpr();
		Value value;
		if (!(pExpr->IsBinaryOp() && dynamic_cast<const Expr_BinaryOp *>(pExpr)->
										GetOperator()->GetOpType() == OPTYPE_Contains)) {
			sig.SetError(ERR_TypeError, "iteratable must be specified as arguments");
			return false;
		}
		const Expr_BinaryOp *pExprBin =
						dynamic_cast<const Expr_BinaryOp *>(pExpr);
		value = pExprBin->GetRight()->Exec(env, sig);
		if (sig.IsSignalled()) return false;
		Iterator *pIterator = value.CreateIterator(sig);
		if (pIterator == NULL) return false;
		exprLeftList.push_back(const_cast<Expr *>(pExprBin->GetLeft()));
		iteratorOwner.push_back(pIterator);
	}
	return true;
}

//-----------------------------------------------------------------------------
// Iterator::Share
//-----------------------------------------------------------------------------
Iterator::Share::Share() : _doneFlag(false), _indexMin(0)
{
	_indexList.push_back(_indexMin);
}

int Iterator::Share::Register()
{
	int id = static_cast<int>(_indexList.size());
	_indexList.push_back(_indexMin);
	return id;
}

bool Iterator::Share::Next(int id, Value &value)
{
	size_t iElem = _indexList[id] - _indexMin;
	if (iElem >= _valueDeque.size()) return false;
	value = _valueDeque[iElem];
	_indexList[id] = static_cast<UInt>(_indexMin + iElem + 1);
	size_t indexMinCur = _indexMin;
	foreach (IndexList, pIndex, _indexList) {
		if (indexMinCur > *pIndex) indexMinCur = *pIndex;
	}
	for (size_t cnt = indexMinCur - _indexMin; cnt > 0; cnt--) {
		_valueDeque.pop_front();
	}
	_indexMin = indexMinCur;
	return true;
}

void Iterator::Share::Store(int id, const Value &value)
{
	_valueDeque.push_back(value);
	_indexList[id] = static_cast<UInt>(_indexMin + _valueDeque.size());
}

//-----------------------------------------------------------------------------
// Iterator_GenericClone
//-----------------------------------------------------------------------------
Iterator *Iterator_GenericClone::GetSource()
{
	return _pIterator.get();
}

bool Iterator_GenericClone::DoNext(Environment &env, Signal sig, Value &value)
{
	return _pIterator->NextShared(env, sig, _id, value);
}

String Iterator_GenericClone::ToString(Signal sig) const
{
	return _pIterator->ToString(sig);
}

void Iterator_GenericClone::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Constant
//-----------------------------------------------------------------------------
Iterator *Iterator_Constant::Clone() const
{
	return new Iterator_Constant(*this);
}

Iterator *Iterator_Constant::GetSource()
{
	return NULL;
}

bool Iterator_Constant::DoNext(Environment &env, Signal sig, Value &value)
{
	value = _value;
	return true;
}

String Iterator_Constant::ToString(Signal sig) const
{
	String rtn = "<iterator:constant:";
	rtn += _value.ToString(sig, true);
	rtn += ">";
	return rtn;
}

void Iterator_Constant::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_ConstantN
//-----------------------------------------------------------------------------
Iterator *Iterator_ConstantN::Clone() const
{
	return new Iterator_ConstantN(*this);
}

Iterator *Iterator_ConstantN::GetSource()
{
	return NULL;
}

bool Iterator_ConstantN::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idx >= _cnt) return false;
	if (_cnt > 0) _idx++;
	value = _value;
	return true;
}

String Iterator_ConstantN::ToString(Signal sig) const
{
	String rtn = "<iterator:constant:";
	rtn += NumberToString(_cnt);
	rtn += ":";
	rtn += _value.ToString(sig, true);
	rtn += ")>";
	return rtn;
}

void Iterator_ConstantN::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_OneShot
//-----------------------------------------------------------------------------
Iterator *Iterator_OneShot::Clone() const
{
	return new Iterator_OneShot(*this);
}

Iterator *Iterator_OneShot::GetSource()
{
	return NULL;
}

bool Iterator_OneShot::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) return false;
	value = _value;
	_doneFlag = true;
	return true;
}

String Iterator_OneShot::ToString(Signal sig) const
{
	String rtn = "<iterator:oneshot:";
	rtn += _value.ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_OneShot::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_Rand
//-----------------------------------------------------------------------------
Iterator *Iterator_Rand::GetSource()
{
	return NULL;
}

bool Iterator_Rand::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_cnt >= 0) {
		if (_idx >= _cnt) return false;
		_idx++;
	}
	value = Value((_range > 0)?
		static_cast<Number>(static_cast<int>(RandomGenerator::Real2() * _range)) :
		static_cast<Number>(RandomGenerator::Real2()));
	return true;
}

String Iterator_Rand::ToString(Signal sig) const
{
	String rtn = "<iterator:rands:";
	if (_range > 0) {
		rtn += NumberToString(_range);
	} else {
		rtn += "(floating)";
	}
	rtn += ":";
	if (_cnt >= 0) {
		rtn += NumberToString(_cnt);
	} else {
		rtn += "infinite";
	}
	rtn += ")>";
	return rtn;
}

void Iterator_Rand::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_Range
//-----------------------------------------------------------------------------
Iterator *Iterator_Range::Clone() const
{
	return new Iterator_Range(*this);
}

Iterator *Iterator_Range::GetSource()
{
	return NULL;
}

bool Iterator_Range::DoNext(Environment &env, Signal sig, Value &value)
{
	if (!((_numStep > 0)? (_num < _numEnd) : (_num > _numEnd))) return false;
	value = Value(_num);
	_num += _numStep;
	return true;
}

String Iterator_Range::ToString(Signal sig) const
{
	String rtn;
	if (_numStep == 1 || _numStep == -1) {
		if (_numBegin == 0) {
			rtn = "<iterator:range(";
			rtn += NumberToString(_numEnd);
			rtn += ")>";
		} else {
			rtn = "<iterator:range(";
			rtn += NumberToString(_numBegin);
			rtn += ", ";
			rtn += NumberToString(_numEnd);
			rtn += ")>";
		}
	} else {
		rtn = "<iterator:range(";
		rtn += NumberToString(_numBegin);
		rtn += ", ";
		rtn += NumberToString(_numEnd);
		rtn += ", ";
		rtn += NumberToString(_numStep);
		rtn += ")>";
	}
	return rtn;
}

void Iterator_Range::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_Sequence
//-----------------------------------------------------------------------------
bool Iterator_Sequence::IsSequence() const { return true; }

Iterator *Iterator_Sequence::Clone() const
{
	return new Iterator_Sequence(*this);
}

Iterator *Iterator_Sequence::GetSource()
{
	return NULL;
}

bool Iterator_Sequence::DoNext(Environment &env, Signal sig, Value &value)
{
	if (!((_numStep > 0)? (_num <= _numEnd) : (_num >= _numEnd))) return false;
	value = Value(_num);
	_num += _numStep;
	return true;
}

String Iterator_Sequence::ToString(Signal sig) const
{
	String rtn;
	if (_numStep == 1. || _numStep == -1.) {
		rtn = "<iterator:";
		rtn += NumberToString(_numBegin);
		rtn += "..";
		rtn += NumberToString(_numEnd);
		rtn += ">";
	} else {
		rtn = "<iterator:seq(";
		rtn += NumberToString(_numBegin);
		rtn += ", ";
		rtn += NumberToString(_numEnd);
		rtn += ", ";
		rtn += NumberToString(_numStep);
		rtn += ")>";
	}
	return rtn;
}

void Iterator_Sequence::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_SequenceInf
//-----------------------------------------------------------------------------
bool Iterator_SequenceInf::IsSequenceInf() const { return true; }

Iterator *Iterator_SequenceInf::Clone() const
{
	return new Iterator_SequenceInf(*this);
}

Iterator *Iterator_SequenceInf::GetSource()
{
	return NULL;
}

bool Iterator_SequenceInf::DoNext(Environment &env, Signal sig, Value &value)
{
	value = Value(_num);
	_num += 1;
	return true;
}

String Iterator_SequenceInf::ToString(Signal sig) const
{
	String rtn;
	rtn = "<iterator:";
	rtn += NumberToString(_numBegin);
	rtn += "..>";
	return rtn;
}

void Iterator_SequenceInf::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_Interval
//-----------------------------------------------------------------------------
Iterator *Iterator_Interval::Clone() const
{
	return new Iterator_Interval(*this);
}

Iterator *Iterator_Interval::GetSource()
{
	return NULL;
}

bool Iterator_Interval::DoNext(Environment &env, Signal sig, Value &value)
{
	Number num;
	if (!_DoNext(num)) return false;
	value = Value(num);
	return true;
}

String Iterator_Interval::ToString(Signal sig) const
{
	String str;
	str = "<iterator:interval(";
	str += NumberToString(_numBegin);
	str += ",";
	str += NumberToString(_numEnd);
	str += ",";
	str += NumberToString(_numSamples);
	str += ")>";
	return str;
}

void Iterator_Interval::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

#if 0
//-----------------------------------------------------------------------------
// Iterator_Fork
//-----------------------------------------------------------------------------
Iterator_Fork::Iterator_Fork(Environment *pEnv, Signal sig,
		Function *pFunc, const Value &valueThis, const ValueList &valListArg) :
	Iterator(false), _pEnv(pEnv), _pFunc(pFunc), _valueThis(valueThis), _doneFlag(false)
{
	_iterOwner.PrepareForMap(sig, pFunc->GetDeclOwner(), valListArg);
	_pValListToWrite = &_valListA;
	_pValListToRead = &_valListB;
	_pValueRead = _pValListToRead->begin();
	_readBlock.blockedFlag = false;
	_writeBlock.blockedFlag = false;
}

Iterator *Iterator_Fork::GetSource()
{
	return NULL;
}

bool Iterator_Fork::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pValueRead == _pValListToRead->end()) {
		for (;;) {
			SwapList();
			if (_pValueRead != _pValListToRead->end()) {
				break;
			} else if (_doneFlag) {
				return false;
			} else {
				_readBlock.blockedFlag = true;
				_readBlock.event.Wait();
			}
		}
	}
	value = *_pValueRead++;
	return true;
}

String Iterator_Fork::ToString(Signal sig) const
{
	return String("<iterator:fork>");
}

void Iterator_Fork::SwapList()
{
	_semaphore.Wait();
	ValueList *pValList = _pValListToWrite;
	_pValListToWrite = _pValListToRead;
	_pValListToRead = pValList;
	_pValListToWrite->clear();
	_pValueRead = _pValListToRead->begin();
	if (_writeBlock.blockedFlag) {
		_writeBlock.blockedFlag = false;
		_writeBlock.event.Notify();
	}
	_semaphore.Release();
}

void Iterator_Fork::ForkProcess()
{
	Clone();
	Start();
}

void Iterator_Fork::Run()
{
	Signal sig;
	ValueList valList;
	while (_iterOwner.Next(env, sig, valList)) {
		AutoPtr<Args> pArgs(new Args(valList));
		pArgs->SetThis(_valueThis);
		Value value = _pFunc->Eval(*_pEnv, sig, *pArgs);
		if (sig.IsSignalled()) break;
		_semaphore.Wait();
		_pValListToWrite->push_back(value);
		_semaphore.Release();
		if (_readBlock.blockedFlag) {
			_readBlock.blockedFlag = false;
			_readBlock.event.Notify();
		}
	}
	_doneFlag = true;
}
#endif

//-----------------------------------------------------------------------------
// Iterator_ExplicitMap
//-----------------------------------------------------------------------------
Iterator_ExplicitMap::Iterator_ExplicitMap(Environment *pEnv, Signal sig,
							Iterator *pIterator, Object_function *pObjFunc) :
		Iterator(pIterator->IsInfinite()), _pEnv(pEnv), _sig(sig),
		_pIterator(pIterator), _pObjFunc(pObjFunc)
{
}

Iterator_ExplicitMap::Iterator_ExplicitMap(const Iterator_ExplicitMap &iter) :
		Iterator(iter), _pEnv(iter._pEnv->Reference()), _pIterator(iter._pIterator->Clone()),
		_pObjFunc(Object_function::Reference(iter._pObjFunc.get()))
{
}

Iterator_ExplicitMap::~Iterator_ExplicitMap()
{
	if (IsVirgin()) Consume(*_pEnv, _sig);
}

Iterator *Iterator_ExplicitMap::Clone() const
{
	return new Iterator_ExplicitMap(*this);
}

Iterator *Iterator_ExplicitMap::GetSource()
{
	return _pIterator.get();
}

bool Iterator_ExplicitMap::DoNext(Environment &env, Signal sig, Value &value)
{
	if (!_pIterator->Next(env, sig, value)) return false;
	ValueList valList(value);
	value = _pObjFunc->Eval(*_pEnv, sig, valList);
	return true;
}

String Iterator_ExplicitMap::ToString(Signal sig) const
{
	return String("<iterator:explicit_map>");
}

void Iterator_ExplicitMap::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
	}
}

//-----------------------------------------------------------------------------
// Iterator_ImplicitMap
//-----------------------------------------------------------------------------
Iterator_ImplicitMap::Iterator_ImplicitMap(Environment *pEnv, Signal sig,
						Function *pFunc, Args *pArgs, bool skipInvalidFlag) :
	Iterator(false, skipInvalidFlag), _pEnv(pEnv), _sig(sig),
	_pFunc(pFunc), _pArgs(pArgs), _doneThisFlag(false)
{
	_iterOwner.PrepareForMap(sig, pFunc->GetDeclOwner(), pArgs->GetValueListArg());
	if (sig.IsSignalled()) return;
	Iterator *pIteratorThis = _pArgs->GetIteratorThis();
	SetInfiniteFlag(_iterOwner.IsInfinite() &&
				(pIteratorThis == NULL || pIteratorThis->IsInfinite()));
}

Iterator_ImplicitMap::~Iterator_ImplicitMap()
{
	if (IsVirgin()) Consume(*_pEnv, _sig);
}

Iterator *Iterator_ImplicitMap::GetSource()
{
	return _pArgs->GetIteratorThis();
}

bool Iterator_ImplicitMap::DoNext(Environment &env, Signal sig, Value &value)
{
	ValueList valList;
	if (_doneThisFlag || !_iterOwner.Next(env, sig, valList)) return false;
	AutoPtr<Args> pArgsEach(new Args(*_pArgs, valList));
	value = _pFunc->Eval(*_pEnv, sig, *pArgsEach);
	if (sig.IsSignalled()) return false;
	Iterator *pIteratorThis = _pArgs->GetIteratorThis();
	if (pIteratorThis != NULL) {
		Value valueThis;
		_doneThisFlag = !pIteratorThis->Next(env, sig, valueThis);
		if (sig.IsSignalled()) return false;
		_pArgs->SetThis(valueThis);
	}
	return true;
}

String Iterator_ImplicitMap::ToString(Signal sig) const
{
	String str;
	str += "<iterator:implicit_map:";
	str += _pFunc->ToString();
	str += ">";
	return str;
}

void Iterator_ImplicitMap::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		Iterator *pIteratorThis = _pArgs->GetIteratorThis();
		if (pIteratorThis != NULL) {
			pIteratorThis->GatherFollower(pFrame, envSet);
		}
		_pFunc->GatherFollower(pFrame, envSet);
		_iterOwner.GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_UnaryOperatorMap
//-----------------------------------------------------------------------------
Iterator_UnaryOperatorMap::Iterator_UnaryOperatorMap(Environment *pEnv, Signal sig,
								const Operator *pOperator, const Value &value) :
	Iterator(false), _pEnv(pEnv), _sig(sig), _pOperator(pOperator)
{
	if (value.IsListOrIterator()) {
		_pIterator.reset(value.CreateIterator(sig));
		if (_pIterator.IsNull()) return;
	} else {
		_pIterator.reset(new Iterator_Constant(value));
	}
	SetInfiniteFlag(_pIterator->IsInfinite());
}

Iterator_UnaryOperatorMap::~Iterator_UnaryOperatorMap()
{
	if (IsVirgin()) Consume(*_pEnv, _sig);
}

Iterator *Iterator_UnaryOperatorMap::GetSource()
{
	return NULL;
}

bool Iterator_UnaryOperatorMap::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueArg;
	if (!_pIterator->Next(env, sig, valueArg)) return false;
	value = _pOperator->EvalUnary(*_pEnv, sig, valueArg);
	if (sig.IsSignalled()) return false;
	return true;
}

String Iterator_UnaryOperatorMap::ToString(Signal sig) const
{
	String str;
	str += "<iterator:unary_operator_map:";
	str += ">";
	return str;
}

void Iterator_UnaryOperatorMap::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_BinaryOperatorMap
//-----------------------------------------------------------------------------
Iterator_BinaryOperatorMap::Iterator_BinaryOperatorMap(Environment *pEnv, Signal sig,
		const Operator *pOperator, const Value &valueLeft, const Value &valueRight) :
	Iterator(false), _pEnv(pEnv), _sig(sig), _pOperator(pOperator)
{
	if (valueLeft.IsListOrIterator()) {
		_pIteratorLeft.reset(valueLeft.CreateIterator(sig));
		if (_pIteratorLeft.IsNull()) return;
	} else {
		_pIteratorLeft.reset(new Iterator_Constant(valueLeft));
	}
	if (valueRight.IsListOrIterator()) {
		_pIteratorRight.reset(valueRight.CreateIterator(sig));
		if (_pIteratorRight.IsNull()) return;
	} else {
		_pIteratorRight.reset(new Iterator_Constant(valueRight));
	}
	SetInfiniteFlag(_pIteratorLeft->IsInfinite() && _pIteratorRight->IsInfinite());
}

Iterator_BinaryOperatorMap::~Iterator_BinaryOperatorMap()
{
	if (IsVirgin()) Consume(*_pEnv, _sig);
}

Iterator *Iterator_BinaryOperatorMap::GetSource()
{
	return NULL;
}

bool Iterator_BinaryOperatorMap::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueLeft, valueRight;
	if (!_pIteratorLeft->Next(env, sig, valueLeft) ||
			!_pIteratorRight->Next(env, sig, valueRight)) return false;
	value = _pOperator->EvalBinary(*_pEnv, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return false;
	return true;
}

String Iterator_BinaryOperatorMap::ToString(Signal sig) const
{
	String str;
	str += "<iterator:binary_operator_map:";
	str += ">";
	return str;
}

void Iterator_BinaryOperatorMap::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pIteratorLeft->GatherFollower(pFrame, envSet);
		_pIteratorRight->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_MemberMap
//-----------------------------------------------------------------------------
Iterator_MemberMap::Iterator_MemberMap(Environment *pEnv, Signal sig, Iterator *pIterator, Expr *pExpr) :
		Iterator(pIterator->IsInfinite()), _pEnv(pEnv), _sig(sig), _pIterator(pIterator), _pExpr(pExpr)
{
}

Iterator_MemberMap::~Iterator_MemberMap()
{
	if (IsVirgin()) Consume(*_pEnv, _sig);
}

Iterator *Iterator_MemberMap::GetSource()
{
	return _pIterator.get();
}

bool Iterator_MemberMap::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueThisEach;
	if (!_pIterator->Next(env, sig, valueThisEach)) return false;
	Fundamental *pFundEach = valueThisEach.ExtractFundamental(sig);
	if (sig.IsSignalled()) return false;
	Environment &envEach = *pFundEach;
	value = _pExpr->Exec(envEach, sig);
	if (value.IsFunction()) {
		Object_function *pObj = new Object_function(envEach,
						Function::Reference(value.GetFunction()), valueThisEach);
		value = Value(pObj);
	}
	return true;
}

String Iterator_MemberMap::ToString(Signal sig) const
{
	return String("<iterator:member_map>");
}

void Iterator_MemberMap::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_MethodMap
//-----------------------------------------------------------------------------
Iterator_MethodMap::Iterator_MethodMap(Environment *pEnv, Signal sig, Iterator *pIteratorThis, Expr_Caller *pExprCaller) :
		Iterator(pIteratorThis->IsInfinite()), _pEnv(pEnv), _sig(sig),
		_pIteratorThis(pIteratorThis), _pExprCaller(pExprCaller)
{
}

Iterator_MethodMap::~Iterator_MethodMap()
{
	if (IsVirgin()) Consume(*_pEnv, _sig);
}

Iterator *Iterator_MethodMap::GetSource()
{
	return _pIteratorThis.get();
}

bool Iterator_MethodMap::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueThis;
	if (!_pIteratorThis->Next(env, sig, valueThis)) return false;
	value = _pExprCaller->EvalEach(*_pEnv, sig, valueThis, NULL, false, NULL);
	return true;
}

String Iterator_MethodMap::ToString(Signal sig) const
{
	return String("<iterator:method_map>");
}

void Iterator_MethodMap::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pIteratorThis->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_FuncBinder
//-----------------------------------------------------------------------------
Iterator_FuncBinder::Iterator_FuncBinder(Environment *pEnv,
				Function *pFunc, const Value &valueThis, Iterator *pIterator) :
		Iterator(false), _pEnv(pEnv), _pFunc(pFunc),
		_valueThis(valueThis), _pIterator(pIterator)
{
}

Iterator *Iterator_FuncBinder::GetSource()
{
	return _pIterator.get();
}

bool Iterator_FuncBinder::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueArg;
	if (!_pIterator->Next(env, sig, valueArg)) return false;
	if (valueArg.IsList()) {
		ValueList valListComp = valueArg.GetList();
		if (!_pFunc->GetDeclOwner().Compensate(*_pEnv, sig, valListComp)) {
			return false;
		}
		AutoPtr<Args> pArgs(new Args(valListComp));
		pArgs->SetThis(_valueThis);
		value = _pFunc->Eval(*_pEnv, sig, *pArgs);
		if (sig.IsSignalled()) return false;
	} else {
		ValueList valListComp(valueArg);
		if (!_pFunc->GetDeclOwner().Compensate(*_pEnv, sig, valListComp)) {
			return false;
		}
		AutoPtr<Args> pArgs(new Args(valListComp));
		pArgs->SetThis(_valueThis);
		value = _pFunc->Eval(*_pEnv, sig, *pArgs);
		if (sig.IsSignalled()) return false;
		//sig.SetError(ERR_TypeError, "invalid structure of arguments");
		//return false;
	}
	return true;
}

String Iterator_FuncBinder::ToString(Signal sig) const
{
	String str;
	str += "<iterator:func_binder:";
	str += _pFunc->ToString();
	str += ">";
	return str;
}

void Iterator_FuncBinder::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFunc->GatherFollower(pFrame, envSet);
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Delay
//-----------------------------------------------------------------------------
Iterator *Iterator_Delay::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Delay::DoNext(Environment &env, Signal sig, Value &value)
{
	OAL::Sleep(_delay);
	return _pIterator->Next(env, sig, value);
}

String Iterator_Delay::ToString(Signal sig) const
{
	return String("<iterator:delay>");
}

void Iterator_Delay::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Skip
//-----------------------------------------------------------------------------
Iterator *Iterator_Skip::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Skip::DoNext(Environment &env, Signal sig, Value &value)
{
	bool flag = _pIterator->Next(env, sig, value);
	for (int i = 0; i < _nSkip; i++) {
		Value valueTmp;
		if (!_pIterator->Next(env, sig, valueTmp)) break;
	}
	return flag;
}

String Iterator_Skip::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:skip:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_Skip::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_SkipInvalid
//-----------------------------------------------------------------------------
Iterator *Iterator_SkipInvalid::GetSource()
{
	return _pIterator.get();
}

bool Iterator_SkipInvalid::DoNext(Environment &env, Signal sig, Value &value)
{
	while (_pIterator->Next(env, sig, value)) {
		if (value.IsValid()) return true;
	}
	return false;
}

String Iterator_SkipInvalid::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:skip_invalid:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_SkipInvalid::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_SkipFalse
//-----------------------------------------------------------------------------
Iterator *Iterator_SkipFalse::GetSource()
{
	return _pIterator.get();
}

bool Iterator_SkipFalse::DoNext(Environment &env, Signal sig, Value &value)
{
	while (_pIterator->Next(env, sig, value)) {
		if (value.GetBoolean()) return true;
	}
	return false;
}

String Iterator_SkipFalse::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:skip_false:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_SkipFalse::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_RoundOff
//-----------------------------------------------------------------------------
Iterator *Iterator_RoundOff::GetSource()
{
	return _pIterator.get();
}

bool Iterator_RoundOff::DoNext(Environment &env, Signal sig, Value &value)
{
	if (!_pIterator->Next(env, sig, value)) return false;
	if (value.IsNumber()) {
		Number num = value.GetNumber();
		if (num < _threshold) value = Value(0);
	}
	return true;
}

String Iterator_RoundOff::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:roundoff:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_RoundOff::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_FilterWithFunc
//-----------------------------------------------------------------------------
Iterator_FilterWithFunc::Iterator_FilterWithFunc(Environment *pEnv,
							Iterator *pIterator, Object_function *pObjFunc) :
			Iterator(pIterator->IsInfinite()), _pEnv(pEnv),
			_pIterator(pIterator), _pObjFunc(pObjFunc)
{
}

Iterator *Iterator_FilterWithFunc::GetSource()
{
	return _pIterator.get();
}

bool Iterator_FilterWithFunc::DoNext(Environment &env, Signal sig, Value &value)
{
	while (_pIterator->Next(env, sig, value)) {
		ValueList valList(value);
		Value valueCriteria = _pObjFunc->Eval(*_pEnv, sig, valList);
		if (sig.IsSignalled()) return false;
		if (valueCriteria.GetBoolean()) return true;
	}
	return false;
}

String Iterator_FilterWithFunc::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:filter_with_func:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_FilterWithFunc::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pIterator->GatherFollower(pFrame, envSet);
		_pObjFunc->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_FilterWithIter
//-----------------------------------------------------------------------------
Iterator *Iterator_FilterWithIter::GetSource()
{
	return _pIterator.get();
}

bool Iterator_FilterWithIter::DoNext(Environment &env, Signal sig, Value &value)
{
	while (_pIterator->Next(env, sig, value)) {
		Value valueCriteria;
		if (!_pIteratorCriteria->Next(env, sig, valueCriteria)) break;
		if (valueCriteria.GetBoolean()) return true;
	}
	return false;
}

String Iterator_FilterWithIter::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:filter_with_iter:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_FilterWithIter::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
		_pIteratorCriteria->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_WhileWithFunc
//-----------------------------------------------------------------------------
Iterator_WhileWithFunc::Iterator_WhileWithFunc(Environment *pEnv,
							Iterator *pIterator, Object_function *pObjFunc) :
			Iterator(pIterator->IsInfinite()), _pEnv(pEnv),
			_pIterator(pIterator), _pObjFunc(pObjFunc)
{
}

Iterator *Iterator_WhileWithFunc::GetSource()
{
	return _pIterator.get();
}

bool Iterator_WhileWithFunc::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pIterator.IsNull() || _pObjFunc.IsNull()) return false;
	do {
		if (!_pIterator->Next(env, sig, value)) break;
		ValueList valList(value);
		Value valueCriteria = _pObjFunc->Eval(*_pEnv, sig, valList);
		if (sig.IsSignalled()) break;
		if (!valueCriteria.GetBoolean()) break;
		return true;
	} while (0);
	_pIterator.reset(NULL);
	_pObjFunc.reset(NULL);
	return false;
}

String Iterator_WhileWithFunc::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:while_with_func:";
	if (_pIterator.IsNull()) {
		rtn += "(done)";
	} else {
		rtn += _pIterator->ToString(sig);
	}
	rtn += ">";
	return rtn;
}

void Iterator_WhileWithFunc::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		if (!_pIterator.IsNull()) {
			_pIterator->GatherFollower(pFrame, envSet);
		}
		if (!_pObjFunc.IsNull()) {
			_pObjFunc->GatherFollower(pFrame, envSet);
		}
	}
}

//-----------------------------------------------------------------------------
// Iterator_WhileWithIter
//-----------------------------------------------------------------------------
Iterator *Iterator_WhileWithIter::GetSource()
{
	return _pIterator.get();
}

bool Iterator_WhileWithIter::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pIterator.IsNull() || _pIteratorCriteria.IsNull()) return false;
	do {
		Value valueCriteria;
		if (!_pIteratorCriteria->Next(env, sig, valueCriteria)) break;
		if (!valueCriteria.GetBoolean()) break;
		if (!_pIterator->Next(env, sig, value)) break;
		return true;
	} while (0);
	_pIterator.reset(NULL);
	_pIteratorCriteria.reset(NULL);
	return false;
}

String Iterator_WhileWithIter::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:while_with_iter:";
	if (_pIterator.IsNull()) {
		rtn += "(done)";
	} else {
		rtn += _pIterator->ToString(sig);
	}
	rtn += ">";
	return rtn;
}

void Iterator_WhileWithIter::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (!_pIterator.IsNull()) {
			_pIterator->GatherFollower(pFrame, envSet);
		}
		if (!_pIteratorCriteria.IsNull()) {
			_pIteratorCriteria->GatherFollower(pFrame, envSet);
		}
	}
}

//-----------------------------------------------------------------------------
// Iterator_UntilWithFunc
//-----------------------------------------------------------------------------
Iterator_UntilWithFunc::Iterator_UntilWithFunc(Environment *pEnv, Iterator *pIterator,
								Object_function *pObjFunc, bool containLastFlag) :
			Iterator(pIterator->IsInfinite()), _pEnv(pEnv),
			_pIterator(pIterator), _pObjFunc(pObjFunc), _containLastFlag(containLastFlag)
{
}

Iterator *Iterator_UntilWithFunc::GetSource()
{
	return _pIterator.get();
}

bool Iterator_UntilWithFunc::DoNext(Environment &env, Signal sig, Value &value)
{
	bool rtnDone = false;
	if (_pIterator.IsNull() || _pObjFunc.IsNull()) return false;
	do {
		if (!_pIterator->Next(env, sig, value)) break;
		ValueList valList(value);
		Value valueCriteria = _pObjFunc->Eval(*_pEnv, sig, valList);
		if (sig.IsSignalled()) break;
		if (valueCriteria.GetBoolean()) {
			rtnDone = _containLastFlag;
			break;
		}
		return true;
	} while (0);
	_pIterator.reset(NULL);
	_pObjFunc.reset(NULL);
	return rtnDone;
}

String Iterator_UntilWithFunc::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:until_with_func:";
	if (_pIterator.IsNull()) {
		rtn += "(done)";
	} else {
		rtn += _pIterator->ToString(sig);
	}
	rtn += ">";
	return rtn;
}

void Iterator_UntilWithFunc::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		if (!_pIterator.IsNull()) {
			_pIterator->GatherFollower(pFrame, envSet);
		}
		if (!_pObjFunc.IsNull()) {
			_pObjFunc->GatherFollower(pFrame, envSet);
		}
	}
}

//-----------------------------------------------------------------------------
// Iterator_UntilWithIter
//-----------------------------------------------------------------------------
Iterator *Iterator_UntilWithIter::GetSource()
{
	return _pIterator.get();
}

bool Iterator_UntilWithIter::DoNext(Environment &env, Signal sig, Value &value)
{
	bool rtnDone = false;
	if (_pIterator.IsNull() || _pIteratorCriteria.IsNull()) return false;
	do {
		if (!_pIterator->Next(env, sig, value)) break;
		Value valueCriteria;
		if (!_pIteratorCriteria->Next(env, sig, valueCriteria)) break;
		if (valueCriteria.GetBoolean()) {
			rtnDone = _containLastFlag;
			break;
		}
		return true;
	} while (0);
	_pIterator.reset(NULL);
	_pIteratorCriteria.reset(NULL);
	return rtnDone;
}

String Iterator_UntilWithIter::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:until_with_iter:";
	if (_pIterator.IsNull()) {
		rtn += "(done)";
	} else {
		rtn += _pIterator->ToString(sig);
	}
	rtn += ">";
	return rtn;
}

void Iterator_UntilWithIter::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (!_pIterator.IsNull()) {
			_pIterator->GatherFollower(pFrame, envSet);
		}
		if (!_pIteratorCriteria.IsNull()) {
			_pIteratorCriteria->GatherFollower(pFrame, envSet);
		}
	}
}

//-----------------------------------------------------------------------------
// Iterator_SinceWithFunc
//-----------------------------------------------------------------------------
Iterator_SinceWithFunc::Iterator_SinceWithFunc(Environment *pEnv, Iterator *pIterator,
								Object_function *pObjFunc, bool containFirstFlag) :
			Iterator(pIterator->IsInfinite()), _pEnv(pEnv),
			_pIterator(pIterator), _pObjFunc(pObjFunc), _containFirstFlag(containFirstFlag)
{
}

Iterator *Iterator_SinceWithFunc::GetSource()
{
	return _pIterator.get();
}

bool Iterator_SinceWithFunc::DoNext(Environment &env, Signal sig, Value &value)
{
	for (;;) {
		if (!_pIterator->Next(env, sig, value)) return false;
		if (_pObjFunc.IsNull()) break;
		ValueList valList(value);
		Value valueCriteria = _pObjFunc->Eval(*_pEnv, sig, valList);
		if (sig.IsSignalled()) return false;
		if (valueCriteria.GetBoolean()) {
			_pObjFunc.reset(NULL);
			if (_containFirstFlag) break;
		}
	}
	return true;
}

String Iterator_SinceWithFunc::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:since_with_func:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_SinceWithFunc::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pIterator->GatherFollower(pFrame, envSet);
		if (!_pObjFunc.IsNull()) {
			_pObjFunc->GatherFollower(pFrame, envSet);
		}
	}
}

//-----------------------------------------------------------------------------
// Iterator_SinceWithIter
//-----------------------------------------------------------------------------
Iterator *Iterator_SinceWithIter::GetSource()
{
	return _pIterator.get();
}

bool Iterator_SinceWithIter::DoNext(Environment &env, Signal sig, Value &value)
{
	for (;;) {
		if (!_pIterator->Next(env, sig, value)) return false;
		if (_pIteratorCriteria.IsNull()) break;
		Value valueCriteria;
		if (!_pIteratorCriteria->Next(env, sig, valueCriteria)) return false;
		if (valueCriteria.GetBoolean()) {
			_pIteratorCriteria.reset(NULL);
			if (_containFirstFlag) break;
		}
	}
	return true;
}

String Iterator_SinceWithIter::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:since_with_iter:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_SinceWithIter::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
		if (!_pIteratorCriteria.IsNull()) {
			_pIteratorCriteria->GatherFollower(pFrame, envSet);
		}
	}
}

//-----------------------------------------------------------------------------
// Iterator_Replace
//-----------------------------------------------------------------------------
Iterator *Iterator_Replace::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Replace::DoNext(Environment &env, Signal sig, Value &value)
{
	if (!_pIterator->Next(env, sig, value)) return false;
	if (Value::Compare(value, _value) == 0) value = _valueReplace;
	return true;
}

String Iterator_Replace::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:replace:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_Replace::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_ReplaceInvalid
//-----------------------------------------------------------------------------
Iterator *Iterator_ReplaceInvalid::GetSource()
{
	return _pIterator.get();
}

bool Iterator_ReplaceInvalid::DoNext(Environment &env, Signal sig, Value &value)
{
	if (!_pIterator->Next(env, sig, value)) return false;
	if (value.IsInvalid()) value = _valueReplace;
	return true;
}

String Iterator_ReplaceInvalid::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:replace_invalid:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_ReplaceInvalid::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Format
//-----------------------------------------------------------------------------
Iterator *Iterator_Format::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Format::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueSrc;
	if (!_pIterator->Next(env, sig, valueSrc)) return false;
	String str;
	if (valueSrc.IsList()) {
		str = Formatter::Format(sig, _format.c_str(), valueSrc.GetList());
	} else {
		ValueList valList(valueSrc);
		str = Formatter::Format(sig, _format.c_str(), valList);
	}
	value = Value(env, str.c_str());
	return true;
}

String Iterator_Format::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:format:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_Format::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Pack
//-----------------------------------------------------------------------------
Iterator *Iterator_Pack::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Pack::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueSrc;
	if (!_pIterator->Next(env, sig, valueSrc)) return false;
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	size_t offset = 0;
	if (valueSrc.IsList()) {
		pObjBinary->GetBinary().Pack(env, sig, offset, _format.c_str(), valueSrc.GetList());
	} else {
		ValueList valList(valueSrc);
		pObjBinary->GetBinary().Pack(env, sig, offset, _format.c_str(), valList);
	}
	if (sig.IsSignalled()) return false;
	value = Value(pObjBinary.release());
	return true;
}

String Iterator_Pack::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:pack:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_Pack::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Zipv
//-----------------------------------------------------------------------------
Iterator *Iterator_Zipv::GetSource()
{
	return _iterOwner.empty()? NULL : _iterOwner.front();
}

bool Iterator_Zipv::DoNext(Environment &env, Signal sig, Value &value)
{
	ValueList &valList = value.InitAsList(env);
	return _iterOwner.Next(env, sig, valList);
}

String Iterator_Zipv::ToString(Signal sig) const
{
	return String("<iterator:zipv>");
}

void Iterator_Zipv::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_iterOwner.GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_RunLength
//-----------------------------------------------------------------------------
Iterator *Iterator_RunLength::GetSource()
{
	return _pIterator.get();
}

bool Iterator_RunLength::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) return false;
	Value valueCur;
	while (_pIterator->Next(env, sig, valueCur)) {
		if (_cnt == 0) {
			_cnt = 1;
			_valuePrev = valueCur;
		} else if (Value::Compare(_valuePrev, valueCur) == 0) {
			_cnt++;
		} else {
			value = Value::CreateAsList(env, Value(_cnt), _valuePrev);
			_cnt = 1;
			_valuePrev = valueCur;
			return true;
		}
	}
	if (_cnt == 0) return false;
	value = Value::CreateAsList(env, Value(_cnt), _valuePrev);
	_cnt = 0;
	_doneFlag = true;
	return true;
}

String Iterator_RunLength::ToString(Signal sig) const
{
	return String("<iterator:runlength>");
}

void Iterator_RunLength::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Align
//-----------------------------------------------------------------------------
Iterator *Iterator_Align::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Align::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_cnt == 0) return false;
	if (_cnt > 0) _cnt--;
	if (!_pIterator->Next(env, sig, value)) value = _valueFill;
	return true;
}

String Iterator_Align::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:align:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_Align::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Head
//-----------------------------------------------------------------------------
Iterator *Iterator_Head::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Head::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_cnt == 0) return false;
	if (_cnt > 0) _cnt--;
	return _pIterator->Next(env, sig, value);
}

String Iterator_Head::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:head:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_Head::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Fold
//-----------------------------------------------------------------------------
Iterator *Iterator_Fold::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Fold::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueNext;
	if (!_pIterator->Next(env, sig, valueNext)) return false;
	AutoPtr<Iterator> pIterator(new Iterator_FoldSeg(
							Reference(_pIterator.get()), _cnt, valueNext));
	if (_listItemFlag) {
		bool excludeNilFlag = false;
		value = pIterator->ToList(env, sig, false, excludeNilFlag);
	} else {
		value = Value(env, pIterator.release());
	}
	return true;
}

String Iterator_Fold::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:fold:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_Fold::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_FoldSeg
//-----------------------------------------------------------------------------
Iterator *Iterator_FoldSeg::GetSource()
{
	return _pIterator.get();
}

bool Iterator_FoldSeg::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_cnt == 0) return false;
	value = _valueNext;
	_cnt--;
	if (_cnt > 0 && !_pIterator->Next(env, sig, _valueNext)) _cnt = 0;
	return true;
}

String Iterator_FoldSeg::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:fold_seg:";
	rtn += _pIterator->ToString(sig);
	rtn += ">";
	return rtn;
}

void Iterator_FoldSeg::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Concat
//-----------------------------------------------------------------------------
Iterator *Iterator_Concat::GetSource()
{
	return _iterOwner.empty()? NULL : _iterOwner.front();
}

bool Iterator_Concat::DoNext(Environment &env, Signal sig, Value &value)
{
	for ( ; _ppIterator != _iterOwner.end(); _ppIterator++) {
		Iterator *pIterator = *_ppIterator;
		if (pIterator->Next(env, sig, value)) return true;
	}
	return false;
}

String Iterator_Concat::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:concat>";
	return rtn;
}

void Iterator_Concat::Add(Iterator *pIterator)
{
	_iterOwner.push_back(pIterator);
	_ppIterator = _iterOwner.begin();
	if (pIterator->IsInfinite()) _infiniteFlag = true;
}

void Iterator_Concat::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_iterOwner.GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_repeat
//-----------------------------------------------------------------------------
Iterator_repeat::Iterator_repeat(Environment *pEnv, Signal sig, Function *pFuncBlock,
					bool skipInvalidFlag, bool standaloneFlag, int cnt) :
		Iterator(cnt < 0, skipInvalidFlag), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_standaloneFlag(standaloneFlag),
		_pIteratorSub(NULL), _cnt(cnt), _idx(0)
{
}

Iterator *Iterator_repeat::GetSource()
{
	return NULL;
}

bool Iterator_repeat::DoNext(Environment &env, Signal sig, Value &value)
{
	for (;;) {
		if (_pIteratorSub.IsNull()) {
			if (_cnt >= 0 && _idx >= _cnt) return false;
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValue(Value(static_cast<Number>(_idx)));
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			if (sig.IsBreak()) {
				sig.ClearSignal();
				return false;
			} else if (sig.IsReturn()) {
				if (_standaloneFlag) {
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
			} else if ((sig).IsSignalled()) {
				return false;
			}
			_idx++;
			if (_standaloneFlag && value.IsIterator()) {
				_pIteratorSub.reset(Reference(value.GetIterator()));
				continue;
			}
		} else if (!_pIteratorSub->Next(env, sig, value)) {
			_pIteratorSub.reset(NULL);
			if (sig.IsSignalled()) return false;
			continue;
		}
		break;
	}
	return true;
}

String Iterator_repeat::ToString(Signal sig) const
{
	return String("<iterator:repeat>");
}

void Iterator_repeat::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorSub.IsNull()) _pIteratorSub->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_while
//-----------------------------------------------------------------------------
Iterator_while::Iterator_while(Environment *pEnv, Signal sig, Function *pFuncBlock,
					bool skipInvalidFlag, bool standaloneFlag, Expr *pExpr) :
		Iterator(false, skipInvalidFlag), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_standaloneFlag(standaloneFlag),
		_pIteratorSub(NULL), _pExpr(Expr::Reference(pExpr)), _idx(0)
{
}

Iterator *Iterator_while::GetSource()
{
	return NULL;
}

bool Iterator_while::DoNext(Environment &env, Signal sig, Value &value)
{
	for (;;) {
		if (_pIteratorSub.IsNull()) {
			if (!_pExpr->Exec(*_pEnv, sig).GetBoolean()) return false;
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValue(Value(static_cast<Number>(_idx)));
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			if (sig.IsBreak()) {
				sig.ClearSignal();
				return false;
			} else if (sig.IsReturn()) {
				if (_standaloneFlag) {
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
			} else if ((sig).IsSignalled()) {
				return false;
			}
			_idx++;
			if (_standaloneFlag && value.IsIterator()) {
				_pIteratorSub.reset(Reference(value.GetIterator()));
				continue;
			}
		} else if (!_pIteratorSub->Next(env, sig, value)) {
			_pIteratorSub.reset(NULL);
			if (sig.IsSignalled()) return false;
			continue;
		}
		break;
	}
	return true;
}

String Iterator_while::ToString(Signal sig) const
{
	return String("<iterator:while>");
}

void Iterator_while::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorSub.IsNull()) _pIteratorSub->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_for
//-----------------------------------------------------------------------------
Iterator_for::Iterator_for(Environment *pEnv, Signal sig, Function *pFuncBlock,
			bool skipInvalidFlag, bool standaloneFlag, const ValueList &valListArg) :
		Iterator(false, skipInvalidFlag), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_standaloneFlag(standaloneFlag),
		_pIteratorSub(NULL), _idx(0), _doneFlag(false)
{
	PrepareRepeaterIterators(*_pEnv, sig, valListArg, _exprLeftList, _iteratorOwner);
}

Iterator *Iterator_for::GetSource()
{
	return NULL;
}

bool Iterator_for::DoNext(Environment &env, Signal sig, Value &value)
{
	for (;;) {
		if (_pIteratorSub.IsNull()) {
			if (_doneFlag) return false;
			ExprList::iterator ppExprLeft = _exprLeftList.begin();
			foreach_const (IteratorOwner, ppIterator, _iteratorOwner) {
				Iterator *pIterator = *ppIterator;
				Value valueVar;
				if (!pIterator->Next(env, sig, valueVar)) {
					if (sig.IsSignalled()) return false;
					_doneFlag = true;
					break;
				}
				// same effect as assign operator
				(*ppExprLeft)->DoAssign(*_pEnv, sig, valueVar, NULL, false);
				if (sig.IsSignalled()) return false;
				ppExprLeft++;
			}
			if (_doneFlag) return false;
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValue(Value(static_cast<Number>(_idx)));
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			if (sig.IsBreak()) {
				value = sig.GetValue();
				sig.ClearSignal();
				return false;
			} else if (sig.IsReturn()) {
				if (_standaloneFlag) {
					value = sig.GetValue();
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
			} else if ((sig).IsSignalled()) {
				return false;
			}
			_idx++;
			if (_standaloneFlag && value.IsIterator()) {
				_pIteratorSub.reset(Reference(value.GetIterator()));
				continue;
			}
		} else if (!_pIteratorSub->Next(env, sig, value)) {
			_pIteratorSub.reset(NULL);
			if (sig.IsSignalled()) return false;
			continue;
		}
		break;
	}
	return true;
}

String Iterator_for::ToString(Signal sig) const
{
	return String("<iterator:for>");
}

void Iterator_for::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorSub.IsNull()) _pIteratorSub->GatherFollower(pFrame, envSet);
		_iteratorOwner.GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_cross
//-----------------------------------------------------------------------------
Iterator_cross::Iterator_cross(Environment *pEnv, Signal sig, Function *pFuncBlock,
			bool skipInvalidFlag, bool standaloneFlag, const ValueList &valListArg) :
		Iterator(false, skipInvalidFlag), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_standaloneFlag(standaloneFlag),
		_pIteratorSub(NULL), _idx(0), _doneFlag(true)
{
	if (!PrepareRepeaterIterators(*_pEnv, sig, valListArg,
									_exprLeftList, _iteratorOwnerOrg)) return;
	_valListArg.reserve(_iteratorOwnerOrg.size() + 1);
	_iteratorOwner.reserve(_iteratorOwnerOrg.size());
	_valListArg.push_back(Value(0));
	ExprList::iterator ppExprLeft = _exprLeftList.begin();
	foreach (IteratorOwner, ppIteratorOrg, _iteratorOwnerOrg) {
		Iterator *pIterator = (*ppIteratorOrg)->Clone();
		Value valueVar;
		bool rtn = pIterator->Next(*_pEnv, sig, valueVar);
		if (sig.IsSignalled()) return;
		if (rtn) {
			_doneFlag = false;
			_valListArg.push_back(Value(0));
			_iteratorOwner.push_back(pIterator);
		} else {
			_iteratorOwner.push_back(NULL);
			_valListArg.push_back(Value::Null);
			Iterator::Delete(pIterator);
		}
		(*ppExprLeft)->DoAssign(*_pEnv, sig, valueVar, NULL, false);
		if (sig.IsSignalled()) return;
		ppExprLeft++;
	}
}

Iterator *Iterator_cross::GetSource()
{
	return NULL;
}

bool Iterator_cross::DoNext(Environment &env, Signal sig, Value &value)
{
	for (;;) {
		if (_pIteratorSub.IsNull()) {
			if (_doneFlag) return false;
			_valListArg[0] = Value(_idx);
			AutoPtr<Args> pArgs(new Args(_valListArg));
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			if (sig.IsBreak()) {
				value = sig.GetValue();
				sig.ClearSignal();
				return false;
			} else if (sig.IsReturn()) {
				if (_standaloneFlag) {
					value = sig.GetValue();
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
			} else if ((sig).IsSignalled()) {
				return false;
			}
			_idx++;
			if (_standaloneFlag && value.IsIterator()) {
				_pIteratorSub.reset(Reference(value.GetIterator()));
				continue;
			}
			if (!AdvanceIterators(env, sig)) return false;
		} else if (!_pIteratorSub->Next(env, sig, value)) {
			_pIteratorSub.reset(NULL);
			if (sig.IsSignalled()) return false;
			if (!AdvanceIterators(env, sig)) return false;
			continue;
		}
		break;
	}
	return true;
}

String Iterator_cross::ToString(Signal sig) const
{
	return String("<iterator:cross>");
}

void Iterator_cross::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorSub.IsNull()) _pIteratorSub->GatherFollower(pFrame, envSet);
		_iteratorOwner.GatherFollower(pFrame, envSet);
		_iteratorOwnerOrg.GatherFollower(pFrame, envSet);
	}
}

bool Iterator_cross::AdvanceIterators(Environment &env, Signal sig)
{
	ExprList::reverse_iterator ppExprLeft = _exprLeftList.rbegin();
	ValueList::reverse_iterator pValueArg = _valListArg.rbegin();
	IteratorOwner::reverse_iterator ppIteratorOrg = _iteratorOwnerOrg.rbegin();
	foreach_reverse (IteratorOwner, ppIterator, _iteratorOwner) {
		Iterator *pIterator = *ppIterator;
		Value valueVar;
		if (pIterator != NULL) {
			if (pIterator->Next(env, sig, valueVar)) {
				*pValueArg = Value(pValueArg->GetNumber() + 1);
				(*ppExprLeft)->DoAssign(*_pEnv, sig, valueVar, NULL, false);
				if (sig.IsSignalled()) return false;
				break;
			}
			if (sig.IsSignalled()) return false;
			Iterator::Delete(pIterator);
			pIterator = (*ppIteratorOrg)->Clone();
			pIterator->Next(env, sig, valueVar);
			if (sig.IsSignalled()) return false;
			(*ppExprLeft)->DoAssign(*_pEnv, sig, valueVar, NULL, false);
			if (sig.IsSignalled()) return false;
			*pValueArg = Value(0);
			*ppIterator = pIterator;
		}
		if (ppIterator + 1 == _iteratorOwner.rend()) {
			_doneFlag = true;
			break;
		}
		ppExprLeft++;
		pValueArg++;
		ppIteratorOrg++;
	}
	return true;
}

//-----------------------------------------------------------------------------
// IteratorOwner
//-----------------------------------------------------------------------------
IteratorOwner::IteratorOwner(const IteratorOwner &iterOwner)
{
	reserve(iterOwner.size());
	foreach_const (IteratorOwner, ppIterator, iterOwner) {
		push_back((*ppIterator)->Clone());
	}
}

IteratorOwner::~IteratorOwner()
{
	foreach (IteratorOwner, ppIterator, *this) {
		Iterator::Delete(*ppIterator);
	}
}

bool IteratorOwner::Next(Environment &env, Signal sig, ValueList &valList)
{
	valList.clear();
	foreach (IteratorOwner, ppIterator, *this) {
		Iterator *pIterator = *ppIterator;
		Value value;
		if (!pIterator->Next(env, sig, value)) return false;
		valList.push_back(value);
	}
	return true;
}

void IteratorOwner::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	foreach (IteratorOwner, ppIterator, *this) {
		Iterator *pIterator = *ppIterator;
		pIterator->GatherFollower(pFrame, envSet);
	}
}

bool IteratorOwner::IsInfinite() const
{
	foreach_const (IteratorOwner, ppIterator, *this) {
		if (!(*ppIterator)->IsInfinite()) return false;
	}
	return true;
}

bool IteratorOwner::PrepareForMap(Signal sig,
				const DeclarationList &declList, const ValueList &valListArg)
{
	ValueList::const_iterator pValue = valListArg.begin();
	DeclarationList::const_iterator ppDecl = declList.begin();
	for ( ; pValue != valListArg.end() && ppDecl != declList.end(); pValue++) {
		const Declaration *pDecl = *ppDecl;
		Iterator *pIterator = NULL;
		if (pDecl->ShouldImplicitMap(*pValue)) {
			pIterator = pValue->CreateIterator(sig);
			if (pIterator == NULL) return false;
		} else {
			pIterator = new Iterator_Constant(*pValue);
		}
		push_back(pIterator);
		if (!pDecl->IsVariableLength()) ppDecl++;
	}
	return true;
}


}
