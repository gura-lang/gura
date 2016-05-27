//----------------------------------------------------------------------------
// wxMediaEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMediaEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMediaEvent
//----------------------------------------------------------------------------
Object_wx_MediaEvent::~Object_wx_MediaEvent()
{
}

Object *Object_wx_MediaEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MediaEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MediaEvent:");
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
// Class implementation for wxMediaEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MediaEvent)
{
}

Gura_ImplementDescendantCreator(wx_MediaEvent)
{
	return new Object_wx_MediaEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
