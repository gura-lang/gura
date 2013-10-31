#ifndef __CAIRO_OBJECT_USER_FONT_FACE_H__
#define __CAIRO_OBJECT_USER_FONT_FACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_user_font_face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(user_font_face);

class Object_user_font_face : public Object_font_face {
private:
	//static cairo_user_data_key_t key_ObjFontFaceL;
public:
	Gura_DeclareObjectAccessor(user_font_face)
public:
	inline Object_user_font_face(cairo_font_face_t *font_face) :
										Object_font_face(font_face) {}
	virtual String ToString(Signal sig, bool exprFlag);
public:
	static cairo_status_t init_func(cairo_scaled_font_t *scaled_font,
			cairo_t *cr, cairo_font_extents_t *extents);
	static cairo_status_t render_glyph_func(cairo_scaled_font_t *scaled_font,
			unsigned long  glyph, cairo_t *cr, cairo_text_extents_t *extents);
	static cairo_status_t text_to_glyphs_func(cairo_scaled_font_t *scaled_font,
			const char *utf8, int utf8_len,
			cairo_glyph_t **glyphs, int *num_glyphs,
			cairo_text_cluster_t **clusters, int *num_clusters,
			cairo_text_cluster_flags_t *cluster_flags);
	static cairo_status_t unicode_to_glyph_func(cairo_scaled_font_t *scaled_font,
			unsigned long  unicode, unsigned long *glyph_index);
};

Gura_EndModuleScope(cairo)

#endif
