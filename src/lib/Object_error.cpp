//
// Object_error
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_error
//-----------------------------------------------------------------------------
Object_error::Object_error(const Object_error &obj) :
										Object(obj), _errType(obj._errType)
{
}

Object_error::~Object_error()
{
}

Object *Object_error::Clone() const
{
	return new Object_error(*this);
}

String Object_error::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<error:";
	rtn += GetErrorTypeName(_errType);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_error
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_error::Class_error(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_error)
{
}

Object *Class_error::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_error::OnModuleEntry(Environment &env, Signal sig)
{
}

}
