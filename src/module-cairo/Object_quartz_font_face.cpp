#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_quartz_font_face implementation
//-----------------------------------------------------------------------------
String Object_quartz_font_face::ToString(bool exprFlag)
{
	return String("<cairo.quartz_font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for quartz_font_face
//-----------------------------------------------------------------------------
//#cairo_font_face_t *cairo_quartz_font_face_create_for_cgfont(CGFontRef font);
//#cairo_font_face_t *cairo_quartz_font_face_create_for_atsu_font_id(ATSUFontID font_id);

// implementation of class quartz_font_face
Gura_ImplementUserClass(quartz_font_face)
{
}

Gura_EndModuleScope(cairo)
