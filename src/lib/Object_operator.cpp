//
// Object_operator
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_operator
//-----------------------------------------------------------------------------
Object_operator::Object_operator(const Object_operator &obj) :
										Object(obj), _opType(obj._opType)
{
}

Object_operator::~Object_operator()
{
}

Object *Object_operator::Clone() const
{
	return new Object_operator(*this);
}

String Object_operator::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<operator:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_operator
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_operator::Class_operator(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_operator)
{
}

Object *Class_operator::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_operator::OnModuleEntry(Environment &env, Signal sig)
{
}

}
