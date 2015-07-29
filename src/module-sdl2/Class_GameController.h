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
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_GameController *GetEntity() { return _pGameController; }
};

Gura_EndModuleScope(sdl2)

#endif
