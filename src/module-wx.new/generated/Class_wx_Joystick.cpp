//----------------------------------------------------------------------------
// wxJoystick
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxJoystick
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxJoystick
//----------------------------------------------------------------------------
Object_wx_Joystick::~Object_wx_Joystick()
{
}

Object *Object_wx_Joystick::Clone() const
{
	return nullptr;
}

String Object_wx_Joystick::ToString(bool exprFlag)
{
	String rtn("<wx.Joystick:");
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
// Class implementation for wxJoystick
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Joystick)
{
}

Gura_ImplementDescendantCreator(wx_Joystick)
{
	return new Object_wx_Joystick((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
