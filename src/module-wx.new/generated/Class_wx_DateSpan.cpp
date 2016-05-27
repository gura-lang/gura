//----------------------------------------------------------------------------
// wxDateSpan
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDateSpan
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateSpan
//----------------------------------------------------------------------------
Object_wx_DateSpan::~Object_wx_DateSpan()
{
}

Object *Object_wx_DateSpan::Clone() const
{
	return nullptr;
}

String Object_wx_DateSpan::ToString(bool exprFlag)
{
	String rtn("<wx.DateSpan:");
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
// Class implementation for wxDateSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateSpan)
{
}

Gura_ImplementDescendantCreator(wx_DateSpan)
{
	return new Object_wx_DateSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
