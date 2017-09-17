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
// trainer(expr:expr, sources+:symbol):map {block?}
Gura_DeclareFunction(trainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr, OCCUR_Once);
	DeclareArg(env, "sources", VTYPE_symbol, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_trainer));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(trainer)
{
	AutoPtr<Trainer> pTrainer(new Trainer());
	SymbolSet symbolsSource;
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		symbolsSource.Insert(pValue->GetSymbol());
	}
	if (!pTrainer->CreateFromExpr(env, Object_expr::GetObject(arg, 0)->GetExpr(), symbolsSource)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_trainer(env, pTrainer.release())));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// trainer#result
Gura_DeclareProperty_R(trainer, result)
{
	SetPropAttr(VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		"Evaluation result.");
}

Gura_ImplementPropertyGetter(trainer, result)
{
	Trainer *pTrainer = Object_trainer::GetObject(valueThis)->GetTrainer();
	//return Array::ToValue(env, pTrainer->GetResult()->Reference());
	return Array::ToValue(env, pTrainer->GetResultSoftmax()->Reference());
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// trainer#eval() {block?}
Gura_DeclareMethod(trainer, eval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(trainer, eval)
{
	Trainer *pTrainer = Object_trainer::GetObjectThis(arg)->GetTrainer();
	if (!pTrainer->Eval(env)) return Value::Nil;
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
	if (!pTrainer->Train(env, pArrayCorrect)) return Value::Nil;
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
