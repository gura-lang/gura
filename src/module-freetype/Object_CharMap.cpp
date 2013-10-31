#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_CharMap implementation
//-----------------------------------------------------------------------------
Object *Object_CharMap::Clone() const
{
	return NULL;
}

String Object_CharMap::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.CharMap>");
	return String(buff);
}

bool Object_CharMap::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_CharMap::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_CharMap::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for freetype.CharMap
//-----------------------------------------------------------------------------
// freetype.CharMap#Get_Index()
Gura_DeclareMethod(CharMap, Get_Index)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(CharMap, Get_Index)
{
	FT_CharMap charmap = Object_CharMap::GetThisObj(args)->GetEntity();
	FT_Int rtn = ::FT_Get_Charmap_Index(charmap);
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.CharMap
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(CharMap)
{
	Gura_AssignMethod(CharMap, Get_Index);
}

Gura_EndModuleScope(freetype)
