//----------------------------------------------------------------------------
// wxGridSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridSizer
//----------------------------------------------------------------------------
Object_wx_GridSizer::~Object_wx_GridSizer()
{
}

Object *Object_wx_GridSizer::Clone() const
{
	return nullptr;
}

String Object_wx_GridSizer::ToString(bool exprFlag)
{
	String rtn("<wx.GridSizer:");
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
// Class implementation for wxGridSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizer)
{
}

Gura_ImplementDescendantCreator(wx_GridSizer)
{
	return new Object_wx_GridSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
