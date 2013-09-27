//
// Object_error
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_error
//-----------------------------------------------------------------------------
Object_error::Object_error(const Object_error &obj) :
										Object(obj), _errType(obj._errType)
{
}

Object_error::~Object_error()
{
}

Object *Object_error::Clone() const
{
	return new Object_error(*this);
}

bool Object_error::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(text));
	symbols.insert(Gura_Symbol(message));
	symbols.insert(Gura_Symbol(value));
	return true;
}

Value Object_error::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(text))) {
	} else if (pSymbol->IsIdentical(Gura_Symbol(message))) {
	} else if (pSymbol->IsIdentical(Gura_Symbol(value))) {
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_error::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<error:";
	rtn += Error::GetTypeName(_errType);
	rtn += ">";
	return rtn;
}

void Object_error::SetSnapshot(const Signal &sig)
{
	_str = sig.GetError().GetStringSTL();
	_pExprCauseOwner.reset(new ExprOwner(sig.GetError().GetExprCauseOwner()));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_error
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_error::Class_error(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_error)
{
}

void Class_error::Prepare(Environment &env)
{
}

Object *Class_error::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
