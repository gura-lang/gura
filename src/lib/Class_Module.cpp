//=============================================================================
// Gura class: Module
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_Module::Class_Module(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_Module)
{
}

void Class_Module::DoPrepare(Environment &env)
{
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_Module::CastFrom(Environment &env, Value &value, ULong flags)
{
	return false;
}

Class::SerializeFmtVer Class_Module::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_Module::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_Module::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	if (serializeFmtVer == SerializeFmtVer_1) {
		value = Value::Nil;
		return true;
	}
	SetError_UnsupportedSerializeFmtVer(serializeFmtVer);
	return false;
}

}
