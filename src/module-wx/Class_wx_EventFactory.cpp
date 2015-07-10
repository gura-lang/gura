//----------------------------------------------------------------------------
// wxEventFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventFactory
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_EventFactory, GetEventType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EventFactory, GetEventType)
{
	Object_wx_EventFactory *pThis = Object_wx_EventFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEventType rtn = pThis->GetEventType();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_EventFactory, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_EventFactory, GetName)
{
	Object_wx_EventFactory *pThis = Object_wx_EventFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const char *rtn = pThis->GetName();
	return ReturnValue(env, sig, args, Value(rtn));
}

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

String Object_wx_EventFactory::ToString(bool exprFlag)
{
	String rtn("<wx.EventFactory:");
	rtn += GetName();
	rtn += ">";
	return rtn;
}

Object_wx_Event *Object_wx_EventFactory::CreateEventObject(wxEvent &event)
{
	return new Object_wx_Event(&event, nullptr, false);
}

void Object_wx_EventFactory::Connect(Environment &env, Signal &sig,
		wxEvtHandler *pEvtHandler, int id, int lastId,
		wxObjectEventFunction function, Object_function *pObjFunc, wxEvtHandler *eventSink)
{
	wxEventType eventType = GetEventType();
	if (eventType != wxEVT_NULL) {
		EventHandlerPack *pEventHandlerPack = new EventHandlerPack(env, sig,
							pObjFunc, Object_wx_EventFactory::Reference(this));
		pEvtHandler->Connect(id, lastId, eventType, function, pEventHandlerPack, eventSink);
		return;
	}
	for (int i = 0; i < _cntEventTypes; i++) {
		wxEventType eventType = _eventTypes[i];
		EventHandlerPack *pEventHandlerPack = new EventHandlerPack(env, sig,
			Object_function::Reference(pObjFunc), Object_wx_EventFactory::Reference(this));
		pEvtHandler->Connect(id, lastId, eventType, function, pEventHandlerPack, eventSink);
	}
	Object::Delete(pObjFunc);
}

//----------------------------------------------------------------------------
// Class implementation for wxEventFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventFactory)
{
	Gura_AssignMethod(wx_EventFactory, GetEventType);
	Gura_AssignMethod(wx_EventFactory, GetName);
}

Gura_ImplementDescendantCreator(wx_EventFactory)
{
	return new Object_wx_EventFactory((pClass == nullptr)? this : pClass, 0, "");
}

//----------------------------------------------------------------------------
// Object_wx_EventFactory_ScrollEvent
//----------------------------------------------------------------------------
Object_wx_EventFactory_ScrollEvent::Object_wx_EventFactory_ScrollEvent(const char *name) :
										Object_wx_EventFactory(wxEVT_NULL, name)
{
	static const wxEventType eventTypes[] = {
		wxEVT_SCROLL_TOP,
		wxEVT_SCROLL_BOTTOM,
		wxEVT_SCROLL_LINEUP,
		wxEVT_SCROLL_LINEDOWN,
		wxEVT_SCROLL_PAGEUP,
		wxEVT_SCROLL_PAGEDOWN,
		wxEVT_SCROLL_THUMBTRACK,
		wxEVT_SCROLL_THUMBRELEASE,
	};
	_cntEventTypes = ArraySizeOf(eventTypes);
	_eventTypes = eventTypes;
}

Object_wx_Event *Object_wx_EventFactory_ScrollEvent::CreateEventObject(wxEvent &event)
{
	return new Object_wx_ScrollEvent(wxDynamicCast(&event, wxScrollEvent), nullptr, OwnerFalse);
}

//----------------------------------------------------------------------------
// Object_wx_EventFactory_ScrollWinEvent
//----------------------------------------------------------------------------
Object_wx_EventFactory_ScrollWinEvent::Object_wx_EventFactory_ScrollWinEvent(const char *name) :
										Object_wx_EventFactory(wxEVT_NULL, name)
{
	static const wxEventType eventTypes[] = {
		wxEVT_SCROLLWIN_TOP,
		wxEVT_SCROLLWIN_BOTTOM,
		wxEVT_SCROLLWIN_LINEUP,
		wxEVT_SCROLLWIN_LINEDOWN,
		wxEVT_SCROLLWIN_PAGEUP,
		wxEVT_SCROLLWIN_PAGEDOWN,
		wxEVT_SCROLLWIN_THUMBTRACK,
		wxEVT_SCROLLWIN_THUMBRELEASE,
	};
	_cntEventTypes = ArraySizeOf(eventTypes);
	_eventTypes = eventTypes;
}

Object_wx_Event *Object_wx_EventFactory_ScrollWinEvent::CreateEventObject(wxEvent &event)
{
	return new Object_wx_ScrollWinEvent(wxDynamicCast(&event, wxScrollWinEvent), nullptr, OwnerFalse);
}

//----------------------------------------------------------------------------
// Object_wx_EventFactory_JoystickEvent
//----------------------------------------------------------------------------
Object_wx_EventFactory_JoystickEvent::Object_wx_EventFactory_JoystickEvent(const char *name) :
										Object_wx_EventFactory(wxEVT_NULL, name)
{
	static const wxEventType eventTypes[] = {
		wxEVT_JOY_BUTTON_DOWN,
		wxEVT_JOY_BUTTON_UP,
		wxEVT_JOY_MOVE,
		wxEVT_JOY_ZMOVE,
	};
	_cntEventTypes = ArraySizeOf(eventTypes);
	_eventTypes = eventTypes;
}

Object_wx_Event *Object_wx_EventFactory_JoystickEvent::CreateEventObject(wxEvent &event)
{
	return new Object_wx_JoystickEvent(wxDynamicCast(&event, wxJoystickEvent), nullptr, OwnerFalse);
}

//----------------------------------------------------------------------------
// Object_wx_EventFactory_MouseEvent
//----------------------------------------------------------------------------
Object_wx_EventFactory_MouseEvent::Object_wx_EventFactory_MouseEvent(const char *name) :
										Object_wx_EventFactory(wxEVT_NULL, name)
{
	static const wxEventType eventTypes[] = {
		wxEVT_LEFT_DOWN,
		wxEVT_LEFT_UP,
		wxEVT_LEFT_DCLICK,
		wxEVT_MIDDLE_DOWN,
		wxEVT_MIDDLE_UP,
		wxEVT_MIDDLE_DCLICK,
		wxEVT_RIGHT_DOWN,
		wxEVT_RIGHT_UP,
		wxEVT_RIGHT_DCLICK,
		wxEVT_MOTION,
		wxEVT_ENTER_WINDOW,
		wxEVT_LEAVE_WINDOW,
		wxEVT_MOUSEWHEEL,
	};
	_cntEventTypes = ArraySizeOf(eventTypes);
	_eventTypes = eventTypes;
}

Object_wx_Event *Object_wx_EventFactory_MouseEvent::CreateEventObject(wxEvent &event)
{
	return new Object_wx_MouseEvent(wxDynamicCast(&event, wxMouseEvent), nullptr, OwnerFalse);
}

//-----------------------------------------------------------------------------
// EventHandlerPack
//-----------------------------------------------------------------------------
EventHandlerPack::~EventHandlerPack()
{
	//::printf("EventHandlerPack destroyed %p\n", this);
}

void EventHandlerPack::Eval(wxEvent &event)
{
	Object_wx_Event *pObj = _pEventFactory->CreateEventObject(event);
	ValueList valListArg;
	valListArg.push_back(Value(pObj));
	_pObjFunc->Eval(*_pEnv, _sig, valListArg);
}

Gura_EndModuleScope(wx)
