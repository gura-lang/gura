//=============================================================================
// Gura class: Class
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_Class::Class_Class(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_Class)
{
}

void Class_Class::DoPrepare(Environment &env)
{
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_Class::CastFrom(Environment &env, Value &value, ULong flags)
{
	return false;
}

Class::SerializeFmtVer Class_Class::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_Class::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_Class::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	value = Value::Nil;
	return true;
}

}
