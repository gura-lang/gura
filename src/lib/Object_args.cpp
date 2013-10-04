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

//-----------------------------------------------------------------------------
// Object implementation for args
//-----------------------------------------------------------------------------
Object_args::~Object_args()
{
}

Object *Object_args::Clone() const
{
	return new Object_args(*this);
}

String Object_args::ToString(Signal sig, bool exprFlag)
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
	Gura_AssignMethod(args, isset);
}

void Class_args::Prepare(Environment &env)
{
}

Object *Class_args::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
