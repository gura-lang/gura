//=============================================================================
// Gura class: Sequence
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_Sequence::Class_Sequence(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_Sequence)
{
}

void Class_Sequence::Prepare(Environment &env)
{
}

bool Class_Sequence::CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_Sequence::Serialize(Environment &env, Signal &sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_Sequence::Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

}
