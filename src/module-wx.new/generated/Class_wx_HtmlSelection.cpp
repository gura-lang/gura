//----------------------------------------------------------------------------
// wxHtmlSelection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlSelection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlSelection
//----------------------------------------------------------------------------
Object_wx_HtmlSelection::~Object_wx_HtmlSelection()
{
}

Object *Object_wx_HtmlSelection::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlSelection::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlSelection:");
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
// Class implementation for wxHtmlSelection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlSelection)
{
}

Gura_ImplementDescendantCreator(wx_HtmlSelection)
{
	return new Object_wx_HtmlSelection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
