//----------------------------------------------------------------------------
// wxDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDialog
//----------------------------------------------------------------------------
Object_wx_Dialog::~Object_wx_Dialog()
{
}

Object *Object_wx_Dialog::Clone() const
{
	return nullptr;
}

String Object_wx_Dialog::ToString(bool exprFlag)
{
	String rtn("<wx.Dialog:");
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
// Class implementation for wxDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dialog)
{
}

Gura_ImplementDescendantCreator(wx_Dialog)
{
	return new Object_wx_Dialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
