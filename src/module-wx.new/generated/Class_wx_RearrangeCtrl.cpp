//----------------------------------------------------------------------------
// wxRearrangeCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRearrangeCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRearrangeCtrl
//----------------------------------------------------------------------------
Object_wx_RearrangeCtrl::~Object_wx_RearrangeCtrl()
{
}

Object *Object_wx_RearrangeCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_RearrangeCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.RearrangeCtrl:");
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
// Class implementation for wxRearrangeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeCtrl)
{
}

Gura_ImplementDescendantCreator(wx_RearrangeCtrl)
{
	return new Object_wx_RearrangeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
