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
	inline Object_RendererInfo(const SDL_RendererInfo &info) :
						Object(Gura_UserClass(RendererInfo)), _info(info) {}
	virtual ~Object_RendererInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &__to_delete__,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_RendererInfo *GetEntity() { return &_info; }
};

Gura_EndModuleScope(sdl2)

#endif
