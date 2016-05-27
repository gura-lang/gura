//----------------------------------------------------------------------------
// wxPathList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPathList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPathList
//----------------------------------------------------------------------------
Object_wx_PathList::~Object_wx_PathList()
{
}

Object *Object_wx_PathList::Clone() const
{
	return nullptr;
}

String Object_wx_PathList::ToString(bool exprFlag)
{
	String rtn("<wx.PathList:");
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
// Class implementation for wxPathList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PathList)
{
}

Gura_ImplementDescendantCreator(wx_PathList)
{
	return new Object_wx_PathList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
