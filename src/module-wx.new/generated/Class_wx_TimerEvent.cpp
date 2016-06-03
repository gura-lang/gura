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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxTimerEvent, "wxTimerEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TimerEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxTimerEvent)
{
	//wxTimerEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxTimerEvent_1, "wxTimerEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timer", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TimerEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxTimerEvent_1)
{
	//int timer = arg.GetNumber(0)
	//wxTimerEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TimerEvent, __GetInterval, "GetInterval")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimerEvent, __GetInterval)
{
	Object_wx_TimerEvent *pThis = Object_wx_TimerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInterval();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimerEvent, __GetTimer, "GetTimer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimerEvent, __GetTimer)
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
	// Constructor assignment
	Gura_AssignFunction(__wxTimerEvent);
	Gura_AssignFunction(__wxTimerEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_TimerEvent, __GetInterval);
	Gura_AssignMethod(wx_TimerEvent, __GetTimer);
}

Gura_ImplementDescendantCreator(wx_TimerEvent)
{
	return new Object_wx_TimerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
