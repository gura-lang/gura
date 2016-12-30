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

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_SBit#x
Gura_DeclareProperty_RW(FTC_SBit, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_SBit, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_SBit, x)
{
	return Value::Nil;
}

// freetype.FTC_SBit#y
Gura_DeclareProperty_RW(FTC_SBit, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_SBit, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_SBit, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_SBit
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_SBit)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_SBit, x);
	Gura_AssignProperty(FTC_SBit, y);
#endif
	Gura_AssignValue(FTC_SBit, Value(Reference()));
}

Gura_EndModuleScope(freetype)
