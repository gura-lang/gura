#ifndef __SDL2_CLASS_HAPTIC_H__
#define __SDL2_CLASS_HAPTIC_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Haptic declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Haptic);

class Object_Haptic : public Object {
private:
	SDL_Haptic *_pHaptic;
public:
	Gura_DeclareObjectAccessor(Haptic)
public:
	inline Object_Haptic(SDL_Haptic *pHaptic) :
						Object(Gura_UserClass(Haptic)), _pHaptic(pHaptic) {}
	virtual ~Object_Haptic();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &sig,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Haptic *GetEntity() { return _pHaptic; }
};

Gura_EndModuleScope(sdl2)

#endif
