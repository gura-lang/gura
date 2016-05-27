//----------------------------------------------------------------------------
// wxFileCtrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileCtrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileCtrlEvent
//----------------------------------------------------------------------------
Object_wx_FileCtrlEvent::~Object_wx_FileCtrlEvent()
{
}

Object *Object_wx_FileCtrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FileCtrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FileCtrlEvent:");
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
// Class implementation for wxFileCtrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileCtrlEvent)
{
}

Gura_ImplementDescendantCreator(wx_FileCtrlEvent)
{
	return new Object_wx_FileCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
