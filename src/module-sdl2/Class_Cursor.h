#ifndef __SDL2_CLASS_CURSOR_H__
#define __SDL2_CLASS_CURSOR_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Cursor declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Cursor);

class Object_Cursor : public Object {
private:
	SDL_Cursor *_pCursor;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(Cursor)
public:
	inline Object_Cursor(SDL_Cursor *pCursor, bool ownerFlag) :
		Object(Gura_UserClass(Cursor)), _pCursor(pCursor), _ownerFlag(ownerFlag) {}
	virtual ~Object_Cursor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Cursor *GetEntity() { return _pCursor; }
};

Gura_EndModuleScope(sdl2)

#endif
