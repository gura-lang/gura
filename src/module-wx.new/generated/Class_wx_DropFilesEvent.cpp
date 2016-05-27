//----------------------------------------------------------------------------
// wxDropFilesEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDropFilesEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDropFilesEvent
//----------------------------------------------------------------------------
Object_wx_DropFilesEvent::~Object_wx_DropFilesEvent()
{
}

Object *Object_wx_DropFilesEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DropFilesEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DropFilesEvent:");
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
// Class implementation for wxDropFilesEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropFilesEvent)
{
}

Gura_ImplementDescendantCreator(wx_DropFilesEvent)
{
	return new Object_wx_DropFilesEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
