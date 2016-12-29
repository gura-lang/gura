#ifndef __SDL2_CLASS_DISPLAYMODE_H__
#define __SDL2_CLASS_DISPLAYMODE_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_DisplayMode declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(DisplayMode);

class Object_DisplayMode : public Object {
private:
	SDL_DisplayMode _mode;
public:
	Gura_DeclareObjectAccessor(DisplayMode)
public:
	inline Object_DisplayMode(const SDL_DisplayMode &mode) :
					Object(Gura_UserClass(DisplayMode)), _mode(mode) {}
	virtual ~Object_DisplayMode();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_DisplayMode *GetEntity() { return &_mode; }
};

Gura_EndModuleScope(sdl2)

#endif
