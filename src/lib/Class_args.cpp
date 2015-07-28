//=============================================================================
// Gura class: args
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_args
//-----------------------------------------------------------------------------
Object *Object_args::Clone() const
{
	return new Object_args(*this);
}

bool Object_args::DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(values));
	return true;
}

Value Object_args::DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
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

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// args#finalize_trailer():void
Gura_DeclareMethod(args, finalize_trailer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Signals finalizing status to trailers after the current function.");
}

Gura_ImplementMethod(args, finalize_trailer)
{
	Args *pArgs = Object_args::GetThisObj(args)->GetArgs();
	pArgs->FinalizeTrailer();
	return Value::Null;
}

// args#isset(symbol:symbol)
Gura_DeclareMethod(args, isset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns `true` if the function is called with an attribute\n"
		"that matches the specified symbol.\n");
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Cancels evaluation of following trailers.\n"
		"\n"
		"Example:\n"
		"\n"
		"    f(flag:boolean) = {\n"
		"        !flag && __args__.quit_trailer() \n"
		"    }\n"
		"    \n"
		"    f(true) println('printed')\n"
		"    f(false) println('not printed')\n"
		);
}

Gura_ImplementMethod(args, quit_trailer)
{
	Args *pArgs = Object_args::GetThisObj(args)->GetArgs();
	pArgs->QuitTrailer();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Implementation of class
//----------------------------------------------------------------------------
Class_args::Class_args(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_args)
{
}

void Class_args::Prepare(Environment &env)
{
	Gura_AssignValue(args, Value(Reference()));
	Gura_AssignMethod(args, finalize_trailer);
	Gura_AssignMethod(args, isset);
	Gura_AssignMethod(args, quit_trailer);
}

Object *Class_args::CreateDescendant(Environment &env, Signal &__to_delete__, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
