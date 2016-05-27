//----------------------------------------------------------------------------
// wxPropertyGrid
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGrid
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGrid
//----------------------------------------------------------------------------
Object_wx_PropertyGrid::~Object_wx_PropertyGrid()
{
}

Object *Object_wx_PropertyGrid::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGrid::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGrid:");
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
// Class implementation for wxPropertyGrid
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGrid)
{
}

Gura_ImplementDescendantCreator(wx_PropertyGrid)
{
	return new Object_wx_PropertyGrid((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
