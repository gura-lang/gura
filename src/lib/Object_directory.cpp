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
	//Directory *pDirectory = GetDirectory();
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

void Class_directory::Prepare(Environment &env)
{
}

bool Class_directory::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsString()) {
		AutoPtr<Directory> pDirectory(PathManager::OpenDirectory(env, sig,
									value.GetString(), PathManager::NF_Signal));
		if (sig.IsSignalled()) return false;
		value = Value(new Object_directory(env, pDirectory.release()));
		return true;
	}
	return false;
}

Object *Class_directory::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return NULL;
}

}
