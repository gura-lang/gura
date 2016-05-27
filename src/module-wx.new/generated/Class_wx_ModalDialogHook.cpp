//----------------------------------------------------------------------------
// wxModalDialogHook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxModalDialogHook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxModalDialogHook
//----------------------------------------------------------------------------
Object_wx_ModalDialogHook::~Object_wx_ModalDialogHook()
{
}

Object *Object_wx_ModalDialogHook::Clone() const
{
	return nullptr;
}

String Object_wx_ModalDialogHook::ToString(bool exprFlag)
{
	String rtn("<wx.ModalDialogHook:");
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
// Class implementation for wxModalDialogHook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ModalDialogHook)
{
}

Gura_ImplementDescendantCreator(wx_ModalDialogHook)
{
	return new Object_wx_ModalDialogHook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
