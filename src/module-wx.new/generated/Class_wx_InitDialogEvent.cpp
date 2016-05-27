//----------------------------------------------------------------------------
// wxInitDialogEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInitDialogEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInitDialogEvent
//----------------------------------------------------------------------------
Object_wx_InitDialogEvent::~Object_wx_InitDialogEvent()
{
}

Object *Object_wx_InitDialogEvent::Clone() const
{
	return nullptr;
}

String Object_wx_InitDialogEvent::ToString(bool exprFlag)
{
	String rtn("<wx.InitDialogEvent:");
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
// Class implementation for wxInitDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InitDialogEvent)
{
}

Gura_ImplementDescendantCreator(wx_InitDialogEvent)
{
	return new Object_wx_InitDialogEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
