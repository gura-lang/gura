//----------------------------------------------------------------------------
// wxGridCellAttrProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAttrProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Object_wx_GridCellAttrProvider::~Object_wx_GridCellAttrProvider()
{
}

Object *Object_wx_GridCellAttrProvider::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAttrProvider::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAttrProvider:");
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
// Class implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAttrProvider)
{
}

Gura_ImplementDescendantCreator(wx_GridCellAttrProvider)
{
	return new Object_wx_GridCellAttrProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
