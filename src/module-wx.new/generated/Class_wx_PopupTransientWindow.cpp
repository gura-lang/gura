//----------------------------------------------------------------------------
// wxPopupTransientWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPopupTransientWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPopupTransientWindow
//----------------------------------------------------------------------------
Object_wx_PopupTransientWindow::~Object_wx_PopupTransientWindow()
{
}

Object *Object_wx_PopupTransientWindow::Clone() const
{
	return nullptr;
}

String Object_wx_PopupTransientWindow::ToString(bool exprFlag)
{
	String rtn("<wx.PopupTransientWindow:");
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
Gura_DeclareMethod(wx_PopupTransientWindow, wxPopupTransientWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupTransientWindow, wxPopupTransientWindow)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPopupTransientWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PopupTransientWindow, wxPopupTransientWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupTransientWindow, wxPopupTransientWindow_1)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxPopupTransientWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PopupTransientWindow, Popup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupTransientWindow, Popup)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int focus = arg.GetNumber(0)
	//pThis->GetEntity()->Popup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PopupTransientWindow, Dismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupTransientWindow, Dismiss)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PopupTransientWindow, ProcessLeftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupTransientWindow, ProcessLeftDown)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessLeftDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PopupTransientWindow, OnDismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupTransientWindow, OnDismiss)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnDismiss();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPopupTransientWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PopupTransientWindow)
{
	Gura_AssignMethod(wx_PopupTransientWindow, wxPopupTransientWindow);
	Gura_AssignMethod(wx_PopupTransientWindow, wxPopupTransientWindow_1);
	Gura_AssignMethod(wx_PopupTransientWindow, Popup);
	Gura_AssignMethod(wx_PopupTransientWindow, Dismiss);
	Gura_AssignMethod(wx_PopupTransientWindow, ProcessLeftDown);
	Gura_AssignMethod(wx_PopupTransientWindow, OnDismiss);
}

Gura_ImplementDescendantCreator(wx_PopupTransientWindow)
{
	return new Object_wx_PopupTransientWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
