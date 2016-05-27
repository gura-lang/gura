//----------------------------------------------------------------------------
// wxRegKey
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRegKey
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRegKey
//----------------------------------------------------------------------------
Object_wx_RegKey::~Object_wx_RegKey()
{
}

Object *Object_wx_RegKey::Clone() const
{
	return nullptr;
}

String Object_wx_RegKey::ToString(bool exprFlag)
{
	String rtn("<wx.RegKey:");
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
// Class implementation for wxRegKey
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegKey)
{
}

Gura_ImplementDescendantCreator(wx_RegKey)
{
	return new Object_wx_RegKey((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
