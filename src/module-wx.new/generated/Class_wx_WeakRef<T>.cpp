//----------------------------------------------------------------------------
// wxWeakRef<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWeakRef<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWeakRef<T>
//----------------------------------------------------------------------------
Object_wx_WeakRef<T>::~Object_wx_WeakRef<T>()
{
}

Object *Object_wx_WeakRef<T>::Clone() const
{
	return nullptr;
}

String Object_wx_WeakRef<T>::ToString(bool exprFlag)
{
	String rtn("<wx.WeakRef<T>:");
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
// Class implementation for wxWeakRef<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WeakRef<T>)
{
}

Gura_ImplementDescendantCreator(wx_WeakRef<T>)
{
	return new Object_wx_WeakRef<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
