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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PopupTransientWindow, "PopupTransientWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PopupTransientWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PopupTransientWindow)
{
	//wxPopupTransientWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PopupTransientWindow_1, "PopupTransientWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PopupTransientWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PopupTransientWindow_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxPopupTransientWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PopupTransientWindow, __Popup, "Popup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupTransientWindow, __Popup)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* focus = arg.GetNumber(0)
	//pThis->GetEntity()->Popup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PopupTransientWindow, __Dismiss, "Dismiss")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupTransientWindow, __Dismiss)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PopupTransientWindow, __ProcessLeftDown, "ProcessLeftDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupTransientWindow, __ProcessLeftDown)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMouseEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessLeftDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PopupTransientWindow, __OnDismiss, "OnDismiss")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupTransientWindow, __OnDismiss)
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
	// Constructor assignment
	Gura_AssignFunction(__PopupTransientWindow);
	Gura_AssignFunction(__PopupTransientWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_PopupTransientWindow, __Popup);
	Gura_AssignMethod(wx_PopupTransientWindow, __Dismiss);
	Gura_AssignMethod(wx_PopupTransientWindow, __ProcessLeftDown);
	Gura_AssignMethod(wx_PopupTransientWindow, __OnDismiss);
}

Gura_ImplementDescendantCreator(wx_PopupTransientWindow)
{
	return new Object_wx_PopupTransientWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
