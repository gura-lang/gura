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
	inline Object_AudioSpec() : Object(Gura_UserClass(AudioSpec)) {
		::SDL_zero(_spec);
	}
	virtual ~Object_AudioSpec();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_AudioSpec &GetEntity() { return _spec; }
};

Gura_EndModuleScope(sdl2)

#endif
