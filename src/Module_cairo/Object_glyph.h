#ifndef __CAIRO_OBJECT_GLYPH_H__
#define __CAIRO_OBJECT_GLYPH_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_glyph declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(glyph);

class Object_glyph : public Object {
private:
	cairo_glyph_t _glyph;
public:
	Gura_DeclareObjectAccessor(glyph)
public:
	inline Object_glyph(const cairo_glyph_t &glyph) :
						Object(Gura_UserClass(glyph)), _glyph(glyph) {}
	virtual ~Object_glyph();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_glyph_t &GetEntity() { return _glyph; }
	inline const cairo_glyph_t &GetEntity() const { return _glyph; }
};

}}

#endif
