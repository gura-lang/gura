//----------------------------------------------------------------------------
// wxGridCellBoolRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellBoolRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellBoolRenderer::~Object_wx_GridCellBoolRenderer()
{
}

Object *Object_wx_GridCellBoolRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellBoolRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellBoolRenderer:");
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
// Class implementation for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellBoolRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridCellBoolRenderer)
{
	return new Object_wx_GridCellBoolRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
