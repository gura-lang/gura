#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_glyph implementation
//-----------------------------------------------------------------------------
Object_glyph::~Object_glyph()
{
	::cairo_glyph_free(_glyphs);
}

Object *Object_glyph::Clone() const
{
	return NULL;
}

String Object_glyph::ToString(bool exprFlag)
{
	return String("<cairo.glyph>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for glyph
//-----------------------------------------------------------------------------
// cairo.glyph.allocate(num_glyphs:number) {block?}
Gura_DeclareClassMethod(glyph, allocate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num_glyphs", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(glyph, allocate)
{
	int num_glyphs = args.GetInt(0);
	cairo_glyph_t *glyphs = ::cairo_glyph_allocate(num_glyphs);
	Object_glyph *pObjGlyph = new Object_glyph(glyphs, num_glyphs);
	return ReturnValue(env, sig, args, Value(pObjGlyph));
}

// implementation of class glyph
Gura_ImplementUserClass(glyph)
{
	Gura_AssignMethod(glyph, allocate);
}

Gura_EndModuleScope(cairo)
