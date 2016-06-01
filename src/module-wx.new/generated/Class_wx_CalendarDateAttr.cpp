//----------------------------------------------------------------------------
// wxCalendarDateAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarDateAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Object_wx_CalendarDateAttr::~Object_wx_CalendarDateAttr()
{
}

Object *Object_wx_CalendarDateAttr::Clone() const
{
	return nullptr;
}

String Object_wx_CalendarDateAttr::ToString(bool exprFlag)
{
	String rtn("<wx.CalendarDateAttr:");
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
Gura_DeclareMethod(wx_CalendarDateAttr, wxCalendarDateAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBorder", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, wxCalendarDateAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colText = arg.GetNumber(0)
	//int colBack = arg.GetNumber(1)
	//int colBorder = arg.GetNumber(2)
	//int font = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//pThis->GetEntity()->wxCalendarDateAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, wxCalendarDateAttr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBorder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, wxCalendarDateAttr_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int border = arg.GetNumber(0)
	//int colBorder = arg.GetNumber(1)
	//pThis->GetEntity()->wxCalendarDateAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBorderColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBorderColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBorderColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBorderColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBorderColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBorderColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, IsHoliday)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, IsHoliday)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsHoliday();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colBack = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int border = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBorderColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBorderColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorderColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetHoliday)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "holiday", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetHoliday)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int holiday = arg.GetNumber(0)
	//pThis->GetEntity()->SetHoliday();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colText = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetMark)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetMark)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMark();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetMark)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "m", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetMark)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int m = arg.GetNumber(0)
	//pThis->GetEntity()->SetMark();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarDateAttr)
{
	Gura_AssignMethod(wx_CalendarDateAttr, wxCalendarDateAttr);
	Gura_AssignMethod(wx_CalendarDateAttr, wxCalendarDateAttr_1);
	Gura_AssignMethod(wx_CalendarDateAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, GetBorder);
	Gura_AssignMethod(wx_CalendarDateAttr, GetBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, GetFont);
	Gura_AssignMethod(wx_CalendarDateAttr, GetTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, HasBorder);
	Gura_AssignMethod(wx_CalendarDateAttr, HasBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, HasFont);
	Gura_AssignMethod(wx_CalendarDateAttr, HasTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, IsHoliday);
	Gura_AssignMethod(wx_CalendarDateAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, SetBorder);
	Gura_AssignMethod(wx_CalendarDateAttr, SetBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, SetFont);
	Gura_AssignMethod(wx_CalendarDateAttr, SetHoliday);
	Gura_AssignMethod(wx_CalendarDateAttr, SetTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, GetMark);
	Gura_AssignMethod(wx_CalendarDateAttr, SetMark);
}

Gura_ImplementDescendantCreator(wx_CalendarDateAttr)
{
	return new Object_wx_CalendarDateAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
