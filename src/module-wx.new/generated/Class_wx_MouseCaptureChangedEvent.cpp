//----------------------------------------------------------------------------
// wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Object_wx_MouseCaptureChangedEvent::~Object_wx_MouseCaptureChangedEvent()
{
}

Object *Object_wx_MouseCaptureChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MouseCaptureChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MouseCaptureChangedEvent:");
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
// Class implementation for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseCaptureChangedEvent)
{
}

Gura_ImplementDescendantCreator(wx_MouseCaptureChangedEvent)
{
	return new Object_wx_MouseCaptureChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
