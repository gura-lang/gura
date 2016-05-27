//----------------------------------------------------------------------------
// wxCommandLinkButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommandLinkButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCommandLinkButton
//----------------------------------------------------------------------------
Object_wx_CommandLinkButton::~Object_wx_CommandLinkButton()
{
}

Object *Object_wx_CommandLinkButton::Clone() const
{
	return nullptr;
}

String Object_wx_CommandLinkButton::ToString(bool exprFlag)
{
	String rtn("<wx.CommandLinkButton:");
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
// Class implementation for wxCommandLinkButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandLinkButton)
{
}

Gura_ImplementDescendantCreator(wx_CommandLinkButton)
{
	return new Object_wx_CommandLinkButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
