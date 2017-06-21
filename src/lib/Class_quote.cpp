//=============================================================================
// Gura class: quote
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_quote::Class_quote(Environment *pEnvOuter) : ClassPrimitive(pEnvOuter, VTYPE_quote)
{
}

void Class_quote::DoPrepare(Environment &env)
{
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_quote::CastFrom(Environment &env, Value &value, ULong flags)
{
	return false;
}

Class::SerializeFmtVer Class_quote::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_quote::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_quote::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	if (serializeFmtVer == SerializeFmtVer_1) {
		value = Value::Nil;
		return true;
	}
	SetError_UnsupportedSerializeFmtVer(serializeFmtVer);
	return false;
}

}
