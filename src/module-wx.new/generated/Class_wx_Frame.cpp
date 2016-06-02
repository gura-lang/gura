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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Frame, wxFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, wxFrame)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, wxFrame_1)
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

Gura_ImplementMethod(wx_Frame, wxFrame_1)
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
	//pThis->GetEntity()->wxFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, Centre)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Centre();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, Create)
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

Gura_ImplementMethod(wx_Frame, Create)
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

Gura_DeclareMethod(wx_Frame, CreateStatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, CreateStatusBar)
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

Gura_DeclareMethod(wx_Frame, CreateToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, CreateToolBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->CreateToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, DoGiveHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, DoGiveHelp)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//pThis->GetEntity()->DoGiveHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, GetClientAreaOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, GetClientAreaOrigin)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientAreaOrigin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, GetMenuBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, GetMenuBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, GetStatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, GetStatusBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStatusBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, GetStatusBarPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, GetStatusBarPane)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStatusBarPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, GetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, GetToolBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, OnCreateStatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, OnCreateStatusBar)
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

Gura_DeclareMethod(wx_Frame, OnCreateToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, OnCreateToolBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->OnCreateToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, ProcessCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, ProcessCommand)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, SetMenuBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menuBar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetMenuBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menuBar = arg.GetNumber(0)
	//pThis->GetEntity()->SetMenuBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, SetStatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "statusBar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetStatusBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int statusBar = arg.GetNumber(0)
	//pThis->GetEntity()->SetStatusBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, SetStatusBarPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetStatusBarPane)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetStatusBarPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, SetStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetStatusText)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int number = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, SetStatusWidths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths_field", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetStatusWidths)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int widths_field = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusWidths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, SetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolBar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, SetToolBar)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolBar = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, MSWGetTaskBarButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Frame, MSWGetTaskBarButton)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MSWGetTaskBarButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, PushStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, PushStatusText)
{
	Object_wx_Frame *pThis = Object_wx_Frame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int number = arg.GetNumber(1)
	//pThis->GetEntity()->PushStatusText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Frame, PopStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Frame, PopStatusText)
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
	Gura_AssignMethod(wx_Frame, wxFrame);
	Gura_AssignMethod(wx_Frame, wxFrame_1);
	Gura_AssignMethod(wx_Frame, Centre);
	Gura_AssignMethod(wx_Frame, Create);
	Gura_AssignMethod(wx_Frame, CreateStatusBar);
	Gura_AssignMethod(wx_Frame, CreateToolBar);
	Gura_AssignMethod(wx_Frame, DoGiveHelp);
	Gura_AssignMethod(wx_Frame, GetClientAreaOrigin);
	Gura_AssignMethod(wx_Frame, GetMenuBar);
	Gura_AssignMethod(wx_Frame, GetStatusBar);
	Gura_AssignMethod(wx_Frame, GetStatusBarPane);
	Gura_AssignMethod(wx_Frame, GetToolBar);
	Gura_AssignMethod(wx_Frame, OnCreateStatusBar);
	Gura_AssignMethod(wx_Frame, OnCreateToolBar);
	Gura_AssignMethod(wx_Frame, ProcessCommand);
	Gura_AssignMethod(wx_Frame, SetMenuBar);
	Gura_AssignMethod(wx_Frame, SetStatusBar);
	Gura_AssignMethod(wx_Frame, SetStatusBarPane);
	Gura_AssignMethod(wx_Frame, SetStatusText);
	Gura_AssignMethod(wx_Frame, SetStatusWidths);
	Gura_AssignMethod(wx_Frame, SetToolBar);
	Gura_AssignMethod(wx_Frame, MSWGetTaskBarButton);
	Gura_AssignMethod(wx_Frame, PushStatusText);
	Gura_AssignMethod(wx_Frame, PopStatusText);
}

Gura_ImplementDescendantCreator(wx_Frame)
{
	return new Object_wx_Frame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
