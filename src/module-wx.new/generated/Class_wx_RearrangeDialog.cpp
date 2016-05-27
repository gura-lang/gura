//----------------------------------------------------------------------------
// wxRearrangeDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRearrangeDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRearrangeDialog
//----------------------------------------------------------------------------
Object_wx_RearrangeDialog::~Object_wx_RearrangeDialog()
{
}

Object *Object_wx_RearrangeDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RearrangeDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RearrangeDialog:");
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
// Class implementation for wxRearrangeDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeDialog)
{
}

Gura_ImplementDescendantCreator(wx_RearrangeDialog)
{
	return new Object_wx_RearrangeDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
