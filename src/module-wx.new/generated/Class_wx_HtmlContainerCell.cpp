//----------------------------------------------------------------------------
// wxHtmlContainerCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlContainerCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlContainerCell
//----------------------------------------------------------------------------
Object_wx_HtmlContainerCell::~Object_wx_HtmlContainerCell()
{
}

Object *Object_wx_HtmlContainerCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlContainerCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlContainerCell:");
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
// Class implementation for wxHtmlContainerCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlContainerCell)
{
}

Gura_ImplementDescendantCreator(wx_HtmlContainerCell)
{
	return new Object_wx_HtmlContainerCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
