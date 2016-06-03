//----------------------------------------------------------------------------
// wxMDIClientWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIClientWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMDIClientWindow
//----------------------------------------------------------------------------
Object_wx_MDIClientWindow::~Object_wx_MDIClientWindow()
{
}

Object *Object_wx_MDIClientWindow::Clone() const
{
	return nullptr;
}

String Object_wx_MDIClientWindow::ToString(bool exprFlag)
{
	String rtn("<wx.MDIClientWindow:");
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
Gura_DeclareFunctionAlias(__wxMDIClientWindow, "wxMDIClientWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxMDIClientWindow)
{
	//wxMDIClientWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MDIClientWindow, __CreateClient, "CreateClient")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIClientWindow, __CreateClient)
{
	Object_wx_MDIClientWindow *pThis = Object_wx_MDIClientWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->CreateClient();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMDIClientWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIClientWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__wxMDIClientWindow);
	// Method assignment
	Gura_AssignMethod(wx_MDIClientWindow, __CreateClient);
}

Gura_ImplementDescendantCreator(wx_MDIClientWindow)
{
	return new Object_wx_MDIClientWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
