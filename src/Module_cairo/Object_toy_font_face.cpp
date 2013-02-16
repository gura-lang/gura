#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_toy_font_face implementation
//-----------------------------------------------------------------------------
String Object_toy_font_face::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.toy_font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for toy_font_face
//-----------------------------------------------------------------------------
//#cairo_font_face_t *cairo_toy_font_face_create(const char *family, cairo_font_slant_t slant, cairo_font_weight_t weight);
//#const char *cairo_toy_font_face_get_family(cairo_font_face_t *font_face);
//#cairo_font_slant_t cairo_toy_font_face_get_slant(cairo_font_face_t *font_face);
//#cairo_font_weight_t cairo_toy_font_face_get_weight(cairo_font_face_t *font_face);

// implementation of class toy_font_face
Gura_ImplementUserClass(toy_font_face)
{
}

}}
