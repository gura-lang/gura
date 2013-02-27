#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_BDF_Property implementation
//-----------------------------------------------------------------------------
Object *Object_BDF_Property::Clone() const
{
	return NULL;
}

String Object_BDF_Property::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.BDF_Property>");
	return String(buff);
}

bool Object_BDF_Property::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_BDF_Property::DoGetProp(Signal sig, const Symbol *pSymbol,
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

Value Object_BDF_Property::DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
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
// Class implementation for freetype.BDF_Property
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(BDF_Property)
{
}

}}
