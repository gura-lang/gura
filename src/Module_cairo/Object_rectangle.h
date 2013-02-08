#ifndef __CAIRO_OBJECT_RECTANGLE_H__
#define __CAIRO_OBJECT_RECTANGLE_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_rectangle declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(rectangle);

class Object_rectangle : public Object {
private:
	cairo_rectangle_t _rectangle;
public:
	Gura_DeclareObjectAccessor(rectangle)
public:
	inline Object_rectangle(const cairo_rectangle_t &rectangle) :
					Object(Gura_UserClass(rectangle)), _rectangle(rectangle) {}
	virtual ~Object_rectangle();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_rectangle_t &GetEntity() { return _rectangle; }
};

}}

#endif
