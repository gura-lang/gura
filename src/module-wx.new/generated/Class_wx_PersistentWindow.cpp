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
// Class implementation for wxPersistentWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentWindow)
{
}

Gura_ImplementDescendantCreator(wx_PersistentWindow)
{
	return new Object_wx_PersistentWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
