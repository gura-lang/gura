#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//static cairo_user_data_key_t Object_user_font_face::key_ObjFontFaceL;

void destroy_ObjFontFace(void *data)
{
	Object_font_face *pObjFontFace = reinterpret_cast<Object_font_face *>(data);
	Object::Delete(pObjFontFace);
}

//-----------------------------------------------------------------------------
// Object_user_font_face implementation
//-----------------------------------------------------------------------------
String Object_user_font_face::ToString(bool exprFlag)
{
	return String("<cairo.user_font_face>");
}

cairo_status_t Object_user_font_face::init_func(cairo_scaled_font_t *scaled_font,
		cairo_t *cr, cairo_font_extents_t *extents)
{
	cairo_font_face_t *font_face = ::cairo_scaled_font_get_font_face(scaled_font);
	//Object_font_face *pObjFontFace = reinterpret_cast<Object_font_face *>(
	//					::cairo_font_face_get_user_data(font_face, &key_ObjFontFace));
	
	return CAIRO_STATUS_SUCCESS;
}

cairo_status_t Object_user_font_face::render_glyph_func(cairo_scaled_font_t *scaled_font,
		unsigned long  glyph, cairo_t *cr, cairo_text_extents_t *extents)
{
	return CAIRO_STATUS_SUCCESS;
}

cairo_status_t Object_user_font_face::text_to_glyphs_func(cairo_scaled_font_t *scaled_font,
		const char *utf8, int utf8_len,
		cairo_glyph_t **glyphs, int *num_glyphs,
		cairo_text_cluster_t **clusters, int *num_clusters,
		cairo_text_cluster_flags_t *cluster_flags)
{
	return CAIRO_STATUS_SUCCESS;
}

cairo_status_t Object_user_font_face::unicode_to_glyph_func(cairo_scaled_font_t *scaled_font,
		unsigned long  unicode, unsigned long *glyph_index)
{
	return CAIRO_STATUS_SUCCESS;
}

//-----------------------------------------------------------------------------
// Gura interfaces for user_font_face
//-----------------------------------------------------------------------------
// cairo.user_font_face.create() {block?}
Gura_DeclareClassMethod(user_font_face, create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(user_font_face, create)
{
	cairo_font_face_t *font_face = ::cairo_user_font_face_create();
	Object_user_font_face *pObjFontFace = new Object_user_font_face(font_face);
	//::cairo_font_face_set_user_data(font_face, &key_ObjFontFace,
	//		Object_user_font_face::Reference(pObjFontFace), destroy_ObjFontFace);
	::cairo_user_font_face_set_init_func(font_face, Object_user_font_face::init_func);
	::cairo_user_font_face_set_render_glyph_func(font_face, Object_user_font_face::render_glyph_func);
	::cairo_user_font_face_set_unicode_to_glyph_func(font_face, Object_user_font_face::unicode_to_glyph_func);
	::cairo_user_font_face_set_text_to_glyphs_func(font_face, Object_user_font_face::text_to_glyphs_func);
	return ReturnValue(env, sig, args, Value(pObjFontFace));
}

//#cairo_user_scaled_font_init_func_t cairo_user_font_face_get_init_func(cairo_font_face_t *font_face);
//#cairo_user_scaled_font_render_glyph_func_t cairo_user_font_face_get_render_glyph_func(cairo_font_face_t *font_face);
//#cairo_user_scaled_font_unicode_to_glyph_func_t cairo_user_font_face_get_unicode_to_glyph_func(cairo_font_face_t *font_face);
//#cairo_user_scaled_font_text_to_glyphs_func_t cairo_user_font_face_get_text_to_glyphs_func(cairo_font_face_t *font_face);

// implementation of class user_font_face
Gura_ImplementUserClass(user_font_face)
{
	Gura_AssignMethod(user_font_face, create);
}

Gura_EndModuleScope(cairo)
