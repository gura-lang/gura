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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PopupWindow, "PopupWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PopupWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PopupWindow)
{
	//wxPopupWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PopupWindow_1, "PopupWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PopupWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PopupWindow_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxPopupWindow(parent, flags);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	//wxWindow* parent = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Create(parent, flags);
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
	//const wxPoint& ptOrigin = arg.GetNumber(0)
	//const wxSize& sizePopup = arg.GetNumber(1)
	//pThis->GetEntity()->Position(ptOrigin, sizePopup);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPopupWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PopupWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__PopupWindow);
	Gura_AssignFunction(__PopupWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_PopupWindow, __Create);
	Gura_AssignMethod(wx_PopupWindow, __Position);
}

Gura_ImplementDescendantCreator(wx_PopupWindow)
{
	return new Object_wx_PopupWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
