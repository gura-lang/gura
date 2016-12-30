#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_Manager implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_Manager::Clone() const
{
	return nullptr;
}

String Object_FTC_Manager::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_Manager>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_Manager#x
Gura_DeclareProperty_RW(FTC_Manager, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_Manager, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_Manager, x)
{
	return Value::Nil;
}

// freetype.FTC_Manager#y
Gura_DeclareProperty_RW(FTC_Manager, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_Manager, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_Manager, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_Manager
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_Manager)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_Manager, x);
	Gura_AssignProperty(FTC_Manager, y);
#endif
	Gura_AssignValue(FTC_Manager, Value(Reference()));
}

Gura_EndModuleScope(freetype)
