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
// Class implementation for wxMDIClientWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIClientWindow)
{
}

Gura_ImplementDescendantCreator(wx_MDIClientWindow)
{
	return new Object_wx_MDIClientWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
