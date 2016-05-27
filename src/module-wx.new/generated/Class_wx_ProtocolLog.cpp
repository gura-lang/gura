//----------------------------------------------------------------------------
// wxProtocolLog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProtocolLog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProtocolLog
//----------------------------------------------------------------------------
Object_wx_ProtocolLog::~Object_wx_ProtocolLog()
{
}

Object *Object_wx_ProtocolLog::Clone() const
{
	return nullptr;
}

String Object_wx_ProtocolLog::ToString(bool exprFlag)
{
	String rtn("<wx.ProtocolLog:");
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
// Class implementation for wxProtocolLog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProtocolLog)
{
}

Gura_ImplementDescendantCreator(wx_ProtocolLog)
{
	return new Object_wx_ProtocolLog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
