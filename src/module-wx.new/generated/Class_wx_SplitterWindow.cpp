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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_SplitterWindow, wxSplitterWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, wxSplitterWindow)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSplitterWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, wxSplitterWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, wxSplitterWindow_1)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxSplitterWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, Create)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int point = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, GetMinimumPaneSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, GetMinimumPaneSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinimumPaneSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, GetSashGravity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, GetSashGravity)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSashGravity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, GetSashPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, GetSashPosition)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSashPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, GetSashSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, GetSashSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSashSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, GetDefaultSashSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, GetDefaultSashSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultSashSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, GetSplitMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, GetSplitMode)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSplitMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, GetWindow1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, GetWindow1)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow1();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, GetWindow2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, GetWindow2)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow2();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, Initialize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, IsSashInvisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, IsSashInvisible)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSashInvisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, IsSplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, IsSplit)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSplit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, OnDoubleClickSash)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, OnDoubleClickSash)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->OnDoubleClickSash();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, OnSashPositionChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newSashPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, OnSashPositionChange)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newSashPosition = arg.GetNumber(0)
	//pThis->GetEntity()->OnSashPositionChange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, OnUnsplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "removed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, OnUnsplit)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int removed = arg.GetNumber(0)
	//pThis->GetEntity()->OnUnsplit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, ReplaceWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winOld", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winNew", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, ReplaceWindow)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int winOld = arg.GetNumber(0)
	//int winNew = arg.GetNumber(1)
	//pThis->GetEntity()->ReplaceWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetMinimumPaneSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paneSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetMinimumPaneSize)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paneSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinimumPaneSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetSashGravity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "gravity", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetSashGravity)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int gravity = arg.GetNumber(0)
	//pThis->GetEntity()->SetSashGravity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetSashPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "redraw", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetSashPosition)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int redraw = arg.GetNumber(1)
	//pThis->GetEntity()->SetSashPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetSplitMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetSplitMode)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetSplitMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SetSashInvisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invisible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SetSashInvisible)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int invisible = arg.GetNumber(0)
	//pThis->GetEntity()->SetSashInvisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SplitHorizontally)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sashPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SplitHorizontally)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window1 = arg.GetNumber(0)
	//int window2 = arg.GetNumber(1)
	//int sashPosition = arg.GetNumber(2)
	//pThis->GetEntity()->SplitHorizontally();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, SplitVertically)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sashPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, SplitVertically)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window1 = arg.GetNumber(0)
	//int window2 = arg.GetNumber(1)
	//int sashPosition = arg.GetNumber(2)
	//pThis->GetEntity()->SplitVertically();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, Unsplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toRemove", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterWindow, Unsplit)
{
	Object_wx_SplitterWindow *pThis = Object_wx_SplitterWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toRemove = arg.GetNumber(0)
	//pThis->GetEntity()->Unsplit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterWindow, UpdateSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterWindow, UpdateSize)
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
	Gura_AssignMethod(wx_SplitterWindow, wxSplitterWindow);
	Gura_AssignMethod(wx_SplitterWindow, wxSplitterWindow_1);
	Gura_AssignMethod(wx_SplitterWindow, Create);
	Gura_AssignMethod(wx_SplitterWindow, GetMinimumPaneSize);
	Gura_AssignMethod(wx_SplitterWindow, GetSashGravity);
	Gura_AssignMethod(wx_SplitterWindow, GetSashPosition);
	Gura_AssignMethod(wx_SplitterWindow, GetSashSize);
	Gura_AssignMethod(wx_SplitterWindow, GetDefaultSashSize);
	Gura_AssignMethod(wx_SplitterWindow, GetSplitMode);
	Gura_AssignMethod(wx_SplitterWindow, GetWindow1);
	Gura_AssignMethod(wx_SplitterWindow, GetWindow2);
	Gura_AssignMethod(wx_SplitterWindow, Initialize);
	Gura_AssignMethod(wx_SplitterWindow, IsSashInvisible);
	Gura_AssignMethod(wx_SplitterWindow, IsSplit);
	Gura_AssignMethod(wx_SplitterWindow, OnDoubleClickSash);
	Gura_AssignMethod(wx_SplitterWindow, OnSashPositionChange);
	Gura_AssignMethod(wx_SplitterWindow, OnUnsplit);
	Gura_AssignMethod(wx_SplitterWindow, ReplaceWindow);
	Gura_AssignMethod(wx_SplitterWindow, SetMinimumPaneSize);
	Gura_AssignMethod(wx_SplitterWindow, SetSashGravity);
	Gura_AssignMethod(wx_SplitterWindow, SetSashPosition);
	Gura_AssignMethod(wx_SplitterWindow, SetSplitMode);
	Gura_AssignMethod(wx_SplitterWindow, SetSashInvisible);
	Gura_AssignMethod(wx_SplitterWindow, SplitHorizontally);
	Gura_AssignMethod(wx_SplitterWindow, SplitVertically);
	Gura_AssignMethod(wx_SplitterWindow, Unsplit);
	Gura_AssignMethod(wx_SplitterWindow, UpdateSize);
}

Gura_ImplementDescendantCreator(wx_SplitterWindow)
{
	return new Object_wx_SplitterWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
