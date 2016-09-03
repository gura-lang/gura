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

bool Object_configuration::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(aliases));
	return true;
}

Value Object_configuration::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(aliases))) {
		AutoPtr<Aliases> pAliases(_pCfg->MakeAliases(env));
		if (pAliases.IsNull()) return Value::Nil;
		return Value(new Object_aliases(pAliases.release()));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_configuration::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.configuration:";
	rtn += _pCfg->GetSourceName();
	rtn += ">";
	return rtn;
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
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads a configuration file, which is usually dubbed \"Doxyfile\",\n"
		"from `stream` and creates a `doxygen.configuration` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("cfg", "doxygen.configuration"));
}

Gura_ImplementFunction(configuration)
{
	Stream &stream = arg.GetStream(0);
	AutoPtr<Configuration> pCfg(new Configuration());
	if (!pCfg->ReadStream(env, stream)) return Value::Nil;
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
		Gura_Symbol(en), Help::FMT_markdown,
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
		Gura_Symbol(en), Help::FMT_markdown,
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
	Gura_AssignFunction(configuration);
	Gura_AssignMethod(configuration, get);
	Gura_AssignMethod(configuration, print);
}

Gura_ImplementCastFrom(configuration)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, pDecl);
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
