//=============================================================================
// Gura class: boolean
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_boolean::Class_boolean(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_boolean)
{
}

void Class_boolean::Prepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(boolean, Value(Reference()));
}

bool Class_boolean::CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl)
{
	if (value.Is_list()) {
		return true;
	} else {
		value = Value(value.GetBoolean());
		return true;
	}
}

bool Class_boolean::Serialize(Environment &env, Signal &__to_delete__, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	return stream.SerializeUChar(sig, static_cast<UChar>(value.GetBoolean()));
}

bool Class_boolean::Deserialize(Environment &env, Signal &__to_delete__, Stream &stream, Value &value) const
{
	Signal &sig = GetSignal();
	UChar num = 0;
	if (!stream.DeserializeUChar(sig, num)) return false;
	value = Value(num != 0);
	return true;
}

bool Class_boolean::Format_d(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_d(flags,
		static_cast<int>(value.GetBoolean()), buff, sizeof(buff)));
}

bool Class_boolean::Format_u(Signal &__to_delete__, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_d(flags,
		static_cast<int>(value.GetBoolean()), buff, sizeof(buff)));
}

}
