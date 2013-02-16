#ifndef __CAIRO_OBJECT_USER_FONT_FACE_H__
#define __CAIRO_OBJECT_USER_FONT_FACE_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_user_font_face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(user_font_face);

class Object_user_font_face : public Object_font_face {
public:
	Gura_DeclareObjectAccessor(user_font_face)
public:
	inline Object_user_font_face(cairo_font_face_t *font_face) :
										Object_font_face(font_face) {}
	virtual String ToString(Signal sig, bool exprFlag);
};

}}

#endif
