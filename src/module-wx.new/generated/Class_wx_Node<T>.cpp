//----------------------------------------------------------------------------
// wxNode<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNode<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNode<T>
//----------------------------------------------------------------------------
Object_wx_Node<T>::~Object_wx_Node<T>()
{
}

Object *Object_wx_Node<T>::Clone() const
{
	return nullptr;
}

String Object_wx_Node<T>::ToString(bool exprFlag)
{
	String rtn("<wx.Node<T>:");
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
// Class implementation for wxNode<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Node<T>)
{
}

Gura_ImplementDescendantCreator(wx_Node<T>)
{
	return new Object_wx_Node<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
