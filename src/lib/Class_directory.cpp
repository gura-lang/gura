//=============================================================================
// Gura class: directory
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
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
	Signal &sig = env.GetSignal();
	const char *pathName = arg.GetString(0);
	AutoPtr<Directory> pDirectory(Directory::Open(env,
								pathName, PathMgr::NF_Signal));
	if (sig.IsSignalled()) return Value::Nil;
	Object_directory *pObj = new Object_directory(env, pDirectory.release());
	return ReturnValue(env, arg, Value(pObj));
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
