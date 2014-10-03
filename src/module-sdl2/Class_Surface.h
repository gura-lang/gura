#ifndef __SDL2_CLASS_SURFACE_H__
#define __SDL2_CLASS_SURFACE_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Surface);

class Object_Surface : public Object {
private:
	SDL_Surface *_pSurface;
public:
	Gura_DeclareObjectAccessor(Surface)
public:
	inline Object_Surface(SDL_Surface *pSurface) :
						Object(Gura_UserClass(Surface)), _pSurface(pSurface) {}
	virtual ~Object_Surface();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_Surface *GetEntity() { return _pSurface; }
};

Gura_EndModuleScope(sdl2)

#endif
