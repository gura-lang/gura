#ifndef __SDL2_CLASS_JOYSTICKGUID_H__
#define __SDL2_CLASS_JOYSTICKGUID_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_JoystickGUID declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(JoystickGUID);

class Object_JoystickGUID : public Object {
private:
	SDL_JoystickGUID _guid;
public:
	Gura_DeclareObjectAccessor(JoystickGUID)
public:
	inline Object_JoystickGUID(const SDL_JoystickGUID &guid) :
						Object(Gura_UserClass(JoystickGUID)), _guid(guid) {}
	virtual ~Object_JoystickGUID();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_JoystickGUID *GetEntity() { return &_guid; }
};

Gura_EndModuleScope(sdl2)

#endif
