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

//----------------------------------------------------------------------------
// Class implementation for wxNonOwnedWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NonOwnedWindow)
{
}

Gura_ImplementDescendantCreator(wx_NonOwnedWindow)
{
	return new Object_wx_NonOwnedWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
