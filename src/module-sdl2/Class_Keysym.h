#ifndef __SDL2_CLASS_KEYSYM_H__
#define __SDL2_CLASS_KEYSYM_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Keysym declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Keysym);

class Object_Keysym : public Object {
private:
	SDL_Keysym _keysym;
public:
	Gura_DeclareObjectAccessor(Keysym)
public:
	inline Object_Keysym(const SDL_Keysym &keysym) :
						Object(Gura_UserClass(Keysym)), _keysym(keysym) {}
	virtual ~Object_Keysym();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &sig,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Keysym *GetEntity() { return &_keysym; }
};

Gura_EndModuleScope(sdl2)

#endif
