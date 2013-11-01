#ifndef __CAIRO_CLASS_QUARTZ_FONT_FACE_H__
#define __CAIRO_CLASS_QUARTZ_FONT_FACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_quartz_font_face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(quartz_font_face);

class Object_quartz_font_face : public Object_font_face {
public:
	Gura_DeclareObjectAccessor(quartz_font_face)
public:
	inline Object_quartz_font_face(cairo_font_face_t *font_face) :
										Object_font_face(font_face) {}
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(cairo)

#endif
