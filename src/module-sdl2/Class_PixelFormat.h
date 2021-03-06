#ifndef __SDL2_CLASS_PIXELFORMAT_H__
#define __SDL2_CLASS_PIXELFORMAT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_PixelFormat declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(PixelFormat);

class Object_PixelFormat : public Object {
private:
	SDL_PixelFormat *_pPixelFormat;
public:
	Gura_DeclareObjectAccessor(PixelFormat)
public:
	inline Object_PixelFormat(SDL_PixelFormat *pPixelFormat) :
						Object(Gura_UserClass(PixelFormat)), _pPixelFormat(pPixelFormat) {}
	virtual ~Object_PixelFormat();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_PixelFormat *GetEntity() { return _pPixelFormat; }
};

Gura_EndModuleScope(sdl2)

#endif
