//----------------------------------------------------------------------------
// wxMutexLocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMutexLocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMutexLocker
//----------------------------------------------------------------------------
Object_wx_MutexLocker::~Object_wx_MutexLocker()
{
}

Object *Object_wx_MutexLocker::Clone() const
{
	return nullptr;
}

String Object_wx_MutexLocker::ToString(bool exprFlag)
{
	String rtn("<wx.MutexLocker:");
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
// Class implementation for wxMutexLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MutexLocker)
{
}

Gura_ImplementDescendantCreator(wx_MutexLocker)
{
	return new Object_wx_MutexLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
