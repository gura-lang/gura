#ifndef __SDL2_CLASS_COLOR_H__
#define __SDL2_CLASS_COLOR_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Color declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Color);

class Object_Color : public Object {
private:
	SDL_Color _color;
public:
	Gura_DeclareObjectAccessor(Color)
public:
	inline Object_Color(const SDL_Color &color) :
						Object(Gura_UserClass(Color)), _color(color) {}
	virtual ~Object_Color();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_Color &GetEntity() { return _color; }
};

Gura_EndModuleScope(sdl2)

#endif
