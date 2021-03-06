//-----------------------------------------------------------------------------
// Gura module: curl
//-----------------------------------------------------------------------------
#include "stdafx.h"

#define Gura_AssignValueCURLINFO(name) \
Gura_AssignValue(INFO_##name, Value(CURLINFO_##name))

#define Gura_AssignValueCURLE(name) \
Gura_AssignValue(E_##name, Value(CURLE_##name))

#define Gura_AssignValueCURLOPT(name) \
Gura_AssignValue(OPT_##name, Value(CURLOPT_##name))

#define Gura_AssignValueCURLFORM(name) \
Gura_AssignValue(FORM_##name, Value(CURLFORM_##name))

#define Gura_AssignValuePAUSE(name) \
Gura_AssignValue(PAUSE_##name, Value(CURLPAUSE_##name))

#define Gura_AssignValueVERSION(name) \
Gura_AssignValue(VERSION_##name, Value(CURL_VERSION_##name))

Gura_BeginModuleBody(curl)

//-----------------------------------------------------------------------------
// global variable
//-----------------------------------------------------------------------------
Value g_valueTimeout;
OAL::Semaphore *g_pSemaphoreCurl = nullptr;

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
void SetError_Curl(Signal &sig, CURLcode code)
{
	sig.SetError(ERR_LibraryError, "[curl] %s", ::curl_easy_strerror(code));
}

//-----------------------------------------------------------------------------
// Fileinfo
//-----------------------------------------------------------------------------
Fileinfo::Fileinfo(const struct curl_fileinfo *finfo, const String &dirName) :
	_cntRef(1),
	_filename(finfo->filename),
	_filetype(finfo->filetype),
	_time(finfo->time),
	_perm(finfo->perm),
	_uid(finfo->uid),
	_gid(finfo->gid),
	_size(finfo->size),
	_hardlinks(finfo->hardlinks),
	_dirName(dirName)
{
	//::printf("time:   %d %s\n", _time, finfo->strings.time);
	//::printf("perm:   %o %s\n", _perm, finfo->strings.perm);
	//::printf("user:   %d %s\n", _uid, finfo->strings.user);
	//::printf("group:  %d %s\n", _gid, finfo->strings.group);
	//::printf("target: %s\n", finfo->strings.target);
}

//-----------------------------------------------------------------------------
// FileinfoOwner
//-----------------------------------------------------------------------------
FileinfoOwner::~FileinfoOwner()
{
	Clear();
}

void FileinfoOwner::Clear()
{
	foreach (FileinfoOwner, ppFileinfo, *this) {
		Fileinfo *pFileinfo = *ppFileinfo;
		Fileinfo::Delete(pFileinfo);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Browser
//-----------------------------------------------------------------------------
Browser::Browser(Signal &sig, FileinfoOwner &fileinfoOwner, const String &dirName) :
	_sig(sig), _fileinfoOwner(fileinfoOwner), _dirName(dirName)
{
}

long Browser::OnChunkBgn(struct curl_fileinfo *finfo, int remains)
{
	_fileinfoOwner.push_back(new Fileinfo(finfo, _dirName));
	return CURL_CHUNK_BGN_FUNC_SKIP;
}

long Browser::OnChunkEnd()
{
	return CURL_CHUNK_END_FUNC_OK;
}

long Browser::OnChunkBgnStub(struct curl_fileinfo *finfo,
								struct callback_data *data, int remains)
{
	Browser *pBrowser = reinterpret_cast<Browser *>(data);
	return pBrowser->OnChunkBgn(finfo, remains);
}

long Browser::OnChunkEndStub(struct callback_data *data)
{
	Browser *pBrowser = reinterpret_cast<Browser *>(data);
	return pBrowser->OnChunkEnd();
}

//-----------------------------------------------------------------------------
// Downloader
//-----------------------------------------------------------------------------
Downloader::Downloader(Signal &sig, const String &uri, Stream *pStream) :
	_sig(sig), _uri(uri), _pStream(pStream)
{
}

size_t Downloader::OnWrite(char *buffer, size_t size, size_t nitems)
{
	//::printf("OnWrite(%d)\n", nitems);
	return _pStream->Write(_sig, buffer, size * nitems);
}

size_t Downloader::OnWriteStub(char *buffer, size_t size, size_t nitems, void *outstream)
{
	Downloader *pDownloader = reinterpret_cast<Downloader *>(outstream);
	return pDownloader->OnWrite(buffer, size, nitems);
}

void Downloader::Run()
{
	g_pSemaphoreCurl->Wait();
	CURL *curl = ::curl_easy_init();
	if (curl != nullptr) {
		::curl_easy_setopt(curl, CURLOPT_URL, _uri.c_str());
		::curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		::curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
		::curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteStub);
		CURLcode code = ::curl_easy_perform(curl);
		if (code != CURLE_OK) SetError_Curl(_sig, code);
		::curl_easy_cleanup(curl);
		//_pStreamFIFO->SetWriteDoneFlag();
		_pStream->Close();
	}
	g_pSemaphoreCurl->Release();
}

//-----------------------------------------------------------------------------
// Uploader
//-----------------------------------------------------------------------------
Uploader::Uploader(Signal &sig, const String &uri, Stream *pStream) :
	_sig(sig), _uri(uri), _pStream(pStream)
{
}

size_t Uploader::OnRead(char *buffer, size_t size, size_t nitems)
{
	return _pStream->Read(_sig, buffer, size * nitems);
}

size_t Uploader::OnReadStub(char *buffer, size_t size, size_t nitems, void *instream)
{
	Uploader *pUploader = reinterpret_cast<Uploader *>(instream);
	return pUploader->OnRead(buffer, size, nitems);
}

void Uploader::Run()
{
	g_pSemaphoreCurl->Wait();
	CURL *curl = ::curl_easy_init();
	if (curl != nullptr) {
		::curl_easy_setopt(curl, CURLOPT_URL, _uri.c_str());
		::curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
#if 0
		do {
			struct curl_slist *slist = nullptr;
			slist = ::curl_slist_append(slist, cmd1);
			slist = ::curl_slist_append(slist, cmd2);
			::curl_easy_setopt(curl, CURLOPT_POSTQUOTE, slist);
		} while (0);
#endif
		//::curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, static_cast<curl_off_t>(_pStreamFIFO->GetSize()));
		::curl_easy_setopt(curl, CURLOPT_READDATA, this);
		::curl_easy_setopt(curl, CURLOPT_READFUNCTION, OnReadStub);
		CURLcode code = ::curl_easy_perform(curl);
		if (code != CURLE_OK) SetError_Curl(_sig, code);
		//::curl_slist_free_all(slist);
		::curl_easy_cleanup(curl);
	}
	g_pSemaphoreCurl->Release();
}

//-----------------------------------------------------------------------------
// Gura module functions: curl
//-----------------------------------------------------------------------------
// curl.version() {block?}
Gura_DeclareFunction(version)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a string of the libcurl version.");
}

Gura_ImplementFunction(version)
{
	const char *rtn = ::curl_version();
	return ReturnValue(env, arg, Value(rtn));
}

// curl.easy_init() {block?}
Gura_DeclareFunction(easy_init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Initializes cURL and returns a easy_handle object.");
}

Gura_ImplementFunction(easy_init)
{
	CURL *curl = ::curl_easy_init();
	return ReturnValue(env, arg, Value(new Object_easy_handle(curl)));
}

// curl.opendir(uri:string) {block?}
Gura_DeclareFunction(opendir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "uri", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a `directory` instance that browses network resources.");
}

Gura_ImplementFunction(opendir)
{
	const char *uri = arg.GetString(0);
	size_t len = ::strlen(uri);
	Directory::Type type = (len > 0 && IsFileSeparator(uri[len - 1]))?
		Directory::TYPE_Container : Directory::TYPE_Item;
	AutoPtr<Directory> pDirectory(new Directory_cURL(nullptr, uri, type, nullptr));
	return ReturnValue(env, arg, Value(new Object_directory(env, pDirectory.release())));
}

// curl.set_timeout(timeout:number):void
Gura_DeclareFunction(set_timeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "timeout", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Sets timeout in seconds that is applied while browsing directories.");
}

Gura_ImplementFunction(set_timeout)
{
	g_valueTimeout = arg.GetValue(0);
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
	g_pSemaphoreCurl = new OAL::Semaphore();
	::curl_global_init(CURL_GLOBAL_ALL);
	// class realization
	Gura_RealizeAndPrepareUserClass(easy_handle, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(Stat, env.LookupClass(VTYPE_object));
	// class reference assignment
	Gura_AssignValue(easy_handle, Value(Gura_UserClass(easy_handle)->Reference()));
	// value assignment
	// CURLINFO
	Gura_AssignValueCURLINFO(TEXT);
	Gura_AssignValueCURLINFO(HEADER_IN);
	Gura_AssignValueCURLINFO(HEADER_OUT);
	Gura_AssignValueCURLINFO(DATA_IN);
	Gura_AssignValueCURLINFO(DATA_OUT);
	Gura_AssignValueCURLINFO(SSL_DATA_IN);
	Gura_AssignValueCURLINFO(SSL_DATA_OUT);
	Gura_AssignValueCURLINFO(END);
	Gura_AssignValueCURLINFO(CERTINFO);
	Gura_AssignValueCURLINFO(NONE);
	Gura_AssignValueCURLINFO(EFFECTIVE_URL);
	Gura_AssignValueCURLINFO(RESPONSE_CODE);
	Gura_AssignValueCURLINFO(TOTAL_TIME);
	Gura_AssignValueCURLINFO(NAMELOOKUP_TIME);
	Gura_AssignValueCURLINFO(CONNECT_TIME);
	Gura_AssignValueCURLINFO(PRETRANSFER_TIME);
	Gura_AssignValueCURLINFO(SIZE_UPLOAD);
	Gura_AssignValueCURLINFO(SIZE_DOWNLOAD);
	Gura_AssignValueCURLINFO(SPEED_DOWNLOAD);
	Gura_AssignValueCURLINFO(SPEED_UPLOAD);
	Gura_AssignValueCURLINFO(HEADER_SIZE);
	Gura_AssignValueCURLINFO(REQUEST_SIZE);
	Gura_AssignValueCURLINFO(SSL_VERIFYRESULT);
	Gura_AssignValueCURLINFO(FILETIME);
	Gura_AssignValueCURLINFO(CONTENT_LENGTH_DOWNLOAD);
	Gura_AssignValueCURLINFO(CONTENT_LENGTH_UPLOAD);
	Gura_AssignValueCURLINFO(STARTTRANSFER_TIME);
	Gura_AssignValueCURLINFO(CONTENT_TYPE);
	Gura_AssignValueCURLINFO(REDIRECT_TIME);
	Gura_AssignValueCURLINFO(REDIRECT_COUNT);
	Gura_AssignValueCURLINFO(PRIVATE);
	Gura_AssignValueCURLINFO(HTTP_CONNECTCODE);
	Gura_AssignValueCURLINFO(HTTPAUTH_AVAIL);
	Gura_AssignValueCURLINFO(PROXYAUTH_AVAIL);
	Gura_AssignValueCURLINFO(OS_ERRNO);
	Gura_AssignValueCURLINFO(NUM_CONNECTS);
	Gura_AssignValueCURLINFO(SSL_ENGINES);
	Gura_AssignValueCURLINFO(COOKIELIST);
	Gura_AssignValueCURLINFO(LASTSOCKET);
	Gura_AssignValueCURLINFO(FTP_ENTRY_PATH);
	Gura_AssignValueCURLINFO(REDIRECT_URL);
	Gura_AssignValueCURLINFO(PRIMARY_IP);
	Gura_AssignValueCURLINFO(APPCONNECT_TIME);
	Gura_AssignValueCURLINFO(CERTINFO);
	Gura_AssignValueCURLINFO(CONDITION_UNMET);
	Gura_AssignValueCURLINFO(RTSP_SESSION_ID);
	Gura_AssignValueCURLINFO(RTSP_CLIENT_CSEQ);
	Gura_AssignValueCURLINFO(RTSP_SERVER_CSEQ);
	Gura_AssignValueCURLINFO(RTSP_CSEQ_RECV);
	Gura_AssignValueCURLINFO(PRIMARY_PORT);
	Gura_AssignValueCURLINFO(LOCAL_IP);
	Gura_AssignValueCURLINFO(LOCAL_PORT);
	Gura_AssignValueCURLINFO(LASTONE);
	Gura_AssignValueCURLINFO(HTTP_CODE);
	// CURLcode
	Gura_AssignValueCURLE(ABORTED_BY_CALLBACK);
	Gura_AssignValueCURLE(OK);
	Gura_AssignValueCURLE(UNSUPPORTED_PROTOCOL);
	Gura_AssignValueCURLE(FAILED_INIT);
	Gura_AssignValueCURLE(URL_MALFORMAT);
#if defined(CURLE_NOT_BUILT_IN)
	Gura_AssignValueCURLE(NOT_BUILT_IN);
#endif
	Gura_AssignValueCURLE(COULDNT_RESOLVE_PROXY);
	Gura_AssignValueCURLE(COULDNT_RESOLVE_HOST);
	Gura_AssignValueCURLE(COULDNT_CONNECT);
	Gura_AssignValueCURLE(FTP_WEIRD_SERVER_REPLY);
	Gura_AssignValueCURLE(REMOTE_ACCESS_DENIED);
#if defined(CURLE_FTP_ACCEPT_FAILED)
	Gura_AssignValueCURLE(FTP_ACCEPT_FAILED);
#endif
	Gura_AssignValueCURLE(FTP_WEIRD_PASS_REPLY);
#if defined(CURLE_FTP_ACCEPT_TIMEOUT)
	Gura_AssignValueCURLE(FTP_ACCEPT_TIMEOUT);
#endif
	Gura_AssignValueCURLE(FTP_WEIRD_PASV_REPLY);
	Gura_AssignValueCURLE(FTP_WEIRD_227_FORMAT);
	Gura_AssignValueCURLE(FTP_CANT_GET_HOST);
	Gura_AssignValueCURLE(OBSOLETE16);
	Gura_AssignValueCURLE(FTP_COULDNT_SET_TYPE);
	Gura_AssignValueCURLE(PARTIAL_FILE);
	Gura_AssignValueCURLE(FTP_COULDNT_RETR_FILE);
	Gura_AssignValueCURLE(OBSOLETE20);
	Gura_AssignValueCURLE(QUOTE_ERROR);
	Gura_AssignValueCURLE(HTTP_RETURNED_ERROR);
	Gura_AssignValueCURLE(WRITE_ERROR);
	Gura_AssignValueCURLE(OBSOLETE24);
	Gura_AssignValueCURLE(UPLOAD_FAILED);
	Gura_AssignValueCURLE(READ_ERROR);
	Gura_AssignValueCURLE(OUT_OF_MEMORY);
	Gura_AssignValueCURLE(OPERATION_TIMEDOUT);
	Gura_AssignValueCURLE(OBSOLETE29);
	Gura_AssignValueCURLE(FTP_PORT_FAILED);
	Gura_AssignValueCURLE(FTP_COULDNT_USE_REST);
	Gura_AssignValueCURLE(OBSOLETE32);
	Gura_AssignValueCURLE(RANGE_ERROR);
	Gura_AssignValueCURLE(HTTP_POST_ERROR);
	Gura_AssignValueCURLE(SSL_CONNECT_ERROR);
	Gura_AssignValueCURLE(BAD_DOWNLOAD_RESUME);
	Gura_AssignValueCURLE(FILE_COULDNT_READ_FILE);
	Gura_AssignValueCURLE(LDAP_CANNOT_BIND);
	Gura_AssignValueCURLE(LDAP_SEARCH_FAILED);
	Gura_AssignValueCURLE(OBSOLETE40);
	Gura_AssignValueCURLE(FUNCTION_NOT_FOUND);
	Gura_AssignValueCURLE(ABORTED_BY_CALLBACK);
	Gura_AssignValueCURLE(BAD_FUNCTION_ARGUMENT);
	Gura_AssignValueCURLE(OBSOLETE44);
	Gura_AssignValueCURLE(INTERFACE_FAILED);
	Gura_AssignValueCURLE(OBSOLETE46);
	Gura_AssignValueCURLE(TOO_MANY_REDIRECTS);
#if defined(CURLE_UNKNOWN_OPTION)
	Gura_AssignValueCURLE(UNKNOWN_OPTION);
#endif
	Gura_AssignValueCURLE(TELNET_OPTION_SYNTAX);
	Gura_AssignValueCURLE(OBSOLETE50);
	Gura_AssignValueCURLE(PEER_FAILED_VERIFICATION);
	Gura_AssignValueCURLE(GOT_NOTHING);
	Gura_AssignValueCURLE(SSL_ENGINE_NOTFOUND);
	Gura_AssignValueCURLE(SSL_ENGINE_SETFAILED);
	Gura_AssignValueCURLE(SEND_ERROR);
	Gura_AssignValueCURLE(RECV_ERROR);
	Gura_AssignValueCURLE(OBSOLETE57);
	Gura_AssignValueCURLE(SSL_CERTPROBLEM);
	Gura_AssignValueCURLE(SSL_CIPHER);
	Gura_AssignValueCURLE(SSL_CACERT);
	Gura_AssignValueCURLE(BAD_CONTENT_ENCODING);
	Gura_AssignValueCURLE(LDAP_INVALID_URL);
	Gura_AssignValueCURLE(FILESIZE_EXCEEDED);
	Gura_AssignValueCURLE(USE_SSL_FAILED);
	Gura_AssignValueCURLE(SEND_FAIL_REWIND);
	Gura_AssignValueCURLE(SSL_ENGINE_INITFAILED);
	Gura_AssignValueCURLE(LOGIN_DENIED);
	Gura_AssignValueCURLE(TFTP_NOTFOUND);
	Gura_AssignValueCURLE(TFTP_PERM);
	Gura_AssignValueCURLE(REMOTE_DISK_FULL);
	Gura_AssignValueCURLE(TFTP_ILLEGAL);
	Gura_AssignValueCURLE(TFTP_UNKNOWNID);
	Gura_AssignValueCURLE(REMOTE_FILE_EXISTS);
	Gura_AssignValueCURLE(TFTP_NOSUCHUSER);
	Gura_AssignValueCURLE(CONV_FAILED);
	Gura_AssignValueCURLE(CONV_REQD);
	Gura_AssignValueCURLE(SSL_CACERT_BADFILE);
	Gura_AssignValueCURLE(REMOTE_FILE_NOT_FOUND);
	Gura_AssignValueCURLE(SSH);
	Gura_AssignValueCURLE(SSL_SHUTDOWN_FAILED);
	Gura_AssignValueCURLE(AGAIN);
	Gura_AssignValueCURLE(SSL_CRL_BADFILE);
	Gura_AssignValueCURLE(SSL_ISSUER_ERROR);
	Gura_AssignValueCURLE(FTP_PRET_FAILED);
	Gura_AssignValueCURLE(RTSP_CSEQ_ERROR);
	Gura_AssignValueCURLE(RTSP_SESSION_ERROR);
	Gura_AssignValueCURLE(FTP_BAD_FILE_LIST);
	Gura_AssignValueCURLE(CHUNK_FAILED);
#if defined(CURLE_NO_CONNECTION_AVAILABLE)
	Gura_AssignValueCURLE(NO_CONNECTION_AVAILABLE);
#endif
	// CURLoption
	Gura_AssignValueCURLOPT(FILE);							// OBJECTPOINT
	Gura_AssignValueCURLOPT(URL);							// OBJECTPOINT
	Gura_AssignValueCURLOPT(PORT);							// LONG
	Gura_AssignValueCURLOPT(PROXY);							// OBJECTPOINT
	Gura_AssignValueCURLOPT(USERPWD);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(PROXYUSERPWD);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(RANGE);							// OBJECTPOINT
	Gura_AssignValueCURLOPT(INFILE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(ERRORBUFFER);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(WRITEFUNCTION);					// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(READFUNCTION);					// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(TIMEOUT);						// LONG
	Gura_AssignValueCURLOPT(INFILESIZE);					// LONG
	Gura_AssignValueCURLOPT(POSTFIELDS);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(REFERER);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(FTPPORT);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(USERAGENT);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(LOW_SPEED_LIMIT);				// LONG
	Gura_AssignValueCURLOPT(LOW_SPEED_TIME);				// LONG
	Gura_AssignValueCURLOPT(RESUME_FROM);					// LONG
	Gura_AssignValueCURLOPT(COOKIE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(HTTPHEADER);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(HTTPPOST);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSLCERT);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(KEYPASSWD);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(CRLF);							// LONG
	Gura_AssignValueCURLOPT(QUOTE);							// OBJECTPOINT
	Gura_AssignValueCURLOPT(WRITEHEADER);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(COOKIEFILE);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSLVERSION);					// LONG
	Gura_AssignValueCURLOPT(TIMECONDITION);					// LONG
	Gura_AssignValueCURLOPT(TIMEVALUE);						// LONG
	Gura_AssignValueCURLOPT(CUSTOMREQUEST);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(STDERR);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(POSTQUOTE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(WRITEINFO);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(VERBOSE);						// LONG
	Gura_AssignValueCURLOPT(HEADER);						// LONG
	Gura_AssignValueCURLOPT(NOPROGRESS);					// LONG
	Gura_AssignValueCURLOPT(NOBODY);						// LONG
	Gura_AssignValueCURLOPT(FAILONERROR);					// LONG
	Gura_AssignValueCURLOPT(UPLOAD);						// LONG
	Gura_AssignValueCURLOPT(POST);							// LONG
	Gura_AssignValueCURLOPT(DIRLISTONLY);					// LONG
	Gura_AssignValueCURLOPT(APPEND);						// LONG
	Gura_AssignValueCURLOPT(NETRC);							// LONG
	Gura_AssignValueCURLOPT(FOLLOWLOCATION);				// LONG
	Gura_AssignValueCURLOPT(TRANSFERTEXT);					// LONG
	Gura_AssignValueCURLOPT(PUT);							// LONG
	Gura_AssignValueCURLOPT(PROGRESSFUNCTION);				// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(PROGRESSDATA);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(AUTOREFERER);					// LONG
	Gura_AssignValueCURLOPT(PROXYPORT);						// LONG
	Gura_AssignValueCURLOPT(POSTFIELDSIZE);					// LONG
	Gura_AssignValueCURLOPT(HTTPPROXYTUNNEL);				// LONG
	Gura_AssignValueCURLOPT(INTERFACE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(KRBLEVEL);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSL_VERIFYPEER);				// LONG
	Gura_AssignValueCURLOPT(CAINFO);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(MAXREDIRS);						// LONG
	Gura_AssignValueCURLOPT(FILETIME);						// LONG
	Gura_AssignValueCURLOPT(TELNETOPTIONS);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(MAXCONNECTS);					// LONG
	Gura_AssignValueCURLOPT(CLOSEPOLICY);					// LONG
	Gura_AssignValueCURLOPT(FRESH_CONNECT);					// LONG
	Gura_AssignValueCURLOPT(FORBID_REUSE);					// LONG
	Gura_AssignValueCURLOPT(RANDOM_FILE);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(EGDSOCKET);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(CONNECTTIMEOUT);				// LONG
	Gura_AssignValueCURLOPT(HEADERFUNCTION);				// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(HTTPGET);						// LONG
	Gura_AssignValueCURLOPT(SSL_VERIFYHOST);				// LONG
	Gura_AssignValueCURLOPT(COOKIEJAR);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSL_CIPHER_LIST);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(HTTP_VERSION);					// LONG
	Gura_AssignValueCURLOPT(FTP_USE_EPSV);					// LONG
	Gura_AssignValueCURLOPT(SSLCERTTYPE);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSLKEY);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSLKEYTYPE);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSLENGINE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSLENGINE_DEFAULT);				// LONG
	Gura_AssignValueCURLOPT(DNS_USE_GLOBAL_CACHE);			// LONG
	Gura_AssignValueCURLOPT(DNS_CACHE_TIMEOUT);				// LONG
	Gura_AssignValueCURLOPT(PREQUOTE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(DEBUGFUNCTION);					// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(DEBUGDATA);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(COOKIESESSION);					// LONG
	Gura_AssignValueCURLOPT(CAPATH);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(BUFFERSIZE);					// LONG
	Gura_AssignValueCURLOPT(NOSIGNAL);						// LONG
	Gura_AssignValueCURLOPT(SHARE);							// OBJECTPOINT
	Gura_AssignValueCURLOPT(PROXYTYPE);						// LONG
#if defined(CURLOPT_ACCEPT_ENCODING)
	Gura_AssignValueCURLOPT(ACCEPT_ENCODING);				// OBJECTPOINT
#endif
	Gura_AssignValueCURLOPT(PRIVATE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(HTTP200ALIASES);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(UNRESTRICTED_AUTH);				// LONG
	Gura_AssignValueCURLOPT(FTP_USE_EPRT);					// LONG
	Gura_AssignValueCURLOPT(HTTPAUTH);						// LONG
	Gura_AssignValueCURLOPT(SSL_CTX_FUNCTION);				// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(SSL_CTX_DATA);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(FTP_CREATE_MISSING_DIRS);		// LONG
	Gura_AssignValueCURLOPT(PROXYAUTH);						// LONG
	Gura_AssignValueCURLOPT(FTP_RESPONSE_TIMEOUT);			// LONG
	Gura_AssignValueCURLOPT(IPRESOLVE);						// LONG
	Gura_AssignValueCURLOPT(MAXFILESIZE);					// LONG
	Gura_AssignValueCURLOPT(INFILESIZE_LARGE);				// OFF_T
	Gura_AssignValueCURLOPT(RESUME_FROM_LARGE);				// OFF_T
	Gura_AssignValueCURLOPT(MAXFILESIZE_LARGE);				// OFF_T
	Gura_AssignValueCURLOPT(NETRC_FILE);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(USE_SSL);						// LONG
	Gura_AssignValueCURLOPT(POSTFIELDSIZE_LARGE);			// OFF_T
	Gura_AssignValueCURLOPT(TCP_NODELAY);					// LONG
	Gura_AssignValueCURLOPT(FTPSSLAUTH);					// LONG
	Gura_AssignValueCURLOPT(IOCTLFUNCTION);					// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(IOCTLDATA);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(FTP_ACCOUNT);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(COOKIELIST);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(IGNORE_CONTENT_LENGTH);			// LONG
	Gura_AssignValueCURLOPT(FTP_SKIP_PASV_IP);				// LONG
	Gura_AssignValueCURLOPT(FTP_FILEMETHOD);				// LONG
	Gura_AssignValueCURLOPT(LOCALPORT);						// LONG
	Gura_AssignValueCURLOPT(LOCALPORTRANGE);				// LONG
	Gura_AssignValueCURLOPT(CONNECT_ONLY);					// LONG
	Gura_AssignValueCURLOPT(CONV_FROM_NETWORK_FUNCTION);	// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(CONV_TO_NETWORK_FUNCTION);		// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(CONV_FROM_UTF8_FUNCTION);		// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(MAX_SEND_SPEED_LARGE);			// OFF_T
	Gura_AssignValueCURLOPT(MAX_RECV_SPEED_LARGE);			// OFF_T
	Gura_AssignValueCURLOPT(FTP_ALTERNATIVE_TO_USER);		// OBJECTPOINT
	Gura_AssignValueCURLOPT(SOCKOPTFUNCTION);				// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(SOCKOPTDATA);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSL_SESSIONID_CACHE);			// LONG
	Gura_AssignValueCURLOPT(SSH_AUTH_TYPES);				// LONG
	Gura_AssignValueCURLOPT(SSH_PUBLIC_KEYFILE);			// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSH_PRIVATE_KEYFILE);			// OBJECTPOINT
	Gura_AssignValueCURLOPT(FTP_SSL_CCC);					// LONG
	Gura_AssignValueCURLOPT(TIMEOUT_MS);					// LONG
	Gura_AssignValueCURLOPT(CONNECTTIMEOUT_MS);				// LONG
	Gura_AssignValueCURLOPT(HTTP_TRANSFER_DECODING);		// LONG
	Gura_AssignValueCURLOPT(HTTP_CONTENT_DECODING);			// LONG
	Gura_AssignValueCURLOPT(NEW_FILE_PERMS);				// LONG
	Gura_AssignValueCURLOPT(NEW_DIRECTORY_PERMS);			// LONG
	Gura_AssignValueCURLOPT(POSTREDIR);						// LONG
	Gura_AssignValueCURLOPT(SSH_HOST_PUBLIC_KEY_MD5);		// OBJECTPOINT
	Gura_AssignValueCURLOPT(OPENSOCKETFUNCTION);			// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(OPENSOCKETDATA);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(COPYPOSTFIELDS);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(PROXY_TRANSFER_MODE);			// LONG
	Gura_AssignValueCURLOPT(SEEKFUNCTION);					// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(SEEKDATA);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(CRLFILE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(ISSUERCERT);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(ADDRESS_SCOPE);					// LONG
	Gura_AssignValueCURLOPT(CERTINFO);						// LONG
	Gura_AssignValueCURLOPT(USERNAME);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(PASSWORD);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(PROXYUSERNAME);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(PROXYPASSWORD);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(NOPROXY);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(TFTP_BLKSIZE);					// LONG
	Gura_AssignValueCURLOPT(SOCKS5_GSSAPI_SERVICE);			// OBJECTPOINT
	Gura_AssignValueCURLOPT(SOCKS5_GSSAPI_NEC);				// LONG
	Gura_AssignValueCURLOPT(PROTOCOLS);						// LONG
	Gura_AssignValueCURLOPT(REDIR_PROTOCOLS);				// LONG
	Gura_AssignValueCURLOPT(SSH_KNOWNHOSTS);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(SSH_KEYFUNCTION);				// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(SSH_KEYDATA);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(MAIL_FROM);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(MAIL_RCPT);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(FTP_USE_PRET);					// LONG
	Gura_AssignValueCURLOPT(RTSP_REQUEST);					// LONG
	Gura_AssignValueCURLOPT(RTSP_SESSION_ID);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(RTSP_STREAM_URI);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(RTSP_TRANSPORT);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(RTSP_CLIENT_CSEQ);				// LONG
	Gura_AssignValueCURLOPT(RTSP_SERVER_CSEQ);				// LONG
	Gura_AssignValueCURLOPT(INTERLEAVEDATA);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(INTERLEAVEFUNCTION);			// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(WILDCARDMATCH);					// LONG
	Gura_AssignValueCURLOPT(CHUNK_BGN_FUNCTION);			// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(CHUNK_END_FUNCTION);			// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(FNMATCH_FUNCTION);				// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(CHUNK_DATA);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(FNMATCH_DATA);					// OBJECTPOINT
#if defined(CURLOPT_RESOLVE)
	Gura_AssignValueCURLOPT(RESOLVE);						// OBJECTPOINT
#endif
#if defined(CURLOPT_TLSAUTH_USERNAME)
	Gura_AssignValueCURLOPT(TLSAUTH_USERNAME);				// OBJECTPOINT
#endif
#if defined(CURLOPT_TLSAUTH_PASSWORD)
	Gura_AssignValueCURLOPT(TLSAUTH_PASSWORD);				// OBJECTPOINT
#endif
#if defined(CURLOPT_TLSAUTH_TYPE)
	Gura_AssignValueCURLOPT(TLSAUTH_TYPE);					// OBJECTPOINT
#endif
#if defined(CURLOPT_TRANSFER_ENCODING)
	Gura_AssignValueCURLOPT(TRANSFER_ENCODING);				// LONG
#endif
#if defined(CURLOPT_CLOSESOCKETFUNCTION)
	Gura_AssignValueCURLOPT(CLOSESOCKETFUNCTION);			// FUNCTIONPOINT
#endif
#if defined(CURLOPT_CLOSESOCKETDATA)
	Gura_AssignValueCURLOPT(CLOSESOCKETDATA);				// OBJECTPOINT
#endif
#if defined(CURLOPT_GSSAPI_DELEGATION)
	Gura_AssignValueCURLOPT(GSSAPI_DELEGATION);				// LONG
#endif
#if defined(CURLOPT_DNS_SERVERS)
	Gura_AssignValueCURLOPT(DNS_SERVERS);					// OBJECTPOINT
#endif
#if defined(CURLOPT_ACCEPTTIMEOUT_MS)
	Gura_AssignValueCURLOPT(ACCEPTTIMEOUT_MS);				// LONG
#endif
#if defined(CURLOPT_TCP_KEEPALIVE)
	Gura_AssignValueCURLOPT(TCP_KEEPALIVE);					// LONG
#endif
#if defined(CURLOPT_TCP_KEEPIDLE)
	Gura_AssignValueCURLOPT(TCP_KEEPIDLE);					// LONG
#endif
#if defined(CURLOPT_TCP_KEEPINTVL)
	Gura_AssignValueCURLOPT(TCP_KEEPINTVL);					// LONG
#endif
#if defined(CURLOPT_SSL_OPTIONS)
	Gura_AssignValueCURLOPT(SSL_OPTIONS);					// LONG
#endif
#if defined(CURLOPT_MAIL_AUTH)
	Gura_AssignValueCURLOPT(MAIL_AUTH);						// OBJECTPOINT
#endif
	Gura_AssignValueCURLOPT(ENCODING);
	Gura_AssignValueCURLOPT(SERVER_RESPONSE_TIMEOUT);
	Gura_AssignValueCURLOPT(POST301);
	Gura_AssignValueCURLOPT(SSLKEYPASSWD);
	Gura_AssignValueCURLOPT(FTPAPPEND);
	Gura_AssignValueCURLOPT(FTPLISTONLY);
	Gura_AssignValueCURLOPT(FTP_SSL);
	Gura_AssignValueCURLOPT(SSLCERTPASSWD);
	Gura_AssignValueCURLOPT(KRB4LEVEL);
	Gura_AssignValueCURLOPT(WRITEDATA);
	Gura_AssignValueCURLOPT(READDATA);
	Gura_AssignValueCURLOPT(HEADERDATA);
	Gura_AssignValueCURLOPT(RTSPHEADER);
	// CURLformoption
	Gura_AssignValueCURLFORM(NOTHING);
	Gura_AssignValueCURLFORM(COPYNAME);
	Gura_AssignValueCURLFORM(PTRNAME);
	Gura_AssignValueCURLFORM(NAMELENGTH);
	Gura_AssignValueCURLFORM(COPYCONTENTS);
	Gura_AssignValueCURLFORM(PTRCONTENTS);
	Gura_AssignValueCURLFORM(CONTENTSLENGTH);
	Gura_AssignValueCURLFORM(FILECONTENT);
	Gura_AssignValueCURLFORM(ARRAY);
	Gura_AssignValueCURLFORM(OBSOLETE);
	Gura_AssignValueCURLFORM(FILE);
	Gura_AssignValueCURLFORM(BUFFER);
	Gura_AssignValueCURLFORM(BUFFERPTR);
	Gura_AssignValueCURLFORM(BUFFERLENGTH);
	Gura_AssignValueCURLFORM(CONTENTTYPE);
	Gura_AssignValueCURLFORM(CONTENTHEADER);
	Gura_AssignValueCURLFORM(FILENAME);
	Gura_AssignValueCURLFORM(END);
	Gura_AssignValueCURLFORM(OBSOLETE2);
	Gura_AssignValueCURLFORM(STREAM);
	// bitmask of easy_handle#pause
	Gura_AssignValuePAUSE(RECV);
	Gura_AssignValuePAUSE(RECV_CONT);
	Gura_AssignValuePAUSE(SEND);
	Gura_AssignValuePAUSE(SEND_CONT);
	Gura_AssignValuePAUSE(ALL);
	Gura_AssignValuePAUSE(CONT);
	// version information
	Gura_AssignValueVERSION(IPV6);
	Gura_AssignValueVERSION(KERBEROS4);
	Gura_AssignValueVERSION(SSL);
	Gura_AssignValueVERSION(LIBZ);
	Gura_AssignValueVERSION(NTLM);
	Gura_AssignValueVERSION(GSSNEGOTIATE);
	Gura_AssignValueVERSION(DEBUG);
	Gura_AssignValueVERSION(ASYNCHDNS);
	Gura_AssignValueVERSION(SPNEGO);
	Gura_AssignValueVERSION(LARGEFILE);
	Gura_AssignValueVERSION(IDN);
	Gura_AssignValueVERSION(SSPI);
	Gura_AssignValueVERSION(CONV);
	Gura_AssignValueVERSION(CURLDEBUG);
#if defined(CURL_VERSION_TLSAUTH_SRP)
	Gura_AssignValueVERSION(TLSAUTH_SRP);
#endif
#if defined(CURL_VERSION_NTLM_WB)
	Gura_AssignValueVERSION(NTLM_WB);
#endif
	// function assignment
	Gura_AssignFunction(version);
	Gura_AssignFunction(easy_init);
	Gura_AssignFunction(opendir);
	Gura_AssignFunction(set_timeout);
	// registration of directory factory
	PathMgr::Register(env, new PathMgr_cURL());
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Directory_cURL implementation
//-----------------------------------------------------------------------------
Directory_cURL::Directory_cURL(Directory *pParent, const char *name, Type type, Fileinfo *pFileinfo) :
	Directory(pParent, name, type, '/', false), _pFileinfo(pFileinfo)
{
}

Directory_cURL::~Directory_cURL()
{
}

Directory *Directory_cURL::DoNext(Environment &env)
{
	Signal &sig = env.GetSignal();
	if (_pFileinfoOwner.get() == nullptr) {
		_pFileinfoOwner.reset(DoBrowse(env));
		if (sig.IsSignalled()) return nullptr;
		_ppFileinfo = _pFileinfoOwner->begin();
	}
	if (_ppFileinfo == _pFileinfoOwner->end()) return nullptr;
	Fileinfo *pFileinfo = *_ppFileinfo++;
	Type type = (pFileinfo->GetFiletype() == CURLFILETYPE_DIRECTORY)? TYPE_Container : TYPE_Item;
	return new Directory_cURL(Directory::Reference(this), pFileinfo->GetFilename(), type, pFileinfo->Reference());
}

Stream *Directory_cURL::DoOpenStream(Environment &env, UInt32 attr)
{
	Signal &sig = env.GetSignal();
	AutoPtr<StreamFIFO> pStreamFIFO(new StreamFIFO(env, 65536));
	AutoPtr<StreamFIFO> pStreamFIFORtn(new StreamFIFO(env, pStreamFIFO->GetEntity()->Reference()));
	// pThread will automatically be deleted after the thread is done.
	OAL::Thread *pThread = nullptr;
	if (attr & Stream::ATTR_Writable) {
		pThread = new Uploader(sig, GetName(), pStreamFIFO.release());
	} else {
		pThread = new Downloader(sig, GetName(), pStreamFIFO.release());
	}
	pThread->Start();
	return pStreamFIFORtn.release();
}

Object *Directory_cURL::DoGetStatObj(Signal &sig)
{
	return (_pFileinfo.get() == nullptr)? nullptr : new Object_Stat(_pFileinfo->Reference());
}

FileinfoOwner *Directory_cURL::DoBrowse(Environment &env)
{
	g_pSemaphoreCurl->Wait();
	std::unique_ptr<FileinfoOwner> pFileinfoOwner(new FileinfoOwner());
	CURL *curl = ::curl_easy_init();
	if (curl == nullptr) {
		g_pSemaphoreCurl->Release();
		return nullptr;
	}
	String dirName = MakePathName(true, nullptr);
	String url = dirName + "*";
	::curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	::curl_easy_setopt(curl, CURLOPT_WILDCARDMATCH, 1L);
	std::unique_ptr<Browser> pBrowser(new Browser(env, *pFileinfoOwner, dirName));
	::curl_easy_setopt(curl, CURLOPT_CHUNK_DATA, pBrowser.get());
	::curl_easy_setopt(curl, CURLOPT_CHUNK_BGN_FUNCTION, Browser::OnChunkBgnStub);
	::curl_easy_setopt(curl, CURLOPT_CHUNK_END_FUNCTION, Browser::OnChunkEndStub);
	//::curl_easy_setopt(curl, CURLOPT_FILETIME, 1L);
	if (g_valueTimeout.Is_number()) {
		::curl_easy_setopt(curl, CURLOPT_TIMEOUT, g_valueTimeout.GetLong());
	}
	CURLcode code = ::curl_easy_perform(curl);
	if(code != CURLE_OK && code != CURLE_REMOTE_FILE_NOT_FOUND) {
		// CURLE_REMOTE_FILE_NOT_FOUND is returned when a directory is empty
		SetError_Curl(env, code);
		::curl_easy_cleanup(curl);
		g_pSemaphoreCurl->Release();
		return nullptr;
	}
	::curl_easy_cleanup(curl);
	g_pSemaphoreCurl->Release();
	return pFileinfoOwner.release();
}

//-----------------------------------------------------------------------------
// PathMgr_cURL implementation
//-----------------------------------------------------------------------------
bool PathMgr_cURL::IsResponsible(Environment &env,
						const Directory *pParent, const char *pathName)
{
	return pParent == nullptr && (
			StartsWith(pathName, "http:", 0, false) ||
			StartsWith(pathName, "https:", 0, false) ||
			StartsWith(pathName, "ftp:", 0, false) ||
			StartsWith(pathName, "ftps:", 0, false) ||
			StartsWith(pathName, "sftp:", 0, false));
}

Directory *PathMgr_cURL::DoOpenDirectory(Environment &env,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode)
{
	const char *uri = *pPathName;
	size_t len = ::strlen(uri);
	Directory::Type type = (len > 0 && IsFileSeparator(uri[len - 1]))?
		Directory::TYPE_Container : Directory::TYPE_Item;
	AutoPtr<Directory> pDirectory(new Directory_cURL(Directory::Reference(pParent), uri, type, nullptr));
	*pPathName = uri + len;
	return pDirectory.release();
}

//-----------------------------------------------------------------------------
// Object_easy_handle implementation
//-----------------------------------------------------------------------------
Object_easy_handle::~Object_easy_handle()
{
	if (_curl != nullptr) {
		//::curl_easy_cleanup(_curl);
	}
}

Object *Object_easy_handle::Clone() const
{
	return nullptr;
}

String Object_easy_handle::ToString(bool exprFlag)
{
	String str;
	str += "<curl.easy_handle:";
	if (_curl == nullptr) {
		str += "invalid";
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// curl.easy_handle#surface
Gura_DeclareProperty_R(easy_handle, surface)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(easy_handle, surface)
{
	//return Value(Object_surface::Reference(_pObjSurface.get()));
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for easy_handle
// easy_handle operations
//-----------------------------------------------------------------------------
// curl.easy_handle#escape(string:string):void
Gura_DeclareMethod(easy_handle, escape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "string", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, escape)
{
	Object_easy_handle *pThis = Object_easy_handle::GetObjectThis(arg);
	const String str = arg.GetStringSTL(0);
	const char *rtn = ::curl_easy_escape(pThis->GetEntity(),
							str.c_str(), static_cast<int>(str.size()));
	return Value(rtn);
}

// curl.easy_handle#getinfo(info:number)
Gura_DeclareMethod(easy_handle, getinfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "info", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, getinfo)
{
	Signal &sig = env.GetSignal();
	Object_easy_handle *pThis = Object_easy_handle::GetObjectThis(arg);
	CURLcode code;
	CURLINFO info = static_cast<CURLINFO>(arg.GetInt(0));
	int infoType = arg.GetInt(0) & CURLINFO_TYPEMASK;
	if (infoType == CURLINFO_STRING) {
		const char *rtn = nullptr;
		code = ::curl_easy_getinfo(pThis->GetEntity(), info, &rtn);
		if (code != CURLE_OK) {
			SetError_Curl(sig, code);
			return Value::Nil;
		}
		return Value(rtn);
	} else if (infoType == CURLINFO_LONG) {
		long rtn = 0;
		code = ::curl_easy_getinfo(pThis->GetEntity(), info, &rtn);
		if (code != CURLE_OK) {
			SetError_Curl(sig, code);
			return Value::Nil;
		}
		return Value(static_cast<Int32>(rtn));
	} else if (infoType == CURLINFO_DOUBLE) {
		double rtn = 0;
		code = ::curl_easy_getinfo(pThis->GetEntity(), info, &rtn);
		if (code != CURLE_OK) {
			SetError_Curl(sig, code);
			return Value::Nil;
		}
		return Value(rtn);
	} else if (infoType == CURLINFO_SLIST) {
		// not implemented yet
	}
	sig.SetError(ERR_ValueError, "invalid value for info");
	return Value::Nil;
}

// curl.easy_handle#pause(bitmask:number):void
Gura_DeclareMethod(easy_handle, pause)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "bitmask", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, pause)
{
	Object_easy_handle *pThis = Object_easy_handle::GetObjectThis(arg);
	int bitmask = arg.GetInt(0);
	CURLcode code = ::curl_easy_pause(pThis->GetEntity(), bitmask);
	
	return Value::Nil;
}

#if 0
// curl.easy_handle#perform(stream?:stream:w):void
Gura_DeclareMethod(easy_handle, perform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, perform)
{
	return Value::Nil;
}
#endif

// curl.easy_handle#recv(buflen:number)
Gura_DeclareMethod(easy_handle, recv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "buflen", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, recv)
{
	Signal &sig = env.GetSignal();
	Object_easy_handle *pThis = Object_easy_handle::GetObjectThis(arg);
	size_t buflen = arg.GetSizeT(0);
	if (buflen == 0) return Value::Nil;
	AutoPtr<Memory> pMemory(new MemoryHeap(buflen));
	size_t n = 0;
	CURLcode code = ::curl_easy_recv(pThis->GetEntity(), pMemory->GetPointer(), buflen, &n);
	if (code != CURLE_OK) {
		SetError_Curl(sig, code);
		return Value::Nil;
	}
	return new Object_binary(env, pMemory->GetPointer(), n);
}

// curl.easy_handle#reset():void
Gura_DeclareMethod(easy_handle, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, reset)
{
	Object_easy_handle *pThis = Object_easy_handle::GetObjectThis(arg);
	::curl_easy_reset(pThis->GetEntity());
	return Value::Nil;
}

// curl.easy_handle#send(buffer:binary)
Gura_DeclareMethod(easy_handle, send)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "buffer", VTYPE_binary);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, send)
{
	Signal &sig = env.GetSignal();
	Object_easy_handle *pThis = Object_easy_handle::GetObjectThis(arg);
	const Binary &buffer = arg.GetBinary(0);
	size_t n = 0;
	CURLcode code = ::curl_easy_send(pThis->GetEntity(), buffer.data(), buffer.size(), &n);
	if (code != CURLE_OK) {
		SetError_Curl(sig, code);
		return Value::Nil;
	}
	return Value(n);
}

// curl.easy_handle#setopt(option:number, arg):void
Gura_DeclareMethod(easy_handle, setopt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "option", VTYPE_number);
	DeclareArg(env, "arg", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, setopt)
{
	Signal &sig = env.GetSignal();
	Object_easy_handle *pThis = Object_easy_handle::GetObjectThis(arg);
	CURLcode code;
	CURLoption option = static_cast<CURLoption>(arg.GetInt(0));
	if (arg.Is_number(1)) {
		if (!(option < CURLOPTTYPE_OBJECTPOINT || CURLOPTTYPE_OFF_T <= option)) {
			sig.SetError(ERR_TypeError, "number cannot be specified for the option");
			return Value::Nil;
		}
		code = ::curl_easy_setopt(pThis->GetEntity(), option, arg.GetInt(1));
	} else if (arg.Is_string(1)) {
		if (!(CURLOPTTYPE_OBJECTPOINT <= option && option < CURLOPTTYPE_FUNCTIONPOINT)) {
			sig.SetError(ERR_TypeError, "string cannot be specified for the option");
			return Value::Nil;
		}
		code = ::curl_easy_setopt(pThis->GetEntity(), option, arg.GetString(1));
	} else {
		Declaration::SetError_InvalidArgument(env);
		return Value::Nil;
	}
	if (code != CURLE_OK) SetError_Curl(sig, code);
	return Value::Nil;
}

// curl.easy_handle#unescape(string:string):void
Gura_DeclareMethod(easy_handle, unescape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "string", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(easy_handle, unescape)
{
	Object_easy_handle *pThis = Object_easy_handle::GetObjectThis(arg);
	const String str = arg.GetStringSTL(0);
	int outlength = 0;
	const char *rtn = ::curl_easy_unescape(pThis->GetEntity(),
					str.c_str(), static_cast<int>(str.size()), &outlength);
	return Value(rtn, outlength);
}

// implementation of class easy_handle
Gura_ImplementUserClass(easy_handle)
{
	// Assignment of properties
	//Gura_AssignProperty(easy_handle, surface);
	// Assignment of methods
	Gura_AssignMethod(easy_handle, escape);
	Gura_AssignMethod(easy_handle, getinfo);
	//Gura_AssignMethod(easy_handle, perform);
	Gura_AssignMethod(easy_handle, recv);
	Gura_AssignMethod(easy_handle, reset);
	Gura_AssignMethod(easy_handle, send);
	Gura_AssignMethod(easy_handle, setopt);
	Gura_AssignMethod(easy_handle, unescape);
}

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
	return String("<curl.stat>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// curl.Stat#atime
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	bool utcFlag = true;
	return Value(new Object_datetime(env, OAL::ToDateTime(pFileinfo->GetTime(), utcFlag)));
}

// curl.Stat#ctime
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	bool utcFlag = true;
	return Value(new Object_datetime(env, OAL::ToDateTime(pFileinfo->GetTime(), utcFlag)));
}

// curl.Stat#dirname
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	return Value(pFileinfo->GetDirname());
}

// curl.Stat#filename
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	return Value(pFileinfo->GetFilename());
}

// curl.Stat#gid
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	return Value(pFileinfo->GetGid());
}

// curl.Stat#mtime
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	bool utcFlag = true;
	return Value(new Object_datetime(env, OAL::ToDateTime(pFileinfo->GetTime(), utcFlag)));
}

// curl.Stat#pathname
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	String pathName = pFileinfo->GetDirname();
	pathName += pFileinfo->GetFilename();
	if (pFileinfo->GetFiletype() == CURLFILETYPE_DIRECTORY) pathName += '/';
	return Value(pathName.c_str());
}

// curl.Stat#size
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	return Value(pFileinfo->GetSize());
}

// curl.Stat#uid
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
	const Fileinfo *pFileinfo = Object_Stat::GetObject(valueThis)->GetFileinfo();
	return Value(pFileinfo->GetUid());
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
	Gura_AssignProperty(Stat, mtime);
	Gura_AssignProperty(Stat, pathname);
	Gura_AssignProperty(Stat, size);
	Gura_AssignProperty(Stat, uid);
#if 0
	Gura_AssignProperty(Stat, isblk);
	Gura_AssignProperty(Stat, ischr);
	Gura_AssignProperty(Stat, isdir);
	Gura_AssignProperty(Stat, isfifo);
	Gura_AssignProperty(Stat, islnk);
	Gura_AssignProperty(Stat, isreg);
	Gura_AssignProperty(Stat, issock);
#endif
}

Gura_EndModuleBody(curl, curl)

Gura_RegisterModule(curl)
