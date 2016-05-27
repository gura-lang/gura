//----------------------------------------------------------------------------
// wxURL
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxURL
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxURL
//----------------------------------------------------------------------------
Object_wx_URL::~Object_wx_URL()
{
}

Object *Object_wx_URL::Clone() const
{
	return nullptr;
}

String Object_wx_URL::ToString(bool exprFlag)
{
	String rtn("<wx.URL:");
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
// Class implementation for wxURL
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URL)
{
}

Gura_ImplementDescendantCreator(wx_URL)
{
	return new Object_wx_URL((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
