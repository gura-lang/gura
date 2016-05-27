//----------------------------------------------------------------------------
// wxPoint
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPoint
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPoint
//----------------------------------------------------------------------------
Object_wx_Point::~Object_wx_Point()
{
}

Object *Object_wx_Point::Clone() const
{
	return nullptr;
}

String Object_wx_Point::ToString(bool exprFlag)
{
	String rtn("<wx.Point:");
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
// Class implementation for wxPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point)
{
}

Gura_ImplementDescendantCreator(wx_Point)
{
	return new Object_wx_Point((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
