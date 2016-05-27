//----------------------------------------------------------------------------
// wxSocketEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketEvent
//----------------------------------------------------------------------------
Object_wx_SocketEvent::~Object_wx_SocketEvent()
{
}

Object *Object_wx_SocketEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SocketEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SocketEvent:");
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
// Class implementation for wxSocketEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketEvent)
{
}

Gura_ImplementDescendantCreator(wx_SocketEvent)
{
	return new Object_wx_SocketEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
