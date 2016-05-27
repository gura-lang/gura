//----------------------------------------------------------------------------
// wxHelpControllerBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpControllerBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpControllerBase
//----------------------------------------------------------------------------
Object_wx_HelpControllerBase::~Object_wx_HelpControllerBase()
{
}

Object *Object_wx_HelpControllerBase::Clone() const
{
	return nullptr;
}

String Object_wx_HelpControllerBase::ToString(bool exprFlag)
{
	String rtn("<wx.HelpControllerBase:");
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
// Class implementation for wxHelpControllerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpControllerBase)
{
}

Gura_ImplementDescendantCreator(wx_HelpControllerBase)
{
	return new Object_wx_HelpControllerBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
