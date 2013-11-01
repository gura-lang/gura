//
// Object_args
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gura interfaces for args
//-----------------------------------------------------------------------------
// args#isset(symbol:symbol)
Gura_DeclareMethod(args, isset)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol, OCCUR_Once);
}

Gura_ImplementMethod(args, isset)
{
	Args *pArgs = Object_args::GetThisObj(args)->GetArgs();
	bool rtn = pArgs->IsSet(args.GetSymbol(0));
	return Value(rtn);
}

// args#quit_trailer():void
Gura_DeclareMethod(args, quit_trailer)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(args, quit_trailer)
{
	Args *pArgs = Object_args::GetThisObj(args)->GetArgs();
	pArgs->QuitTrailer();
	return Value::Null;
}

// args#finalize_trailer():void
Gura_DeclareMethod(args, finalize_trailer)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(args, finalize_trailer)
{
	Args *pArgs = Object_args::GetThisObj(args)->GetArgs();
	pArgs->FinalizeTrailer();
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Object implementation for args
//-----------------------------------------------------------------------------
Object *Object_args::Clone() const
{
	return new Object_args(*this);
}

bool Object_args::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(values));
	return true;
}

Value Object_args::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(values))) {
		Value rtn;
		rtn.InitAsList(env, _pArgs->GetValueListArg());
		return rtn;
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_args::ToString(bool exprFlag)
{
	String str;
	str += "<args:";
	str += ">";
	return str;
}

//----------------------------------------------------------------------------
// Class implementation for args
//----------------------------------------------------------------------------
Class_args::Class_args(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_args)
{
}

void Class_args::Prepare(Environment &env)
{
	Gura_AssignMethod(args, isset);
	Gura_AssignMethod(args, quit_trailer);
	Gura_AssignMethod(args, finalize_trailer);
}

Object *Class_args::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
