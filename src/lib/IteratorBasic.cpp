//=============================================================================
// IteratorBasic
//=============================================================================
#include "stdafx.h"

namespace Gura {

static bool PrepareRepeaterIterators(Environment &env, Signal sig,
	const ValueList &valListArg, ExprList &exprLeftList, IteratorOwner &iteratorOwner);

//-----------------------------------------------------------------------------
// Iterator_GenericClone
//-----------------------------------------------------------------------------
Iterator *Iterator_GenericClone::GetSource()
{
	return _pIterator->GetSource();
}

bool Iterator_GenericClone::DoNext(Environment &env, Signal sig, Value &value)
{
	return _pIterator->NextShared(env, sig, _id, value);
}

String Iterator_GenericClone::ToString() const
{
	return _pIterator->ToString();
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

String Iterator_Constant::ToString() const
{
	String rtn = "const(";
	rtn += _value.ToString(true);
	rtn += ")";
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

String Iterator_ConstantN::ToString() const
{
	String rtn = "consts(";
	rtn += _value.ToString(true);
	rtn += ",";
	rtn += NumberToString(_cnt);
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

String Iterator_OneShot::ToString() const
{
	String rtn = "oneshot(";
	rtn += _value.ToString();
	rtn += ")";
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
		static_cast<Number>(static_cast<int>(Random::Real2() * _range)) :
		static_cast<Number>(Random::Real2()));
	return true;
}

String Iterator_Rand::ToString() const
{
	String rtn = "rands(";
	if (_range > 0) {
		rtn += NumberToString(_range);
	} else {
		rtn += "nil";
	}
	rtn += ",";
	if (_cnt >= 0) {
		rtn += NumberToString(_cnt);
	} else {
		rtn += "nil";
	}
	rtn += ")";
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

String Iterator_Range::ToString() const
{
	String rtn;
	if (_numStep == 1 || _numStep == -1) {
		if (_numBegin == 0) {
			rtn = "range(";
			rtn += NumberToString(_numEnd);
			rtn += ")";
		} else {
			rtn = "range(";
			rtn += NumberToString(_numBegin);
			rtn += ",";
			rtn += NumberToString(_numEnd);
			rtn += ")";
		}
	} else {
		rtn = "range(";
		rtn += NumberToString(_numBegin);
		rtn += ",";
		rtn += NumberToString(_numEnd);
		rtn += ",";
		rtn += NumberToString(_numStep);
		rtn += ")";
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

String Iterator_Sequence::ToString() const
{
	String rtn;
	if (_numStep == 1. || _numStep == -1.) {
		rtn += NumberToString(_numBegin);
		rtn += "..";
		rtn += NumberToString(_numEnd);
	} else {
		rtn = "sequence(";
		rtn += NumberToString(_numBegin);
		rtn += ",";
		rtn += NumberToString(_numEnd);
		rtn += ",";
		rtn += NumberToString(_numStep);
		rtn += ")";
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
	_num += _numStep;
	return true;
}

String Iterator_SequenceInf::ToString() const
{
	String rtn;
	if (_numStep == 1) {
		rtn += NumberToString(_numBegin);
		rtn += "..";
	} else {
		rtn = "range(";
		rtn += NumberToString(_numBegin);
		rtn += ",";
		rtn += "nil";
		rtn += ",";
		rtn += NumberToString(_numStep);
		rtn += ")";
	}
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

String Iterator_Interval::ToString() const
{
	String str;
	str = "interval(";
	str += NumberToString(_numBegin);
	str += ",";
	str += NumberToString(_numEnd);
	str += ",";
	str += NumberToString(_numSamples);
	str += ")";
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

String Iterator_Fork::ToString() const
{
	String rtn;
	rtn += "fork()";
	return rtn;
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

String Iterator_ExplicitMap::ToString() const
{
	String rtn;
	rtn += "(";
	rtn += _pIterator->ToString();
	rtn += ").map(";
	rtn += _pObjFunc->ToString(true);
	rtn += ")";
	return rtn;
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

String Iterator_ImplicitMap::ToString() const
{
	String str;
	str += "implicitmap(";
	str += _pFunc->GetName();
	str += ";";
	foreach_const (IteratorOwner, ppIterator, _iterOwner) {
		const Iterator *pIterator = *ppIterator;
		if (ppIterator != _iterOwner.begin()) str += ",";
		str += pIterator->ToString();
	}
	str += ")";
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
				const Operator *pOperator, const Value &value, bool suffixFlag) :
	Iterator(false), _pEnv(pEnv), _sig(sig), _pOperator(pOperator), _suffixFlag(suffixFlag)
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
	value = _pOperator->EvalUnary(*_pEnv, sig, valueArg, _suffixFlag);
	if (sig.IsSignalled()) return false;
	return true;
}

String Iterator_UnaryOperatorMap::ToString() const
{
	String str;
	str += "unary_operator_map(";
	str += _pOperator->GetSymbol()->GetName();
	str += ";";
	str += _pIterator->ToString();
	str += ")";
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

String Iterator_BinaryOperatorMap::ToString() const
{
	String str;
	str += "binary_operator_map(";
	str += _pOperator->GetSymbol()->GetName();
	str += ";";
	str += _pIteratorLeft->ToString();
	str += ",";
	str += _pIteratorRight->ToString();
	str += ")";
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
	Fundamental *pFundEach = NULL;
	if (valueThisEach.IsPrimitive()) {
		pFundEach = env.LookupClass(valueThisEach.GetValueType());
	} else {
		pFundEach = valueThisEach.ExtractFundamental(sig);
		if (sig.IsSignalled()) return false;
	}
	if (_pExpr->IsIdentifier()) {
		SeqPostHandler *pSeqPostHandler = NULL;
		const Expr_Identifier *pExprIdentifier =
							dynamic_cast<const Expr_Identifier *>(_pExpr.get());
		value = pExprIdentifier->Exec(*pFundEach, sig, valueThisEach, pSeqPostHandler);
	} else {
		SeqPostHandler *pSeqPostHandler = NULL;
		value = _pExpr->Exec2(*pFundEach, sig, pSeqPostHandler);
	}
	if (value.Is_function()) {
		Object_function *pObj = new Object_function(env,
									Function::Reference(value.GetFunction()));
		pObj->SetThis(valueThisEach);
		value = Value(pObj);
	}
	return true;
}

String Iterator_MemberMap::ToString() const
{
	String rtn;
	rtn += "member_map(";
	rtn += _pExpr->ToString(Expr::SCRSTYLE_Brief);
	rtn += ";";
	rtn += _pIterator->ToString();
	rtn += ")";
	return rtn;
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

String Iterator_MethodMap::ToString() const
{
	String rtn;
	rtn += "member_map(";
	rtn += _pExprCaller->ToString(Expr::SCRSTYLE_Brief);
	rtn += ";";
	rtn += _pIteratorThis->ToString();
	rtn += ")";
	return rtn;
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
	if (valueArg.Is_list()) {
		ValueList valListComp = valueArg.GetList();
		if (!_pFunc->GetDeclOwner().Compensate(*_pEnv, sig, valListComp)) {
			return false;
		}
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetThis(_valueThis);
		pArgs->SetValueListArg(valListComp);
		value = _pFunc->Eval(*_pEnv, sig, *pArgs);
		if (sig.IsSignalled()) return false;
	} else {
		ValueList valListComp(valueArg);
		if (!_pFunc->GetDeclOwner().Compensate(*_pEnv, sig, valListComp)) {
			return false;
		}
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetThis(_valueThis);
		pArgs->SetValueListArg(valListComp);
		value = _pFunc->Eval(*_pEnv, sig, *pArgs);
		if (sig.IsSignalled()) return false;
		//sig.SetError(ERR_TypeError, "invalid structure of arguments");
		//return false;
	}
	return true;
}

String Iterator_FuncBinder::ToString() const
{
	String str;
	str += "func_binder(";
	str += _pFunc->ToString();
	str += ")";
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

String Iterator_Delay::ToString() const
{
	return String("delay");
}

void Iterator_Delay::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pIterator->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_Contains
//-----------------------------------------------------------------------------
Iterator *Iterator_Contains::GetSource()
{
	return _pIterator.get();
}

bool Iterator_Contains::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueElem;
	if (!_pIterator->Next(env, sig, valueElem)) return false;
	value = Value(_valListToFind.DoesContain(env, sig, valueElem));
	return !sig.IsSignalled();
}

String Iterator_Contains::ToString() const
{
	String rtn;
	rtn += "Contains";
	return rtn;
}

void Iterator_Contains::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
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
	if (_firstFlag) {
		_firstFlag = false;
	} else {
		for (int i = 0; i < _nSkip; i++) {
			Value valueTmp;
			if (!_pIterator->Next(env, sig, valueTmp)) break;
		}
	}
	return _pIterator->Next(env, sig, value);
#if 0
	bool flag = _pIterator->Next(env, sig, value);
	for (int i = 0; i < _nSkip; i++) {
		Value valueTmp;
		if (!_pIterator->Next(env, sig, valueTmp)) break;
	}
	return flag;
#endif
}

String Iterator_Skip::ToString() const
{
	String rtn;
	rtn += "skip(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_SkipInvalid::ToString() const
{
	String rtn;
	rtn += "skip_invalid(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_SkipFalse::ToString() const
{
	String rtn;
	rtn += "skip_false(";
	rtn += _pIterator->ToString();
	rtn += ")";
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
	if (value.Is_number()) {
		Number num = value.GetNumber();
		if (num < _threshold) value = Value(0);
	}
	return true;
}

String Iterator_RoundOff::ToString() const
{
	String rtn;
	rtn += "roundoff(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_FilterWithFunc::ToString() const
{
	String rtn;
	rtn += "filter_with_func(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_FilterWithIter::ToString() const
{
	String rtn;
	rtn += "filter_with_iter(";
	rtn += _pIterator->ToString();
	rtn += ")";
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
			Iterator(false), _pEnv(pEnv),
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

String Iterator_WhileWithFunc::ToString() const
{
	String rtn;
	rtn += "while_with_func(";
	if (_pIterator.IsNull()) {
		rtn += "(done)";
	} else {
		rtn += _pIterator->ToString();
	}
	rtn += ")";
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

String Iterator_WhileWithIter::ToString() const
{
	String rtn;
	rtn += "while_with_iter(";
	if (_pIterator.IsNull()) {
		rtn += "(done)";
	} else {
		rtn += _pIterator->ToString();
	}
	rtn += ")";
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
			Iterator(false), _pEnv(pEnv),
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

String Iterator_UntilWithFunc::ToString() const
{
	String rtn;
	rtn += "until_with_func(";
	if (_pIterator.IsNull()) {
		rtn += "(done)";
	} else {
		rtn += _pIterator->ToString();
	}
	rtn += ")";
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

String Iterator_UntilWithIter::ToString() const
{
	String rtn;
	rtn += "until_with_iter(";
	if (_pIterator.IsNull()) {
		rtn += "(done)";
	} else {
		rtn += _pIterator->ToString();
	}
	rtn += ")";
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

String Iterator_SinceWithFunc::ToString() const
{
	String rtn;
	rtn += "since_with_func(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_SinceWithIter::ToString() const
{
	String rtn;
	rtn += "since_with_iter(";
	rtn += _pIterator->ToString();
	rtn += ")";
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
	int cmp = Value::Compare(env, sig, value, _value);
	if (sig.IsSignalled()) return false;
	if (cmp == 0) value = _valueReplace;
	return true;
}

String Iterator_Replace::ToString() const
{
	String rtn;
	rtn += "replace(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_ReplaceInvalid::ToString() const
{
	String rtn;
	rtn += "replace_invalid(";
	rtn += _pIterator->ToString();
	rtn += ")";
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
	if (valueSrc.Is_list()) {
		str = Formatter::Format(sig, _format.c_str(), valueSrc.GetList());
	} else {
		ValueList valList(valueSrc);
		str = Formatter::Format(sig, _format.c_str(), valList);
	}
	value = Value(str);
	return true;
}

String Iterator_Format::ToString() const
{
	String rtn;
	rtn += "format(";
	rtn += _pIterator->ToString();
	rtn += ")";
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
	if (valueSrc.Is_list()) {
		pObjBinary->GetBinary().Pack(env, sig, offset, _format.c_str(), valueSrc.GetList());
	} else {
		ValueList valList(valueSrc);
		pObjBinary->GetBinary().Pack(env, sig, offset, _format.c_str(), valList);
	}
	if (sig.IsSignalled()) return false;
	value = Value(pObjBinary.release());
	return true;
}

String Iterator_Pack::ToString() const
{
	String rtn;
	rtn += "pack(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_Zipv::ToString() const
{
	return String("zipv");
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
		} else {
			int cmp = Value::Compare(env, sig, _valuePrev, valueCur);
			if (sig.IsSignalled()) return false;
			if (cmp == 0) {
				_cnt++;
			} else {
				value = Value::CreateList(env, Value(_cnt), _valuePrev);
				_cnt = 1;
				_valuePrev = valueCur;
				return true;
			}
		}
	}
	if (_cnt == 0) return false;
	value = Value::CreateList(env, Value(_cnt), _valuePrev);
	_cnt = 0;
	_doneFlag = true;
	return true;
}

String Iterator_RunLength::ToString() const
{
	return String("runlength");
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

String Iterator_Align::ToString() const
{
	String rtn;
	rtn += "align(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_Head::ToString() const
{
	String rtn;
	rtn += "head(";
	rtn += _pIterator->ToString();
	rtn += ")";
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
		value = Value(new Object_iterator(env, pIterator.release()));
	}
	return true;
}

String Iterator_Fold::ToString() const
{
	String rtn;
	rtn += "fold(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_FoldSeg::ToString() const
{
	String rtn;
	rtn += "fold_seg(";
	rtn += _pIterator->ToString();
	rtn += ")";
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

String Iterator_Concat::ToString() const
{
	String rtn;
	rtn += "concat";
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
// Iterator_Walk
//-----------------------------------------------------------------------------
Iterator_Walk::Iterator_Walk(Iterator *pIterator, Mode mode,
							 bool walkListFlag, bool walkIteratorFlag) :
	Iterator(pIterator->IsInfinite() || walkIteratorFlag), _mode(mode),
	_walkListFlag(walkListFlag), _walkIteratorFlag(walkIteratorFlag)
{
	_iterDeque.push_back(pIterator);
	_pIteratorCur = pIterator;
}

Iterator_Walk::~Iterator_Walk()
{
	foreach (IteratorDeque, ppIterator, _iterDeque) {
		Iterator *pIterator = *ppIterator;
		Iterator::Delete(pIterator);
	}
}

Iterator *Iterator_Walk::GetSource()
{
	return _pIteratorCur;
}

bool Iterator_Walk::DoNext(Environment &env, Signal sig, Value &value)
{
	while (_pIteratorCur != NULL) {
		if (_pIteratorCur->Next(env, sig, value)) {
			if (value.Is_list()) {
				if (!_walkListFlag) return true;
			} else if (value.Is_iterator()) {
				if (!_walkIteratorFlag) return true;
			} else {
				return true;
			}
			Iterator *pIterator = value.CreateIterator(sig);
			if (pIterator == NULL) return false;
			_iterDeque.push_back(pIterator);
			if (_mode == MODE_DepthFirstSearch) {
				_pIteratorCur = pIterator;
			}
		} else {
			Iterator::Delete(_pIteratorCur);
			if (_mode == MODE_DepthFirstSearch) {
				_iterDeque.pop_back();
				_pIteratorCur = _iterDeque.empty()? NULL : _iterDeque.back();
			} else { // _mode == MODE_BreadthFirstSearch
				_iterDeque.pop_front();
				_pIteratorCur = _iterDeque.empty()? NULL : _iterDeque.front();
			}
		}
	}
	return false;
}

String Iterator_Walk::ToString() const
{
	String rtn;
	rtn += "walk";
	return rtn;
}

void Iterator_Walk::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_Repeater
//-----------------------------------------------------------------------------
Iterator_Repeater::Iterator_Repeater(Environment *pEnv, Signal sig, Function *pFuncBlock,
					bool skipInvalidFlag, bool genIterFlag, Iterator *pIteratorSrc) :
		Iterator(pIteratorSrc->IsInfinite(), skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(NULL), _pIteratorSrc(pIteratorSrc), _idx(0), _doneFlag(false)
{
}

Iterator *Iterator_Repeater::GetSource()
{
	return _pIteratorSrc.get();
}

bool Iterator_Repeater::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) return false;
	for (;;) {
		if (_pIteratorNest.IsNull()) {
			Value valueSrc;
			AutoPtr<Args> pArgs(new Args());
			// **** https://github.com/gura-lang/gura/issues/1 ****
#if 0
			pArgs->AddValue(valueSrc);
			for (Iterator *pIteratorSrc = _pIteratorSrc.get();
					pIteratorSrc != NULL; pIteratorSrc = pIteratorSrc->GetSource()) {
				pArgs->AddValue(Value(static_cast<Number>(pIteratorSrc->GetIndexNext())));
			}
			if (!_pIteratorSrc->Next(env, sig, valueSrc)) return false;
			pArgs->GetValueListArg()[0] = valueSrc;
#else
			if (!_pIteratorSrc->Next(env, sig, valueSrc)) return false;
			pArgs->AddValue(valueSrc);
			for (Iterator *pIteratorSrc = _pIteratorSrc.get();
					pIteratorSrc != NULL; pIteratorSrc = pIteratorSrc->GetSource()) {
				pArgs->AddValue(Value(static_cast<Number>(pIteratorSrc->GetIndexCur())));
			}
#endif
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			_idx++;
			if (sig.IsBreak()) {
				value = sig.GetValue();
				sig.ClearSignal();
				_doneFlag = true;
				return value.IsValid();
			} else if (sig.IsReturn()) {
				if (_genIterFlag) {
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
				if (value.IsInvalid()) continue;
			} else if (sig.IsSignalled()) {
				return false;
			}
			if (!_genIterFlag || !value.Is_iterator() ||
									!value.GetIterator()->IsRepeater()) break;
			_pIteratorNest.reset(Reference(value.GetIterator()));
		} else if (_pIteratorNest->Next(env, sig, value)) {
			break;
		} else {
			_pIteratorNest.reset(NULL);
			if (sig.IsSignalled()) return false;
		}
	}
	return true;
}

String Iterator_Repeater::ToString() const
{
	return String("repeater");
}

void Iterator_Repeater::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorNest.IsNull()) _pIteratorNest->GatherFollower(pFrame, envSet);
		_pIteratorSrc->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_repeat
//-----------------------------------------------------------------------------
Iterator_repeat::Iterator_repeat(Environment *pEnv, Signal sig, Function *pFuncBlock,
					bool skipInvalidFlag, bool genIterFlag, int cnt) :
		Iterator(cnt < 0, skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(NULL), _cnt(cnt), _idx(0), _doneFlag(false)
{
}

Iterator *Iterator_repeat::GetSource()
{
	return NULL;
}

bool Iterator_repeat::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) return false;
	for (;;) {
		if (_pIteratorNest.IsNull()) {
			if (_cnt >= 0 && _idx >= _cnt) return false;
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValue(Value(static_cast<Number>(_idx)));
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			_idx++;
			if (sig.IsBreak()) {
				value = sig.GetValue();
				sig.ClearSignal();
				_doneFlag = true;
				return value.IsValid();
			} else if (sig.IsReturn()) {
				if (_genIterFlag) {
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
				if (value.IsInvalid()) continue;
			} else if (sig.IsSignalled()) {
				return false;
			}
			if (!_genIterFlag || !value.Is_iterator() ||
									!value.GetIterator()->IsRepeater()) break;
			_pIteratorNest.reset(Reference(value.GetIterator()));
		} else if (_pIteratorNest->Next(env, sig, value)) {
			break;
		} else {
			_pIteratorNest.reset(NULL);
			if (sig.IsSignalled()) return false;
		}
	}
	return true;
}

String Iterator_repeat::ToString() const
{
	return String("repeat");
}

void Iterator_repeat::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorNest.IsNull()) _pIteratorNest->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_while
//-----------------------------------------------------------------------------
Iterator_while::Iterator_while(Environment *pEnv, Signal sig, Function *pFuncBlock,
					bool skipInvalidFlag, bool genIterFlag, Expr *pExpr) :
		Iterator(false, skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(NULL), _pExpr(Expr::Reference(pExpr)), _idx(0), _doneFlag(false)
{
}

Iterator *Iterator_while::GetSource()
{
	return NULL;
}

bool Iterator_while::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_doneFlag) return false;
	for (;;) {
		if (_pIteratorNest.IsNull()) {
			SeqPostHandler *pSeqPostHandler = NULL;
			if (!_pExpr->Exec2(*_pEnv, sig, pSeqPostHandler).GetBoolean()) return false;
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValue(Value(static_cast<Number>(_idx)));
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			_idx++;
			if (sig.IsBreak()) {
				value = sig.GetValue();
				sig.ClearSignal();
				_doneFlag = true;
				return value.IsValid();
			} else if (sig.IsReturn()) {
				if (_genIterFlag) {
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
				if (value.IsInvalid()) continue;
			} else if (sig.IsSignalled()) {
				return false;
			}
			if (!_genIterFlag || !value.Is_iterator() ||
									!value.GetIterator()->IsRepeater()) break;
			_pIteratorNest.reset(Reference(value.GetIterator()));
		} else if (_pIteratorNest->Next(env, sig, value)) {
			break;
		} else {
			_pIteratorNest.reset(NULL);
			if (sig.IsSignalled()) return false;
		}
	}
	return true;
}

String Iterator_while::ToString() const
{
	return String("while");
}

void Iterator_while::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorNest.IsNull()) _pIteratorNest->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_for
//-----------------------------------------------------------------------------
Iterator_for::Iterator_for(Environment *pEnv, Signal sig, Function *pFuncBlock,
			bool skipInvalidFlag, bool genIterFlag, const ValueList &valListArg) :
		Iterator(false, skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(NULL), _idx(0), _doneFlag(false)
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
		if (_pIteratorNest.IsNull()) {
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
				(*ppExprLeft)->Assign(*_pEnv, sig, valueVar, NULL, false);
				if (sig.IsSignalled()) return false;
				ppExprLeft++;
			}
			if (_doneFlag) return false;
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValue(Value(static_cast<Number>(_idx)));
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			_idx++;
			if (sig.IsBreak()) {
				value = sig.GetValue();
				sig.ClearSignal();
				_doneFlag = true;
				return value.IsValid();
			} else if (sig.IsReturn()) {
				if (_genIterFlag) {
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
				if (value.IsInvalid()) continue;
			} else if (sig.IsSignalled()) {
				return false;
			}
			if (!_genIterFlag || !value.Is_iterator() ||
									!value.GetIterator()->IsRepeater()) break;
			_pIteratorNest.reset(Reference(value.GetIterator()));
		} else if (_pIteratorNest->Next(env, sig, value)) {
			break;
		} else {
			_pIteratorNest.reset(NULL);
			if (sig.IsSignalled()) return false;
		}
	}
	return true;
}

String Iterator_for::ToString() const
{
	return String("for");
}

void Iterator_for::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorNest.IsNull()) _pIteratorNest->GatherFollower(pFrame, envSet);
		_iteratorOwner.GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_cross
//-----------------------------------------------------------------------------
Iterator_cross::Iterator_cross(Environment *pEnv, Signal sig, Function *pFuncBlock,
			bool skipInvalidFlag, bool genIterFlag, const ValueList &valListArg) :
		Iterator(false, skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(NULL), _idx(0), _doneFlag(true)
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
		(*ppExprLeft)->Assign(*_pEnv, sig, valueVar, NULL, false);
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
		if (_pIteratorNest.IsNull()) {
			if (_doneFlag) return false;
			_valListArg[0] = Value(_idx);
			AutoPtr<Args> pArgs(new Args());
			pArgs->SetValueListArg(_valListArg);
			value = _pFuncBlock->Eval(*_pEnv, sig, *pArgs);
			_idx++;
			if (sig.IsBreak()) {
				value = sig.GetValue();
				sig.ClearSignal();
				_doneFlag = true;
				return value.IsValid();
			} else if (sig.IsReturn()) {
				if (_genIterFlag) {
					sig.ClearSignal();
				}
				return false;
			} else if (sig.IsContinue()) {
				value = sig.GetValue();
				sig.ClearSignal();
				if (value.IsInvalid()) {
					if (!AdvanceIterators(env, sig)) return false;
					continue;
				}
			} else if (sig.IsSignalled()) {
				return false;
			}
			if (!_genIterFlag || !value.Is_iterator() ||
									!value.GetIterator()->IsRepeater()) {
				if (!AdvanceIterators(env, sig)) return false;
				break;
			}
			_pIteratorNest.reset(Reference(value.GetIterator()));
		} else if (_pIteratorNest->Next(env, sig, value)) {
			break;
		} else {
			_pIteratorNest.reset(NULL);
			if (sig.IsSignalled()) return false;
			if (!AdvanceIterators(env, sig)) return false;
		}
	}
	return true;
}

String Iterator_cross::ToString() const
{
	return String("cross");
}

void Iterator_cross::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pFuncBlock->GatherFollower(pFrame, envSet);
		if (!_pIteratorNest.IsNull()) _pIteratorNest->GatherFollower(pFrame, envSet);
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
				(*ppExprLeft)->Assign(*_pEnv, sig, valueVar, NULL, false);
				if (sig.IsSignalled()) return false;
				break;
			}
			if (sig.IsSignalled()) return false;
			Iterator::Delete(pIterator);
			pIterator = (*ppIteratorOrg)->Clone();
			pIterator->Next(env, sig, valueVar);
			if (sig.IsSignalled()) return false;
			(*ppExprLeft)->Assign(*_pEnv, sig, valueVar, NULL, false);
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
// utilities
//-----------------------------------------------------------------------------
bool PrepareRepeaterIterators(Environment &env, Signal sig,
	const ValueList &valListArg, ExprList &exprLeftList, IteratorOwner &iteratorOwner)
{
	foreach_const (ValueList, pValue, valListArg) {
		GURA_ASSUME(env, pValue->Is_expr());
		const Expr *pExpr = pValue->GetExpr();
		Value value;
		if (!(pExpr->IsBinaryOp() && dynamic_cast<const Expr_BinaryOp *>(pExpr)->
										GetOperator()->GetOpType() == OPTYPE_Contains)) {
			sig.SetError(ERR_TypeError, "iteratable must be specified as arguments");
			return false;
		}
		SeqPostHandler *pSeqPostHandlerLeft = NULL;
		const Expr_BinaryOp *pExprBin =
						dynamic_cast<const Expr_BinaryOp *>(pExpr);
		value = pExprBin->GetRight()->Exec2(env, sig, pSeqPostHandlerLeft);
		if (sig.IsSignalled()) return false;
		Iterator *pIterator = value.CreateIterator(sig);
		if (pIterator == NULL) return false;
		exprLeftList.push_back(const_cast<Expr *>(pExprBin->GetLeft()));
		iteratorOwner.push_back(pIterator);
	}
	return true;
}

}
