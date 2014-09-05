//=============================================================================
// Uri
// reference: RFC1738 (Uniform Resource Locators)
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Uri
//-----------------------------------------------------------------------------
Uri::Uri() : _userValidFlag(false)
{
}

Uri::Uri(const Uri &uri) : _userValidFlag(uri._userValidFlag),
	_scheme(uri._scheme), _user(uri._user), _password(uri._password),
	_host(uri._host), _port(uri._port), _urlpath(uri._urlpath), _misc(uri._misc)
{
	// ftp, http, gopher, mailto, news, nntp, telnet, wais, file, prospro
}

bool Uri::Parse(Signal sig, const char *str)
{
	enum {
		STAT_Scheme,
		STAT_Slash1, STAT_Slash2, STAT_Host, STAT_Port,
		STAT_UrlPath,
		STAT_MailTo,
		STAT_News,
	} stat = STAT_Scheme;
	_userValidFlag = false;
	_scheme.clear();
	_user.clear();
	_password.clear();
	_host.clear();
	_port.clear();
	_urlpath.clear();
	_misc.clear();
	for (const char *p = str; *p != '\0'; p++) {
		char ch = *p;
		if (stat == STAT_Scheme) {
			if (ch == ':') {
				if (_scheme == "mailto") {
					stat = STAT_MailTo;
				} else if (_scheme == "news") {
					stat = STAT_News;
				} else {
					stat = STAT_Slash1;
				}
			} else if (('a' <= ch && ch <= 'z') || ch == '+' || ch == '.' || ch == '-') {
				_scheme += ch;
			} else if ('A' <= ch && ch <= 'Z') {
				_scheme += ch - 'A' + 'a';
			} else {
				sig.SetError(ERR_ValueError, "invalid scheme name");
				return false;
			}
		} else if (stat == STAT_Slash1) {
			if (ch == '/') {
				stat = STAT_Slash2;
			} else {
				SetError_InvalidURIFormat(sig);
				return false;
			}
		} else if (stat == STAT_Slash2) {
			if (ch == '/') {
				stat = STAT_Host;
			} else {
				SetError_InvalidURIFormat(sig);
				return false;
			}
		} else if (stat == STAT_Host) {
			if (ch == ':') {
				stat = STAT_Port;
			} else if (ch == '/') {
				_urlpath += ch;
				stat = STAT_UrlPath;
			} else if (ch == '@') {
				if (_userValidFlag) {
					SetError_InvalidURIFormat(sig);
					return false;
				}
				_userValidFlag = true;
				_user = _host, _password = _port;
				_host.clear(), _port.clear();
			} else if (0x20 <= ch && ch < 0x7f) {
				_host += ch;
			} else {
				SetError_InvalidURIFormat(sig);
				return false;
			}
		} else if (stat == STAT_Port) {
			if (ch == '/') {
				_urlpath += ch;
				stat = STAT_UrlPath;
			} else if (ch == '@') {
				if (_userValidFlag) {
					SetError_InvalidURIFormat(sig);
					return false;
				}
				_userValidFlag = true;
				_user = _host, _password = _port;
				_host.clear(), _port.clear();
				stat = STAT_Host;
			} else if (0x20 <= ch && ch < 0x7f) {
				_port += ch;
			} else {
				SetError_InvalidURIFormat(sig);
				return false;
			}
		} else if (stat == STAT_UrlPath) {
			_urlpath += ch;
		} else if (stat == STAT_MailTo) {
			_misc += ch;
		} else if (stat == STAT_News) {
			_misc += ch;
		}
	}
	return true;
}

String Uri::ToString() const
{
	String rtn;
	if (!_scheme.empty()) {
		rtn += _scheme;
		rtn += ":";
		if (_scheme != "mailto" && _scheme != "news") {
			rtn += "//";
		}
	}
	if (_userValidFlag) {
		if (!_user.empty()) {
			rtn += _user;
			if (!_password.empty()) {
				rtn += ":";
				rtn += _password;
			}
		}
		rtn += "@";
	}
	rtn += _host;
	if (!_port.empty()) {
		rtn += ":";
		rtn += _port;
	}
	if (!_urlpath.empty()) {
		rtn += _urlpath;
	}
	if (!_misc.empty()) {
		rtn += _misc;
	}
	return rtn;
}

void Uri::SetError_InvalidURIFormat(Signal sig)
{
	sig.SetError(ERR_ValueError, "invalid URI format");
}

String Uri::ExtractPath(const char *urlPath)
{
	const char *p = urlPath;
	for ( ; *p != '?' && *p != '#' && *p != '\0'; p++) ;
	return String(urlPath, p);
}

void Uri::ExtractQuery(const char *urlPath, ValueDict &valDict, bool skipPathFlag)
{
	enum {
		STAT_Begin, STAT_Key, STAT_Value,
	} stat = skipPathFlag? STAT_Begin : STAT_Key;
	String key, value;
	UChar chHex = 0x00;
	for (const char *p = urlPath; ; p++) {
		const char ch = *p;
		switch (stat) {
		case STAT_Begin: {
			if (ch == '?') {
				stat = STAT_Key;
			} else {
				// nothing to do
			}
			break;
		}
		case STAT_Key: {
			if (ch == '=') {
				stat = STAT_Value;
			} else if (ch == '?' || ch == '#' || ch == '&' || ch == '\0') {
				valDict[Value(key)] = Value::Null;
				key.clear();
			} else if (ch == '+') {
				key += ' ';
			} else {
				key += ch;
			}
			break;
		}
		case STAT_Value: {
			if (ch == '?' || ch == '#' || ch == '&' || ch == '\0') {
				valDict[Value(key)] = Value(value);
				key.clear();
				value.clear();
				stat = STAT_Key;
			} else if (ch == '+') {
				value += ' ';
			} else {
				value += ch;
			}
			break;
		}
		}
		if (ch == '#' || ch == '\0') break;
	}
}

String Uri::ExtractFragment(const char *urlPath)
{
	const char *p = ::strchr(urlPath, '#');
	return (p == NULL)? "" : p + 1;
}

}
