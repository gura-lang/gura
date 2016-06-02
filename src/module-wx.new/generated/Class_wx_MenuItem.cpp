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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MenuItem, wxMenuItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentMenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subMenu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, wxMenuItem)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parentMenu = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int helpString = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//int subMenu = arg.GetNumber(5)
	//pThis->GetEntity()->wxMenuItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, Check)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int check = arg.GetNumber(0)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, Enable)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetLabelFromText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, GetLabelFromText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelFromText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetLabelText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, GetLabelText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetBackgroundColour)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, GetBitmap)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int checked = arg.GetNumber(0)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetDisabledBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetDisabledBitmap)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetFont)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetHelp)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetId)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetItemLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetItemLabel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetItemLabelText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetItemLabelText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemLabelText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetKind)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetLabel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetMarginWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetMarginWidth)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetName)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetSubMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetSubMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSubMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetTextColour)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetAccelFromString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, GetAccelFromString)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->GetAccelFromString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, GetAccel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, GetAccel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAccel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, IsCheck)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, IsCheck)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCheck();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, IsCheckable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, IsCheckable)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCheckable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, IsChecked)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, IsEnabled)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, IsRadio)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, IsRadio)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRadio();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, IsSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, IsSeparator)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, IsSubMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuItem, IsSubMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSubMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetBackgroundColour)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetBitmap)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int checked = arg.GetNumber(1)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetBitmaps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "unchecked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetBitmaps)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int checked = arg.GetNumber(0)
	//int unchecked = arg.GetNumber(1)
	//pThis->GetEntity()->SetBitmaps();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetDisabledBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "disabled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetDisabledBitmap)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int disabled = arg.GetNumber(0)
	//pThis->GetEntity()->SetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetFont)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetHelp)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int helpString = arg.GetNumber(0)
	//pThis->GetEntity()->SetHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetItemLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetItemLabel)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetMarginWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetMarginWidth)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetSubMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetSubMenu)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetSubMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetText)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetTextColour)
{
	Object_wx_MenuItem *pThis = Object_wx_MenuItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuItem, SetAccel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "accel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuItem, SetAccel)
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
	Gura_AssignMethod(wx_MenuItem, wxMenuItem);
	Gura_AssignMethod(wx_MenuItem, Check);
	Gura_AssignMethod(wx_MenuItem, Enable);
	Gura_AssignMethod(wx_MenuItem, GetLabelFromText);
	Gura_AssignMethod(wx_MenuItem, GetLabelText);
	Gura_AssignMethod(wx_MenuItem, GetBackgroundColour);
	Gura_AssignMethod(wx_MenuItem, GetBitmap);
	Gura_AssignMethod(wx_MenuItem, GetDisabledBitmap);
	Gura_AssignMethod(wx_MenuItem, GetFont);
	Gura_AssignMethod(wx_MenuItem, GetHelp);
	Gura_AssignMethod(wx_MenuItem, GetId);
	Gura_AssignMethod(wx_MenuItem, GetItemLabel);
	Gura_AssignMethod(wx_MenuItem, GetItemLabelText);
	Gura_AssignMethod(wx_MenuItem, GetKind);
	Gura_AssignMethod(wx_MenuItem, GetLabel);
	Gura_AssignMethod(wx_MenuItem, GetMarginWidth);
	Gura_AssignMethod(wx_MenuItem, GetMenu);
	Gura_AssignMethod(wx_MenuItem, GetName);
	Gura_AssignMethod(wx_MenuItem, GetSubMenu);
	Gura_AssignMethod(wx_MenuItem, GetText);
	Gura_AssignMethod(wx_MenuItem, GetTextColour);
	Gura_AssignMethod(wx_MenuItem, GetAccelFromString);
	Gura_AssignMethod(wx_MenuItem, GetAccel);
	Gura_AssignMethod(wx_MenuItem, IsCheck);
	Gura_AssignMethod(wx_MenuItem, IsCheckable);
	Gura_AssignMethod(wx_MenuItem, IsChecked);
	Gura_AssignMethod(wx_MenuItem, IsEnabled);
	Gura_AssignMethod(wx_MenuItem, IsRadio);
	Gura_AssignMethod(wx_MenuItem, IsSeparator);
	Gura_AssignMethod(wx_MenuItem, IsSubMenu);
	Gura_AssignMethod(wx_MenuItem, SetBackgroundColour);
	Gura_AssignMethod(wx_MenuItem, SetBitmap);
	Gura_AssignMethod(wx_MenuItem, SetBitmaps);
	Gura_AssignMethod(wx_MenuItem, SetDisabledBitmap);
	Gura_AssignMethod(wx_MenuItem, SetFont);
	Gura_AssignMethod(wx_MenuItem, SetHelp);
	Gura_AssignMethod(wx_MenuItem, SetItemLabel);
	Gura_AssignMethod(wx_MenuItem, SetMarginWidth);
	Gura_AssignMethod(wx_MenuItem, SetMenu);
	Gura_AssignMethod(wx_MenuItem, SetSubMenu);
	Gura_AssignMethod(wx_MenuItem, SetText);
	Gura_AssignMethod(wx_MenuItem, SetTextColour);
	Gura_AssignMethod(wx_MenuItem, SetAccel);
}

Gura_ImplementDescendantCreator(wx_MenuItem)
{
	return new Object_wx_MenuItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
