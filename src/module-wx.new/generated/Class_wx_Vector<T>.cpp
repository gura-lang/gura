//----------------------------------------------------------------------------
// wxVector<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVector<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVector<T>
//----------------------------------------------------------------------------
Object_wx_Vector<T>::~Object_wx_Vector<T>()
{
}

Object *Object_wx_Vector<T>::Clone() const
{
	return nullptr;
}

String Object_wx_Vector<T>::ToString(bool exprFlag)
{
	String rtn("<wx.Vector<T>:");
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
// Class implementation for wxVector<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Vector<T>)
{
}

Gura_ImplementDescendantCreator(wx_Vector<T>)
{
	return new Object_wx_Vector<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
