//----------------------------------------------------------------------------
// wxDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataObject
//----------------------------------------------------------------------------
Object_wx_DataObject::~Object_wx_DataObject()
{
}

Object *Object_wx_DataObject::Clone() const
{
	return nullptr;
}

String Object_wx_DataObject::ToString(bool exprFlag)
{
	String rtn("<wx.DataObject:");
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
// Class implementation for wxDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObject)
{
	
}

Gura_ImplementDescendantCreator(wx_DataObject)
{
	return new Object_wx_DataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
