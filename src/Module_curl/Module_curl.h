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
// Object_context declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(context);

class Object_context : public Object {
private:
	CURL *_curl;
	AutoPtr<Stream> _pStreamIn;
	AutoPtr<Stream> _pStreamOut;
public:
	Gura_DeclareObjectAccessor(context)
public:
	inline Object_context(CURL *curl) :
				Object(Gura_UserClass(context)), _curl(curl) {}
	virtual ~Object_context();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline CURL *GetEntity() { return _curl; }
	inline Stream *GetStreamIn() { return _pStreamIn.get(); }
	inline Stream *GetStreamOut() { return _pStreamOut.get(); }
	inline void SetStreamIn(Stream *pStreamIn) { _pStreamIn.reset(pStreamIn); }
	inline void SetStreamOut(Stream *pStreamOut) { _pStreamOut.reset(pStreamOut); }
};

}}

#endif
