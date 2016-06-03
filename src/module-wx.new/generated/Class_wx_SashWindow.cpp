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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxSashWindow, "wxSashWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SashWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxSashWindow)
{
	//wxSashWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxSashWindow_1, "wxSashWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SashWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxSashWindow_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//wxSashWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SashWindow, __GetMaximumSizeX, "GetMaximumSizeX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, __GetMaximumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaximumSizeX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __GetMaximumSizeY, "GetMaximumSizeY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, __GetMaximumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaximumSizeY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __GetMinimumSizeX, "GetMinimumSizeX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, __GetMinimumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinimumSizeX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __GetMinimumSizeY, "GetMinimumSizeY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, __GetMinimumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinimumSizeY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __GetSashVisible, "GetSashVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __GetSashVisible)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int edge = arg.GetNumber(0)
	//pThis->GetEntity()->GetSashVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SetMaximumSizeX, "SetMaximumSizeX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __SetMaximumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaximumSizeX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SetMaximumSizeY, "SetMaximumSizeY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __SetMaximumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaximumSizeY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SetMinimumSizeX, "SetMinimumSizeX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __SetMinimumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinimumSizeX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SetMinimumSizeY, "SetMinimumSizeY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __SetMinimumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinimumSizeY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SetSashVisible, "SetSashVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __SetSashVisible)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int edge = arg.GetNumber(0)
	//int visible = arg.GetNumber(1)
	//pThis->GetEntity()->SetSashVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __GetEdgeMargin, "GetEdgeMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __GetEdgeMargin)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int edge = arg.GetNumber(0)
	//pThis->GetEntity()->GetEdgeMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SetDefaultBorderSize, "SetDefaultBorderSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __SetDefaultBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultBorderSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __GetDefaultBorderSize, "GetDefaultBorderSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, __GetDefaultBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultBorderSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SetExtraBorderSize, "SetExtraBorderSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __SetExtraBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraBorderSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __GetExtraBorderSize, "GetExtraBorderSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, __GetExtraBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraBorderSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SashHitTest, "SashHitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tolerance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, __SashHitTest)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int tolerance = arg.GetNumber(2)
	//pThis->GetEntity()->SashHitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashWindow, __SizeWindows, "SizeWindows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashWindow, __SizeWindows)
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
	// Constructor assignment
	Gura_AssignFunction(__wxSashWindow);
	Gura_AssignFunction(__wxSashWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_SashWindow, __GetMaximumSizeX);
	Gura_AssignMethod(wx_SashWindow, __GetMaximumSizeY);
	Gura_AssignMethod(wx_SashWindow, __GetMinimumSizeX);
	Gura_AssignMethod(wx_SashWindow, __GetMinimumSizeY);
	Gura_AssignMethod(wx_SashWindow, __GetSashVisible);
	Gura_AssignMethod(wx_SashWindow, __SetMaximumSizeX);
	Gura_AssignMethod(wx_SashWindow, __SetMaximumSizeY);
	Gura_AssignMethod(wx_SashWindow, __SetMinimumSizeX);
	Gura_AssignMethod(wx_SashWindow, __SetMinimumSizeY);
	Gura_AssignMethod(wx_SashWindow, __SetSashVisible);
	Gura_AssignMethod(wx_SashWindow, __GetEdgeMargin);
	Gura_AssignMethod(wx_SashWindow, __SetDefaultBorderSize);
	Gura_AssignMethod(wx_SashWindow, __GetDefaultBorderSize);
	Gura_AssignMethod(wx_SashWindow, __SetExtraBorderSize);
	Gura_AssignMethod(wx_SashWindow, __GetExtraBorderSize);
	Gura_AssignMethod(wx_SashWindow, __SashHitTest);
	Gura_AssignMethod(wx_SashWindow, __SizeWindows);
}

Gura_ImplementDescendantCreator(wx_SashWindow)
{
	return new Object_wx_SashWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
