//----------------------------------------------------------------------------
// wxKeyboardState
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxKeyboardState
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxKeyboardState
//----------------------------------------------------------------------------
Object_wx_KeyboardState::~Object_wx_KeyboardState()
{
}

Object *Object_wx_KeyboardState::Clone() const
{
	return nullptr;
}

String Object_wx_KeyboardState::ToString(bool exprFlag)
{
	String rtn("<wx.KeyboardState:");
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
// Class implementation for wxKeyboardState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_KeyboardState)
{
}

Gura_ImplementDescendantCreator(wx_KeyboardState)
{
	return new Object_wx_KeyboardState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
