//----------------------------------------------------------------------------
// wxSharedPtr<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSharedPtr<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSharedPtr<T>
//----------------------------------------------------------------------------
Object_wx_SharedPtr<T>::~Object_wx_SharedPtr<T>()
{
}

Object *Object_wx_SharedPtr<T>::Clone() const
{
	return nullptr;
}

String Object_wx_SharedPtr<T>::ToString(bool exprFlag)
{
	String rtn("<wx.SharedPtr<T>:");
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
// Class implementation for wxSharedPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SharedPtr<T>)
{
}

Gura_ImplementDescendantCreator(wx_SharedPtr<T>)
{
	return new Object_wx_SharedPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
