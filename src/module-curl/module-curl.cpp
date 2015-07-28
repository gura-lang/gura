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
// utility functions
//-----------------------------------------------------------------------------
void SetError_Curl(Signal &sig, CURLcode code)
{
	sig.SetError(ERR_RuntimeError, "%s", ::curl_easy_strerror(code));
}

//-----------------------------------------------------------------------------
// Fileinfo
//-----------------------------------------------------------------------------
Fileinfo::Fileinfo(const struct curl_fileinfo *finfo) :
			_filename(finfo->filename),
			_filetype(finfo->filetype),
			_time(finfo->time),
			_perm(finfo->perm),
			_uid(finfo->uid),
			_gid(finfo->gid),
			_size(finfo->size),
			_hardlinks(finfo->hardlinks)
{
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
		delete pFileinfo;
	}
	clear();
}

//-----------------------------------------------------------------------------
// Browser
//-----------------------------------------------------------------------------
Browser::Browser(Signal &sig, FileinfoOwner &fileinfoOwner) :
									_sig(sig), _fileinfoOwner(fileinfoOwner)
{
}

long Browser::OnChunkBgn(struct curl_fileinfo *finfo, int remains)
{
	_fileinfoOwner.push_back(new Fileinfo(finfo));
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
// Writer
//-----------------------------------------------------------------------------
Writer::Writer(Signal &sig, Stream *pStream) : _sig(sig), _pStream(pStream)
{
}

size_t Writer::OnWrite(char *buffer, size_t size, size_t nitems)
{
	//::printf("OnWrite(%d)\n", nitems);
	return _pStream->Write(_sig, buffer, size * nitems);
}

size_t Writer::OnWriteStub(char *buffer, size_t size, size_t nitems, void *outstream)
{
	Writer *pWriter = reinterpret_cast<Writer *>(outstream);
	return pWriter->OnWrite(buffer, size, nitems);
}

//-----------------------------------------------------------------------------
// Reader
//-----------------------------------------------------------------------------
Reader::Reader(Signal &sig, Stream *pStream) : _sig(sig), _pStream(pStream)
{
}

size_t Reader::OnRead(char *buffer, size_t size, size_t nitems)
{
	return _pStream->Read(_sig, buffer, size * nitems);
}

int Reader::OnSeek(curl_off_t offset, int origin)
{
	return 0;
}

size_t Reader::OnReadStub(char *buffer, size_t size, size_t nitems, void *instream)
{
	Reader *pReader = reinterpret_cast<Reader *>(instream);
	return pReader->OnRead(buffer, size, nitems);
}

int Reader::OnSeekStub(void *instream, curl_off_t offset, int origin)
{
	Reader *pReader = reinterpret_cast<Reader *>(instream);
	return pReader->OnSeek(offset, origin);
}

int fnmatch_callback(void *ptr, const char *pattern, const char *string)
{
	return 0;
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
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a string of the libcurl version.");
}

Gura_ImplementFunction(version)
{
	const char *rtn = ::curl_version();
	return ReturnValue(env, args, Value(rtn));
}

// curl.easy_init() {block?}
Gura_DeclareFunction(easy_init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Initializes cURL and returns a easy_handle object.");
}

Gura_ImplementFunction(easy_init)
{
	CURL *curl = ::curl_easy_init();
	return ReturnValue(env, args, Value(new Object_easy_handle(curl)));
}

// curl.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(test)
{
	CURLcode code;
	CURL *curl = ::curl_easy_init();
	if (curl == nullptr) return Value::Null;
	::curl_easy_setopt(curl, CURLOPT_URL, "ftp://ftp.debian.org/debian/*");
	::curl_easy_setopt(curl, CURLOPT_WILDCARDMATCH, 1L);
	std::unique_ptr<FileinfoOwner> pFileinfoOwner(new FileinfoOwner());
	std::unique_ptr<Browser> pBrowser(new Browser(sig, *pFileinfoOwner));
	::curl_easy_setopt(curl, CURLOPT_CHUNK_DATA, pBrowser.get());
	::curl_easy_setopt(curl, CURLOPT_CHUNK_BGN_FUNCTION, Browser::OnChunkBgnStub);
	::curl_easy_setopt(curl, CURLOPT_CHUNK_END_FUNCTION, Browser::OnChunkEndStub);
	code = ::curl_easy_perform(curl);
	if(code == CURLE_OK) {
		foreach (FileinfoOwner, ppFileinfo, *pFileinfoOwner) {
			Fileinfo *pFileinfo = *ppFileinfo;
			curlfiletype filetype = pFileinfo->GetFiletype();
			::printf("%-40s %10luB %s\n", pFileinfo->GetFilename(),
				static_cast<ULong>(pFileinfo->GetSize()),
				(filetype == CURLFILETYPE_DIRECTORY)? "DIR" :
				(filetype == CURLFILETYPE_FILE)? "FILE" : "OTHER");
		}
	} else {
		::fprintf(stderr, "curl_easy_perform() failed: %s\n",
										::curl_easy_strerror(code));
	}
	::curl_easy_cleanup(curl);
	::curl_global_cleanup();
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeAndPrepareUserClass(easy_handle, env.LookupClass(VTYPE_object));
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
	Gura_AssignFunction(test);
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
Directory_cURL::Directory_cURL(Directory *pParent, const char *name, Type type) :
							Directory(pParent, name, type, '/')
{
}

Directory_cURL::~Directory_cURL()
{
}

Directory *Directory_cURL::DoNext(Environment &env, Signal &sig)
{
	if (_pFileinfoOwner.get() == nullptr) {
		_pFileinfoOwner.reset(DoBrowse(sig));
		if (sig.IsSignalled()) return nullptr;
		_ppFileinfo = _pFileinfoOwner->begin();
	}
	if (_ppFileinfo == _pFileinfoOwner->end()) return nullptr;
	Fileinfo *pFileinfo = *_ppFileinfo++;
	Type type = (pFileinfo->GetFiletype() == CURLFILETYPE_DIRECTORY)?
												TYPE_Container : TYPE_Item;
	return new Directory_cURL(Directory::Reference(this),
										pFileinfo->GetFilename(), type);
}

Stream *Directory_cURL::DoOpenStream(Environment &env, Signal &sig, ULong attr)
{
	AutoPtr<StreamFIFO> pStream(new StreamFIFO(env, sig, 65536));
	// pThread will automatically be deleted after the thread is done.
	Thread *pThread = new Thread(sig, GetName(),
				dynamic_cast<StreamFIFO *>(Stream::Reference(pStream.get())));
	pThread->Start();
	return pStream.release();
}

FileinfoOwner *Directory_cURL::DoBrowse(Signal &sig)
{
	std::unique_ptr<FileinfoOwner> pFileinfoOwner(new FileinfoOwner());
	CURL *curl = ::curl_easy_init();
	if (curl == nullptr) return nullptr;
	String url = OAL::JoinPathName('/', MakePathName(false, nullptr).c_str(), "*");
	::curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	::curl_easy_setopt(curl, CURLOPT_WILDCARDMATCH, 1L);
	std::unique_ptr<Browser> pBrowser(new Browser(sig, *pFileinfoOwner));
	::curl_easy_setopt(curl, CURLOPT_CHUNK_DATA, pBrowser.get());
	::curl_easy_setopt(curl, CURLOPT_CHUNK_BGN_FUNCTION, Browser::OnChunkBgnStub);
	::curl_easy_setopt(curl, CURLOPT_CHUNK_END_FUNCTION, Browser::OnChunkEndStub);
	CURLcode code = ::curl_easy_perform(curl);
	if(code != CURLE_OK) {
		SetError_Curl(sig, code);
		::curl_easy_cleanup(curl);
		::curl_global_cleanup();
		return nullptr;
	}
	::curl_easy_cleanup(curl);
	::curl_global_cleanup();
	return pFileinfoOwner.release();
}

void Directory_cURL::Thread::Run()
{
	CURL *curl = ::curl_easy_init();
	if (curl == nullptr) return;
	::curl_easy_setopt(curl, CURLOPT_URL, _name.c_str());
	::curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	std::unique_ptr<Writer> pWriter(new Writer(_sig, Stream::Reference(_pStreamFIFO.get())));
	::curl_easy_setopt(curl, CURLOPT_WRITEDATA, pWriter.get());
	::curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Writer::OnWriteStub);
	CURLcode code = ::curl_easy_perform(curl);
	if (code != CURLE_OK) SetError_Curl(_sig, code);
	//::curl_easy_cleanup(curl);
	_pStreamFIFO->SetWriteDoneFlag();
}

//-----------------------------------------------------------------------------
// PathMgr_cURL implementation
//-----------------------------------------------------------------------------
bool PathMgr_cURL::IsResponsible(Environment &env, Signal &sig,
						const Directory *pParent, const char *pathName)
{
	return pParent == nullptr && (
			StartsWith(pathName, "http:", 0, false) ||
			StartsWith(pathName, "https:", 0, false) ||
			StartsWith(pathName, "ftp:", 0, false) ||
			StartsWith(pathName, "ftps:", 0, false) ||
			StartsWith(pathName, "sftp:", 0, false));
}

Directory *PathMgr_cURL::DoOpenDirectory(Environment &env, Signal &sig,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode)
{
	const char *uri = *pPathName;
	size_t len = ::strlen(uri);
	Directory::Type type = (len > 0 && IsFileSeparator(uri[len - 1]))?
						Directory::TYPE_Container : Directory::TYPE_Item;
	AutoPtr<Directory> pDirectory(
				new Directory_cURL(Directory::Reference(pParent), uri, type));
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

bool Object_easy_handle::DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_UserSymbol(surface));
	//symbols.insert(Gura_UserSymbol(width));
	//symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_easy_handle::DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	//evaluatedFlag = true;
	//if (pSymbol->IsIdentical(Gura_UserSymbol(surface))) {
	//	return Value(Object_surface::Reference(_pObjSurface.get()));
	//}
	evaluatedFlag = false;
	return Value::Null;
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
// Gura interfaces for easy_handle
// easy_handle operations
//-----------------------------------------------------------------------------
// curl.easy_handle#escape(string:string):void
Gura_DeclareMethod(easy_handle, escape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "string", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, escape)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	const String str = args.GetStringSTL(0);
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
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, getinfo)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	CURLcode code;
	CURLINFO info = static_cast<CURLINFO>(args.GetInt(0));
	int infoType = args.GetInt(0) & CURLINFO_TYPEMASK;
	if (infoType == CURLINFO_STRING) {
		const char *rtn = nullptr;
		code = ::curl_easy_getinfo(pThis->GetEntity(), info, &rtn);
		if (code != CURLE_OK) {
			SetError_Curl(sig, code);
			return Value::Null;
		}
		return Value(rtn);
	} else if (infoType == CURLINFO_LONG) {
		long rtn = 0;
		code = ::curl_easy_getinfo(pThis->GetEntity(), info, &rtn);
		if (code != CURLE_OK) {
			SetError_Curl(sig, code);
			return Value::Null;
		}
		return Value(rtn);
	} else if (infoType == CURLINFO_DOUBLE) {
		double rtn = 0;
		code = ::curl_easy_getinfo(pThis->GetEntity(), info, &rtn);
		if (code != CURLE_OK) {
			SetError_Curl(sig, code);
			return Value::Null;
		}
		return Value(rtn);
	} else if (infoType == CURLINFO_SLIST) {
		// not implemented yet
	}
	sig.SetError(ERR_ValueError, "invalid value for info");
	return Value::Null;
}

// curl.easy_handle#pause(bitmask:number):void
Gura_DeclareMethod(easy_handle, pause)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "bitmask", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, pause)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	int bitmask = args.GetInt(0);
	CURLcode code = ::curl_easy_pause(pThis->GetEntity(), bitmask);
	
	return Value::Null;
}

// curl.easy_handle#perform(stream?:stream:w):void
Gura_DeclareMethod(easy_handle, perform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, perform)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	Stream *pStreamOut = args.Is_stream(0)?
			&Object_stream::GetObject(args, 0)->GetStream() : env.GetConsole();
	std::unique_ptr<Writer> pWriter(new Writer(sig, Stream::Reference(pStreamOut)));
	::curl_easy_setopt(pThis->GetEntity(), CURLOPT_WRITEDATA, pWriter.get());
	::curl_easy_setopt(pThis->GetEntity(), CURLOPT_WRITEFUNCTION, Writer::OnWriteStub);
	CURLcode code = ::curl_easy_perform(pThis->GetEntity());
	if (code != CURLE_OK) SetError_Curl(sig, code);
	return Value::Null;
}

// curl.easy_handle#recv(buflen:number)
Gura_DeclareMethod(easy_handle, recv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "buflen", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, recv)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	size_t buflen = args.GetSizeT(0);
	if (buflen == 0) return Value::Null;
	AutoPtr<Memory> pMemory(new MemoryHeap(buflen));
	size_t n = 0;
	CURLcode code = ::curl_easy_recv(pThis->GetEntity(), pMemory->GetPointer(), buflen, &n);
	if (code != CURLE_OK) {
		SetError_Curl(sig, code);
		return Value::Null;
	}
	return new Object_binary(env, pMemory->GetPointer(), n);
}

// curl.easy_handle#reset():void
Gura_DeclareMethod(easy_handle, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, reset)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	::curl_easy_reset(pThis->GetEntity());
	return Value::Null;
}

// curl.easy_handle#send(buffer:binary)
Gura_DeclareMethod(easy_handle, send)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "buffer", VTYPE_binary);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, send)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	const Binary &buffer = args.GetBinary(0);
	size_t n = 0;
	CURLcode code = ::curl_easy_send(pThis->GetEntity(), buffer.data(), buffer.size(), &n);
	if (code != CURLE_OK) {
		SetError_Curl(sig, code);
		return Value::Null;
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
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, setopt)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	CURLcode code;
	CURLoption option = static_cast<CURLoption>(args.GetInt(0));
	if (args.Is_number(1)) {
		if (!(option < CURLOPTTYPE_OBJECTPOINT || CURLOPTTYPE_OFF_T <= option)) {
			sig.SetError(ERR_TypeError, "number cannot be specified for the option");
			return Value::Null;
		}
		code = ::curl_easy_setopt(pThis->GetEntity(), option, args.GetInt(1));
	} else if (args.Is_string(1)) {
		if (!(CURLOPTTYPE_OBJECTPOINT <= option && option < CURLOPTTYPE_FUNCTIONPOINT)) {
			sig.SetError(ERR_TypeError, "string cannot be specified for the option");
			return Value::Null;
		}
		code = ::curl_easy_setopt(pThis->GetEntity(), option, args.GetString(1));
	} else {
		Declaration::SetError_InvalidArgument(sig);
		return Value::Null;
	}
	if (code != CURLE_OK) SetError_Curl(sig, code);
	return Value::Null;
}

// curl.easy_handle#unescape(string:string):void
Gura_DeclareMethod(easy_handle, unescape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "string", VTYPE_string);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(easy_handle, unescape)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	const String str = args.GetStringSTL(0);
	int outlength = 0;
	const char *rtn = ::curl_easy_unescape(pThis->GetEntity(),
					str.c_str(), static_cast<int>(str.size()), &outlength);
	return Value(rtn, outlength);
}

// implementation of class easy_handle
Gura_ImplementUserClass(easy_handle)
{
	Gura_AssignMethod(easy_handle, escape);
	Gura_AssignMethod(easy_handle, getinfo);
	Gura_AssignMethod(easy_handle, perform);
	Gura_AssignMethod(easy_handle, recv);
	Gura_AssignMethod(easy_handle, reset);
	Gura_AssignMethod(easy_handle, send);
	Gura_AssignMethod(easy_handle, setopt);
	Gura_AssignMethod(easy_handle, unescape);
}

Gura_EndModuleBody(curl, curl)

Gura_RegisterModule(curl)
