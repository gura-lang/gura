//----------------------------------------------------------------------------
// wxEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEvent
//----------------------------------------------------------------------------
Object_wx_Event::~Object_wx_Event()
{
}

Object *Object_wx_Event::Clone() const
{
	return nullptr;
}

String Object_wx_Event::ToString(bool exprFlag)
{
	String rtn("<wx.Event:");
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
Gura_DeclareMethod(wx_Event, wxEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, wxEvent)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int eventType = arg.GetNumber(1)
	//pThis->GetEntity()->wxEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, Clone)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, GetEventObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, GetEventObject)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, GetEventType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, GetEventType)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, GetEventCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, GetEventCategory)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, GetId)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, GetEventUserData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, GetEventUserData)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventUserData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, GetSkipped)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, GetSkipped)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSkipped();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, GetTimestamp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, GetTimestamp)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTimestamp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, IsCommandEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, IsCommandEvent)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCommandEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, ResumePropagation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propagationLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, ResumePropagation)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int propagationLevel = arg.GetNumber(0)
	//pThis->GetEntity()->ResumePropagation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, SetEventObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetEventObject)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->SetEventObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, SetEventType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetEventType)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetEventType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetId)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, SetTimestamp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeStamp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, SetTimestamp)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timeStamp = arg.GetNumber(0)
	//pThis->GetEntity()->SetTimestamp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, ShouldPropagate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, ShouldPropagate)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShouldPropagate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, Skip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "skip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, Skip)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int skip = arg.GetNumber(0)
	//pThis->GetEntity()->Skip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Event, StopPropagation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, StopPropagation)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StopPropagation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Event)
{
	Gura_AssignMethod(wx_Event, wxEvent);
	Gura_AssignMethod(wx_Event, Clone);
	Gura_AssignMethod(wx_Event, GetEventObject);
	Gura_AssignMethod(wx_Event, GetEventType);
	Gura_AssignMethod(wx_Event, GetEventCategory);
	Gura_AssignMethod(wx_Event, GetId);
	Gura_AssignMethod(wx_Event, GetEventUserData);
	Gura_AssignMethod(wx_Event, GetSkipped);
	Gura_AssignMethod(wx_Event, GetTimestamp);
	Gura_AssignMethod(wx_Event, IsCommandEvent);
	Gura_AssignMethod(wx_Event, ResumePropagation);
	Gura_AssignMethod(wx_Event, SetEventObject);
	Gura_AssignMethod(wx_Event, SetEventType);
	Gura_AssignMethod(wx_Event, SetId);
	Gura_AssignMethod(wx_Event, SetTimestamp);
	Gura_AssignMethod(wx_Event, ShouldPropagate);
	Gura_AssignMethod(wx_Event, Skip);
	Gura_AssignMethod(wx_Event, StopPropagation);
}

Gura_ImplementDescendantCreator(wx_Event)
{
	return new Object_wx_Event((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
