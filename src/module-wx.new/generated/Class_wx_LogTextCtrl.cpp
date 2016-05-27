//----------------------------------------------------------------------------
// wxLogTextCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogTextCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogTextCtrl
//----------------------------------------------------------------------------
Object_wx_LogTextCtrl::~Object_wx_LogTextCtrl()
{
}

Object *Object_wx_LogTextCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_LogTextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.LogTextCtrl:");
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
// Class implementation for wxLogTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogTextCtrl)
{
}

Gura_ImplementDescendantCreator(wx_LogTextCtrl)
{
	return new Object_wx_LogTextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
