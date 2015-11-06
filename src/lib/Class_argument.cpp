//=============================================================================
// Gura class: argument
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_argument
//-----------------------------------------------------------------------------
Object *Object_argument::Clone() const
{
	return new Object_argument(*this);
}

bool Object_argument::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(function));
	symbols.insert(Gura_Symbol(values));
	return true;
}

Value Object_argument::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(function))) {
		return Value(new Object_function(env, _pArg->GetFunction()->Reference()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(values))) {
		Value rtn;
		_pArg->GetValues(rtn.InitAsList(env));
		return rtn;
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_argument::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<argument:";
	::sprintf(buff, "%ldslots", _pArg->CountSlot());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// argument#finalize_trailer():void
Gura_DeclareMethod(arg, finalize_trailer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Signals finalizing status to trailers after the current function.");
}

Gura_ImplementMethod(arg, finalize_trailer)
{
	//Argument *pArg = Object_argument::GetObjectThis(arg)->GetArgument();
	//pArg->FinalizeTrailer();
	env.SetError(ERR_NotImplementedError, "not implemented yet");
	return Value::Nil;
}

// argument#isset(symbol:symbol)
Gura_DeclareMethod(arg, isset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns `true` if the function is called with an attribute\n"
		"that matches the specified symbol.\n");
}

Gura_ImplementMethod(arg, isset)
{
	Argument *pArg = Object_argument::GetObjectThis(arg)->GetArgument();
	bool rtn = pArg->IsSet(arg.GetSymbol(0));
	return Value(rtn);
}

// argument#quit_trailer():void
Gura_DeclareMethod(arg, quit_trailer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Cancels evaluation of following trailers.\n"
		"\n"
		"Example:\n"
		"\n"
		"    f(flag:boolean) = {\n"
		"        !flag && __arg__.quit_trailer() \n"
		"    }\n"
		"    \n"
		"    f(true) println('printed')\n"
		"    f(false) println('not printed')\n"
		);
}

Gura_ImplementMethod(arg, quit_trailer)
{
	Argument *pArg = Object_argument::GetObjectThis(arg)->GetArgument();
	pArg->QuitTrailer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Implementation of class
//----------------------------------------------------------------------------
Class_argument::Class_argument(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_argument)
{
}

void Class_argument::Prepare(Environment &env)
{
	Gura_AssignValue(argument, Value(Reference()));
	Gura_AssignMethod(arg, finalize_trailer);
	Gura_AssignMethod(arg, isset);
	Gura_AssignMethod(arg, quit_trailer);
}

Object *Class_argument::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
