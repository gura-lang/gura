//=============================================================================
// Gura class: array
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_array
//-----------------------------------------------------------------------------
Object *Object_array::Clone() const
{
	return nullptr;
}

String Object_array::ToString(bool exprFlag)
{
	return "<array>";
}

Value Object_array::IndexGet(Environment &env, const Value &valueIdx)
{
	return Value::Nil;
}

void Object_array::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
}

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
		);
}

Gura_ImplementClassMethod(array, dot)
{
	Signal &sig = env.GetSignal();
	const Array *pArrayL = Object_array::GetObject(arg, 0)->GetArray();
	const Array *pArrayR = Object_array::GetObject(arg, 1)->GetArray();
	//BinaryOpType binaryOp = _binaryOps_Dot[pArrayA->GetElemType()][pArrayB->GetElemType()];
	//AutoPtr<Array> pArrayResult((*binaryOp)(sig, *pArrayA, *pArrayB));
	AutoPtr<Array> pArrayResult(Array::Dot(sig, pArrayL, pArrayR));
	if (pArrayResult.IsNull()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayResult.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_array::Class_array(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_array)
{
}

void Class_array::Prepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(array, Value(Reference()));
	// method assignment
	Gura_AssignMethod(array, dot);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en + 1);
}

}
