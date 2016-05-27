//----------------------------------------------------------------------------
// wxXmlDoctype
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlDoctype
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlDoctype
//----------------------------------------------------------------------------
Object_wx_XmlDoctype::~Object_wx_XmlDoctype()
{
}

Object *Object_wx_XmlDoctype::Clone() const
{
	return nullptr;
}

String Object_wx_XmlDoctype::ToString(bool exprFlag)
{
	String rtn("<wx.XmlDoctype:");
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
// Class implementation for wxXmlDoctype
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlDoctype)
{
}

Gura_ImplementDescendantCreator(wx_XmlDoctype)
{
	return new Object_wx_XmlDoctype((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
