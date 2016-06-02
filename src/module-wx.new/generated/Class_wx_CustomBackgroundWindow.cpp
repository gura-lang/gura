//----------------------------------------------------------------------------
// wxCustomBackgroundWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCustomBackgroundWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCustomBackgroundWindow
//----------------------------------------------------------------------------
Object_wx_CustomBackgroundWindow::~Object_wx_CustomBackgroundWindow()
{
}

Object *Object_wx_CustomBackgroundWindow::Clone() const
{
	return nullptr;
}

String Object_wx_CustomBackgroundWindow::ToString(bool exprFlag)
{
	String rtn("<wx.CustomBackgroundWindow:");
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
Gura_DeclareMethod(wx_CustomBackgroundWindow, wxCustomBackgroundWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomBackgroundWindow, wxCustomBackgroundWindow)
{
	Object_wx_CustomBackgroundWindow *pThis = Object_wx_CustomBackgroundWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCustomBackgroundWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CustomBackgroundWindow, SetBackgroundBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomBackgroundWindow, SetBackgroundBitmap)
{
	Object_wx_CustomBackgroundWindow *pThis = Object_wx_CustomBackgroundWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCustomBackgroundWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CustomBackgroundWindow)
{
	Gura_AssignMethod(wx_CustomBackgroundWindow, wxCustomBackgroundWindow);
	Gura_AssignMethod(wx_CustomBackgroundWindow, SetBackgroundBitmap);
}

Gura_ImplementDescendantCreator(wx_CustomBackgroundWindow)
{
	return new Object_wx_CustomBackgroundWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
