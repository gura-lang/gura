//=============================================================================
// OperatorBasic
//=============================================================================
#include "stdafx.h"
#include "gura/Class_arrayT.h"
#include <math.h>

#define LoopOn_ArrayT() \
ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT(); \
size_t cnt = pArrayT->GetCountTotal(); \
AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(new ArrayT<T_ElemResult>(cnt)); \
T_Elem *pElem = pArrayT->GetPointer(); \
T_ElemResult *pResult = pArrayTResult->GetPointer();	\
for (size_t i = 0; i < cnt; i++, pElem++, pResult++)

#define LoopOn_ArrayTAndArrayT() \
ArrayT<T_ElemL> *pArrayTLeft = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT(); \
ArrayT<T_ElemR> *pArrayTRight = Object_arrayT<T_ElemR>::GetObject(valueRight)->GetArrayT(); \
size_t cnt = ChooseMin(pArrayTLeft->GetCountTotal(), pArrayTRight->GetCountTotal()); \
AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(new ArrayT<T_ElemResult>(cnt)); \
T_ElemL *pLeft = pArrayTLeft->GetPointer(); \
T_ElemR *pRight = pArrayTRight->GetPointer(); \
T_ElemResult *pResult = pArrayTResult->GetPointer();	\
for (size_t i = 0; i < cnt; i++, pLeft++, pRight++, pResult++)

#define LoopOn_ArrayTAndNumber() \
ArrayT<T_ElemL> *pArrayTLeft = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT(); \
Number numRight = valueRight.GetNumber(); \
size_t cnt = pArrayTLeft->GetCountTotal(); \
AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(new ArrayT<T_ElemResult>(cnt)); \
T_ElemL *pLeft = pArrayTLeft->GetPointer(); \
T_ElemResult *pResult = pArrayTResult->GetPointer();	\
for (size_t i = 0; i < cnt; i++, pLeft++, pResult++)

#define LoopOn_NumberAndArrayT() \
Number numLeft = valueLeft.GetNumber(); \
ArrayT<T_ElemR> *pArrayTRight = Object_arrayT<T_ElemR>::GetObject(valueRight)->GetArrayT(); \
size_t cnt = pArrayTRight->GetCountTotal(); \
AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(new ArrayT<T_ElemResult>(cnt)); \
T_ElemR *pRight = pArrayTRight->GetPointer(); \
T_ElemResult *pResult = pArrayTResult->GetPointer();	\
for (size_t i = 0; i < cnt; i++, pRight++, pResult++)

#define ImplementArrayTOperators(op) \
Gura_ImplementBinaryOperator(op, array_at_char, array_at_char) \
{ \
	return op##_ArrayTAndArrayT<Char, Char, Char>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, array_at_uchar, array_at_uchar) \
{ \
	return op##_ArrayTAndArrayT<UChar, UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_at_short, array_at_short) \
{ \
	return op##_ArrayTAndArrayT<Short, Short, Short>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, array_at_ushort, array_at_ushort) \
{ \
	return op##_ArrayTAndArrayT<UShort, UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_at_int, array_at_int) \
{ \
	return op##_ArrayTAndArrayT<Int, Int, Int>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint, array_at_uint) \
{ \
	return op##_ArrayTAndArrayT<UInt, UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, array_at_int32, array_at_int32) \
{ \
	return op##_ArrayTAndArrayT<Int32, Int32, Int32>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint32, array_at_uint32) \
{ \
	return op##_ArrayTAndArrayT<UInt32, UInt32, UInt32>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, array_at_int64, array_at_int64) \
{ \
	return op##_ArrayTAndArrayT<Int64, Int64, Int64>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint64, array_at_uint64) \
{ \
	return op##_ArrayTAndArrayT<UInt64, UInt64, UInt64>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \
Gura_ImplementBinaryOperator(op, array_at_float, array_at_float) \
{ \
	return op##_ArrayTAndArrayT<float, float, float>(env, valueLeft, valueRight, VTYPE_array_at_float); \
} \
Gura_ImplementBinaryOperator(op, array_at_double, array_at_double) \
{ \
	return op##_ArrayTAndArrayT<double, double, double>(env, valueLeft, valueRight, VTYPE_array_at_double); \
} \
Gura_ImplementBinaryOperator(op, array_at_char, number) \
{ \
	return op##_ArrayTAndNumber<Char, Char>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, array_at_uchar, number) \
{ \
	return op##_ArrayTAndNumber<UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_at_short, number) \
{ \
	return op##_ArrayTAndNumber<Short, Short>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, array_at_ushort, number)	\
{ \
	return op##_ArrayTAndNumber<UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_at_int, number) \
{ \
	return op##_ArrayTAndNumber<Int, Int>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint, number) \
{ \
	return op##_ArrayTAndNumber<UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, array_at_int32, number) \
{ \
	return op##_ArrayTAndNumber<Int32, Int32>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint32, number) \
{ \
	return op##_ArrayTAndNumber<UInt32, UInt32>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, array_at_int64, number) \
{ \
	return op##_ArrayTAndNumber<Int64, Int64>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint64, number) \
{ \
	return op##_ArrayTAndNumber<UInt64, UInt64>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \
Gura_ImplementBinaryOperator(op, array_at_float, number) \
{ \
	return op##_ArrayTAndNumber<float, float>(env, valueLeft, valueRight, VTYPE_array_at_float); \
} \
Gura_ImplementBinaryOperator(op, array_at_double, number) \
{ \
	return op##_ArrayTAndNumber<double, double>(env, valueLeft, valueRight, VTYPE_array_at_double); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_char) \
{ \
	return op##_NumberAndArrayT<Char, Char>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uchar)	\
{ \
	return op##_NumberAndArrayT<UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_short)	\
{ \
	return op##_NumberAndArrayT<Short, Short>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_ushort)	\
{ \
	return op##_NumberAndArrayT<UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int) \
{ \
	return op##_NumberAndArrayT<Int, Int>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint)	\
{ \
	return op##_NumberAndArrayT<UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int32) \
{ \
	return op##_NumberAndArrayT<Int32, Int32>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint32)	\
{ \
	return op##_NumberAndArrayT<UInt32, UInt32>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int64)	\
{ \
	return op##_NumberAndArrayT<Int64, Int64>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint64) \
{ \
	return op##_NumberAndArrayT<UInt64, UInt64>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_float)	\
{ \
	return op##_NumberAndArrayT<float, float>(env, valueLeft, valueRight, VTYPE_array_at_float); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_double)	\
{ \
	return op##_NumberAndArrayT<double, double>(env, valueLeft, valueRight, VTYPE_array_at_double); \
}

#define ImplementArrayTBitOperators(op) \
Gura_ImplementBinaryOperator(op, array_at_char, array_at_char) \
{ \
	return op##_ArrayTAndArrayT<Char, Char, Char>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, array_at_uchar, array_at_uchar) \
{ \
	return op##_ArrayTAndArrayT<UChar, UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_at_short, array_at_short) \
{ \
	return op##_ArrayTAndArrayT<Short, Short, Short>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, array_at_ushort, array_at_ushort) \
{ \
	return op##_ArrayTAndArrayT<UShort, UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_at_int, array_at_int) \
{ \
	return op##_ArrayTAndArrayT<Int, Int, Int>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint, array_at_uint) \
{ \
	return op##_ArrayTAndArrayT<UInt, UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, array_at_int32, array_at_int32) \
{ \
	return op##_ArrayTAndArrayT<Int32, Int32, Int32>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint32, array_at_uint32) \
{ \
	return op##_ArrayTAndArrayT<UInt32, UInt32, UInt32>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, array_at_int64, array_at_int64) \
{ \
	return op##_ArrayTAndArrayT<Int64, Int64, Int64>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint64, array_at_uint64) \
{ \
	return op##_ArrayTAndArrayT<UInt64, UInt64, UInt64>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \
Gura_ImplementBinaryOperator(op, array_at_char, number) \
{ \
	return op##_ArrayTAndNumber<Char, Char>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, array_at_uchar, number) \
{ \
	return op##_ArrayTAndNumber<UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_at_short, number) \
{ \
	return op##_ArrayTAndNumber<Short, Short>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, array_at_ushort, number)	\
{ \
	return op##_ArrayTAndNumber<UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_at_int, number) \
{ \
	return op##_ArrayTAndNumber<Int, Int>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint, number) \
{ \
	return op##_ArrayTAndNumber<UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, array_at_int32, number) \
{ \
	return op##_ArrayTAndNumber<Int32, Int32>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint32, number) \
{ \
	return op##_ArrayTAndNumber<UInt32, UInt32>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, array_at_int64, number) \
{ \
	return op##_ArrayTAndNumber<Int64, Int64>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint64, number) \
{ \
	return op##_ArrayTAndNumber<UInt64, UInt64>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_char) \
{ \
	return op##_NumberAndArrayT<Char, Char>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uchar)	\
{ \
	return op##_NumberAndArrayT<UChar, UChar>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_short)	\
{ \
	return op##_NumberAndArrayT<Short, Short>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_ushort)	\
{ \
	return op##_NumberAndArrayT<UShort, UShort>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int) \
{ \
	return op##_NumberAndArrayT<Int, Int>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint)	\
{ \
	return op##_NumberAndArrayT<UInt, UInt>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int32) \
{ \
	return op##_NumberAndArrayT<Int32, Int32>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint32)	\
{ \
	return op##_NumberAndArrayT<UInt32, UInt32>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int64)	\
{ \
	return op##_NumberAndArrayT<Int64, Int64>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint64) \
{ \
	return op##_NumberAndArrayT<UInt64, UInt64>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \

#define AssignArrayTOperators(op) \
Gura_AssignBinaryOperator(op, array_at_char, array_at_char); \
Gura_AssignBinaryOperator(op, array_at_uchar, array_at_uchar); \
Gura_AssignBinaryOperator(op, array_at_short, array_at_short); \
Gura_AssignBinaryOperator(op, array_at_ushort, array_at_ushort); \
Gura_AssignBinaryOperator(op, array_at_int, array_at_int);	   \
Gura_AssignBinaryOperator(op, array_at_uint, array_at_uint); \
Gura_AssignBinaryOperator(op, array_at_int32, array_at_int32); \
Gura_AssignBinaryOperator(op, array_at_uint32, array_at_uint32); \
Gura_AssignBinaryOperator(op, array_at_int64, array_at_int64); \
Gura_AssignBinaryOperator(op, array_at_uint64, array_at_uint64); \
Gura_AssignBinaryOperator(op, array_at_float, array_at_float); \
Gura_AssignBinaryOperator(op, array_at_double, array_at_double); \
Gura_AssignBinaryOperator(op, array_at_char, number); \
Gura_AssignBinaryOperator(op, array_at_uchar, number); \
Gura_AssignBinaryOperator(op, array_at_short, number); \
Gura_AssignBinaryOperator(op, array_at_ushort, number); \
Gura_AssignBinaryOperator(op, array_at_int, number); \
Gura_AssignBinaryOperator(op, array_at_uint, number); \
Gura_AssignBinaryOperator(op, array_at_int32, number); \
Gura_AssignBinaryOperator(op, array_at_uint32, number); \
Gura_AssignBinaryOperator(op, array_at_int64, number); \
Gura_AssignBinaryOperator(op, array_at_uint64, number); \
Gura_AssignBinaryOperator(op, array_at_float, number); \
Gura_AssignBinaryOperator(op, array_at_double, number); \
Gura_AssignBinaryOperator(op, number, array_at_char);	\
Gura_AssignBinaryOperator(op, number, array_at_uchar); \
Gura_AssignBinaryOperator(op, number, array_at_short); \
Gura_AssignBinaryOperator(op, number, array_at_ushort); \
Gura_AssignBinaryOperator(op, number, array_at_int); \
Gura_AssignBinaryOperator(op, number, array_at_uint); \
Gura_AssignBinaryOperator(op, number, array_at_int32); \
Gura_AssignBinaryOperator(op, number, array_at_uint32); \
Gura_AssignBinaryOperator(op, number, array_at_int64); \
Gura_AssignBinaryOperator(op, number, array_at_uint64); \
Gura_AssignBinaryOperator(op, number, array_at_float); \
Gura_AssignBinaryOperator(op, number, array_at_double);

#define AssignArrayTBitOperators(op) \
Gura_AssignBinaryOperator(op, array_at_char, array_at_char); \
Gura_AssignBinaryOperator(op, array_at_uchar, array_at_uchar); \
Gura_AssignBinaryOperator(op, array_at_short, array_at_short); \
Gura_AssignBinaryOperator(op, array_at_ushort, array_at_ushort); \
Gura_AssignBinaryOperator(op, array_at_int, array_at_int); \
Gura_AssignBinaryOperator(op, array_at_uint, array_at_uint); \
Gura_AssignBinaryOperator(op, array_at_int32, array_at_int32); \
Gura_AssignBinaryOperator(op, array_at_uint32, array_at_uint32); \
Gura_AssignBinaryOperator(op, array_at_int64, array_at_int64); \
Gura_AssignBinaryOperator(op, array_at_uint64, array_at_uint64); \
Gura_AssignBinaryOperator(op, array_at_char, number); \
Gura_AssignBinaryOperator(op, array_at_uchar, number); \
Gura_AssignBinaryOperator(op, array_at_short, number); \
Gura_AssignBinaryOperator(op, array_at_ushort, number); \
Gura_AssignBinaryOperator(op, array_at_int, number); \
Gura_AssignBinaryOperator(op, array_at_uint, number); \
Gura_AssignBinaryOperator(op, array_at_int32, number); \
Gura_AssignBinaryOperator(op, array_at_uint32, number); \
Gura_AssignBinaryOperator(op, array_at_int64, number); \
Gura_AssignBinaryOperator(op, array_at_uint64, number); \
Gura_AssignBinaryOperator(op, number, array_at_char);	\
Gura_AssignBinaryOperator(op, number, array_at_uchar); \
Gura_AssignBinaryOperator(op, number, array_at_short); \
Gura_AssignBinaryOperator(op, number, array_at_ushort); \
Gura_AssignBinaryOperator(op, number, array_at_int); \
Gura_AssignBinaryOperator(op, number, array_at_uint); \
Gura_AssignBinaryOperator(op, number, array_at_int32); \
Gura_AssignBinaryOperator(op, number, array_at_uint32); \
Gura_AssignBinaryOperator(op, number, array_at_int64); \
Gura_AssignBinaryOperator(op, number, array_at_uint64);

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

Gura_ImplementUnaryOperator(Pos, matrix)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, timedelta)
{
	return value;
}

template<typename T_ElemResult, typename T_Elem>
Value Pos_ArrayT(Environment &env, const Value &value, ValueType valTypeResult)
{
	LoopOn_ArrayT() {
		*pResult = static_cast<T_ElemResult>(*pElem);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

Gura_ImplementUnaryOperator(Pos, array_at_char)
{
	return Pos_ArrayT<Char, Char>(env, value, VTYPE_array_at_char);
}

Gura_ImplementUnaryOperator(Pos, array_at_uchar)
{
	return Pos_ArrayT<UChar, UChar>(env, value, VTYPE_array_at_uchar);
}

Gura_ImplementUnaryOperator(Pos, array_at_short)
{
	return Pos_ArrayT<Short, Short>(env, value, VTYPE_array_at_short);
}

Gura_ImplementUnaryOperator(Pos, array_at_ushort)
{
	return Pos_ArrayT<UShort, UShort>(env, value, VTYPE_array_at_ushort);
}

Gura_ImplementUnaryOperator(Pos, array_at_int)
{
	return Pos_ArrayT<Int, Int>(env, value, VTYPE_array_at_int);
}

Gura_ImplementUnaryOperator(Pos, array_at_uint)
{
	return Pos_ArrayT<UInt, UInt>(env, value, VTYPE_array_at_uint);
}

Gura_ImplementUnaryOperator(Pos, array_at_int32)
{
	return Pos_ArrayT<Int32, Int32>(env, value, VTYPE_array_at_int32);
}

Gura_ImplementUnaryOperator(Pos, array_at_uint32)
{
	return Pos_ArrayT<UInt32, UInt32>(env, value, VTYPE_array_at_uint32);
}

Gura_ImplementUnaryOperator(Pos, array_at_int64)
{
	return Pos_ArrayT<Int64, Int64>(env, value, VTYPE_array_at_int64);
}

Gura_ImplementUnaryOperator(Pos, array_at_uint64)
{
	return Pos_ArrayT<UInt64, UInt64>(env, value, VTYPE_array_at_uint64);
}

Gura_ImplementUnaryOperator(Pos, array_at_float)
{
	return Pos_ArrayT<float, float>(env, value, VTYPE_array_at_float);
}

Gura_ImplementUnaryOperator(Pos, array_at_double)
{
	return Pos_ArrayT<double, double>(env, value, VTYPE_array_at_double);
}

//-----------------------------------------------------------------------------
// [-A] ... UnaryOperator(Neg, A)
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

Gura_ImplementUnaryOperator(Neg, vertex)
{
	const Vertex &vertex = Object_vertex::GetObject(value)->GetVertex();
	return Value(new Object_vertex(env, Vertex(-vertex.x, -vertex.y, -vertex.z)));
}

template<typename T_ElemResult, typename T_Elem>
Value Neg_ArrayT(Environment &env, const Value &value, ValueType valTypeResult)
{
	LoopOn_ArrayT() {
		*pResult = -static_cast<T_ElemResult>(*pElem);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

Gura_ImplementUnaryOperator(Neg, array_at_char)
{
	return Neg_ArrayT<Char, Char>(env, value, VTYPE_array_at_char);
}

Gura_ImplementUnaryOperator(Neg, array_at_uchar)
{
	return Neg_ArrayT<Char, UChar>(env, value, VTYPE_array_at_char);
}

Gura_ImplementUnaryOperator(Neg, array_at_short)
{
	return Neg_ArrayT<Short, Short>(env, value, VTYPE_array_at_short);
}

Gura_ImplementUnaryOperator(Neg, array_at_ushort)
{
	return Neg_ArrayT<Short, UShort>(env, value, VTYPE_array_at_short);
}

Gura_ImplementUnaryOperator(Neg, array_at_int)
{
	return Neg_ArrayT<Int, Int>(env, value, VTYPE_array_at_int);
}

Gura_ImplementUnaryOperator(Neg, array_at_uint)
{
	return Neg_ArrayT<Int, UInt>(env, value, VTYPE_array_at_int);
}

Gura_ImplementUnaryOperator(Neg, array_at_int32)
{
	return Neg_ArrayT<Int32, Int32>(env, value, VTYPE_array_at_int32);
}

Gura_ImplementUnaryOperator(Neg, array_at_uint32)
{
	return Neg_ArrayT<Int32, UInt32>(env, value, VTYPE_array_at_int32);
}

Gura_ImplementUnaryOperator(Neg, array_at_int64)
{
	return Neg_ArrayT<Int64, Int64>(env, value, VTYPE_array_at_int64);
}

Gura_ImplementUnaryOperator(Neg, array_at_uint64)
{
	return Neg_ArrayT<Int64, UInt64>(env, value, VTYPE_array_at_int64);
}

Gura_ImplementUnaryOperator(Neg, array_at_float)
{
	return Neg_ArrayT<float, float>(env, value, VTYPE_array_at_float);
}

Gura_ImplementUnaryOperator(Neg, array_at_double)
{
	return Neg_ArrayT<double, double>(env, value, VTYPE_array_at_double);
}

//-----------------------------------------------------------------------------
// [~A] ... UnaryOperator(Invert, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Inv, number)
{
	ULong num = ~static_cast<ULong>(value.GetNumber());
	return Value(static_cast<Number>(num));
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
Gura_ImplementUnaryOperatorSuffix(SeqInf, number)
{
	Number numBegin = value.GetNumber();
	return Value(new Object_iterator(env, new Iterator_SequenceInf(numBegin)));
}

//-----------------------------------------------------------------------------
// [A?] ... UnaryOperator(Question, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(Question, any)
{
	bool rtn = value.GetBoolean();
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// [A*] ... UnaryOperator(Each, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(Each, any)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
	if (pIterator.IsNull()) return Value::Nil;
	return Value(new Object_iterator(env, pIterator.release()));
}

//-----------------------------------------------------------------------------
// [A + B] ... BinaryOperator(Add, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Add, number, number)
{
	return Value(valueLeft.GetNumber() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Add, boolean, boolean)
{
	return Value(valueLeft.GetNumber() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Add, number, boolean)
{
	return Value(valueLeft.GetNumber() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Add, boolean, number)
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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Add_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
#if 0
	ArrayT<T_ElemL> *pArrayL = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT();
	ArrayT<T_ElemR> *pArrayR = Object_arrayT<T_ElemR>::GetObject(valueRight)->GetArrayT();
	size_t cnt = ChooseMin(pArrayL->GetCountTotal(), pArrayR->GetCountTotal());
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(cnt));
	if (!Add(env.GetSignal(), *pArrayResult, *pArrayL, *pArrayR)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
#endif
	return Op_ArrayAndArray<T_ElemResult, T_ElemL, T_ElemR, Add>(env, valueLeft, valueRight, valTypeResult);
}

template<typename T_ElemResult, typename T_ElemL>
Value Add_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = *pLeft + static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Add_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemR>(numLeft) + *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTOperators(Add)

//-----------------------------------------------------------------------------
// [A - B] ... BinaryOperator(Sub, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Sub, number, number)
{
	return Value(valueLeft.GetNumber() - valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Sub, boolean, boolean)
{
	return Value(valueLeft.GetNumber() - valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Sub, number, boolean)
{
	return Value(valueLeft.GetNumber() - valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Sub, boolean, number)
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
	AutoPtr<Object_pointer> pObj(dynamic_cast<Object_pointer *>(
						Object_pointer::GetObject(valueLeft)->Clone()));
	if (!pObj->GetPointer()->Advance(env, -valueRight.GetInt())) return Value::Nil;
	return Value(pObj.release());
}

Gura_ImplementBinaryOperator(Sub, pointer, pointer)
{
#if 0
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
#endif
	const Pointer *pPtr1 = Object_pointer::GetObject(valueLeft)->GetPointer();
	const Pointer *pPtr2 = Object_pointer::GetObject(valueRight)->GetPointer();
	if (pPtr1->GetTarget() != pPtr2->GetTarget()) {
		env.SetError(ERR_ValueError,
			"cannot calculate difference between pointers of different binaries");
		return Value::Nil;
	}
	int offset1 = static_cast<int>(pPtr1->GetOffset());
	int offset2 = static_cast<int>(pPtr2->GetOffset());
	return Value(static_cast<Number>(offset1 - offset2));
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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Sub_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndArrayT() {
		*pResult = *pLeft - *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Sub_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = *pLeft - static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Sub_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemR>(numLeft) - *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTOperators(Sub)

//-----------------------------------------------------------------------------
// [A * B] ... BinaryOperator(Mul, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mul, number, number)
{
	return Value(valueLeft.GetNumber() * valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Mul, boolean, boolean)
{
	return Value(valueLeft.GetNumber() * valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Mul, number, boolean)
{
	return Value(valueLeft.GetNumber() * valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Mul, boolean, number)
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

#if 0
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

Gura_ImplementBinaryOperator(Mul, matrix, list)
{
	return Matrix::Mul(env,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight.GetList());
}
#endif

Gura_ImplementBinaryOperator(Mul, any, matrix)
{
	return Matrix::Mul(env,
			valueLeft, Object_matrix::GetObject(valueRight)->GetMatrix());
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

Gura_ImplementBinaryOperator(Mul, vertex, number)
{
	const Vertex &vertex = Object_vertex::GetObject(valueLeft)->GetVertex();
	double num = valueRight.GetDouble();
	return Value(new Object_vertex(env, Vertex(
									   vertex.x * num,
									   vertex.y * num,
									   vertex.z * num)));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Mul_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndArrayT() {
		*pResult = *pLeft * *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Mul_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = *pLeft * static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Mul_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemR>(numLeft) * *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTOperators(Mul)

//-----------------------------------------------------------------------------
// [A / B] ... BinaryOperator(Div, A, B)
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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Div_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	LoopOn_ArrayTAndArrayT() {
		if (*pRight == 0) {
			Operator::SetError_DivideByZero(sig);
			return Value::Nil;
		}
		*pResult = *pLeft / *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Div_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	ArrayT<T_ElemL> *pArrayTLeft = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT();
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	size_t cnt = pArrayTLeft->GetCountTotal();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(new ArrayT<T_ElemResult>(cnt));
	T_ElemL *pLeft = pArrayTLeft->GetPointer();
	T_ElemResult *pResult = pArrayTResult->GetPointer();
	for (size_t i = 0; i < cnt; i++, pLeft++, pResult++) {
		*pResult = *pLeft / static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Div_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	LoopOn_NumberAndArrayT() {
		if (*pRight == 0) {
			Operator::SetError_DivideByZero(sig);
			return Value::Nil;
		}
		*pResult = static_cast<T_ElemR>(numLeft) / *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTOperators(Div)

//-----------------------------------------------------------------------------
// [A % B] ... BinaryOperator(Mod, A, B)
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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Mod_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	LoopOn_ArrayTAndArrayT() {
		if (*pRight == 0) {
			Operator::SetError_DivideByZero(sig);
			return Value::Nil;
		}
		*pResult = static_cast<T_ElemResult>(::fmod(static_cast<double>(*pLeft), static_cast<double>(*pRight)));
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Mod_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	ArrayT<T_ElemL> *pArrayTLeft = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT();
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Nil;
	}
	size_t cnt = pArrayTLeft->GetCountTotal();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(new ArrayT<T_ElemResult>(cnt));
	T_ElemL *pLeft = pArrayTLeft->GetPointer();
	T_ElemResult *pResult = pArrayTResult->GetPointer();
	for (size_t i = 0; i < cnt; i++, pLeft++, pResult++) {
		*pResult = static_cast<T_ElemResult>(::fmod(static_cast<double>(*pLeft), static_cast<double>(numRight)));
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Mod_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	LoopOn_NumberAndArrayT() {
		if (*pRight == 0) {
			Operator::SetError_DivideByZero(sig);
			return Value::Nil;
		}
		*pResult = static_cast<T_ElemResult>(::fmod(static_cast<double>(numLeft), static_cast<double>(*pRight)));
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTOperators(Mod)

//-----------------------------------------------------------------------------
// [A %% B] ... BinaryOperator(ModMod, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A ** B] ... BinaryOperator(Pow, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pow, number, number)
{
	return Value(::pow(valueLeft.GetNumber(), valueRight.GetNumber()));
}

Gura_ImplementBinaryOperator(Pow, complex, complex)
{
#if defined(_MSC_VER) && _MSC_VER < 1900
	return Value(std::pow(valueLeft.GetComplex(), valueRight.GetComplex()));
#else
	return Value(std::pow<double, double>(valueLeft.GetComplex(), valueRight.GetComplex()));
#endif
}

Gura_ImplementBinaryOperator(Pow, number, complex)
{
	return Value(std::pow(valueLeft.GetNumber(), valueRight.GetComplex()));
}

Gura_ImplementBinaryOperator(Pow, complex, number)
{
	return Value(std::pow(valueLeft.GetComplex(), valueRight.GetNumber()));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Pow_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndArrayT() {
		*pResult = static_cast<T_ElemResult>(std::pow(static_cast<double>(*pLeft), static_cast<double>(*pRight)));
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Pow_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = static_cast<T_ElemResult>(std::pow(static_cast<double>(*pLeft), static_cast<double>(numRight)));
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Pow_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemResult>(std::pow(static_cast<double>(numLeft), static_cast<double>(*pRight)));
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTOperators(Pow)

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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value And_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndArrayT() {
		*pResult = *pLeft & *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value And_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = *pLeft & static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value And_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemR>(numLeft) & *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTBitOperators(And)

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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Or_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndArrayT() {
		*pResult = *pLeft | *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Or_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = *pLeft | static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Or_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemR>(numLeft) | *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTBitOperators(Or)

//-----------------------------------------------------------------------------
// [A ^ B] ... BinaryOperator(Xor, A, B)
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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Xor_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndArrayT() {
		*pResult = *pLeft ^ *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Xor_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = *pLeft ^ static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Xor_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemR>(numLeft) ^ *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTBitOperators(Xor)

//-----------------------------------------------------------------------------
// [A << B] ... BinaryOperator(Shl, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shl, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) <<
							static_cast<ULong>(valueRight.GetNumber()));
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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Shl_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndArrayT() {
		*pResult = *pLeft << *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Shl_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = *pLeft << static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Shl_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemR>(numLeft) << *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTBitOperators(Shl)

//-----------------------------------------------------------------------------
// [A >> B] ... BinaryOperator(Shr, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shr, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) >>
							static_cast<ULong>(valueRight.GetNumber()));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value Shr_ArrayTAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndArrayT() {
		*pResult = *pLeft >> *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemL>
Value Shr_ArrayTAndNumber(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_ArrayTAndNumber() {
		*pResult = *pLeft >> static_cast<T_ElemL>(numRight);
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

template<typename T_ElemResult, typename T_ElemR>
Value Shr_NumberAndArrayT(Environment &env,
			   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	LoopOn_NumberAndArrayT() {
		*pResult = static_cast<T_ElemR>(numLeft) >> *pRight;
	}
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayTResult.release()));
}

ImplementArrayTBitOperators(Shr)

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
	Number numBegin = valueLeft.GetNumber();
	Number numEnd = valueRight.GetNumber();
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
// OperatorEntryCustom
//-----------------------------------------------------------------------------
Value OperatorEntryCustom::DoEval(Environment &env, const Value &value) const
{
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->StoreValue(env, value)) return Value::Nil;
	return _pFunc->Eval(env, *pArg);
}

Value OperatorEntryCustom::DoEval(Environment &env,
					const Value &valueLeft, const Value &valueRight) const
{
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->StoreValue(env, valueLeft, valueRight)) return Value::Nil;
	return _pFunc->Eval(env, *pArg);
}

//-----------------------------------------------------------------------------
// OperatorEntryDerived
//-----------------------------------------------------------------------------
Value OperatorEntryDerived::DoEval(Environment &env, const Value &value) const
{
	return _pOperatorEntryOrg->DoEval(env, value);
}

Value OperatorEntryDerived::DoEval(Environment &env,
					const Value &valueLeft, const Value &valueRight) const
{
	return _pOperatorEntryOrg->DoEval(env, valueLeft, valueRight);
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
	Gura_AssignUnaryOperator(Pos, array_at_char);
	Gura_AssignUnaryOperator(Pos, array_at_uchar);
	Gura_AssignUnaryOperator(Pos, array_at_short);
	Gura_AssignUnaryOperator(Pos, array_at_ushort);
	Gura_AssignUnaryOperator(Pos, array_at_int);
	Gura_AssignUnaryOperator(Pos, array_at_uint);
	Gura_AssignUnaryOperator(Pos, array_at_int32);
	Gura_AssignUnaryOperator(Pos, array_at_uint32);
	Gura_AssignUnaryOperator(Pos, array_at_int64);
	Gura_AssignUnaryOperator(Pos, array_at_uint64);
	Gura_AssignUnaryOperator(Pos, array_at_float);
	Gura_AssignUnaryOperator(Pos, array_at_double);
	Gura_AssignUnaryOperator(Neg, number);
	Gura_AssignUnaryOperator(Neg, complex);
	Gura_AssignUnaryOperator(Neg, rational);
	Gura_AssignUnaryOperator(Neg, matrix);
	Gura_AssignUnaryOperator(Neg, timedelta);
	Gura_AssignUnaryOperator(Neg, vertex);
	Gura_AssignUnaryOperator(Neg, array_at_char);
	Gura_AssignUnaryOperator(Neg, array_at_uchar);
	Gura_AssignUnaryOperator(Neg, array_at_short);
	Gura_AssignUnaryOperator(Neg, array_at_ushort);
	Gura_AssignUnaryOperator(Neg, array_at_int);
	Gura_AssignUnaryOperator(Neg, array_at_uint);
	Gura_AssignUnaryOperator(Neg, array_at_int32);
	Gura_AssignUnaryOperator(Neg, array_at_uint32);
	Gura_AssignUnaryOperator(Neg, array_at_int64);
	Gura_AssignUnaryOperator(Neg, array_at_uint64);
	Gura_AssignUnaryOperator(Neg, array_at_float);
	Gura_AssignUnaryOperator(Neg, array_at_double);
	Gura_AssignUnaryOperator(Inv, number);
	Gura_AssignUnaryOperator(Not, any);
	Gura_AssignUnaryOperatorSuffix(SeqInf, number);
	Gura_AssignUnaryOperatorSuffix(Question, any);
	Gura_AssignUnaryOperatorSuffix(Each, any);
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
	Gura_AssignBinaryOperator(Add, vertex, vertex);
	AssignArrayTOperators(Add);
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
	Gura_AssignBinaryOperator(Sub, matrix, matrix);
	Gura_AssignBinaryOperator(Sub, datetime, timedelta);
	Gura_AssignBinaryOperator(Sub, datetime, datetime);
	Gura_AssignBinaryOperator(Sub, timedelta, timedelta);
	Gura_AssignBinaryOperator(Sub, color, color);
	Gura_AssignBinaryOperator(Sub, pointer, number);
	Gura_AssignBinaryOperator(Sub, pointer, pointer);
	Gura_AssignBinaryOperator(Sub, vertex, vertex);
	AssignArrayTOperators(Sub);
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
#if 0
	Gura_AssignBinaryOperator(Mul, matrix, matrix);
	Gura_AssignBinaryOperator(Mul, list, matrix);
	Gura_AssignBinaryOperator(Mul, matrix, list);
#endif
	Gura_AssignBinaryOperator(Mul, any, matrix);
	Gura_AssignBinaryOperator(Mul, matrix, any);
	Gura_AssignBinaryOperator(Mul, timedelta, number);
	Gura_AssignBinaryOperator(Mul, number, timedelta);
	Gura_AssignBinaryOperator(Mul, function, any);
	Gura_AssignBinaryOperator(Mul, Class, any);
	Gura_AssignBinaryOperator(Mul, string, number);
	Gura_AssignBinaryOperator(Mul, number, string);
	Gura_AssignBinaryOperator(Mul, binary, number);
	Gura_AssignBinaryOperator(Mul, number, binary);
	Gura_AssignBinaryOperator(Mul, vertex, number);
	AssignArrayTOperators(Mul);
	Gura_AssignBinaryOperator(Div, number, number);
	Gura_AssignBinaryOperator(Div, number, complex);
	Gura_AssignBinaryOperator(Div, number, rational);
	Gura_AssignBinaryOperator(Div, complex, number);
	Gura_AssignBinaryOperator(Div, complex, complex);
	Gura_AssignBinaryOperator(Div, rational, number);
	Gura_AssignBinaryOperator(Div, rational, rational);
	Gura_AssignBinaryOperator(Div, matrix, any);
	Gura_AssignBinaryOperator(Div, vertex, number);
	AssignArrayTOperators(Div);
	Gura_AssignBinaryOperator(Mod, number, number);
	AssignArrayTOperators(Mod);
	Gura_AssignBinaryOperator(Pow, number, number);
	Gura_AssignBinaryOperator(Pow, complex, complex);
	Gura_AssignBinaryOperator(Pow, number, complex);
	Gura_AssignBinaryOperator(Pow, complex, number);
	AssignArrayTOperators(Pow);
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
	AssignArrayTBitOperators(And);
	Gura_AssignBinaryOperator(Or, number, number);
	Gura_AssignBinaryOperator(Or, boolean, boolean);
	Gura_AssignBinaryOperator(Or, nil, any);
	Gura_AssignBinaryOperator(Or, any, nil);
	AssignArrayTBitOperators(Or);
	Gura_AssignBinaryOperator(Xor, number, number);
	Gura_AssignBinaryOperator(Xor, boolean, boolean);
	AssignArrayTBitOperators(Xor);
	Gura_AssignBinaryOperator(Shl, number, number);
	Gura_AssignBinaryOperator(Shl, stream, any);
	AssignArrayTBitOperators(Shl);
	Gura_AssignBinaryOperator(Shr, number, number);
	AssignArrayTBitOperators(Shr);
	Gura_AssignBinaryOperator(OrOr, any, any);
	Gura_AssignBinaryOperator(AndAnd, any, any);
	Gura_AssignBinaryOperator(Seq, number, number);
	Gura_AssignBinaryOperator(Pair, symbol, any);
	Gura_AssignBinaryOperator(Pair, string, any);
	Gura_AssignBinaryOperator(Pair, number, any);
}

}
