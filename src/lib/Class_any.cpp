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
Class_any::Class_any(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_any)
{
}

void Class_any::DoPrepare(Environment &env)
{
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_any::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_any::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_any::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	value = Value::Nil;
	return true;
}


}
