//----------------------------------------------------------------------------
// wxGridCellAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAttr
//----------------------------------------------------------------------------
Object_wx_GridCellAttr::~Object_wx_GridCellAttr()
{
}

Object *Object_wx_GridCellAttr::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAttr::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAttr:");
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
// Class implementation for wxGridCellAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAttr)
{
}

Gura_ImplementDescendantCreator(wx_GridCellAttr)
{
	return new Object_wx_GridCellAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
