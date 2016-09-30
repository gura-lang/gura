//=============================================================================
// Class_aliases.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_aliases
//-----------------------------------------------------------------------------
Object_aliases::~Object_aliases()
{
}

Object *Object_aliases::Clone() const
{
	return nullptr;
}

bool Object_aliases::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Object_aliases::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Nil;
}

String Object_aliases::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.aliases:";
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.aliases#print(out?:stream):void
Gura_DeclareMethod(aliases, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Prints out definitions of aliases to the stream `out`.\n"
		"If the argument is omitted, the result would be put out to the standard output.\n");
}

Gura_ImplementMethod(aliases, print)
{
	Stream &stream = arg.IsValid(0)? arg.GetStream(0) : *env.GetConsole();
	const Aliases *pAliases = Object_aliases::GetObjectThis(arg)->GetAliases();
	pAliases->Print(env, stream);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.aliases
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(aliases)
{
	Gura_AssignValue(aliases, Value(Reference()));
	Gura_AssignMethod(aliases, print);
}

Gura_ImplementCastFrom(aliases)
{
	Gura_UserClass(configuration)->CastFrom(env, value, pDecl);
	if (value.IsType(VTYPE_configuration)) {
		const Configuration *pCfg = Object_configuration::GetObject(value)->GetConfiguration();
		AutoPtr<Aliases> pAliases(pCfg->MakeAliases(env));
		if (pAliases.IsNull()) return false;
		value = Value(new Object_aliases(pAliases.release()));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(aliases)
{
	return false;
}

Gura_EndModuleScope(doxygen)
