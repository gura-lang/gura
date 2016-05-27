//----------------------------------------------------------------------------
// wxIdManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIdManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIdManager
//----------------------------------------------------------------------------
Object_wx_IdManager::~Object_wx_IdManager()
{
}

Object *Object_wx_IdManager::Clone() const
{
	return nullptr;
}

String Object_wx_IdManager::ToString(bool exprFlag)
{
	String rtn("<wx.IdManager:");
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
// Class implementation for wxIdManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IdManager)
{
}

Gura_ImplementDescendantCreator(wx_IdManager)
{
	return new Object_wx_IdManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
