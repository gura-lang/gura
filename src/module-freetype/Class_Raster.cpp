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
