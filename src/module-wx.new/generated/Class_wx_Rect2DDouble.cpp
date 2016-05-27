//----------------------------------------------------------------------------
// wxRect2DDouble
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRect2DDouble
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRect2DDouble
//----------------------------------------------------------------------------
Object_wx_Rect2DDouble::~Object_wx_Rect2DDouble()
{
}

Object *Object_wx_Rect2DDouble::Clone() const
{
	return nullptr;
}

String Object_wx_Rect2DDouble::ToString(bool exprFlag)
{
	String rtn("<wx.Rect2DDouble:");
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
// Class implementation for wxRect2DDouble
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect2DDouble)
{
}

Gura_ImplementDescendantCreator(wx_Rect2DDouble)
{
	return new Object_wx_Rect2DDouble((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
