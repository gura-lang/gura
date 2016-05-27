//----------------------------------------------------------------------------
// wxDCClipper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCClipper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCClipper
//----------------------------------------------------------------------------
Object_wx_DCClipper::~Object_wx_DCClipper()
{
}

Object *Object_wx_DCClipper::Clone() const
{
	return nullptr;
}

String Object_wx_DCClipper::ToString(bool exprFlag)
{
	String rtn("<wx.DCClipper:");
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
// Class implementation for wxDCClipper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCClipper)
{
}

Gura_ImplementDescendantCreator(wx_DCClipper)
{
	return new Object_wx_DCClipper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
