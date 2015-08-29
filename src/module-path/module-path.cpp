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
		Gura_Symbol(en), Help::FMT_markdown,
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
		Gura_Symbol(en), Help::FMT_markdown, 
		"Removes a suffix part of a path name.");
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
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns the last part of a path name.");
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
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a path name after eliminating its bottom part.");
}

Gura_ImplementFunction(cutbottom)
{
	String top;
	PathMgr::SplitBottom(arg.GetString(0), &top, nullptr);
	return Value(top);
}

// path.dir(directory?:directory, pattern*:string):map:flat:[stat,file,dir] {block?}
Gura_DeclareFunction(dir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "directory", VTYPE_directory, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stat));
	DeclareAttr(Gura_Symbol(file));
	DeclareAttr(Gura_Symbol(dir));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Creates an iterator that lists item names in the specified directory.\n"
		"If pathname is omitted, the current directory shall be listed.\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(dir)
{
	Signal &sig = env.GetSignal();
	bool addSepFlag = true;
	bool statFlag = arg.IsSet(Gura_Symbol(stat));
	bool ignoreCaseFlag = OAL::IgnoreCaseInPathNameFlag;
	bool fileFlag = arg.IsSet(Gura_Symbol(file)) || !arg.IsSet(Gura_Symbol(dir));
	bool dirFlag = arg.IsSet(Gura_Symbol(dir)) || !arg.IsSet(Gura_Symbol(file));
	int depthMax = 0;
	StringList patterns;
	if (!arg.GetList(1).ToStringList(sig, patterns)) return Value::Nil;
	AutoPtr<Directory> pDirectory;
	if (arg.Is_directory(0)) {
		pDirectory.reset(Directory::Reference(Object_directory::GetObject(arg, 0)->GetDirectory()));
	} else {
		pDirectory.reset(Directory::Open(env, "", PathMgr::NF_Signal));
		if (pDirectory.IsNull()) return Value::Nil;
	}
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
		Gura_Symbol(en), Help::FMT_markdown, 
		"Splits a pathname by a directory separator and returns a directory name part.");
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
		Gura_Symbol(en), Help::FMT_markdown,
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
		Gura_Symbol(en), Help::FMT_markdown, 
		"Extracts a suffix part of a path name.");
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
		Gura_Symbol(en), Help::FMT_markdown, 
		"Splits a pathname by a directory separator and returns a file name part.");
}

Gura_ImplementFunction(filename)
{
	String fileName;
	PathMgr::SplitFileName(arg.GetString(0), nullptr, &fileName);
	return Value(fileName);
}

// path.glob(pattern:string):map:flat:[stat,file,dir] {block?}
Gura_DeclareFunction(glob)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "pattern", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stat));
	DeclareAttr(Gura_Symbol(file));
	DeclareAttr(Gura_Symbol(dir));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Creates an iterator for item names that match with a pattern supporting\n"
		"UNIX shell-style wild cards. In default, case of characters is distinguished.\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(glob)
{
	bool addSepFlag = true;
	bool statFlag = arg.IsSet(Gura_Symbol(stat));
	bool ignoreCaseFlag = OAL::IgnoreCaseInPathNameFlag;
	bool fileFlag = arg.IsSet(Gura_Symbol(file)) || !arg.IsSet(Gura_Symbol(dir));
	bool dirFlag = arg.IsSet(Gura_Symbol(dir)) || !arg.IsSet(Gura_Symbol(file));
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
		Gura_Symbol(en), Help::FMT_markdown,
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

// path.match(pattern:string, name:string):map
Gura_DeclareFunction(match)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string);
	DeclareArg(env, "name", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns true if a name matches with a pattern that supports UNIX\n"
		"shell-style wild cards. In default, case of characters is distinguished.");
}

Gura_ImplementFunction(match)
{
	const char *pattern = arg.GetString(0);
	const char *name = arg.GetString(1);
	bool ignoreCaseFlag = OAL::IgnoreCaseInPathNameFlag;
	return Value(PathMgr::DoesMatchName(pattern, name, ignoreCaseFlag));
}

// path.regulate(name:string):map:[uri]
Gura_DeclareFunction(regulate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string);
	DeclareAttr(Gura_Symbol(uri));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a regulated path name of the given name.");
}

Gura_ImplementFunction(regulate)
{
	char chSeparator = arg.IsSet(Gura_Symbol(uri))? '/' : OAL::FileSeparator;
	bool cutLastSepFlag = false;
	return Value(OAL::RegulatePathName(chSeparator,
								arg.GetString(0), cutLastSepFlag));
}

// path.split(pathname:string):map:[bottom]
Gura_DeclareFunction(split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareAttr(Gura_Symbol(bottom));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Splits a pathname by a directory separator and returns a list containing\n"
		"a directory name as the first element and a base name as the second one.\n"
		"This has the same result as calling path.dirname() and path.filename().");
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
	ValueList &valList = result.InitAsList(env);
	valList.push_back(Value(first));
	valList.push_back(Value(second));
	return result;
}

// path.splitext(pathname:string):map
Gura_DeclareFunction(splitext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Splits a pathname by a dot character indicating a beginning of an extension\n"
		"and returns a list containing a path name without an extention\n"
		"and an extention part.");
}

Gura_ImplementFunction(splitext)
{
	const char *pathName = arg.GetString(0);
	const char *p = PathMgr::SeekExtName(pathName);
	Value result;
	ValueList &valList = result.InitAsList(env);
	size_t lenLeft = p - pathName;
	valList.push_back(Value(pathName, lenLeft));
	valList.push_back(Value((*p == '.')? p + 1 : p));
	return result;
}

// path.stat(directory:directory):map
Gura_DeclareFunction(stat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "directory", VTYPE_directory);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
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

// path.walk(directory?:directory, maxdepth?:number, pattern*:string):map:flat:[stat,file,dir] {block?}
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Creates an iterator that recursively lists item names under the specified\n"
		"directory. If pathname is omitted, search starts at the current directory\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementFunction(walk)
{
	Signal &sig = env.GetSignal();
	bool addSepFlag = true;
	bool statFlag = arg.IsSet(Gura_Symbol(stat));
	bool ignoreCaseFlag = OAL::IgnoreCaseInPathNameFlag;
	bool fileFlag = arg.IsSet(Gura_Symbol(file)) || !arg.IsSet(Gura_Symbol(dir));
	bool dirFlag = arg.IsSet(Gura_Symbol(dir)) || !arg.IsSet(Gura_Symbol(file));
	int depthMax = arg.Is_number(1)? arg.GetInt(1) : -1;
	StringList patterns;
	if (!arg.GetList(2).ToStringList(sig, patterns)) return Value::Nil;
	AutoPtr<Directory> pDirectory;
	if (arg.Is_directory(0)) {
		pDirectory.reset(Directory::Reference(Object_directory::GetObject(arg, 0)->GetDirectory()));
	} else {
		pDirectory.reset(Directory::Open(env, "", PathMgr::NF_Signal));
		if (pDirectory.IsNull()) return Value::Nil;
	}
	Directory::Iterator_Walk *pIterator = new Directory::Iterator_Walk(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag,
					pDirectory.release(), depthMax, patterns);
	return ReturnIterator(env, arg, pIterator);
}

// Module entry
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
