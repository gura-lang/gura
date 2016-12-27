#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_font_extents implementation
//-----------------------------------------------------------------------------
Object_font_extents::~Object_font_extents()
{
}

Object *Object_font_extents::Clone() const
{
	return nullptr;
}

String Object_font_extents::ToString(bool exprFlag)
{
	return String("<cairo.font_extents>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// cairo.font_extents#ascent
Gura_DeclareProperty_R(font_extents, ascent)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(font_extents, ascent)
{
	const cairo_font_extents_t &font_extents =
		Object_font_extents::GetObject(valueThis)->GetEntity();
	return Value(font_extents.ascent);
}

// cairo.font_extents#descent
Gura_DeclareProperty_R(font_extents, descent)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(font_extents, descent)
{
	const cairo_font_extents_t &font_extents =
		Object_font_extents::GetObject(valueThis)->GetEntity();
	return Value(font_extents.descent);
}

// cairo.font_extents#height
Gura_DeclareProperty_R(font_extents, height)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(font_extents, height)
{
	const cairo_font_extents_t &font_extents =
		Object_font_extents::GetObject(valueThis)->GetEntity();
	return Value(font_extents.height);
}

// cairo.font_extents#max_x_advance
Gura_DeclareProperty_R(font_extents, max_x_advance)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(font_extents, max_x_advance)
{
	const cairo_font_extents_t &font_extents =
		Object_font_extents::GetObject(valueThis)->GetEntity();
	return Value(font_extents.max_x_advance);
}

// cairo.font_extents#max_y_advance
Gura_DeclareProperty_R(font_extents, max_y_advance)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(font_extents, max_y_advance)
{
	const cairo_font_extents_t &font_extents =
		Object_font_extents::GetObject(valueThis)->GetEntity();
	return Value(font_extents.max_y_advance);
}

//-----------------------------------------------------------------------------
// Gura interfaces for font_extents
//-----------------------------------------------------------------------------
// implementation of class font_extents
Gura_ImplementUserClass(font_extents)
{
	// Assignment of properties
	Gura_AssignProperty(font_extents, ascent);
	Gura_AssignProperty(font_extents, descent);
	Gura_AssignProperty(font_extents, height);
	Gura_AssignProperty(font_extents, max_x_advance);
	Gura_AssignProperty(font_extents, max_y_advance);
}

Gura_EndModuleScope(cairo)
