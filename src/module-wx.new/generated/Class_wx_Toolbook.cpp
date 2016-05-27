//----------------------------------------------------------------------------
// wxToolbook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToolbook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolbook
//----------------------------------------------------------------------------
Object_wx_Toolbook::~Object_wx_Toolbook()
{
}

Object *Object_wx_Toolbook::Clone() const
{
	return nullptr;
}

String Object_wx_Toolbook::ToString(bool exprFlag)
{
	String rtn("<wx.Toolbook:");
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
// Class implementation for wxToolbook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Toolbook)
{
}

Gura_ImplementDescendantCreator(wx_Toolbook)
{
	return new Object_wx_Toolbook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
