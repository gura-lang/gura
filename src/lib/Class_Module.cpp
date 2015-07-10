//=============================================================================
// Gura class: Module
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_Module::Class_Module(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_Module)
{
}

void Class_Module::Prepare(Environment &env)
{
}

bool Class_Module::CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_Module::Serialize(Environment &env, Signal &sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_Module::Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

}
