//=============================================================================
// Gura module: arrayutil
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(arrayutil)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// arrayutil.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"This function adds two numbers and returns the result.\n");
}

Gura_ImplementFunction(test)
{
	return Value(arg.GetNumber(0) + arg.GetNumber(1));
}

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

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
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
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(arrayutil, arrayutil)

Gura_RegisterModule(arrayutil)
