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
Gura_DeclareFunctionAlias(__SashLayoutWindow, "SashLayoutWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SashLayoutWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SashLayoutWindow)
{
	//wxSashLayoutWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SashLayoutWindow_1, "SashLayoutWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SashLayoutWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SashLayoutWindow_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxSashLayoutWindow(parent, id, pos, size, style, name);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create(parent, id, pos, size, style, name);
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
	//wxCalculateLayoutEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCalculateLayout(event);
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
	//wxQueryLayoutInfoEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnQueryLayoutInfo(event);
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
	//wxLayoutAlignment alignment = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment(alignment);
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
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultSize(size);
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
	//wxLayoutOrientation orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation(orientation);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashLayoutWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__SashLayoutWindow);
	Gura_AssignFunction(__SashLayoutWindow_1);
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
