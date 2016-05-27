//----------------------------------------------------------------------------
// wxFSVolume
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFSVolume
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFSVolume
//----------------------------------------------------------------------------
Object_wx_FSVolume::~Object_wx_FSVolume()
{
}

Object *Object_wx_FSVolume::Clone() const
{
	return nullptr;
}

String Object_wx_FSVolume::ToString(bool exprFlag)
{
	String rtn("<wx.FSVolume:");
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
// Class implementation for wxFSVolume
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FSVolume)
{
}

Gura_ImplementDescendantCreator(wx_FSVolume)
{
	return new Object_wx_FSVolume((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
