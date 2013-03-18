//
// Object_directory
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_directory
//-----------------------------------------------------------------------------
bool Object_directory::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_directory::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

String Object_directory::ToString(Signal sig, bool exprFlag)
{
	String str;
	Directory &directory = GetDirectory();
	str += "<directory:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_directory
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_directory::Class_directory(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_directory)
{
}

bool Class_directory::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
#if 0
	if (value.IsString()) {
		value = Value(new Object_directory(env, pStream));
		return true;
	}
#endif
	return false;
}

Object *Class_directory::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return NULL;
}

void Class_directory::OnModuleEntry(Environment &env, Signal sig)
{
}

}
