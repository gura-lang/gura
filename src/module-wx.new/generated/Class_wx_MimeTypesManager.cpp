//----------------------------------------------------------------------------
// wxMimeTypesManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMimeTypesManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Object_wx_MimeTypesManager::~Object_wx_MimeTypesManager()
{
}

Object *Object_wx_MimeTypesManager::Clone() const
{
	return nullptr;
}

String Object_wx_MimeTypesManager::ToString(bool exprFlag)
{
	String rtn("<wx.MimeTypesManager:");
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
// Class implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MimeTypesManager)
{
}

Gura_ImplementDescendantCreator(wx_MimeTypesManager)
{
	return new Object_wx_MimeTypesManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
