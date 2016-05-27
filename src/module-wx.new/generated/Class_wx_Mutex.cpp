//----------------------------------------------------------------------------
// wxMutex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMutex
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMutex
//----------------------------------------------------------------------------
Object_wx_Mutex::~Object_wx_Mutex()
{
}

Object *Object_wx_Mutex::Clone() const
{
	return nullptr;
}

String Object_wx_Mutex::ToString(bool exprFlag)
{
	String rtn("<wx.Mutex:");
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
// Class implementation for wxMutex
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Mutex)
{
}

Gura_ImplementDescendantCreator(wx_Mutex)
{
	return new Object_wx_Mutex((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
