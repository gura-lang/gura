//----------------------------------------------------------------------------
// wxThumbBarButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxThumbBarButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxThumbBarButton
//----------------------------------------------------------------------------
Object_wx_ThumbBarButton::~Object_wx_ThumbBarButton()
{
}

Object *Object_wx_ThumbBarButton::Clone() const
{
	return nullptr;
}

String Object_wx_ThumbBarButton::ToString(bool exprFlag)
{
	String rtn("<wx.ThumbBarButton:");
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
Gura_DeclareMethod(wx_ThumbBarButton, wxThumbBarButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, wxThumbBarButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, wxThumbBarButton_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dismissOnClick", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hasBackground", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shown", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, wxThumbBarButton_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//int tooltip = arg.GetNumber(2)
	//int enable = arg.GetNumber(3)
	//int dismissOnClick = arg.GetNumber(4)
	//int hasBackground = arg.GetNumber(5)
	//int shown = arg.GetNumber(6)
	//int interactive = arg.GetNumber(7)
	//pThis->GetEntity()->wxThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dismissOnClick", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hasBackground", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shown", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//int tooltip = arg.GetNumber(2)
	//int enable = arg.GetNumber(3)
	//int dismissOnClick = arg.GetNumber(4)
	//int hasBackground = arg.GetNumber(5)
	//int shown = arg.GetNumber(6)
	//int interactive = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, ~wxThumbBarButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, ~wxThumbBarButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, GetID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, GetID)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetID();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, GetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, GetTooltip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, GetTooltip)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTooltip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, IsEnable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, IsEnable)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEnable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, Disable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, Disable)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Disable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, IsDismissOnClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, IsDismissOnClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDismissOnClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, EnableDismissOnClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, EnableDismissOnClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDismissOnClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, DisableDimissOnClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, DisableDimissOnClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisableDimissOnClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, HasBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, HasBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, SetHasBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "has", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, SetHasBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int has = arg.GetNumber(0)
	//pThis->GetEntity()->SetHasBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, IsShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int shown = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, IsInteractive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, IsInteractive)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsInteractive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThumbBarButton, SetInteractive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, SetInteractive)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int interactive = arg.GetNumber(0)
	//pThis->GetEntity()->SetInteractive();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxThumbBarButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThumbBarButton)
{
	Gura_AssignMethod(wx_ThumbBarButton, wxThumbBarButton);
	Gura_AssignMethod(wx_ThumbBarButton, wxThumbBarButton_1);
	Gura_AssignMethod(wx_ThumbBarButton, Create);
	Gura_AssignMethod(wx_ThumbBarButton, ~wxThumbBarButton);
	Gura_AssignMethod(wx_ThumbBarButton, GetID);
	Gura_AssignMethod(wx_ThumbBarButton, GetIcon);
	Gura_AssignMethod(wx_ThumbBarButton, GetTooltip);
	Gura_AssignMethod(wx_ThumbBarButton, IsEnable);
	Gura_AssignMethod(wx_ThumbBarButton, Enable);
	Gura_AssignMethod(wx_ThumbBarButton, Disable);
	Gura_AssignMethod(wx_ThumbBarButton, IsDismissOnClick);
	Gura_AssignMethod(wx_ThumbBarButton, EnableDismissOnClick);
	Gura_AssignMethod(wx_ThumbBarButton, DisableDimissOnClick);
	Gura_AssignMethod(wx_ThumbBarButton, HasBackground);
	Gura_AssignMethod(wx_ThumbBarButton, SetHasBackground);
	Gura_AssignMethod(wx_ThumbBarButton, IsShown);
	Gura_AssignMethod(wx_ThumbBarButton, Show);
	Gura_AssignMethod(wx_ThumbBarButton, Hide);
	Gura_AssignMethod(wx_ThumbBarButton, IsInteractive);
	Gura_AssignMethod(wx_ThumbBarButton, SetInteractive);
}

Gura_ImplementDescendantCreator(wx_ThumbBarButton)
{
	return new Object_wx_ThumbBarButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
