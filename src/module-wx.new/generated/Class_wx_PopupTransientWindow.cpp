//----------------------------------------------------------------------------
// wxPopupTransientWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPopupTransientWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPopupTransientWindow
//----------------------------------------------------------------------------
Object_wx_PopupTransientWindow::~Object_wx_PopupTransientWindow()
{
}

Object *Object_wx_PopupTransientWindow::Clone() const
{
	return nullptr;
}

String Object_wx_PopupTransientWindow::ToString(bool exprFlag)
{
	String rtn("<wx.PopupTransientWindow:");
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
// Class implementation for wxPopupTransientWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PopupTransientWindow)
{
}

Gura_ImplementDescendantCreator(wx_PopupTransientWindow)
{
	return new Object_wx_PopupTransientWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
