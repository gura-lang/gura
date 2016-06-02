//----------------------------------------------------------------------------
// wxTimerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimerEvent
//----------------------------------------------------------------------------
Object_wx_TimerEvent::~Object_wx_TimerEvent()
{
}

Object *Object_wx_TimerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TimerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TimerEvent:");
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
Gura_DeclareMethod(wx_TimerEvent, wxTimerEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimerEvent, wxTimerEvent)
{
	Object_wx_TimerEvent *pThis = Object_wx_TimerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTimerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimerEvent, wxTimerEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimerEvent, wxTimerEvent_1)
{
	Object_wx_TimerEvent *pThis = Object_wx_TimerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timer = arg.GetNumber(0)
	//pThis->GetEntity()->wxTimerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimerEvent, GetInterval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimerEvent, GetInterval)
{
	Object_wx_TimerEvent *pThis = Object_wx_TimerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInterval();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimerEvent, GetTimer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimerEvent, GetTimer)
{
	Object_wx_TimerEvent *pThis = Object_wx_TimerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTimer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimerEvent)
{
	Gura_AssignMethod(wx_TimerEvent, wxTimerEvent);
	Gura_AssignMethod(wx_TimerEvent, wxTimerEvent_1);
	Gura_AssignMethod(wx_TimerEvent, GetInterval);
	Gura_AssignMethod(wx_TimerEvent, GetTimer);
}

Gura_ImplementDescendantCreator(wx_TimerEvent)
{
	return new Object_wx_TimerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
