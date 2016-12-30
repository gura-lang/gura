#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_Scaler implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_Scaler::Clone() const
{
	return nullptr;
}

String Object_FTC_Scaler::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_Scaler>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_Scaler#x
Gura_DeclareProperty_RW(FTC_Scaler, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_Scaler, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_Scaler, x)
{
	return Value::Nil;
}

// freetype.FTC_Scaler#y
Gura_DeclareProperty_RW(FTC_Scaler, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_Scaler, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_Scaler, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_Scaler
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_Scaler)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_Scaler, x);
	Gura_AssignProperty(FTC_Scaler, y);
#endif
	Gura_AssignValue(FTC_Saler, Value(Reference()));
}

Gura_EndModuleScope(freetype)
