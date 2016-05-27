//----------------------------------------------------------------------------
// wxRichTextEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextEvent
//----------------------------------------------------------------------------
Object_wx_RichTextEvent::~Object_wx_RichTextEvent()
{
}

Object *Object_wx_RichTextEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextEvent:");
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
// Class implementation for wxRichTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextEvent)
{
}

Gura_ImplementDescendantCreator(wx_RichTextEvent)
{
	return new Object_wx_RichTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
