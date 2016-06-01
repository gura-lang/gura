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
Gura_DeclareMethod(wx_CalendarCtrl, wxCalendarCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, wxCalendarCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxCalendarCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, wxCalendarCtrl_1)
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

Gura_ImplementMethod(wx_CalendarCtrl, wxCalendarCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_CalendarCtrl, ~wxCalendarCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, ~wxCalendarCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxCalendarCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, Create)
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

Gura_ImplementMethod(wx_CalendarCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_CalendarCtrl, EnableHolidayDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "display", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableHolidayDisplay)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int display = arg.GetNumber(0)
	//pThis->GetEntity()->EnableHolidayDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, EnableMonthChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableMonthChange)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableMonthChange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, EnableYearChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableYearChange)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableYearChange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//pThis->GetEntity()->GetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetDate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetDate)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHeaderColourBg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHeaderColourBg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderColourBg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHeaderColourFg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHeaderColourFg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderColourFg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHighlightColourBg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHighlightColourBg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHighlightColourBg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHighlightColourFg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHighlightColourFg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHighlightColourFg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHolidayColourBg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHolidayColourBg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHolidayColourBg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHolidayColourFg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHolidayColourFg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHolidayColourFg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "date", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int date = arg.GetNumber(1)
	//int wd = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, ResetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, ResetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//pThis->GetEntity()->ResetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//pThis->GetEntity()->SetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetDate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "date", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetDate)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int date = arg.GetNumber(0)
	//pThis->GetEntity()->SetDate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHeaderColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colFg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHeaderColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colFg = arg.GetNumber(0)
	//int colBg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeaderColours();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHighlightColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colFg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHighlightColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colFg = arg.GetNumber(0)
	//int colBg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHighlightColours();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHoliday)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHoliday)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//pThis->GetEntity()->SetHoliday();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHolidayColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colFg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHolidayColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colFg = arg.GetNumber(0)
	//int colBg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHolidayColours();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, Mark)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mark", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, Mark)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int day = arg.GetNumber(0)
	//int mark = arg.GetNumber(1)
	//pThis->GetEntity()->Mark();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetDateRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lowerdate", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "upperdate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetDateRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int lowerdate = arg.GetNumber(0)
	//int upperdate = arg.GetNumber(1)
	//pThis->GetEntity()->SetDateRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetDateRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lowerdate", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "upperdate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetDateRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_CalendarCtrl, wxCalendarCtrl);
	Gura_AssignMethod(wx_CalendarCtrl, wxCalendarCtrl_1);
	Gura_AssignMethod(wx_CalendarCtrl, ~wxCalendarCtrl);
	Gura_AssignMethod(wx_CalendarCtrl, Create);
	Gura_AssignMethod(wx_CalendarCtrl, EnableHolidayDisplay);
	Gura_AssignMethod(wx_CalendarCtrl, EnableMonthChange);
	Gura_AssignMethod(wx_CalendarCtrl, EnableYearChange);
	Gura_AssignMethod(wx_CalendarCtrl, GetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, GetDate);
	Gura_AssignMethod(wx_CalendarCtrl, GetHeaderColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, GetHeaderColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, GetHighlightColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, GetHighlightColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, GetHolidayColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, GetHolidayColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, HitTest);
	Gura_AssignMethod(wx_CalendarCtrl, ResetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, SetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, SetDate);
	Gura_AssignMethod(wx_CalendarCtrl, SetHeaderColours);
	Gura_AssignMethod(wx_CalendarCtrl, SetHighlightColours);
	Gura_AssignMethod(wx_CalendarCtrl, SetHoliday);
	Gura_AssignMethod(wx_CalendarCtrl, SetHolidayColours);
	Gura_AssignMethod(wx_CalendarCtrl, Mark);
	Gura_AssignMethod(wx_CalendarCtrl, SetDateRange);
	Gura_AssignMethod(wx_CalendarCtrl, GetDateRange);
}

Gura_ImplementDescendantCreator(wx_CalendarCtrl)
{
	return new Object_wx_CalendarCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
