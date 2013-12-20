//=============================================================================
// Gura class: error
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_error
//-----------------------------------------------------------------------------
Object_error::Object_error(const Object_error &obj) : Object(obj), _err(obj._err)
{
}

Object *Object_error::Clone() const
{
	return new Object_error(*this);
}

bool Object_error::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(source));
	symbols.insert(Gura_Symbol(lineno));
	symbols.insert(Gura_Symbol(linenobtm));
	symbols.insert(Gura_Symbol(postext));
	symbols.insert(Gura_Symbol(text));
	symbols.insert(Gura_Symbol(trace));
	return true;
}

Value Object_error::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(source))) {
		const char *sourceName = _err.GetSourceName();
		if (sourceName == NULL) return Value::Null;
		return Value(sourceName);
	} else if (pSymbol->IsIdentical(Gura_Symbol(lineno))) {
		return Value(_err.GetLineNoTop());
	} else if (pSymbol->IsIdentical(Gura_Symbol(linenobtm))) {
		return Value(_err.GetLineNoBtm());
	} else if (pSymbol->IsIdentical(Gura_Symbol(postext))) {
		return Value(_err.MakePosText());
	} else if (pSymbol->IsIdentical(Gura_Symbol(text))) {
		bool lineInfoFlag = attrs.IsSet(Gura_Symbol(lineno));
		return Value(_err.MakeText(lineInfoFlag));
	} else if (pSymbol->IsIdentical(Gura_Symbol(trace))) {
		AutoPtr<ExprOwner> pExprOwner(new ExprOwner());
		_err.GetExprCauseOwner().ExtractTrace(*pExprOwner);
		return Value(new Object_iterator(env, new ExprOwner::Iterator(pExprOwner.release())));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_error::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<error:";
	rtn += _err.GetTypeName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_error::Class_error(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_error)
{
}

void Class_error::Prepare(Environment &env)
{
	Error::AssignErrorTypes(*this);
	Gura_AssignValue(error, Value(this));
}

Object *Class_error::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
