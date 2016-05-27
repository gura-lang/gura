//----------------------------------------------------------------------------
// wxRegConfig
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRegConfig
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRegConfig
//----------------------------------------------------------------------------
Object_wx_RegConfig::~Object_wx_RegConfig()
{
}

Object *Object_wx_RegConfig::Clone() const
{
	return nullptr;
}

String Object_wx_RegConfig::ToString(bool exprFlag)
{
	String rtn("<wx.RegConfig:");
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
// Class implementation for wxRegConfig
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegConfig)
{
}

Gura_ImplementDescendantCreator(wx_RegConfig)
{
	return new Object_wx_RegConfig((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
