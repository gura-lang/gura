//----------------------------------------------------------------------------
// wxChoice
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxChoice
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxChoice
//----------------------------------------------------------------------------
Object_wx_Choice::~Object_wx_Choice()
{
}

Object *Object_wx_Choice::Clone() const
{
	return nullptr;
}

String Object_wx_Choice::ToString(bool exprFlag)
{
	String rtn("<wx.Choice:");
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
// Class implementation for wxChoice
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Choice)
{
}

Gura_ImplementDescendantCreator(wx_Choice)
{
	return new Object_wx_Choice((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
