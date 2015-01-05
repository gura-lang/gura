#ifndef __SDL2_CLASS_AUDIOCVT_H__
#define __SDL2_CLASS_AUDIOCVT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_AudioCVT declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(AudioCVT);

class Object_AudioCVT : public Object {
private:
	SDL_AudioCVT _cvt;
public:
	Gura_DeclareObjectAccessor(AudioCVT)
public:
	inline Object_AudioCVT() : Object(Gura_UserClass(AudioCVT)) {
		::memset(&_cvt, 0x00, sizeof(_cvt));
	}
	virtual ~Object_AudioCVT();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_AudioCVT *GetEntity() { return &_cvt; }
};

Gura_EndModuleScope(sdl2)

#endif
