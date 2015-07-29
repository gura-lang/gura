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

bool Class_Sequence::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_Sequence::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_Sequence::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

}
