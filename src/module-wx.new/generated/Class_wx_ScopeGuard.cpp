//----------------------------------------------------------------------------
// wxScopeGuard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopeGuard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopeGuard
//----------------------------------------------------------------------------
Object_wx_ScopeGuard::~Object_wx_ScopeGuard()
{
}

Object *Object_wx_ScopeGuard::Clone() const
{
	return nullptr;
}

String Object_wx_ScopeGuard::ToString(bool exprFlag)
{
	String rtn("<wx.ScopeGuard:");
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
// Class implementation for wxScopeGuard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopeGuard)
{
}

Gura_ImplementDescendantCreator(wx_ScopeGuard)
{
	return new Object_wx_ScopeGuard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
