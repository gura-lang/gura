#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Raster implementation
//-----------------------------------------------------------------------------
Object *Object_Raster::Clone() const
{
	return nullptr;
}

String Object_Raster::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Raster>");
	return String(buff);
}

bool Object_Raster::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
#if 0
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
#endif
	return true;
}

Value Object_Raster::DoGetProp(Environment &env, const Symbol *pSymbol,
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

Value Object_Raster::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
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
// freetype.Raster#x
Gura_DeclareProperty_RW(Raster, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Raster, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Raster, x)
{
	return Value::Nil;
}

// freetype.Raster#y
Gura_DeclareProperty_RW(Raster, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Raster, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Raster, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Raster
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Raster)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(Raster, x);
	Gura_AssignProperty(Raster, y);
#endif
	Gura_AssignValue(Raster, Value(Reference()));
}

Gura_EndModuleScope(freetype)
