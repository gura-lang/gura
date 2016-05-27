//----------------------------------------------------------------------------
// wxGraphicsGradientStops
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsGradientStops
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsGradientStops
//----------------------------------------------------------------------------
Object_wx_GraphicsGradientStops::~Object_wx_GraphicsGradientStops()
{
}

Object *Object_wx_GraphicsGradientStops::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsGradientStops::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsGradientStops:");
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
// Class implementation for wxGraphicsGradientStops
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsGradientStops)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsGradientStops)
{
	return new Object_wx_GraphicsGradientStops((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
