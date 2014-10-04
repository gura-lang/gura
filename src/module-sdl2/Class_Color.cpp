#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Color implementation
//-----------------------------------------------------------------------------
Object_Color::~Object_Color()
{
}

Object *Object_Color::Clone() const
{
	return NULL;
}

String Object_Color::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl2.Color:r=%d,g=%d,b=%d>", _color.r, _color.g, _color.b);
	return String(buff);
}

bool Object_Color::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(r));
	symbols.insert(Gura_UserSymbol(g));
	symbols.insert(Gura_UserSymbol(b));
	return true;
}

Value Object_Color::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(r))) {
		return Value(_color.r);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(g))) {
		return Value(_color.g);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(b))) {
		return Value(_color.b);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Color::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(r))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_color.r = static_cast<Uint8>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(g))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_color.g = static_cast<Uint8>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(b))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_color.b = static_cast<Uint8>(value.GetUInt());
		return value;
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Color
//-----------------------------------------------------------------------------
// implementation of class Color
Gura_ImplementUserClass(Color)
{
}

Gura_EndModuleScope(sdl2)
