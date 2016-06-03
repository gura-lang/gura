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
Gura_DeclareFunctionAlias(__wxRichToolTip, "wxRichToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichToolTip));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichToolTip)
{
	//int title = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//wxRichToolTip();
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
	//int col = arg.GetNumber(0)
	//int colEnd = arg.GetNumber(1)
	//pThis->GetEntity()->SetBackgroundColour();
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
	//pThis->GetEntity()->SetIcon();
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
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon();
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
	//int millisecondsTimeout = arg.GetNumber(0)
	//int millisecondsDelay = arg.GetNumber(1)
	//pThis->GetEntity()->SetTimeout();
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
	//int tipKind = arg.GetNumber(0)
	//pThis->GetEntity()->SetTipKind();
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
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFont();
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
	//int win = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//pThis->GetEntity()->ShowFor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichToolTip
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichToolTip)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichToolTip);
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
