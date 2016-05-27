//----------------------------------------------------------------------------
// wxEventBlocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventBlocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEventBlocker
//----------------------------------------------------------------------------
Object_wx_EventBlocker::~Object_wx_EventBlocker()
{
}

Object *Object_wx_EventBlocker::Clone() const
{
	return nullptr;
}

String Object_wx_EventBlocker::ToString(bool exprFlag)
{
	String rtn("<wx.EventBlocker:");
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
// Class implementation for wxEventBlocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventBlocker)
{
}

Gura_ImplementDescendantCreator(wx_EventBlocker)
{
	return new Object_wx_EventBlocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
