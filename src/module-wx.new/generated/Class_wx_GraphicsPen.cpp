//----------------------------------------------------------------------------
// wxGraphicsPen
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsPen
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsPen
//----------------------------------------------------------------------------
Object_wx_GraphicsPen::~Object_wx_GraphicsPen()
{
}

Object *Object_wx_GraphicsPen::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsPen::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsPen:");
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
// Class implementation for wxGraphicsPen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsPen)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsPen)
{
	return new Object_wx_GraphicsPen((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
