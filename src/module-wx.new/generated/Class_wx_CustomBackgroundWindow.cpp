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

//----------------------------------------------------------------------------
// Class implementation for wxCustomBackgroundWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CustomBackgroundWindow)
{
}

Gura_ImplementDescendantCreator(wx_CustomBackgroundWindow)
{
	return new Object_wx_CustomBackgroundWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
