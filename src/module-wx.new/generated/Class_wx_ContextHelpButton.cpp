//----------------------------------------------------------------------------
// wxContextHelpButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxContextHelpButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxContextHelpButton
//----------------------------------------------------------------------------
Object_wx_ContextHelpButton::~Object_wx_ContextHelpButton()
{
}

Object *Object_wx_ContextHelpButton::Clone() const
{
	return nullptr;
}

String Object_wx_ContextHelpButton::ToString(bool exprFlag)
{
	String rtn("<wx.ContextHelpButton:");
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
// Class implementation for wxContextHelpButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextHelpButton)
{
}

Gura_ImplementDescendantCreator(wx_ContextHelpButton)
{
	return new Object_wx_ContextHelpButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
