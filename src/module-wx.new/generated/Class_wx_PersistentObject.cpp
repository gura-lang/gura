//----------------------------------------------------------------------------
// wxPersistentObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistentObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistentObject
//----------------------------------------------------------------------------
Object_wx_PersistentObject::~Object_wx_PersistentObject()
{
}

Object *Object_wx_PersistentObject::Clone() const
{
	return nullptr;
}

String Object_wx_PersistentObject::ToString(bool exprFlag)
{
	String rtn("<wx.PersistentObject:");
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
// Class implementation for wxPersistentObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentObject)
{
}

Gura_ImplementDescendantCreator(wx_PersistentObject)
{
	return new Object_wx_PersistentObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
