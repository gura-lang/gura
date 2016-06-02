//----------------------------------------------------------------------------
// wxMenu
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMenu
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMenu
//----------------------------------------------------------------------------
Object_wx_Menu::~Object_wx_Menu()
{
}

Object *Object_wx_Menu::Clone() const
{
	return nullptr;
}

String Object_wx_Menu::ToString(bool exprFlag)
{
	String rtn("<wx.Menu:");
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
Gura_DeclareMethod(wx_Menu, wxMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, wxMenu)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, wxMenu_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, wxMenu_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->wxMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, wxMenu_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, wxMenu_2)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->wxMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Append)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int helpString = arg.GetNumber(2)
	//int kind = arg.GetNumber(3)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Append_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subMenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Append_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int subMenu = arg.GetNumber(2)
	//int helpString = arg.GetNumber(3)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Append_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menuItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Append_2)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menuItem = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, AppendCheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, AppendCheckItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int help = arg.GetNumber(2)
	//pThis->GetEntity()->AppendCheckItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, AppendRadioItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, AppendRadioItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int help = arg.GetNumber(2)
	//pThis->GetEntity()->AppendRadioItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, AppendSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, AppendSeparator)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AppendSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, AppendSubMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "submenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, AppendSubMenu)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int submenu = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int help = arg.GetNumber(2)
	//pThis->GetEntity()->AppendSubMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Break)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, Break)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Break();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Check)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int check = arg.GetNumber(1)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Delete)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Delete_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Delete_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Destroy)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Destroy_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Destroy_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Enable)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, FindChildItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, FindChildItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->FindChildItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "itemString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, FindItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int itemString = arg.GetNumber(0)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, FindItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, FindItem_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int menu = arg.GetNumber(1)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, FindItemByPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, FindItemByPosition)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemByPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, GetHelpString)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, GetLabel)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetLabelText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, GetLabelText)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetMenuItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, GetMenuItemCount)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetMenuItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, GetMenuItems)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetMenuItems_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, GetMenuItems_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, GetTitle)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menuItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Insert)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int menuItem = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Insert_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int helpString = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "submenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Insert_2)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int submenu = arg.GetNumber(3)
	//int help = arg.GetNumber(4)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, InsertCheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, InsertCheckItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int helpString = arg.GetNumber(3)
	//pThis->GetEntity()->InsertCheckItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, InsertRadioItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, InsertRadioItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int helpString = arg.GetNumber(3)
	//pThis->GetEntity()->InsertRadioItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, InsertSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, InsertSeparator)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->InsertSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, IsChecked)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, IsEnabled)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Prepend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Prepend)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Prepend_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Prepend_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int helpString = arg.GetNumber(2)
	//int kind = arg.GetNumber(3)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Prepend_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "submenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Prepend_2)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int submenu = arg.GetNumber(2)
	//int help = arg.GetNumber(3)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, PrependCheckItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, PrependCheckItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int helpString = arg.GetNumber(2)
	//pThis->GetEntity()->PrependCheckItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, PrependRadioItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, PrependRadioItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int helpString = arg.GetNumber(2)
	//pThis->GetEntity()->PrependRadioItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, PrependSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, PrependSeparator)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PrependSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Remove)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Remove_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Remove_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, SetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetHelpString)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetLabel)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetTitle)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, UpdateUI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, UpdateUI)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateUI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, SetInvokingWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetInvokingWindow)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->SetInvokingWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetInvokingWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, GetInvokingWindow)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInvokingWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, GetWindow)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, GetStyle)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, SetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, SetParent)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, GetParent)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Attach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menubar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, Attach)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menubar = arg.GetNumber(0)
	//pThis->GetEntity()->Attach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, Detach)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Menu, IsAttached)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, IsAttached)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAttached();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMenu
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Menu)
{
	Gura_AssignMethod(wx_Menu, wxMenu);
	Gura_AssignMethod(wx_Menu, wxMenu_1);
	Gura_AssignMethod(wx_Menu, wxMenu_2);
	Gura_AssignMethod(wx_Menu, Append);
	Gura_AssignMethod(wx_Menu, Append_1);
	Gura_AssignMethod(wx_Menu, Append_2);
	Gura_AssignMethod(wx_Menu, AppendCheckItem);
	Gura_AssignMethod(wx_Menu, AppendRadioItem);
	Gura_AssignMethod(wx_Menu, AppendSeparator);
	Gura_AssignMethod(wx_Menu, AppendSubMenu);
	Gura_AssignMethod(wx_Menu, Break);
	Gura_AssignMethod(wx_Menu, Check);
	Gura_AssignMethod(wx_Menu, Delete);
	Gura_AssignMethod(wx_Menu, Delete_1);
	Gura_AssignMethod(wx_Menu, Destroy);
	Gura_AssignMethod(wx_Menu, Destroy_1);
	Gura_AssignMethod(wx_Menu, Enable);
	Gura_AssignMethod(wx_Menu, FindChildItem);
	Gura_AssignMethod(wx_Menu, FindItem);
	Gura_AssignMethod(wx_Menu, FindItem_1);
	Gura_AssignMethod(wx_Menu, FindItemByPosition);
	Gura_AssignMethod(wx_Menu, GetHelpString);
	Gura_AssignMethod(wx_Menu, GetLabel);
	Gura_AssignMethod(wx_Menu, GetLabelText);
	Gura_AssignMethod(wx_Menu, GetMenuItemCount);
	Gura_AssignMethod(wx_Menu, GetMenuItems);
	Gura_AssignMethod(wx_Menu, GetMenuItems_1);
	Gura_AssignMethod(wx_Menu, GetTitle);
	Gura_AssignMethod(wx_Menu, Insert);
	Gura_AssignMethod(wx_Menu, Insert_1);
	Gura_AssignMethod(wx_Menu, Insert_2);
	Gura_AssignMethod(wx_Menu, InsertCheckItem);
	Gura_AssignMethod(wx_Menu, InsertRadioItem);
	Gura_AssignMethod(wx_Menu, InsertSeparator);
	Gura_AssignMethod(wx_Menu, IsChecked);
	Gura_AssignMethod(wx_Menu, IsEnabled);
	Gura_AssignMethod(wx_Menu, Prepend);
	Gura_AssignMethod(wx_Menu, Prepend_1);
	Gura_AssignMethod(wx_Menu, Prepend_2);
	Gura_AssignMethod(wx_Menu, PrependCheckItem);
	Gura_AssignMethod(wx_Menu, PrependRadioItem);
	Gura_AssignMethod(wx_Menu, PrependSeparator);
	Gura_AssignMethod(wx_Menu, Remove);
	Gura_AssignMethod(wx_Menu, Remove_1);
	Gura_AssignMethod(wx_Menu, SetHelpString);
	Gura_AssignMethod(wx_Menu, SetLabel);
	Gura_AssignMethod(wx_Menu, SetTitle);
	Gura_AssignMethod(wx_Menu, UpdateUI);
	Gura_AssignMethod(wx_Menu, SetInvokingWindow);
	Gura_AssignMethod(wx_Menu, GetInvokingWindow);
	Gura_AssignMethod(wx_Menu, GetWindow);
	Gura_AssignMethod(wx_Menu, GetStyle);
	Gura_AssignMethod(wx_Menu, SetParent);
	Gura_AssignMethod(wx_Menu, GetParent);
	Gura_AssignMethod(wx_Menu, Attach);
	Gura_AssignMethod(wx_Menu, Detach);
	Gura_AssignMethod(wx_Menu, IsAttached);
}

Gura_ImplementDescendantCreator(wx_Menu)
{
	return new Object_wx_Menu((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
