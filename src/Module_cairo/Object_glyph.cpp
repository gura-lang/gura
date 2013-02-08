#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_glyph implementation
//-----------------------------------------------------------------------------
Object_glyph::~Object_glyph()
{
}

Object *Object_glyph::Clone() const
{
	return NULL;
}

String Object_glyph::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.glyph>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for glyph
//-----------------------------------------------------------------------------
//#cairo_glyph_t *cairo_glyph_allocate(int num_glyphs);
//#void cairo_glyph_free(cairo_glyph_t *glyphs);

// implementation of class glyph
Gura_ImplementUserClass(glyph)
{
}

}}
