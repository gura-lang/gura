//=============================================================================
// Gura class: quote
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_quote::Class_quote(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_quote)
{
}

void Class_quote::Prepare(Environment &env)
{
}

bool Class_quote::CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_quote::Serialize(Environment &env, Signal &__to_delete__, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_quote::Deserialize(Environment &env, Signal &__to_delete__, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

}
