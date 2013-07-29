//-----------------------------------------------------------------------------
// Gura curl module
//-----------------------------------------------------------------------------
#ifndef __MODULE_CURL_H__
#define __MODULE_CURL_H__
#include <gura.h>
#define CURL_STATICLIB
#include <curl/curl.h>

Gura_BeginModule(curl)

//-----------------------------------------------------------------------------
// FileinfoList
//-----------------------------------------------------------------------------
class Fileinfo {
private:
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
public:
	Fileinfo(const struct curl_fileinfo *finfo);
	inline const char *GetFilename() const { return _filename.c_str(); }
	inline curlfiletype GetFiletype() const { return _filetype; }
	inline time_t GetTime() const { return _time; }
	inline UInt GetPerm() const { return _perm; }
	inline int GetUid() const { return _uid; }
	inline int GetGid() const { return _gid; }
	inline curl_off_t GetSize() const { return _size; }
	inline long int GetHardlinks() const { return _hardlinks; }
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
	Signal _sig;
	FileinfoOwner &_fileinfoOwner;
public:
	Browser(Signal sig, FileinfoOwner &fileinfoOwner);
	long OnChunkBgn(struct curl_fileinfo *finfo, int remains);
	long OnChunkEnd();
	static long OnChunkBgnStub(struct curl_fileinfo *finfo,
								struct callback_data *data, int remains);
	static long OnChunkEndStub(struct callback_data *data);
};

//-----------------------------------------------------------------------------
// Writer
//-----------------------------------------------------------------------------
class Writer {
private:
	Signal _sig;
	AutoPtr<Stream> _pStream;
public:
	Writer(Signal sig, Stream *pStream);
	size_t OnWrite(char *buffer, size_t size, size_t nitems);
	static size_t OnWriteStub(char *buffer, size_t size, size_t nitems, void *outstream);
};

//-----------------------------------------------------------------------------
// Reader
//-----------------------------------------------------------------------------
class Reader {
private:
	Signal _sig;
	AutoPtr<Stream> _pStream;
public:
	Reader(Signal sig, Stream *pStream);
	size_t OnRead(char *buffer, size_t size, size_t nitems);
	int OnSeek(curl_off_t offset, int origin);
	static size_t OnReadStub(char *buffer, size_t size, size_t nitems, void *instream);
	static int OnSeekStub(void *instream, curl_off_t offset, int origin);
};

//-----------------------------------------------------------------------------
// Directory_cURL declaration
//-----------------------------------------------------------------------------
class Directory_cURL : public Directory {
public:
	class Thread : public OAL::Thread {
	private:
		Signal _sig;
		String _name;
		AutoPtr<StreamFIFO> _pStreamFIFO;
	public:
		inline Thread(Signal sig, const String &name, StreamFIFO *pStreamFIFO) :
						_sig(sig), _name(name), _pStreamFIFO(pStreamFIFO) {}
		virtual void Run();
	};
private:
	String _name;
	std::auto_ptr<FileinfoOwner> _pFileinfoOwner;
	FileinfoOwner::iterator _ppFileinfo;
public:
	Directory_cURL(Directory *pParent, const char *name, Type type);
	virtual ~Directory_cURL();
	virtual Directory *DoNext(Environment &env, Signal sig);
	virtual Stream *DoOpenStream(Environment &env, Signal sig, ULong attr);
	FileinfoOwner *DoBrowse(Signal sig);
};

//-----------------------------------------------------------------------------
// PathManager_cURL declaration
//-----------------------------------------------------------------------------
class PathManager_cURL : public PathManager {
public:
	virtual bool IsResponsible(Environment &env, Signal sig,
					const Directory *pParent, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env, Signal sig,
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
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline CURL *GetEntity() { return _curl; }
};

}}

#endif
