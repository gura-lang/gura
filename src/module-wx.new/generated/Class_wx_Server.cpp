//----------------------------------------------------------------------------
// wxServer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxServer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxServer
//----------------------------------------------------------------------------
Object_wx_Server::~Object_wx_Server()
{
}

Object *Object_wx_Server::Clone() const
{
	return nullptr;
}

String Object_wx_Server::ToString(bool exprFlag)
{
	String rtn("<wx.Server:");
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
// Class implementation for wxServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Server)
{
}

Gura_ImplementDescendantCreator(wx_Server)
{
	return new Object_wx_Server((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
