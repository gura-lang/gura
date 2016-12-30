#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_ImageType implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_ImageType::Clone() const
{
	return nullptr;
}

String Object_FTC_ImageType::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_ImageType>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_ImageType#x
Gura_DeclareProperty_RW(FTC_ImageType, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_ImageType, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_ImageType, x)
{
	return Value::Nil;
}

// freetype.FTC_ImageType#y
Gura_DeclareProperty_RW(FTC_ImageType, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_ImageType, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_ImageType, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_ImageType
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_ImageType)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_ImageType, x);
	Gura_AssignProperty(FTC_ImageType, y);
#endif
	Gura_AssignValue(FTC_ImageType, Value(Reference()));
}

Gura_EndModuleScope(freetype)
