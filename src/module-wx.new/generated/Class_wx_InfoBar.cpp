//----------------------------------------------------------------------------
// wxInfoBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInfoBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInfoBar
//----------------------------------------------------------------------------
Object_wx_InfoBar::~Object_wx_InfoBar()
{
}

Object *Object_wx_InfoBar::Clone() const
{
	return nullptr;
}

String Object_wx_InfoBar::ToString(bool exprFlag)
{
	String rtn("<wx.InfoBar:");
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
// Class implementation for wxInfoBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InfoBar)
{
}

Gura_ImplementDescendantCreator(wx_InfoBar)
{
	return new Object_wx_InfoBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
