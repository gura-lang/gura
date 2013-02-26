#include "stdafx.h"

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Vector implementation
//-----------------------------------------------------------------------------
Object *Object_Vector::Clone() const
{
	return NULL;
}

String Object_Vector::ToString(Signal sig, bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl.Vector:x=%d,y=%d>", _vector.x, _vector.y);
	return String(buff);
}

bool Object_Vector::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	return true;
}

Value Object_Vector::DoGetProp(Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_vector.y);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Vector::DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.x = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_vector.y = static_cast<FT_Pos>(value.GetLong());
		return Value(_vector.y);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Vector
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Vector)
{
}

}}
