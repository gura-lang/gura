//----------------------------------------------------------------------------
// wxSemaphore
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSemaphore
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSemaphore
//----------------------------------------------------------------------------
Object_wx_Semaphore::~Object_wx_Semaphore()
{
}

Object *Object_wx_Semaphore::Clone() const
{
	return nullptr;
}

String Object_wx_Semaphore::ToString(bool exprFlag)
{
	String rtn("<wx.Semaphore:");
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
// Class implementation for wxSemaphore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Semaphore)
{
}

Gura_ImplementDescendantCreator(wx_Semaphore)
{
	return new Object_wx_Semaphore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
