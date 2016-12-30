#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_SBitCache implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_SBitCache::Clone() const
{
	return nullptr;
}

String Object_FTC_SBitCache::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_SBitCache>");
	return String(buff);
}

bool Object_FTC_SBitCache::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_FTC_SBitCache::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	return Value::Nil;
}

Value Object_FTC_SBitCache::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_SBitCache#x
Gura_DeclareProperty_RW(FTC_SBitCache, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_SBitCache, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_SBitCache, x)
{
	return Value::Nil;
}

// freetype.FTC_SBitCache#y
Gura_DeclareProperty_RW(FTC_SBitCache, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_SBitCache, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_SBitCache, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_SBitCache
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_SBitCache)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_SBitCache, x);
	Gura_AssignProperty(FTC_SBitCache, y);
#endif
	Gura_AssignValue(FTC_SBitCache, Value(Reference()));
}

Gura_EndModuleScope(freetype)
