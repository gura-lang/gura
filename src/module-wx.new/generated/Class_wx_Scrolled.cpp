//----------------------------------------------------------------------------
// wxScrolled
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScrolled
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScrolled
//----------------------------------------------------------------------------
Object_wx_Scrolled::~Object_wx_Scrolled()
{
}

Object *Object_wx_Scrolled::Clone() const
{
	return nullptr;
}

String Object_wx_Scrolled::ToString(bool exprFlag)
{
	String rtn("<wx.Scrolled:");
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
// Class implementation for wxScrolled
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Scrolled)
{
}

Gura_ImplementDescendantCreator(wx_Scrolled)
{
	return new Object_wx_Scrolled((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
