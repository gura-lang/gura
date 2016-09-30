//=============================================================================
// Gura class: quote
//=============================================================================
#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_quote::Class_quote(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_quote)
{
}

void Class_quote::Prepare(Environment &env)
{
	// help document
	AddHelp(
		Gura_Symbol(en),
		R"**(
)**");
}

bool Class_quote::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_quote::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_quote::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	value = Value::Nil;
	return true;
}

}
