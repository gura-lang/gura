#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_ft_font_face implementation
//-----------------------------------------------------------------------------
String Object_ft_font_face::ToString(bool exprFlag)
{
	return String("<cairo.ft_font_face>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for ft_font_face
//-----------------------------------------------------------------------------
#if 0
// cairo.ft_font_face.create_for_ft_face(face:FT_Face, load_flag:number) {block?}
Gura_DeclareClassMethod(ft_font_face, create_for_ft_face)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "face", VTYPE_number);
	DeclareArg(env, "load_flag", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(ft_font_face, create_for_ft_face)
{
	//FT_Face face = NULL;
	int load_flag = args.GetInt(1);
	cairo_font_face_t *font_face = ::cairo_ft_font_face_create_for_ft_face(face, load_flags);
	Object_ft_font_face *pObjFontFace = new Object_ft_font_face(font_face);
	return ReturnValue(env, sig, args, Value(pObjFontFace));
}
#endif

//#cairo_font_face_t *cairo_ft_font_face_create_for_pattern(FcPattern *pattern);

//#unsigned int cairo_ft_font_face_get_synthesize(cairo_font_face_t *font_face);
//#void cairo_ft_font_face_set_synthesize(cairo_font_face_t *font_face, unsigned int synth_flags);
//#void cairo_ft_font_face_unset_synthesize (cairo_font_face_t *font_face, unsigned int synth_flags);

// implementation of class ft_font_face
Gura_ImplementUserClass(ft_font_face)
{
}

Gura_EndModuleScope(cairo)
