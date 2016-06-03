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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlHelpWindow, "HtmlHelpWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpWindow)
{
	//int data = arg.GetNumber(0)
	//wxHtmlHelpWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HtmlHelpWindow_1, "HtmlHelpWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wxWindowID", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpWindow_1)
{
	//int parent = arg.GetNumber(0)
	//int wxWindowID = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int helpStyle = arg.GetNumber(5)
	//int data = arg.GetNumber(6)
	//wxHtmlHelpWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __Create)
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

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __Display, "Display")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __Display)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->Display();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __Display_1, "Display_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __Display_1)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Display();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __DisplayContents, "DisplayContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __DisplayContents)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisplayContents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __DisplayIndex, "DisplayIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __DisplayIndex)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisplayIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __GetData)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __KeywordSearch, "KeywordSearch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyword", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __KeywordSearch)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keyword = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->KeywordSearch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __ReadCustomization, "ReadCustomization")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __ReadCustomization)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->ReadCustomization();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __UseConfig, "UseConfig")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootpath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __UseConfig)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int config = arg.GetNumber(0)
	//int rootpath = arg.GetNumber(1)
	//pThis->GetEntity()->UseConfig();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __WriteCustomization, "WriteCustomization")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __WriteCustomization)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->WriteCustomization();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __RefreshLists, "RefreshLists")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __RefreshLists)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RefreshLists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __GetController, "GetController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __GetController)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetController();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __SetController, "SetController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "controller", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __SetController)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int controller = arg.GetNumber(0)
	//pThis->GetEntity()->SetController();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __CreateSearch, "CreateSearch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __CreateSearch)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateSearch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __AddToolbarButtons, "AddToolbarButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolBar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __AddToolbarButtons)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolBar = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->AddToolbarButtons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __CreateContents, "CreateContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __CreateContents)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateContents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpWindow, __CreateIndex, "CreateIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, __CreateIndex)
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
	// Constructor assignment
	Gura_AssignFunction(__HtmlHelpWindow);
	Gura_AssignFunction(__HtmlHelpWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_HtmlHelpWindow, __Create);
	Gura_AssignMethod(wx_HtmlHelpWindow, __Display);
	Gura_AssignMethod(wx_HtmlHelpWindow, __Display_1);
	Gura_AssignMethod(wx_HtmlHelpWindow, __DisplayContents);
	Gura_AssignMethod(wx_HtmlHelpWindow, __DisplayIndex);
	Gura_AssignMethod(wx_HtmlHelpWindow, __GetData);
	Gura_AssignMethod(wx_HtmlHelpWindow, __KeywordSearch);
	Gura_AssignMethod(wx_HtmlHelpWindow, __ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpWindow, __UseConfig);
	Gura_AssignMethod(wx_HtmlHelpWindow, __WriteCustomization);
	Gura_AssignMethod(wx_HtmlHelpWindow, __RefreshLists);
	Gura_AssignMethod(wx_HtmlHelpWindow, __GetController);
	Gura_AssignMethod(wx_HtmlHelpWindow, __SetController);
	Gura_AssignMethod(wx_HtmlHelpWindow, __CreateSearch);
	Gura_AssignMethod(wx_HtmlHelpWindow, __AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpWindow, __CreateContents);
	Gura_AssignMethod(wx_HtmlHelpWindow, __CreateIndex);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpWindow)
{
	return new Object_wx_HtmlHelpWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
