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
Gura_DeclareMethodAlias(wx_NonOwnedWindow, __SetShape, "SetShape")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NonOwnedWindow, __SetShape)
{
	Object_wx_NonOwnedWindow *pThis = Object_wx_NonOwnedWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->SetShape();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NonOwnedWindow, __SetShape_1, "SetShape_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NonOwnedWindow, __SetShape_1)
{
	Object_wx_NonOwnedWindow *pThis = Object_wx_NonOwnedWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGraphicsPath& path = arg.GetNumber(0)
	//pThis->GetEntity()->SetShape();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNonOwnedWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NonOwnedWindow)
{
	// Class assignment
	Gura_AssignValueEx("NonOwnedWindow", Reference());
	// Method assignment
	Gura_AssignMethod(wx_NonOwnedWindow, __SetShape);
	Gura_AssignMethod(wx_NonOwnedWindow, __SetShape_1);
}

Gura_ImplementDescendantCreator(wx_NonOwnedWindow)
{
	return new Object_wx_NonOwnedWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
