//
// Object_uri
// referred to RFC1738 (Uniform Resource Locators)

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_uri
//-----------------------------------------------------------------------------
Object_uri::Object_uri(const Object_uri &obj) : Object(obj),
	_userValidFlag(obj._userValidFlag), _scheme(obj._scheme),
	_user(obj._user), _password(obj._password),
	_host(obj._host), _port(obj._port), _urlpath(obj._urlpath), _misc(obj._misc)
{
	// ftp, http, gopher, mailto, news, nntp, telnet, wais, file, prospro
}

Object_uri::~Object_uri()
{
}

Object *Object_uri::Clone() const
{
	return new Object_uri(*this);
}

bool Object_uri::Parse(Signal sig, const char *str)
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
			} else if ('a' <= ch && ch <= 'z' || ch == '+' || ch == '.' || ch == '-') {
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

String Object_uri::ToString(Signal sig, bool exprFlag)
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
		rtn += "/";
		rtn += _urlpath;
	}
	if (!_misc.empty()) {
		rtn += _misc;
	}
	return rtn;
}

void Object_uri::SetError_InvalidURIFormat(Signal sig)
{
	sig.SetError(ERR_ValueError, "invalid URI format");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_uri
//-----------------------------------------------------------------------------
// uri#scheme(str?:string)
Gura_DeclareMethod(uri, scheme)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Sets or gets scheme part of the URI.");
}

Gura_ImplementMethod(uri, scheme)
{
	Object_uri *pThis = Object_uri::GetThisObj(args);
	if (args.IsString(0)) {
		pThis->SetScheme(args.GetString(0));
		return args.GetThis();
	} else {
		return Value(env, pThis->GetScheme());
	}
}

// uri#user(str?:string)
Gura_DeclareMethod(uri, user)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Sets or gets scheme user of the URI.");
}

Gura_ImplementMethod(uri, user)
{
	Object_uri *pThis = Object_uri::GetThisObj(args);
	if (args.IsString(0)) {
		pThis->SetUser(args.GetString(0));
		return args.GetThis();
	} else {
		if (!pThis->IsUserValid()) return Value::Null;
		return Value(env, pThis->GetUser());
	}
}

// uri#password(str?:string)
Gura_DeclareMethod(uri, password)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Sets or gets password part of the URI.");
}

Gura_ImplementMethod(uri, password)
{
	Object_uri *pThis = Object_uri::GetThisObj(args);
	if (args.IsString(0)) {
		pThis->SetPassword(args.GetString(0));
		return args.GetThis();
	} else {
		return Value(env, pThis->GetPassword());
	}
}

// uri#host(str?:string)
Gura_DeclareMethod(uri, host)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Sets or gets host part of the URI.");
}

Gura_ImplementMethod(uri, host)
{
	Object_uri *pThis = Object_uri::GetThisObj(args);
	if (args.IsString(0)) {
		pThis->SetHost(args.GetString(0));
		return args.GetThis();
	} else {
		return Value(env, pThis->GetHost());
	}
}

// uri#port(str?:string)
Gura_DeclareMethod(uri, port)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Sets or gets port part of the URI.");
}

Gura_ImplementMethod(uri, port)
{
	Object_uri *pThis = Object_uri::GetThisObj(args);
	if (args.IsString(0)) {
		pThis->SetPort(args.GetString(0));
		return args.GetThis();
	} else {
		return Value(env, pThis->GetPort());
	}
}

// uri#urlpath(str?:string)
Gura_DeclareMethod(uri, urlpath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Sets or gets url-path part of the URI.");
}

Gura_ImplementMethod(uri, urlpath)
{
	Object_uri *pThis = Object_uri::GetThisObj(args);
	if (args.IsString(0)) {
		pThis->SetUrlPath(args.GetString(0));
		return args.GetThis();
	} else {
		return Value(env, pThis->GetUrlPath());
	}
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_uri::Class_uri(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_uri)
{
	Gura_AssignMethod(uri, scheme);
	Gura_AssignMethod(uri, user);
	Gura_AssignMethod(uri, password);
	Gura_AssignMethod(uri, host);
	Gura_AssignMethod(uri, port);
	Gura_AssignMethod(uri, urlpath);
}

Object *Class_uri::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_uri::OnModuleEntry(Environment &env, Signal sig)
{
}

}
