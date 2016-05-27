//----------------------------------------------------------------------------
// wxStopWatch
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStopWatch
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStopWatch
//----------------------------------------------------------------------------
Object_wx_StopWatch::~Object_wx_StopWatch()
{
}

Object *Object_wx_StopWatch::Clone() const
{
	return nullptr;
}

String Object_wx_StopWatch::ToString(bool exprFlag)
{
	String rtn("<wx.StopWatch:");
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
// Class implementation for wxStopWatch
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StopWatch)
{
}

Gura_ImplementDescendantCreator(wx_StopWatch)
{
	return new Object_wx_StopWatch((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
