//=============================================================================
// OAL: OS Abstraction Layer
//=============================================================================
#ifndef __GURA_OAL_H__
#define __GURA_OAL_H__
#include "Common.h"
#include "DateTime.h"
#include "Signal.h"

#if defined(GURA_ON_MSWIN)
#define snprintf _snprintf
#else
#include <semaphore.h>
#include <sys/types.h>
#include <dirent.h>
#endif

namespace Gura {

class Stream;
class StringList;
class ValueList;

namespace OAL {

//-----------------------------------------------------------------------------
// generic functions
//-----------------------------------------------------------------------------
GURA_DLLDECLARE extern const char FileSeparatorWin;
GURA_DLLDECLARE extern const char FileSeparatorUnix;
GURA_DLLDECLARE extern const char FileSeparator;

GURA_DLLDECLARE extern const bool IgnoreCaseInPathNameFlag;

GURA_DLLDECLARE bool IsAbsPathName(const char *pathName);
GURA_DLLDECLARE String MakeAbsPathName(char chSeparator, const char *fileName);
GURA_DLLDECLARE String RegulatePathName(char chSeparator, const char *pathName, bool cutLastSepFlag);
GURA_DLLDECLARE String JoinPathName(char chSeparator, const char *pathName, const char *name);
GURA_DLLDECLARE String JoinPathName(char chSeparator, const char *pathName, const char *name, size_t len);
GURA_DLLDECLARE String EliminateBottomDirName(const char *pathName);

inline String JoinPathName(const char *pathName, const char *name) {
	return JoinPathName(OAL::FileSeparator, pathName, name);
}

inline String JoinPathName(const char *pathName, const char *name, size_t len) {
	return JoinPathName(OAL::FileSeparator, pathName, name, len);
}

GURA_DLLDECLARE const char *EncodingForConsole();

GURA_DLLDECLARE int ExecProgram(Environment &env, Signal sig, const char *pathName,
		const ValueList &valList, Stream *pStreamStdout, Stream *pStreamStderr,
		bool forkFlag);
GURA_DLLDECLARE String GetEnv(const char *name);
GURA_DLLDECLARE void PutEnv(const char *name, const char *value);
GURA_DLLDECLARE bool Copy(const char *src, const char *dst, bool failIfExistsFlag);
GURA_DLLDECLARE bool Rename(const char *src, const char *dst);
GURA_DLLDECLARE bool Remove(const char *pathName);
GURA_DLLDECLARE bool DoesExist(const char *pathName);
GURA_DLLDECLARE bool IsDir(const char *pathName, bool *pExistFlag = NULL);
GURA_DLLDECLARE bool CopyDir(const char *dirNameSrc, const char *dirNameDst);
GURA_DLLDECLARE bool CopyDirTree(const char *dirNameSrc, const char *dirNameDst);
GURA_DLLDECLARE bool MakeDir(const char *pathName);
GURA_DLLDECLARE bool MakeDirTree(const char *pathName);
GURA_DLLDECLARE bool RemoveDir(const char *pathName);
GURA_DLLDECLARE bool RemoveDirTree(const char *pathName);
GURA_DLLDECLARE bool ChangeCurDir(const char *pathName);
GURA_DLLDECLARE String GetCurDir();
GURA_DLLDECLARE bool ChangeMode(int modeOct, const char *pathName);
GURA_DLLDECLARE bool ChangeMode(const char *mode, const char *pathName);
GURA_DLLDECLARE void Sleep(Number delay);
GURA_DLLDECLARE Number GetTickTime();
GURA_DLLDECLARE DateTime GetCurDateTime(bool utcFlag = false);
#if defined(GURA_ON_MSWIN)
GURA_DLLDECLARE void SetModuleHandle(HMODULE hModule);
GURA_DLLDECLARE DateTime ToDateTime(const SYSTEMTIME &st, int secsOffset);
GURA_DLLDECLARE DateTime ToDateTime(const FILETIME &ft, bool utcFlag = false);
GURA_DLLDECLARE SYSTEMTIME ToSYSTEMTIME(const DateTime &dt);
GURA_DLLDECLARE FILETIME ToFILETIME(const DateTime &dt);
static inline bool IsPathSeparator(char ch) { return ch == ';'; }
#else
GURA_DLLDECLARE DateTime ToDateTime(const struct tm &tm, int secsOffset);
GURA_DLLDECLARE DateTime ToDateTime(time_t t, bool utcFlag = false);
static inline bool IsPathSeparator(char ch) { return ch == ';' || ch == ':'; }
#endif
GURA_DLLDECLARE int GetSecsOffsetTZ();
GURA_DLLDECLARE String GetBaseDir();
GURA_DLLDECLARE String GetDataDir();
GURA_DLLDECLARE String GetModuleDir();
GURA_DLLDECLARE String GetIncludeDir();
GURA_DLLDECLARE String GetLocalDir();
GURA_DLLDECLARE String GetExecutable();
GURA_DLLDECLARE void SetupModulePath(StringList &strList);
GURA_DLLDECLARE void SetupExecutablePath();
GURA_DLLDECLARE String ToNativeString(const char *str, int len = -1);
GURA_DLLDECLARE String FromNativeString(const char *str, int len = -1);

//-----------------------------------------------------------------------------
// FileStat declaration
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE FileStat {
public:
	enum {
		ATTR_Dir	= (1 << 22),
		ATTR_Chr	= (1 << 21),
		ATTR_Blk	= (1 << 20),
		ATTR_Reg	= (1 << 19),
		ATTR_Fifo	= (1 << 18),
		ATTR_Lnk	= (1 << 17),
		ATTR_Sock	= (1 << 16),
	};
private:
	String _pathName;
	ULong _attr;
	ULong _bytes;
	DateTime _atime;
	DateTime _mtime;
	DateTime _ctime;
	long _uid;
	long _gid;
public:
	inline FileStat() : _attr(0), _bytes(0), _uid(0), _gid(0) {}
	inline FileStat(const char *pathName, ULong attr, ULong bytes,
				const DateTime &atime, const DateTime &mtime, const DateTime &ctime,
				long uid, long gid) :
		_pathName(pathName), _attr(attr), _bytes(bytes),
		_atime(atime), _mtime(mtime), _ctime(ctime),
		_uid(uid), _gid(gid) {}
	inline FileStat(const FileStat &fileStat) :
		_pathName(fileStat._pathName), _attr(fileStat._attr), _bytes(fileStat._bytes),
		_atime(fileStat._atime), _mtime(fileStat._mtime), _ctime(fileStat._ctime),
		_uid(fileStat._uid), _gid(fileStat._gid) {}
#if defined(GURA_ON_MSWIN)
	FileStat(const char *pathName, const BY_HANDLE_FILE_INFORMATION &attrData);
	FileStat(const char *pathName, const WIN32_FILE_ATTRIBUTE_DATA &attrData);
	FileStat(const char *pathName, const WIN32_FIND_DATA &findData);
#else
	FileStat(const char *pathName, const struct stat &stat);
#endif
	inline const char *GetPathName() const { return _pathName.c_str(); }
	inline ULong GetSize() const { return _bytes; }
	inline const DateTime &GetATime() const { return _atime; }
	inline const DateTime &GetMTime() const { return _mtime; }
	inline const DateTime &GetCTime() const { return _ctime; }
	inline long GetUid() const { return _uid; }
	inline long GetGid() const { return _gid; }
	inline long GetMode() const { return _attr & 0777; }
	inline bool IsDir() const { return (_attr & ATTR_Dir)? true : false; }
	inline bool IsChr() const { return (_attr & ATTR_Chr)? true : false; }
	inline bool IsBlk() const { return (_attr & ATTR_Blk)? true : false; }
	inline bool IsReg() const { return (_attr & ATTR_Reg)? true : false; }
	inline bool IsFifo() const { return (_attr & ATTR_Fifo)? true : false; }
	inline bool IsLnk() const { return (_attr & ATTR_Lnk)? true : false; }
	inline bool IsSock() const { return (_attr & ATTR_Sock)? true : false; }
	static FileStat *Generate(Signal sig, const char *fileName);
};

//-----------------------------------------------------------------------------
// DirLister
//-----------------------------------------------------------------------------
class DirLister {
	String _dirName;
#if defined(GURA_ON_MSWIN)
	HANDLE _hFind;
#else
	DIR *_dirp;
#endif
	bool _joinPathNameFlag;
public:
	DirLister(const char *dirName, bool joinPathNameFlag = true);
	~DirLister();
	bool Next(const char *pattern, String &pathName, bool *pDirFlag);
};

//-----------------------------------------------------------------------------
// DynamicLibrary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE DynamicLibrary {
private:
#if defined(GURA_ON_MSWIN)
	HMODULE _hModule;
#else
	void *_hLibrary;
#endif
public:
	DynamicLibrary();
	bool Open(Signal sig, const char *pathName);
	void *GetEntry(Signal sig, const char *name);
};

//-----------------------------------------------------------------------------
// Thread
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Thread {
private:
#if defined(GURA_ON_MSWIN)
	HANDLE _hThread;
	DWORD _threadId;
#else
	pthread_t _pt;
#endif
public:
	Thread();
	virtual ~Thread();
	void Start();
	void Wait();
	virtual void Run() = 0;
};

//-----------------------------------------------------------------------------
// Semaphore
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Semaphore {
private:
#if defined(GURA_ON_MSWIN)
	HANDLE _hMutex;
#else
	sem_t _sem;
#endif
public:
	Semaphore();
	~Semaphore();
	void Wait();
	void Release();
};

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Event {
private:
#if defined(GURA_ON_MSWIN)
	HANDLE _hEvent;
#else
	pthread_mutex_t _mutex;
#endif
public:
	Event();
	~Event();
	void Wait();
	void Notify();
};

}
}

#endif
