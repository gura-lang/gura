//=============================================================================
// Gura class: token
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_token
//-----------------------------------------------------------------------------
Object_token::Object_token(const Object_token &obj) : Object(obj), _token(obj.GetToken())
{
}

Object *Object_token::Clone() const
{
	return new Object_token(*this);
}

bool Object_token::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(type));
	symbols.insert(Gura_Symbol(source));
	return true;
}

Value Object_token::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(type))) {
		return Value(Symbol::Add(_token.GetTypeName()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(source))) {
		return Value(_token.GetSource());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_token::ToString(bool exprFlag)
{
	String str;
	str += "<token:";
	str += _token.GetTypeName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_token::Class_token(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_token)
{
}

void Class_token::Prepare(Environment &env)
{
	Gura_AssignValue(token, Value(Reference()));
}

Object *Class_token::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
