//----------------------------------------------------------------------------
// wxWindowModalDialogEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowModalDialogEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowModalDialogEvent
//----------------------------------------------------------------------------
Object_wx_WindowModalDialogEvent::~Object_wx_WindowModalDialogEvent()
{
}

Object *Object_wx_WindowModalDialogEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WindowModalDialogEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WindowModalDialogEvent:");
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
// Class implementation for wxWindowModalDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowModalDialogEvent)
{
}

Gura_ImplementDescendantCreator(wx_WindowModalDialogEvent)
{
	return new Object_wx_WindowModalDialogEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
