#ifndef __SDL2_CLASS_GAMECONTROLLER_H__
#define __SDL2_CLASS_GAMECONTROLLER_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_GameController declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(GameController);

class Object_GameController : public Object {
private:
	SDL_GameController *_pGameController;
public:
	Gura_DeclareObjectAccessor(GameController)
public:
	inline Object_GameController(SDL_GameController *pGameController) :
						Object(Gura_UserClass(GameController)), _pGameController(pGameController) {}
	virtual ~Object_GameController();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_GameController *GetEntity() { return _pGameController; }
};

Gura_EndModuleScope(sdl2)

#endif
