//=============================================================================
// Gura class: trainer
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_trainer
//-----------------------------------------------------------------------------
Object_trainer::Object_trainer(Environment &env, Trainer *pTrainer) :
	Object(env.LookupClass(VTYPE_trainer)), _pTrainer(pTrainer)
{
}

Object_trainer::Object_trainer(Class *pClass, Trainer *pTrainer) :
	Object(pClass), _pTrainer(pTrainer)
{
}

Object *Object_trainer::Clone() const
{
	return nullptr;
}
	
String Object_trainer::ToString(bool exprFlag)
{
	String str;
	str += "<trainer";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// trainer(model:expr, inputs*:symbol):map {block?}
Gura_DeclareFunction(trainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "model", VTYPE_expr, OCCUR_Once);
	DeclareArg(env, "inputs", VTYPE_symbol, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_trainer));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(trainer)
{
	AutoPtr<Trainer> pTrainer(new Trainer());
	SymbolSet symbolsInput;
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		symbolsInput.Insert(pValue->GetSymbol());
	}
	if (!pTrainer->CreateFromExpr(env, Object_expr::GetObject(arg, 0)->GetExpr(), symbolsInput)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_trainer(env, pTrainer.release())));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// trainer#result:nil
Gura_DeclareProperty_R(trainer, result)
{
	SetPropAttr(VTYPE_array, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"Evaluation result.");
}

Gura_ImplementPropertyGetter(trainer, result)
{
	Trainer *pTrainer = Object_trainer::GetObject(valueThis)->GetTrainer();
	const Array *pArray = pTrainer->GetResult();
	return (pArray == nullptr)? Value::Nil : Array::ToValue(env, pArray->Reference());
}

// trainer#model
Gura_DeclareProperty_R(trainer, model)
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		"Evaluation result.");
}

Gura_ImplementPropertyGetter(trainer, model)
{
	Trainer *pTrainer = Object_trainer::GetObject(valueThis)->GetTrainer();
	return Value(new Object_expr(env, pTrainer->GetExprModel()->Reference()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// trainer#eval(env?:environment) {block?}
Gura_DeclareMethod(trainer, eval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "env", VTYPE_environment, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(trainer, eval)
{
	Trainer *pTrainer = Object_trainer::GetObjectThis(arg)->GetTrainer();
	AutoPtr<Environment> pEnv(
		arg.Is_environment(0)?
		Object_environment::GetObject(arg, 0)->GetEnv().Reference() :
		env.Derive(ENVTYPE_block));
	if (!pTrainer->EvalForward(*pEnv)) return Value::Nil;
	return ReturnValue(env, arg, Array::ToValue(env, pTrainer->GetResult()->Reference()));
}

// trainer#train(correct:array):void
Gura_DeclareMethod(trainer, train)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "correct", VTYPE_array);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(trainer, train)
{
	Trainer *pTrainer = Object_trainer::GetObjectThis(arg)->GetTrainer();
	const Array *pArrayCorrect = Object_array::GetObject(arg, 0)->GetArray();
	if (!pTrainer->EvalForward(env)) return Value::Nil;
	if (!pTrainer->EvalBackward(env, pArrayCorrect)) return Value::Nil;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_trainer::Class_trainer(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_trainer)
{
}

void Class_trainer::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(trainer);
	// Assignment of properties
	Gura_AssignProperty(trainer, result);
	Gura_AssignProperty(trainer, model);
	// Assignment of methods
	Gura_AssignMethod(trainer, eval);
	Gura_AssignMethod(trainer, train);
	// Assignment of value
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_trainer::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
