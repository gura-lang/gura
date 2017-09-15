//=============================================================================
// Gura class: arrahchain
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_arraychain
//-----------------------------------------------------------------------------
Object_arraychain::Object_arraychain(Environment &env, ArrayChain *pArrayChain) :
	Object(env.LookupClass(VTYPE_arraychain)), _pArrayChain(pArrayChain)
{
}

Object_arraychain::Object_arraychain(Class *pClass, ArrayChain *pArrayChain) :
	Object(pClass), _pArrayChain(pArrayChain)
{
}

Object *Object_arraychain::Clone() const
{
	return nullptr;
}
	
String Object_arraychain::ToString(bool exprFlag)
{
	String str;
	str += "<arraychain";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// arraychain(expr:expr):map {block?}
Gura_DeclareFunction(arraychain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_arraychain));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(arraychain)
{
	AutoPtr<ArrayChain> pArrayChain(new ArrayChain());
	if (!pArrayChain->CreateFromExpr(env, Object_expr::GetObject(arg, 0)->GetExpr())) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_arraychain(env, pArrayChain.release())));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// arraychain#eval() {block?}
Gura_DeclareMethod(arraychain, eval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(arraychain, eval)
{
	ArrayChain *pArrayChain = Object_arraychain::GetObjectThis(arg)->GetArrayChain();
	if (!pArrayChain->Eval(env)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayChain->GetResult()->Reference())));
}

// arraychain#train(correct:array):void
Gura_DeclareMethod(arraychain, train)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "correct", VTYPE_array);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(arraychain, train)
{
	ArrayChain *pArrayChain = Object_arraychain::GetObjectThis(arg)->GetArrayChain();
	const Array *pArrayCorrect = Object_array::GetObject(0)->GetArray();
	if (!pArrayChain->Train(env, pArrayCorrect)) return Value::Nil;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_arraychain::Class_arraychain(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_arraychain)
{
}

void Class_arraychain::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(arraychain);
	// Assignment of methods
	Gura_AssignMethod(arraychain, eval);
	Gura_AssignMethod(arraychain, train);
	// Assignment of value
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_arraychain::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
