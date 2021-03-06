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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__CalendarDateAttr, "CalendarDateAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBorder", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CalendarDateAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CalendarDateAttr)
{
	//const wxColour& colText = arg.GetNumber(0)
	//const wxColour& colBack = arg.GetNumber(1)
	//const wxColour& colBorder = arg.GetNumber(2)
	//const wxFont& font = arg.GetNumber(3)
	//wxCalendarDateBorder border = arg.GetNumber(4)
	//wxCalendarDateAttr(colText, colBack, colBorder, font, border);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CalendarDateAttr_1, "CalendarDateAttr_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBorder", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CalendarDateAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CalendarDateAttr_1)
{
	//wxCalendarDateBorder border = arg.GetNumber(0)
	//const wxColour& colBorder = arg.GetNumber(1)
	//wxCalendarDateAttr(border, colBorder);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CalendarDateAttr, __GetBackgroundColour, "GetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __GetBackgroundColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __GetBorder, "GetBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __GetBorder)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCalendarDateBorder _rtn = pThis->GetEntity()->GetBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __GetBorderColour, "GetBorderColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __GetBorderColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetBorderColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __GetFont)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& _rtn = pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __GetTextColour, "GetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __GetTextColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __HasBackgroundColour, "HasBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __HasBackgroundColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __HasBorder, "HasBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __HasBorder)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __HasBorderColour, "HasBorderColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __HasBorderColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBorderColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __HasFont, "HasFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __HasFont)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __HasTextColour, "HasTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __HasTextColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __IsHoliday, "IsHoliday")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __IsHoliday)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsHoliday();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __SetBackgroundColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colBack = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour(colBack);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __SetBorder, "SetBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __SetBorder)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCalendarDateBorder border = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorder(border);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __SetBorderColour, "SetBorderColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __SetBorderColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorderColour(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __SetFont)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __SetHoliday, "SetHoliday")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "holiday", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __SetHoliday)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool holiday = arg.GetNumber(0)
	//pThis->GetEntity()->SetHoliday(holiday);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __SetTextColour, "SetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __SetTextColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colText = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour(colText);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __GetMark, "GetMark")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __GetMark)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxCalendarDateAttr& _rtn = pThis->GetEntity()->GetMark();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalendarDateAttr, __SetMark, "SetMark")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "m", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, __SetMark)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxCalendarDateAttr& m = arg.GetNumber(0)
	//pThis->GetEntity()->SetMark(m);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarDateAttr)
{
	// Constructor assignment
	Gura_AssignFunction(__CalendarDateAttr);
	Gura_AssignFunction(__CalendarDateAttr_1);
	// Method assignment
	Gura_AssignMethod(wx_CalendarDateAttr, __GetBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __GetBorder);
	Gura_AssignMethod(wx_CalendarDateAttr, __GetBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __GetFont);
	Gura_AssignMethod(wx_CalendarDateAttr, __GetTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __HasBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __HasBorder);
	Gura_AssignMethod(wx_CalendarDateAttr, __HasBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __HasFont);
	Gura_AssignMethod(wx_CalendarDateAttr, __HasTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __IsHoliday);
	Gura_AssignMethod(wx_CalendarDateAttr, __SetBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __SetBorder);
	Gura_AssignMethod(wx_CalendarDateAttr, __SetBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __SetFont);
	Gura_AssignMethod(wx_CalendarDateAttr, __SetHoliday);
	Gura_AssignMethod(wx_CalendarDateAttr, __SetTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, __GetMark);
	Gura_AssignMethod(wx_CalendarDateAttr, __SetMark);
}

Gura_ImplementDescendantCreator(wx_CalendarDateAttr)
{
	return new Object_wx_CalendarDateAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
