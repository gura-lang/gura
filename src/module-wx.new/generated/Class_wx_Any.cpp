//----------------------------------------------------------------------------
// wxAny
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAny
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAny
//----------------------------------------------------------------------------
Object_wx_Any::~Object_wx_Any()
{
}

Object *Object_wx_Any::Clone() const
{
	return nullptr;
}

String Object_wx_Any::ToString(bool exprFlag)
{
	String rtn("<wx.Any:");
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
// Class implementation for wxAny
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Any)
{
}

Gura_ImplementDescendantCreator(wx_Any)
{
	return new Object_wx_Any((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
