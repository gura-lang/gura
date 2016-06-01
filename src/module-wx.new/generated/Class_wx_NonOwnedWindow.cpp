//----------------------------------------------------------------------------
// wxNonOwnedWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNonOwnedWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNonOwnedWindow
//----------------------------------------------------------------------------
Object_wx_NonOwnedWindow::~Object_wx_NonOwnedWindow()
{
}

Object *Object_wx_NonOwnedWindow::Clone() const
{
	return nullptr;
}

String Object_wx_NonOwnedWindow::ToString(bool exprFlag)
{
	String rtn("<wx.NonOwnedWindow:");
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
Gura_DeclareMethod(wx_NonOwnedWindow, SetShape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NonOwnedWindow, SetShape)
{
	Signal &sig = env.GetSignal();
	Object_wx_NonOwnedWindow *pThis = Object_wx_NonOwnedWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->SetShape();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NonOwnedWindow, SetShape_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NonOwnedWindow, SetShape_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_NonOwnedWindow *pThis = Object_wx_NonOwnedWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetShape();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNonOwnedWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NonOwnedWindow)
{
	Gura_AssignMethod(wx_NonOwnedWindow, SetShape);
	Gura_AssignMethod(wx_NonOwnedWindow, SetShape_1);
}

Gura_ImplementDescendantCreator(wx_NonOwnedWindow)
{
	return new Object_wx_NonOwnedWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
