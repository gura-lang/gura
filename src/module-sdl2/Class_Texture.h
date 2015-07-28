#ifndef __SDL2_CLASS_TEXTURE_H__
#define __SDL2_CLASS_TEXTURE_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Texture declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Texture);

class Object_Texture : public Object {
private:
	SDL_Texture *_pTexture;
public:
	Gura_DeclareObjectAccessor(Texture)
public:
	inline Object_Texture(SDL_Texture *pTexture) :
						Object(Gura_UserClass(Texture)), _pTexture(pTexture) {}
	virtual ~Object_Texture();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &__to_delete__,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Texture *GetEntity() { return _pTexture; }
};

Gura_EndModuleScope(sdl2)

#endif
