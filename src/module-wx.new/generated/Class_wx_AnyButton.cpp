//----------------------------------------------------------------------------
// wxAnyButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnyButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnyButton
//----------------------------------------------------------------------------
Object_wx_AnyButton::~Object_wx_AnyButton()
{
}

Object *Object_wx_AnyButton::Clone() const
{
	return nullptr;
}

String Object_wx_AnyButton::ToString(bool exprFlag)
{
	String rtn("<wx.AnyButton:");
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
// Class implementation for wxAnyButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnyButton)
{
}

Gura_ImplementDescendantCreator(wx_AnyButton)
{
	return new Object_wx_AnyButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
