//----------------------------------------------------------------------------
// wxClient
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClient
//----------------------------------------------------------------------------
Object_wx_Client::~Object_wx_Client()
{
}

Object *Object_wx_Client::Clone() const
{
	return nullptr;
}

String Object_wx_Client::ToString(bool exprFlag)
{
	String rtn("<wx.Client:");
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
// Class implementation for wxClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Client)
{
}

Gura_ImplementDescendantCreator(wx_Client)
{
	return new Object_wx_Client((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
