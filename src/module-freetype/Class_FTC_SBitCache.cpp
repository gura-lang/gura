#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_SBitCache implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_SBitCache::Clone() const
{
	return nullptr;
}

String Object_FTC_SBitCache::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_SBitCache>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_SBitCache#x
Gura_DeclareProperty_RW(FTC_SBitCache, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_SBitCache, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_SBitCache, x)
{
	return Value::Nil;
}

// freetype.FTC_SBitCache#y
Gura_DeclareProperty_RW(FTC_SBitCache, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_SBitCache, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_SBitCache, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_SBitCache
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_SBitCache)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_SBitCache, x);
	Gura_AssignProperty(FTC_SBitCache, y);
#endif
	Gura_AssignValue(FTC_SBitCache, Value(Reference()));
}

Gura_EndModuleScope(freetype)
