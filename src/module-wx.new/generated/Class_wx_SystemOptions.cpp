//----------------------------------------------------------------------------
// wxSystemOptions
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemOptions
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSystemOptions
//----------------------------------------------------------------------------
Object_wx_SystemOptions::~Object_wx_SystemOptions()
{
}

Object *Object_wx_SystemOptions::Clone() const
{
	return nullptr;
}

String Object_wx_SystemOptions::ToString(bool exprFlag)
{
	String rtn("<wx.SystemOptions:");
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
// Class implementation for wxSystemOptions
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemOptions)
{
}

Gura_ImplementDescendantCreator(wx_SystemOptions)
{
	return new Object_wx_SystemOptions((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
