#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_BBox implementation
//-----------------------------------------------------------------------------
Object *Object_BBox::Clone() const
{
	return nullptr;
}

String Object_BBox::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.BBox:xMin=%ld,yMin=%ld,xMax=%ld,yMax=%ld>",
						_bbox.xMin, _bbox.yMin, _bbox.xMax, _bbox.yMax);
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.BBox#xMax
Gura_DeclareProperty_RW(BBox, xMax)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BBox, xMax)
{
	const FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	return Value(bbox.xMax);
}

Gura_ImplementPropertySetter(BBox, xMax)
{
	FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	bbox.xMax = static_cast<FT_Pos>(value.GetLong());
	return Value(bbox.xMax);
}

// freetype.BBox#xMin
Gura_DeclareProperty_RW(BBox, xMin)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BBox, xMin)
{
	const FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	return Value(bbox.xMin);
}

Gura_ImplementPropertySetter(BBox, xMin)
{
	FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	bbox.xMin = static_cast<FT_Pos>(value.GetLong());
	return Value(bbox.xMin);
}

// freetype.BBox#yMax
Gura_DeclareProperty_RW(BBox, yMax)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BBox, yMax)
{
	const FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	return Value(bbox.yMax);
}

Gura_ImplementPropertySetter(BBox, yMax)
{
	FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	bbox.yMax = static_cast<FT_Pos>(value.GetLong());
	return Value(bbox.yMax);
}

// freetype.BBox#yMin
Gura_DeclareProperty_RW(BBox, yMin)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(BBox, yMin)
{
	const FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	return Value(bbox.yMin);
}

Gura_ImplementPropertySetter(BBox, yMin)
{
	FT_BBox &bbox = Object_BBox::GetObject(valueThis)->GetEntity();
	bbox.yMin = static_cast<FT_Pos>(value.GetLong());
	return Value(bbox.yMin);
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.BBox
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(BBox)
{
	// Assignment of properties
	Gura_AssignProperty(BBox, xMax);
	Gura_AssignProperty(BBox, xMin);
	Gura_AssignProperty(BBox, yMax);
	Gura_AssignProperty(BBox, yMin);
	// Assignment of value
	Gura_AssignValue(BBox, Value(Reference()));
}

Gura_EndModuleScope(freetype)
