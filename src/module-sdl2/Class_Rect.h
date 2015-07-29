#ifndef __SDL2_CLASS_RECT_H__
#define __SDL2_CLASS_RECT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Rect declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Rect);

class Object_Rect : public Object {
private:
	SDL_Rect _rect;
public:
	Gura_DeclareObjectAccessor(Rect)
public:
	inline Object_Rect(const SDL_Rect &rect) :
						Object(Gura_UserClass(Rect)), _rect(rect) {}
	virtual ~Object_Rect();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env,
							const Symbol *pSymbol, const SymbolSet &attrs,
							bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Rect *GetEntity() { return &_rect; }
};

Gura_EndModuleScope(sdl2)

#endif
