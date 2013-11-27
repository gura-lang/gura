#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_toy_font_face implementation
//-----------------------------------------------------------------------------
String Object_toy_font_face::ToString(bool exprFlag)
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
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a font face from a triplet of family, slant, and weight.\n"
	"These font faces are used in implementation of the the cairo_t \"toy\" font API.\n"
	"\n"
	"If family is the zero-length string \"\", the platform-specific default family is assumed.\n"
	"The default family then can be queried using cairo.toy_font_face#get_family().\n"
	"\n"
	"The cairo.context#select_font_face() function uses this to create font faces.\n"
	"See that function for limitations and other details of toy font faces.\n"
	);
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

// cairo.toy_font_face#get_family()
Gura_DeclareMethod(toy_font_face, get_family)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the familly name of a toy font.\n"
	);
}

Gura_ImplementMethod(toy_font_face, get_family)
{
	Object_toy_font_face *pThis = Object_toy_font_face::GetThisObj(args);
	cairo_font_face_t *font_face = pThis->GetEntity();
	const char *rtn = ::cairo_toy_font_face_get_family(font_face);
	return Value(rtn);
}

// cairo.toy_font_face#get_slant()
Gura_DeclareMethod(toy_font_face, get_slant)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the slant a toy font.\n"
	);
}

Gura_ImplementMethod(toy_font_face, get_slant)
{
	Object_toy_font_face *pThis = Object_toy_font_face::GetThisObj(args);
	cairo_font_face_t *font_face = pThis->GetEntity();
	cairo_font_slant_t rtn = ::cairo_toy_font_face_get_slant(font_face);
	return Value(rtn);
}

// cairo.toy_font_face#get_weight()
Gura_DeclareMethod(toy_font_face, get_weight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the weight a toy font.\n"
	);
}

Gura_ImplementMethod(toy_font_face, get_weight)
{
	Object_toy_font_face *pThis = Object_toy_font_face::GetThisObj(args);
	cairo_font_face_t *font_face = pThis->GetEntity();
	cairo_font_weight_t rtn = ::cairo_toy_font_face_get_weight(font_face);
	return Value(rtn);
}

// implementation of class toy_font_face
Gura_ImplementUserClass(toy_font_face)
{
	Gura_AssignMethod(toy_font_face, create);
	Gura_AssignMethod(toy_font_face, get_family);
	Gura_AssignMethod(toy_font_face, get_slant);
	Gura_AssignMethod(toy_font_face, get_weight);
}

Gura_EndModuleScope(cairo)
