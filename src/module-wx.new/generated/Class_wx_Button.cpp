//----------------------------------------------------------------------------
// wxButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxButton
//----------------------------------------------------------------------------
Object_wx_Button::~Object_wx_Button()
{
}

Object *Object_wx_Button::Clone() const
{
	return nullptr;
}

String Object_wx_Button::ToString(bool exprFlag)
{
	String rtn("<wx.Button:");
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
// Class implementation for wxButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Button)
{
}

Gura_ImplementDescendantCreator(wx_Button)
{
	return new Object_wx_Button((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
