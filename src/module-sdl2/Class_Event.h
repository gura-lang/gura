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
	String _text;
public:
	Gura_DeclareObjectAccessor(Event)
public:
	inline Object_Event(const SDL_Event &event) : Object(Gura_UserClass(Event)), _event(event) {
		if (_event.type == SDL_DROPFILE) {
			_text = _event.drop.file;
			_event.drop.file = const_cast<char *>(_text.c_str());
			SDL_free(_event.drop.file);
		}
	}
	virtual ~Object_Event();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Event *GetEntity() { return &_event; }
};

Gura_EndModuleScope(sdl2)

#endif
