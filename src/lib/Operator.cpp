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
	if (iter != map.end()) return iter->second;
	iter = map.find(CalcKey(VTYPE_any));
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
// UnaryOperator(Invert, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Invert, number)
{
	unsigned long num = ~static_cast<unsigned long>(value.GetNumber());
	return Value(static_cast<Number>(num));
}

//-----------------------------------------------------------------------------
// UnaryOperator(Not, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Not, any)
{
	bool rtn = !value.GetBoolean();
	return Value(rtn);
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

//-----------------------------------------------------------------------------
// BinaryOperator(Minus, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Minus, number, number)
{
	return Value(valueLeft.GetNumber() - valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Minus, complex, complex)
{
	return Value(valueLeft.GetComplex() - valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Minus, number, complex)
{
	return Value(valueLeft.GetNumber() - valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Minus, complex, number)
{
	return Value(valueLeft.GetComplex() - valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Minus, matrix, matrix)
{
	return Matrix::OperatorPlusMinus(env, sig, OPTYPE_Minus,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Minus, datetime, timedelta)
{
	DateTime dateTime = valueLeft.GetDateTime();
	dateTime.Minus(valueRight.GetTimeDelta());
	return Value(env, dateTime);
}

Gura_ImplementBinaryOperator(Minus, datetime, datetime)
{
	const DateTime &dt1 = valueLeft.GetDateTime();
	const DateTime &dt2 = valueRight.GetDateTime();
	if ((dt1.HasTZOffset() && !dt2.HasTZOffset()) ||
								(!dt1.HasTZOffset() && dt2.HasTZOffset())) {
		sig.SetError(ERR_ValueError, "failed to calculate datetime difference");
		return Value::Null;
	}
	return Value(env, dt1.Minus(dt2));
}

Gura_ImplementBinaryOperator(Minus, timedelta, timedelta)
{
	TimeDelta td1 = valueLeft.GetTimeDelta();
	TimeDelta td2 = valueRight.GetTimeDelta();
	return Value(env, TimeDelta(
			td1.GetDays() - td2.GetDays(),
			td1.GetSecsRaw() - td2.GetSecsRaw(),
			td1.GetUSecs() - td2.GetUSecs()));
}

Gura_ImplementBinaryOperator(Minus, color, color)
{
	const Color &color1 = Object_color::GetObject(valueLeft)->GetColor();
	const Color &color2 = Object_color::GetObject(valueRight)->GetColor();
	return Value(::sqrt(static_cast<double>(color1.CalcDist(color2))));
}

Gura_ImplementBinaryOperator(Minus, binaryptr, number)
{
	AutoPtr<Object_binaryptr> pObj(dynamic_cast<Object_binaryptr *>(
						Object_binaryptr::GetObject(valueLeft)->Clone()));
	pObj->UnpackForward(sig,
						-static_cast<int>(valueRight.GetNumber()), true);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj.release());
}

Gura_ImplementBinaryOperator(Minus, binaryptr, binaryptr)
{
	const Object_binaryptr *pObj1 = Object_binaryptr::GetObject(valueLeft);
	const Object_binaryptr *pObj2 = Object_binaryptr::GetObject(valueRight);
	if (&pObj1->GetBinary() != &pObj2->GetBinary()) {
		sig.SetError(ERR_ValueError,
			"cannot calculate difference between pointers of different binaries");
		return Value::Null;
	}
	int offset1 = static_cast<int>(pObj1->GetOffset());
	int offset2 = static_cast<int>(pObj2->GetOffset());
	return Value(static_cast<Number>(offset1 - offset2));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Multiply, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Multiply, number, number)
{
	return Value(valueLeft.GetNumber() * valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Multiply, complex, complex)
{
	return Value(valueLeft.GetComplex() * valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Multiply, number, complex)
{
	return Value(valueLeft.GetNumber() * valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Multiply, complex, number)
{
	return Value(valueLeft.GetComplex() * valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Multiply, matrix, matrix)
{
	return Matrix::OperatorMultiply(env, sig,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Multiply, list, matrix)
{
	return Matrix::OperatorMultiply(env, sig,
			valueLeft.GetList(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Multiply, any, matrix)
{
	return Matrix::OperatorMultiply(env, sig,
			valueLeft, Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Multiply, matrix, list)
{
	return Matrix::OperatorMultiply(env, sig,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight.GetList());
}

Gura_ImplementBinaryOperator(Multiply, matrix, any)
{
	return Matrix::OperatorMultiply(env, sig,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight);
}

Gura_ImplementBinaryOperator(Multiply, timedelta, number)
{
	const TimeDelta &td = valueLeft.GetTimeDelta();
	long num = valueRight.GetLong();
	return Value(env,
		TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num));
}

Gura_ImplementBinaryOperator(Multiply, number, timedelta)
{
	const TimeDelta &td = valueRight.GetTimeDelta();
	long num = valueLeft.GetLong();
	return Value(env,
		TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num));
}

Gura_ImplementBinaryOperator(Multiply, function, any)
{
	const Object_function *pObj = Object_function::GetObject(valueLeft);
	if (pObj->GetFunction()->IsUnary()) {
		ValueList valListArg(valueRight);
		Value result = pObj->Eval(env, sig, valListArg);
		if (sig.IsSignalled()) return Value::Null;
		return result;
	} else {
		sig.SetError(ERR_TypeError, "unary function is expected for multiplier-form applier");
		return Value::Null;
	}
}

Gura_ImplementBinaryOperator(Multiply, string, number)
{
	String str;
	for (int cnt = static_cast<int>(valueRight.GetNumber()); cnt > 0; cnt--) {
		str += valueLeft.GetString();
	}
	return Value(env, str);
}

Gura_ImplementBinaryOperator(Multiply, number, string)
{
	String str;
	for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
		str += valueRight.GetString();
	}
	return Value(env, str);
}

Gura_ImplementBinaryOperator(Multiply, binary, number)
{
	Binary buff;
	for (int cnt = static_cast<int>(valueRight.GetNumber()); cnt > 0; cnt--) {
		buff += valueLeft.GetBinary();
	}
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Multiply, number, binary)
{
	Binary buff;
	for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
		buff += valueRight.GetBinary();
	}
	return Value(new Object_binary(env, buff, true));
}

#if 0
//-----------------------------------------------------------------------------
// BinaryOperator(Divide, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Divide, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Modulo, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Modulo, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Power, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Power, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Equal, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Equal, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(NotEqual, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(NotEqual, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Greater, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Greater, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Less, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Less, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(GreaterEq, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(GreaterEq, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(LessEq, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(LessEq, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Compare, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Compare, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(ContainCheck, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(ContainCheck, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Or, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Or, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(And, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(And, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Xor, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Xor, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(ShiftL, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(ShiftL, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(ShiftR, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(ShiftR, number, number)

//-----------------------------------------------------------------------------
// BinaryOperator(Sequence, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Sequence, number, number)

//-----------------------------------------------------------------------------
// UnaryOperator(SequenceInf, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(SequenceInf, number)
{
#endif

void AssignBasicOperators(Environment &env)
{
	Gura_AssignUnaryOperator(Pos, number);
	Gura_AssignUnaryOperator(Pos, complex);
	Gura_AssignUnaryOperator(Pos, matrix);
	Gura_AssignUnaryOperator(Pos, timedelta);
	Gura_AssignUnaryOperator(Neg, number);
	Gura_AssignUnaryOperator(Neg, complex);
	Gura_AssignUnaryOperator(Neg, matrix);
	Gura_AssignUnaryOperator(Neg, timedelta);
	Gura_AssignUnaryOperator(Invert, number);
	Gura_AssignUnaryOperator(Not, any);
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
	Gura_AssignBinaryOperator(Minus, number, number);
	Gura_AssignBinaryOperator(Minus, complex, complex);
	Gura_AssignBinaryOperator(Minus, number, complex);
	Gura_AssignBinaryOperator(Minus, complex, number);
	Gura_AssignBinaryOperator(Minus, matrix, matrix);
	Gura_AssignBinaryOperator(Minus, datetime, timedelta);
	Gura_AssignBinaryOperator(Minus, datetime, datetime);
	Gura_AssignBinaryOperator(Minus, timedelta, timedelta);
	Gura_AssignBinaryOperator(Minus, color, color);
	Gura_AssignBinaryOperator(Minus, binaryptr, number);
	Gura_AssignBinaryOperator(Minus, binaryptr, binaryptr);
	Gura_AssignBinaryOperator(Multiply, number, number);
	Gura_AssignBinaryOperator(Multiply, complex, complex);
	Gura_AssignBinaryOperator(Multiply, number, complex);
	Gura_AssignBinaryOperator(Multiply, complex, number);
	Gura_AssignBinaryOperator(Multiply, matrix, matrix);
	Gura_AssignBinaryOperator(Multiply, list, matrix);
	Gura_AssignBinaryOperator(Multiply, any, matrix);
	Gura_AssignBinaryOperator(Multiply, matrix, list);
	Gura_AssignBinaryOperator(Multiply, matrix, any);
	Gura_AssignBinaryOperator(Multiply, timedelta, number);
	Gura_AssignBinaryOperator(Multiply, number, timedelta);
	Gura_AssignBinaryOperator(Multiply, function, any);
	Gura_AssignBinaryOperator(Multiply, string, number);
	Gura_AssignBinaryOperator(Multiply, number, string);
	Gura_AssignBinaryOperator(Multiply, binary, number);
	Gura_AssignBinaryOperator(Multiply, number, binary);
}

}
