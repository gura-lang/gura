//----------------------------------------------------------------------------
// wxEventFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEventFactory
//----------------------------------------------------------------------------
Object_wx_EventFactory::~Object_wx_EventFactory()
{
}

Object *Object_wx_EventFactory::Clone() const
{
	return new Object_wx_EventFactory(*this);
}

String Object_wx_EventFactory::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.EventFactory:");
	rtn += GetName();
	rtn += ">";
	return rtn;
}

Object_wx_Event *Object_wx_EventFactory::CreateEventObject(wxEvent &event)
{
	return new Object_wx_Event(&event, NULL, false);
}

void Object_wx_EventFactory::Connect(Environment &env, Signal sig,
		wxEvtHandler *pEvtHandler, int id, int lastId,
		wxObjectEventFunction function, const Function *pFunc, wxEvtHandler *eventSink)
{
	wxEventType eventType = GetEventType();
	if (eventType != wxEVT_NULL) {
		EventHandlerPack *pEventHandlerPack = new EventHandlerPack(env, sig,
			Function::Reference(pFunc), Object_wx_EventFactory::Reference(this));
		pEvtHandler->Connect(id, lastId, eventType, function, pEventHandlerPack, eventSink);
		return;
	}
	for (int i = 0; i < _cntEventTypes; i++) {
		wxEventType eventType = _eventTypes[i];
		EventHandlerPack *pEventHandlerPack = new EventHandlerPack(env, sig,
			Function::Reference(pFunc), Object_wx_EventFactory::Reference(this));
		pEvtHandler->Connect(id, lastId, eventType, function, pEventHandlerPack, eventSink);
	}
}

void Object_wx_EventFactory::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxEventFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventFactory)
{
	
}

Gura_ImplementDescendantCreator(wx_EventFactory)
{
	return new Object_wx_EventFactory((pClass == NULL)? this : pClass, NULL, "");
}

}}
