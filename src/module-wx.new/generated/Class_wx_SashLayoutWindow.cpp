//----------------------------------------------------------------------------
// wxSashLayoutWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSashLayoutWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Object_wx_SashLayoutWindow::~Object_wx_SashLayoutWindow()
{
}

Object *Object_wx_SashLayoutWindow::Clone() const
{
	return nullptr;
}

String Object_wx_SashLayoutWindow::ToString(bool exprFlag)
{
	String rtn("<wx.SashLayoutWindow:");
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
Gura_DeclareMethod(wx_SashLayoutWindow, wxSashLayoutWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashLayoutWindow, wxSashLayoutWindow)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSashLayoutWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, wxSashLayoutWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, wxSashLayoutWindow_1)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxSashLayoutWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, Create)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashLayoutWindow, GetAlignment)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashLayoutWindow, GetOrientation)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, OnCalculateLayout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, OnCalculateLayout)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCalculateLayout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, OnQueryLayoutInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, OnQueryLayoutInfo)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnQueryLayoutInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetAlignment)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetDefaultSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetDefaultSize)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetOrientation)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashLayoutWindow)
{
	Gura_AssignMethod(wx_SashLayoutWindow, wxSashLayoutWindow);
	Gura_AssignMethod(wx_SashLayoutWindow, wxSashLayoutWindow_1);
	Gura_AssignMethod(wx_SashLayoutWindow, Create);
	Gura_AssignMethod(wx_SashLayoutWindow, GetAlignment);
	Gura_AssignMethod(wx_SashLayoutWindow, GetOrientation);
	Gura_AssignMethod(wx_SashLayoutWindow, OnCalculateLayout);
	Gura_AssignMethod(wx_SashLayoutWindow, OnQueryLayoutInfo);
	Gura_AssignMethod(wx_SashLayoutWindow, SetAlignment);
	Gura_AssignMethod(wx_SashLayoutWindow, SetDefaultSize);
	Gura_AssignMethod(wx_SashLayoutWindow, SetOrientation);
}

Gura_ImplementDescendantCreator(wx_SashLayoutWindow)
{
	return new Object_wx_SashLayoutWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
