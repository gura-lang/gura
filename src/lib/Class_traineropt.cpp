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
	str += "<traineropt:";
	str += _pOptimizer->GetName(); 
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// traineropt@adam():map {block?}
Gura_DeclareFunctionAlias(traineropt_at_adam, "traineropt@adam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(traineropt_at_adam)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_Adam());
	return ReturnValue(env, arg, Value(new Object_traineropt(env, pOptimizer.release())));
}

// traineropt@gradient_descent(learning_rate:number):map {block?}
Gura_DeclareFunctionAlias(traineropt_at_gradient_descent, "traineropt@gradient_descent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "learning_rate", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(traineropt_at_gradient_descent)
{
	Double learningRate = arg.GetDouble(0);
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_GradientDescent(learningRate));
	return ReturnValue(env, arg, Value(new Object_traineropt(env, pOptimizer.release())));
}

// traineropt@momentum():map {block?}
Gura_DeclareFunctionAlias(traineropt_at_momentum, "traineropt@momentum")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(traineropt_at_momentum)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_Momentum());
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
	Gura_AssignFunction(traineropt_at_adam);
	Gura_AssignFunction(traineropt_at_gradient_descent);
	Gura_AssignFunction(traineropt_at_momentum);
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
