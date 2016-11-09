//=============================================================================
// Operator_array
//=============================================================================
#include "stdafx.h"
#include "gura/Class_arrayT.h"
#include <math.h>

//-----------------------------------------------------------------------------
// Macros to implement/assign binary operators for array
//-----------------------------------------------------------------------------
#define Gura_ImplementUnaryOperators_Array(op, sigAttr) \
Gura_ImplementUnaryOperator(op, array_at_char) \
{ \
	return Op_Array_##sigAttr<Char, Char, op>(env, value, VTYPE_array_at_char); \
} \
Gura_ImplementUnaryOperator(op, array_at_uchar) \
{ \
	return Op_Array_##sigAttr<UChar, UChar, op>(env, value, VTYPE_array_at_uchar); \
} \
Gura_ImplementUnaryOperator(op, array_at_short) \
{ \
	return Op_Array_##sigAttr<Short, Short, op>(env, value, VTYPE_array_at_short); \
} \
Gura_ImplementUnaryOperator(op, array_at_ushort) \
{ \
	return Op_Array_##sigAttr<UShort, UShort, op>(env, value, VTYPE_array_at_ushort); \
} \
Gura_ImplementUnaryOperator(op, array_at_int) \
{ \
	return Op_Array_##sigAttr<Int, Int, op>(env, value, VTYPE_array_at_int); \
} \
Gura_ImplementUnaryOperator(op, array_at_uint) \
{ \
	return Op_Array_##sigAttr<UInt, UInt, op>(env, value, VTYPE_array_at_uint); \
} \
Gura_ImplementUnaryOperator(op, array_at_int32) \
{ \
	return Op_Array_##sigAttr<Int32, Int32, op>(env, value, VTYPE_array_at_int32); \
} \
Gura_ImplementUnaryOperator(op, array_at_uint32) \
{ \
	return Op_Array_##sigAttr<UInt32, UInt32, op>(env, value, VTYPE_array_at_uint32); \
} \
Gura_ImplementUnaryOperator(op, array_at_int64) \
{ \
	return Op_Array_##sigAttr<Int64, Int64, op>(env, value, VTYPE_array_at_int64); \
} \
Gura_ImplementUnaryOperator(op, array_at_uint64) \
{ \
	return Op_Array_##sigAttr<UInt64, UInt64, op>(env, value, VTYPE_array_at_uint64); \
} \
Gura_ImplementUnaryOperator(op, array_at_float) \
{ \
	return Op_Array_##sigAttr<float, float, op>(env, value, VTYPE_array_at_float); \
} \
Gura_ImplementUnaryOperator(op, array_at_double) \
{ \
	return Op_Array_##sigAttr<double, double, op>(env, value, VTYPE_array_at_double); \
}

#define Gura_ImplementBinaryOperators_Array(op, sigAttr) \
Gura_ImplementBinaryOperator(op, array_at_char, array_at_char) \
{ \
	return Op_ArrayAndArray_##sigAttr<Char, Char, Char, op>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, array_at_uchar, array_at_uchar) \
{ \
	return Op_ArrayAndArray_##sigAttr<UChar, UChar, UChar, op>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_at_short, array_at_short) \
{ \
	return Op_ArrayAndArray_##sigAttr<Short, Short, Short, op>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, array_at_ushort, array_at_ushort) \
{ \
	return Op_ArrayAndArray_##sigAttr<UShort, UShort, UShort, op>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_at_int, array_at_int) \
{ \
	return Op_ArrayAndArray_##sigAttr<Int, Int, Int, op>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint, array_at_uint) \
{ \
	return Op_ArrayAndArray_##sigAttr<UInt, UInt, UInt, op>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, array_at_int32, array_at_int32) \
{ \
	return Op_ArrayAndArray_##sigAttr<Int32, Int32, Int32, op>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint32, array_at_uint32) \
{ \
	return Op_ArrayAndArray_##sigAttr<UInt32, UInt32, UInt32, op>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, array_at_int64, array_at_int64) \
{ \
	return Op_ArrayAndArray_##sigAttr<Int64, Int64, Int64, op>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint64, array_at_uint64) \
{ \
	return Op_ArrayAndArray_##sigAttr<UInt64, UInt64, UInt64, op>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \
Gura_ImplementBinaryOperator(op, array_at_float, array_at_float) \
{ \
	return Op_ArrayAndArray_##sigAttr<float, float, float, op>(env, valueLeft, valueRight, VTYPE_array_at_float); \
} \
Gura_ImplementBinaryOperator(op, array_at_double, array_at_double) \
{ \
	return Op_ArrayAndArray_##sigAttr<double, double, double, op>(env, valueLeft, valueRight, VTYPE_array_at_double); \
} \
Gura_ImplementBinaryOperator(op, array_at_char, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<Char, Char, Char, op>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, array_at_uchar, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<UChar, UChar, UChar, op>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, array_at_short, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<Short, Short, Short, op>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, array_at_ushort, number)	\
{ \
	return Op_ArrayAndNumber_##sigAttr<UShort, UShort, UShort, op>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, array_at_int, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<Int, Int, Int, op>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<UInt, UInt, UInt, op>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, array_at_int32, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<Int32, Int32, Int32, op>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint32, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<UInt32, UInt32, UInt32, op>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, array_at_int64, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<Int64, Int64, Int64, op>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, array_at_uint64, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<UInt64, UInt64, UInt64, op>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \
Gura_ImplementBinaryOperator(op, array_at_float, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<float, float, float, op>(env, valueLeft, valueRight, VTYPE_array_at_float); \
} \
Gura_ImplementBinaryOperator(op, array_at_double, number) \
{ \
	return Op_ArrayAndNumber_##sigAttr<double, double, double, op>(env, valueLeft, valueRight, VTYPE_array_at_double); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_char) \
{ \
	return Op_NumberAndArray_##sigAttr<Char, Char, Char, op>(env, valueLeft, valueRight, VTYPE_array_at_char); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uchar)	\
{ \
	return Op_NumberAndArray_##sigAttr<UChar, UChar, UChar, op>(env, valueLeft, valueRight, VTYPE_array_at_uchar); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_short)	\
{ \
	return Op_NumberAndArray_##sigAttr<Short, Short, Short, op>(env, valueLeft, valueRight, VTYPE_array_at_short); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_ushort)	\
{ \
	return Op_NumberAndArray_##sigAttr<UShort, UShort, UShort, op>(env, valueLeft, valueRight, VTYPE_array_at_ushort); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int) \
{ \
	return Op_NumberAndArray_##sigAttr<Int, Int, Int, op>(env, valueLeft, valueRight, VTYPE_array_at_int); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint)	\
{ \
	return Op_NumberAndArray_##sigAttr<UInt, UInt, UInt, op>(env, valueLeft, valueRight, VTYPE_array_at_uint); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int32) \
{ \
	return Op_NumberAndArray_##sigAttr<Int32, Int32, Int32, op>(env, valueLeft, valueRight, VTYPE_array_at_int32); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint32)	\
{ \
	return Op_NumberAndArray_##sigAttr<UInt32, UInt32, UInt32, op>(env, valueLeft, valueRight, VTYPE_array_at_uint32); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_int64)	\
{ \
	return Op_NumberAndArray_##sigAttr<Int64, Int64, Int64, op>(env, valueLeft, valueRight, VTYPE_array_at_int64); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_uint64) \
{ \
	return Op_NumberAndArray_##sigAttr<UInt64, UInt64, UInt64, op>(env, valueLeft, valueRight, VTYPE_array_at_uint64); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_float)	\
{ \
	return Op_NumberAndArray_##sigAttr<float, float, float, op>(env, valueLeft, valueRight, VTYPE_array_at_float); \
} \
Gura_ImplementBinaryOperator(op, number, array_at_double)	\
{ \
	return Op_NumberAndArray_##sigAttr<double, double, double, op>(env, valueLeft, valueRight, VTYPE_array_at_double); \
}

#define Gura_AssignBinaryOperators_Array(op) \
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

#define Gura_AssignUnaryOperators_Array(op) \
Gura_AssignUnaryOperator(op, array_at_char); \
Gura_AssignUnaryOperator(op, array_at_uchar); \
Gura_AssignUnaryOperator(op, array_at_short); \
Gura_AssignUnaryOperator(op, array_at_ushort); \
Gura_AssignUnaryOperator(op, array_at_int); \
Gura_AssignUnaryOperator(op, array_at_uint); \
Gura_AssignUnaryOperator(op, array_at_int32); \
Gura_AssignUnaryOperator(op, array_at_uint32); \
Gura_AssignUnaryOperator(op, array_at_int64); \
Gura_AssignUnaryOperator(op, array_at_uint64); \
Gura_AssignUnaryOperator(op, array_at_float); \
Gura_AssignUnaryOperator(op, array_at_double);

namespace Gura {

template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, T_Elem)>
Value Op_Array_NoSig(Environment &env, const Value &value, ValueType valTypeResult)
{
	ArrayT<T_Elem> *pArray = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT();
	size_t cnt = pArray->GetCountTotal();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(cnt));
	if (!Op_Array_NoSig<T_ElemResult, T_Elem, op>(
			env.GetSignal(), *pArrayResult, *pArray)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
	void (*op)(T_ElemResult &, T_ElemL, T_ElemR)>
Value Op_ArrayAndArray_NoSig(Environment &env,
					   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	ArrayT<T_ElemL> *pArrayL = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT();
	ArrayT<T_ElemR> *pArrayR = Object_arrayT<T_ElemR>::GetObject(valueRight)->GetArrayT();
	if (!Array::CheckElemwiseCalculatable(sig, *pArrayL, *pArrayR)) return false;
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult;
	if (pArrayL->GetDimensions().size() >= pArrayR->GetDimensions().size()) {
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(pArrayL->GetDimensions()));
	} else {
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(pArrayR->GetDimensions()));
	}
	if (!Op_ArrayAndArray_NoSig<T_ElemResult, T_ElemL, T_ElemR, op>(
			sig, *pArrayResult, *pArrayL, *pArrayR)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
	void (*op)(T_ElemResult &, T_ElemL, T_ElemR)>
Value Op_ArrayAndNumber_NoSig(Environment &env,
						const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	ArrayT<T_ElemL> *pArrayL = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT();
	Number numR = valueRight.GetNumber();
	size_t cnt = pArrayL->GetCountTotal();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(cnt));
	if (!Op_ArrayAndNumber_NoSig<T_ElemResult, T_ElemL, T_ElemR, op>(
			env.GetSignal(), *pArrayResult, *pArrayL, numR)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
	void (*op)(T_ElemResult &, T_ElemL, T_ElemR)>
Value Op_NumberAndArray_NoSig(Environment &env,
						const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Number numL = valueLeft.GetNumber();
	ArrayT<T_ElemR> *pArrayR = Object_arrayT<T_ElemR>::GetObject(valueRight)->GetArrayT();
	size_t cnt = pArrayR->GetCountTotal();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(cnt));
	if (!Op_NumberAndArray_NoSig<T_ElemResult, T_ElemL, T_ElemR, op>(
			env.GetSignal(), *pArrayResult, numL, *pArrayR)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, T_Elem)>
Value Op_Array_Sig(Environment &env, const Value &value, ValueType valTypeResult)
{
	ArrayT<T_Elem> *pArray = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT();
	size_t cnt = pArray->GetCountTotal();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(cnt));
	if (!Op_Array_Sig<T_ElemResult, T_Elem, op>(
			env.GetSignal(), *pArrayResult, *pArray)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
	bool (*op)(Signal &sig, T_ElemResult &, T_ElemL, T_ElemR)>
Value Op_ArrayAndArray_Sig(Environment &env,
					   const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Signal &sig = env.GetSignal();
	ArrayT<T_ElemL> *pArrayL = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT();
	ArrayT<T_ElemR> *pArrayR = Object_arrayT<T_ElemR>::GetObject(valueRight)->GetArrayT();
	if (!Array::CheckElemwiseCalculatable(sig, *pArrayL, *pArrayR)) return false;
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult;
	if (pArrayL->GetDimensions().size() >= pArrayR->GetDimensions().size()) {
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(pArrayL->GetDimensions()));
	} else {
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(pArrayR->GetDimensions()));
	}
	if (!Op_ArrayAndArray_Sig<T_ElemResult, T_ElemL, T_ElemR, op>(
			sig, *pArrayResult, *pArrayL, *pArrayR)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
	bool (*op)(Signal &sig, T_ElemResult &, T_ElemL, T_ElemR)>
Value Op_ArrayAndNumber_Sig(Environment &env,
						const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	ArrayT<T_ElemL> *pArrayL = Object_arrayT<T_ElemL>::GetObject(valueLeft)->GetArrayT();
	Number numR = valueRight.GetNumber();
	size_t cnt = pArrayL->GetCountTotal();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(cnt));
	if (!Op_ArrayAndNumber_Sig<T_ElemResult, T_ElemL, T_ElemR, op>(
			env.GetSignal(), *pArrayResult, *pArrayL, numR)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
	bool (*op)(Signal &sig, T_ElemResult &, T_ElemL, T_ElemR)>
Value Op_NumberAndArray_Sig(Environment &env,
						const Value &valueLeft, const Value &valueRight, ValueType valTypeResult)
{
	Number numL = valueLeft.GetNumber();
	ArrayT<T_ElemR> *pArrayR = Object_arrayT<T_ElemR>::GetObject(valueRight)->GetArrayT();
	size_t cnt = pArrayR->GetCountTotal();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(cnt));
	if (!Op_NumberAndArray_Sig<T_ElemResult, T_ElemL, T_ElemR, op>(
			env.GetSignal(), *pArrayResult, numL, *pArrayR)) return false;
	return Value(new Object_arrayT<T_ElemResult>(env, valTypeResult, pArrayResult.release()));
}

Gura_ImplementUnaryOperators_Array(Pos, NoSig)
Gura_ImplementUnaryOperators_Array(Neg, NoSig)
Gura_ImplementBinaryOperators_Array(Add, NoSig)
Gura_ImplementBinaryOperators_Array(Sub, NoSig)
Gura_ImplementBinaryOperators_Array(Mul, NoSig)
Gura_ImplementBinaryOperators_Array(Div, Sig)
Gura_ImplementBinaryOperators_Array(Mod, Sig)
Gura_ImplementBinaryOperators_Array(Pow, NoSig)
Gura_ImplementBinaryOperators_Array(And, NoSig)
Gura_ImplementBinaryOperators_Array(Or, NoSig)
Gura_ImplementBinaryOperators_Array(Xor, NoSig)
Gura_ImplementBinaryOperators_Array(Shl, NoSig)
Gura_ImplementBinaryOperators_Array(Shr, NoSig)

void Operator::AssignOperator_array(Environment &env)
{
	Gura_AssignUnaryOperators_Array(Pos);
	Gura_AssignUnaryOperators_Array(Neg);
	Gura_AssignBinaryOperators_Array(Add);
	Gura_AssignBinaryOperators_Array(Sub);
	Gura_AssignBinaryOperators_Array(Mul);
	Gura_AssignBinaryOperators_Array(Div);
	Gura_AssignBinaryOperators_Array(Mod);
	Gura_AssignBinaryOperators_Array(Pow);
	Gura_AssignBinaryOperators_Array(And);
	Gura_AssignBinaryOperators_Array(Or);
	Gura_AssignBinaryOperators_Array(Xor);
	Gura_AssignBinaryOperators_Array(Shl);
	Gura_AssignBinaryOperators_Array(Shr);
}

}
