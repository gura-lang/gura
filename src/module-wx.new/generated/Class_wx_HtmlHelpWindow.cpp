//----------------------------------------------------------------------------
// wxHtmlHelpWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpWindow
//----------------------------------------------------------------------------
Object_wx_HtmlHelpWindow::~Object_wx_HtmlHelpWindow()
{
}

Object *Object_wx_HtmlHelpWindow::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpWindow::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpWindow:");
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
Gura_DeclareMethod(wx_HtmlHelpWindow, wxHtmlHelpWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, wxHtmlHelpWindow)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxHtmlHelpWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, wxHtmlHelpWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wxWindowID", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, wxHtmlHelpWindow_1)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int wxWindowID = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int helpStyle = arg.GetNumber(5)
	//int data = arg.GetNumber(6)
	//pThis->GetEntity()->wxHtmlHelpWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, Create)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int helpStyle = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, Display)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, Display)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->Display();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, Display_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, Display_1)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Display();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, DisplayContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, DisplayContents)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisplayContents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, DisplayIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, DisplayIndex)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisplayIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, GetData)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, KeywordSearch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyword", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, KeywordSearch)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keyword = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->KeywordSearch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, ReadCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, ReadCustomization)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->ReadCustomization();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, UseConfig)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootpath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, UseConfig)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int config = arg.GetNumber(0)
	//int rootpath = arg.GetNumber(1)
	//pThis->GetEntity()->UseConfig();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, WriteCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, WriteCustomization)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->WriteCustomization();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, RefreshLists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, RefreshLists)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RefreshLists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, GetController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, GetController)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, SetController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "controller", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, SetController)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int controller = arg.GetNumber(0)
	//pThis->GetEntity()->SetController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, CreateSearch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, CreateSearch)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateSearch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, AddToolbarButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolBar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, AddToolbarButtons)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolBar = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->AddToolbarButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, CreateContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, CreateContents)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateContents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, CreateIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, CreateIndex)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateIndex();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpWindow)
{
	Gura_AssignMethod(wx_HtmlHelpWindow, wxHtmlHelpWindow);
	Gura_AssignMethod(wx_HtmlHelpWindow, wxHtmlHelpWindow_1);
	Gura_AssignMethod(wx_HtmlHelpWindow, Create);
	Gura_AssignMethod(wx_HtmlHelpWindow, Display);
	Gura_AssignMethod(wx_HtmlHelpWindow, Display_1);
	Gura_AssignMethod(wx_HtmlHelpWindow, DisplayContents);
	Gura_AssignMethod(wx_HtmlHelpWindow, DisplayIndex);
	Gura_AssignMethod(wx_HtmlHelpWindow, GetData);
	Gura_AssignMethod(wx_HtmlHelpWindow, KeywordSearch);
	Gura_AssignMethod(wx_HtmlHelpWindow, ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpWindow, UseConfig);
	Gura_AssignMethod(wx_HtmlHelpWindow, WriteCustomization);
	Gura_AssignMethod(wx_HtmlHelpWindow, RefreshLists);
	Gura_AssignMethod(wx_HtmlHelpWindow, GetController);
	Gura_AssignMethod(wx_HtmlHelpWindow, SetController);
	Gura_AssignMethod(wx_HtmlHelpWindow, CreateSearch);
	Gura_AssignMethod(wx_HtmlHelpWindow, AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpWindow, CreateContents);
	Gura_AssignMethod(wx_HtmlHelpWindow, CreateIndex);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpWindow)
{
	return new Object_wx_HtmlHelpWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
