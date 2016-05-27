//----------------------------------------------------------------------------
// wxWebKitCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitCtrl
//----------------------------------------------------------------------------
Object_wx_WebKitCtrl::~Object_wx_WebKitCtrl()
{
}

Object *Object_wx_WebKitCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitCtrl:");
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
// Class implementation for wxWebKitCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitCtrl)
{
}

Gura_ImplementDescendantCreator(wx_WebKitCtrl)
{
	return new Object_wx_WebKitCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
