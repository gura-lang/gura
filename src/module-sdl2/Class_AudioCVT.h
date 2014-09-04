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
	inline Object_AudioCVT() : Object(Gura_UserClass(AudioCVT)) {}
	virtual ~Object_AudioCVT();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_AudioCVT *GetEntity() { return &_cvt; }
};

Gura_EndModuleScope(sdl2)

#endif
