#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_user_font_face implementation
//-----------------------------------------------------------------------------
String Object_user_font_face::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.user_font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for user_font_face
//-----------------------------------------------------------------------------
//#cairo_font_face_t *cairo_user_font_face_create(void);

//#void cairo_user_font_face_set_init_func(cairo_font_face_t *font_face,  cairo_user_scaled_font_init_func_t init_func);
//#cairo_user_scaled_font_init_func_t cairo_user_font_face_get_init_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_render_glyph_func(cairo_font_face_t *font_face, cairo_user_scaled_font_render_glyph_func_t render_glyph_func);
//#cairo_user_scaled_font_render_glyph_func_t cairo_user_font_face_get_render_glyph_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_unicode_to_glyph_func(cairo_font_face_t *font_face, cairo_user_scaled_font_unicode_to_glyph_func_t unicode_to_glyph_func);
//#cairo_user_scaled_font_unicode_to_glyph_func_t cairo_user_font_face_get_unicode_to_glyph_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_text_to_glyphs_func(cairo_font_face_t *font_face, cairo_user_scaled_font_text_to_glyphs_func_t text_to_glyphs_func);
//#cairo_user_scaled_font_text_to_glyphs_func_t cairo_user_font_face_get_text_to_glyphs_func(cairo_font_face_t *font_face);

// implementation of class user_font_face
Gura_ImplementUserClass(user_font_face)
{
}

}}
