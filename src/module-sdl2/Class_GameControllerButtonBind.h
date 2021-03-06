#ifndef __SDL2_CLASS_GAMECONTROLLERBUTTONBIND_H__
#define __SDL2_CLASS_GAMECONTROLLERBUTTONBIND_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_GameControllerButtonBind declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(GameControllerButtonBind);

class Object_GameControllerButtonBind : public Object {
private:
	SDL_GameControllerButtonBind _gameControllerButtonBind;
public:
	Gura_DeclareObjectAccessor(GameControllerButtonBind)
public:
	inline Object_GameControllerButtonBind(SDL_GameControllerButtonBind gameControllerButtonBind) :
						Object(Gura_UserClass(GameControllerButtonBind)), _gameControllerButtonBind(gameControllerButtonBind) {}
	virtual ~Object_GameControllerButtonBind();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_GameControllerButtonBind *GetEntity() { return &_gameControllerButtonBind; }
};

Gura_EndModuleScope(sdl2)

#endif
