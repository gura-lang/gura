//-----------------------------------------------------------------------------
// Gura module: path
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(path)

//-----------------------------------------------------------------------------
// Gura module functions: path
//-----------------------------------------------------------------------------
// path.stat(directory:directory):map
Gura_DeclareFunction(stat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "directory", VTYPE_directory);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a stat object associated with the specified item.");
}

Gura_ImplementFunction(stat)
{
	Directory *pDirectory = args.GetDirectory(0);
	AutoPtr<Object> pObj(pDirectory->GetStatObj(sig));
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj.release());
}

// path.exists(pathname:string):map
Gura_DeclareFunction(exists)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns true if the specified file exists in a file system.");
}

Gura_ImplementFunction(exists)
{
	bool existFlag = PathManager::DoesExist(env, sig, args.GetString(0));
	if (sig.IsSignalled()) return Value::Null;
	return Value(existFlag);
}

// path.dir(directory?:directory, pattern*:string):map:flat:[stat,icase,file,dir] {block?}
Gura_DeclareFunction(dir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "directory", VTYPE_directory, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stat));
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_Symbol(file));
	DeclareAttr(Gura_Symbol(dir));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that lists item names in the specified directory.\n"
	"If pathname is omitted, the current directory shall be listed.\n"
	GURA_ITERATOR_HELP);
}

Gura_ImplementFunction(dir)
{
	bool addSepFlag = true;
	bool statFlag = args.IsSet(Gura_Symbol(stat));
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	bool fileFlag = args.IsSet(Gura_Symbol(file)) || !args.IsSet(Gura_Symbol(dir));
	bool dirFlag = args.IsSet(Gura_Symbol(dir)) || !args.IsSet(Gura_Symbol(file));
	int depthMax = 0;
	StringList patterns;
	if (!args.GetList(1).ToStringList(sig, patterns)) return Value::Null;
	AutoPtr<Directory> pDirectory;
	if (args.Is_directory(0)) {
		pDirectory.reset(Directory::Reference(args.GetDirectory(0)));
	} else {
		pDirectory.reset(Directory::Open(env, sig, "", PathManager::NF_Signal));
		if (pDirectory.IsNull()) return Value::Null;
	}
	Directory::Iterator_Walk *pIterator = new Directory::Iterator_Walk(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag,
					pDirectory.release(), depthMax, patterns);
	return ReturnIterator(env, sig, args, pIterator);
}

// path.walk(directory?:directory, maxdepth?:number, pattern*:string):map:flat:[stat,icase,file,dir] {block?}
Gura_DeclareFunction(walk)
{
	SetMode(RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "directory", VTYPE_directory, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxdepth", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stat));
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_Symbol(file));
	DeclareAttr(Gura_Symbol(dir));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator that recursively lists item names under the specified\n"
	"directory. If pathname is omitted, search starts at the current directory\n"
	GURA_ITERATOR_HELP);
}

Gura_ImplementFunction(walk)
{
	bool addSepFlag = true;
	bool statFlag = args.IsSet(Gura_Symbol(stat));
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	bool fileFlag = args.IsSet(Gura_Symbol(file)) || !args.IsSet(Gura_Symbol(dir));
	bool dirFlag = args.IsSet(Gura_Symbol(dir)) || !args.IsSet(Gura_Symbol(file));
	int depthMax = args.Is_number(1)? args.GetInt(1) : -1;
	StringList patterns;
	if (!args.GetList(2).ToStringList(sig, patterns)) return Value::Null;
	AutoPtr<Directory> pDirectory;
	if (args.Is_directory(0)) {
		pDirectory.reset(Directory::Reference(args.GetDirectory(0)));
	} else {
		pDirectory.reset(Directory::Open(env, sig, "", PathManager::NF_Signal));
		if (pDirectory.IsNull()) return Value::Null;
	}
	Directory::Iterator_Walk *pIterator = new Directory::Iterator_Walk(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag,
					pDirectory.release(), depthMax, patterns);
	return ReturnIterator(env, sig, args, pIterator);
}

// path.glob(pattern:string):map:flat:[stat,icase,file,dir] {block?}
Gura_DeclareFunction(glob)
{
	SetMode(RSLTMODE_Normal, FLAG_Map | FLAG_Flat);
	DeclareArg(env, "pattern", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(stat));
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_Symbol(file));
	DeclareAttr(Gura_Symbol(dir));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Creates an iterator for item names that match with a pattern supporting\n"
	"UNIX shell-style wild cards. In default, case of characters is distinguished.\n"
	"To ignore cases, specify :icase attribute.\n"
	GURA_ITERATOR_HELP);
}

Gura_ImplementFunction(glob)
{
	bool addSepFlag = true;
	bool statFlag = args.IsSet(Gura_Symbol(stat));
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	bool fileFlag = args.IsSet(Gura_Symbol(file)) || !args.IsSet(Gura_Symbol(dir));
	bool dirFlag = args.IsSet(Gura_Symbol(dir)) || !args.IsSet(Gura_Symbol(file));
	AutoPtr<Directory::Iterator_Glob> pIterator(new Directory::Iterator_Glob(
					addSepFlag, statFlag, ignoreCaseFlag, fileFlag, dirFlag));
	if (!pIterator->Init(env, sig, args.GetString(0))) {
		return Value::Null;
	}
	return ReturnIterator(env, sig, args, pIterator.release());
}

// path.match(pattern:string, name:string):map
Gura_DeclareFunction(match)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string);
	DeclareArg(env, "name", VTYPE_string);
	DeclareAttr(Gura_Symbol(icase));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns true if a name matches with a pattern that supports UNIX\n"
	"shell-style wild cards. In default, case of characters is distinguished.\n"
	"To ignore cases, specify :icase attribute.");
}

Gura_ImplementFunction(match)
{
	const char *pattern = args.GetString(0);
	const char *name = args.GetString(1);
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	return Value(PathManager::DoesMatchName(pattern, name, ignoreCaseFlag));
}

// path.split(pathname:string):map:[bottom]
Gura_DeclareFunction(split)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareAttr(Gura_Symbol(bottom));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Splits a pathname by a directory separator and returns a list containing\n"
	"a directory name as the first element and a base name as the second one.\n"
	"This has the same result as calling path.dirname() and path.filename().");
}

Gura_ImplementFunction(split)
{
	String first, second;
	if (args.IsSet(Gura_Symbol(bottom))) {
		PathManager::SplitBottom(args.GetString(0), &first, &second);
	} else {
		PathManager::SplitFileName(args.GetString(0), &first, &second);
	}
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.push_back(Value(first));
	valList.push_back(Value(second));
	return result;
}

// path.dirname(pathname:string):map
Gura_DeclareFunction(dirname)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Splits a pathname by a directory separator and returns a directory name part.");
}

Gura_ImplementFunction(dirname)
{
	String dirName;
	PathManager::SplitFileName(args.GetString(0), &dirName, NULL);
	return Value(dirName);
}

// path.filename(pathname:string):map
Gura_DeclareFunction(filename)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Splits a pathname by a directory separator and returns a file name part.");
}

Gura_ImplementFunction(filename)
{
	String fileName;
	PathManager::SplitFileName(args.GetString(0), NULL, &fileName);
	return Value(fileName);
}

// path.bottom(pathname:string):map
Gura_DeclareFunction(bottom)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns the last part of a path name.");
}

Gura_ImplementFunction(bottom)
{
	String bottom;
	PathManager::SplitBottom(args.GetString(0), NULL, &bottom);
	return Value(bottom);
}

// path.cutbottom(pathname:string):map
Gura_DeclareFunction(cutbottom)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a path name after eliminating its bottom part.");
}

Gura_ImplementFunction(cutbottom)
{
	String top;
	PathManager::SplitBottom(args.GetString(0), &top, NULL);
	return Value(top);
}

// path.absname(name:string):map:[uri]
Gura_DeclareFunction(absname)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string);
	DeclareAttr(Gura_Symbol(uri));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an absolute path name of the given name.");
}

Gura_ImplementFunction(absname)
{
	char chSeparator = args.IsSet(Gura_Symbol(uri))? '/' : OAL::FileSeparator;
	return Value(OAL::MakeAbsPathName(chSeparator, args.GetString(0)));
}

// path.regulate(name:string):map:[uri]
Gura_DeclareFunction(regulate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string);
	DeclareAttr(Gura_Symbol(uri));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a regulated path name of the given name.");
}

Gura_ImplementFunction(regulate)
{
	char chSeparator = args.IsSet(Gura_Symbol(uri))? '/' : OAL::FileSeparator;
	bool cutLastSepFlag = false;
	return Value(OAL::RegulatePathName(chSeparator,
								args.GetString(0), cutLastSepFlag));
}

// path.join(paths+:string):map:[uri]
Gura_DeclareFunction(join)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "paths", VTYPE_string, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(uri));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a path name that joins given strings with directory separators.");
}

Gura_ImplementFunction(join)
{
	String str;
	const ValueList &valList = args.GetList(0);
	char chSeparator = args.IsSet(Gura_Symbol(uri))? '/' : OAL::FileSeparator;
	foreach_const (ValueList, pValue, valList) {
		str = OAL::JoinPathName(chSeparator, str.c_str(), pValue->GetString());
	}
	return Value(str);
}

// path.splitext(pathname:string):map
Gura_DeclareFunction(splitext)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Splits a pathname by a dot character indicating a beginning of an extension\n"
	"and returns a list containing a path name without an extention\n"
	"and an extention part.");
}

Gura_ImplementFunction(splitext)
{
	const char *pathName = args.GetString(0);
	const char *p = PathManager::SeekExtName(pathName);
	Value result;
	ValueList &valList = result.InitAsList(env);
	size_t lenLeft = p - pathName;
	valList.push_back(Value(pathName, lenLeft));
	valList.push_back(Value((*p == '.')? p + 1 : p));
	return result;
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
	Gura_AssignFunction(stat);
	Gura_AssignFunction(exists);
	Gura_AssignFunction(dir);
	Gura_AssignFunction(walk);
	Gura_AssignFunction(glob);
	Gura_AssignFunction(match);
	Gura_AssignFunction(split);
	Gura_AssignFunction(dirname);
	Gura_AssignFunction(filename);
	Gura_AssignFunction(bottom);
	Gura_AssignFunction(cutbottom);
	Gura_AssignFunction(absname);
	Gura_AssignFunction(regulate);
	Gura_AssignFunction(join);
	Gura_AssignFunction(splitext);
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(path, path)

Gura_RegisterModule(path)
