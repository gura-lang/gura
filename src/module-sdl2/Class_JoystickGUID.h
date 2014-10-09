#ifndef __SDL2_CLASS_JOYSTICKGUID_H__
#define __SDL2_CLASS_JOYSTICKGUID_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_JoystickGUID declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(JoystickGUID);

class Object_JoystickGUID : public Object {
private:
	SDL_JoystickGUID _guid;
public:
	Gura_DeclareObjectAccessor(JoystickGUID)
public:
	inline Object_JoystickGUID(const SDL_JoystickGUID &guid) :
						Object(Gura_UserClass(JoystickGUID)), _guid(guid) {}
	virtual ~Object_JoystickGUID();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_JoystickGUID *GetEntity() { return &_guid; }
};

Gura_EndModuleScope(sdl2)

#endif
