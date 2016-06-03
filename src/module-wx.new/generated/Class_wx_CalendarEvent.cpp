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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxCalendarEvent, "wxCalendarEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CalendarEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxCalendarEvent)
{
	//wxCalendarEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxCalendarEvent_1, "wxCalendarEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CalendarEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxCalendarEvent_1)
{
	//int win = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//wxCalendarEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CalendarEvent, __GetWeekDay, "GetWeekDay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarEvent, __GetWeekDay)
{
	Object_wx_CalendarEvent *pThis = Object_wx_CalendarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWeekDay();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarEvent, __SetWeekDay, "SetWeekDay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarEvent, __SetWeekDay)
{
	Object_wx_CalendarEvent *pThis = Object_wx_CalendarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//pThis->GetEntity()->SetWeekDay();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCalendarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxCalendarEvent);
	Gura_AssignFunction(__wxCalendarEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_CalendarEvent, __GetWeekDay);
	Gura_AssignMethod(wx_CalendarEvent, __SetWeekDay);
}

Gura_ImplementDescendantCreator(wx_CalendarEvent)
{
	return new Object_wx_CalendarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
