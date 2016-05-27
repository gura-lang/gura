//----------------------------------------------------------------------------
// wxMouseEventsManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseEventsManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseEventsManager
//----------------------------------------------------------------------------
Object_wx_MouseEventsManager::~Object_wx_MouseEventsManager()
{
}

Object *Object_wx_MouseEventsManager::Clone() const
{
	return nullptr;
}

String Object_wx_MouseEventsManager::ToString(bool exprFlag)
{
	String rtn("<wx.MouseEventsManager:");
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
// Class implementation for wxMouseEventsManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseEventsManager)
{
}

Gura_ImplementDescendantCreator(wx_MouseEventsManager)
{
	return new Object_wx_MouseEventsManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
