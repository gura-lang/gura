//=============================================================================
// Gura class: uri
//=============================================================================
#include "stdafx.h"

namespace Gura {

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

bool Object_uri::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(scheme));
	symbols.insert(Gura_Symbol(user));
	symbols.insert(Gura_Symbol(password));
	symbols.insert(Gura_Symbol(host));
	symbols.insert(Gura_Symbol(port));
	symbols.insert(Gura_Symbol(urlpath));
	symbols.insert(Gura_Symbol(misc));
	return true;
}

Value Object_uri::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(scheme))) {
		return Value(_uri.GetScheme());
	} else if (pSymbol->IsIdentical(Gura_Symbol(user))) {
		return Value(_uri.GetUser());
	} else if (pSymbol->IsIdentical(Gura_Symbol(password))) {
		return Value(_uri.GetPassword());
	} else if (pSymbol->IsIdentical(Gura_Symbol(host))) {
		return Value(_uri.GetHost());
	} else if (pSymbol->IsIdentical(Gura_Symbol(port))) {
		return Value(_uri.GetPort());
	} else if (pSymbol->IsIdentical(Gura_Symbol(urlpath))) {
		return Value(_uri.GetUrlPath());
	} else if (pSymbol->IsIdentical(Gura_Symbol(misc))) {
		return Value(_uri.GetMisc());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_uri::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(scheme))) {
		if (!value.MustBe_string(sig)) return Value::Nil;
		_uri.SetScheme(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(user))) {
		if (!value.MustBe_string(sig)) return Value::Nil;
		_uri.SetUser(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(password))) {
		if (!value.MustBe_string(sig)) return Value::Nil;
		_uri.SetPassword(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(host))) {
		if (!value.MustBe_string(sig)) return Value::Nil;
		_uri.SetHost(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(port))) {
		if (!value.MustBe_string(sig)) return Value::Nil;
		_uri.SetPort(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(urlpath))) {
		if (!value.MustBe_string(sig)) return Value::Nil;
		_uri.SetUrlPath(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(misc))) {
		if (!value.MustBe_string(sig)) return Value::Nil;
		_uri.SetMisc(value.GetString());
		return value;
	}
	return DoGetProp(env, pSymbol, attrs, evaluatedFlag);
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
		Gura_Symbol(en), Help::FMT_markdown,
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
	if (args.Is_string(0)) {
		if (!pObj->GetUri().Parse(sig, args.GetString(0))) return Value::Nil;
	}
	return ReturnValue(env, args, Value(pObj.release()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// uri#getfragment()
Gura_DeclareMethod(uri, getfragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the fragment part contained in the URI path of the `uri` instance.");
}

Gura_ImplementMethod(uri, getfragment)
{
	const Uri &uri = Object_uri::GetObjectThis(args)->GetUri();
	return Value(uri.ExtractFragment(uri.GetUrlPath()));
}

// uri#getpath()
Gura_DeclareMethod(uri, getpath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the path part contained in the URI path of the `uri` instance.");
}

Gura_ImplementMethod(uri, getpath)
{
	const Uri &uri = Object_uri::GetObjectThis(args)->GetUri();
	return Value(uri.ExtractPath(uri.GetUrlPath()));
}

// uri#getquery()
Gura_DeclareMethod(uri, getquery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the query part contained in the URI path of the `uri` instance.");
}

Gura_ImplementMethod(uri, getquery)
{
	const Uri &uri = Object_uri::GetObjectThis(args)->GetUri();
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
		Gura_Symbol(en), Help::FMT_markdown,
		"Parses a query string and returns a dictionary\n"
		"that contains key-value pairs of the query.");
}

Gura_ImplementClassMethod(uri, parsequery)
{
	Value result;
	ValueDict &valDict = result.InitAsDict(env, true);
	Uri::ExtractQuery(args.GetString(0), valDict, false);
	return result;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_uri::Class_uri(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_uri)
{
}

void Class_uri::Prepare(Environment &env)
{
	Gura_AssignFunction(uri);
	Gura_AssignMethod(uri, getfragment);
	Gura_AssignMethod(uri, getpath);
	Gura_AssignMethod(uri, getquery);
	Gura_AssignMethod(uri, parsequery);
}

bool Class_uri::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
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
