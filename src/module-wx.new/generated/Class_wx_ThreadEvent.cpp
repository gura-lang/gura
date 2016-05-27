//----------------------------------------------------------------------------
// wxThreadEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxThreadEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxThreadEvent
//----------------------------------------------------------------------------
Object_wx_ThreadEvent::~Object_wx_ThreadEvent()
{
}

Object *Object_wx_ThreadEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ThreadEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ThreadEvent:");
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
// Class implementation for wxThreadEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThreadEvent)
{
}

Gura_ImplementDescendantCreator(wx_ThreadEvent)
{
	return new Object_wx_ThreadEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
