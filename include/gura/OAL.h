// OAL: OS Abstraction Layer
#ifndef __GURA_OAL_H__
#define __GURA_OAL_H__
#include "Common.h"
#include "DateTime.h"
#include "Signal.h"
#include <semaphore.h>

#if defined(HAVE_WINDOWS_H)
#define ecvt _ecvt
#define fcvt _fcvt
#define gcvt _gcvt
#else
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
DLLDECLARE extern const char FileSeparatorWin;
DLLDECLARE extern const char FileSeparatorUnix;
DLLDECLARE extern const char FileSeparator;

DLLDECLARE bool IsAbsPathName(const char *pathName);
DLLDECLARE String MakeAbsPathName(char chSeparator, const char *fileName);
DLLDECLARE String RegulatePathName(char chSeparator, const char *pathName, bool cutLastSepFlag);
DLLDECLARE String JoinPathName(char chSeparator, const char *pathName, const char *name);
DLLDECLARE String JoinPathName(char chSeparator, const char *pathName, const char *name, size_t len);
DLLDECLARE String EliminateBottomDirName(const char *pathName);

inline String JoinPathName(const char *pathName, const char *name) {
	return JoinPathName(OAL::FileSeparator, pathName, name);
}

inline String JoinPathName(const char *pathName, const char *name, size_t len) {
	return JoinPathName(OAL::FileSeparator, pathName, name, len);
}

DLLDECLARE int ExecProgram(Environment &env, Signal sig, const char *pathName,
		const ValueList &valList, Stream *pStreamStdout, Stream *pStreamStderr,
		bool forkFlag);
DLLDECLARE String GetEnv(const char *name);
DLLDECLARE void PutEnv(const char *name, const char *value);
DLLDECLARE bool Rename(const char *src, const char *dst);
DLLDECLARE bool Remove(const char *pathName);
DLLDECLARE bool IsExist(const char *pathName);
DLLDECLARE bool IsDir(const char *pathName, bool *pExistFlag = NULL);
DLLDECLARE bool MakeDir(const char *pathName);
DLLDECLARE bool MakeDirTree(const char *pathName);
DLLDECLARE bool RemoveDir(const char *pathName);
DLLDECLARE bool RemoveDirTree(const char *pathName);
DLLDECLARE bool ChangeCurDir(const char *pathName);
DLLDECLARE String GetCurDir();
DLLDECLARE bool ChangeMode(int modeOct, const char *pathName);
DLLDECLARE bool ChangeMode(const char *mode, const char *pathName);
DLLDECLARE void Sleep(Number delay);
DLLDECLARE Number GetTickTime();
DLLDECLARE DateTime GetCurDateTime(bool utcFlag = false);
#if defined(HAVE_WINDOWS_H)
DLLDECLARE void SetModuleHandle(HMODULE hModule);
DLLDECLARE DateTime ToDateTime(const SYSTEMTIME &st, int secsOffset);
DLLDECLARE DateTime ToDateTime(const FILETIME &ft, bool utcFlag = false);
DLLDECLARE SYSTEMTIME ToSYSTEMTIME(const DateTime &dt);
DLLDECLARE FILETIME ToFILETIME(const DateTime &dt);
static inline bool IsPathSeparator(char ch) { return ch == ';'; }
#else
DLLDECLARE DateTime ToDateTime(const struct tm &tm, int secsOffset);
DLLDECLARE DateTime ToDateTime(time_t t, bool utcFlag = false);
static inline bool IsPathSeparator(char ch) { return ch == ';' || ch == ':'; }
#endif
DLLDECLARE int GetSecsOffsetTZ();
DLLDECLARE String GetBaseDir();
DLLDECLARE String GetDataDir();
DLLDECLARE String GetLibDir();
DLLDECLARE String GetLocalDir();
DLLDECLARE String GetExecutable();
DLLDECLARE void SetupModulePath(StringList &strList);
DLLDECLARE void SetupExecutablePath();
DLLDECLARE String ToNativeString(const char *str, int len = -1);
DLLDECLARE String FromNativeString(const char *str, int len = -1);

//-----------------------------------------------------------------------------
// FileStat declaration
//-----------------------------------------------------------------------------
class DLLDECLARE FileStat {
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
	unsigned long _attr;
	unsigned long _bytes;
	DateTime _atime;
	DateTime _mtime;
	DateTime _ctime;
	long _uid;
	long _gid;
public:
	inline FileStat() : _attr(0), _bytes(0), _uid(0), _gid(0) {}
	inline FileStat(const char *pathName, unsigned long attr, unsigned long bytes,
				const DateTime &atime, const DateTime &mtime, const DateTime &ctime,
				long uid, long gid) :
		_pathName(pathName), _attr(attr), _bytes(bytes),
		_atime(atime), _mtime(mtime), _ctime(ctime),
		_uid(uid), _gid(gid) {}
	inline FileStat(const FileStat &fileStat) :
		_pathName(fileStat._pathName), _attr(fileStat._attr), _bytes(fileStat._bytes),
		_atime(fileStat._atime), _mtime(fileStat._mtime), _ctime(fileStat._ctime),
		_uid(fileStat._uid), _gid(fileStat._gid) {}
#if defined(HAVE_WINDOWS_H)
	FileStat(const char *pathName, const BY_HANDLE_FILE_INFORMATION &attrData);
	FileStat(const char *pathName, const WIN32_FILE_ATTRIBUTE_DATA &attrData);
	FileStat(const char *pathName, const WIN32_FIND_DATA &findData);
#else
	FileStat(const char *pathName, const struct stat &stat);
#endif
	inline const char *GetPathName() const { return _pathName.c_str(); }
	inline unsigned long GetSize() const { return _bytes; }
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
#if defined(HAVE_WINDOWS_H)
	HANDLE _hFind;
#else
	DIR *_dirp;
#endif
public:
	DirLister(const char *dirName);
	~DirLister();
	bool Next(const char *pattern, String &pathName, bool *pDirFlag);
};

//-----------------------------------------------------------------------------
// DynamicLibrary
//-----------------------------------------------------------------------------
class DLLDECLARE DynamicLibrary {
private:
#if defined(HAVE_WINDOWS_H)
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
// Memory
//-----------------------------------------------------------------------------
class DLLDECLARE Memory {
private:
	size_t _bytes;
	char *_buff;
public:
	inline Memory(const Memory &memory) :
								_bytes(memory._bytes), _buff(NULL) {
		::memcpy(Allocate(_bytes), memory.GetPointer(), _bytes);
	}
	Memory(size_t bytes = 0);
	~Memory();
	inline size_t GetSize() const { return _bytes; }
	void *Allocate(size_t bytes);
	void *Resize(size_t bytes, size_t bytesToCopy);
	void Free();
	void *GetPointer(size_t offset = 0) const;
};

//-----------------------------------------------------------------------------
// Thread
//-----------------------------------------------------------------------------
class DLLDECLARE Thread {
public:
	void Start();
	virtual void Run() = 0;
};

//-----------------------------------------------------------------------------
// Semaphore
//-----------------------------------------------------------------------------
class DLLDECLARE Semaphore {
private:
#if defined(HAVE_WINDOWS_H)
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
class DLLDECLARE Event {
private:
#if defined(HAVE_WINDOWS_H)
	HANDLE _hEvent;
#else
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
