//----------------------------------------------------------------------------
// wxLog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLog
//----------------------------------------------------------------------------
Object_wx_Log::~Object_wx_Log()
{
}

Object *Object_wx_Log::Clone() const
{
	return nullptr;
}

String Object_wx_Log::ToString(bool exprFlag)
{
	String rtn("<wx.Log:");
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
// Class implementation for wxLog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Log)
{
}

Gura_ImplementDescendantCreator(wx_Log)
{
	return new Object_wx_Log((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
