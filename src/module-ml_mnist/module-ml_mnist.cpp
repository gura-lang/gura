//=============================================================================
// Gura module: ml.mnist
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(ml_mnist)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.mnist.test(expr:expr)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "expr", VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(test)
{
	ArrayChainOwner arrayChainOwner;
	arrayChainOwner.CreateFromExpr(env, Object_expr::GetObject(arg, 0)->GetExpr());
	arrayChainOwner.front()->Print(0);
	if (!arrayChainOwner.InitForward(env)) return Value::Nil;
	arrayChainOwner.front()->Print(0);
	if (!arrayChainOwner.InitBackward(env)) return Value::Nil;
	arrayChainOwner.front()->Print(0);
	if (!arrayChainOwner.EvalForward(env)) return Value::Nil;
	if (!arrayChainOwner.EvalBackward(env)) return Value::Nil;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entry
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// Realization of class
	Gura_RealizeUserClass(ImageSet, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(LabelSet, env.LookupClass(VTYPE_object));
	// Preparation of class
	Gura_PrepareUserClass(ImageSet);
	Gura_PrepareUserClass(LabelSet);
	// Assignment of function
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ml_mnist, mnist)

Gura_RegisterModule(ml_mnist)
