//----------------------------------------------------------------------------
// wxSpinCtrlDouble
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinCtrlDouble
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinCtrlDouble
//----------------------------------------------------------------------------
Object_wx_SpinCtrlDouble::~Object_wx_SpinCtrlDouble()
{
}

Object *Object_wx_SpinCtrlDouble::Clone() const
{
	return nullptr;
}

String Object_wx_SpinCtrlDouble::ToString(bool exprFlag)
{
	String rtn("<wx.SpinCtrlDouble:");
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
// Class implementation for wxSpinCtrlDouble
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinCtrlDouble)
{
}

Gura_ImplementDescendantCreator(wx_SpinCtrlDouble)
{
	return new Object_wx_SpinCtrlDouble((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
