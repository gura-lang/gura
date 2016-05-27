//----------------------------------------------------------------------------
// wxKeyEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxKeyEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxKeyEvent
//----------------------------------------------------------------------------
Object_wx_KeyEvent::~Object_wx_KeyEvent()
{
}

Object *Object_wx_KeyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_KeyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.KeyEvent:");
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
// Class implementation for wxKeyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_KeyEvent)
{
}

Gura_ImplementDescendantCreator(wx_KeyEvent)
{
	return new Object_wx_KeyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
