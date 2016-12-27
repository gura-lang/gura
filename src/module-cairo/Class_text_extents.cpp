#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_text_extents implementation
//-----------------------------------------------------------------------------
Object_text_extents::~Object_text_extents()
{
}

Object *Object_text_extents::Clone() const
{
	return nullptr;
}

String Object_text_extents::ToString(bool exprFlag)
{
	return String("<cairo.text_extents>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// cairo.text_extents#height
Gura_DeclareProperty_R(text_extents, height)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(text_extents, height)
{
	const cairo_text_extents_t &text_extents =
		Object_text_extents::GetObject(valueThis)->GetEntity();
	return Value(text_extents.height);
}

// cairo.text_extents#width
Gura_DeclareProperty_R(text_extents, width)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(text_extents, width)
{
	const cairo_text_extents_t &text_extents =
		Object_text_extents::GetObject(valueThis)->GetEntity();
	return Value(text_extents.width);
}

// cairo.text_extents#x_advance
Gura_DeclareProperty_R(text_extents, x_advance)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(text_extents, x_advance)
{
	const cairo_text_extents_t &text_extents =
		Object_text_extents::GetObject(valueThis)->GetEntity();
	return Value(text_extents.x_advance);
}

// cairo.text_extents#x_bearing
Gura_DeclareProperty_R(text_extents, x_bearing)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(text_extents, x_bearing)
{
	const cairo_text_extents_t &text_extents =
		Object_text_extents::GetObject(valueThis)->GetEntity();
	return Value(text_extents.x_bearing);
}

// cairo.text_extents#y_advance
Gura_DeclareProperty_R(text_extents, y_advance)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(text_extents, y_advance)
{
	const cairo_text_extents_t &text_extents =
		Object_text_extents::GetObject(valueThis)->GetEntity();
	return Value(text_extents.y_advance);
}

// cairo.text_extents#y_bearing
Gura_DeclareProperty_R(text_extents, y_bearing)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(text_extents, y_bearing)
{
	const cairo_text_extents_t &text_extents =
		Object_text_extents::GetObject(valueThis)->GetEntity();
	return Value(text_extents.y_bearing);
}

//-----------------------------------------------------------------------------
// Gura interfaces for text_extents
//-----------------------------------------------------------------------------
// implementation of class text_extents
Gura_ImplementUserClass(text_extents)
{
	// Assignment of properties
	Gura_AssignProperty(text_extents, height);
	Gura_AssignProperty(text_extents, width);
	Gura_AssignProperty(text_extents, x_advance);
	Gura_AssignProperty(text_extents, x_bearing);
	Gura_AssignProperty(text_extents, y_advance);
	Gura_AssignProperty(text_extents, y_bearing);
}

Gura_EndModuleScope(cairo)
