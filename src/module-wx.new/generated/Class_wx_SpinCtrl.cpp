//----------------------------------------------------------------------------
// wxSpinCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinCtrl
//----------------------------------------------------------------------------
Object_wx_SpinCtrl::~Object_wx_SpinCtrl()
{
}

Object *Object_wx_SpinCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_SpinCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.SpinCtrl:");
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
// Class implementation for wxSpinCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinCtrl)
{
}

Gura_ImplementDescendantCreator(wx_SpinCtrl)
{
	return new Object_wx_SpinCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
