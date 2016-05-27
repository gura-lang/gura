//----------------------------------------------------------------------------
// wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellDateTimeRenderer::~Object_wx_GridCellDateTimeRenderer()
{
}

Object *Object_wx_GridCellDateTimeRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellDateTimeRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellDateTimeRenderer:");
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
// Class implementation for wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellDateTimeRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridCellDateTimeRenderer)
{
	return new Object_wx_GridCellDateTimeRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
