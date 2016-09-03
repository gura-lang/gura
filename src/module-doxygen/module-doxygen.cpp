//=============================================================================
// Gura module: doxygen
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(doxygen)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// doxygen.makescript(stream?:stream:w):void
Gura_DeclareFunction(makescript)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementFunction(makescript)
{
	Stream &stream = arg.IsValid(0)? arg.GetStream(0) : *env.GetConsole();
	CommandFormat::MakeScript(env, stream);
	return Value::Nil;
}

#if 0
// doxygen.test(stream:stream):void
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
}

Gura_ImplementFunction(test)
{
	Stream &stream = arg.GetStream(0);
	AutoPtr<Configuration> pCfg(new Configuration());
	pCfg->ReadStream(env, stream);
	//cfg.Print();
	//AutoPtr<Aliases> pAliases(pCfg->MakeAliases(env));
	//pAliases->Print(env, stream);
	return Value::Nil;
}
#endif

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	Elem::Initialize();
	CommandFormat::Initialize();
	// symbol realization
	Gura_RealizeUserSymbol(aftermember);
	Gura_RealizeUserSymbol(aliases);
	Gura_RealizeUserSymbol(elem);
	Gura_RealizeUserSymbol(source);
	// class realization
	Gura_RealizeUserClass(elem, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(structure, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(document, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(configuration, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(aliases, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(renderer, env.LookupClass(VTYPE_object));
	// class preparation
	Gura_PrepareUserClass(elem);
	Gura_PrepareUserClass(structure);
	Gura_PrepareUserClass(document);
	Gura_PrepareUserClass(configuration);
	Gura_PrepareUserClass(aliases);
	Gura_PrepareUserClass(renderer);
	// function assignment
	Gura_AssignFunction(makescript);
	//Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
bool IsBlank(const char *str)
{
	for (const char *p = str; *p != '\0'; p++) {
		char ch = *p;
		if (ch != ' ' && ch != '\t' && ch != '\n') return false;
	}
	return true;
}

const char *SkipBlankLine(const char *str)
{
	const char *p = str;
	for ( ; *p != '\0'; p++) {
		char ch = *p;
		if (ch == '\n') return p + 1;
		if (ch != ' ' && ch != '\t') return str;
	}
	return p;
}

Gura_EndModuleBody(doxygen, doxygen)

Gura_RegisterModule(doxygen)
