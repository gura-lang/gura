#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_font_face implementation
//-----------------------------------------------------------------------------
Object_font_face::~Object_font_face()
{
	::cairo_font_face_destroy(_font_face);
}

Object *Object_font_face::Clone() const
{
	return nullptr;
}

String Object_font_face::ToString(bool exprFlag)
{
	return String("<cairo.font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for font_face
//-----------------------------------------------------------------------------
//#cairo_font_face_t *cairo_font_face_reference(cairo_font_face_t *font_face);
//#void cairo_font_face_destroy(cairo_font_face_t *font_face);

// cairo.font_face#status()
Gura_DeclareMethod(font_face, status)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_face, status)
{
	Object_font_face *pThis = Object_font_face::GetObjectThis(args);
	cairo_font_face_t *font_face = pThis->GetEntity();
	cairo_status_t rtn = cairo_font_face_status(font_face);
	return Value(rtn);
}

// cairo.font_face#get_type()
Gura_DeclareMethod(font_face, get_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(font_face, get_type)
{
	Object_font_face *pThis = Object_font_face::GetObjectThis(args);
	cairo_font_face_t *font_face = pThis->GetEntity();
	cairo_font_type_t rtn = cairo_font_face_get_type(font_face);
	return Value(rtn);
}

//#unsigned int cairo_font_face_get_reference_count(cairo_font_face_t *font_face);
//#cairo_status_t cairo_font_face_set_user_data(cairo_font_face_t *font_face, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_font_face_get_user_data(cairo_font_face_t *font_face, const cairo_user_data_key_t *key);

// implementation of class font_face
Gura_ImplementUserClass(font_face)
{
}

Gura_EndModuleScope(cairo)
