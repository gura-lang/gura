//-----------------------------------------------------------------------------
// Gura fs module
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "Module_fs.h"

Gura_BeginModule(fs)

Gura_DeclarePrivUserSymbol(pathname);
Gura_DeclarePrivUserSymbol(dirname);
Gura_DeclarePrivUserSymbol(filename);
Gura_DeclarePrivUserSymbol(size);
Gura_DeclarePrivUserSymbol(uid);
Gura_DeclarePrivUserSymbol(gid);
Gura_DeclarePrivUserSymbol(atime);
Gura_DeclarePrivUserSymbol(mtime);
Gura_DeclarePrivUserSymbol(ctime);
Gura_DeclarePrivUserSymbol(isdir);
Gura_DeclarePrivUserSymbol(ischr);
Gura_DeclarePrivUserSymbol(isblk);
Gura_DeclarePrivUserSymbol(isreg);
Gura_DeclarePrivUserSymbol(isfifo);
Gura_DeclarePrivUserSymbol(islnk);
Gura_DeclarePrivUserSymbol(issock);
Gura_DeclarePrivUserSymbol(tree);

//-----------------------------------------------------------------------------
// Object_Stat implementation
//-----------------------------------------------------------------------------
Object_Stat::~Object_Stat()
{
}

Object *Object_Stat::Clone() const
{
	return new Object_Stat(*this);
}

bool Object_Stat::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(pathname));
	symbols.insert(Gura_UserSymbol(dirname));
	symbols.insert(Gura_UserSymbol(filename));
	symbols.insert(Gura_UserSymbol(size));
	symbols.insert(Gura_UserSymbol(uid));
	symbols.insert(Gura_UserSymbol(gid));
	symbols.insert(Gura_UserSymbol(atime));
	symbols.insert(Gura_UserSymbol(mtime));
	symbols.insert(Gura_UserSymbol(ctime));
	symbols.insert(Gura_UserSymbol(isdir));
	symbols.insert(Gura_UserSymbol(ischr));
	symbols.insert(Gura_UserSymbol(isblk));
	symbols.insert(Gura_UserSymbol(isreg));
	symbols.insert(Gura_UserSymbol(isfifo));
	symbols.insert(Gura_UserSymbol(islnk));
	symbols.insert(Gura_UserSymbol(issock));
	return true;
}

Value Object_Stat::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(pathname))) {
		return Value(env, _fileStat.GetPathName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(dirname))) {
		String dirName;
		Directory::SplitFileName(_fileStat.GetPathName(), &dirName, NULL);
		return Value(env, dirName.c_str());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(filename))) {
		String fileName;
		Directory::SplitFileName(_fileStat.GetPathName(), NULL, &fileName);
		return Value(env, fileName.c_str());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(size))) {
		return Value(static_cast<Number>(_fileStat.GetSize()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(uid))) {
		return Value(static_cast<Number>(_fileStat.GetUid()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(gid))) {
		return Value(static_cast<Number>(_fileStat.GetGid()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(atime))) {
		return Value(new Object_datetime(env, _fileStat.GetATime()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mtime))) {
		return Value(new Object_datetime(env, _fileStat.GetMTime()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ctime))) {
		return Value(new Object_datetime(env, _fileStat.GetCTime()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(isdir))) {
		return Value(_fileStat.IsDir());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ischr))) {
		return Value(_fileStat.IsChr());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(isblk))) {
		return Value(_fileStat.IsBlk());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(isreg))) {
		return Value(_fileStat.IsReg());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(isfifo))) {
		return Value(_fileStat.IsFifo());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(islnk))) {
		return Value(_fileStat.IsLnk());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(issock))) {
		return Value(_fileStat.IsSock());
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_Stat::ToString(Signal sig, bool exprFlag)
{
	return String("<fs.stat>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Stat
//-----------------------------------------------------------------------------
// implementation of class Stat
Gura_ImplementUserClass(Stat)
{
}

//-----------------------------------------------------------------------------
// Stream_File implementation
//-----------------------------------------------------------------------------
Stream_File::~Stream_File()
{
	Close();
}

const char *Stream_File::GetName() const
{
	return _fileName.c_str();
}

const char *Stream_File::GetIdentifier() const
{
	return _fileName.c_str();
}

bool Stream_File::GetAttribute(Attribute &attr)
{
	std::auto_ptr<OAL::FileStat> pFileStat(
					OAL::FileStat::Generate(_sig, _fileName.c_str()));
	if (pFileStat.get() == NULL) return false;
	attr.atime = pFileStat->GetATime();
	attr.mtime = pFileStat->GetMTime();
	attr.ctime = pFileStat->GetCTime();
	attr.attr = attr.attrMask = pFileStat->GetMode();
	return true;
}

#if defined(GURA_ON_MSWIN)
Stream_File::Stream_File(Signal sig) : Stream(sig, ATTR_BwdSeekable), _hFile(INVALID_HANDLE_VALUE), _needCloseFlag(false)
{
}

bool Stream_File::Open(Signal sig, const char *fileName,
								unsigned long attr, const char *encoding)
{
	Close();
	_attr |= attr;
	if (!InstallCodec(encoding, true)) {
		sig.SetError(ERR_CodecError, "unsupported encoding '%s'", encoding);
		return false;
	}
	_fileName = OAL::MakeAbsPathName(OAL::FileSeparator, fileName);
	DWORD dwDesiredAccess =
			IsAppend()? GENERIC_WRITE :
			IsReadable()? GENERIC_READ :
			IsWritable()? GENERIC_WRITE :
			GENERIC_READ;
	DWORD dwShareMode = FILE_SHARE_READ;
	DWORD dwCreationDisposition =
			IsAppend()? OPEN_ALWAYS :
			IsReadable()? OPEN_EXISTING :
			IsWritable()? CREATE_ALWAYS :
			OPEN_EXISTING;
	_hFile = ::CreateFile(OAL::ToNativeString(_fileName.c_str()).c_str(),
					dwDesiredAccess, dwShareMode,
					NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);
	if (_hFile == INVALID_HANDLE_VALUE) {
		String fileNameBase;
		Directory::SplitFileName(fileName, NULL, &fileNameBase);
		sig.SetError(ERR_IOError, "can't open file '%s'", fileNameBase.c_str());
		return false;
	}
	if (IsAppend()) {
		::SetFilePointer(_hFile, 0, NULL, FILE_END);
	}
	_map.hFileMappingObject = NULL;
	_map.buff = NULL;
	_map.bytes = 0;
	_map.offset = 0;
	_needCloseFlag = true;
	if (dwDesiredAccess == GENERIC_READ) {
		_map.hFileMappingObject =
				::CreateFileMapping(_hFile, NULL, PAGE_READONLY, 0, 0, NULL);
		if (_map.hFileMappingObject == NULL) {
			// it seems to open an empty file
			return true;
		}
		_map.buff = reinterpret_cast<unsigned char *>(
				::MapViewOfFile(_map.hFileMappingObject, FILE_MAP_READ, 0, 0, 0));
		_map.bytes = ::GetFileSize(_hFile, NULL);
		_map.offset = 0;
	}
	return true;
}

bool Stream_File::OpenStdin()
{
	Close();
	_hFile = ::GetStdHandle(STD_INPUT_HANDLE);
	if (_hFile != INVALID_HANDLE_VALUE) {
		_fileName = "stdin", SetReadable(true), SetWritable(false);
		InstallCodec("cp932", true);
	}
	return true;
}

bool Stream_File::OpenStdout()
{
	Close();
	_hFile = ::GetStdHandle(STD_OUTPUT_HANDLE);
	if (_hFile != INVALID_HANDLE_VALUE) {
		_fileName = "stdout", SetReadable(false), SetWritable(true);
		InstallCodec("cp932", true);
	}
	return true;
}

bool Stream_File::OpenStderr()
{
	Close();
	_hFile = ::GetStdHandle(STD_ERROR_HANDLE);
	if (_hFile != INVALID_HANDLE_VALUE) {
		_fileName = "stderr", SetReadable(false), SetWritable(true);
		InstallCodec("cp932", true);
	}
	return true;
}

bool Stream_File::SetAttribute(const Attribute &attr)
{
	HANDLE hFileDst = ::CreateFile(_fileName.c_str(),
			GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFileDst == INVALID_HANDLE_VALUE) return false;
	FILETIME ftCreate = OAL::ToFILETIME(attr.ctime);
	FILETIME ftAccess = OAL::ToFILETIME(attr.atime);
	FILETIME ftWrite = OAL::ToFILETIME(attr.mtime);
	::SetFileTime(hFileDst, &ftCreate, &ftAccess, &ftWrite);
	::CloseHandle(hFileDst);
	return true;
}

size_t Stream_File::DoRead(Signal sig, void *buff, size_t bytes)
{
	if (_map.hFileMappingObject == NULL) {
		DWORD dwBytesRead;
		::ReadFile(_hFile, buff, static_cast<DWORD>(bytes), &dwBytesRead, NULL);
		return static_cast<size_t>(dwBytesRead);
	} else {
		size_t bytesRead = bytes;
		if (_map.offset >= _map.bytes) {
			return 0;
		} else if (_map.offset + bytesRead > _map.bytes) {
			bytesRead = _map.bytes - _map.offset;
		}
		::memcpy(buff, _map.buff + _map.offset, bytesRead);
		_map.offset += bytesRead;
		return bytesRead;
	}
}

size_t Stream_File::DoWrite(Signal sig, const void *buff, size_t bytes)
{
	DWORD dwBytesWritten;
	::WriteFile(_hFile, buff, static_cast<DWORD>(bytes), &dwBytesWritten, NULL);
	return static_cast<size_t>(dwBytesWritten);
}

bool Stream_File::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	if (_hFile == INVALID_HANDLE_VALUE) return true;
	if (_map.hFileMappingObject == NULL) {
		DWORD dwMoveMethod =
			(seekMode == SeekSet)? FILE_BEGIN :
			(seekMode == SeekCur)? FILE_CURRENT : FILE_BEGIN;
		DWORD dwPtr = ::SetFilePointer(_hFile, offset, NULL, dwMoveMethod);
		if (dwPtr == INVALID_SET_FILE_POINTER) {
			sig.SetError(ERR_IOError, "seek error");
			return false;
		}
	} else {
		if (seekMode == SeekSet) {
			_map.offset = static_cast<size_t>(offset);
		} else if (seekMode == SeekCur) {
			if (offset < 0 && _map.offset < static_cast<size_t>(-offset)) {
				sig.SetError(ERR_IOError, "seek error");
				return false;
			}
			_map.offset = static_cast<size_t>(_map.offset + offset);
		}
		if (_map.offset > _map.bytes) {
			sig.SetError(ERR_IOError, "seek error");
			return false;
		}
	}
	return true;
}

bool Stream_File::DoFlush(Signal sig)
{
	::FlushFileBuffers(_hFile);
	return true;
}

bool Stream_File::DoClose(Signal sig)
{
	if (_needCloseFlag && _hFile != INVALID_HANDLE_VALUE) {
		if (_map.hFileMappingObject != NULL) {
			::UnmapViewOfFile(_map.buff);
			::CloseHandle(_map.hFileMappingObject);
			_map.hFileMappingObject = NULL;
			_map.buff = NULL;
		}
		::CloseHandle(_hFile);
		_hFile = INVALID_HANDLE_VALUE;
		_needCloseFlag = false;
		ReleaseCodec();
	}
	return true;
}

size_t Stream_File::DoGetSize()
{
	if (_hFile == INVALID_HANDLE_VALUE) return 0;
	DWORD rtn = ::GetFileSize(_hFile, NULL);
	if (rtn == 0xffffffff) return InvalidSize;
	return static_cast<size_t>(rtn);
}

Object *Stream_File::DoGetStatObj(Signal sig)
{
	BY_HANDLE_FILE_INFORMATION attrData;
	String pathName = OAL::MakeAbsPathName(OAL::FileSeparator, _fileName.c_str());
	if (::GetFileInformationByHandle(_hFile, &attrData) == 0) {
		sig.SetError(ERR_IOError, "failed to get file status of %s", pathName.c_str());
		return NULL;
	}
	return new Object_Stat(OAL::FileStat(pathName.c_str(), attrData));
}

#else // !defined(GURA_ON_MSWIN)
Stream_File::Stream_File(Signal sig) : Stream(sig, ATTR_BwdSeekable), _fp(NULL), _needCloseFlag(false)
{
}

bool Stream_File::Open(Signal sig, const char *fileName,
								unsigned long attr, const char *encoding)
{
	Close();
	_attr |= attr;
	if (!InstallCodec(encoding, false)) {
		sig.SetError(ERR_CodecError, "unsupported encoding '%s'", encoding);
		return false;
	}
	_fileName = OAL::MakeAbsPathName(OAL::FileSeparator, fileName);
	char modeMod[8];
	if (IsAppend()) {
		modeMod[0] = 'a';
	} else if (IsReadable()) {
		modeMod[0] = 'r';
	} else if (IsWritable()) {
		modeMod[0] = 'w';
	} else {
		modeMod[0] = 'r';
	}
	modeMod[1] = '\0';
	_fp = ::fopen(OAL::ToNativeString(_fileName.c_str()).c_str(), modeMod);
	if (_fp == NULL) {
		String fileNameBase;
		Directory::SplitFileName(fileName, NULL, &fileNameBase);
		sig.SetError(ERR_IOError, "can't open file '%s'", fileNameBase.c_str());
		return false;
	}
	_needCloseFlag = true;
	return true;
}

bool Stream_File::OpenStdin()
{
	_fp = stdin;
	_fileName = "stdin", SetReadable(true), SetWritable(false);
	InstallCodec(Codec::EncodingFromLANG(), false);
	return true;
}

bool Stream_File::OpenStdout()
{
	_fp = stdout;
	_fileName = "stdout", SetReadable(false), SetWritable(true);
	InstallCodec(Codec::EncodingFromLANG(), false);
	return true;
}

bool Stream_File::OpenStderr()
{
	_fp = stderr;
	_fileName = "stderr", SetReadable(false), SetWritable(true);
	InstallCodec(Codec::EncodingFromLANG(), false);
	return true;
}

bool Stream_File::SetAttribute(const Attribute &attr)
{
	return false;
}

size_t Stream_File::DoRead(Signal sig, void *buff, size_t bytes)
{
	return ::fread(buff, 1, bytes, _fp);
}

size_t Stream_File::DoWrite(Signal sig, const void *buff, size_t bytes)
{
	return ::fwrite(buff, 1, bytes, _fp);
}

bool Stream_File::DoFlush(Signal sig)
{
	::fflush(_fp);
	return true;
}

bool Stream_File::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	if (_fp == NULL) return true;
	int origin =
		(seekMode == SeekSet)? SEEK_SET :
		(seekMode == SeekCur)? SEEK_CUR : SEEK_SET;
	if (::fseek(_fp, offset, origin) != 0) {
		sig.SetError(ERR_IOError, "seek error");
		return false;
	}
	return true;
}

bool Stream_File::DoClose(Signal sig)
{
	if (_needCloseFlag && _fp != NULL) {
		::fclose(_fp);
		_fp = NULL;
		_needCloseFlag = false;
		ReleaseCodec();
	}
	return true;
}

size_t Stream_File::DoGetSize()
{
	if (_fp == NULL) return 0;
	struct stat stat;
	if (::fstat(fileno(_fp), &stat) != 0) return InvalidSize;
	return static_cast<size_t>(stat.st_size);
}

Object *Stream_File::DoGetStatObj(Signal sig)
{
	unsigned long attr = 0;
	struct stat stat;
	String pathName = OAL::MakeAbsPathName(OAL::FileSeparator, _fileName.c_str());
	if (::fstat(fileno(_fp), &stat) != 0) {
		sig.SetError(ERR_IOError, "failed to get file status of %s", pathName.c_str());
		return NULL;
	}
	return new Object_Stat(OAL::FileStat(pathName.c_str(), stat));
}

#endif

//-----------------------------------------------------------------------------
// Directory_FileSys implementation
//-----------------------------------------------------------------------------
#if defined(GURA_ON_MSWIN)
Directory_FileSys::Directory_FileSys(Directory *pParent, const char *name,
										Type type, OAL::FileStat *pFileStat) :
	Directory(pParent, name, type, OAL::FileSeparator),
	_hFind(INVALID_HANDLE_VALUE), _pFileStat(pFileStat)
{
}

Directory_FileSys::~Directory_FileSys()
{
	::FindClose(_hFind);
}

Directory *Directory_FileSys::DoNext(Environment &env, Signal sig)
{
	WIN32_FIND_DATA findData;
	if (_hFind == INVALID_HANDLE_VALUE) {
		String pathName(MakePathName(false));
		if (!pathName.empty()) pathName += GetSeparator();
		pathName += "*.*";
		_hFind = ::FindFirstFile(OAL::ToNativeString(pathName.c_str()).c_str(), &findData);
		if (_hFind == INVALID_HANDLE_VALUE) return NULL;
	} else if (!::FindNextFile(_hFind, &findData)) {
		::FindClose(_hFind);
		_hFind = INVALID_HANDLE_VALUE;
		return NULL;
	}
	while (::strcmp(findData.cFileName, ".") == 0 ||
			::strcmp(findData.cFileName, "..") == 0) {
		if (!::FindNextFile(_hFind, &findData)) {
			::FindClose(_hFind);
			_hFind = INVALID_HANDLE_VALUE;
			return NULL;
		}
	}
	Type type = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)?
												TYPE_Container : TYPE_Item;
	String fileName = OAL::FromNativeString(findData.cFileName);
	return new Directory_FileSys(Directory::Reference(this), fileName.c_str(),
							type, new OAL::FileStat(fileName.c_str(), findData));
}

bool Directory_FileSys::IsExist(Signal sig, const char *pathName)
{
	WIN32_FILE_ATTRIBUTE_DATA attrData;
	return ::GetFileAttributesEx(OAL::ToNativeString(pathName).c_str(),
										GetFileExInfoStandard, &attrData) != 0;
}

bool Directory_FileSys::IsDir(Signal sig, const char *pathName)
{
	WIN32_FILE_ATTRIBUTE_DATA attrData;
	return ::GetFileAttributesEx(OAL::ToNativeString(pathName).c_str(),
									GetFileExInfoStandard, &attrData) != 0 &&
					(attrData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

#else

Directory_FileSys::Directory_FileSys(Directory *pParent, const char *name,
												Type type, OAL::FileStat *pFileStat) :
	Directory(pParent, name, type, OAL::FileSeparator),
	_pDir(NULL), _pFileStat(pFileStat)
{
}

Directory_FileSys::~Directory_FileSys()
{
	if (_pDir != NULL) closedir(_pDir);
}

Directory *Directory_FileSys::DoNext(Environment &env, Signal sig)
{
	if (_pDir == NULL) {
		String pathName(MakePathName(false));
		String pathNameEnc = OAL::ToNativeString(pathName.c_str());
		_pDir = opendir(pathNameEnc.empty()? "." : pathNameEnc.c_str());
		if (_pDir == NULL) return NULL;
	}
	struct dirent *pEnt = NULL;
	for (;;) {
		pEnt = readdir(_pDir);
		if (pEnt == NULL) {
			closedir(_pDir);
			_pDir = NULL;
			return NULL;
		}
		if (::strcmp(pEnt->d_name, ".") != 0 &&
			::strcmp(pEnt->d_name, "..") != 0) break;
	}
	Type type = (pEnt->d_type == DT_DIR)? TYPE_Container : TYPE_Item;
	return new Directory_FileSys(Directory::Reference(this),
					OAL::FromNativeString(pEnt->d_name).c_str(), type, NULL);
}

bool Directory_FileSys::IsExist(Signal sig, const char *pathName)
{
	struct stat stat;
	return ::stat(OAL::ToNativeString(pathName).c_str(), &stat) == 0;
}

bool Directory_FileSys::IsDir(Signal sig, const char *pathName)
{
	struct stat stat;
	return ::stat(OAL::ToNativeString(pathName).c_str(), &stat) == 0 && S_ISDIR(stat.st_mode);
}

#endif

Object *Directory_FileSys::DoGetStatObj(Signal sig)
{
	if (_pFileStat.get() == NULL) {
		OAL::FileStat *pFileStat =
				OAL::FileStat::Generate(sig, MakePathName(false).c_str());
		if (sig.IsSignalled()) return NULL;
		_pFileStat.reset(pFileStat);
	}
	return new Object_Stat(*_pFileStat);
}

Stream *Directory_FileSys::DoOpenStream(Environment &env, Signal sig,
										unsigned long attr, const char *encoding)
{
	Stream_File *pStream = new Stream_File(sig);
	if (!pStream->Open(sig, MakePathName(false).c_str(), attr, encoding)) {
		return NULL;
	}
	return pStream;
}

//-----------------------------------------------------------------------------
// DirectoryFactory_FileSys implementation
//-----------------------------------------------------------------------------
bool DirectoryFactory_FileSys::IsResponsible(Environment &env, Signal sig,
								const Directory *pParent, const char *pathName)
{
	if (pParent != NULL) return false;
	
	return true;
}

Directory *DirectoryFactory_FileSys::DoOpenDirectory(Environment &env, Signal sig,
	Directory *pParent, const char **pPathName, Directory::NotFoundMode notFoundMode)
{
	Directory *pDirectory = NULL;
	String field;
	String pathAccum;
	const char *p = *pPathName;
	if (IsFileSeparator(*p)) {
		pathAccum += OAL::FileSeparator;
		p++;
		Directory::Type type = Directory::TYPE_RootContainer;
		pDirectory = new Directory_FileSys(
						Directory::Reference(pParent), "", type, NULL);
		pParent = pDirectory;
	}
	for ( ; ; p++) {
		char ch = *p;
		if (IsFileSeparator(ch) || ch == '\0') {
			pathAccum += field;
			Directory::Type type = Directory::TYPE_Container;
			if (!pathAccum.empty()) {
				bool existFlag = Directory_FileSys::IsExist(sig, pathAccum.c_str());
				if (sig.IsSignalled()) return NULL;
				if (existFlag) {
					type = Directory_FileSys::IsDir(sig, pathAccum.c_str())?
								Directory::TYPE_Container : Directory::TYPE_Item;
					if (sig.IsSignalled()) return NULL;
				} else if (notFoundMode == Directory::NF_Wouldbe) {
					type = IsFileSeparator(ch)?
								Directory::TYPE_Container : Directory::TYPE_Item;
				} else if (notFoundMode == Directory::NF_Signal) {
					sig.SetError(ERR_IOError, "path not exist: %s", pathAccum.c_str());
					return NULL;
				} else {
					return NULL;
				}
			}
			pDirectory = new Directory_FileSys(
					Directory::Reference(pParent), field.c_str(), type, NULL);
			pParent = pDirectory;
			field.clear();
			if (type == Directory::TYPE_Item || ch == '\0') break;
			pathAccum += OAL::FileSeparator;
		} else {
			field += ch;
		}
	}
	*pPathName = p;
	return pDirectory;
}

//-----------------------------------------------------------------------------
// Gura module functions: fs
//-----------------------------------------------------------------------------
// fs.rename(src:string, dst:string):map:void
Gura_DeclareFunction(rename)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "src", VTYPE_string);
	DeclareArg(env, "dst", VTYPE_string);
	AddHelp(Gura_Symbol(en), "Renames a file or directory.");
}

Gura_ImplementFunction(rename)
{
	if (!OAL::Rename(args.GetString(0), args.GetString(1))) {
		sig.SetError(ERR_IOError, "failed to rename a file or directory");
	}
	return Value::Null;
}

// fs.remove(pathname:string):map:void
Gura_DeclareFunction(remove)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), "Removes a file from the file system.");
}

Gura_ImplementFunction(remove)
{
	if (!OAL::Remove(args.GetString(0))) {
		sig.SetError(ERR_IOError, "failed to remove a file");
	}
	return Value::Null;
}

// fs.mkdir(pathname:string):map:void[:tree]
Gura_DeclareFunction(mkdir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareAttr(Gura_UserSymbol(tree));
	AddHelp(Gura_Symbol(en), "Creates a directory.");
}

Gura_ImplementFunction(mkdir)
{
	const char *pathName = args.GetString(0);
	bool rtn = args.IsSet(Gura_UserSymbol(tree))?
				OAL::MakeDirTree(pathName) :
				OAL::MakeDir(pathName);
	if (!rtn) {
		sig.SetError(ERR_IOError, "failed to create a directory %s", pathName);
	}
	return Value::Null;
}

// fs.rmdir(pathname:string):map:void[:tree]
Gura_DeclareFunction(rmdir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareAttr(Gura_UserSymbol(tree));
	AddHelp(Gura_Symbol(en), "Removes a directory.");
}

Gura_ImplementFunction(rmdir)
{
	const char *pathName = args.GetString(0);
	bool rtn = args.IsSet(Gura_UserSymbol(tree))?
				OAL::RemoveDirTree(pathName) :
				OAL::RemoveDir(pathName);
	if (!rtn) {
		sig.SetError(ERR_IOError, "failed to remove a directory %s", pathName);
	}
	return Value::Null;
}

// fs.chdir(pathname:string) {block?}
Gura_DeclareFunction(chdir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), "Changes the current working directory.");
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(chdir)
{
	if (args.IsBlockSpecified()) {
		String pathNameOrg = OAL::GetCurDir();
		if (!OAL::ChangeCurDir(args.GetString(0))) {
			sig.SetError(ERR_IOError, "failed to change current directory");
			return Value::Null;
		}
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		Value rtn = pExprBlock->Exec(env, sig);
		OAL::ChangeCurDir(pathNameOrg.c_str());
		return rtn;
	} else if (!OAL::ChangeCurDir(args.GetString(0))) {
		sig.SetError(ERR_IOError, "failed to change current directory");
		return Value::Null;
	}
	return Value::Null;
}

// fs.getcwd()
Gura_DeclareFunction(getcwd)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Returns the current working directory.");
}

Gura_ImplementFunction(getcwd)
{
	String pathName = OAL::GetCurDir();
	return Value(env, pathName.c_str());
}

// fs.chmod(mode, pathname:string):map:void
Gura_DeclareFunction(chmod)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_any);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(Gura_Symbol(en), "Changes the access mode of a file.");
}

Gura_ImplementFunction(chmod)
{
	bool rtn = false;
	if (args.IsString(0)) {
		rtn = OAL::ChangeMode(args.GetString(0), args.GetString(1));
	} else if (args.IsNumber(0)) {
		rtn = OAL::ChangeMode(args.GetInt(0), args.GetString(1));
	} else {
		sig.SetError(ERR_ValueError, "number or string must be specified as mode");
		return Value::Null;
	}
	if (!rtn) {
		sig.SetError(ERR_IOError, "failed to change access mode");
	}
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(pathname);
	Gura_RealizeUserSymbol(dirname);
	Gura_RealizeUserSymbol(filename);
	Gura_RealizeUserSymbol(size);
	Gura_RealizeUserSymbol(uid);
	Gura_RealizeUserSymbol(gid);
	Gura_RealizeUserSymbol(atime);
	Gura_RealizeUserSymbol(mtime);
	Gura_RealizeUserSymbol(ctime);
	Gura_RealizeUserSymbol(isdir);
	Gura_RealizeUserSymbol(ischr);
	Gura_RealizeUserSymbol(isblk);
	Gura_RealizeUserSymbol(isreg);
	Gura_RealizeUserSymbol(isfifo);
	Gura_RealizeUserSymbol(islnk);
	Gura_RealizeUserSymbol(issock);
	Gura_RealizeUserSymbol(tree);
	// class realization
	Gura_RealizeUserClassEx(Stat, "stat", env.LookupClass(VTYPE_object));
	// symbol realization
	DirectoryFactory::Register(new DirectoryFactory_FileSys());
	// assign symbols in sys module
	Module *pModuleSys = env.GetModule_sys();
	do {
		Stream_File *pStream = new Stream_File(sig);
		pStream->OpenStdin();
		pModuleSys->AssignValue(Gura_Symbol(stdin),
							Value(new Object_stream(env, pStream)));
	} while (0);
	do {
		Stream_File *pStream = new Stream_File(sig);
		pStream->OpenStdout();
		pModuleSys->AssignValue(Gura_Symbol(stdout),
							Value(new Object_stream(env, pStream)));
	} while (0);
	do {
		Stream_File *pStream = new Stream_File(sig);
		pStream->OpenStderr();
		pModuleSys->AssignValue(Gura_Symbol(stderr),
							Value(new Object_stream(env, pStream)));
	} while (0);
	// function assignment
	Gura_AssignFunction(rename);
	Gura_AssignFunction(remove);
	Gura_AssignFunction(mkdir);
	Gura_AssignFunction(rmdir);
	Gura_AssignFunction(chdir);
	Gura_AssignFunction(getcwd);
	Gura_AssignFunction(chmod);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(fs, fs)

Gura_RegisterModule(fs)
