//----------------------------------------------------------------------------
// wxIconLocation
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIconLocation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIconLocation
//----------------------------------------------------------------------------
Object_wx_IconLocation::~Object_wx_IconLocation()
{
}

Object *Object_wx_IconLocation::Clone() const
{
	return nullptr;
}

String Object_wx_IconLocation::ToString(bool exprFlag)
{
	String rtn("<wx.IconLocation:");
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
// Class implementation for wxIconLocation
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconLocation)
{
}

Gura_ImplementDescendantCreator(wx_IconLocation)
{
	return new Object_wx_IconLocation((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
