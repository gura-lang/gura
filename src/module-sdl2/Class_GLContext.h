#ifndef __SDL2_CLASS_GLCONTEXT_H__
#define __SDL2_CLASS_GLCONTEXT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_GLContext declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(GLContext);

class Object_GLContext : public Object {
private:
	SDL_GLContext _context;
public:
	Gura_DeclareObjectAccessor(GLContext)
public:
	inline Object_GLContext(SDL_GLContext context) :
						Object(Gura_UserClass(GLContext)), _context(context) {}
	virtual ~Object_GLContext();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_GLContext GetEntity() { return _context; }
};

Gura_EndModuleScope(sdl2)

#endif
