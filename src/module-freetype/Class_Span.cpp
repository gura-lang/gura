#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Span implementation
//-----------------------------------------------------------------------------
Object *Object_Span::Clone() const
{
	return nullptr;
}

String Object_Span::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Span>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.Span#x
Gura_DeclareProperty_RW(Span, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Span, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Span, x)
{
	return Value::Nil;
}

// freetype.Span#y
Gura_DeclareProperty_RW(Span, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Span, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(Span, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Span
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Span)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(Span, x);
	Gura_AssignProperty(Span, y);
#endif
	Gura_AssignValue(Span, Value(Reference()));
}

Gura_EndModuleScope(freetype)
