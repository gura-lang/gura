//----------------------------------------------------------------------------
// wxAutomationObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAutomationObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAutomationObject
//----------------------------------------------------------------------------
Object_wx_AutomationObject::~Object_wx_AutomationObject()
{
}

Object *Object_wx_AutomationObject::Clone() const
{
	return nullptr;
}

String Object_wx_AutomationObject::ToString(bool exprFlag)
{
	String rtn("<wx.AutomationObject:");
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
// Class implementation for wxAutomationObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AutomationObject)
{
}

Gura_ImplementDescendantCreator(wx_AutomationObject)
{
	return new Object_wx_AutomationObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
