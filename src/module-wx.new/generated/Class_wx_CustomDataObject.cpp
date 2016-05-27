//----------------------------------------------------------------------------
// wxCustomDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCustomDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCustomDataObject
//----------------------------------------------------------------------------
Object_wx_CustomDataObject::~Object_wx_CustomDataObject()
{
}

Object *Object_wx_CustomDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_CustomDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.CustomDataObject:");
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
// Class implementation for wxCustomDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CustomDataObject)
{
}

Gura_ImplementDescendantCreator(wx_CustomDataObject)
{
	return new Object_wx_CustomDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
