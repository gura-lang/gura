//----------------------------------------------------------------------------
// wxScopedPtr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedPtr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedPtr
//----------------------------------------------------------------------------
Object_wx_ScopedPtr::~Object_wx_ScopedPtr()
{
}

Object *Object_wx_ScopedPtr::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedPtr::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedPtr:");
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
// Class implementation for wxScopedPtr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedPtr)
{
}

Gura_ImplementDescendantCreator(wx_ScopedPtr)
{
	return new Object_wx_ScopedPtr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
