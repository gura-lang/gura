//----------------------------------------------------------------------------
// wxObjectDataPtr<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxObjectDataPtr<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxObjectDataPtr<T>
//----------------------------------------------------------------------------
Object_wx_ObjectDataPtr<T>::~Object_wx_ObjectDataPtr<T>()
{
}

Object *Object_wx_ObjectDataPtr<T>::Clone() const
{
	return nullptr;
}

String Object_wx_ObjectDataPtr<T>::ToString(bool exprFlag)
{
	String rtn("<wx.ObjectDataPtr<T>:");
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
// Class implementation for wxObjectDataPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ObjectDataPtr<T>)
{
}

Gura_ImplementDescendantCreator(wx_ObjectDataPtr<T>)
{
	return new Object_wx_ObjectDataPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
