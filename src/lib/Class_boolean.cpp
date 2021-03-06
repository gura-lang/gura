//=============================================================================
// Gura class: boolean
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
# Overview

The `boolean` class represents a boolean data type that is used in logical operations
including NOT, AND, OR and XOR.

The `boolean` type provides two values: `true` and `false`.
The other types of values can also be calculated in logical operations
according to the following general rule:

- The `nil` value is evaluated as `false` value.
- Other values are evaluated as `true`.

Note that the number `0` is treated as `true` in logical operations.
)**";

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_boolean::Class_boolean(Environment *pEnvOuter) : ClassPrimitive(pEnvOuter, VTYPE_boolean)
{
}

void Class_boolean::DoPrepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(boolean, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_boolean::CastFrom(Environment &env, Value &value, ULong flags)
{
	if (value.Is_list()) {
		return true;
	} else {
		value = Value(value.GetBoolean());
		return true;
	}
}

Class::SerializeFmtVer Class_boolean::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_boolean::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	return stream.SerializeUInt8(sig, static_cast<UInt8>(value.GetBoolean()));
}

bool Class_boolean::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	if (serializeFmtVer == SerializeFmtVer_1) {
		UInt8 num = 0;
		if (!stream.DeserializeUInt8(env, num)) return false;
		value = Value(num != 0);
		return true;
	}
	SetError_UnsupportedSerializeFmtVer(serializeFmtVer);
	return false;
}

bool Class_boolean::Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_d(flags,
		static_cast<int>(value.GetBoolean()), buff, sizeof(buff)));
}

bool Class_boolean::Format_u(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	char buff[128];
	return pFormatter->PutAlignedString(sig, flags, Formatter::Format_d(flags,
		static_cast<int>(value.GetBoolean()), buff, sizeof(buff)));
}

}
