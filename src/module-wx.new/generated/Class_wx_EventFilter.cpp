//----------------------------------------------------------------------------
// wxEventFilter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventFilter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEventFilter
//----------------------------------------------------------------------------
Object_wx_EventFilter::~Object_wx_EventFilter()
{
}

Object *Object_wx_EventFilter::Clone() const
{
	return nullptr;
}

String Object_wx_EventFilter::ToString(bool exprFlag)
{
	String rtn("<wx.EventFilter:");
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
// Class implementation for wxEventFilter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventFilter)
{
}

Gura_ImplementDescendantCreator(wx_EventFilter)
{
	return new Object_wx_EventFilter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
