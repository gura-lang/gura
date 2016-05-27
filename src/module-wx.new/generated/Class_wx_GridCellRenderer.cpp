//----------------------------------------------------------------------------
// wxGridCellRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellRenderer::~Object_wx_GridCellRenderer()
{
}

Object *Object_wx_GridCellRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellRenderer:");
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
// Class implementation for wxGridCellRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridCellRenderer)
{
	return new Object_wx_GridCellRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
