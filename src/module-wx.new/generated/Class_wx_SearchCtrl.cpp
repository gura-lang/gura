//----------------------------------------------------------------------------
// wxSearchCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSearchCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSearchCtrl
//----------------------------------------------------------------------------
Object_wx_SearchCtrl::~Object_wx_SearchCtrl()
{
}

Object *Object_wx_SearchCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_SearchCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.SearchCtrl:");
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
// Class implementation for wxSearchCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SearchCtrl)
{
}

Gura_ImplementDescendantCreator(wx_SearchCtrl)
{
	return new Object_wx_SearchCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
