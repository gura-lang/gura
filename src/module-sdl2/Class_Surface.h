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
	AutoPtr<Image> _pImage;
public:
	Gura_DeclareObjectAccessor(Surface)
public:
	inline Object_Surface(SDL_Surface *pSurface, Image *pImage = nullptr) :
		Object(Gura_UserClass(Surface)), _pSurface(pSurface), _pImage(pImage) {}
	virtual ~Object_Surface();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	static Object_Surface *CreateSurfaceFromImage(Signal &sig, Image *pImage);
	inline SDL_Surface *GetEntity() { return _pSurface; }
};

Gura_EndModuleScope(sdl2)

#endif
