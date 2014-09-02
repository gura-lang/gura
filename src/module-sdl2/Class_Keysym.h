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
	inline SDL_Keysym &GetEntity() { return _keysym; }
};

Gura_EndModuleScope(sdl2)

#endif
