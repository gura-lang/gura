//----------------------------------------------------------------------------
// wxTreebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreebook
//----------------------------------------------------------------------------
Object_wx_Treebook::~Object_wx_Treebook()
{
}

Object *Object_wx_Treebook::Clone() const
{
	return nullptr;
}

String Object_wx_Treebook::ToString(bool exprFlag)
{
	String rtn("<wx.Treebook:");
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
// Class implementation for wxTreebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Treebook)
{
}

Gura_ImplementDescendantCreator(wx_Treebook)
{
	return new Object_wx_Treebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
