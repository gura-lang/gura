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
// array#average() {block?}
Gura_DeclareMethod(array, average)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates an average value of elements in the array.\n"
		);
}

Gura_ImplementMethod(array, average)
{
	return Value::Nil;
}

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

// array#dump():void
Gura_DeclareMethod(array, dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en),
		"Prints out a binary dump of the array's content.\n"
		);
}

Gura_ImplementMethod(array, dump)
{
	return Value::Nil;
}

// arrayT#each() {block?}
Gura_DeclareMethod(array, each)
{
	SetFuncAttr(VTYPE_iterator, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that iterates each element in the array.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en()
		"\n"
		"The block parameter is `|elem:number, idx:number|`\n"
		"where `elem` is the element value.\n"
		);
}

Gura_ImplementMethod(array, each)
{
	return Value::Nil;
}

// array#fill(value:number):void
Gura_DeclareMethod(array, fill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Fills array with a specified value.\n"
		);
}

Gura_ImplementMethod(array, fill)
{
	return Value::Nil;
}

// array#flat()
Gura_DeclareMethod(array, flat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Flatten elements in the array.\n"
		);
}

Gura_ImplementMethod(array, flat)
{
	//ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	return Value::Nil;
}

// array#head(n:number):map {block?}
Gura_DeclareMethod(array, head)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted specified number of elements\n"
		"from the beginning of the source.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod(array, head)
{
	return Value::Nil;
}

// array#offset(n:number):map {block?}
Gura_DeclareMethod(array, offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted elements of the source\n"
		"after skipping the first `n` elements.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod(array, offset)
{
	return Value::Nil;
}

// array#paste(offset:number, src:array):map:void
Gura_DeclareMethod(array, paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "src", VTYPE_array, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Pastes elements of `src` into the target `array` instance.\n"
		"\n"
		"The argument `offset` specifies the posision where elements are pasted in\n"
		);
}

Gura_ImplementMethod(array, paste)
{
	return Value::Nil;
}

// array#sum() {block?}
Gura_DeclareMethod(array, sum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a summation value of elements in the array.\n"
		);
}

Gura_ImplementMethod(array, sum)
{
	return Value::Nil;
}

// array#tail(n:number):map {block?}
Gura_DeclareMethod(array, tail)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted specified number of elements\n"
		"from the bottom of the source.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod(array, tail)
{
	return Value::Nil;
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
	Gura_AssignMethod(array, average);
	Gura_AssignMethod(array, dot);
	Gura_AssignMethod(array, dump);
	Gura_AssignMethod(array, each);
	Gura_AssignMethod(array, fill);
	Gura_AssignMethod(array, flat);
	Gura_AssignMethod(array, head);
	Gura_AssignMethod(array, offset);
	Gura_AssignMethod(array, paste);
	Gura_AssignMethod(array, sum);
	Gura_AssignMethod(array, tail);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en + 1);
}

}
