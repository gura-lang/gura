//----------------------------------------------------------------------------
// wxXmlResourceHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlResourceHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlResourceHandler
//----------------------------------------------------------------------------
Object_wx_XmlResourceHandler::~Object_wx_XmlResourceHandler()
{
}

Object *Object_wx_XmlResourceHandler::Clone() const
{
	return nullptr;
}

String Object_wx_XmlResourceHandler::ToString(bool exprFlag)
{
	String rtn("<wx.XmlResourceHandler:");
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
// Class implementation for wxXmlResourceHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlResourceHandler)
{
}

Gura_ImplementDescendantCreator(wx_XmlResourceHandler)
{
	return new Object_wx_XmlResourceHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
