#ifndef __CAIRO_OBJECT_FONT_FACE_H__
#define __CAIRO_OBJECT_FONT_FACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_font_face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(font_face);

class Object_font_face : public Object {
private:
	cairo_font_face_t *_font_face;
public:
	Gura_DeclareObjectAccessor(font_face)
public:
	inline Object_font_face(cairo_font_face_t *font_face) :
					Object(Gura_UserClass(font_face)), _font_face(font_face) {}
	virtual ~Object_font_face();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_font_face_t *GetEntity() { return _font_face; }
};

Gura_EndModuleScope(cairo)

#endif
