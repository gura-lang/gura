//----------------------------------------------------------------------------
// wxGraphicsBitmap
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsBitmap
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsBitmap
//----------------------------------------------------------------------------
Object_wx_GraphicsBitmap::~Object_wx_GraphicsBitmap()
{
}

Object *Object_wx_GraphicsBitmap::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsBitmap::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsBitmap:");
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
// Class implementation for wxGraphicsBitmap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsBitmap)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsBitmap)
{
	return new Object_wx_GraphicsBitmap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
