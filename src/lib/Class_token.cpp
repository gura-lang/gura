//=============================================================================
// Gura class: token
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_token
//-----------------------------------------------------------------------------
Object_token::Object_token(const Object_token &obj) : Object(obj), _token(obj.GetToken())
{
}

Object *Object_token::Clone() const
{
	return new Object_token(*this);
}

String Object_token::ToString(bool exprFlag)
{
	String str;
	str += "<token:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_token::Class_token(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_token)
{
}

void Class_token::Prepare(Environment &env)
{
	Gura_AssignValue(token, Value(Reference()));
}

Object *Class_token::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
