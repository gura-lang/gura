//-----------------------------------------------------------------------------
// Gura module: sys
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <gura.h>

Gura_BeginModuleBody(sys)

//-----------------------------------------------------------------------------
// Gura module functions: sys
//-----------------------------------------------------------------------------
// sys.echo(flag:boolean)
Gura_DeclareFunction(echo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en), 
		"Enables or disables echo-back functionality according to flag.");
}

Gura_ImplementFunction(echo)
{
	env.GetGlobal()->SetEchoFlag(arg.GetBoolean(0));
	return Value::Nil;
}

// sys.exit(status?:number)
Gura_DeclareFunction(exit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "status", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"Terminates the program with a specified status number.");
}

Gura_ImplementFunction(exit)
{
	::exit(arg.Is_number(0)? arg.GetInt(0) : 0);
	return Value::Nil;
}

// sys.interactive()
Gura_DeclareFunction(interactive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Enters to interactive mode.");
}

Gura_ImplementFunction(interactive)
{
	return env.ExecInteractiveHandler();
}

// sys.required_version(major:number, minor:number, patch:number)
Gura_DeclareFunction(required_version)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "major", VTYPE_number);
	DeclareArg(env, "minor", VTYPE_number);
	DeclareArg(env, "patch", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), 
		"Raises an error if the running interpreter doesn't satisfy the required version.");
}

Gura_ImplementFunction(required_version)
{
	Signal &sig = env.GetSignal();
	int verMajor = arg.GetInt(0);
	int verMinor = arg.GetInt(1);
	int verPatch = arg.GetInt(2);
	int numReq = verMajor * 1000000 + verMinor * 1000 + verPatch;
	int numSys = GURA_VERSION_MAJOR * 1000000 +
				GURA_VERSION_MINOR * 1000 + GURA_VERSION_PATCH;
	if (numReq > numSys) {
		sig.SetError(ERR_VersionError,
			 "required version is %d.%d.%d or later", verMajor, verMinor, verPatch);
		return Value::Nil;
	}
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// value assignment
	Gura_AssignValue(version,		Value(GURA_VERSION));
	Gura_AssignValue(banner,		Value(Version::GetBanner(false)));
	Gura_AssignValue(timestamp,		Value(Version::GetTimeStamp()));
	Gura_AssignValue(build,			Value(Symbol::Add(GURA_HOST_COMPILER_NAME)));
	Gura_AssignValue(platform,		Value(Symbol::Add(GURA_PLATFORM_NAME)));
	Gura_AssignValue(ps1,			Value(">>> "));
	Gura_AssignValue(ps2,			Value("... "));
	Gura_AssignValue(langcode,		Value(OAL::GetLangCode()));
	Gura_AssignValue(executable,	Value(OAL::GetExecutable()));
	Gura_AssignValue(incdir,		Value(OAL::GetIncludeDir()));
	Gura_AssignValue(libdir,		Value(OAL::GetLibraryDir()));
	Gura_AssignValue(datadir,		Value(OAL::GetDataDir()));
	Gura_AssignValue(moddir,		Value(OAL::GetModuleDir()));
	Gura_AssignValue(fontdir,		Value(OAL::GetFontDir()));
	String dirNameLocal = OAL::GetLocalDir();
	Gura_AssignValue(localdir, Value(dirNameLocal));
	Gura_AssignValue(
		appdir, Value(OAL::JoinPathName(dirNameLocal.c_str(), "application")));
	Gura_AssignValue(
		cfgdir, Value(OAL::JoinPathName(dirNameLocal.c_str(), "config")));
	Gura_AssignValue(
		workdir, Value(OAL::JoinPathName(dirNameLocal.c_str(), "work")));
	// function assignment
	Gura_AssignFunction(echo);
	Gura_AssignFunction(exit);
	Gura_AssignFunction(interactive);
	Gura_AssignFunction(required_version);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(sys, sys)

Gura_RegisterModule(sys)
