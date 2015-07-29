#ifndef __SDL2_CLASS_HAPTICEFFECT_H__
#define __SDL2_CLASS_HAPTICEFFECT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_HapticEffect declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(HapticEffect);

class Object_HapticEffect : public Object {
private:
	SDL_HapticEffect *_pHapticEffect;
public:
	Gura_DeclareObjectAccessor(HapticEffect)
public:
	inline Object_HapticEffect(SDL_HapticEffect *pHapticEffect) :
						Object(Gura_UserClass(HapticEffect)), _pHapticEffect(pHapticEffect) {}
	virtual ~Object_HapticEffect();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_HapticEffect *GetEntity() { return _pHapticEffect; }
};

Gura_EndModuleScope(sdl2)

#endif
