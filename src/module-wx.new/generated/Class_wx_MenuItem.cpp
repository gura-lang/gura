//----------------------------------------------------------------------------
// wxMenuItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMenuItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMenuItem
//----------------------------------------------------------------------------
Object_wx_MenuItem::~Object_wx_MenuItem()
{
}

Object *Object_wx_MenuItem::Clone() const
{
	return nullptr;
}

String Object_wx_MenuItem::ToString(bool exprFlag)
{
	String rtn("<wx.MenuItem:");
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
Gura_DeclareFunctionAlias(__wxMenuItem, "wxMenuItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentMenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subMenu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxMenuItem)
{
	//int parentMenu = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int helpString = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//int subMenu = arg.GetNumber(5)
	//wxMenuItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MenuItem, __Check, "Check")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __Check)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int check = arg.GetNumber(0)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __Enable, "Enable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __Enable)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetLabelFromText, "GetLabelFromText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __GetLabelFromText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelFromText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetLabelText, "GetLabelText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __GetLabelText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetBackgroundColour, "GetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetBackgroundColour)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __GetBitmap)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int checked = arg.GetNumber(0)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetDisabledBitmap, "GetDisabledBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetDisabledBitmap)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetFont)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetHelp, "GetHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetHelp)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetId)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetItemLabel, "GetItemLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetItemLabel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetItemLabelText, "GetItemLabelText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetItemLabelText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemLabelText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetKind)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetLabel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetMarginWidth, "GetMarginWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetMarginWidth)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetMenu, "GetMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetName)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetSubMenu, "GetSubMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetSubMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSubMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetTextColour, "GetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetTextColour)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetAccelFromString, "GetAccelFromString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __GetAccelFromString)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->GetAccelFromString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __GetAccel, "GetAccel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __GetAccel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAccel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __IsCheck, "IsCheck")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __IsCheck)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCheck();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __IsCheckable, "IsCheckable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __IsCheckable)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCheckable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __IsChecked, "IsChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __IsChecked)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __IsEnabled, "IsEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __IsEnabled)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __IsRadio, "IsRadio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __IsRadio)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRadio();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __IsSeparator, "IsSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __IsSeparator)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __IsSubMenu, "IsSubMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, __IsSubMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSubMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetBackgroundColour)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetBitmap)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int checked = arg.GetNumber(1)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetBitmaps, "SetBitmaps")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "unchecked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetBitmaps)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int checked = arg.GetNumber(0)
	//int unchecked = arg.GetNumber(1)
	//pThis->GetEntity()->SetBitmaps();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetDisabledBitmap, "SetDisabledBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "disabled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetDisabledBitmap)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int disabled = arg.GetNumber(0)
	//pThis->GetEntity()->SetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetFont)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetHelp, "SetHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetHelp)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int helpString = arg.GetNumber(0)
	//pThis->GetEntity()->SetHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetItemLabel, "SetItemLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetItemLabel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetMarginWidth, "SetMarginWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetMarginWidth)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetMenu, "SetMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetSubMenu, "SetSubMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetSubMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetSubMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetTextColour, "SetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetTextColour)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuItem, __SetAccel, "SetAccel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "accel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, __SetAccel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int accel = arg.GetNumber(0)
	//pThis->GetEntity()->SetAccel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMenuItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuItem)
{
	// Constructor assignment
	Gura_AssignFunction(__wxMenuItem);
	// Method assignment
	Gura_AssignMethod(wx_MenuItem, __Check);
	Gura_AssignMethod(wx_MenuItem, __Enable);
	Gura_AssignMethod(wx_MenuItem, __GetLabelFromText);
	Gura_AssignMethod(wx_MenuItem, __GetLabelText);
	Gura_AssignMethod(wx_MenuItem, __GetBackgroundColour);
	Gura_AssignMethod(wx_MenuItem, __GetBitmap);
	Gura_AssignMethod(wx_MenuItem, __GetDisabledBitmap);
	Gura_AssignMethod(wx_MenuItem, __GetFont);
	Gura_AssignMethod(wx_MenuItem, __GetHelp);
	Gura_AssignMethod(wx_MenuItem, __GetId);
	Gura_AssignMethod(wx_MenuItem, __GetItemLabel);
	Gura_AssignMethod(wx_MenuItem, __GetItemLabelText);
	Gura_AssignMethod(wx_MenuItem, __GetKind);
	Gura_AssignMethod(wx_MenuItem, __GetLabel);
	Gura_AssignMethod(wx_MenuItem, __GetMarginWidth);
	Gura_AssignMethod(wx_MenuItem, __GetMenu);
	Gura_AssignMethod(wx_MenuItem, __GetName);
	Gura_AssignMethod(wx_MenuItem, __GetSubMenu);
	Gura_AssignMethod(wx_MenuItem, __GetText);
	Gura_AssignMethod(wx_MenuItem, __GetTextColour);
	Gura_AssignMethod(wx_MenuItem, __GetAccelFromString);
	Gura_AssignMethod(wx_MenuItem, __GetAccel);
	Gura_AssignMethod(wx_MenuItem, __IsCheck);
	Gura_AssignMethod(wx_MenuItem, __IsCheckable);
	Gura_AssignMethod(wx_MenuItem, __IsChecked);
	Gura_AssignMethod(wx_MenuItem, __IsEnabled);
	Gura_AssignMethod(wx_MenuItem, __IsRadio);
	Gura_AssignMethod(wx_MenuItem, __IsSeparator);
	Gura_AssignMethod(wx_MenuItem, __IsSubMenu);
	Gura_AssignMethod(wx_MenuItem, __SetBackgroundColour);
	Gura_AssignMethod(wx_MenuItem, __SetBitmap);
	Gura_AssignMethod(wx_MenuItem, __SetBitmaps);
	Gura_AssignMethod(wx_MenuItem, __SetDisabledBitmap);
	Gura_AssignMethod(wx_MenuItem, __SetFont);
	Gura_AssignMethod(wx_MenuItem, __SetHelp);
	Gura_AssignMethod(wx_MenuItem, __SetItemLabel);
	Gura_AssignMethod(wx_MenuItem, __SetMarginWidth);
	Gura_AssignMethod(wx_MenuItem, __SetMenu);
	Gura_AssignMethod(wx_MenuItem, __SetSubMenu);
	Gura_AssignMethod(wx_MenuItem, __SetText);
	Gura_AssignMethod(wx_MenuItem, __SetTextColour);
	Gura_AssignMethod(wx_MenuItem, __SetAccel);
}

Gura_ImplementDescendantCreator(wx_MenuItem)
{
	return new Object_wx_MenuItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
