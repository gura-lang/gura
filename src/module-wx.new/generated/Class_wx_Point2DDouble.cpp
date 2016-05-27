//----------------------------------------------------------------------------
// wxPoint2DDouble
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPoint2DDouble
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPoint2DDouble
//----------------------------------------------------------------------------
Object_wx_Point2DDouble::~Object_wx_Point2DDouble()
{
}

Object *Object_wx_Point2DDouble::Clone() const
{
	return nullptr;
}

String Object_wx_Point2DDouble::ToString(bool exprFlag)
{
	String rtn("<wx.Point2DDouble:");
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
// Class implementation for wxPoint2DDouble
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point2DDouble)
{
}

Gura_ImplementDescendantCreator(wx_Point2DDouble)
{
	return new Object_wx_Point2DDouble((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
