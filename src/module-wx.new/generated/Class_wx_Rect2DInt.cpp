//----------------------------------------------------------------------------
// wxRect2DInt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRect2DInt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRect2DInt
//----------------------------------------------------------------------------
Object_wx_Rect2DInt::~Object_wx_Rect2DInt()
{
}

Object *Object_wx_Rect2DInt::Clone() const
{
	return nullptr;
}

String Object_wx_Rect2DInt::ToString(bool exprFlag)
{
	String rtn("<wx.Rect2DInt:");
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
// Class implementation for wxRect2DInt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect2DInt)
{
}

Gura_ImplementDescendantCreator(wx_Rect2DInt)
{
	return new Object_wx_Rect2DInt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
