//=============================================================================
// OperatorArray
//=============================================================================
#include "stdafx.h"
#include <math.h>

namespace Gura {

//-----------------------------------------------------------------------------
// [+A] ... UnaryOperator(Pos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Pos, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Pos, value);
}

//-----------------------------------------------------------------------------
// [-A] ... UnaryOperator(Neg, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Neg, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Neg, value);
}

//-----------------------------------------------------------------------------
// [~A] ... UnaryOperator(Invert, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [!A] ... UnaryOperator(Not, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A..] ... UnaryOperator(SeqInf, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A?] ... UnaryOperator(Question, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A*] ... UnaryOperator(Each, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A+] ... UnaryOperator(PostPos, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A%] ... UnaryOperator(PostMod, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A + B] ... BinaryOperator(Add, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Add, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Add, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Add, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Add, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Add, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Add, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Add, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Add, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Add, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Add, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A - B] ... BinaryOperator(Sub, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Sub, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Sub, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Sub, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Sub, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Sub, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Sub, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Sub, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Sub, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Sub, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Sub, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A * B] ... BinaryOperator(Mul, A, B)
//-----------------------------------------------------------------------------
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
// [A |.| B] ... BinaryOperator(Dot, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Dot, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Dot, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Dot, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, Array::binaryFuncPack_Dot, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Dot, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, Array::binaryFuncPack_Dot, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Dot, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, Array::binaryFuncPack_Dot, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Dot, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, Array::binaryFuncPack_Dot, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A |^| B] ... BinaryOperator(Cross, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A |*| B] ... BinaryOperator(Filter, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Filter, array, filter_at_conv1d)
{
	Array *pArray = Object_filter_at_conv1d::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_conv2d)
{
	Array *pArray = Object_filter_at_conv2d::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_conv3d)
{
	Array *pArray = Object_filter_at_conv3d::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_maxpool1d)
{
	Array *pArray = Object_filter_at_maxpool1d::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_maxpool2d)
{
	Array *pArray = Object_filter_at_maxpool2d::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_maxpool3d)
{
	Array *pArray = Object_filter_at_maxpool3d::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_relu)
{
	Array *pArray = Object_filter_at_relu::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_sigmoid)
{
	Array *pArray = Object_filter_at_sigmoid::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_softmax)
{
	Array *pArray = Object_filter_at_softmax::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
}

Gura_ImplementBinaryOperator(Filter, array, filter_at_tanh)
{
	Array *pArray = Object_filter_at_tanh::GetObject(valueRight)->GetFilter().Apply(
		env, nullptr,
		Object_array::GetObject(valueLeft)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Array::ToValue(env, pArray);
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

//-----------------------------------------------------------------------------
// [A in B] ... BinaryOperator(Contains, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A & B] ... BinaryOperator(And, A, B)
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// [A && B] ... BinaryOperator(AndAnd, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A .. B] ... BinaryOperator(Seq, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A => B] ... BinaryOperator(Pair, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.abs(A) ... UnaryOperator(Math_abs, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_abs, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_abs, value);
}

//-----------------------------------------------------------------------------
// math.acos(A) ... UnaryOperator(Math_acos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_acos, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_acos, value);
}

//-----------------------------------------------------------------------------
// math.arg(A) ... UnaryOperator(Math_arg, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_arg, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_arg, value);
}

//-----------------------------------------------------------------------------
// math.asin(A) ... UnaryOperator(Math_asin, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_asin, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_asin, value);
}

//-----------------------------------------------------------------------------
// math.atan(A) ... UnaryOperator(Math_atan, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_atan, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_atan, value);
}

//-----------------------------------------------------------------------------
// math.atan2(A, B) ... UnaryOperator(Math_atan2, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.ceil(A) ... UnaryOperator(Math_ceil, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_ceil, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_ceil, value);
}

//-----------------------------------------------------------------------------
// math.conj(A) ... UnaryOperator(Math_conj, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_conj, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_conj, value);
}

//-----------------------------------------------------------------------------
// math.cos(A) ... UnaryOperator(Math_cos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_cos, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_cos, value);
}

//-----------------------------------------------------------------------------
// math.cosh(A) ... UnaryOperator(Math_cosh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_cosh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_cosh, value);
}

//-----------------------------------------------------------------------------
// math.covariance(A, B) ... BinaryOperator(Math_covariance, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.cross(A, B) ... BinaryOperator(Math_cross, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.delta(A) ... UnaryOperator(Math_delta, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_delta, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_delta, value);
}

//-----------------------------------------------------------------------------
// math.dot(A, B) ... BinaryOperator(Math_dot, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.exp(A) ... UnaryOperator(Math_exp, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_exp, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_exp, value);
}

//-----------------------------------------------------------------------------
// math.floor(A) ... UnaryOperator(Math_floor, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_floor, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_floor, value);
}

//-----------------------------------------------------------------------------
// math.hypot(A, B) ... BinaryOperator(Math_hypot, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.imag(A) ... UnaryOperator(Math_imag, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_imag, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_imag, value);
}

//-----------------------------------------------------------------------------
// math.log(A) ... UnaryOperator(Math_log, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_log, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_log, value);
}

//-----------------------------------------------------------------------------
// math.log10(A) ... UnaryOperator(Math_log10, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_log10, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_log10, value);
}

//-----------------------------------------------------------------------------
// math.norm(A) ... UnaryOperator(Math_norm, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_norm, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_norm, value);
}

//-----------------------------------------------------------------------------
// math.real(A) ... UnaryOperator(Math_real, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_real, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_real, value);
}

//-----------------------------------------------------------------------------
// math.relu(A) ... UnaryOperator(Math_relu, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_relu, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_relu, value);
}

//-----------------------------------------------------------------------------
// math.sigmoid(A) ... UnaryOperator(Math_sigmoid, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sigmoid, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_sigmoid, value);
}

//-----------------------------------------------------------------------------
// math.sin(A) ... UnaryOperator(Math_sin, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sin, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_sin, value);
}

//-----------------------------------------------------------------------------
// math.sinh(A) ... UnaryOperator(Math_sinh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sinh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_sinh, value);
}

//-----------------------------------------------------------------------------
// math.sqrt(A) ... UnaryOperator(Math_sqrt, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sqrt, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_sqrt, value);
}

//-----------------------------------------------------------------------------
// math.tan(A) ... UnaryOperator(Math_tan, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_tan, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_tan, value);
}

//-----------------------------------------------------------------------------
// math.tanh(A) ... UnaryOperator(Math_tanh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_tanh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_tanh, value);
}

//-----------------------------------------------------------------------------
// math.unitstep(A) ... UnaryOperator(Math_unitstep, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_unitstep, array)
{
	return Array::ApplyUnaryFuncOnValue(env, Array::unaryFuncPack_Math_unitstep, value);
}

//-----------------------------------------------------------------------------
// Operator assignment
//-----------------------------------------------------------------------------
void Operator::AssignOperatorArray(Environment &env)
{
	// unary operators
	Gura_AssignUnaryOperator(Pos, array);
	Gura_AssignUnaryOperator(Neg, array);
	// binary operators
	Gura_AssignBinaryOperator(Add, array, array);
	Gura_AssignBinaryOperator(Add, array, number);
	Gura_AssignBinaryOperator(Add, number, array);
	Gura_AssignBinaryOperator(Add, array, complex);
	Gura_AssignBinaryOperator(Add, complex, array);
	Gura_AssignBinaryOperator(Sub, array, array);
	Gura_AssignBinaryOperator(Sub, array, number);
	Gura_AssignBinaryOperator(Sub, number, array);
	Gura_AssignBinaryOperator(Sub, array, complex);
	Gura_AssignBinaryOperator(Sub, complex, array);
	Gura_AssignBinaryOperator(Mul, array, array);
	Gura_AssignBinaryOperator(Mul, array, number);
	Gura_AssignBinaryOperator(Mul, number, array);
	Gura_AssignBinaryOperator(Mul, array, complex);
	Gura_AssignBinaryOperator(Mul, complex, array);
	Gura_AssignBinaryOperator(Div, array, array);
	Gura_AssignBinaryOperator(Div, array, number);
	Gura_AssignBinaryOperator(Div, number, array);
	Gura_AssignBinaryOperator(Div, array, complex);
	Gura_AssignBinaryOperator(Div, complex, array);
	Gura_AssignBinaryOperator(Mod, array, array);
	Gura_AssignBinaryOperator(Mod, array, number);
	Gura_AssignBinaryOperator(Mod, number, array);
	Gura_AssignBinaryOperator(Dot, array, array);
	Gura_AssignBinaryOperator(Dot, array, number);
	Gura_AssignBinaryOperator(Dot, number, array);
	Gura_AssignBinaryOperator(Dot, array, complex);
	Gura_AssignBinaryOperator(Dot, complex, array);
	Gura_AssignBinaryOperator(Filter, array, filter_at_conv1d);
	Gura_AssignBinaryOperator(Filter, array, filter_at_conv2d);
	Gura_AssignBinaryOperator(Filter, array, filter_at_conv3d);
	Gura_AssignBinaryOperator(Filter, array, filter_at_maxpool1d);
	Gura_AssignBinaryOperator(Filter, array, filter_at_maxpool2d);
	Gura_AssignBinaryOperator(Filter, array, filter_at_maxpool3d);
	Gura_AssignBinaryOperator(Filter, array, filter_at_relu);
	Gura_AssignBinaryOperator(Filter, array, filter_at_sigmoid);
	Gura_AssignBinaryOperator(Filter, array, filter_at_softmax);
	Gura_AssignBinaryOperator(Filter, array, filter_at_tanh);
	Gura_AssignBinaryOperator(Pow, array, array);
	Gura_AssignBinaryOperator(Pow, array, number);
	Gura_AssignBinaryOperator(Pow, number, array);
	Gura_AssignBinaryOperator(Pow, array, complex);
	Gura_AssignBinaryOperator(Pow, complex, array);
	Gura_AssignBinaryOperator(Eq, array, array);
	Gura_AssignBinaryOperator(Eq, array, number);
	Gura_AssignBinaryOperator(Eq, number, array);
	Gura_AssignBinaryOperator(Eq, array, complex);
	Gura_AssignBinaryOperator(Eq, complex, array);
	Gura_AssignBinaryOperator(Ne, array, array);
	Gura_AssignBinaryOperator(Ne, array, number);
	Gura_AssignBinaryOperator(Ne, number, array);
	Gura_AssignBinaryOperator(Ne, array, complex);
	Gura_AssignBinaryOperator(Ne, complex, array);
	Gura_AssignBinaryOperator(Gt, array, array);
	Gura_AssignBinaryOperator(Gt, array, number);
	Gura_AssignBinaryOperator(Gt, number, array);
	Gura_AssignBinaryOperator(Gt, array, complex);
	Gura_AssignBinaryOperator(Gt, complex, array);
	Gura_AssignBinaryOperator(Lt, array, array);
	Gura_AssignBinaryOperator(Lt, array, number);
	Gura_AssignBinaryOperator(Lt, number, array);
	Gura_AssignBinaryOperator(Lt, array, complex);
	Gura_AssignBinaryOperator(Lt, complex, array);
	Gura_AssignBinaryOperator(Ge, array, array);
	Gura_AssignBinaryOperator(Ge, array, number);
	Gura_AssignBinaryOperator(Ge, number, array);
	Gura_AssignBinaryOperator(Ge, array, complex);
	Gura_AssignBinaryOperator(Ge, complex, array);
	Gura_AssignBinaryOperator(Le, array, array);
	Gura_AssignBinaryOperator(Le, array, number);
	Gura_AssignBinaryOperator(Le, number, array);
	Gura_AssignBinaryOperator(Le, array, complex);
	Gura_AssignBinaryOperator(Le, complex, array);
	Gura_AssignBinaryOperator(And, array, array);
	Gura_AssignBinaryOperator(And, array, number);
	Gura_AssignBinaryOperator(And, number, array);
	Gura_AssignBinaryOperator(Or, array, array);
	Gura_AssignBinaryOperator(Or, array, number);
	Gura_AssignBinaryOperator(Or, number, array);
	Gura_AssignBinaryOperator(Xor, array, array);
	Gura_AssignBinaryOperator(Xor, array, number);
	Gura_AssignBinaryOperator(Xor, number, array);
	Gura_AssignBinaryOperator(Shl, array, array);
	Gura_AssignBinaryOperator(Shl, array, number);
	Gura_AssignBinaryOperator(Shl, number, array);
	Gura_AssignBinaryOperator(Shr, array, array);
	Gura_AssignBinaryOperator(Shr, array, number);
	Gura_AssignBinaryOperator(Shr, number, array);
	// mathematical functions
	Gura_AssignUnaryOperator(Math_abs, array);
	Gura_AssignUnaryOperator(Math_acos, array);
	Gura_AssignUnaryOperator(Math_arg, array);
	Gura_AssignUnaryOperator(Math_asin, array);
	Gura_AssignUnaryOperator(Math_atan, array);
	Gura_AssignUnaryOperator(Math_ceil, array);
	Gura_AssignUnaryOperator(Math_conj, array);
	Gura_AssignUnaryOperator(Math_cos, array);
	Gura_AssignUnaryOperator(Math_cosh, array);
	Gura_AssignUnaryOperator(Math_delta, array);
	Gura_AssignUnaryOperator(Math_exp, array);
	Gura_AssignUnaryOperator(Math_floor, array);
	Gura_AssignUnaryOperator(Math_imag, array);
	Gura_AssignUnaryOperator(Math_log, array);
	Gura_AssignUnaryOperator(Math_log10, array);
	Gura_AssignUnaryOperator(Math_norm, array);
	Gura_AssignUnaryOperator(Math_real, array);
	Gura_AssignUnaryOperator(Math_relu, array);
	Gura_AssignUnaryOperator(Math_sigmoid, array);
	Gura_AssignUnaryOperator(Math_sin, array);
	Gura_AssignUnaryOperator(Math_sinh, array);
	Gura_AssignUnaryOperator(Math_sqrt, array);
	Gura_AssignUnaryOperator(Math_tan, array);
	Gura_AssignUnaryOperator(Math_tanh, array);
	Gura_AssignUnaryOperator(Math_unitstep, array);
}

}
