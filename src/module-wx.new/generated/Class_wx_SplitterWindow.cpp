//----------------------------------------------------------------------------
// wxSplitterWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSplitterWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSplitterWindow
//----------------------------------------------------------------------------
Object_wx_SplitterWindow::~Object_wx_SplitterWindow()
{
}

Object *Object_wx_SplitterWindow::Clone() const
{
	return nullptr;
}

String Object_wx_SplitterWindow::ToString(bool exprFlag)
{
	String rtn("<wx.SplitterWindow:");
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
Gura_DeclareFunctionAlias(__SplitterWindow, "SplitterWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SplitterWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SplitterWindow)
{
	//wxSplitterWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SplitterWindow_1, "SplitterWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SplitterWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SplitterWindow_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxSplitterWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SplitterWindow, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __Create)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& point = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __GetMinimumPaneSize, "GetMinimumPaneSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __GetMinimumPaneSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinimumPaneSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __GetSashGravity, "GetSashGravity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __GetSashGravity)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSashGravity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __GetSashPosition, "GetSashPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __GetSashPosition)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSashPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __GetSashSize, "GetSashSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __GetSashSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSashSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __GetDefaultSashSize, "GetDefaultSashSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __GetDefaultSashSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultSashSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __GetSplitMode, "GetSplitMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __GetSplitMode)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSplitMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __GetWindow1, "GetWindow1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __GetWindow1)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow1();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __GetWindow2, "GetWindow2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __GetWindow2)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow2();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __Initialize, "Initialize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __Initialize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __IsSashInvisible, "IsSashInvisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __IsSashInvisible)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSashInvisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __IsSplit, "IsSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __IsSplit)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSplit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __OnDoubleClickSash, "OnDoubleClickSash")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __OnDoubleClickSash)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->OnDoubleClickSash();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __OnSashPositionChange, "OnSashPositionChange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newSashPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __OnSashPositionChange)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newSashPosition = arg.GetNumber(0)
	//pThis->GetEntity()->OnSashPositionChange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __OnUnsplit, "OnUnsplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "removed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __OnUnsplit)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* removed = arg.GetNumber(0)
	//pThis->GetEntity()->OnUnsplit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __ReplaceWindow, "ReplaceWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winOld", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winNew", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __ReplaceWindow)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* winOld = arg.GetNumber(0)
	//wxWindow* winNew = arg.GetNumber(1)
	//pThis->GetEntity()->ReplaceWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __SetMinimumPaneSize, "SetMinimumPaneSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paneSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __SetMinimumPaneSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paneSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinimumPaneSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __SetSashGravity, "SetSashGravity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "gravity", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __SetSashGravity)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double gravity = arg.GetNumber(0)
	//pThis->GetEntity()->SetSashGravity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __SetSashPosition, "SetSashPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "redraw", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __SetSashPosition)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//bool redraw = arg.GetNumber(1)
	//pThis->GetEntity()->SetSashPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __SetSplitMode, "SetSplitMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __SetSplitMode)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetSplitMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __SetSashInvisible, "SetSashInvisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invisible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __SetSashInvisible)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool invisible = arg.GetNumber(0)
	//pThis->GetEntity()->SetSashInvisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __SplitHorizontally, "SplitHorizontally")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sashPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __SplitHorizontally)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window1 = arg.GetNumber(0)
	//wxWindow* window2 = arg.GetNumber(1)
	//int sashPosition = arg.GetNumber(2)
	//pThis->GetEntity()->SplitHorizontally();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __SplitVertically, "SplitVertically")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sashPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __SplitVertically)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window1 = arg.GetNumber(0)
	//wxWindow* window2 = arg.GetNumber(1)
	//int sashPosition = arg.GetNumber(2)
	//pThis->GetEntity()->SplitVertically();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __Unsplit, "Unsplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toRemove", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, __Unsplit)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* toRemove = arg.GetNumber(0)
	//pThis->GetEntity()->Unsplit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterWindow, __UpdateSize, "UpdateSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, __UpdateSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSplitterWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplitterWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__SplitterWindow);
	Gura_AssignFunction(__SplitterWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_SplitterWindow, __Create);
	Gura_AssignMethod(wx_SplitterWindow, __GetMinimumPaneSize);
	Gura_AssignMethod(wx_SplitterWindow, __GetSashGravity);
	Gura_AssignMethod(wx_SplitterWindow, __GetSashPosition);
	Gura_AssignMethod(wx_SplitterWindow, __GetSashSize);
	Gura_AssignMethod(wx_SplitterWindow, __GetDefaultSashSize);
	Gura_AssignMethod(wx_SplitterWindow, __GetSplitMode);
	Gura_AssignMethod(wx_SplitterWindow, __GetWindow1);
	Gura_AssignMethod(wx_SplitterWindow, __GetWindow2);
	Gura_AssignMethod(wx_SplitterWindow, __Initialize);
	Gura_AssignMethod(wx_SplitterWindow, __IsSashInvisible);
	Gura_AssignMethod(wx_SplitterWindow, __IsSplit);
	Gura_AssignMethod(wx_SplitterWindow, __OnDoubleClickSash);
	Gura_AssignMethod(wx_SplitterWindow, __OnSashPositionChange);
	Gura_AssignMethod(wx_SplitterWindow, __OnUnsplit);
	Gura_AssignMethod(wx_SplitterWindow, __ReplaceWindow);
	Gura_AssignMethod(wx_SplitterWindow, __SetMinimumPaneSize);
	Gura_AssignMethod(wx_SplitterWindow, __SetSashGravity);
	Gura_AssignMethod(wx_SplitterWindow, __SetSashPosition);
	Gura_AssignMethod(wx_SplitterWindow, __SetSplitMode);
	Gura_AssignMethod(wx_SplitterWindow, __SetSashInvisible);
	Gura_AssignMethod(wx_SplitterWindow, __SplitHorizontally);
	Gura_AssignMethod(wx_SplitterWindow, __SplitVertically);
	Gura_AssignMethod(wx_SplitterWindow, __Unsplit);
	Gura_AssignMethod(wx_SplitterWindow, __UpdateSize);
}

Gura_ImplementDescendantCreator(wx_SplitterWindow)
{
	return new Object_wx_SplitterWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
