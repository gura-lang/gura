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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PersistentWindow, "PersistentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PersistentWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PersistentWindow)
{
	//WindowType* win = arg.GetNumber(0)
	//wxPersistentWindow(win);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PersistentWindow, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentWindow, __Get)
{
	Object_wx_PersistentWindow *pThis = Object_wx_PersistentWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//WindowType* _rtn = pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentWindow, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentWindow, __GetName)
{
	Object_wx_PersistentWindow *pThis = Object_wx_PersistentWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPersistentWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__PersistentWindow);
	// Method assignment
	Gura_AssignMethod(wx_PersistentWindow, __Get);
	Gura_AssignMethod(wx_PersistentWindow, __GetName);
}

Gura_ImplementDescendantCreator(wx_PersistentWindow)
{
	return new Object_wx_PersistentWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
