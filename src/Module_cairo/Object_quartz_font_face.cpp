#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_quartz_font_face implementation
//-----------------------------------------------------------------------------
String Object_quartz_font_face::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.quartz_font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for quartz_font_face
//-----------------------------------------------------------------------------
//#unsigned int cairo_font_face_get_reference_count(cairo_font_face_t *font_face);
//#cairo_status_t cairo_font_face_set_user_data(cairo_font_face_t *font_face, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_font_face_get_user_data(cairo_font_face_t *font_face, const cairo_user_data_key_t *key);

//#cairo_font_face_t *cairo_toy_font_face_create(const char *family, cairo_font_slant_t slant, cairo_font_weight_t weight);

//#cairo_font_face_t *cairo_quartz_font_face_create_for_ft_face(FT_Face face, int load_flags);
//#cairo_font_face_t *cairo_quartz_font_face_create_for_pattern(FcPattern *pattern);

//#cairo_font_face_t *cairo_quartz_font_face_create_for_logfontw(LOGFONTW *logfont);
//#cairo_font_face_t *cairo_quartz_font_face_create_for_hfont(HFONT font);
//#cairo_font_face_t *cairo_quartz_font_face_create_for_logfontw_hfont(LOGFONTW *logfont, HFONT font);

//#cairo_font_face_t *cairo_quartz_font_face_create_for_cgfont(CGFontRef font);
//#cairo_font_face_t *cairo_quartz_font_face_create_for_atsu_font_id(ATSUFontID font_id);

//#cairo_font_face_t *cairo_user_font_face_create(void);

//#const char *cairo_toy_font_face_get_family(cairo_font_face_t *font_face);
//#cairo_font_slant_t cairo_toy_font_face_get_slant(cairo_font_face_t *font_face);
//#cairo_font_weight_t cairo_toy_font_face_get_weight(cairo_font_face_t *font_face);

//#unsigned int cairo_quartz_font_face_get_synthesize(cairo_font_face_t *font_face);
//#void cairo_quartz_font_face_set_synthesize(cairo_font_face_t *font_face, unsigned int synth_flags);
//#void cairo_quartz_font_face_unset_synthesize (cairo_font_face_t *font_face, unsigned int synth_flags);

//#void cairo_user_font_face_set_init_func(cairo_font_face_t *font_face,  cairo_user_scaled_font_init_func_t init_func);
//#cairo_user_scaled_font_init_func_t cairo_user_font_face_get_init_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_render_glyph_func(cairo_font_face_t *font_face, cairo_user_scaled_font_render_glyph_func_t render_glyph_func);
//#cairo_user_scaled_font_render_glyph_func_t cairo_user_font_face_get_render_glyph_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_unicode_to_glyph_func(cairo_font_face_t *font_face, cairo_user_scaled_font_unicode_to_glyph_func_t unicode_to_glyph_func);
//#cairo_user_scaled_font_unicode_to_glyph_func_t cairo_user_font_face_get_unicode_to_glyph_func(cairo_font_face_t *font_face);
//#void cairo_user_font_face_set_text_to_glyphs_func(cairo_font_face_t *font_face, cairo_user_scaled_font_text_to_glyphs_func_t text_to_glyphs_func);
//#cairo_user_scaled_font_text_to_glyphs_func_t cairo_user_font_face_get_text_to_glyphs_func(cairo_font_face_t *font_face);

// implementation of class quartz_font_face
Gura_ImplementUserClass(quartz_font_face)
{
}

}}
