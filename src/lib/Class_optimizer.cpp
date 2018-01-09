//=============================================================================
// Gura class: optimizer
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_optimizer
//-----------------------------------------------------------------------------
Object_optimizer::Object_optimizer(Environment &env, Trainer::Optimizer *pOptimizer) :
	Object(env.LookupClass(VTYPE_optimizer)), _pOptimizer(pOptimizer)
{
}

Object_optimizer::Object_optimizer(Class *pClass, Trainer::Optimizer *pOptimizer) :
	Object(pClass), _pOptimizer(pOptimizer)
{
}

String Object_optimizer::ToString(bool exprFlag)
{
	String str;
	str += "<optimizer:";
	str += _pOptimizer->GetName(); 
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// optimizer@adagrad():map {block?}
Gura_DeclareFunctionAlias(optimizer_at_adagrad, "optimizer@adagrad")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(optimizer_at_adagrad)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_AdaGrad());
	return ReturnValue(env, arg, Value(new Object_optimizer(env, pOptimizer.release())));
}

// optimizer@adam():map {block?}
Gura_DeclareFunctionAlias(optimizer_at_adam, "optimizer@adam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(optimizer_at_adam)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_Adam());
	return ReturnValue(env, arg, Value(new Object_optimizer(env, pOptimizer.release())));
}

// optimizer@gradient_descent(learning_rate:number):map {block?}
Gura_DeclareFunctionAlias(optimizer_at_gradient_descent, "optimizer@gradient_descent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "learning_rate", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(optimizer_at_gradient_descent)
{
	Double learningRate = arg.GetDouble(0);
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_GradientDescent(learningRate));
	return ReturnValue(env, arg, Value(new Object_optimizer(env, pOptimizer.release())));
}

// optimizer@momentum():map {block?}
Gura_DeclareFunctionAlias(optimizer_at_momentum, "optimizer@momentum")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(optimizer_at_momentum)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_Momentum());
	return ReturnValue(env, arg, Value(new Object_optimizer(env, pOptimizer.release())));
}

// optimizer@nesterov():map {block?}
Gura_DeclareFunctionAlias(optimizer_at_nesterov, "optimizer@nesterov")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(optimizer_at_nesterov)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_Nesterov());
	return ReturnValue(env, arg, Value(new Object_optimizer(env, pOptimizer.release())));
}

// optimizer@none():map {block?}
Gura_DeclareFunctionAlias(optimizer_at_none, "optimizer@none")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(optimizer_at_none)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_None());
	return ReturnValue(env, arg, Value(new Object_optimizer(env, pOptimizer.release())));
}

// optimizer@rmsprop():map {block?}
Gura_DeclareFunctionAlias(optimizer_at_rmsprop, "optimizer@rmsprop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(optimizer_at_rmsprop)
{
	AutoPtr<Trainer::Optimizer> pOptimizer(new Trainer::Optimizer_RMSprop());
	return ReturnValue(env, arg, Value(new Object_optimizer(env, pOptimizer.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_optimizer::Class_optimizer(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_optimizer)
{
}

void Class_optimizer::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(optimizer_at_adagrad);
	Gura_AssignFunction(optimizer_at_adam);
	Gura_AssignFunction(optimizer_at_gradient_descent);
	Gura_AssignFunction(optimizer_at_momentum);
	Gura_AssignFunction(optimizer_at_nesterov);
	Gura_AssignFunction(optimizer_at_none);
	Gura_AssignFunction(optimizer_at_rmsprop);
	// Assignment of value
	Gura_AssignValue(optimizer, Value(this));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_optimizer::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
