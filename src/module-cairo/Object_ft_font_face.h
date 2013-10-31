#ifndef __CAIRO_OBJECT_FT_FONT_FACE_H__
#define __CAIRO_OBJECT_FT_FONT_FACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_ft_font_face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ft_font_face);

class Object_ft_font_face : public Object_font_face {
public:
	Gura_DeclareObjectAccessor(ft_font_face)
public:
	inline Object_ft_font_face(cairo_font_face_t *font_face) :
										Object_font_face(font_face) {}
	virtual String ToString(Signal sig, bool exprFlag);
};

Gura_EndModuleScope(cairo)

#endif
