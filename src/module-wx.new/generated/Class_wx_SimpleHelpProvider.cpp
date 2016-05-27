//----------------------------------------------------------------------------
// wxSimpleHelpProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSimpleHelpProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSimpleHelpProvider
//----------------------------------------------------------------------------
Object_wx_SimpleHelpProvider::~Object_wx_SimpleHelpProvider()
{
}

Object *Object_wx_SimpleHelpProvider::Clone() const
{
	return nullptr;
}

String Object_wx_SimpleHelpProvider::ToString(bool exprFlag)
{
	String rtn("<wx.SimpleHelpProvider:");
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
// Class implementation for wxSimpleHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SimpleHelpProvider)
{
}

Gura_ImplementDescendantCreator(wx_SimpleHelpProvider)
{
	return new Object_wx_SimpleHelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
