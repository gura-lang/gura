//-----------------------------------------------------------------------------
// Gura module: fs
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_FS_H__
#define __GURA_MODULE_FS_H__
#include <gura.h>

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

Gura_BeginModuleHeader(fs)

//-----------------------------------------------------------------------------
// Object_Stat declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Stat);

class Object_Stat : public Object {
private:
	OAL::FileStat _fileStat;
public:
	Gura_DeclareObjectAccessor(Stat)
public:
	inline Object_Stat(const OAL::FileStat &fileStat) :
				Object(Gura_UserClass(Stat)), _fileStat(fileStat) {}
	inline Object_Stat(const Object_Stat &obj) :
				Object(obj), _fileStat(obj._fileStat) {}
	virtual ~Object_Stat();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Stream_File declaration
//-----------------------------------------------------------------------------
class Stream_File : public Stream {
private:
#if defined(GURA_ON_MSWIN)
	HANDLE _hFile;
	struct {
		HANDLE hFileMappingObject;
		UChar *buff;
		size_t offset;
		size_t bytes;
	} _map;
#else
	// FILE instance cannot be passed to DLL's args (see KB190799 in MSDN)
	FILE *_fp;
#endif
	bool _needCloseFlag;
	String _fileName;
public:
	Stream_File(Environment &env, Signal sig);
	~Stream_File();
	bool Open(Signal sig, const char *fileName, ULong attr);
	bool OpenStdin();
	bool OpenStdout();
	bool OpenStderr();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t bytes);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t bytes);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	virtual Object *DoGetStatObj(Signal sig);
private:
	inline Stream_File(Environment &env, Signal sig, const Stream_File &file) :
											Stream(env, sig, ATTR_None) {}
};

//-----------------------------------------------------------------------------
// Directory_FileSys declaration
//-----------------------------------------------------------------------------
class Directory_FileSys : public Directory {
private:
#if defined(GURA_ON_MSWIN)
	HANDLE _hFind;
#else
	DIR *_pDir;
#endif
	std::auto_ptr<OAL::FileStat> _pFileStat;
public:
	Directory_FileSys(Directory *pParent, const char *name,
										Type type, OAL::FileStat *pFileStat);
	inline Directory_FileSys(const Directory_FileSys &directory) : Directory(directory) {}
	virtual ~Directory_FileSys();
	virtual Object *DoGetStatObj(Signal sig);
	static bool IsExist(Signal sig, const char *pathName);
	static bool IsDir(Signal sig, const char *pathName);
protected:
	virtual Directory *DoNext(Environment &env, Signal sig);
	virtual Stream *DoOpenStream(Environment &env, Signal sig, ULong attr);
};

//-----------------------------------------------------------------------------
// PathMgr_FileSys declaration
//-----------------------------------------------------------------------------
class PathMgr_FileSys : public PathMgr {
public:
	virtual bool IsResponsible(Environment &env, Signal sig,
					const Directory *pParent, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env, Signal sig,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode);
};

Gura_EndModuleHeader(fs)

#endif
