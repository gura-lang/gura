//----------------------------------------------------------------------------
// wxConnectionBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConnectionBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConnectionBase
//----------------------------------------------------------------------------
Object_wx_ConnectionBase::~Object_wx_ConnectionBase()
{
}

Object *Object_wx_ConnectionBase::Clone() const
{
	return nullptr;
}

String Object_wx_ConnectionBase::ToString(bool exprFlag)
{
	String rtn("<wx.ConnectionBase:");
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
// Class implementation for wxConnectionBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConnectionBase)
{
}

Gura_ImplementDescendantCreator(wx_ConnectionBase)
{
	return new Object_wx_ConnectionBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
