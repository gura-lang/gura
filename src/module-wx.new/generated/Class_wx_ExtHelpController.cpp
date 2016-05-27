//----------------------------------------------------------------------------
// wxExtHelpController
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxExtHelpController
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxExtHelpController
//----------------------------------------------------------------------------
Object_wx_ExtHelpController::~Object_wx_ExtHelpController()
{
}

Object *Object_wx_ExtHelpController::Clone() const
{
	return nullptr;
}

String Object_wx_ExtHelpController::ToString(bool exprFlag)
{
	String rtn("<wx.ExtHelpController:");
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
// Class implementation for wxExtHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ExtHelpController)
{
}

Gura_ImplementDescendantCreator(wx_ExtHelpController)
{
	return new Object_wx_ExtHelpController((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
