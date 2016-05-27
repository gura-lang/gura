//----------------------------------------------------------------------------
// wxSystemThemedControl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemThemedControl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSystemThemedControl
//----------------------------------------------------------------------------
Object_wx_SystemThemedControl::~Object_wx_SystemThemedControl()
{
}

Object *Object_wx_SystemThemedControl::Clone() const
{
	return nullptr;
}

String Object_wx_SystemThemedControl::ToString(bool exprFlag)
{
	String rtn("<wx.SystemThemedControl:");
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
// Class implementation for wxSystemThemedControl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemThemedControl)
{
}

Gura_ImplementDescendantCreator(wx_SystemThemedControl)
{
	return new Object_wx_SystemThemedControl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
