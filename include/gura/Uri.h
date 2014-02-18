//=============================================================================
// Uri
// reference: RFC1738 (Uniform Resource Locators)
//=============================================================================
#ifndef __GURA_URI_H__
#define __GURA_URI_H__

#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Uri
//-----------------------------------------------------------------------------
class Uri {
public:
	bool _userValidFlag;
	String _scheme;
	String _user;
	String _password;
	String _host;
	String _port;
	String _urlpath;
	String _misc;
public:
	Uri();
	Uri(const Uri &uri);
	inline bool IsUserValid() const { return _userValidFlag; }
	inline const char *GetScheme() const { return _scheme.c_str(); }
	inline const char *GetUser() const { return _user.c_str(); }
	inline const char *GetPassword() const { return _password.c_str(); }
	inline const char *GetHost() const { return _host.c_str(); }
	inline const char *GetPort() const { return _port.c_str(); }
	inline const char *GetUrlPath() const { return _urlpath.c_str(); }
	inline const char *GetMisc() const { return _misc.c_str(); }
	inline void SetScheme(const char *str) { _scheme = str; }
	inline void SetUser(const char *str) { _user = str, _userValidFlag = true; }
	inline void SetPassword(const char *str) { _password = str; }
	inline void SetHost(const char *str) { _host = str; }
	inline void SetPort(const char *str) { _port = str; }
	inline void SetUrlPath(const char *str) { _urlpath = str; }
	inline void SetMisc(const char *str) { _misc = str; }
	bool Parse(Signal sig, const char *str);
	String ToString() const;
	void SetError_InvalidURIFormat(Signal sig);
	static String ExtractPath(const char *urlPath);
	static void ExtractQuery(const char *urlPath, ValueDict &valDict);
	static String ExtractFragment(const char *urlPath);
};

}
#endif
