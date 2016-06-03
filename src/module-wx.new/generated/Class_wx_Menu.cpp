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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Menu, "Menu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Menu));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Menu)
{
	//wxMenu();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Menu_1, "Menu_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Menu));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Menu_1)
{
	//long style = arg.GetNumber(0)
	//wxMenu();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Menu_2, "Menu_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Menu));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Menu_2)
{
	//const wxString& title = arg.GetNumber(0)
	//long style = arg.GetNumber(1)
	//wxMenu();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Menu, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Append)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const wxString& helpString = arg.GetNumber(2)
	//wxItemKind kind = arg.GetNumber(3)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Append_1, "Append_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subMenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Append_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//wxMenu* subMenu = arg.GetNumber(2)
	//const wxString& helpString = arg.GetNumber(3)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Append_2, "Append_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menuItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Append_2)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenuItem* menuItem = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __AppendCheckItem, "AppendCheckItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __AppendCheckItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const wxString& help = arg.GetNumber(2)
	//pThis->GetEntity()->AppendCheckItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __AppendRadioItem, "AppendRadioItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __AppendRadioItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const wxString& help = arg.GetNumber(2)
	//pThis->GetEntity()->AppendRadioItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __AppendSeparator, "AppendSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __AppendSeparator)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AppendSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __AppendSubMenu, "AppendSubMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "submenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __AppendSubMenu)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* submenu = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//const wxString& help = arg.GetNumber(2)
	//pThis->GetEntity()->AppendSubMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Break, "Break")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __Break)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Break();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Check, "Check")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Check)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//bool check = arg.GetNumber(1)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Delete, "Delete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Delete)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Delete_1, "Delete_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Delete_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenuItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Destroy, "Destroy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Destroy)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Destroy_1, "Destroy_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Destroy_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenuItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Enable, "Enable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Enable)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//bool enable = arg.GetNumber(1)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __FindChildItem, "FindChildItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __FindChildItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//size_t* pos = arg.GetNumber(1)
	//pThis->GetEntity()->FindChildItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __FindItem, "FindItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "itemString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __FindItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& itemString = arg.GetNumber(0)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __FindItem_1, "FindItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __FindItem_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxMenu** menu = arg.GetNumber(1)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __FindItemByPosition, "FindItemByPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __FindItemByPosition)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t position = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemByPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetHelpString, "GetHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __GetHelpString)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetHelpString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __GetLabel)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetLabelText, "GetLabelText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __GetLabelText)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetMenuItemCount, "GetMenuItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __GetMenuItemCount)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetMenuItems, "GetMenuItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __GetMenuItems)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetMenuItems_1, "GetMenuItems_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __GetMenuItems_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __GetTitle)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menuItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Insert)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxMenuItem* menuItem = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Insert_1, "Insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Insert_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//const wxString& item = arg.GetNumber(2)
	//const wxString& helpString = arg.GetNumber(3)
	//wxItemKind kind = arg.GetNumber(4)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Insert_2, "Insert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "submenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Insert_2)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//wxMenu* submenu = arg.GetNumber(3)
	//const wxString& help = arg.GetNumber(4)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __InsertCheckItem, "InsertCheckItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __InsertCheckItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//const wxString& item = arg.GetNumber(2)
	//const wxString& helpString = arg.GetNumber(3)
	//pThis->GetEntity()->InsertCheckItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __InsertRadioItem, "InsertRadioItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __InsertRadioItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//const wxString& item = arg.GetNumber(2)
	//const wxString& helpString = arg.GetNumber(3)
	//pThis->GetEntity()->InsertRadioItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __InsertSeparator, "InsertSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __InsertSeparator)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//pThis->GetEntity()->InsertSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __IsChecked, "IsChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __IsChecked)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __IsEnabled, "IsEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __IsEnabled)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Prepend, "Prepend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Prepend)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenuItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Prepend_1, "Prepend_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Prepend_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const wxString& helpString = arg.GetNumber(2)
	//wxItemKind kind = arg.GetNumber(3)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Prepend_2, "Prepend_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "submenu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Prepend_2)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//wxMenu* submenu = arg.GetNumber(2)
	//const wxString& help = arg.GetNumber(3)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __PrependCheckItem, "PrependCheckItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __PrependCheckItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const wxString& helpString = arg.GetNumber(2)
	//pThis->GetEntity()->PrependCheckItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __PrependRadioItem, "PrependRadioItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __PrependRadioItem)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const wxString& helpString = arg.GetNumber(2)
	//pThis->GetEntity()->PrependRadioItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __PrependSeparator, "PrependSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __PrependSeparator)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PrependSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Remove)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Remove_1, "Remove_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Remove_1)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenuItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __SetHelpString, "SetHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __SetHelpString)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetHelpString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __SetLabel, "SetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __SetLabel)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __SetTitle, "SetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __SetTitle)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __UpdateUI, "UpdateUI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __UpdateUI)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEvtHandler* source = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateUI();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __SetInvokingWindow, "SetInvokingWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __SetInvokingWindow)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->SetInvokingWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetInvokingWindow, "GetInvokingWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __GetInvokingWindow)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInvokingWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __GetWindow)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __GetStyle)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __SetParent, "SetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __SetParent)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __GetParent)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Attach, "Attach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menubar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Menu, __Attach)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenuBar* menubar = arg.GetNumber(0)
	//pThis->GetEntity()->Attach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __Detach, "Detach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __Detach)
{
	Object_wx_Menu *pThis = Object_wx_Menu::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Menu, __IsAttached, "IsAttached")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Menu, __IsAttached)
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
	// Constructor assignment
	Gura_AssignFunction(__Menu);
	Gura_AssignFunction(__Menu_1);
	Gura_AssignFunction(__Menu_2);
	// Method assignment
	Gura_AssignMethod(wx_Menu, __Append);
	Gura_AssignMethod(wx_Menu, __Append_1);
	Gura_AssignMethod(wx_Menu, __Append_2);
	Gura_AssignMethod(wx_Menu, __AppendCheckItem);
	Gura_AssignMethod(wx_Menu, __AppendRadioItem);
	Gura_AssignMethod(wx_Menu, __AppendSeparator);
	Gura_AssignMethod(wx_Menu, __AppendSubMenu);
	Gura_AssignMethod(wx_Menu, __Break);
	Gura_AssignMethod(wx_Menu, __Check);
	Gura_AssignMethod(wx_Menu, __Delete);
	Gura_AssignMethod(wx_Menu, __Delete_1);
	Gura_AssignMethod(wx_Menu, __Destroy);
	Gura_AssignMethod(wx_Menu, __Destroy_1);
	Gura_AssignMethod(wx_Menu, __Enable);
	Gura_AssignMethod(wx_Menu, __FindChildItem);
	Gura_AssignMethod(wx_Menu, __FindItem);
	Gura_AssignMethod(wx_Menu, __FindItem_1);
	Gura_AssignMethod(wx_Menu, __FindItemByPosition);
	Gura_AssignMethod(wx_Menu, __GetHelpString);
	Gura_AssignMethod(wx_Menu, __GetLabel);
	Gura_AssignMethod(wx_Menu, __GetLabelText);
	Gura_AssignMethod(wx_Menu, __GetMenuItemCount);
	Gura_AssignMethod(wx_Menu, __GetMenuItems);
	Gura_AssignMethod(wx_Menu, __GetMenuItems_1);
	Gura_AssignMethod(wx_Menu, __GetTitle);
	Gura_AssignMethod(wx_Menu, __Insert);
	Gura_AssignMethod(wx_Menu, __Insert_1);
	Gura_AssignMethod(wx_Menu, __Insert_2);
	Gura_AssignMethod(wx_Menu, __InsertCheckItem);
	Gura_AssignMethod(wx_Menu, __InsertRadioItem);
	Gura_AssignMethod(wx_Menu, __InsertSeparator);
	Gura_AssignMethod(wx_Menu, __IsChecked);
	Gura_AssignMethod(wx_Menu, __IsEnabled);
	Gura_AssignMethod(wx_Menu, __Prepend);
	Gura_AssignMethod(wx_Menu, __Prepend_1);
	Gura_AssignMethod(wx_Menu, __Prepend_2);
	Gura_AssignMethod(wx_Menu, __PrependCheckItem);
	Gura_AssignMethod(wx_Menu, __PrependRadioItem);
	Gura_AssignMethod(wx_Menu, __PrependSeparator);
	Gura_AssignMethod(wx_Menu, __Remove);
	Gura_AssignMethod(wx_Menu, __Remove_1);
	Gura_AssignMethod(wx_Menu, __SetHelpString);
	Gura_AssignMethod(wx_Menu, __SetLabel);
	Gura_AssignMethod(wx_Menu, __SetTitle);
	Gura_AssignMethod(wx_Menu, __UpdateUI);
	Gura_AssignMethod(wx_Menu, __SetInvokingWindow);
	Gura_AssignMethod(wx_Menu, __GetInvokingWindow);
	Gura_AssignMethod(wx_Menu, __GetWindow);
	Gura_AssignMethod(wx_Menu, __GetStyle);
	Gura_AssignMethod(wx_Menu, __SetParent);
	Gura_AssignMethod(wx_Menu, __GetParent);
	Gura_AssignMethod(wx_Menu, __Attach);
	Gura_AssignMethod(wx_Menu, __Detach);
	Gura_AssignMethod(wx_Menu, __IsAttached);
}

Gura_ImplementDescendantCreator(wx_Menu)
{
	return new Object_wx_Menu((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
