//----------------------------------------------------------------------------
// wxDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDC
//----------------------------------------------------------------------------
Object_wx_DC::~Object_wx_DC()
{
}

Object *Object_wx_DC::Clone() const
{
	return nullptr;
}

String Object_wx_DC::ToString(bool exprFlag)
{
	String rtn("<wx.DC:");
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
// Class implementation for wxDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DC)
{
}

Gura_ImplementDescendantCreator(wx_DC)
{
	return new Object_wx_DC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
