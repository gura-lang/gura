//----------------------------------------------------------------------------
// wxHtmlCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlCell
//----------------------------------------------------------------------------
Object_wx_HtmlCell::~Object_wx_HtmlCell()
{
}

Object *Object_wx_HtmlCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlCell:");
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
// Class implementation for wxHtmlCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlCell)
{
}

Gura_ImplementDescendantCreator(wx_HtmlCell)
{
	return new Object_wx_HtmlCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
