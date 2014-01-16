//=============================================================================
// Gura class: suffixmgr
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object implementation for suffixmgr
//-----------------------------------------------------------------------------
Object_suffixmgr::Object_suffixmgr(Environment &env, SuffixManagerMap &suffixManagerMap) :
			Object(env.LookupClass(VTYPE_suffixmgr)), _suffixManagerMap(suffixManagerMap)
{
}

Object_suffixmgr::Object_suffixmgr(Class *pClass, SuffixManagerMap &suffixManagerMap) :
			Object(pClass), _suffixManagerMap(suffixManagerMap)
{
}

Object *Object_suffixmgr::Clone() const
{
	return NULL; //new Object_suffixmgr(*this);
}

bool Object_suffixmgr::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(lang));
	symbols.insert(Gura_Symbol(text));
	return true;
}

Value Object_suffixmgr::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_suffixmgr::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_suffixmgr::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<suffixmgr:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_suffixmgr::Class_suffixmgr(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_suffixmgr)
{
}

void Class_suffixmgr::Prepare(Environment &env)
{
}

}
