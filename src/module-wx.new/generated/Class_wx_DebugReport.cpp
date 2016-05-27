//----------------------------------------------------------------------------
// wxDebugReport
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReport
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugReport
//----------------------------------------------------------------------------
Object_wx_DebugReport::~Object_wx_DebugReport()
{
}

Object *Object_wx_DebugReport::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReport::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReport:");
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
// Class implementation for wxDebugReport
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReport)
{
}

Gura_ImplementDescendantCreator(wx_DebugReport)
{
	return new Object_wx_DebugReport((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
