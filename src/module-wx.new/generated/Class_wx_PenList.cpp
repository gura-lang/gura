//----------------------------------------------------------------------------
// wxPenList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPenList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPenList
//----------------------------------------------------------------------------
Object_wx_PenList::~Object_wx_PenList()
{
}

Object *Object_wx_PenList::Clone() const
{
	return nullptr;
}

String Object_wx_PenList::ToString(bool exprFlag)
{
	String rtn("<wx.PenList:");
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
// Class implementation for wxPenList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PenList)
{
}

Gura_ImplementDescendantCreator(wx_PenList)
{
	return new Object_wx_PenList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
