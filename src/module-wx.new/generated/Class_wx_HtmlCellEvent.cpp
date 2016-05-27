//----------------------------------------------------------------------------
// wxHtmlCellEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlCellEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlCellEvent
//----------------------------------------------------------------------------
Object_wx_HtmlCellEvent::~Object_wx_HtmlCellEvent()
{
}

Object *Object_wx_HtmlCellEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlCellEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlCellEvent:");
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
// Class implementation for wxHtmlCellEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlCellEvent)
{
}

Gura_ImplementDescendantCreator(wx_HtmlCellEvent)
{
	return new Object_wx_HtmlCellEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
