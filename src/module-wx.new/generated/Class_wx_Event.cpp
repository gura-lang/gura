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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxEvent, "wxEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Event));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxEvent)
{
	//int id = arg.GetNumber(0)
	//int eventType = arg.GetNumber(1)
	//wxEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Event, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __Clone)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __GetEventObject, "GetEventObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __GetEventObject)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __GetEventType, "GetEventType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __GetEventType)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __GetEventCategory, "GetEventCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __GetEventCategory)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventCategory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __GetId)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __GetEventUserData, "GetEventUserData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __GetEventUserData)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventUserData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __GetSkipped, "GetSkipped")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __GetSkipped)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSkipped();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __GetTimestamp, "GetTimestamp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __GetTimestamp)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTimestamp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __IsCommandEvent, "IsCommandEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __IsCommandEvent)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCommandEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __ResumePropagation, "ResumePropagation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propagationLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, __ResumePropagation)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int propagationLevel = arg.GetNumber(0)
	//pThis->GetEntity()->ResumePropagation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __SetEventObject, "SetEventObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, __SetEventObject)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->SetEventObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __SetEventType, "SetEventType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, __SetEventType)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetEventType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __SetId, "SetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, __SetId)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __SetTimestamp, "SetTimestamp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeStamp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, __SetTimestamp)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timeStamp = arg.GetNumber(0)
	//pThis->GetEntity()->SetTimestamp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __ShouldPropagate, "ShouldPropagate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __ShouldPropagate)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShouldPropagate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __Skip, "Skip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "skip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Event, __Skip)
{
	Object_wx_Event *pThis = Object_wx_Event::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int skip = arg.GetNumber(0)
	//pThis->GetEntity()->Skip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Event, __StopPropagation, "StopPropagation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Event, __StopPropagation)
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
	// Constructor assignment
	Gura_AssignFunction(__wxEvent);
	// Method assignment
	Gura_AssignMethod(wx_Event, __Clone);
	Gura_AssignMethod(wx_Event, __GetEventObject);
	Gura_AssignMethod(wx_Event, __GetEventType);
	Gura_AssignMethod(wx_Event, __GetEventCategory);
	Gura_AssignMethod(wx_Event, __GetId);
	Gura_AssignMethod(wx_Event, __GetEventUserData);
	Gura_AssignMethod(wx_Event, __GetSkipped);
	Gura_AssignMethod(wx_Event, __GetTimestamp);
	Gura_AssignMethod(wx_Event, __IsCommandEvent);
	Gura_AssignMethod(wx_Event, __ResumePropagation);
	Gura_AssignMethod(wx_Event, __SetEventObject);
	Gura_AssignMethod(wx_Event, __SetEventType);
	Gura_AssignMethod(wx_Event, __SetId);
	Gura_AssignMethod(wx_Event, __SetTimestamp);
	Gura_AssignMethod(wx_Event, __ShouldPropagate);
	Gura_AssignMethod(wx_Event, __Skip);
	Gura_AssignMethod(wx_Event, __StopPropagation);
}

Gura_ImplementDescendantCreator(wx_Event)
{
	return new Object_wx_Event((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
