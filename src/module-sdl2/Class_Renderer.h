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
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Renderer *GetEntity() { return _pRenderer; }
};

Gura_EndModuleScope(sdl2)

#endif
