//----------------------------------------------------------------------------
// wxCalendarEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCalendarEvent
//----------------------------------------------------------------------------
Object_wx_CalendarEvent::~Object_wx_CalendarEvent()
{
}

Object *Object_wx_CalendarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CalendarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CalendarEvent:");
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
Gura_DeclareMethod(wx_CalendarEvent, wxCalendarEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarEvent, wxCalendarEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarEvent *pThis = Object_wx_CalendarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxCalendarEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarEvent, wxCalendarEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarEvent, wxCalendarEvent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarEvent *pThis = Object_wx_CalendarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->wxCalendarEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarEvent, GetWeekDay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarEvent, GetWeekDay)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarEvent *pThis = Object_wx_CalendarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWeekDay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarEvent, SetWeekDay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarEvent, SetWeekDay)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarEvent *pThis = Object_wx_CalendarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//pThis->GetEntity()->SetWeekDay();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCalendarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarEvent)
{
	Gura_AssignMethod(wx_CalendarEvent, wxCalendarEvent);
	Gura_AssignMethod(wx_CalendarEvent, wxCalendarEvent_1);
	Gura_AssignMethod(wx_CalendarEvent, GetWeekDay);
	Gura_AssignMethod(wx_CalendarEvent, SetWeekDay);
}

Gura_ImplementDescendantCreator(wx_CalendarEvent)
{
	return new Object_wx_CalendarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
