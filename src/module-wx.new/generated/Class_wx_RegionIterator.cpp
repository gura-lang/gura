//----------------------------------------------------------------------------
// wxRegionIterator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRegionIterator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRegionIterator
//----------------------------------------------------------------------------
Object_wx_RegionIterator::~Object_wx_RegionIterator()
{
}

Object *Object_wx_RegionIterator::Clone() const
{
	return nullptr;
}

String Object_wx_RegionIterator::ToString(bool exprFlag)
{
	String rtn("<wx.RegionIterator:");
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
// Class implementation for wxRegionIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegionIterator)
{
}

Gura_ImplementDescendantCreator(wx_RegionIterator)
{
	return new Object_wx_RegionIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
