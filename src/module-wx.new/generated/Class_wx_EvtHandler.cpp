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
Gura_DeclareMethodAlias(wx_EvtHandler, __wxEvtHandler, "wxEvtHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __wxEvtHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxEvtHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __QueueEvent, "QueueEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __QueueEvent)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->QueueEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __AddPendingEvent, "AddPendingEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __AddPendingEvent)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->AddPendingEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __CallAfter, "CallAfter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __CallAfter)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//pThis->GetEntity()->CallAfter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __CallAfter_1, "CallAfter_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "functor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __CallAfter_1)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int functor = arg.GetNumber(0)
	//pThis->GetEntity()->CallAfter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __ProcessEvent, "ProcessEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __ProcessEvent)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __ProcessEventLocally, "ProcessEventLocally")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __ProcessEventLocally)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessEventLocally();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __SafelyProcessEvent, "SafelyProcessEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __SafelyProcessEvent)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->SafelyProcessEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __ProcessPendingEvents, "ProcessPendingEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __ProcessPendingEvents)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ProcessPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __DeletePendingEvents, "DeletePendingEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __DeletePendingEvents)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeletePendingEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __SearchEventTable, "SearchEventTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __SearchEventTable)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//int event = arg.GetNumber(1)
	//pThis->GetEntity()->SearchEventTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Connect, "Connect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Connect)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int lastId = arg.GetNumber(1)
	//int eventType = arg.GetNumber(2)
	//int function = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//int eventSink = arg.GetNumber(5)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Connect_1, "Connect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Connect_1)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int eventType = arg.GetNumber(1)
	//int function = arg.GetNumber(2)
	//int userData = arg.GetNumber(3)
	//int eventSink = arg.GetNumber(4)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Connect_2, "Connect_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Connect_2)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int function = arg.GetNumber(1)
	//int userData = arg.GetNumber(2)
	//int eventSink = arg.GetNumber(3)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Disconnect, "Disconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Disconnect)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int function = arg.GetNumber(1)
	//int userData = arg.GetNumber(2)
	//int eventSink = arg.GetNumber(3)
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Disconnect_1, "Disconnect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Disconnect_1)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int eventType = arg.GetNumber(1)
	//int function = arg.GetNumber(2)
	//int userData = arg.GetNumber(3)
	//int eventSink = arg.GetNumber(4)
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Disconnect_2, "Disconnect_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventSink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Disconnect_2)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int lastId = arg.GetNumber(1)
	//int eventType = arg.GetNumber(2)
	//int function = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//int eventSink = arg.GetNumber(5)
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Bind, "Bind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "functor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Bind)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int functor = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int lastId = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Bind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Bind_1, "Bind_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Bind_1)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int lastId = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Bind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Unbind, "Unbind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "functor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Unbind)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int functor = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int lastId = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Unbind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Unbind_1, "Unbind_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lastId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __Unbind_1)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int lastId = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->Unbind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __GetClientData, "GetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __GetClientData)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __GetClientObject, "GetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __GetClientObject)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __SetClientData, "SetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __SetClientData)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __SetClientObject, "SetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __SetClientObject)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __GetEvtHandlerEnabled, "GetEvtHandlerEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __GetEvtHandlerEnabled)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEvtHandlerEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __GetNextHandler, "GetNextHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __GetNextHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __GetPreviousHandler, "GetPreviousHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __GetPreviousHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPreviousHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __SetEvtHandlerEnabled, "SetEvtHandlerEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enabled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __SetEvtHandlerEnabled)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enabled = arg.GetNumber(0)
	//pThis->GetEntity()->SetEvtHandlerEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __SetNextHandler, "SetNextHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __SetNextHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->SetNextHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __SetPreviousHandler, "SetPreviousHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __SetPreviousHandler)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->SetPreviousHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __Unlink, "Unlink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __Unlink)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Unlink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __IsUnlinked, "IsUnlinked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EvtHandler, __IsUnlinked)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsUnlinked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __AddFilter, "AddFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __AddFilter)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->AddFilter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __RemoveFilter, "RemoveFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __RemoveFilter)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFilter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __TryBefore, "TryBefore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __TryBefore)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->TryBefore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EvtHandler, __TryAfter, "TryAfter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EvtHandler, __TryAfter)
{
	Object_wx_EvtHandler *pThis = Object_wx_EvtHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->TryAfter();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEvtHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EvtHandler)
{
	Gura_AssignMethod(wx_EvtHandler, __wxEvtHandler);
	Gura_AssignMethod(wx_EvtHandler, __QueueEvent);
	Gura_AssignMethod(wx_EvtHandler, __AddPendingEvent);
	Gura_AssignMethod(wx_EvtHandler, __CallAfter);
	Gura_AssignMethod(wx_EvtHandler, __CallAfter_1);
	Gura_AssignMethod(wx_EvtHandler, __ProcessEvent);
	Gura_AssignMethod(wx_EvtHandler, __ProcessEventLocally);
	Gura_AssignMethod(wx_EvtHandler, __SafelyProcessEvent);
	Gura_AssignMethod(wx_EvtHandler, __ProcessPendingEvents);
	Gura_AssignMethod(wx_EvtHandler, __DeletePendingEvents);
	Gura_AssignMethod(wx_EvtHandler, __SearchEventTable);
	Gura_AssignMethod(wx_EvtHandler, __Connect);
	Gura_AssignMethod(wx_EvtHandler, __Connect_1);
	Gura_AssignMethod(wx_EvtHandler, __Connect_2);
	Gura_AssignMethod(wx_EvtHandler, __Disconnect);
	Gura_AssignMethod(wx_EvtHandler, __Disconnect_1);
	Gura_AssignMethod(wx_EvtHandler, __Disconnect_2);
	Gura_AssignMethod(wx_EvtHandler, __Bind);
	Gura_AssignMethod(wx_EvtHandler, __Bind_1);
	Gura_AssignMethod(wx_EvtHandler, __Unbind);
	Gura_AssignMethod(wx_EvtHandler, __Unbind_1);
	Gura_AssignMethod(wx_EvtHandler, __GetClientData);
	Gura_AssignMethod(wx_EvtHandler, __GetClientObject);
	Gura_AssignMethod(wx_EvtHandler, __SetClientData);
	Gura_AssignMethod(wx_EvtHandler, __SetClientObject);
	Gura_AssignMethod(wx_EvtHandler, __GetEvtHandlerEnabled);
	Gura_AssignMethod(wx_EvtHandler, __GetNextHandler);
	Gura_AssignMethod(wx_EvtHandler, __GetPreviousHandler);
	Gura_AssignMethod(wx_EvtHandler, __SetEvtHandlerEnabled);
	Gura_AssignMethod(wx_EvtHandler, __SetNextHandler);
	Gura_AssignMethod(wx_EvtHandler, __SetPreviousHandler);
	Gura_AssignMethod(wx_EvtHandler, __Unlink);
	Gura_AssignMethod(wx_EvtHandler, __IsUnlinked);
	Gura_AssignMethod(wx_EvtHandler, __AddFilter);
	Gura_AssignMethod(wx_EvtHandler, __RemoveFilter);
	Gura_AssignMethod(wx_EvtHandler, __TryBefore);
	Gura_AssignMethod(wx_EvtHandler, __TryAfter);
}

Gura_ImplementDescendantCreator(wx_EvtHandler)
{
	return new Object_wx_EvtHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
