#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_mesh_pattern implementation
//-----------------------------------------------------------------------------
String Object_mesh_pattern::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.mesh_pattern>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for mesh_pattern
//-----------------------------------------------------------------------------
// cairo.mesh_pattern.create() {block?}
Gura_DeclareClassMethod(mesh_pattern, create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(mesh_pattern, create)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_mesh();
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_mesh_pattern(pattern)));
}

//#void cairo_mesh_pattern_begin_patch(cairo_pattern_t *pattern);
//#void cairo_mesh_pattern_end_patch(cairo_pattern_t *pattern);
//#void cairo_mesh_pattern_move_to(cairo_pattern_t *pattern, double x, double y);
//#void cairo_mesh_pattern_line_to(cairo_pattern_t *pattern, double x, double y);
//#void cairo_mesh_pattern_curve_to(cairo_pattern_t *pattern, double x1, double y1, double x2, double y2, double x3, double y3);
//#void cairo_mesh_pattern_set_control_point(cairo_pattern_t *pattern, unsigned int point_num, double x, double y);
//#void cairo_mesh_pattern_set_corner_color_rgb(cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue);
//#void cairo_mesh_pattern_set_corner_color_rgba(cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue, double alpha);
//#cairo_status_t cairo_mesh_pattern_get_patch_count(cairo_pattern_t *pattern, unsigned int *count);
//#cairo_path_t *cairo_mesh_pattern_get_path(cairo_pattern_t *pattern, unsigned int patch_num);
//#cairo_status_t cairo_mesh_pattern_get_control_point(cairo_pattern_t *pattern, unsigned int patch_num, unsigned int point_num, double *x, double *y);
//#cairo_status_t cairo_mesh_pattern_get_corner_color_rgba(cairo_pattern_t *pattern, unsigned int patch_num, unsigned int corner_num, double *red, double *green, double *blue, double *alpha);

// implementation of class mesh_pattern
Gura_ImplementUserClass(mesh_pattern)
{
}

}}
