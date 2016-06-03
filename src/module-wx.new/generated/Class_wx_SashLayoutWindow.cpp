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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxSashLayoutWindow, "wxSashLayoutWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxSashLayoutWindow)
{
	//wxSashLayoutWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxSashLayoutWindow_1, "wxSashLayoutWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxSashLayoutWindow_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//wxSashLayoutWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SashLayoutWindow, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, __Create)
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

Gura_DeclareMethodAlias(wx_SashLayoutWindow, __GetAlignment, "GetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashLayoutWindow, __GetAlignment)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashLayoutWindow, __GetOrientation, "GetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SashLayoutWindow, __GetOrientation)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashLayoutWindow, __OnCalculateLayout, "OnCalculateLayout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, __OnCalculateLayout)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCalculateLayout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashLayoutWindow, __OnQueryLayoutInfo, "OnQueryLayoutInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, __OnQueryLayoutInfo)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnQueryLayoutInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashLayoutWindow, __SetAlignment, "SetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, __SetAlignment)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashLayoutWindow, __SetDefaultSize, "SetDefaultSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, __SetDefaultSize)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashLayoutWindow, __SetOrientation, "SetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, __SetOrientation)
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
	// Constructor assignment
	Gura_AssignFunction(__wxSashLayoutWindow);
	Gura_AssignFunction(__wxSashLayoutWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_SashLayoutWindow, __Create);
	Gura_AssignMethod(wx_SashLayoutWindow, __GetAlignment);
	Gura_AssignMethod(wx_SashLayoutWindow, __GetOrientation);
	Gura_AssignMethod(wx_SashLayoutWindow, __OnCalculateLayout);
	Gura_AssignMethod(wx_SashLayoutWindow, __OnQueryLayoutInfo);
	Gura_AssignMethod(wx_SashLayoutWindow, __SetAlignment);
	Gura_AssignMethod(wx_SashLayoutWindow, __SetDefaultSize);
	Gura_AssignMethod(wx_SashLayoutWindow, __SetOrientation);
}

Gura_ImplementDescendantCreator(wx_SashLayoutWindow)
{
	return new Object_wx_SashLayoutWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
