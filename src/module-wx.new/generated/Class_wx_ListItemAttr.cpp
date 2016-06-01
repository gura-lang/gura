//----------------------------------------------------------------------------
// wxListItemAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListItemAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListItemAttr
//----------------------------------------------------------------------------
Object_wx_ListItemAttr::~Object_wx_ListItemAttr()
{
}

Object *Object_wx_ListItemAttr::Clone() const
{
	return nullptr;
}

String Object_wx_ListItemAttr::ToString(bool exprFlag)
{
	String rtn("<wx.ListItemAttr:");
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
Gura_DeclareMethod(wx_ListItemAttr, wxListItemAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, wxListItemAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxListItemAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, wxListItemAttr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, wxListItemAttr_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colText = arg.GetNumber(0)
	//int colBack = arg.GetNumber(1)
	//int font = arg.GetNumber(2)
	//pThis->GetEntity()->wxListItemAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, HasBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, HasBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, HasFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, HasFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, HasTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, HasTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListItemAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListItemAttr)
{
	Gura_AssignMethod(wx_ListItemAttr, wxListItemAttr);
	Gura_AssignMethod(wx_ListItemAttr, wxListItemAttr_1);
	Gura_AssignMethod(wx_ListItemAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, GetFont);
	Gura_AssignMethod(wx_ListItemAttr, GetTextColour);
	Gura_AssignMethod(wx_ListItemAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, HasFont);
	Gura_AssignMethod(wx_ListItemAttr, HasTextColour);
	Gura_AssignMethod(wx_ListItemAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, SetFont);
	Gura_AssignMethod(wx_ListItemAttr, SetTextColour);
}

Gura_ImplementDescendantCreator(wx_ListItemAttr)
{
	return new Object_wx_ListItemAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
