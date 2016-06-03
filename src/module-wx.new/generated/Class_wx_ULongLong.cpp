//----------------------------------------------------------------------------
// wxULongLong
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxULongLong
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxULongLong
//----------------------------------------------------------------------------
Object_wx_ULongLong::~Object_wx_ULongLong()
{
}

Object *Object_wx_ULongLong::Clone() const
{
	return nullptr;
}

String Object_wx_ULongLong::ToString(bool exprFlag)
{
	String rtn("<wx.ULongLong:");
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
// Class implementation for wxULongLong
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ULongLong)
{
	// Class assignment
	Gura_AssignValueEx("ULongLong", Reference());
}

Gura_ImplementDescendantCreator(wx_ULongLong)
{
	return new Object_wx_ULongLong((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
