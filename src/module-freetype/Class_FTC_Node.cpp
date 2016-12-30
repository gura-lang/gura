#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_Node implementation
//-----------------------------------------------------------------------------
Object *Object_FTC_Node::Clone() const
{
	return nullptr;
}

String Object_FTC_Node::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.FTC_Node>");
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.FTC_Node#x
Gura_DeclareProperty_RW(FTC_Node, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_Node, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_Node, x)
{
	return Value::Nil;
}

// freetype.FTC_Node#y
Gura_DeclareProperty_RW(FTC_Node, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(FTC_Node, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(FTC_Node, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.FTC_Node
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(FTC_Node)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(FTC_Node, x);
	Gura_AssignProperty(FTC_Node, y);
#endif
	Gura_AssignValue(FTC_Node, Value(Reference()));
}

Gura_EndModuleScope(freetype)
