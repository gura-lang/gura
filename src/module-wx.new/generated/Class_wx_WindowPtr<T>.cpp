//----------------------------------------------------------------------------
// wxWindowPtr<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowPtr<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowPtr<T>
//----------------------------------------------------------------------------
Object_wx_WindowPtr<T>::~Object_wx_WindowPtr<T>()
{
}

Object *Object_wx_WindowPtr<T>::Clone() const
{
	return nullptr;
}

String Object_wx_WindowPtr<T>::ToString(bool exprFlag)
{
	String rtn("<wx.WindowPtr<T>:");
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
// Method implementation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Class implementation for wxWindowPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowPtr<T>)
{
}

Gura_ImplementDescendantCreator(wx_WindowPtr<T>)
{
	return new Object_wx_WindowPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
