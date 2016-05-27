//----------------------------------------------------------------------------
// wxDDEServer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEServer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDDEServer
//----------------------------------------------------------------------------
Object_wx_DDEServer::~Object_wx_DDEServer()
{
}

Object *Object_wx_DDEServer::Clone() const
{
	return nullptr;
}

String Object_wx_DDEServer::ToString(bool exprFlag)
{
	String rtn("<wx.DDEServer:");
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
// Class implementation for wxDDEServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEServer)
{
}

Gura_ImplementDescendantCreator(wx_DDEServer)
{
	return new Object_wx_DDEServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
