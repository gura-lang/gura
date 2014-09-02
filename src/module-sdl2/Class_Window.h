#ifndef __SDL2_CLASS_WINDOW_H__
#define __SDL2_CLASS_WINDOW_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Window declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Window);

class Object_Window : public Object {
private:
	SDL_Window *_pWindow;
public:
	Gura_DeclareObjectAccessor(Window)
public:
	inline Object_Window(SDL_Window *pWindow) :
						Object(Gura_UserClass(Window)), _pWindow(pWindow) {}
	virtual ~Object_Window();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_Window *GetEntity() { return _pWindow; }
};

Gura_EndModuleScope(sdl2)

#endif
