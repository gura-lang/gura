//=============================================================================
// Gura class: any
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_any::Class_any(Environment *pEnvOuter) : ClassPrimitive(pEnvOuter, VTYPE_any)
{
}

void Class_any::DoPrepare(Environment &env)
{
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_any::CastFrom(Environment &env, Value &value, ULong flags)
{
	return false;
}

Class::SerializeFmtVer Class_any::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_any::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_any::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	if (serializeFmtVer == SerializeFmtVer_1) {
		value = Value::Nil;
		return true;
	}
	SetError_UnsupportedSerializeFmtVer(serializeFmtVer);
	return false;
}


}
