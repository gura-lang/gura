//----------------------------------------------------------------------------
// wxHelpProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpProvider
//----------------------------------------------------------------------------
Object_wx_HelpProvider::~Object_wx_HelpProvider()
{
}

Object *Object_wx_HelpProvider::Clone() const
{
	return nullptr;
}

String Object_wx_HelpProvider::ToString(bool exprFlag)
{
	String rtn("<wx.HelpProvider:");
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
// Class implementation for wxHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpProvider)
{
}

Gura_ImplementDescendantCreator(wx_HelpProvider)
{
	return new Object_wx_HelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
