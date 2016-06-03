//----------------------------------------------------------------------------
// wxGraphicsBrush
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsBrush
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsBrush
//----------------------------------------------------------------------------
Object_wx_GraphicsBrush::~Object_wx_GraphicsBrush()
{
}

Object *Object_wx_GraphicsBrush::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsBrush::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsBrush:");
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
// Class implementation for wxGraphicsBrush
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsBrush)
{
	// Class assignment
	Gura_AssignValueEx("GraphicsBrush", Reference());
}

Gura_ImplementDescendantCreator(wx_GraphicsBrush)
{
	return new Object_wx_GraphicsBrush((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
