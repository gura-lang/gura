//----------------------------------------------------------------------------
// wxScopedTiedPtr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedTiedPtr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Object_wx_ScopedTiedPtr::~Object_wx_ScopedTiedPtr()
{
}

Object *Object_wx_ScopedTiedPtr::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedTiedPtr::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedTiedPtr:");
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
// Class implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedTiedPtr)
{
}

Gura_ImplementDescendantCreator(wx_ScopedTiedPtr)
{
	return new Object_wx_ScopedTiedPtr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
