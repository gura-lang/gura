//----------------------------------------------------------------------------
// wxPropertyGridManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridManager
//----------------------------------------------------------------------------
Object_wx_PropertyGridManager::~Object_wx_PropertyGridManager()
{
}

Object *Object_wx_PropertyGridManager::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridManager::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridManager:");
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
// Class implementation for wxPropertyGridManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridManager)
{
}

Gura_ImplementDescendantCreator(wx_PropertyGridManager)
{
	return new Object_wx_PropertyGridManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
