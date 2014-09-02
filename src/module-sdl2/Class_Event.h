#ifndef __SDL2_CLASS_EVENT_H__
#define __SDL2_CLASS_EVENT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Event declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Event);

class Object_Event : public Object {
private:
	SDL_Event *_pEvent;
public:
	Gura_DeclareObjectAccessor(Event)
public:
	inline Object_Event(SDL_Event *pEvent) :
						Object(Gura_UserClass(Event)), _pEvent(pEvent) {}
	virtual ~Object_Event();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline SDL_Event *GetEntity() { return _pEvent; }
};

Gura_EndModuleScope(sdl2)

#endif
