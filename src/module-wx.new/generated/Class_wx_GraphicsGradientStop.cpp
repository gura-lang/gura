//----------------------------------------------------------------------------
// wxGraphicsGradientStop
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsGradientStop
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsGradientStop
//----------------------------------------------------------------------------
Object_wx_GraphicsGradientStop::~Object_wx_GraphicsGradientStop()
{
}

Object *Object_wx_GraphicsGradientStop::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsGradientStop::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsGradientStop:");
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
// Class implementation for wxGraphicsGradientStop
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsGradientStop)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsGradientStop)
{
	return new Object_wx_GraphicsGradientStop((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
