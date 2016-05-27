//----------------------------------------------------------------------------
// wxUIActionSimulator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUIActionSimulator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUIActionSimulator
//----------------------------------------------------------------------------
Object_wx_UIActionSimulator::~Object_wx_UIActionSimulator()
{
}

Object *Object_wx_UIActionSimulator::Clone() const
{
	return nullptr;
}

String Object_wx_UIActionSimulator::ToString(bool exprFlag)
{
	String rtn("<wx.UIActionSimulator:");
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
// Class implementation for wxUIActionSimulator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UIActionSimulator)
{
}

Gura_ImplementDescendantCreator(wx_UIActionSimulator)
{
	return new Object_wx_UIActionSimulator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
