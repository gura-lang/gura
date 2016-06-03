//----------------------------------------------------------------------------
// wxDateTime
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDateTime
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateTime
//----------------------------------------------------------------------------
Object_wx_DateTime::~Object_wx_DateTime()
{
}

Object *Object_wx_DateTime::Clone() const
{
	return nullptr;
}

String Object_wx_DateTime::ToString(bool exprFlag)
{
	String rtn("<wx.DateTime:");
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
// Class implementation for wxDateTime
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateTime)
{
}

Gura_ImplementDescendantCreator(wx_DateTime)
{
	return new Object_wx_DateTime((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
