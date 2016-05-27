//----------------------------------------------------------------------------
// wxWizard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWizard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWizard
//----------------------------------------------------------------------------
Object_wx_Wizard::~Object_wx_Wizard()
{
}

Object *Object_wx_Wizard::Clone() const
{
	return nullptr;
}

String Object_wx_Wizard::ToString(bool exprFlag)
{
	String rtn("<wx.Wizard:");
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
// Class implementation for wxWizard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Wizard)
{
}

Gura_ImplementDescendantCreator(wx_Wizard)
{
	return new Object_wx_Wizard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
