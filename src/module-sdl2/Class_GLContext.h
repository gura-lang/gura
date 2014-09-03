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
	inline SDL_GLContext GetEntity() { return _context; }
};

Gura_EndModuleScope(sdl2)

#endif
