#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_ft_font_face implementation
//-----------------------------------------------------------------------------
String Object_ft_font_face::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.ft_font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for ft_font_face
//-----------------------------------------------------------------------------
//#cairo_font_face_t *cairo_ft_font_face_create_for_ft_face(FT_Face face, int load_flags);
//#cairo_font_face_t *cairo_ft_font_face_create_for_pattern(FcPattern *pattern);

//#unsigned int cairo_ft_font_face_get_synthesize(cairo_font_face_t *font_face);
//#void cairo_ft_font_face_set_synthesize(cairo_font_face_t *font_face, unsigned int synth_flags);
//#void cairo_ft_font_face_unset_synthesize (cairo_font_face_t *font_face, unsigned int synth_flags);

// implementation of class ft_font_face
Gura_ImplementUserClass(ft_font_face)
{
}

}}
