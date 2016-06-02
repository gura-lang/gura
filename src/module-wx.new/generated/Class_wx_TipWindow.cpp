//----------------------------------------------------------------------------
// wxTipWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTipWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTipWindow
//----------------------------------------------------------------------------
Object_wx_TipWindow::~Object_wx_TipWindow()
{
}

Object *Object_wx_TipWindow::Clone() const
{
	return nullptr;
}

String Object_wx_TipWindow::ToString(bool exprFlag)
{
	String rtn("<wx.TipWindow:");
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
Gura_DeclareMethod(wx_TipWindow, wxTipWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxLength", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "windowPtr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rectBounds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TipWindow, wxTipWindow)
{
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int maxLength = arg.GetNumber(2)
	//int windowPtr = arg.GetNumber(3)
	//int rectBounds = arg.GetNumber(4)
	//pThis->GetEntity()->wxTipWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TipWindow, SetBoundingRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rectBound", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TipWindow, SetBoundingRect)
{
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rectBound = arg.GetNumber(0)
	//pThis->GetEntity()->SetBoundingRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TipWindow, SetTipWindowPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TipWindow, SetTipWindowPtr)
{
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int windowPtr = arg.GetNumber(0)
	//pThis->GetEntity()->SetTipWindowPtr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTipWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipWindow)
{
	Gura_AssignMethod(wx_TipWindow, wxTipWindow);
	Gura_AssignMethod(wx_TipWindow, SetBoundingRect);
	Gura_AssignMethod(wx_TipWindow, SetTipWindowPtr);
}

Gura_ImplementDescendantCreator(wx_TipWindow)
{
	return new Object_wx_TipWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
