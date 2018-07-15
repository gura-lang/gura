//=============================================================================
// Gura class: uri
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
# Overview

The `uri` instance analyzes a URI string and returns each part in it
such as the scheme and path.
A generic URI has the following format:

    scheme:[//[user:password@]host:port]][/]path[?query][#fragment]


# Property

A `uri` instance has the following properties:

${markdown.makedoc@property(`en, uri)}


# Constructor

${markdown.makedoc@function(`en
uri
)}


# Method

${markdown.makedoc@function(`en
uri.getfragment
uri.getpath
uri.getquery
uri.parsequery
)}


# Cast Operation

A function that expects a `uri` instance in its argument can also take a value of
`string` that is recognized as a URI string.

With the above casting feature, you can call a function `f(uri:uri)`
that takes a `uri` instance in its argument as below:

- ``f(uri('http://example.com'))`` .. The most explicit way.
- `f('http://example.com')` .. Implicit casting: from `string` to `uri`.
)**";

//-----------------------------------------------------------------------------
// Object_uri
//-----------------------------------------------------------------------------
Object_uri::Object_uri(const Object_uri &obj) : Object(obj), _uri(obj._uri)
{
}

Object *Object_uri::Clone() const
{
	return new Object_uri(*this);
}

String Object_uri::ToString(bool exprFlag)
{
	return _uri.ToString();
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// uri(str?:string):map {block?}
Gura_DeclareFunction(uri)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_uri));
	AddHelp(
		Gura_Symbol(en),
		"Creates `uri` instance.\n"
		"\n"
		"If the argument `str` is specified,\n"
		"it would be parsed as a URI which is stored in the instance.\n"
		"\n"
		"If omitted, the instance would be initialized as an empty one.\n");
}

Gura_ImplementFunction(uri)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Object_uri> pObj(new Object_uri(env));
	if (arg.Is_string(0)) {
		if (!pObj->GetUri().Parse(sig, arg.GetString(0))) return Value::Nil;
	}
	return ReturnValue(env, arg, Value(pObj.release()));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// uri#scheme
Gura_DeclareProperty_RW(uri, scheme)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Scheme part in the URI.");
}

Gura_ImplementPropertyGetter(uri, scheme)
{
	const Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	return Value(uri.GetScheme());
}

Gura_ImplementPropertySetter(uri, scheme)
{
	Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	uri.SetScheme(value.GetString());
	return value;
}

// uri#user
Gura_DeclareProperty_RW(uri, user)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"User part in the URI.");
}

Gura_ImplementPropertyGetter(uri, user)
{
	const Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	return Value(uri.GetUser());
}

Gura_ImplementPropertySetter(uri, user)
{
	Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	uri.SetUser(value.GetString());
	return value;
}

// uri#password
Gura_DeclareProperty_RW(uri, password)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Password part in the URI.");
}

Gura_ImplementPropertyGetter(uri, password)
{
	const Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	return Value(uri.GetPassword());
}

Gura_ImplementPropertySetter(uri, password)
{
	Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	uri.SetPassword(value.GetString());
	return value;
}

// uri#host
Gura_DeclareProperty_RW(uri, host)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Host part in the URI.");
}

Gura_ImplementPropertyGetter(uri, host)
{
	const Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	return Value(uri.GetHost());
}

Gura_ImplementPropertySetter(uri, host)
{
	Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	uri.SetHost(value.GetString());
	return value;
}

// uri#port
Gura_DeclareProperty_RW(uri, port)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Port part in the URI.");
}

Gura_ImplementPropertyGetter(uri, port)
{
	const Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	return Value(uri.GetPort());
}

Gura_ImplementPropertySetter(uri, port)
{
	Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	uri.SetPort(value.GetString());
	return value;
}

// uri#urlpath
Gura_DeclareProperty_RW(uri, urlpath)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"URL path part in the URI, which contains the path, query and fragment part.");
}

Gura_ImplementPropertyGetter(uri, urlpath)
{
	const Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	return Value(uri.GetUrlPath());
}

Gura_ImplementPropertySetter(uri, urlpath)
{
	Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	uri.SetUrlPath(value.GetString());
	return value;
}

// uri#misc
Gura_DeclareProperty_RW(uri, misc)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Misc part in the URI.");
}

Gura_ImplementPropertyGetter(uri, misc)
{
	const Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	return Value(uri.GetMisc());
}

Gura_ImplementPropertySetter(uri, misc)
{
	Uri &uri = Object_uri::GetObject(valueThis)->GetUri();
	uri.SetMisc(value.GetString());
	return value;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// uri#getfragment()
Gura_DeclareMethod(uri, getfragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the fragment part contained in the URI path.");
}

Gura_ImplementMethod(uri, getfragment)
{
	const Uri &uri = Object_uri::GetObjectThis(arg)->GetUri();
	return Value(uri.ExtractFragment(uri.GetUrlPath()));
}

// uri#getpath()
Gura_DeclareMethod(uri, getpath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the path part contained in the URI path.");
}

Gura_ImplementMethod(uri, getpath)
{
	const Uri &uri = Object_uri::GetObjectThis(arg)->GetUri();
	return Value(uri.ExtractPath(uri.GetUrlPath()));
}

// uri#getquery()
Gura_DeclareMethod(uri, getquery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns a `dict` instance that is made from the query part in the URI path.");
}

Gura_ImplementMethod(uri, getquery)
{
	const Uri &uri = Object_uri::GetObjectThis(arg)->GetUri();
	Value result;
	ValueDict &valDict = result.InitAsDict(env, true);
	Uri::ExtractQuery(uri.GetUrlPath(), valDict);
	return result;
}

// uri.parsequery(query:string):map
Gura_DeclareClassMethod(uri, parsequery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "query", VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"This is a utility function to parse a query string\n"
		"and return a `dict` instance that contains key-value pairs for the query.\n");
}

Gura_ImplementClassMethod(uri, parsequery)
{
	Value result;
	ValueDict &valDict = result.InitAsDict(env, true);
	Uri::ExtractQuery(arg.GetString(0), valDict, false);
	return result;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_uri::Class_uri(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_uri)
{
}

void Class_uri::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(uri);
	// Assignment of properties
	Gura_AssignProperty(uri, scheme);
	Gura_AssignProperty(uri, user);
	Gura_AssignProperty(uri, password);
	Gura_AssignProperty(uri, host);
	Gura_AssignProperty(uri, port);
	Gura_AssignProperty(uri, urlpath);
	Gura_AssignProperty(uri, misc);
	// Assignment of methods
	Gura_AssignMethod(uri, getfragment);
	Gura_AssignMethod(uri, getpath);
	Gura_AssignMethod(uri, getquery);
	Gura_AssignMethod(uri, parsequery);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_uri::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	if (value.Is_string()) {
		AutoPtr<Object_uri> pObj(new Object_uri(env));
		if (!pObj->GetUri().Parse(sig, value.GetString())) return false;
		value = Value(pObj.release());
		return true;
	}
	return false;
}

Object *Class_uri::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
