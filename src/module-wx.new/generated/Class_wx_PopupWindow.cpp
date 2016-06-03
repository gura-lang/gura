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
Gura_DeclareMethodAlias(wx_PopupWindow, __wxPopupWindow, "wxPopupWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PopupWindow, __wxPopupWindow)
{
	Object_wx_PopupWindow *pThis = Object_wx_PopupWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PopupWindow, __wxPopupWindow_1, "wxPopupWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupWindow, __wxPopupWindow_1)
{
	Object_wx_PopupWindow *pThis = Object_wx_PopupWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxPopupWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PopupWindow, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupWindow, __Create)
{
	Object_wx_PopupWindow *pThis = Object_wx_PopupWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PopupWindow, __Position, "Position")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptOrigin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizePopup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupWindow, __Position)
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
	Gura_AssignMethod(wx_PopupWindow, __wxPopupWindow);
	Gura_AssignMethod(wx_PopupWindow, __wxPopupWindow_1);
	Gura_AssignMethod(wx_PopupWindow, __Create);
	Gura_AssignMethod(wx_PopupWindow, __Position);
}

Gura_ImplementDescendantCreator(wx_PopupWindow)
{
	return new Object_wx_PopupWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
