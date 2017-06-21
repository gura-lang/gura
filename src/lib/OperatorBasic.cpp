//=============================================================================
// OperatorBasic
//=============================================================================
#include "stdafx.h"
#include <math.h>

namespace Gura {

//-----------------------------------------------------------------------------
// [+A] ... UnaryOperator(Pos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Pos, number)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, complex)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, rational)
{
	Signal &sig = env.GetSignal();
	const Rational &a = value.GetRational();
	if (a.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	if (a.numer == 0) return Value::Zero;
	return Value(+a);
}

Gura_ImplementUnaryOperator(Pos, timedelta)
{
	return value;
}

//-----------------------------------------------------------------------------
// [-A] ... UnaryOperator(Neg, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Neg, number)
{
	return Value(-value.GetDouble());
}

Gura_ImplementUnaryOperator(Neg, complex)
{
	return Value(-value.GetComplex());
}

Gura_ImplementUnaryOperator(Neg, rational)
{
	Signal &sig = env.GetSignal();
	const Rational &a = value.GetRational();
	if (a.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	if (a.numer == 0) return Value::Zero;
	return Value(-a);
}

Gura_ImplementUnaryOperator(Neg, timedelta)
{
	TimeDelta td = Object_timedelta::GetObject(value)->GetTimeDelta();
	return Value(new Object_timedelta(env, TimeDelta(-td.GetDays(), -td.GetSecsRaw(), -td.GetUSecs())));
}

Gura_ImplementUnaryOperator(Neg, vertex)
{
	const Vertex &vertex = Object_vertex::GetObject(value)->GetVertex();
	return Value(new Object_vertex(env, Vertex(-vertex.x, -vertex.y, -vertex.z)));
}

//-----------------------------------------------------------------------------
// [~A] ... UnaryOperator(Invert, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Inv, number)
{
	ULong num = ~value.GetULong();
	return Value(num);
}

//-----------------------------------------------------------------------------
// [!A] ... UnaryOperator(Not, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Not, any)
{
	bool rtn = !value.GetBoolean();
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// [A..] ... UnaryOperator(SeqInf, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(SeqInf, number)
{
	Number numBegin = value.GetDouble();
	return Value(new Object_iterator(env, new Iterator_SequenceInf(numBegin)));
}

//-----------------------------------------------------------------------------
// [A?] ... UnaryOperator(Question, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Question, any)
{
	bool rtn = value.GetBoolean();
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// [A*] ... UnaryOperator(Each, A)
//-----------------------------------------------------------------------------
//************* conflict with argument expansion in a function call ***********
Gura_ImplementUnaryOperator(Each, any)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
	if (pIterator.IsNull()) return Value::Nil;
	return Value(new Object_iterator(env, pIterator.release()));
}

//-----------------------------------------------------------------------------
// [A+] ... UnaryOperator(PostPos, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A%] ... UnaryOperator(PostMod, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A + B] ... BinaryOperator(Add, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Add, number, number)
{
	return Value(valueLeft.GetDouble() + valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Add, boolean, boolean)
{
	return Value(valueLeft.GetDouble() + valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Add, number, boolean)
{
	return Value(valueLeft.GetDouble() + valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Add, boolean, number)
{
	return Value(valueLeft.GetDouble() + valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Add, complex, complex)
{
	return Value(valueLeft.GetComplex() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Add, rational, rational)
{
	Signal &sig = env.GetSignal();
	const Rational &a = valueLeft.GetRational();
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a + b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Add, rational, number)
{
	Signal &sig = env.GetSignal();
	const Rational &a = valueLeft.GetRational();
	const Rational b = Rational::FromNumber(valueRight.GetDouble());
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a + b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Add, number, rational)
{
	Signal &sig = env.GetSignal();
	const Rational a = Rational::FromNumber(valueLeft.GetDouble());
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a + b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Add, number, complex)
{
	return Value(valueLeft.GetDouble() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Add, complex, number)
{
	return Value(valueLeft.GetComplex() + valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Add, datetime, timedelta)
{
	DateTime dateTime = Object_datetime::GetObject(valueLeft)->GetDateTime();
	const TimeDelta &timeDelta = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	dateTime.Plus(timeDelta);
	return Value(new Object_datetime(env, dateTime));
}

Gura_ImplementBinaryOperator(Add, timedelta, datetime)
{
	const TimeDelta &timeDelta = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	DateTime dateTime = Object_datetime::GetObject(valueRight)->GetDateTime();
	dateTime.Plus(timeDelta);
	return Value(new Object_datetime(env, dateTime));
}

Gura_ImplementBinaryOperator(Add, timedelta, timedelta)
{
	TimeDelta td1 = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	TimeDelta td2 = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	return Value(new Object_timedelta(env, TimeDelta(
			td1.GetDays() + td2.GetDays(),
			td1.GetSecsRaw() + td2.GetSecsRaw(),
			td1.GetUSecs() + td2.GetUSecs())));
}

Gura_ImplementBinaryOperator(Add, string, string)
{
	String str(valueLeft.GetString());
	str += valueRight.GetString();
	return Value(str);
}

Gura_ImplementBinaryOperator(Add, binary, binary)
{
	Binary buff(valueLeft.GetBinary());
	buff += valueRight.GetBinary();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Add, binary, string)
{
	Binary buff(valueLeft.GetBinary());
	buff += valueRight.GetString();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Add, string, binary)
{
	Binary buff;
	buff += valueLeft.GetString();
	buff += valueRight.GetBinary();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Add, pointer, number)
{
	AutoPtr<Object_pointer> pObj(dynamic_cast<Object_pointer *>(
						Object_pointer::GetObject(valueLeft)->Clone()));
	if (!pObj->GetPointer()->Advance(env, valueRight.GetInt())) return Value::Nil;
	return Value(pObj.release());
}

Gura_ImplementBinaryOperator(Add, string, any)
{
	String str(valueLeft.GetString());
	str += valueRight.ToString();
	return Value(str);
}

Gura_ImplementBinaryOperator(Add, any, string)
{
	String str(valueLeft.ToString());
	str += valueRight.GetString();
	return Value(str);
}

Gura_ImplementBinaryOperator(Add, vertex, vertex)
{
	const Vertex &vertexL = Object_vertex::GetObject(valueLeft)->GetVertex();
	const Vertex &vertexR = Object_vertex::GetObject(valueRight)->GetVertex();
	return Value(new Object_vertex(env, Vertex(
									   vertexL.x + vertexR.x,
									   vertexL.y + vertexR.y,
									   vertexL.z + vertexR.z)));
}

//-----------------------------------------------------------------------------
// [A - B] ... BinaryOperator(Sub, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Sub, number, number)
{
	return Value(valueLeft.GetDouble() - valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Sub, boolean, boolean)
{
	return Value(valueLeft.GetDouble() - valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Sub, number, boolean)
{
	return Value(valueLeft.GetDouble() - valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Sub, boolean, number)
{
	return Value(valueLeft.GetDouble() - valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Sub, complex, complex)
{
	return Value(valueLeft.GetComplex() - valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Sub, rational, rational)
{
	Signal &sig = env.GetSignal();
	const Rational &a = valueLeft.GetRational();
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a - b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Sub, rational, number)
{
	Signal &sig = env.GetSignal();
	const Rational &a = valueLeft.GetRational();
	const Rational b = Rational::FromNumber(valueRight.GetDouble());
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a - b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Sub, number, rational)
{
	Signal &sig = env.GetSignal();
	const Rational a = Rational::FromNumber(valueLeft.GetDouble());
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a - b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Sub, number, complex)
{
	return Value(valueLeft.GetDouble() - valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Sub, complex, number)
{
	return Value(valueLeft.GetComplex() - valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Sub, datetime, timedelta)
{
	DateTime dateTime = Object_datetime::GetObject(valueLeft)->GetDateTime();
	dateTime.Minus(Object_timedelta::GetObject(valueRight)->GetTimeDelta());
	return Value(new Object_datetime(env, dateTime));
}

Gura_ImplementBinaryOperator(Sub, datetime, datetime)
{
	Signal &sig = env.GetSignal();
	const DateTime &dt1 = Object_datetime::GetObject(valueLeft)->GetDateTime();
	const DateTime &dt2 = Object_datetime::GetObject(valueRight)->GetDateTime();
	if ((dt1.HasTZOffset() && !dt2.HasTZOffset()) ||
								(!dt1.HasTZOffset() && dt2.HasTZOffset())) {
		sig.SetError(ERR_ValueError, "failed to calculate datetime difference");
		return Value::Nil;
	}
	return Value(new Object_timedelta(env, dt1.Minus(dt2)));
}

Gura_ImplementBinaryOperator(Sub, timedelta, timedelta)
{
	TimeDelta td1 = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	TimeDelta td2 = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	return Value(new Object_timedelta(env, TimeDelta(
			td1.GetDays() - td2.GetDays(),
			td1.GetSecsRaw() - td2.GetSecsRaw(),
			td1.GetUSecs() - td2.GetUSecs())));
}

Gura_ImplementBinaryOperator(Sub, color, color)
{
	const Color &color1 = Object_color::GetObject(valueLeft)->GetColor();
	const Color &color2 = Object_color::GetObject(valueRight)->GetColor();
	return Value(::sqrt(color1.CalcDistSqu(color2)));
}

Gura_ImplementBinaryOperator(Sub, pointer, number)
{
	AutoPtr<Object_pointer> pObj(dynamic_cast<Object_pointer *>(
						Object_pointer::GetObject(valueLeft)->Clone()));
	if (!pObj->GetPointer()->Advance(env, -valueRight.GetInt())) return Value::Nil;
	return Value(pObj.release());
}

Gura_ImplementBinaryOperator(Sub, pointer, pointer)
{
	const Pointer *pPtr1 = Object_pointer::GetObject(valueLeft)->GetPointer();
	const Pointer *pPtr2 = Object_pointer::GetObject(valueRight)->GetPointer();
	if (pPtr1->GetTarget() != pPtr2->GetTarget()) {
		env.SetError(ERR_ValueError,
			"cannot calculate difference between pointers of different binaries");
		return Value::Nil;
	}
	int offset1 = static_cast<int>(pPtr1->GetOffset());
	int offset2 = static_cast<int>(pPtr2->GetOffset());
	return Value(offset1 - offset2);
}

Gura_ImplementBinaryOperator(Sub, vertex, vertex)
{
	const Vertex &vertexL = Object_vertex::GetObject(valueLeft)->GetVertex();
	const Vertex &vertexR = Object_vertex::GetObject(valueRight)->GetVertex();
	return Value(new Object_vertex(env, Vertex(
									   vertexL.x - vertexR.x,
									   vertexL.y - vertexR.y,
									   vertexL.z - vertexR.z)));
}

//-----------------------------------------------------------------------------
// [A * B] ... BinaryOperator(Mul, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mul, number, number)
{
	return Value(valueLeft.GetDouble() * valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Mul, boolean, boolean)
{
	return Value(valueLeft.GetDouble() * valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Mul, number, boolean)
{
	return Value(valueLeft.GetDouble() * valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Mul, boolean, number)
{
	return Value(valueLeft.GetDouble() * valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Mul, complex, complex)
{
	return Value(valueLeft.GetComplex() * valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Mul, rational, rational)
{
	Signal &sig = env.GetSignal();
	const Rational &a = valueLeft.GetRational();
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a * b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Mul, rational, number)
{
	Signal &sig = env.GetSignal();
	const Rational &a = valueLeft.GetRational();
	const Rational b = Rational::FromNumber(valueRight.GetDouble());
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a * b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Mul, number, rational)
{
	Signal &sig = env.GetSignal();
	const Rational a = Rational::FromNumber(valueLeft.GetDouble());
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a * b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Mul, number, complex)
{
	return Value(valueLeft.GetDouble() * valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Mul, complex, number)
{
	return Value(valueLeft.GetComplex() * valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(Mul, timedelta, number)
{
	const TimeDelta &td = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	long num = valueRight.GetLong();
	return Value(new Object_timedelta(env,
		TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num)));
}

Gura_ImplementBinaryOperator(Mul, number, timedelta)
{
	const TimeDelta &td = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	long num = valueLeft.GetLong();
	return Value(new Object_timedelta(env,
		TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num)));
}

Gura_ImplementBinaryOperator(Mul, function, any)
{
	Signal &sig = env.GetSignal();
	const Object_function *pObj = Object_function::GetObject(valueLeft);
	Value result = pObj->Eval(env, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return result;
}

Gura_ImplementBinaryOperator(Mul, Class, any)
{
	const Class *pClass = valueLeft.GetClassItself();
	const Function *pConstructor = pClass->GetConstructor();
	if (pConstructor == nullptr) {
		pClass->SetError_NoConstructor();
		return Value::Nil;
	}
	AutoPtr<Argument> pArg(new Argument(pConstructor));
	if (pArg->StoreValue(env, valueRight) && pArg->Complete(env)) {
		return pConstructor->Eval(env, *pArg);
	}
	return Value::Nil;
}

Gura_ImplementBinaryOperator(Mul, string, number)
{
	String str;
	for (int cnt = valueRight.GetInt(); cnt > 0; cnt--) {
		str += valueLeft.GetString();
	}
	return Value(str);
}

Gura_ImplementBinaryOperator(Mul, number, string)
{
	String str;
	for (int cnt = valueLeft.GetInt(); cnt > 0; cnt--) {
		str += valueRight.GetString();
	}
	return Value(str);
}

Gura_ImplementBinaryOperator(Mul, binary, number)
{
	Binary buff;
	for (int cnt = valueRight.GetInt(); cnt > 0; cnt--) {
		buff += valueLeft.GetBinary();
	}
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Mul, number, binary)
{
	Binary buff;
	for (int cnt = valueLeft.GetInt(); cnt > 0; cnt--) {
		buff += valueRight.GetBinary();
	}
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Mul, vertex, number)
{
	const Vertex &vertex = Object_vertex::GetObject(valueLeft)->GetVertex();
	double num = valueRight.GetDouble();
	return Value(new Object_vertex(env, Vertex(
									   vertex.x * num,
									   vertex.y * num,
									   vertex.z * num)));
}

Gura_ImplementBinaryOperator(Mul, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Mul, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mul, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Mul, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mul, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Mul, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mul, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Mul, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mul, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Mul, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A / B] ... BinaryOperator(Div, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Div, number, number)
{
	Signal &sig = env.GetSignal();
	Number numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(valueLeft.GetDouble() / numRight);
}

Gura_ImplementBinaryOperator(Div, complex, complex)
{
	Signal &sig = env.GetSignal();
	Complex numRight = valueRight.GetComplex();
	if (numRight == Complex(0.)) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(valueLeft.GetComplex() / valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Div, rational, rational)
{
	Signal &sig = env.GetSignal();
	const Rational &a = valueLeft.GetRational();
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.numer == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a / b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Div, rational, number)
{
	Signal &sig = env.GetSignal();
	const Rational &a = valueLeft.GetRational();
	const Rational b = Rational::FromNumber(valueRight.GetDouble());
	if (a.denom == 0 || b.numer == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a / b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Div, number, rational)
{
	Signal &sig = env.GetSignal();
	const Rational a = Rational::FromNumber(valueLeft.GetDouble());
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.numer == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Nil;
	}
	Rational c = a / b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Div, number, complex)
{
	Signal &sig = env.GetSignal();
	Complex numRight = valueRight.GetComplex();
	if (numRight == Complex(0.)) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(valueLeft.GetDouble() / numRight);
}

Gura_ImplementBinaryOperator(Div, complex, number)
{
	Signal &sig = env.GetSignal();
	Number numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(valueLeft.GetComplex() / numRight);
}

Gura_ImplementBinaryOperator(Div, vertex, number)
{
	Signal &sig = env.GetSignal();
	const Vertex &vertex = Object_vertex::GetObject(valueLeft)->GetVertex();
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(new Object_vertex(env, Vertex(
									   vertex.x / numRight,
									   vertex.y / numRight,
									   vertex.z / numRight)));
}

Gura_ImplementBinaryOperator(Div, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Div, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Div, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Div, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Div, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Div, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Div, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Div, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Div, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Div, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A % B] ... BinaryOperator(Mod, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mod, number, number)
{
	Signal &sig = env.GetSignal();
	Number numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(::fmod(valueLeft.GetDouble(), numRight));
}

Gura_ImplementBinaryOperator(Mod, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Mod, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mod, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Mod, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mod, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Mod, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A %% B] ... BinaryOperator(ModMod, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A |.| B] ... BinaryOperator(DotProd, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(DotProd, number, number)
{
	return Value(valueLeft.GetDouble() * valueRight.GetDouble());
}

Gura_ImplementBinaryOperator(DotProd, array, array)
{
	const Array *pArrayL = Object_array::GetObject(valueLeft)->GetArray();
	const Array *pArrayR = Object_array::GetObject(valueRight)->GetArray();
	return Array::Dot(env, pArrayL, pArrayR);
}

Gura_ImplementBinaryOperator(DotProd, vertex, vertex)
{
	const Vertex &v1 = Object_vertex::GetObject(valueLeft)->GetVertex();
	const Vertex &v2 = Object_vertex::GetObject(valueRight)->GetVertex();
	return Value(Vertex::CalcDotProduct(v1, v2));
}

//-----------------------------------------------------------------------------
// [A |*| B] ... BinaryOperator(CrossProd, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(CrossProd, vertex, vertex)
{
	const Vertex &v1 = Object_vertex::GetObject(valueLeft)->GetVertex();
	const Vertex &v2 = Object_vertex::GetObject(valueRight)->GetVertex();
	return Value(new Object_vertex(env, Vertex::CalcCrossProduct(v1, v2)));
}

//-----------------------------------------------------------------------------
// [A |+| B] ... BinaryOperator(Join, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A |-| B] ... BinaryOperator(Difference, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A |&| B] ... BinaryOperator(Intersection, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A ||| B] ... BinaryOperator(Union, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A ** B] ... BinaryOperator(Pow, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pow, number, number)
{
	return Value(::pow(valueLeft.GetDouble(), valueRight.GetDouble()));
}

Gura_ImplementBinaryOperator(Pow, complex, complex)
{
	Complex result;
	Operator_Pow::Calc(result, valueLeft.GetComplex(), valueRight.GetComplex());
	return Value(result);
}

Gura_ImplementBinaryOperator(Pow, number, complex)
{
	return Value(std::pow(valueLeft.GetDouble(), valueRight.GetComplex()));
}

Gura_ImplementBinaryOperator(Pow, complex, number)
{
	return Value(std::pow(valueLeft.GetComplex(), valueRight.GetDouble()));
}

Gura_ImplementBinaryOperator(Pow, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Pow, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pow, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Pow, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pow, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Pow, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pow, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Pow, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pow, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Pow, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A == B] ... BinaryOperator(Eq, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Eq, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp == 0);
}

Gura_ImplementBinaryOperator(Eq, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Eq, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Eq, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Eq, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Eq, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Eq, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Eq, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Eq, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Eq, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Eq, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A != B] ... BinaryOperator(Ne, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ne, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp != 0);
}

Gura_ImplementBinaryOperator(Ne, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Ne, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ne, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Ne, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ne, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Ne, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ne, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Ne, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ne, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Ne, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A > B] ... BinaryOperator(Gt, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Gt, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp > 0);
}

Gura_ImplementBinaryOperator(Gt, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Gt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Gt, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Gt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Gt, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Gt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Gt, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Gt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Gt, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Gt, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A < B] ... BinaryOperator(Lt, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Lt, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp < 0);
}

Gura_ImplementBinaryOperator(Lt, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Lt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Lt, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Lt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Lt, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Lt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Lt, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Lt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Lt, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Lt, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A >= B] ... BinaryOperator(Ge, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ge, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp >= 0);
}

Gura_ImplementBinaryOperator(Ge, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Ge, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ge, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Ge, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ge, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Ge, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ge, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Ge, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ge, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Ge, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A <= B] ... BinaryOperator(Le, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Le, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp <= 0);
}

Gura_ImplementBinaryOperator(Le, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Le, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Le, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Le, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Le, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Le, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Le, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Le, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Le, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Le, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A <=> B] BinaryOperator(Cmp, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Cmp, boolean, boolean)
{
	return Value(Value::CompareBoolean(valueLeft.GetBoolean(), valueRight.GetBoolean()));
}

Gura_ImplementBinaryOperator(Cmp, complex, complex)
{
	return Value(Value::CompareComplex(valueLeft.GetComplex(), valueRight.GetComplex()));
}

Gura_ImplementBinaryOperator(Cmp, number, number)
{
	return Value(Value::CompareNumber(valueLeft.GetDouble(), valueRight.GetDouble()));
}

Gura_ImplementBinaryOperator(Cmp, rational, rational)
{
	return Value(Value::CompareRational(valueLeft.GetRational(), valueRight.GetRational()));
}

Gura_ImplementBinaryOperator(Cmp, number, rational)
{
	Signal &sig = env.GetSignal();
	const Rational &ratio = valueRight.GetRational();
	if (ratio.denom == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(Value::CompareNumber(valueLeft.GetDouble(), ratio.numer / ratio.denom));
}

Gura_ImplementBinaryOperator(Cmp, rational, number)
{
	Signal &sig = env.GetSignal();
	const Rational &ratio = valueLeft.GetRational();
	if (ratio.denom == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(Value::CompareNumber(ratio.numer / ratio.denom, valueRight.GetDouble()));
}

Gura_ImplementBinaryOperator(Cmp, string, string)
{
	return Value(Value::CompareString(valueLeft.GetString(), valueRight.GetString(), false));
}

Gura_ImplementBinaryOperator(Cmp, symbol, symbol)
{
	return Value(Value::CompareSymbol(valueLeft.GetSymbol(), valueRight.GetSymbol()));
}

Gura_ImplementBinaryOperator(Cmp, binary, binary)
{
	const Binary &buff1 = valueLeft.GetBinary();
	const Binary &buff2 = valueRight.GetBinary();
	return
		(buff1.size() < buff2.size())? -1 :
		(buff1.size() > buff2.size())? +1 :
		::memcmp(buff1.data(), buff2.data(), buff1.size());
}

Gura_ImplementBinaryOperator(Cmp, datetime, datetime)
{
	const DateTime &dt1 = Object_datetime::GetObject(valueLeft)->GetDateTime();
	const DateTime &dt2 = Object_datetime::GetObject(valueRight)->GetDateTime();
	return DateTime::Compare(dt1, dt2);
}

Gura_ImplementBinaryOperator(Cmp, list, list)
{
	Signal &sig = env.GetSignal();
	const ValueList &valList1 = valueLeft.GetList();
	const ValueList &valList2 = valueRight.GetList();
	if (valList1.size() < valList2.size()) return Value(-1);
	if (valList1.size() > valList2.size()) return Value(+1);
	ValueList::const_iterator pValue1 = valList1.begin();
	ValueList::const_iterator pValue2 = valList2.begin();
	for ( ; pValue1 != valList1.end(); pValue1++, pValue2++) {
		int cmp = Value::Compare(env, *pValue1, *pValue2);
		if (sig.IsSignalled()) return Value::Nil;
		if (cmp < 0) return Value(-1);
		if (cmp > 0) return Value(+1);
	}
	return Value(0);
}

Gura_ImplementBinaryOperator(Cmp, timedelta, timedelta)
{
	const TimeDelta &td1 = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	const TimeDelta &td2 = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	return TimeDelta::Compare(td1, td2);
}

//-----------------------------------------------------------------------------
// [A in B] ... BinaryOperator(Contains, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Contains, any, any)
{
	Signal &sig = env.GetSignal();
	if (valueLeft.Is_list() || valueLeft.Is_iterator()) {
		AutoPtr<Iterator_Contains> pIterator(new Iterator_Contains(valueLeft.CreateIterator(sig)));
		if (sig.IsSignalled()) return Value::Nil;
		ValueList &valListToFind = pIterator->GetValueListToFind();
		if (valueRight.Is_list()) {
			valListToFind.Append(valueRight.GetList());
		} else if (valueRight.Is_iterator()) {
			AutoPtr<Iterator> pIteratorToFind(valueRight.CreateIterator(sig));
			if (pIteratorToFind.IsNull()) return Value::Nil;
			valListToFind.Append(env, pIteratorToFind.get());
			if (sig.IsSignalled()) return Value::Nil;
		} else {
			valListToFind.push_back(valueRight);
		}
		if (valueLeft.Is_iterator()) {
			return Value(new Object_iterator(env, pIterator.release()));
		}
		return pIterator->ToList(env, true, false);
	} else if (valueRight.Is_list()) {
		bool foundFlag = valueRight.GetList().DoesContain(env, valueLeft);
		if (sig.IsSignalled()) return Value::Nil;
		return Value(foundFlag);
	} else if (valueRight.Is_iterator()) {
		AutoPtr<Iterator> pIteratorToFind(valueRight.CreateIterator(sig));
		if (pIteratorToFind.IsNull()) return Value::Nil;
		bool foundFlag = pIteratorToFind->DoesContain(env, valueLeft);
		if (sig.IsSignalled()) return Value::Nil;
		return Value(foundFlag);
	} else {
		int cmp = Value::Compare(env, valueLeft, valueRight);
		if (sig.IsSignalled()) return Value::Nil;
		return Value(cmp == 0);
	}
}

//-----------------------------------------------------------------------------
// [A & B] ... BinaryOperator(And, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(And, number, number)
{
	return Value(valueLeft.GetULong() & valueRight.GetULong());
}

Gura_ImplementBinaryOperator(And, boolean, boolean)
{
	return Value(valueLeft.GetBoolean() && valueRight.GetBoolean());
}

Gura_ImplementBinaryOperator(And, nil, any)
{
	return Value::Nil;	// nil & any -> nil
}

Gura_ImplementBinaryOperator(And, any, nil)
{
	return Value::Nil;	// any & nil -> nil
}

Gura_ImplementBinaryOperator(And, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_And, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(And, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_And, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(And, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_And, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A | B] ... BinaryOperator(Or, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Or, number, number)
{
	return Value(valueLeft.GetULong() | valueRight.GetULong());
}

Gura_ImplementBinaryOperator(Or, boolean, boolean)
{
	return Value(valueLeft.GetBoolean() || valueRight.GetBoolean());
}

Gura_ImplementBinaryOperator(Or, nil, any)
{
	return valueRight;	// nil | any -> any
}

Gura_ImplementBinaryOperator(Or, any, nil)
{
	return valueLeft;	// any | nil -> any
}

Gura_ImplementBinaryOperator(Or, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Or, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Or, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Or, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Or, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Or, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A ^ B] ... BinaryOperator(Xor, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Xor, number, number)
{
	return Value(valueLeft.GetULong() ^ valueRight.GetULong());
}

Gura_ImplementBinaryOperator(Xor, boolean, boolean)
{
	bool flagLeft = valueLeft.GetBoolean();
	bool flagRight = valueRight.GetBoolean();
	return Value((flagLeft && !flagRight) || (!flagLeft && flagRight));
}

Gura_ImplementBinaryOperator(Xor, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Xor, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Xor, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Xor, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Xor, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Xor, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A << B] ... BinaryOperator(Shl, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shl, number, number)
{
	return Value(valueLeft.GetULong() << valueRight.GetULong());
}

Gura_ImplementBinaryOperator(Shl, stream, any)
{
	Signal &sig = env.GetSignal();
	Stream &stream = valueLeft.GetStream();
	if (!stream.CheckWritable(sig)) return Value::Nil;
	if (valueRight.Is_binary()) {
		const Binary &binary = valueRight.GetBinary();
		stream.Write(sig, binary.c_str(), binary.size());
		if (sig.IsSignalled()) return Value::Nil;
	} else {
		String str(valueRight.ToString(false));
		if (sig.IsSignalled()) return Value::Nil;
		stream.Print(sig, str.c_str());
		if (sig.IsSignalled()) return Value::Nil;
	}
	return valueLeft;
}

Gura_ImplementBinaryOperator(Shl, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Shl, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Shl, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Shl, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Shl, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Shl, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A >> B] ... BinaryOperator(Shr, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shr, number, number)
{
	return Value(valueLeft.GetULong() >> valueRight.GetULong());
}

Gura_ImplementBinaryOperator(Shr, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Shr, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Shr, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Shr, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Shr, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Shr, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A || B] ... BinaryOperator(OrOr, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(OrOr, any, any)
{
	if (valueLeft.GetBoolean()) return valueLeft;
	return valueRight;
}

//-----------------------------------------------------------------------------
// [A && B] ... BinaryOperator(AndAnd, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(AndAnd, any, any)
{
	if (!valueLeft.GetBoolean()) return valueLeft;
	return valueRight;
}

//-----------------------------------------------------------------------------
// [A .. B] ... BinaryOperator(Seq, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Seq, number, number)
{
	Number numBegin = valueLeft.GetDouble();
	Number numEnd = valueRight.GetDouble();
	Number numStep = (numEnd >= numBegin)? +1 : -1;
	return Value(new Object_iterator(env, new Iterator_Sequence(numBegin, numEnd, numStep)));
}

//-----------------------------------------------------------------------------
// [A => B] ... BinaryOperator(Pair, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pair, symbol, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pair, string, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pair, number, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// math.abs(A) ... UnaryOperator(Math_abs, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_abs, number)
{
	double result;
	Operator_Math_abs::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_abs, complex)
{
	Complex result;
	Operator_Math_abs::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_abs, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_abs, value);
}

//-----------------------------------------------------------------------------
// math.acos(A) ... UnaryOperator(Math_acos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_acos, number)
{
	double result;
	Operator_Math_acos::Calc(result, value.GetDouble());
	if (flags & FLAG_Deg) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_acos, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_acos, value);
}

//-----------------------------------------------------------------------------
// math.arg(A) ... UnaryOperator(Math_arg, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_arg, number)
{
	double result;
	Operator_Math_arg::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_arg, complex)
{
	double result;
	Operator_Math_arg::Calc(result, value.GetComplex());
	if (flags & FLAG_Deg) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_arg, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_arg, value);
}

//-----------------------------------------------------------------------------
// math.asin(A) ... UnaryOperator(Math_asin, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_asin, number)
{
	double result;
	Operator_Math_asin::Calc(result, value.GetDouble());
	if (flags & FLAG_Deg) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_asin, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_asin, value);
}

//-----------------------------------------------------------------------------
// math.atan(A) ... UnaryOperator(Math_atan, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_atan, number)
{
	double result;
	Operator_Math_atan::Calc(result, value.GetDouble());
	if (flags & FLAG_Deg) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_atan, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_atan, value);
}

//-----------------------------------------------------------------------------
// math.atan2(A, B) ... UnaryOperator(Math_atan2, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Math_atan2, number, number)
{
	double result;
	Operator_Math_atan2::Calc(result, valueLeft.GetDouble(), valueRight.GetDouble());
	if (flags & FLAG_Deg) result = RadToDeg(result);
	return Value(result);
}

//-----------------------------------------------------------------------------
// math.ceil(A) ... UnaryOperator(Math_ceil, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_ceil, number)
{
	double result;
	Operator_Math_ceil::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_ceil, complex)
{
	Complex result;
	Operator_Math_ceil::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_ceil, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_ceil, value);
}

//-----------------------------------------------------------------------------
// math.conj(A) ... UnaryOperator(Math_conj, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_conj, number)
{
	double result;
	Operator_Math_conj::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_conj, complex)
{
	Complex result;
	Operator_Math_conj::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_conj, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_conj, value);
}

//-----------------------------------------------------------------------------
// math.cos(A) ... UnaryOperator(Math_cos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_cos, number)
{
	double num = value.GetDouble();
	if (flags & FLAG_Deg) num = DegToRad(num);
	double result;
	Operator_Math_cos::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_cos, complex)
{
	const Complex &num = value.GetComplex();
	Complex result;
	Operator_Math_cos::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_cos, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_cos, value);
}

//-----------------------------------------------------------------------------
// math.cosh(A) ... UnaryOperator(Math_cosh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_cosh, number)
{
	double num = value.GetDouble();
	double result;
	Operator_Math_cosh::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_cosh, complex)
{
	const Complex &num = value.GetComplex();
	Complex result;
	Operator_Math_cosh::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_cosh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_cosh, value);
}

//-----------------------------------------------------------------------------
// math.covariance(A, B) ... BinaryOperator(Math_covariance, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Math_covariance, iterator, iterator)
{
	size_t cntA, cntB;
	Iterator *pIteratorA = valueLeft.GetIterator();
	Iterator *pIteratorB = valueRight.GetIterator();
	Value valueAveA = pIteratorA->Clone()->Average(env, cntA);
	if (!valueAveA.Is_number()) return Value::Nil;
	Value valueAveB = pIteratorB->Clone()->Average(env, cntB);
	if (!valueAveB.Is_number()) return Value::Nil;
	if (cntA != cntB) {
		env.SetError(ERR_ValueError, "different length of iterators");
		return Value::Nil;
	}
	Number result = 0;
	Number averageA = valueAveA.GetNumber();
	Number averageB = valueAveB.GetNumber();
	Value valueA, valueB;
	while (pIteratorA->Next(env, valueA) && pIteratorB->Next(env, valueB)) {
		if (valueA.Is_number() && valueB.Is_number()) {
			result +=
				(valueA.GetNumber() - averageA) * (valueB.GetNumber() - averageB);
		} else {
			env.SetError(ERR_ValueError, "invalid data type of element");
			return Value::Nil;
		}
	}
	if (env.IsSignalled()) return Value::Nil;
	return Value(result / static_cast<Number>(cntA));
}

//-----------------------------------------------------------------------------
// math.cross(A, B) ... BinaryOperator(Math_cross, A, B)
//-----------------------------------------------------------------------------
static Value CalcCrossElem(Environment &env,
						   const Value &ax, const Value &ay, const Value &bx, const Value &by);

Gura_ImplementBinaryOperator(Math_cross, list, list)
{
	const ValueList &valList1 = valueLeft.GetList();
	const ValueList &valList2 = valueRight.GetList();
	if (valList1.size() != valList2.size()) {
		env.SetError(ERR_ValueError, "different length of lists");
		return Value::Nil;
	}
	if (valList1.size() == 2) {
		return CalcCrossElem(env, valList1[0], valList1[1], valList2[0], valList2[1]);
	} else if (valList1.size() == 3) {
		Value result;
		Object_list *pObjList = result.InitAsList(env);
		pObjList->Reserve(3);
		Value value;
		value = CalcCrossElem(env, valList1[1], valList1[2], valList2[1], valList2[2]);
		if (env.IsSignalled()) return Value::Nil;
		pObjList->Add(value);
		value = CalcCrossElem(env, valList1[2], valList1[0], valList2[2], valList2[0]);
		if (env.IsSignalled()) return Value::Nil;
		pObjList->Add(value);
		value = CalcCrossElem(env, valList1[0], valList1[1], valList2[0], valList2[1]);
		if (env.IsSignalled()) return Value::Nil;
		pObjList->Add(value);
		return result;
	}
	env.SetError(ERR_ValueError,
				"only support two or three dimension vector for cross product");
	return Value::Nil;
}

Value CalcCrossElem(Environment &env,
					const Value &ax, const Value &ay, const Value &bx, const Value &by)
{
	Signal &sig = env.GetSignal();
	Value valueLeft;
	do {
		valueLeft = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, ax, by, FLAG_None);
		if (sig.IsSignalled()) return Value::Nil;
	} while (0);
	Value valueRight;
	do {
		valueRight = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, ay, bx, FLAG_None);
		if (sig.IsSignalled()) return Value::Nil;
	} while (0);
	Value value;
	do {
		value = env.GetOperator(OPTYPE_Sub)->EvalBinary(env, valueLeft, valueRight, FLAG_None);
		if (sig.IsSignalled()) return Value::Nil;
	} while (0);
	return value;
}

//-----------------------------------------------------------------------------
// math.delta(A) ... UnaryOperator(Math_delta, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_delta, number)
{
	double result;
	Operator_Math_delta::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_delta, complex)
{
	Complex result;
	Operator_Math_delta::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_delta, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_delta, value);
}

//-----------------------------------------------------------------------------
// math.dot(A, B) ... BinaryOperator(Math_dot, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Math_dot, list, list)
{
	const ValueList &valList1 = valueLeft.GetList();
	const ValueList &valList2 = valueRight.GetList();
	if (valList1.size() != valList2.size()) {
		env.SetError(ERR_ValueError, "different length of lists");
		return Value::Nil;
	}
	ValueList::const_iterator pValue1 = valList1.begin();
	ValueList::const_iterator pValue2 = valList2.begin();
	Value valueSum(0);
	for ( ; pValue1 != valList1.end(); pValue1++, pValue2++) {
		Value value;
		do {
			value = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, *pValue1, *pValue2, FLAG_None);
			if (env.IsSignalled()) return Value::Nil;
		} while (0);
		do {
			valueSum = env.GetOperator(OPTYPE_Add)->EvalBinary(env, valueSum, value, FLAG_None);
			if (env.IsSignalled()) return Value::Nil;
		} while (0);
	}
	return valueSum;
}

//-----------------------------------------------------------------------------
// math.exp(A) ... UnaryOperator(Math_exp, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_exp, number)
{
	double result;
	Operator_Math_exp::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_exp, complex)
{
	Complex result;
	Operator_Math_exp::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_exp, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_exp, value);
}

//-----------------------------------------------------------------------------
// math.floor(A) ... UnaryOperator(Math_floor, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_floor, number)
{
	double result;
	Operator_Math_floor::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_floor, complex)
{
	Complex result;
	Operator_Math_floor::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_floor, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_floor, value);
}

//-----------------------------------------------------------------------------
// math.hypot(A, B) ... BinaryOperator(Math_hypot, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Math_hypot, number, number)
{
	double result;
	Operator_Math_hypot::Calc(result, valueLeft.GetDouble(), valueRight.GetDouble());
	return Value(result);
}

//-----------------------------------------------------------------------------
// math.imag(A) ... UnaryOperator(Math_imag, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_imag, number)
{
	double result;
	Operator_Math_imag::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_imag, complex)
{
	double result;
	Operator_Math_imag::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_imag, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_imag, value);
}

//-----------------------------------------------------------------------------
// math.log(A) ... UnaryOperator(Math_log, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_log, number)
{
	double num = value.GetDouble();
	if (num == 0.) {
		env.SetError(ERR_MathError, "can't calculate a logarithm of zero");
		return Value::Nil;
	} else if (num < 0.) {
		return Value(std::log(Complex(num)));
	}
	return Value(::log(num));
}

Gura_ImplementUnaryOperator(Math_log, complex)
{
	const Complex &num = value.GetComplex();
	if (num.IsZero()) {
		env.SetError(ERR_MathError, "can't calculate a logarithm of zero");
		return Value::Nil;
	}
	return Value(std::log(num));
}

Gura_ImplementUnaryOperator(Math_log, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_log, value);
}

//-----------------------------------------------------------------------------
// math.log10(A) ... UnaryOperator(Math_log10, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_log10, number)
{
	double num = value.GetDouble();
	if (num == 0.) {
		env.SetError(ERR_MathError, "can't calculate a logarithm of zero");
		return Value::Nil;
	} else if (num < 0.) {
		return Value(std::log10(Complex(num)));
	}
	return Value(::log10(num));
}

Gura_ImplementUnaryOperator(Math_log10, complex)
{
	const Complex &num = value.GetComplex();
	if (num.IsZero()) {
		env.SetError(ERR_MathError, "can't calculate a logarithm of zero");
		return Value::Nil;
	}
	return Value(std::log10(num));
}

Gura_ImplementUnaryOperator(Math_log10, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_log10, value);
}

//-----------------------------------------------------------------------------
// math.norm(A) ... UnaryOperator(Math_norm, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_norm, number)
{
	double result;
	Operator_Math_norm::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_norm, complex)
{
	Complex result;
	Operator_Math_norm::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_norm, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_norm, value);
}

//-----------------------------------------------------------------------------
// math.ramp(A) ... UnaryOperator(Math_ramp, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_ramp, number)
{
	double result;
	Operator_Math_ramp::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_ramp, complex)
{
	Complex result;
	Operator_Math_ramp::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_ramp, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_ramp, value);
}

//-----------------------------------------------------------------------------
// math.real(A) ... UnaryOperator(Math_real, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_real, number)
{
	double result;
	Operator_Math_real::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_real, complex)
{
	double result;
	Operator_Math_real::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_real, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_real, value);
}

//-----------------------------------------------------------------------------
// math.sigmoid(A) ... UnaryOperator(Math_sigmoid, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sigmoid, number)
{
	double num = value.GetDouble();
	if (flags & FLAG_Deg) num = DegToRad(num);
	double result;
	Operator_Math_sigmoid::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_sigmoid, complex)
{
	const Complex &num = value.GetComplex();
	Complex result;
	Operator_Math_sigmoid::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_sigmoid, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_sigmoid, value);
}

//-----------------------------------------------------------------------------
// math.sin(A) ... UnaryOperator(Math_sin, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sin, number)
{
	double num = value.GetDouble();
	if (flags & FLAG_Deg) num = DegToRad(num);
	double result;
	Operator_Math_sin::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_sin, complex)
{
	const Complex &num = value.GetComplex();
	Complex result;
	Operator_Math_sin::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_sin, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_sin, value);
}

//-----------------------------------------------------------------------------
// math.sinh(A) ... UnaryOperator(Math_sinh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sinh, number)
{
	double result;
	Operator_Math_sinh::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_sinh, complex)
{
	Complex result;
	Operator_Math_sinh::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_sinh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_sinh, value);
}

//-----------------------------------------------------------------------------
// math.sqrt(A) ... UnaryOperator(Math_sqrt, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sqrt, number)
{
	double num = value.GetDouble();
	return (num >= 0)? Value(::sqrt(num)) : Value(Complex(0, ::sqrt(-num)));
}

Gura_ImplementUnaryOperator(Math_sqrt, complex)
{
	const Complex &num = value.GetComplex();
	return Value(std::sqrt(num));
}

Gura_ImplementUnaryOperator(Math_sqrt, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_sqrt, value);
}

//-----------------------------------------------------------------------------
// math.tan(A) ... UnaryOperator(Math_tan, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_tan, number)
{
	double num = value.GetDouble();
	if (flags & FLAG_Deg) num = DegToRad(num);
	double result;
	Operator_Math_tan::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_tan, complex)
{
	const Complex &num = value.GetComplex();
	Complex result;
	Operator_Math_tan::Calc(result, num);
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_tan, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_tan, value);
}

//-----------------------------------------------------------------------------
// math.tanh(A) ... UnaryOperator(Math_tanh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_tanh, number)
{
	double result;
	Operator_Math_tanh::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_tanh, complex)
{
	Complex result;
	Operator_Math_tanh::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_tanh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_tanh, value);
}

//-----------------------------------------------------------------------------
// math.unitstep(A) ... UnaryOperator(Math_unitstep, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_unitstep, number)
{
	double result;
	Operator_Math_unitstep::Calc(result, value.GetDouble());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_unitstep, complex)
{
	Complex result;
	Operator_Math_unitstep::Calc(result, value.GetComplex());
	return Value(result);
}

Gura_ImplementUnaryOperator(Math_unitstep, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_unitstep, value);
}

//-----------------------------------------------------------------------------
// OperatorEntryCustom
//-----------------------------------------------------------------------------
Value OperatorEntryCustom::DoEval(Environment &env, const Value &value, ULong flags) const
{
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->StoreValue(env, value)) return Value::Nil;
	return _pFunc->Eval(env, *pArg);
}

Value OperatorEntryCustom::DoEval(Environment &env,
								  const Value &valueLeft, const Value &valueRight, ULong flags) const
{
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->StoreValue(env, valueLeft, valueRight)) return Value::Nil;
	return _pFunc->Eval(env, *pArg);
}

//-----------------------------------------------------------------------------
// OperatorEntryDerived
//-----------------------------------------------------------------------------
Value OperatorEntryDerived::DoEval(Environment &env, const Value &value, ULong flags) const
{
	return _pOperatorEntryOrg->DoEval(env, value, flags);
}

Value OperatorEntryDerived::DoEval(Environment &env,
								   const Value &valueLeft, const Value &valueRight, ULong flags) const
{
	return _pOperatorEntryOrg->DoEval(env, valueLeft, valueRight, flags);
}

//-----------------------------------------------------------------------------
// Operator assignment
//-----------------------------------------------------------------------------
void Operator::AssignOperatorBasic(Environment &env)
{
	// unary operators
	Gura_AssignUnaryOperator(Pos, number);
	Gura_AssignUnaryOperator(Pos, complex);
	Gura_AssignUnaryOperator(Pos, rational);
	Gura_AssignUnaryOperator(Pos, timedelta);
	Gura_AssignUnaryOperator(Neg, number);
	Gura_AssignUnaryOperator(Neg, complex);
	Gura_AssignUnaryOperator(Neg, rational);
	Gura_AssignUnaryOperator(Neg, timedelta);
	Gura_AssignUnaryOperator(Neg, vertex);
	Gura_AssignUnaryOperator(Inv, number);
	Gura_AssignUnaryOperator(Not, any);
	Gura_AssignUnaryOperator(SeqInf, number);
	Gura_AssignUnaryOperator(Question, any);
	//Gura_AssignUnaryOperator(Each, any);
	// binary operators
	Gura_AssignBinaryOperator(Add, number, number);
	Gura_AssignBinaryOperator(Add, boolean, boolean);
	Gura_AssignBinaryOperator(Add, number, boolean);
	Gura_AssignBinaryOperator(Add, boolean, number);
	Gura_AssignBinaryOperator(Add, number, complex);
	Gura_AssignBinaryOperator(Add, number, rational);
	Gura_AssignBinaryOperator(Add, complex, number);
	Gura_AssignBinaryOperator(Add, complex, complex);
	Gura_AssignBinaryOperator(Add, rational, number);
	Gura_AssignBinaryOperator(Add, rational, rational);
	Gura_AssignBinaryOperator(Add, datetime, timedelta);
	Gura_AssignBinaryOperator(Add, timedelta, datetime);
	Gura_AssignBinaryOperator(Add, timedelta, timedelta);
	Gura_AssignBinaryOperator(Add, string, string);
	Gura_AssignBinaryOperator(Add, binary, binary);
	Gura_AssignBinaryOperator(Add, binary, string);
	Gura_AssignBinaryOperator(Add, string, binary);
	Gura_AssignBinaryOperator(Add, pointer, number);
	Gura_AssignBinaryOperator(Add, string, any);
	Gura_AssignBinaryOperator(Add, any, string);
	Gura_AssignBinaryOperator(Add, vertex, vertex);
	Gura_AssignBinaryOperator(Sub, number, number);
	Gura_AssignBinaryOperator(Sub, boolean, boolean);
	Gura_AssignBinaryOperator(Sub, number, boolean);
	Gura_AssignBinaryOperator(Sub, boolean, number);
	Gura_AssignBinaryOperator(Sub, number, complex);
	Gura_AssignBinaryOperator(Sub, number, rational);
	Gura_AssignBinaryOperator(Sub, complex, number);
	Gura_AssignBinaryOperator(Sub, complex, complex);
	Gura_AssignBinaryOperator(Sub, rational, number);
	Gura_AssignBinaryOperator(Sub, rational, rational);
	Gura_AssignBinaryOperator(Sub, datetime, timedelta);
	Gura_AssignBinaryOperator(Sub, datetime, datetime);
	Gura_AssignBinaryOperator(Sub, timedelta, timedelta);
	Gura_AssignBinaryOperator(Sub, color, color);
	Gura_AssignBinaryOperator(Sub, pointer, number);
	Gura_AssignBinaryOperator(Sub, pointer, pointer);
	Gura_AssignBinaryOperator(Sub, vertex, vertex);
	Gura_AssignBinaryOperator(Mul, number, number);
	Gura_AssignBinaryOperator(Mul, boolean, boolean);
	Gura_AssignBinaryOperator(Mul, number, boolean);
	Gura_AssignBinaryOperator(Mul, boolean, number);
	Gura_AssignBinaryOperator(Mul, number, complex);
	Gura_AssignBinaryOperator(Mul, number, rational);
	Gura_AssignBinaryOperator(Mul, complex, number);
	Gura_AssignBinaryOperator(Mul, complex, complex);
	Gura_AssignBinaryOperator(Mul, rational, number);
	Gura_AssignBinaryOperator(Mul, rational, rational);
	Gura_AssignBinaryOperator(Mul, timedelta, number);
	Gura_AssignBinaryOperator(Mul, number, timedelta);
	Gura_AssignBinaryOperator(Mul, function, any);
	Gura_AssignBinaryOperator(Mul, Class, any);
	Gura_AssignBinaryOperator(Mul, string, number);
	Gura_AssignBinaryOperator(Mul, number, string);
	Gura_AssignBinaryOperator(Mul, binary, number);
	Gura_AssignBinaryOperator(Mul, number, binary);
	Gura_AssignBinaryOperator(Mul, vertex, number);
	Gura_AssignBinaryOperator(Mul, array, array);
	Gura_AssignBinaryOperator(Mul, array, number);
	Gura_AssignBinaryOperator(Mul, number, array);
	Gura_AssignBinaryOperator(Mul, array, complex);
	Gura_AssignBinaryOperator(Mul, complex, array);
	Gura_AssignBinaryOperator(Div, number, number);
	Gura_AssignBinaryOperator(Div, number, complex);
	Gura_AssignBinaryOperator(Div, number, rational);
	Gura_AssignBinaryOperator(Div, complex, number);
	Gura_AssignBinaryOperator(Div, complex, complex);
	Gura_AssignBinaryOperator(Div, rational, number);
	Gura_AssignBinaryOperator(Div, rational, rational);
	Gura_AssignBinaryOperator(Div, vertex, number);
	Gura_AssignBinaryOperator(Div, array, array);
	Gura_AssignBinaryOperator(Div, array, number);
	Gura_AssignBinaryOperator(Div, number, array);
	Gura_AssignBinaryOperator(Div, array, complex);
	Gura_AssignBinaryOperator(Div, complex, array);
	Gura_AssignBinaryOperator(Mod, number, number);
	Gura_AssignBinaryOperator(Mod, array, array);
	Gura_AssignBinaryOperator(Mod, array, number);
	Gura_AssignBinaryOperator(Mod, number, array);
	Gura_AssignBinaryOperator(DotProd, number, number);
	Gura_AssignBinaryOperator(DotProd, array, array);
	Gura_AssignBinaryOperator(DotProd, vertex, vertex);
	Gura_AssignBinaryOperator(CrossProd, vertex, vertex);
	Gura_AssignBinaryOperator(Pow, number, number);
	Gura_AssignBinaryOperator(Pow, complex, complex);
	Gura_AssignBinaryOperator(Pow, number, complex);
	Gura_AssignBinaryOperator(Pow, complex, number);
	Gura_AssignBinaryOperator(Pow, array, array);
	Gura_AssignBinaryOperator(Pow, array, number);
	Gura_AssignBinaryOperator(Pow, number, array);
	Gura_AssignBinaryOperator(Pow, array, complex);
	Gura_AssignBinaryOperator(Pow, complex, array);
	Gura_AssignBinaryOperator(Eq, any, any);
	Gura_AssignBinaryOperator(Eq, array, array);
	Gura_AssignBinaryOperator(Eq, array, number);
	Gura_AssignBinaryOperator(Eq, number, array);
	Gura_AssignBinaryOperator(Eq, array, complex);
	Gura_AssignBinaryOperator(Eq, complex, array);
	Gura_AssignBinaryOperator(Ne, any, any);
	Gura_AssignBinaryOperator(Ne, array, array);
	Gura_AssignBinaryOperator(Ne, array, number);
	Gura_AssignBinaryOperator(Ne, number, array);
	Gura_AssignBinaryOperator(Ne, array, complex);
	Gura_AssignBinaryOperator(Ne, complex, array);
	Gura_AssignBinaryOperator(Gt, any, any);
	Gura_AssignBinaryOperator(Gt, array, array);
	Gura_AssignBinaryOperator(Gt, array, number);
	Gura_AssignBinaryOperator(Gt, number, array);
	Gura_AssignBinaryOperator(Gt, array, complex);
	Gura_AssignBinaryOperator(Gt, complex, array);
	Gura_AssignBinaryOperator(Lt, any, any);
	Gura_AssignBinaryOperator(Lt, array, array);
	Gura_AssignBinaryOperator(Lt, array, number);
	Gura_AssignBinaryOperator(Lt, number, array);
	Gura_AssignBinaryOperator(Lt, array, complex);
	Gura_AssignBinaryOperator(Lt, complex, array);
	Gura_AssignBinaryOperator(Ge, any, any);
	Gura_AssignBinaryOperator(Ge, array, array);
	Gura_AssignBinaryOperator(Ge, array, number);
	Gura_AssignBinaryOperator(Ge, number, array);
	Gura_AssignBinaryOperator(Ge, array, complex);
	Gura_AssignBinaryOperator(Ge, complex, array);
	Gura_AssignBinaryOperator(Le, any, any);
	Gura_AssignBinaryOperator(Le, array, array);
	Gura_AssignBinaryOperator(Le, array, number);
	Gura_AssignBinaryOperator(Le, number, array);
	Gura_AssignBinaryOperator(Le, array, complex);
	Gura_AssignBinaryOperator(Le, complex, array);
	Gura_AssignBinaryOperator(Cmp, boolean, boolean);
	Gura_AssignBinaryOperator(Cmp, complex, complex);
	Gura_AssignBinaryOperator(Cmp, number, number);
	Gura_AssignBinaryOperator(Cmp, rational, rational);
	Gura_AssignBinaryOperator(Cmp, number, rational);
	Gura_AssignBinaryOperator(Cmp, rational, number);
	Gura_AssignBinaryOperator(Cmp, string, string);
	Gura_AssignBinaryOperator(Cmp, symbol, symbol);
	Gura_AssignBinaryOperator(Cmp, binary, binary);
	Gura_AssignBinaryOperator(Cmp, datetime, datetime);
	Gura_AssignBinaryOperator(Cmp, list, list);
	Gura_AssignBinaryOperator(Cmp, timedelta, timedelta);
	Gura_AssignBinaryOperator(Contains, any, any);
	Gura_AssignBinaryOperator(And, number, number);
	Gura_AssignBinaryOperator(And, boolean, boolean);
	Gura_AssignBinaryOperator(And, nil, any);
	Gura_AssignBinaryOperator(And, any, nil);
	Gura_AssignBinaryOperator(And, array, array);
	Gura_AssignBinaryOperator(And, array, number);
	Gura_AssignBinaryOperator(And, number, array);
	Gura_AssignBinaryOperator(Or, number, number);
	Gura_AssignBinaryOperator(Or, boolean, boolean);
	Gura_AssignBinaryOperator(Or, nil, any);
	Gura_AssignBinaryOperator(Or, any, nil);
	Gura_AssignBinaryOperator(Or, array, array);
	Gura_AssignBinaryOperator(Or, array, number);
	Gura_AssignBinaryOperator(Or, number, array);
	Gura_AssignBinaryOperator(Xor, number, number);
	Gura_AssignBinaryOperator(Xor, boolean, boolean);
	Gura_AssignBinaryOperator(Xor, array, array);
	Gura_AssignBinaryOperator(Xor, array, number);
	Gura_AssignBinaryOperator(Xor, number, array);
	Gura_AssignBinaryOperator(Shl, number, number);
	Gura_AssignBinaryOperator(Shl, stream, any);
	Gura_AssignBinaryOperator(Shl, array, array);
	Gura_AssignBinaryOperator(Shl, array, number);
	Gura_AssignBinaryOperator(Shl, number, array);
	Gura_AssignBinaryOperator(Shr, number, number);
	Gura_AssignBinaryOperator(Shr, array, array);
	Gura_AssignBinaryOperator(Shr, array, number);
	Gura_AssignBinaryOperator(Shr, number, array);
	Gura_AssignBinaryOperator(OrOr, any, any);
	Gura_AssignBinaryOperator(AndAnd, any, any);
	Gura_AssignBinaryOperator(Seq, number, number);
	Gura_AssignBinaryOperator(Pair, symbol, any);
	Gura_AssignBinaryOperator(Pair, string, any);
	Gura_AssignBinaryOperator(Pair, number, any);
	// mathematical functions
	Gura_AssignUnaryOperator(Math_abs, number);
	Gura_AssignUnaryOperator(Math_abs, complex);
	Gura_AssignUnaryOperator(Math_abs, array);
	Gura_AssignUnaryOperator(Math_acos, number);
	Gura_AssignUnaryOperator(Math_acos, array);
	Gura_AssignUnaryOperator(Math_arg, number);
	Gura_AssignUnaryOperator(Math_arg, complex);
	Gura_AssignUnaryOperator(Math_arg, array);
	Gura_AssignUnaryOperator(Math_asin, number);
	Gura_AssignUnaryOperator(Math_asin, array);
	Gura_AssignUnaryOperator(Math_atan, number);
	Gura_AssignUnaryOperator(Math_atan, array);
	Gura_AssignBinaryOperator(Math_atan2, number, number);
	Gura_AssignUnaryOperator(Math_ceil, number);
	Gura_AssignUnaryOperator(Math_ceil, complex);
	Gura_AssignUnaryOperator(Math_ceil, array);
	Gura_AssignUnaryOperator(Math_conj, number);
	Gura_AssignUnaryOperator(Math_conj, complex);
	Gura_AssignUnaryOperator(Math_conj, array);
	Gura_AssignUnaryOperator(Math_cos, number);
	Gura_AssignUnaryOperator(Math_cos, complex);
	Gura_AssignUnaryOperator(Math_cos, array);
	Gura_AssignUnaryOperator(Math_cosh, number);
	Gura_AssignUnaryOperator(Math_cosh, complex);
	Gura_AssignUnaryOperator(Math_cosh, array);
	Gura_AssignBinaryOperator(Math_covariance, iterator, iterator);
	Gura_AssignBinaryOperator(Math_cross, list, list);
	Gura_AssignUnaryOperator(Math_delta, number);
	Gura_AssignUnaryOperator(Math_delta, complex);
	Gura_AssignUnaryOperator(Math_delta, array);
	Gura_AssignBinaryOperator(Math_dot, list, list);
	Gura_AssignUnaryOperator(Math_exp, number);
	Gura_AssignUnaryOperator(Math_exp, complex);
	Gura_AssignUnaryOperator(Math_exp, array);
	Gura_AssignUnaryOperator(Math_floor, number);
	Gura_AssignUnaryOperator(Math_floor, complex);
	Gura_AssignUnaryOperator(Math_floor, array);
	Gura_AssignBinaryOperator(Math_hypot, number, number);
	Gura_AssignUnaryOperator(Math_imag, number);
	Gura_AssignUnaryOperator(Math_imag, complex);
	Gura_AssignUnaryOperator(Math_imag, array);
	Gura_AssignUnaryOperator(Math_log, number);
	Gura_AssignUnaryOperator(Math_log, complex);
	Gura_AssignUnaryOperator(Math_log, array);
	Gura_AssignUnaryOperator(Math_log10, number);
	Gura_AssignUnaryOperator(Math_log10, complex);
	Gura_AssignUnaryOperator(Math_log10, array);
	Gura_AssignUnaryOperator(Math_norm, number);
	Gura_AssignUnaryOperator(Math_norm, complex);
	Gura_AssignUnaryOperator(Math_norm, array);
	Gura_AssignUnaryOperator(Math_ramp, number);
	Gura_AssignUnaryOperator(Math_ramp, complex);
	Gura_AssignUnaryOperator(Math_ramp, array);
	Gura_AssignUnaryOperator(Math_real, number);
	Gura_AssignUnaryOperator(Math_real, complex);
	Gura_AssignUnaryOperator(Math_real, array);
	Gura_AssignUnaryOperator(Math_sigmoid, number);
	Gura_AssignUnaryOperator(Math_sigmoid, complex);
	Gura_AssignUnaryOperator(Math_sigmoid, array);
	Gura_AssignUnaryOperator(Math_sin, number);
	Gura_AssignUnaryOperator(Math_sin, complex);
	Gura_AssignUnaryOperator(Math_sin, array);
	Gura_AssignUnaryOperator(Math_sinh, number);
	Gura_AssignUnaryOperator(Math_sinh, complex);
	Gura_AssignUnaryOperator(Math_sinh, array);
	Gura_AssignUnaryOperator(Math_sqrt, number);
	Gura_AssignUnaryOperator(Math_sqrt, complex);
	Gura_AssignUnaryOperator(Math_sqrt, array);
	Gura_AssignUnaryOperator(Math_tan, number);
	Gura_AssignUnaryOperator(Math_tan, complex);
	Gura_AssignUnaryOperator(Math_tan, array);
	Gura_AssignUnaryOperator(Math_tanh, number);
	Gura_AssignUnaryOperator(Math_tanh, complex);
	Gura_AssignUnaryOperator(Math_tanh, array);
	Gura_AssignUnaryOperator(Math_unitstep, number);
	Gura_AssignUnaryOperator(Math_unitstep, complex);
	Gura_AssignUnaryOperator(Math_unitstep, array);
}

}
