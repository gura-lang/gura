#include "stdafx.h"

Gura_BeginModuleScope(arrayutil)

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

void AssignOperators(Environment &env)
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
}

Gura_EndModuleScope(arrayutil)
