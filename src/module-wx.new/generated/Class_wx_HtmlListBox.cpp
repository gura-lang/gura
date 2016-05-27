//----------------------------------------------------------------------------
// wxHtmlListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlListBox
//----------------------------------------------------------------------------
Object_wx_HtmlListBox::~Object_wx_HtmlListBox()
{
}

Object *Object_wx_HtmlListBox::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlListBox::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlListBox:");
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
// Class implementation for wxHtmlListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlListBox)
{
}

Gura_ImplementDescendantCreator(wx_HtmlListBox)
{
	return new Object_wx_HtmlListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
