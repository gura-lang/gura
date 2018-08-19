//-----------------------------------------------------------------------------
// Gura module: path
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(path)

//-----------------------------------------------------------------------------
// Gura module functions: path
//-----------------------------------------------------------------------------
// path.absname(name:string):map:[uri]
Gura_DeclareFunction(absname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string);
	DeclareAttr(Gura_Symbol(uri));
	AddHelp(
		Gura_Symbol(en),
		"Returns an absolute path name of the given name.");
}

Gura_ImplementFunction(absname)
{
	char chSeparator = arg.IsSet(Gura_Symbol(uri))? '/' : OAL::FileSeparator;
	return Value(OAL::MakeAbsPathName(chSeparator, arg.GetString(0)));
}

// path.basename(pathname:string):map
Gura_DeclareFunction(basename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), 
		"Removes a suffix part of a path name.\n"
		"This is complementary to `path.extname()`.\n"
		"\n"
		"Example:\n"
		"```\n"
		"path.basename('/foo/bar/file.txt')  # Returns '/foo/bar/file'\n"
		"```\n");
}

Gura_ImplementFunction(basename)
{
	const char *pathName = arg.GetString(0);
	const char *p = PathMgr::SeekExtName(pathName);
	size_t lenLeft = p - pathName;
	return Value(pathName, lenLeft);
}

// path.bottom(pathname:string):map
Gura_DeclareFunction(bottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), 
		"Returns the last part of a path name (cf. `path.filename()`)."
		"This is complementary to `path.cutbottom()`.\n"
		"\n"
		"Example:\n"
		"```\n"
		"path.bottom('/foo/bar/file.txt')  # Returns 'file.txt'\n"
		"path.bottom('/foo/bar/dir/')      # Returns 'dir'\n"
		"```\n");
}

Gura_ImplementFunction(bottom)
{
	String bottom;
	PathMgr::SplitBottom(arg.GetString(0), nullptr, &bottom);
	return Value(bottom);
}

// path.cutbottom(pathname:string):map
Gura_DeclareFunction(cutbottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a path name after eliminating its bottom part (cf. `path.dirname()`)."
		"This is complementary to `path.bottom()`.\n"
		"\n"
		"Example:\n"
		"```\n"
		"path.cutbottom('/foo/bar/file.txt')  # Returns '/foo/bar/'\n"
		"path.cutbottom('/foo/bar/dir/')      # Returns '/foo/bar/'\n"
		"```\n");
}

Gura_ImplementFunction(cutbottom)
{
	String top;
	PathMgr::SplitBottom(arg.GetString(0), &top, nullptr);
	return Value(top);
}

// path.dir(directory?:directory, pattern*:string):map:flat:[stat,file,dir,case,icase] {block?}
Gura_DeclareFunction(dir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "directory", VTYPE_directory, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stat));
	DeclareAttr(Gura_Symbol(file));
	DeclareAttr(Gura_Symbol(dir));
	DeclareAttr(Gura_Symbol(case_));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that lists item names in the specified directory.\n"
		"If pathname is omitted, the current directory shall be listed.\n"
		"\n"
		"Though the default sensitiveness of character cases during pattern matching depends on the target directory,\n"
		"it can be changed by attributes `:case` for case-sensitive and `:icase` for case-insensitive.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(dir)
{
	bool addSepFlag = true;
	bool statFlag = arg.IsSet(Gura_Symbol(stat));
	bool fileFlag = arg.IsSet(Gura_Symbol(file)) || !arg.IsSet(Gura_Symbol(dir));
	bool dirFlag = arg.IsSet(Gura_Symbol(dir)) || !arg.IsSet(Gura_Symbol(file));
	int depthMax = 0;
	StringList patterns;
	arg.GetList(1).ToStringList(patterns);
	AutoPtr<Directory> pDirectory;
	if (arg.Is_directory(0)) {
		pDirectory.reset(Directory::Reference(Object_directory::GetObject(arg, 0)->GetDirectory()));
	} else {
		pDirectory.reset(Directory::Open(env, "", PathMgr::NF_Signal));
		if (pDirectory.IsNull()) return Value::Nil;
	}
	bool ignoreCaseFlag = pDirectory->DoesIgnoreCase();
	if (arg.IsSet(Gura_Symbol(case_))) ignoreCaseFlag = false;
	if (arg.IsSet(Gura_Symbol(icase))) ignoreCaseFlag = true;
	Directory::Iterator_Walk *pIterator = new Directory::Iterator_Walk(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag,
					pDirectory.release(), depthMax, patterns);
	return ReturnIterator(env, arg, pIterator);
}

// path.dirname(pathname:string):map
Gura_DeclareFunction(dirname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), 
		"Splits a pathname by a directory separator and returns a directory name part (cf. `path.cutbottom()`)."
		"This is complementary to `path.filename()`.\n"
		"\n"
		"Example:\n"
		"```\n"
		"path.dirname('/foo/bar/file.txt')  # Returns '/foo/bar/'\n"
		"path.dirname('/foo/bar/dir/')      # Returns '/foo/bar/dir/'\n"
		"```\n");
}

Gura_ImplementFunction(dirname)
{
	String dirName;
	PathMgr::SplitFileName(arg.GetString(0), &dirName, nullptr);
	return Value(dirName);
}

// path.exists(pathname:string):map
Gura_DeclareFunction(exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Returns true if the specified file exists in a file system.");
}

Gura_ImplementFunction(exists)
{
	Signal &sig = env.GetSignal();
	bool existFlag = PathMgr::DoesExist(env, arg.GetString(0));
	if (sig.IsSignalled()) return Value::Nil;
	return Value(existFlag);
}

// path.extname(pathname:string):map
Gura_DeclareFunction(extname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), 
		"Extracts a suffix part of a path name. It returns an empty string when the given pathname has no suffix.\n"
		"This is complementary to `path.basename()`.\n"
		"\n"
		"Example:\n"
		"```\n"
		"path.extname('/foo/bar/file.txt')  # Returns 'txt'\n"
		"path.extname('/foo/bar/file')      # Returns ''\n"
		"```\n");
}

Gura_ImplementFunction(extname)
{
	const char *pathName = arg.GetString(0);
	const char *p = PathMgr::SeekExtName(pathName);
	return Value((*p == '.')? p + 1 : p);
}

// path.filename(pathname:string):map
Gura_DeclareFunction(filename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), 
		"Splits a pathname by a directory separator and returns a file name part (cf. `path.bottom()`).\n"
		"This is complementary to `path.dirname()`.\n"
		"\n"
		"Example:\n"
		"```\n"
		"path.filename('/foo/bar/file.txt')  # Returns 'file.txt'\n"
		"path.filename('/foo/bar/dir/')      # Returns ''\n"
		"```\n");
}

Gura_ImplementFunction(filename)
{
	String fileName;
	PathMgr::SplitFileName(arg.GetString(0), nullptr, &fileName);
	return Value(fileName);
}

// path.glob(pattern:string):map:flat:[stat,file,dir,case,icase] {block?}
Gura_DeclareFunction(glob)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "pattern", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stat));
	DeclareAttr(Gura_Symbol(file));
	DeclareAttr(Gura_Symbol(dir));
	DeclareAttr(Gura_Symbol(case_));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator for item names that match with a pattern supporting\n"
		"UNIX shell-style wild cards. In default, case of characters is distinguished.\n"
		"\n"
		"Though the default sensitiveness of character cases during pattern matching depends on the current platform,\n"
		"it can be changed by attributes `:case` for case-sensitive and `:icase` for case-insensitive.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(glob)
{
	bool addSepFlag = true;
	bool statFlag = arg.IsSet(Gura_Symbol(stat));
	bool ignoreCaseFlag = OAL::IgnoreCaseInPathNameFlag;
	bool fileFlag = arg.IsSet(Gura_Symbol(file)) || !arg.IsSet(Gura_Symbol(dir));
	bool dirFlag = arg.IsSet(Gura_Symbol(dir)) || !arg.IsSet(Gura_Symbol(file));
	if (arg.IsSet(Gura_Symbol(case_))) ignoreCaseFlag = false;
	if (arg.IsSet(Gura_Symbol(icase))) ignoreCaseFlag = true;
	AutoPtr<Directory::Iterator_Glob> pIterator(new Directory::Iterator_Glob(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag));
	if (!pIterator->Init(env, arg.GetString(0))) {
		return Value::Nil;
	}
	return ReturnIterator(env, arg, pIterator.release());
}

// path.join(paths+:string):map:[uri]
Gura_DeclareFunction(join)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "paths", VTYPE_string, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(uri));
	AddHelp(
		Gura_Symbol(en),
		"Returns a path name that joins given strings with directory separators.");
}

Gura_ImplementFunction(join)
{
	String str;
	const ValueList &valList = arg.GetList(0);
	char chSeparator = arg.IsSet(Gura_Symbol(uri))? '/' : OAL::FileSeparator;
	foreach_const (ValueList, pValue, valList) {
		str = OAL::JoinPathName(chSeparator, str.c_str(), pValue->GetString());
	}
	return Value(str);
}

// path.match(pattern:string, name:string):map:[case,icase]
Gura_DeclareFunction(match)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string);
	DeclareArg(env, "name", VTYPE_string);
	DeclareAttr(Gura_Symbol(case_));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(
		Gura_Symbol(en), 
		"Returns true if a name matches with a pattern that supports UNIX shell-style wild cards.\n"
		"\n"
		"Though the default sensitiveness of character cases depends on the current platform,\n"
		"it can be changed by attributes `:case` for case-sensitive and `:icase` for case-insensitive.\n");
}

Gura_ImplementFunction(match)
{
	const char *pattern = arg.GetString(0);
	const char *name = arg.GetString(1);
	bool ignoreCaseFlag = OAL::IgnoreCaseInPathNameFlag;
	if (arg.IsSet(Gura_Symbol(case_))) ignoreCaseFlag = false;
	if (arg.IsSet(Gura_Symbol(icase))) ignoreCaseFlag = true;
	return Value(PathMgr::DoesMatchName(pattern, name, ignoreCaseFlag));
}

// path.regulate(name:string):map:[uri]
Gura_DeclareFunction(regulate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string);
	DeclareAttr(Gura_Symbol(uri));
	AddHelp(
		Gura_Symbol(en),
		"Removes redundant relative directories.");
}

Gura_ImplementFunction(regulate)
{
	char chSeparator = arg.IsSet(Gura_Symbol(uri))? '/' : OAL::FileSeparator;
	bool cutLastSepFlag = false;
	return Value(OAL::RegulatePathName(chSeparator, arg.GetString(0), cutLastSepFlag));
}

// path.split(pathname:string):map:[bottom]
Gura_DeclareFunction(split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareAttr(Gura_Symbol(bottom));
	AddHelp(
		Gura_Symbol(en), 
		"Splits a pathname by a directory separator and returns a list containing\n"
		"a directory name as the first element and a base name as the second one.\n"
		"\n"
		"Calling this function has the same result as calling `path.dirname()` and `path.filename()`.\n"
		"\n"
		"Calling this function with `:bottom` attribute has the same result as calling\n"
		"`path.cutbottom()` and `path.bottom()`.\n"
		"\n"
		"Example:\n"
		"```\n"
		"path.split('/foo/bar/file.txt')         # Returns ['/foo/bar/', 'file.txt']\n"
		"path.split('/foo/bar/dir/')             # Returns ['/foo/bar/dir/', '']\n"
		"\n"
		"path.split('/foo/bar/file.txt'):bottom  # Returns ['/foo/bar/', 'file.txt']\n"
		"path.split('/foo/bar/dir/'):bottom      # Returns ['/foo/bar/', 'dir']\n"
		"```\n");
}

Gura_ImplementFunction(split)
{
	String first, second;
	if (arg.IsSet(Gura_Symbol(bottom))) {
		PathMgr::SplitBottom(arg.GetString(0), &first, &second);
	} else {
		PathMgr::SplitFileName(arg.GetString(0), &first, &second);
	}
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	pObjList->Add(Value(first));
	pObjList->Add(Value(second));
	return result;
}

// path.splitext(pathname:string):map
Gura_DeclareFunction(splitext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), 
		"Splits a pathname by a dot character indicating a beginning of an extension\n"
		"and returns a list containing a path name without an extention\n"
		"and an extention part.");
}

Gura_ImplementFunction(splitext)
{
	const char *pathName = arg.GetString(0);
	const char *p = PathMgr::SeekExtName(pathName);
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	size_t lenLeft = p - pathName;
	pObjList->Add(Value(pathName, lenLeft));
	pObjList->Add(Value((*p == '.')? p + 1 : p));
	return result;
}

// path.stat(directory:directory):map
Gura_DeclareFunction(stat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "directory", VTYPE_directory);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a stat object associated with the specified item.");
}

Gura_ImplementFunction(stat)
{
	Signal &sig = env.GetSignal();
	Directory *pDirectory = Object_directory::GetObject(arg, 0)->GetDirectory();
	AutoPtr<Object> pObj(pDirectory->GetStatObj(sig));
	if (sig.IsSignalled()) return Value::Nil;
	return Value(pObj.release());
}

// path.walk(directory?:directory, maxdepth?:number, pattern*:string):map:flat:[stat,file,dir,case,icase] {block?}
Gura_DeclareFunction(walk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "directory", VTYPE_directory, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxdepth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stat));
	DeclareAttr(Gura_Symbol(file));
	DeclareAttr(Gura_Symbol(dir));
	DeclareAttr(Gura_Symbol(case_));
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(
		Gura_Symbol(en), 
		"Creates an iterator that recursively lists item names under the specified directory.\n"
		"If `directory` is omitted, search starts at the current directory.\n"
		"\n"
		"Though the default sensitiveness of character cases during pattern matching depends on the target directory,\n"
		"it can be changed by attributes `:case` for case-sensitive and `:icase` for case-insensitive.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(walk)
{
	bool addSepFlag = true;
	bool statFlag = arg.IsSet(Gura_Symbol(stat));
	bool fileFlag = arg.IsSet(Gura_Symbol(file)) || !arg.IsSet(Gura_Symbol(dir));
	bool dirFlag = arg.IsSet(Gura_Symbol(dir)) || !arg.IsSet(Gura_Symbol(file));
	int depthMax = arg.Is_number(1)? arg.GetInt(1) : -1;
	StringList patterns;
	arg.GetList(2).ToStringList(patterns);
	AutoPtr<Directory> pDirectory;
	if (arg.Is_directory(0)) {
		pDirectory.reset(Directory::Reference(Object_directory::GetObject(arg, 0)->GetDirectory()));
	} else {
		pDirectory.reset(Directory::Open(env, "", PathMgr::NF_Signal));
		if (pDirectory.IsNull()) return Value::Nil;
	}
	bool ignoreCaseFlag = pDirectory->DoesIgnoreCase();
	if (arg.IsSet(Gura_Symbol(case_))) ignoreCaseFlag = false;
	if (arg.IsSet(Gura_Symbol(icase))) ignoreCaseFlag = true;
	Directory::Iterator_Walk *pIterator = new Directory::Iterator_Walk(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag,
					pDirectory.release(), depthMax, patterns);
	return ReturnIterator(env, arg, pIterator);
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
	do {
		char str[2];
		str[0] = OAL::FileSeparator;
		str[1] = '\0';
		Gura_AssignValue(sep_file, Value(str));
	} while (0);
	// function assignment
	Gura_AssignFunction(absname);
	Gura_AssignFunction(basename);
	Gura_AssignFunction(bottom);
	Gura_AssignFunction(cutbottom);
	Gura_AssignFunction(dir);
	Gura_AssignFunction(dirname);
	Gura_AssignFunction(exists);
	Gura_AssignFunction(extname);
	Gura_AssignFunction(filename);
	Gura_AssignFunction(glob);
	Gura_AssignFunction(join);
	Gura_AssignFunction(match);
	Gura_AssignFunction(regulate);
	Gura_AssignFunction(split);
	Gura_AssignFunction(splitext);
	Gura_AssignFunction(stat);
	Gura_AssignFunction(walk);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(path, path)

Gura_RegisterModule(path)
