//=============================================================================
// Gura class: help
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object implementation for help
//-----------------------------------------------------------------------------
Object_help::Object_help(Environment &env, Help *pHelp) :
			Object(env.LookupClass(VTYPE_help)), _pHelp(pHelp)
{
}

Object_help::Object_help(Class *pClass, Help *pHelp) :
			Object(pClass), _pHelp(pHelp)
{
}

Object *Object_help::Clone() const
{
	return NULL; //new Object_help(*this);
}

bool Object_help::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(lang));
	symbols.insert(Gura_Symbol(text));
	return true;
}

Value Object_help::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(_pHelp->GetFormatNameSTL());
	} else if (pSymbol->IsIdentical(Gura_Symbol(lang))) {
		return Value(_pHelp->GetSymbol());
	} else if (pSymbol->IsIdentical(Gura_Symbol(text))) {
		return Value(_pHelp->GetTextSTL());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_help::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_help::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<help:";
	rtn += _pHelp->GetSymbol()->GetName();
	rtn += ":";
	rtn += _pHelp->GetFormatName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_help::Class_help(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_help)
{
}

void Class_help::Prepare(Environment &env)
{
}

}
