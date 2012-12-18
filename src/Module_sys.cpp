//-----------------------------------------------------------------------------
// Gura sys module
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include <gura.h>

Gura_BeginModule(sys)

//-----------------------------------------------------------------------------
// Gura module functions: sys
//-----------------------------------------------------------------------------
// sys.echo(flag:boolean)
Gura_DeclareFunction(echo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flag", VTYPE_boolean);
	SetHelp(
	"Enables or disables echo-back functionality according to flag.");
}

Gura_ImplementFunction(echo)
{
	env.SetEchoFlag(args.GetBoolean(0));
	return Value::Null;
}

// sys.exit(status?:number)
Gura_DeclareFunction(exit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "status", VTYPE_number, OCCUR_ZeroOrOnce);
	SetHelp(
	"Terminates the program with a specified status number.");
}

Gura_ImplementFunction(exit)
{
	::exit(args.IsNumber(0)? args.GetInt(0) : 0);
	return Value::Null;
}

Gura_ModuleEntry()
{
	// value assignment
	Gura_AssignValue(version, Value(env, GURA_VERSION));
	Gura_AssignValue(ps1, Value(env, ">>> "));
	Gura_AssignValue(ps2, Value(env, "... "));
	do {
		Value valueBuild, valuePlatform;
#if defined(_MSC_VER)
		valueBuild = Value(Gura_Symbol(msc));
		valuePlatform = Value(Gura_Symbol(windows));
#elif defined(__BORLANDC__)
		valueBuild = Value(Gura_Symbol(bcc));
		valuePlatform = Value(Gura_Symbol(windows));
#elif defined(__GNUC__) && defined(__GNUC_MINOR__)
		valueBuild = Value(Gura_Symbol(gnuc));
		valuePlatform = Value(Gura_Symbol(linux));
#else
		valueBuild = Value::Null;
		valuePlatform = Value::Null;
#endif
		Gura_AssignValue(build, valueBuild);
		Gura_AssignValue(platform, valuePlatform);
	} while (0);
	Gura_AssignValue(executable, Value(env, OAL::GetExecutable().c_str()));
	Gura_AssignValue(datadir, Value(env, OAL::GetDataDir().c_str()));
	Gura_AssignValue(libdir, Value(env, OAL::GetLibDir().c_str()));
	Gura_AssignValue(localdir, Value(env, OAL::GetLocalDir().c_str()));
	// function assignment
	Gura_AssignFunction(echo);
	Gura_AssignFunction(exit);
}

Gura_ModuleTerminate()
{
}

bool IsCompositeFile(const char *pathName)
{
	const char *extName = Directory::SeekExtName(pathName);
	return ::strcasecmp(extName, ".gurc") == 0 ||
			::strcasecmp(extName, ".gurcw") == 0;
}

void Setup(Module *pModule, Signal sig, int argc, const char *argv[])
{
	Environment &env = *pModule;
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		if (argc >= 2 && argv != NULL) {
			valList.push_back(Value(env,
					OAL::MakeAbsPathName(OAL::FileSeparator, argv[1]).c_str()));
			for (int i = 2; i < argc; i++) {
				const char *arg = argv[i];
				valList.push_back(Value(env, arg));
			}
		}
		env.AssignValue(Symbol::Add("argv"), value, false);
	} while (0);
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		StringList strList;
		OAL::SetupModulePath(strList);
		foreach (StringList, pStr, strList) {
			valList.push_back(Value(env, pStr->c_str()));
		}
		if (argc >= 2 && IsCompositeFile(argv[1])) {
			valList.push_back(Value(env,
				OAL::MakeAbsPathName(OAL::FileSeparator, argv[1]).c_str()));
		}
		env.AssignValue(Symbol::Add("path"), value, false);
	} while (0);
	do {
		std::string str;
		if (argc < 2) {
			str = OAL::GetCurDir();
		} else {
			str = OAL::MakeAbsPathName(OAL::FileSeparator, argv[1]);
			if (!IsCompositeFile(argv[1])) {
				String dirName;
				Directory::SplitFileName(str.c_str(), &dirName, NULL);
				str = dirName;
			}
		}
		env.AssignValue(Symbol::Add("maindir"), Value(env, str.c_str()), false);
	} while (0);
	env.GetGlobal()->_pModule_sys = pModule;
}

Gura_EndModule(sys, sys)

Gura_RegisterModule(sys)
