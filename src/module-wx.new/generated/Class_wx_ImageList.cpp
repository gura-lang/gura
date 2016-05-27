//----------------------------------------------------------------------------
// wxImageList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxImageList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxImageList
//----------------------------------------------------------------------------
Object_wx_ImageList::~Object_wx_ImageList()
{
}

Object *Object_wx_ImageList::Clone() const
{
	return nullptr;
}

String Object_wx_ImageList::ToString(bool exprFlag)
{
	String rtn("<wx.ImageList:");
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
// Class implementation for wxImageList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ImageList)
{
}

Gura_ImplementDescendantCreator(wx_ImageList)
{
	return new Object_wx_ImageList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
