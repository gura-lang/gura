#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_ImageCache implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_ImageCache::Clone() const
{
	return nullptr;
}

String Object_FTC_ImageCache::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_ImageCache>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_ImageCache#x
Gura_DeclareProperty_RW(FTC_ImageCache, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_ImageCache, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_ImageCache, x)
{
	return Value::Nil;
}

// freetype.FTC_ImageCache#y
Gura_DeclareProperty_RW(FTC_ImageCache, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_ImageCache, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_ImageCache, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_ImageCache
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_ImageCache)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_ImageCache, x);
	Gura_AssignProperty(FTC_ImageCache, y);
#endif
	Gura_AssignValue(FTC_ImageCache, Value(Reference()));
}

Gura_EndModuleScope(freetype)
