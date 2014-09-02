#ifndef __SDL2_CLASS_RENDERER_H__
#define __SDL2_CLASS_RENDERER_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Renderer declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Renderer);

class Object_Renderer : public Object {
private:
	SDL_Renderer *_pRenderer;
public:
	Gura_DeclareObjectAccessor(Renderer)
public:
	inline Object_Renderer(SDL_Renderer *pRenderer) :
						Object(Gura_UserClass(Renderer)), _pRenderer(pRenderer) {}
	virtual ~Object_Renderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_Renderer *GetEntity() { return _pRenderer; }
};

Gura_EndModuleScope(sdl2)

#endif
