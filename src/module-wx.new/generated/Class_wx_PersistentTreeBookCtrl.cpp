//----------------------------------------------------------------------------
// wxPersistentTreeBookCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistentTreeBookCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistentTreeBookCtrl
//----------------------------------------------------------------------------
Object_wx_PersistentTreeBookCtrl::~Object_wx_PersistentTreeBookCtrl()
{
}

Object *Object_wx_PersistentTreeBookCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_PersistentTreeBookCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.PersistentTreeBookCtrl:");
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
// Class implementation for wxPersistentTreeBookCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentTreeBookCtrl)
{
}

Gura_ImplementDescendantCreator(wx_PersistentTreeBookCtrl)
{
	return new Object_wx_PersistentTreeBookCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
