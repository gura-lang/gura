//----------------------------------------------------------------------------
// wxDatagramSocket
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDatagramSocket
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDatagramSocket
//----------------------------------------------------------------------------
Object_wx_DatagramSocket::~Object_wx_DatagramSocket()
{
}

Object *Object_wx_DatagramSocket::Clone() const
{
	return nullptr;
}

String Object_wx_DatagramSocket::ToString(bool exprFlag)
{
	String rtn("<wx.DatagramSocket:");
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
// Class implementation for wxDatagramSocket
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DatagramSocket)
{
}

Gura_ImplementDescendantCreator(wx_DatagramSocket)
{
	return new Object_wx_DatagramSocket((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
