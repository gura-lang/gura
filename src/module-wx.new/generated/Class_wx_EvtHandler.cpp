//----------------------------------------------------------------------------
// wxEvtHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEvtHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEvtHandler
//----------------------------------------------------------------------------
Object_wx_EvtHandler::~Object_wx_EvtHandler()
{
}

Object *Object_wx_EvtHandler::Clone() const
{
	return nullptr;
}

String Object_wx_EvtHandler::ToString(bool exprFlag)
{
	String rtn("<wx.EvtHandler:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_EvtHandler, wxEvtHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, wxEvtHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxEvtHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, ~wxEvtHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, ~wxEvtHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxEvtHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, QueueEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, QueueEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->QueueEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, AddPendingEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, AddPendingEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->AddPendingEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, CallAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, CallAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//pThis->GetEntity()->CallAfter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, CallAfter_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "functor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, CallAfter_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int functor = arg.GetNumber(0)
	//pThis->GetEntity()->CallAfter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, ProcessEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, ProcessEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, ProcessEventLocally)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, ProcessEventLocally)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessEventLocally();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, SafelyProcessEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SafelyProcessEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->SafelyProcessEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, ProcessPendingEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, ProcessPendingEvents)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ProcessPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, DeletePendingEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, DeletePendingEvents)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeletePendingEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, SearchEventTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SearchEventTable)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//int event = arg.GetNumber(1)
	//pThis->GetEntity()->SearchEventTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Connect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Connect)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int lastId = arg.GetNumber(1)
	//int eventType = arg.GetNumber(2)
	//int function = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//int eventSink = arg.GetNumber(5)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Connect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Connect_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int eventType = arg.GetNumber(1)
	//int function = arg.GetNumber(2)
	//int userData = arg.GetNumber(3)
	//int eventSink = arg.GetNumber(4)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Connect_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Connect_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int function = arg.GetNumber(1)
	//int userData = arg.GetNumber(2)
	//int eventSink = arg.GetNumber(3)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Disconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Disconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int function = arg.GetNumber(1)
	//int userData = arg.GetNumber(2)
	//int eventSink = arg.GetNumber(3)
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Disconnect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Disconnect_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int eventType = arg.GetNumber(1)
	//int function = arg.GetNumber(2)
	//int userData = arg.GetNumber(3)
	//int eventSink = arg.GetNumber(4)
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Disconnect_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Disconnect_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int lastId = arg.GetNumber(1)
	//int eventType = arg.GetNumber(2)
	//int function = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//int eventSink = arg.GetNumber(5)
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Bind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "functor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Bind)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int functor = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int lastId = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Bind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Bind_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Bind_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int lastId = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Bind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Unbind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "functor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Unbind)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int functor = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int lastId = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Unbind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Unbind_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, Unbind_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int lastId = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Unbind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, GetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, GetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, GetEvtHandlerEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, GetEvtHandlerEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEvtHandlerEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, GetNextHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, GetNextHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNextHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, GetPreviousHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, GetPreviousHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPreviousHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, SetEvtHandlerEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enabled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetEvtHandlerEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enabled = arg.GetNumber(0)
	//pThis->GetEntity()->SetEvtHandlerEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, SetNextHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetNextHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->SetNextHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, SetPreviousHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, SetPreviousHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->SetPreviousHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, Unlink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, Unlink)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Unlink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, IsUnlinked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, IsUnlinked)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsUnlinked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, AddFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, AddFilter)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->AddFilter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, RemoveFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, RemoveFilter)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFilter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, TryBefore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, TryBefore)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->TryBefore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EvtHandler, TryAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, TryAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->TryAfter();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEvtHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EvtHandler)
{
	Gura_AssignMethod(wx_EvtHandler, wxEvtHandler);
	Gura_AssignMethod(wx_EvtHandler, ~wxEvtHandler);
	Gura_AssignMethod(wx_EvtHandler, QueueEvent);
	Gura_AssignMethod(wx_EvtHandler, AddPendingEvent);
	Gura_AssignMethod(wx_EvtHandler, CallAfter);
	Gura_AssignMethod(wx_EvtHandler, CallAfter_1);
	Gura_AssignMethod(wx_EvtHandler, ProcessEvent);
	Gura_AssignMethod(wx_EvtHandler, ProcessEventLocally);
	Gura_AssignMethod(wx_EvtHandler, SafelyProcessEvent);
	Gura_AssignMethod(wx_EvtHandler, ProcessPendingEvents);
	Gura_AssignMethod(wx_EvtHandler, DeletePendingEvents);
	Gura_AssignMethod(wx_EvtHandler, SearchEventTable);
	Gura_AssignMethod(wx_EvtHandler, Connect);
	Gura_AssignMethod(wx_EvtHandler, Connect_1);
	Gura_AssignMethod(wx_EvtHandler, Connect_2);
	Gura_AssignMethod(wx_EvtHandler, Disconnect);
	Gura_AssignMethod(wx_EvtHandler, Disconnect_1);
	Gura_AssignMethod(wx_EvtHandler, Disconnect_2);
	Gura_AssignMethod(wx_EvtHandler, Bind);
	Gura_AssignMethod(wx_EvtHandler, Bind_1);
	Gura_AssignMethod(wx_EvtHandler, Unbind);
	Gura_AssignMethod(wx_EvtHandler, Unbind_1);
	Gura_AssignMethod(wx_EvtHandler, GetClientData);
	Gura_AssignMethod(wx_EvtHandler, GetClientObject);
	Gura_AssignMethod(wx_EvtHandler, SetClientData);
	Gura_AssignMethod(wx_EvtHandler, SetClientObject);
	Gura_AssignMethod(wx_EvtHandler, GetEvtHandlerEnabled);
	Gura_AssignMethod(wx_EvtHandler, GetNextHandler);
	Gura_AssignMethod(wx_EvtHandler, GetPreviousHandler);
	Gura_AssignMethod(wx_EvtHandler, SetEvtHandlerEnabled);
	Gura_AssignMethod(wx_EvtHandler, SetNextHandler);
	Gura_AssignMethod(wx_EvtHandler, SetPreviousHandler);
	Gura_AssignMethod(wx_EvtHandler, Unlink);
	Gura_AssignMethod(wx_EvtHandler, IsUnlinked);
	Gura_AssignMethod(wx_EvtHandler, AddFilter);
	Gura_AssignMethod(wx_EvtHandler, RemoveFilter);
	Gura_AssignMethod(wx_EvtHandler, TryBefore);
	Gura_AssignMethod(wx_EvtHandler, TryAfter);
}

Gura_ImplementDescendantCreator(wx_EvtHandler)
{
	return new Object_wx_EvtHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
