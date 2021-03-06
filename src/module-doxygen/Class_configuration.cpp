//=============================================================================
// Class_configuration.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_configuration
//-----------------------------------------------------------------------------
Object_configuration::~Object_configuration()
{
}

Object *Object_configuration::Clone() const
{
	return nullptr;
}

String Object_configuration::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.configuration:";
	rtn += _pCfg->GetSourceName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// doxygen.configuration#aliases
Gura_DeclareProperty_R(configuration, aliases)
{
	SetPropAttr(VTYPE_aliases);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(configuration, aliases)
{
	const Configuration *pCfg = Object_configuration::GetObject(valueThis)->GetConfiguration();
	AutoPtr<Aliases> pAliases(pCfg->MakeAliases(env));
	if (pAliases.IsNull()) return Value::Nil;
	return Value(new Object_aliases(pAliases.release()));
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
// doxygen.configuration(stream?:stream) {block?}
Gura_DeclareFunction(configuration)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(configuration));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Reads a configuration file, which is usually dubbed \"Doxyfile\",\n"
		"from `stream` and creates a `doxygen.configuration` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("cfg", "doxygen.configuration"));
}

Gura_ImplementFunction(configuration)
{
	AutoPtr<Configuration> pCfg(new Configuration());
	if (arg.IsValid(0)) {
		Stream &stream = arg.GetStream(0);
		if (!pCfg->ReadStream(env, stream)) return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_configuration(pCfg.release())));
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.configuration#get(tagname:string):map:[raise]
Gura_DeclareMethod(configuration, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tagname", VTYPE_string, OCCUR_Once);
	DeclareAttr(Gura_Symbol(raise));
	AddHelp(
		Gura_Symbol(en),
		"Returns a value associated with the tag specified by the argument `tagname`.\n"
		"\n"
		"If the specified tag is not found, the method would return `nil`\n"
		"while it would cause an error in the case the attribute `:raise` is specified.\n");
}

Gura_ImplementMethod(configuration, get)
{
	const Configuration *pCfg = Object_configuration::GetObjectThis(arg)->GetConfiguration();
	const char *name = arg.GetString(0);
	const Configuration::Entry *pEntry = pCfg->Lookup(name);
	if (pEntry == nullptr) {
		if (arg.IsSet(Gura_Symbol(raise))) {
			env.SetError(ERR_KeyError, "the configuration doesn't have an entry named '%s'", name);
		}
		return Value::Nil;
	}
	return pEntry->GetAsValue(env);
}

// doxygen.configuration#print(out?:stream):void
Gura_DeclareMethod(configuration, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Prints out the content of the configuration to `out`.\n"
		"If omitted, the result would be put out to standard output.\n");
}

Gura_ImplementMethod(configuration, print)
{
	const Configuration *pCfg = Object_configuration::GetObjectThis(arg)->GetConfiguration();
	Stream &stream = arg.IsValid(0)? arg.GetStream(0) : *env.GetConsole();
	pCfg->Print(env, stream);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.configuration
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(configuration)
{
	// Assignment of function
	Gura_AssignFunction(configuration);
	// Assignment of properties
	Gura_AssignProperty(configuration, aliases);
	// Assignment of methods
	Gura_AssignMethod(configuration, get);
	Gura_AssignMethod(configuration, print);
}

Gura_ImplementCastFrom(configuration)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, flags);
	if (value.Is_stream()) {
		Stream &stream = value.GetStream();
		AutoPtr<Configuration> pCfg(new Configuration());
		if (!pCfg->ReadStream(env, stream)) return false;
		value = Value(new Object_configuration(pCfg.release()));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(configuration)
{
	return false;
}

Gura_EndModuleScope(doxygen)
