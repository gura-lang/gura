//----------------------------------------------------------------------------
// wxPropagationDisabler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropagationDisabler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropagationDisabler
//----------------------------------------------------------------------------
Object_wx_PropagationDisabler::~Object_wx_PropagationDisabler()
{
}

Object *Object_wx_PropagationDisabler::Clone() const
{
	return nullptr;
}

String Object_wx_PropagationDisabler::ToString(bool exprFlag)
{
	String rtn("<wx.PropagationDisabler:");
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
// Class implementation for wxPropagationDisabler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropagationDisabler)
{
}

Gura_ImplementDescendantCreator(wx_PropagationDisabler)
{
	return new Object_wx_PropagationDisabler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
