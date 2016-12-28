#ifndef __SDL2_CLASS_JOYSTICK_H__
#define __SDL2_CLASS_JOYSTICK_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Joystick declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Joystick);

class Object_Joystick : public Object {
private:
	SDL_Joystick *_pJoystick;
public:
	Gura_DeclareObjectAccessor(Joystick)
public:
	inline Object_Joystick(SDL_Joystick *pJoystick) :
						Object(Gura_UserClass(Joystick)), _pJoystick(pJoystick) {}
	virtual ~Object_Joystick();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_Joystick *GetEntity() { return _pJoystick; }
};

Gura_EndModuleScope(sdl2)

#endif
