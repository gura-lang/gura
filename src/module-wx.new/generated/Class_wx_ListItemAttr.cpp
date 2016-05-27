//----------------------------------------------------------------------------
// wxListItemAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListItemAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListItemAttr
//----------------------------------------------------------------------------
Object_wx_ListItemAttr::~Object_wx_ListItemAttr()
{
}

Object *Object_wx_ListItemAttr::Clone() const
{
	return nullptr;
}

String Object_wx_ListItemAttr::ToString(bool exprFlag)
{
	String rtn("<wx.ListItemAttr:");
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
// Class implementation for wxListItemAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListItemAttr)
{
}

Gura_ImplementDescendantCreator(wx_ListItemAttr)
{
	return new Object_wx_ListItemAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
