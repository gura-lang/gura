//=============================================================================
// Gura class: any
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_any::Class_any(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_any)
{
}

void Class_any::Prepare(Environment &env)
{
}

bool Class_any::CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_any::Serialize(Environment &env, Signal &__to_delete__, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_any::Deserialize(Environment &env, Signal &__to_delete__, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}


}
