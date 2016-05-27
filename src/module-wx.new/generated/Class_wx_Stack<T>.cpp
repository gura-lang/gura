//----------------------------------------------------------------------------
// wxStack<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStack<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStack<T>
//----------------------------------------------------------------------------
Object_wx_Stack<T>::~Object_wx_Stack<T>()
{
}

Object *Object_wx_Stack<T>::Clone() const
{
	return nullptr;
}

String Object_wx_Stack<T>::ToString(bool exprFlag)
{
	String rtn("<wx.Stack<T>:");
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
// Class implementation for wxStack<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Stack<T>)
{
}

Gura_ImplementDescendantCreator(wx_Stack<T>)
{
	return new Object_wx_Stack<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
