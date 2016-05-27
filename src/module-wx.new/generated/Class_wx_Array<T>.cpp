//----------------------------------------------------------------------------
// wxArray<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArray<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArray<T>
//----------------------------------------------------------------------------
Object_wx_Array<T>::~Object_wx_Array<T>()
{
}

Object *Object_wx_Array<T>::Clone() const
{
	return nullptr;
}

String Object_wx_Array<T>::ToString(bool exprFlag)
{
	String rtn("<wx.Array<T>:");
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
// Class implementation for wxArray<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Array<T>)
{
}

Gura_ImplementDescendantCreator(wx_Array<T>)
{
	return new Object_wx_Array<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
