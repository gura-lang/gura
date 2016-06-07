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
Gura_DeclareFunctionAlias(__ComboCtrl, "ComboCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ComboCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ComboCtrl)
{
	//wxComboCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ComboCtrl_1, "ComboCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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

Gura_ImplementFunction(__ComboCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxComboCtrl(parent, id, value, pos, size, style, validator, name);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, value, pos, size, style, validator, name);
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
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePopupAnimation(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __IsKeyPopupToggle, "IsKeyPopupToggle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __IsKeyPopupToggle)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxKeyEvent& event = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsKeyPopupToggle(event);
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
	//wxDC& dc = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->PrepareBackground(dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __ShouldDrawFocus, "ShouldDrawFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __ShouldDrawFocus)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->ShouldDrawFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetBitmapDisabled, "GetBitmapDisabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetBitmapDisabled)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& _rtn = pThis->GetEntity()->GetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetBitmapHover, "GetBitmapHover")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetBitmapHover)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& _rtn = pThis->GetEntity()->GetBitmapHover();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetBitmapNormal, "GetBitmapNormal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetBitmapNormal)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& _rtn = pThis->GetEntity()->GetBitmapNormal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetBitmapPressed, "GetBitmapPressed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetBitmapPressed)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& _rtn = pThis->GetEntity()->GetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetButtonSize, "GetButtonSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetButtonSize)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetButtonSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetCustomPaintWidth, "GetCustomPaintWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetCustomPaintWidth)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCustomPaintWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetFeatures, "GetFeatures")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetFeatures)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFeatures();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetHint, "GetHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetHint)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetInsertionPoint, "GetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetInsertionPoint)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetLastPosition, "GetLastPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetLastPosition)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetMargins, "GetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetMargins)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetPopupControl, "GetPopupControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetPopupControl)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxComboPopup* _rtn = pThis->GetEntity()->GetPopupControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetPopupWindow, "GetPopupWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetPopupWindow)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetTextCtrl, "GetTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetTextCtrl)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextCtrl* _rtn = pThis->GetEntity()->GetTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetTextIndent, "GetTextIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetTextIndent)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord _rtn = pThis->GetEntity()->GetTextIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetTextRect, "GetTextRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetTextRect)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& _rtn = pThis->GetEntity()->GetTextRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __GetValue)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetValue();
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
	//bool generateEvent = arg.GetNumber(0)
	//pThis->GetEntity()->HidePopup(generateEvent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __IsPopupShown, "IsPopupShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, __IsPopupShown)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsPopupShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __IsPopupWindowState, "IsPopupWindowState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __IsPopupWindowState)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsPopupWindowState(state);
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
	//long from = arg.GetNumber(0)
	//long to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove(from, to);
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
	//long from = arg.GetNumber(0)
	//long to = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//pThis->GetEntity()->Replace(from, to, text);
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
	//const wxBitmap& bmpNormal = arg.GetNumber(0)
	//bool pushButtonBg = arg.GetNumber(1)
	//const wxBitmap& bmpPressed = arg.GetNumber(2)
	//const wxBitmap& bmpHover = arg.GetNumber(3)
	//const wxBitmap& bmpDisabled = arg.GetNumber(4)
	//pThis->GetEntity()->SetButtonBitmaps(bmpNormal, pushButtonBg, bmpPressed, bmpHover, bmpDisabled);
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
	//pThis->GetEntity()->SetButtonPosition(width, height, side, spacingX);
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
	//pThis->GetEntity()->SetCustomPaintWidth(width);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetHint, "SetHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetHint)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& hint = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetHint(hint);
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
	//long pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint(pos);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetMargins)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetMargins(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __SetMargins_1, "SetMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __SetMargins_1)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord left = arg.GetNumber(0)
	//wxCoord top = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetMargins(left, top);
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
	//pThis->GetEntity()->SetPopupAnchor(anchorSide);
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
	//wxComboPopup* popup = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupControl(popup);
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
	//pThis->GetEntity()->SetPopupExtents(extLeft, extRight);
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
	//pThis->GetEntity()->SetPopupMaxHeight(height);
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
	//pThis->GetEntity()->SetPopupMinWidth(width);
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
	//long from = arg.GetNumber(0)
	//long to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection(from, to);
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
	//const wxString& value = arg.GetNumber(0)
	//pThis->GetEntity()->SetText(value);
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
	//pThis->GetEntity()->SetTextCtrlStyle(style);
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
	//pThis->GetEntity()->SetTextIndent(indent);
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
	//const wxString& value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(value);
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
	//const wxString& value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValueByUser(value);
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
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->UseAltPopupWindow(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ComboCtrl, __AnimateShow, "AnimateShow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, __AnimateShow)
{
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->AnimateShow(rect, flags);
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
	//wxComboPopup* popup = arg.GetNumber(0)
	//pThis->GetEntity()->DoSetPopupControl(popup);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxComboCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__ComboCtrl);
	Gura_AssignFunction(__ComboCtrl_1);
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
