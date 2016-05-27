//----------------------------------------------------------------------------
// wxRearrangeList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRearrangeList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRearrangeList
//----------------------------------------------------------------------------
Object_wx_RearrangeList::~Object_wx_RearrangeList()
{
}

Object *Object_wx_RearrangeList::Clone() const
{
	return nullptr;
}

String Object_wx_RearrangeList::ToString(bool exprFlag)
{
	String rtn("<wx.RearrangeList:");
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
// Class implementation for wxRearrangeList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeList)
{
}

Gura_ImplementDescendantCreator(wx_RearrangeList)
{
	return new Object_wx_RearrangeList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
