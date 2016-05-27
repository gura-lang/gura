//----------------------------------------------------------------------------
// wxHTMLDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHTMLDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHTMLDataObject
//----------------------------------------------------------------------------
Object_wx_HTMLDataObject::~Object_wx_HTMLDataObject()
{
}

Object *Object_wx_HTMLDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_HTMLDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.HTMLDataObject:");
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
// Class implementation for wxHTMLDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HTMLDataObject)
{
}

Gura_ImplementDescendantCreator(wx_HTMLDataObject)
{
	return new Object_wx_HTMLDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
