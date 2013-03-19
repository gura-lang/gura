//
// Object_uri
// reference: RFC1738 (Uniform Resource Locators)

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

bool Object_uri::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(scheme));
	symbols.insert(Gura_Symbol(user));
	symbols.insert(Gura_Symbol(password));
	symbols.insert(Gura_Symbol(host));
	symbols.insert(Gura_Symbol(port));
	symbols.insert(Gura_Symbol(urlpath));
	symbols.insert(Gura_Symbol(misc));
	return true;
}

Value Object_uri::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(scheme))) {
		return Value(env, _scheme);
	} else if (pSymbol->IsIdentical(Gura_Symbol(user))) {
		return Value(env, _user);
	} else if (pSymbol->IsIdentical(Gura_Symbol(password))) {
		return Value(env, _password);
	} else if (pSymbol->IsIdentical(Gura_Symbol(host))) {
		return Value(env, _host);
	} else if (pSymbol->IsIdentical(Gura_Symbol(port))) {
		return Value(env, _port);
	} else if (pSymbol->IsIdentical(Gura_Symbol(urlpath))) {
		return Value(env, _urlpath);
	} else if (pSymbol->IsIdentical(Gura_Symbol(misc))) {
		return Value(env, _misc);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_uri::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(scheme))) {
		if (!value.MustBeString(sig)) return Value::Null;
		_scheme = value.GetStringSTL();
		return Value(env, _scheme);
	} else if (pSymbol->IsIdentical(Gura_Symbol(user))) {
		if (!value.MustBeString(sig)) return Value::Null;
		_user = value.GetStringSTL();
		return Value(env, _user);
	} else if (pSymbol->IsIdentical(Gura_Symbol(password))) {
		if (!value.MustBeString(sig)) return Value::Null;
		_password = value.GetStringSTL();
		return Value(env, _password);
	} else if (pSymbol->IsIdentical(Gura_Symbol(host))) {
		if (!value.MustBeString(sig)) return Value::Null;
		_host = value.GetStringSTL();
		return Value(env, _host);
	} else if (pSymbol->IsIdentical(Gura_Symbol(port))) {
		if (!value.MustBeString(sig)) return Value::Null;
		_port = value.GetStringSTL();
		return Value(env, _port);
	} else if (pSymbol->IsIdentical(Gura_Symbol(urlpath))) {
		if (!value.MustBeString(sig)) return Value::Null;
		_urlpath = value.GetStringSTL();
		return Value(env, _urlpath);
	} else if (pSymbol->IsIdentical(Gura_Symbol(misc))) {
		if (!value.MustBeString(sig)) return Value::Null;
		_misc = value.GetStringSTL();
		return Value(env, _misc);
	}
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
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
// uri(str:string):map {block?}
Gura_DeclareFunction(uri)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(uri)
{
	AutoPtr<Object_uri> pObj(new Object_uri(env));
	if (!pObj->Parse(sig, args.GetString(0))) return Value::Null;
	return Value(pObj.release());
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_uri::Class_uri(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_uri)
{
}

bool Class_uri::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsString()) {
		AutoPtr<Object_uri> pObj(new Object_uri(env));
		if (!pObj->Parse(sig, value.GetString())) return false;
		value = Value(pObj.release());
		return true;
	}
	return false;
}

Object *Class_uri::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_uri::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(uri);
}

}
