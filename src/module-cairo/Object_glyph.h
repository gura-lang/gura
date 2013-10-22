#ifndef __CAIRO_OBJECT_GLYPH_H__
#define __CAIRO_OBJECT_GLYPH_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_glyph declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(glyph);

class Object_glyph : public Object {
private:
	cairo_glyph_t *_glyphs;
	int _num_glyphs;
public:
	Gura_DeclareObjectAccessor(glyph)
public:
	inline Object_glyph(cairo_glyph_t *glyphs, int num_glyphs) :
		Object(Gura_UserClass(glyph)), _glyphs(glyphs), _num_glyphs(num_glyphs) {}
	virtual ~Object_glyph();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_glyph_t *GetGlyphs() { return _glyphs; }
	inline int GetNumGlyphs() const { return _num_glyphs; }
};

}}

#endif
