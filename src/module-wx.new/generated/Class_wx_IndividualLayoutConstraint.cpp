//----------------------------------------------------------------------------
// wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Object_wx_IndividualLayoutConstraint::~Object_wx_IndividualLayoutConstraint()
{
}

Object *Object_wx_IndividualLayoutConstraint::Clone() const
{
	return nullptr;
}

String Object_wx_IndividualLayoutConstraint::ToString(bool exprFlag)
{
	String rtn("<wx.IndividualLayoutConstraint:");
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
// Class implementation for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IndividualLayoutConstraint)
{
}

Gura_ImplementDescendantCreator(wx_IndividualLayoutConstraint)
{
	return new Object_wx_IndividualLayoutConstraint((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
