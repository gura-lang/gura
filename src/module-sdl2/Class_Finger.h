#ifndef __SDL2_CLASS_FINGER_H__
#define __SDL2_CLASS_FINGER_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Finger declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Finger);

class Object_Finger : public Object {
private:
	SDL_Finger *_pFinger;
public:
	Gura_DeclareObjectAccessor(Finger)
public:
	inline Object_Finger(SDL_Finger *pFinger) :
						Object(Gura_UserClass(Finger)), _pFinger(pFinger) {}
	virtual ~Object_Finger();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &__to_delete__,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Finger *GetEntity() { return _pFinger; }
};

Gura_EndModuleScope(sdl2)

#endif
