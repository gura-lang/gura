//----------------------------------------------------------------------------
// wxGridCellCoords
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellCoords
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Object_wx_GridCellCoords::~Object_wx_GridCellCoords()
{
}

Object *Object_wx_GridCellCoords::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellCoords::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellCoords:");
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
// Class implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellCoords)
{
}

Gura_ImplementDescendantCreator(wx_GridCellCoords)
{
	return new Object_wx_GridCellCoords((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
