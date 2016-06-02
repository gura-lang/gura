//----------------------------------------------------------------------------
// wxPopupWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPopupWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPopupWindow
//----------------------------------------------------------------------------
Object_wx_PopupWindow::~Object_wx_PopupWindow()
{
}

Object *Object_wx_PopupWindow::Clone() const
{
	return nullptr;
}

String Object_wx_PopupWindow::ToString(bool exprFlag)
{
	String rtn("<wx.PopupWindow:");
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
Gura_DeclareMethod(wx_PopupWindow, wxPopupWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupWindow, wxPopupWindow)
{
	Object_wx_PopupWindow *pThis = Object_wx_PopupWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PopupWindow, wxPopupWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupWindow, wxPopupWindow_1)
{
	Object_wx_PopupWindow *pThis = Object_wx_PopupWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PopupWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupWindow, Create)
{
	Object_wx_PopupWindow *pThis = Object_wx_PopupWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PopupWindow, Position)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptOrigin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizePopup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupWindow, Position)
{
	Object_wx_PopupWindow *pThis = Object_wx_PopupWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptOrigin = arg.GetNumber(0)
	//int sizePopup = arg.GetNumber(1)
	//pThis->GetEntity()->Position();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPopupWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PopupWindow)
{
	Gura_AssignMethod(wx_PopupWindow, wxPopupWindow);
	Gura_AssignMethod(wx_PopupWindow, wxPopupWindow_1);
	Gura_AssignMethod(wx_PopupWindow, Create);
	Gura_AssignMethod(wx_PopupWindow, Position);
}

Gura_ImplementDescendantCreator(wx_PopupWindow)
{
	return new Object_wx_PopupWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
