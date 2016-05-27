//----------------------------------------------------------------------------
// wxHtmlWindowInterface
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWindowInterface
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Object_wx_HtmlWindowInterface::~Object_wx_HtmlWindowInterface()
{
}

Object *Object_wx_HtmlWindowInterface::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWindowInterface::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWindowInterface:");
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
// Class implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindowInterface)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWindowInterface)
{
	return new Object_wx_HtmlWindowInterface((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
