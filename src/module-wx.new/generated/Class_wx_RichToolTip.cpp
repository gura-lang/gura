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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichToolTip, "RichToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichToolTip));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichToolTip)
{
	//const wxString& title = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//wxRichToolTip(title, message);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichToolTip, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, __SetBackgroundColour)
{
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//const wxColour& colEnd = arg.GetNumber(1)
	//pThis->GetEntity()->SetBackgroundColour(col, colEnd);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichToolTip, __SetIcon, "SetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, __SetIcon)
{
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon(icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichToolTip, __SetIcon_1, "SetIcon_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, __SetIcon_1)
{
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon(icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichToolTip, __SetTimeout, "SetTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "millisecondsTimeout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "millisecondsDelay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, __SetTimeout)
{
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned millisecondsTimeout = arg.GetNumber(0)
	//unsigned millisecondsDelay = arg.GetNumber(1)
	//pThis->GetEntity()->SetTimeout(millisecondsTimeout, millisecondsDelay);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichToolTip, __SetTipKind, "SetTipKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tipKind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, __SetTipKind)
{
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTipKind tipKind = arg.GetNumber(0)
	//pThis->GetEntity()->SetTipKind(tipKind);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichToolTip, __SetTitleFont, "SetTitleFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, __SetTitleFont)
{
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichToolTip, __ShowFor, "ShowFor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichToolTip, __ShowFor)
{
	Object_wx_RichToolTip *pThis = Object_wx_RichToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//const wxRect* rect = arg.GetNumber(1)
	//pThis->GetEntity()->ShowFor(win, rect);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichToolTip
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichToolTip)
{
	// Constructor assignment
	Gura_AssignFunction(__RichToolTip);
	// Method assignment
	Gura_AssignMethod(wx_RichToolTip, __SetBackgroundColour);
	Gura_AssignMethod(wx_RichToolTip, __SetIcon);
	Gura_AssignMethod(wx_RichToolTip, __SetIcon_1);
	Gura_AssignMethod(wx_RichToolTip, __SetTimeout);
	Gura_AssignMethod(wx_RichToolTip, __SetTipKind);
	Gura_AssignMethod(wx_RichToolTip, __SetTitleFont);
	Gura_AssignMethod(wx_RichToolTip, __ShowFor);
}

Gura_ImplementDescendantCreator(wx_RichToolTip)
{
	return new Object_wx_RichToolTip((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
