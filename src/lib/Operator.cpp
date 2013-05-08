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
	if (iter != map.end()) return iter->second;
	iter = map.find(CalcKey(valTypeLeft, VTYPE_any));
	if (iter != map.end()) return iter->second;
	iter = map.find(CalcKey(VTYPE_any, valTypeRight));
	return (iter == map.end())? NULL : iter->second;
}

//-----------------------------------------------------------------------------
// UnaryOperator(Pos, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Pos, number)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, complex)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, matrix)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, timedelta)
{
	return value;
}

//-----------------------------------------------------------------------------
// UnaryOperator(Neg, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Neg, number)
{
	return Value(-value.GetNumber());
}

Gura_ImplementUnaryOperator(Neg, complex)
{
	return Value(-value.GetComplex());
}

Gura_ImplementUnaryOperator(Neg, matrix)
{
	return Matrix::OperatorNeg(env, sig, Object_matrix::GetObject(value)->GetMatrix());
}

Gura_ImplementUnaryOperator(Neg, timedelta)
{
	TimeDelta td = value.GetTimeDelta();
	return Value(env, TimeDelta(-td.GetDays(), -td.GetSecsRaw(), -td.GetUSecs()));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Plus, *, *)
//-----------------------------------------------------------------------------
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

Gura_ImplementBinaryOperator(Plus, datetime, timedelta)
{
	DateTime dateTime = valueLeft.GetDateTime();
	dateTime.Plus(valueRight.GetTimeDelta());
	return Value(env, dateTime);
}

Gura_ImplementBinaryOperator(Plus, timedelta, datetime)
{
	DateTime dateTime = valueRight.GetDateTime();
	dateTime.Plus(valueLeft.GetTimeDelta());
	return Value(env, dateTime);
}

Gura_ImplementBinaryOperator(Plus, timedelta, timedelta)
{
	TimeDelta td1 = valueLeft.GetTimeDelta();
	TimeDelta td2 = valueRight.GetTimeDelta();
	return Value(env, TimeDelta(
			td1.GetDays() + td2.GetDays(),
			td1.GetSecsRaw() + td2.GetSecsRaw(),
			td1.GetUSecs() + td2.GetUSecs()));
}

Gura_ImplementBinaryOperator(Plus, string, string)
{
	String str(valueLeft.GetString());
	str += valueRight.GetString();
	return Value(env, str.c_str());
}

Gura_ImplementBinaryOperator(Plus, binary, binary)
{
	Binary buff(valueLeft.GetBinary());
	buff += valueRight.GetBinary();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Plus, binary, string)
{
	Binary buff(valueLeft.GetBinary());
	buff += valueRight.GetString();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Plus, string, binary)
{
	Binary buff;
	buff += valueLeft.GetString();
	buff += valueRight.GetBinary();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Plus, binaryptr, number)
{
	Object_binaryptr *pObj = dynamic_cast<Object_binaryptr *>(
						Object_binaryptr::GetObject(valueLeft)->Clone());
	pObj->UnpackForward(sig,
						static_cast<int>(valueRight.GetNumber()), true);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj);
}

Gura_ImplementBinaryOperator(Plus, string, any)
{
	String str(valueLeft.GetString());
	str += valueRight.ToString(sig);
	return Value(env, str.c_str());
}

Gura_ImplementBinaryOperator(Plus, any, string)
{
	String str(valueLeft.ToString(sig));
	str += valueRight.GetString();
	return Value(env, str.c_str());
}

void AssignBasicOperators(Environment &env)
{
	// UnaryOperator(Pos, *)
	Gura_AssignUnaryOperator(Pos, number);
	Gura_AssignUnaryOperator(Pos, complex);
	Gura_AssignUnaryOperator(Pos, matrix);
	Gura_AssignUnaryOperator(Pos, timedelta);
	// UnaryOperator(Neg, *)
	Gura_AssignUnaryOperator(Neg, number);
	Gura_AssignUnaryOperator(Neg, complex);
	Gura_AssignUnaryOperator(Neg, matrix);
	Gura_AssignUnaryOperator(Neg, timedelta);
	// BinaryOperator(Plus, *, *)
	Gura_AssignBinaryOperator(Plus, number, number);
	Gura_AssignBinaryOperator(Plus, complex, complex);
	Gura_AssignBinaryOperator(Plus, number, complex);
	Gura_AssignBinaryOperator(Plus, complex, number);
	Gura_AssignBinaryOperator(Plus, matrix, matrix);
	Gura_AssignBinaryOperator(Plus, datetime, timedelta);
	Gura_AssignBinaryOperator(Plus, timedelta, datetime);
	Gura_AssignBinaryOperator(Plus, timedelta, timedelta);
	Gura_AssignBinaryOperator(Plus, string, string);
	Gura_AssignBinaryOperator(Plus, binary, binary);
	Gura_AssignBinaryOperator(Plus, binary, string);
	Gura_AssignBinaryOperator(Plus, string, binary);
	Gura_AssignBinaryOperator(Plus, binaryptr, number);
	Gura_AssignBinaryOperator(Plus, string, any);
	Gura_AssignBinaryOperator(Plus, any, string);
}

}
