#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_CharMap implementation
//-----------------------------------------------------------------------------
Object *Object_CharMap::Clone() const
{
	return nullptr;
}

String Object_CharMap::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.CharMap>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.CharMap#x
Gura_DeclareProperty_RW(CharMap, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(CharMap, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(CharMap, x)
{
	return Value::Nil;
}

// freetype.CharMap#y
Gura_DeclareProperty_RW(CharMap, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(CharMap, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(CharMap, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for freetype.CharMap
//-----------------------------------------------------------------------------
// freetype.CharMap#Get_Index()
Gura_DeclareMethod(CharMap, Get_Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(CharMap, Get_Index)
{
	FT_CharMap charmap = Object_CharMap::GetObjectThis(arg)->GetEntity();
	FT_Int rtn = ::FT_Get_Charmap_Index(charmap);
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.CharMap
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(CharMap)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(CharMap, x);
	Gura_AssignProperty(CharMap, y);
#endif
	Gura_AssignValue(CharMap, Value(Reference()));
	Gura_AssignMethod(CharMap, Get_Index);
}

Gura_EndModuleScope(freetype)
