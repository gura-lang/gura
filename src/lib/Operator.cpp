#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Operator
//-----------------------------------------------------------------------------
Value Operator::DoEval(Environment &env, Signal sig, const Value &value) const
{
	return Value::Null;
}

Value Operator::DoEval(Environment &env, Signal sig,
				const Value &valueLeft, const Value &valueRight) const
{
	return Value::Null;
}

void Operator::Assign(Environment &env, Operator *pOperator)
{
	OperatorMap &map = env.GetGlobal()->GetOperatorMap(pOperator->GetOpType());
	Key key = pOperator->CalcKey();
	OperatorMap::iterator iter = map.find(key);
	if (iter == map.end()) {
		map[key] = pOperator;
	} else {
		delete iter->second;
		iter->second = pOperator;
	}
}

const Operator *Operator::Lookup(Environment &env, OpType opType, ValueType valType)
{
	OperatorMap &map = env.GetGlobal()->GetOperatorMap(opType);
	OperatorMap::const_iterator iter = map.find(CalcKey(valType));
	return (iter == map.end())? NULL : iter->second;
}

const Operator *Operator::Lookup(Environment &env, OpType opType, ValueType valTypeLeft, ValueType valTypeRight)
{
	OperatorMap &map = env.GetGlobal()->GetOperatorMap(opType);
	OperatorMap::const_iterator iter = map.find(CalcKey(valTypeLeft, valTypeRight));
	return (iter == map.end())? NULL : iter->second;
}

Gura_ImplementUnaryOperator(Pos, number)
{
	return value;
}

Gura_ImplementBinaryOperator(Plus, number, number)
{
	return Value(valueLeft.GetNumber() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Plus, complex, complex)
{
	return Value(valueLeft.GetComplex() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Plus, number, complex)
{
	return Value(valueLeft.GetNumber() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Plus, complex, number)
{
	return Value(valueLeft.GetComplex() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Plus, matrix, matrix)
{
	return Matrix::OperatorPlusMinus(env, sig, OPTYPE_Plus,
		Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

#if 0
	} else if (valueLeft.IsDateTime() && valueRight.IsTimeDelta()) {
		DateTime dateTime = valueLeft.GetDateTime();
		dateTime.Plus(valueRight.GetTimeDelta());
		return Value(env, dateTime);
	} else if (valueLeft.IsTimeDelta() && valueRight.IsDateTime()) {
		DateTime dateTime = valueRight.GetDateTime();
		dateTime.Plus(valueLeft.GetTimeDelta());
		return Value(env, dateTime);
	} else if (valueLeft.IsTimeDelta() && valueRight.IsTimeDelta()) {
		TimeDelta td1 = valueLeft.GetTimeDelta();
		TimeDelta td2 = valueRight.GetTimeDelta();
		return Value(env, TimeDelta(
				td1.GetDays() + td2.GetDays(),
				td1.GetSecsRaw() + td2.GetSecsRaw(),
				td1.GetUSecs() + td2.GetUSecs()));
	} else if (valueLeft.IsString() && valueRight.IsString()) {
		String str(valueLeft.GetString());
		str += valueRight.GetString();
		result = Value(env, str.c_str());
		return result;
	} else if (valueLeft.IsBinary() && valueRight.IsBinary()) {
		Binary buff(valueLeft.GetBinary());
		buff += valueRight.GetBinary();
		result = Value(new Object_binary(env, buff, true));
		return result;
	} else if (valueLeft.IsBinary() && valueRight.IsString()) {
		Binary buff(valueLeft.GetBinary());
		buff += valueRight.GetString();
		result = Value(new Object_binary(env, buff, true));
		return result;
	} else if (valueLeft.IsString() && valueRight.IsBinary()) {
		Binary buff;
		buff += valueLeft.GetString();
		buff += valueRight.GetBinary();
		result = Value(new Object_binary(env, buff, true));
		return result;
	} else if (valueLeft.IsBinaryPtr() && valueRight.IsNumber()) {
		Object_binaryptr *pObj =
			dynamic_cast<Object_binaryptr *>(Object_binaryptr::GetObject(valueLeft)->Clone());
		pObj->UnpackForward(sig,
							static_cast<int>(valueRight.GetNumber()), true);
		if (sig.IsSignalled()) return Value::Null;
		Value result;
		result.InitAsObject(pObj);
		return result;
#endif

void AssignBasicOperators(Environment &env)
{
	Gura_AssignUnaryOperator(Pos, number);
	Gura_AssignBinaryOperator(Plus, number, number);
}

}
