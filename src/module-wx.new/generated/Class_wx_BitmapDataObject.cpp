//----------------------------------------------------------------------------
// wxBitmapDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapDataObject
//----------------------------------------------------------------------------
Object_wx_BitmapDataObject::~Object_wx_BitmapDataObject()
{
}

Object *Object_wx_BitmapDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapDataObject:");
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
// Class implementation for wxBitmapDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapDataObject)
{
}

Gura_ImplementDescendantCreator(wx_BitmapDataObject)
{
	return new Object_wx_BitmapDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
