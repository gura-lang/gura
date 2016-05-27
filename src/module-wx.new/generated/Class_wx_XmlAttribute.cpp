//----------------------------------------------------------------------------
// wxXmlAttribute
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlAttribute
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlAttribute
//----------------------------------------------------------------------------
Object_wx_XmlAttribute::~Object_wx_XmlAttribute()
{
}

Object *Object_wx_XmlAttribute::Clone() const
{
	return nullptr;
}

String Object_wx_XmlAttribute::ToString(bool exprFlag)
{
	String rtn("<wx.XmlAttribute:");
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
// Class implementation for wxXmlAttribute
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlAttribute)
{
}

Gura_ImplementDescendantCreator(wx_XmlAttribute)
{
	return new Object_wx_XmlAttribute((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
