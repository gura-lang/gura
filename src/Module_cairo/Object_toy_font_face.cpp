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
// cairo.toy_font_face.create(family:string, slant:number, weight:number) {block?}
Gura_DeclareClassMethod(toy_font_face, create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "family", VTYPE_string);
	DeclareArg(env, "slant", VTYPE_number);
	DeclareArg(env, "weight", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(toy_font_face, create)
{
	const char *family = args.GetString(0);
	cairo_font_slant_t slant = static_cast<cairo_font_slant_t>(args.GetInt(1));
	cairo_font_weight_t weight = static_cast<cairo_font_weight_t>(args.GetInt(2));
	cairo_font_face_t *font_face = ::cairo_toy_font_face_create(family, slant, weight);
	Object_toy_font_face *pObjFontFace = new Object_toy_font_face(font_face);
	return ReturnValue(env, sig, args, Value(pObjFontFace));
}

//#const char *cairo_toy_font_face_get_family(cairo_font_face_t *font_face);
//#cairo_font_slant_t cairo_toy_font_face_get_slant(cairo_font_face_t *font_face);
//#cairo_font_weight_t cairo_toy_font_face_get_weight(cairo_font_face_t *font_face);

// implementation of class toy_font_face
Gura_ImplementUserClass(toy_font_face)
{
	Gura_AssignMethod(toy_font_face, create);
}

}}
