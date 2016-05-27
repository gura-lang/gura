//----------------------------------------------------------------------------
// wxDCPenChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCPenChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCPenChanger
//----------------------------------------------------------------------------
Object_wx_DCPenChanger::~Object_wx_DCPenChanger()
{
}

Object *Object_wx_DCPenChanger::Clone() const
{
	return nullptr;
}

String Object_wx_DCPenChanger::ToString(bool exprFlag)
{
	String rtn("<wx.DCPenChanger:");
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
// Class implementation for wxDCPenChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCPenChanger)
{
}

Gura_ImplementDescendantCreator(wx_DCPenChanger)
{
	return new Object_wx_DCPenChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
