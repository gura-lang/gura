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
		Gura_Symbol(en), Help::FMT_markdown, 
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "status", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Terminates the program with a specified status number.");
}

Gura_ImplementFunction(exit)
{
	::exit(args.Is_number(0)? args.GetInt(0) : 0);
	return Value::Null;
}

// sys.required_version(major:number, minor:number, patch:number)
Gura_DeclareFunction(required_version)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "major", VTYPE_number);
	DeclareArg(env, "minor", VTYPE_number);
	DeclareArg(env, "patch", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Raises an error if the running interpreter doesn't satisfy the required version.");
}

Gura_ImplementFunction(required_version)
{
	int verMajor = args.GetInt(0);
	int verMinor = args.GetInt(1);
	int verPatch = args.GetInt(2);
	int numReq = verMajor * 1000000 + verMinor * 1000 + verPatch;
	int numSys = GURA_VERSION_MAJOR * 1000000 +
				GURA_VERSION_MINOR * 1000 + GURA_VERSION_PATCH;
	if (numReq > numSys) {
		sig.SetError(ERR_VersionError,
			 "required version is %d.%d.%d or later", verMajor, verMinor, verPatch);
		return Value::Null;
	}
	return Value::Null;
}

Gura_ModuleEntry()
{
	// value assignment
	Gura_AssignValue(version,		Value(GURA_VERSION));
	Gura_AssignValue(banner,		Value(Version::GetBanner()));
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
	Gura_AssignFunction(required_version);
	return true;
}

Gura_ModuleTerminate()
{
}

bool IsCompositeFile(const char *pathName)
{
	const char *extName = PathMgr::SeekExtName(pathName);
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
	AutoPtr<Directory::Iterator_Glob> pIterator(new Directory::Iterator_Glob(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag));
	if (!pIterator->Init(env, sig, pattern)) return false;
	Value value;
	bool emptyFlag = true;
	while (pIterator->Next(env, sig, value)) {
		valList.push_back(value);
		emptyFlag  = false;
	}
	if (emptyFlag) valList.push_back(Value(pattern));
	return !sig.IsSignalled();
}

bool SetCmdLineArgs(Module *pModule, Signal sig, int argc, const char *argv[])
{
	Environment &env = *pModule;
	String fileNameScript;
	if (argc >= 2) {
		fileNameScript = OAL::FromNativeString(argv[1]);
	}
	do {
		Value value;
		ValueList &valList = value.InitAsList(env);
		if (argc >= 2 && argv != NULL) {
			valList.push_back(Value(OAL::MakeAbsPathName(OAL::FileSeparator, fileNameScript.c_str())));
			for (int i = 2; i < argc; i++) {
				const char *arg = argv[i];
				//if (Directory::HasWildCard(arg)) {
				//	if (!ExpandWildCard(env, sig, valList, arg)) return false;
				//} else {
				//	valList.push_back(Value(arg));
				//}
				valList.push_back(Value(OAL::FromNativeString(arg)));
			}
		}
		env.AssignValue(Symbol::Add("argv"), value, EXTRA_Public);
	} while (0);
	do {
		Option &opt = env.GetOption();
		Value value;
		ValueList &valList = value.InitAsList(env);
		do {
			String dirName, fileName;
			PathMgr::SplitFileName(fileNameScript.c_str(), &dirName, &fileName);
			if (!dirName.empty()) {
				valList.push_back(Value(OAL::MakeAbsPathName(OAL::FileSeparator, dirName.c_str())));
			}
		} while (0);
		valList.push_back(Value("."));
		if (opt.IsSet("import-dir")) {
			foreach_const (StringList, pStr, opt.GetStringList("import-dir")) {
				valList.push_back(Value(*pStr));
			}
		}
		StringList strList;
		OAL::SetupModulePath(strList);
		foreach (StringList, pStr, strList) {
			valList.push_back(Value(*pStr));
		}
		if (argc >= 2 && IsCompositeFile(fileNameScript.c_str())) {
			valList.push_back(Value(OAL::MakeAbsPathName(OAL::FileSeparator, fileNameScript.c_str())));
		}
		env.AssignValue(Symbol::Add("path"), value, EXTRA_Public);
	} while (0);
	do {
		String str;
		if (argc < 2) {
			str = OAL::GetCurDir();
		} else {
			str = OAL::MakeAbsPathName(OAL::FileSeparator, fileNameScript.c_str());
			if (!IsCompositeFile(fileNameScript.c_str())) {
				String dirName;
				PathMgr::SplitFileName(str.c_str(), &dirName, NULL);
				str = dirName;
			}
		}
		env.AssignValue(Symbol::Add("maindir"), Value(str), EXTRA_Public);
	} while (0);
	return true;
}

Gura_EndModuleBody(sys, sys)

Gura_RegisterModule(sys)
