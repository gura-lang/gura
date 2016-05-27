//----------------------------------------------------------------------------
// wxMessageQueue<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageQueue<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageQueue<T>
//----------------------------------------------------------------------------
Object_wx_MessageQueue<T>::~Object_wx_MessageQueue<T>()
{
}

Object *Object_wx_MessageQueue<T>::Clone() const
{
	return nullptr;
}

String Object_wx_MessageQueue<T>::ToString(bool exprFlag)
{
	String rtn("<wx.MessageQueue<T>:");
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
// Class implementation for wxMessageQueue<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageQueue<T>)
{
}

Gura_ImplementDescendantCreator(wx_MessageQueue<T>)
{
	return new Object_wx_MessageQueue<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
