//----------------------------------------------------------------------------
// wxGridCellNumberRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellNumberRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellNumberRenderer::~Object_wx_GridCellNumberRenderer()
{
}

Object *Object_wx_GridCellNumberRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellNumberRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellNumberRenderer:");
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
// Class implementation for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellNumberRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridCellNumberRenderer)
{
	return new Object_wx_GridCellNumberRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
