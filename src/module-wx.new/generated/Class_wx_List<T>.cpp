//----------------------------------------------------------------------------
// wxList<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxList<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxList<T>
//----------------------------------------------------------------------------
Object_wx_List<T>::~Object_wx_List<T>()
{
}

Object *Object_wx_List<T>::Clone() const
{
	return nullptr;
}

String Object_wx_List<T>::ToString(bool exprFlag)
{
	String rtn("<wx.List<T>:");
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
// Class implementation for wxList<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_List<T>)
{
}

Gura_ImplementDescendantCreator(wx_List<T>)
{
	return new Object_wx_List<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
