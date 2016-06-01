//----------------------------------------------------------------------------
// wxRichToolTip
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichToolTip
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichToolTip
//----------------------------------------------------------------------------
Object_wx_RichToolTip::~Object_wx_RichToolTip()
{
}

Object *Object_wx_RichToolTip::Clone() const
{
	return nullptr;
}

String Object_wx_RichToolTip::ToString(bool exprFlag)
{
	String rtn("<wx.RichToolTip:");
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
Gura_DeclareMethod(wx_RichToolTip, wxRichToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, wxRichToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichToolTip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichToolTip, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int colEnd = arg.GetNumber(1)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichToolTip, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichToolTip, SetIcon_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, SetIcon_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichToolTip, SetTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "millisecondsTimeout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "millisecondsDelay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, SetTimeout)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int millisecondsTimeout = arg.GetNumber(0)
	//int millisecondsDelay = arg.GetNumber(1)
	//pThis->GetEntity()->SetTimeout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichToolTip, SetTipKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tipKind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, SetTipKind)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tipKind = arg.GetNumber(0)
	//pThis->GetEntity()->SetTipKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichToolTip, SetTitleFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, SetTitleFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichToolTip, ShowFor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, ShowFor)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//pThis->GetEntity()->ShowFor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichToolTip, ~wxRichToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichToolTip, ~wxRichToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichToolTip();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichToolTip
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichToolTip)
{
	Gura_AssignMethod(wx_RichToolTip, wxRichToolTip);
	Gura_AssignMethod(wx_RichToolTip, SetBackgroundColour);
	Gura_AssignMethod(wx_RichToolTip, SetIcon);
	Gura_AssignMethod(wx_RichToolTip, SetIcon_1);
	Gura_AssignMethod(wx_RichToolTip, SetTimeout);
	Gura_AssignMethod(wx_RichToolTip, SetTipKind);
	Gura_AssignMethod(wx_RichToolTip, SetTitleFont);
	Gura_AssignMethod(wx_RichToolTip, ShowFor);
	Gura_AssignMethod(wx_RichToolTip, ~wxRichToolTip);
}

Gura_ImplementDescendantCreator(wx_RichToolTip)
{
	return new Object_wx_RichToolTip((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
