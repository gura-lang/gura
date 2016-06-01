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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ComboCtrl, wxComboCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, wxComboCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxComboCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, wxComboCtrl_1)
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

Gura_ImplementMethod(wx_ComboCtrl, wxComboCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxComboCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, ~wxComboCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, ~wxComboCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxComboCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, Create)
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

Gura_ImplementMethod(wx_ComboCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_ComboCtrl, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Cut)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, Dismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Dismiss)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, EnablePopupAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, EnablePopupAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnablePopupAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, IsKeyPopupToggle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, IsKeyPopupToggle)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->IsKeyPopupToggle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, PrepareBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, PrepareBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->PrepareBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, ShouldDrawFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, ShouldDrawFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShouldDrawFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapDisabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapDisabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapHover)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapHover)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapHover();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapNormal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapNormal)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapNormal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetBitmapPressed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetBitmapPressed)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapPressed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetButtonSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetButtonSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetButtonSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetCustomPaintWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetCustomPaintWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCustomPaintWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetFeatures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetFeatures)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFeatures();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetHint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetLastPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetLastPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetPopupControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetPopupControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPopupControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetPopupWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetPopupWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetTextRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetTextRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, HidePopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "generateEvent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, HidePopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int generateEvent = arg.GetNumber(0)
	//pThis->GetEntity()->HidePopup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, IsPopupShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, IsPopupShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPopupShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, IsPopupWindowState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, IsPopupWindowState)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->IsPopupWindowState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, OnButtonClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, OnButtonClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnButtonClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Paste)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, Popup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Popup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Popup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetButtonBitmaps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmpNormal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pushButtonBg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpPressed", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpHover", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetButtonBitmaps)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmpNormal = arg.GetNumber(0)
	//int pushButtonBg = arg.GetNumber(1)
	//int bmpPressed = arg.GetNumber(2)
	//int bmpHover = arg.GetNumber(3)
	//int bmpDisabled = arg.GetNumber(4)
	//pThis->GetEntity()->SetButtonBitmaps();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetButtonPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "side", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "spacingX", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetButtonPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int side = arg.GetNumber(2)
	//int spacingX = arg.GetNumber(3)
	//pThis->GetEntity()->SetButtonPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetCustomPaintWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetCustomPaintWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetCustomPaintWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetHint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hint = arg.GetNumber(0)
	//pThis->GetEntity()->SetHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetInsertionPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetInsertionPointEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, SetInsertionPointEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetMargins_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int top = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anchorSide", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupAnchor)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int anchorSide = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "popup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int popup = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupExtents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "extRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupExtents)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int extLeft = arg.GetNumber(0)
	//int extRight = arg.GetNumber(1)
	//pThis->GetEntity()->SetPopupExtents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupMaxHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupMaxHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupMaxHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetPopupMinWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetPopupMinWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetPopupMinWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetTextCtrlStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetTextCtrlStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCtrlStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetTextIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetTextIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, SetValueByUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, SetValueByUser)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValueByUser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, ShowPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, ShowPopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowPopup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ComboCtrl, Undo)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, UseAltPopupWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, UseAltPopupWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->UseAltPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, AnimateShow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, AnimateShow)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->AnimateShow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ComboCtrl, DoSetPopupControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "popup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ComboCtrl, DoSetPopupControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ComboCtrl *pThis = Object_wx_ComboCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int popup = arg.GetNumber(0)
	//pThis->GetEntity()->DoSetPopupControl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxComboCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboCtrl)
{
	Gura_AssignMethod(wx_ComboCtrl, wxComboCtrl);
	Gura_AssignMethod(wx_ComboCtrl, wxComboCtrl_1);
	Gura_AssignMethod(wx_ComboCtrl, ~wxComboCtrl);
	Gura_AssignMethod(wx_ComboCtrl, Copy);
	Gura_AssignMethod(wx_ComboCtrl, Create);
	Gura_AssignMethod(wx_ComboCtrl, Cut);
	Gura_AssignMethod(wx_ComboCtrl, Dismiss);
	Gura_AssignMethod(wx_ComboCtrl, EnablePopupAnimation);
	Gura_AssignMethod(wx_ComboCtrl, IsKeyPopupToggle);
	Gura_AssignMethod(wx_ComboCtrl, PrepareBackground);
	Gura_AssignMethod(wx_ComboCtrl, ShouldDrawFocus);
	Gura_AssignMethod(wx_ComboCtrl, GetBitmapDisabled);
	Gura_AssignMethod(wx_ComboCtrl, GetBitmapHover);
	Gura_AssignMethod(wx_ComboCtrl, GetBitmapNormal);
	Gura_AssignMethod(wx_ComboCtrl, GetBitmapPressed);
	Gura_AssignMethod(wx_ComboCtrl, GetButtonSize);
	Gura_AssignMethod(wx_ComboCtrl, GetCustomPaintWidth);
	Gura_AssignMethod(wx_ComboCtrl, GetFeatures);
	Gura_AssignMethod(wx_ComboCtrl, GetHint);
	Gura_AssignMethod(wx_ComboCtrl, GetInsertionPoint);
	Gura_AssignMethod(wx_ComboCtrl, GetLastPosition);
	Gura_AssignMethod(wx_ComboCtrl, GetMargins);
	Gura_AssignMethod(wx_ComboCtrl, GetPopupControl);
	Gura_AssignMethod(wx_ComboCtrl, GetPopupWindow);
	Gura_AssignMethod(wx_ComboCtrl, GetTextCtrl);
	Gura_AssignMethod(wx_ComboCtrl, GetTextIndent);
	Gura_AssignMethod(wx_ComboCtrl, GetTextRect);
	Gura_AssignMethod(wx_ComboCtrl, GetValue);
	Gura_AssignMethod(wx_ComboCtrl, HidePopup);
	Gura_AssignMethod(wx_ComboCtrl, IsPopupShown);
	Gura_AssignMethod(wx_ComboCtrl, IsPopupWindowState);
	Gura_AssignMethod(wx_ComboCtrl, OnButtonClick);
	Gura_AssignMethod(wx_ComboCtrl, Paste);
	Gura_AssignMethod(wx_ComboCtrl, Popup);
	Gura_AssignMethod(wx_ComboCtrl, Remove);
	Gura_AssignMethod(wx_ComboCtrl, Replace);
	Gura_AssignMethod(wx_ComboCtrl, SetButtonBitmaps);
	Gura_AssignMethod(wx_ComboCtrl, SetButtonPosition);
	Gura_AssignMethod(wx_ComboCtrl, SetCustomPaintWidth);
	Gura_AssignMethod(wx_ComboCtrl, SetHint);
	Gura_AssignMethod(wx_ComboCtrl, SetInsertionPoint);
	Gura_AssignMethod(wx_ComboCtrl, SetInsertionPointEnd);
	Gura_AssignMethod(wx_ComboCtrl, SetMargins);
	Gura_AssignMethod(wx_ComboCtrl, SetMargins_1);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupAnchor);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupControl);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupExtents);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupMaxHeight);
	Gura_AssignMethod(wx_ComboCtrl, SetPopupMinWidth);
	Gura_AssignMethod(wx_ComboCtrl, SetSelection);
	Gura_AssignMethod(wx_ComboCtrl, SetText);
	Gura_AssignMethod(wx_ComboCtrl, SetTextCtrlStyle);
	Gura_AssignMethod(wx_ComboCtrl, SetTextIndent);
	Gura_AssignMethod(wx_ComboCtrl, SetValue);
	Gura_AssignMethod(wx_ComboCtrl, SetValueByUser);
	Gura_AssignMethod(wx_ComboCtrl, ShowPopup);
	Gura_AssignMethod(wx_ComboCtrl, Undo);
	Gura_AssignMethod(wx_ComboCtrl, UseAltPopupWindow);
	Gura_AssignMethod(wx_ComboCtrl, AnimateShow);
	Gura_AssignMethod(wx_ComboCtrl, DoSetPopupControl);
}

Gura_ImplementDescendantCreator(wx_ComboCtrl)
{
	return new Object_wx_ComboCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
