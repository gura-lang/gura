//----------------------------------------------------------------------------
// wxScopedPtr<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedPtr<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedPtr<T>
//----------------------------------------------------------------------------
Object_wx_ScopedPtr<T>::~Object_wx_ScopedPtr<T>()
{
}

Object *Object_wx_ScopedPtr<T>::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedPtr<T>::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedPtr<T>:");
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
// Class implementation for wxScopedPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedPtr<T>)
{
}

Gura_ImplementDescendantCreator(wx_ScopedPtr<T>)
{
	return new Object_wx_ScopedPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
