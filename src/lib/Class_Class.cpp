//=============================================================================
// Gura class: Class
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_Class::Class_Class(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_Class)
{
}

void Class_Class::Prepare(Environment &env)
{
}

bool Class_Class::CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_Class::Serialize(Environment &env, Signal &sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_Class::Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

}
