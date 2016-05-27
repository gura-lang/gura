//----------------------------------------------------------------------------
// wxMouseEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseEvent
//----------------------------------------------------------------------------
Object_wx_MouseEvent::~Object_wx_MouseEvent()
{
}

Object *Object_wx_MouseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MouseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MouseEvent:");
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
// Class implementation for wxMouseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseEvent)
{
}

Gura_ImplementDescendantCreator(wx_MouseEvent)
{
	return new Object_wx_MouseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
