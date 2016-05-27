//----------------------------------------------------------------------------
// wxTipWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTipWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTipWindow
//----------------------------------------------------------------------------
Object_wx_TipWindow::~Object_wx_TipWindow()
{
}

Object *Object_wx_TipWindow::Clone() const
{
	return nullptr;
}

String Object_wx_TipWindow::ToString(bool exprFlag)
{
	String rtn("<wx.TipWindow:");
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
// Class implementation for wxTipWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipWindow)
{
}

Gura_ImplementDescendantCreator(wx_TipWindow)
{
	return new Object_wx_TipWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
