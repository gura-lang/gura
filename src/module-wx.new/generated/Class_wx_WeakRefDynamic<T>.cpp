//----------------------------------------------------------------------------
// wxWeakRefDynamic<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWeakRefDynamic<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWeakRefDynamic<T>
//----------------------------------------------------------------------------
Object_wx_WeakRefDynamic<T>::~Object_wx_WeakRefDynamic<T>()
{
}

Object *Object_wx_WeakRefDynamic<T>::Clone() const
{
	return nullptr;
}

String Object_wx_WeakRefDynamic<T>::ToString(bool exprFlag)
{
	String rtn("<wx.WeakRefDynamic<T>:");
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
// Class implementation for wxWeakRefDynamic<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WeakRefDynamic<T>)
{
}

Gura_ImplementDescendantCreator(wx_WeakRefDynamic<T>)
{
	return new Object_wx_WeakRefDynamic<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
