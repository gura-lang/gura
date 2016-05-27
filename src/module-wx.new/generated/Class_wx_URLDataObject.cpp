//----------------------------------------------------------------------------
// wxURLDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxURLDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxURLDataObject
//----------------------------------------------------------------------------
Object_wx_URLDataObject::~Object_wx_URLDataObject()
{
}

Object *Object_wx_URLDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_URLDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.URLDataObject:");
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
// Class implementation for wxURLDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URLDataObject)
{
}

Gura_ImplementDescendantCreator(wx_URLDataObject)
{
	return new Object_wx_URLDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
