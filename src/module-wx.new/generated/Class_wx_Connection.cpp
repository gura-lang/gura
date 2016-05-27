//----------------------------------------------------------------------------
// wxConnection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConnection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConnection
//----------------------------------------------------------------------------
Object_wx_Connection::~Object_wx_Connection()
{
}

Object *Object_wx_Connection::Clone() const
{
	return nullptr;
}

String Object_wx_Connection::ToString(bool exprFlag)
{
	String rtn("<wx.Connection:");
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
// Class implementation for wxConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Connection)
{
}

Gura_ImplementDescendantCreator(wx_Connection)
{
	return new Object_wx_Connection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
