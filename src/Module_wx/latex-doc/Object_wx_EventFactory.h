//----------------------------------------------------------------------------
// wxEventFactory
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_EVENTFACTORY_H__
#define __OBJECT_WX_EVENTFACTORY_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEventFactory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EventFactory);

//----------------------------------------------------------------------------
// Object declaration for wxEventFactory
//----------------------------------------------------------------------------
class Object_wx_EventFactory : public Object {
protected:
	wxEventType _eventType;
	String _name;
	int _cntEventTypes;
	const wxEventType *_eventTypes;
public:
	Gura_DeclareObjectAccessor(wx_EventFactory)
public:
	inline Object_wx_EventFactory(wxEventType eventType, const char *name) :
		Object(Gura_UserClass(wx_EventFactory)),
		_eventType(eventType), _name(name), _cntEventTypes(0), _eventTypes(NULL) {}
	inline Object_wx_EventFactory(Class *pClass, wxEventType eventType, const char *name) :
		Object(pClass),
		_eventType(eventType), _name(name), _cntEventTypes(0), _eventTypes(NULL) {}
	inline bool IsInvalid(Signal sig) const { return false; }
	virtual ~Object_wx_EventFactory();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual Object_wx_Event *CreateEventObject(wxEvent &event);
	inline wxEventType GetEventType() { return _eventType; }
	inline const char *GetName() { return _name.c_str(); }
	void Connect(Environment &env, Signal sig,
		wxEvtHandler *pEvtHandler, int id, int lastId,
		wxObjectEventFunction function, const Function *pFunc, wxEvtHandler *eventSink);
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

template<typename T_WX, typename T_Gura>
class Object_wx_EventFactoryDerive : public Object_wx_EventFactory {
public:
	inline Object_wx_EventFactoryDerive(wxEventType type, const char *name) :
									Object_wx_EventFactory(type, name) {}
	virtual Object_wx_Event *CreateEventObject(wxEvent &event) {
		return new T_Gura(wxDynamicCast(&event, T_WX), NULL, false);
	}
};

#define Gura_AssignWxEvent(type, name, className) do { \
	Object_wx_EventFactory *pObjEventFactory = \
		new Object_wx_EventFactoryDerive<wx##className, Object_wx_##className>(wx##type, #name); \
	Gura_AssignValueEx(#name, Value(pObjEventFactory)); \
} while (0)

//-----------------------------------------------------------------------------
// EventHandlerPack
//-----------------------------------------------------------------------------
class EventHandlerPack : public wxObject {
private:
	Environment _env;
	Signal _sig;
	AutoPtr<Function> _pFunc;
	AutoPtr<Object_wx_EventFactory> _pEventFactory;
public:
	inline EventHandlerPack(Environment &env, Signal sig,
					Function *pFunc, Object_wx_EventFactory *pEventFactory) :
		_env(env), _sig(sig), _pFunc(pFunc), _pEventFactory(pEventFactory) {}
	void Eval(wxEvent &event);
	Signal &GetSignal() { return _sig; }
};

}}

#endif
