//----------------------------------------------------------------------------
// wxTrackable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTrackable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTrackable
//----------------------------------------------------------------------------
Object_wx_Trackable::~Object_wx_Trackable()
{
}

Object *Object_wx_Trackable::Clone() const
{
	return nullptr;
}

String Object_wx_Trackable::ToString(bool exprFlag)
{
	String rtn("<wx.Trackable:");
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
// Class implementation for wxTrackable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Trackable)
{
}

Gura_ImplementDescendantCreator(wx_Trackable)
{
	return new Object_wx_Trackable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
