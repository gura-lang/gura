//----------------------------------------------------------------------------
// wxHeaderCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderCtrl
//----------------------------------------------------------------------------
Object_wx_HeaderCtrl::~Object_wx_HeaderCtrl()
{
}

Object *Object_wx_HeaderCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderCtrl:");
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
// Class implementation for wxHeaderCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrl)
{
}

Gura_ImplementDescendantCreator(wx_HeaderCtrl)
{
	return new Object_wx_HeaderCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
