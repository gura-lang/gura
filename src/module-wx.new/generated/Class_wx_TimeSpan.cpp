//----------------------------------------------------------------------------
// wxTimeSpan
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimeSpan
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimeSpan
//----------------------------------------------------------------------------
Object_wx_TimeSpan::~Object_wx_TimeSpan()
{
}

Object *Object_wx_TimeSpan::Clone() const
{
	return nullptr;
}

String Object_wx_TimeSpan::ToString(bool exprFlag)
{
	String rtn("<wx.TimeSpan:");
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
// Class implementation for wxTimeSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimeSpan)
{
}

Gura_ImplementDescendantCreator(wx_TimeSpan)
{
	return new Object_wx_TimeSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
