#ifndef __CAIRO_OBJECT_TOY_FONT_FACE_H__
#define __CAIRO_OBJECT_TOY_FONT_FACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_toy_font_face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(toy_font_face);

class Object_toy_font_face : public Object_font_face {
public:
	Gura_DeclareObjectAccessor(toy_font_face)
public:
	inline Object_toy_font_face(cairo_font_face_t *font_face) :
										Object_font_face(font_face) {}
	virtual String ToString(Signal sig, bool exprFlag);
};

Gura_EndModuleScope(cairo)

#endif
