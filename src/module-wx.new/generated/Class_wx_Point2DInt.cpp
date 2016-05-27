//----------------------------------------------------------------------------
// wxPoint2DInt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPoint2DInt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPoint2DInt
//----------------------------------------------------------------------------
Object_wx_Point2DInt::~Object_wx_Point2DInt()
{
}

Object *Object_wx_Point2DInt::Clone() const
{
	return nullptr;
}

String Object_wx_Point2DInt::ToString(bool exprFlag)
{
	String rtn("<wx.Point2DInt:");
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
// Class implementation for wxPoint2DInt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point2DInt)
{
}

Gura_ImplementDescendantCreator(wx_Point2DInt)
{
	return new Object_wx_Point2DInt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
