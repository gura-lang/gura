//----------------------------------------------------------------------------
// wxStyledTextCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStyledTextCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStyledTextCtrl
//----------------------------------------------------------------------------
Object_wx_StyledTextCtrl::~Object_wx_StyledTextCtrl()
{
}

Object *Object_wx_StyledTextCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_StyledTextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.StyledTextCtrl:");
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
// Class implementation for wxStyledTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StyledTextCtrl)
{
}

Gura_ImplementDescendantCreator(wx_StyledTextCtrl)
{
	return new Object_wx_StyledTextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
