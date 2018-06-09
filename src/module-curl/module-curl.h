//-----------------------------------------------------------------------------
// Gura module: curl
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CURL_H__
#define __GURA_MODULE_CURL_H__
#include <gura.h>
#define CURL_STATICLIB
#include <curl/curl.h>

Gura_BeginModuleHeader(curl)

//-----------------------------------------------------------------------------
// Fileinfo
//-----------------------------------------------------------------------------
class Fileinfo {
private:
	int _cntRef;
	String _filename;
	curlfiletype _filetype;
	time_t _time;
	UInt _perm;
	int _uid;
	int _gid;
	curl_off_t _size;
	long int _hardlinks;
	//String time;
	//String perm;
	//String user;
	//String group;
	//String target; /* pointer to the target filename of a symlink */
	String _dirName;
public:
	Gura_DeclareReferenceAccessor(Fileinfo);
public:
	Fileinfo(const struct curl_fileinfo *finfo, const String &dirName);
protected:
	inline ~Fileinfo() {}
public:
	inline const char *GetFilename() const { return _filename.c_str(); }
	inline curlfiletype GetFiletype() const { return _filetype; }
	inline time_t GetTime() const { return _time; }
	inline UInt GetPerm() const { return _perm; }
	inline int GetUid() const { return _uid; }
	inline int GetGid() const { return _gid; }
	inline curl_off_t GetSize() const { return _size; }
	inline long int GetHardlinks() const { return _hardlinks; }
	inline const char *GetDirname() const { return _dirName.c_str(); }
private:
	inline Fileinfo(const Fileinfo &fileInfo) {}
};

//-----------------------------------------------------------------------------
// FileinfoList
//-----------------------------------------------------------------------------
class FileinfoList : public std::vector<Fileinfo *> {
};

//-----------------------------------------------------------------------------
// FileinfoOwner
//-----------------------------------------------------------------------------
class FileinfoOwner : public FileinfoList {
public:
	~FileinfoOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Browser
//-----------------------------------------------------------------------------
class Browser {
private:
	Signal &_sig;
	FileinfoOwner &_fileinfoOwner;
	String _dirName;
public:
	Browser(Signal &sig, FileinfoOwner &fileinfoOwner, const String &dirName);
	long OnChunkBgn(struct curl_fileinfo *finfo, int remains);
	long OnChunkEnd();
	static long OnChunkBgnStub(struct curl_fileinfo *finfo,
								struct callback_data *data, int remains);
	static long OnChunkEndStub(struct callback_data *data);
};

//-----------------------------------------------------------------------------
// Downloader
//-----------------------------------------------------------------------------
class Downloader {
private:
	Signal &_sig;
	AutoPtr<Stream> _pStream;
public:
	Downloader(Signal &sig, Stream *pStream);
	size_t OnWrite(char *buffer, size_t size, size_t nitems);
	static size_t OnWriteStub(char *buffer, size_t size, size_t nitems, void *outstream);
};

//-----------------------------------------------------------------------------
// Uploader
//-----------------------------------------------------------------------------
class Uploader {
private:
	Signal &_sig;
	AutoPtr<Stream> _pStream;
public:
	Uploader(Signal &sig, Stream *pStream);
	size_t OnRead(char *buffer, size_t size, size_t nitems);
	static size_t OnReadStub(char *buffer, size_t size, size_t nitems, void *instream);
};

//-----------------------------------------------------------------------------
// Directory_cURL declaration
//-----------------------------------------------------------------------------
class Directory_cURL : public Directory {
public:
	class ThreadDownload : public OAL::Thread {
	private:
		Signal &_sig;
		String _name;
		AutoPtr<StreamFIFO> _pStreamFIFO;
	public:
		inline ThreadDownload(Signal &sig, const String &name, StreamFIFO *pStreamFIFO) :
						_sig(sig), _name(name), _pStreamFIFO(pStreamFIFO) {}
		virtual void Run();
	};
	class ThreadUpload : public OAL::Thread {
	private:
		Signal &_sig;
		String _name;
		AutoPtr<StreamFIFO> _pStreamFIFO;
	public:
		inline ThreadUpload(Signal &sig, const String &name, StreamFIFO *pStreamFIFO) :
						_sig(sig), _name(name), _pStreamFIFO(pStreamFIFO) {}
		virtual void Run();
	};
private:
	AutoPtr<Fileinfo> _pFileinfo;	// this may be nullptr
	std::unique_ptr<FileinfoOwner> _pFileinfoOwner;
	FileinfoOwner::iterator _ppFileinfo;
public:
	Directory_cURL(Directory *pParent, const char *name, Type type, Fileinfo *pFileinfo);
	virtual ~Directory_cURL();
	virtual Directory *DoNext(Environment &env);
	virtual Stream *DoOpenStream(Environment &env, UInt32 attr);
	virtual Object *DoGetStatObj(Signal &sig);
	FileinfoOwner *DoBrowse(Environment &env);
};

//-----------------------------------------------------------------------------
// PathMgr_cURL declaration
//-----------------------------------------------------------------------------
class PathMgr_cURL : public PathMgr {
public:
	virtual bool IsResponsible(Environment &env,
					const Directory *pParent, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode);
};

//-----------------------------------------------------------------------------
// Object_context declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(easy_handle);

class Object_easy_handle : public Object {
private:
	CURL *_curl;
public:
	Gura_DeclareObjectAccessor(easy_handle)
public:
	inline Object_easy_handle(CURL *curl) :
				Object(Gura_UserClass(easy_handle)), _curl(curl) {}
	virtual ~Object_easy_handle();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline CURL *GetEntity() { return _curl; }
};

//-----------------------------------------------------------------------------
// Object_Stat declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Stat);

class Object_Stat : public Object {
public:
	Gura_DeclareObjectAccessor(Stat);
private:
	AutoPtr<Fileinfo> _pFileinfo;
public:
	inline Object_Stat(Fileinfo *pFileinfo) :
		Object(Gura_UserClass(Stat)), _pFileinfo(pFileinfo) {}
	inline Object_Stat(const Object_Stat &obj) :
		Object(obj), _pFileinfo(Fileinfo::Reference(obj._pFileinfo.get())) {}
	virtual ~Object_Stat();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline const Fileinfo *GetFileinfo() const { return _pFileinfo.get(); }
};

Gura_EndModuleHeader(curl)

#endif
