//=============================================================================
// OperatorBasic
//=============================================================================
#include "stdafx.h"
#include <math.h>

#define LoopOn_Array() \
Array<T_Elem> *pArray = Object_array<T_Elem>::GetObject(value)->GetArray(); \
size_t cnt = pArray->GetSize(); \
AutoPtr<Array<T_ElemResult> > pArrayResult(new Array<T_ElemResult>(cnt)); \
T_Elem *pElem = pArray->GetPointer(); \
T_ElemResult *pResult = pArrayResult->GetPointer();	\
for (size_t i = 0; i < cnt; i++, pElem++, pResult++)

#define LoopOn_ArrayAndArray() \
Array<T_ElemLeft> *pArrayLeft = Object_array<T_ElemLeft>::GetObject(valueLeft)->GetArray(); \
Array<T_ElemRight> *pArrayRight = Object_array<T_ElemRight>::GetObject(valueRight)->GetArray(); \
size_t cnt = ChooseMin(pArrayLeft->GetSize(), pArrayRight->GetSize()); \
AutoPtr<Array<T_ElemResult> > pArrayResult(new Array<T_ElemResult>(cnt)); \
T_ElemLeft *pLeft = pArrayLeft->GetPointer(); \
T_ElemRight *pRight = pArrayRight->GetPointer(); \
T_ElemResult *pResult = pArrayResult->GetPointer();	\
for (size_t i = 0; i < cnt; i++, pLeft++, pRight++, pResult++)

#define LoopOn_ArrayAndNumber() \
Array<T_ElemLeft> *pArrayLeft = Object_array<T_ElemLeft>::GetObject(valueLeft)->GetArray(); \
Number numRight = valueRight.GetNumber(); \
size_t cnt = pArrayLeft->GetSize(); \
AutoPtr<Array<T_ElemResult> > pArrayResult(new Array<T_ElemResult>(cnt)); \
T_ElemLeft *pLeft = pArrayLeft->GetPointer(); \
T_ElemResult *pResult = pArrayResult->GetPointer();	\
for (size_t i = 0; i < cnt; i++, pLeft++, pResult++)

#define LoopOn_NumberAndArray() \
Number numLeft = valueLeft.GetNumber(); \
Array<T_ElemRight> *pArrayRight = Object_array<T_ElemRight>::GetObject(valueRight)->GetArray(); \
size_t cnt = pArrayRight->GetSize(); \
AutoPtr<Array<T_ElemResult> > pArrayResult(new Array<T_ElemResult>(cnt)); \
T_ElemRight *pRight = pArrayRight->GetPointer(); \
T_ElemResult *pResult = pArrayResult->GetPointer();	\
for (size_t i = 0; i < cnt; i++, pRight++, pResult++)

#define ImplementArrayOperators(op) \
Gura_ImplementBinaryOperator(op, array_char, array_char) \
{ \
	return op##_ArrayAndArray<char, char, char>(env, valueLeft, valueRight, VTYPE_array_char); \
} \
Gura_ImplementBinaryOperator(op, array_uchar, array_uchar) \
{ \
	return op##_ArrayAndArray<UChar, UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_short, array_short) \
{ \
	return op##_ArrayAndArray<short, short, short>(env, valueLeft, valueRight, VTYPE_array_short); \
} \
Gura_ImplementBinaryOperator(op, array_ushort, array_ushort) \
{ \
	return op##_ArrayAndArray<UShort, UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_long, array_long) \
{ \
	return op##_ArrayAndArray<long, long, long>(env, valueLeft, valueRight, VTYPE_array_long); \
} \
Gura_ImplementBinaryOperator(op, array_ulong, array_ulong) \
{ \
	return op##_ArrayAndArray<ULong, ULong, ULong>(env, valueLeft, valueRight, VTYPE_array_ulong); \
} \
Gura_ImplementBinaryOperator(op, array_int, array_int) \
{ \
	return op##_ArrayAndArray<int, int, int>(env, valueLeft, valueRight, VTYPE_array_int); \
} \
Gura_ImplementBinaryOperator(op, array_uint, array_uint) \
{ \
	return op##_ArrayAndArray<UInt, UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_uint); \
} \
Gura_ImplementBinaryOperator(op, array_float, array_float) \
{ \
	return op##_ArrayAndArray<float, float, float>(env, valueLeft, valueRight, VTYPE_array_float); \
} \
Gura_ImplementBinaryOperator(op, array_double, array_double) \
{ \
	return op##_ArrayAndArray<double, double, double>(env, valueLeft, valueRight, VTYPE_array_double); \
} \
Gura_ImplementBinaryOperator(op, array_char, number) \
{ \
	return op##_ArrayAndNumber<char, char>(env, valueLeft, valueRight, VTYPE_array_char); \
} \
Gura_ImplementBinaryOperator(op, array_uchar, number) \
{ \
	return op##_ArrayAndNumber<UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_short, number) \
{ \
	return op##_ArrayAndNumber<short, short>(env, valueLeft, valueRight, VTYPE_array_short); \
} \
Gura_ImplementBinaryOperator(op, array_ushort, number)	\
{ \
	return op##_ArrayAndNumber<UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_long, number) \
{ \
	return op##_ArrayAndNumber<long, long>(env, valueLeft, valueRight, VTYPE_array_long); \
} \
Gura_ImplementBinaryOperator(op, array_ulong, number) \
{ \
	return op##_ArrayAndNumber<ULong, ULong>(env, valueLeft, valueRight, VTYPE_array_ulong); \
} \
Gura_ImplementBinaryOperator(op, array_int, number) \
{ \
	return op##_ArrayAndNumber<int, int>(env, valueLeft, valueRight, VTYPE_array_int); \
} \
Gura_ImplementBinaryOperator(op, array_uint, number) \
{ \
	return op##_ArrayAndNumber<UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_uint); \
} \
Gura_ImplementBinaryOperator(op, array_float, number) \
{ \
	return op##_ArrayAndNumber<float, float>(env, valueLeft, valueRight, VTYPE_array_float); \
} \
Gura_ImplementBinaryOperator(op, array_double, number) \
{ \
	return op##_ArrayAndNumber<double, double>(env, valueLeft, valueRight, VTYPE_array_double); \
} \
Gura_ImplementBinaryOperator(op, number, array_char) \
{ \
	return op##_NumberAndArray<char, char>(env, valueLeft, valueRight, VTYPE_array_char); \
} \
Gura_ImplementBinaryOperator(op, number, array_uchar)	\
{ \
	return op##_NumberAndArray<UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_uchar); \
} \
Gura_ImplementBinaryOperator(op, number, array_short)	\
{ \
	return op##_NumberAndArray<short, short>(env, valueLeft, valueRight, VTYPE_array_short); \
} \
Gura_ImplementBinaryOperator(op, number, array_ushort)	\
{ \
	return op##_NumberAndArray<UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_ushort); \
} \
Gura_ImplementBinaryOperator(op, number, array_long) \
{ \
	return op##_NumberAndArray<long, long>(env, valueLeft, valueRight, VTYPE_array_long); \
} \
Gura_ImplementBinaryOperator(op, number, array_ulong)	\
{ \
	return op##_NumberAndArray<ULong, ULong>(env, valueLeft, valueRight, VTYPE_array_ulong); \
} \
Gura_ImplementBinaryOperator(op, number, array_int)	\
{ \
	return op##_NumberAndArray<int, int>(env, valueLeft, valueRight, VTYPE_array_int); \
} \
Gura_ImplementBinaryOperator(op, number, array_uint) \
{ \
	return op##_NumberAndArray<UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_uint); \
} \
Gura_ImplementBinaryOperator(op, number, array_float)	\
{ \
	return op##_NumberAndArray<float, float>(env, valueLeft, valueRight, VTYPE_array_float); \
} \
Gura_ImplementBinaryOperator(op, number, array_double)	\
{ \
	return op##_NumberAndArray<double, double>(env, valueLeft, valueRight, VTYPE_array_double); \
}

#define ImplementArrayBitOperators(op) \
Gura_ImplementBinaryOperator(op, array_char, array_char) \
{ \
	return op##_ArrayAndArray<char, char, char>(env, valueLeft, valueRight, VTYPE_array_char); \
} \
Gura_ImplementBinaryOperator(op, array_uchar, array_uchar) \
{ \
	return op##_ArrayAndArray<UChar, UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_short, array_short) \
{ \
	return op##_ArrayAndArray<short, short, short>(env, valueLeft, valueRight, VTYPE_array_short); \
} \
Gura_ImplementBinaryOperator(op, array_ushort, array_ushort) \
{ \
	return op##_ArrayAndArray<UShort, UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_long, array_long) \
{ \
	return op##_ArrayAndArray<long, long, long>(env, valueLeft, valueRight, VTYPE_array_long); \
} \
Gura_ImplementBinaryOperator(op, array_ulong, array_ulong) \
{ \
	return op##_ArrayAndArray<ULong, ULong, ULong>(env, valueLeft, valueRight, VTYPE_array_ulong); \
} \
Gura_ImplementBinaryOperator(op, array_int, array_int) \
{ \
	return op##_ArrayAndArray<int, int, int>(env, valueLeft, valueRight, VTYPE_array_int); \
} \
Gura_ImplementBinaryOperator(op, array_uint, array_uint) \
{ \
	return op##_ArrayAndArray<UInt, UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_uint); \
} \
Gura_ImplementBinaryOperator(op, array_char, number) \
{ \
	return op##_ArrayAndNumber<char, char>(env, valueLeft, valueRight, VTYPE_array_char); \
} \
Gura_ImplementBinaryOperator(op, array_uchar, number) \
{ \
	return op##_ArrayAndNumber<UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_short, number) \
{ \
	return op##_ArrayAndNumber<short, short>(env, valueLeft, valueRight, VTYPE_array_short); \
} \
Gura_ImplementBinaryOperator(op, array_ushort, number)	\
{ \
	return op##_ArrayAndNumber<UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_long, number) \
{ \
	return op##_ArrayAndNumber<long, long>(env, valueLeft, valueRight, VTYPE_array_long); \
} \
Gura_ImplementBinaryOperator(op, array_ulong, number) \
{ \
	return op##_ArrayAndNumber<ULong, ULong>(env, valueLeft, valueRight, VTYPE_array_ulong); \
} \
Gura_ImplementBinaryOperator(op, array_int, number) \
{ \
	return op##_ArrayAndNumber<int, int>(env, valueLeft, valueRight, VTYPE_array_int); \
} \
Gura_ImplementBinaryOperator(op, array_uint, number) \
{ \
	return op##_ArrayAndNumber<UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_uint); \
} \
Gura_ImplementBinaryOperator(op, number, array_char) \
{ \
	return op##_NumberAndArray<char, char>(env, valueLeft, valueRight, VTYPE_array_char); \
} \
Gura_ImplementBinaryOperator(op, number, array_uchar)	\
{ \
	return op##_NumberAndArray<UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_uchar); \
} \
Gura_ImplementBinaryOperator(op, number, array_short)	\
{ \
	return op##_NumberAndArray<short, short>(env, valueLeft, valueRight, VTYPE_array_short); \
} \
Gura_ImplementBinaryOperator(op, number, array_ushort)	\
{ \
	return op##_NumberAndArray<UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_ushort); \
} \
Gura_ImplementBinaryOperator(op, number, array_long) \
{ \
	return op##_NumberAndArray<long, long>(env, valueLeft, valueRight, VTYPE_array_long); \
} \
Gura_ImplementBinaryOperator(op, number, array_ulong)	\
{ \
	return op##_NumberAndArray<ULong, ULong>(env, valueLeft, valueRight, VTYPE_array_ulong); \
} \
Gura_ImplementBinaryOperator(op, number, array_int)	\
{ \
	return op##_NumberAndArray<int, int>(env, valueLeft, valueRight, VTYPE_array_int); \
} \
Gura_ImplementBinaryOperator(op, number, array_uint) \
{ \
	return op##_NumberAndArray<UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_uint); \
} \

#define AssignArrayOperators(op) \
Gura_AssignBinaryOperator(op, array_char, array_char); \
Gura_AssignBinaryOperator(op, array_uchar, array_uchar); \
Gura_AssignBinaryOperator(op, array_short, array_short); \
Gura_AssignBinaryOperator(op, array_ushort, array_ushort); \
Gura_AssignBinaryOperator(op, array_long, array_long); \
Gura_AssignBinaryOperator(op, array_ulong, array_ulong); \
Gura_AssignBinaryOperator(op, array_int, array_int); \
Gura_AssignBinaryOperator(op, array_uint, array_uint); \
Gura_AssignBinaryOperator(op, array_float, array_float); \
Gura_AssignBinaryOperator(op, array_double, array_double); \
Gura_AssignBinaryOperator(op, array_char, number); \
Gura_AssignBinaryOperator(op, array_uchar, number); \
Gura_AssignBinaryOperator(op, array_short, number); \
Gura_AssignBinaryOperator(op, array_ushort, number); \
Gura_AssignBinaryOperator(op, array_long, number); \
Gura_AssignBinaryOperator(op, array_ulong, number); \
Gura_AssignBinaryOperator(op, array_int, number); \
Gura_AssignBinaryOperator(op, array_uint, number); \
Gura_AssignBinaryOperator(op, array_float, number); \
Gura_AssignBinaryOperator(op, array_double, number); \
Gura_AssignBinaryOperator(op, number, array_char);	\
Gura_AssignBinaryOperator(op, number, array_uchar); \
Gura_AssignBinaryOperator(op, number, array_short); \
Gura_AssignBinaryOperator(op, number, array_ushort); \
Gura_AssignBinaryOperator(op, number, array_long); \
Gura_AssignBinaryOperator(op, number, array_ulong); \
Gura_AssignBinaryOperator(op, number, array_int); \
Gura_AssignBinaryOperator(op, number, array_uint); \
Gura_AssignBinaryOperator(op, number, array_float); \
Gura_AssignBinaryOperator(op, number, array_double);

#define AssignArrayBitOperators(op) \
Gura_AssignBinaryOperator(op, array_char, array_char); \
Gura_AssignBinaryOperator(op, array_uchar, array_uchar); \
Gura_AssignBinaryOperator(op, array_short, array_short); \
Gura_AssignBinaryOperator(op, array_ushort, array_ushort); \
Gura_AssignBinaryOperator(op, array_long, array_long); \
Gura_AssignBinaryOperator(op, array_ulong, array_ulong); \
Gura_AssignBinaryOperator(op, array_int, array_int); \
Gura_AssignBinaryOperator(op, array_uint, array_uint); \
Gura_AssignBinaryOperator(op, array_char, number); \
Gura_AssignBinaryOperator(op, array_uchar, number); \
Gura_AssignBinaryOperator(op, array_short, number); \
Gura_AssignBinaryOperator(op, array_ushort, number); \
Gura_AssignBinaryOperator(op, array_long, number); \
Gura_AssignBinaryOperator(op, array_ulong, number); \
Gura_AssignBinaryOperator(op, array_int, number); \
Gura_AssignBinaryOperator(op, array_uint, number); \
Gura_AssignBinaryOperator(op, number, array_char);	\
Gura_AssignBinaryOperator(op, number, array_uchar); \
Gura_AssignBinaryOperator(op, number, array_short); \
Gura_AssignBinaryOperator(op, number, array_ushort); \
Gura_AssignBinaryOperator(op, number, array_long); \
Gura_AssignBinaryOperator(op, number, array_ulong); \
Gura_AssignBinaryOperator(op, number, array_int); \
Gura_AssignBinaryOperator(op, number, array_uint);

namespace Gura {

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

Gura_ImplementUnaryOperator(Pos, matrix)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, timedelta)
{
	return value;
}

template<typename T_Elem, typename T_ElemResult>
Value Pos_Array(Environment &env, const Value &value, ValueType valTypeResult)
{
	LoopOn_Array() {
		*pResult = static_cast<T_ElemResult>(*pElem);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

Gura_ImplementUnaryOperator(Pos, array_char)
{
	return Pos_Array<char, char>(env, value, VTYPE_array_char);
}

Gura_ImplementUnaryOperator(Pos, array_uchar)
{
	return Pos_Array<UChar, UChar>(env, value, VTYPE_array_uchar);
}

Gura_ImplementUnaryOperator(Pos, array_short)
{
	return Pos_Array<short, short>(env, value, VTYPE_array_short);
}

Gura_ImplementUnaryOperator(Pos, array_ushort)
{
	return Pos_Array<UShort, UShort>(env, value, VTYPE_array_ushort);
}

Gura_ImplementUnaryOperator(Pos, array_long)
{
	return Pos_Array<long, long>(env, value, VTYPE_array_long);
}

Gura_ImplementUnaryOperator(Pos, array_ulong)
{
	return Pos_Array<ULong, ULong>(env, value, VTYPE_array_ulong);
}

Gura_ImplementUnaryOperator(Pos, array_int)
{
	return Pos_Array<int, int>(env, value, VTYPE_array_int);
}

Gura_ImplementUnaryOperator(Pos, array_uint)
{
	return Pos_Array<UInt, UInt>(env, value, VTYPE_array_uint);
}

Gura_ImplementUnaryOperator(Pos, array_float)
{
	return Pos_Array<float, float>(env, value, VTYPE_array_float);
}

Gura_ImplementUnaryOperator(Pos, array_double)
{
	return Pos_Array<double, double>(env, value, VTYPE_array_double);
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

Gura_ImplementUnaryOperator(Neg, matrix)
{
	return Matrix::Neg(env, Object_matrix::GetObject(value)->GetMatrix());
}

Gura_ImplementUnaryOperator(Neg, timedelta)
{
	TimeDelta td = Object_timedelta::GetObject(value)->GetTimeDelta();
	return Value(new Object_timedelta(env, TimeDelta(-td.GetDays(), -td.GetSecsRaw(), -td.GetUSecs())));
}

template<typename T_Elem, typename T_ElemResult>
Value Neg_Array(Environment &env, const Value &value, ValueType valTypeResult)
{
	LoopOn_Array() {
		*pResult = -static_cast<T_ElemResult>(*pElem);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

Gura_ImplementUnaryOperator(Neg, array_char)
{
	return Neg_Array<char, char>(env, value, VTYPE_array_char);
}

Gura_ImplementUnaryOperator(Neg, array_uchar)
{
	return Neg_Array<UChar, char>(env, value, VTYPE_array_char);
}

Gura_ImplementUnaryOperator(Neg, array_short)
{
	return Neg_Array<short, short>(env, value, VTYPE_array_short);
}

Gura_ImplementUnaryOperator(Neg, array_ushort)
{
	return Neg_Array<UShort, short>(env, value, VTYPE_array_short);
}

Gura_ImplementUnaryOperator(Neg, array_long)
{
	return Neg_Array<long, long>(env, value, VTYPE_array_long);
}

Gura_ImplementUnaryOperator(Neg, array_ulong)
{
	return Neg_Array<ULong, long>(env, value, VTYPE_array_long);
}

Gura_ImplementUnaryOperator(Neg, array_int)
{
	return Neg_Array<int, int>(env, value, VTYPE_array_int);
}

Gura_ImplementUnaryOperator(Neg, array_uint)
{
	return Neg_Array<UInt, int>(env, value, VTYPE_array_int);
}

Gura_ImplementUnaryOperator(Neg, array_float)
{
	return Neg_Array<float, float>(env, value, VTYPE_array_float);
}

Gura_ImplementUnaryOperator(Neg, array_double)
{
	return Neg_Array<double, double>(env, value, VTYPE_array_double);
}

//-----------------------------------------------------------------------------
// UnaryOperator(Invert, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Inv, number)
{
	ULong num = ~static_cast<ULong>(value.GetNumber());
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
// UnaryOperator(SeqInf, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(SeqInf, number)
{
	Number numBegin = value.GetNumber();
	return Value(new Object_iterator(env, new Iterator_SequenceInf(numBegin)));
}

//-----------------------------------------------------------------------------
// UnaryOperator(Question, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(Question, any)
{
	bool rtn = value.GetBoolean();
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// UnaryOperator(Each, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(Each, any)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
	if (pIterator.IsNull()) return Value::Nil;
	return Value(new Object_iterator(env, pIterator.release()));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Add, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Add, number, number)
{
	return Value(valueLeft.GetNumber() + valueRight.GetNumber());
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
	const Rational b = Rational::FromNumber(valueRight.GetNumber());
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
	const Rational a = Rational::FromNumber(valueLeft.GetNumber());
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
	return Value(valueLeft.GetNumber() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Add, complex, number)
{
	return Value(valueLeft.GetComplex() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Add, matrix, matrix)
{
	return Matrix::AddSub(env, OPTYPE_Add,
		Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
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
	Signal &sig = env.GetSignal();
	Object_pointer *pObj = dynamic_cast<Object_pointer *>(
						Object_pointer::GetObject(valueLeft)->Clone());
	pObj->UnpackForward(sig,
						static_cast<int>(valueRight.GetNumber()), true);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(pObj);
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

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Add_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = *pLeft + *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Add_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = *pLeft + static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Add_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemRight>(numLeft) + *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayOperators(Add)

//-----------------------------------------------------------------------------
// BinaryOperator(Sub, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Sub, number, number)
{
	return Value(valueLeft.GetNumber() - valueRight.GetNumber());
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
	const Rational b = Rational::FromNumber(valueRight.GetNumber());
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
	const Rational a = Rational::FromNumber(valueLeft.GetNumber());
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
	return Value(valueLeft.GetNumber() - valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Sub, complex, number)
{
	return Value(valueLeft.GetComplex() - valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Sub, matrix, matrix)
{
	return Matrix::AddSub(env, OPTYPE_Sub,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
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
	return Value(::sqrt(static_cast<double>(color1.CalcDistSqu(color2))));
}

Gura_ImplementBinaryOperator(Sub, pointer, number)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Object_pointer> pObj(dynamic_cast<Object_pointer *>(
						Object_pointer::GetObject(valueLeft)->Clone()));
	pObj->UnpackForward(sig,
						-static_cast<int>(valueRight.GetNumber()), true);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(pObj.release());
}

Gura_ImplementBinaryOperator(Sub, pointer, pointer)
{
	Signal &sig = env.GetSignal();
	const Object_pointer *pObj1 = Object_pointer::GetObject(valueLeft);
	const Object_pointer *pObj2 = Object_pointer::GetObject(valueRight);
	if (&pObj1->GetBinary() != &pObj2->GetBinary()) {
		sig.SetError(ERR_ValueError,
			"cannot calculate difference between pointers of different binaries");
		return Value::Nil;
	}
	int offset1 = static_cast<int>(pObj1->GetOffset());
	int offset2 = static_cast<int>(pObj2->GetOffset());
	return Value(static_cast<Number>(offset1 - offset2));
}

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Sub_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = *pLeft - *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Sub_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = *pLeft - static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Sub_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemRight>(numLeft) - *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayOperators(Sub)

//-----------------------------------------------------------------------------
// BinaryOperator(Mul, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mul, number, number)
{
	return Value(valueLeft.GetNumber() * valueRight.GetNumber());
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
	const Rational b = Rational::FromNumber(valueRight.GetNumber());
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
	const Rational a = Rational::FromNumber(valueLeft.GetNumber());
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
	return Value(valueLeft.GetNumber() * valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Mul, complex, number)
{
	return Value(valueLeft.GetComplex() * valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Mul, matrix, matrix)
{
	return Matrix::Mul(env,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Mul, list, matrix)
{
	return Matrix::Mul(env,
			valueLeft.GetList(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Mul, any, matrix)
{
	return Matrix::Mul(env,
			valueLeft, Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Mul, matrix, list)
{
	return Matrix::Mul(env,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight.GetList());
}

Gura_ImplementBinaryOperator(Mul, matrix, any)
{
	return Matrix::Mul(env,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight);
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
	if (pObj->GetFunction()->IsUnary()) {
		ValueList valListArg(valueRight);
		Value result = pObj->Eval(env, valListArg);
		if (sig.IsSignalled()) return Value::Nil;
		return result;
	} else {
		sig.SetError(ERR_TypeError, "unary function is expected for multiplier-form applier");
		return Value::Nil;
	}
}

Gura_ImplementBinaryOperator(Mul, string, number)
{
	String str;
	for (int cnt = static_cast<int>(valueRight.GetNumber()); cnt > 0; cnt--) {
		str += valueLeft.GetString();
	}
	return Value(str);
}

Gura_ImplementBinaryOperator(Mul, number, string)
{
	String str;
	for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
		str += valueRight.GetString();
	}
	return Value(str);
}

Gura_ImplementBinaryOperator(Mul, binary, number)
{
	Binary buff;
	for (int cnt = static_cast<int>(valueRight.GetNumber()); cnt > 0; cnt--) {
		buff += valueLeft.GetBinary();
	}
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Mul, number, binary)
{
	Binary buff;
	for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
		buff += valueRight.GetBinary();
	}
	return Value(new Object_binary(env, buff, true));
}

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Mul_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = *pLeft * *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Mul_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = *pLeft * static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Mul_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemRight>(numLeft) * *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayOperators(Mul)

//-----------------------------------------------------------------------------
// BinaryOperator(Div, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Div, number, number)
{
	Signal &sig = env.GetSignal();
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(valueLeft.GetNumber() / numRight);
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
	const Rational b = Rational::FromNumber(valueRight.GetNumber());
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
	const Rational a = Rational::FromNumber(valueLeft.GetNumber());
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
	return Value(valueLeft.GetNumber() / numRight);
}

Gura_ImplementBinaryOperator(Div, complex, number)
{
	Signal &sig = env.GetSignal();
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(valueLeft.GetComplex() / numRight);
}

Gura_ImplementBinaryOperator(Div, matrix, any)
{
	return Matrix::Div(env,
					Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight);
}

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Div_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	LoopOn_ArrayAndArray() {
		if (*pRight == 0) {
			Operator::SetError_DivideByZero(sig);
			return Value::Nil;
		}
		*pResult = *pLeft / *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Div_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	Array<T_ElemLeft> *pArrayLeft = Object_array<T_ElemLeft>::GetObject(valueLeft)->GetArray();
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	size_t cnt = pArrayLeft->GetSize();
	AutoPtr<Array<T_ElemResult> > pArrayResult(new Array<T_ElemResult>(cnt));
	T_ElemLeft *pLeft = pArrayLeft->GetPointer();
	T_ElemResult *pResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < cnt; i++, pLeft++, pResult++) {
		*pResult = *pLeft / static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Div_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	LoopOn_NumberAndArray() {
		if (*pRight == 0) {
			Operator::SetError_DivideByZero(sig);
			return Value::Nil;
		}
		*pResult = static_cast<T_ElemRight>(numLeft) / *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayOperators(Div)

//-----------------------------------------------------------------------------
// BinaryOperator(Mod, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mod, number, number)
{
	Signal &sig = env.GetSignal();
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(::fmod(valueLeft.GetNumber(), numRight));
}

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Mod_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	LoopOn_ArrayAndArray() {
		if (*pRight == 0) {
			Operator::SetError_DivideByZero(sig);
			return Value::Nil;
		}
		*pResult = static_cast<T_ElemResult>(::fmod(static_cast<double>(*pLeft), static_cast<double>(*pRight)));
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Mod_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	Array<T_ElemLeft> *pArrayLeft = Object_array<T_ElemLeft>::GetObject(valueLeft)->GetArray();
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	size_t cnt = pArrayLeft->GetSize();
	AutoPtr<Array<T_ElemResult> > pArrayResult(new Array<T_ElemResult>(cnt));
	T_ElemLeft *pLeft = pArrayLeft->GetPointer();
	T_ElemResult *pResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < cnt; i++, pLeft++, pResult++) {
		*pResult = static_cast<T_ElemResult>(::fmod(static_cast<double>(*pLeft), static_cast<double>(numRight)));
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Mod_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	LoopOn_NumberAndArray() {
		if (*pRight == 0) {
			Operator::SetError_DivideByZero(sig);
			return Value::Nil;
		}
		*pResult = static_cast<T_ElemResult>(::fmod(static_cast<double>(numLeft), static_cast<double>(*pRight)));
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayOperators(Mod)

//-----------------------------------------------------------------------------
// BinaryOperator(Pow, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pow, number, number)
{
	return Value(::pow(valueLeft.GetNumber(), valueRight.GetNumber()));
}

Gura_ImplementBinaryOperator(Pow, complex, complex)
{
	return Value(std::pow(valueLeft.GetComplex(), valueRight.GetComplex()));
}

Gura_ImplementBinaryOperator(Pow, number, complex)
{
	return Value(std::pow(valueLeft.GetNumber(), valueRight.GetComplex()));
}

Gura_ImplementBinaryOperator(Pow, complex, number)
{
	return Value(std::pow(valueLeft.GetComplex(), valueRight.GetNumber()));
}

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Pow_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = static_cast<T_ElemResult>(std::pow(static_cast<double>(*pLeft), static_cast<double>(*pRight)));
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Pow_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = static_cast<T_ElemResult>(std::pow(static_cast<double>(*pLeft), static_cast<double>(numRight)));
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Pow_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemResult>(std::pow(static_cast<double>(numLeft), static_cast<double>(*pRight)));
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayOperators(Pow)

//-----------------------------------------------------------------------------
// BinaryOperator(Eq, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Eq, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp == 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Ne, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ne, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp != 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Gt, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Gt, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp > 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Lt, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Lt, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp < 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Ge, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ge, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp >= 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Le, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Le, any, any)
{
	Signal &sig = env.GetSignal();
	int cmp = Value::Compare(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(cmp <= 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Cmp, *, *)
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
	return Value(Value::CompareNumber(valueLeft.GetNumber(), valueRight.GetNumber()));
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
	return Value(Value::CompareNumber(valueLeft.GetNumber(), ratio.numer / ratio.denom));
}

Gura_ImplementBinaryOperator(Cmp, rational, number)
{
	Signal &sig = env.GetSignal();
	const Rational &ratio = valueLeft.GetRational();
	if (ratio.denom == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	return Value(Value::CompareNumber(ratio.numer / ratio.denom, valueRight.GetNumber()));
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
// BinaryOperator(Contains, *, *)
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
// BinaryOperator(And, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(And, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) &
						static_cast<ULong>(valueRight.GetNumber()));
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

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value And_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = *pLeft & *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value And_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = *pLeft & static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value And_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemRight>(numLeft) & *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayBitOperators(And)

//-----------------------------------------------------------------------------
// BinaryOperator(Or, *, *)
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

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Or_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = *pLeft | *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Or_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = *pLeft | static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Or_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemRight>(numLeft) | *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayBitOperators(Or)

//-----------------------------------------------------------------------------
// BinaryOperator(Xor, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Xor, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) ^
						static_cast<ULong>(valueRight.GetNumber()));
}

Gura_ImplementBinaryOperator(Xor, boolean, boolean)
{
	bool flagLeft = valueLeft.GetBoolean();
	bool flagRight = valueRight.GetBoolean();
	return Value((flagLeft && !flagRight) || (!flagLeft && flagRight));
}

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Xor_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = *pLeft ^ *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Xor_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = *pLeft ^ static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Xor_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemRight>(numLeft) ^ *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayBitOperators(Xor)

//-----------------------------------------------------------------------------
// BinaryOperator(Shl, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shl, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) <<
							static_cast<ULong>(valueRight.GetNumber()));
}

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Shl_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = *pLeft << *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Shl_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = *pLeft << static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Shl_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemRight>(numLeft) << *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayBitOperators(Shl)

//-----------------------------------------------------------------------------
// BinaryOperator(Shr, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shr, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) >>
							static_cast<ULong>(valueRight.GetNumber()));
}

template<typename T_ElemLeft, typename T_ElemRight, typename T_ElemResult>
Value Shr_ArrayAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndArray() {
		*pResult = *pLeft >> *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemLeft, typename T_ElemResult>
Value Shr_ArrayAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayAndNumber() {
		*pResult = *pLeft >> static_cast<T_ElemLeft>(numRight);
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemRight, typename T_ElemResult>
Value Shr_NumberAndArray(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArray() {
		*pResult = static_cast<T_ElemRight>(numLeft) >> *pRight;
	}
	return Value(new Object_array<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

ImplementArrayBitOperators(Shr)

//-----------------------------------------------------------------------------
// BinaryOperator(OrOr, any, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(OrOr, any, any)
{
	if (valueLeft.GetBoolean()) return valueLeft;
	return valueRight;
}

//-----------------------------------------------------------------------------
// BinaryOperator(AndAnd, any, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(AndAnd, any, any)
{
	if (!valueLeft.GetBoolean()) return valueLeft;
	return valueRight;
}

//-----------------------------------------------------------------------------
// BinaryOperator(Seq, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Seq, number, number)
{
	Number numBegin = valueLeft.GetNumber();
	Number numEnd = valueRight.GetNumber();
	Number numStep = (numEnd >= numBegin)? +1 : -1;
	return Value(new Object_iterator(env, new Iterator_Sequence(numBegin, numEnd, numStep)));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Pair, symbol, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pair, symbol, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Pair, string, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pair, string, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Pair, number, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pair, number, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// OperatorEntryCustom
//-----------------------------------------------------------------------------
Value OperatorEntryCustom::DoEval(Environment &env, const Value &value) const
{
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->AddValue(env, value)) return Value::Nil;
	return _pFunc->Eval(env, *pArg);
}

Value OperatorEntryCustom::DoEval(Environment &env,
					const Value &valueLeft, const Value &valueRight) const
{
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->AddValue(env, valueLeft, valueRight)) return Value::Nil;
	return _pFunc->Eval(env, *pArg);
}

//-----------------------------------------------------------------------------
// Operator assignment
//-----------------------------------------------------------------------------
void Operator::AssignBasicOperators(Environment &env)
{
	Gura_AssignUnaryOperator(Pos, number);
	Gura_AssignUnaryOperator(Pos, complex);
	Gura_AssignUnaryOperator(Pos, rational);
	Gura_AssignUnaryOperator(Pos, matrix);
	Gura_AssignUnaryOperator(Pos, timedelta);
	Gura_AssignUnaryOperator(Pos, array_char);
	Gura_AssignUnaryOperator(Pos, array_uchar);
	Gura_AssignUnaryOperator(Pos, array_short);
	Gura_AssignUnaryOperator(Pos, array_ushort);
	Gura_AssignUnaryOperator(Pos, array_long);
	Gura_AssignUnaryOperator(Pos, array_ulong);
	Gura_AssignUnaryOperator(Pos, array_int);
	Gura_AssignUnaryOperator(Pos, array_uint);
	Gura_AssignUnaryOperator(Pos, array_float);
	Gura_AssignUnaryOperator(Pos, array_double);
	Gura_AssignUnaryOperator(Neg, number);
	Gura_AssignUnaryOperator(Neg, complex);
	Gura_AssignUnaryOperator(Neg, rational);
	Gura_AssignUnaryOperator(Neg, matrix);
	Gura_AssignUnaryOperator(Neg, timedelta);
	Gura_AssignUnaryOperator(Neg, array_char);
	Gura_AssignUnaryOperator(Neg, array_uchar);
	Gura_AssignUnaryOperator(Neg, array_short);
	Gura_AssignUnaryOperator(Neg, array_ushort);
	Gura_AssignUnaryOperator(Neg, array_long);
	Gura_AssignUnaryOperator(Neg, array_ulong);
	Gura_AssignUnaryOperator(Neg, array_int);
	Gura_AssignUnaryOperator(Neg, array_uint);
	Gura_AssignUnaryOperator(Neg, array_float);
	Gura_AssignUnaryOperator(Neg, array_double);
	Gura_AssignUnaryOperator(Inv, number);
	Gura_AssignUnaryOperator(Not, any);
	Gura_AssignUnaryOperatorSuffix(SeqInf, number);
	Gura_AssignUnaryOperatorSuffix(Question, any);
	Gura_AssignUnaryOperatorSuffix(Each, any);
	Gura_AssignBinaryOperator(Add, number, number);
	Gura_AssignBinaryOperator(Add, number, complex);
	Gura_AssignBinaryOperator(Add, number, rational);
	Gura_AssignBinaryOperator(Add, complex, number);
	Gura_AssignBinaryOperator(Add, complex, complex);
	Gura_AssignBinaryOperator(Add, rational, number);
	Gura_AssignBinaryOperator(Add, rational, rational);
	Gura_AssignBinaryOperator(Add, matrix, matrix);
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
	AssignArrayOperators(Add);
	Gura_AssignBinaryOperator(Sub, number, number);
	Gura_AssignBinaryOperator(Sub, number, complex);
	Gura_AssignBinaryOperator(Sub, number, rational);
	Gura_AssignBinaryOperator(Sub, complex, number);
	Gura_AssignBinaryOperator(Sub, complex, complex);
	Gura_AssignBinaryOperator(Sub, rational, number);
	Gura_AssignBinaryOperator(Sub, rational, rational);
	Gura_AssignBinaryOperator(Sub, matrix, matrix);
	Gura_AssignBinaryOperator(Sub, datetime, timedelta);
	Gura_AssignBinaryOperator(Sub, datetime, datetime);
	Gura_AssignBinaryOperator(Sub, timedelta, timedelta);
	Gura_AssignBinaryOperator(Sub, color, color);
	Gura_AssignBinaryOperator(Sub, pointer, number);
	Gura_AssignBinaryOperator(Sub, pointer, pointer);
	AssignArrayOperators(Sub);
	Gura_AssignBinaryOperator(Mul, number, number);
	Gura_AssignBinaryOperator(Mul, number, complex);
	Gura_AssignBinaryOperator(Mul, number, rational);
	Gura_AssignBinaryOperator(Mul, complex, number);
	Gura_AssignBinaryOperator(Mul, complex, complex);
	Gura_AssignBinaryOperator(Mul, rational, number);
	Gura_AssignBinaryOperator(Mul, rational, rational);
	Gura_AssignBinaryOperator(Mul, matrix, matrix);
	Gura_AssignBinaryOperator(Mul, list, matrix);
	Gura_AssignBinaryOperator(Mul, any, matrix);
	Gura_AssignBinaryOperator(Mul, matrix, list);
	Gura_AssignBinaryOperator(Mul, matrix, any);
	Gura_AssignBinaryOperator(Mul, timedelta, number);
	Gura_AssignBinaryOperator(Mul, number, timedelta);
	Gura_AssignBinaryOperator(Mul, function, any);
	Gura_AssignBinaryOperator(Mul, string, number);
	Gura_AssignBinaryOperator(Mul, number, string);
	Gura_AssignBinaryOperator(Mul, binary, number);
	Gura_AssignBinaryOperator(Mul, number, binary);
	AssignArrayOperators(Mul);
	Gura_AssignBinaryOperator(Div, number, number);
	Gura_AssignBinaryOperator(Div, number, complex);
	Gura_AssignBinaryOperator(Div, number, rational);
	Gura_AssignBinaryOperator(Div, complex, number);
	Gura_AssignBinaryOperator(Div, complex, complex);
	Gura_AssignBinaryOperator(Div, rational, number);
	Gura_AssignBinaryOperator(Div, rational, rational);
	Gura_AssignBinaryOperator(Div, matrix, any);
	AssignArrayOperators(Div);
	Gura_AssignBinaryOperator(Mod, number, number);
	AssignArrayOperators(Mod);
	Gura_AssignBinaryOperator(Pow, number, number);
	Gura_AssignBinaryOperator(Pow, complex, complex);
	Gura_AssignBinaryOperator(Pow, number, complex);
	Gura_AssignBinaryOperator(Pow, complex, number);
	AssignArrayOperators(Pow);
	Gura_AssignBinaryOperator(Eq, any, any);
	Gura_AssignBinaryOperator(Ne, any, any);
	Gura_AssignBinaryOperator(Gt, any, any);
	Gura_AssignBinaryOperator(Lt, any, any);
	Gura_AssignBinaryOperator(Ge, any, any);
	Gura_AssignBinaryOperator(Le, any, any);
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
	AssignArrayBitOperators(And);
	Gura_AssignBinaryOperator(Or, number, number);
	Gura_AssignBinaryOperator(Or, boolean, boolean);
	Gura_AssignBinaryOperator(Or, nil, any);
	Gura_AssignBinaryOperator(Or, any, nil);
	AssignArrayBitOperators(Or);
	Gura_AssignBinaryOperator(Xor, number, number);
	Gura_AssignBinaryOperator(Xor, boolean, boolean);
	AssignArrayBitOperators(Xor);
	Gura_AssignBinaryOperator(Shl, number, number);
	AssignArrayBitOperators(Shl);
	Gura_AssignBinaryOperator(Shr, number, number);
	AssignArrayBitOperators(Shr);
	Gura_AssignBinaryOperator(OrOr, any, any);
	Gura_AssignBinaryOperator(AndAnd, any, any);
	Gura_AssignBinaryOperator(Seq, number, number);
	Gura_AssignBinaryOperator(Pair, symbol, any);
	Gura_AssignBinaryOperator(Pair, string, any);
	Gura_AssignBinaryOperator(Pair, number, any);
}

}
