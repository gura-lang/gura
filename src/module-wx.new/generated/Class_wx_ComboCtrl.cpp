//----------------------------------------------------------------------------
// wxComboCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxComboCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxComboCtrl
//----------------------------------------------------------------------------
Object_wx_ComboCtrl::~Object_wx_ComboCtrl()
{
}

Object *Object_wx_ComboCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_ComboCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.ComboCtrl:");
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
Gura_DeclareFunctionAlias(__wxComboCtrl, "wxComboCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ComboCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxComboCtrl)
{
	//wxComboCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxComboCtrl_1, "wxComboCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ComboCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxComboCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//wxComboCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ComboCtrl, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __Copy)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __Create)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __Cut, "Cut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __Cut)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __Dismiss, "Dismiss")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __Dismiss)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __EnablePopupAnimation, "EnablePopupAnimation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __EnablePopupAnimation)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePopupAnimation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __IsKeyPopupToggle, "IsKeyPopupToggle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __IsKeyPopupToggle)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->IsKeyPopupToggle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __PrepareBackground, "PrepareBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __PrepareBackground)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->PrepareBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __ShouldDrawFocus, "ShouldDrawFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __ShouldDrawFocus)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShouldDrawFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetBitmapDisabled, "GetBitmapDisabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetBitmapDisabled)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetBitmapHover, "GetBitmapHover")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetBitmapHover)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapHover();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetBitmapNormal, "GetBitmapNormal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetBitmapNormal)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapNormal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetBitmapPressed, "GetBitmapPressed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetBitmapPressed)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetButtonSize, "GetButtonSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetButtonSize)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButtonSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetCustomPaintWidth, "GetCustomPaintWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetCustomPaintWidth)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCustomPaintWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetFeatures, "GetFeatures")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetFeatures)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFeatures();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetHint, "GetHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetHint)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetInsertionPoint, "GetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetInsertionPoint)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetLastPosition, "GetLastPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetLastPosition)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetMargins, "GetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetMargins)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetPopupControl, "GetPopupControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetPopupControl)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPopupControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetPopupWindow, "GetPopupWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetPopupWindow)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetTextCtrl, "GetTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetTextCtrl)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetTextIndent, "GetTextIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetTextIndent)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetTextRect, "GetTextRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetTextRect)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetValue)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __HidePopup, "HidePopup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "generateEvent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __HidePopup)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int generateEvent = arg.GetNumber(0)
	//pThis->GetEntity()->HidePopup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __IsPopupShown, "IsPopupShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __IsPopupShown)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPopupShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __IsPopupWindowState, "IsPopupWindowState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __IsPopupWindowState)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->IsPopupWindowState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __OnButtonClick, "OnButtonClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __OnButtonClick)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnButtonClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __Paste, "Paste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __Paste)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __Popup, "Popup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __Popup)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Popup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __Remove)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __Replace)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetButtonBitmaps, "SetButtonBitmaps")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmpNormal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pushButtonBg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpPressed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpHover", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetButtonBitmaps)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmpNormal = arg.GetNumber(0)
	//int pushButtonBg = arg.GetNumber(1)
	//int bmpPressed = arg.GetNumber(2)
	//int bmpHover = arg.GetNumber(3)
	//int bmpDisabled = arg.GetNumber(4)
	//pThis->GetEntity()->SetButtonBitmaps();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetButtonPosition, "SetButtonPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "side", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "spacingX", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetButtonPosition)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int side = arg.GetNumber(2)
	//int spacingX = arg.GetNumber(3)
	//pThis->GetEntity()->SetButtonPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetCustomPaintWidth, "SetCustomPaintWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetCustomPaintWidth)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetCustomPaintWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetHint, "SetHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetHint)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hint = arg.GetNumber(0)
	//pThis->GetEntity()->SetHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetInsertionPoint, "SetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetInsertionPoint)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetInsertionPointEnd, "SetInsertionPointEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetInsertionPointEnd)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetMargins)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetMargins_1, "SetMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetMargins_1)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int top = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetPopupAnchor, "SetPopupAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anchorSide", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetPopupAnchor)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int anchorSide = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetPopupControl, "SetPopupControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "popup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetPopupControl)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int popup = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetPopupExtents, "SetPopupExtents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "extRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetPopupExtents)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extLeft = arg.GetNumber(0)
	//int extRight = arg.GetNumber(1)
	//pThis->GetEntity()->SetPopupExtents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetPopupMaxHeight, "SetPopupMaxHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetPopupMaxHeight)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupMaxHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetPopupMinWidth, "SetPopupMinWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetPopupMinWidth)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupMinWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetSelection)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetText)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetTextCtrlStyle, "SetTextCtrlStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetTextCtrlStyle)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCtrlStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetTextIndent, "SetTextIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetTextIndent)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetValue)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetValueByUser, "SetValueByUser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetValueByUser)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValueByUser();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __ShowPopup, "ShowPopup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __ShowPopup)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowPopup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __Undo, "Undo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __Undo)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __UseAltPopupWindow, "UseAltPopupWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __UseAltPopupWindow)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->UseAltPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __AnimateShow, "AnimateShow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __AnimateShow)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->AnimateShow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __DoSetPopupControl, "DoSetPopupControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "popup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __DoSetPopupControl)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int popup = arg.GetNumber(0)
	//pThis->GetEntity()->DoSetPopupControl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxComboCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__wxComboCtrl);
	Gura_AssignFunction(__wxComboCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_ComboCtrl, __Copy);
	Gura_AssignMethod(wx_ComboCtrl, __Create);
	Gura_AssignMethod(wx_ComboCtrl, __Cut);
	Gura_AssignMethod(wx_ComboCtrl, __Dismiss);
	Gura_AssignMethod(wx_ComboCtrl, __EnablePopupAnimation);
	Gura_AssignMethod(wx_ComboCtrl, __IsKeyPopupToggle);
	Gura_AssignMethod(wx_ComboCtrl, __PrepareBackground);
	Gura_AssignMethod(wx_ComboCtrl, __ShouldDrawFocus);
	Gura_AssignMethod(wx_ComboCtrl, __GetBitmapDisabled);
	Gura_AssignMethod(wx_ComboCtrl, __GetBitmapHover);
	Gura_AssignMethod(wx_ComboCtrl, __GetBitmapNormal);
	Gura_AssignMethod(wx_ComboCtrl, __GetBitmapPressed);
	Gura_AssignMethod(wx_ComboCtrl, __GetButtonSize);
	Gura_AssignMethod(wx_ComboCtrl, __GetCustomPaintWidth);
	Gura_AssignMethod(wx_ComboCtrl, __GetFeatures);
	Gura_AssignMethod(wx_ComboCtrl, __GetHint);
	Gura_AssignMethod(wx_ComboCtrl, __GetInsertionPoint);
	Gura_AssignMethod(wx_ComboCtrl, __GetLastPosition);
	Gura_AssignMethod(wx_ComboCtrl, __GetMargins);
	Gura_AssignMethod(wx_ComboCtrl, __GetPopupControl);
	Gura_AssignMethod(wx_ComboCtrl, __GetPopupWindow);
	Gura_AssignMethod(wx_ComboCtrl, __GetTextCtrl);
	Gura_AssignMethod(wx_ComboCtrl, __GetTextIndent);
	Gura_AssignMethod(wx_ComboCtrl, __GetTextRect);
	Gura_AssignMethod(wx_ComboCtrl, __GetValue);
	Gura_AssignMethod(wx_ComboCtrl, __HidePopup);
	Gura_AssignMethod(wx_ComboCtrl, __IsPopupShown);
	Gura_AssignMethod(wx_ComboCtrl, __IsPopupWindowState);
	Gura_AssignMethod(wx_ComboCtrl, __OnButtonClick);
	Gura_AssignMethod(wx_ComboCtrl, __Paste);
	Gura_AssignMethod(wx_ComboCtrl, __Popup);
	Gura_AssignMethod(wx_ComboCtrl, __Remove);
	Gura_AssignMethod(wx_ComboCtrl, __Replace);
	Gura_AssignMethod(wx_ComboCtrl, __SetButtonBitmaps);
	Gura_AssignMethod(wx_ComboCtrl, __SetButtonPosition);
	Gura_AssignMethod(wx_ComboCtrl, __SetCustomPaintWidth);
	Gura_AssignMethod(wx_ComboCtrl, __SetHint);
	Gura_AssignMethod(wx_ComboCtrl, __SetInsertionPoint);
	Gura_AssignMethod(wx_ComboCtrl, __SetInsertionPointEnd);
	Gura_AssignMethod(wx_ComboCtrl, __SetMargins);
	Gura_AssignMethod(wx_ComboCtrl, __SetMargins_1);
	Gura_AssignMethod(wx_ComboCtrl, __SetPopupAnchor);
	Gura_AssignMethod(wx_ComboCtrl, __SetPopupControl);
	Gura_AssignMethod(wx_ComboCtrl, __SetPopupExtents);
	Gura_AssignMethod(wx_ComboCtrl, __SetPopupMaxHeight);
	Gura_AssignMethod(wx_ComboCtrl, __SetPopupMinWidth);
	Gura_AssignMethod(wx_ComboCtrl, __SetSelection);
	Gura_AssignMethod(wx_ComboCtrl, __SetText);
	Gura_AssignMethod(wx_ComboCtrl, __SetTextCtrlStyle);
	Gura_AssignMethod(wx_ComboCtrl, __SetTextIndent);
	Gura_AssignMethod(wx_ComboCtrl, __SetValue);
	Gura_AssignMethod(wx_ComboCtrl, __SetValueByUser);
	Gura_AssignMethod(wx_ComboCtrl, __ShowPopup);
	Gura_AssignMethod(wx_ComboCtrl, __Undo);
	Gura_AssignMethod(wx_ComboCtrl, __UseAltPopupWindow);
	Gura_AssignMethod(wx_ComboCtrl, __AnimateShow);
	Gura_AssignMethod(wx_ComboCtrl, __DoSetPopupControl);
}

Gura_ImplementDescendantCreator(wx_ComboCtrl)
{
	return new Object_wx_ComboCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
