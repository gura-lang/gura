#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_scaled_font implementation
//-----------------------------------------------------------------------------
Object_scaled_font::~Object_scaled_font()
{
	::cairo_scaled_font_destroy(_scaled_font);
}

Object *Object_scaled_font::Clone() const
{
	return nullptr;
}

String Object_scaled_font::ToString(bool exprFlag)
{
	return String("<cairo.scaled_font>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for scaled_font
//-----------------------------------------------------------------------------
//#cairo_scaled_font_t *cairo_scaled_font_create(cairo_font_face_t *font_face, const cairo_matrix_t *font_matrix, const cairo_matrix_t *ctm, const cairo_font_options_t *options);
// cairo.scaled_font.create(font_face:cairo.font_face,
//            font_matrix:matrix, ctm:matrix, options:cairo.font_options) {block?}
Gura_DeclareClassMethod(scaled_font, create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "font_face", VTYPE_font_face);
	DeclareArg(env, "font_matrix", VTYPE_matrix);
	DeclareArg(env, "ctm", VTYPE_matrix);
	DeclareArg(env, "options", VTYPE_font_options);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementClassMethod(scaled_font, create)
{
	Signal &sig = env.GetSignal();
	cairo_font_face_t *font_face = Object_font_face::GetObject(args, 0)->GetEntity();
	cairo_matrix_t font_matrix;
	cairo_matrix_t ctm;
	if (!MatrixToCairo(sig, font_matrix,
			Object_matrix::GetObject(args, 1)->GetMatrix())) return Value::Null;
	if (!MatrixToCairo(sig, ctm,
			Object_matrix::GetObject(args, 2)->GetMatrix())) return Value::Null;
	cairo_font_options_t *options = Object_font_options::GetObject(args, 3)->GetEntity();
	cairo_scaled_font_t *scaled_font = ::cairo_scaled_font_create(
			::cairo_font_face_reference(font_face), &font_matrix, &ctm, options);
	return ReturnValue(env, args, Value(new Object_scaled_font(scaled_font)));
}

//#cairo_scaled_font_t *cairo_scaled_font_reference(cairo_scaled_font_t *scaled_font);
//#void cairo_scaled_font_destroy(cairo_scaled_font_t *scaled_font);

//#FT_Face cairo_ft_scaled_font_lock_face(cairo_scaled_font_t *scaled_font);
//#void cairo_ft_scaled_font_unlock_face(cairo_scaled_font_t *scaled_font);

//#cairo_status_t cairo_win32_scaled_font_select_font (cairo_scaled_font_t *scaled_font, HDC hdc);
//#void cairo_win32_scaled_font_done_font(cairo_scaled_font_t *scaled_font);
//#double cairo_win32_scaled_font_get_metrics_factor(cairo_scaled_font_t *scaled_font);
//#void cairo_win32_scaled_font_get_logical_to_device(cairo_scaled_font_t *scaled_font, cairo_matrix_t *logical_to_device);
//#void cairo_win32_scaled_font_get_device_to_logical(cairo_scaled_font_t *scaled_font, cairo_matrix_t *device_to_logical);

//#cairo_status_t cairo_scaled_font_status(cairo_scaled_font_t *scaled_font);

//#void cairo_scaled_font_extents(cairo_scaled_font_t *scaled_font, cairo_font_extents_t *extents);

//#void cairo_scaled_font_text_extents(cairo_scaled_font_t *scaled_font, const char *utf8, cairo_text_extents_t *extents);

//#void cairo_scaled_font_glyph_extents(cairo_scaled_font_t *scaled_font, const cairo_glyph_t *glyphs, int num_glyphs, cairo_text_extents_t *extents);

//#cairo_status_t cairo_scaled_font_text_to_glyphs(cairo_scaled_font_t *scaled_font, double x, double y, const char *utf8, int utf8_len, cairo_glyph_t **glyphs, int *num_glyphs, cairo_text_cluster_t **clusters, int *num_clusters, cairo_text_cluster_flags_t *cluster_flags);

//#cairo_font_face_t *cairo_scaled_font_get_font_face(cairo_scaled_font_t *scaled_font);

//#void cairo_scaled_font_get_font_options(cairo_scaled_font_t *scaled_font, cairo_font_options_t *options);

//#void cairo_scaled_font_get_font_matrix(cairo_scaled_font_t *scaled_font, cairo_matrix_t *font_matrix);

//#void cairo_scaled_font_get_ctm(cairo_scaled_font_t *scaled_font, cairo_matrix_t *ctm);

//#void cairo_scaled_font_get_scale_matrix(cairo_scaled_font_t *scaled_font, cairo_matrix_t *scale_matrix);

//#cairo_font_type_t cairo_scaled_font_get_type(cairo_scaled_font_t *scaled_font);

//#unsigned int cairo_scaled_font_get_reference_count(cairo_scaled_font_t *scaled_font);

//#cairo_status_t cairo_scaled_font_set_user_data(cairo_scaled_font_t *scaled_font, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_scaled_font_get_user_data(cairo_scaled_font_t *scaled_font, const cairo_user_data_key_t *key);

// implementation of class font_options
Gura_ImplementUserClass(scaled_font)
{
	Gura_AssignMethod(scaled_font, create);
}

Gura_EndModuleScope(cairo)
