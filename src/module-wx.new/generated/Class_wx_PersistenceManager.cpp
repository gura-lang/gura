//----------------------------------------------------------------------------
// wxPersistenceManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistenceManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistenceManager
//----------------------------------------------------------------------------
Object_wx_PersistenceManager::~Object_wx_PersistenceManager()
{
}

Object *Object_wx_PersistenceManager::Clone() const
{
	return nullptr;
}

String Object_wx_PersistenceManager::ToString(bool exprFlag)
{
	String rtn("<wx.PersistenceManager:");
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
// Class implementation for wxPersistenceManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistenceManager)
{
}

Gura_ImplementDescendantCreator(wx_PersistenceManager)
{
	return new Object_wx_PersistenceManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
