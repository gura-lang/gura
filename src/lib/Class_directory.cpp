//=============================================================================
// Gura class: directory
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
# Overview

The `directory` class handles information necessary to seek directory structure in a path.
Its instance usually works with functions in `path` module: `path.dir()` and `path.walk()`.

Though the instance can be created by `directory()` function,
you don't have to use it in many cases because a casting from `string` to `directory` instance
works implicitly in a function call.


# Constructor

${markdown.makedoc@function(`en
directory
)}
)**";

//-----------------------------------------------------------------------------
// Object_directory
//-----------------------------------------------------------------------------
String Object_directory::ToString(bool exprFlag)
{
	const Directory *pDirectory = GetDirectory();
	String str;
	str += "<directory:";
	pDirectory->GetName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// directory(pathname:string):map {block?}
Gura_DeclareFunction(directory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_directory));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `directory` instance from the specified path name.\n");
}

Gura_ImplementFunction(directory)
{
	const char *pathName = arg.GetString(0);
	AutoPtr<Directory> pDirectory(Directory::Open(env, pathName, PathMgr::NF_Signal));
	if (env.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_directory(env, pDirectory.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_directory::Class_directory(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_directory)
{
}

void Class_directory::DoPrepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(directory);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_directory::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	if (value.Is_string()) {
		AutoPtr<Directory> pDirectory(Directory::Open(env,
									value.GetString(), PathMgr::NF_Signal));
		if (sig.IsSignalled()) return false;
		value = Value(new Object_directory(env, pDirectory.release()));
		return true;
	}
	return false;
}

Object *Class_directory::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
