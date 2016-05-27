//----------------------------------------------------------------------------
// wxPersistentBookCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistentBookCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistentBookCtrl
//----------------------------------------------------------------------------
Object_wx_PersistentBookCtrl::~Object_wx_PersistentBookCtrl()
{
}

Object *Object_wx_PersistentBookCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_PersistentBookCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.PersistentBookCtrl:");
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
// Class implementation for wxPersistentBookCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentBookCtrl)
{
}

Gura_ImplementDescendantCreator(wx_PersistentBookCtrl)
{
	return new Object_wx_PersistentBookCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
