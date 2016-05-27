//----------------------------------------------------------------------------
// wxTimer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimer
//----------------------------------------------------------------------------
Object_wx_Timer::~Object_wx_Timer()
{
}

Object *Object_wx_Timer::Clone() const
{
	return nullptr;
}

String Object_wx_Timer::ToString(bool exprFlag)
{
	String rtn("<wx.Timer:");
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
// Class implementation for wxTimer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Timer)
{
}

Gura_ImplementDescendantCreator(wx_Timer)
{
	return new Object_wx_Timer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
