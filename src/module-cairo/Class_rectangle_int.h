#ifndef __CAIRO_CLASS_RECTANGLE_INT_H__
#define __CAIRO_CLASS_RECTANGLE_INT_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_rectangle_int declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(rectangle_int);

class Object_rectangle_int : public Object {
private:
	cairo_rectangle_int_t _rectangle;
public:
	Gura_DeclareObjectAccessor(rectangle_int)
public:
	inline Object_rectangle_int(const cairo_rectangle_int_t &rectangle) :
					Object(Gura_UserClass(rectangle_int)), _rectangle(rectangle) {}
	virtual ~Object_rectangle_int();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline cairo_rectangle_int_t &GetEntity() { return _rectangle; }
};

Gura_EndModuleScope(cairo)

#endif
