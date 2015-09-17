//=============================================================================
// IteratorBasic
//=============================================================================
#include "stdafx.h"

namespace Gura {

static bool PrepareRepeaterIterators(Environment &env,
	const ValueList &valListArg, ExprList &exprLeftList, IteratorOwner &iteratorOwner);

//-----------------------------------------------------------------------------
// Iterator_GenericClone
//-----------------------------------------------------------------------------
Iterator *Iterator_GenericClone::GetSource()
{
	return _pIterator->GetSource();
}

bool Iterator_GenericClone::DoNext(Environment &env, Value &value)
{
	return _pIterator->NextShared(env, _id, value);
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
	return nullptr;
}

bool Iterator_Constant::DoNext(Environment &env, Value &value)
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
	return nullptr;
}

bool Iterator_ConstantN::DoNext(Environment &env, Value &value)
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
	return nullptr;
}

bool Iterator_OneShot::DoNext(Environment &env, Value &value)
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
	return nullptr;
}

bool Iterator_Rand::DoNext(Environment &env, Value &value)
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
	return nullptr;
}

bool Iterator_Range::DoNext(Environment &env, Value &value)
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
	return nullptr;
}

bool Iterator_Sequence::DoNext(Environment &env, Value &value)
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
	return nullptr;
}

bool Iterator_SequenceInf::DoNext(Environment &env, Value &value)
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
	return nullptr;
}

bool Iterator_Interval::DoNext(Environment &env, Value &value)
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

//-----------------------------------------------------------------------------
// Iterator_ExplicitMap
//-----------------------------------------------------------------------------
Iterator_ExplicitMap::Iterator_ExplicitMap(Environment *pEnv,
							Iterator *pIterator, Object_function *pObjFunc) :
	Iterator(pIterator->IsInfinite()), _pEnv(pEnv),
	_pIterator(pIterator), _pObjFunc(pObjFunc)
{
}

Iterator_ExplicitMap::Iterator_ExplicitMap(const Iterator_ExplicitMap &iter) :
		Iterator(iter), _pEnv(iter._pEnv->Reference()),
		_pIterator(iter._pIterator->Clone()),
		_pObjFunc(Object_function::Reference(iter._pObjFunc.get()))
{
}

Iterator_ExplicitMap::~Iterator_ExplicitMap()
{
	if (IsVirgin()) Consume(*_pEnv);
}

Iterator *Iterator_ExplicitMap::Clone() const
{
	return new Iterator_ExplicitMap(*this);
}

Iterator *Iterator_ExplicitMap::GetSource()
{
	return _pIterator.get();
}

bool Iterator_ExplicitMap::DoNext(Environment &env, Value &value)
{
	if (!_pIterator->Next(env, value)) return false;
	value = _pObjFunc->Eval(*_pEnv, value);
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
Iterator_ImplicitMap::Iterator_ImplicitMap(Environment *pEnv, Argument *pArg, bool skipInvalidFlag) :
	Iterator(pArg->IsInfiniteMap(), skipInvalidFlag), _pEnv(pEnv), _pArg(pArg), _doneThisFlag(false)
{
}

Iterator_ImplicitMap::~Iterator_ImplicitMap()
{
	if (IsVirgin()) Consume(*_pEnv);
}

Iterator *Iterator_ImplicitMap::GetSource()
{
	return _pArg->GetIteratorThis();
}

bool Iterator_ImplicitMap::DoNext(Environment &env, Value &value)
{
	if (_doneThisFlag || !_pArg->NextMap(env)) return false;
	value = _pArg->GetFunction()->Eval(*_pEnv, *_pArg);
	if (env.IsSignalled()) return false;
	Iterator *pIteratorThis = _pArg->GetIteratorThis();
	if (pIteratorThis != nullptr) {
		Value valueThis;
		_doneThisFlag = !pIteratorThis->Next(env, valueThis);
		if (env.IsSignalled()) return false;
		_pArg->SetValueThis(valueThis);
	}
	return true;
}

String Iterator_ImplicitMap::ToString() const
{
	String str;
	str += "implicitmap(";
	str += _pArg->GetFunction()->GetName();
#if 0
	str += ";";
	foreach_const (IteratorOwner, ppIterator, _iterOwner) {
		const Iterator *pIterator = *ppIterator;
		if (ppIterator != _iterOwner.begin()) str += ",";
		str += pIterator->ToString();
	}
#endif
	str += ")";
	return str;
}

void Iterator_ImplicitMap::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		if (_pEnv->GetFrameOwner().DoesExist(pFrame)) envSet.insert(_pEnv.get());
		_pArg->GatherFollower(pFrame, envSet);
	}
}

//-----------------------------------------------------------------------------
// Iterator_UnaryOperatorMap
//-----------------------------------------------------------------------------
Iterator_UnaryOperatorMap::Iterator_UnaryOperatorMap(Environment *pEnv,
				const Operator *pOperator, const Value &value, bool suffixFlag) :
	Iterator(false), _pEnv(pEnv), _pOperator(pOperator), _suffixFlag(suffixFlag)
{
	Signal &sig = pEnv->GetSignal();
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
	if (IsVirgin()) Consume(*_pEnv);
}

Iterator *Iterator_UnaryOperatorMap::GetSource()
{
	return nullptr;
}

bool Iterator_UnaryOperatorMap::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Value valueArg;
	if (!_pIterator->Next(env, valueArg)) return false;
	value = _pOperator->EvalUnary(*_pEnv, valueArg, _suffixFlag);
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
Iterator_BinaryOperatorMap::Iterator_BinaryOperatorMap(Environment *pEnv,
		const Operator *pOperator, const Value &valueLeft, const Value &valueRight) :
	Iterator(false), _pEnv(pEnv), _pOperator(pOperator)
{
	Signal &sig = pEnv->GetSignal();
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
	if (IsVirgin()) Consume(*_pEnv);
}

Iterator *Iterator_BinaryOperatorMap::GetSource()
{
	return nullptr;
}

bool Iterator_BinaryOperatorMap::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Value valueLeft, valueRight;
	if (!_pIteratorLeft->Next(env, valueLeft) ||
			!_pIteratorRight->Next(env, valueRight)) return false;
	value = _pOperator->EvalBinary(*_pEnv, valueLeft, valueRight);
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
Iterator_MemberMap::Iterator_MemberMap(Environment *pEnv, Iterator *pIterator, Expr *pExpr) :
		Iterator(pIterator->IsInfinite()), _pEnv(pEnv), _pIterator(pIterator), _pExpr(pExpr)
{
}

Iterator_MemberMap::~Iterator_MemberMap()
{
	if (IsVirgin()) Consume(*_pEnv);
}

Iterator *Iterator_MemberMap::GetSource()
{
	return _pIterator.get();
}

bool Iterator_MemberMap::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Value valueThisEach;
	if (!_pIterator->Next(env, valueThisEach)) return false;
	Fundamental *pFundEach = nullptr;
	if (valueThisEach.IsPrimitive()) {
		pFundEach = env.LookupClass(valueThisEach.GetValueType());
	} else {
		pFundEach = valueThisEach.ExtractFundamental(sig);
		if (sig.IsSignalled()) return false;
	}
	if (_pExpr->IsIdentifier()) {
		const Expr_Identifier *pExprIdentifier =
							dynamic_cast<const Expr_Identifier *>(_pExpr.get());
		value = pExprIdentifier->GetThisProp(*pFundEach, valueThisEach);
	} else {
		value = _pExpr->Exec(*pFundEach);
	}
	if (value.Is_function()) {
		Object_function *pObj = new Object_function(env,
									Function::Reference(value.GetFunction()));
		pObj->SetValueThis(valueThisEach);
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
Iterator_MethodMap::Iterator_MethodMap(Environment *pEnv, Iterator *pIteratorThis, Expr_Caller *pExprCaller) :
		Iterator(pIteratorThis->IsInfinite()), _pEnv(pEnv),
		_pIteratorThis(pIteratorThis), _pExprCaller(pExprCaller)
{
}

Iterator_MethodMap::~Iterator_MethodMap()
{
	if (IsVirgin()) Consume(*_pEnv);
}

Iterator *Iterator_MethodMap::GetSource()
{
	return _pIteratorThis.get();
}

bool Iterator_MethodMap::DoNext(Environment &env, Value &value)
{
	Value valueThis;
	if (!_pIteratorThis->Next(env, valueThis)) return false;
	value = _pExprCaller->EvalEach(*_pEnv, valueThis, nullptr, false, nullptr);
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

bool Iterator_FuncBinder::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Value valueArg;
	if (!_pIterator->Next(env, valueArg)) return false;
	if (valueArg.Is_list()) {
		AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
		pArg->SetValueThis(_valueThis);
		if (!pArg->AddValues(env, valueArg.GetList())) return false;
		if (!pArg->Complete(*_pEnv)) return false;
		value = _pFunc->Eval(*_pEnv, *pArg);
		if (sig.IsSignalled()) return false;
	} else {
		AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
		pArg->SetValueThis(_valueThis);
		if (!pArg->AddValue(env, valueArg)) return false;
		if (!pArg->Complete(*_pEnv)) return false;
		value = _pFunc->Eval(*_pEnv, *pArg);
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

bool Iterator_Delay::DoNext(Environment &env, Value &value)
{
	OAL::Sleep(_delay);
	return _pIterator->Next(env, value);
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

bool Iterator_Contains::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Value valueElem;
	if (!_pIterator->Next(env, valueElem)) return false;
	value = Value(_valListToFind.DoesContain(env, valueElem));
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

bool Iterator_Skip::DoNext(Environment &env, Value &value)
{
	if (_firstFlag) {
		_firstFlag = false;
	} else {
		for (int i = 0; i < _nSkip; i++) {
			Value valueTmp;
			if (!_pIterator->Next(env, valueTmp)) break;
		}
	}
	return _pIterator->Next(env, value);
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

bool Iterator_SkipInvalid::DoNext(Environment &env, Value &value)
{
	while (_pIterator->Next(env, value)) {
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

bool Iterator_SkipFalse::DoNext(Environment &env, Value &value)
{
	while (_pIterator->Next(env, value)) {
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

bool Iterator_RoundOff::DoNext(Environment &env, Value &value)
{
	if (!_pIterator->Next(env, value)) return false;
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

bool Iterator_FilterWithFunc::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	while (_pIterator->Next(env, value)) {
		Value valueCriteria = _pObjFunc->Eval(*_pEnv, value);
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

bool Iterator_FilterWithIter::DoNext(Environment &env, Value &value)
{
	while (_pIterator->Next(env, value)) {
		Value valueCriteria;
		if (!_pIteratorCriteria->Next(env, valueCriteria)) break;
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

bool Iterator_WhileWithFunc::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_pIterator.IsNull() || _pObjFunc.IsNull()) return false;
	do {
		if (!_pIterator->Next(env, value)) break;
		Value valueCriteria = _pObjFunc->Eval(*_pEnv, value);
		if (sig.IsSignalled()) break;
		if (!valueCriteria.GetBoolean()) break;
		return true;
	} while (0);
	_pIterator.reset(nullptr);
	_pObjFunc.reset(nullptr);
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

bool Iterator_WhileWithIter::DoNext(Environment &env, Value &value)
{
	if (_pIterator.IsNull() || _pIteratorCriteria.IsNull()) return false;
	do {
		Value valueCriteria;
		if (!_pIteratorCriteria->Next(env, valueCriteria)) break;
		if (!valueCriteria.GetBoolean()) break;
		if (!_pIterator->Next(env, value)) break;
		return true;
	} while (0);
	_pIterator.reset(nullptr);
	_pIteratorCriteria.reset(nullptr);
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

bool Iterator_UntilWithFunc::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	bool rtnDone = false;
	if (_pIterator.IsNull() || _pObjFunc.IsNull()) return false;
	do {
		if (!_pIterator->Next(env, value)) break;
		Value valueCriteria = _pObjFunc->Eval(*_pEnv, value);
		if (sig.IsSignalled()) break;
		if (valueCriteria.GetBoolean()) {
			rtnDone = _containLastFlag;
			break;
		}
		return true;
	} while (0);
	_pIterator.reset(nullptr);
	_pObjFunc.reset(nullptr);
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

bool Iterator_UntilWithIter::DoNext(Environment &env, Value &value)
{
	bool rtnDone = false;
	if (_pIterator.IsNull() || _pIteratorCriteria.IsNull()) return false;
	do {
		if (!_pIterator->Next(env, value)) break;
		Value valueCriteria;
		if (!_pIteratorCriteria->Next(env, valueCriteria)) break;
		if (valueCriteria.GetBoolean()) {
			rtnDone = _containLastFlag;
			break;
		}
		return true;
	} while (0);
	_pIterator.reset(nullptr);
	_pIteratorCriteria.reset(nullptr);
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

bool Iterator_SinceWithFunc::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	for (;;) {
		if (!_pIterator->Next(env, value)) return false;
		if (_pObjFunc.IsNull()) break;
		Value valueCriteria = _pObjFunc->Eval(*_pEnv, value);
		if (sig.IsSignalled()) return false;
		if (valueCriteria.GetBoolean()) {
			_pObjFunc.reset(nullptr);
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

bool Iterator_SinceWithIter::DoNext(Environment &env, Value &value)
{
	for (;;) {
		if (!_pIterator->Next(env, value)) return false;
		if (_pIteratorCriteria.IsNull()) break;
		Value valueCriteria;
		if (!_pIteratorCriteria->Next(env, valueCriteria)) return false;
		if (valueCriteria.GetBoolean()) {
			_pIteratorCriteria.reset(nullptr);
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

bool Iterator_Replace::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (!_pIterator->Next(env, value)) return false;
	int cmp = Value::Compare(env, value, _value);
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

bool Iterator_ReplaceInvalid::DoNext(Environment &env, Value &value)
{
	if (!_pIterator->Next(env, value)) return false;
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

bool Iterator_Format::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Value valueSrc;
	if (!_pIterator->Next(env, valueSrc)) return false;
	String str;
	if (valueSrc.Is_list()) {
		str = Formatter::FormatValueList(sig, _format.c_str(), valueSrc.GetList());
	} else {
		ValueList valList(valueSrc);
		str = Formatter::FormatValueList(sig, _format.c_str(), valList);
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

bool Iterator_Pack::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Value valueSrc;
	if (!_pIterator->Next(env, valueSrc)) return false;
	AutoPtr<Object_binary> pObjBinary(new Object_binary(env));
	size_t offset = 0;
	if (valueSrc.Is_list()) {
		pObjBinary->GetBinary().Pack(env, offset, _format.c_str(), valueSrc.GetList());
	} else {
		ValueList valList(valueSrc);
		pObjBinary->GetBinary().Pack(env, offset, _format.c_str(), valList);
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
	return _iterOwner.empty()? nullptr : _iterOwner.front();
}

bool Iterator_Zipv::DoNext(Environment &env, Value &value)
{
	ValueList &valList = value.InitAsList(env);
	return _iterOwner.Next(env, valList);
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

bool Iterator_RunLength::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_doneFlag) return false;
	Value valueCur;
	while (_pIterator->Next(env, valueCur)) {
		if (_cnt == 0) {
			_cnt = 1;
			_valuePrev = valueCur;
		} else {
			int cmp = Value::Compare(env, _valuePrev, valueCur);
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

bool Iterator_Align::DoNext(Environment &env, Value &value)
{
	if (_cnt == 0) return false;
	if (_cnt > 0) _cnt--;
	if (!_pIterator->Next(env, value)) value = _valueFill;
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

bool Iterator_Head::DoNext(Environment &env, Value &value)
{
	if (_cnt == 0) return false;
	if (_cnt > 0) _cnt--;
	return _pIterator->Next(env, value);
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

bool Iterator_Fold::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_doneFlag) return false;
	Value valueElem;
	Value valueNext;
	ValueList &valList = valueNext.InitAsList(env);
	valList.reserve(_cnt);
	if (_cntStep < _cnt) {
		foreach (ValueList, pValue, _valListRemain) {
			valList.push_back(*pValue);
		}
		_valListRemain.clear();
		bool newElemFlag = false;
		while (valList.size() < _cnt) {
			if (!_pIterator->Next(env, valueElem)) {
				_doneFlag = true;
				break;
			}
			newElemFlag = true;
			valList.push_back(valueElem);
		}
		if (!newElemFlag || sig.IsSignalled()) return false;
		if (valList.size() > _cntStep) {
			for (ValueList::iterator pValue = valList.begin() + _cntStep;
			 						pValue != valList.end(); pValue++) {
				_valListRemain.push_back(*pValue);
			}
		}
	} else {
		while (valList.size() < _cnt) {
			if (!_pIterator->Next(env, valueElem)) {
				_doneFlag = true;
				break;
			}
			valList.push_back(valueElem);
		}
		if (sig.IsSignalled()) return false;
		for (size_t n = _cntStep - _cnt; n > 0; n--) {
			if (!_pIterator->Next(env, valueElem)) {
				_doneFlag = true;
				break;
			}
		}
		if (sig.IsSignalled()) return false;
	}
	if (valList.empty() || (_neatFlag && valList.size() < _cnt)) {
		return false;
	} else if (_listItemFlag) {
		value = valueNext;
	} else {
		Iterator *pIterator = new Object_list::IteratorEach(
							Object_list::GetObject(valueNext)->Reference());
		value = Value(new Object_iterator(env, pIterator));
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
// Iterator_Concat
//-----------------------------------------------------------------------------
Iterator *Iterator_Concat::GetSource()
{
	return _iterOwner.empty()? nullptr : _iterOwner.front();
}

bool Iterator_Concat::DoNext(Environment &env, Value &value)
{
	for ( ; _ppIterator != _iterOwner.end(); _ppIterator++) {
		Iterator *pIterator = *_ppIterator;
		if (pIterator->Next(env, value)) return true;
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

bool Iterator_Walk::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	while (_pIteratorCur != nullptr) {
		if (_pIteratorCur->Next(env, value)) {
			if (value.Is_list()) {
				if (!_walkListFlag) return true;
			} else if (value.Is_iterator()) {
				if (!_walkIteratorFlag) return true;
			} else {
				return true;
			}
			Iterator *pIterator = value.CreateIterator(sig);
			if (pIterator == nullptr) return false;
			_iterDeque.push_back(pIterator);
			if (_mode == MODE_DepthFirstSearch) {
				_pIteratorCur = pIterator;
			}
		} else {
			Iterator::Delete(_pIteratorCur);
			if (_mode == MODE_DepthFirstSearch) {
				_iterDeque.pop_back();
				_pIteratorCur = _iterDeque.empty()? nullptr : _iterDeque.back();
			} else { // _mode == MODE_BreadthFirstSearch
				_iterDeque.pop_front();
				_pIteratorCur = _iterDeque.empty()? nullptr : _iterDeque.front();
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
Iterator_Repeater::Iterator_Repeater(Environment *pEnv, Function *pFuncBlock,
					bool skipInvalidFlag, bool genIterFlag, Iterator *pIteratorSrc) :
		Iterator(pIteratorSrc->IsInfinite(), skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(nullptr), _pIteratorSrc(pIteratorSrc), _idx(0), _doneFlag(false)
{
}

Iterator *Iterator_Repeater::GetSource()
{
	return _pIteratorSrc.get();
}

bool Iterator_Repeater::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_doneFlag) return false;
	for (;;) {
		if (_pIteratorNest.IsNull()) {
			Value valueSrc;
			AutoPtr<Argument> pArg(new Argument(_pFuncBlock.get()));
			if (!_pIteratorSrc->Next(env, valueSrc)) return false;
			if (!pArg->AddValue(env, valueSrc)) return false;
			for (Iterator *pIteratorSrc = _pIteratorSrc.get();
					pIteratorSrc != nullptr; pIteratorSrc = pIteratorSrc->GetSource()) {
				if (!pArg->AddValue(env, Value(static_cast<Number>(
												   pIteratorSrc->GetIndexCur())))) return false;
			}
			value = _pFuncBlock->Eval(*_pEnv, *pArg);
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
		} else if (_pIteratorNest->Next(env, value)) {
			break;
		} else {
			_pIteratorNest.reset(nullptr);
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
Iterator_repeat::Iterator_repeat(Environment *pEnv, Function *pFuncBlock,
					bool skipInvalidFlag, bool genIterFlag, int cnt) :
		Iterator(cnt < 0, skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(nullptr), _cnt(cnt), _idx(0), _doneFlag(false)
{
}

Iterator *Iterator_repeat::GetSource()
{
	return nullptr;
}

bool Iterator_repeat::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_doneFlag) return false;
	for (;;) {
		if (_pIteratorNest.IsNull()) {
			if (_cnt >= 0 && _idx >= _cnt) return false;
			AutoPtr<Argument> pArg(new Argument(_pFuncBlock.get()));
			if (!pArg->AddValue(env, Value(static_cast<Number>(_idx)))) return false;
			value = _pFuncBlock->Eval(*_pEnv, *pArg);
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
		} else if (_pIteratorNest->Next(env, value)) {
			break;
		} else {
			_pIteratorNest.reset(nullptr);
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
Iterator_while::Iterator_while(Environment *pEnv, Function *pFuncBlock,
					bool skipInvalidFlag, bool genIterFlag, Expr *pExpr) :
		Iterator(false, skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(nullptr), _pExpr(Expr::Reference(pExpr)), _idx(0), _doneFlag(false)
{
}

Iterator *Iterator_while::GetSource()
{
	return nullptr;
}

bool Iterator_while::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_doneFlag) return false;
	for (;;) {
		if (_pIteratorNest.IsNull()) {
			if (!_pExpr->Exec(*_pEnv).GetBoolean()) return false;
			AutoPtr<Argument> pArg(new Argument(_pFuncBlock.get()));
			if (!pArg->AddValue(env, Value(static_cast<Number>(_idx)))) return false;
			value = _pFuncBlock->Eval(*_pEnv, *pArg);
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
		} else if (_pIteratorNest->Next(env, value)) {
			break;
		} else {
			_pIteratorNest.reset(nullptr);
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
Iterator_for::Iterator_for(Environment *pEnv, Function *pFuncBlock,
			bool skipInvalidFlag, bool genIterFlag, const ValueList &valListArg) :
		Iterator(false, skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(nullptr), _idx(0), _doneFlag(false)
{
	PrepareRepeaterIterators(*_pEnv, valListArg, _exprLeftList, _iteratorOwner);
}

Iterator *Iterator_for::GetSource()
{
	return nullptr;
}

bool Iterator_for::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	for (;;) {
		if (_pIteratorNest.IsNull()) {
			if (_doneFlag) return false;
			ExprList::iterator ppExprLeft = _exprLeftList.begin();
			foreach_const (IteratorOwner, ppIterator, _iteratorOwner) {
				Iterator *pIterator = *ppIterator;
				Value valueVar;
				if (!pIterator->Next(env, valueVar)) {
					if (sig.IsSignalled()) return false;
					_doneFlag = true;
					break;
				}
				// same effect as assign operator
				(*ppExprLeft)->Assign(*_pEnv, valueVar, nullptr, false);
				if (sig.IsSignalled()) return false;
				ppExprLeft++;
			}
			if (_doneFlag) return false;
			AutoPtr<Argument> pArg(new Argument(_pFuncBlock.get()));
			if (!pArg->AddValue(env, Value(static_cast<Number>(_idx)))) return false;
			value = _pFuncBlock->Eval(*_pEnv, *pArg);
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
		} else if (_pIteratorNest->Next(env, value)) {
			break;
		} else {
			_pIteratorNest.reset(nullptr);
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
Iterator_cross::Iterator_cross(Environment *pEnv, Function *pFuncBlock,
			bool skipInvalidFlag, bool genIterFlag, const ValueList &valListArg) :
		Iterator(false, skipInvalidFlag, true), _pEnv(pEnv), _pFuncBlock(pFuncBlock),
		_genIterFlag(genIterFlag),
		_pIteratorNest(nullptr), _idx(0), _doneFlag(true)
{
	Signal &sig = pEnv->GetSignal();
	if (!PrepareRepeaterIterators(*_pEnv, valListArg,
									_exprLeftList, _iteratorOwnerOrg)) return;
	_valListArg.reserve(_iteratorOwnerOrg.size() + 1);
	_iteratorOwner.reserve(_iteratorOwnerOrg.size());
	_valListArg.push_back(Value(0));
	ExprList::iterator ppExprLeft = _exprLeftList.begin();
	foreach (IteratorOwner, ppIteratorOrg, _iteratorOwnerOrg) {
		Iterator *pIterator = (*ppIteratorOrg)->Clone();
		Value valueVar;
		bool rtn = pIterator->Next(*_pEnv, valueVar);
		if (sig.IsSignalled()) return;
		if (rtn) {
			_doneFlag = false;
			_valListArg.push_back(Value(0));
			_iteratorOwner.push_back(pIterator);
		} else {
			_iteratorOwner.push_back(nullptr);
			_valListArg.push_back(Value::Nil);
			Iterator::Delete(pIterator);
		}
		(*ppExprLeft)->Assign(*_pEnv, valueVar, nullptr, false);
		if (sig.IsSignalled()) return;
		ppExprLeft++;
	}
}

Iterator *Iterator_cross::GetSource()
{
	return nullptr;
}

bool Iterator_cross::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	for (;;) {
		if (_pIteratorNest.IsNull()) {
			if (_doneFlag) return false;
			_valListArg[0] = Value(_idx);
			AutoPtr<Argument> pArg(new Argument(_pFuncBlock.get()));
			if (!pArg->AddValues(env, _valListArg)) return false;
			value = _pFuncBlock->Eval(*_pEnv, *pArg);
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
					if (!AdvanceIterators(env)) return false;
					continue;
				}
			} else if (sig.IsSignalled()) {
				return false;
			}
			if (!_genIterFlag || !value.Is_iterator() ||
									!value.GetIterator()->IsRepeater()) {
				if (!AdvanceIterators(env)) return false;
				break;
			}
			_pIteratorNest.reset(Reference(value.GetIterator()));
		} else if (_pIteratorNest->Next(env, value)) {
			break;
		} else {
			_pIteratorNest.reset(nullptr);
			if (sig.IsSignalled()) return false;
			if (!AdvanceIterators(env)) return false;
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

bool Iterator_cross::AdvanceIterators(Environment &env)
{
	Signal &sig = env.GetSignal();
	ExprList::reverse_iterator ppExprLeft = _exprLeftList.rbegin();
	ValueList::reverse_iterator pValueArg = _valListArg.rbegin();
	IteratorOwner::reverse_iterator ppIteratorOrg = _iteratorOwnerOrg.rbegin();
	foreach_reverse (IteratorOwner, ppIterator, _iteratorOwner) {
		Iterator *pIterator = *ppIterator;
		Value valueVar;
		if (pIterator != nullptr) {
			if (pIterator->Next(env, valueVar)) {
				*pValueArg = Value(pValueArg->GetNumber() + 1);
				(*ppExprLeft)->Assign(*_pEnv, valueVar, nullptr, false);
				if (sig.IsSignalled()) return false;
				break;
			}
			if (sig.IsSignalled()) return false;
			Iterator::Delete(pIterator);
			pIterator = (*ppIteratorOrg)->Clone();
			pIterator->Next(env, valueVar);
			if (sig.IsSignalled()) return false;
			(*ppExprLeft)->Assign(*_pEnv, valueVar, nullptr, false);
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
bool PrepareRepeaterIterators(Environment &env,
	const ValueList &valListArg, ExprList &exprLeftList, IteratorOwner &iteratorOwner)
{
	Signal &sig = env.GetSignal();
	foreach_const (ValueList, pValue, valListArg) {
		GURA_ASSUME(env, pValue->Is_expr());
		const Expr *pExpr = pValue->GetExpr();
		Value value;
		if (!(pExpr->IsBinaryOp() && dynamic_cast<const Expr_BinaryOp *>(pExpr)->
										GetOperator()->GetOpType() == OPTYPE_Contains)) {
			sig.SetError(ERR_TypeError, "iteratable must be specified as arguments");
			return false;
		}
		const Expr_BinaryOp *pExprBin = dynamic_cast<const Expr_BinaryOp *>(pExpr);
		value = pExprBin->GetRight()->Exec(env);
		if (sig.IsSignalled()) return false;
		Iterator *pIterator = value.CreateIterator(sig);
		if (pIterator == nullptr) return false;
		exprLeftList.push_back(const_cast<Expr *>(pExprBin->GetLeft()));
		iteratorOwner.push_back(pIterator);
	}
	return true;
}

}
