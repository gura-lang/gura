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
	AddHelp(Gura_Symbol(en), 
	"Enables or disables echo-back functionality according to flag.");
}

Gura_ImplementFunction(echo)
{
	env.GetGlobal()->SetEchoFlag(args.GetBoolean(0));
	return Value::Null;
}

// sys.exit(status?:number)
Gura_DeclareFunction(exit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "status", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), 
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
#elif defined(__GNUC__) && defined(__GNUC_MINOR__)
		valueBuild = Value(Gura_Symbol(gnuc));
#else
		valueBuild = Value::Null;
#endif
#if defined(GURA_ON_MSWIN)
		valuePlatform = Value(Gura_Symbol(mswin));
#elif defined(GURA_ON_LINUX)
		valuePlatform = Value(Gura_Symbol(linux));
#else
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
	const char *extName = PathManager::SeekExtName(pathName);
	return ::strcasecmp(extName, ".gurc") == 0 ||
			::strcasecmp(extName, ".gurcw") == 0;
}

static bool ExpandWildCard(Environment &env, Signal sig,
									ValueList &valList, const char *pattern)
{
	bool addSepFlag = true;
	bool statFlag = false;
#if defined(GURA_ON_MSWIN)
	bool ignoreCaseFlag = true;
#else
	bool ignoreCaseFlag = false;
#endif
	bool fileFlag = true;
	bool dirFlag = true;
	AutoPtr<PathManager::Iterator_Glob> pIterator(new PathManager::Iterator_Glob(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag));
	if (!pIterator->Init(env, sig, pattern)) return false;
	Value value;
	bool emptyFlag = true;
	while (pIterator->Next(env, sig, value)) {
		valList.push_back(value);
		emptyFlag  = false;
	}
	if (emptyFlag) valList.push_back(Value(env, pattern));
	return !sig.IsSignalled();
}

bool SetupValues(Module *pModule, Signal sig, int argc, const char *argv[])
{
	Environment &env = *pModule;
	String fileNameScript = OAL::FromNativeString(argv[1]);
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		if (argc >= 2 && argv != NULL) {
			valList.push_back(Value(env,
					OAL::MakeAbsPathName(OAL::FileSeparator, fileNameScript.c_str()).c_str()));
			for (int i = 2; i < argc; i++) {
				const char *arg = argv[i];
				//if (Directory::HasWildCard(arg)) {
				//	if (!ExpandWildCard(env, sig, valList, arg)) return false;
				//} else {
				//	valList.push_back(Value(env, arg));
				//}
				valList.push_back(Value(env, OAL::FromNativeString(arg)));
			}
		}
		env.AssignValue(Symbol::Add("argv"), value, EXTRA_Public);
	} while (0);
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		StringList strList;
		OAL::SetupModulePath(strList);
		foreach (StringList, pStr, strList) {
			valList.push_back(Value(env, pStr->c_str()));
		}
		if (argc >= 2 && IsCompositeFile(fileNameScript.c_str())) {
			valList.push_back(Value(env,
				OAL::MakeAbsPathName(OAL::FileSeparator, fileNameScript.c_str()).c_str()));
		}
		env.AssignValue(Symbol::Add("path"), value, EXTRA_Public);
	} while (0);
	do {
		std::string str;
		if (argc < 2) {
			str = OAL::GetCurDir();
		} else {
			str = OAL::MakeAbsPathName(OAL::FileSeparator, fileNameScript.c_str());
			if (!IsCompositeFile(fileNameScript.c_str())) {
				String dirName;
				PathManager::SplitFileName(str.c_str(), &dirName, NULL);
				str = dirName;
			}
		}
		env.AssignValue(Symbol::Add("maindir"), Value(env, str.c_str()), EXTRA_Public);
	} while (0);
	return true;
}

Gura_EndModule(sys, sys)

Gura_RegisterModule(sys)
