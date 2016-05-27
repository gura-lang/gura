//----------------------------------------------------------------------------
// wxXmlResource
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlResource
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlResource
//----------------------------------------------------------------------------
Object_wx_XmlResource::~Object_wx_XmlResource()
{
}

Object *Object_wx_XmlResource::Clone() const
{
	return nullptr;
}

String Object_wx_XmlResource::ToString(bool exprFlag)
{
	String rtn("<wx.XmlResource:");
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
// Class implementation for wxXmlResource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlResource)
{
}

Gura_ImplementDescendantCreator(wx_XmlResource)
{
	return new Object_wx_XmlResource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
