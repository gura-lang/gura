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
// trainer(model:expr, optimizer:optimizer:nil, inputs*:symbol):map {block?}
Gura_DeclareFunction(trainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "model", VTYPE_expr, OCCUR_Once);
	DeclareArg(env, "optimizer", VTYPE_optimizer, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "inputs", VTYPE_symbol, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_trainer));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(trainer)
{
	Trainer::Optimizer *pOptimizer = arg.IsValid(1)?
		Object_optimizer::GetObject(arg, 1)->GetOptimizer()->Reference() : new Trainer::Optimizer_None();
	AutoPtr<Trainer> pTrainer(new Trainer(pOptimizer));
	SymbolSet symbolsInput;
	foreach_const (ValueList, pValue, arg.GetList(2)) {
		symbolsInput.Insert(pValue->GetSymbol());
	}
	if (!pTrainer->CreateFromExpr(env, Object_expr::GetObject(arg, 0)->GetExpr(), symbolsInput)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_trainer(env, pTrainer.release())));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
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

// trainer#node@bottom
Gura_DeclarePropertyAlias_R(trainer, node_at_bottom, "node@bottom")
{
	SetPropAttr(VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		"Returns a `trainernode` instance that is placed at bottom.");
}

Gura_ImplementPropertyGetter(trainer, node_at_bottom)
{
	Trainer *pTrainer = Object_trainer::GetObject(valueThis)->GetTrainer();
	return Value(new Object_trainernode(env, pTrainer->Reference(), pTrainer->GetNodeBottom()));
}

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
		"Evaluates the registered model and returns its result.\n"
		"\n"
		"If the argument `env` is specified, evaluation is done in that environment.\n"
		"Otherwise, the scope where the methos is called is used.\n");
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

// trainer#evalbwd(correct:array, env?:environment):void
Gura_DeclareMethod(trainer, evalbwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "correct", VTYPE_array);
	DeclareArg(env, "env", VTYPE_environment, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Evaluates backward proces for the registered model. This must be called after `trainer#eval()`.\n"
		"\n"
		"The argument `correct` takes an `array` instance that represents the 'correct' answer for the result."
		"\n"
		"If the argument `env` is specified, evaluation is done in that environment.\n"
		"Otherwise, the scope where the methos is called is used.\n");
}

Gura_ImplementMethod(trainer, evalbwd)
{
	Trainer *pTrainer = Object_trainer::GetObjectThis(arg)->GetTrainer();
	const Array *pArrayCorrect = Object_array::GetObject(arg, 0)->GetArray();
	AutoPtr<Environment> pEnv(
		arg.Is_environment(0)?
		Object_environment::GetObject(arg, 0)->GetEnv().Reference() :
		env.Derive(ENVTYPE_block));
	if (!pTrainer->EvalBackward(*pEnv, pArrayCorrect)) return Value::Nil;
	return Value::Nil;
}

// trainer#node(id:symbol):map:[nil] {block?}
Gura_DeclareMethod(trainer, node)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_symbol);
	DeclareAttr(Gura_Symbol(nil));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(trainer, node)
{
	Trainer *pTrainer = Object_trainer::GetObjectThis(arg)->GetTrainer();
	const Symbol *pSymbol = arg.GetSymbol(0);
	Trainer::Node *pNode = pTrainer->FindNode(pSymbol);
	Value valueRtn;
	if (pNode == nullptr) {
		if (!arg.IsSet(Gura_Symbol(nil))) {
			env.SetError(ERR_ValueError, "failed to find a node with the specified id");
			return Value::Nil;
		}
	} else {
		valueRtn = Value(new Object_trainernode(env, pTrainer->Reference(), pNode));
	}
	return ReturnValue(env, arg, valueRtn);
}

// trainer#train(correct:array, env?:environment):void
Gura_DeclareMethod(trainer, train)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "correct", VTYPE_array);
	DeclareArg(env, "env", VTYPE_environment, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Do evaluating and backward-evaluating in a row.\n"
		"Calling this methos is the same as calling `trainer#eval()` and then `trainer#evalbwd()`.\n"
		"\n"
		"The argument `correct` takes an `array` instance that represents the 'correct' answer for the result."
		"\n"
		"If the argument `env` is specified, evaluation is done in that environment.\n"
		"Otherwise, the scope where the methos is called is used.\n");
}

Gura_ImplementMethod(trainer, train)
{
	Trainer *pTrainer = Object_trainer::GetObjectThis(arg)->GetTrainer();
	const Array *pArrayCorrect = Object_array::GetObject(arg, 0)->GetArray();
	AutoPtr<Environment> pEnv(
		arg.Is_environment(0)?
		Object_environment::GetObject(arg, 0)->GetEnv().Reference() :
		env.Derive(ENVTYPE_block));
	if (!pTrainer->EvalForward(*pEnv)) return Value::Nil;
	if (!pTrainer->EvalBackward(*pEnv, pArrayCorrect)) return Value::Nil;
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
	Gura_AssignProperty(trainer, model);
	Gura_AssignProperty(trainer, node_at_bottom);
	Gura_AssignProperty(trainer, result);
	// Assignment of methods
	Gura_AssignMethod(trainer, eval);
	Gura_AssignMethod(trainer, evalbwd);
	Gura_AssignMethod(trainer, node);
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
