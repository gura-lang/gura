//----------------------------------------------------------------------------
// wxGridUpdateLocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridUpdateLocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridUpdateLocker
//----------------------------------------------------------------------------
Object_wx_GridUpdateLocker::~Object_wx_GridUpdateLocker()
{
}

Object *Object_wx_GridUpdateLocker::Clone() const
{
	return nullptr;
}

String Object_wx_GridUpdateLocker::ToString(bool exprFlag)
{
	String rtn("<wx.GridUpdateLocker:");
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
// Class implementation for wxGridUpdateLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridUpdateLocker)
{
}

Gura_ImplementDescendantCreator(wx_GridUpdateLocker)
{
	return new Object_wx_GridUpdateLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
