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
Gura_DeclareMethod(wx_MenuBar, wxMenuBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, wxMenuBar)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->wxMenuBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, wxMenuBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menus", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "titles", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, wxMenuBar_1)
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

Gura_DeclareMethod(wx_MenuBar, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Append)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Check)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int check = arg.GetNumber(1)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Enable)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, IsEnabledTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, IsEnabledTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->IsEnabledTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, EnableTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, EnableTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, FindItem)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int menu = arg.GetNumber(1)
	//pThis->GetEntity()->FindItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, FindMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, FindMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->FindMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, FindMenuItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menuString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, FindMenuItem)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menuString = arg.GetNumber(0)
	//int itemString = arg.GetNumber(1)
	//pThis->GetEntity()->FindMenuItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, GetHelpString)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, GetLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetLabelTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, GetLabelTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabelTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menuIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, GetMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menuIndex = arg.GetNumber(0)
	//pThis->GetEntity()->GetMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetMenuCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuCount)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetMenuLabelText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, GetMenuLabelText)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetMenuLabelText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Insert)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int menu = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, IsChecked)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, IsEnabled)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Refresh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eraseBackground", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Refresh)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eraseBackground = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//pThis->GetEntity()->Refresh();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Remove)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Replace)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int menu = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, SetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetHelpString)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, SetLabelTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetLabelTop)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetLabelTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, SetMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, SetMenuLabel)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, MacSetCommonMenuBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menubar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, MacSetCommonMenuBar)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menubar = arg.GetNumber(0)
	//pThis->GetEntity()->MacSetCommonMenuBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, MacGetCommonMenuBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, MacGetCommonMenuBar)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MacGetCommonMenuBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, OSXGetAppleMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, OSXGetAppleMenu)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OSXGetAppleMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, GetFrame)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, IsAttached)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, IsAttached)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAttached();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Attach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuBar, Attach)
{
	Object_wx_MenuBar *pThis = Object_wx_MenuBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->Attach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuBar, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuBar, Detach)
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
	Gura_AssignMethod(wx_MenuBar, wxMenuBar);
	Gura_AssignMethod(wx_MenuBar, wxMenuBar_1);
	Gura_AssignMethod(wx_MenuBar, Append);
	Gura_AssignMethod(wx_MenuBar, Check);
	Gura_AssignMethod(wx_MenuBar, Enable);
	Gura_AssignMethod(wx_MenuBar, IsEnabledTop);
	Gura_AssignMethod(wx_MenuBar, EnableTop);
	Gura_AssignMethod(wx_MenuBar, FindItem);
	Gura_AssignMethod(wx_MenuBar, FindMenu);
	Gura_AssignMethod(wx_MenuBar, FindMenuItem);
	Gura_AssignMethod(wx_MenuBar, GetHelpString);
	Gura_AssignMethod(wx_MenuBar, GetLabel);
	Gura_AssignMethod(wx_MenuBar, GetLabelTop);
	Gura_AssignMethod(wx_MenuBar, GetMenu);
	Gura_AssignMethod(wx_MenuBar, GetMenuCount);
	Gura_AssignMethod(wx_MenuBar, GetMenuLabel);
	Gura_AssignMethod(wx_MenuBar, GetMenuLabelText);
	Gura_AssignMethod(wx_MenuBar, Insert);
	Gura_AssignMethod(wx_MenuBar, IsChecked);
	Gura_AssignMethod(wx_MenuBar, IsEnabled);
	Gura_AssignMethod(wx_MenuBar, Refresh);
	Gura_AssignMethod(wx_MenuBar, Remove);
	Gura_AssignMethod(wx_MenuBar, Replace);
	Gura_AssignMethod(wx_MenuBar, SetHelpString);
	Gura_AssignMethod(wx_MenuBar, SetLabel);
	Gura_AssignMethod(wx_MenuBar, SetLabelTop);
	Gura_AssignMethod(wx_MenuBar, SetMenuLabel);
	Gura_AssignMethod(wx_MenuBar, MacSetCommonMenuBar);
	Gura_AssignMethod(wx_MenuBar, MacGetCommonMenuBar);
	Gura_AssignMethod(wx_MenuBar, OSXGetAppleMenu);
	Gura_AssignMethod(wx_MenuBar, GetFrame);
	Gura_AssignMethod(wx_MenuBar, IsAttached);
	Gura_AssignMethod(wx_MenuBar, Attach);
	Gura_AssignMethod(wx_MenuBar, Detach);
}

Gura_ImplementDescendantCreator(wx_MenuBar)
{
	return new Object_wx_MenuBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
