//----------------------------------------------------------------------------
// wxMouseState
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseState
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseState
//----------------------------------------------------------------------------
Object_wx_MouseState::~Object_wx_MouseState()
{
}

Object *Object_wx_MouseState::Clone() const
{
	return nullptr;
}

String Object_wx_MouseState::ToString(bool exprFlag)
{
	String rtn("<wx.MouseState:");
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
// Class implementation for wxMouseState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseState)
{
}

Gura_ImplementDescendantCreator(wx_MouseState)
{
	return new Object_wx_MouseState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
