//----------------------------------------------------------------------------
// wxAcceleratorEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAcceleratorEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Object_wx_AcceleratorEntry::~Object_wx_AcceleratorEntry()
{
}

Object *Object_wx_AcceleratorEntry::Clone() const
{
	return nullptr;
}

String Object_wx_AcceleratorEntry::ToString(bool exprFlag)
{
	String rtn("<wx.AcceleratorEntry:");
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
// Class implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorEntry)
{
}

Gura_ImplementDescendantCreator(wx_AcceleratorEntry)
{
	return new Object_wx_AcceleratorEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
