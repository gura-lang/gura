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
	return Value::Null;
}

Value Object_uri::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(scheme))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		_uri.SetScheme(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(user))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		_uri.SetUser(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(password))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		_uri.SetPassword(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(host))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		_uri.SetHost(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(port))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		_uri.SetPort(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(urlpath))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		_uri.SetUrlPath(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(misc))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		_uri.SetMisc(value.GetString());
		return value;
	}
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(uri)
{
	AutoPtr<Object_uri> pObj(new Object_uri(env));
	if (args.Is_string(0)) {
		if (!pObj->GetUri().Parse(sig, args.GetString(0))) return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
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
}

bool Class_uri::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_string()) {
		AutoPtr<Object_uri> pObj(new Object_uri(env));
		if (!pObj->GetUri().Parse(sig, value.GetString())) return false;
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

}
