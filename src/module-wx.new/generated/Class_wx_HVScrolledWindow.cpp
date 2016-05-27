//----------------------------------------------------------------------------
// wxHVScrolledWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHVScrolledWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHVScrolledWindow
//----------------------------------------------------------------------------
Object_wx_HVScrolledWindow::~Object_wx_HVScrolledWindow()
{
}

Object *Object_wx_HVScrolledWindow::Clone() const
{
	return nullptr;
}

String Object_wx_HVScrolledWindow::ToString(bool exprFlag)
{
	String rtn("<wx.HVScrolledWindow:");
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
// Class implementation for wxHVScrolledWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HVScrolledWindow)
{
}

Gura_ImplementDescendantCreator(wx_HVScrolledWindow)
{
	return new Object_wx_HVScrolledWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
