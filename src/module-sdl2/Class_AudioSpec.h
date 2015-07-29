#ifndef __SDL2_CLASS_AUDIOSPEC_H__
#define __SDL2_CLASS_AUDIOSPEC_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_AudioSpec declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(AudioSpec);

class Object_AudioSpec : public Object {
private:
	SDL_AudioSpec _spec;
public:
	Gura_DeclareObjectAccessor(AudioSpec)
public:
	inline Object_AudioSpec(const SDL_AudioSpec &spec) :
						Object(Gura_UserClass(AudioSpec)), _spec(spec) {}
	virtual ~Object_AudioSpec();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_AudioSpec *GetEntity() { return &_spec; }
};

Gura_EndModuleScope(sdl2)

#endif
