//----------------------------------------------------------------------------
// wxAuiTabContainerButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiTabContainerButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiTabContainerButton
//----------------------------------------------------------------------------
Object_wx_AuiTabContainerButton::~Object_wx_AuiTabContainerButton()
{
}

Object *Object_wx_AuiTabContainerButton::Clone() const
{
	return nullptr;
}

String Object_wx_AuiTabContainerButton::ToString(bool exprFlag)
{
	String rtn("<wx.AuiTabContainerButton:");
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
// Class implementation for wxAuiTabContainerButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiTabContainerButton)
{
	// Class assignment
	Gura_AssignValueEx("AuiTabContainerButton", Reference());
}

Gura_ImplementDescendantCreator(wx_AuiTabContainerButton)
{
	return new Object_wx_AuiTabContainerButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
