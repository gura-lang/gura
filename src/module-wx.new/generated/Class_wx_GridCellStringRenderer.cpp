//----------------------------------------------------------------------------
// wxGridCellStringRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellStringRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellStringRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellStringRenderer::~Object_wx_GridCellStringRenderer()
{
}

Object *Object_wx_GridCellStringRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellStringRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellStringRenderer:");
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
// Class implementation for wxGridCellStringRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellStringRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridCellStringRenderer)
{
	return new Object_wx_GridCellStringRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
