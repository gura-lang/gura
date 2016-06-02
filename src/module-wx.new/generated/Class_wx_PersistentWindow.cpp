//----------------------------------------------------------------------------
// wxPersistentWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistentWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistentWindow
//----------------------------------------------------------------------------
Object_wx_PersistentWindow::~Object_wx_PersistentWindow()
{
}

Object *Object_wx_PersistentWindow::Clone() const
{
	return nullptr;
}

String Object_wx_PersistentWindow::ToString(bool exprFlag)
{
	String rtn("<wx.PersistentWindow:");
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
Gura_DeclareMethod(wx_PersistentWindow, wxPersistentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentWindow, wxPersistentWindow)
{
	Object_wx_PersistentWindow *pThis = Object_wx_PersistentWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxPersistentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentWindow, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentWindow, Get)
{
	Object_wx_PersistentWindow *pThis = Object_wx_PersistentWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentWindow, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentWindow, GetName)
{
	Object_wx_PersistentWindow *pThis = Object_wx_PersistentWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPersistentWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentWindow)
{
	Gura_AssignMethod(wx_PersistentWindow, wxPersistentWindow);
	Gura_AssignMethod(wx_PersistentWindow, Get);
	Gura_AssignMethod(wx_PersistentWindow, GetName);
}

Gura_ImplementDescendantCreator(wx_PersistentWindow)
{
	return new Object_wx_PersistentWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
