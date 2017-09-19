//-----------------------------------------------------------------------------
// Gura module: fs
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(fs)

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
Gura_DeclarePrivUserSymbol(follow_link);

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

String Object_Stat::ToString(bool exprFlag)
{
	return String("<fs.stat>");
}

// fs.stat(pathname:string) {block?}
Gura_DeclareFunction(stat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pathname", VTYPE_string, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(Stat));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementFunction(stat)
{
	Signal &sig = env.GetSignal();
	const char *pathName = arg.GetString(0);
	std::unique_ptr<OAL::FileStat> pFileStat(OAL::FileStat::Generate(sig, pathName));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_Stat(*pFileStat)));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// fs.Stat#atime
Gura_DeclareProperty_R(Stat, atime)
{
	SetPropAttr(VTYPE_datetime);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, atime)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(new Object_datetime(env, fileStat.GetATime()));
}

// fs.Stat#ctime
Gura_DeclareProperty_R(Stat, ctime)
{
	SetPropAttr(VTYPE_datetime);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, ctime)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(new Object_datetime(env, fileStat.GetCTime()));
}

// fs.Stat#dirname
Gura_DeclareProperty_R(Stat, dirname)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, dirname)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	String dirName;
	PathMgr::SplitFileName(fileStat.GetPathName(), &dirName, nullptr);
	return Value(dirName);
}

// fs.Stat#filename
Gura_DeclareProperty_R(Stat, filename)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, filename)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	String fileName;
	PathMgr::SplitFileName(fileStat.GetPathName(), nullptr, &fileName);
	return Value(fileName);
}

// fs.Stat#gid
Gura_DeclareProperty_R(Stat, gid)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, gid)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(static_cast<Number>(fileStat.GetGid()));
}

// fs.Stat#isblk
Gura_DeclareProperty_R(Stat, isblk)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, isblk)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(fileStat.IsBlk());
}

// fs.Stat#ischr
Gura_DeclareProperty_R(Stat, ischr)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, ischr)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(fileStat.IsChr());
}

// fs.Stat#isdir
Gura_DeclareProperty_R(Stat, isdir)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, isdir)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(fileStat.IsDir());
}

// fs.Stat#isfifo
Gura_DeclareProperty_R(Stat, isfifo)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, isfifo)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(fileStat.IsFifo());
}

// fs.Stat#islnk
Gura_DeclareProperty_R(Stat, islnk)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, islnk)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(fileStat.IsLnk());
}

// fs.Stat#isreg
Gura_DeclareProperty_R(Stat, isreg)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, isreg)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(fileStat.IsReg());
}

// fs.Stat#issock
Gura_DeclareProperty_R(Stat, issock)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, issock)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(fileStat.IsSock());
}

// fs.Stat#mtime
Gura_DeclareProperty_R(Stat, mtime)
{
	SetPropAttr(VTYPE_datetime);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, mtime)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(new Object_datetime(env, fileStat.GetMTime()));
}

// fs.Stat#pathname
Gura_DeclareProperty_R(Stat, pathname)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, pathname)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(fileStat.GetPathName());
}

// fs.Stat#size
Gura_DeclareProperty_R(Stat, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, size)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(static_cast<Number>(fileStat.GetSize()));
}

// fs.Stat#uid
Gura_DeclareProperty_R(Stat, uid)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Stat, uid)
{
	const OAL::FileStat &fileStat = Object_Stat::GetObject(valueThis)->GetFileStat();
	return Value(static_cast<Number>(fileStat.GetUid()));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_Stat
//-----------------------------------------------------------------------------
// implementation of class Stat
Gura_ImplementUserClass(Stat)
{
	// Assignment of properties
	Gura_AssignProperty(Stat, atime);
	Gura_AssignProperty(Stat, ctime);
	Gura_AssignProperty(Stat, dirname);
	Gura_AssignProperty(Stat, filename);
	Gura_AssignProperty(Stat, gid);
	Gura_AssignProperty(Stat, isblk);
	Gura_AssignProperty(Stat, ischr);
	Gura_AssignProperty(Stat, isdir);
	Gura_AssignProperty(Stat, isfifo);
	Gura_AssignProperty(Stat, islnk);
	Gura_AssignProperty(Stat, isreg);
	Gura_AssignProperty(Stat, issock);
	Gura_AssignProperty(Stat, mtime);
	Gura_AssignProperty(Stat, pathname);
	Gura_AssignProperty(Stat, size);
	Gura_AssignProperty(Stat, uid);
	// Assignment of function
	Gura_AssignFunction(stat);
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
	std::unique_ptr<OAL::FileStat> pFileStat(
					OAL::FileStat::Generate(_sig, _fileName.c_str()));
	if (pFileStat.get() == nullptr) return false;
	attr.atime = pFileStat->GetATime();
	attr.mtime = pFileStat->GetMTime();
	attr.ctime = pFileStat->GetCTime();
	attr.uid = pFileStat->GetUid();
	attr.gid = pFileStat->GetGid();
	attr.attr = attr.attrMask = pFileStat->GetMode();
	return true;
}

#if defined(GURA_ON_MSWIN)
Stream_File::Stream_File(Environment &env) :
	Stream(env, ATTR_BwdSeekable), _hFile(INVALID_HANDLE_VALUE), _needCloseFlag(false)
{
	_map.hFileMappingObject = nullptr;
	_map.buff = nullptr;
	_map.bytes = 0;
	_map.offset = 0;
}

bool Stream_File::Open(Signal &sig, const char *fileName, UInt32 attr)
{
	Close();
	_attr |= attr;
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
					nullptr, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (_hFile == INVALID_HANDLE_VALUE) {
		sig.SetError(ERR_IOError, "can't open file '%s'", fileName);
		return false;
	}
	if (IsAppend()) {
		::SetFilePointer(_hFile, 0, nullptr, FILE_END);
	}
	_map.hFileMappingObject = nullptr;
	_map.buff = nullptr;
	_map.bytes = 0;
	_map.offset = 0;
	_needCloseFlag = true;
	if (dwDesiredAccess == GENERIC_READ) {
		_map.hFileMappingObject =
				::CreateFileMapping(_hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
		if (_map.hFileMappingObject == nullptr) {
			// it seems to open an empty file
			return true;
		}
		_map.buff = reinterpret_cast<UChar *>(
				::MapViewOfFile(_map.hFileMappingObject, FILE_MAP_READ, 0, 0, 0));
		_map.bytes = ::GetFileSize(_hFile, nullptr);
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
		SetCodec(Codec::CreateCodec(_sig, OAL::GetEncodingForConsole(), true, true));
	}
	_blockingFlag = true;
	return true;
}

bool Stream_File::OpenStdout()
{
	Close();
	_hFile = ::GetStdHandle(STD_OUTPUT_HANDLE);
	if (_hFile != INVALID_HANDLE_VALUE) {
		_fileName = "stdout", SetReadable(false), SetWritable(true);
		SetCodec(Codec::CreateCodec(_sig, OAL::GetEncodingForConsole(), true, true));
	}
	return true;
}

bool Stream_File::OpenStderr()
{
	Close();
	_hFile = ::GetStdHandle(STD_ERROR_HANDLE);
	if (_hFile != INVALID_HANDLE_VALUE) {
		_fileName = "stderr", SetReadable(false), SetWritable(true);
		SetCodec(Codec::CreateCodec(_sig, OAL::GetEncodingForConsole(), true, true));
	}
	return true;
}

bool Stream_File::SetAttribute(const Attribute &attr)
{
	HANDLE hFileDst = ::CreateFile(_fileName.c_str(),
			GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (hFileDst == INVALID_HANDLE_VALUE) return false;
	FILETIME ftCreate = OAL::ToFILETIME(attr.ctime);
	FILETIME ftAccess = OAL::ToFILETIME(attr.atime);
	FILETIME ftWrite = OAL::ToFILETIME(attr.mtime);
	::SetFileTime(hFileDst, &ftCreate, &ftAccess, &ftWrite);
	::CloseHandle(hFileDst);
	return true;
}

size_t Stream_File::DoRead(Signal &sig, void *buff, size_t bytes)
{
	if (_map.hFileMappingObject == nullptr) {
		DWORD dwBytesRead;
		::ReadFile(_hFile, buff, static_cast<DWORD>(bytes), &dwBytesRead, nullptr);
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

size_t Stream_File::DoWrite(Signal &sig, const void *buff, size_t bytes)
{
	DWORD dwBytesWritten;
	::WriteFile(_hFile, buff, static_cast<DWORD>(bytes), &dwBytesWritten, nullptr);
	return static_cast<size_t>(dwBytesWritten);
}

bool Stream_File::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	if (_hFile == INVALID_HANDLE_VALUE) return true;
	if (_map.hFileMappingObject == nullptr) {
		DWORD dwMoveMethod =
			(seekMode == SeekSet)? FILE_BEGIN :
			(seekMode == SeekCur)? FILE_CURRENT : FILE_BEGIN;
		DWORD dwPtr = ::SetFilePointer(_hFile, offset, nullptr, dwMoveMethod);
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

bool Stream_File::DoFlush(Signal &sig)
{
	::FlushFileBuffers(_hFile);
	return true;
}

bool Stream_File::DoClose(Signal &sig)
{
	if (!_needCloseFlag) return true;
	if (_hFile != INVALID_HANDLE_VALUE) {
		if (_map.hFileMappingObject != nullptr) {
			::UnmapViewOfFile(_map.buff);
			::CloseHandle(_map.hFileMappingObject);
			_map.hFileMappingObject = nullptr;
			_map.buff = nullptr;
		}
		::CloseHandle(_hFile);
		_hFile = INVALID_HANDLE_VALUE;
		_needCloseFlag = false;
		
	}
	return Stream::DoClose(sig);
}

size_t Stream_File::DoGetSize()
{
	if (_hFile == INVALID_HANDLE_VALUE) return 0;
	DWORD rtn = ::GetFileSize(_hFile, nullptr);
	if (rtn == 0xffffffff) return InvalidSize;
	return static_cast<size_t>(rtn);
}

Object *Stream_File::DoGetStatObj(Signal &sig)
{
	BY_HANDLE_FILE_INFORMATION attrData;
	String pathName = OAL::MakeAbsPathName(OAL::FileSeparator, _fileName.c_str());
	if (::GetFileInformationByHandle(_hFile, &attrData) == 0) {
		sig.SetError(ERR_IOError, "failed to get file status of %s", pathName.c_str());
		return nullptr;
	}
	return new Object_Stat(OAL::FileStat(pathName.c_str(), attrData));
}

#else // !defined(GURA_ON_MSWIN)
Stream_File::Stream_File(Environment &env) :
		Stream(env, ATTR_BwdSeekable), _fp(nullptr), _needCloseFlag(false)
{
}

bool Stream_File::Open(Signal &sig, const char *fileName, UInt32 attr)
{
	Close();
	_attr |= attr;
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
	if (_fp == nullptr) {
		sig.SetError(ERR_IOError, "can't open file '%s'", fileName);
		return false;
	}
	_needCloseFlag = true;
	return true;
}

bool Stream_File::OpenStdin()
{
	_fp = stdin;
	_fileName = "stdin", SetReadable(true), SetWritable(false);
	SetCodec(Codec::CreateCodec(_sig, OAL::GetEncodingForConsole(), true, false));
	_blockingFlag = true;
	return true;
}

bool Stream_File::OpenStdout()
{
	_fp = stdout;
	_fileName = "stdout", SetReadable(false), SetWritable(true);
	SetCodec(Codec::CreateCodec(_sig, OAL::GetEncodingForConsole(), true, false));
	return true;
}

bool Stream_File::OpenStderr()
{
	_fp = stderr;
	_fileName = "stderr", SetReadable(false), SetWritable(true);
	SetCodec(Codec::CreateCodec(_sig, OAL::GetEncodingForConsole(), true, false));
	return true;
}

bool Stream_File::SetAttribute(const Attribute &attr)
{
	return false;
}

size_t Stream_File::DoRead(Signal &sig, void *buff, size_t bytes)
{
	return ::fread(buff, 1, bytes, _fp);
}

size_t Stream_File::DoWrite(Signal &sig, const void *buff, size_t bytes)
{
	return ::fwrite(buff, 1, bytes, _fp);
}

bool Stream_File::DoFlush(Signal &sig)
{
	::fflush(_fp);
	return true;
}

bool Stream_File::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	if (_fp == nullptr) return true;
	int origin =
		(seekMode == SeekSet)? SEEK_SET :
		(seekMode == SeekCur)? SEEK_CUR : SEEK_SET;
	if (::fseek(_fp, offset, origin) != 0) {
		sig.SetError(ERR_IOError, "seek error");
		return false;
	}
	return true;
}

bool Stream_File::DoClose(Signal &sig)
{
	if (!_needCloseFlag) return true;
	if (_fp != nullptr) {
		::fclose(_fp);
		_fp = nullptr;
		_needCloseFlag = false;
	}
	return Stream::DoClose(sig);
}

size_t Stream_File::DoGetSize()
{
	if (_fp == nullptr) return 0;
	struct stat stat;
	if (::fstat(fileno(_fp), &stat) != 0) return InvalidSize;
	return static_cast<size_t>(stat.st_size);
}

Object *Stream_File::DoGetStatObj(Signal &sig)
{
	struct stat stat;
	String pathName = OAL::MakeAbsPathName(OAL::FileSeparator, _fileName.c_str());
	if (::fstat(fileno(_fp), &stat) != 0) {
		sig.SetError(ERR_IOError, "failed to get file status of %s", pathName.c_str());
		return nullptr;
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

Directory *Directory_FileSys::DoNext(Environment &env)
{
	WIN32_FIND_DATA findData;
	if (_hFind == INVALID_HANDLE_VALUE) {
		String pathName(MakePathName(false));
		if (!pathName.empty()) pathName += GetSeparator();
		pathName += "*.*";
		_hFind = ::FindFirstFile(OAL::ToNativeString(pathName.c_str()).c_str(), &findData);
		if (_hFind == INVALID_HANDLE_VALUE) return nullptr;
	} else if (!::FindNextFile(_hFind, &findData)) {
		::FindClose(_hFind);
		_hFind = INVALID_HANDLE_VALUE;
		return nullptr;
	}
	while (::strcmp(findData.cFileName, ".") == 0 ||
			::strcmp(findData.cFileName, "..") == 0) {
		if (!::FindNextFile(_hFind, &findData)) {
			::FindClose(_hFind);
			_hFind = INVALID_HANDLE_VALUE;
			return nullptr;
		}
	}
	Type type = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)?
												TYPE_Container : TYPE_Item;
	String fileName = OAL::FromNativeString(findData.cFileName);
	return new Directory_FileSys(Directory::Reference(this), fileName.c_str(),
							type, new OAL::FileStat(fileName.c_str(), findData));
}

bool Directory_FileSys::IsExist(Signal &sig, const char *pathName)
{
	WIN32_FILE_ATTRIBUTE_DATA attrData;
	return ::GetFileAttributesEx(OAL::ToNativeString(pathName).c_str(),
										GetFileExInfoStandard, &attrData) != 0;
}

bool Directory_FileSys::IsDir(Signal &sig, const char *pathName)
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
	_pDir(nullptr), _pFileStat(pFileStat)
{
}

Directory_FileSys::~Directory_FileSys()
{
	if (_pDir != nullptr) closedir(_pDir);
}

Directory *Directory_FileSys::DoNext(Environment &env)
{
	if (_pDir == nullptr) {
		String pathName(MakePathName(false));
		String pathNameEnc = OAL::ToNativeString(pathName.c_str());
		_pDir = opendir(pathNameEnc.empty()? "." : pathNameEnc.c_str());
		if (_pDir == nullptr) return nullptr;
	}
	struct dirent *pEnt = nullptr;
	for (;;) {
		pEnt = readdir(_pDir);
		if (pEnt == nullptr) {
			closedir(_pDir);
			_pDir = nullptr;
			return nullptr;
		}
		if (::strcmp(pEnt->d_name, ".") != 0 &&
			::strcmp(pEnt->d_name, "..") != 0) break;
	}
	Type type = (pEnt->d_type == DT_DIR)? TYPE_Container : TYPE_Item;
	return new Directory_FileSys(Directory::Reference(this),
					OAL::FromNativeString(pEnt->d_name).c_str(), type, nullptr);
}

bool Directory_FileSys::IsExist(Signal &sig, const char *pathName)
{
	struct stat stat;
	return ::stat(OAL::ToNativeString(pathName).c_str(), &stat) == 0;
}

bool Directory_FileSys::IsDir(Signal &sig, const char *pathName)
{
	struct stat stat;
	return ::stat(OAL::ToNativeString(pathName).c_str(), &stat) == 0 && S_ISDIR(stat.st_mode);
}

#endif

Object *Directory_FileSys::DoGetStatObj(Signal &sig)
{
	if (_pFileStat.get() == nullptr) {
		OAL::FileStat *pFileStat =
				OAL::FileStat::Generate(sig, MakePathName(false).c_str());
		if (sig.IsSignalled()) return nullptr;
		_pFileStat.reset(pFileStat);
	}
	return new Object_Stat(*_pFileStat);
}

Stream *Directory_FileSys::DoOpenStream(Environment &env, UInt32 attr)
{
	Signal &sig = env.GetSignal();
	Stream_File *pStream = new Stream_File(env);
	if (!pStream->Open(sig, MakePathName(false).c_str(), attr)) {
		return nullptr;
	}
	return pStream;
}

//-----------------------------------------------------------------------------
// PathMgr_FileSys implementation
//-----------------------------------------------------------------------------
bool PathMgr_FileSys::IsResponsible(Environment &env,
								const Directory *pParent, const char *pathName)
{
	if (pParent != nullptr) return false;
	
	return true;
}

Directory *PathMgr_FileSys::DoOpenDirectory(Environment &env,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode)
{
	Signal &sig = env.GetSignal();
	Directory *pDirectory = nullptr;
	String field;
	String pathAccum;
	const char *p = *pPathName;
	if (IsFileSeparator(*p)) {
		pathAccum += OAL::FileSeparator;
		p++;
		Directory::Type type = Directory::TYPE_RootContainer;
		pDirectory = new Directory_FileSys(
						Directory::Reference(pParent), "", type, nullptr);
		pParent = pDirectory;
	}
	for ( ; ; p++) {
		char ch = *p;
		if (IsFileSeparator(ch) || ch == '\0') {
			pathAccum += field;
			Directory::Type type = Directory::TYPE_Container;
			if (!pathAccum.empty()) {
				bool existFlag = Directory_FileSys::IsExist(sig, pathAccum.c_str());
				if (sig.IsSignalled()) return nullptr;
				if (existFlag) {
					type = Directory_FileSys::IsDir(sig, pathAccum.c_str())?
								Directory::TYPE_Container : Directory::TYPE_Item;
					if (sig.IsSignalled()) return nullptr;
				} else if (notFoundMode == NF_Wouldbe) {
					type = IsFileSeparator(ch)?
								Directory::TYPE_Container : Directory::TYPE_Item;
				} else if (notFoundMode == NF_Signal) {
					sig.SetError(ERR_IOError, "path not exist '%s'", pathAccum.c_str());
					return nullptr;
				} else {
					return nullptr;
				}
			}
			pDirectory = new Directory_FileSys(
					Directory::Reference(pParent), field.c_str(), type, nullptr);
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
// fs.chdir(pathname:string) {block?}
Gura_DeclareFunction(chdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Changes the current working directory to `pathname`.\n"
		"\n"
		"The block would be evaluated if specified, and the working directory would be changed\n"
		"only during that evaluation period.\n");
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(chdir)
{
	Signal &sig = env.GetSignal();
	if (arg.IsBlockSpecified()) {
		String pathNameOrg = OAL::GetCurDir();
		if (!OAL::ChangeCurDir(arg.GetString(0))) {
			sig.SetError(ERR_IOError, "failed to change current directory");
			return Value::Nil;
		}
		const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
		if (sig.IsSignalled()) return Value::Nil;
		Value rtn = pExprBlock->Exec(env);
		OAL::ChangeCurDir(pathNameOrg.c_str());
		return rtn;
	} else if (!OAL::ChangeCurDir(arg.GetString(0))) {
		sig.SetError(ERR_IOError, "failed to change current directory");
		return Value::Nil;
	}
	return Value::Nil;
}

// fs.chmod(mode, pathname:string):map:void:[follow_link]
Gura_DeclareFunction(chmod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_any);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareAttr(Gura_UserSymbol(follow_link));
	AddHelp(
		Gura_Symbol(en),
		"Changes the access mode of a file specified by `pathname`.\n"
		"\n"
		"There are two formats to specify the mode: one is by a number, and another in a string.\n"
		"\n"
		"When specified in a number, following bits are associated with access permissions:\n"
		"\n"
		"- `b8 b7 b6` .. Read, write and executable permissions for owners\n"
		"- `b5 b4 b3` .. Read, write and executable permissions for groups\n"
		"- `b2 b1 b0` .. Read, write and executable permissions for others\n"
		"\n"
		"When set to one, each permission is validated.\n"
		"\n"
		"When specified in a string, it accepts a permission directive\n"
		"in a format of following regular expression\n"
		"    [ugoa]+([-+=][rwx]+)+\n"
		"It starts with characters that represent target which permissions are modified as described below:\n"
		"\n"
		"- `u` .. owners\n"
		"- `g` .. groups\n"
		"- `o` .. others\n"
		"- `a` .. all users\n"
		"\n"
		"Then, follows an operation:\n"
		"- `-` .. remove\n"
		"- `+` .. append\n"
		"- `=` .. set\n"
		"\n"
		"At last, permission attributes are specified as below:\n"
		"\n"
		"- `r` .. read permission\n"
		"- `w` .. write permission\n"
		"- `x` .. executable permission\n"
		"\n"
		"If the modification target is a link file, each platform would have different result:\n"
		"\n"
		"- Linux .. Modifies permissions of the link file itself.\n"
		"           Specifying `:follow_link` attribute would modify permsisions of the target file\n instead.\n"
		"- MacOS .. Modifies permissions of the target file. Attribute `:follow_link` has no effect.\n"
		"- Windows .. Modifies permissions of the link file. Attribute `:follow_link` has no effect.\n");
}

Gura_ImplementFunction(chmod)
{
	Signal &sig = env.GetSignal();
	bool rtn = false;
	bool followLinkFlag = arg.IsSet(Gura_UserSymbol(follow_link));
	if (arg.Is_string(0)) {
		rtn = OAL::ChangeMode(arg.GetString(0), arg.GetString(1), followLinkFlag);
	} else if (arg.Is_number(0)) {
		rtn = OAL::ChangeMode(arg.GetInt(0), arg.GetString(1), followLinkFlag);
	} else {
		sig.SetError(ERR_ValueError, "number or string must be specified as mode");
		return Value::Nil;
	}
	if (!rtn) {
		sig.SetError(ERR_IOError, "failed to change access mode");
	}
	return Value::Nil;
}

// fs.copy(src:string, dst:string):map:void:[overwrite]
Gura_DeclareFunction(copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "src", VTYPE_string);
	DeclareArg(env, "dst", VTYPE_string);
	DeclareAttr(Gura_Symbol(overwrite));
	//DeclareAttr(Gura_Symbol(follow_link));
	AddHelp(
		Gura_Symbol(en),
		"Copies a file.\n"
		"\n"
		"An argument `src` needs to specify a path name of a file that is to be copied\n"
		"while `dst` can specify a path name of either a file or a directory.\n"
		"If `dst` is a directory, the file would be copied into that.\n"
		"Otherwise, it would create a copy of `src` that has a name specified by `dst`.\n"
		"\n"
		"If a destination file already exists, an error occurs.\n"
		"Specifying an attribute `:overwrite` would overwrite an existing one.\n");
}

Gura_ImplementFunction(copy)
{
	Signal &sig = env.GetSignal();
	bool failIfExistsFlag = !arg.IsSet(Gura_Symbol(overwrite));
	bool followLinkFlag = arg.IsSet(Gura_UserSymbol(follow_link));
	if (!OAL::Copy(arg.GetString(0), arg.GetString(1), failIfExistsFlag, followLinkFlag)) {
		sig.SetError(ERR_IOError, "failed to copy a file %s", arg.GetString(0));
	}
	return Value::Nil;
}

// fs.cpdir(src:string, dst:string):map:void[:tree]
Gura_DeclareFunction(cpdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "src", VTYPE_string);
	DeclareArg(env, "dst", VTYPE_string);
	DeclareAttr(Gura_UserSymbol(tree));
	AddHelp(
		Gura_Symbol(en),
		"Copies a directory.\n"
		"\n"
		"Arguments `src` and `dst` specify source directory and destination directory respectively.\n"
		"In default, sub directories are not copied.`\n"
		"Specifying `:tree` attribute would copy all the sub directories in the source.\n");
}

Gura_ImplementFunction(cpdir)
{
	Signal &sig = env.GetSignal();
	const char *dirNameSrc = arg.GetString(0);
	const char *dirNameDst = arg.GetString(1);
	bool rtn = arg.IsSet(Gura_UserSymbol(tree))?
				OAL::CopyDirTree(dirNameSrc, dirNameDst) :
				OAL::CopyDir(dirNameSrc, dirNameDst);
	if (!rtn) {
		sig.SetError(ERR_IOError, "failed to copies a directory '%s' to '%s'",
													dirNameSrc, dirNameDst);
	}
	return Value::Nil;
}

// fs.getcwd()
Gura_DeclareFunction(getcwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the current working directory.");
}

Gura_ImplementFunction(getcwd)
{
	String pathName = OAL::GetCurDir();
	return Value(pathName);
}

// fs.mkdir(pathname:string):map:void[:tree]
Gura_DeclareFunction(mkdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareAttr(Gura_UserSymbol(tree));
	AddHelp(
		Gura_Symbol(en),
		"Creates a directory.\n"
		"\n"
		"If `pathname` consists of multiple sub directories and some of them still doesn't exist,\n"
		"an error occurs. Specifying `:tree` attribute would create such directories.\n");
}

Gura_ImplementFunction(mkdir)
{
	Signal &sig = env.GetSignal();
	const char *pathName = arg.GetString(0);
	bool rtn = arg.IsSet(Gura_UserSymbol(tree))?
				OAL::MakeDirTree(pathName) :
				OAL::MakeDir(pathName);
	if (!rtn) {
		sig.SetError(ERR_IOError, "failed to create a directory %s", pathName);
	}
	return Value::Nil;
}

// fs.remove(pathname:string):map:void
Gura_DeclareFunction(remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Removes a file from the file system.");
}

Gura_ImplementFunction(remove)
{
	Signal &sig = env.GetSignal();
	if (!OAL::Remove(arg.GetString(0))) {
		sig.SetError(ERR_IOError, "failed to remove a file");
	}
	return Value::Nil;
}

// fs.rename(src:string, dst:string):map:void
Gura_DeclareFunction(rename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "src", VTYPE_string);
	DeclareArg(env, "dst", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Renames a file or directory.");
}

Gura_ImplementFunction(rename)
{
	Signal &sig = env.GetSignal();
	if (!OAL::Rename(arg.GetString(0), arg.GetString(1))) {
		sig.SetError(ERR_IOError, "failed to rename a file or directory");
	}
	return Value::Nil;
}

// fs.rmdir(pathname:string):map:void[:tree]
Gura_DeclareFunction(rmdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareAttr(Gura_UserSymbol(tree));
	AddHelp(
		Gura_Symbol(en),
		"Removes a directory.\n"
		"\n"
		"If the directory contains sub directories, an error occurs.\n"
		"Specifying `:tree` attribute would delete such a directory.\n");
}

Gura_ImplementFunction(rmdir)
{
	Signal &sig = env.GetSignal();
	const char *pathName = arg.GetString(0);
	bool rtn = arg.IsSet(Gura_UserSymbol(tree))?
				OAL::RemoveDirTree(pathName) :
				OAL::RemoveDir(pathName);
	if (!rtn) {
		sig.SetError(ERR_IOError, "failed to remove a directory %s", pathName);
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
	Gura_RealizeUserSymbol(follow_link);
	// class realization
	Gura_RealizeAndPrepareUserClassAlias(Stat, "stat", env.LookupClass(VTYPE_object));
	// symbol realization
	PathMgr::Register(env, new PathMgr_FileSys());
	// assign symbols in sys module
	Module *pModuleSys = env.GetGlobal()->GetModule_sys();
	do {
		Stream_File *pStream = new Stream_File(env);
		pStream->OpenStdin();
		pModuleSys->AssignValue(Gura_Symbol(stdin),
					Value(new Object_stream(env, pStream)), EXTRA_Public);
	} while (0);
	do {
		Stream_File *pStream = new Stream_File(env);
		pStream->OpenStdout();
		pModuleSys->AssignValue(Gura_Symbol(stdout),
					Value(new Object_stream(env, pStream)), EXTRA_Public);
	} while (0);
	do {
		Stream_File *pStream = new Stream_File(env);
		pStream->OpenStderr();
		pModuleSys->AssignValue(Gura_Symbol(stderr),
					Value(new Object_stream(env, pStream)), EXTRA_Public);
	} while (0);
	// function assignment
	Gura_AssignFunction(chdir);
	Gura_AssignFunction(chmod);
	Gura_AssignFunction(copy);
	Gura_AssignFunction(cpdir);
	Gura_AssignFunction(getcwd);
	Gura_AssignFunction(mkdir);
	Gura_AssignFunction(remove);
	Gura_AssignFunction(rename);
	Gura_AssignFunction(rmdir);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(fs, fs)

Gura_RegisterModule(fs)
