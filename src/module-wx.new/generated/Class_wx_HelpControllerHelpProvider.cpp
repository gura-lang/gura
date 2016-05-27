//----------------------------------------------------------------------------
// wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Object_wx_HelpControllerHelpProvider::~Object_wx_HelpControllerHelpProvider()
{
}

Object *Object_wx_HelpControllerHelpProvider::Clone() const
{
	return nullptr;
}

String Object_wx_HelpControllerHelpProvider::ToString(bool exprFlag)
{
	String rtn("<wx.HelpControllerHelpProvider:");
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
// Class implementation for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpControllerHelpProvider)
{
}

Gura_ImplementDescendantCreator(wx_HelpControllerHelpProvider)
{
	return new Object_wx_HelpControllerHelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
