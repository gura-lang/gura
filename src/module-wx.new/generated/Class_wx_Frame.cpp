//----------------------------------------------------------------------------
// wxFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFrame
//----------------------------------------------------------------------------
Object_wx_Frame::~Object_wx_Frame()
{
}

Object *Object_wx_Frame::Clone() const
{
	return nullptr;
}

String Object_wx_Frame::ToString(bool exprFlag)
{
	String rtn("<wx.Frame:");
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
Gura_DeclareFunctionAlias(__wxFrame, "wxFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Frame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFrame)
{
	//wxFrame();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFrame_1, "wxFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Frame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFrame_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Frame, __Centre, "Centre")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __Centre)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Centre();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __Create)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __CreateStatusBar, "CreateStatusBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __CreateStatusBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int number = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int name = arg.GetNumber(3)
	//pThis->GetEntity()->CreateStatusBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __CreateToolBar, "CreateToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __CreateToolBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->CreateToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __DoGiveHelp, "DoGiveHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __DoGiveHelp)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//pThis->GetEntity()->DoGiveHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __GetClientAreaOrigin, "GetClientAreaOrigin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, __GetClientAreaOrigin)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientAreaOrigin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __GetMenuBar, "GetMenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, __GetMenuBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __GetStatusBar, "GetStatusBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, __GetStatusBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStatusBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __GetStatusBarPane, "GetStatusBarPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, __GetStatusBarPane)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStatusBarPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __GetToolBar, "GetToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, __GetToolBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __OnCreateStatusBar, "OnCreateStatusBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __OnCreateStatusBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int number = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int name = arg.GetNumber(3)
	//pThis->GetEntity()->OnCreateStatusBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __OnCreateToolBar, "OnCreateToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __OnCreateToolBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->OnCreateToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __ProcessCommand, "ProcessCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __ProcessCommand)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessCommand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __SetMenuBar, "SetMenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menuBar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __SetMenuBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menuBar = arg.GetNumber(0)
	//pThis->GetEntity()->SetMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __SetStatusBar, "SetStatusBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "statusBar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __SetStatusBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int statusBar = arg.GetNumber(0)
	//pThis->GetEntity()->SetStatusBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __SetStatusBarPane, "SetStatusBarPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __SetStatusBarPane)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetStatusBarPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __SetStatusText, "SetStatusText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __SetStatusText)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int number = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __SetStatusWidths, "SetStatusWidths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths_field", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __SetStatusWidths)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int widths_field = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusWidths();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __SetToolBar, "SetToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolBar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __SetToolBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolBar = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __MSWGetTaskBarButton, "MSWGetTaskBarButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, __MSWGetTaskBarButton)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MSWGetTaskBarButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __PushStatusText, "PushStatusText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __PushStatusText)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int number = arg.GetNumber(1)
	//pThis->GetEntity()->PushStatusText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Frame, __PopStatusText, "PopStatusText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, __PopStatusText)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int number = arg.GetNumber(0)
	//pThis->GetEntity()->PopStatusText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Frame)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFrame);
	Gura_AssignFunction(__wxFrame_1);
	// Method assignment
	Gura_AssignMethod(wx_Frame, __Centre);
	Gura_AssignMethod(wx_Frame, __Create);
	Gura_AssignMethod(wx_Frame, __CreateStatusBar);
	Gura_AssignMethod(wx_Frame, __CreateToolBar);
	Gura_AssignMethod(wx_Frame, __DoGiveHelp);
	Gura_AssignMethod(wx_Frame, __GetClientAreaOrigin);
	Gura_AssignMethod(wx_Frame, __GetMenuBar);
	Gura_AssignMethod(wx_Frame, __GetStatusBar);
	Gura_AssignMethod(wx_Frame, __GetStatusBarPane);
	Gura_AssignMethod(wx_Frame, __GetToolBar);
	Gura_AssignMethod(wx_Frame, __OnCreateStatusBar);
	Gura_AssignMethod(wx_Frame, __OnCreateToolBar);
	Gura_AssignMethod(wx_Frame, __ProcessCommand);
	Gura_AssignMethod(wx_Frame, __SetMenuBar);
	Gura_AssignMethod(wx_Frame, __SetStatusBar);
	Gura_AssignMethod(wx_Frame, __SetStatusBarPane);
	Gura_AssignMethod(wx_Frame, __SetStatusText);
	Gura_AssignMethod(wx_Frame, __SetStatusWidths);
	Gura_AssignMethod(wx_Frame, __SetToolBar);
	Gura_AssignMethod(wx_Frame, __MSWGetTaskBarButton);
	Gura_AssignMethod(wx_Frame, __PushStatusText);
	Gura_AssignMethod(wx_Frame, __PopStatusText);
}

Gura_ImplementDescendantCreator(wx_Frame)
{
	return new Object_wx_Frame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
