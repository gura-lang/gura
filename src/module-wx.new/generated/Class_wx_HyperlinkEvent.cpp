//----------------------------------------------------------------------------
// wxHyperlinkEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHyperlinkEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHyperlinkEvent
//----------------------------------------------------------------------------
Object_wx_HyperlinkEvent::~Object_wx_HyperlinkEvent()
{
}

Object *Object_wx_HyperlinkEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HyperlinkEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HyperlinkEvent:");
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
// Class implementation for wxHyperlinkEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HyperlinkEvent)
{
}

Gura_ImplementDescendantCreator(wx_HyperlinkEvent)
{
	return new Object_wx_HyperlinkEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
