//----------------------------------------------------------------------------
// wxEventLoopActivator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventLoopActivator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEventLoopActivator
//----------------------------------------------------------------------------
Object_wx_EventLoopActivator::~Object_wx_EventLoopActivator()
{
}

Object *Object_wx_EventLoopActivator::Clone() const
{
	return nullptr;
}

String Object_wx_EventLoopActivator::ToString(bool exprFlag)
{
	String rtn("<wx.EventLoopActivator:");
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
// Class implementation for wxEventLoopActivator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventLoopActivator)
{
}

Gura_ImplementDescendantCreator(wx_EventLoopActivator)
{
	return new Object_wx_EventLoopActivator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
