//----------------------------------------------------------------------------
// wxCondition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCondition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCondition
//----------------------------------------------------------------------------
Object_wx_Condition::~Object_wx_Condition()
{
}

Object *Object_wx_Condition::Clone() const
{
	return nullptr;
}

String Object_wx_Condition::ToString(bool exprFlag)
{
	String rtn("<wx.Condition:");
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
// Class implementation for wxCondition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Condition)
{
}

Gura_ImplementDescendantCreator(wx_Condition)
{
	return new Object_wx_Condition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
