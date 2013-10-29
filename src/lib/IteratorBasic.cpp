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
	Fundamental *pFundEach = NULL;
	if (valueThisEach.IsPrimitive()) {
		pFundEach = env.LookupClass(valueThisEach.GetValueType());
	} else {
		pFundEach = valueThisEach.ExtractFundamental(sig);
		if (sig.IsSignalled()) return false;
	}
	SeqPostHandler *pSeqPostHandler = NULL;
	value = _pExpr->Exec2(*pFundEach, sig, pSeqPostHandler);
	if (value.IsFunction()) {
		Object_function *pObj = new Object_function(*pFundEach,
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
			pArgs->AddValue(valueSrc);
			for (Iterator *pIteratorSrc = _pIteratorSrc.get();
					pIteratorSrc != NULL; pIteratorSrc = pIteratorSrc->GetSource()) {
				pArgs->AddValue(Value(static_cast<Number>(pIteratorSrc->GetCountNext())));
			}
			if (!_pIteratorSrc->Next(env, sig, valueSrc)) return false;
			pArgs->GetValueListArg()[0] = valueSrc;
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
			if (!_genIterFlag || !value.IsIterator() ||
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

String Iterator_Repeater::ToString(Signal sig) const
{
	return String("<iterator:Repeater>");
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
			if (!_genIterFlag || !value.IsIterator() ||
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

String Iterator_repeat::ToString(Signal sig) const
{
	return String("<iterator:repeat>");
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
			if (!_genIterFlag || !value.IsIterator() ||
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

String Iterator_while::ToString(Signal sig) const
{
	return String("<iterator:while>");
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
				(*ppExprLeft)->DoAssign(*_pEnv, sig, valueVar, NULL, false);
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
			if (!_genIterFlag || !value.IsIterator() ||
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

String Iterator_for::ToString(Signal sig) const
{
	return String("<iterator:for>");
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
			if (!_genIterFlag || !value.IsIterator() ||
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

String Iterator_cross::ToString(Signal sig) const
{
	return String("<iterator:cross>");
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
// utilities
//-----------------------------------------------------------------------------
bool PrepareRepeaterIterators(Environment &env, Signal sig,
	const ValueList &valListArg, ExprList &exprLeftList, IteratorOwner &iteratorOwner)
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
