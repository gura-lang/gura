//=============================================================================
// Gura module: arrayutil
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(arrayutil)

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// array.dot(a:array, b:array):static:map {block?}
Gura_DeclareClassMethod(array, dot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_array);
	DeclareArg(env, "b", VTYPE_array);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a dot product between two arrays that have one or two dimensions.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementClassMethod(array, dot)
{
	const Array *pArrayL = Object_array::GetObject(arg, 0)->GetArray();
	const Array *pArrayR = Object_array::GetObject(arg, 1)->GetArray();
	Value valResult = CalcDot(env, pArrayL, pArrayR);
	if (env.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, valResult);
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
	// Assignment of method
	Gura_AssignMethodTo(VTYPE_array, array, dot);
	// Assignment of operator
	AssignOperators(env);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(arrayutil, arrayutil)

Gura_RegisterModule(arrayutil)
