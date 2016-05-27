//----------------------------------------------------------------------------
// wxRealPoint
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRealPoint
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRealPoint
//----------------------------------------------------------------------------
Object_wx_RealPoint::~Object_wx_RealPoint()
{
}

Object *Object_wx_RealPoint::Clone() const
{
	return nullptr;
}

String Object_wx_RealPoint::ToString(bool exprFlag)
{
	String rtn("<wx.RealPoint:");
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
// Class implementation for wxRealPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RealPoint)
{
}

Gura_ImplementDescendantCreator(wx_RealPoint)
{
	return new Object_wx_RealPoint((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
