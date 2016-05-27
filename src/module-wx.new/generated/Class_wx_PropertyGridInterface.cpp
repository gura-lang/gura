//----------------------------------------------------------------------------
// wxPropertyGridInterface
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridInterface
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridInterface
//----------------------------------------------------------------------------
Object_wx_PropertyGridInterface::~Object_wx_PropertyGridInterface()
{
}

Object *Object_wx_PropertyGridInterface::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridInterface::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridInterface:");
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
// Class implementation for wxPropertyGridInterface
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridInterface)
{
}

Gura_ImplementDescendantCreator(wx_PropertyGridInterface)
{
	return new Object_wx_PropertyGridInterface((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
