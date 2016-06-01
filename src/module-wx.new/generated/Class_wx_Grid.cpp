//----------------------------------------------------------------------------
// wxGrid
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGrid
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGrid
//----------------------------------------------------------------------------
Object_wx_Grid::~Object_wx_Grid()
{
}

Object *Object_wx_Grid::Clone() const
{
	return nullptr;
}

String Object_wx_Grid::ToString(bool exprFlag)
{
	String rtn("<wx.Grid:");
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
// Class implementation for wxGrid
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Grid)
{
	
}

Gura_ImplementDescendantCreator(wx_Grid)
{
	return new Object_wx_Grid((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
