#ifndef __SDL2_CLASS_EVENT_H__
#define __SDL2_CLASS_EVENT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Event declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Event);

class Object_Event : public Object {
private:
	SDL_Event _event;
public:
	Gura_DeclareObjectAccessor(Event)
public:
	inline Object_Event() : Object(Gura_UserClass(Event)) {}
	virtual ~Object_Event();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Event *GetEntity() { return &_event; }
};

Gura_EndModuleScope(sdl2)

#endif
