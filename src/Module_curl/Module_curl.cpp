//-----------------------------------------------------------------------------
// Gura curl module
//-----------------------------------------------------------------------------
#include "Module_curl.h"

#define Gura_AssignValueCURLINFO(name) \
Gura_AssignValue(INFO_##name, Value(CURLINFO_##name))

#define Gura_AssignValueCURLE(name) \
Gura_AssignValue(E_##name, Value(CURLE_##name))

#define Gura_AssignValueCURLOPT(name) \
Gura_AssignValue(OPT_##name, Value(CURLOPT_##name))

#define Gura_AssignValueCURLFORM(name) \
Gura_AssignValue(FORM_##name, Value(CURLFORM_##name))

Gura_BeginModule(curl)

//-----------------------------------------------------------------------------
// Writer
//-----------------------------------------------------------------------------
Writer::Writer(Signal sig, Stream *pStream) : _sig(sig), _pStream(pStream)
{
}

size_t Writer::OnWrite(char *buffer, size_t size, size_t nitems) {
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
Reader::Reader(Signal sig, Stream *pStream) : _sig(sig), _pStream(pStream)
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
// curl.easy_init() {block?}
Gura_DeclareFunction(easy_init)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Initializes cURL and returns a easy_handle object.");
}

Gura_ImplementFunction(easy_init)
{
	CURL *curl = ::curl_easy_init();
	return ReturnValue(env, sig, args, Value(new Object_easy_handle(curl)));
}

// curl.test()
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "");
}

Gura_ImplementFunction(test)
{
	CURL *curl;
	CURLcode res;
	curl = ::curl_easy_init();
	if(curl) {
		::curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
		/* example.com is redirected, so we tell libcurl to follow redirection */ 
		::curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		res = ::curl_easy_perform(curl);
		if(res != CURLE_OK) {
			::fprintf(stderr, "curl_easy_perform() failed: %s\n",
											::curl_easy_strerror(res));
		}
		/* always cleanup */ 
		::curl_easy_cleanup(curl);
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(easy_handle, env.LookupClass(VTYPE_object));
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
	Gura_AssignValueCURLE(NOT_BUILT_IN);
	Gura_AssignValueCURLE(COULDNT_RESOLVE_PROXY);
	Gura_AssignValueCURLE(COULDNT_RESOLVE_HOST);
	Gura_AssignValueCURLE(COULDNT_CONNECT);
	Gura_AssignValueCURLE(FTP_WEIRD_SERVER_REPLY);
	Gura_AssignValueCURLE(REMOTE_ACCESS_DENIED);
#if 0
	Gura_AssignValueCURLE(FTP_ACCEPT_FAILED);
#endif
	Gura_AssignValueCURLE(FTP_WEIRD_PASS_REPLY);
#if 0
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
	Gura_AssignValueCURLE(UNKNOWN_OPTION);
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
#if 0
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
	Gura_AssignValueCURLOPT(ACCEPT_ENCODING);				// OBJECTPOINT
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
	Gura_AssignValueCURLOPT(RESOLVE);						// OBJECTPOINT
	Gura_AssignValueCURLOPT(TLSAUTH_USERNAME);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(TLSAUTH_PASSWORD);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(TLSAUTH_TYPE);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(TRANSFER_ENCODING);				// LONG
	Gura_AssignValueCURLOPT(CLOSESOCKETFUNCTION);			// FUNCTIONPOINT
	Gura_AssignValueCURLOPT(CLOSESOCKETDATA);				// OBJECTPOINT
	Gura_AssignValueCURLOPT(GSSAPI_DELEGATION);				// LONG
#if 0
	Gura_AssignValueCURLOPT(DNS_SERVERS);					// OBJECTPOINT
	Gura_AssignValueCURLOPT(ACCEPTTIMEOUT_MS);				// LONG
	Gura_AssignValueCURLOPT(TCP_KEEPALIVE);					// LONG
	Gura_AssignValueCURLOPT(TCP_KEEPIDLE);					// LONG
	Gura_AssignValueCURLOPT(TCP_KEEPINTVL);					// LONG
	Gura_AssignValueCURLOPT(SSL_OPTIONS);					// LONG
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
	// function assignment
	Gura_AssignFunction(easy_init);
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Object_easy_handle implementation
//-----------------------------------------------------------------------------
Object_easy_handle::~Object_easy_handle()
{
	if (_curl != NULL) {
		::curl_easy_cleanup(_curl);
	}
}

Object *Object_easy_handle::Clone() const
{
	return NULL;
}

bool Object_easy_handle::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_UserSymbol(surface));
	//symbols.insert(Gura_UserSymbol(width));
	//symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_easy_handle::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	//evaluatedFlag = true;
	//if (pSymbol->IsIdentical(Gura_UserSymbol(surface))) {
	//	return Value(Object_surface::Reference(_pObjSurface.get()));
	//}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_easy_handle::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<curl.easy_handle:";
	if (_curl == NULL) {
		str += "invalid";
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for easy_handle
// easy_handle operations
//-----------------------------------------------------------------------------
// curl.easy_handle#setopt(option:number, arg)
Gura_DeclareMethod(easy_handle, setopt)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "option", VTYPE_number);
	DeclareArg(env, "arg", VTYPE_any);
}

Gura_ImplementMethod(easy_handle, setopt)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	CURLcode rtn;
	CURLoption option = static_cast<CURLoption>(args.GetInt(0));
	if (args.IsNumber(1)) {
		if (!(option < CURLOPTTYPE_OBJECTPOINT || CURLOPTTYPE_OFF_T <= option)) {
			sig.SetError(ERR_TypeError, "number cannot be specified for the option");
			return Value::Null;
		}
		rtn = ::curl_easy_setopt(pThis->GetEntity(), option, args.GetInt(1));
	} else if (args.IsString(1)) {
		if (!(CURLOPTTYPE_OBJECTPOINT <= option && option < CURLOPTTYPE_FUNCTIONPOINT)) {
			sig.SetError(ERR_TypeError, "string cannot be specified for the option");
			return Value::Null;
		}
		rtn = ::curl_easy_setopt(pThis->GetEntity(), option, args.GetString(1));
	} else {
		Declaration::SetError_InvalidArgument(sig);
		return Value::Null;
	}
	return Value(rtn);
}

// curl.easy_handle#perform()
Gura_DeclareMethod(easy_handle, perform)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(easy_handle, perform)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	Stream *pStreamOut = pThis->GetStreamOut();
	if (pStreamOut == NULL) pStreamOut = env.GetConsole();
	std::auto_ptr<Writer> pWriter(new Writer(sig, Stream::Reference(pStreamOut)));
	::curl_easy_setopt(pThis->GetEntity(), CURLOPT_WRITEDATA, pWriter.get());
	::curl_easy_setopt(pThis->GetEntity(), CURLOPT_WRITEFUNCTION, Writer::OnWriteStub);
	CURLcode rtn = ::curl_easy_perform(pThis->GetEntity());
	return Value(rtn);
}

// curl.easy_handle#SetStreamOut(stream:stream:w):reduce
Gura_DeclareMethod(easy_handle, SetStreamOut)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
}

Gura_ImplementMethod(easy_handle, SetStreamOut)
{
	Object_easy_handle *pThis = Object_easy_handle::GetThisObj(args);
	pThis->SetStreamOut(Stream::Reference(&Object_stream::GetObject(args, 0)->GetStream()));
	return args.GetThis();
}

// implementation of class easy_handle
Gura_ImplementUserClass(easy_handle)
{
	Gura_AssignMethod(easy_handle, setopt);
	Gura_AssignMethod(easy_handle, perform);
	Gura_AssignMethod(easy_handle, SetStreamOut);
}

Gura_EndModule(curl, curl)

Gura_RegisterModule(curl)
