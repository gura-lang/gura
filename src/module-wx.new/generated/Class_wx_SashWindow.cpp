//----------------------------------------------------------------------------
// wxSashWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSashWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSashWindow
//----------------------------------------------------------------------------
Object_wx_SashWindow::~Object_wx_SashWindow()
{
}

Object *Object_wx_SashWindow::Clone() const
{
	return nullptr;
}

String Object_wx_SashWindow::ToString(bool exprFlag)
{
	String rtn("<wx.SashWindow:");
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
Gura_DeclareMethod(wx_SashWindow, wxSashWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, wxSashWindow)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSashWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, wxSashWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, wxSashWindow_1)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxSashWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, GetMaximumSizeX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, GetMaximumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaximumSizeX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, GetMaximumSizeY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, GetMaximumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaximumSizeY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, GetMinimumSizeX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, GetMinimumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinimumSizeX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, GetMinimumSizeY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, GetMinimumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinimumSizeY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, GetSashVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, GetSashVisible)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int edge = arg.GetNumber(0)
	//pThis->GetEntity()->GetSashVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SetMaximumSizeX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetMaximumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaximumSizeX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SetMaximumSizeY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetMaximumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaximumSizeY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SetMinimumSizeX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetMinimumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinimumSizeX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SetMinimumSizeY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetMinimumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinimumSizeY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SetSashVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetSashVisible)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int edge = arg.GetNumber(0)
	//int visible = arg.GetNumber(1)
	//pThis->GetEntity()->SetSashVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, GetEdgeMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, GetEdgeMargin)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int edge = arg.GetNumber(0)
	//pThis->GetEntity()->GetEdgeMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SetDefaultBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetDefaultBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultBorderSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, GetDefaultBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, GetDefaultBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultBorderSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SetExtraBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetExtraBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraBorderSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, GetExtraBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, GetExtraBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraBorderSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SashHitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tolerance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SashHitTest)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int tolerance = arg.GetNumber(2)
	//pThis->GetEntity()->SashHitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashWindow, SizeWindows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, SizeWindows)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SizeWindows();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSashWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashWindow)
{
	Gura_AssignMethod(wx_SashWindow, wxSashWindow);
	Gura_AssignMethod(wx_SashWindow, wxSashWindow_1);
	Gura_AssignMethod(wx_SashWindow, GetMaximumSizeX);
	Gura_AssignMethod(wx_SashWindow, GetMaximumSizeY);
	Gura_AssignMethod(wx_SashWindow, GetMinimumSizeX);
	Gura_AssignMethod(wx_SashWindow, GetMinimumSizeY);
	Gura_AssignMethod(wx_SashWindow, GetSashVisible);
	Gura_AssignMethod(wx_SashWindow, SetMaximumSizeX);
	Gura_AssignMethod(wx_SashWindow, SetMaximumSizeY);
	Gura_AssignMethod(wx_SashWindow, SetMinimumSizeX);
	Gura_AssignMethod(wx_SashWindow, SetMinimumSizeY);
	Gura_AssignMethod(wx_SashWindow, SetSashVisible);
	Gura_AssignMethod(wx_SashWindow, GetEdgeMargin);
	Gura_AssignMethod(wx_SashWindow, SetDefaultBorderSize);
	Gura_AssignMethod(wx_SashWindow, GetDefaultBorderSize);
	Gura_AssignMethod(wx_SashWindow, SetExtraBorderSize);
	Gura_AssignMethod(wx_SashWindow, GetExtraBorderSize);
	Gura_AssignMethod(wx_SashWindow, SashHitTest);
	Gura_AssignMethod(wx_SashWindow, SizeWindows);
}

Gura_ImplementDescendantCreator(wx_SashWindow)
{
	return new Object_wx_SashWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
