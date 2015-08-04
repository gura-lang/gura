//-----------------------------------------------------------------------------
// Gura module: http
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_HTTP_H__
#define __GURA_MODULE_HTTP_H__
#include <gura.h>
#include <gura/helper/ZLibHelper.h>
#include <algorithm>

#if defined(GURA_ON_MSWIN)
typedef int socklen_t;
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

inline void closesocket(int sock) { close(sock); }
#endif

Gura_BeginModuleHeader(http)

class Header;
class Stream_Http;
class Object_server;
class Object_client;
class Object_session;

struct KeyCompare_Dict {
	inline bool operator()(const String &s1, const String &s2) const {
		return ::strcasecmp(s1.c_str(), s2.c_str()) < 0;
	}
};

Gura_DeclareUserSymbol(request);
Gura_DeclareUserSymbol(status);
Gura_DeclareUserSymbol(field_names);
Gura_DeclareUserSymbol(method);
Gura_DeclareUserSymbol(uri);
Gura_DeclareUserSymbol(scheme);
Gura_DeclareUserSymbol(authority);
Gura_DeclareUserSymbol(path);
Gura_DeclareUserSymbol(query);
Gura_DeclareUserSymbol(fragment);
Gura_DeclareUserSymbol(version);
Gura_DeclareUserSymbol(code);
Gura_DeclareUserSymbol(reason);
Gura_DeclareUserSymbol(proxies);
Gura_DeclareUserSymbol(body);
Gura_DeclareUserSymbol(server);
Gura_DeclareUserSymbol(session);
Gura_DeclareUserSymbol(sessions);
Gura_DeclareUserSymbol(remote_ip);
Gura_DeclareUserSymbol(remote_host);
Gura_DeclareUserSymbol(remote_logname);
Gura_DeclareUserSymbol(local_ip);
Gura_DeclareUserSymbol(local_host);
Gura_DeclareUserSymbol(date);				// 14.18 Date
Gura_DeclareUserSymbol(expires);			// 14.21 Expires
Gura_DeclareUserSymbol(last_modified);		// 14.29 Last-Modified

//-----------------------------------------------------------------------------
// Chunk declaration
//-----------------------------------------------------------------------------
class Chunk {
public:
	enum Stat {
		STAT_Start,
		STAT_Size, STAT_ExtName, STAT_ExtValue,
		STAT_Complete,
	};
private:
	Stat _stat;
	size_t _size;
	String _extName;
	String _extValue;
public:
	inline Chunk() : _stat(STAT_Start), _size(0) {}
	~Chunk();
	inline bool IsComplete() const { return _stat == STAT_Complete; }
	inline size_t GetSize() const { return _size; }
	inline const char *GetExtName() const { return _extName.c_str(); }
	inline const char *GetExtValue() const { return _extValue.c_str(); }
	bool ParseChar(Signal &sig, char ch);
};

//-----------------------------------------------------------------------------
// SimpleHTMLParser declaration
//-----------------------------------------------------------------------------
class SimpleHTMLParser {
public:
	enum Stat {
		STAT_Init,
		STAT_Tag1stChar,
		STAT_TagName, STAT_SeekTagClose,
		STAT_AttrName, STAT_SeekEqual,
		STAT_AttrValue,
		STAT_AttrValueQuotedS, STAT_AttrValueQuotedD, STAT_AttrValueNaked,
		STAT_Comment, STAT_Comment1stChar, STAT_Comment2ndChar,
		STAT_SkipSpace,
		STAT_Error, STAT_Complete,
	};
	typedef std::map<String, String, KeyCompare_Dict> Attrs;
protected:
	Stat _stat;
	Stat _statNext;
	char _tagPrefix;
	String _tagName;
	String _attrName, _attrValue;
	Attrs _attrs;
public:
	inline SimpleHTMLParser() :
			_stat(STAT_Complete), _statNext(STAT_Complete), _tagPrefix('\0') {}
	bool ParseChar(Signal &sig, char ch);
	inline void Activate() { _stat = _statNext = STAT_Init; }
	inline bool IsComplete() const {
		return _stat == STAT_Complete;
	}
	inline bool IsActive() const {
		return _stat != STAT_Error && _stat != STAT_Complete;
	}
	virtual bool AcceptTag(Signal &sig,
				char tagPrefix, const char *tagName, const Attrs &attrs) = 0;
};

//-----------------------------------------------------------------------------
// EncodingDetector declaration
//-----------------------------------------------------------------------------
class EncodingDetector : public SimpleHTMLParser {
private:
	String _encoding;
public:
	virtual bool AcceptTag(Signal &sig,
				char tagPrefix, const char *tagName, const Attrs &attrs);
	inline bool IsValidEncoding() const {
		return IsComplete() && !_encoding.empty();
	}
	inline const char *GetEncoding() const { return _encoding.c_str(); }
};

//-----------------------------------------------------------------------------
// LinkDetector declaration
//-----------------------------------------------------------------------------
class LinkDetector : public SimpleHTMLParser {
public:
	virtual bool AcceptTag(Signal &sig,
				char tagPrefix, const char *tagName, const Attrs &attrs);
};

//-----------------------------------------------------------------------------
// ContentType declaration
//-----------------------------------------------------------------------------
class ContentType {
private:
	String _type;
	String _charset;
public:
	inline ContentType() {}
	bool Parse(Signal &sig, const char *str);
	inline const char *GetType() const { return _type.c_str(); }
	inline const char *GetCharset() const { return _charset.c_str(); }
	inline bool IsValidCharset() const { return !_charset.empty(); }
};

//-----------------------------------------------------------------------------
// Header declaration
//-----------------------------------------------------------------------------
class Header {
public:
	enum Stat {
		STAT_LineTop, STAT_FieldName, STAT_FieldValue,
		STAT_LineFolded, STAT_SkipWhiteSpace,
		STAT_Complete,
	};
	typedef std::map<String, StringList *, KeyCompare_Dict> Dict;
private:
	Stat _stat;
	String _fieldName;
	String _fieldValue;
	Dict _dict;
public:
	inline Header(bool completeFlag = false) :
					_stat(completeFlag? STAT_Complete : STAT_LineTop) {}
	Header(const Header &header);
	~Header();
	bool ParseChar(Signal &sig, char ch);
	bool IsComplete() const { return _stat == STAT_Complete; }
	void Reset();
	bool SetFields(Signal &sig, const ValueDict &valueDict, Stream *pStreamBody);
	//Value GetFieldsAsDict(Environment &env) const;
	void SetField(const char *fieldName, const char *fieldValue);
	bool GetField(const char *fieldName, StringList **ppStringList) const;
	Value GetField(Environment &env, Signal &sig, const char *fieldName, bool signalFlag) const;
	Value GetFieldNames(Environment &env, Signal &sig) const;
	Value IndexGet(Environment &env, const Value &valueIdx) const;
	bool GetTimeField(Environment &env, Signal &sig, const Symbol *pSymbol, Value &value) const;
	bool IsField(const char *fieldName, const char *value, bool *pFoundFlag = nullptr) const;
	inline static void SetError_InvalidFormat(Signal &sig) {
		sig.SetError(ERR_FormatError, "invalid format of HTTP header");
	}
	String GetString() const;
	Stream_Http *GenerateDownStream(Environment &env, Signal &sig,
					Object *pObjOwner, int sock, const char *name) const;
	static void DoDirProp(SymbolSet &symbols);
};

//-----------------------------------------------------------------------------
// Request declaration
//-----------------------------------------------------------------------------
class Request {
public:
	enum Stat {
		STAT_Start,
		STAT_Method,
		STAT_RequestURI,
		STAT_HttpVersion,
		STAT_SkipSpace, STAT_Header,
	};
private:
	Stat _stat;
	Stat _statNext;
	String _method;			// method
	String _requestURI;		// uri
	String _httpVersion;	// version
	Header _header;
public:
	inline Request() : _stat(STAT_Start), _statNext(STAT_Start) {}
	inline void SetRequest(const char *method, const char *requestURI, const char *httpVersion) {
		_method = method, _requestURI = requestURI, _httpVersion = httpVersion;
		_header.Reset();
	}
	bool ParseChar(Signal &sig, char ch);
	bool IsComplete() const { return _header.IsComplete(); }
	inline Header &GetHeader() { return _header; }
	inline const Header &GetHeader() const { return _header; }
	inline void Reset() {
		_stat = STAT_Start, _statNext = STAT_Start;
		_method.clear(), _requestURI.clear(), _httpVersion.clear();
		_header.Reset();
	}
	inline const char *GetMethod() const { return _method.c_str(); }
	inline const char *GetRequestURI() const { return _requestURI.c_str(); }
	inline const char *GetHttpVersion() const { return _httpVersion.c_str(); }
	inline static void SetError_InvalidFormat(Signal &sig) {
		sig.SetError(ERR_FormatError, "invalid format of HTTP request");
	}
	inline bool HasBody() const {
		// see RFC 2616 4.3 MessageBody
		return _header.GetField("Content-Length", nullptr) ||
							_header.GetField("Transfer-Encoding", nullptr);
	}
	bool Send(Signal &sig, int sock);
	bool Receive(Signal &sig, int sock);
};

//-----------------------------------------------------------------------------
// Status declaration
//-----------------------------------------------------------------------------
class Status {
public:
	enum Stat {
		STAT_Start,
		STAT_HttpVersion, STAT_StatusCode, STAT_ReasonPhrase,
		STAT_SkipSpace, STAT_Header,
	};
	enum Code {
		CODE_Invalid,
		// RFC 2616 10.1 Informational 1xx
		CODE_Continue,
		CODE_SwitchingProtocols,
		// RFC 2616 10.2 Successful 2xx
		CODE_OK,
		CODE_Created,
		CODE_Accepted,
		CODE_NonAuthoritativeInformation,
		CODE_NoContent,
		CODE_ResetContent,
		CODE_PartialContent,
		// RFC 2616 10.3 Redirection 3xx
		CODE_MultipleChoices,
		CODE_MovedPermanently,
		CODE_Found,
		CODE_SeeOther,
		CODE_NotModified,
		CODE_UseProxy,
		CODE_TemporaryRedirect,
		// RFC 2616 10.4 Client Error 4xx
		CODE_BadRequest,
		CODE_Unauthorized,
		CODE_PaymentRequired,
		CODE_Forbidden,
		CODE_NotFound,
		CODE_MethodNotAllowed,
		CODE_NotAcceptable,
		CODE_ProxyAuthenticationRequired,
		CODE_RequestTimeOut,
		CODE_Conflict,
		CODE_Gone,
		CODE_LengthRequired,
		CODE_PreconditionFailed,
		CODE_RequestEntityTooLarge,
		CODE_RequestURITooLarge,
		CODE_UnsupportedMediaType,
		CODE_RequestedRangeNotSatisfiable,
		CODE_ExpectationFailed,
		// RFC 2616 10.5 Server Error 5xx
		CODE_InternalServerError,
		CODE_NotImplemented,
		CODE_BadGateway,
		CODE_ServiceUnavailable,
		CODE_GatewayTimeOut,
		CODE_HTTPVersionNotSupported,
	};
	struct CodePhrase {
		const char *statusCode;
		const char *reasonPhrase;
		Code code;
	};
private:
	Stat _stat;
	Stat _statNext;
	String _httpVersion;	// version
	String _statusCode;		// code
	String _reasonPhrase;	// reason
	Header _header;
	static const CodePhrase _codePhraseTbl[];
public:
	inline Status() : _stat(STAT_Start), _statNext(STAT_Start) {}
	inline Status(const Status &status) : _stat(status._stat), _statNext(status._statNext),
		_httpVersion(status._httpVersion), _statusCode(status._statusCode),
		_reasonPhrase(status._reasonPhrase), _header(status._header) {}
	void SetStatus(const char *httpVersion, const char *statusCode, const char *reasonPhrase);
	bool ParseChar(Signal &sig, char ch);
	bool IsComplete() const { return _header.IsComplete(); }
	inline Header &GetHeader() { return _header; }
	inline const Header &GetHeader() const { return _header; }
	inline void Reset() {
		_stat = STAT_Start, _statNext = STAT_Start;
		_httpVersion.clear(), _statusCode.clear(), _reasonPhrase.clear();
		_header.Reset();
	}
	inline const char *GetHttpVersion() const { return _httpVersion.c_str(); }
	inline const char *GetStatusCode() const { return _statusCode.c_str(); }
	inline const char *GetReasonPhrase() const { return _reasonPhrase.c_str(); }
	inline bool IsOK() const {
		return _statusCode.compare("200") == 0;
	}
	inline static void SetError_InvalidFormat(Signal &sig) {
		sig.SetError(ERR_FormatError, "invalid format of HTTP status");
	}
	inline bool HasBody() const {
		// see RFC 2616 4.3 MessageBody
		return _statusCode.compare("204") != 0 && _statusCode.compare("304") != 0;
	}
	bool Send(Signal &sig, int sock);
	bool Receive(Signal &sig, int sock);
};

//-----------------------------------------------------------------------------
// Stream_Socket declaration
//-----------------------------------------------------------------------------
class Stream_Socket : public Stream {
private:
	AutoPtr<Object> _pObjOwner;
	int _sock;
public:
	Stream_Socket(Environment &env, Signal &sig, Object *pObjOwner, int sock);
	~Stream_Socket();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal &sig, void *buff, size_t bytes);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t bytes);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
	virtual Object *DoGetStatObj(Signal &sig);
};

//-----------------------------------------------------------------------------
// Stream_Chunked declaration
//-----------------------------------------------------------------------------
class Stream_Chunked : public Stream {
private:
	AutoPtr<Stream> _pStream;
	size_t _bytesChunk;
	bool _doneFlag;
	AutoPtr<Memory> _pMemory;
public:
	Stream_Chunked(Environment &env, Signal &sig, Stream *pStream, ULong attr);
	~Stream_Chunked();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal &sig, void *buff, size_t bytes);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t bytes);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
};

//-----------------------------------------------------------------------------
// Stream_Http declaration
//-----------------------------------------------------------------------------
class Stream_Http : public Stream {
private:
	AutoPtr<Stream> _pStream;
	String _name;
	size_t _bytesRead;
	Header _header;
	EncodingDetector _encodingDetector;
	AutoPtr<Memory> _pMemory;
public:
	Stream_Http(Environment &env, Signal &sig, Stream *pStream, ULong attr,
						const char *name, size_t bytes, const Header &header);
	~Stream_Http();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal &sig, void *buff, size_t bytes);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t bytes);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
	virtual Object *DoGetStatObj(Signal &sig);
	inline void ActivateEncodingDetector() {
		_encodingDetector.Activate();
	}
	bool Cleanup(Signal &sig);
};

//-----------------------------------------------------------------------------
// Object_stat
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(stat);

class Object_stat : public Object {
private:
	Header _header;
public:
	Gura_DeclareObjectAccessor(stat)
public:
	inline Object_stat(const Header &header) :
				Object(Gura_UserClass(stat)), _header(header) {}
	inline Object_stat(const Object_stat &obj) :
				Object(obj), _header(obj._header) {}
	virtual ~Object_stat();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual String ToString(bool exprFlag);
	Header &GetHeader() { return _header; }
};

//-----------------------------------------------------------------------------
// Object_request declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(request);

class Object_request : public Object {
public:
	Gura_DeclareObjectAccessor(request)
private:
	AutoPtr<Object_session> _pObjSession;
	Status _status;
public:
	inline Object_request(Object_session *pObjSession) :
			Object(Gura_UserClass(request)), _pObjSession(pObjSession) {}
	virtual ~Object_request();
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	bool SendResponse(Signal &sig,
		const char *statusCode, const char *reasonPhrase, Stream *pStreamBody,
		const char *httpVersion, const ValueDict &valueDict);
	Stream *SendRespChunk(Signal &sig,
		const char *statusCode, const char *reasonPhrase,
		const char *httpVersion, const ValueDict &valueDict);
	inline Object_session *GetSessionObj() { return _pObjSession.get(); }
};

//-----------------------------------------------------------------------------
// Object_response declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(response);

class Object_response : public Object {
public:
	Gura_DeclareObjectAccessor(response)
private:
	AutoPtr<Object_client> _pObjClient;
public:
	inline Object_response(Object_client *pObjClient) :
			Object(Gura_UserClass(response)), _pObjClient(pObjClient) {}
	virtual ~Object_response();
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Object_client *GetClientObj() { return _pObjClient.get(); }
};

//-----------------------------------------------------------------------------
// Object_session declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(session);

class Object_session : public Object {
public:
	Gura_DeclareObjectAccessor(session)
private:
	AutoPtr<Object_server> _pObjServer;
	AutoPtr<Stream_Http> _pStreamHttp;
	int _sock;
	String _remoteIP;
	String _remoteHost;
	String _remoteLogname;
	String _localIP;
	String _localHost;
	Request _request;
	DateTime _dateTime;
public:
	inline Object_session(Object_server *pObjServer, int sock,
			const char *remoteIP, const char *remoteHost, const char *remoteLogname,
			const char *localIP, const char *localHost, const DateTime dateTime) :
		Object(Gura_UserClass(session)),
		_pObjServer(pObjServer), _pStreamHttp(nullptr), _sock(sock),
		_remoteIP(remoteIP), _remoteHost(remoteHost), _remoteLogname(remoteLogname),
		_localIP(localIP), _localHost(localHost), _dateTime(dateTime) {}
	inline Object_session(const Object_session &obj) : Object(obj) {}
	virtual ~Object_session();
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline bool IsValid() const { return _sock > 0; }
	inline int GetSocket() const { return _sock; }
	inline Request &GetRequest() { return _request; }
	inline Stream_Http *GetStream() { return _pStreamHttp.get(); }
	inline const DateTime &GetDateTime() const { return _dateTime; }
	bool ReceiveRequest(Signal &sig);
	bool CleanupRequest(Signal &sig);
};

//-----------------------------------------------------------------------------
// Object_server declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(server);

class Object_server : public Object {
public:
	typedef std::vector<Object_session *> SessionList;
public:
	Gura_DeclareObjectAccessor(server)
private:
	String _addr;
	short _port;
	sockaddr_in _saddrServer;
	int _sockListen;
	fd_set _fdsRead;
	SessionList _sessionList;
public:
	Object_server();
	virtual ~Object_server();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	bool Prepare(Signal &sig, const char *addr, short port);
	Object_request *Wait(Signal &sig);
};

//-----------------------------------------------------------------------------
// Object_client declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(client);

class Object_client : public Object {
public:
	Gura_DeclareObjectAccessor(client)
private:
	AutoPtr<Stream_Http> _pStreamHttp;
	int _sock;
	String _addr;
	String _addrProxy;
	short _port;
	short _portProxy;
	String _userIdProxy;
	String _passwordProxy;
	Request _request;
	Status _status;
public:
	inline Object_client() : Object(Gura_UserClass(client)),
			_pStreamHttp(nullptr), _sock(-1), _port(0), _portProxy(0) {}
	virtual ~Object_client();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	bool Prepare(Signal &sig, const char *addr, short port,
					const char *addrProxy, short portProxy,
					const char *userIdProxy, const char *passwordProxy);
	inline Request &GetRequest() { return _request; }
	inline Status &GetStatus() { return _status; }
	inline Stream_Http *GetStream() { return _pStreamHttp.get(); }
	inline bool IsViaProxy() const { return !_addrProxy.empty(); }
	Object_response *SendRequest(Signal &sig,
			const char *method, const char *uri, Stream *pStreamBody,
			const char *httpVersion, const ValueDict &valueDict);
	bool CleanupResponse(Signal &sig);
};

//-----------------------------------------------------------------------------
// Object_proxy declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(proxy);

class Object_proxy : public Object {
public:
	Gura_DeclareObjectAccessor(proxy)
private:
	String _addr;
	short _port;
	String _userId;
	String _password;
	AutoPtr<Function> _pFuncCriteria;
public:
	inline Object_proxy(const char *addr, short port,
					const char *userId, const char *password, Function *pFuncCriteria) :
		Object(Gura_UserClass(proxy)), _addr(addr), _port(port),
		_userId(userId), _password(password), _pFuncCriteria(pFuncCriteria) {}
	virtual ~Object_proxy();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline const char *GetAddr() const { return _addr.c_str(); }
	inline short GetPort() const { return _port; }
	inline const char *GetUserId() const { return _userId.c_str(); }
	inline const char *GetPassword() const { return _password.c_str(); }
	bool IsResponsible(Environment &env, const char *addr) const;
};

//-----------------------------------------------------------------------------
// Directory_Http declaration
//-----------------------------------------------------------------------------
class Directory_Http : public Directory {
private:
	String _scheme;
	String _authority;
	String _query;
	String _fragment;
public:
	Directory_Http(Directory *pParent, const char *name, Type type);
	virtual ~Directory_Http();
	virtual Directory *DoNext(Environment &env);
	virtual Stream *DoOpenStream(Environment &env, ULong attr);
	inline void SetScheme(const char *scheme) { _scheme = scheme; }
	inline void SetAuthority(const char *authority) { _authority = authority; }
	inline void SetQuery(const char *query) { _query = query; }
	inline void SetFragment(const char *fragment) { _fragment = fragment; }
	inline const char *GetScheme() const { return _scheme.c_str(); }
	inline const char *GetAuthority() const { return _authority.c_str(); }
	inline const char *GetQuery() const { return _query.c_str(); }
	inline const char *GetFragment() const { return _fragment.c_str(); }
};

//-----------------------------------------------------------------------------
// PathMgr_Http declaration
//-----------------------------------------------------------------------------
class PathMgr_Http : public PathMgr {
public:
	virtual bool IsResponsible(Environment &env,
					const Directory *pParent, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode);
};

Gura_EndModuleHeader(http)

#endif
