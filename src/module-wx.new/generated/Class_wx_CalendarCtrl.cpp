//----------------------------------------------------------------------------
// wxCalendarCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCalendarCtrl
//----------------------------------------------------------------------------
Object_wx_CalendarCtrl::~Object_wx_CalendarCtrl()
{
}

Object *Object_wx_CalendarCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_CalendarCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.CalendarCtrl:");
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
Gura_DeclareMethodAlias(wx_CalendarCtrl, __wxCalendarCtrl, "wxCalendarCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, __wxCalendarCtrl)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCalendarCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __wxCalendarCtrl_1, "wxCalendarCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "date", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __wxCalendarCtrl_1)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int date = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxCalendarCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "date", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __Create)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int date = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __EnableHolidayDisplay, "EnableHolidayDisplay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "display", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __EnableHolidayDisplay)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int display = arg.GetNumber(0)
	//pThis->GetEntity()->EnableHolidayDisplay();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __EnableMonthChange, "EnableMonthChange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __EnableMonthChange)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableMonthChange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __EnableYearChange, "EnableYearChange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __EnableYearChange)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableYearChange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetAttr, "GetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetAttr)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//pThis->GetEntity()->GetAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetDate, "GetDate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetDate)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetHeaderColourBg, "GetHeaderColourBg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetHeaderColourBg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderColourBg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetHeaderColourFg, "GetHeaderColourFg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetHeaderColourFg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderColourFg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetHighlightColourBg, "GetHighlightColourBg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetHighlightColourBg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHighlightColourBg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetHighlightColourFg, "GetHighlightColourFg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetHighlightColourFg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHighlightColourFg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetHolidayColourBg, "GetHolidayColourBg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetHolidayColourBg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHolidayColourBg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetHolidayColourFg, "GetHolidayColourFg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetHolidayColourFg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHolidayColourFg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "date", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __HitTest)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int date = arg.GetNumber(1)
	//int wd = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __ResetAttr, "ResetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __ResetAttr)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//pThis->GetEntity()->ResetAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __SetAttr, "SetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __SetAttr)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//pThis->GetEntity()->SetAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __SetDate, "SetDate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "date", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __SetDate)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int date = arg.GetNumber(0)
	//pThis->GetEntity()->SetDate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __SetHeaderColours, "SetHeaderColours")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colFg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __SetHeaderColours)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colFg = arg.GetNumber(0)
	//int colBg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeaderColours();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __SetHighlightColours, "SetHighlightColours")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colFg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __SetHighlightColours)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colFg = arg.GetNumber(0)
	//int colBg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHighlightColours();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __SetHoliday, "SetHoliday")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __SetHoliday)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//pThis->GetEntity()->SetHoliday();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __SetHolidayColours, "SetHolidayColours")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colFg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __SetHolidayColours)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colFg = arg.GetNumber(0)
	//int colBg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHolidayColours();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __Mark, "Mark")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mark", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __Mark)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//int mark = arg.GetNumber(1)
	//pThis->GetEntity()->Mark();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __SetDateRange, "SetDateRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lowerdate", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "upperdate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __SetDateRange)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lowerdate = arg.GetNumber(0)
	//int upperdate = arg.GetNumber(1)
	//pThis->GetEntity()->SetDateRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarCtrl, __GetDateRange, "GetDateRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lowerdate", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "upperdate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, __GetDateRange)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lowerdate = arg.GetNumber(0)
	//int upperdate = arg.GetNumber(1)
	//pThis->GetEntity()->GetDateRange();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCalendarCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarCtrl)
{
	Gura_AssignMethod(wx_CalendarCtrl, __wxCalendarCtrl);
	Gura_AssignMethod(wx_CalendarCtrl, __wxCalendarCtrl_1);
	Gura_AssignMethod(wx_CalendarCtrl, __Create);
	Gura_AssignMethod(wx_CalendarCtrl, __EnableHolidayDisplay);
	Gura_AssignMethod(wx_CalendarCtrl, __EnableMonthChange);
	Gura_AssignMethod(wx_CalendarCtrl, __EnableYearChange);
	Gura_AssignMethod(wx_CalendarCtrl, __GetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, __GetDate);
	Gura_AssignMethod(wx_CalendarCtrl, __GetHeaderColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, __GetHeaderColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, __GetHighlightColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, __GetHighlightColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, __GetHolidayColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, __GetHolidayColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, __HitTest);
	Gura_AssignMethod(wx_CalendarCtrl, __ResetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, __SetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, __SetDate);
	Gura_AssignMethod(wx_CalendarCtrl, __SetHeaderColours);
	Gura_AssignMethod(wx_CalendarCtrl, __SetHighlightColours);
	Gura_AssignMethod(wx_CalendarCtrl, __SetHoliday);
	Gura_AssignMethod(wx_CalendarCtrl, __SetHolidayColours);
	Gura_AssignMethod(wx_CalendarCtrl, __Mark);
	Gura_AssignMethod(wx_CalendarCtrl, __SetDateRange);
	Gura_AssignMethod(wx_CalendarCtrl, __GetDateRange);
}

Gura_ImplementDescendantCreator(wx_CalendarCtrl)
{
	return new Object_wx_CalendarCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
