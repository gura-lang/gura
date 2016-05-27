//----------------------------------------------------------------------------
// wxApp
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxApp
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxApp
//----------------------------------------------------------------------------
Object_wx_App::~Object_wx_App()
{
}

Object *Object_wx_App::Clone() const
{
	return nullptr;
}

String Object_wx_App::ToString(bool exprFlag)
{
	String rtn("<wx.App:");
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
// Class implementation for wxApp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_App)
{
}

Gura_ImplementDescendantCreator(wx_App)
{
	return new Object_wx_App((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
