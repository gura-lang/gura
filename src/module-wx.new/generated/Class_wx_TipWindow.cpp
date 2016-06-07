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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TipWindow, "TipWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxLength", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "windowPtr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rectBounds", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TipWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TipWindow)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//wxCoord maxLength = arg.GetNumber(2)
	//wxTipWindow** windowPtr = arg.GetNumber(3)
	//wxRect* rectBounds = arg.GetNumber(4)
	//wxTipWindow(parent, text, maxLength, windowPtr, rectBounds);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TipWindow, __SetBoundingRect, "SetBoundingRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rectBound", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TipWindow, __SetBoundingRect)
{
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rectBound = arg.GetNumber(0)
	//pThis->GetEntity()->SetBoundingRect(rectBound);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TipWindow, __SetTipWindowPtr, "SetTipWindowPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TipWindow, __SetTipWindowPtr)
{
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTipWindow** windowPtr = arg.GetNumber(0)
	//pThis->GetEntity()->SetTipWindowPtr(windowPtr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTipWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__TipWindow);
	// Method assignment
	Gura_AssignMethod(wx_TipWindow, __SetBoundingRect);
	Gura_AssignMethod(wx_TipWindow, __SetTipWindowPtr);
}

Gura_ImplementDescendantCreator(wx_TipWindow)
{
	return new Object_wx_TipWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
