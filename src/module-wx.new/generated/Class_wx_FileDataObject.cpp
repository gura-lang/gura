//----------------------------------------------------------------------------
// wxFileDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileDataObject
//----------------------------------------------------------------------------
Object_wx_FileDataObject::~Object_wx_FileDataObject()
{
}

Object *Object_wx_FileDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_FileDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.FileDataObject:");
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
// Class implementation for wxFileDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDataObject)
{
}

Gura_ImplementDescendantCreator(wx_FileDataObject)
{
	return new Object_wx_FileDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
