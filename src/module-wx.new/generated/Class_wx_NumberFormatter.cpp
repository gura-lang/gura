//----------------------------------------------------------------------------
// wxNumberFormatter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNumberFormatter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNumberFormatter
//----------------------------------------------------------------------------
Object_wx_NumberFormatter::~Object_wx_NumberFormatter()
{
}

Object *Object_wx_NumberFormatter::Clone() const
{
	return nullptr;
}

String Object_wx_NumberFormatter::ToString(bool exprFlag)
{
	String rtn("<wx.NumberFormatter:");
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
// Class implementation for wxNumberFormatter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NumberFormatter)
{
	// Class assignment
	Gura_AssignValueEx("NumberFormatter", Reference());
}

Gura_ImplementDescendantCreator(wx_NumberFormatter)
{
	return new Object_wx_NumberFormatter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
