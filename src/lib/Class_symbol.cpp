//=============================================================================
// Gura class: symbol
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// symbol#eval(env?:environment)
Gura_DeclareMethod(symbol, eval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "env", VTYPE_environment, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Evaluate a symbol object.");
}

Gura_ImplementMethod(symbol, eval)
{
	Signal &sig = env.GetSignal();
	const Symbol *pSymbol = args.GetThis().GetSymbol();
	AutoPtr<Expr> pExpr(new Expr_Identifier(pSymbol));
	Environment *pEnv = args.Is_environment(0)?
			Object_environment::GetObject(args, 0)->GetEnv().Reference() :
			new Environment(&env, ENVTYPE_block);
	return Processor::Run(pEnv, sig, pExpr.get());
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_symbol::Class_symbol(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_symbol)
{
}

void Class_symbol::Prepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(symbol, Value(Reference()));
	// method assignment
	Gura_AssignMethod(symbol, eval);	// primitive method
}

bool Class_symbol::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	if (value.Is_string()) {
		value = Value(Symbol::Add(value.GetString()));
		return true;
	}
	return false;
}

bool Class_symbol::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	return stream.SerializeSymbol(sig, value.GetSymbol());
}

bool Class_symbol::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	Signal &sig = GetSignal();
	const Symbol *pSymbol = nullptr;
	if (!stream.DeserializeSymbol(sig, &pSymbol)) return false;
	value = Value(pSymbol);
	return true;
}

}
