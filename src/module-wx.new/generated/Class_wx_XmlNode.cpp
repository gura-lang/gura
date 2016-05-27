//----------------------------------------------------------------------------
// wxXmlNode
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlNode
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlNode
//----------------------------------------------------------------------------
Object_wx_XmlNode::~Object_wx_XmlNode()
{
}

Object *Object_wx_XmlNode::Clone() const
{
	return nullptr;
}

String Object_wx_XmlNode::ToString(bool exprFlag)
{
	String rtn("<wx.XmlNode:");
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
// Class implementation for wxXmlNode
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlNode)
{
}

Gura_ImplementDescendantCreator(wx_XmlNode)
{
	return new Object_wx_XmlNode((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
