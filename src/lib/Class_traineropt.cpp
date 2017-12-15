//=============================================================================
// Gura class: traineropt
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_traineropt
//-----------------------------------------------------------------------------
Object_traineropt::Object_traineropt(Environment &env, Trainer::Optimizer *pOptimizer) :
	Object(env.LookupClass(VTYPE_traineropt)), _pOptimizer(pOptimizer)
{
}

Object_traineropt::Object_traineropt(Class *pClass, Trainer::Optimizer *pOptimizer) :
	Object(pClass), _pOptimizer(pOptimizer)
{
}

String Object_traineropt::ToString(bool exprFlag)
{
	String str;
	str += "<traineropt";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// traineropt@gradient_descent(alpha:number):map {block?}
Gura_DeclareFunctionAlias(traineropt_at_gradient_descent, "traineropt@gradient_descent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "alpha", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(traineropt_at_gradient_descent)
{
	Double alpha = arg.GetDouble(0);
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_GradientDescent(alpha));
	return ReturnValue(env, arg, Value(new Object_traineropt(env, pOptimizer.release())));
}

// traineropt@none():map {block?}
Gura_DeclareFunctionAlias(traineropt_at_none, "traineropt@none")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(traineropt_at_none)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_None());
	return ReturnValue(env, arg, Value(new Object_traineropt(env, pOptimizer.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_traineropt::Class_traineropt(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_traineropt)
{
}

void Class_traineropt::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(traineropt_at_gradient_descent);
	Gura_AssignFunction(traineropt_at_none);
	// Assignment of value
	Gura_AssignValue(traineropt, Value(this));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_traineropt::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
