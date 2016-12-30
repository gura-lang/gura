#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_BDF_Property implementation
//-----------------------------------------------------------------------------
Object *Object_BDF_Property::Clone() const
{
	return nullptr;
}

String Object_BDF_Property::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.BDF_Property>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.BDF_Property#x
Gura_DeclareProperty_RW(BDF_Property, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BDF_Property, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(BDF_Property, x)
{
	return Value::Nil;
}

// freetype.BDF_Property#y
Gura_DeclareProperty_RW(BDF_Property, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BDF_Property, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(BDF_Property, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.BDF_Property
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(BDF_Property)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(BDF_Property, x);
	Gura_AssignProperty(BDF_Property, y);
#endif
	Gura_AssignValue(BDF_Property, Value(Reference()));
}

Gura_EndModuleScope(freetype)
