#ifndef __SDL2_CLASS_PALETTE_H__
#define __SDL2_CLASS_PALETTE_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Palette declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Palette);

class Object_Palette : public Object {
private:
	SDL_Palette *_pPalette;
public:
	Gura_DeclareObjectAccessor(Palette)
public:
	inline Object_Palette(SDL_Palette *pPalette) :
						Object(Gura_UserClass(Palette)), _pPalette(pPalette) {}
	virtual ~Object_Palette();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &sig,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Palette *GetEntity() { return _pPalette; }
};

Gura_EndModuleScope(sdl2)

#endif
