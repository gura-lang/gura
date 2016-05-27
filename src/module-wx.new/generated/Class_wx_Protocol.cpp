//----------------------------------------------------------------------------
// wxProtocol
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProtocol
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProtocol
//----------------------------------------------------------------------------
Object_wx_Protocol::~Object_wx_Protocol()
{
}

Object *Object_wx_Protocol::Clone() const
{
	return nullptr;
}

String Object_wx_Protocol::ToString(bool exprFlag)
{
	String rtn("<wx.Protocol:");
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
// Class implementation for wxProtocol
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Protocol)
{
}

Gura_ImplementDescendantCreator(wx_Protocol)
{
	return new Object_wx_Protocol((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
