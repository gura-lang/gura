//----------------------------------------------------------------------------
// wxMediaCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMediaCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMediaCtrl
//----------------------------------------------------------------------------
Object_wx_MediaCtrl::~Object_wx_MediaCtrl()
{
}

Object *Object_wx_MediaCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_MediaCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.MediaCtrl:");
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
// Class implementation for wxMediaCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MediaCtrl)
{
}

Gura_ImplementDescendantCreator(wx_MediaCtrl)
{
	return new Object_wx_MediaCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
