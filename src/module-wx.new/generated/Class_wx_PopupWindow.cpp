//----------------------------------------------------------------------------
// wxPopupWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPopupWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPopupWindow
//----------------------------------------------------------------------------
Object_wx_PopupWindow::~Object_wx_PopupWindow()
{
}

Object *Object_wx_PopupWindow::Clone() const
{
	return nullptr;
}

String Object_wx_PopupWindow::ToString(bool exprFlag)
{
	String rtn("<wx.PopupWindow:");
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
// Class implementation for wxPopupWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PopupWindow)
{
}

Gura_ImplementDescendantCreator(wx_PopupWindow)
{
	return new Object_wx_PopupWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
