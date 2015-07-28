#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_SBit implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_SBit::Clone() const
{
	return nullptr;
}

String Object_FTC_SBit::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_SBit>");
	return String(buff);
}

bool Object_FTC_SBit::DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, sig, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_FTC_SBit::DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
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

Value Object_FTC_SBit::DoSetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
#if 0
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
#endif
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_SBit
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_SBit)
{
	Gura_AssignValue(FTC_SBit, Value(Reference()));
}

Gura_EndModuleScope(freetype)
