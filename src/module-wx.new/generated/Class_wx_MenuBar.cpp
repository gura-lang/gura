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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__MenuBar, "MenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MenuBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MenuBar)
{
	//long style = arg.GetNumber(0)
	//wxMenuBar(style);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__MenuBar_1, "MenuBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menus", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "titles", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MenuBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MenuBar_1)
{
	//size_t n = arg.GetNumber(0)
	//wxMenu* menus = arg.GetNumber(1)
	//const wxString titles = arg.GetNumber(2)
	//long style = arg.GetNumber(3)
	//wxMenuBar(n, menus, titles, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MenuBar, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Append)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* menu = arg.GetNumber(0)
	//const wxString& title = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Append(menu, title);
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
	//bool check = arg.GetNumber(1)
	//pThis->GetEntity()->Check(id, check);
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
	//bool enable = arg.GetNumber(1)
	//pThis->GetEntity()->Enable(id, enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __IsEnabledTop, "IsEnabledTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __IsEnabledTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsEnabledTop(pos);
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
	//size_t pos = arg.GetNumber(0)
	//bool enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTop(pos, enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __FindItem, "FindItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __FindItem)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxMenu** menu = arg.GetNumber(1)
	//wxMenuItem* _rtn = pThis->GetEntity()->FindItem(id, menu);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __FindMenu, "FindMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __FindMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->FindMenu(title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __FindMenuItem, "FindMenuItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "menuString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __FindMenuItem)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& menuString = arg.GetNumber(0)
	//const wxString& itemString = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->FindMenuItem(menuString, itemString);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetHelpString, "GetHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetHelpString)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetHelpString(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetLabel(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetLabelTop, "GetLabelTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetLabelTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetLabelTop(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetMenu, "GetMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "menuIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t menuIndex = arg.GetNumber(0)
	//wxMenu* _rtn = pThis->GetEntity()->GetMenu(menuIndex);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetMenuCount, "GetMenuCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __GetMenuCount)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetMenuCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetMenuLabel, "GetMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetMenuLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetMenuLabel(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetMenuLabelText, "GetMenuLabelText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __GetMenuLabelText)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetMenuLabelText(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Insert)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxMenu* menu = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->Insert(pos, menu, title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __IsChecked, "IsChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __IsChecked)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsChecked(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __IsEnabled, "IsEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __IsEnabled)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsEnabled(id);
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
	//bool eraseBackground = arg.GetNumber(0)
	//const wxRect* rect = arg.GetNumber(1)
	//pThis->GetEntity()->Refresh(eraseBackground, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Remove)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxMenu* _rtn = pThis->GetEntity()->Remove(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, __Replace)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxMenu* menu = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//wxMenu* _rtn = pThis->GetEntity()->Replace(pos, menu, title);
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
	//const wxString& helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetHelpString(id, helpString);
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
	//const wxString& label = arg.GetNumber(1)
	//pThis->GetEntity()->SetLabel(id, label);
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
	//size_t pos = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//pThis->GetEntity()->SetLabelTop(pos, label);
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
	//size_t pos = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//pThis->GetEntity()->SetMenuLabel(pos, label);
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
	//wxMenuBar* menubar = arg.GetNumber(0)
	//pThis->GetEntity()->MacSetCommonMenuBar(menubar);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __MacGetCommonMenuBar, "MacGetCommonMenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __MacGetCommonMenuBar)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenuBar* _rtn = pThis->GetEntity()->MacGetCommonMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __OSXGetAppleMenu, "OSXGetAppleMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __OSXGetAppleMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* _rtn = pThis->GetEntity()->OSXGetAppleMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __GetFrame, "GetFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __GetFrame)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFrame* _rtn = pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuBar, __IsAttached, "IsAttached")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, __IsAttached)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsAttached();
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
	//wxFrame* frame = arg.GetNumber(0)
	//pThis->GetEntity()->Attach(frame);
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
	// Constructor assignment
	Gura_AssignFunction(__MenuBar);
	Gura_AssignFunction(__MenuBar_1);
	// Method assignment
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
