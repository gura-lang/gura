//----------------------------------------------------------------------------
// wxHtmlHelpFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Object_wx_HtmlHelpFrame::~Object_wx_HtmlHelpFrame()
{
}

Object *Object_wx_HtmlHelpFrame::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpFrame::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpFrame:");
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
// Class implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpFrame)
{
}

Gura_ImplementDescendantCreator(wx_HtmlHelpFrame)
{
	return new Object_wx_HtmlHelpFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
