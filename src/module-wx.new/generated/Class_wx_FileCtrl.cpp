//----------------------------------------------------------------------------
// wxFileCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileCtrl
//----------------------------------------------------------------------------
Object_wx_FileCtrl::~Object_wx_FileCtrl()
{
}

Object *Object_wx_FileCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FileCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FileCtrl:");
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
// Class implementation for wxFileCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileCtrl)
{
}

Gura_ImplementDescendantCreator(wx_FileCtrl)
{
	return new Object_wx_FileCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
