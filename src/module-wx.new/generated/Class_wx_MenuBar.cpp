//----------------------------------------------------------------------------
// wxMenuBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMenuBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMenuBar
//----------------------------------------------------------------------------
Object_wx_MenuBar::~Object_wx_MenuBar()
{
}

Object *Object_wx_MenuBar::Clone() const
{
	return nullptr;
}

String Object_wx_MenuBar::ToString(bool exprFlag)
{
	String rtn("<wx.MenuBar:");
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
Gura_DeclareMethodAlias(wx_MenuBar, __wxMenuBar, "wxMenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __wxMenuBar)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->wxMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __wxMenuBar_1, "wxMenuBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menus", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "titles", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __wxMenuBar_1)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int menus = arg.GetNumber(1)
	//int titles = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->wxMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Append)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Check, "Check")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Check)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int check = arg.GetNumber(1)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Enable, "Enable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Enable)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __IsEnabledTop, "IsEnabledTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __IsEnabledTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->IsEnabledTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __EnableTop, "EnableTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __EnableTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __FindItem, "FindItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __FindItem)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int menu = arg.GetNumber(1)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __FindMenu, "FindMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __FindMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->FindMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __FindMenuItem, "FindMenuItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menuString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __FindMenuItem)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menuString = arg.GetNumber(0)
	//int itemString = arg.GetNumber(1)
	//pThis->GetEntity()->FindMenuItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetHelpString, "GetHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetHelpString)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetHelpString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetLabelTop, "GetLabelTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetLabelTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetMenu, "GetMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menuIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menuIndex = arg.GetNumber(0)
	//pThis->GetEntity()->GetMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetMenuCount, "GetMenuCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __GetMenuCount)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetMenuLabel, "GetMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetMenuLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetMenuLabelText, "GetMenuLabelText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetMenuLabelText)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetMenuLabelText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Insert)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int menu = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __IsChecked, "IsChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __IsChecked)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __IsEnabled, "IsEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __IsEnabled)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Refresh, "Refresh")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eraseBackground", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Refresh)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eraseBackground = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//pThis->GetEntity()->Refresh();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Remove)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Replace)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int menu = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __SetHelpString, "SetHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __SetHelpString)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetHelpString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __SetLabel, "SetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __SetLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __SetLabelTop, "SetLabelTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __SetLabelTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetLabelTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __SetMenuLabel, "SetMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __SetMenuLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __MacSetCommonMenuBar, "MacSetCommonMenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menubar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __MacSetCommonMenuBar)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menubar = arg.GetNumber(0)
	//pThis->GetEntity()->MacSetCommonMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __MacGetCommonMenuBar, "MacGetCommonMenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __MacGetCommonMenuBar)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MacGetCommonMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __OSXGetAppleMenu, "OSXGetAppleMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __OSXGetAppleMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OSXGetAppleMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetFrame, "GetFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __GetFrame)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __IsAttached, "IsAttached")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __IsAttached)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAttached();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Attach, "Attach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Attach)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->Attach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Detach, "Detach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __Detach)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMenuBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuBar)
{
	Gura_AssignMethod(wx_MenuBar, __wxMenuBar);
	Gura_AssignMethod(wx_MenuBar, __wxMenuBar_1);
	Gura_AssignMethod(wx_MenuBar, __Append);
	Gura_AssignMethod(wx_MenuBar, __Check);
	Gura_AssignMethod(wx_MenuBar, __Enable);
	Gura_AssignMethod(wx_MenuBar, __IsEnabledTop);
	Gura_AssignMethod(wx_MenuBar, __EnableTop);
	Gura_AssignMethod(wx_MenuBar, __FindItem);
	Gura_AssignMethod(wx_MenuBar, __FindMenu);
	Gura_AssignMethod(wx_MenuBar, __FindMenuItem);
	Gura_AssignMethod(wx_MenuBar, __GetHelpString);
	Gura_AssignMethod(wx_MenuBar, __GetLabel);
	Gura_AssignMethod(wx_MenuBar, __GetLabelTop);
	Gura_AssignMethod(wx_MenuBar, __GetMenu);
	Gura_AssignMethod(wx_MenuBar, __GetMenuCount);
	Gura_AssignMethod(wx_MenuBar, __GetMenuLabel);
	Gura_AssignMethod(wx_MenuBar, __GetMenuLabelText);
	Gura_AssignMethod(wx_MenuBar, __Insert);
	Gura_AssignMethod(wx_MenuBar, __IsChecked);
	Gura_AssignMethod(wx_MenuBar, __IsEnabled);
	Gura_AssignMethod(wx_MenuBar, __Refresh);
	Gura_AssignMethod(wx_MenuBar, __Remove);
	Gura_AssignMethod(wx_MenuBar, __Replace);
	Gura_AssignMethod(wx_MenuBar, __SetHelpString);
	Gura_AssignMethod(wx_MenuBar, __SetLabel);
	Gura_AssignMethod(wx_MenuBar, __SetLabelTop);
	Gura_AssignMethod(wx_MenuBar, __SetMenuLabel);
	Gura_AssignMethod(wx_MenuBar, __MacSetCommonMenuBar);
	Gura_AssignMethod(wx_MenuBar, __MacGetCommonMenuBar);
	Gura_AssignMethod(wx_MenuBar, __OSXGetAppleMenu);
	Gura_AssignMethod(wx_MenuBar, __GetFrame);
	Gura_AssignMethod(wx_MenuBar, __IsAttached);
	Gura_AssignMethod(wx_MenuBar, __Attach);
	Gura_AssignMethod(wx_MenuBar, __Detach);
}

Gura_ImplementDescendantCreator(wx_MenuBar)
{
	return new Object_wx_MenuBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
