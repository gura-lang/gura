//----------------------------------------------------------------------------
// wxClipboardTextEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClipboardTextEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClipboardTextEvent
//----------------------------------------------------------------------------
Object_wx_ClipboardTextEvent::~Object_wx_ClipboardTextEvent()
{
}

Object *Object_wx_ClipboardTextEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ClipboardTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ClipboardTextEvent:");
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
// Class implementation for wxClipboardTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClipboardTextEvent)
{
}

Gura_ImplementDescendantCreator(wx_ClipboardTextEvent)
{
	return new Object_wx_ClipboardTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
