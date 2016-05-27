//----------------------------------------------------------------------------
// wxEventLoopBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventLoopBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEventLoopBase
//----------------------------------------------------------------------------
Object_wx_EventLoopBase::~Object_wx_EventLoopBase()
{
}

Object *Object_wx_EventLoopBase::Clone() const
{
	return nullptr;
}

String Object_wx_EventLoopBase::ToString(bool exprFlag)
{
	String rtn("<wx.EventLoopBase:");
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
// Class implementation for wxEventLoopBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventLoopBase)
{
}

Gura_ImplementDescendantCreator(wx_EventLoopBase)
{
	return new Object_wx_EventLoopBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
