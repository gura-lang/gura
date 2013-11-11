//-----------------------------------------------------------------------------
// Gura directory class
//-----------------------------------------------------------------------------
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

String Object_directory::ToString(bool exprFlag)
{
	String str;
	//Directory *pDirectory = GetDirectory();
	str += "<directory:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for directory
//-----------------------------------------------------------------------------
// directory(pathname:string):map {block?}
Gura_DeclareFunction(directory)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_directory));
}

Gura_ImplementFunction(directory)
{
	const char *pathName = args.GetString(0);
	AutoPtr<Directory> pDirectory(Directory::Open(env, sig,
								pathName, PathManager::NF_Signal));
	if (sig.IsSignalled()) return Value::Null;
	Object_directory *pObj = new Object_directory(env, pDirectory.release());
	return ReturnValue(env, sig, args, Value(pObj));
}

//-----------------------------------------------------------------------------
// Class implementation
//-----------------------------------------------------------------------------
Class_directory::Class_directory(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_directory)
{
}

void Class_directory::Prepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(directory);
}

bool Class_directory::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_string()) {
		AutoPtr<Directory> pDirectory(Directory::Open(env, sig,
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
