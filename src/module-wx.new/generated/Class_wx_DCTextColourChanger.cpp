//----------------------------------------------------------------------------
// wxDCTextColourChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCTextColourChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCTextColourChanger
//----------------------------------------------------------------------------
Object_wx_DCTextColourChanger::~Object_wx_DCTextColourChanger()
{
}

Object *Object_wx_DCTextColourChanger::Clone() const
{
	return nullptr;
}

String Object_wx_DCTextColourChanger::ToString(bool exprFlag)
{
	String rtn("<wx.DCTextColourChanger:");
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
// Class implementation for wxDCTextColourChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCTextColourChanger)
{
}

Gura_ImplementDescendantCreator(wx_DCTextColourChanger)
{
	return new Object_wx_DCTextColourChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
