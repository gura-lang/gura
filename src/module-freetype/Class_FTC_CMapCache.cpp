#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_CMapCache implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_CMapCache::Clone() const
{
	return nullptr;
}

String Object_FTC_CMapCache::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_CMapCache>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_CMapCache#x
Gura_DeclareProperty_RW(FTC_CMapCache, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_CMapCache, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_CMapCache, x)
{
	return Value::Nil;
}

// freetype.FTC_CMapCache#y
Gura_DeclareProperty_RW(FTC_CMapCache, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_CMapCache, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_CMapCache, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_CMapCache
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_CMapCache)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_CMapCache, x);
	Gura_AssignProperty(FTC_CMapCache, y);
#endif
	Gura_AssignValue(FTC_CMapCache, Value(Reference()));
}

Gura_EndModuleScope(freetype)
