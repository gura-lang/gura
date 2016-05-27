//----------------------------------------------------------------------------
// wxSimplebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSimplebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSimplebook
//----------------------------------------------------------------------------
Object_wx_Simplebook::~Object_wx_Simplebook()
{
}

Object *Object_wx_Simplebook::Clone() const
{
	return nullptr;
}

String Object_wx_Simplebook::ToString(bool exprFlag)
{
	String rtn("<wx.Simplebook:");
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
// Class implementation for wxSimplebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Simplebook)
{
}

Gura_ImplementDescendantCreator(wx_Simplebook)
{
	return new Object_wx_Simplebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
