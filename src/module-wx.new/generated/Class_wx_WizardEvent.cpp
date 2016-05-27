//----------------------------------------------------------------------------
// wxWizardEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWizardEvent
//----------------------------------------------------------------------------
Object_wx_WizardEvent::~Object_wx_WizardEvent()
{
}

Object *Object_wx_WizardEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WizardEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WizardEvent:");
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
// Class implementation for wxWizardEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardEvent)
{
}

Gura_ImplementDescendantCreator(wx_WizardEvent)
{
	return new Object_wx_WizardEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
