//=============================================================================
// Gura class: formatter
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_formatter
//-----------------------------------------------------------------------------
Object_formatter::Object_formatter(const Object_formatter &obj) :
										Object(obj), _flags(obj._flags)
{
}

Object_formatter::~Object_formatter()
{
}

Object *Object_formatter::Clone() const
{
	return new Object_formatter(*this);
}

bool Object_formatter::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_formatter::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(days))) {
		return Value(static_cast<Number>(_formatter.GetDays()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(secs))) {
		return Value(static_cast<Number>(_formatter.GetSecsRaw()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(usecs))) {
		return Value(static_cast<Number>(_formatter.GetUSecs()));
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

String Object_formatter::ToString(bool exprFlag)
{
	String str;
	str += "<formatter:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_formatter::Class_formatter(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_formatter)
{
}

void Class_formatter::Prepare(Environment &env)
{
	//Gura_AssignFunction(formatter);
}

Object *Class_formatter::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
