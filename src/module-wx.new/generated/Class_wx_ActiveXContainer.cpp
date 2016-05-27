//----------------------------------------------------------------------------
// wxActiveXContainer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxActiveXContainer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Object_wx_ActiveXContainer::~Object_wx_ActiveXContainer()
{
}

Object *Object_wx_ActiveXContainer::Clone() const
{
	return nullptr;
}

String Object_wx_ActiveXContainer::ToString(bool exprFlag)
{
	String rtn("<wx.ActiveXContainer:");
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
// Class implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActiveXContainer)
{
}

Gura_ImplementDescendantCreator(wx_ActiveXContainer)
{
	return new Object_wx_ActiveXContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
