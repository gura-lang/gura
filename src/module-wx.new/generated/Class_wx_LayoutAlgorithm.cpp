//----------------------------------------------------------------------------
// wxLayoutAlgorithm
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLayoutAlgorithm
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Object_wx_LayoutAlgorithm::~Object_wx_LayoutAlgorithm()
{
}

Object *Object_wx_LayoutAlgorithm::Clone() const
{
	return nullptr;
}

String Object_wx_LayoutAlgorithm::ToString(bool exprFlag)
{
	String rtn("<wx.LayoutAlgorithm:");
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
// Class implementation for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LayoutAlgorithm)
{
}

Gura_ImplementDescendantCreator(wx_LayoutAlgorithm)
{
	return new Object_wx_LayoutAlgorithm((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
