//=============================================================================
// Gura class: symbol
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// symbol#eval(env?:environment)
Gura_DeclareMethod(symbol, eval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "env", VTYPE_environment, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Evaluate a symbol object.");
}

Gura_ImplementMethod(symbol, eval)
{
	const Symbol *pSymbol = arg.GetValueThis().GetSymbol();
	AutoPtr<Expr> pExpr(new Expr_Identifier(pSymbol));
	AutoPtr<Environment> pEnv(
		arg.Is_environment(0)?
		Object_environment::GetObject(arg, 0)->GetEnv().Reference() :
		env.Derive(ENVTYPE_block));
	return pExpr->Exec(*pEnv);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_symbol::Class_symbol(Environment *pEnvOuter) : ClassPrimitive(pEnvOuter, VTYPE_symbol)
{
}

void Class_symbol::DoPrepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(symbol, Value(Reference()));
	// method assignment
	Gura_AssignMethod(symbol, eval);	// primitive method
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_symbol::CastFrom(Environment &env, Value &value, ULong flags)
{
	if (value.Is_string()) {
		value = Value(Symbol::Add(value.GetString()));
		return true;
	}
	return false;
}

Class::SerializeFmtVer Class_symbol::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_symbol::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	return stream.SerializeSymbol(sig, value.GetSymbol());
}

bool Class_symbol::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	if (serializeFmtVer == SerializeFmtVer_1) {
		const Symbol *pSymbol = nullptr;
		if (!stream.DeserializeSymbol(env, &pSymbol)) return false;
		value = Value(pSymbol);
		return true;
	}
	SetError_UnsupportedSerializeFmtVer(serializeFmtVer);
	return false;
}

}
