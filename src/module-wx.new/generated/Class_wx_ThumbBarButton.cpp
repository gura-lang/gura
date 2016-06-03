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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxThumbBarButton, "wxThumbBarButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ThumbBarButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxThumbBarButton)
{
	//wxThumbBarButton();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxThumbBarButton_1, "wxThumbBarButton_1")
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
	SetClassToConstruct(Gura_UserClass(wx_ThumbBarButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxThumbBarButton_1)
{
	//int id = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//int tooltip = arg.GetNumber(2)
	//int enable = arg.GetNumber(3)
	//int dismissOnClick = arg.GetNumber(4)
	//int hasBackground = arg.GetNumber(5)
	//int shown = arg.GetNumber(6)
	//int interactive = arg.GetNumber(7)
	//wxThumbBarButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ThumbBarButton, __Create, "Create")
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

Gura_ImplementMethod(wx_ThumbBarButton, __Create)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_ThumbBarButton, __GetID, "GetID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __GetID)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetID();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __GetIcon, "GetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __GetIcon)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __GetTooltip, "GetTooltip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __GetTooltip)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTooltip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __IsEnable, "IsEnable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __IsEnable)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEnable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __Enable, "Enable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, __Enable)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __Disable, "Disable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __Disable)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Disable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __IsDismissOnClick, "IsDismissOnClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __IsDismissOnClick)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDismissOnClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __EnableDismissOnClick, "EnableDismissOnClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, __EnableDismissOnClick)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDismissOnClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __DisableDimissOnClick, "DisableDimissOnClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __DisableDimissOnClick)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableDimissOnClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __HasBackground, "HasBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __HasBackground)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __SetHasBackground, "SetHasBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "has", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, __SetHasBackground)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int has = arg.GetNumber(0)
	//pThis->GetEntity()->SetHasBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __IsShown, "IsShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __IsShown)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, __Show)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int shown = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __Hide, "Hide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __Hide)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __IsInteractive, "IsInteractive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThumbBarButton, __IsInteractive)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsInteractive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThumbBarButton, __SetInteractive, "SetInteractive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThumbBarButton, __SetInteractive)
{
	Object_wx_ThumbBarButton *pThis = Object_wx_ThumbBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int interactive = arg.GetNumber(0)
	//pThis->GetEntity()->SetInteractive();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxThumbBarButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThumbBarButton)
{
	// Constructor assignment
	Gura_AssignFunction(__wxThumbBarButton);
	Gura_AssignFunction(__wxThumbBarButton_1);
	// Method assignment
	Gura_AssignMethod(wx_ThumbBarButton, __Create);
	Gura_AssignMethod(wx_ThumbBarButton, __GetID);
	Gura_AssignMethod(wx_ThumbBarButton, __GetIcon);
	Gura_AssignMethod(wx_ThumbBarButton, __GetTooltip);
	Gura_AssignMethod(wx_ThumbBarButton, __IsEnable);
	Gura_AssignMethod(wx_ThumbBarButton, __Enable);
	Gura_AssignMethod(wx_ThumbBarButton, __Disable);
	Gura_AssignMethod(wx_ThumbBarButton, __IsDismissOnClick);
	Gura_AssignMethod(wx_ThumbBarButton, __EnableDismissOnClick);
	Gura_AssignMethod(wx_ThumbBarButton, __DisableDimissOnClick);
	Gura_AssignMethod(wx_ThumbBarButton, __HasBackground);
	Gura_AssignMethod(wx_ThumbBarButton, __SetHasBackground);
	Gura_AssignMethod(wx_ThumbBarButton, __IsShown);
	Gura_AssignMethod(wx_ThumbBarButton, __Show);
	Gura_AssignMethod(wx_ThumbBarButton, __Hide);
	Gura_AssignMethod(wx_ThumbBarButton, __IsInteractive);
	Gura_AssignMethod(wx_ThumbBarButton, __SetInteractive);
}

Gura_ImplementDescendantCreator(wx_ThumbBarButton)
{
	return new Object_wx_ThumbBarButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
