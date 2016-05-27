//----------------------------------------------------------------------------
// wxGridCellEnumRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellEnumRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellEnumRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellEnumRenderer::~Object_wx_GridCellEnumRenderer()
{
}

Object *Object_wx_GridCellEnumRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellEnumRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellEnumRenderer:");
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
// Class implementation for wxGridCellEnumRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellEnumRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridCellEnumRenderer)
{
	return new Object_wx_GridCellEnumRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
