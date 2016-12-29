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
	inline SDL_Finger *GetEntity() { return _pFinger; }
};

Gura_EndModuleScope(sdl2)

#endif
