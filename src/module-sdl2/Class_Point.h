#ifndef __SDL2_CLASS_POINT_H__
#define __SDL2_CLASS_POINT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Point declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Point);

class Object_Point : public Object {
private:
	SDL_Point _point;
public:
	Gura_DeclareObjectAccessor(Point)
public:
	inline Object_Point(const SDL_Point &point) :
						Object(Gura_UserClass(Point)), _point(point) {}
	virtual ~Object_Point();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_Point *GetEntity() { return &_point; }
};

Gura_EndModuleScope(sdl2)

#endif
