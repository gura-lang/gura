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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__CustomBackgroundWindow, "CustomBackgroundWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CustomBackgroundWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CustomBackgroundWindow)
{
	//wxCustomBackgroundWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CustomBackgroundWindow, __SetBackgroundBitmap, "SetBackgroundBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomBackgroundWindow, __SetBackgroundBitmap)
{
	Object_wx_CustomBackgroundWindow *pThis = Object_wx_CustomBackgroundWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundBitmap(bmp);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCustomBackgroundWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CustomBackgroundWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__CustomBackgroundWindow);
	// Method assignment
	Gura_AssignMethod(wx_CustomBackgroundWindow, __SetBackgroundBitmap);
}

Gura_ImplementDescendantCreator(wx_CustomBackgroundWindow)
{
	return new Object_wx_CustomBackgroundWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
