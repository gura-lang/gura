//----------------------------------------------------------------------------
// wxTCPClient
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTCPClient
//----------------------------------------------------------------------------
Object_wx_TCPClient::~Object_wx_TCPClient()
{
}

Object *Object_wx_TCPClient::Clone() const
{
	return nullptr;
}

String Object_wx_TCPClient::ToString(bool exprFlag)
{
	String rtn("<wx.TCPClient:");
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
// Class implementation for wxTCPClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPClient)
{
}

Gura_ImplementDescendantCreator(wx_TCPClient)
{
	return new Object_wx_TCPClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
