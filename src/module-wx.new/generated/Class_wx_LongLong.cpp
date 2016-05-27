//----------------------------------------------------------------------------
// wxLongLong
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLongLong
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLongLong
//----------------------------------------------------------------------------
Object_wx_LongLong::~Object_wx_LongLong()
{
}

Object *Object_wx_LongLong::Clone() const
{
	return nullptr;
}

String Object_wx_LongLong::ToString(bool exprFlag)
{
	String rtn("<wx.LongLong:");
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
// Class implementation for wxLongLong
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LongLong)
{
}

Gura_ImplementDescendantCreator(wx_LongLong)
{
	return new Object_wx_LongLong((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
