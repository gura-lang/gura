#ifndef __SDL2_CLASS_RECT_H__
#define __SDL2_CLASS_RECT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Rect declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Rect);

class Object_Rect : public Object {
private:
	SDL_Rect _rect;
public:
	Gura_DeclareObjectAccessor(Rect)
public:
	inline Object_Rect(const SDL_Rect &rect) :
						Object(Gura_UserClass(Rect)), _rect(rect) {}
	virtual ~Object_Rect();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_Rect &GetEntity() { return _rect; }
};

Gura_EndModuleScope(sdl2)

#endif
