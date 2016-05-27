//----------------------------------------------------------------------------
// wxSocketClient
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketClient
//----------------------------------------------------------------------------
Object_wx_SocketClient::~Object_wx_SocketClient()
{
}

Object *Object_wx_SocketClient::Clone() const
{
	return nullptr;
}

String Object_wx_SocketClient::ToString(bool exprFlag)
{
	String rtn("<wx.SocketClient:");
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
// Class implementation for wxSocketClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketClient)
{
}

Gura_ImplementDescendantCreator(wx_SocketClient)
{
	return new Object_wx_SocketClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
