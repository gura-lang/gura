//----------------------------------------------------------------------------
// wxDialUpManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialUpManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDialUpManager
//----------------------------------------------------------------------------
Object_wx_DialUpManager::~Object_wx_DialUpManager()
{
}

Object *Object_wx_DialUpManager::Clone() const
{
	return nullptr;
}

String Object_wx_DialUpManager::ToString(bool exprFlag)
{
	String rtn("<wx.DialUpManager:");
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
// Class implementation for wxDialUpManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpManager)
{
}

Gura_ImplementDescendantCreator(wx_DialUpManager)
{
	return new Object_wx_DialUpManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
