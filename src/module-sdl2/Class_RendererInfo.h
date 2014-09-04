#ifndef __SDL2_CLASS_RENDERERINFO_H__
#define __SDL2_CLASS_RENDERERINFO_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_RendererInfo declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(RendererInfo);

class Object_RendererInfo : public Object {
private:
	SDL_RendererInfo _info;
public:
	Gura_DeclareObjectAccessor(RendererInfo)
public:
	inline Object_RendererInfo() : Object(Gura_UserClass(RendererInfo)) {}
	virtual ~Object_RendererInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_RendererInfo *GetEntity() { return &_info; }
};

Gura_EndModuleScope(sdl2)

#endif
